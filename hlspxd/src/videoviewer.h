#ifndef VIDEOVIEWER_H
#define VIDEOVIEWER_H

#include "utils.h"
#include <list>
// entry in m3u8 file
struct PlayListRecord
{
	std::string Tag;					// tag - required field
	std::vector<std::string> Attributes;	// attributes
	Uri TsUri;					// URL - absolute or relative
};

// used to select the required stream resolution
struct StreamInf
{
	int Bandwidth;				// resolution
	Uri TsUri;					// URL - absolute or relative
	StreamInf() :Bandwidth(0) {}

	bool operator < (const StreamInf &other) const
	{
		return Bandwidth < other.Bandwidth;
	}
};

class TsURI : public Uri
{
public:
	double	Duration;						// total played duration (sec)
	TsURI()
		:Duration(0)
	{}
	TsURI(const std::string & uri, double Duration)
		:Uri(uri), Duration(Duration)
	{}
	TsURI(Uri uri, double Duration)
		:Uri(uri), Duration(Duration)
	{}

	TsURI(const TsURI &other)
		:Uri(other), Duration(other.Duration)
	{}
};

struct TsPacketHdr
{
	union
	{
		uint32_t Uval;
		struct
		{
			uint32_t CC : 4;
			uint32_t AFC : 2;
			uint32_t TSC : 2;
			uint32_t PID : 13;
			uint32_t TP : 1;
			uint32_t PUSI : 1;
			uint32_t TEI : 1;
			uint32_t Sync : 8;
		}Sval;
	};
	TsPacketHdr(){}

	TsPacketHdr(void *buf)
	{
		Uval = ntohl(*((uint32_t*)buf));
	}
};

#define TS_FRAME_LEN 188
#define TS_FRAMES_IN_BUF 4
#define TS_BUF_LEN TS_FRAMES_IN_BUF*TS_FRAME_LEN

class VideoViewer
{
	socketstream VideoStream;			// output stream
	VideoQuality SessionQuality;		// video quality
	Uri VideoUri;						// current URI
	HttpClient M3U8Client;				// content server session
	char TsBuf[TS_BUF_LEN];				// output buffer

	// parser
	static std::regex PlRx;				//15 = file
	std::vector<PlayListRecord> PlayList;	// playlist

	int	MaxHistLen;				// history length

	std::list<TsURI> TsList;			// TS file list

	HttpClient tsClient;

	void ReadM3U8();

public:
	VideoViewer(SOCKET ClientSocket);
	~VideoViewer();
	void Run();
	void Stop();
};

#endif
