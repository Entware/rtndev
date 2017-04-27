#ifndef NETUTILS_H
#define NETUTILS_H

#include "platform.h"

enum VideoQuality
{
	Video_high,
	Video_medium,
	Video_low
};

// trim from end (in place)
static inline void rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(),
		std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}

// копировать все в строку
size_t copyToString(std::istream &src, std::string& str);

class LogWriter
{
private:
	static void WriteBuf(const char *message);
public:
	static const char *errMessages[];
	static void WriteLog(const char *format, ...);
	static void WriteLog(int errIndx);
};

/////////////////////////////
class Uri
{
	static const std::string RESERVED_PATH;
	static const std::string ILLEGAL;
	static std::regex uriRx;
	std::string		_host;
	std::string		_port;
	std::string		_path;

	void clear()
	{
		_host.clear();
		_port.clear();
		_path.clear();
	}
	void parse(const char *str);
	static std::string formatHex(unsigned char c);

public:
	Uri() {}

	Uri(const Uri& uri) :
		_host(uri._host),
		_port(uri._port),
		_path(uri._path)
	{}

	Uri(const std::string &host, const std::string &port, const std::string &path)
		:_host(host), _port(port), _path(path)
	{}

	Uri(const char *str)
	{
		parse(str);
	}

	Uri(const std::string &str)
	{
		parse(str.c_str());
	}

	Uri(const Uri& base, const std::string &str) :
		_host(base._host),
		_port(base._port)
	{
		size_t pos = base._path.rfind('/');
		_path = base._path.substr(0, pos + 1) + str;
	}


	Uri& operator = (const Uri& uri)
	{
		if (&uri != this)
		{
			_host = uri._host;
			_port = uri._port;
			_path = uri._path;
		}
		return *this;
	}

	Uri& operator = (const char* uri)
	{
		clear();
		parse(uri);
		return *this;
	}

	Uri& operator = (const std::string& uri)
	{
		clear();
		parse(uri.c_str());
		return *this;
	}

	bool equals(const Uri& uri) const
	{
		return  _host == uri._host
			&& _port == uri._port
			&& _path == uri._path;
	}
	bool operator == (const Uri& uri) const
	{
		return equals(uri);
	}

	const std::string getHost() const;
	inline std::string getPort() const { return (_port.empty()) ? "80" : _port; }
	const std::string getPath() const;
	inline const bool isRelative() const { return _host.empty(); }
	inline const bool empty() const { return (_host.empty() && _path.empty()); }

	std::string toString() const;

	static void decode(const std::string& str, std::string& decodedStr, bool plusAsSpace = false);
	static void encode(const std::string& str, const std::string& reserved, std::string& encodedStr);
};


// streambuf для сокета
class socketbuf
	: public std::streambuf
{
protected:

	static const int SIZE = 752;
	char obuf[SIZE];
	char ibuf[SIZE];
	SOCKET sock;
	long readTimeout, writeTimeout;		// timeouts - mls

public:
	socketbuf() : sock(INVALID_SOCKET), readTimeout(60000), writeTimeout(60000)
	{
		std::streambuf::setp(obuf, obuf + (SIZE - 1));
		std::streambuf::setg(ibuf, ibuf, ibuf);
	}
	
	virtual ~socketbuf() 
	{ 
		sync(); 
		close();
	}

	void open(Uri &uri);
	
	void close()
	{
		if (sock != INVALID_SOCKET)
		{
			closesocket(sock);
			sock = INVALID_SOCKET;
		}
	}

	void set_socket(SOCKET sock) 
	{
		this->sock = sock; 
		std::streambuf::setp(obuf, obuf + (SIZE - 1));
		std::streambuf::setg(ibuf, ibuf, ibuf);
	}
	SOCKET get_socket() { return this->sock; }
	void set_timeouts(long rd, long wr){ readTimeout = rd; writeTimeout = wr; }

protected:

	int output_buffer()
	{
		if (sock == INVALID_SOCKET) return traits_type::eof();

		int num = std::streambuf::pptr() - std::streambuf::pbase();

		fd_set WriteSet;
		struct timeval Time;
		FD_ZERO(&WriteSet);
		FD_SET(sock, &WriteSet);
		Time.tv_sec = writeTimeout / 1000L;
		Time.tv_usec = (writeTimeout % 1000L) * 1000L;

		int wrRes = select(sock + 1, NULL, &WriteSet, NULL, &Time);
		if (wrRes > 0)	// OK
		{
			if (send(sock, obuf, num, 0) != num)
				return traits_type::eof();
			std::streambuf::pbump(-num);
			return num;
		}
		else if (wrRes == 0)	// timeout
		{
			throw Exception("Write timeout");
		}
		throw Exception("Write select");
		//return traits_type::eof();
	}

	virtual int_type overflow(int_type c)
	{
		if (c != traits_type::eof())
		{
			*std::streambuf::pptr() = c;
			std::streambuf::pbump(1);
		}

		if (output_buffer() == traits_type::eof())
			return traits_type::eof();
		return c;
	}

	virtual int sync()
	{
		if (output_buffer() == traits_type::eof())
			return traits_type::eof();
		return 0;
	}

	virtual int_type underflow()
	{
		if (std::streambuf::gptr() < std::streambuf::egptr())
			return traits_type::to_int_type(*std::streambuf::gptr());

		if (sock == INVALID_SOCKET) return traits_type::eof();
		int num;

		fd_set ReadSet;
		struct timeval Time;
		FD_ZERO(&ReadSet);
		FD_SET(sock, &ReadSet);
		Time.tv_sec = readTimeout / 1000L;
		Time.tv_usec = (readTimeout % 1000L) * 1000L;

		int selRes = select(sock + 1, &ReadSet, NULL, NULL, &Time);
		if (selRes > 0) { /* got some data */

			if ((num = recv(sock, ibuf, SIZE, 0)) <= 0)
				return traits_type::eof();					// end of file
			std::streambuf::setg(ibuf, ibuf, ibuf + num);
			return traits_type::to_int_type(*std::streambuf::gptr());
		}
		else if (selRes == 0) { /* timeout */
			throw Exception("Read timeout");
		}
		throw Exception("Read select");
	}
};

