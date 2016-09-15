/*
 * info_media.h
 * Copyright (C) 2007-2014 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_INFO_MEDIA_H
#define NFLC_INFO_MEDIA_H

#include <dlna_memory.h>
#include <dlna_mime.h>
#include <dlna_error.h>

#include <nflc_drm_api.h>

#define MIME_TYPE_LEN 32

#include <info_avi_def.h>

#include <access_conf.h>

#ifdef DEVELOPMENT_ENABLE_CVP_SERVER_PLAYSPEED
/*
 * [GUN: XD3U5] MM ps-param (Server-Side play-speeds parameter)
 * ps-param = [ps-param-delim] "DLNA.ORG_PS=" ps-value
 * ps-param-delim = ";"
 * ps-value = [server-speed *("," server-speed)]
 * server-speed = <conforms to the TransportPlaySpeed string, as specified in the AVTransport specification>
 * Now server-speed value are fixed, provide by DLNA.
 */
#define PROTOCOL_INFO_DLNA_ORG_PS_RARAM_FOR_AUDIO_VIDEO ";DLNA.ORG_PS=-300\\,-60\\,-30\\,-15\\,-5\\,-2\\,-1/2\\,-1/3\\,1/3\\,1/2\\,2\\,15\\,30\\,60\\,300"
#endif /* DEVELOPMENT_ENABLE_CVP_SERVER_PLAYSPEED */

#	ifdef HAVE_DTCP
#  ifdef HAVE_LOP
#		define PROTOCOL_INFO_DLNA_ORG_FLAGS_FOR_AUDIO_VIDEO ";DLNA.ORG_FLAGS=21710000000000000000000000000000"
#  else
#   define PROTOCOL_INFO_DLNA_ORG_FLAGS_FOR_AUDIO_VIDEO ";DLNA.ORG_FLAGS=01710000000000000000000000000000"
#  endif
#	else
#  ifdef HAVE_LOP
#		define PROTOCOL_INFO_DLNA_ORG_FLAGS_FOR_AUDIO_VIDEO ";DLNA.ORG_FLAGS=21700000000000000000000000000000"
#  else
#   define PROTOCOL_INFO_DLNA_ORG_FLAGS_FOR_AUDIO_VIDEO ";DLNA.ORG_FLAGS=01700000000000000000000000000000"
#  endif
#	endif

#      ifdef HAVE_DTCP
#  ifdef HAVE_LOP
#		define PROTOCOL_INFO_DLNA_ORG_FLAGS_FOR_LPCM ";DLNA.ORG_FLAGS=61710000000000000000000000000000"
#  else /*HAVE_LOP*/
#   define PROTOCOL_INFO_DLNA_ORG_FLAGS_FOR_LPCM ";DLNA.ORG_FLAGS=01710000000000000000000000000000"
#  endif /*HAVE_LOP*/
#	else /*HAVE_DTCP*/
#  ifdef HAVE_LOP
#		define PROTOCOL_INFO_DLNA_ORG_FLAGS_FOR_LPCM ";DLNA.ORG_FLAGS=67100000000000000000000000000000"
#  else /*HAVE_LOP*/
#   define PROTOCOL_INFO_DLNA_ORG_FLAGS_FOR_LPCM ";DLNA.ORG_FLAGS=01700000000000000000000000000000"
#  endif /*HAVE_LOP*/
#	endif /*HAVE_DTCP*/

#ifdef HAVE_DTCP
#	define PROTOCOL_INFO_DLNA_ORG_FLAGS_FOR_IMAGE ";DLNA.ORG_FLAGS=00D10000000000000000000000000000"
#	define PROTOCOL_INFO_DLNA_ORG_FLAGS_FOR_IMAGE_UNLPFLAG ";DLNA.ORG_FLAGS=00D00000000000000000000000000000"
#else
#	define PROTOCOL_INFO_DLNA_ORG_FLAGS_FOR_IMAGE ";DLNA.ORG_FLAGS=00D00000000000000000000000000000"
#endif

/* Audio.  */
#define DLNA_CMS_PROTO_HTTP_LPCM_44100_MONO_MPE                                  \
  "http-get:*:audio/L16;channels=1;rate=44100:DLNA.ORG_PN=LPCM;DLNA.ORG_OP=11;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_LPCM_44100_MONO                                   \
  "http-get:*:audio/L16;channels=1;rate=44100:DLNA.ORG_PN=LPCM;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_LPCM_44100_STEREO_MPE                                \
  "http-get:*:audio/L16;channels=2;rate=44100:DLNA.ORG_PN=LPCM;DLNA.ORG_OP=11;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_LPCM_44100_STEREO                                \
  "http-get:*:audio/L16;channels=2;rate=44100:DLNA.ORG_PN=LPCM;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_LPCM_48000_MONO_MPE                                   \
  "http-get:*:audio/L16;channels=1;rate=48000:DLNA.ORG_PN=LPCM;DLNA.ORG_OP=11;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_LPCM_48000_MONO                                   \
  "http-get:*:audio/L16;channels=1;rate=48000:DLNA.ORG_PN=LPCM;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_LPCM_48000_STEREO_MPE                                \
  "http-get:*:audio/L16;channels=2;rate=48000:DLNA.ORG_PN=LPCM;DLNA.ORG_OP=11;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_LPCM_48000_STEREO                                 \
  "http-get:*:audio/L16;channels=2;rate=48000:DLNA.ORG_PN=LPCM;DLNA.ORG_OP=01;DLNA.ORG_CI=0"


#define DLNA_CMS_PROTO_HTTP_MP3                                               \
  "http-get:*:audio/mpeg:DLNA.ORG_PN=MP3;DLNA.ORG_OP=11;DLNA.ORG_CI=0"
#define DLNA_CMS_PROTO_HTTP_MP3_NOTIMESEEK                                               \
  "http-get:*:audio/mpeg:DLNA.ORG_PN=MP3;DLNA.ORG_OP=01;DLNA.ORG_CI=0"
#define DLNA_CMS_PROTO_HTTP_MP4_AUDIO                                         \
  "http-get:*:audio/mp4:DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_3GPP_AUDIO                                        \
  "http-get:*:audio/3gpp:DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#ifdef MEDIA_PROCESSING_EXTENSION
#define DLNA_CMS_PROTO_HTTP_WAV                                               \
  "http-get:*:audio/wav:DLNA.ORG_OP=11;DLNA.ORG_CI=0"
#else /* MEDIA_PROCESSING_EXTENSION */
#define DLNA_CMS_PROTO_HTTP_WAV                                               \
  "http-get:*:audio/wav:DLNA.ORG_OP=01;DLNA.ORG_CI=0"
#endif /* MEDIA_PROCESSING_EXTENSION */

#define DLNA_CMS_PROTO_HTTP_WMA_BASE                                          \
  "http-get:*:audio/x-ms-wma:DLNA.ORG_PN=WMABASE;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_WMA_FULL                                          \
  "http-get:*:audio/x-ms-wma:DLNA.ORG_PN=WMAFULL;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_WMA_PRO                                          \
  "http-get:*:audio/x-ms-wma:DLNA.ORG_PN=WMAPRO;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_AAC_ISO_320                                      \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=AAC_ISO_320;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_AAC_ADTS_320                                      \
  "http-get:*:audio/vnd.dlna.adts:DLNA.ORG_PN=AAC_ADTS_320;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_DTCP_HTTP_AAC_ADTS_320                                      \
  "http-get:*:application/x-dtcp1;DTCP1HOST=0.0.0.0;DTCP1PORT=13001;CONTENTFORMAT=\"audio/vnd.dlna.adts\":DLNA.ORG_PN=AAC_ADTS_320;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_HEAAC_L2_ISO                                     \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=HEAAC_L2_ISO;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

/* DTCP Audio */
#define DLNA_CMS_PROTO_DTCP_HTTP_LPCM_44100_MONO                              \
  "http-get:*:application/x-dtcp1;DTCP1HOST=0.0.0.0;DTCP1PORT=13001;CONTENTFORMAT=\"audio/L16;channels=1;rate=44100\":DLNA.ORG_PN=DTCP_LPCM;DLNA.ORG_OP=01"

#define DLNA_CMS_PROTO_DTCP_HTTP_LPCM_44100_STEREO                            \
  "http-get:*:application/x-dtcp1;DTCP1HOST=0.0.0.0;DTCP1PORT=13001;CONTENTFORMAT=\"audio/L16;channels=2;rate=44100\":DLNA.ORG_PN=DTCP_LPCM;DLNA.ORG_OP=01"

#define DLNA_CMS_PROTO_DTCP_HTTP_LPCM_48000_MONO                              \
  "http-get:*:application/x-dtcp1;DTCP1HOST=0.0.0.0;DTCP1PORT=13001;CONTENTFORMAT=\"audio/L16;channels=1;rate=48000\":DLNA.ORG_PN=DTCP_LPCM;DLNA.ORG_OP=01"

#define DLNA_CMS_PROTO_DTCP_HTTP_LPCM_48000_STEREO                            \
  "http-get:*:application/x-dtcp1;DTCP1HOST=0.0.0.0;DTCP1PORT=13001;CONTENTFORMAT=\"audio/L16;channels=2;rate=48000\":DLNA.ORG_PN=DTCP_LPCM;DLNA.ORG_OP=01"


#define DLNA_CMS_PROTO_DTCP_HTTP_MP3                                          \
  "http-get:*:application/x-dtcp1;DTCP1HOST=0.0.0.0;DTCP1PORT=13001;CONTENTFORMAT=\"audio/mpeg\":DLNA.ORG_PN=DTCP_MP3;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_DTCP_HTTP_WAV                                          \
  "http-get:*:application/x-dtcp1;DTCP1HOST=0.0.0.0;DTCP1PORT=13001;CONTENTFORMAT=\"audio/wav\":DLNA.ORG_OP=01;DLNA.ORG_CI=0"

/* Image.  */
#define DLNA_CMS_PROTO_HTTP_JPEG_SM                                           \
  "http-get:*:image/jpeg:DLNA.ORG_PN=JPEG_SM;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_JPEG_MED                                          \
  "http-get:*:image/jpeg:DLNA.ORG_PN=JPEG_MED;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_JPEG_LRG                                          \
  "http-get:*:image/jpeg:DLNA.ORG_PN=JPEG_LRG;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_JPEG_GEO                                           \
  "http-get:*:image/jpeg:DLNA.ORG_PN=JPEG_LRG;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_JPEG_TN                                           \
  "http-get:*:image/jpeg:DLNA.ORG_PN=JPEG_TN;DLNA.ORG_CI=1"

#define DLNA_CMS_PROTO_HTTP_JPEG_SM_ICO                                       \
  "http-get:*:image/jpeg:DLNA.ORG_PN=JPEG_SM_ICO;DLNA.ORG_OP=01;DLNA.ORG_CI=1"

