/*
 * \file dms_publish_api.h
 * \brief DMS Publish Header
 *
 * Copyright (C) 2014 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef DMS_PUBLISH_API_H_
#define DMS_PUBLISH_API_H_

#include <dlna_peer.h>
#include <nflc_contents.h>

/**
 * @addtogroup Macros
 */
/*@{*/
/*!
 * Allowed Output Encryption Type for the content/streams i.e, DMS serves the content to the client as per the allowed output encryption type
  <table>
         <tr>
                <td><b>Member</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>DMS_ALLOWED_OUTPUT_TYPE_CLEAR</td>
                <td>(0) Content to be served as Clear</td>
        </tr>
        <tr>
                <td>DMS_ALLOWED_OUTPUT_TYPE_DTCP</td>
                <td>(1 << 0) Content to be served as DTCP Protected</td>
        </tr>
         <tr>
                <td>DMS_ALLOWED_OUTPUT_TYPE_DRM</td>
                <td>(1 << 1) Content to be served as DRM Encrypted</td>
        </tr>
        <tr>
                <td>DMS_ALLOWED_OUTPUT_TYPE_CA</td>
                <td>(1 << 2) Content to be served as CA Encrypted</td>
        </tr>
        <tr>
                <td>DMS_ALLOWED_OUTPUT_TYPE_DHCP</td>
                <td>(1 << 3) Content to be served as DHCP Encrypted</td>
        </tr>
</table>
 */
#define DMS_ALLOWED_OUTPUT_TYPE_CLEAR           0
#define DMS_ALLOWED_OUTPUT_TYPE_DTCP            (1 << 0)
#define DMS_ALLOWED_OUTPUT_TYPE_DRM             (1 << 1)
#define DMS_ALLOWED_OUTPUT_TYPE_CA              (1 << 2)
#define DMS_ALLOWED_OUTPUT_TYPE_DHCP            (1 << 3)
/*@}*/

enum {
  DMS_STORAGE_DB_LOCATION_LOCAL,
  DMS_STORAGE_DB_LOCATION_CENTRAL
};

/**
 * @addtogroup Enumerators
 */
/*@{*/

/*!
    TDMSStorageDBLocation represents the location type of added share

    <table>
    <tr>
        <td><b>Definition</b></td>
        <td><b>Description</b></td>
    </tr>
    <tr>
        <td>DMS_STORAGE_DB_LOCATION_LOCAL</td>
        <td>Database is saved locally at the root of the storage/folder</td>
    </tr>
    <tr>
        <td>DMS_STORAGE_DB_LOCATION_CENTRAL</td>
        <td>Database is saved centrally at the root of the storage/folder</td>
    </tr>
    </table>

*/
typedef slim_int TDMSStorageDBLocation;
/*@}*/

enum {
  DMS_DTCP_CCI_COPY_FREE,
  DMS_DTCP_CCI_COPY_FREE_EPN_ASSERTED,
  DMS_DTCP_CCI_COPY_ONE_GEN,
  DMS_DTCP_CCI_NO_MORE_COPIES,
  DMS_DTCP_CCI_COPY_NEVER
};

/**
 * @addtogroup Enumerators
 */
/*@{*/

/*!
    TDMSDtcpCci - DTCP Copy Control Information

    <table>
    <tr>
        <td><b>Definition</b></td>
        <td><b>Description</b></td>
    </tr>
    <tr>
        <td>DMS_DTCP_CCI_COPY_FREE</td>
        <td>Copy Freely</td>
    </tr>
    <tr>
        <td>DMS_DTCP_CCI_COPY_FREE_EPN_ASSERTED</td>
        <td>Copy Freely with EPN Asserted</td>
    </tr>
    <tr>
        <td>DMS_DTCP_CCI_COPY_ONE_GEN</td>
        <td>Copy One Generation</td>
    </tr>
    <tr>
        <td>DMS_DTCP_CCI_NO_MORE_COPIES</td>
        <td>No More Copies</td>
    </tr>
    <tr>
        <td>DMS_DTCP_CCI_COPY_NEVER</td>
        <td>Copy Never</td>
    </tr>
    </table>

*/
typedef slim_int TDMSDtcpCci;
/*@}*/

enum {
  DMS_ENCRYPTION_TYPE_NONE,
  DMS_ENCRYPTION_TYPE_DRM,
  DMS_ENCRYPTION_TYPE_CA
};
/**
 * @addtogroup Enumerators
 */
/*@{*/

