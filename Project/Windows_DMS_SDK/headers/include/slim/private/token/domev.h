/*
	domev.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/token/domev.h 5     06/07/15 2:45 Yamabuti $ */

/* DO NOT EDIT! This file is generated automagically. */

#ifndef SLIM_TOKEN_DOMEV_H
#define SLIM_TOKEN_DOMEV_H

#include <slim/basis/base.h>
#include <slim/basis/token.h>
#include <slim/private/token/domevid.h>

SLIM_BEGIN_C_LINKAGE

struct TDOMEventInfo_ {
	TToken fBase;	/* must be the first field */
};
typedef struct TDOMEventInfo_ TDOMEventInfo;

#define SLIM_TKOFF_BASE_DOMEV0	(0)
#define SLIM_TKNAM_BASE_DOMEV0	((slim_char *)cSlim_TokenName_DOMEV)
#define SLIM_TKOFF_DOMEV_DOMFocusIn	(SLIM_TKOFF_BASE_DOMEV0 + 0)
#define SLIM_TKNAM_DOMEV_DOMFocusIn	(SLIM_TKNAM_BASE_DOMEV0 + 0)
#define SLIM_TKLEN_DOMEV_DOMFocusIn	(10)
#define SLIM_TOKEN_DOMEV_DOMFocusIn	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_DOMFocusIn))
#define SLIM_TKOFF_DOMEV_DOMFocusOut	(SLIM_TKOFF_BASE_DOMEV0 + 11)
#define SLIM_TKNAM_DOMEV_DOMFocusOut	(SLIM_TKNAM_BASE_DOMEV0 + 11)
#define SLIM_TKLEN_DOMEV_DOMFocusOut	(11)
#define SLIM_TOKEN_DOMEV_DOMFocusOut	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_DOMFocusOut))
#define SLIM_TKOFF_DOMEV_DOMActivate	(SLIM_TKOFF_BASE_DOMEV0 + 23)
#define SLIM_TKNAM_DOMEV_DOMActivate	(SLIM_TKNAM_BASE_DOMEV0 + 23)
#define SLIM_TKLEN_DOMEV_DOMActivate	(11)
#define SLIM_TOKEN_DOMEV_DOMActivate	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_DOMActivate))
#define SLIM_TKOFF_DOMEV_click	(SLIM_TKOFF_BASE_DOMEV0 + 35)
#define SLIM_TKNAM_DOMEV_click	(SLIM_TKNAM_BASE_DOMEV0 + 35)
#define SLIM_TKLEN_DOMEV_click	(5)
#define SLIM_TOKEN_DOMEV_click	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_click))
#define SLIM_TKOFF_DOMEV_dblclick	(SLIM_TKOFF_BASE_DOMEV0 + 41)
#define SLIM_TKNAM_DOMEV_dblclick	(SLIM_TKNAM_BASE_DOMEV0 + 41)
#define SLIM_TKLEN_DOMEV_dblclick	(8)
#define SLIM_TOKEN_DOMEV_dblclick	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_dblclick))
#define SLIM_TKOFF_DOMEV_mousedown	(SLIM_TKOFF_BASE_DOMEV0 + 50)
#define SLIM_TKNAM_DOMEV_mousedown	(SLIM_TKNAM_BASE_DOMEV0 + 50)
#define SLIM_TKLEN_DOMEV_mousedown	(9)
#define SLIM_TOKEN_DOMEV_mousedown	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_mousedown))
#define SLIM_TKOFF_DOMEV_mouseup	(SLIM_TKOFF_BASE_DOMEV0 + 60)
#define SLIM_TKNAM_DOMEV_mouseup	(SLIM_TKNAM_BASE_DOMEV0 + 60)
#define SLIM_TKLEN_DOMEV_mouseup	(7)
#define SLIM_TOKEN_DOMEV_mouseup	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_mouseup))
#define SLIM_TKOFF_DOMEV_mouseover	(SLIM_TKOFF_BASE_DOMEV0 + 68)
#define SLIM_TKNAM_DOMEV_mouseover	(SLIM_TKNAM_BASE_DOMEV0 + 68)
#define SLIM_TKLEN_DOMEV_mouseover	(9)
#define SLIM_TOKEN_DOMEV_mouseover	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_mouseover))
#define SLIM_TKOFF_DOMEV_mousemove	(SLIM_TKOFF_BASE_DOMEV0 + 78)
#define SLIM_TKNAM_DOMEV_mousemove	(SLIM_TKNAM_BASE_DOMEV0 + 78)
#define SLIM_TKLEN_DOMEV_mousemove	(9)
#define SLIM_TOKEN_DOMEV_mousemove	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_mousemove))
#define SLIM_TKOFF_DOMEV_mouseout	(SLIM_TKOFF_BASE_DOMEV0 + 88)
#define SLIM_TKNAM_DOMEV_mouseout	(SLIM_TKNAM_BASE_DOMEV0 + 88)
#define SLIM_TKLEN_DOMEV_mouseout	(8)
#define SLIM_TOKEN_DOMEV_mouseout	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_mouseout))
#define SLIM_TKOFF_DOMEV_mousewheel	(SLIM_TKOFF_BASE_DOMEV0 + 97)
#define SLIM_TKNAM_DOMEV_mousewheel	(SLIM_TKNAM_BASE_DOMEV0 + 97)
#define SLIM_TKLEN_DOMEV_mousewheel	(10)
#define SLIM_TOKEN_DOMEV_mousewheel	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_mousewheel))
#define SLIM_TKOFF_DOMEV_contextmenu	(SLIM_TKOFF_BASE_DOMEV0 + 108)
#define SLIM_TKNAM_DOMEV_contextmenu	(SLIM_TKNAM_BASE_DOMEV0 + 108)
#define SLIM_TKLEN_DOMEV_contextmenu	(11)
#define SLIM_TOKEN_DOMEV_contextmenu	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_contextmenu))
#define SLIM_TKOFF_DOMEV_load	(SLIM_TKOFF_BASE_DOMEV0 + 120)
#define SLIM_TKNAM_DOMEV_load	(SLIM_TKNAM_BASE_DOMEV0 + 120)
#define SLIM_TKLEN_DOMEV_load	(4)
#define SLIM_TOKEN_DOMEV_load	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_load))
#define SLIM_TKOFF_DOMEV_unload	(SLIM_TKOFF_BASE_DOMEV0 + 125)
#define SLIM_TKNAM_DOMEV_unload	(SLIM_TKNAM_BASE_DOMEV0 + 125)
#define SLIM_TKLEN_DOMEV_unload	(6)
#define SLIM_TOKEN_DOMEV_unload	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_unload))
#define SLIM_TKOFF_DOMEV_abort	(SLIM_TKOFF_BASE_DOMEV0 + 132)
#define SLIM_TKNAM_DOMEV_abort	(SLIM_TKNAM_BASE_DOMEV0 + 132)
#define SLIM_TKLEN_DOMEV_abort	(5)
#define SLIM_TOKEN_DOMEV_abort	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_abort))
#define SLIM_TKOFF_DOMEV_error	(SLIM_TKOFF_BASE_DOMEV0 + 138)
#define SLIM_TKNAM_DOMEV_error	(SLIM_TKNAM_BASE_DOMEV0 + 138)
#define SLIM_TKLEN_DOMEV_error	(5)
#define SLIM_TOKEN_DOMEV_error	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_error))
#define SLIM_TKOFF_DOMEV_select	(SLIM_TKOFF_BASE_DOMEV0 + 144)
#define SLIM_TKNAM_DOMEV_select	(SLIM_TKNAM_BASE_DOMEV0 + 144)
#define SLIM_TKLEN_DOMEV_select	(6)
#define SLIM_TOKEN_DOMEV_select	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_select))
#define SLIM_TKOFF_DOMEV_change	(SLIM_TKOFF_BASE_DOMEV0 + 151)
#define SLIM_TKNAM_DOMEV_change	(SLIM_TKNAM_BASE_DOMEV0 + 151)
#define SLIM_TKLEN_DOMEV_change	(6)
#define SLIM_TOKEN_DOMEV_change	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_change))
#define SLIM_TKOFF_DOMEV_submit	(SLIM_TKOFF_BASE_DOMEV0 + 158)
#define SLIM_TKNAM_DOMEV_submit	(SLIM_TKNAM_BASE_DOMEV0 + 158)
#define SLIM_TKLEN_DOMEV_submit	(6)
#define SLIM_TOKEN_DOMEV_submit	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_submit))
#define SLIM_TKOFF_DOMEV_reset	(SLIM_TKOFF_BASE_DOMEV0 + 165)
#define SLIM_TKNAM_DOMEV_reset	(SLIM_TKNAM_BASE_DOMEV0 + 165)
#define SLIM_TKLEN_DOMEV_reset	(5)
#define SLIM_TOKEN_DOMEV_reset	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_reset))
#define SLIM_TKOFF_DOMEV_focus	(SLIM_TKOFF_BASE_DOMEV0 + 171)
#define SLIM_TKNAM_DOMEV_focus	(SLIM_TKNAM_BASE_DOMEV0 + 171)
#define SLIM_TKLEN_DOMEV_focus	(5)
#define SLIM_TOKEN_DOMEV_focus	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_focus))
#define SLIM_TKOFF_DOMEV_blur	(SLIM_TKOFF_BASE_DOMEV0 + 177)
#define SLIM_TKNAM_DOMEV_blur	(SLIM_TKNAM_BASE_DOMEV0 + 177)
#define SLIM_TKLEN_DOMEV_blur	(4)
#define SLIM_TOKEN_DOMEV_blur	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_blur))
#define SLIM_TKOFF_DOMEV_resize	(SLIM_TKOFF_BASE_DOMEV0 + 182)
#define SLIM_TKNAM_DOMEV_resize	(SLIM_TKNAM_BASE_DOMEV0 + 182)
#define SLIM_TKLEN_DOMEV_resize	(6)
#define SLIM_TOKEN_DOMEV_resize	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_resize))
#define SLIM_TKOFF_DOMEV_scroll	(SLIM_TKOFF_BASE_DOMEV0 + 189)
#define SLIM_TKNAM_DOMEV_scroll	(SLIM_TKNAM_BASE_DOMEV0 + 189)
#define SLIM_TKLEN_DOMEV_scroll	(6)
#define SLIM_TOKEN_DOMEV_scroll	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_scroll))
#define SLIM_TKOFF_DOMEV_wml_action	(SLIM_TKOFF_BASE_DOMEV0 + 196)
#define SLIM_TKNAM_DOMEV_wml_action	(SLIM_TKNAM_BASE_DOMEV0 + 196)
#define SLIM_TKLEN_DOMEV_wml_action	(10)
#define SLIM_TOKEN_DOMEV_wml_action	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_wml_action))
#define SLIM_TKOFF_DOMEV_pick	(SLIM_TKOFF_BASE_DOMEV0 + 207)
#define SLIM_TKNAM_DOMEV_pick	(SLIM_TKNAM_BASE_DOMEV0 + 207)
#define SLIM_TKLEN_DOMEV_pick	(4)
#define SLIM_TOKEN_DOMEV_pick	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_pick))
#define SLIM_TKOFF_DOMEV_keypress	(SLIM_TKOFF_BASE_DOMEV0 + 212)
#define SLIM_TKNAM_DOMEV_keypress	(SLIM_TKNAM_BASE_DOMEV0 + 212)
#define SLIM_TKLEN_DOMEV_keypress	(8)
#define SLIM_TOKEN_DOMEV_keypress	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_keypress))
#define SLIM_TKOFF_DOMEV_keydown	(SLIM_TKOFF_BASE_DOMEV0 + 221)
#define SLIM_TKNAM_DOMEV_keydown	(SLIM_TKNAM_BASE_DOMEV0 + 221)
#define SLIM_TKLEN_DOMEV_keydown	(7)
#define SLIM_TOKEN_DOMEV_keydown	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_keydown))
#define SLIM_TKOFF_DOMEV_keyup	(SLIM_TKOFF_BASE_DOMEV0 + 229)
#define SLIM_TKNAM_DOMEV_keyup	(SLIM_TKNAM_BASE_DOMEV0 + 229)
#define SLIM_TKLEN_DOMEV_keyup	(5)
#define SLIM_TOKEN_DOMEV_keyup	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_keyup))
#define SLIM_TKOFF_DOMEV_script_scheme	(SLIM_TKOFF_BASE_DOMEV0 + 235)
#define SLIM_TKNAM_DOMEV_script_scheme	(SLIM_TKNAM_BASE_DOMEV0 + 235)
#define SLIM_TKLEN_DOMEV_script_scheme	(13)
#define SLIM_TOKEN_DOMEV_script_scheme	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_script_scheme))
#define SLIM_TKOFF_DOMEV_smil_begin	(SLIM_TKOFF_BASE_DOMEV0 + 249)
#define SLIM_TKNAM_DOMEV_smil_begin	(SLIM_TKNAM_BASE_DOMEV0 + 249)
#define SLIM_TKLEN_DOMEV_smil_begin	(10)
#define SLIM_TOKEN_DOMEV_smil_begin	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_smil_begin))
#define SLIM_TKOFF_DOMEV_smil_end	(SLIM_TKOFF_BASE_DOMEV0 + 260)
#define SLIM_TKNAM_DOMEV_smil_end	(SLIM_TKNAM_BASE_DOMEV0 + 260)
#define SLIM_TKLEN_DOMEV_smil_end	(8)
#define SLIM_TOKEN_DOMEV_smil_end	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_smil_end))
#define SLIM_TKOFF_DOMEV_DOMMouseScroll	(SLIM_TKOFF_BASE_DOMEV0 + 269)
#define SLIM_TKNAM_DOMEV_DOMMouseScroll	(SLIM_TKNAM_BASE_DOMEV0 + 269)
#define SLIM_TKLEN_DOMEV_DOMMouseScroll	(14)
#define SLIM_TOKEN_DOMEV_DOMMouseScroll	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_DOMMouseScroll))
#define SLIM_TKOFF_DOMEV_user	(SLIM_TKOFF_BASE_DOMEV0 + 284)
#define SLIM_TKNAM_DOMEV_user	(SLIM_TKNAM_BASE_DOMEV0 + 284)
#define SLIM_TKLEN_DOMEV_user	(4)
#define SLIM_TOKEN_DOMEV_user	(DOMEventInfo_GetItem(SLIM_TKID_DOMEV_user))
#define SLIM_TKOFF_BASE_DOMEV1	(SLIM_TKOFF_BASE_DOMEV0 + 289)
#define SLIM_TKNAM_BASE_DOMEV1	(SLIM_TKNAM_BASE_DOMEV0 + SLIM_TKOFF_BASE_DOMEV1)
#define SLIM_TKLEN_TOTAL_DOMEV	SLIM_TKOFF_BASE_DOMEV1

extern SLIM_ROM slim_char cSlim_TokenName_DOMEV[SLIM_TKLEN_TOTAL_DOMEV];

extern SLIM_ROM TDOMEventInfo cSlim_Token_DOMEV[SLIM_TOKEN_DOMEV_TOKENS];
#define DOMEventInfo_GetItem(id)		((TDOMEventInfo *)&cSlim_Token_DOMEV[(id)])
#define DOMEventInfo_GetItemName(id)	((slim_char *)cSlim_TokenName_DOMEV + ((TToken *)&cSlim_Token_DOMEV[(id)])->fOffset)
#define DOMEventInfo_GetItemNameLen(id)	(((TToken *)&cSlim_Token_DOMEV[(id)])->fLength)

TDOMEventInfo *DOMEventInfo_CaseFindSS(slim_char *in_s, slim_int in_slen);

SLIM_END_C_LINKAGE
#endif
