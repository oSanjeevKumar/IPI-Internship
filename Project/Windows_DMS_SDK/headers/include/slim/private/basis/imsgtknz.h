/*
	imsgtknz.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/basis/imsgtknz.h 23    05/12/28 12:08 Someya $ */

#ifndef SLIM_INETMESSAGE_TOKENIZER_H_PRIVATE
#define SLIM_INETMESSAGE_TOKENIZER_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

/* utilities */

#define SLIM_SPLRFCx822_STRICT_CRLF		0x00000001
#define SLIM_SPLRFCx822_STRICT_7BIT	0x00000002
#define SLIM_SPLRFCx822_MBOX_PTEXT		0x00000004
#define SLIM_SPLRFCx822_MBOX_DOMAIN_REQUIRED	0x00000008

/*
 * InetMsgTokenizer
 */

#define SLIM_SPLBTK_TYPE_ATOM	0x00000001
#define SLIM_SPLBTK_TYPE_CFWS	0x00000002
#define SLIM_SPLBTK_TYPE_QUOTED_STR	0x00000004
#define SLIM_SPLBTK_TYPE_DOMAIN_LIT	0x00000008
#define SLIM_SPLBTK_TYPE_UNSTRUCTURED	0x00000010
#define SLIM_SPLBTK_TYPE_PARAM_TOKEN	0x00000020

#define TInetMsgTokenizer_SetSplitFlag(self,flag) ((self)->fSplitFlag |= (flag))
#define TInetMsgTokenizer_ClearSplitFlag(self,flag) ((self)->fSplitFlag &= ~(flag))
#define TInetMsgTokenizer_Class(self) ((TInetMsgTokenizerClass *)(self)->fBase.fClass)
#define TInetMsgTokenizer_CurrentBoundary(self) ((self)->fCurrentBoundary)

#define InetMsgTokenizer_SplitRFCx822LocalPart(ss,eof,flag) InetMsgTokenizer_SplitRFCx822DottedToken((ss),(eof),(flag),SLIM_SPLBTK_TYPE_ATOM|SLIM_SPLBTK_TYPE_QUOTED_STR)
#define InetMsgTokenizer_SplitRFCx822Domain(ss,eof,flag) InetMsgTokenizer_SplitRFCx822DottedToken((ss),(eof),(flag),SLIM_SPLBTK_TYPE_ATOM|SLIM_SPLBTK_TYPE_DOMAIN_LIT)

/*
 * InetMsgFormatter
 */
#define SLIM_IMTKFMT_NO_VALIDATE	0x00000001

#define TInetMsgFormatter_SetFlag(self,flag) ((self)->fFlag |= (flag))
#define TInetMsgFormatter_ClearFlag(self,flag) ((self)->fFlag &= ~(flag))
#define TInetMsgFormatter_SetSplitFlag(self,flag) ((self)->fSplitFlag |= (flag))
#define TInetMsgFormatter_ClearSplitFlag(self,flag) ((self)->fSplitFlag &= ~(flag))

SLIM_END_C_LINKAGE
#endif /* SLIM_INETMESSAGE_TOKENIZER_H */