/*!
    TDMSEncryptionType represents the Encryption Type of the content

    <table>
    <tr>
        <td><b>Definition</b></td>
        <td><b>Description</b></td>
    </tr>
    <tr>
        <td>DMS_ENCRYPTION_TYPE_NONE</td>
        <td>Content is not Encrypted</td>
    </tr>
    <tr>
        <td>DMS_ENCRYPTION_TYPE_DRM</td>
        <td>Content is DRM Encrypted</td>
    </tr>
    <tr>
        <td>DMS_ENCRYPTION_TYPE_CA</td>
        <td>Content is CA Encrypted</td>
    </tr>
    </table>

*/
typedef slim_int TDMSEncryptionType;
/*@}*/


enum {
  DMS_STREAM_TYPE_LOCAL,
  DMS_STREAM_TYPE_LIVE,
  DMS_STREAM_TYPE_RECORDED,
  DMS_STREAM_TYPE_ONLINE
};
/**
 * @addtogroup Enumerators
 */
/*@{*/

/*!
    TDMSEncryptionType represents the Encryption Type of the content

    <table>
    <tr>
        <td><b>Definition</b></td>
        <td><b>Description</b></td>
    </tr>
    <tr>
        <td>DMS_STREAM_TYPE_LIVE</td>
        <td>Stream is Live</td>
    </tr>
    <tr>
        <td>DMS_STREAM_TYPE_RECORD</td>
        <td>Stream is Record</td>
    </tr>
    <tr>
        <td>DMS_STREAM_TYPE_ONLINE</td>
        <td>Stream is Online</td>
    </tr>
    <tr>
        <td>DMS_STREAM_TYPE_LOCAL</td>
        <td>Stream is Local</td>
    </tr>
    </table>

*/
typedef slim_int TDMSStreamType;
/*@}*/

enum {
  DMS_CONTENT_RESOURCE_TYPE_ORIGINAL,
  DMS_CONTENT_RESOURCE_TYPE_SUBTITLE,
  DMS_CONTENT_RESOURCE_TYPE_THUMBNAIL,
  DMS_CONTENT_RESOURCE_TYPE_TRANSCODED
};
/**
 * @addtogroup Enumerators
 */
/*@{*/

/*!
    TDMSContentResType represents the type of the resource for the content/stream published

    <table>
    <tr>
        <td><b>Definition</b></td>
        <td><b>Description</b></td>
    </tr>
    <tr>
        <td>DMS_CONTENT_RESOURCE_TYPE_ORIGINAL</td>
        <td>Content/Stream original resource</td>
    </tr>
    <tr>
        <td>DMS_CONTENT_RESOURCE_TYPE_SUBTITLE</td>
        <td>Subtitle resource for the content/stream</td>
    </tr>
    <tr>
        <td>DMS_CONTENT_RESOURCE_TYPE_THUMBNAIL</td>
        <td>Thumbnail resource for the content/stream</td>
    </tr>
    <tr>
        <td>DMS_CONTENT_RESOURCE_TYPE_TRANSCODED</td>
        <td>Transcoded resource for the content/stream</td>
    </tr>
    </table>

*/
typedef slim_int TDMSContentResType;
/*@}*/

enum {
  DMS_STREAM_SOURCE_BUFFER_WRITE = 1,
  DMS_STREAM_SOURCE_HTTP_READ,
  DMS_STREAM_SOURCE_FILE_READ
};
/**
 * @addtogroup Enumerators
 */
/*@{*/

/*!
    TDMSContentResType represents the type of the resource for the content/stream published

    <table>
    <tr>
        <td><b>Definition</b></td>
        <td><b>Description</b></td>
    </tr>
    <tr>
        <td>DMS_STREAM_SOURCE_BUFFER_WRITE</td>
        <td>Transcoder will write to DMS the stream</td>
    </tr>
    <tr>
        <td>DMS_STREAM_SOURCE_HTTP_READ</td>
        <td>HTTP Stream</td>
    </tr>
    <tr>
        <td>DMS_STREAM_SOURCE_FILE_READ</td>
        <td>Local File stream</td>
    </tr>
    </table>

*/
typedef slim_int TDMSStreamSource;
/*@}*/

#ifdef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
enum {
  DMS_CONTENTS_TYPE_UNKNOWN = 0,
  /*Image*/
  DMS_CONTENTS_TYPE_JPEG,
  DMS_CONTENTS_TYPE_PNG,
  DMS_CONTENTS_TYPE_BMP,
  DMS_CONTENTS_TYPE_GIF,
  DMS_CONTENTS_TYPE_TIFF,

  /*Audio*/
  DMS_CONTENTS_TYPE_LPCM,
  DMS_CONTENTS_TYPE_PCM,       /* .pcm */
  DMS_CONTENTS_TYPE_MP3,
  DMS_CONTENTS_TYPE_ASF,
  DMS_CONTENTS_TYPE_WMA,
  DMS_CONTENTS_TYPE_WAV,
  DMS_CONTENTS_TYPE_AAC_ADTS,
  DMS_CONTENTS_TYPE_AAC,       /* .aac */
  DMS_CONTENTS_TYPE_MP1,
  DMS_CONTENTS_TYPE_MP2,
  DMS_CONTENTS_TYPE_MP4_AUDIO,
  DMS_CONTENTS_TYPE_3GP_AUDIO,
  DMS_CONTENTS_TYPE_AC3,
  DMS_CONTENTS_TYPE_ATRAC,

