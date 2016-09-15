/*
 * minfo.h
 * Copyright (C) 2013 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef MINFO_H
#define MINFO_H

#include <dlna_memory.h>
#include <nflc_drm_api.h>

/*
 *the epoch time of mp4&3gp file, it equals to the number of seconds which is \
 *from 1904-01-01 00:00:00 to 00:00:00 on January 1, 1970, Coordinated Universal Time(UTC),
 */
#define MEDIA_EPOCH_TIME 2082844800

/* Contents types.  */
typedef enum contents_type
{
  CONTENTS_TYPE_UNKNOWN = 0,
  CONTENTS_TYPE_CONTAINER,
  CONTENTS_TYPE_IMAGE,
  CONTENTS_TYPE_AUDIO,
  CONTENTS_TYPE_VIDEO,
  CONTENTS_TYPE_PLAYLIST,
  CONTENTS_TYPE_REFERENCE,
  CONTENTS_TYPE_SUBTITLE,
  CONTENTS_TYPE_DOCUMENT,

  /*Image Formats*/
  /*Supported Image Formats*/
  CONTENTS_TYPE_JPEG,
  CONTENTS_TYPE_JPE,
  CONTENTS_TYPE_JPG,
  CONTENTS_TYPE_PNG,
  CONTENTS_TYPE_BMP,
  CONTENTS_TYPE_GIF,
  CONTENTS_TYPE_TIF,
  CONTENTS_TYPE_TIFF,
  CONTENTS_TYPE_TGA,
  CONTENTS_TYPE_DPX, /*TODO: Check again if MPE Supports*/
  CONTENTS_TYPE_ICO, /*TODO: Check again if MPE Supports*/
  /*Unsupported Image Formats*/ /*TODO: Check if MPE Supports*/
  CONTENTS_TYPE_QTI,
  CONTENTS_TYPE_QTF,
  CONTENTS_TYPE_QTIF,
  CONTENTS_TYPE_PCD,
  CONTENTS_TYPE_PCX,
  CONTENTS_TYPE_PNM,
  CONTENTS_TYPE_PPM,
  CONTENTS_TYPE_TPIC,

  /*Audio Formats*/
  /*Supported Formats*/
  CONTENTS_TYPE_LPCM,
  CONTENTS_TYPE_MP3,
  CONTENTS_TYPE_ASF,
  CONTENTS_TYPE_WMA,
  CONTENTS_TYPE_WAV,
  CONTENTS_TYPE_AAC,       /* .aac */
  CONTENTS_TYPE_AC3,
  CONTENTS_TYPE_AMR,       /* .amr */
  CONTENTS_TYPE_AIFF,      /* .aiff, .aif, .aifc */
  CONTENTS_TYPE_AU,        /* .au, .snd */
  CONTENTS_TYPE_PCM,       /* .pcm */
  CONTENTS_TYPE_OGG_AUDIO, /* .oga,*/
  CONTENTS_TYPE_FLAC,      /* .flac */
  CONTENTS_TYPE_VOC,       /* .voc */
  CONTENTS_TYPE_SOX,       /* .act */
  CONTENTS_TYPE_MLP,       /* .mlp */
  CONTENTS_TYPE_OV,
  CONTENTS_TYPE_MP2,
  CONTENTS_TYPE_RA,  /*real audio*/
  CONTENTS_TYPE_RAM, /*real audio*/
  CONTENTS_TYPE_MP1,
  CONTENTS_TYPE_ASX,
  CONTENTS_TYPE_MID,
  CONTENTS_TYPE_AT3P,
  CONTENTS_TYPE_RMI,
  CONTENTS_TYPE_SND,
  CONTENTS_TYPE_DAB,    /*Digital Audio Broadcasting HE_AAC_2*/
  CONTENTS_TYPE_APL,    /*Monkey's Audio*/
  CONTENTS_TYPE_DTSHD,  /*DTS HD*/
  CONTENTS_TYPE_MKA,
  CONTENTS_TYPE_MPA,
  CONTENTS_TYPE_F4A,
  CONTENTS_TYPE_F4B,
  CONTENTS_TYPE_MP4_AUDIO,
  CONTENTS_TYPE_3GP_AUDIO,
  CONTENTS_TYPE_L16_AUDIO,
  CONTENTS_TYPE_AAC_ADTS,
  /*Unsupported Formats*/ /*TODO: Check if MPE Supports*/
  CONTENTS_TYPE_OMA,
  CONTENTS_TYPE_ATRAC,

  /*Video Formats*/
  /*Supported Formats*/
  CONTENTS_TYPE_MPEG2,
  CONTENTS_TYPE_MPEG,
  CONTENTS_TYPE_MPG,
  CONTENTS_TYPE_MPG2,
  CONTENTS_TYPE_MPEG2_TS,
  CONTENTS_TYPE_ROQ,       /* extension .roq */
  CONTENTS_TYPE_DV,        /* .dv, .dif */
  CONTENTS_TYPE_OGG_VIDEO, /* .ogv, .oga, .ogx, .ogg, .spx, */
  CONTENTS_TYPE_MOV,       /* .mov */
  CONTENTS_TYPE_MJ2, /* motion jpeg, .mj2 */
  CONTENTS_TYPE_AVI,
  CONTENTS_TYPE_DIVX,
  CONTENTS_TYPE_MJPEG,
  CONTENTS_TYPE_MJPG,
  CONTENTS_TYPE_MPE,
  CONTENTS_TYPE_MP2P,
  CONTENTS_TYPE_MP2T,
  CONTENTS_TYPE_M1V,
  CONTENTS_TYPE_M2V,
  CONTENTS_TYPE_M4V,
  CONTENTS_TYPE_OGM,
  CONTENTS_TYPE_TS,
  CONTENTS_TYPE_M2TS,
  CONTENTS_TYPE_QT,
  CONTENTS_TYPE_WMV,
  CONTENTS_TYPE_MKV,
  CONTENTS_TYPE_FLV,
  CONTENTS_TYPE_F4V,
  CONTENTS_TYPE_F4P,
  CONTENTS_TYPE_3GP_VIDEO,
  CONTENTS_TYPE_MP4_VIDEO,
  CONTENTS_TYPE_TP,
  CONTENTS_TYPE_VC1_ASF,
  /*Unsupported Formats*//*TODO: Check if MPE Supports*/
  CONTENTS_TYPE_AVC,
  CONTENTS_TYPE_TTS,
  CONTENTS_TYPE_MP4PS,
  CONTENTS_TYPE_RMVB,
  CONTENTS_TYPE_HDMOV,
  CONTENTS_TYPE_BIN,
  CONTENTS_TYPE_DIF,
  CONTENTS_TYPE_OGX,
  CONTENTS_TYPE_SPX,
  CONTENTS_TYPE_VDR,

  /*Playlist Formats*/
  CONTENTS_TYPE_M3U,
  CONTENTS_TYPE_M3U8,
  CONTENTS_TYPE_PLS,
  CONTENTS_TYPE_WPL,

  /*Container Formats*/
  CONTENTS_TYPE_MP4,
#ifdef DEVELOPMENT_ENABLE_CVP_2_SERVER
  CONTENTS_TYPE_MP4_EU_MPEG4_B13,
#endif /* DEVELOPMENT_ENABLE_CVP_2_SERVER */
  CONTENTS_TYPE_3GP,
  CONTENTS_TYPE_MATROSKA,  /* .mkv .mka .mks */
  CONTENTS_TYPE_WEBM,      /* .webm */
  CONTENTS_TYPE_WEBP,      /* .webp */
  CONTENTS_TYPE_IMY,       /* IMelody Audio */
  CONTENTS_TYPE_MXMF,      /* Mobile Extensible Music File Format */
  CONTENTS_TYPE_XMF,       /* Extensible Music File Format */
  CONTENTS_TYPE_RTTTL,     /* Ringtone text transfer Language File */ 
  CONTENTS_TYPE_RTX,	   /* Nokia Phone ring tone */
  CONTENTS_TYPE_OTA,	   /* OTA Bitmap (Nokia)*/
  CONTENTS_TYPE_MXF,       /* possible extension .mxf */
  CONTENTS_TYPE_VOB,       /* .vob */
  CONTENTS_TYPE_SWF,       /* .swf */
  CONTENTS_TYPE_RM,        /* .rm */
  CONTENTS_TYPE_3G2,       /* 3GPP2 format, extension .3g2 */
  CONTENTS_TYPE_DVRMS,
  CONTENTS_TYPE_ISO,
  CONTENTS_TYPE_IMG,
  CONTENTS_TYPE_MPD, /* MPEG DASH */
  CONTENTS_TYPE_SUBTITLE_SRT,
  CONTENTS_TYPE_SUBTITLE_SSA,
  CONTENTS_TYPE_SUBTITLE_SUB,
  CONTENTS_TYPE_SUBTITLE_ASS,
  CONTENTS_TYPE_SUBTITLE_AQT,
  CONTENTS_TYPE_SUBTITLE_JSS,
  CONTENTS_TYPE_SUBTITLE_TTXT,
  CONTENTS_TYPE_SUBTITLE_PJS,
  CONTENTS_TYPE_SUBTITLE_PSB,
  CONTENTS_TYPE_SUBTITLE_RT,
  CONTENTS_TYPE_SUBTITLE_SMI,
  CONTENTS_TYPE_SUBTITLE_SSF,
  CONTENTS_TYPE_SUBTITLE_GSUB,
  CONTENTS_TYPE_SUBTITLE_USF,
  CONTENTS_TYPE_SUBTITLE_STL,
  CONTENTS_TYPE_SUBTITLE_IDX,
  CONTENTS_TYPE_SUBTITLE_DKS,
  CONTENTS_TYPE_SUBTITLE_SCR,
  CONTENTS_TYPE_SUBTITLE_TTS,
  CONTENTS_TYPE_SUBTITLE_VSF,
  CONTENTS_TYPE_SUBTITLE_ZEG,
  CONTENTS_TYPE_SUBTITLE_MPL,
  CONTENTS_TYPE_SUBTITLE_SCC,
  CONTENTS_TYPE_SUBTITLE_CPTXML,
  CONTENTS_TYPE_SUBTITLE_EMBEDDED,
  /* General types, unknown extensions *//*TODO: Check if MPE Supports*/
  CONTENTS_TYPE_ALAW,
  CONTENTS_TYPE_ASS,
  CONTENTS_TYPE_AVM2,
  CONTENTS_TYPE_CRC,
  CONTENTS_TYPE_DAUD,
  CONTENTS_TYPE_DTS,
  CONTENTS_TYPE_DVD,
  CONTENTS_TYPE_EA,
  CONTENTS_TYPE_EA_CDATA,
  CONTENTS_TYPE_EAC3,
  CONTENTS_TYPE_FFM,
  CONTENTS_TYPE_MULAW,
  CONTENTS_TYPE_GXF,
  CONTENTS_TYPE_DNXHD,
  CONTENTS_TYPE_FILMSTRIP,
  CONTENTS_TYPE_FRAMECRC,
  CONTENTS_TYPE_H261,
  CONTENTS_TYPE_H263,
  CONTENTS_TYPE_H264,
  CONTENTS_TYPE_IMAGE2,
  CONTENTS_TYPE_IMAGE2PIPE,
  CONTENTS_TYPE_INGENIENT,
  CONTENTS_TYPE_IPMOVIE,
  CONTENTS_TYPE_IPOD,
  CONTENTS_TYPE_MMF,
  CONTENTS_TYPE_MPJPEG,
  CONTENTS_TYPE_MXF_D10,
  CONTENTS_TYPE_NUT,
  CONTENTS_TYPE_OSS,
  CONTENTS_TYPE_PSP,
  CONTENTS_TYPE_R3D,
  CONTENTS_TYPE_RAWVIDEO,
  CONTENTS_TYPE_RCV,
  CONTENTS_TYPE_RTP,
  CONTENTS_TYPE_RTSP,
  CONTENTS_TYPE_SPDIF,
  CONTENTS_TYPE_SVCD,
  CONTENTS_TYPE_TIERTEXSEQ,
  CONTENTS_TYPE_TRUEHD,
  CONTENTS_TYPE_VCD,
  CONTENTS_TYPE_YUV4MPEGPIPE,
  CONTENTS_TYPE_RTML,
  CONTENTS_TYPE_TEXT,
  CONTENTS_TYPE_HTML,
  CONTENTS_TYPE_WORD,
  CONTENTS_TYPE_EXCEL,
  CONTENTS_TYPE_POWERPOINT,
  CONTENTS_TYPE_PDF,
  CONTENTS_TYPE_ONENOTE,
  CONTENTS_TYPE_OOXML_DOCUMENT,
  CONTENTS_TYPE_OOXML_DOCUMENT_TEMPLATE,
  CONTENTS_TYPE_OOXML_WORKBOOK,
  CONTENTS_TYPE_OOXML_WORKBOOK_TEMPLATE,
  CONTENTS_TYPE_OOXML_PRESENTATION,
  CONTENTS_TYPE_OOXML_PRESENTATION_TEMPLATE,
  CONTENTS_TYPE_OOXML_PRESENTATION_SLIDESHOW,
  CONTENTS_TYPE_OOXML_PRESENTATION_SLIDE,
  CONTENTS_TYPE_ME_DOCUMENT,
  CONTENTS_TYPE_ME_DOCUMENT_TEMPLATE,
  CONTENTS_TYPE_ME_WORKBOOK,
  CONTENTS_TYPE_ME_WORKBOOK_TEMPLATE,
  CONTENTS_TYPE_ME_WORKBOOK_ADDIN,
  CONTENTS_TYPE_ME_BINARY_WORKBOOK,
  CONTENTS_TYPE_ME_PRESENTATION,
  CONTENTS_TYPE_ME_PRESENTATION_ADDIN,
  CONTENTS_TYPE_ME_PRESENTATION_TEMPLATE,
  CONTENTS_TYPE_ME_PRESENTATION_SLIDESHOW,
  CONTENTS_TYPE_ME_PRESENTATION_SLIDE
}contents_type_t;



