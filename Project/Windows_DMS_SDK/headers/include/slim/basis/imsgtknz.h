/*
	imsgtknz.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/basis/imsgtknz.h 13    05/12/28 12:07 Someya $ */

#ifndef SLIM_INETMESSAGE_TOKENIZER_H
#define SLIM_INETMESSAGE_TOKENIZER_H

SLIM_BEGIN_C_LINKAGE

/*
 * InetMsgTokenizer
 */
/* for splitting */
#define SLIM_IMTKNZ_SS_ARRAY_MAX	3

enum {
	SLIM_MIMEMSGTKN_TYPE_FIELD = 0,
	SLIM_MIMEMSGTKN_TYPE_LAST_FIELD,
	SLIM_MIMEMSGTKN_TYPE_PREAMBLE,
	SLIM_MIMEMSGTKN_TYPE_DELIMITER,
	SLIM_MIMEMSGTKN_TYPE_BODY,
	SLIM_MIMEMSGTKN_TYPE_CLOSE_DELIMITER,
	SLIM_MIMEMSGTKN_TYPE_EPILOGUE,
	SLIM_MIMEMSGTKN_TYPEs
};

typedef struct TInetMsgToken_ TInetMsgToken;
struct TInetMsgToken_ {
	TxxToken fBase;
	union {
		struct {
			slim_split_ss fName;
			slim_split_ss fBody;
		}Field;
		slim_split_ss Boundary;
	}u;
};

typedef struct TInetMsgTokenizer_ TInetMsgTokenizer;

typedef slim_bool (*InetMsgTokenizer_FindBoundaryProc)(TInetMsgTokenizer *self, slim_split_ss *inout_ss, slim_split_ss *out_boundary);

typedef struct TInetMsgTokenizerClass_ TInetMsgTokenizerClass;
struct TInetMsgTokenizerClass_ {
	TTokenizerClass fBase;
	slim_int fDefaultSplitFlag;
	InetMsgTokenizer_FindBoundaryProc fFindBoundary;
};

#define SLIM_IMTKNZBSTACK_RESERVED_SIZE	4
typedef struct TInetMsgTknzBStack_ TInetMsgTknzBStack;
struct TInetMsgTknzBStack_ {
	slim_short fSize;
	slim_short fDepth;
	TFixedString fStack[SLIM_IMTKNZBSTACK_RESERVED_SIZE];
	TFixedString *fExtraStack;
};

struct TInetMsgTokenizer_ {
	TTokenizer fBase;
	slim_int fSplitFlag;
	slim_int fState;
	TFixedString fCurrentBoundary;
	TInetMsgToken fToken;
	TInetMsgTknzBStack fBoundaryStack;
};

/*
 * InetMsgFormatter
 */

typedef struct TInetMsgFormatterClass_ TInetMsgFormatterClass;
typedef struct TInetMsgFormatter_ TInetMsgFormatter;

struct TInetMsgFormatterClass_ {
	TTokenFormatterClass fBase;
	slim_int fDefaultFlag;
	slim_int fDefaultSplitFlag;
};

struct TInetMsgFormatter_ {
	TTokenFormatter fBase;
	slim_int fFlag;
	slim_int fSplitFlag;
	slim_int fOffset;
	slim_int fLastTokenType;
};


SLIM_END_C_LINKAGE
#endif /* SLIM_INETMESSAGE_TOKENIZER_H */
