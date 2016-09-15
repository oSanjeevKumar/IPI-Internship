/*
 * info_vc1.h
 * Copyright (C) 2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* VC-1 codec support for NFLC. */


#ifndef NFLC_INFO_VC1_H
#define NFLC_INFO_VC1_H

#define VC1_VIDEO_FRR_INVALID_ENTRIES  2
#define  VC1_VIDEO_ENC_TABLE_ENTRIES  20
#define  VC1_VIDEO_ASP_RATIO_ENTRIES   5
#define  VC1_VIDEO_RATE_ENTRIES        5

#define VC1_AUDIO_AC3_SAMPLE_RATE_ENTRIES 3

typedef struct
{
  slim_ulong  bit_rate;  /* bps */
} vc1_profile_system_t;

typedef struct
{
  slim_int  wid;
  slim_int  ht;
} vc1_video_res_t;

typedef struct
{
  slim_int  num;
  slim_int  den;
} vc1_video_asp_ratio_t;

typedef struct
{
  slim_int  num;
  slim_int  den;
} vc1_video_field_rate_t;

typedef struct
{
  slim_int  num;
  slim_int  den;
} vc1_video_frame_rate_t;

typedef struct
{
  vc1_video_res_t        res;
  vc1_video_asp_ratio_t  asrt[VC1_VIDEO_ASP_RATIO_ENTRIES];
  vc1_video_field_rate_t fir[VC1_VIDEO_RATE_ENTRIES];
  vc1_video_frame_rate_t frr[VC1_VIDEO_RATE_ENTRIES];
} vc1_video_enc_parms_t;

typedef struct
{
  vc1_video_enc_parms_t  enc_table[VC1_VIDEO_ENC_TABLE_ENTRIES];
} vc1_profile_video_t;

typedef struct
{
  vc1_profile_system_t  system;
  vc1_profile_video_t   video;
} vc1_profile_t;


#define  VC1_PROFILE_AUDIO_SAMPS  20
#define  VC1_PROFILE_AUDIO_CHANS  20

typedef struct
{
  slim_int      samp_rates[VC1_PROFILE_AUDIO_SAMPS];
  slim_char *   chan_modes[VC1_PROFILE_AUDIO_CHANS];
  slim_int      min_bit_rate;
  slim_int      max_bit_rate;
} vc1_profile_audio_t;

slim_bool
register_media_info_vc1(media_manager_t * mim);

dlna_profile_t
vc1_profile_get(minfo_t *info);

slim_char*
vc1_get_prof_str(minfo_t *info);

#endif /* NFLC_INFO_VC1_H */
