/*
	cssmt.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/token/cssmt.h 21    05/12/28 12:08 Someya $ */

/* DO NOT EDIT! This file is generated automatically. */

#ifndef SLIM_TOKEN_CSSMT_H
#define SLIM_TOKEN_CSSMT_H

#include <slim/basis/base.h>
#include <slim/basis/token.h>
#include <slim/token/cssmtid.h>

SLIM_BEGIN_C_LINKAGE

struct TCSSMediaTypeInfo_ {
	TToken fBase;	/* must be the first field */
	slim_int	fMediaGroups;
};
typedef struct TCSSMediaTypeInfo_ TCSSMediaTypeInfo;

#define SLIM_TKOFF_BASE_CSSMT0	(0)
#define SLIM_TKNAM_BASE_CSSMT0	((slim_char *)cSlim_TokenName_CSSMT)
#define SLIM_TKOFF_CSSMT_all	(SLIM_TKOFF_BASE_CSSMT0 + 0)
#define SLIM_TKNAM_CSSMT_all	(SLIM_TKNAM_BASE_CSSMT0 + 0)
#define SLIM_TKLEN_CSSMT_all	(3)
#define SLIM_TKOFF_CSSMT_aural	(SLIM_TKOFF_BASE_CSSMT0 + 4)
#define SLIM_TKNAM_CSSMT_aural	(SLIM_TKNAM_BASE_CSSMT0 + 4)
#define SLIM_TKLEN_CSSMT_aural	(5)
#define SLIM_TKOFF_CSSMT_braille	(SLIM_TKOFF_BASE_CSSMT0 + 10)
#define SLIM_TKNAM_CSSMT_braille	(SLIM_TKNAM_BASE_CSSMT0 + 10)
#define SLIM_TKLEN_CSSMT_braille	(7)
#define SLIM_TKOFF_CSSMT_embossed	(SLIM_TKOFF_BASE_CSSMT0 + 18)
#define SLIM_TKNAM_CSSMT_embossed	(SLIM_TKNAM_BASE_CSSMT0 + 18)
#define SLIM_TKLEN_CSSMT_embossed	(8)
#define SLIM_TKOFF_CSSMT_handheld	(SLIM_TKOFF_BASE_CSSMT0 + 27)
#define SLIM_TKNAM_CSSMT_handheld	(SLIM_TKNAM_BASE_CSSMT0 + 27)
#define SLIM_TKLEN_CSSMT_handheld	(8)
#define SLIM_TKOFF_CSSMT_print	(SLIM_TKOFF_BASE_CSSMT0 + 36)
#define SLIM_TKNAM_CSSMT_print	(SLIM_TKNAM_BASE_CSSMT0 + 36)
#define SLIM_TKLEN_CSSMT_print	(5)
#define SLIM_TKOFF_CSSMT_projection	(SLIM_TKOFF_BASE_CSSMT0 + 42)
#define SLIM_TKNAM_CSSMT_projection	(SLIM_TKNAM_BASE_CSSMT0 + 42)
#define SLIM_TKLEN_CSSMT_projection	(10)
#define SLIM_TKOFF_CSSMT_screen	(SLIM_TKOFF_BASE_CSSMT0 + 53)
#define SLIM_TKNAM_CSSMT_screen	(SLIM_TKNAM_BASE_CSSMT0 + 53)
#define SLIM_TKLEN_CSSMT_screen	(6)
#define SLIM_TKOFF_CSSMT_tty	(SLIM_TKOFF_BASE_CSSMT0 + 60)
#define SLIM_TKNAM_CSSMT_tty	(SLIM_TKNAM_BASE_CSSMT0 + 60)
#define SLIM_TKLEN_CSSMT_tty	(3)
#define SLIM_TKOFF_CSSMT_tv	(SLIM_TKOFF_BASE_CSSMT0 + 64)
#define SLIM_TKNAM_CSSMT_tv	(SLIM_TKNAM_BASE_CSSMT0 + 64)
#define SLIM_TKLEN_CSSMT_tv	(2)
#define SLIM_TKOFF_BASE_CSSMT1	(SLIM_TKOFF_BASE_CSSMT0 + 67)
#define SLIM_TKNAM_BASE_CSSMT1	(SLIM_TKNAM_BASE_CSSMT0 + SLIM_TKOFF_BASE_CSSMT1)
#define SLIM_TKLEN_TOTAL_CSSMT	SLIM_TKOFF_BASE_CSSMT1

extern SLIM_ROM slim_char cSlim_TokenName_CSSMT[SLIM_TKLEN_TOTAL_CSSMT];

extern SLIM_ROM TCSSMediaTypeInfo cSlim_Token_CSSMT[SLIM_TOKEN_CSSMT_TOKENS];
#define CSSMediaTypeInfo_GetItem(id)		((TCSSMediaTypeInfo *)&cSlim_Token_CSSMT[(id)])
#define CSSMediaTypeInfo_GetItemName(id)	((slim_char *)cSlim_TokenName_CSSMT + ((TToken *)&cSlim_Token_CSSMT[(id)])->fOffset)
#define CSSMediaTypeInfo_GetItemNameLen(id)	(((TToken *)&cSlim_Token_CSSMT[(id)])->fLength)

TCSSMediaTypeInfo *CSSMediaTypeInfo_FindSS(slim_char *in_s, slim_int in_slen);

SLIM_END_C_LINKAGE
#endif
