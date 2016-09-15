/*
	scheme.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/token/scheme.h 27    06/05/11 21:53 Yamabuti $ */

/* DO NOT EDIT! This file is generated automagically. */

#ifndef SLIM_TOKEN_SCHEME_H
#define SLIM_TOKEN_SCHEME_H

#include <slim/basis/base.h>
#include <slim/basis/token.h>
#include <slim/token/schemeid.h>

SLIM_BEGIN_C_LINKAGE


#include <slim/inet/url.h>

struct TURLSchemeInfo_ {
	TToken fBase;	/* must be the first field */
	slim_int fSchemeFlag;
	slim_int fDefaultPort;
};
typedef struct TURLSchemeInfo_ TURLSchemeInfo;

#define SLIM_TKOFF_BASE_SCHEME0	(0)
#define SLIM_TKNAM_BASE_SCHEME0	((slim_char *)cSlim_TokenName_SCHEME)
#define SLIM_TKOFF_SCHEME_http_	(SLIM_TKOFF_BASE_SCHEME0 + 0)
#define SLIM_TKNAM_SCHEME_http_	(SLIM_TKNAM_BASE_SCHEME0 + 0)
#define SLIM_TKLEN_SCHEME_http_	(5)
#define SLIM_TOKEN_SCHEME_http_	(URLSchemeInfo_GetItem(SLIM_TKID_SCHEME_http_))
#define SLIM_TKOFF_SCHEME_https_	(SLIM_TKOFF_BASE_SCHEME0 + 6)
#define SLIM_TKNAM_SCHEME_https_	(SLIM_TKNAM_BASE_SCHEME0 + 6)
#define SLIM_TKLEN_SCHEME_https_	(6)
#define SLIM_TOKEN_SCHEME_https_	(URLSchemeInfo_GetItem(SLIM_TKID_SCHEME_https_))
#define SLIM_TKOFF_SCHEME_file_	(SLIM_TKOFF_BASE_SCHEME0 + 13)
#define SLIM_TKNAM_SCHEME_file_	(SLIM_TKNAM_BASE_SCHEME0 + 13)
#define SLIM_TKLEN_SCHEME_file_	(5)
#define SLIM_TOKEN_SCHEME_file_	(URLSchemeInfo_GetItem(SLIM_TKID_SCHEME_file_))
#define SLIM_TKOFF_SCHEME_pict_	(SLIM_TKOFF_BASE_SCHEME0 + 19)
#define SLIM_TKNAM_SCHEME_pict_	(SLIM_TKNAM_BASE_SCHEME0 + 19)
#define SLIM_TKLEN_SCHEME_pict_	(5)
#define SLIM_TOKEN_SCHEME_pict_	(URLSchemeInfo_GetItem(SLIM_TKID_SCHEME_pict_))
#define SLIM_TKOFF_SCHEME_javascript_	(SLIM_TKOFF_BASE_SCHEME0 + 25)
#define SLIM_TKNAM_SCHEME_javascript_	(SLIM_TKNAM_BASE_SCHEME0 + 25)
#define SLIM_TKLEN_SCHEME_javascript_	(11)
#define SLIM_TOKEN_SCHEME_javascript_	(URLSchemeInfo_GetItem(SLIM_TKID_SCHEME_javascript_))
#define SLIM_TKOFF_SCHEME_data_	(SLIM_TKOFF_BASE_SCHEME0 + 37)
#define SLIM_TKNAM_SCHEME_data_	(SLIM_TKNAM_BASE_SCHEME0 + 37)
#define SLIM_TKLEN_SCHEME_data_	(5)
#define SLIM_TOKEN_SCHEME_data_	(URLSchemeInfo_GetItem(SLIM_TKID_SCHEME_data_))
#define SLIM_TKOFF_SCHEME_about_	(SLIM_TKOFF_BASE_SCHEME0 + 43)
#define SLIM_TKNAM_SCHEME_about_	(SLIM_TKNAM_BASE_SCHEME0 + 43)
#define SLIM_TKLEN_SCHEME_about_	(6)
#define SLIM_TOKEN_SCHEME_about_	(URLSchemeInfo_GetItem(SLIM_TKID_SCHEME_about_))
#define SLIM_TKOFF_BASE_SCHEME1	(SLIM_TKOFF_BASE_SCHEME0 + 50)
#define SLIM_TKNAM_BASE_SCHEME1	(SLIM_TKNAM_BASE_SCHEME0 + SLIM_TKOFF_BASE_SCHEME1)
#define SLIM_TKLEN_TOTAL_SCHEME	SLIM_TKOFF_BASE_SCHEME1

extern SLIM_ROM slim_char cSlim_TokenName_SCHEME[SLIM_TKLEN_TOTAL_SCHEME];

extern SLIM_ROM TURLSchemeInfo cSlim_Token_SCHEME[SLIM_TOKEN_SCHEME_TOKENS];
#define URLSchemeInfo_GetItem(id)		((TURLSchemeInfo *)&cSlim_Token_SCHEME[(id)])
#define URLSchemeInfo_GetItemName(id)	((slim_char *)cSlim_TokenName_SCHEME + ((TToken *)&cSlim_Token_SCHEME[(id)])->fOffset)
#define URLSchemeInfo_GetItemNameLen(id)	(((TToken *)&cSlim_Token_SCHEME[(id)])->fLength)

TURLSchemeInfo *URLSchemeInfo_FindSS(slim_char *in_s, slim_int in_slen);

SLIM_END_C_LINKAGE
#endif
