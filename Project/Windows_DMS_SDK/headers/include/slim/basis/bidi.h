/*
	bidi.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/basis/bidi.h 3     06/01/24 14:29 Nagamati $ */

#ifndef SLIM_BIDI_H
#define SLIM_BIDI_H

SLIM_BEGIN_C_LINKAGE

/*
 * The implementation is based on "Unicode Standard Annex #9 The Bidirectional Algorithm"
 * revision 15 which is based on Unicode 4.1.0.
 *
 * Please refer to
 *
 *   http://www.unicode.org/reports/tr9/
 *
 * if you want to understand details of the algorithm.
 */

/* Forward declaration */
typedef struct TBiDiChar_ TBiDiChar;
typedef struct iTBiDiContext_ **TBiDiContext;

/*
 * Bidirectional character types.
 *
 * Be carefull! The program depends heavily on values of types.
 *
 * If you add new bidirectional character types or change values
 * of existing types, you have to add or change SLIM_BIDI_TYPEFLAG_XXX
 * corresponding to the types.
 */
enum {
	SLIM_BIDI_TYPE_L   = 0,  /* S */
	SLIM_BIDI_TYPE_R   = 1,  /* S */
	SLIM_BIDI_TYPE_EN  = 2,  /* W */
	SLIM_BIDI_TYPE_AN  = 3,  /* W */
	SLIM_BIDI_TYPE_S   = 4,  /* N */
	SLIM_BIDI_TYPE_WS  = 5,  /* N */
	SLIM_BIDI_TYPE_ON  = 6,  /* N */
	SLIM_BIDI_TYPE_AL  = 7,  /* S */
	SLIM_BIDI_TYPE_ET  = 8,  /* W */
	SLIM_BIDI_TYPE_ES  = 9,  /* W */
	SLIM_BIDI_TYPE_CS  = 10, /* W */
	SLIM_BIDI_TYPE_NSM = 11, /* W */
	SLIM_BIDI_TYPE_LRE = 12, /* S */
	SLIM_BIDI_TYPE_LRO = 13, /* S */
	SLIM_BIDI_TYPE_RLE = 14, /* S */
	SLIM_BIDI_TYPE_RLO = 15, /* S */
	SLIM_BIDI_TYPE_PDF = 16, /* W */
	SLIM_BIDI_TYPE_BN  = 17, /* W */
	SLIM_BIDI_TYPE_B   = 18, /* N */

	/* special types */
	SLIM_BIDI_TYPE_UNKNOWN = 19,
	SLIM_BIDI_TYPE_NONE    = 20,
	SLIM_BIDI_TYPE_E       = 21,

	/* aliases */
	SLIM_BIDI_FORMATTING_CODES = SLIM_BIDI_TYPE_LRE,
	SLIM_BIDI_WEAK_PHASE_TYPES = SLIM_BIDI_TYPE_NSM + 1,
	SLIM_BIDI_NEUTRAL_PHASE_TYPES = SLIM_BIDI_TYPE_ON + 1,
	SLIM_BIDI_IMPLICIT_PHASE_TYPES = SLIM_BIDI_TYPE_AN + 1
};

enum {
	SLIM_BIDI_FLAG_LTR      = 0x00000000,	/**< This value is equal to base level of left-to-right paragraph. */
	SLIM_BIDI_FLAG_RTL      = 0x00000001,	/**< This value is equal to base level of right-to-left paragraph. */
	SLIM_BIDI_FLAG_OVERRIDE = 0x00000002,	/**< */

	/* aliases */
	SLIM_BIDI_FLAG_LTR_OVERRIDE = SLIM_BIDI_FLAG_LTR | SLIM_BIDI_FLAG_OVERRIDE,
	SLIM_BIDI_FLAG_RTL_OVERRIDE = SLIM_BIDI_FLAG_RTL | SLIM_BIDI_FLAG_OVERRIDE,

	/**
	 * Using this mask, we can get base level from the flag.
	 */
	SLIM_BIDI_MASK_BASE_LEVEL = SLIM_BIDI_FLAG_LTR | SLIM_BIDI_FLAG_RTL,

	/**
	 * Using this mask, we can get direction information from the flag.
	 */
	SLIM_BIDI_MASK_DIR = SLIM_BIDI_FLAG_LTR | SLIM_BIDI_FLAG_RTL | SLIM_BIDI_FLAG_OVERRIDE
};

struct TBiDiText_ {
	slim_int fFlag;
	slim_int fCharSet;
	slim_int fChars;
	slim_int fBytes;
	TBiDiChar *fChar;
};
typedef struct TBiDiText_ TBiDiText;

