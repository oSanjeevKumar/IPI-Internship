/*
	cert.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/ssl/cert.h 199   06/04/12 19:45 Nagamati $ */

#ifndef SLIM_CERT_H
#define SLIM_CERT_H

SLIM_BEGIN_C_LINKAGE

/* forward declaration */
typedef struct TCertDB_ TCertDB;
typedef struct TCertStore_ TCertStore;
typedef struct TCertStoreItem_ TCertStoreItem;
typedef struct TCertDBManager_ TCertDBManager;


/*==========================
    BER Encoder / Decoder
 ==========================*/

/* errors */
#define SLIM_BER_E_OK					 0
#define SLIM_BER_E_DECODE				-1
#define SLIM_BER_E_ENCODE				-2
#define SLIM_BER_E_NOT_IMPLEMENTED		-3

/* tag types */
#define SLIM_BER_TAG_CLASS_UNIV		0x00
#define SLIM_BER_TAG_CLASS_APPL		0x40
#define SLIM_BER_TAG_CLASS_CTXSP	0x80
#define SLIM_BER_TAG_CLASS_PRVT		0xc0
#define SLIM_BER_TAG_CLASS_MASK		0xc0

#define SLIM_BER_TAG_CONSTRUCTED	0x20
#define SLIM_BER_TAG_ID_MASK		0x1f

#define SLIM_BER_TAG_TYPE_EOC		0x00
#define SLIM_BER_TAG_TYPE_BOOLEAN	0x01
#define SLIM_BER_TAG_TYPE_INTEGER	0x02
#define SLIM_BER_TAG_TYPE_BITSTR	0x03
#define SLIM_BER_TAG_TYPE_OCTSTR	0x04
#define SLIM_BER_TAG_TYPE_NULL		0x05
#define SLIM_BER_TAG_TYPE_OID		0x06
#define SLIM_BER_TAG_TYPE_UTF8STR	0x0c
#define SLIM_BER_TAG_TYPE_SEQUENCE	0x30	/* 0x10 | CONSTRACTED */
#define SLIM_BER_TAG_TYPE_SET		0x31	/* 0x11 | CONSTRACTED */
#define SLIM_BER_TAG_TYPE_PRNTSTR	0x13
#define SLIM_BER_TAG_TYPE_T61STR	0x14
#define SLIM_BER_TAG_TYPE_IA5STR	0x16
#define SLIM_BER_TAG_TYPE_UTCTIME	0x17
#define SLIM_BER_TAG_TYPE_VSBLSTR	0x1a
#define SLIM_BER_TAG_TYPE_UNIVSTR	0x1c
#define SLIM_BER_TAG_TYPE_BMPSTR	0x1e
#define SLIM_BER_TAG_TYPE_MASK		0x3f


/*-------------------
	Algorithm OIDs
 -------------------*/

#define SLIM_BER_OID_ALGO_NULL					SLIM_CRYPT_MD_ALGO_NULL
#define SLIM_BER_OID_ALGO_MD2					SLIM_CRYPT_MD_ALGO_MD2
#define SLIM_BER_OID_ALGO_MD5					SLIM_CRYPT_MD_ALGO_MD5
#define SLIM_BER_OID_ALGO_SHA1					SLIM_CRYPT_MD_ALGO_SHA1
#define SLIM_BER_OID_ALGO_UNKNOWN				SLIM_CRYPT_SIGN_ALGO_UNKNOWN
#define SLIM_BER_OID_ALGO_RSA 					SLIM_CRYPT_SIGN_ALGO_RSA
#define SLIM_BER_OID_ALGO_MD2_WITH_RSA			SLIM_CRYPT_SIGN_ALGO_MD2_RSA
#define SLIM_BER_OID_ALGO_MD5_WITH_RSA			SLIM_CRYPT_SIGN_ALGO_MD5_RSA
#define SLIM_BER_OID_ALGO_SHA1_WITH_RSA			SLIM_CRYPT_SIGN_ALGO_SHA1_RSA
#define SLIM_BER_OID_ALGO_SHA1_WITH_RSA_SIGN	SLIM_CRYPT_SIGN_ALGO_SHA1_RSA_SIGN


/*----------------------
	DN Attribute OIDs
 ----------------------*/

enum {
	SLIM_BER_OID_DN_UNKNOWN = -1,
	SLIM_BER_OID_DN_COUNTRY_NAME,
	SLIM_BER_OID_DN_STATE_OR_PROVINCE_NAME,
	SLIM_BER_OID_DN_LOCALITY_NAME,
	SLIM_BER_OID_DN_STREET_ADDRESS,
	SLIM_BER_OID_DN_ORGANIZATION_NAME,
	SLIM_BER_OID_DN_ORGANIZATION_UNIT_NAME,
	SLIM_BER_OID_DN_COMMON_NAME,
	SLIM_BER_OID_DN_EMAIL_ADDRESS,
	SLIM_BER_OID_DNS,
	SLIM_BER_OID_DN_ALL
};


/*=====================
	Certificate Name
 =====================*/

struct TCertName_ {
	slim_int fAttr;
	slim_int fAttrLen;
	slim_byte *fAttrPtr;
	slim_int fStrType;
	slim_int fStrLen;
	slim_byte *fStr;
};
typedef struct TCertName_ TCertName;


/*================
	Certificate
 ================*/

/*------------------
	Configuration
 ------------------*/

/* Max CRL distribution points */
#define SLIM_CERT_CRLDP_MAX		4

/* Max certificate policies */
#define SLIM_CERT_POLICY_MAX	1

/* Max policy qualifiers */
#define SLIM_CERT_POLICY_QUALIFIER_MAX	4

	
/*----------------
	Error Flags
 ----------------*/

#define SLIM_CERT_E_OK						0x00000000	/* no errors */

