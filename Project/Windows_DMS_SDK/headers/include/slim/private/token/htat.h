/*
	htat.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/token/htat.h 33    06/07/11 22:03 Yamabuti $ */

/* DO NOT EDIT! This file is generated automagically. */

#ifndef SLIM_TOKEN_HTAT_H
#define SLIM_TOKEN_HTAT_H

#include <slim/basis/base.h>
#include <slim/basis/token.h>
#include <slim/private/token/htatid.h>

SLIM_BEGIN_C_LINKAGE

#include <slim/www/htmltk.h>

#define SLIM_TKOFF_BASE_HTAT0	(0)
#define SLIM_TKNAM_BASE_HTAT0	((slim_char *)cSlim_TokenName_HTAT)
#define SLIM_TKOFF_HTAT_abbr	(SLIM_TKOFF_BASE_HTAT0 + 0)
#define SLIM_TKNAM_HTAT_abbr	(SLIM_TKNAM_BASE_HTAT0 + 0)
#define SLIM_TKLEN_HTAT_abbr	(4)
#define SLIM_TOKEN_HTAT_abbr	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_abbr))
#define SLIM_TKOFF_HTAT_accept_charset	(SLIM_TKOFF_BASE_HTAT0 + 5)
#define SLIM_TKNAM_HTAT_accept_charset	(SLIM_TKNAM_BASE_HTAT0 + 5)
#define SLIM_TKLEN_HTAT_accept_charset	(14)
#define SLIM_TOKEN_HTAT_accept_charset	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_accept_charset))
#define SLIM_TKOFF_HTAT_accept	(SLIM_TKOFF_BASE_HTAT0 + 20)
#define SLIM_TKNAM_HTAT_accept	(SLIM_TKNAM_BASE_HTAT0 + 20)
#define SLIM_TKLEN_HTAT_accept	(6)
#define SLIM_TOKEN_HTAT_accept	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_accept))
#define SLIM_TKOFF_HTAT_accesskey	(SLIM_TKOFF_BASE_HTAT0 + 27)
#define SLIM_TKNAM_HTAT_accesskey	(SLIM_TKNAM_BASE_HTAT0 + 27)
#define SLIM_TKLEN_HTAT_accesskey	(9)
#define SLIM_TOKEN_HTAT_accesskey	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_accesskey))
#define SLIM_TKOFF_HTAT_action	(SLIM_TKOFF_BASE_HTAT0 + 37)
#define SLIM_TKNAM_HTAT_action	(SLIM_TKNAM_BASE_HTAT0 + 37)
#define SLIM_TKLEN_HTAT_action	(6)
#define SLIM_TOKEN_HTAT_action	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_action))
#define SLIM_TKOFF_HTAT_align	(SLIM_TKOFF_BASE_HTAT0 + 44)
#define SLIM_TKNAM_HTAT_align	(SLIM_TKNAM_BASE_HTAT0 + 44)
#define SLIM_TKLEN_HTAT_align	(5)
#define SLIM_TOKEN_HTAT_align	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_align))
#define SLIM_TKOFF_HTAT_alink	(SLIM_TKOFF_BASE_HTAT0 + 50)
#define SLIM_TKNAM_HTAT_alink	(SLIM_TKNAM_BASE_HTAT0 + 50)
#define SLIM_TKLEN_HTAT_alink	(5)
#define SLIM_TOKEN_HTAT_alink	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_alink))
#define SLIM_TKOFF_HTAT_alt	(SLIM_TKOFF_BASE_HTAT0 + 56)
#define SLIM_TKNAM_HTAT_alt	(SLIM_TKNAM_BASE_HTAT0 + 56)
#define SLIM_TKLEN_HTAT_alt	(3)
#define SLIM_TOKEN_HTAT_alt	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_alt))
#define SLIM_TKOFF_HTAT_archive	(SLIM_TKOFF_BASE_HTAT0 + 60)
#define SLIM_TKNAM_HTAT_archive	(SLIM_TKNAM_BASE_HTAT0 + 60)
#define SLIM_TKLEN_HTAT_archive	(7)
#define SLIM_TOKEN_HTAT_archive	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_archive))
#define SLIM_TKOFF_HTAT_axis	(SLIM_TKOFF_BASE_HTAT0 + 68)
#define SLIM_TKNAM_HTAT_axis	(SLIM_TKNAM_BASE_HTAT0 + 68)
#define SLIM_TKLEN_HTAT_axis	(4)
#define SLIM_TOKEN_HTAT_axis	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_axis))
#define SLIM_TKOFF_HTAT_background	(SLIM_TKOFF_BASE_HTAT0 + 73)
#define SLIM_TKNAM_HTAT_background	(SLIM_TKNAM_BASE_HTAT0 + 73)
#define SLIM_TKLEN_HTAT_background	(10)
#define SLIM_TOKEN_HTAT_background	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_background))
#define SLIM_TKOFF_HTAT_balance	(SLIM_TKOFF_BASE_HTAT0 + 84)
#define SLIM_TKNAM_HTAT_balance	(SLIM_TKNAM_BASE_HTAT0 + 84)
#define SLIM_TKLEN_HTAT_balance	(7)
#define SLIM_TOKEN_HTAT_balance	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_balance))
#define SLIM_TKOFF_HTAT_bgcolor	(SLIM_TKOFF_BASE_HTAT0 + 92)
#define SLIM_TKNAM_HTAT_bgcolor	(SLIM_TKNAM_BASE_HTAT0 + 92)
#define SLIM_TKLEN_HTAT_bgcolor	(7)
#define SLIM_TOKEN_HTAT_bgcolor	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_bgcolor))
#define SLIM_TKOFF_HTAT_bgproperties	(SLIM_TKOFF_BASE_HTAT0 + 100)
#define SLIM_TKNAM_HTAT_bgproperties	(SLIM_TKNAM_BASE_HTAT0 + 100)
#define SLIM_TKLEN_HTAT_bgproperties	(12)
#define SLIM_TOKEN_HTAT_bgproperties	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_bgproperties))
#define SLIM_TKOFF_HTAT_border	(SLIM_TKOFF_BASE_HTAT0 + 113)
#define SLIM_TKNAM_HTAT_border	(SLIM_TKNAM_BASE_HTAT0 + 113)
#define SLIM_TKLEN_HTAT_border	(6)
#define SLIM_TOKEN_HTAT_border	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_border))
#define SLIM_TKOFF_HTAT_bordercolor	(SLIM_TKOFF_BASE_HTAT0 + 120)
#define SLIM_TKNAM_HTAT_bordercolor	(SLIM_TKNAM_BASE_HTAT0 + 120)
#define SLIM_TKLEN_HTAT_bordercolor	(11)
#define SLIM_TOKEN_HTAT_bordercolor	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_bordercolor))
#define SLIM_TKOFF_HTAT_bottommargin	(SLIM_TKOFF_BASE_HTAT0 + 132)
#define SLIM_TKNAM_HTAT_bottommargin	(SLIM_TKNAM_BASE_HTAT0 + 132)
#define SLIM_TKLEN_HTAT_bottommargin	(12)
#define SLIM_TOKEN_HTAT_bottommargin	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_bottommargin))
#define SLIM_TKOFF_HTAT_cellpadding	(SLIM_TKOFF_BASE_HTAT0 + 145)
#define SLIM_TKNAM_HTAT_cellpadding	(SLIM_TKNAM_BASE_HTAT0 + 145)
#define SLIM_TKLEN_HTAT_cellpadding	(11)
#define SLIM_TOKEN_HTAT_cellpadding	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_cellpadding))
#define SLIM_TKOFF_HTAT_cellspacing	(SLIM_TKOFF_BASE_HTAT0 + 157)
#define SLIM_TKNAM_HTAT_cellspacing	(SLIM_TKNAM_BASE_HTAT0 + 157)
#define SLIM_TKLEN_HTAT_cellspacing	(11)
#define SLIM_TOKEN_HTAT_cellspacing	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_cellspacing))
#define SLIM_TKOFF_HTAT_char	(SLIM_TKOFF_BASE_HTAT0 + 169)
#define SLIM_TKNAM_HTAT_char	(SLIM_TKNAM_BASE_HTAT0 + 169)
#define SLIM_TKLEN_HTAT_char	(4)
#define SLIM_TOKEN_HTAT_char	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_char))
#define SLIM_TKOFF_HTAT_charoff	(SLIM_TKOFF_BASE_HTAT0 + 174)
#define SLIM_TKNAM_HTAT_charoff	(SLIM_TKNAM_BASE_HTAT0 + 174)
#define SLIM_TKLEN_HTAT_charoff	(7)
#define SLIM_TOKEN_HTAT_charoff	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_charoff))
#define SLIM_TKOFF_HTAT_charset	(SLIM_TKOFF_BASE_HTAT0 + 182)
#define SLIM_TKNAM_HTAT_charset	(SLIM_TKNAM_BASE_HTAT0 + 182)
#define SLIM_TKLEN_HTAT_charset	(7)
#define SLIM_TOKEN_HTAT_charset	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_charset))
#define SLIM_TKOFF_HTAT_checked	(SLIM_TKOFF_BASE_HTAT0 + 190)
#define SLIM_TKNAM_HTAT_checked	(SLIM_TKNAM_BASE_HTAT0 + 190)
#define SLIM_TKLEN_HTAT_checked	(7)
#define SLIM_TOKEN_HTAT_checked	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_checked))
#define SLIM_TKOFF_HTAT_cite	(SLIM_TKOFF_BASE_HTAT0 + 198)
#define SLIM_TKNAM_HTAT_cite	(SLIM_TKNAM_BASE_HTAT0 + 198)
#define SLIM_TKLEN_HTAT_cite	(4)
#define SLIM_TOKEN_HTAT_cite	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_cite))
#define SLIM_TKOFF_HTAT_class	(SLIM_TKOFF_BASE_HTAT0 + 203)
#define SLIM_TKNAM_HTAT_class	(SLIM_TKNAM_BASE_HTAT0 + 203)
#define SLIM_TKLEN_HTAT_class	(5)
#define SLIM_TOKEN_HTAT_class	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_class))
#define SLIM_TKOFF_HTAT_classid	(SLIM_TKOFF_BASE_HTAT0 + 209)
#define SLIM_TKNAM_HTAT_classid	(SLIM_TKNAM_BASE_HTAT0 + 209)
#define SLIM_TKLEN_HTAT_classid	(7)
#define SLIM_TOKEN_HTAT_classid	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_classid))
#define SLIM_TKOFF_HTAT_clear	(SLIM_TKOFF_BASE_HTAT0 + 217)
#define SLIM_TKNAM_HTAT_clear	(SLIM_TKNAM_BASE_HTAT0 + 217)
#define SLIM_TKLEN_HTAT_clear	(5)
#define SLIM_TOKEN_HTAT_clear	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_clear))
#define SLIM_TKOFF_HTAT_code	(SLIM_TKOFF_BASE_HTAT0 + 223)
#define SLIM_TKNAM_HTAT_code	(SLIM_TKNAM_BASE_HTAT0 + 223)
#define SLIM_TKLEN_HTAT_code	(4)
#define SLIM_TOKEN_HTAT_code	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_code))
#define SLIM_TKOFF_HTAT_codebase	(SLIM_TKOFF_BASE_HTAT0 + 228)
#define SLIM_TKNAM_HTAT_codebase	(SLIM_TKNAM_BASE_HTAT0 + 228)
#define SLIM_TKLEN_HTAT_codebase	(8)
#define SLIM_TOKEN_HTAT_codebase	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_codebase))
#define SLIM_TKOFF_HTAT_codetype	(SLIM_TKOFF_BASE_HTAT0 + 237)
#define SLIM_TKNAM_HTAT_codetype	(SLIM_TKNAM_BASE_HTAT0 + 237)
#define SLIM_TKLEN_HTAT_codetype	(8)
#define SLIM_TOKEN_HTAT_codetype	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_codetype))
#define SLIM_TKOFF_HTAT_color	(SLIM_TKOFF_BASE_HTAT0 + 246)
#define SLIM_TKNAM_HTAT_color	(SLIM_TKNAM_BASE_HTAT0 + 246)
#define SLIM_TKLEN_HTAT_color	(5)
#define SLIM_TOKEN_HTAT_color	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_color))
#define SLIM_TKOFF_HTAT_cols	(SLIM_TKOFF_BASE_HTAT0 + 252)
#define SLIM_TKNAM_HTAT_cols	(SLIM_TKNAM_BASE_HTAT0 + 252)
#define SLIM_TKLEN_HTAT_cols	(4)
#define SLIM_TOKEN_HTAT_cols	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_cols))
#define SLIM_TKOFF_HTAT_colspan	(SLIM_TKOFF_BASE_HTAT0 + 257)
#define SLIM_TKNAM_HTAT_colspan	(SLIM_TKNAM_BASE_HTAT0 + 257)
#define SLIM_TKLEN_HTAT_colspan	(7)
#define SLIM_TOKEN_HTAT_colspan	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_colspan))
#define SLIM_TKOFF_HTAT_compact	(SLIM_TKOFF_BASE_HTAT0 + 265)
#define SLIM_TKNAM_HTAT_compact	(SLIM_TKNAM_BASE_HTAT0 + 265)
#define SLIM_TKLEN_HTAT_compact	(7)
#define SLIM_TOKEN_HTAT_compact	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_compact))
#define SLIM_TKOFF_HTAT_content	(SLIM_TKOFF_BASE_HTAT0 + 273)
#define SLIM_TKNAM_HTAT_content	(SLIM_TKNAM_BASE_HTAT0 + 273)
#define SLIM_TKLEN_HTAT_content	(7)
#define SLIM_TOKEN_HTAT_content	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_content))
#define SLIM_TKOFF_HTAT_coords	(SLIM_TKOFF_BASE_HTAT0 + 281)
#define SLIM_TKNAM_HTAT_coords	(SLIM_TKNAM_BASE_HTAT0 + 281)
#define SLIM_TKLEN_HTAT_coords	(6)
#define SLIM_TOKEN_HTAT_coords	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_coords))
#define SLIM_TKOFF_HTAT_data	(SLIM_TKOFF_BASE_HTAT0 + 288)
#define SLIM_TKNAM_HTAT_data	(SLIM_TKNAM_BASE_HTAT0 + 288)
#define SLIM_TKLEN_HTAT_data	(4)
#define SLIM_TOKEN_HTAT_data	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_data))
#define SLIM_TKOFF_HTAT_datetime	(SLIM_TKOFF_BASE_HTAT0 + 293)
#define SLIM_TKNAM_HTAT_datetime	(SLIM_TKNAM_BASE_HTAT0 + 293)
#define SLIM_TKLEN_HTAT_datetime	(8)
#define SLIM_TOKEN_HTAT_datetime	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_datetime))
#define SLIM_TKOFF_HTAT_declare	(SLIM_TKOFF_BASE_HTAT0 + 302)
#define SLIM_TKNAM_HTAT_declare	(SLIM_TKNAM_BASE_HTAT0 + 302)
#define SLIM_TKLEN_HTAT_declare	(7)
#define SLIM_TOKEN_HTAT_declare	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_declare))
#define SLIM_TKOFF_HTAT_defer	(SLIM_TKOFF_BASE_HTAT0 + 310)
#define SLIM_TKNAM_HTAT_defer	(SLIM_TKNAM_BASE_HTAT0 + 310)
#define SLIM_TKLEN_HTAT_defer	(5)
#define SLIM_TOKEN_HTAT_defer	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_defer))
#define SLIM_TKOFF_HTAT_dir	(SLIM_TKOFF_BASE_HTAT0 + 316)
#define SLIM_TKNAM_HTAT_dir	(SLIM_TKNAM_BASE_HTAT0 + 316)
#define SLIM_TKLEN_HTAT_dir	(3)
#define SLIM_TOKEN_HTAT_dir	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_dir))
#define SLIM_TKOFF_HTAT_disabled	(SLIM_TKOFF_BASE_HTAT0 + 320)
#define SLIM_TKNAM_HTAT_disabled	(SLIM_TKNAM_BASE_HTAT0 + 320)
#define SLIM_TKLEN_HTAT_disabled	(8)
#define SLIM_TOKEN_HTAT_disabled	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_disabled))
#define SLIM_TKOFF_HTAT_enctype	(SLIM_TKOFF_BASE_HTAT0 + 329)
#define SLIM_TKNAM_HTAT_enctype	(SLIM_TKNAM_BASE_HTAT0 + 329)
#define SLIM_TKLEN_HTAT_enctype	(7)
#define SLIM_TOKEN_HTAT_enctype	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_enctype))
#define SLIM_TKOFF_HTAT_face	(SLIM_TKOFF_BASE_HTAT0 + 337)
#define SLIM_TKNAM_HTAT_face	(SLIM_TKNAM_BASE_HTAT0 + 337)
#define SLIM_TKLEN_HTAT_face	(4)
#define SLIM_TOKEN_HTAT_face	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_face))
#define SLIM_TKOFF_HTAT_for	(SLIM_TKOFF_BASE_HTAT0 + 342)
#define SLIM_TKNAM_HTAT_for	(SLIM_TKNAM_BASE_HTAT0 + 342)
#define SLIM_TKLEN_HTAT_for	(3)
#define SLIM_TOKEN_HTAT_for	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_for))
#define SLIM_TKOFF_HTAT_frame	(SLIM_TKOFF_BASE_HTAT0 + 346)
#define SLIM_TKNAM_HTAT_frame	(SLIM_TKNAM_BASE_HTAT0 + 346)
#define SLIM_TKLEN_HTAT_frame	(5)
#define SLIM_TOKEN_HTAT_frame	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_frame))
#define SLIM_TKOFF_HTAT_frameborder	(SLIM_TKOFF_BASE_HTAT0 + 352)
#define SLIM_TKNAM_HTAT_frameborder	(SLIM_TKNAM_BASE_HTAT0 + 352)
#define SLIM_TKLEN_HTAT_frameborder	(11)
#define SLIM_TOKEN_HTAT_frameborder	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_frameborder))
#define SLIM_TKOFF_HTAT_headers	(SLIM_TKOFF_BASE_HTAT0 + 364)
#define SLIM_TKNAM_HTAT_headers	(SLIM_TKNAM_BASE_HTAT0 + 364)
#define SLIM_TKLEN_HTAT_headers	(7)
#define SLIM_TOKEN_HTAT_headers	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_headers))
#define SLIM_TKOFF_HTAT_height	(SLIM_TKOFF_BASE_HTAT0 + 372)
#define SLIM_TKNAM_HTAT_height	(SLIM_TKNAM_BASE_HTAT0 + 372)
#define SLIM_TKLEN_HTAT_height	(6)
#define SLIM_TOKEN_HTAT_height	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_height))
#define SLIM_TKOFF_HTAT_hidden	(SLIM_TKOFF_BASE_HTAT0 + 379)
#define SLIM_TKNAM_HTAT_hidden	(SLIM_TKNAM_BASE_HTAT0 + 379)
#define SLIM_TKLEN_HTAT_hidden	(6)
#define SLIM_TOKEN_HTAT_hidden	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_hidden))
#define SLIM_TKOFF_HTAT_href	(SLIM_TKOFF_BASE_HTAT0 + 386)
#define SLIM_TKNAM_HTAT_href	(SLIM_TKNAM_BASE_HTAT0 + 386)
#define SLIM_TKLEN_HTAT_href	(4)
#define SLIM_TOKEN_HTAT_href	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_href))
#define SLIM_TKOFF_HTAT_hreflang	(SLIM_TKOFF_BASE_HTAT0 + 391)
#define SLIM_TKNAM_HTAT_hreflang	(SLIM_TKNAM_BASE_HTAT0 + 391)
#define SLIM_TKLEN_HTAT_hreflang	(8)
#define SLIM_TOKEN_HTAT_hreflang	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_hreflang))
#define SLIM_TKOFF_HTAT_hspace	(SLIM_TKOFF_BASE_HTAT0 + 400)
#define SLIM_TKNAM_HTAT_hspace	(SLIM_TKNAM_BASE_HTAT0 + 400)
#define SLIM_TKLEN_HTAT_hspace	(6)
#define SLIM_TOKEN_HTAT_hspace	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_hspace))
#define SLIM_TKOFF_HTAT_http_equiv	(SLIM_TKOFF_BASE_HTAT0 + 407)
#define SLIM_TKNAM_HTAT_http_equiv	(SLIM_TKNAM_BASE_HTAT0 + 407)
#define SLIM_TKLEN_HTAT_http_equiv	(10)
#define SLIM_TOKEN_HTAT_http_equiv	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_http_equiv))
#define SLIM_TKOFF_HTAT_id	(SLIM_TKOFF_BASE_HTAT0 + 418)
#define SLIM_TKNAM_HTAT_id	(SLIM_TKNAM_BASE_HTAT0 + 418)
#define SLIM_TKLEN_HTAT_id	(2)
#define SLIM_TOKEN_HTAT_id	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_id))
#define SLIM_TKOFF_HTAT_ismap	(SLIM_TKOFF_BASE_HTAT0 + 421)
#define SLIM_TKNAM_HTAT_ismap	(SLIM_TKNAM_BASE_HTAT0 + 421)
#define SLIM_TKLEN_HTAT_ismap	(5)
#define SLIM_TOKEN_HTAT_ismap	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_ismap))
#define SLIM_TKOFF_HTAT_label	(SLIM_TKOFF_BASE_HTAT0 + 427)
#define SLIM_TKNAM_HTAT_label	(SLIM_TKNAM_BASE_HTAT0 + 427)
#define SLIM_TKLEN_HTAT_label	(5)
#define SLIM_TOKEN_HTAT_label	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_label))
#define SLIM_TKOFF_HTAT_lang	(SLIM_TKOFF_BASE_HTAT0 + 433)
#define SLIM_TKNAM_HTAT_lang	(SLIM_TKNAM_BASE_HTAT0 + 433)
#define SLIM_TKLEN_HTAT_lang	(4)
#define SLIM_TOKEN_HTAT_lang	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_lang))
#define SLIM_TKOFF_HTAT_language	(SLIM_TKOFF_BASE_HTAT0 + 438)
#define SLIM_TKNAM_HTAT_language	(SLIM_TKNAM_BASE_HTAT0 + 438)
#define SLIM_TKLEN_HTAT_language	(8)
#define SLIM_TOKEN_HTAT_language	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_language))
#define SLIM_TKOFF_HTAT_leftmargin	(SLIM_TKOFF_BASE_HTAT0 + 447)
#define SLIM_TKNAM_HTAT_leftmargin	(SLIM_TKNAM_BASE_HTAT0 + 447)
#define SLIM_TKLEN_HTAT_leftmargin	(10)
#define SLIM_TOKEN_HTAT_leftmargin	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_leftmargin))
#define SLIM_TKOFF_HTAT_link	(SLIM_TKOFF_BASE_HTAT0 + 458)
#define SLIM_TKNAM_HTAT_link	(SLIM_TKNAM_BASE_HTAT0 + 458)
#define SLIM_TKLEN_HTAT_link	(4)
#define SLIM_TOKEN_HTAT_link	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_link))
#define SLIM_TKOFF_HTAT_longdesc	(SLIM_TKOFF_BASE_HTAT0 + 463)
#define SLIM_TKNAM_HTAT_longdesc	(SLIM_TKNAM_BASE_HTAT0 + 463)
#define SLIM_TKLEN_HTAT_longdesc	(8)
#define SLIM_TOKEN_HTAT_longdesc	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_longdesc))
#define SLIM_TKOFF_HTAT_lowsrc	(SLIM_TKOFF_BASE_HTAT0 + 472)
#define SLIM_TKNAM_HTAT_lowsrc	(SLIM_TKNAM_BASE_HTAT0 + 472)
#define SLIM_TKLEN_HTAT_lowsrc	(6)
#define SLIM_TOKEN_HTAT_lowsrc	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_lowsrc))
#define SLIM_TKOFF_HTAT_marginheight	(SLIM_TKOFF_BASE_HTAT0 + 479)
#define SLIM_TKNAM_HTAT_marginheight	(SLIM_TKNAM_BASE_HTAT0 + 479)
#define SLIM_TKLEN_HTAT_marginheight	(12)
#define SLIM_TOKEN_HTAT_marginheight	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_marginheight))
#define SLIM_TKOFF_HTAT_marginwidth	(SLIM_TKOFF_BASE_HTAT0 + 492)
#define SLIM_TKNAM_HTAT_marginwidth	(SLIM_TKNAM_BASE_HTAT0 + 492)
#define SLIM_TKLEN_HTAT_marginwidth	(11)
#define SLIM_TOKEN_HTAT_marginwidth	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_marginwidth))
#define SLIM_TKOFF_HTAT_maxlength	(SLIM_TKOFF_BASE_HTAT0 + 504)
#define SLIM_TKNAM_HTAT_maxlength	(SLIM_TKNAM_BASE_HTAT0 + 504)
#define SLIM_TKLEN_HTAT_maxlength	(9)
#define SLIM_TOKEN_HTAT_maxlength	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_maxlength))
#define SLIM_TKOFF_HTAT_media	(SLIM_TKOFF_BASE_HTAT0 + 514)
#define SLIM_TKNAM_HTAT_media	(SLIM_TKNAM_BASE_HTAT0 + 514)
#define SLIM_TKLEN_HTAT_media	(5)
#define SLIM_TOKEN_HTAT_media	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_media))
#define SLIM_TKOFF_HTAT_method	(SLIM_TKOFF_BASE_HTAT0 + 520)
#define SLIM_TKNAM_HTAT_method	(SLIM_TKNAM_BASE_HTAT0 + 520)
#define SLIM_TKLEN_HTAT_method	(6)
#define SLIM_TOKEN_HTAT_method	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_method))
#define SLIM_TKOFF_HTAT_multiple	(SLIM_TKOFF_BASE_HTAT0 + 527)
#define SLIM_TKNAM_HTAT_multiple	(SLIM_TKNAM_BASE_HTAT0 + 527)
#define SLIM_TKLEN_HTAT_multiple	(8)
#define SLIM_TOKEN_HTAT_multiple	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_multiple))
#define SLIM_TKOFF_HTAT_name	(SLIM_TKOFF_BASE_HTAT0 + 536)
#define SLIM_TKNAM_HTAT_name	(SLIM_TKNAM_BASE_HTAT0 + 536)
#define SLIM_TKLEN_HTAT_name	(4)
#define SLIM_TOKEN_HTAT_name	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_name))
#define SLIM_TKOFF_HTAT_nohref	(SLIM_TKOFF_BASE_HTAT0 + 541)
#define SLIM_TKNAM_HTAT_nohref	(SLIM_TKNAM_BASE_HTAT0 + 541)
#define SLIM_TKLEN_HTAT_nohref	(6)
#define SLIM_TOKEN_HTAT_nohref	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_nohref))
#define SLIM_TKOFF_HTAT_noresize	(SLIM_TKOFF_BASE_HTAT0 + 548)
#define SLIM_TKNAM_HTAT_noresize	(SLIM_TKNAM_BASE_HTAT0 + 548)
#define SLIM_TKLEN_HTAT_noresize	(8)
#define SLIM_TOKEN_HTAT_noresize	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_noresize))
#define SLIM_TKOFF_HTAT_noshade	(SLIM_TKOFF_BASE_HTAT0 + 557)
#define SLIM_TKNAM_HTAT_noshade	(SLIM_TKNAM_BASE_HTAT0 + 557)
#define SLIM_TKLEN_HTAT_noshade	(7)
#define SLIM_TOKEN_HTAT_noshade	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_noshade))
#define SLIM_TKOFF_HTAT_nowrap	(SLIM_TKOFF_BASE_HTAT0 + 565)
#define SLIM_TKNAM_HTAT_nowrap	(SLIM_TKNAM_BASE_HTAT0 + 565)
#define SLIM_TKLEN_HTAT_nowrap	(6)
#define SLIM_TOKEN_HTAT_nowrap	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_nowrap))
#define SLIM_TKOFF_HTAT_object	(SLIM_TKOFF_BASE_HTAT0 + 572)
#define SLIM_TKNAM_HTAT_object	(SLIM_TKNAM_BASE_HTAT0 + 572)
#define SLIM_TKLEN_HTAT_object	(6)
#define SLIM_TOKEN_HTAT_object	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_object))
#define SLIM_TKOFF_HTAT_onabort	(SLIM_TKOFF_BASE_HTAT0 + 579)
#define SLIM_TKNAM_HTAT_onabort	(SLIM_TKNAM_BASE_HTAT0 + 579)
#define SLIM_TKLEN_HTAT_onabort	(7)
#define SLIM_TOKEN_HTAT_onabort	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_onabort))
#define SLIM_TKOFF_HTAT_onblur	(SLIM_TKOFF_BASE_HTAT0 + 587)
#define SLIM_TKNAM_HTAT_onblur	(SLIM_TKNAM_BASE_HTAT0 + 587)
#define SLIM_TKLEN_HTAT_onblur	(6)
#define SLIM_TOKEN_HTAT_onblur	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_onblur))
#define SLIM_TKOFF_HTAT_onchange	(SLIM_TKOFF_BASE_HTAT0 + 594)
#define SLIM_TKNAM_HTAT_onchange	(SLIM_TKNAM_BASE_HTAT0 + 594)
#define SLIM_TKLEN_HTAT_onchange	(8)
#define SLIM_TOKEN_HTAT_onchange	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_onchange))
#define SLIM_TKOFF_HTAT_onclick	(SLIM_TKOFF_BASE_HTAT0 + 603)
#define SLIM_TKNAM_HTAT_onclick	(SLIM_TKNAM_BASE_HTAT0 + 603)
#define SLIM_TKLEN_HTAT_onclick	(7)
#define SLIM_TOKEN_HTAT_onclick	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_onclick))
#define SLIM_TKOFF_HTAT_oncontextmenu	(SLIM_TKOFF_BASE_HTAT0 + 611)
#define SLIM_TKNAM_HTAT_oncontextmenu	(SLIM_TKNAM_BASE_HTAT0 + 611)
#define SLIM_TKLEN_HTAT_oncontextmenu	(13)
#define SLIM_TOKEN_HTAT_oncontextmenu	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_oncontextmenu))
#define SLIM_TKOFF_HTAT_ondblclick	(SLIM_TKOFF_BASE_HTAT0 + 625)
#define SLIM_TKNAM_HTAT_ondblclick	(SLIM_TKNAM_BASE_HTAT0 + 625)
#define SLIM_TKLEN_HTAT_ondblclick	(10)
#define SLIM_TOKEN_HTAT_ondblclick	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_ondblclick))
#define SLIM_TKOFF_HTAT_onerror	(SLIM_TKOFF_BASE_HTAT0 + 636)
#define SLIM_TKNAM_HTAT_onerror	(SLIM_TKNAM_BASE_HTAT0 + 636)
#define SLIM_TKLEN_HTAT_onerror	(7)
#define SLIM_TOKEN_HTAT_onerror	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_onerror))
#define SLIM_TKOFF_HTAT_onfocus	(SLIM_TKOFF_BASE_HTAT0 + 644)
#define SLIM_TKNAM_HTAT_onfocus	(SLIM_TKNAM_BASE_HTAT0 + 644)
#define SLIM_TKLEN_HTAT_onfocus	(7)
#define SLIM_TOKEN_HTAT_onfocus	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_onfocus))
#define SLIM_TKOFF_HTAT_onkeydown	(SLIM_TKOFF_BASE_HTAT0 + 652)
#define SLIM_TKNAM_HTAT_onkeydown	(SLIM_TKNAM_BASE_HTAT0 + 652)
#define SLIM_TKLEN_HTAT_onkeydown	(9)
#define SLIM_TOKEN_HTAT_onkeydown	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_onkeydown))
#define SLIM_TKOFF_HTAT_onkeypress	(SLIM_TKOFF_BASE_HTAT0 + 662)
#define SLIM_TKNAM_HTAT_onkeypress	(SLIM_TKNAM_BASE_HTAT0 + 662)
#define SLIM_TKLEN_HTAT_onkeypress	(10)
#define SLIM_TOKEN_HTAT_onkeypress	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_onkeypress))
#define SLIM_TKOFF_HTAT_onkeyup	(SLIM_TKOFF_BASE_HTAT0 + 673)
#define SLIM_TKNAM_HTAT_onkeyup	(SLIM_TKNAM_BASE_HTAT0 + 673)
#define SLIM_TKLEN_HTAT_onkeyup	(7)
#define SLIM_TOKEN_HTAT_onkeyup	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_onkeyup))
#define SLIM_TKOFF_HTAT_onload	(SLIM_TKOFF_BASE_HTAT0 + 681)
#define SLIM_TKNAM_HTAT_onload	(SLIM_TKNAM_BASE_HTAT0 + 681)
#define SLIM_TKLEN_HTAT_onload	(6)
#define SLIM_TOKEN_HTAT_onload	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_onload))
#define SLIM_TKOFF_HTAT_onmousedown	(SLIM_TKOFF_BASE_HTAT0 + 688)
#define SLIM_TKNAM_HTAT_onmousedown	(SLIM_TKNAM_BASE_HTAT0 + 688)
#define SLIM_TKLEN_HTAT_onmousedown	(11)
#define SLIM_TOKEN_HTAT_onmousedown	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_onmousedown))
#define SLIM_TKOFF_HTAT_onmousemove	(SLIM_TKOFF_BASE_HTAT0 + 700)
#define SLIM_TKNAM_HTAT_onmousemove	(SLIM_TKNAM_BASE_HTAT0 + 700)
#define SLIM_TKLEN_HTAT_onmousemove	(11)
#define SLIM_TOKEN_HTAT_onmousemove	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_onmousemove))
#define SLIM_TKOFF_HTAT_onmouseout	(SLIM_TKOFF_BASE_HTAT0 + 712)
#define SLIM_TKNAM_HTAT_onmouseout	(SLIM_TKNAM_BASE_HTAT0 + 712)
#define SLIM_TKLEN_HTAT_onmouseout	(10)
#define SLIM_TOKEN_HTAT_onmouseout	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_onmouseout))
#define SLIM_TKOFF_HTAT_onmouseover	(SLIM_TKOFF_BASE_HTAT0 + 723)
#define SLIM_TKNAM_HTAT_onmouseover	(SLIM_TKNAM_BASE_HTAT0 + 723)
#define SLIM_TKLEN_HTAT_onmouseover	(11)
#define SLIM_TOKEN_HTAT_onmouseover	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_onmouseover))
#define SLIM_TKOFF_HTAT_onmouseup	(SLIM_TKOFF_BASE_HTAT0 + 735)
#define SLIM_TKNAM_HTAT_onmouseup	(SLIM_TKNAM_BASE_HTAT0 + 735)
#define SLIM_TKLEN_HTAT_onmouseup	(9)
#define SLIM_TOKEN_HTAT_onmouseup	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_onmouseup))
#define SLIM_TKOFF_HTAT_onmousewheel	(SLIM_TKOFF_BASE_HTAT0 + 745)
#define SLIM_TKNAM_HTAT_onmousewheel	(SLIM_TKNAM_BASE_HTAT0 + 745)
#define SLIM_TKLEN_HTAT_onmousewheel	(12)
#define SLIM_TOKEN_HTAT_onmousewheel	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_onmousewheel))
#define SLIM_TKOFF_HTAT_onreset	(SLIM_TKOFF_BASE_HTAT0 + 758)
#define SLIM_TKNAM_HTAT_onreset	(SLIM_TKNAM_BASE_HTAT0 + 758)
#define SLIM_TKLEN_HTAT_onreset	(7)
#define SLIM_TOKEN_HTAT_onreset	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_onreset))
#define SLIM_TKOFF_HTAT_onselect	(SLIM_TKOFF_BASE_HTAT0 + 766)
#define SLIM_TKNAM_HTAT_onselect	(SLIM_TKNAM_BASE_HTAT0 + 766)
#define SLIM_TKLEN_HTAT_onselect	(8)
#define SLIM_TOKEN_HTAT_onselect	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_onselect))
#define SLIM_TKOFF_HTAT_onsubmit	(SLIM_TKOFF_BASE_HTAT0 + 775)
#define SLIM_TKNAM_HTAT_onsubmit	(SLIM_TKNAM_BASE_HTAT0 + 775)
#define SLIM_TKLEN_HTAT_onsubmit	(8)
#define SLIM_TOKEN_HTAT_onsubmit	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_onsubmit))
#define SLIM_TKOFF_HTAT_onunload	(SLIM_TKOFF_BASE_HTAT0 + 784)
#define SLIM_TKNAM_HTAT_onunload	(SLIM_TKNAM_BASE_HTAT0 + 784)
#define SLIM_TKLEN_HTAT_onunload	(8)
#define SLIM_TOKEN_HTAT_onunload	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_onunload))
#define SLIM_TKOFF_HTAT_profile	(SLIM_TKOFF_BASE_HTAT0 + 793)
#define SLIM_TKNAM_HTAT_profile	(SLIM_TKNAM_BASE_HTAT0 + 793)
#define SLIM_TKLEN_HTAT_profile	(7)
#define SLIM_TOKEN_HTAT_profile	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_profile))
#define SLIM_TKOFF_HTAT_prompt	(SLIM_TKOFF_BASE_HTAT0 + 801)
#define SLIM_TKNAM_HTAT_prompt	(SLIM_TKNAM_BASE_HTAT0 + 801)
#define SLIM_TKLEN_HTAT_prompt	(6)
#define SLIM_TOKEN_HTAT_prompt	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_prompt))
#define SLIM_TKOFF_HTAT_readonly	(SLIM_TKOFF_BASE_HTAT0 + 808)
#define SLIM_TKNAM_HTAT_readonly	(SLIM_TKNAM_BASE_HTAT0 + 808)
#define SLIM_TKLEN_HTAT_readonly	(8)
#define SLIM_TOKEN_HTAT_readonly	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_readonly))
#define SLIM_TKOFF_HTAT_rel	(SLIM_TKOFF_BASE_HTAT0 + 817)
#define SLIM_TKNAM_HTAT_rel	(SLIM_TKNAM_BASE_HTAT0 + 817)
#define SLIM_TKLEN_HTAT_rel	(3)
#define SLIM_TOKEN_HTAT_rel	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_rel))
#define SLIM_TKOFF_HTAT_rev	(SLIM_TKOFF_BASE_HTAT0 + 821)
#define SLIM_TKNAM_HTAT_rev	(SLIM_TKNAM_BASE_HTAT0 + 821)
#define SLIM_TKLEN_HTAT_rev	(3)
#define SLIM_TOKEN_HTAT_rev	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_rev))
#define SLIM_TKOFF_HTAT_rightmargin	(SLIM_TKOFF_BASE_HTAT0 + 825)
#define SLIM_TKNAM_HTAT_rightmargin	(SLIM_TKNAM_BASE_HTAT0 + 825)
#define SLIM_TKLEN_HTAT_rightmargin	(11)
#define SLIM_TOKEN_HTAT_rightmargin	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_rightmargin))
#define SLIM_TKOFF_HTAT_rows	(SLIM_TKOFF_BASE_HTAT0 + 837)
#define SLIM_TKNAM_HTAT_rows	(SLIM_TKNAM_BASE_HTAT0 + 837)
#define SLIM_TKLEN_HTAT_rows	(4)
#define SLIM_TOKEN_HTAT_rows	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_rows))
#define SLIM_TKOFF_HTAT_rowspan	(SLIM_TKOFF_BASE_HTAT0 + 842)
#define SLIM_TKNAM_HTAT_rowspan	(SLIM_TKNAM_BASE_HTAT0 + 842)
#define SLIM_TKLEN_HTAT_rowspan	(7)
#define SLIM_TOKEN_HTAT_rowspan	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_rowspan))
#define SLIM_TKOFF_HTAT_rules	(SLIM_TKOFF_BASE_HTAT0 + 850)
#define SLIM_TKNAM_HTAT_rules	(SLIM_TKNAM_BASE_HTAT0 + 850)
#define SLIM_TKLEN_HTAT_rules	(5)
#define SLIM_TOKEN_HTAT_rules	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_rules))
#define SLIM_TKOFF_HTAT_scheme	(SLIM_TKOFF_BASE_HTAT0 + 856)
#define SLIM_TKNAM_HTAT_scheme	(SLIM_TKNAM_BASE_HTAT0 + 856)
#define SLIM_TKLEN_HTAT_scheme	(6)
#define SLIM_TOKEN_HTAT_scheme	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_scheme))
#define SLIM_TKOFF_HTAT_scope	(SLIM_TKOFF_BASE_HTAT0 + 863)
#define SLIM_TKNAM_HTAT_scope	(SLIM_TKNAM_BASE_HTAT0 + 863)
#define SLIM_TKLEN_HTAT_scope	(5)
#define SLIM_TOKEN_HTAT_scope	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_scope))
#define SLIM_TKOFF_HTAT_scroll	(SLIM_TKOFF_BASE_HTAT0 + 869)
#define SLIM_TKNAM_HTAT_scroll	(SLIM_TKNAM_BASE_HTAT0 + 869)
#define SLIM_TKLEN_HTAT_scroll	(6)
#define SLIM_TOKEN_HTAT_scroll	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_scroll))
#define SLIM_TKOFF_HTAT_scrolling	(SLIM_TKOFF_BASE_HTAT0 + 876)
#define SLIM_TKNAM_HTAT_scrolling	(SLIM_TKNAM_BASE_HTAT0 + 876)
#define SLIM_TKLEN_HTAT_scrolling	(9)
#define SLIM_TOKEN_HTAT_scrolling	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_scrolling))
#define SLIM_TKOFF_HTAT_selected	(SLIM_TKOFF_BASE_HTAT0 + 886)
#define SLIM_TKNAM_HTAT_selected	(SLIM_TKNAM_BASE_HTAT0 + 886)
#define SLIM_TKLEN_HTAT_selected	(8)
#define SLIM_TOKEN_HTAT_selected	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_selected))
#define SLIM_TKOFF_HTAT_shape	(SLIM_TKOFF_BASE_HTAT0 + 895)
#define SLIM_TKNAM_HTAT_shape	(SLIM_TKNAM_BASE_HTAT0 + 895)
#define SLIM_TKLEN_HTAT_shape	(5)
#define SLIM_TOKEN_HTAT_shape	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_shape))
#define SLIM_TKOFF_HTAT_size	(SLIM_TKOFF_BASE_HTAT0 + 901)
#define SLIM_TKNAM_HTAT_size	(SLIM_TKNAM_BASE_HTAT0 + 901)
#define SLIM_TKLEN_HTAT_size	(4)
#define SLIM_TOKEN_HTAT_size	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_size))
#define SLIM_TKOFF_HTAT_span	(SLIM_TKOFF_BASE_HTAT0 + 906)
#define SLIM_TKNAM_HTAT_span	(SLIM_TKNAM_BASE_HTAT0 + 906)
#define SLIM_TKLEN_HTAT_span	(4)
#define SLIM_TOKEN_HTAT_span	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_span))
#define SLIM_TKOFF_HTAT_src	(SLIM_TKOFF_BASE_HTAT0 + 911)
#define SLIM_TKNAM_HTAT_src	(SLIM_TKNAM_BASE_HTAT0 + 911)
#define SLIM_TKLEN_HTAT_src	(3)
#define SLIM_TOKEN_HTAT_src	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_src))
#define SLIM_TKOFF_HTAT_standby	(SLIM_TKOFF_BASE_HTAT0 + 915)
#define SLIM_TKNAM_HTAT_standby	(SLIM_TKNAM_BASE_HTAT0 + 915)
#define SLIM_TKLEN_HTAT_standby	(7)
#define SLIM_TOKEN_HTAT_standby	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_standby))
#define SLIM_TKOFF_HTAT_start	(SLIM_TKOFF_BASE_HTAT0 + 923)
#define SLIM_TKNAM_HTAT_start	(SLIM_TKNAM_BASE_HTAT0 + 923)
#define SLIM_TKLEN_HTAT_start	(5)
#define SLIM_TOKEN_HTAT_start	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_start))
#define SLIM_TKOFF_HTAT_style	(SLIM_TKOFF_BASE_HTAT0 + 929)
#define SLIM_TKNAM_HTAT_style	(SLIM_TKNAM_BASE_HTAT0 + 929)
#define SLIM_TKLEN_HTAT_style	(5)
#define SLIM_TOKEN_HTAT_style	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_style))
#define SLIM_TKOFF_HTAT_summary	(SLIM_TKOFF_BASE_HTAT0 + 935)
#define SLIM_TKNAM_HTAT_summary	(SLIM_TKNAM_BASE_HTAT0 + 935)
#define SLIM_TKLEN_HTAT_summary	(7)
#define SLIM_TOKEN_HTAT_summary	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_summary))
#define SLIM_TKOFF_HTAT_tabbable	(SLIM_TKOFF_BASE_HTAT0 + 943)
#define SLIM_TKNAM_HTAT_tabbable	(SLIM_TKNAM_BASE_HTAT0 + 943)
#define SLIM_TKLEN_HTAT_tabbable	(8)
#define SLIM_TOKEN_HTAT_tabbable	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_tabbable))
#define SLIM_TKOFF_HTAT_tabindex	(SLIM_TKOFF_BASE_HTAT0 + 952)
#define SLIM_TKNAM_HTAT_tabindex	(SLIM_TKNAM_BASE_HTAT0 + 952)
#define SLIM_TKLEN_HTAT_tabindex	(8)
#define SLIM_TOKEN_HTAT_tabindex	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_tabindex))
#define SLIM_TKOFF_HTAT_target	(SLIM_TKOFF_BASE_HTAT0 + 961)
#define SLIM_TKNAM_HTAT_target	(SLIM_TKNAM_BASE_HTAT0 + 961)
#define SLIM_TKLEN_HTAT_target	(6)
#define SLIM_TOKEN_HTAT_target	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_target))
#define SLIM_TKOFF_HTAT_text	(SLIM_TKOFF_BASE_HTAT0 + 968)
#define SLIM_TKNAM_HTAT_text	(SLIM_TKNAM_BASE_HTAT0 + 968)
#define SLIM_TKLEN_HTAT_text	(4)
#define SLIM_TOKEN_HTAT_text	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_text))
#define SLIM_TKOFF_HTAT_title	(SLIM_TKOFF_BASE_HTAT0 + 973)
#define SLIM_TKNAM_HTAT_title	(SLIM_TKNAM_BASE_HTAT0 + 973)
#define SLIM_TKLEN_HTAT_title	(5)
#define SLIM_TOKEN_HTAT_title	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_title))
#define SLIM_TKOFF_HTAT_topmargin	(SLIM_TKOFF_BASE_HTAT0 + 979)
#define SLIM_TKNAM_HTAT_topmargin	(SLIM_TKNAM_BASE_HTAT0 + 979)
#define SLIM_TKLEN_HTAT_topmargin	(9)
#define SLIM_TOKEN_HTAT_topmargin	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_topmargin))
#define SLIM_TKOFF_HTAT_type	(SLIM_TKOFF_BASE_HTAT0 + 989)
#define SLIM_TKNAM_HTAT_type	(SLIM_TKNAM_BASE_HTAT0 + 989)
#define SLIM_TKLEN_HTAT_type	(4)
#define SLIM_TOKEN_HTAT_type	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_type))
#define SLIM_TKOFF_HTAT_usemap	(SLIM_TKOFF_BASE_HTAT0 + 994)
#define SLIM_TKNAM_HTAT_usemap	(SLIM_TKNAM_BASE_HTAT0 + 994)
#define SLIM_TKLEN_HTAT_usemap	(6)
#define SLIM_TOKEN_HTAT_usemap	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_usemap))
#define SLIM_TKOFF_HTAT_valign	(SLIM_TKOFF_BASE_HTAT0 + 1001)
#define SLIM_TKNAM_HTAT_valign	(SLIM_TKNAM_BASE_HTAT0 + 1001)
#define SLIM_TKLEN_HTAT_valign	(6)
#define SLIM_TOKEN_HTAT_valign	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_valign))
#define SLIM_TKOFF_HTAT_value	(SLIM_TKOFF_BASE_HTAT0 + 1008)
#define SLIM_TKNAM_HTAT_value	(SLIM_TKNAM_BASE_HTAT0 + 1008)
#define SLIM_TKLEN_HTAT_value	(5)
#define SLIM_TOKEN_HTAT_value	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_value))
#define SLIM_TKOFF_HTAT_valuetype	(SLIM_TKOFF_BASE_HTAT0 + 1014)
#define SLIM_TKNAM_HTAT_valuetype	(SLIM_TKNAM_BASE_HTAT0 + 1014)
#define SLIM_TKLEN_HTAT_valuetype	(9)
#define SLIM_TOKEN_HTAT_valuetype	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_valuetype))
#define SLIM_TKOFF_HTAT_version	(SLIM_TKOFF_BASE_HTAT0 + 1024)
#define SLIM_TKNAM_HTAT_version	(SLIM_TKNAM_BASE_HTAT0 + 1024)
#define SLIM_TKLEN_HTAT_version	(7)
#define SLIM_TOKEN_HTAT_version	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_version))
#define SLIM_TKOFF_HTAT_vlink	(SLIM_TKOFF_BASE_HTAT0 + 1032)
#define SLIM_TKNAM_HTAT_vlink	(SLIM_TKNAM_BASE_HTAT0 + 1032)
#define SLIM_TKLEN_HTAT_vlink	(5)
#define SLIM_TOKEN_HTAT_vlink	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_vlink))
#define SLIM_TKOFF_HTAT_volume	(SLIM_TKOFF_BASE_HTAT0 + 1038)
#define SLIM_TKNAM_HTAT_volume	(SLIM_TKNAM_BASE_HTAT0 + 1038)
#define SLIM_TKLEN_HTAT_volume	(6)
#define SLIM_TOKEN_HTAT_volume	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_volume))
#define SLIM_TKOFF_HTAT_vspace	(SLIM_TKOFF_BASE_HTAT0 + 1045)
#define SLIM_TKNAM_HTAT_vspace	(SLIM_TKNAM_BASE_HTAT0 + 1045)
#define SLIM_TKLEN_HTAT_vspace	(6)
#define SLIM_TOKEN_HTAT_vspace	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_vspace))
#define SLIM_TKOFF_HTAT_width	(SLIM_TKOFF_BASE_HTAT0 + 1052)
#define SLIM_TKNAM_HTAT_width	(SLIM_TKNAM_BASE_HTAT0 + 1052)
#define SLIM_TKLEN_HTAT_width	(5)
#define SLIM_TOKEN_HTAT_width	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_width))
#define SLIM_TKOFF_HTAT_wrap	(SLIM_TKOFF_BASE_HTAT0 + 1058)
#define SLIM_TKNAM_HTAT_wrap	(SLIM_TKNAM_BASE_HTAT0 + 1058)
#define SLIM_TKLEN_HTAT_wrap	(4)
#define SLIM_TOKEN_HTAT_wrap	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_wrap))
#define SLIM_TKOFF_HTAT_behavior	(SLIM_TKOFF_BASE_HTAT0 + 1063)
#define SLIM_TKNAM_HTAT_behavior	(SLIM_TKNAM_BASE_HTAT0 + 1063)
#define SLIM_TKLEN_HTAT_behavior	(8)
#define SLIM_TOKEN_HTAT_behavior	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_behavior))
#define SLIM_TKOFF_HTAT_direction	(SLIM_TKOFF_BASE_HTAT0 + 1072)
#define SLIM_TKNAM_HTAT_direction	(SLIM_TKNAM_BASE_HTAT0 + 1072)
#define SLIM_TKLEN_HTAT_direction	(9)
#define SLIM_TOKEN_HTAT_direction	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_direction))
#define SLIM_TKOFF_HTAT_loop	(SLIM_TKOFF_BASE_HTAT0 + 1082)
#define SLIM_TKNAM_HTAT_loop	(SLIM_TKNAM_BASE_HTAT0 + 1082)
#define SLIM_TKLEN_HTAT_loop	(4)
#define SLIM_TOKEN_HTAT_loop	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_loop))
#define SLIM_TKOFF_HTAT_scrollamount	(SLIM_TKOFF_BASE_HTAT0 + 1087)
#define SLIM_TKNAM_HTAT_scrollamount	(SLIM_TKNAM_BASE_HTAT0 + 1087)
#define SLIM_TKLEN_HTAT_scrollamount	(12)
#define SLIM_TOKEN_HTAT_scrollamount	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_scrollamount))
#define SLIM_TKOFF_HTAT_scrolldelay	(SLIM_TKOFF_BASE_HTAT0 + 1100)
#define SLIM_TKNAM_HTAT_scrolldelay	(SLIM_TKNAM_BASE_HTAT0 + 1100)
#define SLIM_TKLEN_HTAT_scrolldelay	(11)
#define SLIM_TOKEN_HTAT_scrolldelay	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_scrolldelay))
#define SLIM_TKOFF_HTAT_xmlns	(SLIM_TKOFF_BASE_HTAT0 + 1112)
#define SLIM_TKNAM_HTAT_xmlns	(SLIM_TKNAM_BASE_HTAT0 + 1112)
#define SLIM_TKLEN_HTAT_xmlns	(5)
#define SLIM_TOKEN_HTAT_xmlns	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_xmlns))
#define SLIM_TKOFF_HTAT_jad	(SLIM_TKOFF_BASE_HTAT0 + 1118)
#define SLIM_TKNAM_HTAT_jad	(SLIM_TKNAM_BASE_HTAT0 + 1118)
#define SLIM_TKLEN_HTAT_jad	(3)
#define SLIM_TOKEN_HTAT_jad	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_jad))
#define SLIM_TKOFF_HTAT_datasrc	(SLIM_TKOFF_BASE_HTAT0 + 1122)
#define SLIM_TKNAM_HTAT_datasrc	(SLIM_TKNAM_BASE_HTAT0 + 1122)
#define SLIM_TKLEN_HTAT_datasrc	(7)
#define SLIM_TOKEN_HTAT_datasrc	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_datasrc))
#define SLIM_TKOFF_HTAT_datafld	(SLIM_TKOFF_BASE_HTAT0 + 1130)
#define SLIM_TKNAM_HTAT_datafld	(SLIM_TKNAM_BASE_HTAT0 + 1130)
#define SLIM_TKLEN_HTAT_datafld	(7)
#define SLIM_TOKEN_HTAT_datafld	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_datafld))
#define SLIM_TKOFF_HTAT_dataformatas	(SLIM_TKOFF_BASE_HTAT0 + 1138)
#define SLIM_TKNAM_HTAT_dataformatas	(SLIM_TKNAM_BASE_HTAT0 + 1138)
#define SLIM_TKLEN_HTAT_dataformatas	(12)
#define SLIM_TOKEN_HTAT_dataformatas	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_dataformatas))
#define SLIM_TKOFF_HTAT_datapagesize	(SLIM_TKOFF_BASE_HTAT0 + 1151)
#define SLIM_TKNAM_HTAT_datapagesize	(SLIM_TKNAM_BASE_HTAT0 + 1151)
#define SLIM_TKLEN_HTAT_datapagesize	(12)
#define SLIM_TOKEN_HTAT_datapagesize	(HTMLAttrInfo_GetItem(SLIM_TKID_HTAT_datapagesize))
#define SLIM_TKOFF_BASE_HTAT1	(SLIM_TKOFF_BASE_HTAT0 + 1164)
#define SLIM_TKNAM_BASE_HTAT1	(SLIM_TKNAM_BASE_HTAT0 + SLIM_TKOFF_BASE_HTAT1)
#define SLIM_TKLEN_TOTAL_HTAT	SLIM_TKOFF_BASE_HTAT1

extern SLIM_ROM slim_char cSlim_TokenName_HTAT[SLIM_TKLEN_TOTAL_HTAT];

extern SLIM_ROM THTMLAttrInfo cSlim_Token_HTAT[SLIM_TOKEN_HTAT_TOKENS];
#define HTMLAttrInfo_GetItem(id)		((THTMLAttrInfo *)&cSlim_Token_HTAT[(id)])
#define HTMLAttrInfo_GetItemName(id)	((slim_char *)cSlim_TokenName_HTAT + ((TToken *)&cSlim_Token_HTAT[(id)])->fOffset)
#define HTMLAttrInfo_GetItemNameLen(id)	(((TToken *)&cSlim_Token_HTAT[(id)])->fLength)

THTMLAttrInfo *HTMLAttrInfo_FindSS(slim_char *in_s, slim_int in_slen);

SLIM_END_C_LINKAGE
#endif
