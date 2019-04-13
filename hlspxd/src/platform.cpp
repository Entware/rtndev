#include "platform.h"
#include "utils.h"
#include <signal.h>

static void handle_quitsigs(int signo)
{
	(void)&signo;

//	LogWriter::WriteLog("*** Caught SIGNAL %d ***", signo);
	return;
}

int HideSignals()
{
#ifndef _WIN32
	struct sigaction qact;
	qact.sa_handler = handle_quitsigs;
	sigemptyset(&qact.sa_mask);
	qact.sa_flags = 0;

	if ((sigaction(SIGTERM, &qact,NULL) < 0) ||
		(sigaction(SIGQUIT, &qact, NULL) < 0) ||
		(sigaction(SIGINT, &qact, NULL) < 0))
	{
		LogWriter::WriteLog("sigaction-quit");
		return -1;
	}

	qact.sa_flags = SA_NOCLDWAIT | SA_RESTART;
	qact.sa_handler = SIG_IGN;
	sigaction(SIGCHLD,  &qact, NULL);

#endif
	return 0;
}

Exception::Exception(const char * format, ...) throw()
{
	_message = NULL;
	int size = 0;
	va_list ap;

	va_start(ap, format);
	size = vsnprintf(_message, size, format, ap);
	va_end(ap);

	if (size < 0) return;
	size++;
	_message = new char[size];

	va_start(ap, format);
	vsnprintf(_message, size, format, ap);
	va_end(ap);
}
