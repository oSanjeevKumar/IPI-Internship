/*
	chsetinf.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/basis/chsetinf.h 5     05/12/28 12:07 Someya $ */

#ifndef SLIM_CHARSETINFO_H
#define SLIM_CHARSETINFO_H

SLIM_BEGIN_C_LINKAGE

#define SLIM_CHARSET_FLAG_NONE	0x00
#define SLIM_CHARSET_FLAG_USE_ISO2022	0x01
#define SLIM_CHARSET_FLAG_GL_ISNOT_ASCII	0x02
#define SLIM_CHARSET_FLAG_MULTI_PATTERN	0x04 /* the charsets that have more than two patterns of a byte-sequence. */

struct TCharSetInfo_ {
	TToken fBase;	/* must be the first field */
	slim_int fLangSet;
	slim_byte fInfo[4]; /* [0] fixed length(0 means multibyte); [1] maximum bytes(0 means indeterminable); [2] minimum bytes(0 means indeterminable); [3] flag; */
	slim_int fCTypeFlags[2];
};
typedef struct TCharSetInfo_ TCharSetInfo;

SLIM_END_C_LINKAGE
#endif