  DMS_CONTENTS_TYPE_ASX,
  DMS_CONTENTS_TYPE_MID,
  DMS_CONTENTS_TYPE_AT3P,
  DMS_CONTENTS_TYPE_RMI,
  DMS_CONTENTS_TYPE_SND,
  DMS_CONTENTS_TYPE_APL,          /*Monkey's Audio*/
  DMS_CONTENTS_TYPE_DTS,
  DMS_CONTENTS_TYPE_DTSHD,        /*DTS HD*/
  DMS_CONTENTS_TYPE_DAB,
  DMS_CONTENTS_TYPE_AMR,       /* .amr */
  DMS_CONTENTS_TYPE_AU,        /* .au, .snd */
  DMS_CONTENTS_TYPE_OGG_AUDIO, /* .oga,*/
  DMS_CONTENTS_TYPE_FLAC,      /* .flac */
  DMS_CONTENTS_TYPE_VOC,       /* .voc */
  DMS_CONTENTS_TYPE_SOX,       /* .act */
  DMS_CONTENTS_TYPE_MLP,       /* .mlp */
  DMS_CONTENTS_TYPE_RA,        /*real audio*/
  DMS_CONTENTS_TYPE_RAM,       /*real audio*/

  /* Container formats, can contain audio and video files */
  DMS_CONTENTS_TYPE_MATROSKA,  /* .mkv .mka .mks */
  DMS_CONTENTS_TYPE_WEBM,      /* .webm */
  DMS_CONTENTS_TYPE_MXF,       /* possible extension .mxf */
  DMS_CONTENTS_TYPE_VOB,       /* .vob */
  DMS_CONTENTS_TYPE_SWF,       /* .swf */
  DMS_CONTENTS_TYPE_RM,        /* .rm */
  DMS_CONTENTS_TYPE_3G2,       /* 3GPP2 format, extension .3g2 */

  /* Videos */
  DMS_CONTENTS_TYPE_MPEG2,
  DMS_CONTENTS_TYPE_MP4,
  DMS_CONTENTS_TYPE_MP4_VIDEO,
  DMS_CONTENTS_TYPE_3GP,
  DMS_CONTENTS_TYPE_3GP_VIDEO,
  DMS_CONTENTS_TYPE_TS,
  DMS_CONTENTS_TYPE_MPEG2_TS,
  DMS_CONTENTS_TYPE_M2TS,
  DMS_CONTENTS_TYPE_MP2T,
  DMS_CONTENTS_TYPE_MOV,
  DMS_CONTENTS_TYPE_AVI,
  DMS_CONTENTS_TYPE_DIVX,
  DMS_CONTENTS_TYPE_WMV,
  DMS_CONTENTS_TYPE_MJPEG,
  DMS_CONTENTS_TYPE_MPE,
  DMS_CONTENTS_TYPE_MP2P,
  DMS_CONTENTS_TYPE_M2V,
  DMS_CONTENTS_TYPE_M1V,
  DMS_CONTENTS_TYPE_VC1_ASF,
  DMS_CONTENTS_TYPE_ROQ,       /* extension .roq */
  DMS_CONTENTS_TYPE_DV,        /* .dv, .dif */
  DMS_CONTENTS_TYPE_OGG_VIDEO, /* .ogv, .oga, .ogx, .ogg, .spx, */
  DMS_CONTENTS_TYPE_FLV, /*     .flv, .f4v, .f4p, .f4a, .f4b */
  DMS_CONTENTS_TYPE_QT,
  DMS_CONTENTS_TYPE_MJ2, /* motion jpeg, .mj2 */
  DMS_CONTENTS_TYPE_VDR,
  DMS_CONTENTS_TYPE_OV,
  DMS_CONTENTS_TYPE_DVRMS,
  DMS_CONTENTS_TYPE_DVD,
  DMS_CONTENTS_TYPE_H261,
  DMS_CONTENTS_TYPE_H263,
  DMS_CONTENTS_TYPE_H264,
  DMS_CONTENTS_TYPE_ISO,

  /*Playlist*/
  DMS_CONTENTS_TYPE_M3U,
  DMS_CONTENTS_TYPE_M3U8,
  DMS_CONTENTS_TYPE_PLS,
  DMS_CONTENTS_TYPE_WPL

};
#endif /* DEVELOPMENT_ENABLE_PUBLISH_CONTENT */
/**
 * @addtogroup Enumerators
 */
/*@{*/

