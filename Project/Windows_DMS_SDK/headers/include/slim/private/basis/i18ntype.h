/*
	i18ntype.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/basis/i18ntype.h 19    05/12/28 12:08 Someya $ */

/* DO NOT EDIT! This file is generated automagically. */
	
#ifndef SLIM_I18NTYPE_H
#define SLIM_I18NTYPE_H

#ifndef SLIM_BASE_H
#include <slim/basis/base.h>
#endif

SLIM_BEGIN_C_LINKAGE

#define SLIM_I18N_CTYPE_iso2022_gl 0x00000001
#define SLIM_I18N_CTYPE_iso2022_gr94 0x00000002
#define SLIM_I18N_CTYPE_iso2022_gr96 0x00000004
#define SLIM_I18N_CTYPE_iso2022_cr 0x00000008
#define SLIM_I18N_CTYPE_en_ascii_ctrl 0x00000010
#define SLIM_I18N_CTYPE_ja_sjis_kana 0x00000020
#define SLIM_I18N_CTYPE_ja_sjis_kanji_1st 0x00000040
#define SLIM_I18N_CTYPE_ja_sjis_kanji_2nd 0x00000080
#define SLIM_I18N_CTYPE_ja_euc_kana_1st 0x00000100
#define SLIM_I18N_CTYPE_ja_euc_kana_2nd 0x00000200
#define SLIM_I18N_CTYPE_ja_euc_x0212_1st 0x00000400
#define SLIM_I18N_CTYPE_zh_gbk_1st 0x00000800
#define SLIM_I18N_CTYPE_zh_gbk_2nd 0x00001000
#define SLIM_I18N_CTYPE_zh_big5_2nd 0x00002000
#define SLIM_I18N_CTYPE_ucs_utf8_2_1st 0x00004000
#define SLIM_I18N_CTYPE_ucs_utf8_2nd 0x00008000
#define SLIM_I18N_CTYPE_ucs_utf8_3_1st 0x00010000
#define SLIM_I18N_CTYPE_ucs_utf8_4_1st 0x00020000
#define SLIM_I18N_CTYPE_ucs_utf8_5_1st 0x00040000
#define SLIM_I18N_CTYPE_ucs_utf8_6_1st 0x00080000
#define SLIM_I18N_CTYPE_ucs_utf16_1st 0x00100000
#define SLIM_I18N_CTYPE_ucs_utf16_2nd 0x00200000

#define SLIM_I18N_CTYPE_iso646 (SLIM_I18N_CTYPE_iso2022_gl)
#define SLIM_I18N_CTYPE_en_us_ascii (SLIM_I18N_CTYPE_iso646|SLIM_I18N_CTYPE_en_ascii_ctrl)
#define SLIM_I18N_CTYPE_iso8859_x_cr (SLIM_I18N_CTYPE_iso2022_cr)
#define SLIM_I18N_CTYPE_iso8859_x_gr (SLIM_I18N_CTYPE_iso2022_gr96)
#define SLIM_I18N_CTYPE_iso8859 (SLIM_I18N_CTYPE_en_us_ascii|SLIM_I18N_CTYPE_iso8859_x_cr|SLIM_I18N_CTYPE_iso8859_x_gr)
#define SLIM_I18N_CTYPE_ja_euc_kanji_1st (SLIM_I18N_CTYPE_iso2022_gr94)
#define SLIM_I18N_CTYPE_ja_euc_kanji_2nd (SLIM_I18N_CTYPE_iso2022_gr94)
#define SLIM_I18N_CTYPE_ja_euc_x0212_2nd (SLIM_I18N_CTYPE_iso2022_gr94)
#define SLIM_I18N_CTYPE_ja_euc_x0212_3rd (SLIM_I18N_CTYPE_iso2022_gr94)
#define SLIM_I18N_CTYPE_zh_gb2312_1st (SLIM_I18N_CTYPE_iso2022_gr94)
#define SLIM_I18N_CTYPE_zh_gb2312_2nd (SLIM_I18N_CTYPE_iso2022_gr94)
#define SLIM_I18N_CTYPE_zh_big5_1st (SLIM_I18N_CTYPE_iso2022_gr94)
#define SLIM_I18N_CTYPE_ko_euc_kr_1st (SLIM_I18N_CTYPE_iso2022_gr94)
#define SLIM_I18N_CTYPE_ko_euc_kr_2nd (SLIM_I18N_CTYPE_iso2022_gr94)
#define SLIM_I18N_CTYPE_ucs_utf8_3rd (SLIM_I18N_CTYPE_ucs_utf8_2nd)
#define SLIM_I18N_CTYPE_ucs_utf8_4th (SLIM_I18N_CTYPE_ucs_utf8_2nd)
#define SLIM_I18N_CTYPE_ucs_utf8_5th (SLIM_I18N_CTYPE_ucs_utf8_2nd)
#define SLIM_I18N_CTYPE_ucs_utf8_6th (SLIM_I18N_CTYPE_ucs_utf8_2nd)

extern SLIM_ROM slim_word cSlim_i18n_ctype_table[256];

#define slim_i18n_isctype(c,type)    (cSlim_i18n_ctype_table[(c)] & (type))


SLIM_END_C_LINKAGE

#endif
