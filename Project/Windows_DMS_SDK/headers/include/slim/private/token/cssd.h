/*
	cssd.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/token/cssd.h 20    05/12/28 12:08 Someya $ */

/* DO NOT EDIT! This file is generated automatically. */

#ifndef SLIM_TOKEN_CSSD_H
#define SLIM_TOKEN_CSSD_H

#include <slim/basis/base.h>
#include <slim/basis/token.h>
#include <slim/private/token/cssdid.h>

SLIM_BEGIN_C_LINKAGE

struct TCSSDescriptorInfo_ {
	TToken fBase;	/* must be the first field */
};
typedef struct TCSSDescriptorInfo_ TCSSDescriptorInfo;

#define SLIM_TKOFF_BASE_CSSD0	(0)
#define SLIM_TKNAM_BASE_CSSD0	((slim_char *)cSlim_TokenName_CSSD)
#define SLIM_TKOFF_CSSD_ascent	(SLIM_TKOFF_BASE_CSSD0 + 0)
#define SLIM_TKNAM_CSSD_ascent	(SLIM_TKNAM_BASE_CSSD0 + 0)
#define SLIM_TKLEN_CSSD_ascent	(6)
#define SLIM_TKOFF_CSSD_baseline	(SLIM_TKOFF_BASE_CSSD0 + 7)
#define SLIM_TKNAM_CSSD_baseline	(SLIM_TKNAM_BASE_CSSD0 + 7)
#define SLIM_TKLEN_CSSD_baseline	(8)
#define SLIM_TKOFF_CSSD_bbox	(SLIM_TKOFF_BASE_CSSD0 + 16)
#define SLIM_TKNAM_CSSD_bbox	(SLIM_TKNAM_BASE_CSSD0 + 16)
#define SLIM_TKLEN_CSSD_bbox	(4)
#define SLIM_TKOFF_CSSD_cap_height	(SLIM_TKOFF_BASE_CSSD0 + 21)
#define SLIM_TKNAM_CSSD_cap_height	(SLIM_TKNAM_BASE_CSSD0 + 21)
#define SLIM_TKLEN_CSSD_cap_height	(10)
#define SLIM_TKOFF_CSSD_centerline	(SLIM_TKOFF_BASE_CSSD0 + 32)
#define SLIM_TKNAM_CSSD_centerline	(SLIM_TKNAM_BASE_CSSD0 + 32)
#define SLIM_TKLEN_CSSD_centerline	(10)
#define SLIM_TKOFF_CSSD_definition_src	(SLIM_TKOFF_BASE_CSSD0 + 43)
#define SLIM_TKNAM_CSSD_definition_src	(SLIM_TKNAM_BASE_CSSD0 + 43)
#define SLIM_TKLEN_CSSD_definition_src	(14)
#define SLIM_TKOFF_CSSD_descent	(SLIM_TKOFF_BASE_CSSD0 + 58)
#define SLIM_TKNAM_CSSD_descent	(SLIM_TKNAM_BASE_CSSD0 + 58)
#define SLIM_TKLEN_CSSD_descent	(7)
#define SLIM_TKOFF_CSSD_font_family	(SLIM_TKOFF_BASE_CSSD0 + 66)
#define SLIM_TKNAM_CSSD_font_family	(SLIM_TKNAM_BASE_CSSD0 + 66)
#define SLIM_TKLEN_CSSD_font_family	(11)
#define SLIM_TKOFF_CSSD_font_size	(SLIM_TKOFF_BASE_CSSD0 + 78)
#define SLIM_TKNAM_CSSD_font_size	(SLIM_TKNAM_BASE_CSSD0 + 78)
#define SLIM_TKLEN_CSSD_font_size	(9)
#define SLIM_TKOFF_CSSD_font_stretch	(SLIM_TKOFF_BASE_CSSD0 + 88)
#define SLIM_TKNAM_CSSD_font_stretch	(SLIM_TKNAM_BASE_CSSD0 + 88)
#define SLIM_TKLEN_CSSD_font_stretch	(12)
#define SLIM_TKOFF_CSSD_font_style	(SLIM_TKOFF_BASE_CSSD0 + 101)
#define SLIM_TKNAM_CSSD_font_style	(SLIM_TKNAM_BASE_CSSD0 + 101)
#define SLIM_TKLEN_CSSD_font_style	(10)
#define SLIM_TKOFF_CSSD_font_variant	(SLIM_TKOFF_BASE_CSSD0 + 112)
#define SLIM_TKNAM_CSSD_font_variant	(SLIM_TKNAM_BASE_CSSD0 + 112)
#define SLIM_TKLEN_CSSD_font_variant	(12)
#define SLIM_TKOFF_CSSD_font_weight	(SLIM_TKOFF_BASE_CSSD0 + 125)
#define SLIM_TKNAM_CSSD_font_weight	(SLIM_TKNAM_BASE_CSSD0 + 125)
#define SLIM_TKLEN_CSSD_font_weight	(11)
#define SLIM_TKOFF_CSSD_mathline	(SLIM_TKOFF_BASE_CSSD0 + 137)
#define SLIM_TKNAM_CSSD_mathline	(SLIM_TKNAM_BASE_CSSD0 + 137)
#define SLIM_TKLEN_CSSD_mathline	(8)
#define SLIM_TKOFF_CSSD_panose_1	(SLIM_TKOFF_BASE_CSSD0 + 146)
#define SLIM_TKNAM_CSSD_panose_1	(SLIM_TKNAM_BASE_CSSD0 + 146)
#define SLIM_TKLEN_CSSD_panose_1	(8)
#define SLIM_TKOFF_CSSD_slope	(SLIM_TKOFF_BASE_CSSD0 + 155)
#define SLIM_TKNAM_CSSD_slope	(SLIM_TKNAM_BASE_CSSD0 + 155)
#define SLIM_TKLEN_CSSD_slope	(5)
#define SLIM_TKOFF_CSSD_src	(SLIM_TKOFF_BASE_CSSD0 + 161)
#define SLIM_TKNAM_CSSD_src	(SLIM_TKNAM_BASE_CSSD0 + 161)
#define SLIM_TKLEN_CSSD_src	(3)
#define SLIM_TKOFF_CSSD_stemh	(SLIM_TKOFF_BASE_CSSD0 + 165)
#define SLIM_TKNAM_CSSD_stemh	(SLIM_TKNAM_BASE_CSSD0 + 165)
#define SLIM_TKLEN_CSSD_stemh	(5)
#define SLIM_TKOFF_CSSD_stemv	(SLIM_TKOFF_BASE_CSSD0 + 171)
#define SLIM_TKNAM_CSSD_stemv	(SLIM_TKNAM_BASE_CSSD0 + 171)
#define SLIM_TKLEN_CSSD_stemv	(5)
#define SLIM_TKOFF_CSSD_topline	(SLIM_TKOFF_BASE_CSSD0 + 177)
#define SLIM_TKNAM_CSSD_topline	(SLIM_TKNAM_BASE_CSSD0 + 177)
#define SLIM_TKLEN_CSSD_topline	(7)
#define SLIM_TKOFF_CSSD_unicode_range	(SLIM_TKOFF_BASE_CSSD0 + 185)
#define SLIM_TKNAM_CSSD_unicode_range	(SLIM_TKNAM_BASE_CSSD0 + 185)
#define SLIM_TKLEN_CSSD_unicode_range	(13)
#define SLIM_TKOFF_CSSD_units_per_em	(SLIM_TKOFF_BASE_CSSD0 + 199)
#define SLIM_TKNAM_CSSD_units_per_em	(SLIM_TKNAM_BASE_CSSD0 + 199)
#define SLIM_TKLEN_CSSD_units_per_em	(12)
#define SLIM_TKOFF_CSSD_widths	(SLIM_TKOFF_BASE_CSSD0 + 212)
#define SLIM_TKNAM_CSSD_widths	(SLIM_TKNAM_BASE_CSSD0 + 212)
#define SLIM_TKLEN_CSSD_widths	(6)
#define SLIM_TKOFF_CSSD_x_height	(SLIM_TKOFF_BASE_CSSD0 + 219)
#define SLIM_TKNAM_CSSD_x_height	(SLIM_TKNAM_BASE_CSSD0 + 219)
#define SLIM_TKLEN_CSSD_x_height	(8)
#define SLIM_TKOFF_BASE_CSSD1	(SLIM_TKOFF_BASE_CSSD0 + 228)
#define SLIM_TKNAM_BASE_CSSD1	(SLIM_TKNAM_BASE_CSSD0 + SLIM_TKOFF_BASE_CSSD1)
#define SLIM_TKLEN_TOTAL_CSSD	SLIM_TKOFF_BASE_CSSD1

extern SLIM_ROM slim_char cSlim_TokenName_CSSD[SLIM_TKLEN_TOTAL_CSSD];

extern SLIM_ROM TCSSDescriptorInfo cSlim_Token_CSSD[SLIM_TOKEN_CSSD_TOKENS];
#define CSSDescriptorInfo_GetItem(id)		((TCSSDescriptorInfo *)&cSlim_Token_CSSD[(id)])
#define CSSDescriptorInfo_GetItemName(id)	((slim_char *)cSlim_TokenName_CSSD + ((TToken *)&cSlim_Token_CSSD[(id)])->fOffset)
#define CSSDescriptorInfo_GetItemNameLen(id)	(((TToken *)&cSlim_Token_CSSD[(id)])->fLength)

TCSSDescriptorInfo *CSSDescriptorInfo_FindSS(slim_char *in_s, slim_int in_slen);

SLIM_END_C_LINKAGE
#endif
