/*
 * \file dms_publish_storage_api.h
 * \brief dms publish list header
 *
 * Copyright (C) 2009-2014 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_DMS_PUBLISH_STORAGE_API_H_
#define NFLC_DMS_PUBLISH_STORAGE_API_H_

#include <dlna_peer.h>
#include <dms_api.h>
#ifdef HAVE_DTCP
#include <nflc_drm_api.h>
#endif /*HAVE_DTCP*/

enum {
  DMS_STORAGE_LOCATION_TYPE_LOCAL,
  DMS_STORAGE_LOCATION_TYPE_CENTRAL
};

/**
 * @addtogroup Enumerators
 */
/*@{*/

/*!
    TDMSStorageLocationType represents the location type of added share

    <table>
    <tr>
        <td><b>Definition</b></td>
        <td><b>Description</b></td>
    </tr>
    <tr>
        <td>DMS_STORAGE_LOCATION_TYPE_LOCAL</td>
        <td>Location is local</td>
    </tr>
    <tr>
        <td>DMS_STORAGE_LOCATION_TYPE_CENTRAL</td>
        <td>Location is central</td>
    </tr>
    </table>

*/
typedef slim_int TDMSStorageLocationType;

/*@}*/

enum {
  NFLC_DMS_CONTENT_REFERENCE_TYPE_THUMBNAIL,
  NFLC_DMS_CONTENT_REFERENCE_TYPE_SUBTITLE,
  NFLC_DMS_CONTENT_REFERENCE_TYPE_COVER,
  NFLC_DMS_CONTENT_REFERENCE_TYPE_TRANSCODED
};
/**
 * @addtogroup Enumerators
 */
/*@{*/

/*!
    TDMSContentRefType lists the type of references available for the content being published

    <table>
    <tr>
        <td><b>Definition</b></td>
        <td><b>Description</b></td>
    </tr>
    <tr>
        <td>NFLC_DMS_CONTENT_REFERENCE_TYPE_THUMBNAIL</td>
        <td>Thumbnail type reference</td>
    </tr>
    <tr>
        <td>NFLC_DMS_CONTENT_REFERENCE_TYPE_SUBTITLE</td>
        <td>Subtitle type reference</td>
    </tr>
    <tr>
        <td>NFLC_DMS_CONTENT_REFERENCE_TYPE_COVER</td>
        <td>Cover Image (Albumart) type reference</td>
    </tr>
    <tr>
        <td>NFLC_DMS_CONTENT_REFERENCE_TYPE_TRANSCODED</td>
        <td>Transcoded format type reference</td>
    </tr>
    </table>

*/
typedef slim_int TDMSContentRefType;
/*@}*/

#ifdef HAVE_DTCP
enum {
	DLNA_DTCP_CCI_COPY_FREE,
	DLNA_DTCP_CCI_COPY_FREE_EPN_ASSERTED,
	DLNA_DTCP_CCI_COPY_ONE_GEN,
	DLNA_DTCP_CCI_NO_MORE_COPIES,
	DLNA_DTCP_CCI_COPY_NEVER
};

/**
 * @addtogroup Enumerators
 */
/*@{*/

/*!
    dlna_dtcp_cci - Copy Control Information

    <table>
    <tr>
        <td><b>Definition</b></td>
        <td><b>Description</b></td>
    </tr>
    <tr>
        <td>DLNA_DTCP_CCI_COPY_FREE</td>
        <td>Copy Freely</td>
    </tr>
    <tr>
        <td>DLNA_DTCP_CCI_COPY_FREE_EPN_ASSERTED</td>
        <td>Copy Freely with EPN Asserted</td>
    </tr>
    <tr>
        <td>DLNA_DTCP_CCI_COPY_ONE_GEN</td>
        <td>Copy One Generation</td>
    </tr>
    <tr>
        <td>DLNA_DTCP_CCI_NO_MORE_COPIES</td>
        <td>No More Copies</td>
    </tr>
    <tr>
        <td>DLNA_DTCP_CCI_COPY_NEVER</td>
        <td>Copy Never</td>
    </tr>
    </table>

*/
typedef slim_int dlna_dtcp_cci;
/*@}*/

enum {
	DLNA_DTCP_RETENTION_FOREVER,
	DLNA_DTCP_RETENTION_1WEEK,
	DLNA_DTCP_RETENTION_2DAYS,
	DLNA_DTCP_RETENTION_1DAYS,
	DLNA_DTCP_RETENTION_12HOURS,
	DLNA_DTCP_RETENTION_6HOURS,
	DLNA_DTCP_RETENTION_3HOURS,
	DLNA_DTCP_RETENTION_90MINUTES
};

/**
 * @addtogroup Enumerators
 */
/*@{*/

/*!
    dlna_dtcp_retention - Retention State

    <table>
    <tr>
        <td><b>Definition</b></td>
        <td><b>Description</b></td>
    </tr>
    <tr>
        <td>DLNA_DTCP_RETENTION_FOREVER</td>
        <td>Forever</td>
    </tr>
    <tr>
        <td>DLNA_DTCP_RETENTION_1WEEK</td>
        <td>1 Week</td>
    </tr>
    <tr>
        <td>DLNA_DTCP_RETENTION_2DAYS</td>
        <td>2 Days</td>
    </tr>
    <tr>
        <td>DLNA_DTCP_RETENTION_1DAYS</td>
        <td>1 Day</td>
    </tr>
    <tr>
        <td>DLNA_DTCP_RETENTION_12HOURS</td>
        <td>12 Hours</td>
    </tr>
    <tr>
        <td>DLNA_DTCP_RETENTION_6HOURS</td>
        <td>6 Hours</td>
    </tr>
    <tr>
        <td>DLNA_DTCP_RETENTION_3HOURS</td>
        <td>3 Hours</td>
    </tr>
    <tr>
        <td>DLNA_DTCP_RETENTION_90MINUTES</td>
        <td>90 Minutes</td>
    </tr>
    </table>

*/
typedef slim_int dlna_dtcp_retention;
/*@}*/
#endif

/**
 * @addtogroup Macros
 */
