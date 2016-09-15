/*
 * dlna_profiler.h
 * Copyright (C) 2013 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef DLNA_PROFILER_H
#define DLNA_PROFILER_H

#include <dlna_peer.h>
#include <info_media.h>

#define JPEG_SMALL_WIDTH        (640)
#define JPEG_SMALL_HEIGHT       (480)
#define JPEG_MEDIUM_WIDTH       (1024)
#define JPEG_MEDIUM_HEIGHT      (768)
#define JPEG_LARGE_WIDTH        (4096)
#define JPEG_LARGE_HEIGHT       (4096)
#define JPEG_THUMBNAIL_WIDTH    (160)
#define JPEG_THUMBNAIL_HEIGHT   (160)
#define JPEG_SMALL_ICON_WIDTH   (48)
#define JPEG_SMALL_ICON_HEIGHT  (48)
#define JPEG_LARGE_ICON_WIDTH   (120)
#define JPEG_LARGE_ICON_HEIGHT  (120)
#define PNG_SMALL_ICON_WIDTH    (48)
#define PNG_SMALL_ICON_HEIGHT   (48)
#define PNG_LARGE_ICON_WIDTH    (120)
#define PNG_LARGE_ICON_HEIGHT   (120)
#define PNG_THUMBNAIL_WIDTH     (160)
#define PNG_THUMBNAIL_HEIGHT    (160)
#define PNG_LARGE_WIDTH         (4096)
#define PNG_LARGE_HEIGHT        (4096)
#define MPEG_PN_LINE_SIZE       (20)
#define WMV_PN_LINE_SIZE        (20)

typedef enum dlna_profiler_ret_
{
  PROFILER_OK,
  PROFILER_ERROR,
  PROFILER_WRONG_CONTENT_CLASS,
  PROFILER_WRONG_CONTENT_TYPE,
  PROFILER_OUTOF_MEMORY,
  PROFILER_PN_UNKNOWN
} dlna_profiler_ret;

typedef enum dlna_content_class_
{
  CONTENT_CLASS_PICTURE,
  CONTENT_CLASS_AUDIO,
  CONTENT_CLASS_VIDEO,
  CONTENT_CLASS_OTHER
} dlna_content_class;

typedef enum dlna_content_type_
{
  CONTENT_TYPE_JPEG,
  CONTENT_TYPE_PNG,
  CONTENT_TYPE_GIF,
  CONTENT_TYPE_AMR,
  CONTENT_TYPE_LPCM,
  CONTENT_TYPE_WAV,
  CONTENT_TYPE_MP3,
  CONTENT_TYPE_WMA,
  CONTENT_TYPE_MP4_AUDIO,
  CONTENT_TYPE_MP4_VIDEO,
  CONTENT_TYPE_3GP_AUDIO,
  CONTENT_TYPE_3GP_VIDEO,
  CONTENT_TYPE_MPEG2,
  CONTENT_TYPE_WMV,
#ifdef DEVELOPMENT_ENABLE_ADS
  CONTENT_TYPE_MPD
#endif /* DEVELOPMENT_ENABLE_ADS */
} dlna_content_type;

typedef enum dlna_encoding_type_audio_
{
  UNKNOWN_BIT_RATE,
  CONSTANT_BIT_RATE,
  VARIABLE_BIT_RATE
} dlna_encoding_type_audio;

typedef enum dlna_wma_format_audio_ {
  WMv1,
  WMv2,
  WMvPro,
  wma_mp3
} dlna_wma_format_audio;

typedef enum dlna_mp4_format_audio_ {
  FORMAT_UNKNOWN,
  FORMAT_MP4,
  FORMAT_3GP
} dlna_mp4_format_audio;

typedef enum dlna_tv_system_video_ {
  TV_SYSTEM_UNKNOWN,
  TV_SYSTEM_PAL,
  TV_SYSTEM_NTSC,
  TV_SYSTEM_SD,
  TV_SYSTEM_HD
} dlna_tv_system_video;

typedef enum dlna_mpeg2_audio_profile_ {
  MPEG2_AUDIO_TYPE_UNKNOWN,
  MPEG2_AUDIO_TYPE_XA3,
  MPEG2_AUDIO_TYPE_DTS,
  MPEG2_AUDIO_TYPE_DTSHD,
  MPEG2_AUDIO_TYPE_DTSHD_HRA,
  MPEG2_AUDIO_TYPE_DTSHD_MA
} dlna_mpeg2_audio_profile;