#define DLNA_CMS_PROTO_HTTP_JPEG_LRG_ICO                                      \
  "http-get:*:image/jpeg:DLNA.ORG_PN=JPEG_LRG_ICO;DLNA.ORG_OP=01;DLNA.ORG_CI=1"

/* macro definitions for RESIZE_IMAGE_PNG */
#define DLNA_CMS_PROTO_HTTP_PNG_SM_ICO                                        \
  "http-get:*:image/png:DLNA.ORG_PN=PNG_SM_ICO;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_PNG_LRG_ICO                                       \
  "http-get:*:image/png:DLNA.ORG_PN=PNG_LRG_ICO;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_PNG_TN                                            \
  "http-get:*:image/png:DLNA.ORG_PN=PNG_TN;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_PNG_LRG                                           \
  "http-get:*:image/png:DLNA.ORG_PN=PNG_LRG;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

/* Non-DLNA Format  */
#define DLNA_CMS_PROTO_HTTP_JPEG                                               \
  "http-get:*:image/jpeg:DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_PNG                                               \
  "http-get:*:image/png:DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_PCX                                               \
  "http-get:*:image/png:DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_PPM                                               \
  "http-get:*:image/png:DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_BMP                                               \
  "http-get:*:image/bmp:DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_GIF                                               \
  "http-get:*:image/gif:DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_GIF_LRG                                               \
  "http-get:*:image/gif:DLNA.ORG_PN=GIF_LRG;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_WEBP                                             \
  "http-get:*:image/webp:DLNA.ORG_OP=01;DLNA.ORG_CI=0"

/* DTCP Image */
#define DLNA_CMS_PROTO_DTCP_HTTP_JPEG_SM                                      \
  "http-get:*:application/x-dtcp1;DTCP1HOST=0.0.0.0;DTCP1PORT=13001;CONTENTFORMAT=\"image/jpeg\":DLNA.ORG_PN=DTCP_JPEG_SM;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_DTCP_HTTP_JPEG_MED                                     \
  "http-get:*:application/x-dtcp1;DTCP1HOST=0.0.0.0;DTCP1PORT=13001;CONTENTFORMAT=\"image/jpeg\":DLNA.ORG_PN=DTCP_JPEG_MED;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_DTCP_HTTP_JPEG_LRG                                     \
  "http-get:*:application/x-dtcp1;DTCP1HOST=0.0.0.0;DTCP1PORT=13001;CONTENTFORMAT=\"image/jpeg\":DLNA.ORG_PN=DTCP_JPEG_LRG;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_DTCP_HTTP_JPEG_TN                                      \
  "http-get:*:application/x-dtcp1;DTCP1HOST=0.0.0.0;DTCP1PORT=13001;CONTENTFORMAT=\"image/jpeg\":DLNA.ORG_PN=DTCP_JPEG_TN;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_DTCP_HTTP_JPEG_SM_ICO                                  \
  "http-get:*:application/x-dtcp1;DTCP1HOST=0.0.0.0;DTCP1PORT=13001;CONTENTFORMAT=\"image/jpeg\":DLNA.ORG_PN=DTCP_JPEG_SM_ICO;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_DTCP_HTTP_JPEG_LRG_ICO                                 \
  "http-get:*:application/x-dtcp1;DTCP1HOST=0.0.0.0;DTCP1PORT=13001;CONTENTFORMAT=\"image/jpeg\":DLNA.ORG_PN=DTCP_JPEG_LRG_ICO;DLNA.ORG_CI=0"

/* Non-DLNA Format  */
#define DLNA_CMS_PROTO_DTCP_HTTP_JPEG                                               \
  "http-get:*:application/x-dtcp1;DTCP1HOST=0.0.0.0;DTCP1PORT=13001;CONTENTFORMAT=\"image/jpeg\":DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_DTCP_HTTP_PNG                                          \
  "http-get:*:application/x-dtcp1;DTCP1HOST=0.0.0.0;DTCP1PORT=13001;CONTENTFORMAT=\"image/png\":DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_DTCP_HTTP_BMP                                          \
  "http-get:*:application/x-dtcp1;DTCP1HOST=0.0.0.0;DTCP1PORT=13001;CONTENTFORMAT=\"image/bmp\":DLNA.ORG_OP=01;DLNA.ORG_CI=0"


/* Movie.  */
#define DLNA_CMS_PROTO_HTTP_MPEG_NTSC                                         \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_PS_NTSC;DLNA.ORG_OP=11;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_MPEG_PAL                                          \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_PS_PAL;DLNA.ORG_OP=11;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_WMV_MED_BASE                                      \
  "http-get:*:video/x-ms-wmv:DLNA.ORG_PN=WMVMED_BASE;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_WMV_MED_FULL                                      \
  "http-get:*:video/x-ms-wmv:DLNA.ORG_PN=WMVMED_FULL;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_WMV_MED_PRO                                      \
  "http-get:*:video/x-ms-wmv:DLNA.ORG_PN=WMVMED_PRO;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_WMV_HIGH_FULL                                      \
  "http-get:*:video/x-ms-wmv:DLNA.ORG_PN=WMVHIGH_FULL;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_WMV_HIGH_PRO                                      \
  "http-get:*:video/x-ms-wmv:DLNA.ORG_PN=WMVHIGH_PRO;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_WMV_HM_BASE                                      \
  "http-get:*:video/x-ms-wmv:DLNA.ORG_PN=WMVHM_BASE;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_WMV_SPLL_BASE                                      \
  "http-get:*:video/x-ms-wmv:DLNA.ORG_PN=WMVSPLL_BASE;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_WMV_SPML_BASE                                      \
  "http-get:*:video/x-ms-wmv:DLNA.ORG_PN=WMVSPML_BASE;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_WMV_SPML_MP3                                      \
  "http-get:*:video/x-ms-wmv:DLNA.ORG_PN=WMVSPML_MP3;DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_MP4_VIDEO                                         \
  "http-get:*:video/mp4:DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_3GPP_VIDEO                                        \
  "http-get:*:video/3gpp:DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#ifdef HAVE_RTML
#define DLNA_CMS_PROTO_HTTP_RTML                                              \
  "http-get:*:video/rtml:DLNA.ORG_OP=01"

#endif /* HAVE_RTML */

#define DLNA_CMS_PROTO_HTTP_ISO                                               \
  "http-get:*:application/x-iso-image:*"
#define DLNA_CMS_PROTO_HTTP_IMG                                               \
  "http-get:*:application/x-cd-image:*"

#define DLNA_CMS_PROTO_HTTP_DVRMS                                             \
  "http-get:*:video/x-ms-dvr:*"

#define DLNA_CMS_PROTO_HTTP_MKV                                             \
  "http-get:*:video/x-mkv:DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_MKV2                                            \
  "http-get:*:video/mkv:DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_WEBM                                             \
  "http-get:*:video/webm:DLNA.ORG_OP=01;DLNA.ORG_CI=0"


#ifdef MEDIA_PROCESSING_EXTENSION
#define DLNA_CMS_PROTO_HTTP_M3U                                               \
  "http-get:*:application/x-mpegurl:DLNA.ORG_OP=11;DLNA.ORG_CI=0" PROTOCOL_INFO_DLNA_ORG_FLAGS_FOR_AUDIO_VIDEO
#define DLNA_CMS_PROTO_HTTP_M3U8                                              \
  "http-get:*:application/x-mpegurl:DLNA.ORG_OP=11;DLNA.ORG_CI=0" PROTOCOL_INFO_DLNA_ORG_FLAGS_FOR_AUDIO_VIDEO
#else /* MEDIA_PROCESSING_EXTENSION */
#define DLNA_CMS_PROTO_HTTP_M3U                                               \
  "http-get:*:application/x-mpegurl:DLNA.ORG_OP=01;DLNA.ORG_CI=0" PROTOCOL_INFO_DLNA_ORG_FLAGS_FOR_AUDIO_VIDEO
#define DLNA_CMS_PROTO_HTTP_M3U8                                              \
  "http-get:*:application/x-mpegurl:DLNA.ORG_OP=01;DLNA.ORG_CI=0" PROTOCOL_INFO_DLNA_ORG_FLAGS_FOR_AUDIO_VIDEO
#endif /* MEDIA_PROCESSING_EXTENSION */

#define DLNA_CMS_PROTO_HTTP_PLS                                               \
  "http-get:*:audio/x-scpls:DLNA.ORG_OP=01;DLNA.ORG_CI=0" PROTOCOL_INFO_DLNA_ORG_FLAGS_FOR_AUDIO_VIDEO

#define DLNA_CMS_PROTO_HTTP_WPL                                               \
  "http-get:*:application/vnd.ms-wpl:DLNA.ORG_OP=01;DLNA.ORG_CI=0" PROTOCOL_INFO_DLNA_ORG_FLAGS_FOR_AUDIO_VIDEO

/* sink protocolinfo macros*/
/* image profiles */
/* jpeg */
#define DLNA_CMS_SINK_PROTO_HTTP_JPEG_SM \
  "http-get:*:image/jpeg:DLNA.ORG_PN=JPEG_SM"

#define DLNA_CMS_SINK_PROTO_HTTP_JPEG_MED \
  "http-get:*:image/jpeg:DLNA.ORG_PN=JPEG_MED"

#define DLNA_CMS_SINK_PROTO_HTTP_JPEG_LRG \
  "http-get:*:image/jpeg:DLNA.ORG_PN=JPEG_LRG"

#define DLNA_CMS_SINK_PROTO_HTTP_JPEG_TN \
  "http-get:*:image/jpeg:DLNA.ORG_PN=JPEG_TN"

#define DLNA_CMS_SINK_PROTO_HTTP_JPEG_SM_ICO \
  "http-get:*:image/jpeg:DLNA.ORG_PN=JPEG_SM_ICO"

#define DLNA_CMS_SINK_PROTO_HTTP_JPEG_LRG_ICO \
  "http-get:*:image/jpeg:DLNA.ORG_PN=JPEG_LRG_ICO"

/* png */
#define DLNA_CMS_SINK_PROTO_HTTP_PNG_LRG \
  "http-get:*:image/png:DLNA.ORG_PN=PNG_LRG"

#define DLNA_CMS_SINK_PROTO_HTTP_PNG_TN \
  "http-get:*:image/png:DLNA.ORG_PN=PNG_TN"

#define DLNA_CMS_SINK_PROTO_HTTP_PNG_SM_ICO \
  "http-get:*:image/png:DLNA.ORG_PN=PNG_SM_ICO"

#define DLNA_CMS_SINK_PROTO_HTTP_PNG_LRG_ICO \
  "http-get:*:image/png:DLNA.ORG_PN=PNG_LRG_ICO"