/*@{*/
/*!
 * NFLC Published Content Flags, more than one flag can be set for a single content. Please use SET_FLAG macro to set the flags
  <table>
         <tr>
                <td><b>Member</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>NFLC_CONTENT_FLAG_NONE</td>
                <td>(0) None</td>
        </tr>
        <tr>
                <td>NFLC_CONTENT_FLAG_STREAMING_LIVE</td>
                <td>(1) Flag to set streaming online content, the content metadata is required to be input and content is virtually represented</td>
        </tr>
         <tr>
                <td>NFLC_CONTENT_FLAG_STREAMING_RECORDED</td>
                <td>(2) Flag to set streaming local content (eg PVR recorded content) as it will be locally available and saved to database</td>
        </tr>
        <tr>
                <td>NFLC_CONTENTS_FLAG_DTCP_PROTECTED</td>
                <td>(3) Flag to set Content as dtcp-ip protected</td>
        </tr>
        <tr>
                <td>NFLC_CONTENTS_FLAG_CADRM_PROTECTED</td>
                <td>(3) Flag to set Content as CA/DRM protected</td>
        </tr>
</table>
 */
#define NFLC_CONTENT_FLAG_NONE                  (1 << 0)
#define NFLC_CONTENT_FLAG_STREAMING_LIVE        (1 << 1)
#define NFLC_CONTENT_FLAG_STREAMING_RECORDED    (1 << 2)
#define NFLC_CONTENTS_FLAG_DTCP_PROTECTED       (1 << 3)
#define NFLC_CONTENTS_FLAG_CADRM_PROTECTED      (1 << 4)
#define NFLC_CONTENT_FLAG_STREAMING_LIVECONTENT (1 << 5)/* DLNA LRADA Content */
/*@}*/

/**
 * @addtogroup Macros
 */
/*@{*/
/*!
 * NFLC Published Content Flags, more than one flag can be set for a single content. Please use SET_FLAG macro to set the flags
  <table>
         <tr>
                <td><b>Member</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>NFLC_DMS_CONTENT_SEEK_TYPE_BYTE</td>
                <td>Flag to set Content as supporting Byte seek</td>
        </tr>
        <tr>
                <td>NFLC_DMS_CONTENT_SEEK_TYPE_TIME</td>
                <td>(3) Flag to set Content as supporting Time seek</td>
        </tr>
</table>
 */
#ifdef DEVELOPMENT_ENABLE_HTTP_STREAMING_SEEK
#define NFLC_DMS_CONTENT_SEEK_TYPE_BYTE       (1<<0)
#define NFLC_DMS_CONTENT_SEEK_TYPE_TIME       (1<<1)
#define NFLC_DMS_CONTENT_SEEK_TYPE_LOP_BYTE   (1<<2)
#define NFLC_DMS_CONTENT_SEEK_TYPE_LOP_TIME   (1<<3)
#endif
/*@}*/

#ifndef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
struct _TDMSPublishUserMetadata {
  struct _TDMSPublishUserMetadata *prev;
  struct _TDMSPublishUserMetadata *next;
  slim_char *name;
  slim_char *value;
};
#endif /* !DEVELOPMENT_ENABLE_PUBLISH_CONTENT */
/**
 * @addtogroup Structures
 */
/*@{*/

/*!
    TDMSPublishUserMetadata holds the name-value pair of custom metadata for the Published content

    <table>
        <tr>
                <td><b>Member</b></td>
                <td><b>Data Type</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>name</td>
                <td>slim_char</td>
                <td>(Required)Name of the user metadata</td>
        </tr>
        <tr>
                <td>value</td>
                <td>slim_char</td>
                <td>Value of the user metadata</td>
        </tr>
    </table>
*/
typedef struct _TDMSPublishUserMetadata TDMSPublishUserMetadata;
typedef List(TDMSPublishUserMetadata*) TDMSPublishUserMetadataList;
/*@}*/

struct _TDMSPublishContentRef {
  struct _TDMSPublishContentRef *prev;
  struct _TDMSPublishContentRef *next;
  TDMSContentRefType ref_type;
  TDMSContentType ref_content_type;
  slim_word width;
  slim_word height;
  slim_word samplingrate;
  slim_word bitrate;
  slim_char *mime;
  slim_char *duration_str;
  slim_char *ref_url;
};
/**
 * @addtogroup Structures
 */
/*@{*/

/*!
    TDMSPublishContent structure for the content to be published

    <table>
        <tr>
                <td><b>Member</b></td>
                <td><b>Data Type</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>ref_type</td>
                <td>TDMSContentRefType</td>
                <td>Content Reference Type</td>
        </tr>
        <tr>
                <td>ref_content_type</td>
                <td>TDMSContentType</td>
                <td>Type of Reference (For transcoded reference it can be of any type listed in TDMSContentType</td>
        </tr>
        <tr>
                <td>width</td>
                <td>slim_word</td>
                <td>Width of the reference (Image/Video)</td>
        </tr>
        <tr>
                <td>height</td>
                <td>slim_word</td>
                <td>Height of the reference (Image/Video)</td>
        </tr>
        <tr>
                <td>samplingrate</td>
                <td>slim_word</td>
                <td>Sampling rate of the reference</td>
        </tr>
        <tr>
                <td>bitrate</td>
                <td>slim_word</td>
                <td>Bitrate of the reference</td>
        </tr>
        <tr>
                <td>mime</td>
                <td>slim_char</td>
                <td>reference mime (Internet Media Type)</td>
        </tr>
        <tr>
                <td>duration_str</td>
                <td>slim_char</td>
                <td>Duration String. The Form of the duration string is H+:MM:SS[.F+] or H+:MM:SS[.F0/F1],
                     where:
                    \li H+: one or more digits to indicate elapsed hours,
                    \li MM: exactly 2 digits to indicate minutes (00 to 59),
                    \li SS: exactly 2 digits to indicate seconds (00 to 59),
                    \li F+: any number of digits (including no digits) to indicate fractions of seconds,
                    \li F0/F1: a fraction, with F0 and F1 at least one digit long, and F0 < F1.
                    \li The string MAY be preceded by a “+” or “-” sign, and the decimal point itself MUST be omitted if there
                    \li are no fractional second digits.  </td>
        </tr>
        <tr>
                <td>ref_url</td>
                <td>slim_char</td>
                <td>url to the reference location (filepath for local references)</td>
        </tr>
    </table>
*/
typedef struct _TDMSPublishContentRef TDMSPublishContentRef;
/*@}*/

