/*
	chstproc.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

#ifndef SLIM_CHSET_CONF_H
#define SLIM_CHSET_CONF_H

SLIM_BEGIN_C_LINKAGE

#define SLIM_I18N_GETCH_US_ASCII slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_US_ASCII slim_i18n_checkch_en_us_ascii
#define SLIM_I18N_GETCH_ISO_8859_1  slim_i18n_getch_la_iso8859_1
#define SLIM_I18N_CHECKCH_ISO_8859_1 slim_i18n_checkch_la_iso8859_1
#define SLIM_I18N_GETCH_ISO_8859_15  slim_i18n_getch_la_iso8859_15
#define SLIM_I18N_CHECKCH_ISO_8859_15 slim_i18n_checkch_la_iso8859_15
#define SLIM_I18N_GETCH_WINDOWS_1252 slim_i18n_getch_la_windows_1252
#define SLIM_I18N_CHECKCH_WINDOWS_1252 slim_i18n_checkch_la_windows_1252

#ifdef SLIM_CONFIG_USE_JAPANESE
#define SLIM_I18N_GETCH_SHIFT_JIS slim_i18n_getch_ja_shift_jis
#define SLIM_I18N_CHECKCH_SHIFT_JIS slim_i18n_checkch_ja_shift_jis
#define SLIM_I18N_GETCH_EUC_JP slim_i18n_getch_ja_euc
#define SLIM_I18N_CHECKCH_EUC_JP slim_i18n_checkch_ja_euc
#define SLIM_I18N_GETCH_ISO_2022_JP (slim_i18n_getch_proc)slim_i18n_getch_ja_jis7
#define SLIM_I18N_CHECKCH_ISO_2022_JP slim_nil
#else	/* SLIM_CONFIG_USE_JAPANESE */
#define SLIM_I18N_GETCH_SHIFT_JIS slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_SHIFT_JIS slim_i18n_checkch_en_us_ascii
#define SLIM_I18N_GETCH_EUC_JP slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_EUC_JP slim_i18n_checkch_en_us_ascii
#define SLIM_I18N_GETCH_ISO_2022_JP slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_ISO_2022_JP slim_i18n_checkch_en_us_ascii
#endif	/* SLIM_CONFIG_USE_JAPANESE */

#ifdef SLIM_CONFIG_USE_KOREAN
#define SLIM_I18N_GETCH_EUC_KR slim_i18n_getch_ko_euc_kr
#define SLIM_I18N_CHECKCH_EUC_KR slim_i18n_checkch_ko_euc_kr
#define SLIM_I18N_GETCH_UHC  slim_i18n_getch_ko_uhc
#define SLIM_I18N_CHECKCH_UHC slim_i18n_checkch_ko_uhc
#else	/* SLIM_CONFIG_USE_KOREAN */
#define SLIM_I18N_GETCH_EUC_KR slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_EUC_KR slim_i18n_checkch_en_us_ascii
#define SLIM_I18N_GETCH_UHC slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_UHC slim_i18n_checkch_en_us_ascii
#endif	/* SLIM_CONFIG_USE_KOREAN */

#ifdef SLIM_CONFIG_USE_SIMPLIFIED_CHINESE
#define SLIM_I18N_GETCH_GB2312 slim_i18n_getch_zh_gb2312
#define SLIM_I18N_CHECKCH_GB2312 slim_i18n_checkch_zh_gb2312
#define SLIM_I18N_GETCH_GBK slim_i18n_getch_zh_gbk
#define SLIM_I18N_CHECKCH_GBK slim_i18n_checkch_zh_gbk
#define SLIM_I18N_GETCH_GB18030 slim_i18n_getch_zh_gb18030
#define SLIM_I18N_CHECKCH_GB18030 slim_i18n_checkch_zh_gb18030
#else	/* SLIM_CONFIG_USE_SIMPLIFIED_CHINESE */
#define SLIM_I18N_GETCH_GB2312 slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_GB2312 slim_i18n_checkch_en_us_ascii
#define SLIM_I18N_GETCH_GBK slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_GBK slim_i18n_checkch_en_us_ascii
#define SLIM_I18N_GETCH_GB18030 slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_GB18030 slim_i18n_checkch_en_us_ascii
#endif	/* SLIM_CONFIG_USE_SIMPLIFIED_CHINESE */

