/*
	cdatafmt.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/basis/cdatafmt.h 22    06/06/19 15:04 Siu $ */

#ifndef SLIM_CDATA_FORMATTER_H
#define SLIM_CDATA_FORMATTER_H

SLIM_BEGIN_C_LINKAGE


#define SLIM_CDATAFORMAT_FLAG_AsWindows1252	0x00000001
#define SLIM_CDATAFORMAT_FLAG_AllowNull	0x00000002
#define SLIM_CDATAFORMAT_FLAG_StrictSemicolon	0x00000004
#define SLIM_CDATAFORMAT_FLAG_WhiteToSpace	0x00000008 /* \x09, \x0D, \x0A, \x20 are "white" */
#define SLIM_CDATAFORMAT_FLAG_CtrlToSpace	0x00000010 /* except \x09, \x0D, \x0A */
#define SLIM_CDATAFORMAT_FLAG_NBSPToSpace	0x00000020
#define SLIM_CDATAFORMAT_FLAG_SqueezeWhite	0x00000040
#define SLIM_CDATAFORMAT_FLAG_PreserveTab	0x00000080
#define SLIM_CDATAFORMAT_FLAG_PreserveNBSP	0x00000100
#define SLIM_CDATAFORMAT_FLAG_AsXML	0x00000200
#define SLIM_CDATAFORMAT_FLAG_AsHTML	0x00000400
#define SLIM_CDATAFORMAT_FLAG_PermitInvalidRef	0x00000800

#define SLIM_CDATAFORMAT_MASK_MODIFYSPACE ( \
	SLIM_CDATAFORMAT_FLAG_WhiteToSpace |\
	SLIM_CDATAFORMAT_FLAG_CtrlToSpace |\
	SLIM_CDATAFORMAT_FLAG_SqueezeWhite \
)

enum {
	SLIM_CDATAFMT_CASE_GENERIC = 0,
	SLIM_CDATAFMT_CASE_PRESERVE, /* xml:space = "preserve" */
	SLIM_CDATAFMT_CASE_INPUTTEXT,
	SLIM_CDATAFMT_CASE_INPUTVALUE,
	SLIM_CDATAFMT_CASE_INPUTNAME,
	SLIM_CDATAFMT_CASE_IMGALT,
	SLIM_CDATAFMT_CASE_ID,
	SLIM_CDATAFMT_CASE_URL,
	SLIM_CDATAFMT_CASE_STYLE, /* style tag */
	SLIM_CDATAFMT_CASE_SCRIPT, /* script tag */
	SLIM_CDATAFMT_CASE_TEMP, /* temporary */
	SLIM_CDATAFMT_CASEs
};

typedef struct TCDATAFormatter_ TCDATAFormatter;

typedef slim_int (*CDATAFormatter_ResolveReferenceProc)(TCDATAFormatter *self, slim_char *out_buf, slim_char *in_s, slim_int in_len, slim_bool in_has_semicolon, slim_int in_to_chset, slim_int in_mode);
typedef slim_bool (*CDATAFormatter_ParseReferenceProc)(TCDATAFormatter *self, slim_char *in_s, slim_int in_len, slim_bool in_has_semicolon, slim_int *out_code, slim_int in_mode);
typedef slim_bool (*CDATAFormatter_SubstituteUnicodeProc)(slim_int in_code, slim_int in_dest_charset, slim_char **out_s, slim_int *out_len);

typedef struct TCDATAFormatterClass_ TCDATAFormatterClass;
struct TCDATAFormatterClass_ {
	TI18NConverterClass *fConvClass;
	slim_int fDefaultFlags[SLIM_CDATAFMT_CASEs];
	CDATAFormatter_SubstituteUnicodeProc fSubstituteUnicode;
};

struct TCDATAFormatter_ {
	TCDATAFormatterClass *fClass;
	slim_int fFlags[SLIM_CDATAFMT_CASEs];
	CDATAFormatter_ParseReferenceProc fParseReference;
	CDATAFormatter_ResolveReferenceProc fResolveReference;
	slim_bool fLastCharIsSpace;
	slim_opaque fUserData;
};

SLIM_END_C_LINKAGE
#endif