#ifndef DEVELOPMENT_ENABLE_PUBLISH_CONTENT

struct _TDMSAudioInfo {
  slim_word audio_profile;
  slim_word bits_per_samp;
  slim_word audio_ave_bitrate;
  slim_word audio_max_bitrate;
  slim_word audio_encoding_type;
  slim_word quantization;
  slim_word channel_mode_chans;
  slim_word channel_mode_subs;
  slim_word wma_pn_info;
  slim_bool is_mp4_pn_adts;
  slim_bool is_mp4_pn_ltp;
  slim_bool has_mp4_pn_sbr;
  slim_byte mp4_pn_audobjtype;
  slim_word mp4_pn_audio_format;
};
/**
 * @addtogroup Structures
 */
/*@{*/

/*!
    TDMSAudioInfo structure for the audio information to be stored

    <table>
        <tr>
                <td><b>Member</b></td>
                <td><b>Data Type</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>audio_profile</td>
                <td>slim_word</td>
                <td>DLNA Audio profile</td>
        </tr>
        <tr>
                <td>bits_per_samp</td>
                <td>slim_word</td>
                <td>Sampling rate</td>
        </tr>
        <tr>
                <td>audio_ave_bitrate</td>
                <td>slim_word</td>
                <td>Audio average bitrate</td>
        </tr>
        <tr>
                <td>audio_max_bitrate</td>
                <td>slim_word</td>
                <td>Audio max bitrate</td>
        </tr>
        <tr>
                <td>audio_encoding_type</td>
                <td>slim_word</td>
                <td>\li Audio encoding type
                    \li  - constant bitrate
                    \li  - variable bitrate </td>
        </tr>
        <tr>
                <td>quantization</td>
                <td>slim_word</td>
                <td>Quantization</td>
        </tr>
        <tr>
                <td>channel_mode_chans</td>
                <td>slim_word</td>
                <td>Channnel mode chans</td>
        </tr>
        <tr>
                <td>channel_mode_subs</td>
                <td>slim_word</td>
                <td>Channnel mode subs</td>
        </tr>
        <tr>
                <td>wma_pn_info</td>
                <td>slim_word</td>
                <td>WMA audio format</td>
        </tr>
        <tr>
                <td>is_mp4_pn_adts</td>
                <td>slim_bool</td>
                <td>If the content is MP4_PN adts</td>
        </tr>
        <tr>
                <td>is_mp4_pn_ltp</td>
                <td>slim_bool</td>
                <td>If the content is MP4_PN ltp</td>
        </tr>
        <tr>
                <td>has_mp4_pn_sbr</td>
                <td>slim_bool</td>
                <td>If the content has MP4_PN sbr</td>
        </tr>
        <tr>
                <td>mp4_pn_audobjtype</td>
                <td>slim_byte</td>
                <td>MP4_PN audobjtype</td>
        </tr>
        <tr>
                <td>mp4_pn_audio_format</td>
                <td>slim_word</td>
                <td>MP4_PN audio format</td>
        </tr>
    </table>
*/
typedef struct _TDMSAudioInfo dms_audio_info;
/*@}*/

struct _TDMSVideoInfo {
  slim_word video_profile;
  slim_word video_codec_profile;
  slim_word dlna_video_codec_profile;
  slim_word video_res_width;
  slim_word video_res_height;
  slim_word video_framerate_num;
  slim_word video_framerate_den;
  slim_word video_fieldrate_num;
  slim_word video_fieldrate_den;
  slim_word video_bitrate_type;
  slim_ulong video_bitrate_value;
  slim_word video_max_bitrate_type;
  slim_ulong video_max_bitrate_value;
  slim_word video_aspect_ratio_num;
  slim_word video_aspect_ratio_den;
};
/**
 * @addtogroup Structures
 */
/*@{*/

/*!
    TDMSVideoInfo structure for the video information to be stored

    <table>
        <tr>
                <td><b>Member</b></td>
                <td><b>Data Type</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>video_profile</td>
                <td>slim_word</td>
                <td>DLNA Video profile</td>
        </tr>
        <tr>
                <td>video_codec_profile</td>
                <td>slim_word</td>
                <td>Video codec profile</td>
        </tr>
        <tr>
                <td>dlna_video_codec_profile</td>
                <td>slim_word</td>
                <td>DLNA Video codec profile</td>
        </tr>
        <tr>
                <td>video_res_width</td>
                <td>slim_word</td>
                <td>Video resolution width</td>
        </tr>
        <tr>
                <td>video_res_height</td>
                <td>slim_word</td>
                <td>Video resolution height</td>
        </tr>
        <tr>
                <td>video_framerate_num</td>
                <td>slim_word</td>
                <td>Number of the Video framerate</td>
        </tr>
        <tr>
                <td>video_framerate_den</td>
                <td>slim_word</td>
                <td>Video framerate den</td>
        </tr>
        <tr>
                <td>video_fieldrate_num</td>
                <td>slim_word</td>
                <td>Number of the Video fieldrate</td>
        </tr>
        <tr>
                <td>video_fieldrate_den</td>
                <td>slim_word</td>
                <td>Video fieldrate den</td>
        </tr>
        <tr>
                <td>video_bitrate_type</td>
                <td>slim_word</td>
                <td>Video bitrate type</td>
        </tr>
        <tr>
                <td>video_bitrate_value</td>
                <td>slim_ulong</td>
                <td>Video bitrate value</td>
        </tr>
        <tr>
                <td>video_max_bitrate_type</td>
                <td>slim_word</td>
                <td>Video max bitrate type</td>
        </tr>
        <tr>
                <td>video_max_bitrate_value</td>
                <td>slim_ulong</td>
                <td>Video max bitrate value</td>
        </tr>
        <tr>
                <td>video_aspect_ratio_num</td>
                <td>slim_word</td>
                <td>Number of the Video aspect ratio</td>
        </tr>
        <tr>
                <td>video_aspect_ratio_den</td>
                <td>slim_word</td>
                <td>Video aspect ratio den</td>
        </tr>
    </table>
*/
typedef struct _TDMSVideoInfo dms_video_info;
/*@}*/



