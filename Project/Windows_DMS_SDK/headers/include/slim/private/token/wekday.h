/*
	wekday.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/token/wekday.h 2     05/12/28 12:08 Someya $ */

/* DO NOT EDIT! This file is generated automagically. */

#ifndef SLIM_TOKEN_WEKDAY_H
#define SLIM_TOKEN_WEKDAY_H

#include <slim/basis/base.h>
#include <slim/private/token/wekdayid.h>

SLIM_BEGIN_C_LINKAGE

#define SLIM_TKOFF_BASE_WEKDAY0	(0)
#define SLIM_TKNAM_BASE_WEKDAY0	((slim_char *)cSlim_TokenName_WEKDAY)
#define SLIM_TKOFF_WEKDAY_Sunday	(SLIM_TKOFF_BASE_WEKDAY0 + 0)
#define SLIM_TKNAM_WEKDAY_Sunday	(SLIM_TKNAM_BASE_WEKDAY0 + 0)
#define SLIM_TKLEN_WEKDAY_Sunday	(6)
#define SLIM_TKOFF_WEKDAY_Monday	(SLIM_TKOFF_BASE_WEKDAY0 + 7)
#define SLIM_TKNAM_WEKDAY_Monday	(SLIM_TKNAM_BASE_WEKDAY0 + 7)
#define SLIM_TKLEN_WEKDAY_Monday	(6)
#define SLIM_TKOFF_WEKDAY_Tuesday	(SLIM_TKOFF_BASE_WEKDAY0 + 14)
#define SLIM_TKNAM_WEKDAY_Tuesday	(SLIM_TKNAM_BASE_WEKDAY0 + 14)
#define SLIM_TKLEN_WEKDAY_Tuesday	(7)
#define SLIM_TKOFF_WEKDAY_Wednesday	(SLIM_TKOFF_BASE_WEKDAY0 + 22)
#define SLIM_TKNAM_WEKDAY_Wednesday	(SLIM_TKNAM_BASE_WEKDAY0 + 22)
#define SLIM_TKLEN_WEKDAY_Wednesday	(9)
#define SLIM_TKOFF_WEKDAY_Thursday	(SLIM_TKOFF_BASE_WEKDAY0 + 32)
#define SLIM_TKNAM_WEKDAY_Thursday	(SLIM_TKNAM_BASE_WEKDAY0 + 32)
#define SLIM_TKLEN_WEKDAY_Thursday	(8)
#define SLIM_TKOFF_WEKDAY_Friday	(SLIM_TKOFF_BASE_WEKDAY0 + 41)
#define SLIM_TKNAM_WEKDAY_Friday	(SLIM_TKNAM_BASE_WEKDAY0 + 41)
#define SLIM_TKLEN_WEKDAY_Friday	(6)
#define SLIM_TKOFF_WEKDAY_Saturday	(SLIM_TKOFF_BASE_WEKDAY0 + 48)
#define SLIM_TKNAM_WEKDAY_Saturday	(SLIM_TKNAM_BASE_WEKDAY0 + 48)
#define SLIM_TKLEN_WEKDAY_Saturday	(8)
#define SLIM_TKOFF_BASE_WEKDAY1	(SLIM_TKOFF_BASE_WEKDAY0 + 57)
#define SLIM_TKNAM_BASE_WEKDAY1	(SLIM_TKNAM_BASE_WEKDAY0 + SLIM_TKOFF_BASE_WEKDAY1)
#define SLIM_TKLEN_TOTAL_WEKDAY	SLIM_TKOFF_BASE_WEKDAY1

extern SLIM_ROM slim_char cSlim_TokenName_WEKDAY[SLIM_TKLEN_TOTAL_WEKDAY];
extern SLIM_ROM slim_offlen cSlim_TokenOffLenTable_WEKDAY[SLIM_TOKEN_WEKDAY_TOKENS];

#define WeekDay_GetItemName(id)	((slim_char *)cSlim_TokenName_WEKDAY + cSlim_TokenOffLenTable_WEKDAY[(id)].off)
#define WeekDay_GetItemNameLen(id)	(cSlim_TokenOffLenTable_WEKDAY[(id)].len)


SLIM_END_C_LINKAGE
#endif
