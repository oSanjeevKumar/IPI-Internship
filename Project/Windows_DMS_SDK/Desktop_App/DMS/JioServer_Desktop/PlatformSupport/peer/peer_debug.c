/*
 * peer_debug.c
 * Copyright (C) 2007-2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#include <dlna_peer.h>
#include "peer_debug.h"

// log file
FILE *plat_log_file = NULL;

// open log file
void plat_file_init(char *strFile)
{
	plat_log_file = fopen(strFile, "w");
}

// debug print function
int plat_debugprintf(const char *format,
					 ...)
{
#define DEBUG_BUFFER_SIZE 500
	char strMsg[DEBUG_BUFFER_SIZE];
	int nRetVal;
	va_list argptr;
	
	va_start(argptr, format);
	nRetVal = _vsnprintf(strMsg, DEBUG_BUFFER_SIZE, format, argptr);
	va_end(argptr);
	
	// write this message to a log file if it exists
	if (plat_log_file) {
		SYSTEMTIME st;
		GetSystemTime(&st);
		fprintf(plat_log_file,
			"[0x%08X] (%4d.%03d) %s\n",
			GetCurrentThreadId(),
			st.wSecond,
			st.wMilliseconds,
			strMsg);
		fflush(plat_log_file);
	}
	return nRetVal;
}
/* Log printing callback function of application */
typedef void(*logPrintHandler) (void * in_arg, slim_char *str);


/* Initial parameter for NFLC dms core initialization */
struct wrapperInitParams {
	logPrintHandler logPrintCallback;  //Callback function to perform log printing in application layer
	void *callbackArg; //Argument specified by application layer that is used to call callback function
};

typedef struct wrapperInitParams wrapperInitParams_t;

wrapperInitParams_t wrapperparams;
slim_bool wrapperparams_set = 0;

void setWrapperInitParams(wrapperInitParams_t *in_params)
{
	wrapperparams = *in_params;
	wrapperparams_set = 1;
}

#if defined(_DEBUG)
void dlnaDebugPrintfPeer(char *format,
						 ...)
{
	va_list args;
	int nBuf;
	char szBuffer[4096] = {0};
	
	va_start(args, format);
	nBuf = _vsnprintf(szBuffer, 4096, format, args);
	va_end(args);
	OutputDebugStringA(szBuffer);
	printf(szBuffer);
	if (wrapperparams_set) {
		wrapperparams.logPrintCallback(wrapperparams.callbackArg, szBuffer);
	}
}
#endif
