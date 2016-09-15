/*
 * info_mpeg2.h
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

#ifndef NFLC_INFO_MPEG2_H
#define NFLC_INFO_MPEG2_H

/* ISO/IEC 13818-1 2.4.3.3 Semantic definition of fields in
   Transport Stream packet layer.  */
#define MPEG2_TS_HEADER_SYNC_BYTE                       (0x47)

#define MPEG2_START_CODE_PREFIX_LEN                     3
#define MPEG2_START_CODE_LEN                            4

#define MPEG2_PACK_HEADER_MIN_LEN                       14
#define MPEG2_PACK_STUFFING_LEN_OFFSET                  13
#define MPEG2_PACK_STUFFING_LEN_MASK                    0x03

#define MPEG2_SYSTEM_HEADER_MIN_LEN                     96
#define MPEG2_SYSTEM_LEN_OFFSET                         4

#define MPEG2_PES_PACKET_MIN_LEN                        9
#define MPEG2_PES_HEADER_DATA_LEN_OFFSET                8

/* ISO/IEC 13818-2 6.3.3 Sequence header.  */
#define MPEG2_SEQ_HEADER_MIN_LEN                        12
#define MPEG2_SEQ_HEADER_MATRIX_LEN                     64

/* ISO/IEC 13818-2 6.3.4 Extension and user data.  */
#define MPEG2_EXTN_HEADER_MIN_LEN                       5
#define MPEG2_EXTN_START_CODE_OFFSET                    4

/* ISO/IEC 13818-2 6.3.5 Sequence extension.  */
#define MPEG2_EXTN_SEQ_LEN                              10
#define MPEG2_EXTN_SEQ_PROGRESSIVE_OFFSET               5

/* ISO/IEC 13818-2 6.3.6 Sequence display extension.  */
#define MPEG2_EXTN_SEQ_DISP_MIN_LEN                     8
#define MPEG2_EXTN_SEQ_DISP_COLOR_DESC_OFFSET           4
#define MPEG2_EXTN_SEQ_DISP_VIDEO_FORMAT_PAL            0x01
#define MPEG2_EXTN_SEQ_DISP_VIDEO_FORMAT_NTSC           0x02
#define MPEG2_EXTN_SEQ_DISP_VIDEO_FORMAT_SECAM          0x03
#define MPEG2_EXTN_SEQ_DISP_VIDEO_FORMAT_MAC            0x04

/* ISO/IEC 13818-2 6.3.7 Sequence scalable extension.  */
#define MPEG2_EXTN_SEQ_SCALABLE_MIN_LEN                 6
#define MPEG2_EXTN_SEQ_SCALABLE_SPATIAL_LEN             6
#define MPEG2_EXTN_SEQ_SCALABLE_TEMPORAL_LEN            1
#define MPEG2_EXTN_SEQ_SCALABLE_MODE_NON                0x00
#define MPEG2_EXTN_SEQ_SCALABLE_MODE_SPATIAL            0x01
#define MPEG2_EXTN_SEQ_SCALABLE_MODE_SNR                0x02
#define MPEG2_EXTN_SEQ_SCALABLE_MODE_TEMPORAL           0x03

/* ISO/IEC 13818-2 6.3.8 Group of picture header.  */
#define MPEG2_GOP_LEN                                   8

/* ISO/IEC 13818-2 6.3.9 Picture header.  */
#define MPEG2_PICT_HEADER_MIN_LEN                       8
#define MPEG2_PICT_HEADER_INTRA_CODED_MIN_LEN           9
#define MPEG2_PICT_HEADER_BIDIRECTIONALLY_MIN_LEN       9
#define MPEG2_PICT_HEADER_PICT_CODING_OFFSET            5
#define MPEG2_PICT_HEADER_PICT_CODING_FORBIDDEN         0x00
#define MPEG2_PICT_HEADER_PICT_CODING_INTRA_CODED       0x01
#define MPEG2_PICT_HEADER_PICT_CODING_PREDICTIVE_CODED  0x02
#define MPEG2_PICT_HEADER_PICT_CODING_BIDIRECTIONALLY   0x03
#define MPEG2_PICT_HEADER_EXTRA_BIT                     0x04
#define MPEG2_PICT_HEADER_EXTRA_BIT_PREDICTIVE_CODED    0x40