/* DLNA Profile Video component */
typedef enum DLNA_System_Portion_Profile_type
{
  SYS_UNKNOWN,            /* Unknown Profile */
  SYS_MP4,                /* MP4 P2 & MP4 P10 (AVC) */
  SYS_MPEG2_TS,           /* MP4 P2 & MP4 P10 (AVC) */
  SYS_MPEG2_TS_T,         /* MP4 P2 & MP4 P10 (AVC) */
  SYS_MPEG2_TS_ISO,       /* MP4 P2 & MP4 P10 (AVC) */
  SYS_ASF,                /* MP4 P2 & MP4 P10 (AVC) */
  SYS_3GPP,               /* MP4 P2 & MP4 P10 (AVC) */
  SYS_PROF_T_LAST_ENTRY

} sys_prof_t;

/* DLNA  Profile Video component */
typedef enum DLNA_Video_Portion_Profile_type
{
  VID_UNKNOWN,            /* Unknown Profile */
  VID_SP_L0B,             /* MP4 P2 */
  VID_SP_L2,              /* MP4 P2 */
  VID_SP_L3,              /* MP4 P2 */
  VID_SP_L3_VGA,          /* MP4 P2 */
  VID_ASP_L5,             /* MP4 P2 */
  VID_ASP_L5_SO,          /* MP4 P2 */
  VID_ASP_L4_SO,          /* MP4 P2 */
  VID_H263_P0_L10,        /* MP4 P2 H263 */
  VID_H263_P3_L10,        /* MP4 P2 H263 */
  VID_CO,                 /* MP4 P2 */
  VID_MP_HD,              /* MP4 P10 (AVC) */
  VID_MP_SD,              /* MP4 P10 (AVC) */
  VID_MP_L4,              /* MP4 P10 (AVC) */
  VID_MP_L3,              /* MP4 P10 (AVC) */
  VID_HP_L4,              /* HP_L4: MP4 P10 (AVC) */
  VID_CBP_L4,             /* CBP_L4: MP4 P10 (AVC) */
  VID_CBP_L3,             /* CBP_L3: MP4 P10 (AVC) */
  VID_BL_L3_SD,           /* MP4 P10 (AVC) */
  VID_BL_L3L_SD,          /* MP4 P10 (AVC) */
  VID_BL_CIF30,           /* MP4 P10 (AVC) */
  VID_BL_L2_CIF30,        /* MP4 P10 (AVC) */
  VID_BL_CIF15,           /* MP4 P10 (AVC) */
  VID_BL_L12_CIF15,       /* MP4 P10 (AVC) */
  VID_BL_L1B_QCIF,        /* MP4 P10 (AVC) */
  VID_BL_QCIF15,          /* MP4 P10 (AVC) */
#ifdef DEVELOPMENT_ENABLE_CVP_2_SERVER
  VID_AVC_MP4_EU,           /* MP4 P10 (AVC) */
  VID_AVC_MP4_EU_MPEG4_B13, /* MP4 P10 (AVC) */
#endif /* DEVELOPMENT_ENABLE_CVP_2_SERVER */
#ifdef DEVELOPMENT_ENABLE_AVC_MP4_MP_SD
  VID_AVC_MP4_MP_SD,        /* MP4 MP SD (AVC) */
#endif /* DEVELOPMENT_ENABLE_AVC_MP4_MP_SD */
#ifdef DEVELOPMENT_ENABLE_AVC_MP4_HP_HD
  VID_AVC_MP4_HP_HD,        /* MP4_HP_HD (AVC) */
#endif /* DEVELOPMENT_ENABLE_AVC_MP4_HP_HD */
  VID_PROF_T_LAST_ENTRY
} vid_prof_t;