/* fatal */
#define SLIM_CERT_E_NOMEM					0x01000000	/* no memory */
#define SLIM_CERT_E_DECODE					0x02000000	/* fail to decode */
#define SLIM_CERT_E_DB						0x04000000	/* DB error */
#define SLIM_CERT_E_VERIFY					0x08000000	/* fail to velify */
#define SLIM_CERT_E_TRUST					0x10000000	/* untrusted */
#define SLIM_CERT_E_SIGN_ALGO				0x20000000	/* unknown sing algo */
#define SLIM_CERT_E_BAD_CHAIN				0x40000000
#define SLIM_CERT_FATAL_ERR_MASK			0xff000000

/* extensions */
#define SLIM_CERT_E_BASIC_CONSTRAINTS		0x00010000	/* basic constraints error */
#define SLIM_CERT_E_KEY_USAGE				0x00020000	/* incorrect key usage */
#define SLIM_CERT_E_SUBJ_ALT_NAME			0x00040000	/* subject alt name */
#define SLIM_CERT_E_UNSUPPORTED_EXTENSIONS	0x00080000	/* unsupported extensions */
#define SLIM_CERT_EXTN_ERR_MASK				0x00ff0000

/* revocation check */
#define SLIM_CERT_E_NOCRL					0x00000100	/* no CRL */
#define SLIM_CERT_E_REVOKED					0x00000200	/* certificate has been revoked */
#define SLIM_CERT_CRL_MASK					0x0000ff00

/* warning */
#define SLIM_CERT_E_NOISSUER				0x00000001	/* certificate of issuer is not found */
#define SLIM_CERT_E_INVALID_CN				0x00000002	/* subjectCN do not match domain name */
#define SLIM_CERT_E_EXPIRED					0x00000004	/* certificate has been expired */
#define SLIM_CERT_E_ROOT_EXPIRED			0x00000008	/* root certificate has been expired */
#define SLIM_CERT_WARNING_ERR_MASK			0x000000ff


/*---------------------
	Certificate Type
 ---------------------*/

enum {
	SLIM_CERT_TYPE_NONE = -1,
	SLIM_CERT_TYPE_ROOT = 0,
	SLIM_CERT_TYPE_CA,
	SLIM_CERT_TYPE_SERVER,
	SLIM_CERT_TYPE_CLIENT,
	SLIM_CERT_TYPE_CRL,
	SLIM_CERT_TYPES
};

#define SLIM_CERT_TYPEFLAG_NONE		SLIM_FLAG_NONE
#define SLIM_CERT_TYPEFLAG_ROOT		(1 << SLIM_CERT_TYPE_ROOT)
#define SLIM_CERT_TYPEFLAG_CA		(1 << SLIM_CERT_TYPE_CA)
#define SLIM_CERT_TYPEFLAG_SERVER	(1 << SLIM_CERT_TYPE_SERVER)
#define SLIM_CERT_TYPEFLAG_CLIENT	(1 << SLIM_CERT_TYPE_CLIENT)
#define SLIM_CERT_TYPEFLAG_CRL		(1 << SLIM_CERT_TYPE_CRL)
#define SLIM_CERT_TYPEFLAG_SIGNER	(SLIM_CERT_TYPEFLAG_ROOT | SLIM_CERT_TYPEFLAG_CA)
#define SLIM_CERT_TYPEFLAG_USER		(SLIM_CERT_TYPEFLAG_SERVER | SLIM_CERT_TYPEFLAG_CLIENT)
#define SLIM_CERT_TYPEFLAG_CERT		(SLIM_CERT_TYPEFLAG_SIGNER | SLIM_CERT_TYPEFLAG_USER)
#define SLIM_CERT_TYPEFLAG_ALL		(SLIM_CERT_TYPEFLAG_CERT | SLIM_CERT_TYPEFLAG_CRL)


/*----------------
	Check Flags
 ----------------*/

#define SLIM_CERT_CHECK_NONE		0x00000000
#define SLIM_CERT_CHECK_CN			0x00000001
#define SLIM_CERT_CHECK_KU			0x00000002
#define SLIM_CERT_CHECK_BC			0x00000004
#define SLIM_CERT_CHECK_CRL			0x00000008
#define SLIM_CERT_CHECK_EKU			0x00000010
#define SLIM_CERT_CHECK_LOOP		0x00000020
#define SLIM_CERT_NO_CHECK_ROOT_BC	0x00000040


/*---------------------
	Digest Algorithm
 ---------------------*/

#define SLIM_CERT_DIGEST_ALGO_NULL	SLIM_BER_OID_ALGO_NULL
#define SLIM_CERT_DIGEST_ALGO_MD2	SLIM_BER_OID_ALGO_MD2
#define SLIM_CERT_DIGEST_ALGO_MD5	SLIM_BER_OID_ALGO_MD5
#define SLIM_CERT_DIGEST_ALGO_SHA1	SLIM_BER_OID_ALGO_SHA1


/*------------------------
	Signature Algorithm
 ------------------------*/

#define SLIM_CERT_SIGN_ALGO_UNKNOWN				SLIM_BER_OID_ALGO_UNKNOWN
#define SLIM_CERT_SIGN_ALGO_RSA 				SLIM_BER_OID_ALGO_RSA
#define SLIM_CERT_SIGN_ALGO_MD2_WITH_RSA		SLIM_BER_OID_ALGO_MD2_WITH_RSA
#define SLIM_CERT_SIGN_ALGO_MD5_WITH_RSA		SLIM_BER_OID_ALGO_MD5_WITH_RSA
#define SLIM_CERT_SIGN_ALGO_SHA1_WITH_RSA		SLIM_BER_OID_ALGO_SHA1_WITH_RSA
#define SLIM_CERT_SIGN_ALGO_SHA1_WITH_RSA_SIGN	SLIM_BER_OID_ALGO_SHA1_WITH_RSA_SIGN

 
/*------------------------
	Relative Name Types
 ------------------------*/