/*!
  TDMSContentType represents the DMS content media type.

<b>*</b> Content type that requires license contract before using
<b>**</b> Content type supported in extended NFLC version

<table>
        <tr>
                <td><b>Definition</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_UNKNOWN</td>
                <td>Unknown content type</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_JPEG</td>
                <td>JPEG</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_PNG</td>
                <td>PNG</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_BMP</td>
                <td>BMP</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_GIF</td>
                <td>GIF</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_LPCM</td>
                <td>LPCM</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_MP3</td>
                <td>MP3</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_ASF</td>
                <td>ASF</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_WMA</td>
                <td>WMA</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_WMV</td>
                <td>WMV</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_WAV</td>
                <td>WAV</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_MPEG2</td>
                <td>MPEG2</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_OV</td>
                <td>OV</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_MPEG2_TS</td>
                <td>MPEG2 TS(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_VC1_ASF</td>
                <td>VC1(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_ALAW</td>
                <td>ALAW(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_ASS</td>
                <td>ASS(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_AVM2</td>
                <td>AVM2(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_CRC</td>
                <td>CRC(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_DAUD</td>
                <td>DAUD(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_DTS</td>
                <td>DTS(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_DVD</td>
                <td>DVD(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_EA</td>
                <td>EA(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_EA_CDATA</td>
                <td>EA CDATA(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_EAC3</td>
                <td>EAC3(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_FFM</td>
                <td>FFM(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_MULAW</td>
                <td>MULAW(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_GXF</td>
                <td>GXF(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_DNXHD</td>
                <td>DNXHD(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_FILMSTRIP</td>
                <td>FILMSTRIP(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_FRAMECRC</td>
                <td>FRAMECRC(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_H261</td>
                <td>H261(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_H263</td>
                <td>H263(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_H264</td>
                <td>H264(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_IMAGE2</td>
                <td>IMAGE 2(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_IMAGE2PIPE</td>
                <td>IMAGE 2 PIPE(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_INGENIENT</td>
                <td>INGENIENT(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_IPMOVIE</td>
                <td>IPMOVIE(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_IPOD</td>
                <td>IPOD(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_MMF</td>
                <td>MMF(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_MPJPEG</td>
                <td>MPJPEG(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_MXF_D10</td>
                <td>MXF D10(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_NUT</td>
                <td>NUT(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_OSS</td>
                <td>OSS(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_PSP</td>
                <td>PSP(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_R3D</td>
                <td>R3D(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_RAWVIDEO</td>
                <td>RAWVIDEO(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_RCV</td>
                <td>RCV(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_RTP</td>
                <td>RTP(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_RTSP</td>
                <td>RTSP(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_SPDIF</td>
                <td>SPDIF(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_SVCD</td>
                <td>SVCD(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_TIERTEXSEQ</td>
                <td>TIERTEXSEQ(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_TRUEHD</td>
                <td>TRUEHD(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_VCD</td>
                <td>VCD(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_YUV4MPEGPIPE</td>
                <td>YUV4MPEGPIPE(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_MATROSKA</td>
                <td>MATROSKA(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_WEBM</td>
                <td>WEBM(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_MXF</td>
                <td>MXF(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_FLV</td>
                <td>FLV(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_SWF</td>
                <td>SWF(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_RM</td>
                <td>RM(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_3G2</td>
                <td>3G2(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_DPX</td>
                <td>DPX(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_ICO</td>
                <td>ICO(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_AAC</td>
                <td>AAC(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_AMR</td>
                <td>AMR(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_AIFF</td>
                <td>AIFF(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_AU</td>
                <td>AU(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_PCM</td>
                <td>PCM(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_OGG_AUDIO</td>
                <td>OGG AUDIO(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_FLAC</td>
                <td>FLAC(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_VOC</td>
                <td>VOC(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_SOX</td>
                <td>SOX(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_MLP</td>
                <td>MLP(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_MP2</td>
                <td>MP2(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_RA</td>
                <td>RA(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_RAM</td>
                <td>RAM(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_MP1</td>
                <td>MP1(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_ASX</td>
                <td>ASX(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_MID</td>
                <td>MID(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_AT3P</td>
                <td>AT3P(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_RMI</td>
                <td>RMI(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_SND</td>
                <td>SND(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_APL</td>
                <td>APL(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_DTSHD</td>
                <td>DTSHD(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_ROQ</td>
                <td>ROQ(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_DV</td>
                <td>DV(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_OGG_VIDEO</td>
                <td>OGG VIDEO(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_MOV</td>
                <td>MOV(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_MJ2</td>
                <td>MJ2(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_AVI</td>
                <td>AVI(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_DIVX</td>
                <td>DIVX(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_MJPEG</td>
                <td>MJPEG(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_MPE</td>
                <td>MPE(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_MP2P</td>
                <td>MP2P(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_MP2T</td>
                <td>MP2T(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_</td>
                <td>(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_</td>
                <td>(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_M2V</td>
                <td>M2V(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_M1V</td>
                <td>M1V(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_OGM</td>
                <td>OGM(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_TS</td>
                <td>TS(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_QT</td>
                <td>QT(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_TGA</td>
                <td>TGA(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_MPA</td>
                <td>MPA(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_M2TS</td>
                <td>M2TS(**)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_MP4</td>
                <td>MP4(Video or Audio)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_MP4_VIDEO</td>
                <td>MP4 VIDEO</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_MP4_EU_MPEG4_B13</td>
                <td>MP4 VIDEO CONSTRAINED Profile BASE Level 1.3</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_MP4_AUDIO</td>
                <td>MP4 AUDIO</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_3GP</td>
                <td>3GP(Video or Audio)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_3GP_VIDEO</td>
                <td>3GP VIDEO</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_3GP_AUDIO</td>
                <td>3GP AUDIO</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_RTML</td>
                <td>RTML</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_PLAYLIST</td>
                <td>PLAYLIST</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_M3U</td>
                <td>M3U</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_M3U8</td>
                <td>M3U8</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_PLS</td>
                <td>PLS</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_WPL</td>
                <td>WPL</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_DIVX</td>
                <td>DIVX (*)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_AVI</td>
                <td>AVI(*)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_AC3</td>
                <td>AC3(*)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_TIFF</td>
                <td>TIFF(*)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_FLV</td>
                <td>FLV(*)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_QT</td>
                <td>QT(*)</td>
        </tr>
        <tr>
                <td>DMS_CONTENTS_TYPE_ATRAC</td>
                <td>ATRAC(*)</td>
        </tr>

</table>
*/

