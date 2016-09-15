/*
	csspdid.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/token/csspdid.h 6     06/08/25 2:39 Yamabuti $ */

/* DO NOT EDIT! This file is generated automagically. */

#ifndef SLIM_TOKEN_CSSPDID_H
#define SLIM_TOKEN_CSSPDID_H


SLIM_BEGIN_C_LINKAGE

enum {
	SLIM_TKID_CSSPD_first_child = 0,
	SLIM_TKID_CSSPD_link,
	SLIM_TKID_CSSPD_visited,
	SLIM_TKID_CSSPD_hover,
	SLIM_TKID_CSSPD_active,
	SLIM_TKID_CSSPD_focus,
	SLIM_TKID_CSSPD_lang,
	SLIM_TKID_CSSPD_after,
	SLIM_TKID_CSSPD_before,
	SLIM_TKID_CSSPD_first_letter,
	SLIM_TKID_CSSPD_first_line,
	SLIM_TKID_CSSPD_first,
	SLIM_TKID_CSSPD_right,
	SLIM_TKID_CSSPD_left,
#ifdef SLIM_CONFIG_CSS_LEVEL_3
	SLIM_TKID_CSSPD_root,
	SLIM_TKID_CSSPD_last_child,
	SLIM_TKID_CSSPD_only_child,
	SLIM_TKID_CSSPD_empty,
#endif /* SLIM_CONFIG_CSS_LEVEL_3 */
	SLIM_TKID_CSSPD_ENUMS
};

#define SLIM_TOKEN_CSSPD_TOKENS SLIM_TKID_CSSPD_ENUMS
#define SLIM_TOKEN_CSSPD_ENUMS SLIM_TKID_CSSPD_ENUMS


SLIM_END_C_LINKAGE
#endif