#define SLIM_CERT_NAME_UNKNOWN	SLIM_BER_OID_DN_UNKNOWN					/* unkown name type       */
#define SLIM_CERT_NAME_C		SLIM_BER_OID_DN_COUNTRY_NAME			/* country name           */
#define SLIM_CERT_NAME_S		SLIM_BER_OID_DN_STATE_OR_PROVINCE_NAME	/* state or provice name  */
#define SLIM_CERT_NAME_L		SLIM_BER_OID_DN_LOCALITY_NAME			/* locality name          */
#define SLIM_CERT_NAME_ST		SLIM_BER_OID_DN_STREET_ADDRESS			/* street address         */
#define SLIM_CERT_NAME_O		SLIM_BER_OID_DN_ORGANIZATION_NAME		/* organization name      */
#define SLIM_CERT_NAME_OU		SLIM_BER_OID_DN_ORGANIZATION_UNIT_NAME	/* organization unit name */
#define SLIM_CERT_NAME_CN		SLIM_BER_OID_DN_COMMON_NAME				/* common name            */
#define SLIM_CERT_NAME_EMAIL	SLIM_BER_OID_DN_EMAIL_ADDRESS			/* e-mail address         */
#define SLIM_CERT_NAME_ALL		SLIM_BER_OID_DN_ALL						/* for sequential access  */


/*--------------------
	RDN String Type
 --------------------*/

#define SLIM_CERT_RDN_STRTYPE_UTF8STR	SLIM_BER_TAG_TYPE_UTF8STR
#define SLIM_CERT_RDN_STRTYPE_PRNTSTR	SLIM_BER_TAG_TYPE_PRNTSTR
#define SLIM_CERT_RDN_STRTYPE_T61STR	SLIM_BER_TAG_TYPE_T61STR
#define SLIM_CERT_RDN_STRTYPE_IA5STR	SLIM_BER_TAG_TYPE_IA5STR
#define SLIM_CERT_RDN_STRTYPE_UNIVSTR	SLIM_BER_TAG_TYPE_UNIVSTR
#define SLIM_CERT_RDN_STRTYPE_BMPSTR	SLIM_BER_TAG_TYPE_BMPSTR


/*---------------
	Extensions
 ---------------*/

enum {
	SLIM_BER_EXTN_KEY_USAGE = 0,
	SLIM_BER_EXTN_CERT_POLICIES,
	SLIM_BER_EXTN_BASIC_CONSTRAINTS,
	SLIM_BER_EXTN_EXT_KEY_USAGE,
	SLIM_BER_EXTN_CRL_DIST_POINTS,
	SLIM_BER_EXTN_SUBJ_ALT_NAME,
	SLIM_BER_EXTN_UNKNOWN
};


/*----------------------
	Basic Constraints
 ----------------------*/

#define SLIM_CERT_BC_NONE	0
#define SLIM_CERT_BC_CA		1
#define SLIM_CERT_BC_NOT_CA	2


/*--------------
	Key Usage
 --------------*/

#define SLIM_CERT_KU_DIGITAL_SIGNATURE	0x0001
#define SLIM_CERT_KU_NON_REPUDIATION	0x0002
#define SLIM_CERT_KU_KEY_ENCIPHERMENT	0x0004
#define SLIM_CERT_KU_DATA_ENCIPHERMENT	0x0008
#define SLIM_CERT_KU_KEY_AGREEMENT		0x0010
#define SLIM_CERT_KU_KEY_CERT_SIGN		0x0020
#define SLIM_CERT_KU_CRL_SIGN			0x0040
#define SLIM_CERT_KU_ENCIPHER_ONLY		0x0080
#define SLIM_CERT_KU_DECIPHER_ONLY		0x0100


/*-----------------------
	Extended Key Usage
 -----------------------*/

#define SLIM_CERT_EKU_SRVR_AUTH			0x01
#define SLIM_CERT_EKU_CLNT_AUTH			0x02
#define	SLIM_CERT_EKU_CODE_SIGNING		0x04
#define SLIM_CERT_EKU_EMAIL_PROTECTION	0x08
#define SLIM_CERT_EKU_TIME_STAMPING		0x10
#define SLIM_CERT_EKU_OCSP_SIGING		0x20


/*----------------------------------------
	CRL Distribution Point Reason Flags
 ----------------------------------------*/

#define SLIM_CERT_CRLDP_RF_UNUSED					0x0001
#define SLIM_CERT_CRLDP_RF_KEY_COMPROMISE			0x0002
#define SLIM_CERT_CRLDP_RF_CA_COMPROMISE			0x0004
#define SLIM_CERT_CRLDP_RF_AFFILIATION_CHANGED		0x0008
#define SLIM_CERT_CRLDP_RF_SUPERSEDED				0x0010
#define SLIM_CERT_CRLDP_RF_CESSATION_OF_OPERATION	0x0020
#define SLIM_CERT_CRLDP_RF_CERTIFICATE_HOLD			0x0040


/*------------------------------------
	Certificate Policy Qualifier ID
 ------------------------------------*/

enum {
	SLIM_BER_QID_CPS,
	SLIM_BER_QID_UNOTICE,
	SLIM_BER_QID_UNKNOWN
};


/*------------------
	Serial Number
 ------------------*/

struct TCertSerNo_ {
	slim_int fLen;
	slim_byte *fData;
};
typedef struct TCertSerNo_ TCertSerNo;


/*-----------------------
	Distinguished Name
 -----------------------*/

struct TCertDN_ {
	slim_int fLen;
	slim_byte *fData;