typedef slim_int TDMSContentType;
/*@}*/


struct _TDMSPublishStorage {
  slim_char* path;
  slim_char* name;
  slim_char* id;
  TDMSStorageDBLocation database_loc;
  slim_bool auto_index;
  TDMSEncryptionType encryption_type;
};

/**
 * @addtogroup Structures
 */
/*@{*/

/*!
    TDMSPublishStorage specifies the folder/storage (locally accessible by DMS) to be published

    <table>
        <tr>
                <td><b>Member</b></td>
                <td><b>Data Type</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>path</td>
                <td>slim_char</td>
                <td>(Required)Absolute Path of the folder/storage to be published</td>
        </tr>
        <tr>
                <td>name</td>
                <td>slim_char</td>
                <td>(Optional)Name of the folder/storage to be published</td>
        </tr>
        <tr>
                <td>id</td>
                <td>slim_char</td>
                <td>(Optional)Id of the folder/storage to be published</td>
        </tr>
        <tr>
                <td>database_loc</td>
                <td>TDMSStorageDBLocation</td>
                <td>(Conditionally Required)specifies if the database for the storage/folder to be saved locally/centrally</td>
        </tr>
        <tr>
                <td>auto_index</td>
                <td>slim_bool</td>
                <td>(Required)specifies if the storage/folder to be auto-indexed by DMS</td>
        </tr>
        <tr>
                <td>encryption_type</td>
                <td>TDMSEncryptionType</td>
                <td>(Optional)Specifies the encryption type of the content of the storage. By default, if the content is not encrypted, NONE is specified</td>
        </tr>
    </table>
*/
typedef struct _TDMSPublishStorage TDMSPublishStorage;
/*@}*/

#ifdef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
struct _TDMSObjectRights {
  slim_int allowed_output_type;
  TDMSDtcpCci dtcp_cci;
  slim_word concurrent_viewing_count;
  slim_word play_count;
  slim_word nr_devices_allowed;
};
#endif /* DEVELOPMENT_ENABLE_PUBLISH_CONTENT */
/**
 * @addtogroup Structures
 */
/*@{*/

/*!
    TDMSObjectRights specifies the Object Rights of the content/folder to be published

    <table>
        <tr>
                <td><b>Member</b></td>
                <td><b>Data Type</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>allowed_output_type</td>
                <td>slim_int</td>
                <td>(Required)Allowed Output Type for the content</td>
        </tr>
        <tr>
                <td>dtcp_cci</td>
                <td>TDMSDtcpCci</td>
                <td>(Conditionally Required)Copy Control Information for DTCP</td>
        </tr>
        <tr>
                <td>concurrent_viewing_count</td>
                <td>slim_word</td>
                <td>(Optional) Concurrent Viewing Count</td>
        </tr>
        <tr>
                <td>play_count</td>
                <td>slim_word</td>
                <td>(Optional) Total Playcount of the stream</td>
        </tr>
        <tr>
                <td>nr_devices_allowed</td>
                <td>slim_bool</td>
                <td>(Optional) Total number of devices the stream is allowed to be streamed</td>
        </tr>
    </table>
*/
typedef struct _TDMSObjectRights TDMSObjectRights;
/*@}*/

