/*
 * dlna_debug.h
 * Copyright (C) 2007-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */

#ifndef NFLC_DLNA_DEBUG_H
#define NFLC_DLNA_DEBUG_H

#ifdef RELEASE
#define DEBUG_SYSTEM                       0
#else /* RELEASE */
#define DEBUG_SYSTEM                       1
#endif /* RELEASE */

/*
 * These defines are subject to the influence of 'DEBUG_SYSTEM'.
 */
#define IS_DEBUG_SYSTEM_ERROR              (DEBUG_SYSTEM & 1)

/* Memory debug.  */
#define IS_DEBUG_MEMORY_EVENT              (DEBUG_SYSTEM & 1)
#define IS_DEBUG_MEMORY_VERBOSE            (DEBUG_SYSTEM & 1)
#define IS_DEBUG_MEMORY_ERROR              (DEBUG_SYSTEM & 1)

/* SSDP debug.  */
#define IS_DEBUG_SSDP_PACKET               (DEBUG_SYSTEM & 0)
#define IS_DEBUG_SSDP_EVENT                (DEBUG_SYSTEM & 0)
#define IS_DEBUG_SSDP_ERROR                (DEBUG_SYSTEM & 1)

/* GENA debug.  */
#define IS_DEBUG_GENA_PACKET               (DEBUG_SYSTEM & 0)
#define IS_DEBUG_GENA_EVENT                (DEBUG_SYSTEM & 0)
#define IS_DEBUG_GENA_ERROR                (DEBUG_SYSTEM & 1)

/* SOAP debug.  */
#define IS_DEBUG_SOAP_PACKET               (DEBUG_SYSTEM & 0)
#define IS_DEBUG_SOAP_EVENT                (DEBUG_SYSTEM & 0)
#define IS_DEBUG_SOAP_ERROR                (DEBUG_SYSTEM & 1)

/* HTTP debug.  */
#define IS_DEBUG_HTTP_MSG                  (DEBUG_SYSTEM & 0)
#define IS_DEBUG_HTTP_PACKET               (DEBUG_SYSTEM & 0)
#define IS_DEBUG_HTTP_EVENT                (DEBUG_SYSTEM & 0)
#define IS_DEBUG_HTTP_EVENT_VERB           (DEBUG_SYSTEM & 0)
#define IS_DEBUG_HTTP_ERROR                (DEBUG_SYSTEM & 1)
#define IS_DEBUG_HTTP_ACCESS_NOTIFY        (DEBUG_SYSTEM & 0)
#define IS_DEBUG_HTTP_ACCESS_NOTIFY_DETAIL (DEBUG_SYSTEM & 0)
#define IS_DEBUG_HTTP_ACCESS_NOTIFY_ERROR  (DEBUG_SYSTEM & 1)

/* XML */
#define IS_DEBUG_XML_ERROR                 (DEBUG_SYSTEM & 0)

/* UPnP debug.  */
#define IS_DEBUG_UPNP_PACKET               (DEBUG_SYSTEM & 0)
#define IS_DEBUG_UPNP_EVENT                (DEBUG_SYSTEM & 0)
#define IS_DEBUG_UPNP_EVENT_VERB           (DEBUG_SYSTEM & 0)
#define IS_DEBUG_UPNP_ERROR                (DEBUG_SYSTEM & 1)
#define IS_DEBUG_UPNP_MSG                  (DEBUG_SYSTEM & 0)

#define IS_DEBGU_UPLAYER_MSG               (DEBUG_SYSTEM & 0)

/* UPnP interface debug.  */
#define IS_DEBUG_UPNP_IF_EVENT             (DEBUG_SYSTEM & 0)
#define IS_DEBUG_UPNP_IF_ERROR             (DEBUG_SYSTEM & 1)

#define IS_DEBUG_RCS_MSG                   (DEBUG_SYSTEM & 0)
#define IS_DEBUG_RCS_ERROR                 (DEBUG_SYSTEM & 1)

#define IS_DEBUG_AVTS_MSG                  (DEBUG_SYSTEM & 0)
#define IS_DEBUG_AVTS_ERROR                (DEBUG_SYSTEM & 1)

#define IS_DEBUG_CDS_MSG                   (DEBUG_SYSTEM & 0)
#define IS_DEBUG_CDS_ERROR                 (DEBUG_SYSTEM & 1)
#define IS_DEBUG_CDS_PUBLISHER             (DEBUG_SYSTEM & 1)