#ifdef SLIM_CONFIG_USE_TRADITIONAL_CHINESE
#define SLIM_I18N_GETCH_BIG5 slim_i18n_getch_zh_big5
#define SLIM_I18N_CHECKCH_BIG5 slim_i18n_checkch_zh_big5
#else	/* SLIM_CONFIG_USE_TRADITIONAL_CHINESE */
#define SLIM_I18N_GETCH_BIG5 slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_BIG5 slim_i18n_checkch_en_us_ascii
#endif	/* SLIM_CONFIG_USE_TRADITIONAL_CHINESE */

#ifdef SLIM_CONFIG_USE_BALTIC
#define SLIM_I18N_GETCH_ISO_8859_4 slim_i18n_getch_lv_iso8859_4
#define SLIM_I18N_CHECKCH_ISO_8859_4 slim_i18n_checkch_lv_iso8859_4
#define SLIM_I18N_GETCH_WINDOWS_1257 slim_i18n_getch_lv_windows_1257
#define SLIM_I18N_CHECKCH_WINDOWS_1257 slim_i18n_checkch_lv_windows_1257
#else	/* SLIM_CONFIG_USE_BALTIC */
#define SLIM_I18N_GETCH_ISO_8859_4 slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_ISO_8859_4 slim_i18n_checkch_en_us_ascii
#define SLIM_I18N_GETCH_WINDOWS_1257 slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_WINDOWS_1257 slim_i18n_checkch_en_us_ascii
#endif	/* SLIM_CONFIG_USE_BALTIC */

#ifdef SLIM_CONFIG_USE_CENTRAL_EUROPEAN
#define SLIM_I18N_GETCH_ISO_8859_2 slim_i18n_getch_la_iso8859_2
#define SLIM_I18N_CHECKCH_ISO_8859_2 slim_i18n_checkch_la_iso8859_2
#define SLIM_I18N_GETCH_WINDOWS_1250 slim_i18n_getch_la_windows_1250
#define SLIM_I18N_CHECKCH_WINDOWS_1250 slim_i18n_checkch_la_windows_1250
#else	/* SLIM_CONFIG_USE_CENTRAL_EUROPEAN */
#define SLIM_I18N_GETCH_ISO_8859_2 slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_ISO_8859_2 slim_i18n_checkch_en_us_ascii
#define SLIM_I18N_GETCH_WINDOWS_1250 slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_WINDOWS_1250 slim_i18n_checkch_en_us_ascii
#endif	/* SLIM_CONFIG_USE_CENTRAL_EUROPEAN */

#ifdef SLIM_CONFIG_USE_CYRILLIC
#define SLIM_I18N_GETCH_ISO_8859_5 slim_i18n_getch_la_iso8859_5
#define SLIM_I18N_CHECKCH_ISO_8859_5 slim_i18n_checkch_la_iso8859_5
#define SLIM_I18N_GETCH_WINDOWS_1251 slim_i18n_getch_la_windows_1251
#define SLIM_I18N_CHECKCH_WINDOWS_1251 slim_i18n_checkch_la_windows_1251
#define SLIM_I18N_GETCH_KOI8_R slim_i18n_getch_ru_koi8r
#define SLIM_I18N_CHECKCH_KOI8_R slim_nil
#else	/* SLIM_CONFIG_USE_CYRILLIC */
#define SLIM_I18N_GETCH_ISO_8859_5 slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_ISO_8859_5 slim_i18n_checkch_en_us_ascii
#define SLIM_I18N_GETCH_WINDOWS_1251 slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_WINDOWS_1251 slim_i18n_checkch_en_us_ascii
#define SLIM_I18N_GETCH_KOI8_R slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_KOI8_R slim_nil
#endif	/* SLIM_CONFIG_USE_CYRILLIC */