/* gif */
#define DLNA_CMS_SINK_PROTO_HTTP_GIF_LRG \
  "http-get:*:image/gif:DLNA.ORG_PN=GIF_LRG"

/* audio profiles */
/* LPCM */
#define DLNA_CMS_SINK_PROTO_HTTP_LPCM_44100_MONO \
  "http-get:*:audio/L16;channels=1;rate=44100:DLNA.ORG_PN=LPCM"

#define DLNA_CMS_SINK_PROTO_HTTP_LPCM_44100_STEREO \
  "http-get:*:audio/L16;channels=2;rate=44100:DLNA.ORG_PN=LPCM"

#define DLNA_CMS_SINK_PROTO_HTTP_LPCM_48000_MONO \
  "http-get:*:audio/L16;channels=1;rate=48000:DLNA.ORG_PN=LPCM"

#define DLNA_CMS_SINK_PROTO_HTTP_LPCM_48000_STEREO \
  "http-get:*:audio/L16;channels=2;rate=48000:DLNA.ORG_PN=LPCM"

#define DLNA_CMS_SINK_PROTO_HTTP_LPCM_LOW_8000_MONO \
  "http-get:*:audio/L16;channels=1;rate=8000:DLNA.ORG_PN=LPCM_low"

#define DLNA_CMS_SINK_PROTO_HTTP_LPCM_LOW_8000_STEREO \
  "http-get:*:audio/L16;channels=2;rate=8000:DLNA.ORG_PN=LPCM_low"

#define DLNA_CMS_SINK_PROTO_HTTP_LPCM_LOW_11025_MONO \
  "http-get:*:audio/L16;channels=1;rate=11025:DLNA.ORG_PN=LPCM_low"

#define DLNA_CMS_SINK_PROTO_HTTP_LPCM_LOW_11025_STEREO \
  "http-get:*:audio/L16;channels=2;rate=11025:DLNA.ORG_PN=LPCM_low"

#define DLNA_CMS_SINK_PROTO_HTTP_LPCM_LOW_12000_MONO \
  "http-get:*:audio/L16;channels=1;rate=12000:DLNA.ORG_PN=LPCM_low"

#define DLNA_CMS_SINK_PROTO_HTTP_LPCM_LOW_12000_STEREO \
  "http-get:*:audio/L16;channels=2;rate=12000:DLNA.ORG_PN=LPCM_low"

#define DLNA_CMS_SINK_PROTO_HTTP_LPCM_LOW_16000_MONO \
  "http-get:*:audio/L16;channels=1;rate=16000:DLNA.ORG_PN=LPCM_low"

#define DLNA_CMS_SINK_PROTO_HTTP_LPCM_LOW_16000_STEREO \
  "http-get:*:audio/L16;channels=2;rate=16000:DLNA.ORG_PN=LPCM_low"

#define DLNA_CMS_SINK_PROTO_HTTP_LPCM_LOW_22050_MONO \
  "http-get:*:audio/L16;channels=1;rate=22050:DLNA.ORG_PN=LPCM_low"

#define DLNA_CMS_SINK_PROTO_HTTP_LPCM_LOW_22050_STEREO \
  "http-get:*:audio/L16;channels=2;rate=22050:DLNA.ORG_PN=LPCM_low"

#define DLNA_CMS_SINK_PROTO_HTTP_LPCM_LOW_24000_MONO \
  "http-get:*:audio/L16;channels=1;rate=24000:DLNA.ORG_PN=LPCM_low"

#define DLNA_CMS_SINK_PROTO_HTTP_LPCM_LOW_24000_STEREO \
  "http-get:*:audio/L16;channels=2;rate=24000:DLNA.ORG_PN=LPCM_low"

#define DLNA_CMS_SINK_PROTO_HTTP_LPCM_LOW_32000_MONO \
  "http-get:*:audio/L16;channels=1;rate=32000:DLNA.ORG_PN=LPCM_low"

#define DLNA_CMS_SINK_PROTO_HTTP_LPCM_LOW_32000_STEREO \
  "http-get:*:audio/L16;channels=2;rate=32000:DLNA.ORG_PN=LPCM_low"

/* ZZZ.. be unsure of LPCM_MPS media format */
/* #define DLNA_CMS_SINK_PROTO_HTTP_LPCM_MPS_48000_MONO \ */
/*   "http-get:*:audio/L16;rate=48000;channels=1:DLNA.ORG_PN=LPCM_MPS" */

/* #define DLNA_CMS_SINK_PROTO_HTTP_LPCM_MPS_48000_STEREO \ */
/*   "http-get:*:audio/L16;rate=48000;channels=2:DLNA.ORG_PN=LPCM_MPS" */

/* #define DLNA_CMS_SINK_PROTO_HTTP_LPCM_MPS_48000_MULTICHANNEL3 \ */
/*   "http-get:*:audio/L16;rate=48000;channels=3:DLNA.ORG_PN=LPCM_MPS" */
/* . */

#define DLNA_CMS_SINK_PROTO_HTTP_LPCM_LOW_32000_STEREO \
  "http-get:*:audio/L16;channels=2;rate=32000:DLNA.ORG_PN=LPCM_low"

/* MP3 */
#define DLNA_CMS_SINK_PROTO_HTTP_MP3 \
  "http-get:*:audio/mpeg:DLNA.ORG_PN=MP3"

#define DLNA_CMS_SINK_PROTO_HTTP_MP3X \
  "http-get:*:audio/mpeg:DLNA.ORG_PN=MP3X"

#define DLNA_CMS_SINK_PROTO_HTTP_AAC_ADTS \
  "http-get:*:audio/vnd.dlna.adts:DLNA.ORG_PN=AAC_ADTS"

/* MPEG-4 Part3 */
#define DLNA_CMS_SINK_PROTO_HTTP_AAC_ADTS_320 \
  "http-get:*:audio/vnd.dlna.adts:DLNA.ORG_PN=AAC_ADTS_320"

#define DLNA_CMS_SINK_PROTO_HTTP_AAC_ISO_AMP4 \
  "http-get:*:audio/mp4:DLNA.ORG_PN=AAC_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AAC_ISO_A3GPP \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=AAC_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AAC_ISO_320_AMP4 \
  "http-get:*:audio/mp4:DLNA.ORG_PN=AAC_ISO_320"

#define DLNA_CMS_SINK_PROTO_HTTP_AAC_ISO_320_A3GPP \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=AAC_ISO_320"

#define DLNA_CMS_SINK_PROTO_HTTP_AAC_LTP_ISO_AMP4 \
  "http-get:*:audio/mp4:DLNA.ORG_PN=AAC_LTP_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AAC_LTP_ISO_A3GPP \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=AAC_LTP_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AAC_LTP_ISO_AADTS \
  "http-get:*:audio/vnd.dlna.adts:DLNA.ORG_PN=AAC_LTP_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AAC_LTP_MULT5_ISO_AMP4 \
  "http-get:*:audio/mp4:DLNA.ORG_PN=AAC_LTP_MULT5_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AAC_LTP_MULT5_ISO_A3GPP \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=AAC_LTP_MULT5_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AAC_LTP_MULT5_ISO_AADTS \
  "http-get:*:audio/vnd.dlna.adts:DLNA.ORG_PN=AAC_LTP_MULT5_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AAC_LTP_MULT7_ISO_AMP4 \
  "http-get:*:audio/mp4:DLNA.ORG_PN=AAC_LTP_MULT7_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AAC_LTP_MULT7_ISO_A3GPP \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=AAC_LTP_MULT7_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AAC_LTP_MULT7_ISO_AADTS \
  "http-get:*:audio/vnd.dlna.adts:DLNA.ORG_PN=AAC_LTP_MULT7_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AAC_MULT5_ADTS \
  "http-get:*:audio/vnd.dlna.adts:DLNA.ORG_PN=AAC_MULT5_ADTS"

#define DLNA_CMS_SINK_PROTO_HTTP_AAC_MULT5_ISO_AMP4 \
  "http-get:*:audio/mp4:DLNA.ORG_PN=AAC_MULT5_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AAC_MULT5_ISO_A3GPP \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=AAC_MULT5_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAAC_L2_ADTS \
  "http-get:*:audio/vnd.dlna.adts:DLNA.ORG_PN=HEAAC_L2_ADTS"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAAC_L2_ISO_AMP4 \
  "http-get:*:audio/mp4:DLNA.ORG_PN=HEAAC_L2_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAAC_L2_ISO_A3GPP \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=HEAAC_L2_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAAC_L3_ADTS \
  "http-get:*:audio/vnd.dlna.adts:DLNA.ORG_PN=HEAAC_L3_ADTS"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAAC_L3_ISO_AMP4 \
  "http-get:*:audio/mp4:DLNA.ORG_PN=HEAAC_L3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAAC_L3_ISO_A3GPP \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=HEAAC_L3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAAC_MULT5_ADTS \
  "http-get:*:audio/vnd.dlna.adts:DLNA.ORG_PN=HEAAC_MULT5_ADTS"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAAC_MULT5_ISO_AMP4 \
  "http-get:*:audio/mp4:DLNA.ORG_PN=HEAAC_MULT5_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAAC_MULT5_ISO_A3GPP \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=HEAAC_MULT5_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAAC_L2_ADTS_320 \
  "http-get:*:audio/vnd.dlna.adts:DLNA.ORG_PN=HEAAC_L2_ADTS_320"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAAC_L2_ISO_320_AMP4 \
  "http-get:*:audio/mp4:DLNA.ORG_PN=HEAAC_L2_ISO_320"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAAC_L2_ISO_320_A3GPP \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=HEAAC_L2_ISO_320"

#define DLNA_CMS_SINK_PROTO_HTTP_BSAC_ISO_AMP4 \
  "http-get:*:audio/mp4:DLNA.ORG_PN=BSAC_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_BSAC_ISO_A3GPP \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=BSAC_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_BSAC_MULT5_ISO_AMP4 \
  "http-get:*:audio/mp4:DLNA.ORG_PN=BSAC_MULT5_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_BSAC_MULT5_ISO_A3GPP \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=BSAC_MULT5_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAACV2_L2_AMP4 \
  "http-get:*:audio/mp4:DLNA.ORG_PN=HEAACv2_L2"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAACV2_L2_A3GPP \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=HEAACv2_L2"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAACV2_L2_AADTS \
  "http-get:*:audio/vnd.dlna.adts:DLNA.ORG_PN=HEAACv2_L2"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAACV2_L2_320_AMP4 \
  "http-get:*:audio/mp4:DLNA.ORG_PN=HEAACv2_L2_320"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAACV2_L2_320_A3GPP \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=HEAACv2_L2_320"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAACV2_L2_320_AADTS \
  "http-get:*:audio/vnd.dlna.adts:DLNA.ORG_PN=HEAACv2_L2_320"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAACV2_L3_AMP4 \
  "http-get:*:audio/mp4:DLNA.ORG_PN=HEAACv2_L3"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAACV2_L3_A3GPP \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=HEAACv2_L3"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAACV2_L3_AADTS \
  "http-get:*:audio/vnd.dlna.adts:DLNA.ORG_PN=HEAACv2_L3"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAACV2_MULT5_AMP4 \
  "http-get:*:audio/mp4:DLNA.ORG_PN=HEAACv2_MULT5"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAACV2_MULT5_A3GPP \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=HEAACv2_MULT5"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAACV2_MULT5_AADTS \
  "http-get:*:audio/vnd.dlna.adts:DLNA.ORG_PN=HEAACv2_MULT5"