#define IS_DEBUG_BMS_MSG                   (DEBUG_SYSTEM & 0)
#define IS_DEBUG_BMS_ERROR                 (DEBUG_SYSTEM & 1)

#define IS_DEBUG_EMS_MSG                   (DEBUG_SYSTEM & 0)
#define IS_DEBUG_EMS_ERROR                 (DEBUG_SYSTEM & 1)

#define  IS_DEBUG_UPNP_CDS_MSG             (DEBUG_SYSTEM & 0)
#define  IS_DEBUG_UPNP_CDS_ERROR           (DEBUG_SYSTEM & 1)

#define IS_DEBUG_UPNP_CDS_ICP_MSG          (DEBUG_SYSTEM & 0)
#define IS_DEBUG_UPNP_CDS_ICP_ERR          (DEBUG_SYSTEM & 1)

#define IS_DEBUG_USER_AGENT_MSG            (DEBUG_SYSTEM & 0)
#define IS_DEBUG_USER_AGENT_ERR            (DEBUG_SYSTEM & 1)

#define IS_DEBUG_CONTENTS                  (DEBUG_SYSTEM & 0)
#define IS_DEBUG_CONTENTS_VERBOSE          (DEBUG_SYSTEM & 0)

/* DLNA debug.  */
#define IS_DEBUG_DLNA_EVENT                (DEBUG_SYSTEM & 0)
#define IS_DEBUG_DLNA_ERROR                (DEBUG_SYSTEM & 1)

/* MSCP debug.  */
#define IS_DEBUG_MSCP_PACKET               (DEBUG_SYSTEM & 0)
#define IS_DEBUG_MSCP_EVENT                (DEBUG_SYSTEM & 0)
#define IS_DEBUG_MSCP_ERROR                (DEBUG_SYSTEM & 1)

/* MRCP debug.  */
#define IS_DEBUG_MRCP_PACKET               (DEBUG_SYSTEM & 0)
#define IS_DEBUG_MRCP_EVENT                (DEBUG_SYSTEM & 0)
#define IS_DEBUG_MRCP_ERROR                (DEBUG_SYSTEM & 1)

/* DMP debug.  */
#define IS_DEBUG_DMP_EVENT                 (DEBUG_SYSTEM & 0)
#define IS_DEBUG_DMP_API                   (DEBUG_SYSTEM & 0)
#define IS_DEBUG_DMP_ERROR                 (DEBUG_SYSTEM & 1)

/* DMC debug.  */
#define IS_DEBUG_DMC_EVENT                 (DEBUG_SYSTEM & 0)
#define IS_DEBUG_DMC_API                   (DEBUG_SYSTEM & 0)
#define IS_DEBUG_DMC_ERROR                 (DEBUG_SYSTEM & 1)

/* DMS debug.  */
#define IS_DEBUG_DMS_EVENT                 (DEBUG_SYSTEM & 0)
#define IS_DEBUG_DMS_ERROR                 (DEBUG_SYSTEM & 1)
#define IS_DEBUG_DMS_GENA                  (DEBUG_SYSTEM & 0)
#define IS_DEBUG_DMS_MSG                   (DEBUG_SYSTEM & 0)
#define IS_DEBUG_DMS_CONTENTS_IDX          (DEBUG_SYSTEM & 0)
#define IS_DEBUG_DMS_PERFORMANCE           (DEBUG_SYSTEM & 1)

/* DMX API debug.  */
#define IS_DEBUG_API_MSG                   (DEBUG_SYSTEM & 0)
#define IS_DEBUG_API_FUNC                  0                  /* exception. it is not affected from 'DEBUG_SYSTEM' and referred in dlna_peer.h */
#define IS_DEBUG_API_ERROR                 (DEBUG_SYSTEM & 1)

/* peer call debug.  */
#define IS_DEBUG_PEER_MSG                  (DEBUG_SYSTEM & 0)
#define IS_DEBUG_PEER_FUNC                 (DEBUG_SYSTEM & 0)
#define IS_DEBUG_PEER_ERROR                (DEBUG_SYSTEM & 1)

/* Parser Manager */
#define IS_DEBUG_PARSER_MANAGER_INFO       (DEBUG_SYSTEM & 0)
#define IS_DEBUG_PARSER_MANAGER_ERROR      (DEBUG_SYSTEM & 1)

/* media info */
#define IS_DEBUG_MEDIA_INFO                (DEBUG_SYSTEM & 0)
#define IS_DEBUG_MEDIA_INFO_VERB           (DEBUG_SYSTEM & 0)
#define IS_DEBUG_MEDIA_ERROR               (DEBUG_SYSTEM & 1)