struct _TDMSMpeg2Info {
  slim_word  tv_system;
  slim_word  video_streams;
  slim_word  audio_streams;
  slim_word  mpeg2_type;
  slim_ulong sys_bitrate;
  slim_word  pack_size;
  slim_bool  proper_pack_header;
  slim_bool  proper_audio_pack;
  slim_bool  proper_video_pack;
  slim_bool  proper_video_pack_header;
  slim_bool  proper_system_header;
  slim_bool  has_ifo;
  slim_ulong content_length;
  slim_ulong content_length_ifo;
  slim_byte  mpeg2_stream_id;
  slim_bool  proper_sequence_header;
  slim_word  gop_display_fields;
  slim_word  gop_display_frames;
  slim_bool  has_low_delay;
  slim_bool  has_pts;
  slim_bool  has_dts;
  slim_word  number_of_programs;
  slim_word  interlacing_info;
  slim_word  mpeg2_audio_profile;
  slim_byte  ac3_stream_id;
  slim_bool  ac3_proper_pack_header;
  slim_bool  ac3_has_pts;
  slim_word  region;
  slim_word  stream_type;
  slim_word  audio_codec;
};
/**
 * @addtogroup Structures
 */
/*@{*/

/*!
    TDMSMpeg2Info structure for the mpeg2 information to be stored

    <table>
        <tr>
                <td><b>Member</b></td>
                <td><b>Data Type</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>tv_system</td>
                <td>slim_word</td>
                <td>\li TV system
                    \li  - PAL
                    \li  - NTSC
                    \li  - SD
                    \li  - HD </td>
        </tr>
        <tr>
                <td>video_streams</td>
                <td>slim_word</td>
                <td>Number of video streams</td>
        </tr>
        <tr>
                <td>audio_streams</td>
                <td>slim_word</td>
                <td>Number of audio streams</td>
        </tr>
        <tr>
                <td>mpeg2_type</td>
                <td>slim_word</td>
                <td>\li MPEG2 type
                    \li  - PS
                    \li  - TS </td>
        </tr>
        <tr>
                <td>sys_bitrate</td>
                <td>slim_ulong</td>
                <td>System bitrate</td>
        </tr>
        <tr>
                <td>pack_size</td>
                <td>slim_word</td>
                <td>Pack size : must be 2048 bytes</td>
        </tr>
        <tr>
                <td>proper_pack_header</td>
                <td>slim_bool</td>
                <td>Proper pack header</td>
        </tr>
        <tr>
                <td>proper_audio_pack</td>
                <td>slim_bool</td>
                <td>Proper audio pack</td>
        </tr>
        <tr>
                <td>proper_video_pack</td>
                <td>slim_bool</td>
                <td>Proper video pack</td>
        </tr>
        <tr>
                <td>proper_video_pack_header</td>
                <td>slim_bool</td>
                <td>Proper video pack header</td>
        </tr>
        <tr>
                <td>proper_system_header</td>
                <td>slim_bool</td>
                <td>Proper system header</td>
        </tr>
        <tr>
                <td>has_ifo</td>
                <td>slim_bool</td>
                <td>If the content has IFO file</td>
        </tr>
        <tr>
                <td>content_length</td>
                <td>slim_ulong</td>
                <td>Content length</td>
        </tr>
        <tr>
                <td>content_length_ifo</td>
                <td>slim_ulong</td>
                <td>Content length from IFO file</td>
        </tr>
        <tr>
                <td>mpeg2_stream_id</td>
                <td>slim_byte</td>
                <td>MPEG2 stream ID</td>
        </tr>
        <tr>
                <td>proper_sequence_header</td>
                <td>slim_bool</td>
                <td>Proper sequence header</td>
        </tr>
        <tr>
                <td>gop_display_fields</td>
                <td>slim_word</td>
                <td>Display fields of GOP info</td>
        </tr>
        <tr>
                <td>gop_display_frames</td>
                <td>slim_word</td>
                <td>Display frames of GOP info</td>
        </tr>
        <tr>
                <td>has_low_delay</td>
                <td>slim_bool</td>
                <td>"low delay" sequences are not permitted</td>
        </tr>
        <tr>
                <td>has_pts</td>
                <td>slim_bool</td>
                <td>If the content has PTS</td>
        </tr>
        <tr>
                <td>has_dts</td>
                <td>slim_bool</td>
                <td>If the content has DTS</td>
        </tr>
        <tr>
                <td>number_of_programs</td>
                <td>slim_word</td>
                <td>Number of programs</td>
        </tr>
        <tr>
                <td>interlacing_info</td>
                <td>slim_word</td>
                <td>\li Interlacing Information
                    \li  - Unknown
                    \li  - Progressive
                    \li  - Interlaced </td>
        </tr>
        <tr>
                <td>mpeg2_audio_profile</td>
                <td>slim_word</td>
                <td>\li MPEG2 audio profile
                    \li  - XA3
                    \li  - DTS
                    \li  - DTSHD
                    \li  - DTSHD_HRA
                    \li  - DTSHD_MA </td>
        </tr>
        <tr>
                <td>ac3_stream_id</td>
                <td>slim_byte</td>
                <td>AC3 stream ID</td>
        </tr>
        <tr>
                <td>ac3_proper_pack_header</td>
                <td>slim_bool</td>
                <td>AC3 proper pack header</td>
        </tr>
        <tr>
                <td>ac3_has_pts</td>
                <td>slim_bool</td>
                <td>AC3 has PTS</td>
        </tr>
        <tr>
                <td>region</td>
                <td>slim_word</td>
                <td>\li REGION
                    \li  - JP
                    \li  - NA
                    \li  - EU
                    \li  - KO </td>
        </tr>
        <tr>
                <td>stream_type</td>
                <td>slim_word</td>
                <td>MPEG2 stream type
                    \li  - NOTS
                    \li  - VALID_TS
                    \li  - INVALID_TS
                    \li  - NOTS_JP
                    \li  - VALID_TS_JP
                    \li  - INVALID_TS_JP
                    \li  - ARIB_PARTIAL_TS </td>
        </tr>
        <tr>
                <td>audio_codec</td>
                <td>slim_word</td>
                <td>Audio codec profile
                    \li  - AC_AAC
                    \li  - AC_MPEG1_L2 </td>
        </tr>
    </table>
*/
typedef struct _TDMSMpeg2Info dms_mpeg2_info;
/*@}*/