	/* Ugh!: should separate into dn and cookie... */
	slim_int fAttr;
	slim_int fStrType;
	slim_int fPeekAttr;
	slim_byte *fPeekCur;
	slim_int fRDNLen;
};
typedef struct TCertDN_ TCertDN;

/* general name */
struct TCertGN_ {
	slim_int fLen;
	slim_byte *fData;
	slim_int fType;
};
typedef struct TCertGN_ TCertGN;

/* general name types */
enum {
	SLIM_BER_GN_TYPE_OTHER_NAME = 0,
	SLIM_BER_GN_TYPE_RFC882_NAME,
	SLIM_BER_GN_TYPE_DNS_NAME,
	SLIM_BER_GN_TYPE_X400_ADDR,
	SLIM_BER_GN_TYPE_DIR_NAME,
	SLIM_BER_GN_TYPE_EDIPARTY_NAME,
	SLIM_BER_GN_TYPE_URI,
	SLIM_BER_GN_TYPE_IP,
	SLIM_BER_GN_TYPE_REG_ID,
	SLIM_BER_GN_TYPES,

	SLIM_BER_GN_TYPE_ALL = SLIM_BER_GN_TYPES
};


/*---------------
	Extensions
 ---------------*/

/* distribution point name types */
enum {
	SLIM_CERT_CRLDP_NAME_TYPE_NONE = 0,
	SLIM_CERT_CRLDP_NAME_TYPE_GN,
	SLIM_CERT_CRLDP_NAME_TYPE_DN
};

/* crl distribution point */
struct TCertCRLDistPoint_ {
	slim_int fNameType;
	union {
		TCertGN uGN;
		TCertDN uDN;
	} fPointName;
	slim_int fReasonFlags;
	TCertGN fCRLIssuer;
};
typedef struct TCertCRLDistPoint_ TCertCRLDistPoint;

/* policy qualifier */
struct TCertPolicyQualifier_ {
	slim_int fType;
	union {
		struct {
			slim_int fLen;
			slim_byte *fURI;
		} CPSURI;
		struct {
			slim_int fOrgLen;
			slim_byte *fOrg;
			slim_int fTextLen;
			slim_byte *fText;
		} UNotice;
	} u;
};
typedef struct TCertPolicyQualifier_ TCertPolicyQualifier;

struct TCertPolicy_ {
	slim_int fIDLen;
	slim_byte *fID;
	slim_int fQualifierNum;
	TCertPolicyQualifier fQualifier[SLIM_CERT_POLICY_QUALIFIER_MAX];
};
typedef struct TCertPolicy_ TCertPolicy;

struct TCertAltName_ {
	slim_int fLen;
	slim_byte *fPtr;
};
typedef struct TCertAltName_ TCertAltName;


/*-----------
	Cookie
 -----------*/

struct TCertPeekCookie_AltName_ {
	slim_int fPeekType;
	slim_int fOffset;
};
typedef struct TCertPeekCookie_AltName_ TCertPeekCookie_AltName;

struct TCertPeekCookie_Extension_ {
	slim_int fExtnID;
	TASN1Object fExtensions;
	TASN1Iterator fIterator;
};
typedef struct TCertPeekCookie_Extension_ TCertPeekCookie_Extension;

union TCertPeekCookie_ {
	TCertPeekCookie_AltName	uAltName;
	TCertPeekCookie_Extension uExtension;
};
typedef union TCertPeekCookie_ TCertPeekCookie;


/*----------------------
	X.509 Certificate
 ----------------------*/

struct TCert_ {
	slim_int fListIndex;
	TCertStoreItem *fStoreItem;

	slim_int fFlag;	/* SLIM_CERT_FLAG_XXX */

	/* Certificate Informations */
	slim_int fVersion;			/* Version        */
	TCertSerNo fSerNo;			/* Serial Number  */
	slim_int fSignAlgo;			/* Sign Algorithm */
	TCertDN fIssuer;			/* Issuer DN      */
	slim_time fValidityStart;	/* Validiry Start */
	slim_time fValidityEnd;		/* Validity End   */
	TCertDN fSubject;			/* Subject DN     */
	TRSAPublicKey fPublicKey;	/* RSA Publid Key */

	/* for library (authentication and DB manipulation) */
	slim_byte *fPtr; /* pointer to certificate */
	slim_word fLen; /* length of certificate  */
	slim_byte *fInfo; /* pointer to Information */
	slim_word fInfoLen; /* length of Information  */
	slim_byte *fSign; /* pointer to Signature   */
	slim_word fSignLen; /* length of Signature    */

	/* Extensions */
	slim_byte *fExtensionsPtr;
	slim_int fExtensionsLen;
	slim_int fIsCA;
	slim_int fPathDepth;
	slim_word fKeyUsage;
	slim_word fExtKeyUsage;
	TCertAltName fSubjAltName;
	slim_int fCRLDPNum;
	TCertCRLDistPoint fCRLDistPoint[SLIM_CERT_CRLDP_MAX];
	slim_int fPolicyNum;
	TCertPolicy fPolicy[SLIM_CERT_POLICY_MAX];
};
typedef struct TCert_ TCert;

#define SLIM_CERT_FLAG_NONE								0x00000000
#define SLIM_CERT_FLAG_UNSUPPORTED_CRITICAL_EXTENSIONS	0x00000001