enum {
	SLIM_BIDI_TEXTFLAG_ALLOCATED  = 0x00000001,
	SLIM_BIDI_TEXTFLAG_EOP        = 0x00000002,
	SLIM_BIDI_TEXTFLAG_ODD_LEVEL  = 0x00000004,
	SLIM_BIDI_TEXTFLAG_EVEN_LEVEL = 0x00000008
};

struct TBiDiTextRange_ {
	slim_int fStartChar;
	slim_int fEndChar;
	slim_int fStartByte;
	slim_int fEndByte;
};
typedef struct TBiDiTextRange_ TBiDiTextRange;

struct TBiDiPara_ {
	TBiDiText fBase;
	slim_int fBaseLevel;
};
typedef struct TBiDiPara_ TBiDiPara;

struct TBiDiLine_ {
	TBiDiText fBase;
	slim_int *fDispToLogMap;	/* Display Index -> Logical Index */
	slim_int fDisplayChars;
};
typedef struct TBiDiLine_ TBiDiLine;

/* BiDi Paragraph */

/**
 * Initializes BiDi paragraph object.
 *
 * @param[in,out] self is pointer to the BiDi paragraph object to be initialized.
 * @param[in] in_text is pointer to text string.
 * @param[in] in_len is length of text (bytes).
 * @param[in] in_charset is SLIM_CHARSET_XXX of in_text.
 * @param[in] in_flag is bitwise OR of the following flags.
 *              - SLIM_BIDI_FLAG_LTR or SLIM_BIDI_FLAG_RTL
 *              - SLIM_BIDI_FLAG_OVERRIDE
 *
 * @retval SLIM_E_OK successful.
 * @retval SLIM_E_INVAL invalid arguments.
 * @retval SLIM_E_NOMEM lack of memory.
 * @retval SLIM_E_NOTSUPPORTED There are unsupported characters in in_text.
 * @retval SLIM_E_GENERIC other error.
 */
SLIM_API slim_int TBiDiPara_Initialize(TBiDiPara *self, slim_byte *in_text, slim_int in_len, slim_int in_charset, slim_int in_flag);

/**
 * Finalizes BiDi paragraph object.
 *
 * @param[in,out] self is pointer to the BiDi paragraph object to be finalized.
 */
SLIM_API void TBiDiPara_Finalize(TBiDiPara *self);

/**
 * Gets BiDi line object from BiDi paragraph object by range.
 *
 * @param[in] self is pointer to the BiDi paragraph object.
 * @param[in] in_range is range of line you want to get.
 * @param[out] out_line is pointer to the BiDi line object.
 *
 * @retval SLIM_E_OK successful.
 * @retval SLIM_E_NOMEM
 * @retval SLIM_E_INVAL invalid range.
 * @retval SLIM_E_GENERIC other error.
 *
 * @note If in_range is equal to slim_nil, the whole paragraph is returned as a line.
 */
SLIM_API slim_int TBiDiPara_GetLineByRange(TBiDiPara *self, TBiDiTextRange *in_range, TBiDiLine *out_line);

/* BiDi Line */

/**
 * Initializes BiDi line object.
 *
 * @param[in,out] self is pointer to BiDi line object to be initialized.
 */
SLIM_API void TBiDiLine_Initialize(TBiDiLine *self);

/**
 * Finalizes BiDi line object.
 *
 * @param[in,out] self is pointer to BiDi line object to be finalized.
 */
SLIM_API void TBiDiLine_Finalize(TBiDiLine *self);

/**
 * Gets a number of characters of display text.
 *
 * @param[in] self is pointer to the BiDi line object.
 *
 * @return >0 a number of characters.
 */
#define TBiDiLine_DisplayTextChars(self)	((self)->fDisplayChars)

/**
 * Gets display text from the BiDi line object.
 *
 * @param[in] self is pointer to BiDi line object.
 * @param[out] out_text is pointer to buffer for display text.
 *
 * @return bytes of display text.
 */
SLIM_API slim_int TBiDiLine_GetDisplayText(TBiDiLine *self, slim_byte *out_text);

/**
 * Gets display index from logical index.
 *
 * @param[in] self is pointer to BiDi line object.
 * @param[in] in_index is index of character in logical text.
 *
 * @retval >=0
 * @retval <0
 */
SLIM_API slim_int TBiDiLine_LogicalIndexToDisplayIndex(TBiDiLine *self, slim_int in_index);

/**
 * Gets logical index from display index.
 *
 * @param[in] self is pointer to BiDi line object.
 * @param[in] in_index is index of character in display text.
 *
 * @retval >=0
 * @retval <0
 *
 * @note This function is faster than TBiDiLine_LogicalIndexToDisplayIndex.
 */