/* DLNA Profile Audio component */
typedef enum DLNA_Audio_Portion_Profile_type
{
  AUD_UNKNOWN,            /* Unknown Profile */
  AUD_AAC_ISO,                /* MP4 P2 & MP4 P10 (AVC)    NOTE: AUD_AAC_ISO*/
  AUD_AAC_ISO_320,        /* Audio Only */
  AUD_AAC_ADTS,           /* Audio Only */
  AUD_AAC_ADTS_192,       /* Audio Only */
  AUD_AAC_ADTS_320,       /* Audio Only */
/*  AUD_HEAAC,            */ /* MP4 P2    NOTE: DLNA states There is no level 1 HEAAC */
  AUD_HEAAC_MULT5,        /* MP4 P2 & MP4 P10 (AVC)    NOTE:AUD_HEAAC_MULT5_ISO */
  AUD_AAC_MULT5_ISO,      /* Audio Only */
  AUD_AAC_MULT5_ADTS,     /* Audio Only */
  AUD_HEAAC_L2_ISO_320,   /* Audio Only */
  AUD_HEAAC_L2_ADTS,      /* Audio Only */
  AUD_HEAAC_L2_ADTS_320,  /* Audio Only */
  AUD_HEAAC_L3_ISO,       /* Audio Only */
  AUD_HEAAC_L3_ADTS,      /* Audio Only */
  AUD_HEAAC_MULT5_ADTS,   /* Audio Only */
  AUD_ATRAC3plus,         /* MP4 P2 & MP4 P10 (AVC)*/
  AUD_AAC_LTP_STEREO,     /* MP4 P2 */
  AUD_MPEG1_L3,           /* MP4 P2 & MP4 P10 (AVC)*/
  AUD_MPEG2_L2,           /* MP4 P2 */
  AUD_AC3,                /* MP4 P2 & MP4 P10 (AVC)*/
  AUD_EAC3,               /* MP4 P2 & MP4 P10 (AVC)*/
  AUD_G726,               /* MP4 P2 */
  AUD_AMR,                /* MP4 P2 & MP4 P10 (AVC)*/
  AUD_AMR_WBplus,         /* MP4 P2 & MP4 P10 (AVC)*/
  AUD_HEAAC_L2,           /* MP4 P10 (AVC) NOTE: Used for AUD_HEAAC as well */
  AUD_AAC_LTP,            /* MP4 P10 (AVC) NOTE: AUD_AAC_LTP_ISO */
  AUD_AAC_LTP_MULT5,      /* MP4 P10 (AVC) NOTE: AUD_AAC_LTP_MULT7_ISO*/
  AUD_AAC_LTP_MULT7,      /* MP4 P10 (AVC) NOTE: AUD_AAC_LTP_MULT5_ISO*/
  AUD_BSAC,               /* MP4 P10 (AVC) NOTE: AUD_BSAC_ISO */
  AUD_BSAC_MULT5,         /* MP4 P10 (AVC) NOTE: AUD_BSAC_MULT5_ISO */
  AUD_HEAACv2_L2_MPS_DAB,
#ifdef MEDIA_PROCESSING_EXTENSION
  AUD_DTS,
  AUD_DTSHD_HRA,
  AUD_DTSHD_LBR,
  AUD_DTSHD_MA,
  AUD_MLP,
#endif /* MEDIA_PROCESSING_EXTENSION */
  AUD_PROF_T_LAST_ENTRY
} aud_prof_t;