/* API */
#ifdef SLIM_CONFIG_USE_SSL
#define Cert_New()								(Cert_NewX(slim_false))
#define TCert_Name(self)						((self)->fStoreItem != slim_nil ? (self)->fStoreItem->fName : slim_nil)
#define TCert_NameLen(self)						((self)->fStoreItem != slim_nil ? (self)->fStoreItem->fNameLen : 0)
#define TCert_PeekVersion(self)					((self)->fVersion)
#define TCert_PeekSignAlgo(self)				((self)->fSignAlgo)
#define TCert_PeekValidityStart(self, start)	{(*(start)) = (self)->fValidityStart;}	/* (slim_time *)start */
#define TCert_PeekValidityEnd(self, end)		{(*(end)) = (self)->fValidityEnd;}		/* (slim_time *)end   */
#define TCert_PeekRSAPublicKeyBits(self)		(TCert_PeekSignAlgo(self) == SLIM_BER_OID_ALGO_UNKNOWN ? 0 : (self)->fPublicKey.fModulus.fLen * 8)
#define TCertDN_PeekRDNAttr(self)				((self)->fAttr)
#define TCertDN_PeekRDNStrType(self)			((self)->fStrType)
#else /* SLIM_CONFIG_USE_SSL */
/* dummy */
#define Cert_New()								(slim_nil)
#define TCert_Delete(self)						((void)0)
#define TCert_Name(self)						slim_nil
#define TCert_NameLen(self)						(0)
#define TCert_PeekSerialNumber(self, out_str)	(-1)
#define TCert_Decode(self, in_der_cert, in_len)	(SLIM_CERT_E_DECODE)
#define TCert_PeekVersion(self)					(1)
#define TCert_PeekSignAlgo(self)				(SLIM_BER_OID_ALGO_UNKNOWN)
#define TCert_PeekValidityStart(self, start)	((void)0)
#define TCert_PeekValidityEnd(self, end)		((void)0)
#define TCert_PeekRSAPublicKeyBits(self)		(0)
#define TCertDN_BeginPeekRDN(self, in_attr)		(slim_false)
#define TCertDN_PeekRDN(self, out_str)			(-1)
#define TCertDN_PeekRDNAttr(self)				(0)
#define TCertDN_PeekRDNStrType(self)			(0)
#define TCertDN_EndPeekRDN(self)				((void)0)
#endif /* SLIM_CONFIG_USE_SSL */

#define TCert_BeginPeekIssuerRDN(self, attr)	TCertDN_BeginPeekRDN(&((self)->fIssuer), attr)
#define TCert_PeekIssuerRDN(self, str)			TCertDN_PeekRDN(&((self)->fIssuer), str)
#define TCert_PeekIssuerRDNAttr(self)			TCertDN_PeekRDNAttr(&((self)->fIssuer))
#define TCert_PeekIssuerRDNStrType(self)		TCertDN_PeekRDNStrType(&((self)->fIssuer))
#define TCert_EndPeekIssuerRDN(self)			TCertDN_EndPeekRDN(&((self)->fIssuer))
#define TCert_BeginPeekSubjectRDN(self, attr)	TCertDN_BeginPeekRDN(&((self)->fSubject), attr)
#define TCert_PeekSubjectRDN(self, str)			TCertDN_PeekRDN(&((self)->fSubject), str)
#define TCert_PeekSubjectRDNAttr(self)			TCertDN_PeekRDNAttr(&((self)->fSubject))
#define TCert_PeekSubjectRDNStrType(self)		TCertDN_PeekRDNStrType(&((self)->fSubject))
#define TCert_EndPeekSubjectRDN(self)			TCertDN_EndPeekRDN(&((self)->fSubject))


/*================================
	Certificate Revocation List
 ================================*/

/*----------
	Error
 ----------*/

#define SLIM_CRL_E_OK			 0
#define SLIM_CRL_E_DECODE		-1
#define SLIM_CRL_E_SIGN			-2
#define SLIM_CRL_E_GENERIC		-3
#define SLIM_CRL_E_VERIFY		-4
#define SLIM_CRL_E_REVOKED		-5
#define SLIM_CRL_E_NOISSUER		-6
#define SLIM_CRL_E_DB			-7
#define SLIM_CRL_E_TRUST		-8
#define SLIM_CRL_E_NOMEM		-9


/*---------------------
	Digest Algorithm
 ---------------------*/

#define SLIM_CRL_DIGEST_ALGO_NULL	SLIM_BER_OID_ALGO_NULL
#define SLIM_CRL_DIGEST_ALGO_MD2	SLIM_BER_OID_ALGO_MD2
#define SLIM_CRL_DIGEST_ALGO_MD5	SLIM_BER_OID_ALGO_MD5
#define SLIM_CRL_DIGEST_ALGO_SHA1	SLIM_BER_OID_ALGO_SHA1


/*------------------------
	Signature Algorithm
 ------------------------*/

#define SLIM_CRL_SIGN_ALGO_UNKNOWN				SLIM_BER_OID_ALGO_UNKNOWN
#define SLIM_CRL_SIGN_ALGO_RSA 					SLIM_BER_OID_ALGO_RSA
#define SLIM_CRL_SIGN_ALGO_MD2_WITH_RSA			SLIM_BER_OID_ALGO_MD2_WITH_RSA
#define SLIM_CRL_SIGN_ALGO_MD5_WITH_RSA			SLIM_BER_OID_ALGO_MD5_WITH_RSA
#define SLIM_CRL_SIGN_ALGO_SHA1_WITH_RSA		SLIM_BER_OID_ALGO_SHA1_WITH_RSA
#define SLIM_CRL_SIGN_ALGO_SHA1_WITH_RSA_SIGN	SLIM_BER_OID_ALGO_SHA1_WITH_RSA_SIGN

 
/*------------------------
	Relative Name Types
 ------------------------*/

