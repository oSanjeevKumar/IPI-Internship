/*
 * nflc_media_mime.h
 * Copyright (C) 2007-2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2011. Access Company All Rights Reserved.  */

#ifndef NFLC_MEDIA_MIME_H
#define NFLC_MEDIA_MIME_H

#include <dlna_peer.h>
#include "info_media.h"


#define NFLC_MIME_TYPE_VIDEO_ASF        "video/x-ms-asf"
#define NFLC_MIME_TYPE_VIDEO_AVI        "video/avi"
#define NFLC_MIME_TYPE_VIDEO_DV         "video/x-dv"
#define NFLC_MIME_TYPE_VIDEO_DIVX       "video/divx"
#define NFLC_MIME_TYPE_VIDEO_WMV        "video/x-ms-wmv"
#define NFLC_MIME_TYPE_VIDEO_MJPEG      "video/x-motion-jpeg"
#define NFLC_MIME_TYPE_VIDEO_MPEG       "video/mpeg"
#define NFLC_MIME_TYPE_VIDEO_MPEGTS     "video/vnd.dlna.mpeg-tts"
#define NFLC_MIME_TYPE_VIDEO_MP2P       "video/mp2p"
#define NFLC_MIME_TYPE_VIDEO_MP2T       "video/mp2t"
#define NFLC_MIME_TYPE_VIDEO_MPEG2      "video/mpeg2"
#define NFLC_MIME_TYPE_VIDEO_WEBM       "video/webm"

  /* MPEG DASH */
#ifdef DEVELOPMENT_ENABLE_ADS
#define NFLC_MIME_TYPE_VIDEO_MPD        "application/dash+xml"
#endif /* DEVELOPMENT_ENABLE_ADS */

#define NFLC_MIME_TYPE_VIDEO_MP4        "video/mp4"
#define NFLC_MIME_TYPE_VIDEO_MP4PS      "video/x-nerodigital-ps"
#define NFLC_MIME_TYPE_VIDEO_QT         "video/quicktime"
#define NFLC_MIME_TYPE_VIDEO_MKV        "video/x-mkv"
#define NFLC_MIME_TYPE_VIDEO_3GP        "video/3gpp"
#define NFLC_MIME_TYPE_VIDEO_OGG        "video/x-ogg"
#define NFLC_MIME_TYPE_VIDEO_FLV        "video/x-flv"
#define NFLC_MIME_TYPE_VIDEO_M2TS       "video/mpeg"
#define NFLC_MIME_TYPE_VIDEO_VDR        "video/x-vdr"
#define NFLC_MIME_TYPE_VIDEO_TP         "application/octet-stream"
#define NFLC_MIME_TYPE_VIDEO_SWF        "application/vnd.adobe.flash-movie"
#define NFLC_MIME_TYPE_VIDEO_DVR_MS     "video/x-ms-dvr"
#define NFLC_MIME_TYPE_VIDEO_VC1        "video/vc1"
#define NFLC_MIME_TYPE_VIDEO_MJ2        "video/mj2"