/* DLNA Profile Video component */

typedef enum dlna_media_profiles {
  ASF_UNKNOWN,      /* Profile unknown or undefined      */

  PNG_SM_ICO,       /* PNG Small Icon */
  PNG_LRG_ICO,      /* PNG Large Icon */
  PNG_TN,           /* PNG Thumbnail  */
  PNG_LRG,          /* PNG Large      */

  ASF_WMA_BASE,     /* WMA baseline profile < 193kbps    */
  ASF_WMA_FULL,     /* WMA no bitrate limit              */
  ASF_WMA_PRO,      /* WMA Professional version          */
  ASF_WMA_MP3,      /* MP3 Encoding                      */

  /*                   Code         Profile  Resolution  Audio         */
  ASF_WMVMED_BASE,  /* WMVMED_BASE  Main     Medium      Baseline      */
  ASF_WMVMED_FULL,  /* WMVMED_FULL  Main     Medium      Full          */
  ASF_WMVMED_PRO,   /* WMVMED_PRO   Main     Medium      Professional  */
  ASF_WMVHIGH_FULL, /* WMVHIGH_FULL Main     High        Full          */
  ASF_WMVHIGH_PRO,  /* WMVHIGH_PRO  Main     High        Professional  */
  ASF_WMVHM_BASE,   /* WMVHM_BASE   HighMAT  N/A         N/A           */
  ASF_WMVSPLL_BASE, /* WMVSPLL_BASE Simple   Low         Baseline      */
  ASF_WMVSPML_BASE, /* WMVSPML_BASE Simple   Medium      Baseline      */
  ASF_WMVSPML_MP3,  /* WMVSPML_MP3  Simple   Medium      MP3           */

  MPEG_NO_PROF_DEFINED,     /* No particular profile ID fits */

  MPEG_TS_SD_NA,            /* North American Region */
  MPEG_TS_SD_NA_T,
  MPEG_TS_SD_NA_ISO,
  MPEG_TS_HD_NA,
  MPEG_TS_HD_NA_T,
  MPEG_TS_HD_NA_ISO,
  MPEG_TS_SD_NA_XAC3,       /* North American Region with AC3 audio */
  MPEG_TS_SD_NA_XAC3_T,
  MPEG_TS_SD_NA_XAC3_ISO,
  MPEG_TS_HD_NA_XAC3,
  MPEG_TS_HD_NA_XAC3_T,
  MPEG_TS_HD_NA_XAC3_ISO,
  MPEG_TS_NA_ISO,

  MPEG_TS_SD_EU,            /* Europen Union Region */
  MPEG_TS_SD_EU_T,
  MPEG_TS_SD_EU_ISO,
  MPEG_TS_HD_EU,
  MPEG_TS_HD_EU_T,
  MPEG_TS_HD_EU_ISO,
  MPEG_TS_SD_EU_XAC3,       /* Europen Union Region with AC3 audio*/
  MPEG_TS_SD_EU_XAC3_T,
  MPEG_TS_SD_EU_XAC3_ISO,
  MPEG_TS_HD_EU_XAC3,
  MPEG_TS_HD_EU_XAC3_T,
  MPEG_TS_HD_EU_XAC3_ISO,

  MPEG_TS_SD_KO,            /* Korea Region */
  MPEG_TS_SD_KO_T,
  MPEG_TS_SD_KO_ISO,
  MPEG_TS_HD_KO,
  MPEG_TS_HD_KO_T,
  MPEG_TS_HD_KO_ISO,
  MPEG_TS_SD_KO_XAC3,       /* Korea Region AC3 Audio */
  MPEG_TS_SD_KO_XAC3_T,
  MPEG_TS_SD_KO_XAC3_ISO,
  MPEG_TS_HD_KO_XAC3,
  MPEG_TS_HD_KO_XAC3_T,
  MPEG_TS_HD_KO_XAC3_ISO,

  MPEG_TS_JP_T,
#ifdef MEDIA_PROCESSING_EXTENSION
  MPEG_TS_SD_JP_MPEG1_L2_T,
#endif /* MEDIA_PROCESSING_EXTENSION */
  MPEG_TS_ARIB,

  MPEG_TS_MP_LL_AAC,        /* AAC Audio */
  MPEG_TS_MP_LL_AAC_T,
  MPEG_TS_MP_LL_AAC_ISO,

#ifdef MEDIA_PROCESSING_EXTENSION
  MPEG_PS_HD_DTS,
  MPEG_PS_HD_DTSHD,
  MPEG_PS_HD_DTSHD_HRA,
  MPEG_PS_HD_DTSHD_MA,

  MPEG_PS_SD_DTS,
#endif /* MEDIA_PROCESSING_EXTENSION */

  MPEG_PS_NTSC,
  MPEG_PS_PAL,
  MPEG_PS_NTSC_XAC3,
  MPEG_PS_PAL_XAC3,

#ifdef MEDIA_PROCESSING_EXTENSION
  /* MPEG4 PROFILES */
  AVC_MP4_BL_CIF15_AAC_520,

  AVC_MP4_BL_CIF15_AAC_LTP,
  AVC_MP4_BL_CIF15_AAC,
  AVC_MP4_BL_CIF15_HEAAC,

  AVC_MP4_BL_CIF30_AAC_LTP_MULT5,
  AVC_MP4_BL_CIF30_AAC_LTP,
  AVC_MP4_BL_CIF30_AAC_MULT5,
  AVC_MP4_BL_CIF30_HEAAC_L2,
  AVC_MP4_BL_CIF30_MPEG1_L3,

  AVC_MP4_BL_L12_CIF15_HEAAC,

  AVC_MP4_MP_SD_AAC_LTP_MULT5,
  AVC_MP4_MP_SD_AAC_LTP_MULT7,
  AVC_MP4_MP_SD_AAC_LTP,
  AVC_MP4_MP_SD_AAC_MULT5,
  AVC_MP4_MP_SD_HEAAC_L2,
  AVC_MP4_MP_SD_MPEG1_L3,

  MPEG4_H263_MP4_P0_L10_AAC,
  MPEG4_P2_MP4_ASP_AAC,
  MPEG4_P2_MP4_ASP_HEAAC_MULT5,
  MPEG4_P2_MP4_ASP_HEAAC,
  MPEG4_P2_MP4_ASP_L4_SO_AAC,
  MPEG4_P2_MP4_ASP_L4_SO_HEAAC_MULT5,
  MPEG4_P2_MP4_ASP_L4_SO_HEAAC,
  MPEG4_P2_MP4_ASP_L5_SO_AAC,
  MPEG4_P2_MP4_ASP_L5_SO_HEAAC_MULT5,
  MPEG4_P2_MP4_ASP_L5_SO_HEAAC,
  MPEG4_P2_MP4_SP_AAC,
  MPEG4_P2_MP4_SP_HEAAC,

  AVC_TS_SD_EU,
  AVC_TS_SD_EU_ISO,
  AVC_TS_SD_EU_T,
  AVC_TS_HD_EU,
  AVC_TS_HD_EU_ISO,
  AVC_TS_HD_EU_T,

#ifdef DEVELOPMENT_ENABLE_CVP_2_SERVER
  AVC_TS_EU_ISO,
  AVC_TS_NA_ISO,
  AVC_TS_NA_T,
#endif /* DEVELOPMENT_ENABLE_CVP_2_SERVER */

  AVC_TS_BL_CIF30_AC3,
  AVC_TS_BL_CIF30_AC3_T,
  AVC_TS_BL_CIF30_AC3_ISO,

  AVC_TS_HD_60_AC3,
  AVC_TS_HD_60_AC3_T,
  AVC_TS_HD_60_AC3_ISO,
  AVC_TS_HD_50_AC3,
  AVC_TS_HD_50_AC3_T,
  AVC_TS_HD_50_AC3_ISO,
#ifdef DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION_SONY_BRAVIA_PROFILING
  AVC_TS_HD_24_AC3,
  AVC_TS_HD_24_AC3_T,
  AVC_TS_HD_24_AC3_ISO,
#endif /* DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION_SONY_BRAVIA_PROFILING */
  /* VC-1 PROFILES */
  VC1_ASF_AP_L1_WMA,
  VC1_ASF_AP_L2_WMA,
  VC1_PS_HD_DTS,
  VC1_PS_HD_DTSHD,
  VC1_PS_HD_DTSHD_HRA,
  VC1_PS_HD_DTSHD_MA,

  VC1_TS_AP_L1_AC3_ISO,
  VC1_TS_AP_L1_WMA_ISO,
  VC1_TS_AP_L2_AC3_ISO,
  VC1_TS_AP_L2_WMA_ISO,
#endif /* MEDIA_PROCESSING_EXTENSION */
  AVI_PROF, /* AVI Video */
  DIVX_PROF, /* DivX Video */
  WAV_PROF,
#ifdef DLNA_DMS_SUPPORT_AC3
  AC3_PROF,
#endif /* DLNA_DMS_SUPPORT_AC3 */
  OV_PROF,
  TIFF_PROF,
  FLV_PROF,
  QT_PROF,
  ATRAC_PROF,
  AIFF_PROF,  /* AIFF/AIF */
  /*enum jpeg_profile unification with dlna profile enum*/
  JPEG_PROFILE_UNKNOWN,
  JPEG_PROFILE_SM_ICO ,
  JPEG_PROFILE_LRG_ICO,
  JPEG_PROFILE_TN,
  JPEG_PROFILE_SM,
  JPEG_PROFILE_MED,
  JPEG_PROFILE_LRG,
  /**/

  MPEG_LAST_ENTRY

} dlna_profile_t;