#define DLNA_CMS_SINK_PROTO_HTTP_ALS_ISO \
  "http-get:*:audio/mp4:DLNA.ORG_PN=ALS_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_ALS_MULT5_ISO \
  "http-get:*:audio/mp4:DLNA.ORG_PN=ALS_MULT5_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG2_AAC_MPS_AMP4 \
  "http-get:*:audio/mp4:DLNA.ORG_PN=MPEG2_AAC_MPS"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG2_AAC_MPS_A3GPP \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=MPEG2_AAC_MPS"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG2_AAC_MPS_AADTS \
  "http-get:*:audio/vnd.dlna.adts:DLNA.ORG_PN=MPEG2_AAC_MPS"

#define DLNA_CMS_SINK_PROTO_HTTP_AAC_MPS_AMP4 \
  "http-get:*:audio/mp4:DLNA.ORG_PN=AAC_MPS"

#define DLNA_CMS_SINK_PROTO_HTTP_AAC_MPS_A3GPP \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=AAC_MPS"

#define DLNA_CMS_SINK_PROTO_HTTP_AAC_MPS_AADTS \
  "http-get:*:audio/vnd.dlna.adts:DLNA.ORG_PN=AAC_MPS"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAAC_L4_AMP4 \
  "http-get:*:audio/mp4:DLNA.ORG_PN=HEAAC_L4"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAAC_L4_A3GPP \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=HEAAC_L4"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAAC_L4_AADTS \
  "http-get:*:audio/vnd.dlna.adts:DLNA.ORG_PN=HEAAC_L4"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAAC_MULT7_AMP4 \
  "http-get:*:audio/mp4:DLNA.ORG_PN=HEAAC_MULT7"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAAC_MULT7_A3GPP \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=HEAAC_MULT7"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAAC_MULT7_AADTS \
  "http-get:*:audio/vnd.dlna.adts:DLNA.ORG_PN=HEAAC_MULT7"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAAC_MPS_AMP4 \
  "http-get:*:audio/mp4:DLNA.ORG_PN=HEAAC_MPS"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAAC_MPS_A3GPP \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=HEAAC_MPS"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAAC_MPS_AADTS \
  "http-get:*:audio/vnd.dlna.adts:DLNA.ORG_PN=HEAAC_MPS"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAACV2_L4_AMP4 \
  "http-get:*:audio/mp4:DLNA.ORG_PN=HEAACv2_L4"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAACV2_L4_A3GPP \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=HEAACv2_L4"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAACV2_L4_AADTS \
  "http-get:*:audio/vnd.dlna.adts:DLNA.ORG_PN=HEAACv2_L4"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAACV2_MULT7_AMP4 \
  "http-get:*:audio/mp4:DLNA.ORG_PN=HEAACv2_MULT7"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAACV2_MULT7_A3GPP \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=HEAACv2_MULT7"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAACV2_MULT7_AADTS \
  "http-get:*:audio/vnd.dlna.adts:DLNA.ORG_PN=HEAACv2_MULT7"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAACV2_L2_MPS_DAB \
  "http-get:*:audio/xdab:DLNA.ORG_PN=HEAACv2_L2_MPS_DAB"

#define DLNA_CMS_SINK_PROTO_HTTP_AAC_ADTS_192 \
  "http-get:*:audio/vnd.dlna.adts:DLNA.ORG_PN=AAC_ADTS_192"

#define DLNA_CMS_SINK_PROTO_HTTP_AAC_ISO_192_AMP4 \
  "http-get:*:audio/mp4:DLNA.ORG_PN=AAC_ISO_192"

#define DLNA_CMS_SINK_PROTO_HTTP_AAC_ISO_192_A3GPP \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=AAC_ISO_192"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAACV2_L2_128_AMP4 \
  "http-get:*:audio/mp4:DLNA.ORG_PN=HEAACv2_L2_128"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAACV2_L2_128_A3GPP \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=HEAACv2_L2_128"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAACV2_L2_128_AADTS \
  "http-get:*:audio/vnd.dlna.adts:DLNA.ORG_PN=HEAACv2_L2_128"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAAC_L2_ISO_128_AMP4 \
  "http-get:*:audio/mp4:DLNA.ORG_PN=HEAAC_L2_ISO_128"

#define DLNA_CMS_SINK_PROTO_HTTP_HEAAC_L2_ISO_128_A3GPP \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=HEAAC_L2_ISO_128"

/* AC-3 */
#define DLNA_CMS_SINK_PROTO_HTTP_AC_3 \
  "http-get:*:audio/vnd.dolby.dd-raw:DLNA.ORG_PN=AC3"

/* AMR */
#define DLNA_CMS_SINK_PROTO_HTTP_AMR_3GPP_A3GPP \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=AMR_3GPP"

#define DLNA_CMS_SINK_PROTO_HTTP_AMR_3GPP_AMP4 \
  "http-get:*:audio/mp4:DLNA.ORG_PN=AMR_3GPP"

#define DLNA_CMS_SINK_PROTO_HTTP_AMR_WBPLUS \
  "http-get:*:audio/3gpp:DLNA.ORG_PN=AMR_WBplus"

/* ATRAC3plus */
#define DLNA_CMS_SINK_PROTO_HTTP_ATRAC3PLUS \
  "http-get:*:audio/x-sony-oma:DLNA.ORG_PN=ATRAC3plus"

/* WMA */
#define DLNA_CMS_SINK_PROTO_HTTP_WMABASE \
  "http-get:*:audio/x-ms-wma:DLNA.ORG_PN=WMABASE"

#define DLNA_CMS_SINK_PROTO_HTTP_WMAFULL \
  "http-get:*:audio/x-ms-wma:DLNA.ORG_PN=WMAFULL"

#define DLNA_CMS_SINK_PROTO_HTTP_WMAPRO \
  "http-get:*:audio/x-ms-wma:DLNA.ORG_PN=WMAPRO"

#define DLNA_CMS_SINK_PROTO_HTTP_WMALSL \
  "http-get:*:audio/x-ms-wma:DLNA.ORG_PN=WMALSL"

#define DLNA_CMS_SINK_PROTO_HTTP_WMALSL_MULT5 \
  "http-get:*:audio/x-ms-wma:DLNA.ORG_PN=WMALSL_MULT5"

/* DTS Digital Surround */
#define DLNA_CMS_SINK_PROTO_HTTP_DTS \
  "http-get:*:audio/vnd.dts:DLNA.ORG_PN=DTS"

/* DTS-HD */
#define DLNA_CMS_SINK_PROTO_HTTP_DTSHD_HRA \
  "http-get:*:audio/vnd.dts-hd:DLNA.ORG_PN=DTSHD_HRA"

#define DLNA_CMS_SINK_PROTO_HTTP_DTSHD_MA \
  "http-get:*:audio/vnd.dts-hd:DLNA.ORG_PN=DTSHD_MA"

#define DLNA_CMS_SINK_PROTO_HTTP_DTSHD_LBR \
  "http-get:*:audio/vnd.dts-hd:DLNA.ORG_PN=DTSHD_LBR"

/* Enhanced AC-3(Dolby Digital Plus) */
#define DLNA_CMS_SINK_PROTO_HTTP_EAC3 \
  "http-get:*:audio/eac3:DLNA.ORG_PN=EAC3"

/* MLP - Meridian Lossless Packing */
#define DLNA_CMS_SINK_PROTO_HTTP_MLP \
  "http-get:*:audio/vnd.dolby.mlp:DLNA.ORG_PN=MLP"

/* MPEG-1/2 Layer 2 */
#define DLNA_CMS_SINK_PROTO_HTTP_MP2_MPS \
  "http-get:*:audio/mpeg:DLNA.ORG_PN=MP2_MPS"

#define DLNA_CMS_PROTO_HTTP_FLAC \
  "http-get:*:audio/x-flac:DLNA.ORG_OP=01;DLNA.ORG_CI=0"

#define DLNA_CMS_PROTO_HTTP_MKA                                            \
  "http-get:*:audio/x-matroska:DLNA.ORG_OP=01;DLNA.ORG_CI=0"

/* audio video profiles */
/* MPEG-1 */
#define DLNA_CMS_SINK_PROTO_HTTP_MPEG1 \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG1"

/* MPEG-2 */
#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_PS_NTSC \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_PS_NTSC"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_PS_NTSC_XAC3 \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_PS_NTSC_XAC3"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_PS_PAL \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_PS_PAL"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_PS_PAL_XAC3 \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_PS_PAL_XAC3"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_SD_NA \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_SD_NA"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_SD_NA_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_SD_NA_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_SD_NA_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_TS_SD_NA_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_NA \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_HD_NA"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_NA_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_HD_NA_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_NA_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_TS_HD_NA_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_NA_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_TS_NA_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_SD_EU \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_SD_EU"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_SD_EU_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_SD_EU_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_SD_EU_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_TS_SD_EU_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_SD_KO \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_SD_KO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_SD_KO_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_SD_KO_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_SD_KO_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_TS_SD_KO_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_KO \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_HD_KO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_KO_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_HD_KO_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_KO_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_TS_HD_KO_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_KO_XAC3 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_HD_KO_XAC3"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_KO_XAC3_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_HD_KO_XAC3_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_KO_XAC3_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_TS_HD_KO_XAC3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_NA_XAC3 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_HD_NA_XAC3"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_NA_XAC3_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_HD_NA_XAC3_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_NA_XAC3_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_TS_HD_NA_XAC3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_SD_KO_XAC3 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_SD_KO_XAC3"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_SD_KO_XAC3_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_SD_KO_XAC3_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_SD_KO_XAC3_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_TS_SD_KO_XAC3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_SD_NA_XAC3 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_SD_NA_XAC3"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_SD_NA_XAC3_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_SD_NA_XAC3_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_SD_NA_XAC3_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_TS_SD_NA_XAC3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_MP_LL_AAC \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_MP_LL_AAC"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_MP_LL_AAC_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_MP_LL_AAC_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_MP_LL_AAC_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_TS_MP_LL_AAC_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_ES_PAL \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_ES_PAL"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_ES_NTSC \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_ES_NTSC"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_ES_PAL_XAC3 \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_ES_PAL_XAC3"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_ES_NTSC_XAC3 \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_ES_NTSC_XAC3"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_JP_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_JP_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_SD_60_L2_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_SD_60_L2_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_SD_60_AC3_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_SD_60_AC3_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_SD_50_L2_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_SD_50_L2_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_SD_50_AC3_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_SD_50_AC3_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_60_L2_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_HD_60_L2_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_60_L2_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_TS_HD_60_L2_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_50_L2_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_HD_50_L2_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_50_L2_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_TS_HD_50_L2_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_PS_SD_DTS \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_PS_SD_DTS"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_PS_HD_DTS \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_PS_HD_DTS"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_PS_HD_DTSHD_HRA \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_PS_HD_DTSHD_HRA"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_PS_HD_DTSHD_MA \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_PS_HD_DTSHD_MA"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_PS_HD_DTSHD \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_PS_HD_DTSHD"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_DIRECTV_SD \
  "http-get:*:video/x-mpeg2-directv:DLNA.ORG_PN=MPEG_DIRECTV_SD"

