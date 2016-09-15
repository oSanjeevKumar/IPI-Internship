/*
	xxmltknz.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/basis/xxmltknz.h 25    05/12/28 12:08 Someya $ */


#ifndef SLIM_XXML_TOKENIZER_H_PRIVATE
#define SLIM_XXML_TOKENIZER_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

/* xxMLToken */

/* xxMLTokenizer */
#define SLIM_xxMLTKNZ_FLAG_AS_HTML	0x00000001
#define SLIM_xxMLTKNZ_FLAG_AS_XML	0x00000002
#define SLIM_xxMLTKNZ_FLAG_STRICT	0x00000004
#define SLIM_xxMLTKNZ_FLAG_MODE_PTEXT	0x00000008
#define SLIM_xxMLTKNZ_FLAG_MODE_CDATA	0x00000010
#define SLIM_xxMLTKNZ_FLAG_MODE_SCRIPT	0x00000020
#define SLIM_xxMLTKNZ_FLAG_MODE_NORMAL	SLIM_FLAG_NONE
#define SLIM_xxMLTKNZ_FLAG_IGNORE_INVALID_PI	0x00000040
#define SLIM_xxMLTKNZ_FLAG_IGNORE_INVALID_TAG	0x00000080
#define SLIM_xxMLTKNZ_FLAG_IGNORE_INVALID_CDSECT	0x00000100
#define SLIM_xxMLTKNZ_FLAG_IGNORE_INVALID_COMMENT	0x00000200
#define SLIM_xxMLTKNZ_FLAG_IGNORE_INVALID_DTD	0x00000400
#define SLIM_xxMLTKNZ_FLAG_IGNORE_INVALID_REF	0x00000800
#define SLIM_xxMLTKNZ_FLAG_ERR_XML_GRAMMER	0x00001000

#define SLIM_xxMLTKNZ_MASK_MODE ( SLIM_xxMLTKNZ_FLAG_MODE_PTEXT | SLIM_xxMLTKNZ_FLAG_MODE_CDATA | SLIM_xxMLTKNZ_FLAG_MODE_SCRIPT )
#define SLIM_xxMLTKNZ_MASK_ERR ( SLIM_xxMLTKNZ_FLAG_ERR_XML_GRAMMER )
#define SLIM_xxMLTKNZ_MASK_IGNORE_INVALID (SLIM_xxMLTKNZ_FLAG_IGNORE_INVALID_TAG|SLIM_xxMLTKNZ_FLAG_IGNORE_INVALID_CDSECT|SLIM_xxMLTKNZ_FLAG_IGNORE_INVALID_COMMENT|SLIM_xxMLTKNZ_FLAG_IGNORE_INVALID_DTD|SLIM_xxMLTKNZ_FLAG_IGNORE_INVALID_REF|SLIM_xxMLTKNZ_FLAG_IGNORE_INVALID_PI)

#define xxMLTokenizer_CheckFlag(flag, mask) (((flag) & (mask)) != SLIM_FLAG_NONE)
#define xxMLTokenizer_AsHTML(flag) ((flag) & SLIM_xxMLTKNZ_FLAG_AS_HTML)
#define xxMLTokenizer_AsXML(flag) ((flag) & SLIM_xxMLTKNZ_FLAG_AS_XML)
#define xxMLTokenizer_IsStrict(flag) (!xxMLTokenizer_AsHTML(flag) && ((flag) & SLIM_xxMLTKNZ_FLAG_STRICT))

#define xxMLTokenizer_PlaintextMode(flag) (xxMLTokenizer_AsHTML(flag) && ((flag) & SLIM_xxMLTKNZ_FLAG_MODE_PTEXT))
#define xxMLTokenizer_CDATAMode(flag) (xxMLTokenizer_AsHTML(flag) && ((flag) & SLIM_xxMLTKNZ_FLAG_MODE_CDATA))
#define xxMLTokenizer_ScriptMode(flag) (xxMLTokenizer_AsHTML(flag) && ((flag) & SLIM_xxMLTKNZ_FLAG_MODE_SCRIPT))
#define xxMLTokenizer_NormalMode(flag) (!xxMLTokenizer_AsHTML(flag) || ((flag) & SLIM_xxMLTKNZ_MASK_MODE) == 0)

#define xxMLTokenizer_Error(flag) ((flag) & SLIM_xxMLTKNZ_MASK_ERR)
#define xxMLTokenizer_SetError(flag, err) ((flag) = ((flag) & ~SLIM_xxMLTKNZ_MASK_ERR) | (err))

#define xxMLTokenizer_SetDefaultFlag(cls, flag) ((cls)->fDefaultFlag |= (flag))
#define xxMLTokenizer_ClearDefaultFlag(cls, flag) ((cls)->fDefaultFlag &= ~(flag))
#define xxMLTokenizer_DefaultFlag(cls) ((cls)->fDefaultFlag)

#define TxxMLTokenizer_ClearFlag(self, flag) ((self)->fFlag &= ~(flag))
#define TxxMLTokenizer_SetFlag(self, flag) ((self)->fFlag |= (flag))

#define TxxMLTokenizer_SetMode(self, mode) ((self)->fFlag = ((self)->fFlag & ~SLIM_xxMLTKNZ_MASK_MODE) | (mode))
#define TxxMLTokenizer_Mode(self) ((self)->fFlag & SLIM_xxMLTKNZ_MASK_MODE)




/* HTMLTokenizer */
#define SLIM_HTMLTKNZ_MODE_PTEXT	SLIM_xxMLTKNZ_FLAG_MODE_PTEXT
#define SLIM_HTMLTKNZ_MODE_CDATA	SLIM_xxMLTKNZ_FLAG_MODE_CDATA
#define SLIM_HTMLTKNZ_MODE_SCRIPT	SLIM_xxMLTKNZ_FLAG_MODE_SCRIPT
#define SLIM_HTMLTKNZ_MODE_NORMAL	SLIM_xxMLTKNZ_FLAG_MODE_NORMAL

#define HTMLTokenizer_ClearDefaultFlag(cls, flag) xxMLTokenizer_ClearDefaultFlag(&(cls)->fBase,(flag))
#define HTMLTokenizer_SetDefaultFlag(cls, flag) xxMLTokenizer_SetDefaultFlag(&(cls)->fBase,(flag))

#define THTMLTokenizer_SetMode(self, mode) TxxMLTokenizer_SetMode(&(self)->fBase, (mode))
#define THTMLTokenizer_Mode(self) TxxMLTokenizer_Mode(&(self)->fBase)
#define THTMLTokenizer_SetFlag(self, flag) TxxMLTokenizer_SetFlag(&(self)->fBase, (flag))
#define THTMLTokenizer_Flag(self) TxxMLTokenizer_Flag(&(self)->fBase)

#define THTMLTokenizer_AutomaticModeControl(self, b) ((self)->fModeControl = (b))


/* XMLTokenizer */

#define TXMLTokenizer_HasError(self) (xxMLTokenizer_Error((self)->fBase.fFlag) != SLIM_FLAG_NONE)
#define TXMLTokenizer_GetErrorCode(self) ((self)->fBase.fErrorCode)


SLIM_END_C_LINKAGE

#endif
