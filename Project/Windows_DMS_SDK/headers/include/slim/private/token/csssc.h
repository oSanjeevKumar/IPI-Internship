/*
	csssc.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/token/csssc.h 20    05/12/28 12:08 Someya $ */

/* DO NOT EDIT! This file is generated automatically. */

#ifndef SLIM_TOKEN_CSSSC_H
#define SLIM_TOKEN_CSSSC_H

#include <slim/basis/base.h>
#include <slim/basis/token.h>
#include <slim/private/token/cssscid.h>

SLIM_BEGIN_C_LINKAGE

struct TCSSSysColorInfo_ {
	TToken fBase;	/* must be the first field */
	TColor fColor;
};
typedef struct TCSSSysColorInfo_ TCSSSysColorInfo;

#define SLIM_TKOFF_BASE_CSSSC0	(0)
#define SLIM_TKNAM_BASE_CSSSC0	((slim_char *)cSlim_TokenName_CSSSC)
#define SLIM_TKOFF_CSSSC_ActiveBorder	(SLIM_TKOFF_BASE_CSSSC0 + 0)
#define SLIM_TKNAM_CSSSC_ActiveBorder	(SLIM_TKNAM_BASE_CSSSC0 + 0)
#define SLIM_TKLEN_CSSSC_ActiveBorder	(12)
#define SLIM_TKOFF_CSSSC_ActiveCaption	(SLIM_TKOFF_BASE_CSSSC0 + 13)
#define SLIM_TKNAM_CSSSC_ActiveCaption	(SLIM_TKNAM_BASE_CSSSC0 + 13)
#define SLIM_TKLEN_CSSSC_ActiveCaption	(13)
#define SLIM_TKOFF_CSSSC_AppWorkspace	(SLIM_TKOFF_BASE_CSSSC0 + 27)
#define SLIM_TKNAM_CSSSC_AppWorkspace	(SLIM_TKNAM_BASE_CSSSC0 + 27)
#define SLIM_TKLEN_CSSSC_AppWorkspace	(12)
#define SLIM_TKOFF_CSSSC_Background	(SLIM_TKOFF_BASE_CSSSC0 + 40)
#define SLIM_TKNAM_CSSSC_Background	(SLIM_TKNAM_BASE_CSSSC0 + 40)
#define SLIM_TKLEN_CSSSC_Background	(10)
#define SLIM_TKOFF_CSSSC_ButtonFace	(SLIM_TKOFF_BASE_CSSSC0 + 51)
#define SLIM_TKNAM_CSSSC_ButtonFace	(SLIM_TKNAM_BASE_CSSSC0 + 51)
#define SLIM_TKLEN_CSSSC_ButtonFace	(10)
#define SLIM_TKOFF_CSSSC_ButtonHighlight	(SLIM_TKOFF_BASE_CSSSC0 + 62)
#define SLIM_TKNAM_CSSSC_ButtonHighlight	(SLIM_TKNAM_BASE_CSSSC0 + 62)
#define SLIM_TKLEN_CSSSC_ButtonHighlight	(15)
#define SLIM_TKOFF_CSSSC_ButtonShadow	(SLIM_TKOFF_BASE_CSSSC0 + 78)
#define SLIM_TKNAM_CSSSC_ButtonShadow	(SLIM_TKNAM_BASE_CSSSC0 + 78)
#define SLIM_TKLEN_CSSSC_ButtonShadow	(12)
#define SLIM_TKOFF_CSSSC_ButtonText	(SLIM_TKOFF_BASE_CSSSC0 + 91)
#define SLIM_TKNAM_CSSSC_ButtonText	(SLIM_TKNAM_BASE_CSSSC0 + 91)
#define SLIM_TKLEN_CSSSC_ButtonText	(10)
#define SLIM_TKOFF_CSSSC_CaptionText	(SLIM_TKOFF_BASE_CSSSC0 + 102)
#define SLIM_TKNAM_CSSSC_CaptionText	(SLIM_TKNAM_BASE_CSSSC0 + 102)
#define SLIM_TKLEN_CSSSC_CaptionText	(11)
#define SLIM_TKOFF_CSSSC_GrayText	(SLIM_TKOFF_BASE_CSSSC0 + 114)
#define SLIM_TKNAM_CSSSC_GrayText	(SLIM_TKNAM_BASE_CSSSC0 + 114)
#define SLIM_TKLEN_CSSSC_GrayText	(8)
#define SLIM_TKOFF_CSSSC_Highlight	(SLIM_TKOFF_BASE_CSSSC0 + 123)
#define SLIM_TKNAM_CSSSC_Highlight	(SLIM_TKNAM_BASE_CSSSC0 + 123)
#define SLIM_TKLEN_CSSSC_Highlight	(9)
#define SLIM_TKOFF_CSSSC_HighlightText	(SLIM_TKOFF_BASE_CSSSC0 + 133)
#define SLIM_TKNAM_CSSSC_HighlightText	(SLIM_TKNAM_BASE_CSSSC0 + 133)
#define SLIM_TKLEN_CSSSC_HighlightText	(13)
#define SLIM_TKOFF_CSSSC_InactiveBorder	(SLIM_TKOFF_BASE_CSSSC0 + 147)
#define SLIM_TKNAM_CSSSC_InactiveBorder	(SLIM_TKNAM_BASE_CSSSC0 + 147)
#define SLIM_TKLEN_CSSSC_InactiveBorder	(14)
#define SLIM_TKOFF_CSSSC_InactiveCaption	(SLIM_TKOFF_BASE_CSSSC0 + 162)
#define SLIM_TKNAM_CSSSC_InactiveCaption	(SLIM_TKNAM_BASE_CSSSC0 + 162)
#define SLIM_TKLEN_CSSSC_InactiveCaption	(15)
#define SLIM_TKOFF_CSSSC_InactiveCaptionText	(SLIM_TKOFF_BASE_CSSSC0 + 178)
#define SLIM_TKNAM_CSSSC_InactiveCaptionText	(SLIM_TKNAM_BASE_CSSSC0 + 178)
#define SLIM_TKLEN_CSSSC_InactiveCaptionText	(19)
#define SLIM_TKOFF_CSSSC_InfoBackground	(SLIM_TKOFF_BASE_CSSSC0 + 198)
#define SLIM_TKNAM_CSSSC_InfoBackground	(SLIM_TKNAM_BASE_CSSSC0 + 198)
#define SLIM_TKLEN_CSSSC_InfoBackground	(14)
#define SLIM_TKOFF_CSSSC_InfoText	(SLIM_TKOFF_BASE_CSSSC0 + 213)
#define SLIM_TKNAM_CSSSC_InfoText	(SLIM_TKNAM_BASE_CSSSC0 + 213)
#define SLIM_TKLEN_CSSSC_InfoText	(8)
#define SLIM_TKOFF_CSSSC_Menu	(SLIM_TKOFF_BASE_CSSSC0 + 222)
#define SLIM_TKNAM_CSSSC_Menu	(SLIM_TKNAM_BASE_CSSSC0 + 222)
#define SLIM_TKLEN_CSSSC_Menu	(4)
#define SLIM_TKOFF_CSSSC_MenuText	(SLIM_TKOFF_BASE_CSSSC0 + 227)
#define SLIM_TKNAM_CSSSC_MenuText	(SLIM_TKNAM_BASE_CSSSC0 + 227)
#define SLIM_TKLEN_CSSSC_MenuText	(8)
#define SLIM_TKOFF_CSSSC_Scrollbar	(SLIM_TKOFF_BASE_CSSSC0 + 236)
#define SLIM_TKNAM_CSSSC_Scrollbar	(SLIM_TKNAM_BASE_CSSSC0 + 236)
#define SLIM_TKLEN_CSSSC_Scrollbar	(9)
#define SLIM_TKOFF_CSSSC_ThreeDDarkShadow	(SLIM_TKOFF_BASE_CSSSC0 + 246)
#define SLIM_TKNAM_CSSSC_ThreeDDarkShadow	(SLIM_TKNAM_BASE_CSSSC0 + 246)
#define SLIM_TKLEN_CSSSC_ThreeDDarkShadow	(16)
#define SLIM_TKOFF_CSSSC_ThreeDFace	(SLIM_TKOFF_BASE_CSSSC0 + 263)
#define SLIM_TKNAM_CSSSC_ThreeDFace	(SLIM_TKNAM_BASE_CSSSC0 + 263)
#define SLIM_TKLEN_CSSSC_ThreeDFace	(10)
#define SLIM_TKOFF_CSSSC_ThreeDHighlight	(SLIM_TKOFF_BASE_CSSSC0 + 274)
#define SLIM_TKNAM_CSSSC_ThreeDHighlight	(SLIM_TKNAM_BASE_CSSSC0 + 274)
#define SLIM_TKLEN_CSSSC_ThreeDHighlight	(15)
#define SLIM_TKOFF_CSSSC_ThreeDLightShadow	(SLIM_TKOFF_BASE_CSSSC0 + 290)
#define SLIM_TKNAM_CSSSC_ThreeDLightShadow	(SLIM_TKNAM_BASE_CSSSC0 + 290)
#define SLIM_TKLEN_CSSSC_ThreeDLightShadow	(17)
#define SLIM_TKOFF_CSSSC_ThreeDShadow	(SLIM_TKOFF_BASE_CSSSC0 + 308)
#define SLIM_TKNAM_CSSSC_ThreeDShadow	(SLIM_TKNAM_BASE_CSSSC0 + 308)
#define SLIM_TKLEN_CSSSC_ThreeDShadow	(12)
#define SLIM_TKOFF_CSSSC_Window	(SLIM_TKOFF_BASE_CSSSC0 + 321)
#define SLIM_TKNAM_CSSSC_Window	(SLIM_TKNAM_BASE_CSSSC0 + 321)
#define SLIM_TKLEN_CSSSC_Window	(6)
#define SLIM_TKOFF_CSSSC_WindowFrame	(SLIM_TKOFF_BASE_CSSSC0 + 328)
#define SLIM_TKNAM_CSSSC_WindowFrame	(SLIM_TKNAM_BASE_CSSSC0 + 328)
#define SLIM_TKLEN_CSSSC_WindowFrame	(11)
#define SLIM_TKOFF_CSSSC_WindowText	(SLIM_TKOFF_BASE_CSSSC0 + 340)
#define SLIM_TKNAM_CSSSC_WindowText	(SLIM_TKNAM_BASE_CSSSC0 + 340)
#define SLIM_TKLEN_CSSSC_WindowText	(10)
#define SLIM_TKOFF_BASE_CSSSC1	(SLIM_TKOFF_BASE_CSSSC0 + 351)
#define SLIM_TKNAM_BASE_CSSSC1	(SLIM_TKNAM_BASE_CSSSC0 + SLIM_TKOFF_BASE_CSSSC1)
#define SLIM_TKLEN_TOTAL_CSSSC	SLIM_TKOFF_BASE_CSSSC1

extern SLIM_ROM slim_char cSlim_TokenName_CSSSC[SLIM_TKLEN_TOTAL_CSSSC];

extern SLIM_ROM TCSSSysColorInfo cSlim_Token_CSSSC[SLIM_TOKEN_CSSSC_TOKENS];
#define CSSSysColorInfo_GetItem(id)		((TCSSSysColorInfo *)&cSlim_Token_CSSSC[(id)])
#define CSSSysColorInfo_GetItemName(id)	((slim_char *)cSlim_TokenName_CSSSC + ((TToken *)&cSlim_Token_CSSSC[(id)])->fOffset)
#define CSSSysColorInfo_GetItemNameLen(id)	(((TToken *)&cSlim_Token_CSSSC[(id)])->fLength)

TCSSSysColorInfo *CSSSysColorInfo_FindSS(slim_char *in_s, slim_int in_slen);

SLIM_END_C_LINKAGE
#endif