#define IS_DEBUG_MPEG2_EVENT               (DEBUG_SYSTEM & 0)
#define IS_DEBUG_MPEG2_EVENT_VERB          (DEBUG_SYSTEM & 0)
#define IS_DEBUG_MPEG2_ERROR               (DEBUG_SYSTEM & 1)

#define IS_DEBUG_MPEG4_EVENT               (DEBUG_SYSTEM & 0)
#define IS_DEBUG_MPEG4_INFO_VERBOSE        (DEBUG_SYSTEM & 0)
#define IS_DEBUG_MPEG4_ERROR               (DEBUG_SYSTEM & 1)

#define IS_DEBUG_MP4_EVENT                 (DEBUG_SYSTEM & 0)
#define IS_DEBUG_MP4_INFO_VERBOSE          (DEBUG_SYSTEM & 0)
#define IS_DEBUG_MP4_ERROR                 (DEBUG_SYSTEM & 1)

#define IS_DEBUG_VC1_EVENT                 (DEBUG_SYSTEM & 0)
#define IS_DEBUG_VC1_ERROR                 (DEBUG_SYSTEM & 0)

#define IS_DEBUG_WMV_EVENT                 (DEBUG_SYSTEM & 0)
#define IS_DEBUG_WMV_ERROR                 (DEBUG_SYSTEM & 1)

#define IS_DEBUG_JPEG_EVENT                (DEBUG_SYSTEM & 0)
#define IS_DEBUG_JPEG_ERROR                (DEBUG_SYSTEM & 1)

#define IS_DEBUG_WAV_EVENT                 (DEBUG_SYSTEM & 0)
#define IS_DEBUG_WAV_ERROR                 (DEBUG_SYSTEM & 1)

/* DMR debug.  */
#define IS_DEBUG_DMR_EVENT                 (DEBUG_SYSTEM & 0)
#define IS_DEBUG_DMR_ERROR                 (DEBUG_SYSTEM & 1)

/* DMPr debug.  */
#define IS_DEBUG_DMPR_EVENT                (DEBUG_SYSTEM & 0)
#define IS_DEBUG_DMPR_MSG                  (DEBUG_SYSTEM & 0)
#define IS_DEBUG_DMPR_ERROR                (DEBUG_SYSTEM & 1)

/* MP3 debug.  */
#define IS_DEBUG_MP3_EVENT                 (DEBUG_SYSTEM & 0)
#define IS_DEBUG_MP3_ERROR                 (DEBUG_SYSTEM & 1)

/* Media debug */
#define IS_DEBUG_MEDIA_EVENT               (DEBUG_SYSTEM & 0)
#define IS_DEBUG_MEDIA_ERROR               (DEBUG_SYSTEM & 1)
#define IS_DEBUG_MEDIA_PROFILE             (DEBUG_SYSTEM & 0)

/* DTCP debug */
#define IS_DEBUG_DTCP_INPUT                (DEBUG_SYSTEM & 1)
#define IS_DEBUG_DTCP_ERROR                (DEBUG_SYSTEM & 1)
#define IS_DEBUG_DTCP_DEBUG                (DEBUG_SYSTEM & 0)
#define IS_DEBUG_DTCP_DETAIL_DEBUG         (DEBUG_SYSTEM & 0)

/*+UP+ with DTCP Move*/
#define IS_DEBUG_UPLOAD_DTCP_MV_DEBUG      (DEBUG_SYSTEM & 1)
#define IS_DEBUG_UPLOAD_DTCP_MV_ERROR      (DEBUG_SYSTEM & 1)

/* AKE */
#define IS_DEBUG_AKE_DEBUG                 (DEBUG_SYSTEM & 0)
#define IS_DEBUG_AKE_EVENT                 (DEBUG_SYSTEM & 1)
#define IS_DEBUG_AKE_ERROR                 (DEBUG_SYSTEM & 1)

/* Dlna Item Manager */
#define IS_DEBUG_ITEMMGR_DEBUG             (DEBUG_SYSTEM & 0)
#define IS_DEBUG_ITEMMGR_ERROR             (DEBUG_SYSTEM & 0)

/* HDRL */
#define IS_DEBUG_DUMP_INPUT_STREAM         (DEBUG_SYSTEM & 0)
#define IS_DEBUG_HDRL_DEBUG                (DEBUG_SYSTEM & 0)
#define IS_DEBUG_HDRL_API                  (DEBUG_SYSTEM & 0)

