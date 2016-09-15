/*
	slim_regexp.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/basis/regexp.h 27    05/12/28 12:07 Someya $ */

#ifndef SLIM_REGEXP_H
#define SLIM_REGEXP_H

SLIM_BEGIN_C_LINKAGE

enum {
	SLIM_REGEXP_ERR_NOERR,
	SLIM_REGEXP_ERR_PARSE,
	SLIM_REGEXP_ERR_MEMORY,
	SLIM_REGEXP_ERRS
};

struct TRegExpTree_ {
	TTree fBase;
};
typedef struct TRegExpTree_ TRegExpTree;

struct TRegExpClass_ {
	TRegExpTree fTree;
};
typedef struct TRegExpClass_ TRegExpClass;

struct iTRegExp_ {
	slim_int dummy;
};
typedef struct iTRegExp_ **TRegExp;

#define SLIM_REGEXP_RESULT_FLAG_VALID 0x00000001

struct TRegExpResult_ {
	slim_int fFlag;
	slim_int fBufSize;
	slim_split_ss *fBuf;
	slim_split_ss fWhole;
};
typedef struct TRegExpResult_ TRegExpResult;

SLIM_END_C_LINKAGE

#endif /* SLIM_REGEXP_H */
