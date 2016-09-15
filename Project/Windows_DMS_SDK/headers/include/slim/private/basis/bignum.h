/*
	bignum.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/basis/bignum.h 58    05/12/28 12:08 Someya $ */

#ifndef SLIM_BIGNUM_H_PRIVATE
#define SLIM_BIGNUM_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

/*==================
	slim_bignum.c
 ==================*/


#ifdef SLIM_CONFIG_BIGNUM_USE_MODTABLE
#endif /* SLIM_CONFIG_BIGNUM_USE_MODTABLE */

#define TBignum_Sign(self)					((self)->fSign)
#define TBignum_SignInv(self)				(TBignum_Sign(self) == SLIM_BIGNUM_SIGN_POSITIVE ? SLIM_BIGNUM_SIGN_NEGATIVE : SLIM_BIGNUM_SIGN_POSITIVE)
#define TBignum_IsSignEqual(sign1, sign2)	(TBignum_Sign(sign1) == TBignum_Sign(sign2))
#define TBignum_Ptr(self) 					((self)->fPtr)
#define TBignum_Len(self) 					((self)->fLen)
#define TBignum_MaxLen(self)				((self)->fMaxLen)
#define TBignum_WordPtr(self, offset)		(TBignum_Ptr(self) + (offset))
#define TBignum_GetWord(self, offset)		((self)->fPtr[offset])
#define TBignum_SetWord(self, offset, val)	((self)->fPtr[offset] = val)
#define TBignum_GetLSWord(self) 			TBignum_GetWord(self, 0)
#define TBignum_GetMSWord(self)				TBignum_GetWord(self, TBignum_Len(self)-1)
#define TBignum_SetQ(self, val)				{TBignum_SetWord(self, 0, val);	(self)->fLen = 1; TBignum_Sign(self) = slim_true;}
#define TBignum_IsZero(self)				((TBignum_Len(self) == 1 && TBignum_GetLSWord(self) == 0) ? slim_true : slim_false)
#define TBignum_IsOne(self)					((TBignum_Len(self) == 1 && TBignum_GetLSWord(self) == 1) && TBignum_Sign(self) != slim_false ? slim_true : slim_false)
#define TBignum_IsTwo(self)					((TBignum_Len(self) == 1 && TBignum_GetLSWord(self) == 2) && TBignum_Sign(self) != slim_false ? slim_true : slim_false)
#define TBignum_FillZero(self) 				{TBignumPtr_FillZero(self); TBignum_Len(self) = 1; TBignum_Sign(self) = slim_true;}
#define TBignumPtr_FillZero(self)			slim_memset((TBignum_Ptr(self)), 0, sizeof(slim_word)*(TBignum_MaxLen(self)))
#define TBignum_GetLongerLen(in_b1, in_b2)	SLIM_MAX(TBignum_Len(in_b1), TBignum_Len(in_b2))

#define TBignum_IsOdd(self)			(TBignum_GetLSWord(self) & 1 ? slim_true : slim_false)
#define TBignum_IsPositive(self)	(TBignum_Sign(self) == SLIM_BIGNUM_SIGN_POSITIVE)

#define TBignum_Swap(p, q) \
{ \
	TBignum *_t_; \
	_t_ = (p); \
	(p) = (q); \
	(q) = _t_; \
}

#define TBignum_Bytes(self)		((TBignum_Bits(self) + 7) / 8)


#ifdef SLIM_CONFIG_BIGNUM_DEBUG
#endif /* SLIM_CONFIG_BIGNUM_DEBUG */


/*====================
	slim_bignum_x.c
 ====================*/

 

/*=========================
	slim_bignum_addsub.c
 =========================*/

#define TBignum_Add(self, bn)	TBignum_Add3(self, self, bn)
#define TBignum_Sub(self, bn)	TBignum_Sub3(self, self, bn)


/*===========================
	slim_bignum_mulshift.c
 ===========================*/

/* Karatsuba-Ofman version */


#define TBignum_LShift(self, ofs)		TBignum_LShift2(self, self, ofs)
#define TBignum_RShift(self, ofs)		TBignum_RShift2(self, self, ofs)
#define TBignum_LShiftWord(self, ofs)	TBignum_LShiftWord2(self, self, ofs)
#define TBignum_RShiftWord(self, ofs)	TBignum_RShiftWord2(self, self, ofs)


/*=========================
	slim_bignum_divmod.c
 =========================*/

#ifdef SLIM_CONFIG_BIGNUM_USE_MODTABLE
#endif



/*===========================
	slim_bignum_divmod_x.c
 ===========================*/



/*=========================
	slim_bignum_expmod.c
 =========================*/

#ifdef SLIM_CONFIG_BIGNUM_USE_DSP
/* Ugh! this should have "Peer" suffix */
slim_int TBignum_DSPExpMod(TBignum *out_r, TBignum *in_bn, TBignum *in_p, TBignum *in_mod);
#endif /* SLIM_CONFIG_BIGNUM_USE_DSP */


/*===========================
	slim_bignum_expmod_x.c
 ===========================*/


/*======================================================
	slim_bignum_64.c

	be careful to specify same variable (side effect)
	result should not be add1 nor sub1
 ======================================================*/
#ifndef SLIM_CONFIG_BIGNUM_USE_WORD64

#define SLIM_BIGNUM64_ADD_2W_CARRY_OUT(result, add1, add2)	(((result) = (add1) + (add2)) < (add1))
#define SLIM_BIGNUM64_INC_W_CARRY_OUT(result)				(++(result) == 0)

#define SLIM_BIGNUM64_SUB_2W_BORROW_OUT(result, sub1, sub2)	(((result) = (sub1) - (sub2)) > (sub1))
#define SLIM_BIGNUM64_DEC_W_BORROW_OUT(result)				((result)-- == 0)

#define SLIM_BIGNUM64_IS_LATTER_LARGER(h1, l1, h2, l2) (((h1)<(h2)) ? 1 : ((((h1)==(h2)) && ((l1)<(l2))) ? 1 : 0))


/*=======================
	slim_bignum_64_x.c
 =======================*/

#endif /* SLIM_CONFIG_BIGNUM_USE_WORD64 */


/*===================================================================
	Not implemented yet

	we don't implement these skip functions

	void TBignum_ExtractBigBytes(TBignum *bn, slim_byte *dest, slim_word lsbyte, slim_word len);
	slim_int TBignum_InsertBigBytes(TBignum *bn, slim_byte *src, slim_word lsbyte, slim_word len);
	void TBignum_ExtractLittleBytes(TBignum *bn, slim_byte *dest, slim_word lsbyte, slim_word len);
	slim_int TBignum_InsertLittleBytes(TBignum *bn, slim_byte *src, slim_word lsbyte, slim_word len);
	slim_word TBignum_MakeOdd(TBignum *n);
	slim_int TBignum_TwoExpMod(TBignum *result, TBignum *exp, TBignum *mod);
	slim_int TBignum_DoubleExpMod(TBignum *result, TBignum *n1, TBignum *e1, TBignum *n2, TBignum *e2, TBignum *mod);
	slim_int TBignum_Prealloc(TBignum *bn, slim_word bits);
	void TBignum_Norm(TBignum *bn);

	jacobi and prime functions are not, and won't be implemented.
 ===================================================================*/


SLIM_END_C_LINKAGE
#endif /* SLIM_BIGNUM_H_PRIVATE */