#define DLNA_CMS_SINK_PROTO_HTTP_DIRECTV_TS_SD \
  "http-get:*:video/x-mpeg2-directv:DLNA.ORG_PN=DIRECTV_TS_SD"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_SD_NA_MPEG1_L2_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_SD_NA_MPEG1_L2_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_SD_NA_MPEG1_L2_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_TS_SD_NA_MPEG1_L2_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_NA_MPEG1_L2_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_HD_NA_MPEG1_L2_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_DTS_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_HD_DTS_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_DTS_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_TS_HD_DTS_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_DTSHD_HRA_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_HD_DTSHD_HRA_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_DTSHD_HRA_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_TS_HD_DTSHD_HRA_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_DTSHD_MA_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_HD_DTSHD_MA_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_DTSHD_MA_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_TS_HD_DTSHD_MA_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_NA_MPEG1_L2_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_TS_HD_NA_MPEG1_L2_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_SD_EU_AC3_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_SD_EU_AC3_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_SD_EU_AC3_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_TS_SD_EU_AC3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_SD_JP_MPEG1_L2_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_SD_JP_MPEG1_L2_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_DTS_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_DTS_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_DTS_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_TS_DTS_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_DTSHD_HRA_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_DTSHD_HRA_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_DTSHD_HRA_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_TS_DTSHD_HRA_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_DTSHD_MA_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_DTSHD_MA_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_DTSHD_MA_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_TS_DTSHD_MA_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_X_60_L2_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_HD_X_60_L2_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_X_60_L2_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_TS_HD_X_60_L2_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_X_50_L2_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_HD_X_50_L2_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG_TS_HD_X_50_L2_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_TS_HD_X_50_L2_ISO"

/* MPEG-4 Part2 */
#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_SP_AAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_SP_AAC"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_SP_HEAAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_SP_HEAAC"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_SP_ATRAC3PLUS \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_SP_ATRAC3plus"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_SP_AAC_LTP \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_SP_AAC_LTP"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_SP_L2_AAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_SP_L2_AAC"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_SP_L2_AMR \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_SP_L2_AMR"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_SP_AAC \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG4_P2_TS_SP_AAC"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_SP_AAC_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG4_P2_TS_SP_AAC_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_SP_AAC_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG4_P2_TS_SP_AAC_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_SP_MPEG1_L3 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG4_P2_TS_SP_MPEG1_L3"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_SP_MPEG1_L3_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG4_P2_TS_SP_MPEG1_L3_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_SP_MPEG1_L3_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG4_P2_TS_SP_MPEG1_L3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_SP_AC3 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG4_P2_TS_SP_AC3"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_SP_AC3_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG4_P2_TS_SP_AC3_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_SP_AC3_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG4_P2_TS_SP_AC3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_SP_MPEG2_L2 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG4_P2_TS_SP_MPEG2_L2"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_SP_MPEG2_L2_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG4_P2_TS_SP_MPEG2_L2_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_SP_MPEG2_L2_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG4_P2_TS_SP_MPEG2_L2_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_ASP_MPEG2_L2 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG4_P2_TS_ASP_MPEG2_L2"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_ASP_MPEG2_L2_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG4_P2_TS_ASP_MPEG2_L2_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_ASP_MPEG2_L2_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG4_P2_TS_ASP_MPEG2_L2_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_ASF_SP_G726 \
  "http-get:*:video/x-ms-asf:DLNA.ORG_PN=MPEG4_P2_ASF_SP_G726"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_SP_VGA_AAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_SP_VGA_AAC"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_SP_VGA_HEAAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_SP_VGA_HEAAC"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_ASP_AAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_ASP_AAC"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_ASP_HEAAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_ASP_HEAAC"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_SP_HEAAC_MULT5 \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_SP_HEAAC_MULT5"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_ASP_HEAAC_MULT5 \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_ASP_HEAAC_MULT5"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_ASP_ATRAC3PLUS \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_ASP_ATRAC3plus"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_ASP_AAC \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG4_P2_TS_ASP_AAC"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_ASP_AAC_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG4_P2_TS_ASP_AAC_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_ASP_AAC_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG4_P2_TS_ASP_AAC_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_ASP_MPEG1_L3 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG4_P2_TS_ASP_MPEG1_L3"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_ASP_MPEG1_L3_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG4_P2_TS_ASP_MPEG1_L3_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_ASP_MPEG1_L3_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG4_P2_TS_ASP_MPEG1_L3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_ASP_AC3 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG4_P2_TS_ASP_AC3"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_ASP_AC3_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG4_P2_TS_ASP_AC3_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_ASP_AC3_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG4_P2_TS_ASP_AC3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_ASP_L5_SO_AAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_ASP_L5_SO_AAC"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_ASP_L5_SO_HEAAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_ASP_L5_SO_HEAAC"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_ASP_L5_SO_HEAAC_MULT5 \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_ASP_L5_SO_HEAAC_MULT5"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_ASF_ASP_L5_SO_G726 \
  "http-get:*:video/x-ms-asf:DLNA.ORG_PN=MPEG4_P2_ASF_ASP_L5_SO_G726"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_ASP_L4_SO_AAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_ASP_L4_SO_AAC"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_ASP_L4_SO_HEAAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_ASP_L4_SO_HEAAC"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_ASP_L4_SO_HEAAC_MULT5 \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_ASP_L4_SO_HEAAC_MULT5"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_ASF_ASP_L4_SO_G726 \
  "http-get:*:video/x-ms-asf:DLNA.ORG_PN=MPEG4_P2_ASF_ASP_L4_SO_G726"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_H263_MP4_P0_L10_AAC \
  "http-get:*:video/3gpp:DLNA.ORG_PN=MPEG4_H263_MP4_P0_L10_AAC"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_H263_MP4_P0_L10_AAC_LTP \
  "http-get:*:video/3gpp:DLNA.ORG_PN=MPEG4_H263_MP4_P0_L10_AAC_LTP"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_H263_3GPP_P0_L10_AMR_WBPLUS \
  "http-get:*:video/3gpp:DLNA.ORG_PN=MPEG4_H263_3GPP_P0_L10_AMR_WBplus"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_CO_AC3 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG4_P2_TS_CO_AC3"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_CO_AC3_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG4_P2_TS_CO_AC3_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_CO_AC3_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG4_P2_TS_CO_AC3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_CO_MPEG2_L2 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG4_P2_TS_CO_MPEG2_L2"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_CO_MPEG2_L2_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG4_P2_TS_CO_MPEG2_L2_T"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_TS_CO_MPEG2_L2_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=MPEG4_P2_TS_CO_MPEG2_L2_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_3GPP_SP_L0B_AAC_V3GPP \
  "http-get:*:video/3gpp:DLNA.ORG_PN=MPEG4_P2_3GPP_SP_L0B_AAC"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_3GPP_SP_L0B_AAC_VMP4 \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_3GPP_SP_L0B_AAC"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_3GPP_SP_L0B_AMR_V3GPP \
  "http-get:*:video/3gpp:DLNA.ORG_PN=MPEG4_P2_3GPP_SP_L0B_AMR"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_3GPP_SP_L0B_AMR_VMP4 \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_3GPP_SP_L0B_AMR"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_H263_3GPP_P3_L10_AMR_V3GPP \
  "http-get:*:video/3gpp:DLNA.ORG_PN=MPEG4_H263_3GPP_P3_L10_AMR"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_H263_3GPP_P3_L10_AMR_VMP4 \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_H263_3GPP_P3_L10_AMR"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_H263_MP4_P0_L45_HEAACV2_L2 \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_H263_MP4_P0_L45_HEAACv2_L2"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_3GPP_SP_L0B_AMR_WBPLUS \
  "http-get:*:video/3gpp:DLNA.ORG_PN=MPEG4_P2_3GPP_SP_L0B_AMR_WBplus"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_SP_L0B_HEAACV2_L2 \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_SP_L0B_HEAACv2_L2"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_3GPP_SP_L3_AMR_WBPLUS \
  "http-get:*:video/3gpp:DLNA.ORG_PN=MPEG4_P2_3GPP_SP_L3_AMR_WBplus"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_SP_L3_HEAACV2_L2 \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_SP_L3_HEAACv2_L2"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_SP_VGA_HEAAC_RES \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_SP_VGA_HEAAC_res"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_SP_VGA_AAC_RES \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_SP_VGA_AAC_res"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_SP_L6_AAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_SP_L6_AAC"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_SP_L6_AAC_LTP \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_SP_L6_AAC_LTP"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_SP_L6_HEAAC_L2 \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_SP_L6_HEAAC_L2"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_NDSD \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_NDSD"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_H263_3GPP_P0_L10_AMR \
  "http-get:*:video/3gpp:DLNA.ORG_PN=MPEG4_H263_3GPP_P0_L10_AMR"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_H263_3GPP_P0_L45_AMR \
  "http-get:*:video/3gpp:DLNA.ORG_PN=MPEG4_H263_3GPP_P0_L45_AMR"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_H263_3GPP_P0_L45_AMR_WBPLUS \
  "http-get:*:video/3gpp:DLNA.ORG_PN=MPEG4_H263_3GPP_P0_L45_AMR_WBplus"

