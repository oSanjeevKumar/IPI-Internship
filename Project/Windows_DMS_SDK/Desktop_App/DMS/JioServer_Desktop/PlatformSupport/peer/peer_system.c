/*
 * peer_system.c
 * Copyright (C) 2007-2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#include "dlna_peer.h"
#include "peer_system.h"

slim_int dlnaSystemGetPropertyPeer(slim_int in_key,
  slim_char *out_value,
  slim_int in_value_buf_len)
{
  //composing in device type usijng PAL_USER_AGENT_STR + gethostname()
  slim_int str_len = -1;
  char hostname[32] = { 0 };
  slim_int is_hostname = slim_false;
  SYSTEM_INFO siSysInfo;
  int sysInfoID = -1;
  char *x86 = "x86";
  char *x64 = "x64";
  switch (in_key) {
  case NFLC_SYS_PROP_USERAGENT:
    str_len = strlen(SAMPLE_USER_AGENT_STR);
    if (gethostname(hostname, 32) == 0) {
      str_len = str_len + strlen(hostname);
      is_hostname = slim_true;
    }
    else {
      str_len = str_len + 6;
    }
    if (out_value) {
      if ((str_len + 1) <= in_value_buf_len) {
        strcpy((char *)out_value, SAMPLE_USER_AGENT_STR);
        if (is_hostname) {
          strcat((char *)out_value, hostname);
        }
        else {
          strcat((char *)out_value, DEFAULT_DEVICE_NAME);
        }
      }
      else {
        str_len = -1;
      }
    }
    break;
  case NFLC_SYS_PROP_PLATFORM:
    *out_value = 0;
    strcpy((char *)out_value, "OS/Windows");
    strcat((char *)out_value, " HW/");

    GetSystemInfo(&siSysInfo);
    sysInfoID = siSysInfo.wProcessorArchitecture;
    sysInfoID == 0 ? strcat((char *)out_value, x86) : strcat((char *)out_value, x64);
    str_len = strlen(out_value);
    break;

 case NFLC_SYS_PROP_SYSTEMID:
    *out_value = 0 ;
    gethostname(hostname, 32)  ;
    str_len = strlen( hostname ) ;
    if ((str_len + 1) <= in_value_buf_len) {
      strcpy((char *)out_value, hostname);
    }
  break ;

  default:
    break;
  }
  return str_len;
}

slim_bool dlna_time_mktime(const slim_char *par_datetime,
						   const slim_char* par_format,
						   dlna_time_t *par_out_time)
{
    time_t rawtime;
    struct tm *tm;
    if ((!par_datetime) || !(*par_datetime)) {
      DLNA_LOG(DLNA_LOG_PEER_SYSTEM, DLNA_LOG_LEVEL_ERROR, "par_datetime value is null");
      return slim_false;
    }
    time(&rawtime);
    tm = localtime(&rawtime);

    dlna_sscanf(par_datetime,
	    par_format,
	    &tm->tm_year,
	    &tm->tm_mon,
	    &tm->tm_mday,
	    &tm->tm_hour,
	    &tm->tm_min,
	    &tm->tm_sec);
	
    tm->tm_year -= 1900;
    tm->tm_mon -= 1;
    //todo: check:
    // tm->tm_hour += 1;
	
    *par_out_time = mktime(tm);
    return slim_true;
}

slim_int dlnaGetCurrentDatePeer(slim_int *out_year,
								slim_int *out_mon,
								slim_int *out_mday,
								slim_int *out_hour,
								slim_int *out_min,
								slim_int *out_sec,
								slim_int *out_msec)
{
	SYSTEMTIME now;
	GetSystemTime(&now);
	*out_year = now.wYear + 1900;
	*out_mon  = now.wMonth;
	*out_mday = now.wDay;
	*out_hour = now.wHour;
	*out_min  = now.wMinute;
	*out_sec  = now.wSecond;
	*out_msec = now.wMilliseconds;
	return SLIM_E_OK;
}

void
dlnaGetDlnaDate(dlna_timeval *in_timeval, dlna_date *out_date)
{
	SYSTEMTIME now;

	now.wSecond = in_timeval->tv_sec;
	now.wMilliseconds = in_timeval->tv_usec;

	GetSystemTime(&now);

	out_date->year = now.wYear + 1900;
	out_date->mon = now.wMonth;
	out_date->mday = now.wDay;
	out_date->hour = now.wHour;
	out_date->min = now.wMinute;
	out_date->sec = now.wSecond;
	out_date->msec = now.wMilliseconds;
}

slim_double
dlna_log10(slim_double x)
{
	if(x == 0){
		return 0;
	}
	return log10(x);
}
