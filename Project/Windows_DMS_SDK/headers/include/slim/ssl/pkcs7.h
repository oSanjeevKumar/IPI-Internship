/*
	pkcs7.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/ssl/pkcs7.h 16    05/12/28 12:08 Someya $ */

#ifndef SLIM_PKCS7_H
#define SLIM_PKCS7_H

SLIM_BEGIN_C_LINKAGE

/*==========================================
	PKCS#7 v1.5

	Cryptographic Message Syntax Standard
 ==========================================*/

/* forward declaration */
typedef struct TP7KeyInfo_ TP7KeyInfo;
typedef struct TP7KeyInfo_ TPKCSKeyInfo;


/*-------------------------------------
	ContentInfo Wrapper (Public API)
 -------------------------------------*/

struct TP7KeyInfo_ {
	slim_int fType;
	slim_byte *fData;
	slim_int fSize;
};

enum {
	SLIM_P7KEYINFO_TYPE_PASSWORD = 0,	/* for Encrypted-Data */
	SLIM_P7KEYINFO_TYPE_PRIVATE_KEY,	/* for [SignedAnd]Enveloped-Data */
	SLIM_P7KEYINFO_TYPES
};

#define TP7ContentInfo_IsData(self)						(TASN1Object_ToOIDInfoID(&(self)->fContentType) == SLIM_TKID_A1OID_data)
#define TP7ContentInfo_IsSignedData(self)				(TASN1Object_ToOIDInfoID(&(self)->fContentType) == SLIM_TKID_A1OID_signedData)
#define TP7ContentInfo_IsEnvelopedData(self)			(TASN1Object_ToOIDInfoID(&(self)->fContentType) == SLIM_TKID_A1OID_envelopedData)
#define TP7ContentInfo_IsSignedAndEnvelopedData(self)	(TASN1Object_ToOIDInfoID(&(self)->fContentType) == SLIM_TKID_A1OID_signedAndEnvelopedData)
#define TP7ContentInfo_IsDigestedData(self)				(TASN1Object_ToOIDInfoID(&(self)->fContentType) == SLIM_TKID_A1OID_digestedData)
#define TP7ContentInfo_IsEncryptedData(self)			(TASN1Object_ToOIDInfoID(&(self)->fContentType) == SLIM_TKID_A1OID_encryptedData)

SLIM_END_C_LINKAGE

#endif /* SLIM_PKSC7_H */