/* XSRS */
#define IS_DEBUG_XSRS                      (DEBUG_SYSTEM & 1)

/* SPRL */
#define IS_DEBUG_SPRL_API                  (DEBUG_SYSTEM & 0)

#ifdef DLNA_SUPPORT_RUIPL
#define IS_DEBUG_RUI_EVENT                 (DEBUG_SYSTEM & 1)
#define IS_DEBUG_RUI_ERROR                 (DEBUG_SYSTEM & 1)
#define IS_DEBUG_RUI_NOTIFY_EVENT          (DEBUG_SYSTEM & 0)
#define IS_DEBUG_RUI_NOTIFY_PACKET         (DEBUG_SYSTEM & 0)
#define IS_DEBUG_RUI_NOTIFY_ERROR          (DEBUG_SYSTEM & 1)
#endif /* DLNA_SUPPORT_RUIPL */

#ifdef DLNA_SUPPORT_RUISRC
#define IS_DEBUG_RUISRC_VERBOSE            (DEBUG_SYSTEM & 0)
#define IS_DEBUG_RUISRC_EVENT              (DEBUG_SYSTEM & 0)
#define IS_DEBUG_RUISRC_ERROR              (DEBUG_SYSTEM & 1)
#endif /* DLNA_SUPPORT_RUISRC */


#define IS_DEBUG_WEBUI_SRV_VERBOSE         (DEBUG_SYSTEM & 0)
#define IS_DEBUG_WEBUI_SRV_EVENT           (DEBUG_SYSTEM & 0)
#define IS_DEBUG_WEBUI_SRV_ERROR           (DEBUG_SYSTEM & 1)

/* +UP+ */
#define IS_DEBUG_UPLOAD_DEBUG              (DEBUG_SYSTEM & 1)
#define IS_DEBUG_UPLOAD_ERROR              (DEBUG_SYSTEM & 1)
#define IS_DEBUG_UPLOAD_API                (DEBUG_SYSTEM & 0)

/* +Content Sync+ */
#define IS_DEBUG_CSYNC_API                 (DEBUG_SYSTEM & 0)
#define IS_DEBUG_CSYNC_MSG                 (DEBUG_SYSTEM & 0)
#define IS_DEBUG_CSYNC_MSG_VERBOSE         (DEBUG_SYSTEM & 0)
#define IS_DEBUG_CSYNC_EVENT               (DEBUG_SYSTEM & 0)
#define IS_DEBUG_CSYNC_ERROR               (DEBUG_SYSTEM & 1)
#define IS_DEBUG_CSYNC_DB_MSG              (DEBUG_SYSTEM & 0)
#define IS_DEBUG_CSYNC_DB_ERROR            (DEBUG_SYSTEM & 1)


/* AVI */
#define IS_DEBUG_AVI_EVENT                 (DEBUG_SYSTEM & 0)
#define IS_DEBUG_AVI_ERROR                 (DEBUG_SYSTEM & 1)

#ifdef DLNA_DMS_SUPPORT_AC3
/* AC-3 */
#define IS_DEBUG_AC3_EVENT                 (DEBUG_SYSTEM & 0)
#define IS_DEBUG_AC3_ERROR                 (DEBUG_SYSTEM & 1)
#endif /* DLNA_DMS_SUPPORT_AC3 */

/* Ogg Vorbis */
#define IS_DEBUG_OV_EVENT                  (DEBUG_SYSTEM & 0)
#define IS_DEBUG_OV_ERROR                  (DEBUG_SYSTEM & 1)

/* TIFF */
#define IS_DEBUG_TIFF_EVENT                (DEBUG_SYSTEM & 0)
#define IS_DEBUG_TIFF_ERROR                (DEBUG_SYSTEM & 1)

/* FLV */
#define IS_DEBUG_FLV_EVENT                 (DEBUG_SYSTEM & 0)
#define IS_DEBUG_FLV_ERROR                 (DEBUG_SYSTEM & 1)

/* QuickTime */
#define IS_DEBUG_QT_EVENT                  (DEBUG_SYSTEM & 0)
#define IS_DEBUG_QT_ERROR                  (DEBUG_SYSTEM & 1)

/* ATRAC3 */
#define IS_DEBUG_ATRAC_EVENT               (DEBUG_SYSTEM & 0)
#define IS_DEBUG_ATRAC_ERROR               (DEBUG_SYSTEM & 1)

