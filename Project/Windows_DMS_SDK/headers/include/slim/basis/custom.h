/*
	custom.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/basis/custom.h 17    06/04/07 0:46 Yamabuti $ */

#ifndef SLIM_CUSTOM_H
#define SLIM_CUSTOM_H

#ifndef SLIM_BASE_H
#include <slim/basis/base.h>
#endif

#undef SLIM_API
#define SLIM_API SLIM_DLLIMPORT

SLIM_BEGIN_C_LINKAGE

/*
 * I18N
 */

/* prepare I18N environment */
SLIM_API slim_bool slimI18NInitCustom(void);
SLIM_API void slimI18NTidyCustom(void);

/* returns a number of bytes of converted string */
SLIM_API slim_int slimI18NConvertCustom(slim_byte *out_buf, slim_byte *in_str, slim_int in_len, slim_int in_dest_charset, slim_int in_src_charset, slim_int *out_read_len);

/* returns a ID of CharSet
 * out_score is a percentage of reliability */
SLIM_API slim_int slimI18NGuessCustom(slim_int in_langset, slim_byte *in_s, slim_int in_len, slim_bool in_eof, slim_int *out_score);

/*
 * UCS
 */

SLIM_API void slimUCSSupportedEncodingCustom(slim_int *inout_src_encoding, slim_int *inout_dest_encoding);
SLIM_API slim_int slimUCSGetPreferredEncodingCustom(void);

/* returns number of written bytes. If out_buf is NULL, returns a number of bytes
 * required for out_buf.
 * *out_read_bytes is number of bytes actually read.
 */
SLIM_API slim_int slimUCSConvToUCSCustom(slim_byte *in_s, slim_int in_bytes, slim_int in_src_encoding, slim_byte *out_buf, slim_int in_dest_encoding, slim_int *out_read_bytes);
SLIM_API slim_int slimUCSConvFromUCSCustom(slim_byte *in_s, slim_int in_bytes, slim_int in_src_encoding, slim_byte *out_buf, slim_int in_dest_encoding, slim_int *out_read_bytes);

/*
 * UCS PUA(Private User Area)
 */
/* returns converted UCS character, or -1 if it is unconvertible. */
SLIM_API slim_int slimUCSPUAConvCharToPUACustom(slim_byte *in_ch, slim_int in_bytes, slim_int in_src_encoding);
/* NOTE: out_ch has SLIM_I18NCHAR_MAXBUFLEN bytes.
 * returns number of written bytes, or -1 if it is unconvertible. */
SLIM_API slim_int slimUCSPUAConvCharFromPUACustom(slim_word in_pua_ucs4, slim_byte *out_ch, slim_int in_dest_encoding);

SLIM_END_C_LINKAGE

#undef SLIM_API
#define SLIM_API SLIM_DLLEXPORT

#endif
