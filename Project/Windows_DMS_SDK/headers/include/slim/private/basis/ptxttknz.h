/*
	ptxttknz.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/basis/ptxttknz.h 22    05/12/28 12:08 Someya $ */

#ifndef SLIM_PLASTICTEXT_TOKENIZER_H_PRIVATE
#define SLIM_PLASTICTEXT_TOKENIZER_H_PRIVATE

SLIM_BEGIN_C_LINKAGE
/*
 * PTextTokenizer
 */

#define TPTextTokenizer_SetMaxStayTime(self, each, whole) (TParallelTokenizer_SetMaxStayTime(&(self)->fBase, (each), (whole)))


/*
 * PTextURLTokenizer
 */

/*
 * PTextTelTokenizer
 */

#define SLIM_PTEXTTELTKNZ_FLAG_ALLOWZENKAKUSCHEME 0x00000001
#define PTextTelTokenizer_SetFlag(cls, flg) ((cls)->fFlag |= (flg))
#define PTextTelTokenizer_IsZenkakuSchemeAllowed(cls) (((cls)->fFlag & SLIM_PTEXTTELTKNZ_FLAG_ALLOWZENKAKUSCHEME) != 0)

#define PTextTelTokenizer_NumAllowedSchemes(cls) ((cls)->fNumAllowedSchemes)
#define PTextTelTokenizer_AllowedSchemes(cls) ((cls)->fAllowedSchemes)

#define PTextTelTokenizer_MaxNumChars(cls, mode) ((cls)->fMinMaxNumChars[(mode)][0])
#define PTextTelTokenizer_MinNumChars(cls, mode) ((cls)->fMinMaxNumChars[(mode)][1])
#define PTextTelTokenizer_SetMaxNumChars(cls, mode, num) ((cls)->fMinMaxNumChars[(mode)][0] = (slim_byte)(num))
#define PTextTelTokenizer_SetMinNumChars(cls, mode, num) ((cls)->fMinMaxNumChars[(mode)][1] = (slim_byte)(num))


/*
 * PTextMailTokenizer
 */


SLIM_END_C_LINKAGE

#endif

