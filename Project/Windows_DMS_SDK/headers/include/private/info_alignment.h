/*
 * info_alignment.h
 * Copyright (C) 2014 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_INFO_ALIGNMENT_H
#define NFLC_INFO_ALIGNMENT_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_bool
media_is_aligned_properly (slim_char *in_content_path, slim_char *in_pinfo, 
                           dlna_uint64 in_start_byte, dlna_uint64 in_end_byte);

slim_int
media_get_aligned_byte_position (slim_char *in_content_path, slim_char *in_pinfo,
                                 dlna_uint64 in_sp, dlna_uint64 in_ep,
                                 dlna_uint64 *out_aligned_sp, dlna_uint64 *out_aligned_ep);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_INFO_ALIGNMENT_H */