typedef enum media_profile_indicator_types {
  MINFO_MPEG_NOTYPE,        /* Invalid/unspecified                       */

  MINFO_MPEG_TS,            /* Transport Stream Type                     */
  MINFO_MPEG_PS,            /* Program Stream Type                       */
  MINFO_MPEG_ES,            /* Elementary Stream Type                    */

  MINFO_MPEG_KO,            /* Korean Region type                        */
  MINFO_MPEG_NA,            /* North American Region type                */
  MINFO_MPEG_EU,            /* European Region type                      */
  MINFO_MPEG_JP,            /* Japanese Region Type                      */
  MINFO_MPEG_NOREGION,

  MINFO_MPEG_HD,            /* High Definition                           */
  MINFO_MPEG_SD,            /* Stardard Definition                       */
  MINFO_MPEG_OTHER_DEFINITION,

  MINFO_MPEG_NTSC,          /* NTSC video type                           */
  MINFO_MPEG_PAL,           /* PAL video type                            */
  MINFO_MPEG_SEACAM,        /* SEACAM -- French format                   */
  MINFO_MPEG_MAC,           /* MAC                                       */

  MINFO_MPEG_NOTS,          /* TS without timestamp                      */
  MINFO_MPEG_VALID_TS,      /* TS with invalid ts                        */
  MINFO_MPEG_INVALID_TS,    /* TS with valid ts                          */

  MINFO_MPEG_NOTS_JP,       /* JP TS without timestamp                   */
  MINFO_MPEG_VALID_TS_JP,   /* JP TS with invalid ts                     */
  MINFO_MPEG_INVALID_TS_JP, /* JP TS with valid ts                       */
  MINFO_MPEG_ARIB_PARTIAL_TS, /* Partial TS format defined by ARIB       */
} dlna_minfo_t;




