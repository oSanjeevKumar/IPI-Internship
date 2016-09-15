/*
	dom2m.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/token/dom2m.h 23    06/07/26 22:21 Endoh $ */

/* DO NOT EDIT! This file is generated automagically. */

#ifndef SLIM_TOKEN_DOM2M_H
#define SLIM_TOKEN_DOM2M_H

#include <slim/basis/base.h>
#include <slim/basis/token.h>
#include <slim/private/token/dom2mid.h>

SLIM_BEGIN_C_LINKAGE

#include <slim/www/dom.h>

void TDOMModuleEntry_SetDOM2IFNameTable(TDOMModuleEntry *self);
void TDOMModuleEntry_SetDOM2MethodProcTable(TDOMModuleEntry *self);

struct TDOM2IFInfo_ {
    slim_int fNodeType;
    slim_int fBaseIFType;
    slim_int fChildren[1];
};
typedef struct TDOM2IFInfo_ TDOM2IFInfo;
extern SLIM_ROM TDOM2IFInfo gSlim_DOM2IFInfo[];
struct TDOM2MethodInfo_ {
    TToken fBase;	/* must be the first field */
    slim_int fArgs;
    slim_int fFlags[1];
};
typedef struct TDOM2MethodInfo_ TDOM2MethodInfo;
slim_bool TDOM2MethodAttrInfo_CheckIF(slim_int* in_flags, slim_int in_iftype);

#define SLIM_TKOFF_BASE_DOM2M0	(0)
#define SLIM_TKNAM_BASE_DOM2M0	((slim_char *)cSlim_TokenName_DOM2M)
#define SLIM_TKOFF_DOM2M_append	(SLIM_TKOFF_BASE_DOM2M0 + 0)
#define SLIM_TKNAM_DOM2M_append	(SLIM_TKNAM_BASE_DOM2M0 + 0)
#define SLIM_TKLEN_DOM2M_append	(6)
#define SLIM_TOKEN_DOM2M_append	(DOM2MethodInfo_GetItem(SLIM_TKID_DOM2M_append))
#define SLIM_TKOFF_DOM2M_delete	(SLIM_TKOFF_BASE_DOM2M0 + 7)
#define SLIM_TKNAM_DOM2M_delete	(SLIM_TKNAM_BASE_DOM2M0 + 7)
#define SLIM_TKLEN_DOM2M_delete	(6)
#define SLIM_TOKEN_DOM2M_delete	(DOM2MethodInfo_GetItem(SLIM_TKID_DOM2M_delete))
#define SLIM_TKOFF_DOM2M_item	(SLIM_TKOFF_BASE_DOM2M0 + 14)
#define SLIM_TKNAM_DOM2M_item	(SLIM_TKNAM_BASE_DOM2M0 + 14)
#define SLIM_TKLEN_DOM2M_item	(4)
#define SLIM_TOKEN_DOM2M_item	(DOM2MethodInfo_GetItem(SLIM_TKID_DOM2M_item))
#define SLIM_TKOFF_DOM2M_toString	(SLIM_TKOFF_BASE_DOM2M0 + 19)
#define SLIM_TKNAM_DOM2M_toString	(SLIM_TKNAM_BASE_DOM2M0 + 19)
#define SLIM_TKLEN_DOM2M_toString	(8)
#define SLIM_TOKEN_DOM2M_toString	(DOM2MethodInfo_GetItem(SLIM_TKID_DOM2M_toString))
#define SLIM_TKOFF_DOM2M_valueOf	(SLIM_TKOFF_BASE_DOM2M0 + 28)
#define SLIM_TKNAM_DOM2M_valueOf	(SLIM_TKNAM_BASE_DOM2M0 + 28)
#define SLIM_TKLEN_DOM2M_valueOf	(7)
#define SLIM_TOKEN_DOM2M_valueOf	(DOM2MethodInfo_GetItem(SLIM_TKID_DOM2M_valueOf))
#define SLIM_TKOFF_BASE_DOM2M1	(SLIM_TKOFF_BASE_DOM2M0 + 36)
#define SLIM_TKNAM_BASE_DOM2M1	(SLIM_TKNAM_BASE_DOM2M0 + SLIM_TKOFF_BASE_DOM2M1)
#define SLIM_TKLEN_TOTAL_DOM2M	SLIM_TKOFF_BASE_DOM2M1

extern SLIM_ROM slim_char cSlim_TokenName_DOM2M[SLIM_TKLEN_TOTAL_DOM2M];

extern SLIM_ROM TDOM2MethodInfo cSlim_Token_DOM2M[SLIM_TOKEN_DOM2M_TOKENS];
#define DOM2MethodInfo_GetItem(id)		((TDOM2MethodInfo *)&cSlim_Token_DOM2M[(id)])
#define DOM2MethodInfo_GetItemName(id)	((slim_char *)cSlim_TokenName_DOM2M + ((TToken *)&cSlim_Token_DOM2M[(id)])->fOffset)
#define DOM2MethodInfo_GetItemNameLen(id)	(((TToken *)&cSlim_Token_DOM2M[(id)])->fLength)

TDOM2MethodInfo *DOM2MethodInfo_CaseFindSS(slim_char *in_s, slim_int in_slen);

SLIM_END_C_LINKAGE
#endif
