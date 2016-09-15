/*
	xmlat.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/token/xmlat.h 1     06/06/19 19:05 Yamabuti $ */

/* DO NOT EDIT! This file is generated automagically. */

#ifndef SLIM_TOKEN_XMLAT_H
#define SLIM_TOKEN_XMLAT_H

#include <slim/basis/base.h>
#include <slim/basis/token.h>
#include <slim/private/token/xmlatid.h>

SLIM_BEGIN_C_LINKAGE

#include <slim/www/xmloutln.h>


#define SLIM_TKOFF_BASE_XMLAT0	(0)
#define SLIM_TKNAM_BASE_XMLAT0	((slim_char *)cSlim_TokenName_XMLAT)
#define SLIM_TKOFF_XMLAT_base	(SLIM_TKOFF_BASE_XMLAT0 + 0)
#define SLIM_TKNAM_XMLAT_base	(SLIM_TKNAM_BASE_XMLAT0 + 0)
#define SLIM_TKLEN_XMLAT_base	(4)
#define SLIM_TOKEN_XMLAT_base	(XMLAttrInfo_GetItem(SLIM_TKID_XMLAT_base))
#define SLIM_TKOFF_XMLAT_id	(SLIM_TKOFF_BASE_XMLAT0 + 5)
#define SLIM_TKNAM_XMLAT_id	(SLIM_TKNAM_BASE_XMLAT0 + 5)
#define SLIM_TKLEN_XMLAT_id	(2)
#define SLIM_TOKEN_XMLAT_id	(XMLAttrInfo_GetItem(SLIM_TKID_XMLAT_id))
#define SLIM_TKOFF_XMLAT_lang	(SLIM_TKOFF_BASE_XMLAT0 + 8)
#define SLIM_TKNAM_XMLAT_lang	(SLIM_TKNAM_BASE_XMLAT0 + 8)
#define SLIM_TKLEN_XMLAT_lang	(4)
#define SLIM_TOKEN_XMLAT_lang	(XMLAttrInfo_GetItem(SLIM_TKID_XMLAT_lang))
#define SLIM_TKOFF_XMLAT_space	(SLIM_TKOFF_BASE_XMLAT0 + 13)
#define SLIM_TKNAM_XMLAT_space	(SLIM_TKNAM_BASE_XMLAT0 + 13)
#define SLIM_TKLEN_XMLAT_space	(5)
#define SLIM_TOKEN_XMLAT_space	(XMLAttrInfo_GetItem(SLIM_TKID_XMLAT_space))
#define SLIM_TKOFF_BASE_XMLAT1	(SLIM_TKOFF_BASE_XMLAT0 + 19)
#define SLIM_TKNAM_BASE_XMLAT1	(SLIM_TKNAM_BASE_XMLAT0 + SLIM_TKOFF_BASE_XMLAT1)
#define SLIM_TKLEN_TOTAL_XMLAT	SLIM_TKOFF_BASE_XMLAT1

extern SLIM_ROM slim_char cSlim_TokenName_XMLAT[SLIM_TKLEN_TOTAL_XMLAT];

extern SLIM_ROM TXMLAttrInfo cSlim_Token_XMLAT[SLIM_TOKEN_XMLAT_TOKENS];
#define XMLAttrInfo_GetItem(id)		((TXMLAttrInfo *)&cSlim_Token_XMLAT[(id)])
#define XMLAttrInfo_GetItemName(id)	((slim_char *)cSlim_TokenName_XMLAT + ((TToken *)&cSlim_Token_XMLAT[(id)])->fOffset)
#define XMLAttrInfo_GetItemNameLen(id)	(((TToken *)&cSlim_Token_XMLAT[(id)])->fLength)

TXMLAttrInfo *XMLAttrInfo_CaseFindSS(slim_char *in_s, slim_int in_slen);

SLIM_END_C_LINKAGE
#endif