#ifdef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
struct _TDMSPublishVirtualContainer {
  slim_char *name;
  slim_char *id;
  slim_char *parent_id;
};
#endif /* DEVELOPMENT_ENABLE_PUBLISH_CONTENT */

/**
 * @addtogroup Structures
 */
/*@{*/

/*!
    TDMSPublishVirtualContainer specifies the virtual folder

    <table>
        <tr>
                <td><b>Member</b></td>
                <td><b>Data Type</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>name</td>
                <td>slim_char</td>
                <td>(Required)Name of the virtual folder</td>
        </tr>
        <tr>
                <td>id</td>
                <td>slim_char</td>
                <td>(Optional)Id of the virtual folder (could be the same as name)</td>
        </tr>
        <tr>
                <td>parent_id</td>
                <td>slim_char</td>
                <td>(Required) Id of the parent folder of the virtual folder, specify "0" if it is to be a child at root</td>
        </tr>
    </table>
*/
typedef struct _TDMSPublishVirtualContainer TDMSPublishVirtualContainer;
/*@}*/

#ifdef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
struct _TDMSPublishUserMetadata {
  struct _TDMSPublishUserMetadata *prev;
  struct _TDMSPublishUserMetadata *next;
  slim_char *name;
  slim_char *value;
};
#endif /* DEVELOPMENT_ENABLE_PUBLISH_CONTENT */

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

struct _TDMSPublishAudioRes {
  slim_word max_bit_rate;
  slim_word avg_bit_rate;
  slim_word nr_channels;
  slim_word sampling_rate;
  slim_word profile;
  slim_word level;
  slim_char *codec_name;
  slim_char *duration_string;

};

/**
 * @addtogroup Structures
 */
/*@{*/

/*!
    TDMSPublishAudioRes specifies the audio information of the content/folder to be published

    <table>
        <tr>
                <td><b>Member</b></td>
                <td><b>Data Type</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>max_bit_rate</td>
                <td>slim_word</td>
                <td>(Required) Maximum Bitrate</td>
        </tr>
        <tr>
                <td>avg_bit_rate</td>
                <td>slim_word</td>
                <td>(Required) Average Bitrate</td>
        </tr>
        <tr>
                <td>nr_channels</td>
                <td>slim_word</td>
                <td>(Required) Number of Channels</td>
        </tr>
        <tr>
                <td>sampling_rate</td>
                <td>slim_word</td>
                <td>(Required) Sampling rate</td>
        </tr>
        <tr>
                <td>profile</td>
                <td>slim_word</td>
                <td>(Required) CHannel Profile (Channel Configuration) </td>
        </tr>
        <tr>
                <td>level</td>
                <td>slim_word</td>
                <td>(Required) Codec Level</td>
        </tr>
        <tr>
                <td>codec_name</td>
                <td>slim_char</td>
                <td>(Required) Codec Name</td>
        </tr>
        <tr>
                <td>duration_string</td>
                <td>slim_char</td>
                <td>(Required) Duration String. The Form of the duration string is H+:MM:SS[.F+] or H+:MM:SS[.F0/F1],
                     where:
                    \li H+: one or more digits to indicate elapsed hours,
                    \li MM: exactly 2 digits to indicate minutes (00 to 59),
                    \li SS: exactly 2 digits to indicate seconds (00 to 59),
                    \li F+: any number of digits (including no digits) to indicate fractions of seconds,
                    \li F0/F1: a fraction, with F0 and F1 at least one digit long, and F0 < F1.
                    \li The string MAY be preceded by a “+” or “-” sign, and the decimal point itself MUST be omitted if there
                    \li are no fractional second digits.  </td>
        </tr>
    </table>
*/
typedef struct _TDMSPublishAudioRes TDMSPublishAudioRes;
/*@}*/

struct _TDMSPublishVideoRes {
  slim_word width;
  slim_word height;
  slim_word avg_bit_rate;
  slim_word max_bit_rate;
  slim_char *frame_rate;
  slim_char *par;
  slim_char *dar;
  slim_char *region;
  slim_bool have_ifo;
  slim_word profile; /*TODO: Check if this is required for video*/
  slim_word level;
  slim_char *codec_name;
  slim_char *duration_string;
};

/**
 * @addtogroup Structures
 */
/*@{*/