#define SLIM_CRL_NAME_UNKNOWN	SLIM_BER_OID_DN_UNKNOWN					/* unkown name type       */
#define SLIM_CRL_NAME_C			SLIM_BER_OID_DN_COUNTRY_NAME			/* country name           */
#define SLIM_CRL_NAME_S			SLIM_BER_OID_DN_STATE_OR_PROVINCE_NAME	/* state or provice name  */
#define SLIM_CRL_NAME_L			SLIM_BER_OID_DN_LOCALITY_NAME			/* locality name          */
#define SLIM_CRL_NAME_ST		SLIM_BER_OID_DN_STREET_ADDRESS			/* street address         */
#define SLIM_CRL_NAME_O			SLIM_BER_OID_DN_ORGANIZATION_NAME		/* organization name      */
#define SLIM_CRL_NAME_OU		SLIM_BER_OID_DN_ORGANIZATION_UNIT_NAME	/* organization unit name */
#define SLIM_CRL_NAME_CN		SLIM_BER_OID_DN_COMMON_NAME				/* common name            */
#define SLIM_CRL_NAME_EMAIL		SLIM_BER_OID_DN_EMAIL_ADDRESS			/* e-mail address         */
#define SLIM_CRL_NAME_ALL		SLIM_BER_OID_DN_ALL						/* for sequential access  */


/*--------------------
	RDN String Type
 --------------------*/

#define SLIM_CRL_RDN_STRTYPE_UTF8STR	SLIM_BER_TAG_TYPE_UTF8STR
#define SLIM_CRL_RDN_STRTYPE_PRNTSTR	SLIM_BER_TAG_TYPE_PRNTSTR
#define SLIM_CRL_RDN_STRTYPE_T61STR		SLIM_BER_TAG_TYPE_T61STR
#define SLIM_CRL_RDN_STRTYPE_IA5STR		SLIM_BER_TAG_TYPE_IA5STR
#define SLIM_CRL_RDN_STRTYPE_UNIVSTR	SLIM_BER_TAG_TYPE_UNIVSTR
#define SLIM_CRL_RDN_STRTYPE_BMPSTR		SLIM_BER_TAG_TYPE_BMPSTR


/*---------------------------------------------------
	CRL Structure
		CAUTION!! extensions is not supported, yet
 ---------------------------------------------------*/

struct TCRL_ {
	slim_byte *fPtr;
	slim_int fLen;
	slim_byte *fTBSCertList;
	slim_int fTBSCertListLen;
	slim_byte *fSign;
	slim_int fSignLen;

	slim_int fVersion;
	slim_int fSignAlgo;
	TCertDN fIssuer;
	slim_time fThisUpdate;
	slim_time fNextUpdate;	/* optional */
	slim_byte *fRevokedList;
	slim_int fRevokedListLen;
};
typedef struct TCRL_ TCRL;


/*=============
	Find Key
 =============*/

union TCertFindKey_ {
	slim_char *uName;
	TCertDN *uDN;
	TCert *uCert;
	TCRL *uCRL;
	struct {
		slim_byte *fPtr;
		slim_int fLen;
	} uDER;
};
typedef union TCertFindKey_ TCertFindKey;

/* key type */
enum {
	SLIM_CERT_KEYTYPE_ENUM = 0,
	SLIM_CERT_KEYTYPE_NAME,
	SLIM_CERT_KEYTYPE_ISSUER,
	SLIM_CERT_KEYTYPE_SUBJECT,
	SLIM_CERT_KEYTYPE_CERT,
	SLIM_CERT_KEYTYPE_CRL,
	SLIM_CERT_KEYTYPE_DERCERT,
	SLIM_CERT_KEYTYPE_DERCRL,
	SLIM_CERT_KEYTYPES
};


/*=====================
	Certificate List
 =====================*/

/* error code */
#define SLIM_CERTLIST_E_OK			 0
#define SLIM_CERTLIST_E_GENERIC		-1
#define SLIM_CERTLIST_E_NOMEM		-2
#define SLIM_CERTLIST_E_SAME		-3
#define SLIM_CERTLIST_E_DECODE		-4
#define SLIM_CERTLIST_E_FULL		-5

/* list types */
enum {
	SLIM_CERTLIST_TYPE_UNKNOWN = 0,
	SLIM_CERTLIST_TYPE_SERVER,
	SLIM_CERTLIST_TYPE_CLIENT,
	SLIM_CERTLIST_TYPE_BROWSER,
	SLIM_CERTLIST_TYPES
};

/* item flag */
#define SLIM_CERTLIST_CERTTYPE_MASK		0x000000ff	/* SLIM_CERT_TYPE_XXX */
#define SLIM_CERTLIST_FLAG_HANDLE		0x00000100
#define SLIM_CERTLIST_FLAG_BROWSER		0x00000400
#define SLIM_CERTLIST_FLAG_DELETED		0x00000800
#define SLIM_CERTLIST_FLAG_SAVE			0xf0f00000

/* key type */
#define SLIM_CERTLIST_KEYTYPE_NAME		SLIM_CERT_KEYTYPE_NAME
#define SLIM_CERTLIST_KEYTYPE_ISSUER	SLIM_CERT_KEYTYPE_ISSUER
#define SLIM_CERTLIST_KEYTYPE_SUBJECT	SLIM_CERT_KEYTYPE_SUBJECT
#define SLIM_CERTLIST_KEYTYPE_CERT		SLIM_CERT_KEYTYPE_CERT
#define SLIM_CERTLIST_KEYTYPE_CRL		SLIM_CERT_KEYTYPE_CRL
#define SLIM_CERTLIST_KEYTYPE_DERCERT	SLIM_CERT_KEYTYPE_DERCERT
#define SLIM_CERTLIST_KEYTYPE_DERCRL	SLIM_CERT_KEYTYPE_DERCRL

struct TCertListImportInfo_ {
	slim_int fStoreType;
	slim_int fCertType;
	slim_int fRecFlag;
	slim_char *fName;
	slim_byte *fDERCert;
	slim_int fDERCertLen;
	slim_byte *fDERPrKey;
	slim_int fDERPrKeyLen;
};
typedef struct TCertListImportInfo_ TCertListImportInfo;

