#include "videoviewer.h"

using namespace std;

extern VideoQuality DefaultQuality;

std::regex VideoViewer::PlRx(
	"(#EXT[A-Z3\\-]+)"
	"(:"
	"([^\n,]+)"
	"(,([^\n,]*))?"
	"(,([^\n,]*))?"
	"(,([^\n,]*))?"
	"(,([^\n,]*))?"
	"(,([^\n,]*))?"
	")?"
	"(\n((http:\\/\\/([^\\/:]+)(:([[:digit:]]+))?)?\\/?([^\n#]+)))?[\n\r]+");		//15 = file

VideoViewer::VideoViewer(SOCKET ClientSocket)
	:SessionQuality(DefaultQuality),
	MaxHistLen(0)
{
	VideoStream.open(ClientSocket);	

	HttpRequest req(VideoStream);

	string reqStr;
	Uri::decode(req.getPath(), reqStr);

	string reqUri = reqStr;

	size_t pos = reqStr.rfind('|');
	if (pos != string::npos)
	{
		regex usrcmdex("\\|"
			"([-_a-zA-Z0-9.]+)=([-_a-zA-Z0-9.]+)"
			"(,([-_a-zA-Z0-9.]+)=([-_a-zA-Z0-9.]+))?"
			"(,([-_a-zA-Z0-9.]+)=([-_a-zA-Z0-9.]+))?"
			"(,([-_a-zA-Z0-9.]+)=([-_a-zA-Z0-9.]+))?"
			"(,([-_a-zA-Z0-9.]+)=([-_a-zA-Z0-9.]+))?"
			"(,([-_a-zA-Z0-9.]+)=([-_a-zA-Z0-9.]+))?");
		cmatch uscvec;
		if (regex_search(reqStr.c_str() + pos, uscvec, usrcmdex))
		{
			for (size_t i = 1; i < uscvec.size(); i += 3)
			{
				if (!uscvec[i].matched) break;	// no more commands
				string command = uscvec[i].str();
				if (command == "quality")
				{
					if (!uscvec[i + 1].matched) break;
					string value = uscvec[i + 1].str();
					if (value == "high")
						SessionQuality = Video_high;
					else if (value == "medium")
						SessionQuality = Video_medium;
					else if (value == "low")
						SessionQuality = Video_low;
					else
						LogWriter::WriteLog("Wrong quality argument '%s'", value.c_str());
				}
				else
				{
					LogWriter::WriteLog("Wrong command '%s'", command.c_str());
				}

			}
		}
		reqUri = reqStr.substr(0, pos);
	}

	VideoUri = "http:/" + reqUri;

	LogWriter::WriteLog("Request video '%s'", VideoUri.toString().c_str());
}

void VideoViewer::Stop()
{
	VideoStream.close();
}

VideoViewer::~VideoViewer()
{
	Stop();
}

// read M3U8 file
void VideoViewer::ReadM3U8()
{
	PlayList.clear();
	HttpResponse contResp = M3U8Client.getResponse(VideoUri);
	if (contResp.getStatus() != HttpResponse::HTTP_OK)
		throw Exception("Read playlist returned '%d'", contResp.getStatus());
	
	cmatch mavec;
	string plStr;
	size_t strlen = copyToString(M3U8Client.getStream(), plStr);

	const char *strC = plStr.c_str();

	for (size_t pos = 0; pos < strlen;)
	{
		if (!regex_search(strC + pos, mavec, PlRx)) break;
		PlayListRecord recrd;
		recrd.Tag = mavec[1].str();			// #EXT... - tag

		// odd numbered fields contain attributes
		for (size_t i = 3; i < mavec.size(); i += 2)
		{
			if (!mavec[i].matched) break;	// no more attributes
			recrd.Attributes.push_back(mavec[i].str());
		}

		if ((mavec[15].matched))		// URI at position 15
		{
			if (mavec[17].matched)
				recrd.TsUri = Uri(mavec[17].str(), (mavec[19].matched) ? mavec[19].str() : "", mavec[20].str());
			else
				recrd.TsUri = Uri(VideoUri, mavec[20].str());
		}

		PlayList.push_back(recrd);
		pos += mavec[0].length();
	}
	if (PlayList.size() < 2) throw Exception("HLS_TOO_SHORT_PLAYLIST");
	if (PlayList[0].Tag != "#EXTM3U") throw Exception("HLS_NO_EXTM3U");
}


