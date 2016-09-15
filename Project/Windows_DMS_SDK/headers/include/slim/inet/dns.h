/*
	dns.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/inet/dns.h 31    05/12/28 12:07 Someya $ */

#ifndef SLIM_DNS_H
#define SLIM_DNS_H

SLIM_BEGIN_C_LINKAGE

/* type */

enum {
	SLIM_DNS_MODE_IPV4_ONLY = 0,
	SLIM_DNS_MODE_IPV6 = 1
};

typedef slim_opaque TDNS;

/* API */

SLIM_END_C_LINKAGE
#endif