struct TCertListFindInfo_ {
	slim_int fKeyType;	/* SLIM_CERT_KEYTYPE_XXX */
	TCertFindKey fKey;
};
typedef struct TCertListFindInfo_ TCertListFindInfo;

struct iTCertList_ {
	TSpecArray fBase;
	slim_int fType;	/* SLIM_CERTLIST_TYPE_XXX */
	TCertDBManager *fManager;
};
typedef struct iTCertList_ iTCertList;
typedef struct iTCertList_ **TCertList;

/* API */
#ifdef SLIM_CONFIG_USE_SSL
#else /* SLIM_CONFIG_USE_SSL */
/* dummy */
#define CertList_New(in_type)											(slim_nil)
#define TCertList_Clone(self)											(slim_nil)
#define TCertList_Delete(self)											((void)0)
#define TCertList_ImportCert(self, in_info, in_over_write)				(SLIM_CERTLIST_E_GENERIC)
#define TCertList_ImportCRL(self, in_info, in_over_write)				(SLIM_CERTLIST_E_GENERIC)
#define TCertList_Find(self, in_info)									(-1)
#define TCertList_BeginDecode(self, in_index, out_cert)					(SLIM_CERTLIST_E_DECODE)
#define TCertList_EndDecode(self, in_cert)								((void)0)
#define TCertList_Length(self)											(0)
#define TCertList_Remove(self, in_index)								(slim_true)
#define TCertList_Type(self)											(0)
#define TCertList_Flag(self, in_index)									(0)
#define TCertList_RecFlag(self, in_index)								(0)
#define TCertList_SetRecFlag(self, in_index, in_flag, in_on)			((void)0)
#define TCertList_MakeCertName(self, in_index, out_name)				(SLIM_E_GENERIC)
#endif /* SLIM_CONFIG_USE_SSL */

#define TCertList_BeginDecodeFirst(self, cert)			TCertList_BeginDecode(self, 0, cert)
#define TCertList_BeginDecodeLast(self, cert)			TCertList_BeginDecode(self, TCertList_Length(self)-1, cert)
#define TCertList_CertType(self, index)					(TCertList_Flag(self, index) & SLIM_CERTLIST_CERTTYPE_MASK)
#define TCertList_IsBrowserCert(self, index)			(TCertList_Flag(self, index) & SLIM_CERTLIST_FLAG_BROWSER ? slim_true : slim_false)
#define TCertList_IsTrustForServer(self, index)			((TCertList_RecFlag(self, index) & SLIM_CDBREC_FLAG_TRUST_FOR_SERVER) != 0)
#define TCertList_IsTrustForClient(self, index)			((TCertList_RecFlag(self, index) & SLIM_CDBREC_FLAG_TRUST_FOR_CLIENT) != 0)
#define TCertList_IsTrustForCRL(self, index)			((TCertList_RecFlag(self, index) & SLIM_CDBREC_FLAG_TRUST_FOR_CRL) != 0)
#define TCertList_SetTrustForServer(self, index, on)	TCertList_SetRecFlag(self, index, SLIM_CDBREC_FLAG_TRUST_FOR_SERVER, on)
#define TCertList_SetTrustForClient(self, index, on)	TCertList_SetRecFlag(self, index, SLIM_CDBREC_FLAG_TRUST_FOR_CLIENT, on)
#define TCertList_SetTrustForCRL(self, index, on)		TCertList_SetRecFlag(self, index, SLIM_CDBREC_FLAG_TRUST_FOR_CRL, on)


/*============================
	Client Certificate List
 ============================*/

struct iTClientCertList_ {
	TSpecArray fBase;
};
typedef struct iTClientCertList_ iTClientCertList;
typedef iTClientCertList **TClientCertList;

/* API */
#ifdef SLIM_CONFIG_USE_SSL
#else /* SLIM_CONFIG_USE_SSL */
/* dummy */
#define TClientCertList_Clone(self)										(slim_nil)
#define TClientCertList_Delete(self)									((void)0)
#define TClientCertList_Length(self)									(0)
#define TClientCertList_CertPath(self, in_index)						(slim_nil)
#define TClientCertList_VerificationResults(self, index)				(0)
#endif /* SLIM_CONFIG_USE_SSL */


/*====================
	Cert Store Item
 ====================*/

struct TCertStoreItem_ {
	slim_int fFlag;
	slim_int fCertType;
	slim_int fStoreType;

	slim_byte *fName;
	slim_int fNameLen;

	slim_byte *fData;
	slim_int fDataLen;
	slim_int fSerialNumberOfs;
	slim_int fSerialNumberLen;
	slim_int fIssuerOfs;
	slim_int fIssuerLen;
	slim_int fSubjectOfs;
	slim_int fSubjectLen;

	slim_byte *fPrKey;
	slim_int fPrKeyLen;
};

#define SLIM_CDBREC_FLAG_TRUST_FOR_SERVER	0x00000001
#define SLIM_CDBREC_FLAG_TRUST_FOR_CLIENT	0x00000002
#define SLIM_CDBREC_FLAG_TRUST_FOR_CRL		0x00000004
#define SLIM_CDBREC_FLAG_EXTRACTABLE_PRKEY	0x00000008	/* extractable private key */

#define SLIM_CDBREC_FLAG_TRUST_FOR_ALL		(SLIM_CDBREC_FLAG_TRUST_FOR_SERVER | \
											 SLIM_CDBREC_FLAG_TRUST_FOR_CLIENT | \
											 SLIM_CDBREC_FLAG_TRUST_FOR_CRL      )