struct protocol
{
  slim_char *string;

  struct protocol *next;
  struct protocol *prev;
};
typedef struct protocol protocol_t;

struct media_file_information_structure
{
  dlna_uint64      size;       /* file size.                                */
  dlna_time_t      mtime;      /* file modified time.                       */
#ifdef MEDIA_PROCESSING_EXTENSION
  slim_char        mimeTypeStr[50];
#endif /* MEDIA_PROCESSING_EXTENSION */
  mime_type_t      mimetype;   /* dlna mime type                            */
  slim_ulong       maxBitrate; /* Overall Maximum File Bitrate              */
/* ZZZ  slim_ulong      aveBitrate;*/ /* Overall Average File Bitrate          */

  dlna_profile_t   profile_id; /* Profile value                             */
  List(protocol_t*) pinfo_list; /* Protocol info string                 */
  List(protocol_t*) pname_list; /* Protocol name only           */


#ifdef DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION_SONY_BRAVIA_PROFILING

  /* Pinfo relaxed is a version of pinfo expected by some devices (not constrained so much) */
  slim_char * pinfo_relaxed;
  slim_char * pname_relaxed;

#endif /* DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION_SONY_BRAVIA_PROFILING */


  slim_char       *filename;   /* Name of the file being processed          */
  slim_char       *full_path;  /* The full pathname of the file.            */
  slim_char       *folder;     /* Name of the folder the file is in         */
  dlna_uint64      asf_create; /* 100ns slices since mdnt 1/1/1601 GMT      */
#ifdef DEVELOPMENT_ENABLE_PUBLISH_STREAMING_CONTENT
  slim_bool        is_streaming_type; /*Streaming Type Media*/
  slim_bool        is_protected; /*Content is protected or not*/
#endif /*DEVELOPMENT_ENABLE_PUBLISH_STREAMING_CONTENT*/
};
typedef struct media_file_information_structure minfo_file_t;

#ifdef MEDIA_PROCESSING_EXTENSION
#define  DLNA_MIME_STR_SIZE  50
typedef struct
{
  slim_char  mpe_mime_str[DLNA_MIME_STR_SIZE];
  slim_char  dlna_mime_str[DLNA_MIME_STR_SIZE];
} mpe_dlna_map_t;

struct mime_type_node
{
  struct mime_type_node *next;
  struct mime_type_node *prev;
  slim_char *textnode;
  slim_word text_size;
};

typedef struct
{
  List(struct mime_type_node *)full_matches_list;
  List(struct mime_type_node *)wildcards_list;
  slim_char *dlna_full_mime_str;
} mpe_dlna_mime_translation_table_t;

#endif /* MEDIA_PROCESSING_EXTENSION */

#ifdef ENABLE_GPS_SUPPORT
struct media_jpeg_gps_information
{
  slim_bool gps_flag;
  slim_double gps_latitude;
  slim_double gps_longitude;
};
typedef struct media_jpeg_gps_information minfo_gps_t;
#endif /* ENABLE_GPS_SUPPORT */

struct media_info_image_information
{
/*ZZZ  slim_int  percent;     */     /* (JPEG) Percentage of the scaling.          */
  slim_byte picture_structure;/* Picture structure                          */
  slim_int  width;            /* Width of the image                         */
  slim_int  height;           /* height of the image                        */
  slim_int  exif_time;      /* exif time                  */
  slim_char *exif_keywords; /* exif keywords              */
#ifdef ENABLE_GPS_SUPPORT
  minfo_gps_t gps_data;
#endif /* ENABLE_GPS_SUPPORT */
};
typedef struct media_info_image_information minfo_img_t;

#ifdef MEDIA_PROCESSING_EXTENSION
typedef enum audio_codec
{
  AC_UNKNOWN,
  AC_WMA,
  AC_AC3,
  AC_AAC,
  AC_MPEG1_L2
} audio_codec_t;
#endif /* MEDIA_PROCESSING_EXTENSION */

/* ISO/IEC 14496-3:2005(E)  Table1.15 Audio Object Types*/
typedef enum mp4_audio_obj_type
{
  AOT_UNKNOWN,
  AOT_AAC_MAIN = 1,  /* AAC MAIN */
  AOT_AAC_LC   = 2,  /* AAC LC */
  AOT_AAC_LTP  = 4,  /* AAC LTP */
  AOT_HEAAC    = 5,  /* HE-AACv1 = SBR(Spectral Band Replication) */
  AOT_ER_BSAC  = 22  /* BSAC based on AAC */
} mp4_audio_obj_type_t;

struct media_audio_stream_information
{
  slim_ulong    aveBitrate;     /* Average Bitrate         (3.12)             */
  slim_ulong    maxBitrate;     /* Max bitrate             (####)             */
  slim_word     format;         /* CODEC ID or format tag  (9.1)              */
  slim_word     chans;          /* Number of channels      (9.1)              */
  slim_word     samps;          /* # of samples per second (9.1)              */
  slim_word     aveBps;         /* Average Bytes per sec   (9.1)              */
  slim_word     block_align;    /* Block Alignment         (9.1)              */
  slim_word     bitsPerSamp;    /* Bits per Sample         (9.1)              */
  slim_word     chanprof;       /* channel Configuration                      */
  slim_int      version;        /* version of media contents                  */
  slim_int      layer;          /* layer of media contents                    */
  slim_int      protection;     /* protection type                            */
  slim_word     data_length;    /* Audio data length.                         */
  aud_prof_t    audio_profile;   /* Audio profile, needed to repair mime type  */
#ifdef MEDIA_PROCESSING_EXTENSION
  slim_char     chanprofstr[5];
  audio_codec_t codec;
#endif /* MEDIA_PROCESSING_EXTENSION */
#ifdef DEVELOPMENT_NFLC_PROFILER
  slim_bool     is_adts;
  mp4_audio_obj_type_t mp4_audobjtype;
#endif /* DEVELOPMENT_NFLC_PROFILER */
};
typedef struct media_audio_stream_information minfo_aud_t;