struct _TDMSPublishContent {
  slim_char *parent_id;
#ifdef DEVELOPMENT_PUBLISH_ONLINE_RECORDED_CONTENT_API
  slim_char *X_id;
#endif
  slim_word flags;
  TDMSContentClassType content_class;
  TDMSContentType content_type;
  slim_bool readable;
  slim_char *url;
  dlna_uint64 size;
  dlna_time_t date;
  slim_char *title;
  slim_char *album;
  slim_char *creator;
  slim_char *genre;
  slim_char *artist;
  slim_char *composer;
  slim_int  track_num;
  slim_char *duration_str;
  slim_word width;
  slim_word height;
  slim_word bitrate;
  slim_word channels;
  slim_word samplingrate;
  slim_char *rating;
  slim_char *mime;
  slim_word channel_number; /* upnp_channelNr */
  slim_char *dlna_protocol_name;
  List(TDMSPublishUserMetadata*) user_metadata_list;
  List(TDMSPublishContentRef*) references_list;
  slim_bool is_protected;
#ifdef HAVE_DTCP
  minfo_drm_cci cci; /*Copy Control Information*/
#endif /*HAVE_DTCP*/
#ifdef DEVELOPMENT_ENABLE_HTTP_STREAMING_SEEK
  slim_word seek_type;
#endif

  dms_audio_info audio_info;
  dms_video_info video_info;
  dms_mpeg2_info mpeg2_info;

  slim_word system_prof;
  slim_word system_bitrate;

};
#endif /* !DEVELOPMENT_ENABLE_PUBLISH_CONTENT */
/**
 * @addtogroup Structures
 */
/*@{*/

/*!
    TDMSPublishContent structure for the content to be published

    <table>
        <tr>
                <td><b>Member</b></td>
                <td><b>Data Type</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>parent_id</td>
                <td>slim_char</td>
                <td>Parent ID (Folder ID) to which the content be added, For Local content, it is not required</td>
        </tr>
        <tr>
                <td>flags</td>
                <td>slim_word</td>
                <td>Content Flags. See FLAGS Macros for possible Macor options</td>
        </tr>
        <tr>
                <td>content_class</td>
                <td>TDMSContentType</td>
                <td>Content class to be published viz. image/audio/video, For Local content, it is not required</td>
        </tr>
        <tr>
                <td>content_type</td>
                <td>TDMSContentType</td>
                <td>Type of Content to be published, For Local content, it is not required</td>
        </tr>
        <tr>
                <td>readable</td>
                <td>slim_bool</td>
                <td>\li If the content is readable, local,
                    \li set this to slim_true if the content can be readable(head) for parsing by DMS
                    \li if this is set to slim_true, it is not required to add other metadata </td>
        </tr>
        <tr>
                <td>url</td>
                <td>slim_char</td>
                <td>\li url of the content to be published
                    \li For Local content, the fullpath starting with '/' should be set to url</td>
        </tr>
        <tr>
                <td>date</td>
                <td>dlna_time_t</td>
                <td>Creation Date/Last Modified Date of the Content, For Local content, it is not required</td>
        </tr>
        <tr>
                <td>title</td>
                <td>slim_char</td>
                <td>Title of the content or Filename, For Local content, it is not required</td>
        </tr>
        <tr>
                <td>album</td>
                <td>slim_char</td>
                <td>Album Name or Folder Name, For Local content, it is not required</td>
        </tr>
        <tr>
                <td>creator</td>
                <td>slim_char</td>
                <td>Creator of the Content, For Local content, it is not required</td>
        </tr>
        <tr>
                <td>artist</td>
                <td>slim_char</td>
                <td>Artist/Actor of the content, For Local content, it is not required</td>
        </tr>
        <tr>
                <td>genre</td>
                <td>slim_char</td>
                <td>Genre of the content, For Local content, it is not required</td>
        </tr>
        <tr>
                <td>composer</td>
                <td>slim_char</td>
                <td>Composer/Author of the content, For Local content, it is not required</td>
        </tr>
        <tr>
                <td>tracknum</td>
                <td>slim_char</td>
                <td>Track Number of the content (audio/video), For Local content, it is not required</td>
        </tr>
        <tr>
                <td>duration_str</td>
                <td>slim_char</td>
                <td>Duration String, For Local content, it is not required
                    \li The Form of the duration string is H+:MM:SS[.F+] or H+:MM:SS[.F0/F1],where:
                    \li H+: one or more digits to indicate elapsed hours,
                    \li MM: exactly 2 digits to indicate minutes (00 to 59),
                    \li SS: exactly 2 digits to indicate seconds (00 to 59),
                    \li F+: any number of digits (including no digits) to indicate fractions of seconds,
                    \li F0/F1: a fraction, with F0 and F1 at least one digit long, and F0 < F1.
                    \li The string MAY be preceded by a “+” or “-” sign, and the decimal point itself MUST be omitted if there
                    \li are no fractional second digits.  </td>
        </tr>
        <tr>
                <td>width</td>
                <td>slim_word</td>
                <td>width of the content (Image/video), For Local content, it is not required</td>
        </tr>
        <tr>
                <td>height</td>
                <td>slim_word</td>
                <td>Height of the content (Image/Video), For Local content, it is not required</td>
        </tr>
        <tr>
                <td>bitrate</td>
                <td>slim_word</td>
                <td>Bitrate of the content (Audio/Video), For Local content, it is not required</td>
        </tr>
        <tr>
                <td>channels</td>
                <td>slim_word</td>
                <td>Number of channels, For Local content, it is not required</td>
        </tr>
        <tr>
                <td>samplingrate</td>
                <td>slim_word</td>
                <td>Sampling rate of the content, For Local content, it is not required</td>
        </tr>
        <tr>
                <td>rating</td>
                <td>slim_char</td>
                <td>Content rating (or any user rating for the content), For Local content, it is not required</td>
        </tr>
        <tr>
                <td>mime</td>
                <td>slim_char</td>
                <td>Mime Type (Internet Media Type) of the content, For Local content, it is not required</td>
        </tr>
        <tr>
                <td>references_list</td>
                <td>List(TDMSPublishContentRef*)</td>
                <td>List of references for the content to be published, For Local content, it is not required</td>
        </tr>
        <tr>
                <td>cci</td>
                <td>minfo_drm_cci</td>
                <td>\li DRM: Copy Control Information,
                    \li Set this if the CCI is pre-determined and the content needs to be DTCP protected</td>
        </tr>
        <tr>
                <td>seek_type</td>
                <td>slim_word</td>
                <td>Seek Type, Capability of Time seek and Byte seek </td>
        </tr>
        <tr>
                <td>audio_info</td>
                <td>dms_audio_info</td>
                <td>Audio information of the content</td>
        </tr>
        <tr>
                <td>video_info</td>
                <td>dms_video_info</td>
                <td>Video information of the content</td>
        </tr>
        <tr>
                <td>mpeg2_info</td>
                <td>dms_mpeg2_info</td>
                <td>MPEG2 information of the content</td>
        </tr>
        <tr>
                <td>system_prof</td>
                <td>slim_word</td>
                <td>System portion profile type
                    \li  - MP4
                    \li  - MPEG2_TS
                    \li  - MPEG2_TS_T
                    \li  - MPEG2_TS_ISO
                    \li  - ASF
                    \li  - 3GPP </td>
        </tr>
        <tr>
                <td>system_bitrate</td>
                <td>slim_word</td>
                <td>System bitrate</td>
        </tr>
    </table>
*/
typedef struct _TDMSPublishContent TDMSPublishContent;
/*@}*/
#ifndef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
struct _TDMSObjectRights {
	slim_bool is_drm_protected;
	slim_bool allow_dtcp_protection;
	dlna_time_t subscription_time;
#ifdef HAVE_DTCP
	dlna_dtcp_cci cci;
	dlna_dtcp_retention retention_state;
#endif
	slim_int concurrent_viewing;
	slim_int playcount;
	slim_bool allow_distribution;
	slim_int no_of_devices_allowed;
};
#endif /* !DEVELOPMENT_ENABLE_PUBLISH_CONTENT */
/**
 * @addtogroup Macros
 */
