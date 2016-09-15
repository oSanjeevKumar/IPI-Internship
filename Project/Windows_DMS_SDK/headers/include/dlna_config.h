/*
 * dlna_config.h
 * Copyright (C) 2007-2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef _DLNA_CONFIG_H
#define _DLNA_CONFIG_H

/*
 * Include real slim/slim.h.
 */
#define USE_SLIM_LIB

#ifdef USE_SLIM_LIB
/*
 * If use slim i18n library, define this.
 * Otherwise use peer.
 */
# define USE_SLIM_I18N
/*
 * Default language set
 */
# define DLNA_DEFAULT_LANGSET DLNA_I18N_LANGSET_JAPANESE
#endif /* USE_SLIM_LIB */

#ifdef HAVE_DMS
/* DMS Configurations */
#define DEVELOPMENT_CONTENT_AGGREGATION
#define DLNA_NOT_SUPPORT_PLAYER_API
#define HAVE_CDS
#define ENABLE_DMS_RUNTIME_CONFIGURATION
#define DLNA_SUPPORT_XMMRR
#define ENABLE_STORAGE_LISTING
#define ENABLE_CDS_1_0_CONTAINER_UPDATE_IDS
#define ENABLE_DCN_INOTIFY
#define DEVELOPMENT_DATABASE_CHECKPOINT_TRIGGER_VIA_ACCESS_CONF
#define DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION
#define DEVELOPMENT_ENABLE_FOLDER_BROWSE_OPTIMIZATIONS
#define DEVELOPMENT_ENABLE_INDEXING_OF_SHARES
#define DEVELOPMENT_ENABLE_RECURSIVE_TRIGGERS
#define ENABLE_DMS_INDEXING_CALLBACK_ON_CHANGE
#define DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION_SONY_BRAVIA_PROFILING

/* DMS Features */
#define DLNA_SUPPORT_UPLOADER
#ifdef DLNA_SUPPORT_UPLOADER
#define DLNA_DMS_SUPPORT_UPLOAD
#endif /* DLNA_SUPPORT_UPLOADER */
#define ENABLE_THUMBNAIL
#undef DEVELOPMENT_ENABLE_JPEG_SM
#define ENABLE_SUBTITLE_SUPPORT
#define ENABLE_SMART_MEDIA_MANAGER

#ifdef ENABLE_SMART_MEDIA_MANAGER
#define ENABLE_PARENTAL_GUIDANCE
//#define ENABLE_PARENTAL_GUIDANCE_LOCATION_URL_SUPPORT
#define DEVELOPMENT_ENABLE_VIRTUAL_PLAYLISTS
#endif /* ENABLE_SMART_MEDIA_MANAGER */

#undef ENABLE_PLAYLIST_SUPPORT
#ifndef ENABLE_PLAYLIST_SUPPORT
#define DEVELOPMENT_ENABLE_PLAYLIST_AUTOGENERATE
#define DEVELOPMENT_ENABLE_PLAYLIST_CONTAINER
#define DEVELOPEMENT_WINDOWS_PLAYLISTS
#endif /*ENABLE_PLAYLIST_SUPPORT*/

# define DMS_CDS_MAX_REQUESTED_COUNT    (250)
# define NFLC_OLD_API_COMPATIBLE
# define DLNA_DMS_SUPPORT_AVI

# ifdef DLNA_DMS_SUPPORT_AVI
#  define AVI_DETECT_DIVX
/* DMS: Use anal_riff,info_avi to support WAV. */
#  define DLNA_DMS_WAV_USE_INFO_AVI
# endif /* DLNA_DMS_SUPPORT_AVI */

# define DLNA_SUPPORT_MP4_AUDIO

/* NFLC-3.1 Compliant dependency >>>>>> START */
#define DMS_JPEG_MED_PATH       "\\jpeg_med"
/* NFLC-3.1 Compliant dependency >>>>>> END */

#define DMS_JPEG_LRG_PATH       "\\jpeg_lrg"

#endif /* HAVE_DMS */

#ifdef HAVE_DMR

#define ENABLE_DMR_RUNTIME_CONFIGURATION
#define DEVELOPMENT_ENABLE_DMR_RUNTIME_CONFIGURATION 

