#include "utils.h"
#include "videoviewer.h"

using namespace std;

// LogWriter

const char *LogWriter::errMessages[] = { "No memory", "Can't fork", "URI encoding: not a hex digit" };

void LogWriter::WriteBuf(const char *message)
{
	extern std::string LogFileName;

	int sid = syscall(SYS_gettid);
	time_t ltime = time(NULL);
	struct tm *loctim = localtime(&ltime);

	FILE *logfil = fopen(LogFileName.c_str(), "a+t");
	fprintf(logfil, "%02d-%02d-%02dT%02d:%02d:%02d (%d) - %s\n",
		loctim->tm_mday, loctim->tm_mon + 1, loctim->tm_year % 100,
		loctim->tm_hour, loctim->tm_min, loctim->tm_sec,
		sid, message);
	fclose(logfil);
}

extern bool LogEnabled;

void LogWriter::WriteLog(const char *format, ...)
{
	if (!LogEnabled) return;
	char *buf = NULL;
	int size = 0;
	va_list ap;

	va_start(ap, format);
	size = vsnprintf(buf, size, format, ap);
	va_end(ap);

	if (size < 0) return;
	size++;
	buf = new char[size];

	va_start(ap, format);
	vsnprintf(buf, size, format, ap);
	va_end(ap);

	WriteBuf(buf);
	delete[] buf;
}

void LogWriter::WriteLog(int errIndx)
{
	if (!LogEnabled) return;
	WriteBuf(errMessages[errIndx]);
}

size_t copyToString(istream &src, std::string& str)
{
	char *buffer = new char[8192];
	if (!buffer) throw 0;
	streamsize len = 0;
	src.read(buffer, 8192);
	streamsize n = src.gcount();
	while (n > 0)
	{
		len += n;
		str.append(buffer, static_cast<std::string::size_type>(n));
		if (src.good())
		{
			src.read(buffer, 8192);
			n = src.gcount();
		}
		else n = 0;
	}
	delete[] buffer;
	return (size_t)len;
}

////////////////////////////
const std::string Uri::RESERVED_PATH = "?#";
const std::string Uri::ILLEGAL = "%<>{}|\\\"^`";
regex Uri::uriRx("(http:\\/\\/([^\\/:]+)(:([[:digit:]]+))?)?\\/?(.+)");

void Uri::parse(const char *str)
{
	cmatch res;
	if (!regex_search(str, res, uriRx)) throw Exception("Wrong URI");
	if (res[2].matched) decode(res[2].str(), _host);
	if (res[4].matched) _port = res[4].str().c_str();
	if (_port == "80") _port.clear();
	decode(res[5].str(), _path);
}

void  Uri::decode(const std::string& str, std::string& decodedStr, bool plusAsSpace)
{
	bool inQuery = false;
	std::string::const_iterator it = str.begin();
	std::string::const_iterator end = str.end();
	while (it != end)
	{
		char c = *it++;
		if (c == '?') inQuery = true;
		// spaces may be encoded as plus signs in the query
		if (inQuery && plusAsSpace && c == '+') c = ' ';
		else if (c == '%')
		{
			if (it == end) throw Exception("URI encoding: no hex digit following percent sign '%s'", str.c_str());
			char hi = *it++;
			if (it == end) throw Exception("URI encoding: two hex digits must follow percent sign '%s'", str.c_str());
			char lo = *it++;
			if (hi >= '0' && hi <= '9')
				c = hi - '0';
			else if (hi >= 'A' && hi <= 'F')
				c = hi - 'A' + 10;
			else if (hi >= 'a' && hi <= 'f')
				c = hi - 'a' + 10;
			else throw 2;
			c *= 16;
			if (lo >= '0' && lo <= '9')
				c += lo - '0';
			else if (lo >= 'A' && lo <= 'F')
				c += lo - 'A' + 10;
			else if (lo >= 'a' && lo <= 'f')
				c += lo - 'a' + 10;
			else throw 2;
		}
		decodedStr += c;
	}
}

std::string Uri::formatHex(unsigned char c)
{
	char buf[6];
	sprintf(buf, "%02hx", c);
	return string(buf);
}

void Uri::encode(const std::string& str, const std::string& reserved, std::string& encodedStr)
{
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		char c = *it;
		if ((c >= 'a' && c <= 'z') ||
			(c >= 'A' && c <= 'Z') ||
			(c >= '0' && c <= '9') ||
			c == '-' || c == '_' ||
			c == '.' || c == '~')
		{
			encodedStr += c;
		}
		else if (c <= 0x20 || c >= 0x7F || ILLEGAL.find(c) != std::string::npos || reserved.find(c) != std::string::npos)
		{
			encodedStr += '%';
			encodedStr += formatHex((unsigned char)c);
		}
		else encodedStr += c;
	}
}

