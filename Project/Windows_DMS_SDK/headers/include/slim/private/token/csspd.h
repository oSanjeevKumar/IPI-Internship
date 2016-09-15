/*
	csspd.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/token/csspd.h 24    06/08/25 2:39 Yamabuti $ */

/* DO NOT EDIT! This file is generated automagically. */

#ifndef SLIM_TOKEN_CSSPD_H
#define SLIM_TOKEN_CSSPD_H

#include <slim/basis/base.h>
#include <slim/basis/token.h>
#include <slim/private/token/csspdid.h>

SLIM_BEGIN_C_LINKAGE

#include <slim/www/csstk.h>

#define SLIM_TKOFF_BASE_CSSPD0	(0)
#define SLIM_TKNAM_BASE_CSSPD0	((slim_char *)cSlim_TokenName_CSSPD)
#define SLIM_TKOFF_CSSPD_first_child	(SLIM_TKOFF_BASE_CSSPD0 + 0)
#define SLIM_TKNAM_CSSPD_first_child	(SLIM_TKNAM_BASE_CSSPD0 + 0)
#define SLIM_TKLEN_CSSPD_first_child	(11)
#define SLIM_TOKEN_CSSPD_first_child	(CSSPseudoInfo_GetItem(SLIM_TKID_CSSPD_first_child))
#define SLIM_TKOFF_CSSPD_link	(SLIM_TKOFF_BASE_CSSPD0 + 12)
#define SLIM_TKNAM_CSSPD_link	(SLIM_TKNAM_BASE_CSSPD0 + 12)
#define SLIM_TKLEN_CSSPD_link	(4)
#define SLIM_TOKEN_CSSPD_link	(CSSPseudoInfo_GetItem(SLIM_TKID_CSSPD_link))
#define SLIM_TKOFF_CSSPD_visited	(SLIM_TKOFF_BASE_CSSPD0 + 17)
#define SLIM_TKNAM_CSSPD_visited	(SLIM_TKNAM_BASE_CSSPD0 + 17)
#define SLIM_TKLEN_CSSPD_visited	(7)
#define SLIM_TOKEN_CSSPD_visited	(CSSPseudoInfo_GetItem(SLIM_TKID_CSSPD_visited))
#define SLIM_TKOFF_CSSPD_hover	(SLIM_TKOFF_BASE_CSSPD0 + 25)
#define SLIM_TKNAM_CSSPD_hover	(SLIM_TKNAM_BASE_CSSPD0 + 25)
#define SLIM_TKLEN_CSSPD_hover	(5)
#define SLIM_TOKEN_CSSPD_hover	(CSSPseudoInfo_GetItem(SLIM_TKID_CSSPD_hover))
#define SLIM_TKOFF_CSSPD_active	(SLIM_TKOFF_BASE_CSSPD0 + 31)
#define SLIM_TKNAM_CSSPD_active	(SLIM_TKNAM_BASE_CSSPD0 + 31)
#define SLIM_TKLEN_CSSPD_active	(6)
#define SLIM_TOKEN_CSSPD_active	(CSSPseudoInfo_GetItem(SLIM_TKID_CSSPD_active))
#define SLIM_TKOFF_CSSPD_focus	(SLIM_TKOFF_BASE_CSSPD0 + 38)
#define SLIM_TKNAM_CSSPD_focus	(SLIM_TKNAM_BASE_CSSPD0 + 38)
#define SLIM_TKLEN_CSSPD_focus	(5)
#define SLIM_TOKEN_CSSPD_focus	(CSSPseudoInfo_GetItem(SLIM_TKID_CSSPD_focus))
#define SLIM_TKOFF_CSSPD_lang	(SLIM_TKOFF_BASE_CSSPD0 + 44)
#define SLIM_TKNAM_CSSPD_lang	(SLIM_TKNAM_BASE_CSSPD0 + 44)
#define SLIM_TKLEN_CSSPD_lang	(4)
#define SLIM_TOKEN_CSSPD_lang	(CSSPseudoInfo_GetItem(SLIM_TKID_CSSPD_lang))
#define SLIM_TKOFF_CSSPD_after	(SLIM_TKOFF_BASE_CSSPD0 + 49)
#define SLIM_TKNAM_CSSPD_after	(SLIM_TKNAM_BASE_CSSPD0 + 49)
#define SLIM_TKLEN_CSSPD_after	(5)
#define SLIM_TOKEN_CSSPD_after	(CSSPseudoInfo_GetItem(SLIM_TKID_CSSPD_after))
#define SLIM_TKOFF_CSSPD_before	(SLIM_TKOFF_BASE_CSSPD0 + 55)
#define SLIM_TKNAM_CSSPD_before	(SLIM_TKNAM_BASE_CSSPD0 + 55)
#define SLIM_TKLEN_CSSPD_before	(6)
#define SLIM_TOKEN_CSSPD_before	(CSSPseudoInfo_GetItem(SLIM_TKID_CSSPD_before))
#define SLIM_TKOFF_CSSPD_first_letter	(SLIM_TKOFF_BASE_CSSPD0 + 62)
#define SLIM_TKNAM_CSSPD_first_letter	(SLIM_TKNAM_BASE_CSSPD0 + 62)
#define SLIM_TKLEN_CSSPD_first_letter	(12)
#define SLIM_TOKEN_CSSPD_first_letter	(CSSPseudoInfo_GetItem(SLIM_TKID_CSSPD_first_letter))
#define SLIM_TKOFF_CSSPD_first_line	(SLIM_TKOFF_BASE_CSSPD0 + 75)
#define SLIM_TKNAM_CSSPD_first_line	(SLIM_TKNAM_BASE_CSSPD0 + 75)
#define SLIM_TKLEN_CSSPD_first_line	(10)
#define SLIM_TOKEN_CSSPD_first_line	(CSSPseudoInfo_GetItem(SLIM_TKID_CSSPD_first_line))
#define SLIM_TKOFF_CSSPD_first	(SLIM_TKOFF_BASE_CSSPD0 + 86)
#define SLIM_TKNAM_CSSPD_first	(SLIM_TKNAM_BASE_CSSPD0 + 86)
#define SLIM_TKLEN_CSSPD_first	(5)
#define SLIM_TOKEN_CSSPD_first	(CSSPseudoInfo_GetItem(SLIM_TKID_CSSPD_first))
#define SLIM_TKOFF_CSSPD_right	(SLIM_TKOFF_BASE_CSSPD0 + 92)
#define SLIM_TKNAM_CSSPD_right	(SLIM_TKNAM_BASE_CSSPD0 + 92)
#define SLIM_TKLEN_CSSPD_right	(5)
#define SLIM_TOKEN_CSSPD_right	(CSSPseudoInfo_GetItem(SLIM_TKID_CSSPD_right))
#define SLIM_TKOFF_CSSPD_left	(SLIM_TKOFF_BASE_CSSPD0 + 98)
#define SLIM_TKNAM_CSSPD_left	(SLIM_TKNAM_BASE_CSSPD0 + 98)
#define SLIM_TKLEN_CSSPD_left	(4)
#define SLIM_TOKEN_CSSPD_left	(CSSPseudoInfo_GetItem(SLIM_TKID_CSSPD_left))
#define SLIM_TKOFF_BASE_CSSPD1	(SLIM_TKOFF_BASE_CSSPD0 + 103)
#define SLIM_TKNAM_BASE_CSSPD1	(SLIM_TKNAM_BASE_CSSPD0 + SLIM_TKOFF_BASE_CSSPD1)
#ifdef SLIM_CONFIG_CSS_LEVEL_3
#define SLIM_TKOFF_CSSPD_root	(SLIM_TKOFF_BASE_CSSPD1 + 0)
#define SLIM_TKNAM_CSSPD_root	(SLIM_TKNAM_BASE_CSSPD1 + 0)
#define SLIM_TKLEN_CSSPD_root	(4)
#define SLIM_TOKEN_CSSPD_root	(CSSPseudoInfo_GetItem(SLIM_TKID_CSSPD_root))
#define SLIM_TKOFF_CSSPD_last_child	(SLIM_TKOFF_BASE_CSSPD1 + 5)
#define SLIM_TKNAM_CSSPD_last_child	(SLIM_TKNAM_BASE_CSSPD1 + 5)
#define SLIM_TKLEN_CSSPD_last_child	(10)
#define SLIM_TOKEN_CSSPD_last_child	(CSSPseudoInfo_GetItem(SLIM_TKID_CSSPD_last_child))
#define SLIM_TKOFF_CSSPD_only_child	(SLIM_TKOFF_BASE_CSSPD1 + 16)
#define SLIM_TKNAM_CSSPD_only_child	(SLIM_TKNAM_BASE_CSSPD1 + 16)
#define SLIM_TKLEN_CSSPD_only_child	(10)
#define SLIM_TOKEN_CSSPD_only_child	(CSSPseudoInfo_GetItem(SLIM_TKID_CSSPD_only_child))
#define SLIM_TKOFF_CSSPD_empty	(SLIM_TKOFF_BASE_CSSPD1 + 27)
#define SLIM_TKNAM_CSSPD_empty	(SLIM_TKNAM_BASE_CSSPD1 + 27)
#define SLIM_TKLEN_CSSPD_empty	(5)
#define SLIM_TOKEN_CSSPD_empty	(CSSPseudoInfo_GetItem(SLIM_TKID_CSSPD_empty))
#define SLIM_TKOFF_BASE_CSSPD2	(SLIM_TKOFF_BASE_CSSPD1 + 33)
#else /* SLIM_CONFIG_CSS_LEVEL_3 */
#define SLIM_TKOFF_BASE_CSSPD2	(SLIM_TKOFF_BASE_CSSPD1)
#endif /* SLIM_CONFIG_CSS_LEVEL_3 */
#define SLIM_TKNAM_BASE_CSSPD2	(SLIM_TKNAM_BASE_CSSPD0 + SLIM_TKOFF_BASE_CSSPD2)
#define SLIM_TKLEN_TOTAL_CSSPD	SLIM_TKOFF_BASE_CSSPD2

extern SLIM_ROM slim_char cSlim_TokenName_CSSPD[SLIM_TKLEN_TOTAL_CSSPD];

extern SLIM_ROM TCSSPseudoInfo cSlim_Token_CSSPD[SLIM_TOKEN_CSSPD_TOKENS];
#define CSSPseudoInfo_GetItem(id)		((TCSSPseudoInfo *)&cSlim_Token_CSSPD[(id)])
#define CSSPseudoInfo_GetItemName(id)	((slim_char *)cSlim_TokenName_CSSPD + ((TToken *)&cSlim_Token_CSSPD[(id)])->fOffset)
#define CSSPseudoInfo_GetItemNameLen(id)	(((TToken *)&cSlim_Token_CSSPD[(id)])->fLength)

TCSSPseudoInfo *CSSPseudoInfo_FindSS(slim_char *in_s, slim_int in_slen);

SLIM_END_C_LINKAGE
#endif