SLIM_API slim_int TBiDiLine_DisplayIndexToLogicalIndex(TBiDiLine *self, slim_int in_index);

/* Utility Functions */

/**
 * Makes a display text of a logical text.
 *
 * @param[in] in_text is a pointer to the logical text.
 * @param[in] in_len is a number of bytes of the logical text.
 * @param[in] in_charset is a character set of the logical text (SLIM_CHARSET_XXX).
 * @param[in] in_flag is bitwise OR of the following flags.
 *              - SLIM_BIDI_FLAG_LTR or SLIM_BIDI_FLAG_RTL
 *              - SLIM_BIDI_FLAG_OVERRIDE
 * @param[out] out_text is a pointer to the display text.
 *
 * @retval SLIM_E_OK
 * @retval SLIM_E_NOMEM
 * @retval SLIM_E_INVAL
 */
SLIM_API slim_int slim_bidi_make_display_text(slim_byte *in_text, slim_int in_len, slim_int in_charset, slim_int in_flag, TString *out_text);

/* BiDi Peer */

struct TBiDiProperty_ {
	/**
	 * Bidirectional character type of the character.
	 * You can set one of the following types.
	 *
	 *   - SLIM_BIDI_TYPE_L
	 *   - SLIM_BIDI_TYPE_LRE
	 *   - SLIM_BIDI_TYPE_LRO
	 *   - SLIM_BIDI_TYPE_R
	 *   - SLIM_BIDI_TYPE_AL
	 *   - SLIM_BIDI_TYPE_RLE
	 *   - SLIM_BIDI_TYPE_RLO
	 *   - SLIM_BIDI_TYPE_PDF
	 *   - SLIM_BIDI_TYPE_EN
	 *   - SLIM_BIDI_TYPE_ES
	 *   - SLIM_BIDI_TYPE_ET
	 *   - SLIM_BIDI_TYPE_AN
	 *   - SLIM_BIDI_TYPE_CS
	 *   - SLIM_BIDI_TYPE_NSM
	 *   - SLIM_BIDI_TYPE_BN
	 *   - SLIM_BIDI_TYPE_B
	 *   - SLIM_BIDI_TYPE_S
	 *   - SLIM_BIDI_TYPE_WS
	 *   - SLIM_BIDI_TYPE_ON
	 *   - SLIM_BIDI_TYPE_UNKNOWN
	 *
	 * You can set SLIM_BIDI_TYPE_UNKNOWN if you want to proceed the algorighm
	 * although the character is not supported on your platform. In this case,
	 * we treat the character as fType(L) and fMirror(0).
	 */
	slim_byte fType;

	/**
	 * Existance of mirrored character of the character.
	 *
	 * 0: The character has no mirrored character or
	 *    slimBiDiGetPropertyPeer can't return the mirrored character.
	 * 1: The character has mirrored character and
	 *    slimBiDiGetPropertyPeer can return the mirrored character.
	 */
	slim_byte fMirror;
};
typedef struct TBiDiProperty_ TBiDiProperty;

/**
 * Gets Unicode character proterties related to the bidirectional algorithm.
 *
 * @param[in] in_char is pointer to byte array of a character.
 * @param[in] in_bytes is bytes of in_char.
 * @param[in] in_charset is a character set of in_char.
 * @param[out] out_property is pointer to BiDi property structure.
 *
 * @retval SLIM_E_OK Successful.
 * @retval SLIM_E_INVAL Invald arguments.
 * @retval SLIM_E_NOTSUPPORTED Unsupported character.
 * @retval SLIM_E_GENERIC Other error.
 */
SLIM_API slim_int slimBiDiGetPropertyPeer(slim_byte *in_char, slim_int in_bytes, slim_int in_charset, TBiDiProperty *out_property);

/**
 * Gets mirrored character.
 *
 * @param[in] in_char is pointer to byte array of a character.
 * @param[in] in_bytes is bytes of in_char.
 * @param[in] in_charset is a character set of in_char.
 * @param[out] out_char is pointer to byte array to outputting mirrored character of in_char.
 *
 * @retval >0 Bytes of out_char.
 * @retval <0 Invalid arguments or there is no mirrored character related to in_char.
 *
 * @note If out_char is equal to slim_nil, this peer function has to return bytes of mirrored character or <0.
 */
SLIM_API slim_int slimBiDiGetMirroredCharPeer(slim_byte *in_char, slim_int in_bytes, slim_int in_charset, slim_byte *out_char);

SLIM_END_C_LINKAGE

#endif /* SLIM_BIDI_H */