#endif /* HAVE_DMR */

#ifdef HAVE_DMC

# define DLNA_NOT_SUPPORT_PLAYER_API
//# define DLNA_SUPPORT_RUI
# define DLNA_SUPPORT_UPLOADER
# define DLNA_SUPPORT_DOWNLOADER
# define DLNA_SUPPORT_DOWNLOADER_PEER
# define DLNA_SINK_PROTOCOL_INFO_XML			"sink_proto_info.xml"
# define PAL_CONTENTS_PATH_DOWNLOAD				"C:\\nflc\\downloads"

#endif /* HAVE_DMC */

#ifdef DLNA_SUPPORT_RUIPL

//# define DEVELOPMENT_DLNA_SUPPORT_RUIPL
#define RUI_CLIENT_CAPABILITY_XML				"client_capability.xml"

#endif /* DLNA_SUPPORT_RUIPL */
# define LOG_FILE_NAME        SLIM_T("coreLog.txt")

#define PAL_CONTENTS_ICON_JPEG_FILE             "DMS-defaultTN.jpg"
#define PAL_CONTENTS_DEFAULT_PICTURE_TN         "picture_normal.jpg"
#define PAL_CONTENTS_DEFAULT_MUSIC_TN           "music_normal.jpg"
#define PAL_CONTENTS_DEFAULT_VIDEO_TN           "video_normal.jpg"
#define PAL_CONTENTS_DEFAULT_PICTURE_MED        "picture_large.jpg"
#define PAL_CONTENTS_DEFAULT_MUSIC_MED          "music_large.jpg"
#define PAL_CONTENTS_DEFAULT_VIDEO_MED          "video_large.jpg"
#define PAL_CONTENTS_TEMP_ALBUM_ART             "DMS-TempAlbumArt.jpg"

#define DMS_THUMBNAIL_PATH      				"\\thumbnails"
#define DMS_JPEG_SM_PATH						    "\\jpeg_sm"

#define DMS_STORAGE_DATA_DIR          ".nflc_data"
#define DMS_CA_DATA_DIR               ".contentaggregation"
#define DMS_TRANSCODED_PATH 					DMS_STORAGE_DATA_DIR""PATH_SEPARATOR"transcoded"


#define DMS_WINDOWS_XML					"nflc_xml\\"
#define DMS_IGNORE_WINDOWS_FOUND_FOLDER "FOUND."

#define DMS_STORAGE_DATABASE_FILENAME			"nflc_database"
#define DMS_STORAGE_UUID_FILENAME				"uuid.dat"

/* SMM: Upload file path. */
#define PAL_CONTENTS_PATH_UPLOAD				"\\upload"
#define PAL_CONTENTS_DEF_ALBUM_ART_PREFIX		"_album_art"

#define NFLC_SSDP_UNICAST_PORT (0)
#define NFLC_GENA_PORT (13000)
/*
 * HTTP SERVER/USER-AGENT value.
 *
 * Format should be "OS/Version UPnP/1.0 product/version" as defined
 * in UPnP Device Architecture 1.0.
 */
#define PAL_USER_AGENT_STR						"MS-Windows ACCESSTWINE/1.0 UPnP/1.0 DLNADOC/1.50"

#if defined(HAVE_DMP) && !defined(HAVE_XDMR)
#define PAL_FRIENDLY_NAME_STR "ACCESSTWINE/1.0-DMP"
#endif /*HAVE_DMP && !HAVE_XDMR*/
#if defined(HAVE_DMC) && !defined(HAVE_DMR)
#define PAL_FRIENDLY_NAME_STR "ACCESSTWINE/1.0-DMC"
#endif /*HAVE_DMC && !HAVE_DMR*/
#ifdef HAVE_DMPR
#define PAL_FRIENDLY_NAME_STR "ACCESS_NFLC/3.1-DMPr"
#endif /*HAVE_DMPR*/

