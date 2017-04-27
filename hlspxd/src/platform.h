#ifndef PLATFORM_H
#define PLATFORM_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/timeb.h>

#include <string>
#include <vector>
#include <map>
#include <streambuf>
#include <iostream>

#include <algorithm> 
#include <functional> 
#include <locale>
#include <cctype>
#include <exception>
#include <utility>
#include <errno.h>

int HideSignals();

class Exception : public std::exception
{
	char *_message;
public:
	Exception(const char * const &format, ...) throw();
	virtual ~Exception() throw() { delete[] _message; }
	virtual const char *what() const throw() { return _message; }
};

#ifdef _WIN32

#pragma warning(disable : 4996)

#include <regex>
#include <WinSock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "mswsock.lib")

#define RETOK 0

#define pthread_self() 0
#define getpid() 0

#define syscall(SYS_gettid) 0
#define SHUT_RDWR SD_BOTH 

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef long long int64_t;

typedef int pid_t;

class Stopwatch
{
	DWORD startTime;
public:
	Stopwatch():startTime(0){}
	void start() {startTime = GetTickCount();}
	void stop() {startTime = 0;}
	int64_t elapsed(){ return (startTime == 0) ? 0 : (int64_t)(GetTickCount() - startTime); }
};
#else

#include <getopt.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/prctl.h>
#include <signal.h>
#include <regex.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
//#include <pthread.h>

typedef int SOCKET;
#define SOCKET_ERROR (-1)
#define INVALID_SOCKET -1
#define SOCKADDR_IN sockaddr_in
#define SOCKADDR sockaddr
#define closesocket ::close

#define DWORD void
#define WINAPI *
#define RETOK NULL

#define shutdown(arg1,arg2) (void)0
#define SD_BOTH 2
#define Sleep(mls) usleep(mls * 1000)

class Stopwatch
{
	timespec startTime;
public:
	Stopwatch(){startTime.tv_sec = 0;}
	void start() {clock_gettime(CLOCK_MONOTONIC, &startTime);}
	void stop(){startTime.tv_sec = 0;}
	int64_t elapsed()
	{
		if (startTime.tv_sec == 0) return 0;
		timespec curtime;
		clock_gettime(CLOCK_MONOTONIC, &curtime);
		return (int64_t)(curtime.tv_sec - startTime.tv_sec) * 1000 +  (int64_t)(curtime.tv_nsec - startTime.tv_nsec) / 1000000;
	}
};

namespace std
{
	// like c++ 11
	class sub_match 
	{
		const char *first, *second;
	public:

		bool matched;
		sub_match(const char *first, const char *second, bool matched)
			: first(first), second(second), matched(matched)
		{
		}
		operator std::string() const
		{	// convert matched text to string
			return (str());
		}

		std::string str() const
		{	// convert matched text to string
			return (matched ? std::string(first, second) : std::string());
		}
		inline size_t length(){return (second - first);}

	};

	//class match_results : public std::vector<sub_match>
	//{
	//};

	typedef std::vector<sub_match> cmatch;

	class basic_regex
	{
		regex_t preg;
		const char *strptr;

		void init(const char *pattern)
		{
			if (regcomp(&preg, pattern, REG_EXTENDED)) throw Exception("regcomp");
		}

	public:
		basic_regex(const char *pattern)
			: strptr(NULL)
		{
			init(pattern);
		}

		basic_regex(const std::string &pattern)
			: strptr(NULL)
		{
			init(pattern.c_str());
		}

		~basic_regex()
		{
			regfree(&preg);
			if (strptr != NULL)	free((void *)strptr);
		}

		bool _Search(const char *_Str, cmatch &_Matches)
		{
			_Matches.clear();
			regmatch_t res[preg.re_nsub + 1];
			int rc = regexec(&preg, _Str, preg.re_nsub + 1, res, 0);
			if (rc == REG_NOMATCH) return false;
			else if (rc != 0) throw Exception("regexec");
			if (strptr != NULL)	free((void *)strptr);
			strptr = (const char *)strdup(_Str);
			if (!strptr) throw 0;

			for (size_t n = 0; n <= preg.re_nsub; n++)
			{
				if (res[n].rm_so < 0)
					_Matches.push_back(sub_match(strptr, strptr, false));
				else
					_Matches.push_back(sub_match(strptr + res[n].rm_so, strptr + res[n].rm_eo, true));
			}
			return true;
		}
	};

	typedef basic_regex regex;

	inline bool regex_search(const char *_Str, cmatch &_Matches, basic_regex &_Re)
	{
		return _Re._Search(_Str, _Matches);
	}
}

#endif //_WIN32

#endif	//PLATFORM_H