#define IS_DEBUG_STORAGE_MGR_MSG           (DEBUG_SYSTEM & 0)
#define IS_DEBUG_STORAGE_MGR_EVENT         (DEBUG_SYSTEM & 0)
#define IS_DEBUG_STORAGE_MGR_ERROR         (DEBUG_SYSTEM & 1)

#define IS_DEBUG_TIMEVAL_MSG               (DEBUG_SYSTEM & 1)
#define IS_DEBUG_TIMEVAL_ERROR             (DEBUG_SYSTEM & 1)
#define IS_DEBUG_TIMEVAL_VALUE             (DEBUG_SYSTEM & 0)

#define IS_DEBUG_NFLC_DB_IF_ERROR          (DEBUG_SYSTEM & 1)
/*SRS*/
#ifdef DLNA_SUPPORT_SRS
#define IS_DEBUG_SRS_MSG                   (DEBUG_SYSTEM & 0)
#define IS_DEBUG_SRS_ERROR                 (DEBUG_SYSTEM & 1)
#endif /*DLNA_SUPPORT_SRS*/

/* Database peer call debug.  */
#define IS_DEBUG_PEER_DATABASE_MSG         (DEBUG_SYSTEM & 0)
#define IS_DEBUG_PEER_DATABASE_FUNC        (DEBUG_SYSTEM & 0)
#define IS_DEBUG_PEER_DATABASE_ERROR       (DEBUG_SYSTEM & 1)

#define IS_DEBUG_CDS_DATABASE_MSG          (DEBUG_SYSTEM & 0)
#define IS_DEBUG_CDS_DATABASE_ERROR        (DEBUG_SYSTEM & 1)
#define IS_DEBUG_CDS_INFO                  1                  /* exception. it is used for debug message that is not affected from 'DEBUG_SYSTEM'. */

/* Threading debug */
#define IS_DEBUG_THREAD_PEER_MEMORY        (DEBUG_SYSTEM & 0)
#define IS_DEBUG_THREAD_PEER_EVENT         (DEBUG_SYSTEM & 0)
#define IS_DEBUG_THREAD_PEER_SCHEDULING    (DEBUG_SYSTEM & 0)
#define IS_DEBUG_THREAD_PEER_ERROR         (DEBUG_SYSTEM & 1)

#define IS_DEBUG_MPE_MESSAGE               (DEBUG_SYSTEM & 0)
#define IS_DEBUG_MPE_MESSAGE_GPS           (DEBUG_SYSTEM & 0)
#define IS_DEBUG_MPE_ERROR                 (DEBUG_SYSTEM & 1)

#define IS_DEBUG_EXIF_VERBOSE              (DEBUG_SYSTEM & 0)
#define IS_DEBUG_EXIF_EVENT                (DEBUG_SYSTEM & 0)
#define IS_DEBUG_EXIF_ERROR                (DEBUG_SYSTEM & 1)

/* Transcoding related debug */
#define IS_DEBUG_TRANSCODING_MSG           (DEBUG_SYSTEM & 0)
#define IS_DEBUG_TRANSCODING_ERROR         (DEBUG_SYSTEM & 1)

#define IS_DEBUG_PUBLISH_CONTENT_ERROR     (DEBUG_SYSTEM & 1)
#define IS_DEBUG_PUBLISH_CONTENT_MSG       (DEBUG_SYSTEM & 0)

#ifdef DEVELOPMENT_DLNA_SUPPORT_HNSO
#define IS_DEBUG_HNSO_VERBOSE              (DEBUG_SYSTEM & 1)
#define IS_DEBUG_HNSO_EVENT                (DEBUG_SYSTEM & 1)
#define IS_DEBUG_HNSO_ERROR                (DEBUG_SYSTEM & 1)
#endif /* DEVELOPMENT_DLNA_SUPPORT_HNSO */

#ifdef DLNA_SUPPORT_SATIP
#define IS_DEBUG_SATIP_EVENT               (DEBUG_SYSTEM & 0)
#define IS_DEBUG_SATIP_MSG                 (DEBUG_SYSTEM & 0)
#define IS_DEBUG_SATIP_ERROR               (DEBUG_SYSTEM & 1)
#endif /* DLNA_SUPPORT_SATIP */

#define IS_DEBUG_MPE_COMMAND 1

#define IS_DEBUG_SCHEDULING_ORDER    1
#define IS_DEBUG_SCHEDULING_ERROR    1

#endif /* NFLC_DLNA_DEBUG_H */