/* ISO/IEC 13818-2 6.3.10 Picuture coding extension.  */
#define MPEG2_EXTN_PICT_CODING_MIN_LEN                  9
#define MPEG2_EXTN_PICT_CODING_MAX_LEN                  11
#define MPEG2_EXTN_PICT_CODING_STRUCTURE_OFFSET         6
#define MPEG2_EXTN_PICT_CODING_TOP_FIELD_FIRST_OFFSET   7
#define MPEG2_EXTN_PICT_CODING_STRUCTURE_TOP_FIELD      0x01
#define MPEG2_EXTN_PICT_CODING_STRUCTURE_BOTTOM_FIELD   0x02
#define MPEG2_EXTN_PICT_CODING_STRUCTURE_FRAME_PICT     0x03
#define MPEG2_EXTN_PICT_CODING_TOP_FIELD_FIRST          0x80
#define MPEG2_EXTN_PICT_CODING_FRAME_PRED_FRAME_DCT     0x40
#define MPEG2_EXTN_PICT_CODING_CONCEALMENT_MOTION       0x20
#define MPEG2_EXTN_PICT_CODING_Q_SCALE_TYPE             0x10
#define MPEG2_EXTN_PICT_CODING_INTRA_VLC_FORMAT         0x08
#define MPEG2_EXTN_PICT_CODING_ALTERNATE_SCAN           0x04
#define MPEG2_EXTN_PICT_CODING_REPEAT_FIRST_FIELD       0x02
#define MPEG2_EXTN_PICT_CODING_CHROMA_420_TYPE          0x01
#define MPEG2_EXTN_PICT_CODING_PROGRESSIVE_FRAME        0x80
#define MPEG2_EXTN_PICT_CODING_COMPOSITE_FLAG           0x40

/* ISO/IEC 13818-2 6.3.11 Quant matrix extension.  */
#define MPEG2_EXTN_QUANT_QUANTISER_MATRIX_LEN           64
#define MPEG2_EXTN_QUANT_LOAD_INTRA_QUANTISER           0x08
#define MPEG2_EXTN_QUANT_LOAD_NON_INTRA_QUANTISER       0x04
#define MPEG2_EXTN_QUANT_LOAD_CHROMA_INTRA_QUANTISER    0x02
#define MPEG2_EXTN_QUANT_LOAD_CHROMA_NON_INTRA_QUANTISER    0x01

/* ISO/IEC 13818-2 6.3.12 Picture display extension.  */
#define MPEG2_EXTN_PICT_DISP_MIN_LEN                    5
#define MPEG2_EXTN_PICT_DISP_FRAME_OFFSET_LEN           5

/* ISO/IEC 13818-2 6.3.13 Picture temporal scalable extension.  */
#define MPEG2_EXTN_PICT_TEMPORAL_LEN                    8

/* ISO/IEC 13818-2 6.3.14 Picture spatial scalable extension.  */
#define MPEG2_EXTN_PICT_SPATIAL_LEN                     11

/* ISO/IEC 13818-2 6.3.15 Copyright extension.  */
#define MPEG2_EXTN_COPYRIGHT_LEN                        15

/* ISO/IEC 13818-2 6.3.19 Camera parameter extension.  */
#define MPEG2_EXTN_CAMERA_PARAMETERS_LEN            52

