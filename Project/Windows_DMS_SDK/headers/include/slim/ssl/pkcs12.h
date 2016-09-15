/*
	pkcs12.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/ssl/pkcs12.h 19    05/12/28 12:08 Someya $ */

#ifndef SLIM_PKCS12_H
#define SLIM_PKCS12_H

SLIM_BEGIN_C_LINKAGE

/*=========================================
	PKCS#12 v1.0

	Personal Information Exchange Syntax
 =========================================*/

enum {
	SLIM_P12_NO_PRIVACY_MODE,
	SLIM_P12_PUBLICKEY_PRIVACY_MODE,
	SLIM_P12_PASSWORD_PRIVACY_MODE,
	SLIM_P12_UNSUPPORTED_PRIVACY_MODE
};

enum {
	SLIM_P12_NO_INTEGRITY_MODE,
	SLIM_P12_PUBLICKEY_INTEGRITY_MODE,
	SLIM_P12_PASSWORD_INTEGRITY_MODE,
	SLIM_P12_UNSUPPORTED_INTEGRITY_MODE
};

struct TP12AuthSafeIterator_ {
	TASN1Iterator fBase;
	TP7ContentInfo fContentInfo;
	slim_byte *fBuf;
	slim_int fLen;
};
typedef struct TP12AuthSafeIterator_ TP12AuthSafeIterator;


SLIM_END_C_LINKAGE

#endif /* SLIM_PKSC12_H */
