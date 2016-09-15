/*
 * dlna_i18n.h
 * Copyright (C) 2007 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_DLNA_I18N_H
#define NFLC_DLNA_I18N_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void
dlna_i18n_initialize(void);

void
dlna_i18n_finalize(void);

slim_bool
dlnaIsLittleByBOM(slim_byte *in_s);

slim_int
dlnaGetUtf16ByteLen(slim_byte *in_s);

slim_int
dlnaConvertToUTF8(slim_byte *in_s, slim_int in_bytes, 
                    slim_int in_charset,
                    slim_byte *out_buf, slim_int *out_read_bytes);

slim_int
dlnaUTF16LEToUTF8(slim_byte *in_s, slim_int in_bytes, 
                  slim_byte *out_buf, slim_int *out_read_bytes);

slim_int
dlnaGuessConvertToUTF8(slim_byte *in_s, slim_int in_bytes, 
                       slim_byte *out_buf, slim_int *out_read_bytes);

slim_char *
isValidUTF8String(slim_char *in_string);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DLNA_I18N_H */
