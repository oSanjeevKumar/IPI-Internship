/*
	inetutil.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/inet/inetutil.h 25    05/12/28 12:07 Someya $ */

#ifndef SLIM_INETUTIL_H
#define SLIM_INETUTIL_H

SLIM_BEGIN_C_LINKAGE

#define slim_inet_split_header_cs(ss,cs) (!(cs) ? slim_false : (slim_inet_find_http_headerX((ss),(cs),slim_strlen(cs))) )
#define slim_inet_split_header_ss(ss,s,l) (!(s) ? slim_false : (slim_inet_find_http_headerX((ss),(s),(l))) )

SLIM_END_C_LINKAGE
#endif
