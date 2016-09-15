/*
	crypt.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/crypt/crypt.h 68    05/12/28 12:08 Someya $ */

#ifndef SLIM_CRYPT_H_PRIVATE
#define SLIM_CRYPT_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

/*===========================
	Symmetric Cipher Class
 ===========================*/

/*---------------
	CipherInfo
 ---------------*/

#define TSymCipherInfo_IsStream(info)		((info)->fAlgo & SLIM_CRYPT_STRM_CIPHER)
#define TSymCipherInfo_BaseAlgo(info)		((info)->fAlgo & SLIM_CRYPT_CIPHER_BASE_ALGO_MASK)
#define TSymCipherInfo_BlkMode(info)		(((info)->fAlgo & SLIM_CRYPT_BLK_MODE_MASK) >> SLIM_CRYPT_BLK_MODE_SFT)


/*------------------------
	Stream Cipher Class
 ------------------------*/

/*---------------------------------
	Abstract Stream Cipher Class
 ---------------------------------*/

#define TStrmCipher_BaseAlgo(self)		((self)->fAlgo)
#define TStrmCipher_Algo(self)			(SLIM_CRYPT_STRM_CIPHER | TStrmCipher_BaseAlgo(self))



/*-----------------------
	Block Cipher Class
 -----------------------*/

/*----------------------------
	Block Cipher Base Class
 ----------------------------*/

#define TBlkCipherBase_Algo(base)		((base)->fAlgo)
#define TBlkCipherBase_BlkSize(base)	((base)->fBlkSize)


/*-----------------------------
	Elecrtonic Codebook Mode
 -----------------------------*/

#define TBlkCipherECB_BaseAlgo(self)	(TBlkCipherBase_Algo((TBlkCipherBase *)(self)))
#define TBlkCipherECB_Algo(self)		(SLIM_CRYPT_BLK_ECB(TBlkCipherECB_BaseAlgo(self)))


/*-------------------------------
	Cipher Block Chaining Mode
 -------------------------------*/

#define TBlkCipherCBC_BaseAlgo(self)	(TBlkCipherBase_Algo((TBlkCipherBase *)(self)))
#define TBlkCipherCBC_Algo(self)		(SLIM_CRYPT_BLK_CBC(TBlkCipherCBC_BaseAlgo(self)))


/*--------------------------------
	Abstract Block Cipher Class
 --------------------------------*/

#define TBlkCipher_Mode(self)		((self)->fClass->fMode)
#define TBlkCipher_BaseAlgo(self)	(TBlkCipherBase_Algo((TBlkCipherBase *)(&((self)->fCtx))))
#define TBlkCipher_Algo(self)		((TBlkCipher_Mode(self) << SLIM_CRYPT_BLK_MODE_SFT) | TBlkCipher_BaseAlgo(self))
#define TBlkCipher_Remain(self)		((self)->fRemain)
#define TBlkCipher_BlkSize(self)	(TBlkCipherBase_BlkSize((TBlkCipherBase *)(&((self)->fCtx))))


/*------------------------------------
	Abstract Symmetric Cipher Class
 ------------------------------------*/

#define TSymCipher_IsStream(self)		((self)->fIsStream)

#ifdef SLIM_CONFIG_CRYPT_USE_CUSTOM
/* Ugh!: this should have "Peer" suffix */
TSymCipherCtxProcTable *SymCipher_CustomCtxProcTable(TSymCipherInfo *in_info);
#endif /* SLIM_CONFIG_CRYPT_USE_CUSTOM */



/*=========================
	Message Digest Class
 =========================*/

/*--------------------------------------------------
	Abstract Message Digest (slim_crypt_digest.c)
 --------------------------------------------------*/

/* digest method */
#define TMD_Algo(self)				((self)->fDigestAlgo)
#define TMD_Size(self)				((self)->fDigestSize)
#define TMD_ChangeAlgo(self, algo)	(TMD_Initialize(self, algo))


/*-------------------------------
	HMAC (slim_crypt_digest.c)
 -------------------------------*/

#define TCryptHMAC_Algo(self)		((self)->fBase.fDigestAlgo)
#define TCryptHMAC_Size(self)		((self)->fBase.fDigestSize)



/*============================
	Asymmetric Cipher Class
 ============================*/

/*---------------------------
	RSA (slim_crypt_rsa.c)
 ---------------------------*/

/* public key */
#define TRSAPublicKey_Initialize(self)	TRSAKey_Initialize(&(self)->fBase, SLIM_CRYPT_RSAKEY_FLAG_NONE)
#define TRSAPublicKey_Finalize(self)	TRSAKey_Finalize(&(self)->fBase)
#define TRSAPublicKey_FreeBuf(self)		TRSAKey_FreeBuf(&(self)->fBase)

/* private key */
#define TRSAPrivateKey_Initialize(self)	TRSAKey_Initialize(&(self)->fBase, SLIM_CRYPT_RSAKEY_FLAG_PRIVATE)
#define TRSAPrivateKey_Finalize(self)	TRSAKey_Finalize(&(self)->fBase)
#define TRSAPrivateKey_FreeBuf(self)	TRSAKey_FreeBuf(&(self)->fBase)

/*---------------------------------------------------
	Elliptic Curve Cryptosystem (slim_crypt_ecc.c)
 ---------------------------------------------------*/

SLIM_END_C_LINKAGE

#endif /* SLIM_CRYPT_H */