/*!
    TDMSPublishVideoRes specifies the Video Information of the content to be published

    <table>
        <tr>
                <td><b>Member</b></td>
                <td><b>Data Type</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>width</td>
                <td>slim_word</td>
                <td>(Required) Width of the video</td>
        </tr>
        <tr>
                <td>height</td>
                <td>slim_word</td>
                <td>(Required) Height of the video</td>
        </tr>
        <tr>
                <td>avg_bit_rate</td>
                <td>slim_word</td>
                <td>(Required) Average Bitrate</td>
        </tr>
        <tr>
                <td>max_bit_rate</td>
                <td>slim_word</td>
                <td>(Required) Maximum Bitrate</td>
        </tr>
        <tr>
                <td>frame_rate</td>
                <td>slim_char</td>
                <td>(Required) Video Frame Rate Code (Numerator/Denominator) </td>
        </tr>
        <tr>
                <td>par</td>
                <td>slim_char</td>
                <td>(Required) Picture Aspect Ratio (Numerator/Denominator)</td>
        </tr>
        <tr>
                <td>dar</td>
                <td>slim_char</td>
                <td>(Required) Display Aspect Ratio (Numerator/Denominator)</td>
        </tr>
        <tr>
                <td>region</td>
                <td>slim_char</td>
                <td>(Required) Video Region (EU/NA/JP/KO) </td>
        </tr>
        <tr>
                <td>have_ifo</td>
                <td>slim_bool</td>
                <td>(Optional) IFO File (DVD Info File)</td>
        </tr>
        <tr>
                <td>profile</td>
                <td>slim_word</td>
                <td>(Required) Channel Profile (Channel Configuration) </td>
        </tr>
        <tr>
                <td>level</td>
                <td>slim_word</td>
                <td>(Required) Codec Level</td>
        </tr>
        <tr>
                <td>codec_name</td>
                <td>slim_char</td>
                <td>(Required) Codec Name</td>
        </tr>
        <tr>
                <td>duration_string</td>
                <td>slim_char</td>
                <td>(Required) Duration String. The Form of the duration string is H+:MM:SS[.F+] or H+:MM:SS[.F0/F1],
                     where:
                    \li H+: one or more digits to indicate elapsed hours,
                    \li MM: exactly 2 digits to indicate minutes (00 to 59),
                    \li SS: exactly 2 digits to indicate seconds (00 to 59),
                    \li F+: any number of digits (including no digits) to indicate fractions of seconds,
                    \li F0/F1: a fraction, with F0 and F1 at least one digit long, and F0 < F1.
                    \li The string MAY be preceded by a “+” or “-” sign, and the decimal point itself MUST be omitted if there
                    \li are no fractional second digits.  </td>
        </tr>
    </table>
*/
typedef struct _TDMSPublishVideoRes TDMSPublishVideoRes;
/*@}*/

struct _TDMSPublishImageRes {
  slim_word width;
  slim_word height;
};

/**
 * @addtogroup Structures
 */
/*@{*/

/*!
    TDMSPublishImageRes specifies the Image resource of the content to be published

    <table>
        <tr>
                <td><b>Member</b></td>
                <td><b>Data Type</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>width</td>
                <td>slim_word</td>
                <td>(Required) width of the Image</td>
        </tr>
        <tr>
                <td>height</td>
                <td>slim_word</td>
                <td>(Required) height of the Image</td>
        </tr>
    </table>
*/
typedef struct _TDMSPublishImageRes TDMSPublishImageRes;
/*@}*/

struct _TDMSPublishContentRes {
  struct _TDMSPublishContentRes *prev;
  struct _TDMSPublishContentRes *next;
  TDMSContentResType res_type;
  TDMSContentType res_content_type;
  slim_char *mime;
  slim_char *res_url;
  slim_char *extension;
  slim_word seek_flags;
  TDMSEncryptionType encryption_type;
  TDMSStreamSource stream_source;
  TDMSObjectRights *object_rights;
  TDMSPublishImageRes *image_info;
  TDMSPublishAudioRes *audio_info;
  TDMSPublishVideoRes *video_info;
};

/**
 * @addtogroup Structures
 */
/*@{*/

/*!
    TDMSPublishContentRes specifies the resource of the content to be published

    <table>
        <tr>
                <td><b>Member</b></td>
                <td><b>Data Type</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>res_type</td>
                <td>TDMSContentResType</td>
                <td>(Required) Resource Type</td>
        </tr>
        <tr>
                <td>res_content_type</td>
                <td>TDMSContentType</td>
                <td>(Required) Content Type of the resource</td>
        </tr>
        <tr>
                <td>mime</td>
                <td>slim_char</td>
                <td>(Required) Mime Type of the resource</td>
        </tr>
        <tr>
                <td>res_url</td>
                <td>slim_char</td>
                <td>(Required) Url of the resource</td>
        </tr>
        <tr>
                <td>extension</td>
                <td>slim_char</td>
                <td>(Required) Extension of the resource (for eg, mp3, mp4 etc)</td>
        </tr>
        <tr>
                <td>stream_source</td>
                <td>TDMSStreamSource</td>
                <td>(Required) specifies the stream source</td>
        </tr>
        <tr>
                <td>object_rights</td>
                <td>TDMSObjectRights</td>
                <td>(Optional) Object Rights of the resource </td>
        </tr>
        <tr>
                <td>image_info</td>
                <td>TDMSPublishImageRes</td>
                <td>(Conditionally Required) Image information of the resource</td>
        </tr>
        <tr>
                <td>audio_info</td>
                <td>TDMSPublishAudioRes</td>
                <td>(Conditionally Required) Audio Information of the resource</td>
        </tr>
        <tr>
                <td>video_info</td>
                <td>TDMSPublishVideoRes</td>
                <td>(Conditionally Required) Video Information of the resource </td>
        </tr>
    </table>
*/
typedef struct _TDMSPublishContentRes TDMSPublishContentRes;
/*@}*/


