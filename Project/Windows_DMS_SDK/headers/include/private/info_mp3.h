/*
 * info_mp3.h
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

#ifndef NFLC_INFO_MP3_H
#define NFLC_INFO_MP3_H

enum mpeg_version
{
  MPEG_VERSION_1,
  MPEG_VERSION_2,
  MPEG_VERSION_2_5
};

enum mpeg_layer
{
  MPEG_LAYER_1,
  MPEG_LAYER_2,
  MPEG_LAYER_3
};

typedef struct mpa_header {
  slim_int frame_size;
  slim_int error_protection;
  slim_int layer;
  slim_int sample_rate;
  slim_int sample_rate_index; /* between 0 and 8 */
  slim_int bit_rate;
  slim_int bitrate_index;
  slim_int nb_channels;
  slim_int mode;
  slim_int mode_ext;
  slim_int lsf;
} mpa_header_t;


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_bool
register_media_info_mp3(media_manager_t *mim);

slim_bool
mp3_time_seek_adjust(slim_char *in_fullpath, dlna_uint64 *in_file_size,
                     dlna_timeval *in_seek_time, dlna_uint64 *inout_seek_bytes);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_INFO_MP3_H */
