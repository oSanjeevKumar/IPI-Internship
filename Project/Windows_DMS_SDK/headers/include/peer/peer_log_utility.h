#ifndef DLNA_LOG_UTILITY_H
#define DLNA_LOG_UTILITY_H


/* Below logging levels FLAGS are used for development purpose to enable and disable read comments
 #################################################################################################
 # DEBUG -----> For general debugging with function name, line number and user info              #
 #              To enable this flag define it in Rule.in, e.g                                    #
 #              DEFS+=-DDLNA_LOG_ENABLE_DEBUG                                                    #
 #                                                                                               #
 # ERROR -----> For reporting error with function name, line number and user info.               #
 #              To enable this flag define it in Rule.in, e.g                                    #
 #              DEFS+=-DDLNA_LOG_ENABLE_ERROR                                                    #
 #                                                                                               #
 # TRACE -----> For packet tracing with file name, function name, line number and user info.     #
 #              To enable this flag define it in Rule.in, e.g                                    #
 #              DEFS+=-DDLNA_LOG_ENABLE_TRACE                                                    #
 #                                                                                               #
 # FATAL -----> For undefined system wide crash, with file name, function name, line number.     #
 #              To enable this flag define it in Rule.in, e.g                                    #
 #              DEFS+=-DDLNA_LOG_ENABLE_FATAL                                                    #
 #                                                                                               #
 # WARN ----->  For logging user/system warning with function name and line number.              #
 #              this is by default enabled                                                       #
 #              To disable this flag comment out it in Rule.in, e.g                              #
 #              //DEFS+=-DDLNA_LOG_ENABLE_DEBUG                                                  #
 #                                                                                               #
 # INFO ----->  For logging user information only, this is by default enabled                    #
 #              To disable this flag comment out it in Rule.in, e.g                              #
 #              //DEFS+=-DDLNA_LOG_ENABLE_INFO                                                   #
 #################################################################################################
 */

//Global variable use to enable log level at run time, defined in peer_log_utility.c
extern slim_char gLogLevel[];


/* Logging features */
#define DLNA_LOG_TYPE_LEVEL  1
#define DLNA_LOG_TYPE_MODULE 2

/* Logging levels */

/* In case of compile time only both values are set to max to enable and 0 to disable logging.
 * In case of runtime both values are set to max. Only runtime setting will be possible.
 * */
#define ENABLE_MODULE 0xFFFFFFFF

#ifndef DLNA_LOG_RUN_TIME
#define DISABLE_MODULE 0x00000000
#else /* DLNA_LOG_DLNA_LOG_RUN_TIME */
#define DISABLE_MODULE 0xFFFFFFFF
#endif /* DLNA_LOG_RUN_TIME */


/* Do not change this values */
#define DLNA_LOG_LEVEL_INFO  (0x01)
#define DLNA_LOG_LEVEL_WARN  (0x02)
#define DLNA_LOG_LEVEL_DEBUG (0x04)
#define DLNA_LOG_LEVEL_ERROR (0x08)
#define DLNA_LOG_LEVEL_TRACE (0x10)
#define DLNA_LOG_LEVEL_FATAL (0x20)
#define DLNA_LOG_LEVEL_OPTION_TS (0x80)

#ifdef COLOR_LOGGING
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
#else
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
#endif /* COLOR_LOGGING */

//#define DLNA_LOG(DEBUGID, LEVEL, ...)
//#ifndef ENABLE_DLNA_LOG
//#define DLNA_LOG(DEBUGID, LEVEL, ...)
//#else /* ENABLE_DLNA_LOG */
#define DLNA_LOG_DLNA_LOG_LEVEL_INFO  DLNA_LOG_INFO
#define DLNA_LOG_DLNA_LOG_LEVEL_WARN  DLNA_LOG_WARN
#define DLNA_LOG_DLNA_LOG_LEVEL_DEBUG DLNA_LOG_DEBUG
#define DLNA_LOG_DLNA_LOG_LEVEL_ERROR DLNA_LOG_ERROR
#define DLNA_LOG_DLNA_LOG_LEVEL_FATAL DLNA_LOG_FATAL
#define DLNA_LOG_DLNA_LOG_LEVEL_TRACE DLNA_LOG_TRACE

#define DLNA_LOG(DEBUGID, LEVEL, ...) \
  DLNA_LOG_##LEVEL(DEBUGID, LEVEL, ##__VA_ARGS__);
//#endif /* ENABLE_DLNA_LOG */