/*@{*/
/*!
 * Specifies unlimited number of devices allowed for distribution of the content in home network.
  <table>
         <tr>
                <td><b>Member</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>DLNA_DEVICES_ALLOWED_UNLIMITED</td>
                <td>Unlimited</td>
        </tr>
</table>
 */
#define DLNA_DEVICES_ALLOWED_UNLIMITED (-1)
/*@}*/

/**
 * @addtogroup Structures
 */
/*@{*/

/*!
    TDMSObjectRights Object Rights of a stream

    <table>
        <tr>
                <td><b>Member</b></td>
                <td><b>Data Type</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>is_drm_protected</td>
                <td>slim_bool</td>
                <td>Specifies if the stream is natively protected by CA/DRM</td>
        </tr>
        <tr>
                <td>allow_dtcp_protection</td>
                <td>slim_bool</td>
                <td>Specifies if it is to be dtcp protected for further distribution in home network</td>
        </tr>
        <tr>
                <td>subscription_time</td>
                <td>dlna_date</td>
                <td>Content time stamp when it was initially subscribed</td>
        </tr>
        <tr>
                <td>cci</td>
                <td>dlna_dtcp_cci</td>
                <td>Specifies cci information for dtcp</td>
        </tr>
        <tr>
                <td>retention_state</td>
                <td>dlna_dtcp_retention</td>
                <td>Retention state of dtcp</td>
        </tr>
        <tr>
                <td>concurrent_viewing</td>
                <td>slim_int</td>
                <td>Number of concurrent viewing allowed for this content</td>
        </tr>
        <tr>
                <td>playcount</td>
                <td>slim_int</td>
                <td>Number of Plays allowed for the content</td>
        </tr>
        <tr>
                <td>allow_distribution</td>
                <td>slim_bool</td>
                <td>Specifies if content is allowed for distribution in home network</td>
        </tr>
        <tr>
                <td>no_of_devices_allowed</td>
                <td>slim_int</td>
                <td>Specifies maximum number of devices allowed for distribution of the content in home network.
                Set it to DLNA_DEVICES_ALLOWED_UNLIMITED for unlimited number of devices</td>
        </tr>
    </table>
*/
typedef struct _TDMSObjectRights TDMSObjectRights;
/*@}*/


/**
 * @addtogroup Macros
 *
 */
 /*@{*/
 /*!
  * NFLC Publish Content - fixed IDs for predefined virtual containers
  *
  * <table>
  *   <tr>
  *     <td><b>Member</b></td>
  *     <td><b>Description</b></td>
  *   </tr>
  *   <tr>
  *     <td>NFLC_V_CONTAINER_LIVE_CONTENT_ID</td>
  *     <td>Predefined string id for live content virtual container.</td>
  *   </tr>
  *   <tr>
  *     <td>NFLC_V_CONTAINER_ONLINE_CONTENT_ID</td>
  *     <td>Predefined string id for online content virtual container.</td>
  *   </tr>
  *   <tr>
  *     <td>NFLC_V_CONTAINER_RECORDED_CONTENT_ID</td>
  *     <td>Predefined string id for recorded content virtual container.</td>
  *   </tr>
  * </table>
  */
#define NFLC_V_CONTAINER_LIVE_CONTENT_ID     "lc_id"
#define NFLC_V_CONTAINER_ONLINE_CONTENT_ID   "oc_id"
#define NFLC_V_CONTAINER_RECORDED_CONTENT_ID "rc_id"
/*@}*/

#ifndef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
struct _TDMSPublishVirtualContainer {
  slim_char *parent_id;
  slim_char *title;
  slim_char *id;
};
#endif /* !DEVELOPMENT_ENABLE_PUBLISH_CONTENT */
/**
* @addtogroup Structures
*/
/*@{*/

