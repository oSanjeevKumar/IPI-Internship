/*
 * info_pls.h
 * Copyright (C) 2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2010 ACCESS CO., LTD. All rights reserved. */

#ifndef NFLC_INFO_PLS_H
#define NFLC_INFO_PLS_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_bool
register_media_info_pls(media_manager_t *mim);


#ifdef DEVELOPMENT_ENABLE_PLAYLIST_CONTAINER

slim_int
media_playlist_read_pls(slim_char * file_path, struct media_playlist * playlist);

#endif /* DEVELOPMENT_ENABLE_PLAYLIST_CONTAINER */


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_INFO_PLS_H */