#ifdef DEVELOPMENT_NFLC_PROFILER
typedef enum scan_type
{
  ST_UNKNOWN,
  ST_PROGRESSIVE,
  ST_INTERLACED
}scan_type_t;
#endif /* DEVELOPMENT_NFLC_PROFILER */

struct media_video_stream_information
{
  slim_word   width;          /* Max vertical size                          */
  slim_word   height;         /* Max horizontal size                        */
  slim_ulong  aveBitrate;     /* average Bitrate of video stream            */
  slim_ulong  maxBitrate;     /* max Bitrate of video stream                */
  slim_byte   video_format;   /* Video format                               */
  slim_double framerate;      /* Framerate                                  */
  slim_word   framerate_code; /* Framerate code per tab6-4 13818-2          */
  slim_word   aspect_code;    /* aspect ratio code per tab6-3 13818-2       */
  slim_word   video_flags;    /* Video Flags.                               */
  slim_word   have_ifo;       /* IFO file.                                  */
#ifdef DEVELOPMENT_NFLC_PROFILER
  slim_bool   is_proper_mpeg2_ps;
  scan_type_t interlacing;
#endif /* DEVELOPMENT_NFLC_PROFILER */
#ifdef MEDIA_PROCESSING_EXTENSION
  slim_int    dar_num;
  slim_int    dar_den;
  slim_int    par_num;
  slim_int    par_den;
  slim_int    frr_num;
  slim_int    frr_den;
  slim_int    frr_old_num;
  slim_int    frr_old_den;
#endif /* MEDIA_PROCESSING_EXTENSION */
};
typedef struct media_video_stream_information minfo_vid_t;

#ifdef MEDIA_PROCESSING_EXTENSION
typedef enum video_codec {
  VC_UNKNOWN,
  VC_H263,
  VC_MPEG4,
  VC_H264,
  VC_MPEG2,
}vc_t;

typedef enum video_codec_profile {
  VP_UNKNOWN,
  VP_MPEG4_H263_P0,
  VP_MPEG4SP,
  VP_MPEG4ASP,
  VP_MPEG4_AVC_BASE_LINE,
  VP_MPEG4_AVC_MAIN_PROFILE,
  VP_MPEG4_AVC_HIGH_PROFILE,
  VP_MPEG2_MAIN_PROFILE,
  VP_MPEG2_HIGH_PROFILE
}vc_prof_t;

typedef enum video_codec_level {
  VL_UNKNOWN,

  VL_H263_10,
  VL_H263_20,
  VL_H263_30,
  VL_H263_40,
  VL_H263_45,
  VL_H263_50,
  VL_H263_60,
  VL_H263_70,

  VL_SP_L0,
  VL_SP_L0b,
  VL_SP_L1,
  VL_SP_L2,
  VL_SP_L3,

  VL_ASP_L0,
  VL_ASP_L1,
  VL_ASP_L2,
  VL_ASP_L3,
  VL_ASP_L3b,
  VL_ASP_L4,
  VL_ASP_L5,

  VL_AVC_1,
  VL_AVC_1b,
  VL_AVC_1_1,
  VL_AVC_1_2,
  VL_AVC_1_3,
  VL_AVC_2,
  VL_AVC_2_1,
  VL_AVC_2_2,
  VL_AVC_3,
  VL_AVC_3_1,
  VL_AVC_3_2,
  VL_AVC_4,
  VL_AVC_4_1,

  /* MPEG2 video level. please refer ffmpeg avcodec, encode_init() */
  VL_MPEG2_MAIN,
  VL_MPEG2_HIGH,
  VL_MPEG2_HIGH_1440,

}vc_level_t;
#ifndef DEVELOPMENT_NFLC_PROFILER
typedef enum scan_type
{
  ST_UNKNOWN,
  ST_PROGRESSIVE,
  ST_INTERLACED
}scan_type_t;
#endif /* DEVELOPMENT_NFLC_PROFILER */
typedef struct video_info
{
  vc_t    vc;     /* video codec      */
  vc_prof_t vid_prof;   /* video codec profile  */
  vc_level_t  vid_level;    /* video codec level  */
  slim_bool codec_so;   /* simple objects only  */
  scan_type_t interlacing;          /* scan type      */
} video_info_t;

typedef struct video_info_mpeg2
{
  scan_type_t interlacing;    /* scan type */
} video_info_mpeg2_t;

#endif /* MEDIA_PROCESSING_EXTENSION */

#ifdef MPE_ENABLE_EMBEDDED_SUBTITLE_SUPPORT
struct media_subtitle_information
{
  struct media_subtitle_information* next;
  struct media_subtitle_information* prev;

  slim_char *index;   /* Stream index */
  slim_char *language;  /* Subtitle language */
};
typedef struct media_subtitle_information minfo_subtitle_t;
#endif /* MPE_ENABLE_EMBEDDED_SUBTITLE_SUPPORT */

struct media_extended_stream_properties /* 4.1 */
{
  slim_short isSet;           /* set to 1 if this data has been set already */
  slim_ulong start_time;      /* timeline start for this stream in whole ASF*/
  slim_ulong end_time;        /* timeline end for this stream in whole ASF  */
  slim_ulong data_bitrate;    /* leak rate for leaky bucket in bps          */
  slim_ulong buf_size;        /* buffer size in miliseconds                 */
  slim_ulong init_buf_ful;    /* initial fullness in miliseconds of buffer  */
  slim_ulong alt_data_btrt;   /* alternate to above data_bitrate            */
  slim_ulong alt_buf_siz;     /* alternate to above buf_size                */
  slim_ulong alt_ibuf_ful;    /* alternate to above init_buf_ful            */
  slim_short max_obj_size;    /* max size of largest sample, 0=unknown      */
  slim_short reliable;        /* stream requires reliable connection        */
  slim_short seekable;        /* true if this stream is seekable            */
  slim_short no_clean;        /* true if no cleanpoints present             */
  slim_short resend_lc;       /* used in mid-stream connections             */
  slim_int   stream_num;      /* # of this stream, unique, cannot be zero   */
  slim_int   strm_lang_id;    /* specifies language of stream               */
  slim_ulong ave_tpframe;     /* Average time in 100ns counts of each frame */
  slim_int   strm_nam_cnt;    /* # of stream names present                  */
  slim_int   pyld_ext_sys;    /* # of payload extensions                    */
};
typedef struct media_extended_stream_properties  minfo_esp_t;