/*!
TDMSPublishVirtualContainer structure for the content to be published
 <table>
                <tr>
                        <td><b>Member</b></td>
                        <td><b>Data Type</b></td>
                        <td><b>Description</b></td>
                </tr>
                <tr>
                        <td>parent_id</td>
                        <td>slim_char</td>
                        <td>\li  Id of the parent to which the virtual container is created as child
                            \li  "0" is the root parent. If not sure where to add, set parent_id to "0"
                            \li  Then virtual container is created as child of "0"
                            \li / ("0")
                            \li ----/ {Your Virtual Container}
                            \li ----/ Photos
                            \li ----/ Videos
                            \li ----/ etc ... </td>
                </tr>
                <tr>
                        <td>title</td>
                        <td>slim_char</td>
                        <td>Title of the folder</td>
                </tr>
                <tr>
                        <td>id</td>
                        <td>slim_char</td>
                        <td>unique id can be given (title can also used as id)</td>
                </tr>
 </table>
*/
typedef struct _TDMSPublishVirtualContainer TDMSPublishVirtualContainer;
/*@}*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @addtogroup Functions
 */
/*@{*/
#ifndef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
/** \brief Add directory as storage
 *
 * @param self DMS instance
 * @param in_path Path to directory
 * @param in_share_name Name for added share
 * @param in_id ID for added share
 * @param in_location_type Location type of added share
 * @param in_auto_index slim_true, if it required to be watched for directory changes and updated(index/delete) for changes
 *
 * @return \li \c DMS_INVALID_PARAM - null pointers
 *         \li \c ? value returned by dms_storage_add
 */
DLNA_API TDMSReturn
dlnaDmsPublishStorageAdd(TDMS self, slim_char * in_path, slim_char * in_share_name, slim_char* in_id, TDMSStorageLocationType in_location_type, slim_bool in_auto_index);


/** \brief Remove directory from storage list
 *
 * @param self DMS instance
 * @param in_path Path to directory
 *
 * @return \li \c DMS_INVALID_PARAM - null pointers
 *         \li \c ? value returned by dms_storage_del
 */
DLNA_API TDMSReturn
dlnaDmsPublishStorageRemove(TDMS self, slim_char * in_path);


/** \brief Reindex contents
 *
 * @param self DMS instance
 * @param in_path Path to directory
 *
 * @return \li \c DMS_INVALID_PARAM - null pointers
 *         \li \c DMS_INVALID_DESC - operation failed
 *         \li \c DMS_SUCCESS - success
 */
DLNA_API TDMSReturn
dlnaDmsPublishStorageUpdate(TDMS self, slim_char * in_path);
#endif /* !DEVELOPMENT_ENABLE_PUBLISH_CONTENT */

/** \brief Access number of storage entries
 *
 * @param self DMS instance
 * @param out_count Result
 *
 * @return \li \c DMS_INVALID_PARAM - null pointers
 *         \li \c DMS_SUCCESS - success
 */
DLNA_API TDMSReturn
dlnaDmsPublishStorageEnumerateCount(TDMS self, slim_int * out_count);


/** \brief Get info about entry on storage list
 *
 * @param self DMS instance
 * @param in_index Index of entry
 * @param out_path Path to directory
 * @param out_share_name Share name for directory
 *
 * @return \li \c DMS_INVALID_PARAM - null pointers, bad index
 *         \li \c DMS_SUCCESS - success
 *
 * * @warning Strings returned by this function are used internally by library. Do not modify or free. It may be modified or freed without any notice.
 */
DLNA_API TDMSReturn
dlnaDmsPublishStorageEnumerateGet(TDMS self, const slim_int in_index, const slim_char ** const out_path, const slim_char ** const out_share_name);


/** \brief Set directory as default destination for upload requests
 * @param self DMS instance
 * @param in_path Path to directory
 * @return \li \c DMS_INVALID_PARAM - null pointers, destination unavailable
 *         \li \c DMS_SUCCESS - success
 *
 * Underlying api supports folder path with or without character '/' at the end.
 */
DLNA_API TDMSReturn
dlnaDmsPublishStorageSetDefaultUploadFolder(TDMS self, slim_char * in_path);


/** \brief Get default upload destination
 *
 * @param self DMS instance
 * @param out_path Path to directory
 *
 * @return \li \c DMS_INVALID_PARAM - null pointers
 *         \li \c DMS_SUCCESS - success
 *
 * Does not modify out_path in case of error.
 * out_path may be set to null even if DMS_SUCCESS is returned. It means there is no default path.
 *
 * @warning String returned by this function is used internally by library. Do not modify or free. It may be modified or freed without any notice.
 */
DLNA_API TDMSReturn
dlnaDmsPublishStorageGetDefaultUploadFolder(TDMS self, const slim_char ** const out_path);

/** \brief Configures the directory where the databases for the attached media devices shall be stored at a central location.
 * @param self DMS instance
 * @param in_config_path Path to directory
 * @return \li \c DMS_INVALID_PARAM - null pointers, destination unavailable
 *         \li \c DMS_SUCCESS - success
 *
 * This API configures the database location for the attached media devices at some central location instead of than on the device itself.
 * This API can be used for Read-only media devices or for devices that have slower IO operations.
 * If no Central Directory path is set by the API, then it is set to default path which is DMS data directory set by dlnaDmsAlloc()
 */
DLNA_API TDMSReturn
dlnaDmsPublishStorageSetStorageCentralDir(TDMS self, slim_char* in_config_path);

/** \brief Adds list of user metadata to the already indexed content
 * @param self DMS instance
 * @param in_user_metalist List of user metadata
 * @param in_path Absolute path of the file for which user metadata needs to be added
 * @return \li \c DMS_INVALID_PARAM - null pointers, destination unavailable
 *         \li \c DMS_SUCCESS - success
 *
 * This API adds the set of user metadata ( name-value pairs ) to the already indexed content of Storage.
 * dlnaDmsPublishStorageAdd method must be called before invoking this API.
 */
