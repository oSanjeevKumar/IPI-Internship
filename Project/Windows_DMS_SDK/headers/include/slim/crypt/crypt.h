/*
	crypt.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/crypt/crypt.h 69    06/06/19 20:51 Siu $ */

#ifndef SLIM_CRYPT_H
#define SLIM_CRYPT_H

SLIM_BEGIN_C_LINKAGE

/*=======================================
	Pseudo-Random Byte Generator Class
 =======================================*/

/* #define SLIM_CONFIG_CRYPT_USE_X962 */		/* use slim_bignum_XXX_x.c */

#ifdef SLIM_CONFIG_CRYPT_USE_X962
/*------------------------------------------------
	X9.62 SHA-1 Type PRBG (slim_crypt_random.c)

	depend on USE_MD5, USE_SHA1
	use Bignum library
 ------------------------------------------------*/

struct TCryptRandom_ {
	slim_byte	fState[64];
	slim_word	fStateBytes;	/* 20 bytes <= StateBytes <= 64 bytes */
	slim_byte	fPrime[64];
	slim_word	fPrimeBytes;	/* max = 64 bytes */
	slim_byte	fRandom[80];
	slim_word	fRandomBytes;	/* max = 64 bytes */
};
typedef struct TCryptRandom_ TCryptRandom;

#else /* !defined(SLIM_CONFIG_CRYPT_USE_X962) */
/*-----------------------------------------
	SLIM PRBG (slim_crypt_random.c)

	depend on USE_MD5, USE_SHA1, USE_RC4
 -----------------------------------------*/

struct TCryptRandom_ {
	slim_word fBytesNeeded;		/* seed bytes required	*/
	slim_byte fState[16];       /* state of object		*/
	slim_word fOutputAvailable; /* number byte available*/
	slim_byte fOutput[16];      /* output bytes			*/
};
typedef struct TCryptRandom_ TCryptRandom;

#endif /* SLIM_CONFIG_CRYPT_USE_X962 */



/*===========================
	Symmetric Cipher Class
 ===========================*/

#define SLIM_CRYPT_MAX_BLK_SIZE				16
#define SLIM_CRYPT_STRM_CIPHER				0x80000000
#define SLIM_CRYPT_CIPHER_BASE_ALGO_MASK	0x0000ffff

/* stream cipher algorithms */
enum {
	SLIM_CRYPT_STRM_ALGO_NULL = 0,
	SLIM_CRYPT_STRM_ALGO_RC4,
	SLIM_CRYPT_STRM_ALGOS
};
#define SLIM_CRYPT_STRM_ALGO_MASK		SLIM_CRYPT_CIPHER_BASE_ALGO_MASK

#define SLIM_CRYPT_CIPHER_ALGO_NULL		(SLIM_CRYPT_STRM_CIPHER | SLIM_CRYPT_STRM_ALGO_NULL)
#define SLIM_CRYPT_CIPHER_ALGO_RC4		(SLIM_CRYPT_STRM_CIPHER | SLIM_CRYPT_STRM_ALGO_RC4)

/* block cipher algorithms */
enum {
	SLIM_CRYPT_BLK_ALGO_RC2 = 0,
	SLIM_CRYPT_BLK_ALGO_DES,
	SLIM_CRYPT_BLK_ALGO_2KEYDES3,
	SLIM_CRYPT_BLK_ALGO_DES3,
	SLIM_CRYPT_BLK_ALGO_AES,
	SLIM_CRYPT_BLK_ALGOS
};
#define SLIM_CRYPT_BLK_ALGO_MASK	SLIM_CRYPT_CIPHER_BASE_ALGO_MASK

/* block cipher modes */
enum {
	SLIM_CRYPT_BLK_MODE_ECB = 0,
	SLIM_CRYPT_BLK_MODE_CBC,

#if 0	/* not implemented, yet... */
	SLIM_CRYPT_BLK_MODE_CFB,
	SLIM_CRYPT_BLK_MODE_OFB,
#endif /* 0 */

	SLIM_CRYPT_BLK_MODES
};

#define SLIM_CRYPT_BLK_MODE_SFT		16
#define SLIM_CRYPT_BLK_MODE_MASK	0x7fff0000
#define SLIM_CRYPT_BLK_ECB(algo)	((SLIM_CRYPT_BLK_MODE_ECB << SLIM_CRYPT_BLK_MODE_SFT) | (algo))
#define SLIM_CRYPT_BLK_CBC(algo)	((SLIM_CRYPT_BLK_MODE_CBC << SLIM_CRYPT_BLK_MODE_SFT) | (algo))