#define SLIM_CERTSTORE_UPDATE_FLAG		0x00000001	/* fFlag */
#define SLIM_CERTSTORE_UPDATE_CERTTYPE	0x00000002	/* CertType */
#define SLIM_CERTSTORE_UPDATE_NAME		0x00000004	/* fName* */
#define SLIM_CERTSTORE_UPDATE_DATA		0x00000008	/* fData*, fSerialNumber*, fIssuer*, fSubject* */
#define SLIM_CERTSTORE_UPDATE_PRKEY		0x00000010	/* fPrKey* */
#define SLIM_CERTSTORE_UPDATE_ALL		(SLIM_CERTSTORE_UPDATE_FLAG | SLIM_CERTSTORE_UPDATE_CERTTYPE | SLIM_CERTSTORE_UPDATE_NAME | SLIM_CERTSTORE_UPDATE_DATA | SLIM_CERTSTORE_UPDATE_PRKEY)


/*===================
	Cert Find Info
 ===================*/

struct TCertFindInfo_ {
	slim_int fFrom;		/* SLIM_CERT_TYPEFLAG_XXX */
	slim_int fKeyType;	/* SLIM_CERT_KEYTYPE_XXX */
	TCertFindKey fKey;
};
typedef struct TCertFindInfo_ TCertFindInfo;


/*======================
    Certificate Store
 ======================*/

/* SLIM_E_XXX */
#define SLIM_CERTSTORE_E_FULL		(SLIM_E_enum_tail - 1)
#define SLIM_CERTSTORE_E_SAME		(SLIM_E_enum_tail - 2)
#define SLIM_CERTSTORE_E_DECODE		(SLIM_E_enum_tail - 3)

enum {
	SLIM_CERT_STORE_TYPE_NONE = -1,
	SLIM_CERT_STORE_TYPE_ROM = 0,
	SLIM_CERT_STORE_TYPE_MEM,
	SLIM_CERT_STORE_TYPE_EXT,
	SLIM_CERT_STORE_TYPES
};

#define SLIM_CERTSTORE_OPENMODE_READ	0x00000001
#define SLIM_CERTSTORE_OPENMODE_WRITE	0x00000002
#define SLIM_CERTSTORE_OPENMODE_RW		(SLIM_CERTSTORE_OPENMODE_READ | SLIM_CERTSTORE_OPENMODE_WRITE)

typedef slim_int (*TCertStoreOpenProc)(TCertStore *self, slim_int in_mode, slim_opaque *out_desc);
typedef void (*TCertStoreCloseProc)(TCertStore *self, slim_opaque in_desc);
typedef slim_int (*TCertStoreImportProc)(TCertStore *self, slim_opaque in_desc, TCertStoreItem *in_item, slim_opaque *out_id);
typedef slim_int (*TCertStoreDeleteProc)(TCertStore *self, slim_opaque in_desc, slim_opaque in_id);
typedef slim_int (*TCertStoreBeginFindProc)(TCertStore *self, slim_opaque in_desc, slim_opaque *out_ctx);
typedef slim_int (*TCertStoreFindNextProc)(TCertStore *self, slim_opaque in_desc, slim_opaque in_ctx, TCertFindInfo *in_info, slim_opaque *out_id);
typedef void (*TCertStoreEndFindProc)(TCertStore *self, slim_opaque in_desc, slim_opaque in_ctx);
typedef slim_int (*TCertStoreOpenItemProc)(TCertStore *self, slim_opaque in_desc, slim_opaque in_id, TCertStoreItem *out_item);
typedef void (*TCertStoreCloseItemProc)(TCertStore *self, slim_opaque in_desc, slim_opaque in_id, TCertStoreItem *in_item);
typedef slim_int (*TCertStoreUpdateProc)(TCertStore *self, slim_opaque in_desc, slim_opaque in_id, TCertStoreItem *in_item, slim_int in_which);

/* interface */
struct TCertStore_ {
	TCertStoreOpenProc fOpenProc;
	TCertStoreCloseProc fCloseProc;
	TCertStoreImportProc fImportProc;
	TCertStoreDeleteProc fDeleteProc;
	TCertStoreBeginFindProc fBeginFindProc;
	TCertStoreFindNextProc fFindNextProc;
	TCertStoreEndFindProc fEndFindProc;
	TCertStoreOpenItemProc fOpenItemProc;
	TCertStoreCloseItemProc fCloseItemProc;
	TCertStoreUpdateProc fUpdateProc;
};

typedef struct TCertStoreDesc_ TCertStoreDesc;

struct TCertStoreDesc_ {
	TCertStoreDesc *fNext;
	slim_int fMode;	/* SLIM_CERTSTORE_OPENMODE_XXX */
};

/* ROM Store */
struct TRomCertStore_ {
	TCertStore fBase;
	slim_handle fItemList;
	slim_int fMaxItems;
	slim_int fCurrentItems;
	TCertStoreDesc *fHeadDesc;
};
typedef struct TRomCertStore_ TRomCertStore;

/* MEM Store */
struct TMemCertStore_ {
	TCertStore fBase;
	slim_handle fItemList;
	slim_int fMaxItems;
	slim_int fCurrentItems;
	TCertStoreDesc *fHeadDesc;
};
typedef struct TMemCertStore_ TMemCertStore;

typedef slim_int (*TCertStoreEnumerateItemProc)(slim_opaque in_id, TCertStoreItem *in_item, slim_opaque in_aux);


/*=========================
	Certificate Database
 =========================*/

struct TCertDB_ {
	TCertStore *fStore[SLIM_CERT_STORE_TYPES];
};

struct TCertDBDesc_ {
	slim_opaque fCertStoreDesc[SLIM_CERT_STORE_TYPES];
};
typedef struct TCertDBDesc_ TCertDBDesc;


/*=================================
	Certificate Database Manager
 =================================*/

struct TCertDBManager_ {
	slim_int fFlag;
	TCertDB *fDB;
	TCertDBDesc fDesc;
};

#define SLIM_CERTDBM_FLAG_OPENED	0x00000001

SLIM_END_C_LINKAGE

#endif /* SLIM_CERT_H */