/* ISO/IEC 13818-1 Table 2-18 Stream ID assignment.  */
#define MPEG2_STREAM_ID_PROGRAM_END                     0xB9
#define MPEG2_STREAM_ID_PACK_HEADER                     0xBA
#define MPEG2_STREAM_ID_SYSTEM_HEADER                   0xBB
#define MPEG2_STREAM_ID_PROGRAM_STREAM_MAP              0xBC
#define MPEG2_STREAM_ID_PRIVATE_STREM_1                 0xBD
#define MPEG2_STREAM_ID_PADDING_STREAM                  0xBE
#define MPEG2_STREAM_ID_PRIVATE_STREAM_2                0xBF

#define MPEG2_STREAM_ID_AUDIO_STREAM                    0xC0
#define MPEG2_STREAM_ID_VIDEO_STREAM                    0xE0

#define MPEG2_STREAM_ID_ECM_STREAM                      0xF0
#define MPEG2_STREAM_ID_EMM_STREAM                      0xF1
#define MPEG2_STREAM_ID_AUX_STREAM                      0xF9
#define MPEG2_STREAM_ID_PROGRAM_STREAM_DIRECTRY         0xFF

/* ISO/IEC 13818-2 Table 6-1 Start code values.  */
#define MPEG2_START_CODE_PICT                           0x00
#define MPEG2_START_CODE_SLICE                          0x01
#define MPEG2_START_CODE_USER_DATA                      0xB2
#define MPEG2_START_CODE_SEQ_HEADER                     0xB3
#define MPEG2_START_CODE_SEQ_ERROR                      0xB4
#define MPEG2_START_CODE_EXTN                           0xB5
#define MPEG2_START_CODE_SEQ_END                        0xB7
#define MPEG2_START_CODE_GOP                            0xB8

/* ISO/IEC 13818-2 Table 6-2 Extension Start Code Identifier codes.  */
#define MPEG2_START_CODE_EXTN_ID_SEQ                    0x10
#define MPEG2_START_CODE_EXTN_ID_SEQ_DISP               0x20
#define MPEG2_START_CODE_EXTN_ID_QUANT_MATRIX           0x30
#define MPEG2_START_CODE_EXTN_ID_COPYRIGHT              0x40
#define MPEG2_START_CODE_EXTN_ID_SEQ_SCALABLE           0x50
#define MPEG2_START_CODE_EXTN_ID_PICT_DISP              0x70
#define MPEG2_START_CODE_EXTN_ID_PICT_CODING            0x80
#define MPEG2_START_CODE_EXTN_ID_PICT_SPATIAL           0x90
#define MPEG2_START_CODE_EXTN_ID_PICT_TEMPORAL          0xA0
#define MPEG2_START_CODE_EXTN_ID_CAMERA_PARAMETERS      0xB0
#define MPEG2_START_CODE_EXTN_ID_ITU_T                  0xC0

#ifdef MEDIA_PROCESSING_EXTENSION

#define  MPEG2_VIDEO_ENC_TABLE_ENTRIES  20
#define  MPEG2_VIDEO_ASP_RATIO_ENTRIES   5
#define  MPEG2_VIDEO_RATE_ENTRIES        8

/* Profile macros copy from ffmpeg/libavcodec/avcodec.h */
#define FFMPEG_PROFILE_MPEG2_422    0
#define FFMPEG_PROFILE_MPEG2_HIGH   1
#define FFMPEG_PROFILE_MPEG2_SS     2
#define FFMPEG_PROFILE_MPEG2_SNR_SCALABLE  3
#define FFMPEG_PROFILE_MPEG2_MAIN   4
#define FFMPEG_PROFILE_MPEG2_SIMPLE 5



typedef struct
{
  slim_ulong  bit_rate;  /* bps */
} mpeg2_profile_system_t;

typedef struct
{
  slim_int  wid;
  slim_int  ht;
} mpeg2_video_res_t;

typedef struct
{
  slim_int  num;
  slim_int  den;
} mpeg2_video_asp_ratio_t;