#define SLIM_CRYPT_CIPHER_ALGO_RC2_ECB		SLIM_CRYPT_BLK_ECB(SLIM_CRYPT_BLK_ALGO_RC2)
#define SLIM_CRYPT_CIPHER_ALGO_RC2_CBC		SLIM_CRYPT_BLK_CBC(SLIM_CRYPT_BLK_ALGO_RC2)
#define SLIM_CRYPT_CIPHER_ALGO_DES_ECB		SLIM_CRYPT_BLK_ECB(SLIM_CRYPT_BLK_ALGO_DES)
#define SLIM_CRYPT_CIPHER_ALGO_DES_CBC		SLIM_CRYPT_BLK_CBC(SLIM_CRYPT_BLK_ALGO_DES)
#define SLIM_CRYPT_CIPHER_ALGO_2KEYDES3_ECB	SLIM_CRYPT_BLK_ECB(SLIM_CRYPT_BLK_ALGO_2KEYDES3)
#define SLIM_CRYPT_CIPHER_ALGO_2KEYDES3_CBC	SLIM_CRYPT_BLK_CBC(SLIM_CRYPT_BLK_ALGO_2KEYDES3)
#define SLIM_CRYPT_CIPHER_ALGO_DES3_ECB		SLIM_CRYPT_BLK_ECB(SLIM_CRYPT_BLK_ALGO_DES3)
#define SLIM_CRYPT_CIPHER_ALGO_DES3_CBC		SLIM_CRYPT_BLK_CBC(SLIM_CRYPT_BLK_ALGO_DES3)
#define SLIM_CRYPT_CIPHER_ALGO_AES_ECB		SLIM_CRYPT_BLK_ECB(SLIM_CRYPT_BLK_ALGO_AES)
#define SLIM_CRYPT_CIPHER_ALGO_AES_CBC		SLIM_CRYPT_BLK_CBC(SLIM_CRYPT_BLK_ALGO_AES)


/*---------------
	CipherInfo
 ---------------*/

struct TSymCipherInfo_ {
	slim_int	fAlgo;
	slim_bool	fEncrypt;
	slim_byte	*fKey;
	slim_int	fKeyLen;
	slim_byte	*fIV;		/* used by Block Ciphers */
	slim_int	fBlkSize;
};
typedef struct TSymCipherInfo_ TSymCipherInfo;


/*------------------------
	Stream Cipher Class
 ------------------------*/

/*---------------------------
	RC4 (slim_crypt_rc4.c)
 ---------------------------*/
struct TRC4_ {
	slim_byte fSbox[256];
	slim_int fI, fJ;	/* internal counter */
};
typedef struct TRC4_ TRC4;


/*---------------------------------
	Abstract Stream Cipher Class
 ---------------------------------*/

/* context */
union TStrmCipherCtx_ {
	slim_int uNull;
#ifdef SLIM_CONFIG_CRYPT_USE_RC4
	TRC4 uRC4;
#endif
};
typedef union TStrmCipherCtx_ TStrmCipherCtx;

/* context method */
typedef void (*TStrmCipherCtxInitializeProc)(TStrmCipherCtx *self, slim_byte *in_source, slim_int in_len);
typedef void (*TStrmCipherCtxUpdateProc)(TStrmCipherCtx *self, slim_byte *in_buf, slim_int in_len, slim_byte *out_buf);
typedef void (*TStrmCipherCtxFinalizeProc)(TStrmCipherCtx *self);

/* object */
struct TStrmCipher_ {
	/* class */
	slim_int						fAlgo;
	TStrmCipherCtxInitializeProc	fCtxInitializeProc;
	TStrmCipherCtxUpdateProc		fCtxUpdateProc;
	TStrmCipherCtxFinalizeProc		fCtxFinalizeProc;
	/* context */
	TStrmCipherCtx					fCtx;
};
typedef struct TStrmCipher_ TStrmCipher;


/*-----------------------
	Block Cipher Class
 -----------------------*/

/*---------------------------
	RC2 (slim_crypt_rc2.c)
 ---------------------------*/

struct TRC2_ {
	slim_half	fKey[64];
};
typedef struct TRC2_ TRC2;


/*---------------------------
	DES (slim_crypt_des.c)
 ---------------------------*/