#if defined(HAVE_DMR) && !defined(HAVE_DMC) && !defined(HAVE_XDMR)
#define PAL_FRIENDLY_NAME_STR "ACCESSTWINE/1.0-DMR"
#endif /*HAVE_DMR && !HAVE_DMC && !HAVE_XDMR*/
#if defined(HAVE_DMR) && defined(HAVE_DMC) && !defined(HAVE_XDMR)
#define PAL_FRIENDLY_NAME_STR "ACCESSTWINE/1.0-XDMR"
#endif /*HAVE_DMR && !HAVE_DMC && !HAVE_XDMR*/
#ifdef HAVE_XDMR
#define PAL_FRIENDLY_NAME_STR "ACCESSTWINE/1.0-XDMR"
#endif /* HAVE XDMR */
#ifdef HAVE_DMS
#define PAL_FRIENDLY_NAME_STR "ACCESSTWINE/1.0-DMS"
#endif /*HAVE_DMS*/
#ifdef DLNA_SUPPORT_SATIP
#define PAL_FRIENDLY_NAME_STR "ACCESSTWINE/1.0-SATIP"
#endif /*DLNA_SUPPORT_SATIP*/

/* DMS root directory of contents files. */
# define PAL_DMS_DIR			".\\DMS"
# define PAL_DMS_ROOT_DIR		".\\DMS\\media"
/* DMS configuration directory (which will store XML files). */
# define PAL_DMS_CONFIG_DIR		".\\nflc_xml"
# define PAL_DMS_DATA_DIR		".\\DMS\\data"

/* Lowest possible DMS UPnP port number. */
#define PAL_DMS_UPNP_PORT_MIN	(2869)

#ifdef ENABLE_DMS_RUNTIME_CONFIGURATION
#define PAL_DMS_DESCRIPTION_FILE_NAME	"dms_descr.xml"
#else
#define PAL_DMS_DESCRIPTION_FILE_NAME  "dms.xml"
#endif /* ENABLE_DMS_RUNTIME_CONFIGURATION */

# define PAL_DMR_CONFIG_DIR		".\\dlna\\xml"
# define PAL_DMC_CONFIG_DIR		".\\dlna\\xml"
# define LOG_MODULES_FILENAME "log.xml"

// Have to be reviewed and prepared correctly - now it is dummy
#ifdef ENABLE_DMR_RUNTIME_CONFIGURATION
# define PAL_DMR_DESCRIPTION_FILE_NAME	"dmr_desc.xml"
# define DLNA_SINK_PROTOCOL_INFO_XML	"sink_proto_info.xml"
#else /* ENABLE_DMR_RUNTIME_CONFIGURATION */
# define PAL_DMR_DESCRIPTION_FILE_NAME	"dmr.xml"
#endif /* ENABLE_DMR_RUNTIME_CONFIGURATION */

/* DMR UPnP port. */
#define PAL_DMR_UPNP_PORT_MIN	2870

/* Highest possible DMS UPnP port number. */
#define PAL_UPNP_PORT_MAX		(60000)

#define DMS_VIRTUAL_FOLDERS_LIST_FILE_NAME	"virtual_folders_list.xml"
#define DMS_NAMES_FILENAME					"names.xml"
#define DMS_ACCESS_CONF_FILE_NAME			"access_conf.xml"
#define DMS_STORAGE_LIST_FILE_NAME      	"storage_list.xml"

/* SMM: Write DMS application version string on each usb device to identify DMS version */
#define DMS_VERSION				"1.10.x (merge)"
#define DMS_VERSION_FILENAME	"version.txt"

/* SMM: Parental Guidance */
#ifdef ENABLE_PARENTAL_GUIDANCE
# define DMS_PARENTAL_GUIDANCE_FILE_PATH			PAL_DMS_CONFIG_DIR
# define DMS_PARENTAL_CONTROL_DEVICES_LIST_FILE	"pg_device_list.xml"
# define DMS_PARENTAL_GUIDANCE_LEVEL_LIST_FILE	"pg_level_list.xml"
# define DEFAULT_PARENTAL_GUIDANCE_DEVICE_LEVEL	1
# define DEFAULT_PARENTAL_GUIDANCE_CONTENT_LEVEL	1
#endif /* ENABLE_PARENTAL_GUIDANCE */

/* Default SSDP mx value.  */
#define DLNA_SSDP_DEFAULT_MX   (5)

