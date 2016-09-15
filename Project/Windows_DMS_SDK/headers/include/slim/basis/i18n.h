/*
	i18n.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/basis/i18n.h 133   06/07/31 9:20 Someya $ */

#ifndef SLIM_I18N_H
#define SLIM_I18N_H

#ifndef SLIM_TOKEN_CHSETID_H
#include <slim/token/chsetid.h>
#endif
#ifndef SLIM_TOKEN_LNGSETID_H
#include <slim/token/lngsetid.h>
#endif

SLIM_BEGIN_C_LINKAGE

/* declare */
typedef struct TI18NChar_ TI18NChar;

/*
 * CharSet
 */

#define SLIM_CHARSET_UNCERTAIN				(-2)
#define SLIM_CHARSET_UNKNOWN				(-1)
#define SLIM_CHARSET_US_ASCII				SLIM_TKID_CHSET_US_ASCII
#define SLIM_CHARSET_SHIFT_JIS				SLIM_TKID_CHSET_Shift_JIS
#define SLIM_CHARSET_EUC_JP					SLIM_TKID_CHSET_EUC_JP
#define SLIM_CHARSET_ISO_2022_JP			SLIM_TKID_CHSET_ISO_2022_JP
#define SLIM_CHARSET_ISO_8859_1				SLIM_TKID_CHSET_ISO_8859_1
#define SLIM_CHARSET_ISO_8859_15			SLIM_TKID_CHSET_ISO_8859_15
#define SLIM_CHARSET_WINDOWS_1252			SLIM_TKID_CHSET_windows_1252
#define SLIM_CHARSET_EUC_KR					SLIM_TKID_CHSET_EUC_KR
#define SLIM_CHARSET_UHC					SLIM_TKID_CHSET_KS_C_5601_1987
#define SLIM_CHARSET_GB2312					SLIM_TKID_CHSET_GB2312
#define SLIM_CHARSET_GBK					SLIM_TKID_CHSET_GBK
#define SLIM_CHARSET_GB18030				SLIM_TKID_CHSET_GB18030
#define SLIM_CHARSET_BIG5					SLIM_TKID_CHSET_Big5
#define SLIM_CHARSET_ISO_8859_4				SLIM_TKID_CHSET_ISO_8859_4
#define	SLIM_CHARSET_WINDOWS_1257			SLIM_TKID_CHSET_windows_1257
#define SLIM_CHARSET_ISO_8859_2				SLIM_TKID_CHSET_ISO_8859_2
#define	SLIM_CHARSET_WINDOWS_1250			SLIM_TKID_CHSET_windows_1250
#define SLIM_CHARSET_ISO_8859_5				SLIM_TKID_CHSET_ISO_8859_5
#define	SLIM_CHARSET_WINDOWS_1251			SLIM_TKID_CHSET_windows_1251
#define SLIM_CHARSET_KOI8_R					SLIM_TKID_CHSET_koi8_r
#define SLIM_CHARSET_ISO_8859_7				SLIM_TKID_CHSET_ISO_8859_7
#define	SLIM_CHARSET_WINDOWS_1253			SLIM_TKID_CHSET_windows_1253
#define SLIM_CHARSET_ISO_8859_10			SLIM_TKID_CHSET_ISO_8859_10
#define SLIM_CHARSET_ISO_8859_3				SLIM_TKID_CHSET_ISO_8859_3
#define SLIM_CHARSET_WINDOWS_874			SLIM_TKID_CHSET_windows_874
#define SLIM_CHARSET_ISO_8859_9				SLIM_TKID_CHSET_ISO_8859_9
#define	SLIM_CHARSET_WINDOWS_1254			SLIM_TKID_CHSET_windows_1254
#define SLIM_CHARSET_ISO_8859_6				SLIM_TKID_CHSET_ISO_8859_6
#define	SLIM_CHARSET_WINDOWS_1256			SLIM_TKID_CHSET_windows_1256
#define SLIM_CHARSET_ISO_8859_8				SLIM_TKID_CHSET_ISO_8859_8
#define SLIM_CHARSET_ISO_8859_8_I			SLIM_TKID_CHSET_ISO_8859_8_i
#define	SLIM_CHARSET_WINDOWS_1255			SLIM_TKID_CHSET_windows_1255
#define SLIM_CHARSET_UTF_8					SLIM_TKID_CHSET_UTF_8
#define SLIM_CHARSET_UTF_16BE				SLIM_TKID_CHSET_UTF_16BE
#define SLIM_CHARSET_UTF_16LE				SLIM_TKID_CHSET_UTF_16LE
#define SLIM_CHARSET_UCS_2BE				SLIM_TKID_CHSET_ISO_10646_UCS_2
#define SLIM_CHARSET_UCS_2LE				SLIM_TKID_CHSET_ISO_10646_UCS_2_LE
#define SLIM_CHARSET_UCS_4BE				SLIM_TKID_CHSET_ISO_10646_UCS_4
#define SLIM_CHARSET_UCS_4LE				SLIM_TKID_CHSET_ISO_10646_UCS_4_LE

