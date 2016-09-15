/*
	nsuri.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/token/nsuri.h 20    06/06/02 20:01 Endoh $ */

/* DO NOT EDIT! This file is generated automagically. */

#ifndef SLIM_TOKEN_NSURI_H
#define SLIM_TOKEN_NSURI_H

#include <slim/basis/base.h>
#include <slim/basis/token.h>
#include <slim/private/token/nsuriid.h>

SLIM_BEGIN_C_LINKAGE


#include <slim/private/www/xxmlscma.h>

struct TNSURIInfo_ {
	TToken fBase;	/* must be the first field */
	slim_int fxxMLSchemaID;
};
typedef struct TNSURIInfo_ TNSURIInfo;

#define TNSURIInfo_xxMLSchemaID(self) ((self)->fxxMLSchemaID)

#define SLIM_TOKEN_NSURI_UNKNOWN	((TNSURIInfo *)&cSlim_Token_NSURI_UNKNOWN)
extern SLIM_ROM TNSURIInfo cSlim_Token_NSURI_UNKNOWN;

#define SLIM_TKOFF_BASE_NSURI0	(0)
#define SLIM_TKNAM_BASE_NSURI0	((slim_char *)cSlim_TokenName_NSURI)
#define SLIM_TKOFF_NSURI_xhtml	(SLIM_TKOFF_BASE_NSURI0 + 0)
#define SLIM_TKNAM_NSURI_xhtml	(SLIM_TKNAM_BASE_NSURI0 + 0)
#define SLIM_TKLEN_NSURI_xhtml	(28)
#define SLIM_TOKEN_NSURI_xhtml	(NSURIInfo_GetItem(SLIM_TKID_NSURI_xhtml))
#define SLIM_TKOFF_NSURI_rdf	(SLIM_TKOFF_BASE_NSURI0 + 29)
#define SLIM_TKNAM_NSURI_rdf	(SLIM_TKNAM_BASE_NSURI0 + 29)
#define SLIM_TKLEN_NSURI_rdf	(43)
#define SLIM_TOKEN_NSURI_rdf	(NSURIInfo_GetItem(SLIM_TKID_NSURI_rdf))
#define SLIM_TKOFF_NSURI_rss100	(SLIM_TKOFF_BASE_NSURI0 + 73)
#define SLIM_TKNAM_NSURI_rss100	(SLIM_TKNAM_BASE_NSURI0 + 73)
#define SLIM_TKLEN_NSURI_rss100	(24)
#define SLIM_TOKEN_NSURI_rss100	(NSURIInfo_GetItem(SLIM_TKID_NSURI_rss100))
#define SLIM_TKOFF_NSURI_rss090	(SLIM_TKOFF_BASE_NSURI0 + 98)
#define SLIM_TKNAM_NSURI_rss090	(SLIM_TKNAM_BASE_NSURI0 + 98)
#define SLIM_TKLEN_NSURI_rss090	(38)
#define SLIM_TOKEN_NSURI_rss090	(NSURIInfo_GetItem(SLIM_TKID_NSURI_rss090))
#define SLIM_TKOFF_NSURI_rss091	(SLIM_TKOFF_BASE_NSURI0 + 137)
#define SLIM_TKNAM_NSURI_rss091	(SLIM_TKNAM_BASE_NSURI0 + 137)
#define SLIM_TKLEN_NSURI_rss091	(39)
#define SLIM_TOKEN_NSURI_rss091	(NSURIInfo_GetItem(SLIM_TKID_NSURI_rss091))
#define SLIM_TKOFF_NSURI_dc	(SLIM_TKOFF_BASE_NSURI0 + 177)
#define SLIM_TKNAM_NSURI_dc	(SLIM_TKNAM_BASE_NSURI0 + 177)
#define SLIM_TKLEN_NSURI_dc	(32)
#define SLIM_TOKEN_NSURI_dc	(NSURIInfo_GetItem(SLIM_TKID_NSURI_dc))
#define SLIM_TKOFF_NSURI_syn	(SLIM_TKOFF_BASE_NSURI0 + 210)
#define SLIM_TKNAM_NSURI_syn	(SLIM_TKNAM_BASE_NSURI0 + 210)
#define SLIM_TKLEN_NSURI_syn	(44)
#define SLIM_TOKEN_NSURI_syn	(NSURIInfo_GetItem(SLIM_TKID_NSURI_syn))
#define SLIM_TKOFF_NSURI_content	(SLIM_TKOFF_BASE_NSURI0 + 255)
#define SLIM_TKNAM_NSURI_content	(SLIM_TKNAM_BASE_NSURI0 + 255)
#define SLIM_TKLEN_NSURI_content	(40)
#define SLIM_TOKEN_NSURI_content	(NSURIInfo_GetItem(SLIM_TKID_NSURI_content))
#define SLIM_TKOFF_NSURI_atom	(SLIM_TKOFF_BASE_NSURI0 + 296)
#define SLIM_TKNAM_NSURI_atom	(SLIM_TKNAM_BASE_NSURI0 + 296)
#define SLIM_TKLEN_NSURI_atom	(24)
#define SLIM_TOKEN_NSURI_atom	(NSURIInfo_GetItem(SLIM_TKID_NSURI_atom))
#define SLIM_TKOFF_NSURI_svg	(SLIM_TKOFF_BASE_NSURI0 + 321)
#define SLIM_TKNAM_NSURI_svg	(SLIM_TKNAM_BASE_NSURI0 + 321)
#define SLIM_TKLEN_NSURI_svg	(26)
#define SLIM_TOKEN_NSURI_svg	(NSURIInfo_GetItem(SLIM_TKID_NSURI_svg))
#define SLIM_TKOFF_NSURI_smil10	(SLIM_TKOFF_BASE_NSURI0 + 348)
#define SLIM_TKNAM_NSURI_smil10	(SLIM_TKNAM_BASE_NSURI0 + 348)
#define SLIM_TKLEN_NSURI_smil10	(29)
#define SLIM_TOKEN_NSURI_smil10	(NSURIInfo_GetItem(SLIM_TKID_NSURI_smil10))
#define SLIM_TKOFF_NSURI_smil20	(SLIM_TKOFF_BASE_NSURI0 + 378)
#define SLIM_TKNAM_NSURI_smil20	(SLIM_TKNAM_BASE_NSURI0 + 378)
#define SLIM_TKLEN_NSURI_smil20	(38)
#define SLIM_TOKEN_NSURI_smil20	(NSURIInfo_GetItem(SLIM_TKID_NSURI_smil20))
#define SLIM_TKOFF_NSURI_smil21	(SLIM_TKOFF_BASE_NSURI0 + 417)
#define SLIM_TKNAM_NSURI_smil21	(SLIM_TKNAM_BASE_NSURI0 + 417)
#define SLIM_TKLEN_NSURI_smil21	(38)
#define SLIM_TOKEN_NSURI_smil21	(NSURIInfo_GetItem(SLIM_TKID_NSURI_smil21))
#define SLIM_TKOFF_NSURI_vxml	(SLIM_TKOFF_BASE_NSURI0 + 456)
#define SLIM_TKNAM_NSURI_vxml	(SLIM_TKNAM_BASE_NSURI0 + 456)
#define SLIM_TKLEN_NSURI_vxml	(27)
#define SLIM_TOKEN_NSURI_vxml	(NSURIInfo_GetItem(SLIM_TKID_NSURI_vxml))
#define SLIM_TKOFF_NSURI_xml_events	(SLIM_TKOFF_BASE_NSURI0 + 484)
#define SLIM_TKNAM_NSURI_xml_events	(SLIM_TKNAM_BASE_NSURI0 + 484)
#define SLIM_TKLEN_NSURI_xml_events	(33)
#define SLIM_TOKEN_NSURI_xml_events	(NSURIInfo_GetItem(SLIM_TKID_NSURI_xml_events))
#define SLIM_TKOFF_NSURI_xv	(SLIM_TKOFF_BASE_NSURI0 + 518)
#define SLIM_TKNAM_NSURI_xv	(SLIM_TKNAM_BASE_NSURI0 + 518)
#define SLIM_TKLEN_NSURI_xv	(40)
#define SLIM_TOKEN_NSURI_xv	(NSURIInfo_GetItem(SLIM_TKID_NSURI_xv))
#define SLIM_TKOFF_NSURI_xml	(SLIM_TKOFF_BASE_NSURI0 + 559)
#define SLIM_TKNAM_NSURI_xml	(SLIM_TKNAM_BASE_NSURI0 + 559)
#define SLIM_TKLEN_NSURI_xml	(36)
#define SLIM_TOKEN_NSURI_xml	(NSURIInfo_GetItem(SLIM_TKID_NSURI_xml))
#define SLIM_TKOFF_NSURI_xmlns	(SLIM_TKOFF_BASE_NSURI0 + 596)
#define SLIM_TKNAM_NSURI_xmlns	(SLIM_TKNAM_BASE_NSURI0 + 596)
#define SLIM_TKLEN_NSURI_xmlns	(29)
#define SLIM_TOKEN_NSURI_xmlns	(NSURIInfo_GetItem(SLIM_TKID_NSURI_xmlns))
#define SLIM_TKOFF_BASE_NSURI1	(SLIM_TKOFF_BASE_NSURI0 + 626)
#define SLIM_TKNAM_BASE_NSURI1	(SLIM_TKNAM_BASE_NSURI0 + SLIM_TKOFF_BASE_NSURI1)
#define SLIM_TKLEN_TOTAL_NSURI	SLIM_TKOFF_BASE_NSURI1

extern SLIM_ROM slim_char cSlim_TokenName_NSURI[SLIM_TKLEN_TOTAL_NSURI];

extern SLIM_ROM TNSURIInfo cSlim_Token_NSURI[SLIM_TOKEN_NSURI_TOKENS];
#define NSURIInfo_GetItem(id)		((TNSURIInfo *)&cSlim_Token_NSURI[(id)])
#define NSURIInfo_GetItemName(id)	((slim_char *)cSlim_TokenName_NSURI + ((TToken *)&cSlim_Token_NSURI[(id)])->fOffset)
#define NSURIInfo_GetItemNameLen(id)	(((TToken *)&cSlim_Token_NSURI[(id)])->fLength)

TNSURIInfo *NSURIInfo_CaseFindSS(slim_char *in_s, slim_int in_slen);

SLIM_END_C_LINKAGE
#endif
