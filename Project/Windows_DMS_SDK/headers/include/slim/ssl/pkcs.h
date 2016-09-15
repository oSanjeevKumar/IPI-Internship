/*
	pkcs.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/ssl/pkcs.h 26    06/06/23 14:26 Siu $ */

#ifndef SLIM_PKCS_H
#define SLIM_PKCS_H

SLIM_BEGIN_C_LINKAGE

#define SLIM_PX_E_NOT_IMPLEMENTED				(-10001)
#define SLIM_PX_E_UNSUPPORTED_ALGO				(-10002)
#define SLIM_PX_E_VERIFY						(-10003)	/* fail to verify a cert chain */
#define SLIM_PX_E_BAD_CHAIN						(-10004)	/* bad chain */
#define SLIM_PX_E_DECODE						(-10005)	/* fail to decode */
#define SLIM_PX_E_NEED_CONFIRM					(-10010)	/* */
#define SLIM_PX_E_NEED_PASSWORD					(-10011)	/* */
#define SLIM_PX_E_NEED_PRKEY					(-10012)	/* */
#define SLIM_PX_E_NO_CERTS						(-10020)
#define SLIM_PX_E_NO_PRKEYS						(-10022)
#define SLIM_PX_E_DERIVED_KEY_TOO_LONG			(-10501)	/* for PKCS#5 */
#define SLIM_PX_E_DECRYPTION_ERROR				(-10502)	/* for PKCS#5 */
#define SLIM_PX_E_BAD_PARAMS					(-10503)	/* for PKCS#5 */
#define SLIM_PX_E_DECRYPT						(-10504)	/* for PKCS#5 */
#define SLIM_PX_E_UNKNOWN_PRKEY					(-11201)	/* for PKCS#12 [Shrouded]KeyBag */
#define SLIM_PX_E_UNKNOWN_CERT					(-11202)	/* for PKCS#12 CertBag */
#define SLIM_PX_E_UNKNOWN_CRL					(-11203)	/* for PKCS#12 CrlBag */
#define SLIM_PX_E_NO_MAC_DATA					(-11204)	/* for PKCS#12 password integrity mode */
#define SLIM_PX_E_AUTHENTICATE					(-11205)	/* for PKCS#12 authentication failure */

enum {
	SLIM_PX_IMPORTMGR_ST_DECODE = 0,
	SLIM_PX_IMPORTMGR_ST_AUTH,
	SLIM_PX_IMPORTMGR_ST_OPEN,
	SLIM_PX_IMPORTMGR_ST_EXTRACT,
	SLIM_PX_IMPORTMGR_ST_CLOSE,
	SLIM_PX_IMPORTMGR_ST_SORT,
	SLIM_PX_IMPORTMGR_ST_VERIFY,
	SLIM_PX_IMPORTMGR_ST_IMPORT,
	SLIM_PX_IMPORTMGR_ST_PANIC,
	SLIM_PX_IMPORTMGR_STS
};

typedef struct TPxImportMgr_ TPxImportMgr;

typedef slim_bool (*TPxImportMgrStartProc)(TPxImportMgr *self, slim_byte *in_content, slim_int in_content_len);
typedef void (*TPxImportMgrEndProc)(TPxImportMgr *self);
typedef slim_int (*TPxImportMgrStateProc)(TPxImportMgr *self);

struct TPxImportMgr_ {
	slim_int fFlag;
	slim_int fState;
	slim_byte *fContent;
	slim_int fContentLen;
	TCertList fBrowserCertList;
	TCertList fClientCertList;
	slim_int fVerificationResults;
	slim_byte *fClientPrKey;
	slim_int fClientPrKeyLen;
	slim_byte *fPassword;
	slim_int fPasswordLen;
	slim_opaque fUserData;
	TPxImportMgrStartProc fStartProc;
	TPxImportMgrEndProc fEndProc;
	TPxImportMgrStateProc fStateProcTable[SLIM_PX_IMPORTMGR_STS];
};

enum {
	SLIM_PX_IMPORTMGR_TYPE_P7 = 0,
	SLIM_PX_IMPORTMGR_TYPE_P12,
	SLIM_PX_IMPORTMGR_TYPES
};

#define SLIM_PX_IMPORTMGR_FLAG_NONE						SLIM_ASN1_FLAG_NONE
#define SLIM_PX_IMPORTMGR_FLAG_WAIT_PASSWORD			SLIM_ASN1_BF(0)	/* for PKCS#12 password mode */
#define SLIM_PX_IMPORTMGR_FLAG_WAIT_PRKEY				SLIM_ASN1_BF(1)	/* for PKCS#12 public-key mode */
#define SLIM_PX_IMPORTMGR_FLAG_WAIT_CONFIRM				SLIM_ASN1_BF(2)	/* whether import or not */
#define SLIM_PX_IMPORTMGR_FLAG_ALLOC_PRKEY				SLIM_ASN1_BF(3)	/* for PKCS#12. extracted private key */
#define SLIM_P12_IMPORTMGR_FLAG_AUTHSAFE_AVAIL			SLIM_ASN1_BF(16)
#define SLIM_P12_IMPORTMGR_FLAG_SAFECONTENTS_AVAIL		SLIM_ASN1_BF(17)
#define SLIM_P12_IMPORTMGR_FLAG_BEGIN_AUTH_SAFE_SEQ		SLIM_ASN1_BF(18)


#define TPxImportMgr_ExtractedCertList(self)		((self)->fClientCertList)
#define TPxImportMgr_VerificationResults(self)		((self)->fVerificationResults)

SLIM_END_C_LINKAGE

#endif /* SLIM_PKSC_H */