typedef struct
{
  slim_int  num;
  slim_int  den;
} mpeg2_video_field_rate_t;

typedef struct
{
  slim_int  num;
  slim_int  den;
} mpeg2_video_frame_rate_t;

typedef struct
{
  mpeg2_video_res_t        res;
  mpeg2_video_asp_ratio_t  asrt[MPEG2_VIDEO_ASP_RATIO_ENTRIES];
  mpeg2_video_field_rate_t fir[MPEG2_VIDEO_RATE_ENTRIES];
  mpeg2_video_frame_rate_t frr[MPEG2_VIDEO_RATE_ENTRIES];
} mpeg2_video_enc_parms_t;

typedef struct
{
  mpeg2_video_enc_parms_t  enc_table[MPEG2_VIDEO_ENC_TABLE_ENTRIES];
} mpeg2_profile_video_t;

typedef struct
{
  mpeg2_profile_system_t  system;
  mpeg2_profile_video_t   video;
} mpeg2_profile_t;

#define  MPEG2_PROFILE_AUDIO_SAMPS  20
#define  MPEG2_PROFILE_AUDIO_CHANS  20

typedef struct
{
  slim_int      samp_rates[MPEG2_PROFILE_AUDIO_SAMPS];
  slim_char *   chan_modes[MPEG2_PROFILE_AUDIO_CHANS];
  slim_int      min_bit_rate;
  slim_int      max_bit_rate;
} mpeg2_profile_audio_t;

dlna_profile_t
getDlnaMpeg2Profile(minfo_t *info, video_info_mpeg2_t *dinfo);

#ifdef DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION_SONY_BRAVIA_PROFILING
dlna_profile_t
getDlnaMpeg2ProfileRelaxed(minfo_t *info);
#endif /* DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION_SONY_BRAVIA_PROFILING */


#ifdef MEDIA_PROCESSING_EXTENSION
slim_char *
mpeg2_pinfo_get (minfo_t * mp2);
#endif /* MEDIA_PROCESSING_EXTENSION */


#ifdef MEDIA_PROCESSING_EXTENSION
#ifdef DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION_SONY_BRAVIA_PROFILING

slim_char *
mpeg2_get_dlna_profile_string (dlna_profile_t profile_id);

#else /* DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION_SONY_BRAVIA_PROFILING */

slim_char *
mpeg2_get_dlna_profile_string (minfo_t *);

#endif /* DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION_SONY_BRAVIA_PROFILING */
#endif /* MEDIA_PROCESSING_EXTENSION */


dlna_ret_t
getDlnaMpeg2TsStreamType (minfo_t *info, dlna_minfo_t* stream_type);

#ifdef DEVELOPMENT_ENABLE_CVP_2_SERVER
slim_bool
mpeg2_isTsNaIsoProfile(minfo_t *info, video_info_mpeg2_t *dinfo);
#endif /* DEVELOPMENT_ENABLE_CVP_2_SERVER */

#endif /* MEDIA_PROCESSING_EXTENSION */

/* MP2 buffer size. This may need to grow, but set to 4096 for now.
   Must be at least 256 to guarantee enough data is read to determine
   file type. */
#define MP2_BUFFER_SIZE 4096

/* Size of this buffer has high impact on performance of mpeg2_fix_PS_scr. It should be chosen according to CPU */
#define MPEG2FIX_BUFFER_SIZE 64 * 1024

/* Macros.  */
#define MPEG2_PACKET_TS_HEADER_CHECK(P)                                       \
    ((P)[0] == MPEG2_TS_HEADER_SYNC_BYTE)

#define MPEG2_START_CODE_PREFIX_CHECK(P, L)                                   \
    ((L) >= MPEG2_START_CODE_LEN                                              \
     && (P)[0] == mpeg2_packet_start_code_prefix[0]                           \
     && (P)[1] == mpeg2_packet_start_code_prefix[1]                           \
     && (P)[2] == mpeg2_packet_start_code_prefix[2])

