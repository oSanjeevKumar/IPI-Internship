/*
 * info_avi.h
 * Copyright (C) 2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* AVI file support for NFLC. */

#ifndef NFLC_INFO_AVI_H
#define NFLC_INFO_AVI_H

#include <info_avi_def.h> /* Import defs */

slim_bool register_media_info_avi(media_manager_t *mim);
slim_bool register_media_info_divx(media_manager_t *mim);
slim_bool register_media_info_wav(media_manager_t *mim);

slim_int copy_info_if_valid(slim_char **p_dst_out, slim_char **p_src_inout);

#endif /* NFLC_INFO_AVI_H */