struct TDES_ {
	slim_word fSubKey[32];
};
typedef struct TDES_ TDES;


/*----------------------------------------
	2 Key Triple DES (slim_crypt_des.c)
 ----------------------------------------*/

struct T2KeyDES3_ {
	slim_word fSubKey[2][32];
};
typedef struct T2KeyDES3_ T2KeyDES3;


/*----------------------------------------
	3 Key Triple DES (slim_crypt_des.c)
 ----------------------------------------*/

struct TDES3_ {
	slim_word fSubKey[3][32];
};
typedef struct TDES3_ TDES3;


/*--------------------------------------------
	AES (slim_crypt_aes.c)
 --------------------------------------------*/

struct TAES_ {
	slim_int fNr;
	slim_word fEncKey[60];
	slim_word fDecKey[60];
};
typedef struct TAES_ TAES;


/*----------------------------
	Block Cipher Base Class
 ----------------------------*/

/* base context */
union TBlkCipherBaseCtx_ {
	slim_int uDummy;
#ifdef SLIM_CONFIG_CRYPT_USE_RC2
	TRC2 uRC2;
#endif
#ifdef SLIM_CONFIG_CRYPT_USE_DES
	TDES uDES;
#endif
#ifdef SLIM_CONFIG_CRYPT_USE_2KEYDES3
	T2KeyDES3 u2KeyDES3;
#endif
#ifdef SLIM_CONFIG_CRYPT_USE_DES3
	TDES3 uDES3;
#endif
#ifdef SLIM_CONFIG_CRYPT_USE_AES
	TAES uAES;
#endif
};
typedef union TBlkCipherBaseCtx_ TBlkCipherBaseCtx;

/* base context method */
typedef void (*TBlkCipherBaseCtxSetKeyProc)(TBlkCipherBaseCtx *self, slim_byte *in_key, slim_int in_len);
typedef void (*TBlkCipherBaseCtxEncryptProc)(TBlkCipherBaseCtx *self, slim_byte *in_blk, slim_byte *out_blk);
typedef void (*TBlkCipherBaseCtxDecryptProc)(TBlkCipherBaseCtx *self, slim_byte *in_blk, slim_byte *out_blk);

/* base object */
struct TBlkCipherBase_ {
	/* base class */
	slim_int						fAlgo;
	TBlkCipherBaseCtxSetKeyProc		fSetKeyProc;
	TBlkCipherBaseCtxEncryptProc	fEncryptProc;
	TBlkCipherBaseCtxDecryptProc	fDecryptProc;
	/* context */
	TBlkCipherBaseCtx				fCtx;
	slim_int						fBlkSize;
};
typedef struct TBlkCipherBase_ TBlkCipherBase;


/*-----------------------------
	Elecrtonic Codebook Mode
 -----------------------------*/

/* ecb object */
struct TBlkCipherECB_ {
	TBlkCipherBase	fBase;
};
typedef struct TBlkCipherECB_ TBlkCipherECB;


/*-------------------------------
	Cipher Block Chaining Mode
 -------------------------------*/

/* cbc object */
struct TBlkCipherCBC_ {
	TBlkCipherBase	fBase;
	slim_byte		fIV[SLIM_CRYPT_MAX_BLK_SIZE];
	slim_byte		fPrevCipherBlk[SLIM_CRYPT_MAX_BLK_SIZE];
};
typedef struct TBlkCipherCBC_ TBlkCipherCBC;


/*--------------------------------
	Abstract Block Cipher Class
 --------------------------------*/

/* context */
union TBlkCipherCtx_ {
	slim_int uDummy;
#ifdef SLIM_CONFIG_CRYPT_USE_ECB_MODE
	TBlkCipherECB uECB;
#endif
#ifdef SLIM_CONFIG_CRYPT_USE_CBC_MODE
	TBlkCipherCBC uCBC;
#endif
};
typedef union TBlkCipherCtx_ TBlkCipherCtx;

/* context method */
typedef slim_bool (*TBlkCipherCtxInitializeProc)(TBlkCipherCtx *self, TSymCipherInfo *in_info);
typedef void (*TBlkCipherCtxUpdateProc)(TBlkCipherCtx *self, slim_byte *in_plain, slim_int in_len, slim_byte *out_cipher);
typedef void (*TBlkCipherCtxFinalizeProc)(TBlkCipherCtx *self);