/*
 * LangSet
 */

#define	SLIM_I18N_LANGSET_ANON					(-1)
#define SLIM_I18N_LANGSET_JAPANESE				SLIM_TKID_LNGSET_ja
#define SLIM_I18N_LANGSET_WESTERN				SLIM_TKID_LNGSET_en
#define	SLIM_I18N_LANGSET_KOREAN				SLIM_TKID_LNGSET_ko
#define	SLIM_I18N_LANGSET_SIMPLIFIED_CHINESE	SLIM_TKID_LNGSET_zn_cn
#define SLIM_I18N_LANGSET_TRADITIONAL_CHINESE	SLIM_TKID_LNGSET_zn_tw
#define	SLIM_I18N_LANGSET_ARMENIAN				SLIM_I18N_LANGSET_ANON
#define	SLIM_I18N_LANGSET_BALTIC				SLIM_TKID_LNGSET_lv
#define	SLIM_I18N_LANGSET_CELTIC				SLIM_I18N_LANGSET_ANON
#define	SLIM_I18N_LANGSET_CENTRAL_EUROPEAN		SLIM_TKID_LNGSET_hr
#define	SLIM_I18N_LANGSET_CROATIAN				SLIM_I18N_LANGSET_ANON
#define	SLIM_I18N_LANGSET_CYRILLIC				SLIM_TKID_LNGSET_ru
#define	SLIM_I18N_LANGSET_RUSSIAN_CYRILLIC		SLIM_I18N_LANGSET_ANON
#define	SLIM_I18N_LANGSET_UKRANIAN_CYRILLIC		SLIM_I18N_LANGSET_ANON
#define	SLIM_I18N_LANGSET_GREEK					SLIM_TKID_LNGSET_el
#define	SLIM_I18N_LANGSET_ICELANDIC				SLIM_I18N_LANGSET_ANON
#define	SLIM_I18N_LANGSET_NORDIC				SLIM_TKID_LNGSET_et
#define	SLIM_I18N_LANGSET_ROMANIAN				SLIM_I18N_LANGSET_ANON
#define	SLIM_I18N_LANGSET_SOUTH_EUROPEAN		SLIM_TKID_LNGSET_eo
#define	SLIM_I18N_LANGSET_THAI					SLIM_TKID_LNGSET_th
#define	SLIM_I18N_LANGSET_TURKISH				SLIM_TKID_LNGSET_tu
#define	SLIM_I18N_LANGSET_VIETNAMESE			SLIM_I18N_LANGSET_ANON
#define	SLIM_I18N_LANGSET_ARABIC				SLIM_TKID_LNGSET_ar
#define	SLIM_I18N_LANGSET_HEBREW				SLIM_TKID_LNGSET_iw
#define	SLIM_I18N_LANGSET_UNIVERSAL				SLIM_TKID_LNGSET_universal

#define SLIM_I18N_LANGSETS SLIM_TOKEN_LNGSET_ENUMS
#define SLIM_I18N_CHARSETS SLIM_TOKEN_CHSET_ENUMS

struct TLangSetInfo_ {
	slim_int fArchCharSet;
};
typedef struct TLangSetInfo_ TLangSetInfo;

/*
 * I18NConverter
 */
typedef struct TI18NConverterClass_ TI18NConverterClass;
struct TI18NConverterClass_ {
	slim_int fArchLangSet;
};

typedef struct TI18NConverter_ TI18NConverter;
struct TI18NConverter_ {
	TI18NConverterClass *fClass;
	slim_int fGuessedCharSet;
	slim_short fDeterminedCharSet;
	slim_short fDeterminedLangSet;
};