#ifdef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
struct _TDMSPublishContent {
  slim_char *content_id;
  slim_char *parent_id;
  TDMSStreamType stream_type;
  dlna_time_t date;
  slim_char *title;
  slim_char *album;
  slim_char *creator;
  slim_char *genre;
  slim_char *artist;
  slim_char *composer;
  slim_word track_num;
  slim_bool persistent;
  slim_char *rating;
  slim_char *rating_type;
  List(TDMSPublishUserMetadata*) user_metadata_list;
  List(TDMSPublishContentRes*) resources_list;
};
#endif /* DEVELOPMENT_ENABLE_PUBLISH_CONTENT */
/**
 * @addtogroup Structures
 */
/*@{*/

/*!
    TDMSPublishContent specifies the Object Rights of the content/folder to be published

    <table>
        <tr>
                <td><b>Member</b></td>
                <td><b>Data Type</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>content_id</td>
                <td>slim_char</td>
                <td>(Required) Vendor-specific id of the stream </td>
        </tr>
        <tr>
                <td>parent_id</td>
                <td>slim_char</td>
                <td>(Required) Id of the parent folder to which stream to be published shall be associated as child</td>
        </tr>
        <tr>
                <td>stream-type</td>
                <td>TDMSStreamType</td>
                <td>(Required) Type of the stream</td>
        </tr>
        <tr>
                <td>date</td>
                <td>dlna_time_t</td>
                <td>(Optional) Creation/Last Modified time of the content/stream </td>
        </tr>
        <tr>
                <td>title</td>
                <td>slim_char</td>
                <td>(Optional) Title of the stream</td>
        </tr>
        <tr>
                <td>album</td>
                <td>slim_char</td>
                <td>(Optional) Album of the stream</td>
        </tr>
        <tr>
                <td>creator</td>
                <td>slim_char</td>
                <td>(Optional) Creator of the stream</td>
        </tr>
        <tr>
                <td>genre</td>
                <td>slim_char</td>
                <td>(Optional) Genre of the stream</td>
        </tr>
        <tr>
                <td>artist</td>
                <td>slim_char</td>
                <td>(Optional) Artist of the stream</td>
        </tr>
        <tr>
                <td>composer</td>
                <td>slim_char</td>
                <td>(Optional) Composer of the stream </td>
        </tr>
        <tr>
                <td>track_num</td>
                <td>slim_word</td>
                <td>(Optional) Track Number of the stream</td>
        </tr>
                <tr>
                <td>persistent</td>
                <td>slim_bool</td>
                <td>(Optional) Content that need to be retained and stored</td>
        </tr>
        <tr>
                <td>rating</td>
                <td>slim_char</td>
                <td>(Optional) Rating of the stream</td>
        </tr>
                <tr>
                <td>rating_type</td>
                <td>slim_char</td>
                <td>(Optional) Rating Type of the stream</td>
        </tr>
                <tr>
                <td>user_metadata_list</td>
                <td>List(user_metadata*)</td>
                <td>(Required) List of the user metadata.</td>
        </tr>
        <tr>
                <td>resources_list</td>
                <td>List(TDMSPublishContentRes*)</td>
                <td>(Required) List of the resources. Atleast the resource of the content is required</td>
        </tr>
    </table>
*/
typedef struct _TDMSPublishContent TDMSPublishContent;
/*@}*/

// struct _TDMSTranscodeTarget {
//   slim_char *contentId;
//   slim_char *url;
//   slim_char *mime;
//   TDMSPublishContentRes *targetResource;
// };
// 
// typedef struct _TDMSTranscodeTarget TDMSTranscodeTarget;
// 
// struct _TDMSTranscodeBuffer {
//     slim_int sid;
//     slim_int uid;
//     slim_int handle;
//     slim_int length;
//     slim_int flags;
//     slim_char *buf;
// } ;
// typedef struct _TDMSTranscodeBuffer TDMSTranscodeBuffer;

#endif /* DMS_PUBLISH_API_H_ */
