#ifndef VIDEOVIEWER_H
#define VIDEOVIEWER_H

#include "utils.h"
#include <list>
// запись в m3u8 файле
struct PlayListRecord
{
	std::string Tag;					// таг - обязательно есть
	std::vector<std::string> Attributes;	// атрибуты
	Uri TsUri;					// URL - абсолютный или относительный
};

// для выбора нужного разрешения показа
struct StremInf
{
	int Bandwidth;				// разрешение
	Uri TsUri;					// URL - абсолютный или относительный
	StremInf() :Bandwidth(0) {}

	bool operator < (const StremInf &other) const
	{
		return Bandwidth < other.Bandwidth;
	}
};

class TsURI : public Uri
{
public:
	double	Duration;						// время показа файла (sec)
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
	socketstream VideoStream;			// выходной поток
	VideoQuality SessionQuality;		// качество показа видео
	Uri VideoUri;						// URI который показываем
	HttpClient M3U8Client;				// сессия сервера контента
	char TsBuf[TS_BUF_LEN];				// выходной буфер

	// парсер
	static std::regex PlRx;				//15 = file
	std::vector<PlayListRecord> PlayList;	// собственно плейлист

	int	MaxHistLen;				// длина истории

	std::list<TsURI> TsList;			// список ТС файлов

	HttpClient tsClient;

	void ReadM3U8();

public:
	VideoViewer(SOCKET ClientSocket);
	~VideoViewer();
	void Run();
	void Stop();
};

#endif