typedef enum dlna_interlacing_info_ {
  DLNA_INTERLACING_UNKNOWN,
  DLNA_INTERLACING_PROGRESSIVE,
  DLNA_INTERLACING_INTERLACED
} dlna_interlacing_info;


typedef enum dlna_mpeg2_type_ {
  MPEG2_TYPE_UNKNOWN,
  MPEG2_TYPE_PS,
  MPEG2_TYPE_TS
} dlna_mpeg2_type;

typedef enum dlna_mpeg2_region_ {
  MPEG2_REGION_JP,
  MPEG2_REGION_NA,
  MPEG2_REGION_EU,
  MPEG2_REGION_KO,
  MPEG2_REGION_UNKNOWN
} dlna_mpeg2_region;

typedef enum dlna_mpeg2_stream_type_ {
  MPEG2_STREAM_NOTYPE,
  MPEG2_STREAM_NOTS, 
  MPEG2_STREAM_VALID_TS,
  MPEG2_STREAM_INVALID_TS,
  MPEG2_STREAM_NOTS_JP,
  MPEG2_STREAM_VALID_TS_JP,
  MPEG2_STREAM_INVALID_TS_JP,
  MPEG2_STREAM_ARIB_PARTIAL_TS
} dlna_mpeg2_stream_type;

typedef enum dlna_video_codec_profile_ {
  VIDEO_CODEC_PROFILE_MP_ML,
  VIDEO_CODEC_PROFILE_MP_HL,
  VIDEO_CODEC_PROFILE_UNKNOWN
} dlna_video_codec_profile;

typedef enum dlna_audio_codec_profile_ {
  AUDIO_CODEC_UNKNOWN,
  AUDIO_CODEC_AC_AAC,
  AUDIO_CODEC_AC_MPEG1_L2
} dlna_audio_codec_profile;

typedef enum dlna_bitrate_type_ {
  BITRATE_TYPE_UNKNOWN,
  BITRATE_TYPE_CBR,  //constant bit rate
  BITRATE_TYPE_VBR   //variable bit rate
} dlna_bitrate_type;

typedef struct dlna_channel_modes_ {
  slim_word  chans;
  slim_word  subs;
} dlna_channel_modes;

typedef struct dlna_aspect_ratio_
{
  slim_word  num;
  slim_word  den;
} dlna_aspect_ratio;

typedef struct dlna_resolution_pn_info_
{
  slim_word width;
  slim_word height;
} dlna_resolution_pn_info;

typedef struct dlna_frame_rate_
{
  slim_word  num;
  slim_word  den;
} dlna_frame_rate;

typedef struct dlna_field_rate_
{
  slim_word  num;
  slim_word  den;
} dlna_field_rate;

typedef struct dlna_base_pn_info_
{
  dlna_content_class content_class;
  dlna_content_type  content_type;
  slim_char          mimeTypeStr[50];
  void              *profile_private_data;
  slim_char         *filename;
} dlna_base_pn_info;

typedef struct dlna_pic_pn_info_
{
  dlna_resolution_pn_info resolution_info;
}dlna_pic_pn_info;

typedef struct dlna_mp4_pn_info_ {
  slim_bool              is_adts;
  slim_bool              is_ltp;
  slim_bool              has_sbr;
  mp4_audio_obj_type_t   audobjtype;
  dlna_mp4_format_audio  format;
} dlna_mp4_pn_info;

typedef struct dlna_video_bit_rate_ {
  dlna_bitrate_type  bitrate_type;
  slim_ulong         bitrate_value;
} dlna_video_bit_rate;

typedef struct dlna_video_gop_info_ {
  slim_word  display_fields;
  slim_word  frames;
} dlna_video_gop_info;


typedef struct dlna_mpeg2_pn_info_ {
  dlna_tv_system_video      tv_system;  // PAL or NTSC
  slim_word                 video_streams;  //number of video streams
  slim_word                 audio_streams;  //number of audio streams
  dlna_mpeg2_type           mpeg2_type;  // PS or TS
  slim_ulong                sys_bitrate;
  slim_word                 pack_size;  //must be 2048 bytes
  slim_bool                 proper_pack_header;
  slim_bool                 proper_audio_pack;
  slim_bool                 proper_video_pack;
  slim_bool                 proper_video_pack_header;
  slim_bool                 proper_system_header;
  slim_bool                 has_ifo;  //does content have corresponding IFO file?
  slim_ulong                content_length;
  slim_ulong                content_length_ifo;  //content length from IFO file
  slim_byte                 mpeg2_stream_id;
  slim_bool                 proper_sequence_header;
  dlna_video_gop_info       gop_info;
  slim_bool                 has_low_delay;  //low_delay" sequences are not permitted
  slim_bool                 has_pts;
  slim_bool                 has_dts;
  slim_word                 number_of_programs;
  dlna_interlacing_info     interlacing_info;
  dlna_mpeg2_audio_profile  mpeg2_audio_profile;
  /* info for mpeg2 profile with ac3 sound */
  slim_byte                 ac3_stream_id;
  slim_bool                 ac3_proper_pack_header;
  slim_bool                 ac3_has_pts;
  dlna_mpeg2_region         region;
  dlna_mpeg2_stream_type    stream_type;
  dlna_audio_codec_profile  audio_codec;
} dlna_mpeg2_pn_info;

