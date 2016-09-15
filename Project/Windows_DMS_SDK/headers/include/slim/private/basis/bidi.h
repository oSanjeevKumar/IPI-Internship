/*
	bidi.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/basis/bidi.h 3     06/01/24 14:29 Nagamati $ */

#ifndef SLIM_BIDI_H_PRIVATE
#define SLIM_BIDI_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

#define SLIM_BIDI_STACK_SIZE	64

/**
 * Flags of the bidirectional character types.
 *
 * We use these flags to know which types are included in a text processing currently.
 *
 * If you add new flags or change values of existing flags, you have to add or change
 * SLIM_BIDI_TYPE_XXX corresponding to the flags.
 */
enum {
	SLIM_BIDI_TYPEFLAG_L   = 0x00000001, /**< SLIM_BIDI_TYPE_L   */
	SLIM_BIDI_TYPEFLAG_R   = 0x00000002, /**< SLIM_BIDI_TYPE_R   */
	SLIM_BIDI_TYPEFLAG_EN  = 0x00000004, /**< SLIM_BIDI_TYPE_EN  */
	SLIM_BIDI_TYPEFLAG_AN  = 0x00000008, /**< SLIM_BIDI_TYPE_AN  */
	SLIM_BIDI_TYPEFLAG_S   = 0x00000010, /**< SLIM_BIDI_TYPE_S   */
	SLIM_BIDI_TYPEFLAG_WS  = 0x00000020, /**< SLIM_BIDI_TYPE_WS  */
	SLIM_BIDI_TYPEFLAG_ON  = 0x00000040, /**< SLIM_BIDI_TYPE_ON  */
	SLIM_BIDI_TYPEFLAG_AL  = 0x00000080, /**< SLIM_BIDI_TYPE_AL  */
	SLIM_BIDI_TYPEFLAG_ET  = 0x00000100, /**< SLIM_BIDI_TYPE_ET  */
	SLIM_BIDI_TYPEFLAG_ES  = 0x00000200, /**< SLIM_BIDI_TYPE_ES  */
	SLIM_BIDI_TYPEFLAG_CS  = 0x00000400, /**< SLIM_BIDI_TYPE_CS  */
	SLIM_BIDI_TYPEFLAG_NSM = 0x00000800, /**< SLIM_BIDI_TYPE_NSM */
	SLIM_BIDI_TYPEFLAG_LRE = 0x00001000, /**< SLIM_BIDI_TYPE_LRE */
	SLIM_BIDI_TYPEFLAG_LRO = 0x00002000, /**< SLIM_BIDI_TYPE_LRO */
	SLIM_BIDI_TYPEFLAG_RLE = 0x00004000, /**< SLIM_BIDI_TYPE_RLE */
	SLIM_BIDI_TYPEFLAG_RLO = 0x00008000, /**< SLIM_BIDI_TYPE_RLO */
	SLIM_BIDI_TYPEFLAG_PDF = 0x00010000, /**< SLIM_BIDI_TYPE_PDF */
	SLIM_BIDI_TYPEFLAG_BN  = 0x00020000, /**< SLIM_BIDI_TYPE_BN  */
	SLIM_BIDI_TYPEFLAG_B   = 0x00040000  /**< SLIM_BIDI_TYPE_B   */
};

/**
 * Types of the bidirectional override status.
 */
enum {
	SLIM_BIDI_OVERRIDE_N,
	SLIM_BIDI_OVERRIDE_R,
	SLIM_BIDI_OVERRIDE_L
};

/**
 * States of the stage of resolving embedding levels of weak types.
 */
enum {
	/* strong */
	SLIM_BIDI_WST_L = 0,
	SLIM_BIDI_WST_R,
	SLIM_BIDI_WST_AL,
	/* number */
	SLIM_BIDI_WST_L_EN,
	SLIM_BIDI_WST_L_AN,
	SLIM_BIDI_WST_R_EN,
	SLIM_BIDI_WST_R_AN,
	SLIM_BIDI_WST_AL_XN,
	/* neutral */
	SLIM_BIDI_WST_L_N,
	SLIM_BIDI_WST_R_N,
	SLIM_BIDI_WST_AL_N,
	/* terminator */
	SLIM_BIDI_WST_L_ET,
	SLIM_BIDI_WST_R_ET,
	SLIM_BIDI_WST_L_EN_ET,
	SLIM_BIDI_WST_R_EN_ET,
	/* separator */
	SLIM_BIDI_WST_L_EN_XS,
	SLIM_BIDI_WST_L_AN_CS,
	SLIM_BIDI_WST_R_EN_XS,
	SLIM_BIDI_WST_R_AN_CS,
	SLIM_BIDI_WST_AL_XN_CS,
	SLIM_BIDI_WSTS
};

/**
 * States of the stage of resolving embedding levels of neutral types.
 */
enum {
	SLIM_BIDI_NST_L = 0,
	SLIM_BIDI_NST_R,
	SLIM_BIDI_NST_L_AN,
	SLIM_BIDI_NST_L_N,
	SLIM_BIDI_NST_R_N,
	SLIM_BIDI_NST_L_AN_N,
	SLIM_BIDI_NSTS
};

struct TBiDiChar_ {
	slim_byte *fPtr;			/**< is a pointer to a byte array of the character */
	slim_byte fBytes;			/**< is a number of bytes of the character */
	slim_byte fType;			/**< is an original bidirectional character type of the character */
	slim_byte fResolvedType;	/**< is a resolved bidirectional character type of the character */
	slim_byte fLevel;			/**< is an embedding level of the character */
	slim_byte fMirror;			/**< is equal to 0 if the character has a mirrored character, 1 if not */
	slim_byte fReserved[3];
};