#define NFLC_MIME_TYPE_AUDIO_3GP        "audio/3gpp"
#define NFLC_MIME_TYPE_AUDIO_AAC        "audio/x-aac"
#define NFLC_MIME_TYPE_AUDIO_AC3        "audio/x-ac3"
#define NFLC_MIME_TYPE_AUDIO_AIFF       "audio/x-aiff"
#define NFLC_MIME_TYPE_AUDIO_AT3P       "audio/x-atrac3"
#define NFLC_MIME_TYPE_AUDIO_BASIC      "audio/basic"
#define NFLC_MIME_TYPE_AUDIO_DTS        "audio/vnd.dts"
#define NFLC_MIME_TYPE_AUDIO_DTSHD      "audio/vnd.dts.hd"
#define NFLC_MIME_TYPE_AUDIO_ADTS       "audio/vnd.dlna.adts"
#define NFLC_MIME_TYPE_AUDIO_MIDI       "audio/midi"
#define NFLC_MIME_TYPE_AUDIO_MP1        "audio/mp1"
#define NFLC_MIME_TYPE_AUDIO_MP2        "audio/mp2"
#define NFLC_MIME_TYPE_AUDIO_MPEG       "audio/mpeg"
#define NFLC_MIME_TYPE_AUDIO_MP4        "audio/mp4"
#define NFLC_MIME_TYPE_AUDIO_OGG        "audio/x-ogg"
#define NFLC_MIME_TYPE_OGG              "application/ogg"
#define NFLC_MIME_TYPE_AUDIO_WAV        "audio/wav"
#define NFLC_MIME_TYPE_AUDIO_L16        "audio/L16"
#define NFLC_MIME_TYPE_AUDIO_WMA        "audio/x-ms-wma"
#define NFLC_MIME_TYPE_AUDIO_FLAC       "audio/x-flac"
#define NFLC_MIME_TYPE_AUDIO_RA         "audio/x-pn-realaudio"
#define NFLC_MIME_TYPE_AUDIO_MKA        "audio/x-matroska"
#define NFLC_MIME_TYPE_AUDIO_OMA        "audio/x-sony-oma"
#define NFLC_MIME_TYPE_AUDIO_M4A        "audio/m4a"
#define NFLC_MIME_TYPE_AUDIO_MLP        "audio/vnd.dolby.mlp"
#define NFLC_MIME_TYPE_AUDIO_DAB        "application/octet-stream"
#define NFLC_MIME_TYPE_AUDIO_AMR        "audio/3gpp"
#define NFLC_MIME_TYPE_AUDIO_APL        "audio/vnd.dlna.adts"
#define NFLC_MIME_TYPE_AUDIO_IMY        "audio/x-imelody"
#define NFLC_MIME_TYPE_AUDIO_MXMF       "audio/mobile-xmf"
#define NFLC_MIME_TYPE_AUDIO_XMF       "audio/x-xmf"
#define NFLC_MIME_TYPE_AUDIO_RTTTL       "audio/x-rtttl"
#define NFLC_MIME_TYPE_AUDIO_RTX       "application/octet-stream"


#define NFLC_MIME_TYPE_IMAGE_BMP        "image/bmp"
#define NFLC_MIME_TYPE_IMAGE_ICO        "image/x-icon"
#define NFLC_MIME_TYPE_IMAGE_GIF        "image/gif"
#define NFLC_MIME_TYPE_IMAGE_JPEG       "image/jpeg"
#define NFLC_MIME_TYPE_IMAGE_PCD        "image/x-ms-bmp"
#define NFLC_MIME_TYPE_IMAGE_PCX        "image/x-pcx"
#define NFLC_MIME_TYPE_IMAGE_PNG        "image/png"
#define NFLC_MIME_TYPE_IMAGE_PNM        "image/x-portable-anymap"
#define NFLC_MIME_TYPE_IMAGE_PPM        "image/x-portable-pixmap"
#define NFLC_MIME_TYPE_IMAGE_QTI        "image/x-quicktime"
#define NFLC_MIME_TYPE_IMAGE_TIFF       "image/tiff"
#define NFLC_MIME_TYPE_IMAGE_TGA        "image/x-tga"
#define NFLC_MIME_TYPE_IMAGE_WEBP       "image/webp"
#define NFLC_MIME_TYPE_IMAGE_OTA       "application/octet-stream"
 
#define  NFLC_MIME_TYPE_PLAYLIST_M3U "application/x-mpegURL"
#define  NFLC_MIME_TYPE_PLAYLIST_PLS "audio/x-scpls"
#define  NFLC_MIME_TYPE_PLAYLIST_WPL "application/vnd.ms-wpl"
#define  NFLC_MIME_TYPE_PLAYLIST_ASX "video/x-ms-asf"

#define NFLC_MIME_TYPE_SUBTITLE_SUBRIP          "text/srt" /* SubRip */
#define NFLC_MIME_TYPE_SUBTITLE_SUBSTATIONALPHA "text/ssa" /* SubStation Alpha */
#define NFLC_MIME_TYPE_SUBTITLE_POWERDIVX       "text/psb" /* PowerDivX */
#define NFLC_MIME_TYPE_SUBTITLE_PHOENIXJAPANIM  "text/pjs" /* Phoenix Japanim */
#define NFLC_MIME_TYPE_SUBTITLE_MICRODVD        "text/sub" /* MicroDVD */
#define NFLC_MIME_TYPE_SUBTITLE_VOBSUB          "text/idx" /* VOBsub */
#define NFLC_MIME_TYPE_SUBTITLE_DKS             "text/dks" /* DKS */
#define NFLC_MIME_TYPE_SUBTITLE_MACSUB          "text/scr" /* MACsub */
#define NFLC_MIME_TYPE_SUBTITLE_TURBOTITLER     "text/tts" /* TurboTitler */
#define NFLC_MIME_TYPE_SUBTITLE_VIPLAY          "text/vsf" /* ViPlay */
#define NFLC_MIME_TYPE_SUBTITLE_ZEROG           "text/zeg" /* ZeroG */
#define NFLC_MIME_TYPE_SUBTITLE_MPL             "text/mpl" /* MPL */
#define NFLC_MIME_TYPE_SUBTITLE_SCC             "text/scc" /* Scenarist Closed Caption, (Line 21 broadcast closed captions, web media, DVD, iTunes, iPods, iPads, iPhones) */
#define NFLC_MIME_TYPE_SUBTITLE_CPTXML          "text/cptxml" /* Flash Captionate XML (Flash video) */
#define NFLC_MIME_TYPE_SUBTITLE_STL             "text/stl" /* format developed by Spruce Technologies */