#define DLNA_CMS_SINK_PROTO_HTTP_MPEG4_P2_MP4_SP_L5_AAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=MPEG4_P2_MP4_SP_L5_AAC"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_SD_AAC_MULT5 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_SD_AAC_MULT5"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_SD_AAC_MULT5_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_SD_AAC_MULT5_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_SD_AAC_MULT5_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_MP_SD_AAC_MULT5_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_SD_HEAAC_L2 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_SD_HEAAC_L2"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_SD_HEAAC_L2_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_SD_HEAAC_L2_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_SD_HEAAC_L2_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_MP_SD_HEAAC_L2_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_SD_MPEG1_L3 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_SD_MPEG1_L3"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_SD_MPEG1_L3_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_SD_MPEG1_L3_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_SD_MPEG1_L3_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_MP_SD_MPEG1_L3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_SD_AC3 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_SD_AC3"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_SD_AC3_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_SD_AC3_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_SD_AC3_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_MP_SD_AC3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_SD_AAC_LTP \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_SD_AAC_LTP"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_SD_AAC_LTP_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_SD_AAC_LTP_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_SD_AAC_LTP_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_MP_SD_AAC_LTP_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_SD_AAC_LTP_MULT5 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_SD_AAC_LTP_MULT5"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_SD_AAC_LTP_MULT5_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_SD_AAC_LTP_MULT5_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_SD_AAC_LTP_MULT5_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_MP_SD_AAC_LTP_MULT5_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_SD_AAC_LTP_MULT7 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_SD_AAC_LTP_MULT7"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_SD_AAC_LTP_MULT7_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_SD_AAC_LTP_MULT7_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_SD_AAC_LTP_MULT7_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_MP_SD_AAC_LTP_MULT7_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_SD_BSAC \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_SD_BSAC"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_SD_BSAC_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_SD_BSAC_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_SD_BSAC_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_MP_SD_BSAC_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_MP_SD_AAC_MULT5 \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_MP_SD_AAC_MULT5"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_MP_SD_HEAAC_L2 \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_MP_SD_HEAAC_L2"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_MP_SD_MPEG1_L3 \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_MP_SD_MPEG1_L3"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_MP_SD_AC3 \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_MP_SD_AC3"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_MP_SD_AAC_LTP \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_MP_SD_AAC_LTP"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_MP_SD_AAC_LTP_MULT5 \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_MP_SD_AAC_LTP_MULT5"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_MP_SD_AAC_LTP_MULT7 \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_MP_SD_AAC_LTP_MULT7"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_MP_SD_ATRAC3plus \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_MP_SD_ATRAC3plus"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_L3L_SD_AAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_L3L_SD_AAC"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_L3L_SD_HEAAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_L3L_SD_HEAAC"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_L3_SD_AAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_L3_SD_AAC"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_MP_SD_BSAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_MP_SD_BSAC"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF30_AAC_MULT5 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_BL_CIF30_AAC_MULT5"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF30_AAC_MULT5_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_BL_CIF30_AAC_MULT5_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF30_AAC_MULT5_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_BL_CIF30_AAC_MULT5_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF30_HEAAC_L2 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_BL_CIF30_HEAAC_L2"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF30_HEAAC_L2_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_BL_CIF30_HEAAC_L2_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF30_HEAAC_L2_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_BL_CIF30_HEAAC_L2_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF30_MPEG1_L3 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_BL_CIF30_MPEG1_L3"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF30_MPEG1_L3_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_BL_CIF30_MPEG1_L3_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF30_MPEG1_L3_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_BL_CIF30_MPEG1_L3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF30_AC3 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_BL_CIF30_AC3"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF30_AC3_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_BL_CIF30_AC3_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF30_AC3_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_BL_CIF30_AC3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF30_AAC_LTP \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_BL_CIF30_AAC_LTP"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF30_AAC_LTP_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_BL_CIF30_AAC_LTP_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF30_AAC_LTP_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_BL_CIF30_AAC_LTP_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF30_AAC_LTP_MULT5 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_BL_CIF30_AAC_LTP_MULT5"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF30_AAC_LTP_MULT5_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_BL_CIF30_AAC_LTP_MULT5_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF30_AAC_LTP_MULT5_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_BL_CIF30_AAC_LTP_MULT5_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF30_AAC_940 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_BL_CIF30_AAC_940"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF30_AAC_940_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_BL_CIF30_AAC_940_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF30_AAC_940_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_BL_CIF30_AAC_940_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_CIF30_AAC_MULT5 \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_CIF30_AAC_MULT5"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_CIF30_HEAAC_L2 \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_CIF30_HEAAC_L2"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_CIF30_MPEG1_L3 \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_CIF30_MPEG1_L3"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_CIF30_AC3 \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_CIF30_AC3"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_CIF30_AAC_LTP \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_CIF30_AAC_LTP"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_CIF30_AAC_LTP_MULT5 \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_CIF30_AAC_LTP_MULT5"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_L2_CIF30_AAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_L2_CIF30_AAC"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_CIF30_BSAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_CIF30_BSAC"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_CIF30_BSAC_MULT5 \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_CIF30_BSAC_MULT5"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_CIF30_AAC_940 \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_CIF30_AAC_940"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_CIF15_HEAAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_CIF15_HEAAC"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_CIF15_AMR \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_CIF15_AMR"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_HD_AAC_MULT5 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_HD_AAC_MULT5"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_HD_AAC_MULT5_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_HD_AAC_MULT5_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_HD_AAC_MULT5_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_MP_HD_AAC_MULT5_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_HD_HEAAC_L2 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_HD_HEAAC_L2"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_HD_HEAAC_L2_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_HD_HEAAC_L2_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_HD_HEAAC_L2_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_MP_HD_HEAAC_L2_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_HD_MPEG1_L3 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_HD_MPEG1_L3"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_HD_MPEG1_L3_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_HD_MPEG1_L3_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_HD_MPEG1_L3_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_MP_HD_MPEG1_L3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_HD_AC3 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_HD_AC3"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_HD_AC3_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_HD_AC3_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_HD_AC3_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_MP_HD_AC3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_HD_AAC \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_HD_AAC"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_HD_AAC_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_HD_AAC_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_HD_AAC_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_MP_HD_AAC_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_HD_AAC_LTP \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_HD_AAC_LTP"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_HD_AAC_LTP_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_HD_AAC_LTP_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_HD_AAC_LTP_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_MP_HD_AAC_LTP_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_HD_AAC_LTP_MULT5 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_HD_AAC_LTP_MULT5"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_HD_AAC_LTP_MULT5_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_HD_AAC_LTP_MULT5_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_HD_AAC_LTP_MULT5_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_MP_HD_AAC_LTP_MULT5_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_HD_AAC_LTP_MULT7 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_HD_AAC_LTP_MULT7"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_HD_AAC_LTP_MULT7_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_HD_AAC_LTP_MULT7_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_HD_AAC_LTP_MULT7_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_MP_HD_AAC_LTP_MULT7_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF15_AAC \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_BL_CIF15_AAC"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF15_AAC_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_BL_CIF15_AAC_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF15_AAC_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_BL_CIF15_AAC_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF15_AAC_540 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_BL_CIF15_AAC_540"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF15_AAC_540_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_BL_CIF15_AAC_540_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF15_AAC_540_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_BL_CIF15_AAC_540_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF15_AAC_LTP \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_BL_CIF15_AAC_LTP"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF15_AAC_LTP_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_BL_CIF15_AAC_LTP_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF15_AAC_LTP_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_BL_CIF15_AAC_LTP_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF15_BSAC \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_BL_CIF15_BSAC"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF15_BSAC_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_BL_CIF15_BSAC_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_BL_CIF15_BSAC_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_BL_CIF15_BSAC_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_CIF15_AAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_CIF15_AAC"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_CIF15_AAC_520 \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_CIF15_AAC_520"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_CIF15_AAC_LTP \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_CIF15_AAC_LTP"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_CIF15_AAC_LTP_520 \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_CIF15_AAC_LTP_520"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_CIF15_BSAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_CIF15_BSAC"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_L12_CIF15_HEAAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_L12_CIF15_HEAAC"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_L1B_QCIF15_HEAAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_L1B_QCIF15_HEAAC"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_3GPP_BL_CIF30_AMR_WBPLUS \
  "http-get:*:video/3gpp:DLNA.ORG_PN=AVC_3GPP_BL_CIF30_AMR_WBplus"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_3GPP_BL_CIF15_AMR_WBPLUS \
  "http-get:*:video/3gpp:DLNA.ORG_PN=AVC_3GPP_BL_CIF15_AMR_WBplus"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_3GPP_BL_QCIF15_AAC \
  "http-get:*:video/3gpp:DLNA.ORG_PN=AVC_3GPP_BL_QCIF15_AAC"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_3GPP_BL_QCIF15_AAC_LTP \
  "http-get:*:video/3gpp:DLNA.ORG_PN=AVC_3GPP_BL_QCIF15_AAC_LTP"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_3GPP_BL_QCIF15_HEAAC \
  "http-get:*:video/3gpp:DLNA.ORG_PN=AVC_3GPP_BL_QCIF15_HEAAC"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_3GPP_BL_QCIF15_AMR_WBPLUS \
  "http-get:*:video/3gpp:DLNA.ORG_PN=AVC_3GPP_BL_QCIF15_AMR_WBplus"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_3GPP_BL_QCIF15_AMR \
  "http-get:*:video/3gpp:DLNA.ORG_PN=AVC_3GPP_BL_QCIF15_AMR"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_3GPP_BL_L1B_QCIF15_AMR \
  "http-get:*:video/3gpp:DLNA.ORG_PN=AVC_3GPP_BL_L1B_QCIF15_AMR"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_3GPP_BL_L1B_QCIF15_AMR_WBPLUS \
  "http-get:*:video/3gpp:DLNA.ORG_PN=AVC_3GPP_BL_L1B_QCIF15_AMR_WBplus"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HP_SD_HEAACV2_L4_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_HP_SD_HEAACv2_L4_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HP_SD_HEAACV2_L4_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_HP_SD_HEAACv2_L4_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_HP_SD_HEAACV2_L4 \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_HP_SD_HEAACv2_L4"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HP_HD_HEAACV2_L4_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_HP_HD_HEAACv2_L4_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HP_HD_HEAACV2_L4_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_HP_HD_HEAACv2_L4_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_HP_HD_HEAACV2_L4 \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_HP_HD_HEAACv2_L4"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_CIF15_HEAACV2_L2 \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_CIF15_HEAACv2_L2"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_CIF30_HEAACV2_L2 \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_CIF30_HEAACv2_L2"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_3GPP_BL_CIF15_AMR_WBPLUS_RES \
  "http-get:*:video/3gpp:DLNA.ORG_PN=AVC_3GPP_BL_CIF15_AMR_WBplus_res"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_3GPP_BL_CIF30_AMR_WBPLUS_RES \
  "http-get:*:video/3gpp:DLNA.ORG_PN=AVC_3GPP_BL_CIF30_AMR_WBplus_res"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_PS_HD_DTS \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_PS_HD_DTS"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_PS_HD_DTSHD_HRA \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_PS_HD_DTSHD_HRA"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_PS_HD_DTSHD_MA \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_PS_HD_DTSHD_MA"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_PS_HD_DTSHD \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_PS_HD_DTSHD"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_SD_EAC3_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_SD_EAC3_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_SD_EAC3_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_MP_SD_EAC3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HP_SD_AC3_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_HP_SD_AC3_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HP_SD_AC3_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_HP_SD_AC3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HP_SD_EAC3_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_HP_SD_EAC3_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HP_SD_EAC3_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_HP_SD_EAC3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HP_SD_MPEG1_L2_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_HP_SD_MPEG1_L2_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HP_SD_MPEG1_L2_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_HP_SD_MPEG1_L2_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_SD_EU \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_SD_EU"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_SD_EU_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_SD_EU_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_SD_EU_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_SD_EU_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_HD_EAC3_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_HD_EAC3_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_MP_HD_EAC3_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_MP_HD_EAC3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HP_HD_AC3_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_HP_HD_AC3_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HP_HD_AC3_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_HP_HD_AC3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HP_HD_EAC3_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_HP_HD_EAC3_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HP_HD_EAC3_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_HP_HD_EAC3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HP_HD_MPEG1_L2_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_HP_HD_MPEG1_L2_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HP_HD_MPEG1_L2_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_HP_HD_MPEG1_L2_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HD_EU \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_HD_EU"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HD_EU_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_HD_EU_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HD_EU_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_HD_EU_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_JP_AAC_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_JP_AAC_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HD_60_AC3 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_HD_60_AC3"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HD_60_AC3_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_HD_60_AC3_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HD_60_AC3_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_HD_60_AC3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HD_50_AC3 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_HD_50_AC3"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HD_50_AC3_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_HD_50_AC3_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HD_50_AC3_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_HD_50_AC3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HD_24_AC3 \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_HD_24_AC3"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HD_24_AC3_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_HD_24_AC3_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HD_24_AC3_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_HD_24_AC3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HD_DTS_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_HD_DTS_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HD_DTS_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_HD_DTS_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HD_DTSHD_HRA_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_HD_DTSHD_HRA_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HD_DTSHD_HRA_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_HD_DTSHD_HRA_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HD_DTSHD_MA_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_HD_DTSHD_MA_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HD_DTSHD_MA_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_HD_DTSHD_MA_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_DTSHD_MA_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_DTSHD_MA_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_DTSHD_MA_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_DTSHD_MA_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_L1B_QCIF15_HEAACV2 \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_L1B_QCIF15_HEAACv2"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_L12_CIF15_HEAACV2 \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_L12_CIF15_HEAACv2"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_CIF30_HEAAC_MPS \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_CIF30_HEAAC_MPS"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_MP_SD_AAC_MPS \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_MP_SD_AAC_MPS"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_MP_SD_HEAAC_MPS \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_MP_SD_HEAAC_MPS"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_MP_SD_HEAAC_L4 \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_MP_SD_HEAAC_L4"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_MP_HD_AAC_MPS \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_MP_HD_AAC_MPS"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_MP_HD_HEAAC_MPS \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_MP_HD_HEAAC_MPS"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_MP_HD_720P_AAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_MP_HD_720p_AAC"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_MP_HD_1080I_AAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_MP_HD_1080i_AAC"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_HP_HD_AAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_HP_HD_AAC"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_HP_HD_AAC_LTP \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_HP_HD_AAC_LTP"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_HP_HD_HEAAC_L2 \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_HP_HD_HEAAC_L2"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_HP_HD_HEAAC_MULT7 \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_HP_HD_HEAAC_MULT7"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_NDHD \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_NDHD"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_3GPP_BL_L12_CIF15_AMR_WBPLUS \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_3GPP_BL_L12_CIF15_AMR_WBplus"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HD_60_AC3_X_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_HD_60_AC3_X_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HD_50_AC3_X_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_HD_50_AC3_X_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HD_24_AC3_X_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_HD_24_AC3_X_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HD_60_LPCM_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_HD_60_LPCM_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HD_50_LPCM_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_HD_50_LPCM_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_HD_24_LPCM_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_HD_24_LPCM_T"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_L12_CIF15_HEAACV2_350 \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_L12_CIF15_HEAACv2_350"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_CIF15_AAC_350 \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_CIF15_AAC_350"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_CIF15_HEAAC_350 \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_CIF15_HEAAC_350"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_MP_SD_AAC_LC \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_MP_SD_AAC_LC"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_L31_HD_AAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_L31_HD_AAC"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_MP4_BL_L32_HD_AAC \
  "http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_L32_HD_AAC"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_NA_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=AVC_TS_NA_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_AVC_TS_NA_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_NA_T"


