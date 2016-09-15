/*
	schemeid.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/token/schemeid.h 4     05/12/28 12:08 Someya $ */

/* DO NOT EDIT! This file is generated automagically. */

#ifndef SLIM_TOKEN_SCHEMEID_H
#define SLIM_TOKEN_SCHEMEID_H


SLIM_BEGIN_C_LINKAGE

enum {
	SLIM_TKID_SCHEME_http_ = 0,
	SLIM_TKID_SCHEME_https_,
	SLIM_TKID_SCHEME_file_,
	SLIM_TKID_SCHEME_pict_,
	SLIM_TKID_SCHEME_javascript_,
	SLIM_TKID_SCHEME_data_,
	SLIM_TKID_SCHEME_about_,
	SLIM_TKID_SCHEME_ENUMS
};

#define SLIM_TOKEN_SCHEME_TOKENS SLIM_TKID_SCHEME_ENUMS
#define SLIM_TOKEN_SCHEME_ENUMS SLIM_TKID_SCHEME_ENUMS


SLIM_END_C_LINKAGE
#endif
