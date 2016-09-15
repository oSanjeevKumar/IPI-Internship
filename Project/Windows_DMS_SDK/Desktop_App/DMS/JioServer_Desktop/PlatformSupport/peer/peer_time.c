/*
 * peer_time.c
 * Copyright (C) 2007-2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#include <dlna_peer.h>
#define EPOCH_TIME 1900

#define COPY_TM_TO_DD(dd, tm) {	\
	(dd)->year = (tm)->tm_year + EPOCH_TIME; \
	(dd)->mon = (tm)->tm_mon;	\
	(dd)->mday = (tm)->tm_mday;	\
	(dd)->wday = (tm)->tm_wday;	\
	(dd)->yday = (tm)->tm_yday;	\
	(dd)->hour = (tm)->tm_hour;	\
	(dd)->min = (tm)->tm_min;	\
	(dd)->sec = (tm)->tm_sec;	\
	(dd)->msec = 0; }

// get current time in seconds
dlna_time_t dlna_time_currenttime(dlna_time_t *out_time)
{
	return (dlna_time_t)_time32((__time32_t *)out_time);
}

// get current time in seconds and mili-seconds
void dlna_timeval_get(dlna_timeval *timeval)
{
	time_t t;
	
	time(&t);
	timeval->tv_sec = (slim_word)t;
	timeval->tv_usec = 0;
}

void dlna_time_utcdate(dlna_time_t *in_time,
					   dlna_date *out_date)
{
	struct tm *tm;
	time_t timeval;

	timeval = *in_time;
	tm = gmtime(&timeval);
	
	COPY_TM_TO_DD(out_date, tm);
}

void dlna_time_localdate(dlna_time_t *in_time, dlna_date *out_date)
{
	struct tm *tm;
	time_t timeval;
	
	timeval = *in_time;
	tm = localtime(&timeval);
	
	COPY_TM_TO_DD(out_date, tm);
}

slim_int dlna_time_format(slim_char *out_s,
						  slim_int in_maxsize,
						  slim_char *in_format,
						  dlna_date *in_date)
{
	struct tm tm;
	
	memset(&tm, 0, sizeof(struct tm));
	tm.tm_year = in_date->year - EPOCH_TIME;
	tm.tm_mon = in_date->mon;
	tm.tm_mday = in_date->mday;
	tm.tm_wday = in_date->wday;
	tm.tm_yday = in_date->yday;
	tm.tm_hour = in_date->hour;
	tm.tm_min = in_date->min;
	tm.tm_sec = in_date->sec;

	return (slim_int)strftime(out_s, in_maxsize, in_format, &tm);
}

void dlna_time_usleep(slim_int in_microsec)
{
	Sleep((DWORD)(in_microsec / 1000));
}

// convert windows SYSTEMTIME to time_t
time_t winConvertSys2Timet(SYSTEMTIME *rSysTime)
{
	struct tm tmtime;
	time_t tt;

	tmtime.tm_year = rSysTime->wYear - 1900;
	tmtime.tm_mon = rSysTime->wMonth - 1;
	tmtime.tm_mday = rSysTime->wDay;
	tmtime.tm_wday = rSysTime->wDayOfWeek;
	tmtime.tm_hour = rSysTime->wHour;
	tmtime.tm_min = rSysTime->wMinute;
	tmtime.tm_sec = rSysTime->wSecond;

	tt = mktime(&tmtime);

	return tt;
}