DLNA_API TDMSReturn
dlnaDmsPublishStorageContentUserMetadata(TDMS self, TDMSPublishUserMetadataList *in_user_metalist, slim_char *in_path);

#ifndef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
/** \brief Adds the Folder to the Content Directory Service (CDS) of the DMS
 * @param self DMS instance
 * @param in_container_info TDMSPublishVirtualContainer pointer to the folder information
 * @return \li \c DMS_INVALID_PARAM - null pointers,
 *         \li \c DMS_SUCCESS - succes
 *         \li \c Any other Error - Failed to add the folder
 *
 * This API adds the virtual folder to the CDS under the parent folder specified. If not it shall add the folder under root folder (0).
 */
DLNA_API TDMSReturn
dlnaDmsPublishVirtualContainerAdd(TDMS self, TDMSPublishVirtualContainer *in_container_info);
#endif //!DEVELOPMENT_ENABLE_PUBLISH_CONTENT
/** \brief Deletes the Folder from the Content Directory Service (CDS) of the DMS
 * @param self DMS instance
 * @param in_container_id Id of the virtual container to be deleted
 * @return \li \c DMS_INVALID_PARAM - null pointers,
 *         \li \c DMS_SUCCESS - succes
 *         \li \c Any other Error - Failed to delete the folder
 *
 * This API deletes the previously added virtual folder. If you are deleting a folder with children folder and content in it, all the corresponding
 * children and content are deleted. Please be noted root folder and the virtual folders existing by default could not be deleted.
 */
DLNA_API TDMSReturn
dlnaDmsPublishVirtualContainerDelete(TDMS self, slim_char* in_container_id);

/** \brief Adds the content (metadata and url) to the Content Directory Service of DMS
 * @param self DMS instance
 * @param in_content_info Pointer to TDMSPublishContent which specifies the metadata of the content to be published
 * @param in_object_rights Pointer to TDMSObjectRights which specifies the object rights if any of the content to be published
 * @return \li \c DMS_INVALID_PARAM - null pointers,
 *         \li \c DMS_SUCCESS - succes
 *         \li \c DMS_PUBLISH_STREAMING_CONTENT_EXISTS - Content already published
 *         \li \c Any other Error - Failed to delete the folder
 *
 * This function adds the content to the CDS of DMS. This API publishes the content specified by in_content_info. This API can be used to publish Live,
 * Online, PVR Recorded, Local content. It requires the parent for the content to be specified so that the content is not orphaned and appended
 * to a folder for better representation.
 */
#ifdef DEVELOPMENT_PUBLISH_CONTENT_OBJECT_RIGHTS_API
DLNA_API TDMSReturn
dlnaDmsPublishContentAdd(TDMS self, TDMSPublishContent *in_content_info, TDMSObjectRights *in_object_rights);
#else
DLNA_API TDMSReturn
dlnaDmsPublishContentAdd(TDMS self, TDMSPublishContent *in_content_info);
#endif

/** \brief Deletes the previously published content
 * @param self DMS instance
 * @param in_content_path Path of the content to be removed from CDS
 * @return \li \c DMS_INVALID_PARAM - null pointers,
 *         \li \c DMS_SUCCESS - succes
 *         \li \c Any other Error - Failed to delete the folder
 *
 * This function deletes the previously published content by its full path. A folder cannot be deleted by this API.
 */
DLNA_API TDMSReturn
dlnaDmsPublishContentDelete(TDMS self, slim_char* in_content_path);

/** \brief Update the content (metadata and url) to the Content Directory Service of DMS
 * @param self DMS instance
 * @param in_content_info Pointer to TDMSPublishContent which specifies the metadata of the content to be published
 * @param in_object_rights Pointer to TDMSObjectRights which specifies the object rights if any of the content to be published
 * @return \li \c DMS_INVALID_PARAM - null pointers,
 *         \li \c DMS_SUCCESS - succes
 *         \li \c DMS_PUBLISH_STREAMING_CONTENT_EXISTS - Content already published
 *         \li \c Any other Error - Failed to delete the folder
 *
 * This function update the content to the CDS of DMS. This API update the content specified by in_content_info. This API can be used to publish Live,
 * Online, PVR Recorded, Local content. It requires the parent for the content to be specified so that the content is not orphaned and appended
 * to a folder for better representation.
 */
#ifdef DEVELOPMENT_PUBLISH_CONTENT_OBJECT_RIGHTS_API
DLNA_API TDMSReturn
dlnaDmsPublishContentUpdate(TDMS self, TDMSPublishContent *in_content_info, TDMSObjectRights *in_object_rights);
#else
DLNA_API TDMSReturn
dlnaDmsPublishContentUpdate(TDMS self, TDMSPublishContent *in_content_info);
#endif

#ifdef DEVELOPMENT_PUBLISH_ONLINE_RECORDED_CONTENT_API
/** \brief Sets the Database Location for the content being published
 * @param self DMS instance
 * @param in_databse_location Path where the database is to be created
 * @return \li \c DMS_INVALID_PARAM - null pointer(s) were passed or the path specified is too long,
 *         \li \c DMS_ACCESS_DENY - failed to delete a previously set database file,
 *         \li \c NFLC_CDS_DATABASE_ERROR - failed to create a database at the specified location,
 *         \li \c DMS_SUCCESS - success.
 *
 * This function specifies the location of the database. The database for the published content is stored in this location.
 * This can be platform specific secured location, whereby platform provides proper read/write access to this secure location.
 */
DLNA_API TDMSReturn
dlnaDmsPublishContentSetDatabaseLocation(TDMS self, slim_char* in_databse_location);

/** \brief Deletes the Database Location for the content being published
 * @param self DMS instance.
 * @return \li \c DMS_INVALID_PARAM - null pointer passed,
 *         \li \c DMS_ACCESS_DENY - cannot delete the database file,
 *         \li \c DMS_SUCCESS - success.
 * The current database location can be deleted (including the disk contents) with a call to this function.
 */
DLNA_API TDMSReturn
dlnaDmsPublishContentDeleteDatabaseLocation(TDMS self);
#endif /* DEVELOPMENT_PUBLISH_ONLINE_RECORDED_CONTENT_API */

/*@}*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DMS_PUBLISH_STORAGE_API_H_ */
