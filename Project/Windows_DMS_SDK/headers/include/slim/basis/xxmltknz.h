/*
	xxmltknz.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/basis/xxmltknz.h 24    05/12/28 12:07 Someya $ */


#ifndef SLIM_XXML_TOKENIZER_H
#define SLIM_XXML_TOKENIZER_H

SLIM_BEGIN_C_LINKAGE

/* xxMLToken */
enum {
	SLIM_xxMLTOKEN_TYPE_Unknown = SLIM_XXTOKEN_TYPE_UNKNOWN,
	SLIM_xxMLTOKEN_TYPE_StartTag = 0,
	SLIM_xxMLTOKEN_TYPE_EndTag,
	SLIM_xxMLTOKEN_TYPE_EmptyTag,
	SLIM_xxMLTOKEN_TYPE_Text,
	SLIM_xxMLTOKEN_TYPE_Reference,
	SLIM_xxMLTOKEN_TYPE_PI,
	SLIM_xxMLTOKEN_TYPE_Comment,
	SLIM_xxMLTOKEN_TYPE_CDSect,
	SLIM_xxMLTOKEN_TYPE_DTD
};

typedef struct TxxMLToken_ TxxMLToken;
struct TxxMLToken_ {
	TxxToken fBase;
	union {
		struct {
			slim_split_ss fName;
			slim_split_ss fAttrs;
		}Tag;
		struct {
			slim_split_ss fTarget;
			slim_split_ss fData;
		}PI;
		struct {
			slim_split_ss fName;
			slim_split_ss fPublic;
			slim_split_ss fSystem;
			slim_split_ss fMarkupDecl;
		}DTD;
		slim_split_ss Comment;
		slim_split_ss CDSect;
		slim_split_ss Ref;
		slim_split_ss Text;
	}u;
};

typedef struct TxxMLTokenizerClass_ TxxMLTokenizerClass;
struct TxxMLTokenizerClass_ {
	TTokenizerClass fBase;
	slim_int fDefaultFlag;
};

typedef struct TxxMLTokenizer_ TxxMLTokenizer;
struct TxxMLTokenizer_ {
	TTokenizer fBase;
	slim_int fFlag;
	slim_int fErrorCode;
	TxxMLToken fCurrentToken;
};

/*
 * HTML
 */
typedef struct THTMLTokenizerClass_ THTMLTokenizerClass;
struct THTMLTokenizerClass_ {
	TxxMLTokenizerClass fBase;
};

typedef struct THTMLTokenizer_ THTMLTokenizer;
struct THTMLTokenizer_ {
	TxxMLTokenizer fBase;
	slim_char *fModeTerminator; /* CS */
	slim_bool fModeControl;
};

/*
 * XML
 */
typedef struct TXMLTokenizerClass_ TXMLTokenizerClass;
struct TXMLTokenizerClass_ {
	TxxMLTokenizerClass fBase;
};

typedef struct TXMLTokenizer_ TXMLTokenizer;
struct TXMLTokenizer_ {
	TxxMLTokenizer fBase;
};

/* API */

SLIM_END_C_LINKAGE

#endif
