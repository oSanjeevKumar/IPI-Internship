/*
	pkcs5.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/ssl/pkcs5.h 13    05/12/28 12:08 Someya $ */

#ifndef SLIM_PKCS5_H
#define SLIM_PKCS5_H

SLIM_BEGIN_C_LINKAGE

/*========================================
	PKCS#5 v2.0

	Password-Based Cryptgraphy Standard
 ========================================*/

/*----------
	PBES1
 ----------*/

#define SLIM_P5_SALT_SIZE	8

struct TPBESInfo_ {
	slim_int fType;
	slim_int fDigestAlgo;
	slim_int fCipherAlgo;
	slim_int fKeyLen;
	slim_int fBlkSize;
};
typedef struct TPBESInfo_ TPBESInfo;

struct TPBESParams_ {
	TPBESInfo *fInfo;
	slim_bool fEncryption;
	slim_byte *fPassword;
	slim_int fPasswordLen;
	slim_byte *fSalt;
	slim_int fSaltLen;
	slim_int fIterationCount;
};
typedef struct TPBESParams_ TPBESParams;

enum {
	SLIM_PBES_TYPE_P5PBES1 = 0,
	SLIM_PBES_TYPE_P5PBES2,
	SLIM_PBES_TYPE_P12PBES,
	SLIM_PBES_TYPES
};

/*-----------
	PBMAC1
 -----------*/

/* not implemented, yet... */

/*-------------
	Accessor
 -------------*/

SLIM_END_C_LINKAGE

#endif /* SLIM_PKSC5_H */
