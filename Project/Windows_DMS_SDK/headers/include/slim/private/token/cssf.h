/*
	cssf.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/token/cssf.h 21    05/12/28 12:08 Someya $ */

/* DO NOT EDIT! This file is generated automatically. */

#ifndef SLIM_TOKEN_CSSF_H
#define SLIM_TOKEN_CSSF_H

#include <slim/basis/base.h>
#include <slim/basis/token.h>
#include <slim/private/token/cssfid.h>

SLIM_BEGIN_C_LINKAGE

struct TCSSFuncInfo_ {
	TToken fBase;	/* must be the first field */
	slim_byte fValueType;
	slim_byte fFuncType;
};
typedef struct TCSSFuncInfo_ TCSSFuncInfo;

#define SLIM_TKOFF_BASE_CSSF0	(0)
#define SLIM_TKNAM_BASE_CSSF0	((slim_char *)cSlim_TokenName_CSSF)
#define SLIM_TKOFF_CSSF_rgb	(SLIM_TKOFF_BASE_CSSF0 + 0)
#define SLIM_TKNAM_CSSF_rgb	(SLIM_TKNAM_BASE_CSSF0 + 0)
#define SLIM_TKLEN_CSSF_rgb	(3)
#define SLIM_TOKEN_CSSF_rgb	(CSSFuncInfo_GetItem(SLIM_TKID_CSSF_rgb))
#define SLIM_TKOFF_CSSF_rect	(SLIM_TKOFF_BASE_CSSF0 + 4)
#define SLIM_TKNAM_CSSF_rect	(SLIM_TKNAM_BASE_CSSF0 + 4)
#define SLIM_TKLEN_CSSF_rect	(4)
#define SLIM_TOKEN_CSSF_rect	(CSSFuncInfo_GetItem(SLIM_TKID_CSSF_rect))
#define SLIM_TKOFF_CSSF_counter	(SLIM_TKOFF_BASE_CSSF0 + 9)
#define SLIM_TKNAM_CSSF_counter	(SLIM_TKNAM_BASE_CSSF0 + 9)
#define SLIM_TKLEN_CSSF_counter	(7)
#define SLIM_TOKEN_CSSF_counter	(CSSFuncInfo_GetItem(SLIM_TKID_CSSF_counter))
#define SLIM_TKOFF_CSSF_attr	(SLIM_TKOFF_BASE_CSSF0 + 17)
#define SLIM_TKNAM_CSSF_attr	(SLIM_TKNAM_BASE_CSSF0 + 17)
#define SLIM_TKLEN_CSSF_attr	(4)
#define SLIM_TOKEN_CSSF_attr	(CSSFuncInfo_GetItem(SLIM_TKID_CSSF_attr))
#define SLIM_TKOFF_CSSF_url	(SLIM_TKOFF_BASE_CSSF0 + 22)
#define SLIM_TKNAM_CSSF_url	(SLIM_TKNAM_BASE_CSSF0 + 22)
#define SLIM_TKLEN_CSSF_url	(3)
#define SLIM_TOKEN_CSSF_url	(CSSFuncInfo_GetItem(SLIM_TKID_CSSF_url))
#define SLIM_TKOFF_CSSF_format	(SLIM_TKOFF_BASE_CSSF0 + 26)
#define SLIM_TKNAM_CSSF_format	(SLIM_TKNAM_BASE_CSSF0 + 26)
#define SLIM_TKLEN_CSSF_format	(6)
#define SLIM_TOKEN_CSSF_format	(CSSFuncInfo_GetItem(SLIM_TKID_CSSF_format))
#define SLIM_TKOFF_CSSF_local	(SLIM_TKOFF_BASE_CSSF0 + 33)
#define SLIM_TKNAM_CSSF_local	(SLIM_TKNAM_BASE_CSSF0 + 33)
#define SLIM_TKLEN_CSSF_local	(5)
#define SLIM_TOKEN_CSSF_local	(CSSFuncInfo_GetItem(SLIM_TKID_CSSF_local))
#define SLIM_TKOFF_BASE_CSSF1	(SLIM_TKOFF_BASE_CSSF0 + 39)
#define SLIM_TKNAM_BASE_CSSF1	(SLIM_TKNAM_BASE_CSSF0 + SLIM_TKOFF_BASE_CSSF1)
#define SLIM_TKLEN_TOTAL_CSSF	SLIM_TKOFF_BASE_CSSF1

extern SLIM_ROM slim_char cSlim_TokenName_CSSF[SLIM_TKLEN_TOTAL_CSSF];

extern SLIM_ROM TCSSFuncInfo cSlim_Token_CSSF[SLIM_TOKEN_CSSF_TOKENS];
#define CSSFuncInfo_GetItem(id)		((TCSSFuncInfo *)&cSlim_Token_CSSF[(id)])
#define CSSFuncInfo_GetItemName(id)	((slim_char *)cSlim_TokenName_CSSF + ((TToken *)&cSlim_Token_CSSF[(id)])->fOffset)
#define CSSFuncInfo_GetItemNameLen(id)	(((TToken *)&cSlim_Token_CSSF[(id)])->fLength)

TCSSFuncInfo *CSSFuncInfo_FindSS(slim_char *in_s, slim_int in_slen);

SLIM_END_C_LINKAGE
#endif