/* WMV9 */
#define DLNA_CMS_SINK_PROTO_HTTP_WMVMED_BASE \
  "http-get:*:video/x-ms-wmv:DLNA.ORG_PN=WMVMED_BASE"

#define DLNA_CMS_SINK_PROTO_HTTP_WMVMED_FULL \
  "http-get:*:video/x-ms-wmv:DLNA.ORG_PN=WMVMED_FULL"

#define DLNA_CMS_SINK_PROTO_HTTP_WMVMED_PRO \
  "http-get:*:video/x-ms-wmv:DLNA.ORG_PN=WMVMED_PRO"

#define DLNA_CMS_SINK_PROTO_HTTP_WMVHIGH_FULL \
  "http-get:*:video/x-ms-wmv:DLNA.ORG_PN=WMVHIGH_FULL"

#define DLNA_CMS_SINK_PROTO_HTTP_WMVHIGH_PRO \
  "http-get:*:video/x-ms-wmv:DLNA.ORG_PN=WMVHIGH_PRO"

#define DLNA_CMS_SINK_PROTO_HTTP_WMVHM_BASE \
  "http-get:*:video/x-ms-wmv:DLNA.ORG_PN=WMVHM_BASE"

#define DLNA_CMS_SINK_PROTO_HTTP_WMVSPLL_BASE \
  "http-get:*:video/x-ms-wmv:DLNA.ORG_PN=WMVSPLL_BASE"

#define DLNA_CMS_SINK_PROTO_HTTP_WMVSPML_BASE \
  "http-get:*:video/x-ms-wmv:DLNA.ORG_PN=WMVSPML_BASE"

#define DLNA_CMS_SINK_PROTO_HTTP_WMVSPML_MP3 \
  "http-get:*:video/x-ms-wmv:DLNA.ORG_PN=WMVSPML_MP3"

/* VC-1 */
#define DLNA_CMS_SINK_PROTO_HTTP_VC1_PS_HD_DTS \
  "http-get:*:video/mpeg:DLNA.ORG_PN=VC1_PS_HD_DTS"

#define DLNA_CMS_SINK_PROTO_HTTP_VC1_PS_HD_DTSHD_HRA \
  "http-get:*:video/mpeg:DLNA.ORG_PN=VC1_PS_HD_DTSHD_HRA"

#define DLNA_CMS_SINK_PROTO_HTTP_VC1_PS_HD_DTSHD_MA \
  "http-get:*:video/mpeg:DLNA.ORG_PN=VC1_PS_HD_DTSHD_MA"

#define DLNA_CMS_SINK_PROTO_HTTP_VC1_PS_HD_DTSHD \
  "http-get:*:video/mpeg:DLNA.ORG_PN=VC1_PS_HD_DTSHD"

#define DLNA_CMS_SINK_PROTO_HTTP_VC1_TS_AP_L1_AC3_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=VC1_TS_AP_L1_AC3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_VC1_TS_AP_L1_WMA_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=VC1_TS_AP_L1_WMA_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_VC1_TS_AP_L2_AC3_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=VC1_TS_AP_L2_AC3_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_VC1_TS_AP_L2_WMA_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=VC1_TS_AP_L2_WMA_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_VC1_TS_HD_DTS_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=VC1_TS_HD_DTS_T"

#define DLNA_CMS_SINK_PROTO_HTTP_VC1_TS_HD_DTS_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=VC1_TS_HD_DTS_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_VC1_TS_HD_DTSHD_HRA_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=VC1_TS_HD_DTSHD_HRA_T"

#define DLNA_CMS_SINK_PROTO_HTTP_VC1_TS_HD_DTSHD_HRA_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=VC1_TS_HD_DTSHD_HRA_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_VC1_TS_HD_DTSHD_MA_T \
  "http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=VC1_TS_HD_DTSHD_MA_T"

#define DLNA_CMS_SINK_PROTO_HTTP_VC1_TS_HD_DTSHD_MA_ISO \
  "http-get:*:video/mpeg:DLNA.ORG_PN=VC1_TS_HD_DTSHD_MA_ISO"

#define DLNA_CMS_SINK_PROTO_HTTP_VC1_ASF_AP_L1_WMA \
  "http-get:*:video/x-ms-asf:DLNA.ORG_PN=VC1_ASF_AP_L1_WMA"

#define DLNA_CMS_SINK_PROTO_HTTP_VC1_ASF_AP_L2_WMA \
  "http-get:*:video/x-ms-asf:DLNA.ORG_PN=VC1_ASF_AP_L2_WMA"

/*undefined DLNA gudeline following profiles. but it may be that required for extend function*/
/* image */
#define DLNA_CMS_SINK_PROTO_HTTP_BMP \
  "http-get:*:image/bmp:"

#define DLNA_CMS_SINK_PROTO_HTTP_GIF \
  "http-get:*:image/gif:"

#define DLNA_CMS_SINK_PROTO_HTTP_PNG \
  "http-get:*:image/png:"

/* audio */
#define DLNA_CMS_SINK_PROTO_HTTP_WAV \
  "http-get:*:audio/wav:"

#define DLNA_CMS_SINK_PROTO_HTTP_ISO \
  "http-get:*:application/x-iso-image:*"

#define DLNA_CMS_SINK_PROTO_HTTP_IMG \
  "http-get:*:application/x-cd-image:*"

#define DLNA_CMS_SINK_PROTO_HTTP_DVRMS \
  "http-get:*:video/x-ms-dvr:*"

#define DLNA_CMS_SINK_PROTO_HTTP_M3U \
  "http-get:*:application/x-mpegurl:"

#define DLNA_CMS_SINK_PROTO_HTTP_3GPP_AUDIO \
  "http-get:*:audio/3gpp:"

#define DLNA_CMS_SINK_PROTO_HTTP_MP4_AUDIO \
  "http-get:*:audio/mp4:"

/* audio video */
#define DLNA_CMS_SINK_PROTO_HTTP_MP4_VIDEO \
  "http-get:*:video/mp4:"

#define DLNA_CMS_SINK_PROTO_HTTP_3GPP_VIDEO \
  "http-get:*:video/3gpp:"