/* object */
struct TBlkCipher_ {
	/* class */
	slim_int					fMode;
	TBlkCipherCtxInitializeProc	fCtxInitializeProc;
	TBlkCipherCtxUpdateProc		fCtxEncryptProc;
	TBlkCipherCtxUpdateProc		fCtxDecryptProc;
	TBlkCipherCtxFinalizeProc	fCtxFinalizeProc;
	/* context */
	TBlkCipherCtx				fCtx;
	slim_bool					fEncrypt;
	slim_int					fRemain;
	slim_byte					fRemainBuf[SLIM_CRYPT_MAX_BLK_SIZE];
};
typedef struct TBlkCipher_ TBlkCipher;


/*------------------------------------
	Abstract Symmetric Cipher Class
 ------------------------------------*/

/* context */
union TSymCipherCtx_ {
	slim_int uDummy;
#ifdef SLIM_CONFIG_CRYPT_USE_STRM
	TStrmCipher uStrmCipher;
#endif
#ifdef SLIM_CONFIG_CRYPT_USE_BLK
	TBlkCipher uBlkCipher;
#endif
#ifdef SLIM_CONFIG_CRYPT_USE_CUSTOM
	SLIM_CRYPT_SYM_CIPHER_CTX_CUSTOM uCustom;
#endif
};
typedef union TSymCipherCtx_ TSymCipherCtx;

/* context method */
typedef slim_bool (*TSymCipherCtxInitializeProc)(TSymCipherCtx *self, TSymCipherInfo *in_info);
typedef slim_int (*TSymCipherCtxUpdateProc)(TSymCipherCtx *self, slim_byte *in_buf, slim_int in_len, slim_byte *out_buf);
typedef void (*TSymCipherCtxFinalizeProc)(TSymCipherCtx *self);

struct TSymCipherCtxProcTable_ {
	TSymCipherCtxInitializeProc	fCtxInitializeProc;
	TSymCipherCtxUpdateProc		fCtxUpdateProc;
	TSymCipherCtxFinalizeProc	fCtxFinalizeProc;
};
typedef struct TSymCipherCtxProcTable_ TSymCipherCtxProcTable;

/* object */
struct TSymCipher_ {
	/* class */
	TSymCipherCtxInitializeProc	fCtxInitializeProc;
	TSymCipherCtxUpdateProc		fCtxUpdateProc;
	TSymCipherCtxFinalizeProc	fCtxFinalizeProc;
	/* context */
	TSymCipherCtx				fCtx;
	slim_bool					fIsStream;
};
typedef struct TSymCipher_ TSymCipher;



/*=========================
	Message Digest Class
 =========================*/

/* algorithms */
enum {
	SLIM_CRYPT_MD_ALGO_NULL = 0,
	SLIM_CRYPT_MD_ALGO_MD2,
	SLIM_CRYPT_MD_ALGO_MD5,
	SLIM_CRYPT_MD_ALGO_SHA1,
	SLIM_CRYPT_MD_ALGO_SHA256,
	SLIM_CRYPT_MD_ALGOS
};
#define SLIM_CRYPT_MD_ALGO_MASK	0x0000ffff


/*---------------------------
	MD2 (slim_crypt_md2.c)
 ---------------------------*/

/* MD2 block size and digest size (in bytes) */
#define SLIM_CRYPT_MD2_BLOCKSIZE	16
#define SLIM_CRYPT_MD2_DIGESTSIZE	16

/* MD2 context */
struct TMD2_ {
	slim_word	fXW[16];	/* + 0 : state (16bytes)			*/
							/* + 4 : block (16bytes)			*/
							/* + 8 : work=state^block (16bytes)	*/
							/* +12 : checksum (16bytes)			*/
	slim_word	fCount;		/* number of bytes, module 16		*/
};
typedef struct TMD2_ TMD2;


/*---------------------------
	MD5 (slim_crypt_md5.c)
 ---------------------------*/

/* MD5 block size and digest size (in bytes) */
#define SLIM_CRYPT_MD5_BLOCKSIZE	64
#define SLIM_CRYPT_MD5_DIGESTSIZE	16

/* MD5 context */
struct TMD5_ {
	slim_word	fDigest[4];			/* Message digest		*/
	slim_word	fCountLo, fCountHi;	/* 64-bit byte count	*/
	slim_word	fData[16];			/* MD5 data buffer		*/
};
typedef struct TMD5_ TMD5;

	
/*------------------------------
	SHA-1 (slim_crypt_shs1.c)
 ------------------------------*/

