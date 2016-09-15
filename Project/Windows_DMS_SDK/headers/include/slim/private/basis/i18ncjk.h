/*
	i18ncjk.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/basis/i18ncjk.h 16    05/12/28 12:08 Someya $ */

#ifndef SLIM_I18NCJK_H_PRIVATE
#define SLIM_I18NCJK_H_PRIVATE

enum {
	SLIM_CHARSET_JAPANESE_KINSOKU_LETTER,
	SLIM_CHARSET_JAPANESE_KINSOKU_NOTBOL,
	SLIM_CHARSET_JAPANESE_KINSOKU_NOTEOL
};	/* return value of Charset_CheckJapaneseKinsoku() */

#ifndef SLIM_CONFIG_USE_JAPANESE
#define Charset_CheckJapaneseKinsoku(c0,c1) (SLIM_CHARSET_JAPANESE_KINSOKU_LETTER)
#define CharSet_ConvertJapanese_ZenkakuToHankaku(p,ss,cset) ((p) ? (slim_memcpy((p),(ss)->s,(ss)->len), (ss)->len) : (ss)->len)
#define TI18NChar_Japanese_ToLowerOrUpper(ioch, u)
#endif /* SLIM_CONFIG_USE_JAPANESE */

#define TI18NChar_Japanese_ToUpper(ch) TI18NChar_Japanese_ToLowerOrUpper((ch),slim_true)
#define TI18NChar_Japanese_ToLower(ch) TI18NChar_Japanese_ToLowerOrUpper((ch),slim_false)
#define TISO2022Ctx_JIS_Init(self) TISO2022Ctx_Init((self), SLIM_CHARSET_ISO_2022_JP)

#endif
