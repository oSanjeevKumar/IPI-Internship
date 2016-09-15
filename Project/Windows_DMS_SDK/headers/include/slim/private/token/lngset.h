/*
	lngset.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/token/lngset.h 6     05/12/28 12:08 Someya $ */

/* DO NOT EDIT! This file is generated automatically. */

#ifndef SLIM_TOKEN_LNGSET_H
#define SLIM_TOKEN_LNGSET_H

#include <slim/basis/base.h>
#include <slim/basis/token.h>
#include <slim/token/lngsetid.h>

SLIM_BEGIN_C_LINKAGE

typedef struct TLangSetToken_ TLangSetToken;
struct TLangSetToken_ {
	TToken fBase;	/* must be the first field */
};

#define SLIM_TKOFF_BASE_LNGSET0	(0)
#define SLIM_TKNAM_BASE_LNGSET0	((slim_char *)cSlim_TokenName_LNGSET)
#define SLIM_TKOFF_LNGSET_en	(SLIM_TKOFF_BASE_LNGSET0 + 0)
#define SLIM_TKNAM_LNGSET_en	(SLIM_TKNAM_BASE_LNGSET0 + 0)
#define SLIM_TKLEN_LNGSET_en	(2)
#define SLIM_TOKEN_LNGSET_en	(LangSetToken_GetItem(SLIM_TKID_LNGSET_en))
#define SLIM_TKOFF_LNGSET_ja	(SLIM_TKOFF_BASE_LNGSET0 + 3)
#define SLIM_TKNAM_LNGSET_ja	(SLIM_TKNAM_BASE_LNGSET0 + 3)
#define SLIM_TKLEN_LNGSET_ja	(2)
#define SLIM_TOKEN_LNGSET_ja	(LangSetToken_GetItem(SLIM_TKID_LNGSET_ja))
#define SLIM_TKOFF_LNGSET_ko	(SLIM_TKOFF_BASE_LNGSET0 + 6)
#define SLIM_TKNAM_LNGSET_ko	(SLIM_TKNAM_BASE_LNGSET0 + 6)
#define SLIM_TKLEN_LNGSET_ko	(2)
#define SLIM_TOKEN_LNGSET_ko	(LangSetToken_GetItem(SLIM_TKID_LNGSET_ko))
#define SLIM_TKOFF_LNGSET_zn_cn	(SLIM_TKOFF_BASE_LNGSET0 + 9)
#define SLIM_TKNAM_LNGSET_zn_cn	(SLIM_TKNAM_BASE_LNGSET0 + 9)
#define SLIM_TKLEN_LNGSET_zn_cn	(5)
#define SLIM_TOKEN_LNGSET_zn_cn	(LangSetToken_GetItem(SLIM_TKID_LNGSET_zn_cn))
#define SLIM_TKOFF_LNGSET_zn_tw	(SLIM_TKOFF_BASE_LNGSET0 + 15)
#define SLIM_TKNAM_LNGSET_zn_tw	(SLIM_TKNAM_BASE_LNGSET0 + 15)
#define SLIM_TKLEN_LNGSET_zn_tw	(5)
#define SLIM_TOKEN_LNGSET_zn_tw	(LangSetToken_GetItem(SLIM_TKID_LNGSET_zn_tw))
#define SLIM_TKOFF_LNGSET_lv	(SLIM_TKOFF_BASE_LNGSET0 + 21)
#define SLIM_TKNAM_LNGSET_lv	(SLIM_TKNAM_BASE_LNGSET0 + 21)
#define SLIM_TKLEN_LNGSET_lv	(2)
#define SLIM_TOKEN_LNGSET_lv	(LangSetToken_GetItem(SLIM_TKID_LNGSET_lv))
#define SLIM_TKOFF_LNGSET_hr	(SLIM_TKOFF_BASE_LNGSET0 + 24)
#define SLIM_TKNAM_LNGSET_hr	(SLIM_TKNAM_BASE_LNGSET0 + 24)
#define SLIM_TKLEN_LNGSET_hr	(2)
#define SLIM_TOKEN_LNGSET_hr	(LangSetToken_GetItem(SLIM_TKID_LNGSET_hr))
#define SLIM_TKOFF_LNGSET_ru	(SLIM_TKOFF_BASE_LNGSET0 + 27)
#define SLIM_TKNAM_LNGSET_ru	(SLIM_TKNAM_BASE_LNGSET0 + 27)
#define SLIM_TKLEN_LNGSET_ru	(2)
#define SLIM_TOKEN_LNGSET_ru	(LangSetToken_GetItem(SLIM_TKID_LNGSET_ru))
#define SLIM_TKOFF_LNGSET_el	(SLIM_TKOFF_BASE_LNGSET0 + 30)
#define SLIM_TKNAM_LNGSET_el	(SLIM_TKNAM_BASE_LNGSET0 + 30)
#define SLIM_TKLEN_LNGSET_el	(2)
#define SLIM_TOKEN_LNGSET_el	(LangSetToken_GetItem(SLIM_TKID_LNGSET_el))
#define SLIM_TKOFF_LNGSET_et	(SLIM_TKOFF_BASE_LNGSET0 + 33)
#define SLIM_TKNAM_LNGSET_et	(SLIM_TKNAM_BASE_LNGSET0 + 33)
#define SLIM_TKLEN_LNGSET_et	(2)
#define SLIM_TOKEN_LNGSET_et	(LangSetToken_GetItem(SLIM_TKID_LNGSET_et))
#define SLIM_TKOFF_LNGSET_eo	(SLIM_TKOFF_BASE_LNGSET0 + 36)
#define SLIM_TKNAM_LNGSET_eo	(SLIM_TKNAM_BASE_LNGSET0 + 36)
#define SLIM_TKLEN_LNGSET_eo	(2)
#define SLIM_TOKEN_LNGSET_eo	(LangSetToken_GetItem(SLIM_TKID_LNGSET_eo))
#define SLIM_TKOFF_LNGSET_th	(SLIM_TKOFF_BASE_LNGSET0 + 39)
#define SLIM_TKNAM_LNGSET_th	(SLIM_TKNAM_BASE_LNGSET0 + 39)
#define SLIM_TKLEN_LNGSET_th	(2)
#define SLIM_TOKEN_LNGSET_th	(LangSetToken_GetItem(SLIM_TKID_LNGSET_th))
#define SLIM_TKOFF_LNGSET_tu	(SLIM_TKOFF_BASE_LNGSET0 + 42)
#define SLIM_TKNAM_LNGSET_tu	(SLIM_TKNAM_BASE_LNGSET0 + 42)
#define SLIM_TKLEN_LNGSET_tu	(2)
#define SLIM_TOKEN_LNGSET_tu	(LangSetToken_GetItem(SLIM_TKID_LNGSET_tu))
#define SLIM_TKOFF_LNGSET_ar	(SLIM_TKOFF_BASE_LNGSET0 + 45)
#define SLIM_TKNAM_LNGSET_ar	(SLIM_TKNAM_BASE_LNGSET0 + 45)
#define SLIM_TKLEN_LNGSET_ar	(2)
#define SLIM_TOKEN_LNGSET_ar	(LangSetToken_GetItem(SLIM_TKID_LNGSET_ar))
#define SLIM_TKOFF_LNGSET_iw	(SLIM_TKOFF_BASE_LNGSET0 + 48)
#define SLIM_TKNAM_LNGSET_iw	(SLIM_TKNAM_BASE_LNGSET0 + 48)
#define SLIM_TKLEN_LNGSET_iw	(2)
#define SLIM_TOKEN_LNGSET_iw	(LangSetToken_GetItem(SLIM_TKID_LNGSET_iw))
#define SLIM_TKOFF_LNGSET_universal	(SLIM_TKOFF_BASE_LNGSET0 + 51)
#define SLIM_TKNAM_LNGSET_universal	(SLIM_TKNAM_BASE_LNGSET0 + 51)
#define SLIM_TKLEN_LNGSET_universal	(9)
#define SLIM_TOKEN_LNGSET_universal	(LangSetToken_GetItem(SLIM_TKID_LNGSET_universal))
#define SLIM_TKOFF_BASE_LNGSET1	(SLIM_TKOFF_BASE_LNGSET0 + 61)
#define SLIM_TKNAM_BASE_LNGSET1	(SLIM_TKNAM_BASE_LNGSET0 + SLIM_TKOFF_BASE_LNGSET1)
#define SLIM_TKLEN_TOTAL_LNGSET	SLIM_TKOFF_BASE_LNGSET1

extern SLIM_ROM slim_char cSlim_TokenName_LNGSET[SLIM_TKLEN_TOTAL_LNGSET];

extern SLIM_ROM TLangSetToken cSlim_Token_LNGSET[SLIM_TOKEN_LNGSET_TOKENS];
#define LangSetToken_GetItem(id)		((TLangSetToken *)&cSlim_Token_LNGSET[(id)])
#define LangSetToken_GetItemName(id)	((slim_char *)cSlim_TokenName_LNGSET + ((TToken *)&cSlim_Token_LNGSET[(id)])->fOffset)
#define LangSetToken_GetItemNameLen(id)	(((TToken *)&cSlim_Token_LNGSET[(id)])->fLength)


SLIM_END_C_LINKAGE
#endif