/*
 * I18N Character
 */
enum {
	/* common */
	SLIM_I18NCHAR_TYPE_UNKNOWN = 0,
	SLIM_I18NCHAR_TYPE_CTRL,
	SLIM_I18NCHAR_TYPE_ASCII,

	/* ISO-2022 */
#define SLIM_I18NCHAR_TYPE_ISO_CL SLIM_I18NCHAR_TYPE_CTRL
	SLIM_I18NCHAR_TYPE_ISO_GL,
	SLIM_I18NCHAR_TYPE_ISO_CR,
	SLIM_I18NCHAR_TYPE_ISO_GR,
	SLIM_I18NCHAR_TYPE_ISO_ESC_G0, /* ISO2022_CHSET is set to fSubType */
	SLIM_I18NCHAR_TYPE_ISO_ESC_G1, /* ISO2022_CHSET is set to fSubType */
	SLIM_I18NCHAR_TYPE_ISO_ESC_G2, /* ISO2022_CHSET is set to fSubType */
	SLIM_I18NCHAR_TYPE_ISO_ESC_G3, /* ISO2022_CHSET is set to fSubType */
	SLIM_I18NCHAR_TYPE_ISO_SHIFT, /* shift type is set to fSubType */
	
	/* Universal Character Set */
	SLIM_I18NCHAR_TYPE_UCS_UTF8, /* expected bytes is set to fSubType */
	SLIM_I18NCHAR_TYPE_UCS_UTF8_BOM,
	SLIM_I18NCHAR_TYPE_UCS_UTF16_SP, /* surrogate pair; fBytes shall be 4 */
	SLIM_I18NCHAR_TYPE_UCS_UCS2,
	SLIM_I18NCHAR_TYPE_UCS_UCS2_BOM,
	SLIM_I18NCHAR_TYPE_UCS_UCS2_PUA,
	SLIM_I18NCHAR_TYPE_UCS_UCS4,
	SLIM_I18NCHAR_TYPE_UCS_UCS4_BOM,
	SLIM_I18NCHAR_TYPE_UCS_UCS4_PUA,

	/* Japanese */
#define SLIM_I18NCHAR_TYPE_JP_C0 SLIM_I18NCHAR_TYPE_ISO_CL /* JISX0211 C0 */
#define SLIM_I18NCHAR_TYPE_JP_C1 SLIM_I18NCHAR_TYPE_ISO_CR /* JISX0211 C1 */
#define SLIM_I18NCHAR_TYPE_JP_LATIN SLIM_I18NCHAR_TYPE_ASCII /* JISX0201-latin */
	SLIM_I18NCHAR_TYPE_JP_KANA, /* JISX0201-kana */
	SLIM_I18NCHAR_TYPE_JP_ZENKAKU, /* JISX0208 */
	SLIM_I18NCHAR_TYPE_JP_X0212, 
	SLIM_I18NCHAR_TYPE_JP_X0213, 

	/* ko_KR */
#define	SLIM_I18NCHAR_TYPE_KO_ASCII_ROMAN SLIM_I18NCHAR_TYPE_ASCII
	SLIM_I18NCHAR_TYPE_KO_KSX1001_1992,
	SLIM_I18NCHAR_TYPE_KO_UHC,

	/* zh_CN */
	SLIM_I18NCHAR_TYPE_zhCN_GB2312, 
	SLIM_I18NCHAR_TYPE_zhCN_GBK, 
	SLIM_I18NCHAR_TYPE_zhCN_GB18030, 
	SLIM_I18NCHAR_TYPE_zhCN_1BYTE,

	/* zh_TW */
	SLIM_I18NCHAR_TYPE_zhTW_BIG5, 
	SLIM_I18NCHAR_TYPE_zhTW_BIG5_ETen, 

	SLIM_I18NCHAR_TYPES
};

/* sub type */
enum {
	SLIM_ISO2022_CHSET_ISO_646,
	SLIM_ISO2022_CHSET_JISX0201_LATIN,
	SLIM_ISO2022_CHSET_JISX0201_KANA,
	SLIM_ISO2022_CHSET_JISX0208_1978,
	SLIM_ISO2022_CHSET_JISX0208_1983,
	SLIM_ISO2022_CHSET_JISX0212,
	SLIM_ISO2022_CHSET_ISO_8859_1
};

