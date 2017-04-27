// hlspxd_new.cpp : Defines the entry point for the console application.
//

#include "utils.h"
#include "videoviewer.h"
#include <fstream>

using namespace std;

string ProgName = "hlspxd";
string LogFileName = "/opt/var/log/";

bool AsDaemon = true;
#ifdef _WIN32
bool LogEnabled = true;
#else
bool LogEnabled = false;
#endif

int PortNum = 4343;

VideoQuality DefaultQuality = Video_high;

SOCKET ListenSocket = INVALID_SOCKET;
VideoViewer *vview = NULL;

int InitVars(const char *path)
{
#ifndef _WIN32

	string sp(path);

	size_t pos = sp.rfind('/');
	if (pos != string::npos)
		ProgName = sp.substr(pos + 1);
	else
		ProgName = sp;
#endif

	LogFileName.append(ProgName).append(".log");

	return 0;
}


int main(int argc, char* argv[])
{
	InitVars(argv[0]);

	string qualityStr = "high";

#ifndef _WIN32

	static struct option long_opt[] = {
		{"help", 0, 0, 'h'},
		{"port", 1, 0, 'p'},
		{"quality", 1, 0, 'q'},
		{"console", 0, 0, 'c'},
		{"writelog", 0, 0, 'w'},
		{0, 0, 0, 0}
};
	char c;
	while ((c = getopt_long(argc, argv, "h", long_opt, NULL)) != -1)
	{
		switch (c)
		{
		case 'c':
			AsDaemon = false;
			break;
		case 'w':
			LogEnabled = true;
			break;
		case 'p':
			PortNum = atoi(optarg);
			break;
		case 'q':
			qualityStr = optarg;
			if (strcmp(optarg, "high") == 0)
				DefaultQuality = Video_high;
			else if (strcmp(optarg, "medium") == 0)
				DefaultQuality = Video_medium;
			else if (strcmp(optarg, "low") == 0)
				DefaultQuality = Video_low;
			break;
		case 'h':
		default:
			cout << "Usage : " << ProgName << " <option(s)>" << endl
				<< "The options are:" << endl
				<< "   --port=<PortNum>\t\tSpecify port to listen. Default=4343" << endl
				<< "   --quality=<high|medium|low>\tSpecify quality of input video. Default=high" << endl
				<< "-h --help\t\t\tDisplay this output" << endl;
			exit(1);
		}
	}

	if (AsDaemon)
	{
		daemon(0, 0);
		if (HideSignals() != 0) return -1;
	}

#endif
	LogWriter::WriteLog("Start port=%d quality=%s", PortNum, qualityStr.c_str());

	HttpServer srv(PortNum);
	try
	{
		srv.Run();
	}
	catch (exception &ex)
	{
		LogWriter::WriteLog("Error HttpServer %s", ex.what());
		return -1;
	}
	catch (int &ierr)
	{
		LogWriter::WriteLog(ierr);
		return -1;
	}
	catch (...)
	{
		LogWriter::WriteLog("Exception!");
		return -1;
	}

	if (vview != NULL)
		delete vview;

	if (ListenSocket != INVALID_SOCKET)
		closesocket(ListenSocket);

	return 0;
}
