/*
	reader.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/basis/reader.h 40    06/05/17 0:57 Endoh $ */

#ifndef SLIM_READER_H
#define SLIM_READER_H

SLIM_BEGIN_C_LINKAGE

/*
 * ReaderInput
 */
typedef struct TReaderInput_ TReaderInput;
struct TReaderInput_ {
	TIOBuffer *fBuffer;
	TIOBuffer fDefaultBuf;
	slim_int fPrecedingLength;
	slim_bool fHasEOF;
	slim_int fEncoding;
};	

/*
 * TxxToken
 */
#define SLIM_XXTOKEN_TYPE_UNKNOWN (-1)
typedef struct TxxToken_ TxxToken;
struct TxxToken_ {
	slim_int fType;
	slim_int fCharSet;
	slim_split_ss fWhole;
};

/*
 * TTokenizer
 */
enum {
	SLIM_TKNZ_E_DETERMINED,
	SLIM_TKNZ_E_TOOSHORT,
	SLIM_TKNZ_E_INVAL,
	SLIM_TKNZ_E_NOMEM,
	SLIM_TKNZ_E_GENERIC,
	SLIM_TKNZ_E_YIELD, /* exceeds max stay time */
	SLIM_TKNZ_EXCEPTIONS
};
	
typedef struct TTokenizer_ TTokenizer;
typedef struct TTokenizerClass_ TTokenizerClass;

typedef TxxToken * (*Tokenizer_CurrentTokenProc)(TTokenizer *self);
typedef slim_int (*Tokenizer_ReadProc)(TTokenizer *self, TReaderInput *in_input);
typedef void (*Tokenizer_ResetTokenProc)(TTokenizer *self, slim_int in_charset);
typedef slim_bool (*Tokenizer_InitProc)(TTokenizer *self, TTokenizerClass *in_class);
typedef void (*Tokenizer_TidyProc)(TTokenizer *self);
struct TTokenizerClass_ {
	slim_int fObjectSize;
	Tokenizer_CurrentTokenProc fCurrentToken;
	Tokenizer_ReadProc fRead;
	Tokenizer_ResetTokenProc fResetToken;
	Tokenizer_InitProc fInit;
	Tokenizer_TidyProc fTidy;
};

struct TTokenizer_ {
	TTokenizerClass *fClass;
};

/*
 * TTokenHandler
 */
enum {
	SLIM_TKHNDL_E_OK,
	SLIM_TKHNDL_E_NOTFOUND,
	SLIM_TKHNDL_E_WOULDBLOCK,
	SLIM_TKHNDL_E_NOMEM,
	SLIM_TKHNDL_E_GENERIC,
	SLIM_TKHNDL_EXCEPTIONS
};

typedef struct TTokenHandler_ TTokenHandler;

typedef slim_int (*TokenHandler_HandleTokenProc)(TTokenHandler *self, TxxToken *in_token, slim_opaque in_user_data);
typedef struct TTokenHandlerClass_ TTokenHandlerClass;
struct TTokenHandlerClass_ {
	TokenHandler_HandleTokenProc fHandleToken;
};

struct TTokenHandler_ {
	TTokenHandlerClass *fClass;
};

/*
 * TReader
 */
enum {
	SLIM_READER_E_OK,
	SLIM_READER_E_WOULDBLOCK,
	SLIM_READER_E_EOF,
	SLIM_READER_E_NOMEM,
	SLIM_READER_E_GENERIC,
	SLIM_READER_E_IOSLEEP,
	SLIM_READER_EXCEPTIONS
};

typedef struct TReader_ TReader;
struct TReader_ {
	TTokenHandler *fHandler;
	TTokenizer *fTokenizer;
	slim_opaque fUserData; /* for handler */
};

/*
 * WriterBuffer
 */
typedef struct TWriterBuffer_ TWriterBuffer;
struct TWriterBuffer_ {
	slim_vhandle fBuffer;
	TElasticBuf fElasticBuf;
	TRingBuffer fRingBuf;
	slim_bool fHasEOF;
	slim_int fEncoding;
	slim_int fThresholdToFlush;
};

/*
 * WriterOutput (interface)
 */
typedef struct TWriterOutput_ TWriterOutput;
typedef slim_int (*WriterOutput_WriteProc)(slim_opaque in_ctx, slim_byte *in_buf, slim_int in_len, slim_int *out_written_len);
struct TWriterOutput_ {
	slim_opaque fUserData;
	WriterOutput_WriteProc fWrite;
};	

/*
 * TokenGenerator (interface)
 */
typedef struct TTokenGenerator_ TTokenGenerator;
typedef slim_int (*TokenGenerator_GenerateProc)(TTokenGenerator *self);
typedef slim_opaque (*TokenGenerator_LockUnlockTokenProc)(TTokenGenerator *self, slim_bool in_lock);

struct TTokenGenerator_ {
	slim_opaque fUserData;
	TokenGenerator_GenerateProc fGenerate;
	TokenGenerator_LockUnlockTokenProc fLockUnlockToken;
};

/*
 * TokenFormatter
 */
typedef struct TTokenFormatterClass_ TTokenFormatterClass;
typedef struct TTokenFormatter_ TTokenFormatter;
typedef slim_int (*TokenFormatter_FormatProc)(TTokenFormatter *self, slim_opaque in_token, TWriterBuffer *in_buffer);
typedef void (*TokenFormatter_TidyProc)(TTokenFormatter *self);

struct TTokenFormatterClass_ {
	TokenFormatter_FormatProc fFormat;
	TokenFormatter_TidyProc fTidy;
};

struct TTokenFormatter_ {
	TTokenFormatterClass *fClass;
};

/*
 * Writer
 */
typedef struct TWriter_ TWriter;
struct TWriter_ {
	slim_int fFlag;
	TTokenGenerator *fGenerator;
	TTokenFormatter *fFormatter;
	TWriterBuffer fBuffer;
};


/*
 * TParallelTokenizer
 */
typedef struct TTokenListItem_ TTokenListItem;
struct TTokenListItem_ {
	slim_int fTokenID;
	slim_int fPriority; 
	slim_offlen fToken;
};

typedef struct TTokenizerListItem_ TTokenizerListItem;
struct TTokenizerListItem_ {
	slim_int fType;
	slim_int fOffset;
	slim_int fPriority; 
	TTokenizer *fTokenizer;
};

typedef struct TParallelTokenizerClass_ TParallelTokenizerClass;
struct TParallelTokenizerClass_ {
	TTokenizerClass fBase;
	slim_int fDefaultTokenID;
	slim_int fMaxDeterminedTokens;
	slim_int fLimitLenIncrement;
};

typedef struct TParallelTokenizer_ TParallelTokenizer;
struct TParallelTokenizer_ {
	TTokenizer fBase;
	TTree fTree;
	slim_pix fTokenizerListRoot;
	slim_pix fPendingTokenListRoot;
	slim_pix fDeterminedTokenListRoot;
	slim_int fMaxStayEach;
	slim_int fMaxStayWhole;
	/* context */
	slim_int fState;
	slim_pix fNextPix;
	slim_int fNumOfTooShort;
	slim_int fMinOffset;
	slim_int fLimitLen;
};

SLIM_END_C_LINKAGE
#endif