std::string Uri::toString() const
{
	if (isRelative()) return _path;

	std::string uri = "http://" + _host;
	if (!_port.empty())
		uri += ':' + _port;
	uri += '/' + _path;
	return uri;
}

const std::string Uri::getHost() const
{
	string host;
	encode(_host, RESERVED_PATH, host);
	return host;
}

const std::string Uri::getPath() const
{
	string path;
	encode(_path, "", path);
	return path;
}

//////////////////////////
regex HttpMessage::messRx("([^:]+):[[:space:]]+(.+)");

void HttpMessage::init(istream& stream)
{
	cmatch res;
	string inStr;
	do
	{
		if (!stream.good()) break;
		getline(stream, inStr);
		rtrim(inStr);
		if (inStr.empty()) break;

		if (!regex_search(inStr.c_str(), res, messRx)) throw Exception("bad header");
		operator[](res[1].str()) = res[2].str();
	} while (true);
}

const std::string *HttpMessage::getHeaderRecord(std::string key)
{
	std::map<std::string, std::string>::iterator it = find(key);
	if (it == end()) return NULL;
	return &(it->second);
}

std::regex HttpRequest::reqRx("(GET|get)[[:space:]]+([^[:space:]]+)[[:space:]]+(.+)");

HttpRequest::HttpRequest(istream& stream)
{
	cmatch res;

	string inStr;

	getline(stream, inStr);
	//if (!stream.good()) throw Exception("Initial stream closed");
	rtrim(inStr);
	if (inStr.empty()) throw Exception("empty stream");

	if (!regex_search(inStr.c_str(), res, reqRx)) throw Exception("bad request");

	_path = res[2].str();

	HttpMessage::init(stream);
}

//const char *HttpResponce::dayOfWeek[] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
//const char *HttpResponce::MonthName[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
std::regex HttpResponce::respRx("(http|HTTP)/[[:digit:].]+[[:space:]]+([[:digit:]]+)[[:space:]]+(.+)");

//HttpResponce::HttpResponce(HttpStatus status, const std::string& reason) :
//_status(status),
//_reason(reason)
//{
//	struct timeb ltm;
//	ftime(&ltm);
//	struct tm *loctim = gmtime(&ltm.time);
//
//	char *buffer = new char[8192];
//	sprintf(buffer, "%s, %02d %s %d %02d:%02d:%02d.%03d GMT", 
//		dayOfWeek[loctim->tm_wday], loctim->tm_mday, MonthName[loctim->tm_mon], loctim->tm_year + 1900, loctim->tm_hour, loctim->tm_min, loctim->tm_sec, ltm.millitm);
//	operator[]("Date") = buffer;
//	operator[]("Server") = "hlspxd";
//	//operator[]("Last-Modified") = buffer;
//	operator[]("Content-Type") = "text/plain";
//	//operator[]("Connection") = "close";
//}

HttpResponce::HttpResponce(socketstream &stream)
{
	cmatch res;

	string inStr;

	getline(stream, inStr);
	if (!stream.good()) throw Exception("HttpResponce Initial stream closed");
	rtrim(inStr);
	if (inStr.empty()) throw Exception("HttpResponce empty stream");
	if (!regex_search(inStr.c_str(), res, respRx)) throw Exception("HttpResponce bad responce");

	_status = (HttpStatus)atoi(res[2].str().c_str());
	_reason = res[3].str();

	HttpMessage::init(stream);
}

size_t HttpResponce::getContentLength()
{
	const string *contlen = getHeaderRecord("Content-Length");
	if (contlen == NULL) return 0;
	return (size_t)atol((*contlen).c_str());
}

/////////////////////////////////////////////////
#ifdef _WIN32
DWORD WINAPI VieverFunc(void  *param)
{
	try
	{
		SOCKET ClientSocket = *(SOCKET*)param;
		LogWriter::WriteLog("Accept %d", ClientSocket);
		VideoViewer vview(ClientSocket);
		vview.Run();
	}
	catch (Exception &ex)
	{
		LogWriter::WriteLog("Error VideoViewer %s", ex.what());
	}
	catch (int &ierr)
	{
		LogWriter::WriteLog(ierr);
	}
	catch (...)
	{
		LogWriter::WriteLog("Error VideoViewer");
	}
	return RETOK;
}
#else
extern VideoViewer *vview;
static void handle_SIGHUP(int signo)
{
	if (vview != NULL)
	{
		vview->Stop();
	}
}
#endif

extern SOCKET ListenSocket;

HttpServer::HttpServer(int port)
	:PortNum(port)
{
}