/* HTTP_READ_BUFFER_SIZE */
#define DLNA_HTTP_READ_BUFFER_SIZE       (1024*1024)

/* HTTP_WRITE_BUFFER_SIZE */
#define DLNA_HTTP_WRITE_BUFFER_SIZE      (1024*1024)

/* Buffer size for media transport. */
#define DLNA_HTTP_LARGE_FILE_SIZE         (20 * 1024 * 1024)
#define DLNA_HTTP_LARGE_BUFFER_SIZE       (256 * 1024)

/* Ring buffer number threshold.  */
#define DLNA_HTTP_RING_BUFFER_THRESHOLD      (DLNA_HTTP_READ_BUFFER_SIZE * 6)

/* Buffer size for SOAP action. */
#define DLNA_HTTP_MSG_BUFFER_SIZE       (8 * 1024)

/* UPLOADER_TOLERANCE_TIMES_OF_HTTP_TIMEOUT indicates the times of tolerance when   */
/* http timeout during uploading operation.                                         */
/* The range of UPLOADER_TOLERANCE_TIMES_OF_HTTP_TIMEOUT is following:              */
/* 1) negative: show that +UP+ module don't restrict the times of http timeout      */
/*              during uploading operation;                                         */
/* 2) positive number or 0: show the tolerance times of http timeout during         */
/*                          uploading operation.                                    */
#ifdef DLNA_SUPPORT_UPLOADER
# define UPLOADER_TOLERANCE_TIMES_OF_HTTP_TIMEOUT -1
#endif /* DLNA_SUPPORT_UPLOADER */

/*   Requirement [7.3.118.4]: The @dlna:dlnaManaged attribute is a 32-bit unsigned integer
 * encoded into exactly 8 hexadecimal digits, with the following bit definitions. Bit-0 is
 * the least significant bit. If a bit supports a particular operation, then the bit value is
 * true. Otherwise, the bit value is false to indicate the operation is not supported. (e.g.
 * 00000000000000000000000000000001b = 0x00000001 where bit-0 is set to true)
 * The hexadecimal encoded form must consist only of hexadecimal digits. The value
 * must omit the "0x" string that often precedes hexadecimal notation.
 *   1.Bit-0: indicates support for OCM: upload content
 *      1)If true then the MediaServer allows a control point to create child CDS items in the
 *       container for the OCM: upload content operation.
 *      2)Must be false when used with a CDS item.
 *   2.Bit-1: indicates support for OCM: create child container
 *      1) If true on a CDS container, then the MediaServer allows a control point to create
 *       child CDS containers that can support the OCM: upload content.
 *      2) Must be false when used with a CDS item.
 *   3. Bit-2: indicates support for OCM: destroy item
 *      1) If true on a CDS item, then it means the CDS item must be removed from the CDS
 *        hierarchy when the CDS object is successfully destroyed through an OCM: destroy
 *        item request.
 *      2) Must be false when used with a CDS container.
 *   4. All other bits must be false. All other bits are reserved for future use.
 */
#define DLNA_CDS_SUPPORT_OCM

#ifdef DLNA_CDS_SUPPORT_OCM
# define DLNA_CDS_CONTAINER_SUPPORT_OCM		(00000003)
# define DLNA_CDS_ITEM_SUPPORT_OCM		(00000004)
#endif /* DLNA_CDS_SUPPORT_OCM */

/* debug mode */
#include <peer_debug.h>

/*
 * Peer debug related macroes.
 */
#define PEER_DP(arg) slimDebugPrintfPeer arg
#define PEER_ASSERT(test) ((test) ? (void)0 : dlnaDebugPrintfPeer("Assert Failed: %s : %s,%d\n", #test, __FILE__, __LINE__))
#define PEER_ASSERT_MSG(test,msg) ((test) ? (void)0 : dlnaDebugPrintfPeer("Assert Failed: %s %s : %s,%d\n", (msg), #test, __FILE__, __LINE__))
#define PEER_ASSERT_TYPE(var,type) PEER_ASSERT_MSG(sizeof(var) == sizeof(type), "Type mismatch.")

#define USE_TIME_SEEK

/************************************************/
#endif /* _DLNA_CONFIG_H */