#define DLNA_CMS_PROTO_HTTP_AVI AVI_PINFO_STR
#define DLNA_CMS_PROTO_HTTP_DIVX DIVX_PINFO_STR

/* minfo_t and related elements moved to public header for parser plugin module */
#include <minfo.h>

struct media_class;
struct sbuf;

typedef slim_int
(*append_supported_pinfo_proc_t)(struct media_class *self, struct sbuf *in_buf);

typedef dlna_ret_t (*info_get_proc_t)(minfo_t *png);

/* media_class_t */
struct media_class {
  struct media_class *next;
  struct media_class *prev;

  slim_int type;

  /* class functions */
  append_supported_pinfo_proc_t append_supported_pinfo_proc;
  info_get_proc_t info_get_proc;
};

typedef struct media_class media_class_t;


struct jpeg_rescale_processing_interface;

struct media_jpeg_rescale_configuration
{
  enum media_jpeg_rescale_method {
    MEDIA_JPEG_RESCALE_LINE_BY_LINE,
    MEDIA_JPEG_RESCALE_WHOLE_IMAGE,
  } method;

  union {
    struct {
      slim_word memory_limit;
    } whole_image;
  };
};

/* media_manager_t */
struct media_manager {
  List(media_class_t *) media_class_list;

  slim_char *source_pinfo_str;
  minfo_t default_image_thumbnail_minfo;
  minfo_t default_video_thumbnail_minfo;

#ifdef MEDIA_PROCESSING_EXTENSION
 slim_int mpe_server_port;

 mpe_dlna_mime_translation_table_t *mime_type_tr_table;
 slim_word mime_type_tr_table_size;
#endif /*MEDIA_PROCESSING_EXTENSION*/


  struct jpeg_rescale_processing_interface * jpeg_rescale;
};

typedef struct media_manager media_manager_t;

/* Album art types
 * From the most approprite one to the worst.
 * E.g. Front is better than back.
 */
typedef enum album_art_type
{
  ALBUM_ART_FRONT,
  ALBUM_ART_BACK,
  ALBUM_ART_UNKNOWN,
  ALBUM_ART_INVALID
} album_art_type_t;

typedef struct albumArtImage_ {
  slim_char mimeType[MIME_TYPE_LEN];
  slim_int  data_size;
  slim_char *data;
  album_art_type_t type;
}albumArtImage;


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_bool
media_time_seek_adjust(pinfo_t *pinfo, slim_char *full_path, dlna_uint64 *in_file_size,
                       dlna_timeval *in_seek_time, dlna_uint64 *inout_seek_bytes);

contents_type_t
media_ctype_get_by_suffix (slim_char *in_name);

contents_type_t
contents_storage_get_media_class_type_by_type(contents_type_t type);

/* Get the content type based on the */
contents_type_t
media_ctype_get_by_mime(dlna_split_ss * mime);

contents_type_t
media_ctype_get_by_pinfo (pinfo_t *pinfo);

slim_char *
media_suffix_get_by_ctype (contents_type_t ctype);

slim_char *
info_media_generate_file_full_path (void* cm, slim_char *in_parent_path, slim_char *in_file_name, slim_char *in_pinfo, slim_int in_max_length);

/* Get the media information.  */
dlna_ret_t
media_info_get (media_manager_t *mim, minfo_t *info);

#ifdef DEVELOPMENT_NFLC_PROFILER
dlna_ret_t
media_info_parse (media_manager_t *mim, minfo_t *info);
#endif /* DEVELOPMENT_NFLC_PROFILER */

#ifdef MEDIA_PROCESSING_EXTENSION
void
media_pinfo_get (minfo_t *info, slim_char *source_pinfo_str);

const slim_char *
getDlnaMimeStr(const slim_char * mpeMimeStr);

const slim_char *
getDlnaMimeStr2(const slim_char * mpeMimeStr,media_manager_t *mim);
#endif /* MEDIA_PROCESSING_EXTENSION */

/* Free the media information.  */
void
media_info_free (minfo_t *info);

slim_char *
media_get_title(minfo_t *in_info);

slim_char *
media_get_filename(minfo_t *in_info);

slim_char *
media_get_upup_class(minfo_t *in_info);

slim_char *
media_get_upnp_class_from_path(slim_char *full_path);

slim_char *
media_get_upnp_class_from_mime_type(slim_char *mimeType);

slim_int
media_set_upup_class_flag_from_path(minfo_t *in_info, slim_char *in_full_path);

slim_char *
media_get_pinfo_by_path(slim_char *full_path);

dlna_ret_t
media_get_duration(minfo_t *in_info);

slim_char *
media_jpeg_proto_lookup (minfo_t *in_info, slim_int profile);

#ifdef USE_RESIZE_IMAGE_PNG
slim_char *
media_png_proto_lookup (minfo_t *in_info, slim_int profile);
#endif

slim_char *
media_get_pinfo(minfo_t *in_info, slim_char* pinfo, slim_int in_flags);

/* Setup the res@protocolInfo.  */
slim_bool
media_pinfo_set (pinfo_t *pinfo, slim_int mtype, slim_char *pinfo_str);

void
media_pinfo_unset (pinfo_t *pinfo, slim_int mtype);

#ifdef HAVE_DTCP
/* DRM */
slim_bool
contents_drm_manager_initialize(drm_manager_t *self);

void
contents_drm_manager_finalize(drm_manager_t *self);

#define contents_drm_manager_set_drm_proc(self, in_proc) ((self)->get_info_proc = (in_proc))
#define contents_drm_manager_delete_drm_proc(self) ((self)->get_info_proc = slim_nil)

media_drm_t
contents_drm_manager_get_drm_info(drm_manager_t *self, minfo_t *in_info);

drm_entry_t *
contents_drm_manager_find_entry(drm_manager_t *self, media_drm_t in_type);

slim_int
contents_drm_manager_add_entry(drm_manager_t *self, drm_entry_t *in_entry);

void
contents_drm_manager_delete_drm_entry(drm_manager_t *self, media_drm_t in_type);
#endif /* HAVE_DTCP */

slim_bool
media_manager_register_all(media_manager_t *mim);

slim_bool
media_manager_prepare_source_pinfo(media_manager_t *mim);

dlna_ret_t
media_manager_prepare_default_minfo(media_manager_t *mim,
                                    const slim_char *image_path,
                                    const slim_char *video_path);

media_manager_t*
media_manager_alloc();

media_manager_t*
media_manager_alloc_with_jpeg_rescale(struct media_jpeg_rescale_configuration * jpeg_configuration, slim_char *in_xml_dir);

void
media_manager_free(media_manager_t *mim);

void
media_manager_register_class(media_manager_t *mim,
                                  media_class_t *in_media_cls);

media_class_t*
media_class_alloc(slim_int in_type,
         append_supported_pinfo_proc_t in_append_supported_pinfo_proc,
         info_get_proc_t in_info_get_proc);

void
media_class_free(media_class_t *media_cls);

slim_bool
media_has_metadata_title(minfo_t *in_info);

void
media_get_pinfo_by_mime(slim_char* mime, slim_char **out_pinfo);

slim_bool
media_get_supported_content_type(slim_int in_type);

albumArtImage*
media_get_embedded_albumart_image(contents_type_t media_type, slim_char* file_path);

dlna_ret_t
media_create_reference(media_manager_t *mim,
    minfo_t* info,
    slim_int ref_permillage,
    slim_int ref_scaletype,
    slim_char* media_fullpath,
    slim_int media_class,
    slim_int media_type

#ifdef MEDIA_PROCESSING_EXTENSION
    , access_config_t * access_cfg
#endif /*MEDIA_PROCESSING_EXTENSION*/
    );


#ifdef DEVELOPMENT_MATROSKA_EMBEDED_ALBUM_ART

#define MEDIA_EXTRACT_ATTACHMENT_EMBEDED_ALBUM_ART_URI_PREFIX "/embeddedMPE"

/**
 * Extracts attachments, like cover art, from media file.
 * @param in_media_path
 * @param in_output_path
 * @param in_stream_index
 * @return MINFO_OK at success.
 */
slim_int
media_extract_attachment(slim_char * in_media_path,
    slim_char * in_output_path,
    slim_word in_stream_index,
    slim_int in_mpe_port);

/**
 * Obtain required info from uri and calls media_extract_attachment
 * @param in_uri
 * @param output_path
 * @return MINFO_OK at success.
 */
slim_int
media_extract_attachment_by_uri(slim_char * in_uri,
    slim_char * output_path,
    slim_int in_mpe_port);

/**
 * Loads image
 * @param in_output_path
 * @param out_image
 * @return
 */
slim_int
media_extract_attachment_load_image(slim_char * in_image_path,
    albumArtImage ** out_image);

/**
 * Returns uri prefix for attachment in file
 * @param in_attachment_info
 * @param out_prefix
 * @return MINFO_OK at success.
 */
slim_int
media_extract_attachment_get_uri_prefix(
    struct _media_attachment_info * in_attachment_info,
    slim_char ** out_prefix);

#endif /* DEVELOPMENT_MATROSKA_EMBEDED_ALBUM_ART */


#ifdef DEVELOPMENT_ENABLE_PLAYLIST_CONTAINER

struct media_playlist_entry
{
  struct media_playlist_entry * next;
  struct media_playlist_entry * prev;

  slim_char * file_path;
  slim_word file_path_length;
  slim_word is_file_path_relative;
#ifdef DEVELOPEMENT_WINDOWS_PLAYLISTS
  slim_word is_windows_or_samba_path;
#endif /*DEVELOPEMENT_WINDOWS_PLAYLISTS*/
};

struct media_playlist
{
  slim_char * base_path;
  slim_word base_path_length;
  List(struct media_playlist_entry *) entries;
};

struct media_playlist_entry *
media_playlist_entry_alloc();

void
media_playlist_entry_free(struct media_playlist_entry * entry);

struct media_playlist *
media_playlist_alloc();

slim_int
media_playlist_init(slim_char * file_path, struct media_playlist * playlist);

void
media_playlist_clean(struct media_playlist * playlist);

void
media_playlist_free(struct media_playlist * playlist);

#endif /* DEVELOPMENT_ENABLE_PLAYLIST_CONTAINER */

slim_bool
media_is_aligned_properly (slim_char *in_content_path, slim_char *in_pinfo, 
                           dlna_uint64 in_start_byte, dlna_uint64 in_end_byte);

slim_int
media_get_aligned_byte_position (slim_char *in_content_path, slim_char *in_pinfo,
                                 dlna_uint64 in_sp, dlna_uint64 in_ep,
                                 dlna_uint64 *out_aligned_sp, dlna_uint64 *out_aligned_ep);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_INFO_MEDIA_H */
