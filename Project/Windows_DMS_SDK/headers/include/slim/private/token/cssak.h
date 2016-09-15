/*
	cssak.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/token/cssak.h 20    05/12/28 12:08 Someya $ */

/* DO NOT EDIT! This file is generated automatically. */

#ifndef SLIM_TOKEN_CSSAK_H
#define SLIM_TOKEN_CSSAK_H

#include <slim/basis/base.h>
#include <slim/basis/token.h>
#include <slim/private/token/cssakid.h>

SLIM_BEGIN_C_LINKAGE

struct TCSSAtKeywordInfo_ {
	TToken fBase;	/* must be the first field */
};
typedef struct TCSSAtKeywordInfo_ TCSSAtKeywordInfo;

#define SLIM_TKOFF_BASE_CSSAK0	(0)
#define SLIM_TKNAM_BASE_CSSAK0	((slim_char *)cSlim_TokenName_CSSAK)
#define SLIM_TKOFF_CSSAK_import	(SLIM_TKOFF_BASE_CSSAK0 + 0)
#define SLIM_TKNAM_CSSAK_import	(SLIM_TKNAM_BASE_CSSAK0 + 0)
#define SLIM_TKLEN_CSSAK_import	(6)
#define SLIM_TOKEN_CSSAK_import	(CSSAtKeywordInfo_GetItem(SLIM_TKID_CSSAK_import))
#define SLIM_TKOFF_CSSAK_page	(SLIM_TKOFF_BASE_CSSAK0 + 7)
#define SLIM_TKNAM_CSSAK_page	(SLIM_TKNAM_BASE_CSSAK0 + 7)
#define SLIM_TKLEN_CSSAK_page	(4)
#define SLIM_TOKEN_CSSAK_page	(CSSAtKeywordInfo_GetItem(SLIM_TKID_CSSAK_page))
#define SLIM_TKOFF_CSSAK_media	(SLIM_TKOFF_BASE_CSSAK0 + 12)
#define SLIM_TKNAM_CSSAK_media	(SLIM_TKNAM_BASE_CSSAK0 + 12)
#define SLIM_TKLEN_CSSAK_media	(5)
#define SLIM_TOKEN_CSSAK_media	(CSSAtKeywordInfo_GetItem(SLIM_TKID_CSSAK_media))
#define SLIM_TKOFF_CSSAK_font_face	(SLIM_TKOFF_BASE_CSSAK0 + 18)
#define SLIM_TKNAM_CSSAK_font_face	(SLIM_TKNAM_BASE_CSSAK0 + 18)
#define SLIM_TKLEN_CSSAK_font_face	(9)
#define SLIM_TOKEN_CSSAK_font_face	(CSSAtKeywordInfo_GetItem(SLIM_TKID_CSSAK_font_face))
#define SLIM_TKOFF_CSSAK_charset	(SLIM_TKOFF_BASE_CSSAK0 + 28)
#define SLIM_TKNAM_CSSAK_charset	(SLIM_TKNAM_BASE_CSSAK0 + 28)
#define SLIM_TKLEN_CSSAK_charset	(7)
#define SLIM_TOKEN_CSSAK_charset	(CSSAtKeywordInfo_GetItem(SLIM_TKID_CSSAK_charset))
#define SLIM_TKOFF_BASE_CSSAK1	(SLIM_TKOFF_BASE_CSSAK0 + 36)
#define SLIM_TKNAM_BASE_CSSAK1	(SLIM_TKNAM_BASE_CSSAK0 + SLIM_TKOFF_BASE_CSSAK1)
#define SLIM_TKLEN_TOTAL_CSSAK	SLIM_TKOFF_BASE_CSSAK1

extern SLIM_ROM slim_char cSlim_TokenName_CSSAK[SLIM_TKLEN_TOTAL_CSSAK];

extern SLIM_ROM TCSSAtKeywordInfo cSlim_Token_CSSAK[SLIM_TOKEN_CSSAK_TOKENS];
#define CSSAtKeywordInfo_GetItem(id)		((TCSSAtKeywordInfo *)&cSlim_Token_CSSAK[(id)])
#define CSSAtKeywordInfo_GetItemName(id)	((slim_char *)cSlim_TokenName_CSSAK + ((TToken *)&cSlim_Token_CSSAK[(id)])->fOffset)
#define CSSAtKeywordInfo_GetItemNameLen(id)	(((TToken *)&cSlim_Token_CSSAK[(id)])->fLength)

TCSSAtKeywordInfo *CSSAtKeywordInfo_FindSS(slim_char *in_s, slim_int in_slen);

SLIM_END_C_LINKAGE
#endif