#ifdef SLIM_CONFIG_USE_GREEK
#define SLIM_I18N_GETCH_ISO_8859_7 slim_i18n_getch_el_iso8859_7
#define SLIM_I18N_CHECKCH_ISO_8859_7 slim_i18n_checkch_el_iso8859_7
#define SLIM_I18N_GETCH_WINDOWS_1253 slim_i18n_getch_el_windows_1253
#define SLIM_I18N_CHECKCH_WINDOWS_1253 slim_i18n_checkch_el_windows_1253
#else	/* SLIM_CONFIG_USE_GREEK */
#define SLIM_I18N_GETCH_ISO_8859_7 slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_ISO_8859_7 slim_i18n_checkch_en_us_ascii
#define SLIM_I18N_GETCH_WINDOWS_1253 slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_WINDOWS_1253 slim_i18n_checkch_en_us_ascii
#endif	/* SLIM_CONFIG_USE_GREEK */

#ifdef SLIM_CONFIG_USE_NORDIC
#define SLIM_I18N_GETCH_ISO_8859_10 slim_i18n_getch_la_iso8859_10
#define SLIM_I18N_CHECKCH_ISO_8859_10 slim_i18n_checkch_la_iso8859_10
#else	/* SLIM_CONFIG_USE_NORDIC */
#define SLIM_I18N_GETCH_ISO_8859_10 slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_ISO_8859_10 slim_i18n_checkch_en_us_ascii
#endif	/* SLIM_CONFIG_USE_NORDIC */

#ifdef SLIM_CONFIG_USE_SOUTH_EUROPEAN
#define SLIM_I18N_GETCH_ISO_8859_3 slim_i18n_getch_la_iso8859_3
#define SLIM_I18N_CHECKCH_ISO_8859_3 slim_i18n_checkch_la_iso8859_3
#else	/* SLIM_CONFIG_USE_SOUTH_EUROPEAN */
#define SLIM_I18N_GETCH_ISO_8859_3 slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_ISO_8859_3 slim_i18n_checkch_en_us_ascii
#endif	/* SLIM_CONFIG_USE_SOUTH_EUROPEAN */

#ifdef SLIM_CONFIG_USE_THAI
#define SLIM_I18N_GETCH_WINDOWS_874 slim_i18n_getch_th_windows_874
#define SLIM_I18N_CHECKCH_WINDOWS_874 slim_nil 
#else	/* SLIM_CONFIG_USE_THAI */
#define SLIM_I18N_GETCH_WINDOWS_874 slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_WINDOWS_874 slim_nil
#endif	/* SLIM_CONFIG_USE_THAI */

#ifdef SLIM_CONFIG_USE_TURKISH
#define SLIM_I18N_GETCH_ISO_8859_9 slim_i18n_getch_tr_iso8859_9
#define SLIM_I18N_CHECKCH_ISO_8859_9 slim_i18n_checkch_tr_iso8859_9
#define SLIM_I18N_GETCH_WINDOWS_1254 slim_i18n_getch_tr_windows_1254
#define SLIM_I18N_CHECKCH_WINDOWS_1254 slim_i18n_checkch_tr_windows_1254
#else	/* SLIM_CONFIG_USE_TURKISH */
#define SLIM_I18N_GETCH_ISO_8859_9 slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_ISO_8859_9 slim_i18n_checkch_en_us_ascii
#define SLIM_I18N_GETCH_WINDOWS_1254 slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_WINDOWS_1254 slim_i18n_checkch_en_us_ascii
#endif	/* SLIM_CONFIG_USE_TURKISH */

