/*
 * info_jpeg.h
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

/* JPEG information get routine.  */

#ifndef NFLC_INFO_JPEG_H
#define NFLC_INFO_JPEG_H

/* JPEG maximum resolution for each profile.  */
#define JPEG_SM_ICO_W          (48)
#define JPEG_SM_ICO_H          (48)
#define JPEG_LRG_ICO_W         (120)
#define JPEG_LRG_ICO_H         (120)
#define JPEG_TN_W_MAX          (160)
#define JPEG_TN_H_MAX          (160)
#define JPEG_SM_W_MAX          (640)
#define JPEG_SM_H_MAX          (480)
#define JPEG_MED_W_MAX         (1024)
#define JPEG_MED_H_MAX         (768)
#define JPEG_LRG_W_MAX         (4096)
#define JPEG_LRG_H_MAX         (4096)

#define FULL_HD_W_MAX			(1920)
#define FULL_HD_H_MAX			(1080)

#ifdef DEVELOPMENT_NFLC_PROFILER
/* Buffer line size.  */
#ifndef NFLC_LINE_SIZE
#define NFLC_LINE_SIZE  (180)
#endif /* NFLC_LINE_SIZE */
#endif /* DEVELOPMENT_NFLC_PROFILER */

/* JPEG profile.  Not used anymore merged to dlna_profile_t enum to avoid comparison between 2 different enums*/
/*enum jpeg_profile
{
  JPEG_PROFILE_UNKNOWN = 0,
  JPEG_PROFILE_SM_ICO = 1,
  JPEG_PROFILE_LRG_ICO,
  JPEG_PROFILE_TN,
  JPEG_PROFILE_SM,
  JPEG_PROFILE_MED,
  JPEG_PROFILE_LRG
};*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_int
jpeg_profile_get (slim_word in_width, slim_word in_height);

#ifdef MEDIA_PROCESSING_EXTENSION
slim_char *
jpeg_get_prof_str (slim_int profile_id);
#endif /*MEDIA_PROCESSING_EXTENSION*/

slim_bool
register_media_info_jpeg(media_manager_t *mim);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_INFO_JPEG_H */
