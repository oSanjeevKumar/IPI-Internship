/*
	month.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/token/month.h 2     05/12/28 12:08 Someya $ */

/* DO NOT EDIT! This file is generated automagically. */

#ifndef SLIM_TOKEN_MONTH_H
#define SLIM_TOKEN_MONTH_H

#include <slim/basis/base.h>
#include <slim/private/token/monthid.h>

SLIM_BEGIN_C_LINKAGE

#define SLIM_TKOFF_BASE_MONTH0	(0)
#define SLIM_TKNAM_BASE_MONTH0	((slim_char *)cSlim_TokenName_MONTH)
#define SLIM_TKOFF_MONTH_January	(SLIM_TKOFF_BASE_MONTH0 + 0)
#define SLIM_TKNAM_MONTH_January	(SLIM_TKNAM_BASE_MONTH0 + 0)
#define SLIM_TKLEN_MONTH_January	(7)
#define SLIM_TKOFF_MONTH_February	(SLIM_TKOFF_BASE_MONTH0 + 8)
#define SLIM_TKNAM_MONTH_February	(SLIM_TKNAM_BASE_MONTH0 + 8)
#define SLIM_TKLEN_MONTH_February	(8)
#define SLIM_TKOFF_MONTH_March	(SLIM_TKOFF_BASE_MONTH0 + 17)
#define SLIM_TKNAM_MONTH_March	(SLIM_TKNAM_BASE_MONTH0 + 17)
#define SLIM_TKLEN_MONTH_March	(5)
#define SLIM_TKOFF_MONTH_April	(SLIM_TKOFF_BASE_MONTH0 + 23)
#define SLIM_TKNAM_MONTH_April	(SLIM_TKNAM_BASE_MONTH0 + 23)
#define SLIM_TKLEN_MONTH_April	(5)
#define SLIM_TKOFF_MONTH_May	(SLIM_TKOFF_BASE_MONTH0 + 29)
#define SLIM_TKNAM_MONTH_May	(SLIM_TKNAM_BASE_MONTH0 + 29)
#define SLIM_TKLEN_MONTH_May	(3)
#define SLIM_TKOFF_MONTH_June	(SLIM_TKOFF_BASE_MONTH0 + 33)
#define SLIM_TKNAM_MONTH_June	(SLIM_TKNAM_BASE_MONTH0 + 33)
#define SLIM_TKLEN_MONTH_June	(4)
#define SLIM_TKOFF_MONTH_July	(SLIM_TKOFF_BASE_MONTH0 + 38)
#define SLIM_TKNAM_MONTH_July	(SLIM_TKNAM_BASE_MONTH0 + 38)
#define SLIM_TKLEN_MONTH_July	(4)
#define SLIM_TKOFF_MONTH_August	(SLIM_TKOFF_BASE_MONTH0 + 43)
#define SLIM_TKNAM_MONTH_August	(SLIM_TKNAM_BASE_MONTH0 + 43)
#define SLIM_TKLEN_MONTH_August	(6)
#define SLIM_TKOFF_MONTH_September	(SLIM_TKOFF_BASE_MONTH0 + 50)
#define SLIM_TKNAM_MONTH_September	(SLIM_TKNAM_BASE_MONTH0 + 50)
#define SLIM_TKLEN_MONTH_September	(9)
#define SLIM_TKOFF_MONTH_October	(SLIM_TKOFF_BASE_MONTH0 + 60)
#define SLIM_TKNAM_MONTH_October	(SLIM_TKNAM_BASE_MONTH0 + 60)
#define SLIM_TKLEN_MONTH_October	(7)
#define SLIM_TKOFF_MONTH_November	(SLIM_TKOFF_BASE_MONTH0 + 68)
#define SLIM_TKNAM_MONTH_November	(SLIM_TKNAM_BASE_MONTH0 + 68)
#define SLIM_TKLEN_MONTH_November	(8)
#define SLIM_TKOFF_MONTH_December	(SLIM_TKOFF_BASE_MONTH0 + 77)
#define SLIM_TKNAM_MONTH_December	(SLIM_TKNAM_BASE_MONTH0 + 77)
#define SLIM_TKLEN_MONTH_December	(8)
#define SLIM_TKOFF_BASE_MONTH1	(SLIM_TKOFF_BASE_MONTH0 + 86)
#define SLIM_TKNAM_BASE_MONTH1	(SLIM_TKNAM_BASE_MONTH0 + SLIM_TKOFF_BASE_MONTH1)
#define SLIM_TKLEN_TOTAL_MONTH	SLIM_TKOFF_BASE_MONTH1

extern SLIM_ROM slim_char cSlim_TokenName_MONTH[SLIM_TKLEN_TOTAL_MONTH];
extern SLIM_ROM slim_offlen cSlim_TokenOffLenTable_MONTH[SLIM_TOKEN_MONTH_TOKENS];

#define Month_GetItemName(id)	((slim_char *)cSlim_TokenName_MONTH + cSlim_TokenOffLenTable_MONTH[(id)].off)
#define Month_GetItemNameLen(id)	(cSlim_TokenOffLenTable_MONTH[(id)].len)


SLIM_END_C_LINKAGE
#endif
