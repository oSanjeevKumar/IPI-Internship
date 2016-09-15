/*
	cssdm.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/token/cssdm.h 20    05/12/28 12:08 Someya $ */

/* DO NOT EDIT! This file is generated automatically. */

#ifndef SLIM_TOKEN_CSSDM_H
#define SLIM_TOKEN_CSSDM_H

#include <slim/basis/base.h>
#include <slim/basis/token.h>
#include <slim/token/cssdmid.h>

SLIM_BEGIN_C_LINKAGE

struct TCSSDimensionInfo_ {
	TToken fBase;	/* must be the first field */
	slim_int fValueType;
};
typedef struct TCSSDimensionInfo_ TCSSDimensionInfo;

#define SLIM_TKOFF_BASE_CSSDM0	(0)
#define SLIM_TKNAM_BASE_CSSDM0	((slim_char *)cSlim_TokenName_CSSDM)
#define SLIM_TKOFF_CSSDM_em	(SLIM_TKOFF_BASE_CSSDM0 + 0)
#define SLIM_TKNAM_CSSDM_em	(SLIM_TKNAM_BASE_CSSDM0 + 0)
#define SLIM_TKLEN_CSSDM_em	(2)
#define SLIM_TKOFF_CSSDM_ex	(SLIM_TKOFF_BASE_CSSDM0 + 3)
#define SLIM_TKNAM_CSSDM_ex	(SLIM_TKNAM_BASE_CSSDM0 + 3)
#define SLIM_TKLEN_CSSDM_ex	(2)
#define SLIM_TKOFF_CSSDM_px	(SLIM_TKOFF_BASE_CSSDM0 + 6)
#define SLIM_TKNAM_CSSDM_px	(SLIM_TKNAM_BASE_CSSDM0 + 6)
#define SLIM_TKLEN_CSSDM_px	(2)
#define SLIM_TKOFF_CSSDM_in	(SLIM_TKOFF_BASE_CSSDM0 + 9)
#define SLIM_TKNAM_CSSDM_in	(SLIM_TKNAM_BASE_CSSDM0 + 9)
#define SLIM_TKLEN_CSSDM_in	(2)
#define SLIM_TKOFF_CSSDM_cm	(SLIM_TKOFF_BASE_CSSDM0 + 12)
#define SLIM_TKNAM_CSSDM_cm	(SLIM_TKNAM_BASE_CSSDM0 + 12)
#define SLIM_TKLEN_CSSDM_cm	(2)
#define SLIM_TKOFF_CSSDM_mm	(SLIM_TKOFF_BASE_CSSDM0 + 15)
#define SLIM_TKNAM_CSSDM_mm	(SLIM_TKNAM_BASE_CSSDM0 + 15)
#define SLIM_TKLEN_CSSDM_mm	(2)
#define SLIM_TKOFF_CSSDM_pt	(SLIM_TKOFF_BASE_CSSDM0 + 18)
#define SLIM_TKNAM_CSSDM_pt	(SLIM_TKNAM_BASE_CSSDM0 + 18)
#define SLIM_TKLEN_CSSDM_pt	(2)
#define SLIM_TKOFF_CSSDM_pc	(SLIM_TKOFF_BASE_CSSDM0 + 21)
#define SLIM_TKNAM_CSSDM_pc	(SLIM_TKNAM_BASE_CSSDM0 + 21)
#define SLIM_TKLEN_CSSDM_pc	(2)
#define SLIM_TKOFF_CSSDM_deg	(SLIM_TKOFF_BASE_CSSDM0 + 24)
#define SLIM_TKNAM_CSSDM_deg	(SLIM_TKNAM_BASE_CSSDM0 + 24)
#define SLIM_TKLEN_CSSDM_deg	(3)
#define SLIM_TKOFF_CSSDM_rad	(SLIM_TKOFF_BASE_CSSDM0 + 28)
#define SLIM_TKNAM_CSSDM_rad	(SLIM_TKNAM_BASE_CSSDM0 + 28)
#define SLIM_TKLEN_CSSDM_rad	(3)
#define SLIM_TKOFF_CSSDM_grad	(SLIM_TKOFF_BASE_CSSDM0 + 32)
#define SLIM_TKNAM_CSSDM_grad	(SLIM_TKNAM_BASE_CSSDM0 + 32)
#define SLIM_TKLEN_CSSDM_grad	(4)
#define SLIM_TKOFF_CSSDM_ms	(SLIM_TKOFF_BASE_CSSDM0 + 37)
#define SLIM_TKNAM_CSSDM_ms	(SLIM_TKNAM_BASE_CSSDM0 + 37)
#define SLIM_TKLEN_CSSDM_ms	(2)
#define SLIM_TKOFF_CSSDM_s	(SLIM_TKOFF_BASE_CSSDM0 + 40)
#define SLIM_TKNAM_CSSDM_s	(SLIM_TKNAM_BASE_CSSDM0 + 40)
#define SLIM_TKLEN_CSSDM_s	(1)
#define SLIM_TKOFF_CSSDM_Hz	(SLIM_TKOFF_BASE_CSSDM0 + 42)
#define SLIM_TKNAM_CSSDM_Hz	(SLIM_TKNAM_BASE_CSSDM0 + 42)
#define SLIM_TKLEN_CSSDM_Hz	(2)
#define SLIM_TKOFF_CSSDM_kHz	(SLIM_TKOFF_BASE_CSSDM0 + 45)
#define SLIM_TKNAM_CSSDM_kHz	(SLIM_TKNAM_BASE_CSSDM0 + 45)
#define SLIM_TKLEN_CSSDM_kHz	(3)
#define SLIM_TKOFF_BASE_CSSDM1	(SLIM_TKOFF_BASE_CSSDM0 + 49)
#define SLIM_TKNAM_BASE_CSSDM1	(SLIM_TKNAM_BASE_CSSDM0 + SLIM_TKOFF_BASE_CSSDM1)
#define SLIM_TKLEN_TOTAL_CSSDM	SLIM_TKOFF_BASE_CSSDM1

extern SLIM_ROM slim_char cSlim_TokenName_CSSDM[SLIM_TKLEN_TOTAL_CSSDM];

extern SLIM_ROM TCSSDimensionInfo cSlim_Token_CSSDM[SLIM_TOKEN_CSSDM_TOKENS];
#define CSSDimensionInfo_GetItem(id)		((TCSSDimensionInfo *)&cSlim_Token_CSSDM[(id)])
#define CSSDimensionInfo_GetItemName(id)	((slim_char *)cSlim_TokenName_CSSDM + ((TToken *)&cSlim_Token_CSSDM[(id)])->fOffset)
#define CSSDimensionInfo_GetItemNameLen(id)	(((TToken *)&cSlim_Token_CSSDM[(id)])->fLength)

TCSSDimensionInfo *CSSDimensionInfo_FindSS(slim_char *in_s, slim_int in_slen);

SLIM_END_C_LINKAGE
#endif