void VideoViewer::Run()
{	
	ReadM3U8();		// parse preliminary
	// successful - send the response to TV
	VideoStream << "HTTP/1.1 200 OK\nServer: hlspxd\nContent-Type: application/octet-stream\nConnection : close\n\n";
	VideoStream.flush();

	// find redirections to different resolutions
	vector<StreamInf> streamVec;

	for (vector<PlayListRecord>::iterator it = PlayList.begin(); it < PlayList.end(); it++)
	{
		if (it->Tag == "#EXT-X-STREAM-INF")
		{
			if (it->TsUri.empty()) throw Exception("#EXT-X-STREAM-INF - empty URI");
			StreamInf stri;
			stri.TsUri = it->TsUri;
			for (vector<string>::iterator its = it->Attributes.begin(); its != it->Attributes.end(); its++)
			{
				if (its->substr(0, 10) == "BANDWIDTH=")
				{
					if ((stri.Bandwidth = atoi(its->c_str() + 10)) == 0) throw Exception("#EXT-X-STREAM-INF:BANDWIDTH=?");

					//if (sscanf(its->c_str() + 10, "%d", &stri.Bandwidth) != 1) throw Exception("#EXT-X-STREAM-INF:BANDWIDTH=?");
				}
			}
			if (stri.Bandwidth == 0) throw Exception("#EXT-X-STREAM-INF: no BANDWIDTH");
			streamVec.push_back(stri);
		}
	}

	if (streamVec.size() > 0)
	{
		sort(streamVec.begin(), streamVec.end());
		StreamInf &selectedStream = streamVec[0];
		switch (SessionQuality)
		{
		case Video_high:
			selectedStream = streamVec[streamVec.size() - 1];
			break;
		case Video_medium:
			selectedStream = streamVec[streamVec.size() / 2];
			break;
		case Video_low:
			selectedStream = streamVec[0];
			break;
		}

		LogWriter::WriteLog("Select STREAM-INF: URI '%s' BANDWIDTH=%d", selectedStream.TsUri.toString().c_str(), 
			selectedStream.Bandwidth);

		VideoUri = selectedStream.TsUri;

		ReadM3U8();
	}

	double m3uTime = -5.;			// total played duration
	Stopwatch curTime;				// current time
	curTime.start();
	int prevMediaSeq = 0;			// previous chunk sequence number
	int emptCnt = 0;				// empty sequence count
	bool endList = false;			// end of playlist

	while (true)
	{
		int uniqts = 0;			// TS files count
		int addedTs = 0;		// added for processing
		double lps = 0.;		// cached duration (sec)

		int mediaSeq = 0;
		TsURI lastTs;

		for (vector<PlayListRecord>::iterator it = PlayList.begin(); it < PlayList.end(); it++)
		{
			// chunk sequence number
			if (it->Tag == "#EXT-X-MEDIA-SEQUENCE")
			{
				if (it->Attributes.size() == 0) throw Exception("#EXT-X-MEDIA-SEQUENCE - no attributes");
				mediaSeq = atoi(it->Attributes[0].c_str());
			}
			else if (it->Tag == "#EXTINF")
			{
				if (it->Attributes.size() == 0) throw Exception("#EXTINF - no attributes");
				if (it->TsUri.empty()) throw Exception("#EXTINF - TsUri empty");

				double dur = atof(it->Attributes[0].c_str());
							
				if (dur == 0) throw Exception("HSL_BAD_EXTINF_LENGTH");

				TsURI nts(it->TsUri, dur);

				if (nts == lastTs) continue;
				lastTs = nts;
				uniqts++;

				list<TsURI>::iterator it = find(TsList.begin(), TsList.end(), nts);
				if (it == TsList.end())
				{
					TsList.push_back(nts);
					addedTs++;
				}
				else
				{
					lps += dur;
				}
			}
			else if (it->Tag == "#EXT-X-ENDLIST")
			{
				LogWriter::WriteLog("Last media sequence");
				endList = true;
			}
		}

		if (prevMediaSeq != 0)
		{
			if ((prevMediaSeq + addedTs) != mediaSeq)
			{
				LogWriter::WriteLog("Lost %d !!", mediaSeq - prevMediaSeq - addedTs);
			}
		}

		LogWriter::WriteLog("added %d (%d) forward %0.2f mediaSeq %d", addedTs, uniqts, lps, mediaSeq);
		prevMediaSeq = mediaSeq;

		if (addedTs == 0)			// nothing new - should not get here
		{
			if (emptCnt++ > 4)
			{
				LogWriter::WriteLog("Empty sequences!");
				break;
			}
			if (lastTs.Duration == 0) throw	Exception("lastTs.Duration == 0");

			LogWriter::WriteLog("Sleep->%0.2f", lastTs.Duration);

			Sleep((long)(lastTs.Duration * 1000));
			m3uTime += lastTs.Duration;
			ReadM3U8();
			continue;
		}
		emptCnt = 0;

		// clear history
		if (uniqts >= MaxHistLen) MaxHistLen = uniqts * 2;
		if ((int)TsList.size() > MaxHistLen)
		{
			size_t ndel = TsList.size() - MaxHistLen;
			list<TsURI>::iterator lpos = TsList.begin();
			for (size_t n = 0; n < ndel; n++) lpos++;
			TsList.erase(TsList.begin(), lpos);
		}

		list<TsURI>::iterator readPos = TsList.end();
		for (int n = 0; n < addedTs; n++) readPos--;		// position of the first unplayed file

		for (; readPos != TsList.end(); readPos++)
		{
			if (!VideoStream.good()) break;

			HttpResponse tsResp = tsClient.getResponse(*readPos);
			if (tsResp.getStatus() != HttpResponse::HTTP_OK)
				throw Exception("Read TS file returned '%d'", (int)tsResp.getStatus());

			size_t contLen = tsResp.getContentLength();			// TS file length
			if (contLen == 0)
				throw Exception(".ts file has no Content Length");

			double byteDelay = readPos->Duration / contLen;		// delay per byte
			double tsTime = m3uTime;							// time inside .ts
			socketstream &tsStream = tsClient.getStream();

			while (tsStream.good() && VideoStream.good())
			{
				string sss;
				tsStream.read(TsBuf, TS_BUF_LEN);			// read video
				size_t rdbts = (size_t)tsStream.gcount();	// number of bytes read
				VideoStream.write(TsBuf, rdbts);
				tsTime += rdbts * byteDelay;
				double curdel = tsTime - (curTime.elapsed() / 1000.);		// cached, seconds
				if ((curdel > 0.01) && !endList)
				{
					Sleep((long)(curdel * 1000));
				}
			}
			m3uTime += readPos->Duration;
			//VideoStream.flush();
		}
		if (!VideoStream.good())
		{
			LogWriter::WriteLog("Output stream closed");
			break;
		}
		if (endList)
		{
			LogWriter::WriteLog("End VOD");
			break;
		}
		ReadM3U8();
	}
}