#define NFLC_MIME_TYPE_PLAIN_TEXT               "text/plain"
#define NFLC_MIME_TYPE_HTML_TEXT                "text/html"
#define NFLC_MIME_TYPE_WORD                     "application/msword"
#define NFLC_MIME_TYPE_EXCEL                    "application/vnd.ms-excel"
#define NFLC_MIME_TYPE_POWERPOINT               "application/vnd.ms-powerpoint"
#define NFLC_MIME_TYPE_PDF                      "application/pdf"
#define NFLC_MIME_TYPE_ONENOTE                  "application/msonenote"

//OOXML
#define NFLC_MIME_TYPE_OOXML_DOCUMENT               "application/vnd.openxmlformats-officedocument.wordprocessingml.document"
#define NFLC_MIME_TYPE_OOXML_DOCUMENT_TEMPLATE      "application/vnd.openxmlformats-officedocument.wordprocessingml.template"
#define NFLC_MIME_TYPE_OOXML_WORKBOOK               "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet"
#define NFLC_MIME_TYPE_OOXML_WORKBOOK_TEMPLATE      "application/vnd.openxmlformats-officedocument.spreadsheetml.template"
#define NFLC_MIME_TYPE_OOXML_PRESENTATION           "application/vnd.openxmlformats-officedocument.presentationml.presentation"
#define NFLC_MIME_TYPE_OOXML_PRESENTATION_TEMPLATE  "application/vnd.openxmlformats-officedocument.presentationml.template"
#define NFLC_MIME_TYPE_OOXML_PRESENTATION_SLIDESHOW "application/vnd.openxmlformats-officedocument.presentationml.slideshow"
#define NFLC_MIME_TYPE_OOXML_PRESENTATION_SLIDE     "application/vnd.openxmlformats-officedocument.presentationml.slide"

//Macro Enabled
#define NFLC_MIME_TYPE_ME_DOCUMENT               "application/vnd.ms-word.document.macroEnabled.12"
#define NFLC_MIME_TYPE_ME_DOCUMENT_TEMPLATE      "application/vnd.ms-word.template.macroEnabled.12"
#define NFLC_MIME_TYPE_ME_WORKBOOK               "application/vnd.ms-excel.sheet.macroEnabled.12"
#define NFLC_MIME_TYPE_ME_WORKBOOK_TEMPLATE      "application/vnd.ms-excel.template.macroEnabled.12"
#define NFLC_MIME_TYPE_ME_WORKBOOK_ADDIN         "application/vnd.ms-excel.addin.macroEnabled.12"
#define NFLC_MIME_TYPE_ME_BINARY_WORKBOOK        "application/vnd.ms-excel.sheet.binary.macroEnabled.12"
#define NFLC_MIME_TYPE_ME_PRESENTATION           "application/vnd.ms-powerpoint.presentation.macroEnabled.12"
#define NFLC_MIME_TYPE_ME_PRESENTATION_ADDIN     "application/vnd.ms-powerpoint.addin.macroEnabled.12"
#define NFLC_MIME_TYPE_ME_PRESENTATION_TEMPLATE  "application/vnd.ms-powerpoint.template.macroEnabled.12"
#define NFLC_MIME_TYPE_ME_PRESENTATION_SLIDESHOW "application/vnd.ms-powerpoint.slideshow.macroEnabled.12"
#define NFLC_MIME_TYPE_ME_PRESENTATION_SLIDE     "application/vnd.ms-powerpoint.slide.macroEnabled.12"

typedef struct nflc_mime_type {
  contents_type_t media_type;
  slim_char* mime_type;
} nflc_mime_type_t;

slim_char*
nflc_media_get_mimetype(slim_int media_item_type);

#endif /*NFLC_MEDIA_MIME_H*/