#define MPEG2_START_CODE_CHECK(P, L, V)                                       \
    (MPEG2_START_CODE_PREFIX_CHECK (P, L) && (P)[3] == MPEG2_START_CODE_ ## V)

#define MPEG2_STREAM_ID_CHECK(P, L, V)                                        \
    (MPEG2_START_CODE_PREFIX_CHECK (P, L) && (P)[3] == MPEG2_STREAM_ID_ ## V)

#define MPEG2_PACK_SET_POINTER(B, L)                                          \
    do {                                                                      \
      if ((B) + (L) > lim)                                                    \
        p = lim;                                                              \
      else                                                                    \
        p = &B[(L)];                                                          \
      len -= (L);                                                             \
    } while (0)

#define MPEG2_PACK_GET_STUFFING_LEN(P)                                        \
    ((P)[MPEG2_PACK_STUFFING_LEN_OFFSET] & MPEG2_PACK_STUFFING_LEN_MASK)

#define MPEG2_SYSTEM_GET_LEN(P)                                               \
    ((slim_half) ((P)[MPEG2_SYSTEM_LEN_OFFSET] << 8)                          \
                 | ((P)[MPEG2_SYSTEM_LEN_OFFSET + 1] << 0))

#define MPEG2_PES_GET_LEN(P)                                                  \
    MPEG2_SYSTEM_GET_LEN(P)
#define MPEG2_PES_GET_HEADER_DATA_LEN(P)                                      \
    ((P)[MPEG2_PES_HEADER_DATA_LEN_OFFSET])

#define MPEG2_PICT_HEADER_GET_PICT_CODING(P)                            \
    (((P)[MPEG2_PICT_HEADER_PICT_CODING_OFFSET] & 0x38) >> 3)

#define MPEG2_EXTN_GET_START_CODE(P)                                     \
    ((P)[MPEG2_EXTN_START_CODE_OFFSET] & 0xf0)

#define MPEG2_EXTN_GET_SEQ_PROGRESSIVE(P)                           \
    ((P)[MPEG2_EXTN_SEQ_PROGRESSIVE_OFFSET] & 0x08)

#define MPEG2_EXTN_GET_SEQ_DISP_LEN(P)                           \
    (MPEG2_EXTN_SEQ_DISP_MIN_LEN                                 \
     + ((P)[MPEG2_EXTN_SEQ_DISP_COLOR_DESC_OFFSET] & 0x01        \
        ? 3 : 0))
#define MPEG2_EXTN_GET_SEQ_DISP_VIDEO_FORMAT(P)                  \
    (((P)[MPEG2_EXTN_SEQ_DISP_COLOR_DESC_OFFSET] & 0x0E) >> 1)

#define MPEG2_EXTN_GET_SEQ_SCALABLE_MODE(P)                         \
    (((P)[MPEG2_EXTN_START_CODE_OFFSET] & 0x0C) >> 2)
#define MPEG2_EXTN_GET_SEQ_SCALABLE_LAYER_ID(P)                     \
    ((((P)[MPEG2_EXTN_START_CODE_OFFSET] & 0x03) << 2)                   \
     | (((P)[MPEG2_EXTN_START_CODE_OFFSET + 1] & 0xC0) >> 6))

#define MPEG2_EXTN_GET_PICT_CODING_STRUCTURE(P)                       \
    ((P)[MPEG2_EXTN_PICT_CODING_STRUCTURE_OFFSET] & 0x03)
#define MPEG2_EXTN_GET_PICT_CODING_TOP_FIELD_FIRST(P)                 \
    ((P)[MPEG2_EXTN_PICT_CODING_TOP_FIELD_FIRST_OFFSET]               \
     & MPEG2_EXTN_PICT_CODING_TOP_FIELD_FIRST)
#define MPEG2_EXTN_GET_PICT_CODING_FRAME_PRED_FRAME_DCT(P)            \
    ((P)[MPEG2_EXTN_PICT_CODING_TOP_FIELD_FIRST_OFFSET]               \
     & MPEG2_EXTN_PICT_CODING_FRAME_PRED_FRAME_DCT)
#define MPEG2_EXTN_GET_PICT_CODING_REPEAT_FIRST_FIELD(P)              \
    ((P)[MPEG2_EXTN_PICT_CODING_TOP_FIELD_FIRST_OFFSET]               \
     & MPEG2_EXTN_PICT_CODING_REPEAT_FIRST_FIELD)
#define MPEG2_EXTN_GET_PICT_CODING_LEN(P)                             \
    ((P)[MPEG2_EXTN_PICT_CODING_TOP_FIELD_FIRST_OFFSET + 1]           \
     & MPEG2_EXTN_PICT_CODING_COMPOSITE_FLAG                          \
     ? MPEG2_EXTN_PICT_CODING_MIN_LEN                                 \
     : MPEG2_EXTN_PICT_CODING_MAX_LEN)

#define MPEG2_EXTN_GET_PICT_DISP_NUMBER_OF_FRAME_CENTER_OFFSET(I)  \
    ((I)->vid.video_flags & MPEG2_VIDEO_FLAG_PROGRESSIVE_SEQ                 \
     ? ((I)->vid.video_flags & MPEG2_VIDEO_FLAG_REPEAT_FIRST_FIELD                \
        ? ((I)->vid.video_flags & MPEG2_VIDEO_FLAG_TOP_FIELD_FIRST ? 3 : 2) : 1)  \
     : ((I)->img.picture_structure ? 1                                            \
        : ((I)->vid.video_flags & MPEG2_VIDEO_FLAG_REPEAT_FIRST_FIELD ? 3 : 2)))

#define MPEG2_GOP_GET_HOUR(P)    (((P)[4] & 0x7C) >> 2)
#define MPEG2_GOP_GET_MIN(P)    ((((P)[4] & 0x03) << 4)|(((P)[5] & 0xF0) >> 4))
#define MPEG2_GOP_GET_SEC(P)    ((((P)[5] & 0x07) << 3)|(((P)[6] & 0xC0) >> 5))
#define MPEG2_GOP_GET_FRAME(P)    ((((P)[6] & 0x1F) << 1)|(((P)[7] & 0x80) >> 7))


/* for video_flags below */
#define MPEG2_VIDEO_FLAG_PROGRESSIVE_SEQ        (1 << 0)
#define MPEG2_VIDEO_FLAG_TOP_FIELD_FIRST        (1 << 1)
#define MPEG2_VIDEO_FLAG_REPEAT_FIRST_FIELD     (1 << 2)

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_bool
mpeg2_PS_time_seek_adjust(slim_char *in_fullpath, dlna_uint64 *in_file_size,
                          dlna_timeval *in_seek_time, dlna_uint64 *inout_seek_bytes);

dlna_minfo_t
mpeg2_stream_type_check(dlna_file_t);

slim_bool
register_media_info_mpeg2(media_manager_t *mim);

slim_bool
mpeg2_fix_PS_scr(slim_char *in_full_path);

dlna_minfo_t
getDlnaMpeg2TsRegion(minfo_t* info);

#ifdef DEVELOPMENT_NFLC_PROFILER
dlna_ret_t
mpeg2_ts_get_stream_type (minfo_t *in_info);

slim_int
mpeg2_ts_get_definition (minfo_t *in_info, dlna_minfo_t in_region, dlna_minfo_t in_stream_type);

dlna_profile_t
mpeg2_ts_get_region_specific_profile (dlna_minfo_t in_region, dlna_minfo_t in_definition, dlna_minfo_t in_stream_type, audio_codec_t in_audio_codec);
#endif /* DEVELOPMENT_NFLC_PROFILER */



#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_INFO_MPEG2_H */