class socketstream
	: public std::iostream
{
protected:
	socketbuf buf;

public:
	socketstream() : std::iostream(&buf) {}
	//socketstream(SOCKET s, long readTimeout = 60000, long writeTimeout = 60000)
	//	: std::iostream(&buf)
	//{
	//	buf.set_socket(s);
	//	buf.set_timeouts(readTimeout, writeTimeout);
	//}

	virtual ~socketstream()
	{
		close();
	}

	void close()
	{
		buf.close();
		std::iostream::clear();
	}

	virtual bool good()
	{
		return std::iostream::good() && (buf.get_socket() != INVALID_SOCKET);
	}

	void open(SOCKET sock)
	{
		close();
		buf.set_socket(sock);
	}

	void open(Uri &uri)
	{
		close();
		buf.open(uri);
	}

};


//////////////////////////////////
class HttpMessage : public std::map<std::string, std::string>
{
	static std::regex messRx;
protected:
	void init(std::istream& stream);
public:
	const std::string *getHeaderRecord(std::string key);
};

class HttpRequest : public HttpMessage
{
	static std::regex reqRx;
	std::string _path;
public:
	HttpRequest(std::istream& stream);
	inline std::string &getPath(){ return _path; }
};

class HttpResponce : public HttpMessage
{
	//static const char *dayOfWeek[];
	//static const char *MonthName[];
	static std::regex respRx;
public:
	enum HttpStatus
	{
		//HTTP_CONTINUE = 100,
		//HTTP_SWITCHING_PROTOCOLS = 101,
		HTTP_OK = 200,
		//HTTP_CREATED = 201,
		//HTTP_ACCEPTED = 202,
		//HTTP_NONAUTHORITATIVE = 203,
		//HTTP_NO_CONTENT = 204,
		//HTTP_RESET_CONTENT = 205,
		//HTTP_PARTIAL_CONTENT = 206,
		HTTP_MULTIPLE_CHOICES = 300,
		HTTP_MOVED_PERMANENTLY = 301,
		HTTP_FOUND = 302,
		HTTP_SEE_OTHER = 303,
		HTTP_NOT_MODIFIED = 304,
		HTTP_USEPROXY = 305,
		// UNUSED: 306
		HTTP_TEMPORARY_REDIRECT = 307,
		//HTTP_BAD_REQUEST = 400,
		//HTTP_UNAUTHORIZED = 401,
		//HTTP_PAYMENT_REQUIRED = 402,
		//HTTP_FORBIDDEN = 403,
		//HTTP_NOT_FOUND = 404,
		//HTTP_METHOD_NOT_ALLOWED = 405,
		//HTTP_NOT_ACCEPTABLE = 406,
		//HTTP_PROXY_AUTHENTICATION_REQUIRED = 407,
		//HTTP_REQUEST_TIMEOUT = 408,
		//HTTP_CONFLICT = 409,
		//HTTP_GONE = 410,
		//HTTP_LENGTH_REQUIRED = 411,
		//HTTP_PRECONDITION_FAILED = 412,
		//HTTP_REQUESTENTITYTOOLARGE = 413,
		//HTTP_REQUESTURITOOLONG = 414,
		//HTTP_UNSUPPORTEDMEDIATYPE = 415,
		//HTTP_REQUESTED_RANGE_NOT_SATISFIABLE = 416,
		//HTTP_EXPECTATION_FAILED = 417,
		HTTP_INTERNAL_SERVER_ERROR = 500,
		//HTTP_NOT_IMPLEMENTED = 501,
		//HTTP_BAD_GATEWAY = 502,
		//HTTP_SERVICE_UNAVAILABLE = 503,
		//HTTP_GATEWAY_TIMEOUT = 504,
		//HTTP_VERSION_NOT_SUPPORTED = 505
	};

	HttpResponce()
		:_status(HTTP_OK), _reason("OK")
	{}
	HttpResponce(socketstream &socstr);

	size_t getContentLength();
	inline HttpStatus getStatus() const { return _status; }

private:
	HttpStatus  _status;
	std::string _reason;
};

class HttpServer
{
	int PortNum;
public:
	HttpServer(int port);
	void Run();
};

class HttpClient
{
	Uri clientUri;
	socketstream _sockstream;
	void connect2Host(Uri &reqUri);
public:
	HttpClient(){}
	~HttpClient(){ _sockstream.close(); }
	HttpResponce getResponce(Uri &reqUri);
	socketstream &getStream(){ return _sockstream; }
	inline bool connected(){ return _sockstream.good(); }
	inline void abort(){ _sockstream.close(); }
};

#endif
