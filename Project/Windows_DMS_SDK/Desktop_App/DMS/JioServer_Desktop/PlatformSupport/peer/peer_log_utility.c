/* peer_log_utility.c
* Copyright (C) 2011 ACCESS CO.,LTD.
* All rights are reserved by ACCESS CO.,LTD., whether the whole or part
* of the source code including any modifications is concerned.
*
* This is an unpublished source code of ACCESS CO.,LTD., and must be
* treated as confidential material.  The above copyright notice does
* not evidence any actual or intended publication of this source code.
*/
#include <stdio.h>
#include <stdarg.h>
#include <errno.h>
#include <ctype.h>
#include <slim/libcore.h>

#include <dlna_peer.h>
#include <peer_log_utility.h>

#ifdef DLNA_LOG_ENABLE_COLOR
/* Color defination */
#define DLNA_PRINTF_COLOR_DEFAULT "\33[0m"
#define DLNA_PRINTF_COLOR_RESET   "\33[0m"
#define DLNA_PRINTF_COLOR_BLACK   "\33[30m"
#define DLNA_PRINTF_COLOR_RED     "\33[31m"
#define DLNA_PRINTF_COLOR_GREEN   "\33[32m"
#define DLNA_PRINTF_COLOR_YELLOW  "\33[33m"
#define DLNA_PRINTF_COLOR_BLUE    "\33[34m"
#define DLNA_PRINTF_COLOR_MAGENTA "\33[35m"
#define DLNA_PRINTF_COLOR_CYAN    "\33[36m"
#define DLNA_PRINTF_COLOR_WHITE   "\33[37m"
#else /* DLNA_LOG_ENABLE_COLOR */
#define DLNA_PRINTF_COLOR_DEFAULT ""
#define DLNA_PRINTF_COLOR_RESET   ""
#define DLNA_PRINTF_COLOR_BLACK   ""
#define DLNA_PRINTF_COLOR_RED     ""
#define DLNA_PRINTF_COLOR_GREEN   ""
#define DLNA_PRINTF_COLOR_YELLOW  ""
#define DLNA_PRINTF_COLOR_BLUE    ""
#define DLNA_PRINTF_COLOR_MAGENTA ""
#define DLNA_PRINTF_COLOR_CYAN    ""
#define DLNA_PRINTF_COLOR_WHITE   ""
#endif /* DLNA_LOG_ENABLE_COLOR */




void
dlnaLogPrintRawPeer(const char *in_format, ...)
{
  va_list ap;
  int nBuf;
  slim_char szBuffer[4096] = { 0 };

  va_start(ap, in_format);
  nBuf = _vsnprintf(szBuffer, 4096, in_format, ap);
  va_end(ap);

  OutputDebugStringA(szBuffer);
  printf(szBuffer);  // why two different prints here ?

}


