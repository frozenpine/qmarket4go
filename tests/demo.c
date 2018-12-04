#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <float.h>
#include <stdio.h>

#include "FtdcMdApiImpl.h"

#ifdef _WIN32
#define WINDOWS
#endif


#ifdef WINDOWS
#include <windows.h>
#else
#include <unistd.h>
#endif

#ifdef WINDOWS
#define GET_ACCURATE_USEC_TIME(v) 			\
	{					\
	SYSTEMTIME t;			\
	GetLocalTime(&t);		\
	v=t.wHour*3600000000+		\
	t.wMinute*60000000+	\
	t.wSecond*1000000+		\
	t.wMilliseconds*1000;	\
	}
#else
#define GET_ACCURATE_USEC_TIME(v)			\
	{					\
	struct timeval t;		\
	gettimeofday(&t,NULL);		\
	tm *now=localtime(&t.tv_sec);		\
	v=(long)now->tm_hour*3600000000 + (long)now->tm_min*60000000+now->tm_sec*1000000+		\
	t.tv_usec;		\
	}
#endif

#ifdef WINDOWS
#define SLEEP(ms) Sleep(ms)
#else
#define SLEEP(ms) sleep((ms)/1000)
#endif

void OnFrontConnected() {
    printf("Front Connected.");
}

int main() {
    ClientID id = InitApi("./flow/");

    SetCallbackFunOnFrontConnected(id, &OnFrontConnected);

    RegisterFront(id, "tcp://122.144.129.233:30027");

    Init(id);
    Join(id);

    for(int i=0; i<10; i++) {
        SLEEP(1000);
    }
}