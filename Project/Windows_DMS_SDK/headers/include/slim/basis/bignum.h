/*
	bignum.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/basis/bignum.h 54    05/12/28 12:07 Someya $ */

#ifndef SLIM_BIGNUM_H
#define SLIM_BIGNUM_H

SLIM_BEGIN_C_LINKAGE

/*==================
	Configuration
 ==================*/
#ifdef SLIM_CONFIG_DEBUG
#define SLIM_CONFIG_BIGNUM_DEBUG
#endif /* SLIM_CONFIG_DEBUG */

#define SLIM_CONFIG_BIGNUM_USE_MODTABLE

/* #define SLIM_CONFIG_BIGNUM_USE_WORD64 */

/* #define SLIM_CONFIG_BIGNUM_USE_DSP */


/*=============
	Constant
 =============*/
#define SLIM_BIGNUM_BITS_PER_BYTE	8
#define SLIM_BIGNUM_BYTES_PER_WORD	sizeof(slim_word)
#define SLIM_BIGNUM_BITS_PER_WORD	(SLIM_BIGNUM_BITS_PER_BYTE * SLIM_BIGNUM_BYTES_PER_WORD)

#define SLIM_BIGNUM_MAX_WORDLEN		(64*2)		/* you should specify *2 len for processing div mod */

#define SLIM_BIGNUM_IS_PRIME		1
#define SLIM_BIGNUM_IS_NOT_PRIME	0

#define SLIM_BIGNUM_SIGN_POSITIVE	1
#define SLIM_BIGNUM_SIGN_NEGATIVE	-1

/*===============
    Error Code
 ===============*/
#define SLIM_BIGNUM_E_OK			 0
#define SLIM_BIGNUM_E_GENERIC		-1
#define SLIM_BIGNUM_E_NOMEM			-2
#define SLIM_BIGNUM_E_DIV_BY_ZERO	-3
#define SLIM_BIGNUM_E_DSP_BUSY		-4	/* #ifdef SLIM_CONFIG_BIGNUM_USE_DSP */


/*==============
	Data Type
 ==============*/

/*----------------
	64-bit Word
 ----------------*/
#ifdef SLIM_CONFIG_BIGNUM_USE_WORD64
typedef unsigned long long slim_word64;		  
#endif /* SLIM_CONFIG_BIGNUM_USE_WORD64 */

/*-----------
	Bignum
 -----------*/
typedef struct TBignum_ TBignum;
struct TBignum_ {
	slim_int	fSign;	/* +:SLIM_BIGNUM_SIGN_POSITIVE, -:SLIM_BIGNUM_SIGN_NEGATIVE */
	slim_word	fMaxLen;
	slim_word	fLen;
	slim_word	*fPtr;	/* variable */
	
#ifdef SLIM_CONFIG_BIGNUM_USE_MODTABLE
	TBignum		*fTable;
#endif /* SLIM_CONFIG_BIGNUM_USE_MODTABLE */
};

SLIM_END_C_LINKAGE
#endif