void
dlnaLogPrintPeer(dlna_mutex in_mutex, dlna_file_t in_fd, int level, int ts, const char *function, int line, const char *in_format, ...)
{
  va_list ap;
  dlna_date date_tmp; 
  dlna_timeval current_timeval;
  int nBuf;
  slim_char szBuffer[4096] = { 0 };
 
  if ( in_mutex ) {
    dlnaThreadMutexLockPeer(in_mutex);
  }

  if (! in_fd) {

    if( ts ) {
      dlna_timeval_get(&current_timeval); 
      dlnaGetDlnaDate(&current_timeval, &date_tmp); 
      nBuf = snprintf(szBuffer, 4096,"[%02d:%02d:%02d.%03d]", date_tmp.hour, date_tmp.min, date_tmp.sec, date_tmp.msec);

      OutputDebugStringA(szBuffer);
      printf(szBuffer);  // why two different prints here ?
    }

    switch( level ) {
      case DLNA_LOG_LEVEL_INFO:
        nBuf = snprintf(szBuffer, 4096,"[INFO]: ");
      break ;
      case DLNA_LOG_LEVEL_WARN:
        nBuf = snprintf(szBuffer, 4096,"%s[WARN]:%s[%d]: ",DLNA_PRINTF_COLOR_YELLOW, function, line);
      break ;
      case DLNA_LOG_LEVEL_DEBUG:
        nBuf = snprintf(szBuffer, 4096,"[DEBUG]:%s[%d]: ", function, line);
      break ;
      case DLNA_LOG_LEVEL_ERROR:
        nBuf = snprintf(szBuffer, 4096,"%s[ERROR]:%s[%d]: ",DLNA_PRINTF_COLOR_RED, function, line);
      break ;
      case DLNA_LOG_LEVEL_TRACE:
        nBuf = snprintf(szBuffer, 4096,"[TRACE]:%s[%d]: ", function, line);
      break ;
      case DLNA_LOG_LEVEL_FATAL:
        nBuf = snprintf(szBuffer, 4096,"%s[FATAL]:%s[%d]: ",DLNA_PRINTF_COLOR_RED, function, line);
      break ;

    }
    OutputDebugStringA(szBuffer);
    printf(szBuffer);  // why two different prints here ?


    va_start(ap, in_format);
    nBuf = _vsnprintf(szBuffer, 4096, in_format, ap);
    va_end(ap);
    OutputDebugStringA(szBuffer);
    printf(szBuffer);  // why two different prints here ?

    
    switch( level ) {
      case DLNA_LOG_LEVEL_WARN:
      case DLNA_LOG_LEVEL_ERROR:
      case DLNA_LOG_LEVEL_FATAL:
        nBuf = snprintf(szBuffer,4096,"%s\n",DLNA_PRINTF_COLOR_RESET);
      break ;
     
      default:
        nBuf = snprintf(szBuffer,4096,"\n") ;
      break ;
    }
    OutputDebugStringA(szBuffer);
    printf(szBuffer);  // why two different prints here ?


  } else {
    if( ts ) {
      dlna_timeval_get(&current_timeval); 
      dlnaGetDlnaDate(&current_timeval, &date_tmp); 
      nBuf = snprintf(szBuffer, 4096,"[%02d:%02d:%02d.%03d]", date_tmp.hour, date_tmp.min, date_tmp.sec, date_tmp.msec);
      dlnaFileWritePeer(in_fd, szBuffer, nBuf );
    }

    switch( level ) {
      case DLNA_LOG_LEVEL_INFO:
        nBuf = snprintf(szBuffer, 4096,"[INFO]: ");
      break ;
      case DLNA_LOG_LEVEL_WARN:
        nBuf = snprintf(szBuffer, 4096,"[WARN]:%s[%d]: ", function, line);
      break ;
      case DLNA_LOG_LEVEL_DEBUG:
        nBuf = snprintf(szBuffer, 4096,"[DEBUG]:%s[%d]: ", function, line);
      break ;
      case DLNA_LOG_LEVEL_ERROR:
        nBuf = snprintf(szBuffer, 4096,"[ERROR]:%s[%d]: ", function, line);
      break ;
      case DLNA_LOG_LEVEL_TRACE:
        nBuf = snprintf(szBuffer, 4096,"[TRACE]:%s[%d]: ", function, line);
      break ;
      case DLNA_LOG_LEVEL_FATAL:
        nBuf = snprintf(szBuffer, 4096,"[FATAL]:%s[%d]: ", function, line);
      break ;
    }
    dlnaFileWritePeer(in_fd, szBuffer, nBuf );
    va_start(ap, in_format);
    nBuf = _vsnprintf(szBuffer, 4096, in_format, ap);
    dlnaFileWritePeer(in_fd, szBuffer, nBuf);
    va_end(ap);

    dlnaFileWritePeer(in_fd, (slim_char*)"\n", 1);
  }

  if ( in_mutex ) {
    dlnaThreadMutexUnlockPeer(in_mutex);
  }
}

