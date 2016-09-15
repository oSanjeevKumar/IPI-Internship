/*
 * info_mpeg4.h
 * Copyright (C) 2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* mpeg4 codec support for NFLC. */


#ifndef NFLC_INFO_MPEG4_H
#define NFLC_INFO_MPEG4_H

#include <info_media.h>

#ifdef MEDIA_PROCESSING_EXTENSION

#define  MPEG4_VIDEO_ENC_TABLE_ENTRIES  	27
#define  MPEG4_VIDEO_PX_ASP_RATIO_ENTRIES	15
#define  MPEG4_VIDEO_ASP_RATIO_ENTRIES   	 5
#define  MPEG4_VIDEO_RATE_ENTRIES       	 7
#define  MPEG4_SYSTEM_BR_ENTRIES			 10
#define  MPEG4_VIDEO_BR_ENTRIES				 10
#define  MPEG4_VIDEO_CODEC_LEVELS_ENTRIES	10

/* Profile macros copy from ffmpeg/libavcodec/avcodec.h */
#define FFMPEG_MPEG4_ACV_BASELINE_PROFILE	66
#define FFMPEG_MPEG4_ACV_MAIN_PROFILE 		77
#define FFMPEG_MPEG4_ACV_HIGH_PROFILE           100

typedef struct
{
  slim_ulong  bit_rate;  	/* bps */
} mpeg4_profile_system_t;

typedef struct
{
  slim_ulong  bit_rate;  	/* bps */
} mpeg4_profile_video_bitrate_t;

typedef struct
{
  vc_level_t	level;		 /* video codec level */
} mpeg4_video_vc_level_t;

typedef struct
{
  slim_int  wid;
  slim_int  ht;
} mpeg4_video_res_t;

typedef struct
{
  slim_int  num;
  slim_int  den;
} mpeg4_video_asp_ratio_t;

typedef struct
{
  slim_int  num;
  slim_int  den;
} mpeg4_px_asp_ratio_t;

typedef struct
{
  slim_int  num;
  slim_int  den;
} mpeg4_video_field_rate_t;

typedef struct
{
  slim_int  num;
  slim_int  den;
} mpeg4_video_frame_rate_t;

typedef struct
{
  mpeg4_video_res_t        		res;
  mpeg4_px_asp_ratio_t			pxasrt[MPEG4_VIDEO_PX_ASP_RATIO_ENTRIES];
  mpeg4_video_asp_ratio_t  		asrt[MPEG4_VIDEO_ASP_RATIO_ENTRIES];
  mpeg4_video_field_rate_t 		fir[MPEG4_VIDEO_RATE_ENTRIES];
  mpeg4_video_frame_rate_t 		frr[MPEG4_VIDEO_RATE_ENTRIES];
} mpeg4_video_enc_parms_t;

typedef struct
{
  mpeg4_video_enc_parms_t  		enc_table[MPEG4_VIDEO_ENC_TABLE_ENTRIES];
} mpeg4_profile_video_t;

typedef struct
{
  mpeg4_profile_system_t		 system_bps [MPEG4_SYSTEM_BR_ENTRIES];
  mpeg4_profile_video_bitrate_t	 video_bps [MPEG4_VIDEO_BR_ENTRIES];
  mpeg4_video_vc_level_t		 levels[MPEG4_VIDEO_CODEC_LEVELS_ENTRIES];
  mpeg4_profile_video_t   		 video;
} mpeg4_profile_t;

dlna_profile_t
mpeg4_profile_get(minfo_t *info, video_info_t *dinfo);

#ifdef DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION_SONY_BRAVIA_PROFILING
dlna_profile_t
mpeg4_profile_get_relaxed(minfo_t *info);
#endif /* DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION_SONY_BRAVIA_PROFILING */

slim_char*
mpeg4_get_prof_str(slim_int profile_id) ;
#endif /*MEDIA_PROCESSING_EXTENSION*/
#endif /* NFLC_INFO_MPEG4_H */
