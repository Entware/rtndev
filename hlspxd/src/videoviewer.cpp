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
				if (!uscvec[i].matched) break;	// дальше команд нет
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

// чтение M3U8 файла
void VideoViewer::ReadM3U8()
{
	PlayList.clear();
	HttpResponce contResp = M3U8Client.getResponce(VideoUri);
	if (contResp.getStatus() != HttpResponce::HTTP_OK)
		throw Exception("Read playlist returned '%d'", contResp.getStatus());
	
	cmatch mavec;
	string plStr;
	size_t strlen = copyToString(M3U8Client.getStream(), plStr);

	const char *strC = plStr.c_str();

	for (size_t pos = 0; pos < strlen;)
	{
		if (!regex_search(strC + pos, mavec, PlRx)) break;
		PlayListRecord recrd;
		recrd.Tag = mavec[1].str();			// #EXT... - таг

		// нечетные поля содержат атрибуты
		for (size_t i = 3; i < mavec.size(); i += 2)
		{
			if (!mavec[i].matched) break;	// дальше атрибутов нет
			recrd.Attributes.push_back(mavec[i].str());
		}

		if ((mavec[15].matched))		// URI в 15-й позиции
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
	ReadM3U8();		// парсим (предварительно)
	// успешно - послать ответ телевизору
	VideoStream << "HTTP/1.1 200 OK\nServer: hlspxd\nContent-Type: application/octet-stream\nConnection : close\n\n";
	VideoStream.flush();

	// находим переадресации на разные разрешения
	vector<StremInf> streamVec;

	for (vector<PlayListRecord>::iterator it = PlayList.begin(); it < PlayList.end(); it++)
	{
		if (it->Tag == "#EXT-X-STREAM-INF")
		{
			if (it->TsUri.empty()) throw Exception("#EXT-X-STREAM-INF - empty URI");
			StremInf stri;
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
		StremInf &selectedStream = streamVec[0];
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

	double m3uTime = -5.;			// время показа видео
	Stopwatch curTime;				// текущее время
	curTime.start();
	int prevMediaSeq = 0;			// предыдущий номер набора файлов
	int emptCnt = 0;				// счетчик пустых наборов
	bool endList = false;			// конец списка воспроизведения

	while (true)
	{
		int uniqts = 0;			// всего ТС файлов
		int addedTs = 0;		// добавлено для обработки
		double lps = 0.;		// насколько опережаем (sec)

		int mediaSeq = 0;
		TsURI lastTs;

		for (vector<PlayListRecord>::iterator it = PlayList.begin(); it < PlayList.end(); it++)
		{
			// последовательный номер куска
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
				LogWriter::WriteLog("Last media sequance");
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

		if (addedTs == 0)			// ничего нового - сюда не должны попадать НИКОГДА!
		{
			if (emptCnt++ > 4)
			{
				LogWriter::WriteLog("Empty sequances!");
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

		// почистить историю
		if (uniqts >= MaxHistLen) MaxHistLen = uniqts * 2;
		if ((int)TsList.size() > MaxHistLen)
		{
			size_t ndel = TsList.size() - MaxHistLen;
			list<TsURI>::iterator lpos = TsList.begin();
			for (size_t n = 0; n < ndel; n++) lpos++;
			TsList.erase(TsList.begin(), lpos);
		}

		list<TsURI>::iterator readPos = TsList.end();
		for (int n = 0; n < addedTs; n++) readPos--;		// позиция на 1 непоказанный

		for (; readPos != TsList.end(); readPos++)
		{
			if (!VideoStream.good()) break;

			HttpResponce tsResp = tsClient.getResponce(*readPos);
			if (tsResp.getStatus() != HttpResponce::HTTP_OK)
				throw Exception("Read TS file returned '%d'", (int)tsResp.getStatus());

			size_t contLen = tsResp.getContentLength();			// длина ТС файла
			if (contLen == 0)
				throw Exception(".ts file has no  Content Length");

			double byteDelay = readPos->Duration / contLen;		// задержка на байт
			double tsTime = m3uTime;							// время внутри .ts
			socketstream &tsStream = tsClient.getStream();

			while (tsStream.good() && VideoStream.good())
			{
				string sss;
				tsStream.read(TsBuf, TS_BUF_LEN);			// считать видео
				size_t rdbts = (size_t)tsStream.gcount();	// байт считано
				VideoStream.write(TsBuf, rdbts);
				tsTime += rdbts * byteDelay;
				double curdel = tsTime - (curTime.elapsed() / 1000.);		// опережение, сек
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