struct iTBiDiContext_ {
	slim_int fFlag;
	slim_int fPrevLevel;
	slim_int fWeakState;
	slim_int fNeutralState;
	slim_int fStackIndex;
	slim_int fOverflowIndex;
	slim_byte fLevelStack[SLIM_BIDI_STACK_SIZE];
	slim_byte fOverrideStack[SLIM_BIDI_STACK_SIZE];
};
typedef struct iTBiDiContext_ iTBiDiContext;

struct iTBiDiProcessor_ {
	iTBiDiContext fContext;
	slim_bool fLastLine;
	slim_bool fFormattingCode;
	slim_int fExplicitUnresolvedChars;
	slim_int fWeakUnresolvedChars;
	slim_int fNeutralUnresolvedChars;
};
typedef struct iTBiDiProcessor_ iTBiDiProcessor;
typedef struct iTBiDiProcessor_ **TBiDiProcessor;

/* BiDi Utility Functions */

/**
 * Prepares BiDi characters with a text fragment.
 *
 * @param[in] in_text is a pointer to a text fragment.
 * @param[in] in_len is a number of bytes in the text fragment.
 * @param[in] in_charset is a character set (SLIM_CHARSET_XXX) of the text fragment.
 * @param[in] in_chars is a number of characters in the text fragment.
 * @param[out] out_bidi_char is a pointer to an array of BiDi character.
 : @param[out] out_flag is a pointer to a flag stored SLIM_BIDI_TYPEFLAG_XXX.
 *
 * @retval !=slim_false Successful.
 * @retval ==slim_false There are unsupported characters in the text fragment.
 */
slim_bool BiDi_PrepareChars(slim_byte *in_text, slim_int in_len, slim_int in_charset, slim_int in_chars, TBiDiChar *out_bidi_char, slim_int *out_flag);

/* BiDi Context */

/**
 * Creates a BiDi context.
 *
 * @return Created BiDi context.
 */
#define BiDiContext_New()			((TBiDiContext)slim_handle_alloc(sizeof(iTBiDiContext)))

/**
 * Deletes a BiDi context.
 *
 * @param[in] self is the BiDi context.
 */
#define TBiDiContext_Delete(self)	(slim_handle_free((slim_handle)(self)))

/* BiDi Processor */

/**
 * Creates a BiDi processor object.
 *
 * @param[in] in_flag is bitwise OR of the following flags.
 *              - SLIM_BIDI_FLAG_LTR or SLIM_BIDI_FLAG_RTL
 *              - SLIM_BIDI_FLAG_OVERRIDE
 *
 * @return Created BiDi processor object.
 */
TBiDiProcessor BiDiProcessor_New(slim_int in_flag);

/**
 * Deletes a BiDi processor object.
 *
 * @param[in] self is the BiDi processor object.
 */
void TBiDiProcessor_Delete(TBiDiProcessor self);

/**
 * Loads a BiDi context to a BiDi processor object.
 *
 * @param[in] self is the BiDi processor object.
 * @param[in] in_context is the BiDi context.
 */
void TBiDiProcessor_LoadContext(TBiDiProcessor self, TBiDiContext in_context);

/**
 * Saves a BiDi context from a BiDi processor object.
 *
 * @param[in] self is the BiDi processor object.
 * @param[in] in_context is a pointer to the BiDi context.
 */
slim_int TBiDiProcessor_SaveContext(TBiDiProcessor self, TBiDiContext *out_context);

/**
 * Resolves embedding levels of a text.
 *
 * @param[in] self is the BiDi processor object.
 * @param[in] in_text is a pointer to a BiDi text object.
 *
 * @return The number of unresolved characters.
 */
slim_int TBiDiProcessor_ResolveLevels(TBiDiProcessor self, TBiDiText *in_text);

/**
 */
slim_int TBiDiProcessor_PostResolveByType(TBiDiProcessor self, slim_int in_type, TBiDiText *inout_text);

/**
 */
slim_int TBiDiProcessor_PostResolveByText(TBiDiProcessor self, slim_byte *in_text, slim_int in_len, TBiDiText *inout_text);

/* BiDi Line */

/*
 * Initializes a BiDi line object.
 */
slim_int TBiDiLine_InitializeX(TBiDiLine *self, slim_int in_charset, slim_int in_chars, slim_bool in_eop);

/**
 * Reorders characters in the line.
 */
slim_int TBiDiLine_Reorder(TBiDiLine *self, slim_int in_base_level);

/* Utility Functions */

/**
 * Makes a revere text of a logical text.
 *
 * @param[in] in_text is a pointer to the logical text.
 * @param[in] in_len is a number of bytes of the logical text.
 * @param[in] in_charset is a character set of the logical text (SLIM_CHARSET_XXX).
 * @param[out] out_text is a pointer to the display text.
 *
 * @retval SLIM_E_OK
 * @retval SLIM_E_NOMEM
 * @retval SLIM_E_INVAL
 */
slim_int slim_bidi_make_reverse_text(slim_byte *in_text, slim_int in_len, slim_int in_charset, TString *out_text);

SLIM_END_C_LINKAGE

#endif /* SLIM_BIDI_H_PRIVATE */
