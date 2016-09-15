/*
	contdtmn.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/inet/contdtmn.h 22    06/08/25 11:31 Iida $ */

#ifndef SLIM_CONTENT_DETERMINER_H_PRIVATE
#define SLIM_CONTENT_DETERMINER_H_PRIVATE

#include <slim/libinet.h>

SLIM_BEGIN_C_LINKAGE

/*
 * ContentDeterminer
 */


#define ContentDeterminer_SetDefaultCharSetGuessParam(cls, chset, lang) ((cls)->fDefaultGuessParam.fRequestedCharSet = (chset), (cls)->fDefaultGuessParam.fAutoDetectLangSet = (lang))



enum {
	SLIM_CONTDTMN_STATE_MIME_1ST_ADOPT = 0,
	SLIM_CONTDTMN_STATE_MIME_PREPARE_GUESS,
	SLIM_CONTDTMN_STATE_MIME_GUESSING_AS_TEXT,
	SLIM_CONTDTMN_STATE_MIME_GUESSING_AS_BINARY,
	SLIM_CONTDTMN_STATE_MIME_2ND_ADOPT,
	SLIM_CONTDTMN_STATE_MIME_SURMISE_BINARY,
	SLIM_CONTDTMN_STATE_MIME_FINAL_ADOPT,
	SLIM_CONTDTMN_STATE_CHSET_1ST_ADOPT,
	SLIM_CONTDTMN_STATE_CHSET_DETECTING,
	SLIM_CONTDTMN_STATE_CHSET_2ND_ADOPT,
	SLIM_CONTDTMN_STATE_CHSET_PREPARE_GUESS,
	SLIM_CONTDTMN_STATE_CHSET_CHECK_UCS,
	SLIM_CONTDTMN_STATE_CHSET_GUESSING,
	SLIM_CONTDTMN_STATE_CHSET_FINAL_ADOPT,
	SLIM_CONTDTMN_STATE_DONE,
	SLIM_CONTDTMN_STATEs
};

#define SLIM_CONTDTMN_FLAG_DONE		0x00000001
#define SLIM_CONTDTMN_FLAG_ERROR	0x00000002
#define SLIM_CONTDTMN_FLAG_OMIT_CHARSET	0x00000004
#define SLIM_CONTDTMN_FLAG_MIME_DONE_AS_TEXT	0x00000008
#define SLIM_CONTDTMN_FLAG_MIME_DONE_AS_BINARY	0x00000010
#define SLIM_CONTDTMN_FLAG_OMIT_DETECTCHARSET	0x00000020
#define SLIM_CONTDTMN_FLAG_MIME_SURMISE_BINARY	0x00000040

#define SLIM_CONTDTMN_MAXGUESSLENGTH 4096

#define SLIM_CONTDTMN_MASK_MIME_DONE_GUESS	(SLIM_CONTDTMN_FLAG_MIME_DONE_AS_TEXT|SLIM_CONTDTMN_FLAG_MIME_DONE_AS_BINARY)


#define TContentDeterminer_AdoptedMIMEType(self) ((self)->fAdoptedMIMEType)
#define TContentDeterminer_AdoptedCharSet(self) ((self)->fAdoptedCharSet)
#define TContentDeterminer_SetCharSetGuessParam(self, param) ((self)->fCharSetGuessParam = *(param))
#define TContentDeterminer_SetI18NConvParam(self, param) ((self)->fCharSetGuessParam = *(param))
#define TContentDeterminer_CharSetGuessParam(self) (&(self)->fCharSetGuessParam)
#define TContentDeterminer_I18NConvParam(self) (&(self)->fCharSetGuessParam)

#define TContentDeterminer_GuessMIMETypeAsText(self) TContentDeterminer_GuessMIMETypeAsX((self), slim_true)
#define TContentDeterminer_GuessMIMETypeAsBinary(self) TContentDeterminer_GuessMIMETypeAsX((self), slim_false)

#define TContentDeterminer_SetDetectedCharSet(self, charset) ((self)->fFlag |= SLIM_CONTDTMN_FLAG_OMIT_DETECTCHARSET,(self)->fDetectedCharSet = (charset))

/* Ugh! */

SLIM_END_C_LINKAGE

#endif