/*
 * If below three condition will meet only then log will be generated for run time
 * 1> checks whether user has enabled logging level, i.e LEVEL & gLogLevel
 * 2> if number of modules is greater or lesser than 32, that check is performed by 1st condition DEBUGID & WATERMARK
 * 3> 2nd condition Checks whether user has enabled this DEBUGID, i.e DEBUGID & gModuleIdMask
 */
#ifdef DLNA_LOG_RUN_TIME

#define DLNA_LOG_IS_ENABLED(DEBUGID, LEVEL) (LEVEL & gLogLevel[DEBUGID])

//#ifdef DLNA_LOG_ENABLE_INFO
  #define DLNA_LOG_INFO(DEBUGID, LEVEL, ...) \
    if (LEVEL & gLogLevel[DEBUGID]){ \
      dlnaLogPrintPeer( gLogMutex, gLogFd, LEVEL, (DLNA_LOG_LEVEL_OPTION_TS & gLogLevel[DEBUGID]), __FUNCTION__, __LINE__, __VA_ARGS__); \
    }
//#else /* DLNA_LOG_ENABLE_INFO */
//  #define DLNA_LOG_INFO(DEBUGID, LEVEL, ...)
//#endif /* DLNA_LOG_ENABLE_INFO */


//#ifdef DLNA_LOG_ENABLE_DEBUG
  #define DLNA_LOG_DEBUG(DEBUGID, LEVEL, ...) \
    if (LEVEL & gLogLevel[DEBUGID]){ \
      dlnaLogPrintPeer( gLogMutex, gLogFd, LEVEL, (DLNA_LOG_LEVEL_OPTION_TS & gLogLevel[DEBUGID]), __FUNCTION__, __LINE__, __VA_ARGS__); \
    }
//#else /* DLNA_LOG_ENABLE_DEBUG */
//  #define DLNA_LOG_DEBUG(DEBUGID, LEVEL, ...)
//#endif /* DLNA_LOG_ENABLE_DEBUG */

//#ifdef DLNA_LOG_ENABLE_WARN
  #define DLNA_LOG_WARN(DEBUGID, LEVEL, ...) \
    if (LEVEL & gLogLevel[DEBUGID]){ \
      dlnaLogPrintPeer( gLogMutex, gLogFd, LEVEL, (DLNA_LOG_LEVEL_OPTION_TS & gLogLevel[DEBUGID]), __FUNCTION__, __LINE__, __VA_ARGS__); \
    }

//#else /* DLNA_LOG_ENABLE_WARN */
//  #define DLNA_LOG_WARN(DEBUGID, LEVEL, ...)
//#endif /* DLNA_LOG_ENABLE_WARN */

//#ifdef DLNA_LOG_ENABLE_TRACE
  #define DLNA_LOG_TRACE(DEBUGID, LEVEL, ...) \
    if (LEVEL & gLogLevel[DEBUGID]){ \
      dlnaLogPrintPeer( gLogMutex, gLogFd, LEVEL, (DLNA_LOG_LEVEL_OPTION_TS & gLogLevel[DEBUGID]), __FUNCTION__, __LINE__, __VA_ARGS__); \
    }

//#else /* DLNA_LOG_ENABLE_TRACE */
//  #define DLNA_LOG_TRACE(DEBUGID, LEVEL, ...)
//#endif /* DLNA_LOG_ENABLE_TRACE */

//#ifdef DLNA_LOG_ENABLE_ERROR
  #define DLNA_LOG_ERROR(DEBUGID, LEVEL, ...) \
    if (LEVEL & gLogLevel[DEBUGID]){ \
      dlnaLogPrintPeer( gLogMutex, gLogFd, LEVEL, (DLNA_LOG_LEVEL_OPTION_TS & gLogLevel[DEBUGID]), __FUNCTION__,  __LINE__, __VA_ARGS__); \
    }

//#else /* DLNA_LOG_ENABLE_ERROR */
//  #define DLNA_LOG_ERROR(DEBUGID, LEVEL, ...)
//#endif /* DLNA_LOG_ENABLE_ERROR */

//#ifdef DLNA_LOG_ENABLE_FATAL
  #define DLNA_LOG_FATAL(DEBUGID, LEVEL, ...) \
    if (LEVEL & gLogLevel[DEBUGID]){ \
      dlnaLogPrintPeer( gLogMutex, gLogFd, LEVEL, (DLNA_LOG_LEVEL_OPTION_TS & gLogLevel[DEBUGID]), __FUNCTION__, __LINE__, __VA_ARGS__); \
    }