enum {
	SLIM_ISO2022_SHIFT_SI, /* 0x0F */
	SLIM_ISO2022_SHIFT_SO, /* 0x0E */
	SLIM_ISO2022_SHIFT_LS2,
	SLIM_ISO2022_SHIFT_LS3,
	SLIM_ISO2022_SHIFT_LS1R,
	SLIM_ISO2022_SHIFT_LS2R,
	SLIM_ISO2022_SHIFT_LS3R,
	SLIM_ISO2022_SHIFT_SS2,
	SLIM_ISO2022_SHIFT_SS2R, /* 0x8E */
	SLIM_ISO2022_SHIFT_SS3,
	SLIM_ISO2022_SHIFT_SS3R /* 0x8F */
};

#define SLIM_I18NCHAR_MAXBUFLEN 8
struct TI18NChar_ {
	slim_int fCharSet;
	slim_int fType;
	slim_int fSubType;
	/* fBytes: negative value means number of invalid bytes which should be skipped.
	 * zero means that there is no readable byte or it is a incomplete character. */
	slim_int fBytes;
	slim_byte fChar[SLIM_I18NCHAR_MAXBUFLEN];
};

typedef struct TISO2022Ctx_ TISO2022Ctx;
struct TISO2022Ctx_ {
	slim_int fGL;
	slim_int fGR;
	slim_int fG0;
	slim_int fG1;
	slim_int fG2;
	slim_int fG3;
	slim_bool fSSxOn; /* begin single shift */
	slim_bool fSSxOff; /* end single shift */
	slim_int fPreSSCharSet; /* charset before single shift */
	slim_bool fIsSSxR; /* ss uses GR */
};

typedef struct TI18NGuessCtx_ TI18NGuessCtx;
struct TI18NGuessCtx_ {
	slim_int fCharSet;
	slim_int fCharTypeScore;
	slim_int fValidBytes;
	slim_int fAmbiguousBytes;
	slim_int fInvalidBytes;
};

/*
 * I18NString
 */

/* CharSet_StringForeach */
typedef slim_int (*TI18NStrForeachProc)(TI18NChar *in_ch, slim_opaque in_arg);

typedef struct TI18NString_ TI18NString;
struct TI18NString_ {
	slim_byte *fString;
	slim_int fBytes;
	slim_int fChars;
	TCharSetInfo *fCharSetInfo;
};

/*
 * CharLenInfo
 */
typedef slim_int (*slim_i18n_checkch_proc)(slim_byte *in_str, slim_int in_len, slim_int *out_type);

typedef struct TI18NCharLenInfo_ TI18NCharLenInfo;
struct TI18NCharLenInfo_ {
	slim_bool fGLIsASCII;
	slim_int *fCTypeFlags;
	slim_i18n_checkch_proc fCheckCharProc;
	slim_int fCharType;
};

/*
 * I18NStringIterator
 */

typedef struct TI18NStringIterator_ TI18NStringIterator;
struct TI18NStringIterator_ {
	TI18NString *fString;
	slim_int fOffset;
	slim_int fLeadingChars;
	slim_int fReadLen; /* 0 means that there's a incomplete character or no more characters. -1 means that fCurChar is not yet got. */
	slim_bool fUseCharLenInfo;
	TI18NCharLenInfo fCharLenInfo;
	TI18NChar fCurChar;
	TISO2022Ctx fISO2022Ctx;

};

/*
 * I18NCharProc
 */
typedef void (*slim_i18n_getch_proc)(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
typedef void (*slim_i18n_getch_iso2022_proc)(slim_byte *in_str, slim_int in_len, TI18NChar *out_char, TISO2022Ctx *in_ctx);
typedef slim_int (*slim_i18n_checkch_iso2022_proc)(slim_byte *in_str, slim_int in_len, slim_int *out_type, TISO2022Ctx *in_ctx);

typedef struct TI18NCharProc_ TI18NCharProc;
struct TI18NCharProc_ {
	union {
		slim_i18n_getch_proc Normal;
		slim_i18n_getch_iso2022_proc ISO2022;
	}uGetChar;
	union {
		slim_i18n_checkch_proc Normal;
		slim_i18n_checkch_iso2022_proc ISO2022;
	}uCheckChar;
};

/* misc */
typedef slim_bool (*slim_i18n_ctype_proc)(TI18NChar *in_c);

/* API */

SLIM_END_C_LINKAGE
#endif