typedef struct dlna_wma_pn_info_ {
  dlna_wma_format_audio format;
} dlna_wma_pn_info;

typedef struct dlna_audio_pn_info_
{
  aud_prof_t                audio_prof;    /* Set to the DLNA audio Profile              */
  slim_word                 samps;
  slim_ulong                aveBitrate;
  slim_ulong                maxBitrate;
  slim_word                 chans;
  dlna_encoding_type_audio  encoding_type;
  slim_word                 quantization;
  dlna_channel_modes        channel_modes;
  /* Audio information specific for concrete codec */
  dlna_wma_pn_info          wma_pn_info;
  dlna_mp4_pn_info          mp4_pn_info;
}dlna_audio_pn_info;

typedef struct dlna_mpeg2_video_profile_
{
  dlna_resolution_pn_info  video_res;
  dlna_aspect_ratio        aspect_ratio[2];
  dlna_field_rate          field_rate[3];
  dlna_frame_rate          frame_rate[3];
} dlna_mpeg2_video_profile;

typedef struct dlna_mpeg2_audio__dts_profile_
{
  slim_word           samps[6];
  dlna_channel_modes  channel_modes[9];
  slim_word           min_bit_rate;
  slim_word           max_bit_rate;
} dlna_mpeg2_audio_dts_profile;

typedef struct dlna_video_pn_info_
{
  vid_prof_t                video_prof;    /* Set to the DLNA video Profile              */
#ifdef MEDIA_PROCESSING_EXTENSION
  vc_prof_t                 video_codec_prof;
  vc_level_t                video_codec_level;
#endif /*MEDIA_PROCESSING_EXTENSION*/
  dlna_video_codec_profile  video_codec_profile;
  dlna_resolution_pn_info   video_res;
  dlna_frame_rate           frame_rate;
  dlna_field_rate           field_rate;
  dlna_video_bit_rate       video_bit_rate;
  dlna_video_bit_rate       video_max_bit_rate; /* video bitrate, media_video_stream_information->maxBitrate */
  dlna_aspect_ratio         aspect_ratio;
  dlna_mpeg2_pn_info        mpeg2_pn_info;
} dlna_video_pn_info;

struct dlna_extended_stream_properties_
{
  slim_ulong data_bitrate;    /* leak rate for leaky bucket in bps */
};
typedef struct dlna_extended_stream_properties_ dlna_esp_t;

typedef struct dlna_pn_info_
{
  dlna_base_pn_info   base_pn_info;
  dlna_pic_pn_info    pic_info;
  dlna_audio_pn_info  audio_info;
  dlna_video_pn_info  video_info;
  sys_prof_t          system_prof;   /* Set to the DLNA system Profile   */
  slim_word           system_bit_rate;

  dlna_esp_t          aStream;       /* Audio stream extended properties */
} dlna_pn_info;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

dlna_profiler_ret
dlna_profiler_set_dlna_info(minfo_t * info, dlna_pn_info * pn_info);

dlna_profiler_ret
dlna_profiler_pn_get(dlna_pn_info * pn_info);

slim_char *
dlna_profiler_pn_get_string (dlna_pn_info *pn_info);

dlna_profiler_ret
dlna_profiler_pinfo_get(minfo_t * info, media_manager_t *mim, dlna_pn_info * pn_info);

dlna_profiler_ret
dlna_profiler_set_minfo_t( dlna_pn_info * pn_info, minfo_t * info);

dlna_profiler_ret
dlna_profiler_pn_get_incomplete(dlna_pn_info * pn_info);

void
dlna_profiler_pn_info_dump(dlna_pn_info * pn_info);

dlna_profiler_ret
dlna_profiler_dlna_pn_info_init(dlna_pn_info * pn_info);

void
dlna_profiler_dlna_pn_info_fin(dlna_pn_info * pn_info);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* DLNA_PROFILER_H */