//#else /* DLNA_LOG_ENABLE_FATAL */
//  #define DLNA_LOG_FATAL(DEBUGID, LEVEL, ...)
//#endif /* DLNA_LOG_ENABLE_FATAL */

#else /* DLNA_LOG_RUN_TIME */

#define DLNA_LOG_IS_ENABLED(DEBUGID, LEVEL) (DEBUGID)

/*
 * Enable logging for Compile time only 
 */
#ifdef DLNA_LOG_ENABLE_INFO
  #define DLNA_LOG_INFO(DEBUGID, LEVEL, ...) \
    if (DEBUGID) { \
      dlnaLogPrintPeer( gLogMutex, gLogFd, LEVEL, (DLNA_LOG_LEVEL_OPTION_TS & gLogLevel[DEBUGID]), __FUNCTION__, __LINE__, __VA_ARGS__); \
    }
#else /* DLNA_LOG_ENABLE_INFO */
  #define DLNA_LOG_INFO(DEBUGID, LEVEL, ...)
#endif /* DLNA_LOG_ENABLE_INFO */

#ifdef DLNA_LOG_ENABLE_DEBUG
  #define DLNA_LOG_DEBUG(DEBUGID, LEVEL, ...) \
    if (DEBUGID) { \
      dlnaLogPrintPeer( gLogMutex, gLogFd, LEVEL, (DLNA_LOG_LEVEL_OPTION_TS & gLogLevel[DEBUGID]), __FUNCTION__, __LINE__, __VA_ARGS__); \
    }
#else /* DLNA_LOG_ENABLE_DEBUG */
  #define DLNA_LOG_DEBUG(DEBUGID, LEVEL, ...)
#endif /* DLNA_LOG_ENABLE_DEBUG */

#ifdef DLNA_LOG_ENABLE_WARN
  #define DLNA_LOG_WARN(DEBUGID, LEVEL, ...) \
    if (DEBUGID) { \
      dlnaLogPrintPeer( gLogMutex, gLogFd, LEVEL, (DLNA_LOG_LEVEL_OPTION_TS & gLogLevel[DEBUGID]), __FUNCTION__, __LINE__, __VA_ARGS__); \
    }
#else /* DLNA_LOG_ENABLE_WARN */
  #define DLNA_LOG_WARN(DEBUGID, LEVEL, ...)
#endif /* DLNA_LOG_ENABLE_WARN */

#ifdef DLNA_LOG_ENABLE_TRACE
  #define DLNA_LOG_TRACE(DEBUGID, LEVEL, ...) \
    if (DEBUGID) { \
      dlnaLogPrintPeer( gLogMutex, gLogFd, LEVEL, (DLNA_LOG_LEVEL_OPTION_TS & gLogLevel[DEBUGID]), __FUNCTION__,  __LINE__, __VA_ARGS__); \
    }
#else /* DLNA_LOG_ENABLE_TRACE */
  #define DLNA_LOG_TRACE(DEBUGID, LEVEL, ...)
#endif /* DLNA_LOG_ENABLE_TRACE */

#ifdef DLNA_LOG_ENABLE_ERROR
  #define DLNA_LOG_ERROR(DEBUGID, LEVEL, ...) \
    if (DEBUGID) { \
      dlnaLogPrintPeer( gLogMutex, gLogFd, LEVEL, (DLNA_LOG_LEVEL_OPTION_TS & gLogLevel[DEBUGID]), __FUNCTION__, __LINE__, __VA_ARGS__); \
    }
#else /* DLNA_LOG_ENABLE_ERROR */
  #define DLNA_LOG_ERROR(DEBUGID, LEVEL, ...)
#endif /* DLNA_LOG_ENABLE_ERROR */

#ifdef DLNA_LOG_ENABLE_FATAL
  #define DLNA_LOG_FATAL(DEBUGID, LEVEL, ...) \
    if (DEBUGID) { \
      dlnaLogPrintPeer( gLogMutex, gLogFd, LEVEL, (DLNA_LOG_LEVEL_OPTION_TS & gLogLevel[DEBUGID]), __FUNCTION__,  __LINE__, __VA_ARGS__); \
    }
#else /* DLNA_LOG_ENABLE_FATAL */
  #define DLNA_LOG_FATAL(DEBUGID, LEVEL, ...)
#endif /* DLNA_LOG_ENABLE_FATAL */

#endif /*DLNA_LOG_RUN_TIME*/

#endif /* DLNA_LOG_UTILITY_H */