#ifdef SLIM_CONFIG_USE_ARABIC
#define SLIM_I18N_GETCH_ISO_8859_6 slim_i18n_getch_ar_iso8859_6
#define SLIM_I18N_CHECKCH_ISO_8859_6 slim_i18n_checkch_ar_iso8859_6
#define SLIM_I18N_GETCH_WINDOWS_1256 slim_i18n_getch_ar_windows_1256
#define SLIM_I18N_CHECKCH_WINDOWS_1256 slim_i18n_checkch_ar_windows_1256
#else	/* SLIM_CONFIG_USE_ARABIC */
#define SLIM_I18N_GETCH_ISO_8859_6 slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_ISO_8859_6 slim_i18n_checkch_en_us_ascii
#define SLIM_I18N_GETCH_WINDOWS_1256 slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_WINDOWS_1256 slim_i18n_checkch_en_us_ascii
#endif	/* SLIM_CONFIG_USE_ARABIC */

#ifdef SLIM_CONFIG_USE_HEBREW
#define SLIM_I18N_GETCH_ISO_8859_8 slim_i18n_getch_he_iso8859_8
#define SLIM_I18N_CHECKCH_ISO_8859_8 slim_i18n_checkch_he_iso8859_8
#define SLIM_I18N_GETCH_ISO_8859_8_I slim_i18n_getch_he_iso8859_8
#define SLIM_I18N_CHECKCH_ISO_8859_8_I slim_i18n_checkch_he_iso8859_8
#define SLIM_I18N_GETCH_WINDOWS_1255 slim_i18n_getch_he_windows_1255
#define SLIM_I18N_CHECKCH_WINDOWS_1255 slim_i18n_checkch_he_windows_1255
#else	/* SLIM_CONFIG_USE_HEBREW */
#define SLIM_I18N_GETCH_ISO_8859_8 slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_ISO_8859_8 slim_i18n_checkch_en_us_ascii
#define SLIM_I18N_GETCH_ISO_8859_8_I slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_ISO_8859_8_I slim_i18n_checkch_en_us_ascii
#define SLIM_I18N_GETCH_WINDOWS_1255 slim_i18n_getch_en_us_ascii
#define SLIM_I18N_CHECKCH_WINDOWS_1255 slim_i18n_checkch_en_us_ascii
#endif	/* SLIM_CONFIG_USE_HEBREW */

#define SLIM_I18N_GETCH_UTF_8 slim_i18n_getch_ucs_utf8
#define SLIM_I18N_CHECKCH_UTF_8 slim_i18n_checkch_ucs_utf8
#define SLIM_I18N_GETCH_UTF_16BE slim_i18n_getch_ucs_utf16be
#define SLIM_I18N_CHECKCH_UTF_16BE slim_i18n_checkch_ucs_utf16be
#define SLIM_I18N_GETCH_UTF_16LE slim_i18n_getch_ucs_utf16le
#define SLIM_I18N_CHECKCH_UTF_16LE slim_i18n_checkch_ucs_utf16le
#define SLIM_I18N_GETCH_UCS_2BE slim_i18n_getch_ucs_ucs2be
#define SLIM_I18N_CHECKCH_UCS_2BE slim_i18n_checkch_ucs_ucs2be
#define SLIM_I18N_GETCH_UCS_2LE slim_i18n_getch_ucs_ucs2le
#define SLIM_I18N_CHECKCH_UCS_2LE slim_i18n_checkch_ucs_ucs2le
#define SLIM_I18N_GETCH_UCS_4BE slim_i18n_getch_ucs_ucs4be
#define SLIM_I18N_CHECKCH_UCS_4BE slim_i18n_checkch_ucs_ucs4be
#define SLIM_I18N_GETCH_UCS_4LE slim_i18n_getch_ucs_ucs4le
#define SLIM_I18N_CHECKCH_UCS_4LE slim_i18n_checkch_ucs_ucs4le

SLIM_END_C_LINKAGE
#endif
