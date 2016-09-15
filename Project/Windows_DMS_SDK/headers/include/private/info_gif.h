/*
 * info_gif.h
 * Copyright (C) 2007 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* GIF information get routine.  */

#ifndef NFLC_INFO_GIF_H
#define NFLC_INFO_GIF_H

/* GIF maximum resolution for each profile.  */
#define GIF_LRG_W          (1600)
#define GIF_LRG_H          (1200)


/* GIF profile.  */
enum gif_profile
{
  GIF_PROFILE_LRG = 1,
  GIF_PROFILE_UNKNOWN
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_int
gif_profile_get(slim_word in_width, slim_word in_height);

#ifdef MEDIA_PROCESSING_EXTENSION
slim_char*
gif_get_prof_str (slim_int profile_id);
#endif /*MEDIA_PROCESSING_EXTENSION*/

slim_bool
register_media_info_gif(media_manager_t *mim);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_INFO_GIF_H */