struct media_content_information
{
  slim_char  *date;           /* Date String                                */
  slim_char  *album;          /* Album information (directory used if none) */
  slim_char  *title;          /* Title of the media. (used for 3.10 )       */
  slim_char  *author;         /* Author field from 3.10                     */
  slim_char  *creator;        /* Content creator                            */
  slim_char  *copyright;      /* copyright field from 3.10                  */
  slim_char  *desc ;          /* description field from 3.10                */
  slim_char  *rating;         /* rating field from 3.10                     */
  slim_char  *composer;
  slim_char  *genre;          /* Genre information                          */
  slim_char  *group;          /* Group information                          */
  slim_char  *comment;        /* Comments                                   */
  slim_char  *artist;         /* Artist information                         */
  slim_int   tracknum;        /* Track Number                               */
  slim_int   year;
  slim_char * parental_advisory_rating; /* Parental advisory information    */
};
typedef struct media_content_information minfo_cont_t;

struct media_duration_information
{
  slim_double epoc;           /* creat date in sec since Jan 1, 1904 UTC    */
  slim_int    hour;           /* Duration in hours.                         */
  slim_int    min;            /* Duration in minutes.                       */
  slim_int    sec;            /* Duration in seconds.                       */
  slim_int    msec;           /* Duration in milliseconds.                  */
  slim_char  *duration_str;   /* Duration as a string: 0:00:00.000          */
};
typedef struct media_duration_information minfo_dur_t;

/* ConnnectionManager:1 Service Template Version 1.0.1.
 *
 *    2.5.2 ProtocolInfo Concept.  */
struct media_protocol_information_structure
{
  /* Protocol field.  */
  dlna_split_ss protocol;

  /* Network field.  */
  dlna_split_ss network;

  /* contentFormat.  eg. MIME type.  */
  dlna_split_ss mime;

  /* additionalInfo.  eg. DLNA 4th field.  */
  dlna_split_ss info;

  /* res@protocolInfo string.  */
  slim_char *string;

  struct media_protocol_information_structure *next;
  struct media_protocol_information_structure *prev;


#ifdef DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION

  contents_type_t ctype;

#endif /* DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION */
};

typedef struct media_protocol_information_structure pinfo_t;

typedef slim_word upnp_dvd_r_t;


#ifdef DEVELOPMENT_MATROSKA_EMBEDED_ALBUM_ART

struct _media_attachment_info
{
  /**
 *    * Should be initialized to slim_false.
 *       * Specify if file contains attachments.
 *          */
  slim_bool is_available;

  /**
 *    * Initial value should not matter.
 *       * Specify stream index which contain attachment selected as album art.
 *          */
  slim_word stream_index;
};

#endif /* DEVELOPMENT_MATROSKA_EMBEDED_ALBUM_ART */


struct media_information_structure
{
  /* Media information flags.  */
  slim_word flags;
#define MINFO_FLAG_CONTAINER  (1 << 0)
#define MINFO_FLAG_REFERENCE  (1 << 1)
#define MINFO_FLAG_IMAGE      (1 << 2)
#define MINFO_FLAG_AUDIO      (1 << 3)
#define MINFO_FLAG_VIDEO      (1 << 4)
#define MINFO_FLAG_UPLOAD     (1 << 5)
#define MINFO_FLAG_PLAYLIST   (1 << 8)
#define MINFO_FLAG_DTCP       (1 << 9)
#define MINFO_FLAG_DOCUMENT   (1 << 16)

  /* Contents type.  */
  contents_type_t ctype;

  dlna_mtype_t  mtype;        /* Memory type used to allocate memory        */

  minfo_file_t file;          /* file information                           */

  minfo_aud_t  aud;           /* audio stream specific properties           */
  minfo_vid_t  vid;           /* video specific information                 */
  minfo_img_t  img;
#ifdef MPE_ENABLE_EMBEDDED_SUBTITLE_SUPPORT
  List(minfo_subtitle_t *) subtitle_list;
#endif /* MPE_ENABLE_EMBEDDED_SUBTITLE_SUPPORT */


#ifdef DEVELOPMENT_MATROSKA_EMBEDED_ALBUM_ART

  /**
 *    * Set by MPE client during GET_METADATA.
 *       * Note. There may be more than one attachment in file, but only one album art
 *          * can be advertised.
 *             */
  struct _media_attachment_info embeded_album_art;

#endif /* DEVELOPMENT_MATROSKA_EMBEDED_ALBUM_ART */


  /* Protocol info.  */
  pinfo_t pinfo;
  slim_word upnp_channelNr;
#ifdef HAVE_DTCP
  slim_half pmt_pid;
  /* DRM info */
  minfo_drm_t drm_info;
#endif /* HAVE_DTCP */

  minfo_esp_t  aStream;       /* Audio stream extended properties           */
  minfo_esp_t  vStream;       /* Video stream extended properties           */

  minfo_cont_t cont;          /* Contents infomration. i.e. artist          */
  minfo_dur_t  duration;      /* duration information of the file           */

  dlna_minfo_t TVsystem_type; /* NTSC or PAL                                */
  dlna_minfo_t def_type;      /* Standard or High Definition                */
  dlna_minfo_t stream_type;   /* TS, PS, ES stream type                     */
  dlna_minfo_t region_type;   /* region: EU, NA, KO...                      */
  sys_prof_t   system_prof;   /* Set to the DLNA system Profile             */
  vid_prof_t   video_prof;    /* Set to the DLNA video Profile              */

  aud_prof_t   audio_prof;    /* Set to the DLNA audio Profile              */

#ifdef MEDIA_PROCESSING_EXTENSION
  video_info_t video_detail_info;
  slim_bool    time_seek_supported;
#endif /* MEDIA_PROCESSING_EXTENSION */

#ifdef DEVELOPMENT_ICP_PLUGIN
  slim_char * id;
#endif /* DEVELOPMENT_ICP_PLUGIN */
};

typedef struct media_information_structure minfo_t;

#endif /* MINFO_H */

