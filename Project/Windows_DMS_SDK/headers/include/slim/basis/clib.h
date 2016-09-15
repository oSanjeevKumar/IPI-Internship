/*
	clib.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/basis/clib.h 75    05/12/28 12:07 Someya $ */

#ifndef SLIM_CLIB_H
#define SLIM_CLIB_H

#ifndef SLIM_BASE_H
#include <slim/basis/base.h>
#endif

SLIM_BEGIN_C_LINKAGE

/* string */

/* time */
struct slim_time_ {
	slim_int day;	/* days (either backward or forward) since 01 January, 1970 UTC */
	slim_int msec;	/* milliseconds since midnight [0-86399999] */
};
typedef struct slim_time_ slim_time;

struct slim_date_ {
	slim_int year;	/* Anno Domini year (0 means BC 1, -1 means BC 2, ...) */
	slim_int mon;	/* months since January [0-11] */
	slim_int mday;	/* day of the month [1-28,29,30,31] */
	slim_int wday;	/* days since Sunday [0-6] */
	slim_int yday;	/* days since January 1 [0-364,365] */
	slim_int hour;	/* hours since midnight [0-23] */
	slim_int min;	/* minutes after the hour [0-59] */
	slim_int sec;	/* seconds after the minute [0-59] */
	slim_int msec;	/* milliseconds after the second [0-999] */
};
typedef struct slim_date_ slim_date;


#ifdef SLIM_CONFIG_ENABLE_FILESYSTEM_PEER
/*
 * FileSystem
 */
struct slim_dirent_ {
	slim_char *fName; 
};

#define SLIM_STAT_IFMT	0x00170000
#define SLIM_STAT_IFREG	0x00100000
#define SLIM_STAT_IFDIR	0x00040000
#define SLIM_STAT_ISUID	0x00004000
#define SLIM_STAT_ISGID	0x00002000
#define SLIM_STAT_ISVTX	0x00001000
#define SLIM_STAT_IRWXU	0x00000700
#define SLIM_STAT_IRUSR	0x00000400
#define SLIM_STAT_IWUSR	0x00000200
#define SLIM_STAT_IXUSR	0x00000100
#define SLIM_STAT_IRWXG	0x00000070
#define SLIM_STAT_IRGRP	0x00000040
#define SLIM_STAT_IWGRP	0x00000020
#define SLIM_STAT_IXGRP	0x00000010
#define SLIM_STAT_IRWXO	0x00000007
#define SLIM_STAT_IROTH	0x00000004
#define SLIM_STAT_IWOTH	0x00000002
#define SLIM_STAT_IXOTH	0x00000001

struct slim_stat_ {
	slim_int fMode;
	slim_int fSize;
	slim_time fATime;
	slim_time fMTime;
	slim_time fCTime;
};

#define SLIM_STAT_IS_DIR(mode) (((mode) & SLIM_STAT_IFMT) == SLIM_STAT_IFDIR)
#define SLIM_STAT_IS_REG(mode) (((mode) & SLIM_STAT_IFMT) == SLIM_STAT_IFREG)

#endif /* SLIM_CONFIG_ENABLE_FILESYSTEM_PEER */

SLIM_END_C_LINKAGE

#endif