/* SHA1 block size and digest size (in bytes) */
#define SLIM_CRYPT_SHS_BLOCKSIZE	64
#define SLIM_CRYPT_SHS_DIGESTSIZE	20

/* SHA1 context */
struct TSHS_ {
	slim_word	fDigest[5];			/* Message digest		*/
	slim_word	fCountLo, fCountHi;	/* 64-bit byte count	*/
	slim_word	fData[16];			/* SHA1 data buffer		*/
};
typedef struct TSHS_ TSHS;


/*----------------------------------
	SHA-256 (slim_crypt_sha256.c)
 ----------------------------------*/

/* SHA256 block size and digest size (in bytes) */
#define SLIM_CRYPT_SHA256_BLOCKSIZE		64
#define SLIM_CRYPT_SHA256_DIGESTSIZE	32

/* SHA256 context */
struct TSHA256_ {
	slim_word	fDigest[8];			/* Message digest		*/
	slim_word	fCountLo, fCountHi;	/* 64-bit byte count	*/
	slim_word	fData[16];			/* SHA256 data buffer	*/
};
typedef struct TSHA256_ TSHA256;


/*--------------------------------------------------
	Abstract Message Digest (slim_crypt_digest.c)
 --------------------------------------------------*/

/* context */
union TMDCtx_ {
	slim_int uNull;
#ifdef SLIM_CONFIG_CRYPT_USE_MD2
	TMD2 uMD2;
#endif
#ifdef SLIM_CONFIG_CRYPT_USE_MD5
	TMD5 uMD5;
#endif
#ifdef SLIM_CONFIG_CRYPT_USE_SHA1
	TSHS uSHA1;
#endif
#ifdef SLIM_CONFIG_CRYPT_USE_SHA256
	TSHA256 uSHA256;
#endif
};
typedef union TMDCtx_ TMDCtx;

/* context method */
typedef void (*TMDBeginCtxProc)(TMDCtx *self);
typedef void (*TMDUpdateCtxProc)(TMDCtx *self, slim_byte *in_buf, slim_word in_len);
typedef void (*TMDEndCtxProc)(TMDCtx *self, slim_byte *out_digest);

/* object */
struct TMD_ {
	/* class */
	slim_int			fDigestAlgo;
	slim_int			fDigestSize;
	TMDBeginCtxProc		fBeginCtxProc;
	TMDUpdateCtxProc	fUpdateCtxProc;
	TMDEndCtxProc		fEndCtxProc;
	/* context */
	TMDCtx				fCtx;
};
typedef struct TMD_ TMD;


/*-------------------------------
	HMAC (slim_crypt_digest.c)
 -------------------------------*/

/* don't change these constants */
#define SLIM_CRYPT_HMAC_KEYLEN		64
#define SLIM_CRYPT_HMAC_KEYTMPSIZE	32
#define SLIM_CRYPT_HMAC_IPAD		0x36
#define SLIM_CRYPT_HMAC_OPAD		0x5c

struct TCryptHMAC_ {
	TMD		fBase;
	TMDCtx	fInnerCtx;
	TMDCtx	fOuterCtx;
};
typedef struct TCryptHMAC_ TCryptHMAC;



/*============================
	Asymmetric Cipher Class
 ============================*/

/* signature algorithms */
#define SLIM_CRYPT_SIGN_ALGO_BASE_NULL		0x00000000
#define SLIM_CRYPT_SIGN_ALGO_BASE_RSA		0x00010000
#define SLIM_CRYPT_SIGN_ALGO_BASE_RSA_SIGN	0x00020000
#define SLIM_CRYPT_SIGN_ALGO_BASE_MASK		0xffff0000

#define SLIM_CRYPT_SIGN_ALGO_UNKNOWN		(SLIM_CRYPT_MD_ALGO_NULL | SLIM_CRYPT_SIGN_ALGO_BASE_NULL)
#define SLIM_CRYPT_SIGN_ALGO_RSA			(SLIM_CRYPT_MD_ALGO_NULL | SLIM_CRYPT_SIGN_ALGO_BASE_RSA)
#define SLIM_CRYPT_SIGN_ALGO_MD2_RSA		(SLIM_CRYPT_MD_ALGO_MD2  | SLIM_CRYPT_SIGN_ALGO_BASE_RSA)
#define SLIM_CRYPT_SIGN_ALGO_MD5_RSA		(SLIM_CRYPT_MD_ALGO_MD5  | SLIM_CRYPT_SIGN_ALGO_BASE_RSA)
#define SLIM_CRYPT_SIGN_ALGO_SHA1_RSA		(SLIM_CRYPT_MD_ALGO_SHA1 | SLIM_CRYPT_SIGN_ALGO_BASE_RSA)
#define SLIM_CRYPT_SIGN_ALGO_SHA1_RSA_SIGN	(SLIM_CRYPT_MD_ALGO_SHA1 | SLIM_CRYPT_SIGN_ALGO_BASE_RSA_SIGN)