void HttpServer::Run()
{
#ifdef _WIN32

	WSADATA WsaDat;

	if (WSAStartup(MAKEWORD(2, 2), &WsaDat) != 0)
		throw exception("WSA FAILED");
#endif

	ListenSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (ListenSocket == SOCKET_ERROR)
		throw Exception("Socket Failed to load");

	int yes = 1;
	setsockopt(ListenSocket, SOL_SOCKET, SO_REUSEADDR, (const char *)&yes, sizeof(yes));

	SOCKADDR_IN server;

	server.sin_port = htons(PortNum);
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;

	if (::bind(ListenSocket, (SOCKADDR *)(&server), sizeof(server)) == SOCKET_ERROR)
		throw Exception("BINDING FAILED");

	if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR)
		throw Exception("listen FAILED");

	SOCKET ClientSocket;

	do {

		ClientSocket = accept(ListenSocket, NULL, NULL);
		if (ClientSocket == INVALID_SOCKET) {
			if (errno == EINTR) break;						// нормальное завершение
			throw Exception("accept failed");
		}

#ifdef _WIN32

		HANDLE thrH = CreateThread(
			NULL,                   // default security attributes
			0,                      // use default stack size  
			VieverFunc,       // thread function name
			&ClientSocket,          // argument to thread function 
			0,                      // use default creation flags 
			NULL);   // returns the thread identifier 

		if (thrH == NULL) throw Exception("Thread creation failed");
		CloseHandle(thrH);
#else
		pid_t fpid = fork();
		if (fpid == 0)
		{
			closesocket(ListenSocket);
			ListenSocket = INVALID_SOCKET;

			struct sigaction qact;
			qact.sa_handler = handle_SIGHUP;
			sigemptyset(&qact.sa_mask);
			qact.sa_flags = 0;

			if (sigaction(SIGHUP, &qact,NULL) < 0)
				throw Exception("handle_SIGHUP");
			prctl(PR_SET_PDEATHSIG, SIGHUP);

			sigset_t full_sig_set;
			sigfillset(&full_sig_set);
			sigprocmask(SIG_UNBLOCK, &full_sig_set, 0);

			LogWriter::WriteLog("Accept %d", ClientSocket);
			vview = new VideoViewer(ClientSocket);
			if (!vview) throw 0;
			vview->Run();
			return;
		}
		else if  (fpid < 0)
		{
			LogWriter::WriteLog(1);
		}
		closesocket(ClientSocket);
#endif

	} while (ListenSocket != SOCKET_ERROR);

	if (ListenSocket != INVALID_SOCKET)
	{
		closesocket(ListenSocket);
		ListenSocket = INVALID_SOCKET;
	}
}


void socketbuf::open(Uri &uri)
{
	close();

	addrinfo hints, *result, *rp;

	memset(&hints, 0, sizeof hints);

	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	//hints.ai_flags = AI_PASSIVE;
	hints.ai_protocol = IPPROTO_TCP;

	int s = getaddrinfo(uri.getHost().c_str(), uri.getPort().c_str(), &hints, &result);
	if (s != 0) throw Exception("getaddrinfo error: %d", s);

	for (rp = result; rp != NULL; rp = rp->ai_next)
	{
		sock = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
		if (sock < 0)continue;

		if (connect(sock, rp->ai_addr, rp->ai_addrlen) == 0) break;  /* Success */
		closesocket(sock);
	}
	freeaddrinfo(result);           /* No longer needed */
	if (rp == NULL)			/* No address succeeded */
		throw Exception("Could not connect");

	std::streambuf::setp(obuf, obuf + (SIZE - 1));
	std::streambuf::setg(ibuf, ibuf, ibuf);
}


void HttpClient::connect2Host(Uri &reqUri)
{
	clientUri = reqUri;

	_sockstream.open(reqUri);
}

HttpResponce HttpClient::getResponce(Uri &reqUri)
{
	HttpResponce contResp;

	for (int att500 = 0; att500 < 5; att500++)
	{
		connect2Host(reqUri);

		_sockstream << "GET /" << reqUri.getPath() << " HTTP/1.1\nHost: " << reqUri.getHost()
			<< "\nUser-agent: hlspxd\nAccept: */*\nConnection: close\n\n";
		_sockstream.flush();

		contResp = HttpResponce(_sockstream);

		HttpResponce::HttpStatus contStat = contResp.getStatus();

		if ((contStat == HttpResponce::HTTP_FOUND) ||				// redirect
			(contStat == HttpResponce::HTTP_MOVED_PERMANENTLY) ||
			(contStat == HttpResponce::HTTP_TEMPORARY_REDIRECT)
			)
		{
			const string *Location = contResp.getHeaderRecord("Location");
			if (Location == NULL) throw Exception("Redirect - no location");
			clientUri = Uri(*Location);
			if (clientUri.isRelative()) throw Exception("Relative redirection not implemented 1");
			LogWriter::WriteLog("Redirect ->'%s'", Location->c_str());
			reqUri = clientUri;
		}
		else break;
	}
	return contResp;
}
