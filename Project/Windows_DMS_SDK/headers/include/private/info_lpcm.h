/*
 * info_lpcm.h
 * Copyright (C) 2007 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */

#ifndef NFLC_INFO_LPCM_H
#define NFLC_INFO_LPCM_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef MEDIA_PROCESSING_EXTENSION
dlna_ret_t
MPE_lpcm_info_get (minfo_t *lpcm);
#endif /* MEDIA_PROCESSING_EXTENSION */

slim_bool
lpcm_pinfo_core_get (slim_char* pinfo, slim_int length, slim_word samps, slim_word chans);

slim_bool
register_media_info_lpcm(media_manager_t *mim);

#ifdef DEVELOPMENT_NFLC_PROFILER
slim_char *
lpcm_pinfo_get (slim_word samps, slim_word chans);

slim_char *
lpcm_dtcp_pinfo_get (slim_word samps, slim_word chans);
#endif /* DEVELOPMENT_NFLC_PROFILER */
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_INFO_LPCM_H */
