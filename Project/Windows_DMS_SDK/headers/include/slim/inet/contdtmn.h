/*
	contdtmn.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/inet/contdtmn.h 20    06/08/25 17:38 Iida $ */

#ifndef SLIM_CONTENT_DETERMINER_H
#define SLIM_CONTENT_DETERMINER_H

SLIM_BEGIN_C_LINKAGE

/* declare */
typedef struct TContentDeterminer_ TContentDeterminer;

/*
 * CharSetGuessParam
 */
struct TCharSetGuessParam_ {
	slim_int fRequestedCharSet;
	slim_int fAutoDetectLangSet;
};
typedef struct TCharSetGuessParam_ TCharSetGuessParam;
typedef TCharSetGuessParam TI18NConvParam;

/*
 * ContentDeterminer
 */
typedef slim_int (*ContentDeterminer_GuessProc)(TContentDeterminer *self, slim_byte *in_data, slim_int in_len, slim_bool in_eod);
typedef slim_int (*ContentDeterminer_GuessCharSetProc)(TContentDeterminer *self, slim_byte *in_data, slim_int in_len, slim_bool in_eod, slim_int *out_score);
typedef slim_int (*ContentDeterminer_AdoptProc)(TContentDeterminer *self, slim_bool in_first_time, slim_bool in_final_answer);

#define SLIM_CONTDTMN_MAXGUESSLENs 6
typedef struct TContentDeterminerClass_ TContentDeterminerClass;
struct TContentDeterminerClass_ {
	TMIMEInfoClass *fMIMEInfoClass;
	TI18NConverterClass *fI18NConverterClass;
	TCharSetGuessParam fDefaultGuessParam;
	slim_int fMaxGuessLen[SLIM_CONTDTMN_MAXGUESSLENs];
	ContentDeterminer_GuessProc fGuessText;
	ContentDeterminer_GuessProc fGuessBinary;
	ContentDeterminer_AdoptProc fAdoptMIMEType;
	ContentDeterminer_GuessCharSetProc fGuessCharSet;
	ContentDeterminer_GuessProc fDetectCharSet;
	ContentDeterminer_AdoptProc fAdoptCharSet;
};

struct TContentDeterminer_ {
	TContentDeterminerClass *fClass;
	TCharSetGuessParam fCharSetGuessParam;
	TContent fContent;
	slim_int fState;
	slim_int fFlag;
	slim_int fMaxStayTime;
	slim_int fDetectedMIMEType;
	slim_int fExpectedMIMEType;
	slim_int fGuessedMIMEType;
	slim_int fSurmisedMIMEType;
	slim_int fAdoptedMIMEType;
	slim_int fExpectedLangSet;
	slim_int fDetectedCharSet;
	slim_int fGuessedCharSet;
	slim_int fGuessedCharSetScore;
	slim_int fGuessedUniversal;
	slim_int fGuessedUniversalScore;
	slim_int fAdoptedCharSet;
	slim_int fMaxGuessLen[SLIM_CONTDTMN_MAXGUESSLENs];
};

SLIM_END_C_LINKAGE
#endif
