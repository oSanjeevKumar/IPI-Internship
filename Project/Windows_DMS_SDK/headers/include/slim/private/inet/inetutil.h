/*
	inetutil.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/inet/inetutil.h 27    05/12/28 12:08 Someya $ */

#ifndef SLIM_INETUTIL_H_PRIVATE
#define SLIM_INETUTIL_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

/* constant */
#define SLIM_MIME_CR			 SLIM_C('\015') 
#define SLIM_MIME_LF			 SLIM_C('\012') 
extern SLIM_ROM slim_char cSlim_MIME_CRLF[];
#define SLIM_MIME_CRLF	((slim_char *)cSlim_MIME_CRLF)
#define SLIM_MIME_CRLF_LEN (2)

enum {
	SLIM_INET_PATH_SAME,
	SLIM_INET_PATH_ANCESTOR,
	SLIM_INET_PATH_DESCENDANT,
	SLIM_INET_PATH_COUSIN
};




/* MIME/HTTP header */

#define slim_inet_split_header_id(ss,id) slim_inet_find_http_headerX((ss),slim_nil,(id))

SLIM_END_C_LINKAGE

#endif
