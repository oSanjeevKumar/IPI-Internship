/*
 * info_png.h
 * Copyright (C) 2007 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

/* PNG information get routine.  */

#ifndef NFLC_INFO_PNG_H
#define NFLC_INFO_PNG_H

/* PNG maximum resolution for each profile.  */
#define PNG_SM_ICO_W          (48)
#define PNG_SM_ICO_H          (48)
#define PNG_LRG_ICO_W         (120)
#define PNG_LRG_ICO_H         (120)
#define PNG_TN_W_MAX          (160)
#define PNG_TN_H_MAX          (160)
#define PNG_LRG_W_MAX         (4096)
#define PNG_LRG_H_MAX         (4096)

/* PNG profile.  */
enum png_profile
{
  PNG_PROFILE_SM_ICO = 1,
  PNG_PROFILE_LRG_ICO,
  PNG_PROFILE_TN,
  PNG_PROFILE_LRG
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if 0
slim_int
png_profile_get(minfo_t *png);
#else 
dlna_profile_t
png_profile_get(slim_word in_width, slim_word in_height);
#endif
#ifdef MEDIA_PROCESSING_EXTENSION
slim_char *
png_get_prof_str (dlna_profile_t profile);
#endif /*MEDIA_PROCESSING_EXTENSION*/

slim_bool
register_media_info_png(media_manager_t *mim);
#ifdef DEVELOPMENT_NFLC_PROFILER
slim_char *
png_pinfo_get (minfo_t *png);
#endif /* DEVELOPMENT_NFLC_PROFILER */
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_INFO_PNG_H */
