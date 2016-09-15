/*
	token.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/basis/token.h 26    05/12/28 12:07 Someya $ */

#ifndef SLIM_TOKEN_H
#define SLIM_TOKEN_H

SLIM_BEGIN_C_LINKAGE

#define SLIM_TOKEN_NONEXT SLIM_SHORT_MAX
#define SLIM_TOKEN_HASHMASK	0xffff

struct TToken_ {
	slim_int fOffset;
	slim_half fHash;
	slim_short fHashNext;
	slim_short fID;
	slim_short fLength;
};
typedef struct TToken_ TToken;
	/* when you make a type that inherits this type, this type must be the first field of the new type */


struct TTokenDict_ {
	slim_short fItemSize;
	slim_short fTableSize;
	slim_short fTableSizeMask;
};
typedef struct TTokenDict_ TTokenDict;

SLIM_END_C_LINKAGE
#endif