/*---------------------------
	RSA (slim_crypt_rsa.c)
 ---------------------------*/

/* RSA options */
/* #define SLIM_CONFIG_CRYPT_USE_RSA_BLINDING */
/* #define SLIM_CONFIG_CRYPT_USE_KEYGEN */			/* use slim_bignum_XXX_x.c */

/* error code */
#define SLIM_CRYPT_RSA_E_LEN			-100
#define SLIM_CRYPT_RSA_E_DATA			-200
#define SLIM_CRYPT_RSA_E_TRANS			-300
#define SLIM_CRYPT_RSA_E_ALGO			-400
#define SLIM_CRYPT_RSA_E_SIGN			-500

struct TRSAInt_ {
	slim_int	fLen;
	slim_byte	*fPtr;
};
typedef struct TRSAInt_ TRSAInt;

struct TRSAKey_ {
	slim_int	fFlag;
	slim_byte	*fPtr;
	slim_int	fLen;
};
typedef struct TRSAKey_ TRSAKey;

/* flag */
#define SLIM_CRYPT_RSAKEY_FLAG_NONE		0x00000000
#define SLIM_CRYPT_RSAKEY_FLAG_PRIVATE	0x00000001
#define SLIM_CRYPT_RSAKEY_FLAG_DER		0x00000002
#define SLIM_CRYPT_RSAKEY_FLAG_ALLOC	0x00000004

struct TRSAPublicKey_ {
	TRSAKey	fBase;
	TRSAInt	fModulus;	/* variable  length */
	TRSAInt	fExponent;	/* verisable length */
};
typedef struct TRSAPublicKey_ TRSAPublicKey;

struct TRSAPrivateKey_ {
	/* Don't change order */
	TRSAKey	fBase;
	TRSAInt	fModulus;
	TRSAInt	fPublicExponent;
	TRSAInt	fExponent;
	TRSAInt	fPrime[2];
	TRSAInt	fPrimeExponent[2];
	TRSAInt	fCoefficient;
};
typedef struct TRSAPrivateKey_ TRSAPrivateKey;

/*---------------------------------------------------
	Elliptic Curve Cryptography (slim_crypt_ecc.c)
 ---------------------------------------------------*/

/* error code extension */
enum {
	SLIM_CRYPT_ECC_E_SIGN      = SLIM_E_enum_tail,
	SLIM_CRYPT_ECC_E_RANDOM    = SLIM_E_enum_tail - 1,
	SLIM_CRYPT_ECC_E_MD        = SLIM_E_enum_tail - 2,
	SLIM_CRYPT_ECC_E_enum_tail = SLIM_E_enum_tail - 3
};

/**
 * TECInt represents a positive integer as byte-array.
 */
struct TECInt_ {
	slim_byte *fBuf;
	slim_int fLen;
	slim_bool fRef;
};
typedef struct TECInt_ TECInt;

/**
 * TECPoint represents an point (x, y) on an elliptic curve.
 */
struct TECPoint_ {
	TECInt fX;
	TECInt fY;
};
typedef struct TECPoint_ TECPoint;

/**
 * TEC represents an ellptic curve.
 */
struct TEC_ {
	TBignum *fModulus;
	TBignum *fCoefficientA;
	TBignum *fCoefficientB;
	TBignum *fGeneratorX;
	TBignum *fGeneratorY;
	TBignum *fOrder;
	slim_int fBaseBit;
/* Store the base result of multi point addition, (such as ,G 2*G 3*G ..... 255*G). */
	TBignum **bnX;
	TBignum **bnY;
};
typedef struct TEC_ TEC;

struct TECDH_ {
	TEC *fEC;
};
typedef struct TECDH_ TECDH;

struct TECDSA_ {
	TEC *fEC;
	slim_int fHashAlgo;
	slim_byte *fMessageDigest;
};
typedef struct TECDSA_ TECDSA;

SLIM_END_C_LINKAGE

#endif /* SLIM_CRYPT_H */
