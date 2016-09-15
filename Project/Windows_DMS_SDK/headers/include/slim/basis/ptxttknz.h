/*
	ptxttknz.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/basis/ptxttknz.h 23    06/07/31 19:05 Someya $ */

#ifndef SLIM_PLASTICTEXT_TOKENIZER_H
#define SLIM_PLASTICTEXT_TOKENIZER_H

SLIM_BEGIN_C_LINKAGE


enum {
	SLIM_PTEXT_TKID_TEXT = 0,
	SLIM_PTEXT_TKID_URL,
	SLIM_PTEXT_TKID_TEL,
	SLIM_PTEXT_TKID_MAIL,
#ifdef SLIM_CONFIG_USE_MEDIA_SCHEME
	SLIM_PTEXT_TKID_MEDIA,
#endif
	SLIM_PTEXT_TKID_USERDEFINED
};

typedef struct TTokenizerClassListItem_ TTokenizerClassListItem;
struct TTokenizerClassListItem_ {
	slim_int fTokenType;
	TTokenizerClass *fTokenizerClass;
	slim_int fPriority;
	slim_bool fIsMonoLex;
};

typedef struct TPTextTokenizerClass_ TPTextTokenizerClass;
struct TPTextTokenizerClass_ {
	TParallelTokenizerClass fBase;
	TSpecList fTokenizerClassList;
};

typedef struct TPTextTokenizer_ TPTextTokenizer;
struct TPTextTokenizer_ {
	TParallelTokenizer fBase;
	TxxToken fCurrentToken;
};

/*
 * URL
 */
typedef struct TPTextURLTokenizerClass_ TPTextURLTokenizerClass;
struct TPTextURLTokenizerClass_ {
	TTokenizerClass fBase;
	slim_int fMaxLength;
};

typedef struct TPTextURLTokenizer_ TPTextURLTokenizer;
struct TPTextURLTokenizer_ {
	TTokenizer fBase;
	TxxToken fCurrentToken;
};

/*
 * Tel
 */
enum {
	SLIM_PTEXTTELTKNZ_TELNUMMODE_NORMAL = 0,
	SLIM_PTEXTTELTKNZ_TELNUMMODE_INTERNATIONAL,
	SLIM_PTEXTTELTKNZ_TELNUMMODE_ASTERSHARP,
	SLIM_PTEXTTELTKNZ_TELNUMMODE_SCHEME,
	SLIM_PTEXTTELTKNZ_TELNUMMODES
};

#define SLIM_PTEXTTELTKNZ_MAX_ALLOWEDSCHEMES 8
#define SLIM_PTEXTTELTKNZ_MAX_SCHEME_LEN 16 /* include ':' */

typedef struct TPTextTelTokenizerClass_ TPTextTelTokenizerClass;
struct TPTextTelTokenizerClass_ {
	TTokenizerClass fBase;
	slim_int fFlag;
	slim_i18n_ctype_proc fIsTelNum;
	slim_i18n_ctype_proc fIsTelDelim;
	slim_i18n_ctype_proc fIsTel1st;
	slim_i18n_ctype_proc fIsNotTel;
	slim_int fNumAllowedSchemes;
	slim_split_ss fAllowedSchemes[SLIM_PTEXTTELTKNZ_MAX_ALLOWEDSCHEMES];
	slim_byte fMinMaxNumChars[SLIM_PTEXTTELTKNZ_TELNUMMODES][2];
	slim_int f1stCharsLen;
	slim_char fAllowedScheme1stChars[SLIM_PTEXTTELTKNZ_MAX_ALLOWEDSCHEMES * 2];
};

typedef struct TPTextTelTokenizer_ TPTextTelTokenizer;
struct TPTextTelTokenizer_ {
	TTokenizer fBase;
	TxxToken fCurrentToken;
	slim_handle fSchemeConvBuf;
};

/*
 * PTextMailTokenizer
 */

#define SLIM_PTEXTMAILTKNZ_ALLOW_UNKNOWNHNAME	0x00000001 /* allow unknown field name */

typedef struct TPTextMailTokenizerClass_ TPTextMailTokenizerClass;
struct TPTextMailTokenizerClass_ {
	TTokenizerClass fBase;
	slim_int fMaxLength;
	slim_int fFlag;
};

typedef struct TPTextMailTokenizer_ TPTextMailTokenizer;
struct TPTextMailTokenizer_ {
	TTokenizer fBase;
	TxxToken fCurrentToken;
};

/*
 * PTextMediaTokenizer
 */

#define DTV_PTEXT_MEDIA_PRIORITY	(50)

typedef struct TPTextMediaTokenizerClass_ TPTextMediaTokenizerClass;
struct TPTextMediaTokenizerClass_ {
	TTokenizerClass fBase;
	slim_int fMaxLength;
};

typedef struct TPTextMediaTokenizer_ TPTextMediaTokenizer;
struct TPTextMediaTokenizer_ {
	TTokenizer fBase;
	TxxToken fCurrentToken;
};

SLIM_END_C_LINKAGE

#endif

