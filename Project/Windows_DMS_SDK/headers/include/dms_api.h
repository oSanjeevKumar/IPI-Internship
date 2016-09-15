/*
 * dms_api.h
 * Copyright (C) 2009-2014 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_DMS_API_H
#define NFLC_DMS_API_H

#include <dlna_peer.h>
#ifdef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
#include <dms_publish_api.h>
#endif /*DEVELOPMENT_ENABLE_PUBLISH_CONTENT*/
#include <nflc_drm_api.h>
#include <nflc_upnp_api.h>

#ifdef HAVE_DTCP
#include <dtcp_base.h>
#endif

/* DMS types.  */

/**
 * @addtogroup DataTypes
 */
/*@{*/
/*!
TDMS is a DMS library instance.

DMS applications must not access the TDMS.
*/
typedef void * TDMS;
/*@}*/

#define DMS_ENABLED             1
#define DMS_DISABLED            0

#define DMS_CA_ENABLED          1
#define DMS_CA_DISABLED         0

/**
 * @addtogroup Enumerators
 */
/*@{*/
/*!
TDMSReturn is the DMS API return value type.

In the DMS API, the values described in the table below are used as processing results.

<table>
        <tr>
                <td><b>Definition</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>DMS_SUCCESS</td>
                <td>Succeeded</td>
        </tr>
        <tr>
                <td>DMS_GENERIC_ERROR</td>
                <td>Generic error occurred</td>
        </tr>
        <tr>
                <td>DMS_INVALID_PARAM</td>
                <td>Invalid parameter</td>
        </tr>
        <tr>
                <td>DMS_INVALID_ACTION</td>
                <td>Invalid action</td>
        </tr>
        <tr>
                <td>DMS_INVALID_DESC</td>
                <td>Invalid DMS configuration XML file description</td>
        </tr>
        <tr>
                <td>DMS_OUT_OF_MEMORY</td>
                <td>Insufficient memory</td>
        </tr>
        <tr>
                <td>DMS_SOCKET_ERROR</td>
                <td>Socket creation error</td>
        </tr>
        <tr>
                <td>DMS_INIT_FAILED</td>
                <td>Initialization error</td>
        </tr>
        <tr>
                <td>DMS_WOULDBLOCK</td>
                <td>Defer content access permission response</td>
        </tr>
        <tr>
                <td>DMS_ACCESS_ACCEPT</td>
                <td>Allow content access immediately</td>
        </tr>
        <tr>
                <td>DMS_ACCESS_DENY</td>
                <td>Deny content access immediately</td>
        </tr>
        <tr>
                <td>DMS_FILE_NOT_EXIST</td>
                <td>File does not exist.</td>
        </tr>
        <tr>
                <td>DMS_STORAGE_PUBLISH_STORAGE_EXISTS</td>
                <td>Published Storage already exists</td>
        </tr>
        <tr>
                <td>DMS_STORAGE_PUBLISH_STORAGE_ID_CONFLICT</td>
                <td>Published Storage id is already in use</td>
        </tr>
        <tr>
                <td>DMS_STORAGE_PUBLISH_STORAGE_DUPLICATE_NAME</td>
                <td>Published Storage name is duplicated</td>
        </tr>
        <tr>
                <td>DMS_STORAGE_PUBLISH_ALREADY_ON_EXISTING_STORAGE</td>
                <td>Published Storage already Published</td>
        </tr>
        <tr>
                <td>DMS_STORAGE_PUBLISH_SUBFOLDER_ALREADY_ADDED_AS_STORAGE</td>
                <td>Published Storage Subfolder already added</td>
        </tr>
        <tr>
                <td>DMS_STORAGE_PUBLISH_STORAGE_BUSY</td>
                <td>Published Storage is busy.</td>
        </tr>
        <tr>
                <td>DMS_PUBLISH_VIRTUAL_CONTAINER_EXISTS</td>
                <td>Virtual Container already added</td>
        </tr>
        <tr>
                <td>DMS_PUBLISH_STREAMING_CONTENT_EXISTS</td>
                <td>Virtual Container already added</td>
        </tr>
</table>
*/
typedef slim_int TDMSReturn;
/*@}*/
enum {
  DMS_GENERIC_ERROR = UPNP_GENERIC_ERROR,
  DMS_SUCCESS = UPNP_SUCCESS,
  DMS_INVALID_PARAM = UPNP_INVALID_PARAM,
  DMS_INVALID_ACTION = UPNP_INVALID_ACTION,
  DMS_INVALID_DESC = UPNP_INVALID_DESC,
  DMS_OUT_OF_MEMORY = UPNP_OUT_OF_MEMORY,
  DMS_SOCKET_ERROR = UPNP_SOCKET_ERROR,
  DMS_INIT_FAILED = UPNP_INIT_FAILED,
  DMS_WOULDBLOCK = UPNP_WOULDBLOCK,
  DMS_ACCESS_ACCEPT = UPNP_ACCESS_ACCEPT,
  DMS_ACCESS_DENY = UPNP_ACCESS_DENY,
  DMS_FILE_NOT_EXIST = UPNP_FILE_NOT_EXIST,
  DMS_STORAGE_PUBLISH_STORAGE_EXISTS,
  DMS_STORAGE_PUBLISH_STORAGE_NOT_EXISTS = UPNP_STORAGE_NOT_EXISTS,
  DMS_STORAGE_PUBLISH_STORAGE_ID_CONFLICT,
  DMS_STORAGE_PUBLISH_STORAGE_DUPLICATE_NAME,
  DMS_STORAGE_PUBLISH_STORAGE_BUSY,
  DMS_STORAGE_PUBLISH_ALREADY_ON_EXISTING_STORAGE,
  DMS_STORAGE_PUBLISH_SUBFOLDER_ALREADY_ADDED_AS_STORAGE,
  DMS_PUBLISH_VIRTUAL_CONTAINER_EXISTS,
  DMS_PUBLISH_STREAMING_CONTENT_EXISTS,
  DMS_STORAGE_PUBLISH_STORAGE_NOT_WRITABLE,
  DMS_STORAGE_PUBLISH_STORAGE_NOT_A_FOLDER,
  DMS_STORAGE_PUBLISH_STORAGE_NOT_A_FILE,
  DMS_STORAGE_PUBLISH_INVALID_STORAGE,
  DMS_STORAGE_PUBLISH_LIMIT_REACHED
};

typedef enum dmsEvent_ {
  DMS_EVENT_INDEXING_STATE          = 0x01,
  DMS_EVENT_PARTIAL_INDEXING_STATE  = 0x02,
  DMS_EVENT_CA_STATE                = 0x04,
  DMS_EVENT_DMS_STATE               = 0x08,
  DMS_EVENT_DEVICE_LIST_CHANGE      = 0x10,
} dmsEvent;

/**
 * @addtogroup Enumerators
 */
/*@{*/
/*!
TDMSContentIndexingState is used to obtain the current indexing state.
<table>
  <tr>
    <td><b>Definition</b></td>
    <td><b>Description</b></td>
  </tr>
  <tr>
    <td>DMS_CONTENT_INDEXING_STATE_INDEXING</td>
    <td>Indexing is Still in Progress(*)</td>
  </tr>
  <tr>
    <td>DMS_CONTENT_INDEXING_STATE_METADATA</td>
    <td>Indexing for metadata is Finished(*)</td>
  </tr>
  <tr>
    <td>DMS_CONTENT_INDEXING_STATE_THUMBNAIL</td>
    <td>Indexing for reference is Finished(*)</td>
  </tr>
  <tr>
    <td>DMS_CONTENT_INDEXING_STATE_DONE</td>
    <td>Indexing is Finished(*)</td>
  </tr>
  <tr>
    <td>DMS_CONTENT_INDEXING_STATE_ABORTED</td>
    <td>Indexing is Aborted(*)</td>
  </tr>
  <tr>
    <td>DMS_CONTENT_INDEXING_STATE_UNKNOWN</td>
    <td>Indexing State is unknown(*)</td>
  </tr>
</table>
*/
typedef slim_int TDMSContentIndexingState;
/*@}*/

typedef enum dmsContentIndexingState_ {
  DMS_CONTENT_INDEXING_STATE_STARTED,
  DMS_CONTENT_INDEXING_STATE_DONE,
  DMS_CONTENT_INDEXING_STATE_ABORTED,
  DMS_CONTENT_INDEXING_STATE_UNKNOWN
} dmsContentIndexingState;

typedef enum dmsContentIndexingLevel_ {
  DMS_CONTENT_INDEXING_LEVEL_FILESCAN,
  DMS_CONTENT_INDEXING_LEVEL_METADATA,
  DMS_CONTENT_INDEXING_LEVEL_REFERENCES,
  DMS_CONTENT_INDEXING_LEVEL_UNKNOWN
} dmsContentIndexingLevel;

typedef enum dmsContentIndexingError_ {
  DMS_CDS_INDEXING_OK = 0,
  DMS_CDS_INDEXING_ERROR_GENERIC,
  DMS_CDS_INDEXING_ERROR_CANCEL,
  DMS_CDS_INDEXING_ERROR_DATABASE,
  DMS_CDS_INDEXING_ERROR_OUT_OF_MEMORY,
} dmsContentIndexingError;

typedef enum dmsContentPartialIndexingMode_ {
  DMS_CONTENT_PARTIAL_INDEXING_SHARE,
  DMS_CONTENT_PARTIAL_INDEXING_PG,
  DMS_CONTENT_PARTIAL_INDEXING_UNKNOWN
} dmsContentPartialIndexingMode;

struct _TDMSIndexingStateParam{
  TDMS self;
  dmsContentIndexingLevel level;
  dmsContentIndexingState state;
  slim_int errorCode;
  slim_char* storagePath;
};

typedef struct _TDMSIndexingStateParam TDMSIndexingStateParam;

struct _TDMSPartialIndexingStateParam{
  TDMS self;
  dmsContentPartialIndexingMode mode;
  dmsContentIndexingState state;
  slim_int errorCode;
  slim_char* contentId;
};

typedef struct _TDMSPartialIndexingStateParam TDMSPartialIndexingStateParam;

typedef enum dmsState_{
  DMS_STATE_DISABLE = DMS_DISABLED, //dms is disabled
  DMS_STATE_ENABLE = DMS_ENABLED    //dms is enbled
} dmsState;


/**
 * @addtogroup Enumerators
 */
/*@{*/
/*!
TDMSCAIndexingState is used to obtain the current CA indexing state.
<table>
  <tr>
    <td><b>Definition</b></td>
    <td><b>Description</b></td>
  </tr>
  <tr>
    <td>DMS_CA_STATE_DISABLED</td>
    <td>CA indexing is Disabled(*)</td>
  </tr>
  <tr>
    <td>DMS_CA_STATE_IDLE</td>
    <td>CA indexing is Waiting(*)</td>
  </tr>
  <tr>
    <td>DMS_CA_STATE_PROCESSING</td>
    <td>CA indexing is Still in Progress(*)</td>
  </tr>
  <tr>
    <td>DMS_CA_STATE_PAUSED</td>
    <td>CA indexing is Paused(*)</td>
  </tr>
  <tr>
    <td>DMS_CA_STATE_STOPPED</td>
    <td>CA indexing is completely Stopped(*)</td>
  </tr>
</table>
*/
typedef slim_int TDMSCAIndexingState;
/*@}*/


/**
 * @addtogroup Enumerators
 */
/*@{*/
/*!
TDMSCAIndexingState is used to obtain the current CA indexing state.
<table>
  <tr>
    <td><b>Definition</b></td>
    <td><b>Description</b></td>
  </tr>
  <tr>
    <td>slim_true</td>
    <td>DMS is ON</td>
  </tr>
  <tr>
    <td>slim_false</td>
    <td>DMS is OFF</td>
  </tr>
</table>
*/
typedef slim_bool TDMSOnOffState;
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/

/*!
\par Function:
Callback function that notifies the DMS CDS Indexing Status.
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_arg</td>
    <td>Pointer to objects specified in dlnaDmsRegisterIndexStateCallback</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_cat</td>
    <td>Category of updated state</td>
  </tr>
  <tr>
  <tr>
    <td>[in]</td>
    <td>in_param</td>
    <td>param for category as specified by in_cat</td>
  </tr>
</table>

\return None
\par Description:
This callback function notifies the DMS Application which registers this callback for various status.\n
For in_cat as
DMS_EVENT_INDEXING_STATE - See section TDMSContentIndexingState for indexing states.
DMS_EVENT_PG_STATE - See section TDMSPGIndexingState for indexing states.
DMS_EVENT_CA_STATE - See section TDMSCAIndexingState for indexing states.
DMS_EVENT_DMS_STATE - See section TDMSOnOffState for DMS ON/OFF state.
*/
typedef void (*TDMSStateCallback) (void *in_arg, slim_int in_cat, void * in_param);

/*!
\par Function:
Notify about the state of various DMS status.
\par Parameters:
<table>
  <tr>
    <td>[in]</td>
    <td>self</td>
    <td>DLNA DMS device instance</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_arg</td>
    <td>Argument specified by dlnaDmsRegisterStateCallback</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_cat</td>
    <td>Category of state change to be notified, bitwise OR-ed flag, 0 to turn off<br/>
        DMS_EVENT_INDEXING_STATE<br/>
        DMS_EVENT_PG_STATE<br/>
        DMS_EVENT_CA_STATE<br/>
        DMS_EVENT_DMS_STATE
    </td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_callback</td>
    <td>Instance of different type of callback</td>
  </tr>
</table>
\return DMS_SUCCESS Succeeded
\return DMS_INVALID_PARAM Invalid parameter
\par Description:
This API shall notify about the state of various DMS state. 
*/
DLNA_API TDMSReturn
dlnaDmsRegisterStateCallback(TDMS self, void *in_arg, slim_int in_cat, TDMSStateCallback in_callback);

/*@}*/

/**
 * @addtogroup Enumerators
 */
/*@{*/

/*!
Available values for dlnaDMSStorageContentRegisterRescanCallback() callback functions
<table>
      <tr>
           <td><b>Definition</b></td>
           <td><b>Description</b></td>
     </tr>
     <tr>
          <td><b>DMS_STORAGE_CONTENT_RESCAN_STARTED</b></td>
          <td><b>Rescan started</b></td>
     </tr>
     <tr>
	  <td><b>DMS_STORAGE_CONTENT_RESCAN_FINISHED</b></td>
          <td><b>Rescan finished</b></td>
    </tr>
    <tr>
        <td><b>DMS_STORAGE_CONTENT_RESCAN_CANCELLED</b></td>
        <td><b>Rescan Canceled</b></td>
    </tr>
    <tr>
        <td><b>DMS_STORAGE_CONTENT_RESCAN_NO_SPACE_ABORTED</b></td>
        <td><b>Rescan Aborted due to not enough space</b></td>
    </tr>
    <tr>
        <td><b>DMS_STORAGE_CONTENT_RESCAN_ERROR</b></td>
        <td><b>Rescan Error</b></td>
    </tr>
</table>
*/
typedef slim_int TDMSRescanState;
/*@}*/


enum {
  DMS_STORAGE_CONTENT_RESCAN_STARTED,
  DMS_STORAGE_CONTENT_RESCAN_FINISHED,
  DMS_STORAGE_CONTENT_RESCAN_CANCELLED,
  DMS_STORAGE_CONTENT_RESCAN_NO_SPACE_ABORTED,
  DMS_STORAGE_CONTENT_RESCAN_ERROR
};

/**
 * @addtogroup Functions
 */
/*@{*/

/*!
\par Function:
Callback function that notifies the DMS CDS Indexing Status.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_action</td>
		<td>Current action notify</td>
	</tr>
</table>

\return None
\par Description:
This callback function notifies the DMS Application which registers this callback for the indexing status.\n
See section TDMSRescanState for different Indexing States.
*/
typedef void (*TDMSStorageContentRescanCallback) (TDMSRescanState in_state);

/*@}*/

#ifndef _DOXYGEN
/* DMS content access parameter structure. */
struct _TDMSContentAccessParam {
  slim_char *mac_address;
  slim_int id;
  slim_char *percent;
  slim_char *current_bytes;
  slim_char *total_bytes;
};
/**
 * @addtogroup Structures
 */
/*@{*/
/*!
TDMSContentAccessParam is the structure used to retain access information for DMS content.
<table>
         <tr>
                <td><b>Member</b></td>
                <td><b>Data Type</b></td>
                <td><b>Description</b></td>
        </tr>
	<tr>
		<td>mac_address</td>
		<td>slim_char</td>
		<td>MAC address of client that requests access</td>
	</tr>
	<tr>
		<td>id</td>
		<td>slim_int</td>
		<td>=> 0	Content ID<br />
			-1	 Target content unknown</td>
	</tr>
	<tr>
		<td>percent</td>
		<td>slim_char</td>
		<td>Rate of progress accessing content (\%)<br />
			Numeric string of "current_bytes / total_bytes * 100" value. Set "\0"<br />
			if Content-Length is not found in HTTP header.</td>
	</tr>
	<tr>
		<td>current_bytes</td>
		<td>slim_char</td>
		<td>Size transferred while accessing content (bytes)<br />
			Numeric string. Always set actual value, regardless of whether<br />
			Content-Length is in HTTP header.</td>
	</tr>
	<tr>
		<td>total_bytes</td>
		<td>slim_char</td>
		<td>Size of total content (bytes)<br />
			Numeric string. Set "\0" if Content-Length is not found in HTTP header.</td>
	</tr>
</table>

*/
//typedef struct _TDMSContentAccessParam TDMSContentAccessParam;
/*@}*/

/**
 * @addtogroup Macros
 */
/*@{*/
/*!
 * NFLC MAC Address String Length
<table>
         <tr>
                <td><b>Member</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>NFLC_MAC_ADDRESS_STR_LEN</td>
                <td>(24) length of the MAC address</td>
        </tr>
 </table>
 */

#define NFLC_MAC_ADDRESS_STR_LEN     (24)
/*@}*/


/**
 * @addtogroup Functions
 */
/*@{*/

/* Event Notification Callback Function. */
/*!
\par Function:
Callback function that notifies the event.
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMS instance</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>doc</td>
                <td>Pointer to the document structure (device description etc)</td>
        </tr>
</table>

\return None
\par Description:
This function notifies the events from the DMS core to the application
*/
typedef slim_int (*TDMSEventCallback) (TDMS self, void *doc);
/*@}*/


enum {
  DMS_CONTENT_ACCESS_EV_OPEN_PLAY = UPNP_CONTENT_ACCESS_OPEN_PLAY, /* play started*/
  DMS_CONTENT_ACCESS_EV_OPEN_DOWNLOAD = UPNP_CONTENT_ACCESS_OPEN_DOWNLOAD, /* download started */
  DMS_CONTENT_ACCESS_EV_OPEN_UPLOAD = UPNP_CONTENT_ACCESS_OPEN_UPLOAD, /* upload started */
  DMS_CONTENT_ACCESS_EV_UPDATE = UPNP_CONTENT_ACCESS_UPDATE, /* processing */
  DMS_CONTENT_ACCESS_EV_CLOSE = UPNP_CONTENT_ACCESS_CLOSE, /* access ended or canceled*/
  DMS_CONTENT_ACCESS_EV_CANCEL = UPNP_CONTENT_ACCESS_CANCEL, /* canceled*/
  DMS_CONTENT_ACCESS_EV_RSPTO_TIMEOUT = UPNP_CONTENT_ACCESS_RSPTO_TIMEOUT, /* timeout */
  DMS_CONTENT_ACCESS_EV_ERROR_COMM = UPNP_CONTENT_ACCESS_ERROR_COMM, /* network error occurred */
  DMS_CONTENT_ACCESS_EV_ERROR_FILE = UPNP_CONTENT_ACCESS_ERROR_FILE, /* file io error occurred */
  DMS_CONTENT_ACCESS_EV_ERROR_ETC = UPNP_CONTENT_ACCESS_ERROR_ETC, /* error occurred */
  DMS_CONTENT_ACCESS_EV_END
};
/**
 * @addtogroup Enumerators
 */
/*@{*/
/*!
TDMSContentAccessEvent represents the type of content access event specified for
TDMSContentAccessCallback() (see "TDMSContentAccessCallback").

<table>
	<tr>
		<td><b>Definition</b></td>
		<td><b>Description</b></td>
	</tr>
	<tr>
		<td>DMS_CONTENT_ACCESS_EV_OPEN_PLAY</td>
		<td>Request to play content</td>
	</tr>
	<tr>
		<td>DMS_CONTENT_ACCESS_EV_OPEN_DOWNLOAD</td>
		<td>Request to download content</td>
	</tr>
	<tr>
		<td>DMS_CONTENT_ACCESS_EV_OPEN_UPLOAD</td>
		<td>Request to upload content</td>
	</tr>
	<tr>
		<td>DMS_CONTENT_ACCESS_EV_UPDATE</td>
		<td>Accessing content</td>
	</tr>
	<tr>
		<td>DMS_CONTENT_ACCESS_EV_CLOSE</td>
		<td>Completed content access</td>
	</tr>
	<tr>
		<td>DMS_CONTENT_ACCESS_EV_CANCEL</td>
		<td>Cancel content access</td>
	</tr>
	<tr>
		<td>DMS_CONTENT_ACCESS_EV_RSPTO_TIMEOUT</td>
		<td>Time out while waiting for content access permission response</td>
	</tr>
	<tr>
		<td>DMS_CONTENT_ACCESS_EV_ERROR_COMM</td>
		<td>Communication error occurred while accessing content</td>
	</tr>
	<tr>
		<td>DMS_CONTENT_ACCESS_EV_ERROR_FILE</td>
		<td>File I/O error occurred while accessing content</td>
	</tr>
	<tr>
		<td>DMS_CONTENT_ACCESS_EV_ERROR_ETC</td>
		<td>Other error occurred while accessing content</td>
	</tr>
</table>
*/
typedef slim_int TDMSContentAccessEvent;
/*@}*/
#endif /* __DOXYGEN__*/

#ifndef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
enum {
  DMS_CONTENTS_TYPE_UNKNOWN = 0,
  DMS_CONTENTS_TYPE_JPEG,
  DMS_CONTENTS_TYPE_PNG,
  DMS_CONTENTS_TYPE_BMP,
  DMS_CONTENTS_TYPE_GIF,
  DMS_CONTENTS_TYPE_LPCM,
  DMS_CONTENTS_TYPE_MP3,
  DMS_CONTENTS_TYPE_ASF,
  DMS_CONTENTS_TYPE_WMA,
  DMS_CONTENTS_TYPE_WMV,
  DMS_CONTENTS_TYPE_WAV,
  DMS_CONTENTS_TYPE_DAB,
  DMS_CONTENTS_TYPE_MPEG2,
  DMS_CONTENTS_TYPE_OV,

  DMS_CONTENTS_TYPE_MPEG2_TS,

  DMS_CONTENTS_TYPE_VC1_ASF,

  /* General types, unknown extensions */
  DMS_CONTENTS_TYPE_ALAW,
  DMS_CONTENTS_TYPE_ASS, /* .ssa, .ass */
  DMS_CONTENTS_TYPE_AVM2,
  DMS_CONTENTS_TYPE_CRC,
  DMS_CONTENTS_TYPE_DAUD,
  DMS_CONTENTS_TYPE_DTS,
  DMS_CONTENTS_TYPE_DVD,
  DMS_CONTENTS_TYPE_EA,
  DMS_CONTENTS_TYPE_EA_CDATA,
  DMS_CONTENTS_TYPE_EAC3,
  DMS_CONTENTS_TYPE_FFM,
  DMS_CONTENTS_TYPE_MULAW,
  DMS_CONTENTS_TYPE_GXF,
  DMS_CONTENTS_TYPE_DNXHD,
  DMS_CONTENTS_TYPE_FILMSTRIP,
  DMS_CONTENTS_TYPE_FRAMECRC,
  DMS_CONTENTS_TYPE_H261,
  DMS_CONTENTS_TYPE_H263,
  DMS_CONTENTS_TYPE_H264,
  DMS_CONTENTS_TYPE_IMAGE2,
  DMS_CONTENTS_TYPE_IMAGE2PIPE,
  DMS_CONTENTS_TYPE_INGENIENT,
  DMS_CONTENTS_TYPE_IPMOVIE,
  DMS_CONTENTS_TYPE_IPOD,
  DMS_CONTENTS_TYPE_MMF,
  DMS_CONTENTS_TYPE_MPJPEG,
  DMS_CONTENTS_TYPE_MXF_D10,
  DMS_CONTENTS_TYPE_NUT,
  DMS_CONTENTS_TYPE_OSS,
  DMS_CONTENTS_TYPE_PSP,
  DMS_CONTENTS_TYPE_R3D,
  DMS_CONTENTS_TYPE_RAWVIDEO,
  DMS_CONTENTS_TYPE_RCV,
  DMS_CONTENTS_TYPE_RTP,
  DMS_CONTENTS_TYPE_RTSP,
  DMS_CONTENTS_TYPE_SPDIF,
  DMS_CONTENTS_TYPE_SVCD,
  DMS_CONTENTS_TYPE_TIERTEXSEQ,
  DMS_CONTENTS_TYPE_TRUEHD,
  DMS_CONTENTS_TYPE_VCD,
  DMS_CONTENTS_TYPE_YUV4MPEGPIPE,
  /* Container formats, can contain audio and video files */
  DMS_CONTENTS_TYPE_MATROSKA,  /* .mkv .mka .mks */
  DMS_CONTENTS_TYPE_WEBM,      /* .webm */
  DMS_CONTENTS_TYPE_MXF,       /* possible extension .mxf */
  DMS_CONTENTS_TYPE_VOB,       /* .vob */
  DMS_CONTENTS_TYPE_SWF,       /* .swf */
  DMS_CONTENTS_TYPE_RM,        /* .rm */
  DMS_CONTENTS_TYPE_3G2,       /* 3GPP2 format, extension .3g2 */

  /* Still images */
  DMS_CONTENTS_TYPE_DPX,       /* Digital Picture Exchange, .dpx extension */
  DMS_CONTENTS_TYPE_ICO,
  DMS_CONTENTS_TYPE_PCX,
  DMS_CONTENTS_TYPE_PPM,
  /* Audio */
  DMS_CONTENTS_TYPE_AAC,       /* .aac */
  DMS_CONTENTS_TYPE_AMR,       /* .amr */
#ifdef DEVELOPMENT_DLNA_DMS_SUPPORT_AIFF
  DMS_CONTENTS_TYPE_AIFF,      /* .aiff, .aif, .aifc */
#endif
  DMS_CONTENTS_TYPE_AU,        /* .au, .snd */
  DMS_CONTENTS_TYPE_PCM,       /* .pcm */
  DMS_CONTENTS_TYPE_OGG_AUDIO, /* .oga,*/
  DMS_CONTENTS_TYPE_FLAC,      /* .flac */
  DMS_CONTENTS_TYPE_VOC,       /* .voc */
  DMS_CONTENTS_TYPE_SOX,       /* .act */
  DMS_CONTENTS_TYPE_MLP,       /* .mlp */
  DMS_CONTENTS_TYPE_MP2,
  DMS_CONTENTS_TYPE_RA,  /*real audio*/
  DMS_CONTENTS_TYPE_RAM, /*real audio*/
  DMS_CONTENTS_TYPE_MP1,
  DMS_CONTENTS_TYPE_ASX,
  DMS_CONTENTS_TYPE_MID,
  DMS_CONTENTS_TYPE_AT3P,
  DMS_CONTENTS_TYPE_RMI,
  DMS_CONTENTS_TYPE_SND,
  DMS_CONTENTS_TYPE_APL,              /*Monkey's Audio*/
  DMS_CONTENTS_TYPE_DTSHD,    /*DTS HD*/

  /* Videos */
  DMS_CONTENTS_TYPE_ROQ,       /* extension .roq */
  DMS_CONTENTS_TYPE_DV,        /* .dv, .dif */
  DMS_CONTENTS_TYPE_OGG_VIDEO, /* .ogv, .oga, .ogx, .ogg, .spx, */
  DMS_CONTENTS_TYPE_MOV,       /* .mov */
  DMS_CONTENTS_TYPE_MJ2, /* motion jpeg, .mj2 */
  DMS_CONTENTS_TYPE_AVI,
  DMS_CONTENTS_TYPE_DIVX,
  DMS_CONTENTS_TYPE_MJPEG,
  DMS_CONTENTS_TYPE_MPE,
  DMS_CONTENTS_TYPE_MP2P,
  DMS_CONTENTS_TYPE_MP2T,
  DMS_CONTENTS_TYPE_M2V,
  DMS_CONTENTS_TYPE_M1V,
  DMS_CONTENTS_TYPE_OGM,
  DMS_CONTENTS_TYPE_TS,
  DMS_CONTENTS_TYPE_TGA,
  DMS_CONTENTS_TYPE_MPA,
  DMS_CONTENTS_TYPE_M2TS,
  DMS_CONTENTS_TYPE_VDR,

  DMS_CONTENTS_TYPE_AAC_ADTS,

  /* MPEG DASH */
#ifdef DEVELOPMENT_ENABLE_ADS
  DMS_CONTENTS_TYPE_MPD,
#endif /* DEVELOPMENT_ENABLE_ADS */

  DMS_CONTENTS_TYPE_MP4,
  DMS_CONTENTS_TYPE_MP4_VIDEO,
#ifdef DEVELOPMENT_ENABLE_CVP_EU
  DMS_CONTENTS_TYPE_MP4_EU_MPEG4_B13,
#endif /* DEVELOPMENT_ENABLE_CVP_EU */
  DMS_CONTENTS_TYPE_MP4_AUDIO,
  DMS_CONTENTS_TYPE_3GP,
  DMS_CONTENTS_TYPE_3GP_VIDEO,
  DMS_CONTENTS_TYPE_3GP_AUDIO,
  DMS_CONTENTS_TYPE_RTML,
  DMS_CONTENTS_TYPE_PLAYLIST,
  DMS_CONTENTS_TYPE_M3U,
  DMS_CONTENTS_TYPE_M3U8,
  DMS_CONTENTS_TYPE_PLS,
  DMS_CONTENTS_TYPE_WPL,
  DMS_CONTENTS_TYPE_TIFF

#ifdef DLNA_DMS_SUPPORT_AC3
  , DMS_CONTENTS_TYPE_AC3
#endif /* DLNA_DMS_SUPPORT_AC3 */
  , DMS_CONTENTS_TYPE_FLV /*     .flv, .f4v, .f4p, .f4a, .f4b */
  , DMS_CONTENTS_TYPE_QT
  , DMS_CONTENTS_TYPE_ATRAC
  , DMS_CONTENTS_TYPE_ISO
  , DMS_CONTENTS_TYPE_IMG
  , DMS_CONTENTS_TYPE_DVRMS
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

typedef enum dmsContentClassType_ {
  DMS_CONTENTS_CLASS_TYPE_IMAGE,
  DMS_CONTENTS_CLASS_TYPE_AUDIO,
  DMS_CONTENTS_CLASS_TYPE_VIDEO,
  DMS_CONTENTS_CLASS_TYPE_PLAYLIST,
  DMS_CONTENTS_CLASS_TYPE_DOCUMENT
} dmsContentClassType;

/**
* @addtogroup Enumerators
*/
/*@{*/

/*!
TDMSContentClassType represents the DMS content class type like Audio, Image, Video etc.
<table>
   <tr>
      <td><b>Definition</b></td>
      <td><b>Description</b></td>
   </tr>
   <tr>
       <td>DMS_CONTENTS_CLASS_TYPE_IMAGE</td>
       <td>Content Type Class Images</td>
   </tr>
   <tr>
       <td>DMS_CONTENTS_CLASS_TYPE_AUDIO</td>
       <td>Content Type Class Audio</td>
   </tr>
   <tr>
       <td>DMS_CONTENTS_CLASS_TYPE_VIDEO</td>
       <td>Content Type Class Video</td>
   </tr>
   <tr>
       <td>DMS_CONTENTS_CLASS_TYPE_PLAYLIST</td>
       <td>Content Type Class Playlists</td>
   </tr>
   <tr>
       <td>DMS_CONTENTS_CLASS_TYPE_DOCUMENT</td>
       <td>Content Type Class Document</td>
   </tr>
</table>
*/
typedef slim_int TDMSContentClassType;
/*@}*/

enum {
  DMS_CONTENTS_BROWSE_AUDIO,
  DMS_CONTENTS_BROWSE_IMAGE,
  DMS_CONTENTS_BROWSE_VIDEO,
  DMS_CONTENTS_BROWSE_PLAYLIST,
  DMS_CONTENTS_BROWSE_DOCUMENT
};
/**
 * @addtogroup Enumerators
 */
/*@{*/
/*!
TDMSContentBrowseType represents the browse by type
<table>
   <tr>
      <td><b>Definition</b></td>
      <td><b>Description</b></td>
   </tr>
   <tr>
       <td>DMS_CONTENTS_BROWSE_AUDIO</td>
       <td>Content Type Class Images</td>
   </tr>
   <tr>
       <td>DMS_CONTENTS_BROWSE_IMAGE</td>
       <td>Content Type Class Audio</td>
   </tr>
   <tr>
       <td>DMS_CONTENTS_BROWSE_VIDEO</td>
       <td>Content Type Class Video</td>
   </tr>
   <tr>
       <td>DMS_CONTENTS_BROWSE_PLAYLIST</td>
       <td>Content Type Class Playlist</td>
   </tr>
   <tr>
       <td>DMS_CONTENTS_BROWSE_DOCUMENT</td>
       <td>Content Type Class Document</td>
   </tr>
</table>
*/

typedef slim_int TDMSContentBrowseType;
/*@}*/

typedef enum dmsCADatabaseSelectionMode_ {
  DMS_CA_DB_SELECTION_MODE_AUTO,  // Databse location selected automatically
  DMS_CA_DB_SELECTION_MODE_MANUAL // Database location selected manually
} dmsCADatabaseSelectionMode;

/**
 * @addtogroup Enumerators
 */
/*@{*/
/*!
TDMSCADatabaseSelectionMode represents db selection mode
<table>
   <tr>
      <td><b>Definition</b></td>
      <td><b>Description</b></td>
   </tr>
   <tr>
       <td>DMS_CA_DB_SELECTION_MODE_AUTO</td>
       <td>DB location will be selected automatically </td>
   </tr>
   <tr>
       <td>DMS_CA_DB_SELECTION_MODE_MANUAL</td>
       <td>DB location will be selected manually</td>
   </tr>
</table>
*/

typedef slim_int TDMSCADatabaseSelectionMode;
/*@}*/

typedef enum dmsCACommand_ {
  DMS_CA_CMD_PAUSE = 1,
  DMS_CA_CMD_RESUME
} dmsCACommand;

/**
 * @addtogroup Enumerators
 */
/*@{*/
/*!
TDMSCACommand represents command type
<table>
   <tr>
      <td><b>Definition</b></td>
      <td><b>Description</b></td>
   </tr>
   <tr>
       <td>DMS_CA_CMD_PAUSE</td>
       <td>Pause CA command</td>
   </tr>
   <tr>
       <td>DMS_CA_CMD_RESUME</td>
       <td>Resume CA command</td>
   </tr>
</table>
*/

typedef slim_int TDMSCACommand;
/*@}*/

typedef enum dmsCAState_ {
  DMS_CA_STATE_DISABLED,
  DMS_CA_STATE_IDLE,
  DMS_CA_STATE_PROCESSING,
  DMS_CA_STATE_PAUSED,
  DMS_CA_STATE_STOPPED
} dmsCAState;

/**
 * @addtogroup Enumerators
 */
/*@{*/
/*!
TDMSCAState represents state of CA module
<table>
   <tr>
      <td><b>Definition</b></td>
      <td><b>Description</b></td>
   </tr>
   <tr>
       <td>DMS_CA_STATE_DISABLED</td>
       <td>CA is disabled</td>
   </tr>
   <tr>
       <td>DMS_CA_STATE_IDLE</td>
       <td>CA is enabled, database opened, ca is waiting for events</td>
   </tr>
   <tr>
       <td>DMS_CA_STATE_PROCESSING</td>
       <td>CA is enabled, database is opened, ca is processing</td>
   </tr>
   <tr>
       <td>DMS_CA_STATE_PAUSED</td>
       <td> CA is enabled, database is opened, ca is not processing</td>
   </tr>
   <tr>
       <td>DMS_CA_STATE_STOPPED</td>
       <td>CA is enabled, no database is opened</td>
   </tr>
</table>
*/

typedef slim_int TDMSCAState;
/*@}*/

typedef enum dmsCAIndex_ {
  DMS_CA_INDEX_DISABLED,
  DMS_CA_INDEX_ENABLED
} dmsCAIndex;

/**
 * @addtogroup Enumerators
 */
/*@{*/
/*!
TDMSCAIndex represents indexing of specific slave DMS
<table>
   <tr>
      <td><b>Definition</b></td>
      <td><b>Description</b></td>
   </tr>
   <tr>
       <td>DMS_CA_INDEX_DISABLED</td>
       <td>CA indexing of specifc slave DMS is disabled</td>
   </tr>
   <tr>
       <td>DMS_CA_INDEX_ENABLED</td>
       <td>CA indexing of specifc slave DMS is enabled</td>
   </tr>
</table>
*/

typedef slim_int TDMSCAIndex;
/*@}*/


#ifndef _DOXYGEN
#ifdef DEVELOPMENT_CONTENT_API
/* DMS content resource property structure. */
struct _TDMSResProperty {
  slim_char *res;
  slim_char *pinfo;
  dlna_uint64 size;

  slim_word bitrate;
  slim_word sample_rate;
  slim_word duration;

  slim_word width;         /* res@resolution,   */
  slim_word height;
};

/**
 * @addtogroup Structures
 */
/*@{*/
/*!
TDMSContentProperty is the structure used to retain DMS content properties.
<table>
        <tr>
                <td><b>Member</b></td>
                <td><b>Data Type</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>res</td>
                <td>slim_char</td>
                <td>Resource URI</td>
        </tr>
        <tr>
                <td>pinfo</td>
                <td>slim_char</td>
                <td>Resource protocol info</td>
        </tr>
        <tr>
                <td>size</td>
                <td>dlna_uint64</td>
                <td>Resource size</td>
        </tr>
        <tr>
                <td>bitrate</td>
                <td>slim_word</td>
                <td>Resource bitrate</td>
        </tr>
        <tr>
                <td>sample_rate</td>
                <td>slim_word</td>
                <td>Resource sample rate</td>
        </tr>
        <tr>
                <td>duration</td>
                <td>slim_word</td>
                <td>Resource duration</td>
        </tr>
        <tr>
                <td>width</td>
                <td>slim_word</td>
                <td>Resource width</td>
        </tr>
        <tr>
                <td>height</td>
                <td>slim_word</td>
                <td>Resource height</td>
        </tr>
</table>
*/
typedef struct _TDMSResProperty TDMSResProperty;
/*@}*/

/* DMS content album arts structure. */
struct _TDMSUpnpAlbumArtURIs {
  slim_char **upnp_albumArtURI;
  slim_int upnp_albumArtURI_len;
};

/**
 * @addtogroup Structures
 */
/*@{*/
/*!
TDMSUpnpAlbumArtURIs is the structure used to retain content album arts.
<table>
        <tr>
                <td><b>Member</b></td>
                <td><b>Data Type</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>upnp_albumArtURI</td>
                <td>slim_char</td>
                <td>Table containing album art uris</td>
        </tr>
        <tr>
                <td>upnp_albumArtURI_len</td>
                <td>slim_int</td>
                <td>Length of album arts table</td>
        </tr>
</table>
*/
typedef struct _TDMSUpnpAlbumArtURIs TDMSUpnpAlbumArtURIs;
/*@}*/

/* DMS content resource properties structure. */
struct _TDMSResProperties {
  TDMSResProperty *res_properties;
  slim_int res_properties_len;
};
/**
 * @addtogroup Structures
 */
/*@{*/
/*!
TDMSResProperties is the structure used to retain content resource properties.
<table>
        <tr>
                <td><b>Member</b></td>
                <td><b>Data Type</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>res_properties</td>
                 <td>TDMSResProperty</td>
                <td>Table of resource properties</td>
        </tr>
        <tr>
                <td>res_properties_len</td>
                 <td>slim_int</td>
                <td>Length of resource properties table</td>
        </tr>
</table>
*/
typedef struct _TDMSResProperties TDMSResProperties;
/*@}*/
#endif /*DEVELOPMENT_CONTENT_API*/

/* DMS content property structure. */
struct _TDMSContentProperty {
#ifndef DEVELOPMENT_CONTENT_API
  slim_int id;
#else /* DEVELOPMENT_CONTENT_API */
  slim_char *id;
#endif /* DEVELOPMENT_CONTENT_API */
  slim_char *title;
  dlna_time_t dt;
  dlna_time_t time;
#ifndef DEVELOPMENT_CONTENT_API
  dlna_uint64 size;
#endif /* DEVELOPMENT_CONTENT_API */
  TDMSContentType type;
  slim_char *local_path;
#ifdef DEVELOPMENT_CONTENT_API
  slim_char *parent_id;

  slim_char *creator;
  slim_char *upnp_class;
  slim_char *upnp_album;

  slim_char *track_num;

  slim_char *artist;
  slim_char *genre;

  TDMSResProperties resource_properties;
  TDMSUpnpAlbumArtURIs upnp_albumArtURIs;
#endif /* DEVELOPMENT_CONTENT_API */
};
/**
 * @addtogroup Structures
 */
/*@{*/
#ifdef DEVELOPMENT_CONTENT_API
/*!
TDMSContentProperty is the structure used to retain DMS content properties.
<table>
        <tr>
                <td><b>Member</b></td>
                <td><b>Data Type</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>id</td>
                <td>slim_char</td>
                <td>ID of the Content</td>
        </tr>
        <tr>
                <td>title</td>
                <td>slim_char</td>
                <td>dc:title property of the Content</td>
        </tr>
        <tr>
                <td>dt</td>
                <td>dlna_time_t</td>
                <td>dc:date property of the Content</td>
        </tr>
        <tr>
                <td>time</td>
                <td>dlna_time_t</td>
                <td>Last update time of content</td>
        </tr>
        <tr>
                <td>type</td>
                <td>TDMSContentType</td>
                <td>Content type</td>
        </tr>
        <tr>
                <td>local_path</td>
                <td>slim_char</td>
                <td>Path to content</td>
        </tr>
        <tr>
                <td>parent_id</td>
                <td>slim_char</td>
                <td>Content parent ID </td>
        </tr>
        <tr>
                <td>creator</td>
                <td>slim_char</td>
                <td>dc:creator property of the content</td>
        </tr>
        <tr>
                <td>upnp_class</td>
                <td>slim_char</td>
                <td>upnp:class property of the content</td>
        </tr>
        <tr>
                <td>upnp_album</td>
                <td>slim_char</td>
                <td>upnp:album property of the content</td>
        </tr>
        <tr>
                <td>track_num</td>
                <td>slim_char</td>
                <td>upnp:OriginalTracknum property of the content</td>
        </tr>
        <tr>
                <td>artist</td>
                <td>slim_char</td>
                <td>upnp:artist property of the content</td>
        </tr>
        <tr>
                <td>genre</td>
                <td>slim_char</td>
                <td>upnp:genre property of the content</td>
        </tr>
        <tr>
                <td>resource_properties</td>
                <td>TDMSResProperties</td>
                <td>Structure storing content res data </td>
        </tr>
        <tr>
                <td>upnp_albumArtURIs</td>
                <td>TDMSUpnpAlbumArtURIs</td>
                <td>Structure storing urls for album arts</td>
        </tr>
</table>

\par See also:
For information about the dlna_time_t and dlna_uint64 types, see the description of "Data Types"
in "NetFront Living Connect v2.0 Porting Guide".
*/
#else /*DEVELOPMENT_CONTENT_API*/
/*!
TDMSContentProperty is the structure used to retain DMS content properties.
<table>
        <tr>
                <td><b>Member</b></td>
                <td><b>Data Type</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>id</td>
                <td>slim_int</td>
                <td>ID of the Content</td>
        </tr>
        <tr>
                <td>title</td>
                <td>slim_char</td>
                <td>Content title</td>
        </tr>
        <tr>
                <td>dt</td>
                <td>dlna_time_t</td>
                <td>date property item field value</td>
        </tr>
        <tr>
                <td>time</td>
                <td>dlna_time_t</td>
                <td>Last update time of content</td>
        </tr>
        <tr>
                <td>size</td>
                <td>dlna_uint64</td>
                <td>Content size (bytes)</td>
        </tr>
        <tr>
                <td>type</td>
                <td>TDMSContentType</td>
                <td>Content type</td>
        </tr>
        <tr>
                <td>local_path</td>
                <td>slim_char</td>
                <td>Path to content</td>
        </tr>
</table>

\par See also:
For information about the dlna_time_t and dlna_uint64 types, see the description of "Data Types"
in "NetFront Living Connect v2.0 Porting Guide".
*/
#endif /*DEVELOPMENT_CONTENT_API*/

typedef struct _TDMSContentProperty TDMSContentProperty;
/*@}*/
#endif /*__DOXYGEN__*/

#ifndef _DOXYGEN
#ifdef HAVE_DTCP
/* DMS content metadata structure. */
struct _TDMSContentMetadata {
  /* must be set */
  slim_char*            full_path;
  TDMSContentClassType  media_class_type;

  /* generated if not set */
  slim_char*  dc_title;
  slim_char*  upnp_album;

  /* not generated if not set */
  slim_char*  dlna_profile;
  slim_word   date;
  slim_word   modtime;
  dlna_uint64 file_size;
  slim_char*  dc_creator;
  slim_char*  upnp_genre;
  slim_char*  upnp_artist;
  slim_char*  upnp_album_art_full_path;
  slim_word   width;
  slim_word   height;
  slim_char*  track_num;
  slim_char*  duration_str;
  slim_word   bitrate;
  slim_word   sample_rate;
  slim_byte   channels;
  slim_char*  composer;
  slim_word   dlnaManaged;
  slim_word   dlna_org_flags;
  slim_char*  upnp_rating;
  slim_int    shared_flag;

  minfo_drm_mode      mode;
  minfo_drm_retension ret_state;
  minfo_drm_aps       aps;
  minfo_drm_ict       img_const;
  minfo_drm_epn       epn;
  minfo_drm_cci       cci;
};

/**
 * @addtogroup DataTypes
 */
/*@{*/

/*!
TDMSContentMetadata is used to pass metadata of manually added secured content.
*/

typedef struct _TDMSContentMetadata TDMSContentMetadata;

/*@}*/

#endif /* HAVE_DTCP */

struct TDMSConfig_
{
  slim_int flags;
  slim_int ssdp_max_age;
};
/**
 * @addtogroup Structures
 */
/*@{*/
/*!
TDMSConfig is used to set DMS Configurations
<table>
        <tr>
                <td><b>Member</b></td>
                <td><b>Data Type</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>flags</td>
                <td>slim_int</td>
                <td>Flags from a predefined set to be used to configure DMS</td>
        </tr>
         <tr>
                <td>ssdp_max_age</td>
                <td>slim_int</td>
                <td>Max Age for SSDP Notify Msgs for DMS</td>
        </tr>
</table>
*/
typedef struct TDMSConfig_ TDMSConfig;
/*@}*/

struct _TDMSPGLevelObject{
  struct _TDMSPGLevelObject *prev;
  struct _TDMSPGLevelObject *next;
  slim_int level;
  slim_char *name;
  slim_char *description;
};
typedef struct _TDMSPGLevelObject TDMSPGLevelObject;

struct _TDMSPGDeviceObject{
  struct _TDMSPGDeviceObject *prev;
  struct _TDMSPGDeviceObject *next;
  slim_int access_level;
  slim_char *friendlyname;
  slim_char *mac_address;
  slim_char *ip_address;
  slim_char *description;
};
typedef struct _TDMSPGDeviceObject TDMSPGDeviceObject;

struct _TDMSCADeviceObject{
  struct _TDMSCADeviceObject *prev;
  struct _TDMSCADeviceObject *next;
  slim_bool index;    /*! device indexing value */
  slim_char *name;    /*! device friendly name */
  slim_char *uuid;    /*! device uuid */
};
typedef struct _TDMSCADeviceObject TDMSCADeviceObject;

/* DMS Flags for Push Controller*/
#define DMS_FLAG_WITH_PUSH      (1 << 0)
#define DMS_FLAG_DISABLE_DMS    (1 << 1)    /* This flag must use with DMS_FLAG_WITH_PUSH. */

/* DMS configuration parameters. */

/**
 * @addtogroup Macros
 */
/*@{*/
/*!
 * NFLC DMS Configuration Flags
  <table>
         <tr>
                <td><b>Member</b></td>
                <td><b>Description</b></td>
        </tr>
        <tr>
                <td>DMS_CONFIG_FLAG_NONE</td>
                <td>(0) None</td>
        </tr>
                <tr>
                <td>DMS_CONFIG_FLAG_SSDP_MAX_AGE</td>
                <td>(1) Flag to set SSDP Max Age</td>
        </tr>
</table>
 */
#define DMS_CONFIG_FLAG_NONE             (0)
#define DMS_CONFIG_FLAG_SSDP_MAX_AGE     (1 << 0)
/*@}*/
#endif /* _DOXYGEN */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Prototypes.  */

/* DMS Library Functions*/

/**
 * @addtogroup Functions
 */
/*@{*/

/*!
\par Function:
Generates DMS instance.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_p</td>
		<td>DLNA progress manager descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_callback</td>
		<td>Specifies slim_nil</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_port</td>
		<td>DMS UPnP server port number (port number used by DMS)</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_data_dir</td>
		<td>Data directory of DMS.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_xml_dir</td>
		<td>Folder with xml files needed for DMS.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_dms_flags</td>
		<td>UPnP service settings flags<br/>Specify 0 when using as DMS, and the bitwise OR of both the DMS_FLAG_WITH_PUSHand DMS_FLAG_DISABLE_DMS flags when using as +PU+.</td>
	</tr>
</table>

\return != slim_nil Succeeded (DMS instance)
\return == slim_nil Initialization failed
\par Description:
This function generates the DMS instance and initializes the DMS library.

This function must be called first among all the DMS APIs.

Specify the DLNA progress manager descriptor allocated by dlnaProgressAllocPeer() for in_p
(see the description of dlnaProgressAllocPeer() in "NetFront Living Connect v2.0 Porting
Guide").

  Specify the path to the directory where the configuration XML files (device description file and service
description file) used by the DMS are stored for in_xml_dir.
\par Example:
\code
/usr/local/share/dlna/xml
\endcode

Specify the filename of the device description file used by the DMS for in_desc_file. (Example:
dms_descr.xml).

Delete the instance generated by this function using dlnaDmsFree().
*/
/* API: Allocate DMS.  */
DLNA_API TDMS
dlnaDmsAlloc (dlna_progress in_p, TDMSEventCallback in_callback,
    slim_half in_port,
    slim_char * in_data_dir,
    slim_char * in_xml_dir,
    slim_word in_dms_flags);

/*!
\par Function:
Deletes DMS instance.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMS instance</td>
	</tr>
</table>

\return DMS_SUCCESS Succeeded in deleting DMS instance
\return DMS_INVALID_PARAM Invalid parameter
\par Description:
This function deletes the DMS instance.

When the DMS library is started (after successful dlnaDmsStart()), dlnaDmsStop() must be
called to stop the DMS library before calling this function.

After this function is called, delete the DLNA progress by calling dlnaProgressFreePeer() (see the
description of dlnaProgressFreePeer() in "NetFront Living Connect v2.0 Porting Guide").
*/
/* API: Free DMS.  */
DLNA_API TDMSReturn
dlnaDmsFree (TDMS self);

/*!
\par Function:
Starts DMS library.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMS instance</td>
	</tr>
</table>

\return DMS_SUCCESS Succeeded
\return DMS_INVALID_PARAM Invalid parameter
\return DMS_INVALID_DESC Invalid DMS configuration XML file
\return DMS_OUT_OF_MEMORY Insufficient memory
\return DMS_INIT_FAILED Initialization failed
\return DMS_SOCKET_ERROR Socket creation error
\par Description:
This function prepares the protocols to be used for communication by the DMS (SSDP, GENA, SOAP).
After that, it registers an event that sends an SSDP packet to notify other devices on the network that
the DMS device itself is running.

After this function is called, the DMS library is operated by calling dlnaProgressStartPeer() (see
the description of dlnaProgressStartPeer() in "NetFront Living Connect v2.0 Porting Guide").
*/
/* API: Start DMS.  */
DLNA_API TDMSReturn
dlnaDmsStart (TDMS self);

/*!
\par Function:
Stops DMS library.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMS instance</td>
	</tr>
</table>

\return DMS_SUCCESS Succeeded
\return DMS_INVALID_PARAM Invalid parameter
\return DMS_SOCKET_ERROR Socket termination error
\par Description:
This function stops the protocols (SSDP, GENA, SOAP) used by the DMS for communication. After that,
it registers an event that sends an SSDP packet to notify clients on the network that the DMS has
disconnected.

  If the DLNA progress was started by dlnaProgressStartPeer(), then the DLNA progress must be
stopped by dlnaProgressStopPeer(), before calling this function (see the description of
dlnaProgressStopPeer() in "NetFront Living Connect v2.0 Porting Guide").
*/
/* API: Stop DMS.  */
DLNA_API TDMSReturn
dlnaDmsStop (TDMS self);
/**
 * @addtogroup Functions
 */
/*@{*/

/*!
\par Function:
Sets or changes DMS friendly name.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMS instance</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_friendly_name</td>
		<td>Friendly name to set</td>
	</tr>
</table>

\return DMS_SUCCESS Succeeded
\return DMS_INVALID_PARAM Invalid parameter
\return DMS_INVALID_ACTION Invalid action
\return DMS_INVALID_DESC Invalid DMS configuration XML file description
\return DMS_OUT_OF_MEMORY Insufficient memory
\return DMS_INIT_FAILED Initialization failed
\return DMS_SOCKET_ERROR Socket creation error
\par Description:
This function changes the DMS friendly name.

Since calling this function restarts SSDP, the DMS is temporarily disconnected from the network.

This function must be called when the DMS library is started (after successful dlnaDmsStart()).

If this function is called while the DMS library is stopped, it returns DMS_INVALID_ACTION.
*/
/* API: Sets friendlyname of DMS in the device description */
DLNA_API TDMSReturn
dlnaDmsSetFriendlyName (TDMS self, slim_char *in_friendly_name);

/*!
\par Function:
Gets DMS friendly name.
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMS instance</td>
        </tr>
</table>

\return valid Friendlyname if available
\return slim_nil if any error occurs

\par Description:
This function gets the DMS friendly name.

This function must be called when the DMS library is started (after successful dlnaDmsStart()).

If this function is called while the DMS library is stopped, it returns slim_nil.
*/
/* API: Gets friendlyname of DMS in the device description */
DLNA_API slim_char*
dlnaDmsGetFriendlyName(TDMS self);

/**
 * \par Function:
 * Change priority of indexing thread
 * Change scheduling parameters of indexing thread
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>policy</td>
 *     <td>Requested policy</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>priority</td>
 *     <td>Requested priority</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM Null pointer or not supported values of policy and/or priority
 * \return DMS_GENERIC_ERROR MPEServer returned failure.
 * \par Description
 * Change scheduling parameters of indexing thread. Change is applied to thread in progress and any future runs.
 */
TDMSReturn
dlnaDmsSetIndexingThreadScheduling(TDMS self, enum dlna_thread_policy policy, slim_int priority);

/*@}*/

#ifndef _DOXYGEN
/*@}*/

/**
 * @addtogroup Content Property API
 */
/*@{*/
/*!
\par Function:
	Gets DMS content property specified by content ID.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMS instance</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_id</td>
		<td>Content ID </td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_property</td>
		<td>Pointer to buffer where obtained DMS content property is stored</td>
	</tr>
</table>

\return DMS_SUCCESS Succeeded
\return DMS_INVALID_PARAM Invalid parameter
\par Description:
This function returns the DMS content property with the content ID specified for in_id to out_property.

The DMS content property this function returns references data inside the DMS library. Therefore, it
becomes invalid after either a publish folder operation function or dlnaDmsFree() is called.
*/

/* API: Get DMS content property by ID */
#ifndef DEVELOPMENT_CONTENT_API
DLNA_API TDMSReturn
dlnaDmsGetContentPropertyById (TDMS self, slim_int in_id, TDMSContentProperty *out_property);
#else /* DEVELOPMENT_CONTENT_API */
DLNA_API TDMSReturn
dlnaDmsGetContentPropertyById (TDMS self, slim_char *in_id, TDMSContentProperty *out_property);
#endif /* DEVELOPMENT_CONTENT_API */

#ifdef DEVELOPMENT_CONTENT_API

/*!
\par Function:
        Gets DMS connected storage devices table starting from start_index and number limited to request_count.
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMS instance</td>
        </tr>
        <tr>
                <td>[out]</td>
                <td>out_properties</td>
                <td>Pointer to table where collected data is stored</td>
        </tr>
        <tr>
                <td>[out]</td>
                <td>number_returned</td>
                <td>Number of objects (devices) stored in out_properties</td>
        </tr>
        <tr>
                <td>[out]</td>
                <td>total_count</td>
                <td>Total number of devices connected to DMS</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>start_index</td>
                <td>Index of first device returned</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>request_count</td>
                <td>Maximum number of devices returned. When set to 0, no limit is applied - all available devices collected.</td>
        </tr>
</table>

\return DMS_SUCCESS Succeeded
\return DMS_INVALID_PARAM Invalid parameter
\return DMS_OUT_OF_MEMORY Out of memory
\par Description:
This function returns the DMS content properties table with the data describing connected storage devices.

The DMS content property this function returns references data inside the DMS library. Therefore, it
becomes invalid after either a publish folder operation function or dlnaDmsFree() is called.
*/
/* API: Get DMS connected devices */
DLNA_API TDMSReturn
dlnaDmsGetConnectedDevices (TDMS self, TDMSContentProperty **out_properties, slim_word *number_returned, slim_word *total_count, slim_word start_index, slim_word request_count);

/*!
\par Function:
        Gets DMS content properties specified by device ID.
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMS instance</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_id</td>
                <td>Device id</td>
        </tr>
        <tr>
                <td>[out]</td>
                <td>out_properties</td>
                <td>Pointer to table where collected data is stored</td>
        </tr>
        <tr>
                <td>[out]</td>
                <td>number_returned</td>
                <td>Number of objects stored in out_properties</td>
        </tr>
        <tr>
                <td>[out]</td>
                <td>total_count</td>
                <td>Total number of objects available on DMS</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>start_index</td>
                <td>Index of first object to be returned</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>request_count</td>
                <td>Maximum number of objects to be returned. When set to 0, no limit is applied - all available objects collected.</td>
        </tr>
</table>

\return DMS_SUCCESS Succeeded
\return DMS_INVALID_PARAM Invalid parameter
\return DMS_OUT_OF_MEMORY Out of memory
\par Description:
This function returns the DMS content properties table with the data referencing to objects available on specified USB device.

The DMS content property this function returns references data inside the DMS library. Therefore, it
becomes invalid after either a publish folder operation function or dlnaDmsFree() is called.
*/
/* API: Get DMS properties for specified USB device */
DLNA_API TDMSReturn
dlnaDmsGetUsbContents (TDMS self, slim_char* in_id, TDMSContentProperty **out_properties, slim_word *number_returned, slim_word *total_count, slim_word start_index, slim_word request_count);

/*!
\par Function:
        Gets DMS content properties specified by type.
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMS instance</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>type</td>
                <td>Type of content to be returned. [DMS_CONTENTS_BROWSE_AUDIO / DMS_CONTENTS_BROWSE_IMAGE / DMS_CONTENTS_BROWSE_VIDEO] </td>
        </tr>
        <tr>
                <td>[out]</td>
                <td>out_properties</td>
                <td>Pointer to table where collected data is stored</td>
        </tr>
        <tr>
                <td>[out]</td>
                <td>number_returned</td>
                <td>Number of objects stored in out_properties</td>
        </tr>
        <tr>
                <td>[out]</td>
                <td>total_count</td>
                <td>Total number of objects available on DMS</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>start_index</td>
                <td>Index of first object to be returned</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>request_count</td>
                <td>Maximum number of objects to be returned. When set to 0, no limit is applied - all available objects collected.</td>
        </tr>
</table>

\return DMS_SUCCESS Succeeded
\return DMS_INVALID_PARAM Invalid parameter
\return DMS_OUT_OF_MEMORY Out of memory
\par Description:
This function returns the DMS content properties table with the data referencing to objects of specified type.

The DMS content property this function returns references data inside the DMS library. Therefore, it
becomes invalid after either a publish folder operation function or dlnaDmsFree() is called.
*/
/* API: Get DMS content properties of a specified type. */
DLNA_API TDMSReturn
dlnaDmsGetContentByType (TDMS self, TDMSContentBrowseType type, TDMSContentProperty **out_properties, slim_word *number_returned, slim_word *total_count, slim_word start_index, slim_word request_count);

/*!
\par Function:
        Gets PVR (Recording) Contents served by DMS
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMS instance</td>
        </tr>
        <tr>
                <td>[out]</td>
                <td>out_properties</td>
                <td>Pointer to table where collected data is stored</td>
        </tr>
        <tr>
                <td>[out]</td>
                <td>number_returned</td>
                <td>Number of objects stored in out_properties</td>
        </tr>
        <tr>
                <td>[out]</td>
                <td>total_count</td>
                <td>Total number of objects available on DMS</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>start_index</td>
                <td>Index of first object to be returned</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>request_count</td>
                <td>Maximum number of objects to be returned. When set to 0, no limit is applied - all available objects collected.</td>
        </tr>
</table>

\return DMS_SUCCESS Succeeded
\return DMS_INVALID_PARAM Invalid parameter
\return DMS_OUT_OF_MEMORY Out of memory
\par Description:
This function returns the recording (PVR) contents' properties served by DMS.
*/
DLNA_API TDMSReturn
dlnaDmsGetRecordingContent (TDMS self, TDMSContentProperty **out_properties, slim_word *number_returned, slim_word *total_count, slim_word start_index, slim_word request_count);
/*!
\par Function:
        Searches DMS for content properties that meets search criteria.
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMS instance</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>criteria</td>
                <td>String representing DLNA compatible search criteria.</td>
        </tr>
        <tr>
                <td>[out]</td>
                <td>out_properties</td>
                <td>Pointer to table where collected data is stored</td>
        </tr>
        <tr>
                <td>[out]</td>
                <td>number_returned</td>
                <td>Number of objects stored in out_properties</td>
        </tr>
        <tr>
                <td>[out]</td>
                <td>total_count</td>
                <td>Total number of objects available on DMS</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>start_index</td>
                <td>Index of first object to be returned</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>request_count</td>
                <td>Maximum number of objects to be returned. When set to 0, no limit is applied - all available objects collected.</td>
        </tr>
</table>

\return DMS_SUCCESS Succeeded
\return DMS_INVALID_PARAM Invalid parameter
\return DMS_OUT_OF_MEMORY Out of memory
\par Description:
This function returns the DMS content properties table with the data referencing to objects meetings specified search criteria.

The DMS content property this function returns references data inside the DMS library. Therefore, it
becomes invalid after either a publish folder operation function or dlnaDmsFree() is called.
*/
/* API: Get DMS content properties that meets specified search criteria. */
DLNA_API TDMSReturn
dlnaDmsSearchContent (TDMS self, slim_char *criteria, TDMSContentProperty **out_properties, slim_word *number_returned, slim_word *total_count, slim_word start_index, slim_word request_count);

/*!
\par Function:
        Frees data in content property structure.
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMS instance</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>property</td>
                <td>Structure that fields are to be freed.</td>
        </tr>
</table>

\return DMS_SUCCESS Succeeded
\return DMS_INVALID_PARAM Invalid parameter
\par Description:
This function frees memory allocated for content property data.
*/
/* API: Frees content property data. */
DLNA_API TDMSReturn
dlnaDmsContentPropertyFree (TDMS self, TDMSContentProperty *property);

/*!
\par Function:
        Frees dynamically allocated table of content properties.
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMS instance</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>properties</td>
                <td>Pointer to table that stores content properties</td>
        </tr>
</table>

\return DMS_SUCCESS Succeeded
\return DMS_INVALID_PARAM Invalid parameter
\par Description:
This function frees memory allocated for content properties table.
It requires object counter returned by e.g. dlnaDmsSearchContent() as an input.
Function frees both properties data and table itself.
*/
/* API: Frees content property data. */
DLNA_API TDMSReturn
dlnaDmsContentPropertiesSetFree (TDMS self, TDMSContentProperty **properties, slim_word count);

#endif /* DEVELOPMENT_CONTENT_API */
/*@}*/
#endif /*_DOXYGEN*/

#ifdef HAVE_DTCP
/*!
\par Function:
Adds DTCP source device to DLNA stack
\par Parameters:
<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DLNA DMS device instance</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>source</td>
                <td>DTCP device entry to add</td>
        </tr>
</table>
\return slim_int error code value
\par Return Values:
<table>
        <tr>
                <td> \b DMS_SUCCESS</td>
                <td> <b> Entry added successfully</b></td>
        </tr>
        <tr>
                <td>DMS_INIT_FAILED</td>
                <td>Initialization failed</td>
        </tr>
        <tr>
                <td>DMS_GENERIC_ERROR</td>
                <td>Generic error occured</td>
        </tr>
        <tr>
                <td>DMS_INVALID_PARAM</td>
                <td>Invalid parameter was passed to function</td>
        </tr>
</table>
\par Description:
Function adds DTCP source device to DLNA device represented by self.
*/
TDMSReturn
dlnaDmsAssignDTCPSourceDevice(TDMS self, TDTCPDevice source);

/*!
\par Function:
Adds DTCP sink device to DLNA stack
\par Parameters:
<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DLNA DMS device instance</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>sink</td>
                <td>DTCP device entry to add</td>
        </tr>
</table>
\return slim_int error code value
\par Return Values:
<table>
        <tr>
                <td> \b DMS_SUCCESS</td>
                <td> <b> Entry added successfully</b></td>
        </tr>
        <tr>
                <td>DMS_INIT_FAILED</td>
                <td>Initialization failed</td>
        </tr>
        <tr>
                <td>DMS_GENERIC_ERROR</td>
                <td>Generic error occured</td>
        </tr>
        <tr>
                <td>DMS_INVALID_PARAM</td>
                <td>Invalid parameter was passed to function</td>
        </tr>
</table>
\par Description:
Function adds DTCP sink device to DLNA device represented by self.
*/
TDMSReturn
dlnaDmsAssignDTCPSinkDevice(TDMS self, TDTCPDevice sink);

/*!
\par Function:
Adds drm entry to device
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA DMS device instance</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_dtcp_entry</td>
		<td>DTCP device entry to add</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_proc</td>
		<td>Pointer to callback function to get CCI</td>
	</tr>
</table>
\return slim_int error code value
\par Return Values:
<table>
	<tr>
		<td> \b DMS_SUCCESS</td>
		<td> <b> Entry added successfully</b></td>
	</tr>
	<tr>
		<td>DMS_INIT_FAILED</td>
		<td>Initialization failed</td>
	</tr>
	<tr>
		<td>DMS_GENERIC_ERROR</td>
		<td>Generic error occured</td>
	</tr>
	<tr>
		<td>DMS_INVALID_PARAM</td>
		<td>Invalid parameter was passed to function</td>
	</tr>
</table>
\par Description:
Function adds drm entry specified in in_dtcp_entry to device represented by self.
*/
DLNA_API TDMSReturn
dlnaDmsDRMManagerAddDrmEntry (TDMS self, dtcp_device_entry_t *in_dtcp_entry, TDLNADRMManagerCallback in_proc);

/*!
\par Function:
Deletes drm entry from device
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA DMS device instance</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_type</td>
		<td>DRM type to delete from device</td>
	</tr>
</table>
\return none
\par Description:
Function deletes drm entry specified by in_type from device represented by self.
*/
void
dlnaDmsDRMManagerDeleteDrmEntry (TDMS self, media_drm_t in_type);
#endif /* HAVE_DTCP */

#ifndef _DOXYGEN
/*!
\par Function:
Gets the Content Indexing State
\par Parameters:
<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DLNA DMS device instance</td>
        </tr>
        <tr>
                <td>[out]</td>
                <td>out_idx_type</td>
                <td>out_idx_state</td>
                <td>Returns the current Indexing State of type TDMSContentIndexingState</td>
        </tr>
</table>
\return DMS_SUCCESS Succeeded
\return DMS_INVALID_PARAM Invalid parameter
\par Description:
This API returns the current content Indexing State. The value returned is of type TDMSContentIndexingState
*/
DLNA_API TDMSReturn
dlnaDMSGetContentIndexingState( TDMS self, slim_int *out_idx_type, TDMSContentIndexingState *out_idx_state);

/*!
\par Function:
Gets the Last Indexing Time of the Storage Device
\par Parameters:
<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DLNA DMS device instance</td>
        </tr>
                <tr>
                <td>[in]</td>
                <td>in_device_id</td>
                <td>ID of the Storage Device of type slim_char*</td>
        </tr>
        <tr>
                <td>[out]</td>
                <td> out_last_idx_time</td>
                <td>Returns the Last Indexed Time of the storage device specified</td>
        </tr>
</table>
\return DMS_SUCCESS Succeeded
\return DMS_INVALID_PARAM Invalid parameter
\par Description:
This API returns the last Indexed Time of the device specified. If no device specified it returns slim_nil
*/
DLNA_API TDMSReturn
dlnaDMSGetDeviceLastIndexingTime( TDMS self, const slim_char *in_device_id, slim_char *out_last_idx_time );

/*!
\par Function:
Gets the Content Indexing State or the last Indexed Time of the Storage Device Specified
\par Parameters:
<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DLNA DMS device instance</td>
        </tr>
                <tr>
                <td>[in]</td>
                <td>in_device_id</td>
                <td>ID of the Storage Device of type slim_char*</td>
        </tr>
        <tr>
                <td>[out]</td>
                <td> out_time_or_state</td>
                <td>Returns the Last Indexed Time or State of the storage device specified. </td>
        </tr>
</table>
\return DMS_SUCCESS Succeeded
\return DMS_INVALID_PARAM Invalid parameter
\par Description:
This API returns the last Indexed Time or the Indexing State of the device specified.
The Returned Indexing State is a constant string as follows
"INDEXING IN PROGRESS"
"INDEXING DONE"
"INDEXING ABORTED"
If no device specified it returns slim_nil.
If the Storage Device Indexing State or Last Indexed Time could not be ascertained, it returns slim_nil
*/
DLNA_API TDMSReturn
dlnaDMSGetDeviceLastIndexingTimeOrIndexingState( TDMS self, const slim_char *in_device_id, slim_char *out_time_or_state );
#endif /*_DOXYGEN*/

#ifdef DEVELOPMENT_ENABLE_IMPROVEMENT_INDEXING_CALLBACK
/**
 * @addtogroup Configuration API
 */
/*@{*/

/*!
\par Function:
Triggers rescan of the content for all the storage devices attached
\par Parameters:
<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DLNA DMS device instance</td>
        </tr>


</table>
\return DMS_SUCCESS Succeeded
\return DMS_INVALID_PARAM Invalid parameter
\par Description:
This API shall trigger the rescan of the content of all the storage devices attached.
*/
DLNA_API TDMSReturn
dlnaDMSStorageContentRescan(TDMS self);

/*!
\par Function:
Notify about the state of rescan of content.
\par Parameters:
<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DLNA DMS device instance</td>
        </tr>
                <tr>
                <td>[in]</td>
                <td>in_callback_func</td>
                <td>Instance of TDMSStorageContentRescanCallback</td>
        </tr>

</table>
\return DMS_SUCCESS Succeeded
\return DMS_INVALID_PARAM Invalid parameter
\par Description:
This API shall notify about the state of the rescan of content.
*/
DLNA_API TDMSReturn
dlnaDMSStorageContentRegisterRescanCallback(TDMS self, TDMSStorageContentRescanCallback in_callback_func);

/*@}*/

#else /* DEVELOPMENT_ENABLE_IMPROVEMENT_INDEXING_CALLBACK */
/*!
\par Function:
Triggers rescan of the content for all the storage devices attached
\par Parameters:
<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DLNA DMS device instance</td>
        </tr>
                <tr>
                <td>[in]</td>
                <td>in_callback_func</td>
                <td>Instance of TDMSStorageContentRescanCallback</td>
        </tr>

</table>
\return DMS_SUCCESS Succeeded
\return DMS_INVALID_PARAM Invalid parameter
\par Description:
This API shall trigger the rescan of the content of all the storage devices attached.
*/
DLNA_API TDMSReturn
dlnaDMSStorageContentRescan(TDMS self, TDMSStorageContentRescanCallback in_callback_func);

#endif /* DEVELOPMENT_ENABLE_IMPROVEMENT_INDEXING_CALLBACK */

/**
 * @addtogroup Functions
 */
/*@{*/

/**
 * \par Function:
 * Get the total shared content by content type
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_type</td>
 *     <td>TDMSContentClassType content type</td>
 *   </tr>
 *   <tr>
 *     <td>[out]</td>
 *     <td>out_total</td>
 *     <td>Total shared content</td>
 *   </tr>
 * </table>
 * \return slim_true Success
 * \return slim_false Failure
 * \par Description
 * Returns the total shared content by content type.
 */
DLNA_API TDMSReturn
dlnaDmsGetTotalSharedContentByType(TDMS self, TDMSContentClassType in_type, slim_int *out_total);

/**
 * \par Function:
 * Change the share value for the content by type
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_type</td>
 *     <td>TDMSContentClassType content type</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_sharedValue</td>
 *     <td>share value (1 or 0)</td>
 *   </tr>
 * </table>
 * \return slim_true Success
 * \return slim_false Failure
 * \par Description
 * Changes the shared value by content type. This API sets the shared value to in_sharedValue for all the content by in_type content type.
 */
DLNA_API TDMSReturn
dlnaDmsSetShareContentByType(TDMS self, TDMSContentClassType in_type, slim_int in_sharedValue);

/**
 * \par Function:
 * Set the max streaming session limit
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_session_count</td>
 *     <td>Streaming session count (Default is 0 which means unlimited)</td>
 *   </tr>
 * </table>
 * \return slim_true Success
 * \return slim_false Failure
 * \par Description
 * This API sets the maximum streaming session limit to in_session_count.
 */
DLNA_API TDMSReturn
dlnaDmsSetStreamingSessionsLimit (TDMS self, slim_int in_session_count);

#ifdef _DOXYGEN
#define ENABLE_PARENTAL_GUIDANCE
#endif /*_DOXYGEN*/
#ifdef ENABLE_PARENTAL_GUIDANCE
/**
 * @addtogroup DataTypes
 */
/*@{*/
/*!
TPGDeviceObject is the reference of a parental guidance device object.
*/
typedef void * TPGDeviceObject;
/*@}*/

/**
 * @addtogroup DataTypes
 */
/*@{*/
/*!
TPGLevelObject is the reference of a parental guidance level object.
*/
typedef void * TPGLevelObject;
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Get default parental guidance content level
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[out]</td>
 *     <td>out_level</td>
 *     <td>Default content level</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Get default parental guidance content level. Value of default content level is stored in out_level if function returns DMS_SUCCESS.
 */
DLNA_API TDMSReturn
dlnaDmsPGGetDefaultContentLevel(TDMS self, slim_int *out_level);
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Set default parental guidance content level
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_level</td>
 *     <td>Default content level</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer or not supported values.
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Set default parental guidance content level. Value of default content level is set and saved if function returns DMS_SUCCESS.
 * The new default level is assigned to each new indexed content.
 */
DLNA_API TDMSReturn
dlnaDmsPGSetDefaultContentLevel(TDMS self, slim_int in_level);
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Get default parental guidance device level
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[out]</td>
 *     <td>out_level</td>
 *     <td>Default device level</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Get default parental guidance device level. Value of default device level is stored in out_level if function returns DMS_SUCCESS.
 */
DLNA_API TDMSReturn
dlnaDmsPGGetDefaultDeviceLevel(TDMS self, slim_int *out_level);
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Set default parental guidance device level
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_level</td>
 *     <td>Default device level</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer or not supported values.
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Set default parental guidance device level. Value of default device level is set and saved if function returns DMS_SUCCESS.
 * The new default device is assigned to each new detected device.
 */
DLNA_API TDMSReturn
dlnaDmsPGSetDefaultDeviceLevel(TDMS self, slim_int in_level);
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Get number of devices in parental guidance device list
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[out]</td>
 *     <td>out_count</td>
 *     <td>Number of devices</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Get number of devices in parental guidance device list. Number of devices is stored in out_count if function returns DMS_SUCCESS.
 */
DLNA_API TDMSReturn
dlnaDmsPGGetDeviceCount(TDMS self, slim_int *out_count);
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Get first devices in parental guidance device list
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[out]</td>
 *     <td>out_parental_guidance_device</td>
 *     <td>Pointer to first device</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Get first devices in parental guidance device list. Address of first device is stored in out_parental_guidance_device if function returns DMS_SUCCESS.
 * Availability of this object outside caller function is not guaranteed. Copy the data if needed outside caller function.
 */
DLNA_API TDMSReturn
dlnaDmsPGGetFirstDevice(TDMS self, TPGDeviceObject *out_parental_guidance_device);
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Get next devices in parental guidance device list.
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_prev_parental_guidance_device</td>
 *     <td>Pointer of previous device in list</td>
 *   </tr>
 *   <tr>
 *     <td>[out]</td>
 *     <td>out_parental_guidance_device</td>
 *     <td>Pointer to next device</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Get next devices in parental guidance device list. Address of next device is stored in out_parental_guidance_device if function returns DMS_SUCCESS.
 * Availability of this object outside caller function is not guaranteed. Copy the data if needed outside caller function.
 */
DLNA_API TDMSReturn
dlnaDmsPGGetNextDevice(TDMS self, TPGDeviceObject in_prev_parental_guidance_device, TPGDeviceObject *out_parental_guidance_device);
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Get number of level in parental guidance level list
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[out]</td>
 *     <td>out_count</td>
 *     <td>Number of level</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Get number of level in parental guidance device list. Number of level is stored in out_count if function returns DMS_SUCCESS.
 */
DLNA_API TDMSReturn
dlnaDmsPGGetLevelCount(TDMS self, slim_int *out_count);
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Get first level in parental guidance level list.
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[out]</td>
 *     <td>out_parental_guidance_level</td>
 *     <td>Pointer to first level</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Get first level in parental guidance level list. Address of first level is stored in out_parental_guidance_level if function returns DMS_SUCCESS.
 * Availability of this object outside caller function is not guaranteed. Copy the data if needed outside caller function.
 */
DLNA_API TDMSReturn
dlnaDmsPGGetFirstLevel(TDMS self, TPGLevelObject *out_parental_guidance_level);
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Get next level in parental guidance level list.
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_prev_parental_guidance_level</td>
 *     <td>Pointer of previous level in list</td>
 *   </tr>
 *   <tr>
 *     <td>[out]</td>
 *     <td>out_parental_guidance_level</td>
 *     <td>Pointer to next level</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Get next level in parental guidance level list. Address of next level is stored in out_parental_guidance_level if function returns DMS_SUCCESS.
 * Availability of this object outside caller function is not guaranteed. Copy the data if needed outside caller function.
 */
DLNA_API TDMSReturn
dlnaDmsPGGetNextLevel(TDMS self, TPGLevelObject in_prev_parental_guidance_level, TPGLevelObject *out_parental_guidance_level);
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Set parental guidance device level by mac address
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_mac_address</td>
 *     <td>Device mac address</td>
 *   </tr>
 *	 <tr>
 *     <td>[in]</td>
 *     <td>in_level</td>
 *     <td>New device level</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer or not supported values.
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Set parental guidance device level of a device specified by mac address. Value of device level is set and saved if function returns DMS_SUCCESS.
 */
DLNA_API TDMSReturn
dlnaDmsPGSetDeviceLevelByMacAddress(TDMS self, slim_char *in_mac_address, slim_int in_level);
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Delete parental guidance device by mac address
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_mac_address</td>
 *     <td>Device mac address</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer or not supported values.
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Deletes parental guidance device specified by mac address from device list. Device is removed if function returns DMS_SUCCESS.
 */
DLNA_API TDMSReturn
dlnaDmsPGDeviceDeleteByMacAddress(TDMS self, slim_char *in_mac_address);
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Delete parental guidance device
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_parental_guidance_device</td>
 *     <td>Device object</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Deletes parental guidance device TPGDeviceObject from device list. Device is removed and freed if function returns DMS_SUCCESS.
 * in_parental_guidance_device becomes invalid after returning from this function.
 */
DLNA_API TDMSReturn
dlnaDmsPGDeviceDelete(TDMS self, TPGDeviceObject in_parental_guidance_device);
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Set parental guidance device description
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_parental_guidance_device</td>
 *     <td>Device object</td>
 *   </tr>
 *	 <tr>
 *     <td>[in]</td>
 *     <td>in_description</td>
 *     <td>New device description</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer or not supported values.
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Set parental guidance device description. Device description is set and saved if function returns DMS_SUCCESS.
 */
DLNA_API TDMSReturn
dlnaDmsPGDeviceSetDescription(TDMS self, TPGDeviceObject in_parental_guidance_device, slim_char *in_description);
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Get parental guidance device description
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_parental_guidance_device</td>
 *     <td>Device object</td>
 *   </tr>
 *	 <tr>
 *     <td>[out]</td>
 *     <td>out_description</td>
 *     <td>Device description</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer or not supported values.
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Get parental guidance device description. Address of device description is stored in out_description if function returns DMS_SUCCESS.
 * Availability of out_description outside caller function is not guaranteed. Copy the data if needed outside caller function.
 */
DLNA_API TDMSReturn
dlnaDmsPGDeviceGetDescription(TDMS self, TPGDeviceObject in_parental_guidance_device, slim_char **out_description);
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Set parental guidance device IP address
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_parental_guidance_device</td>
 *     <td>Device object</td>
 *   </tr>
 *       <tr>
 *     <td>[in]</td>
 *     <td>in_ip_address</td>
 *     <td>New device IP address</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer or not supported values.
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Set parental guidance device IP address. Device IP address is set and saved if function returns DMS_SUCCESS.
 */
DLNA_API TDMSReturn
dlnaDmsPGDeviceSetIPAddress(TDMS self, TPGDeviceObject in_parental_guidance_device, slim_char *in_ip_address);
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Get parental guidance device ip address
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_parental_guidance_device</td>
 *     <td>Device object</td>
 *   </tr>
 *       <tr>
 *     <td>[out]</td>
 *     <td>out_ip_address</td>
 *     <td>Device IP address</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer or not supported values.
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Get parental guidance device IP address. Address of device IP address is stored in out_ip_address if function returns DMS_SUCCESS.
 * Availability of out_ip_address outside caller function is not guaranteed. Copy the data if needed outside caller function.
 */
DLNA_API TDMSReturn
dlnaDmsPGDeviceGetIPAddress(TDMS self, TPGDeviceObject in_parental_guidance_device, slim_char **out_ip_address);
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Set parental guidance device friendly name
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_parental_guidance_device</td>
 *     <td>Device object</td>
 *   </tr>
 *       <tr>
 *     <td>[in]</td>
 *     <td>in_friendly_name</td>
 *     <td>New device friendly name</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer or not supported values.
 * \return DMS_GENERIC_ERROR Failure
 * \par FriendlyName
 * Set parental guidance device friendly name. Device friendly name is set and saved if function returns DMS_SUCCESS.
 */
DLNA_API TDMSReturn
dlnaDmsPGDeviceSetFriendlyName(TDMS self, TPGDeviceObject in_parental_guidance_device, slim_char *in_friendly_name);
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Get parental guidance device friendly name
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_parental_guidance_device</td>
 *     <td>Device object</td>
 *   </tr>
 *       <tr>
 *     <td>[out]</td>
 *     <td>out_friendly_name</td>
 *     <td>Device friendly name</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer or not supported values.
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Get parental guidance device friendly name. Address of device friendly_name is stored in out_friendly_name if function returns DMS_SUCCESS.
 * Availability of out_friendly_name outside caller function is not guaranteed. Copy the data if needed outside caller function.
 */
DLNA_API TDMSReturn
dlnaDmsPGDeviceGetFriendlyName(TDMS self, TPGDeviceObject in_parental_guidance_device, slim_char **out_friendly_name);
/*@}*/

DLNA_API TDMSReturn
dlnaDmsPGDeviceGetUserAgent(TDMS self, TPGDeviceObject in_parental_guidance_device, slim_char **out_user_agent);

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Set parental guidance device level
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_parental_guidance_device</td>
 *     <td>Device object</td>
 *   </tr>
 *	 <tr>
 *     <td>[in]</td>
 *     <td>in_level</td>
 *     <td>New device level</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer or not supported values.
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Set parental guidance device level. Device level is set and saved if function returns DMS_SUCCESS.
 */
DLNA_API TDMSReturn
dlnaDmsPGDeviceSetLevel(TDMS self, TPGDeviceObject in_parental_guidance_device, slim_int in_level);
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Get parental guidance device level
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_parental_guidance_device</td>
 *     <td>Device object</td>
 *   </tr>
 *	 <tr>
 *     <td>[out]</td>
 *     <td>out_level</td>
 *     <td>Device level</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer or not supported values.
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Get parental guidance device level. Value of device level is stored in out_level if function returns DMS_SUCCESS.
 */
DLNA_API TDMSReturn
dlnaDmsPGDeviceGetLevel(TDMS self, TPGDeviceObject in_parental_guidance_device, slim_int *out_level);
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Set parental guidance device mac address
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_parental_guidance_device</td>
 *     <td>Device object</td>
 *   </tr>
 *	 <tr>
 *     <td>[in]</td>
 *     <td>in_mac_address</td>
 *     <td>New device mac address</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer or not supported values.
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Set parental guidance device mac address. Device mac address is set and saved if function returns DMS_SUCCESS.
 */
DLNA_API TDMSReturn
dlnaDmsPGDeviceSetMacAddress(TDMS self, TPGDeviceObject in_parental_guidance_device, slim_char *in_mac_address);
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Get parental guidance device mac address
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_parental_guidance_device</td>
 *     <td>Device object</td>
 *   </tr>
 *	 <tr>
 *     <td>[out]</td>
 *     <td>out_mac_address</td>
 *     <td>Device mac address</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer or not supported values.
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Get parental guidance device mac address. Address of device mac address is stored in out_mac_address if function returns DMS_SUCCESS.
 * Availability of out_mac_address outside caller function is not guaranteed. Copy the data if needed outside caller function.
 */
DLNA_API TDMSReturn
dlnaDmsPGDeviceGetMacAddress(TDMS self, TPGDeviceObject in_parental_guidance_device, slim_char **out_mac_address);
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Set parental guidance level id
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_parental_guidance_level</td>
 *     <td>Level object</td>
 *   </tr>
 *	 <tr>
 *     <td>[in]</td>
 *     <td>in_id</td>
 *     <td>New level id</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer or not supported values.
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Set parental guidance level id. Level id is set and saved if function returns DMS_SUCCESS.
 */
DLNA_API TDMSReturn
dlnaDmsPGLevelSetId(TDMS self, TPGLevelObject in_parental_guidance_level, slim_int in_id);
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Get parental guidance level id
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_parental_guidance_level</td>
 *     <td>Level object</td>
 *   </tr>
 *	 <tr>
 *     <td>[out]</td>
 *     <td>out_mac_address</td>
 *     <td>Device mac address</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer or not supported values.
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Get parental guidance level id. Value of level id is stored in out_id if function returns DMS_SUCCESS.
 */
DLNA_API TDMSReturn
dlnaDmsPGLevelGetId(TDMS self, TPGLevelObject in_parental_guidance_level, slim_int *out_id);
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Set parental guidance level name
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_parental_guidance_level</td>
 *     <td>Level object</td>
 *   </tr>
 *	 <tr>
 *     <td>[in]</td>
 *     <td>in_name</td>
 *     <td>New level name</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer or not supported values.
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Set parental guidance level name. Level name is set and saved if function returns DMS_SUCCESS.
 */
DLNA_API TDMSReturn
dlnaDmsPGLevelSetName(TDMS self, TPGLevelObject in_parental_guidance_level, slim_char *in_name);
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Get parental guidance level name
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_parental_guidance_level</td>
 *     <td>Level object</td>
 *   </tr>
 *	 <tr>
 *     <td>[out]</td>
 *     <td>out_name</td>
 *     <td>Level name</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer or not supported values.
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Get parental guidance level name. Address of level name is stored in out_name if function returns DMS_SUCCESS.
 * Availability of out_name outside caller function is not guaranteed. Copy the data if needed outside caller function.
 */
DLNA_API TDMSReturn
dlnaDmsPGLevelGetName(TDMS self, TPGLevelObject in_parental_guidance_level, slim_char **out_name);
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Set parental guidance level description
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_parental_guidance_level</td>
 *     <td>Level object</td>
 *   </tr>
 *	 <tr>
 *     <td>[in]</td>
 *     <td>in_description</td>
 *     <td>New level description</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer or not supported values.
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Set parental guidance level description. Level description is set and saved if function returns DMS_SUCCESS.
 */
DLNA_API TDMSReturn
dlnaDmsPGLevelSetDescription(TDMS self, TPGLevelObject in_parental_guidance_level, slim_char *in_description);
/*@}*/

/**
 * @addtogroup Functions
 */
/*@{*/
/*!
 * \par Function:
 * Get parental guidance level description
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_parental_guidance_level</td>
 *     <td>Level object</td>
 *   </tr>
 *	 <tr>
 *     <td>[out]</td>
 *     <td>out_description</td>
 *     <td>Level description</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM NULL pointer or not supported values.
 * \return DMS_GENERIC_ERROR Failure
 * \par Description
 * Get parental guidance level description. Address of level description is stored in out_description if function returns DMS_SUCCESS.
 * Availability of out_description outside caller function is not guaranteed. Copy the data if needed outside caller function.
 */
DLNA_API TDMSReturn
dlnaDmsPGLevelGetDescription(TDMS self, TPGLevelObject in_parental_guidance_level, slim_char **out_description);
/*@}*/
DLNA_API TDMSReturn
dlnaDmsPGGetLevelList(TDMS self, TDMSPGLevelObject **out_list);

DLNA_API TDMSReturn
dlnaDmsPGGetDeviceList(TDMS self, TDMSPGDeviceObject **out_list);

DLNA_API TDMSReturn
dlnaDmsPGSetDeviceParams(TDMS self, TDMSPGDeviceObject *in_device);

DLNA_API TDMSReturn
dlnaDmsPGDeleteDeviceByMac(TDMS self, TDMSPGDeviceObject *in_device);

DLNA_API TDMSReturn
dlnaDMSGetDeviceByMacAddress(TDMS self, slim_char *in_macAddress, TDMSPGDeviceObject **out_device);

TDMSReturn
dlnaDMSSetPGDeviceParams(TDMS self, slim_char *in_macAddress, slim_int *in_level, slim_char *in_description);

#endif /* ENABLE_PARENTAL_GUIDANCE */

#ifndef _DOXYGEN
TDMSReturn
dlnaDmsServerStartAdvertisement (TDMS self);

TDMSReturn
dlnaDmsServerStopAdvertisement (TDMS self);
#endif /*_DOXYGEN*/

#ifdef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
/**
 * @addtogroup Functions
 */
/*@{*/

/*!
\par Function:
Publishes a folder/storage
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMS Instance</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_storage</td>
                <td>TDMSPublishStorage pointer specifying the storage to be published</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_storageObjectRights</td>
                <td>TDMSObjectRights, pointer specifying the storage object rights</td>
        </tr>
</table>

\return DMS_SUCCESS Succeeded
\return DMS_INVALID_PARAM Invalid parameter
\par Description:
This function adds the folder, a partitioned share, a storage device or a mounted usb device to publish the content to be shared with the clients.
This function adds only physical folders and accessible by DMS.
If autoIndex is set to slim_true then all the sub-folders and content with known content types are parsed by DMS for metadata and indexed. Any changes to the added storage i.e. add, delete or move of the content on the storage is automatically indexed if the target system supports Inotify mechanism.
If autoIndex is set to slim_false then only the root folder is added and it is required to use dlnaDmsPublishContentAdd to publish the content of the published storage. This is not recommended until unless it is required to restrict the media to be shared. In some instances, this can be used for sharing limited PVR content.
The in_storageObjectRights specifies the Object Rights for the content of the folder. Any Object rights specified for the folder shall be applied to all the content within the folder
*/
DLNA_API TDMSReturn
dlnaDmsPublishStorageAdd(TDMS self, TDMSPublishStorage *in_storage, TDMSObjectRights *in_storageObjectRights);


/*!
\par Function:
Updates the published folder/storage
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMS Instance</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_storage</td>
                <td>TDMSPublishStorage pointer specifying the storage to be updated</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_storageObjectRights</td>
                <td>TDMSObjectRights, pointer specifying the storage object rights</td>
        </tr>
</table>

\return DMS_SUCCESS Succeeded
\return DMS_INVALID_PARAM Invalid parameter
\par Description:
This function updates the previously added storage i.e. it triggers re-indexing of the already shared folder/storage if the storage is set to auto-index. This API can be used on the systems where auto updates are not possible i.e. if the system does not support Inotify.
This API can also be used to refresh the storage.
*/
DLNA_API TDMSReturn
dlnaDmsPublishStorageUpdate(TDMS self, TDMSPublishStorage *in_storage, TDMSObjectRights *in_storageObjectRights);

/*!
\par Function:
Deletes the published folder/storage
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMS Instance</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_path</td>
                <td>Path of the storage/folder to be removed</td>
        </tr>
</table>

\return DMS_SUCCESS Succeeded
\return DMS_INVALID_PARAM Invalid parameter
\par Description:
This function deletes the storage/folder that has been already published.
*/
DLNA_API TDMSReturn
dlnaDmsPublishStorageRemove(TDMS self, slim_char* in_path);

DLNA_API TDMSReturn
dlnaDmsPublishStorageGetDefaultUploadFolder(TDMS self, const slim_char ** const  out_path);
DLNA_API TDMSReturn
dlnaDmsPublishStorageSetDefaultUploadFolder(TDMS self, slim_char * in_path);
DLNA_API TDMSReturn
dlnaDmsPublishStorageSetStorageCentralDir(TDMS self, slim_char* in_config_path);

/*!
\par Function:
Adds a virtual folder
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMS Instance</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_containerInfo</td>
                <td>pointer to TDMSPublishVirtualContainer, specifying the virtual folder</td>
        </tr>
</table>

\return DMS_SUCCESS Succeeded
\return DMS_INVALID_PARAM Invalid parameter
\par Description:
This function adds a virtual folder to the CDS of DMS. This API can be used to organize the content being published to the desired folders. The folder title, id and parent are specified by in_containerInfo.
Virtual folders can be created for live content to represent the Channels and associate the live streams to these virtual folders.
Virtual folders can be created for PVR and Online Content to organize the content published.

*/
DLNA_API TDMSReturn
dlnaDmsPublishVirtualContainerAdd(TDMS self, TDMSPublishVirtualContainer *in_containerInfo);

/*!
\par Function:
Deletes a virtual folder previously added
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMS Instance</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_containerId</td>
                <td>Id of the container to be deleted</td>
        </tr>
</table>

\return DMS_SUCCESS Succeeded
\return DMS_INVALID_PARAM Invalid parameter
\par Description:
This function deletes the previously added folder. This API does not delete the virtual folders existing by default. It only deletes those folders which were previously added.

*/
DLNA_API TDMSReturn
dlnaDmsPublishVirtualContainerDelete(TDMS self, slim_char *in_containerId);

/*!
\par Function:
Publishes a stream/content
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMS Instance</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_contentInfo</td>
                <td>pointer to TDMSPublishContent, specifying the content to be published</td>
        </tr>
</table>

\return DMS_SUCCESS Succeeded
\return DMS_INVALID_PARAM Invalid parameter
\par Description:
This API publishes the content specified by in_contentInfo. This API can be used to publish Live, Online, PVR Recorded, Local content. It requires the parent for the content to be specified so that the content is not orphaned and appended to a folder for better representation.
Any allocations should be freed by the caller after the function returns.

*/
DLNA_API TDMSReturn
dlnaDmsPublishContentAdd(TDMS self, TDMSPublishContent *in_contentInfo);

/*!
\par Function:
Publishes a stream/content
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMS Instance</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_contentInfo</td>
                <td>pointer to TDMSPublishContent, specifying the content to be updated</td>
        </tr>
</table>

\return DMS_SUCCESS Succeeded
\return DMS_INVALID_PARAM Invalid parameter
\par Description:
This function updates the metadata of the previously published content. This function can be used to update the additional resources especially the transcoded resources.

*/
DLNA_API TDMSReturn
dlnaDmsPublishContentUpdate(TDMS self, TDMSPublishContent *in_contentInfo);

/*!
\par Function:
Deletes the content previously added
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMS Instance</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_contentId</td>
                <td>Id of the content to be deleted</td>
        </tr>
</table>

\return DMS_SUCCESS Succeeded
\return DMS_INVALID_PARAM Invalid parameter
\par Description:
This function deletes the previously published content by its full path. A folder cannot be deleted by this API.
*/
DLNA_API TDMSReturn
dlnaDmsPublishContentDelete(TDMS self, slim_char *in_contentId);

DLNA_API TDMSReturn
dlnaDmsGetPublishedStorages(TDMS self, slim_word in_start_index, slim_word in_request_count, TDMSPublishContent **out_content_list, slim_word *out_number_returned, slim_word *out_total_count);

DLNA_API TDMSReturn
dlnaDmsGetPublishedStorageContents(TDMS self, slim_char* in_storage_id, slim_word in_start_index, slim_word request_count, TDMSPublishContent **out_content_list, slim_word *out_number_returned, slim_word *out_total_count);

DLNA_API TDMSReturn
dlnaDmsGetPublishedStorageContentByType(TDMS self, TDMSContentBrowseType in_type, slim_word in_start_index, slim_word request_count, TDMSPublishContent **out_content_list, slim_word *out_number_returned, slim_word *out_total_count);
#endif /* DEVELOPMENT_ENABLE_PUBLISH_CONTENT */

#ifdef DEVELOPMENT_CONTENT_AGGREGATION
DLNA_API TDMSReturn
dlnaDmsCASetEnabled (TDMS self, slim_bool in_enable);

DLNA_API TDMSReturn
dlnaDmsCAGetEnabled (TDMS self, slim_bool *out_enabled);

DLNA_API TDMSReturn
dlnaDmsCASetDBSelectionMode (TDMS self, TDMSCADatabaseSelectionMode in_mode);

DLNA_API TDMSReturn
dlnaDmsCAGetDBSelectionMode (TDMS self, TDMSCADatabaseSelectionMode *out_mode);

DLNA_API TDMSReturn
dlnaDmsCASetDatabaseLocation (TDMS self, slim_char *in_caDatabaseLocation);

DLNA_API slim_char *
dlnaDmsCAGetDatabaseLocation (TDMS self);

DLNA_API TDMSReturn
dlnaDmsCASetDefaultIndexing (TDMS self, TDMSCAIndex in_index);

DLNA_API TDMSReturn
dlnaDmsCAGetDefaultIndexing (TDMS self, TDMSCAIndex *out_index);

DLNA_API TDMSReturn
dlnaDmsCAGetDeviceList (TDMS self, TDMSCADeviceObject **out_list);

DLNA_API TDMSReturn
dlnaDmsCASetDeviceIndexing (TDMS self, slim_char *in_uuid, TDMSCAIndex in_index);

DLNA_API TDMSReturn
dlnaDmsCASetDBSizeLimit (TDMS self, slim_int in_size);

DLNA_API TDMSReturn
dlnaDmsCAGetDBSizeLimit (TDMS self, slim_int *out_size);

DLNA_API TDMSReturn
dlnaDmsCASetPurgeTime (TDMS self, slim_int in_time);

DLNA_API TDMSReturn
dlnaDmsCAGetPurgeTime (TDMS self, slim_int *out_time);

DLNA_API TDMSReturn
dlnaDmsCASetRescanInterval (TDMS self, slim_int in_interval);

DLNA_API TDMSReturn
dlnaDmsCAGetRescanInterval (TDMS self, slim_int *out_interval);

DLNA_API TDMSReturn
dlnaDmsCAExecuteCommand (TDMS self, TDMSCACommand in_cmd);

DLNA_API TDMSReturn
dlnaDmsCAGetState (TDMS self, TDMSCAState *out_state);

#endif /* DEVELOPMENT_CONTENT_AGGREGATION */

DLNA_API TDMSReturn
dlnaDmsGetServerState (TDMS self, slim_int *out_state);

DLNA_API TDMSReturn
dlnaDmsSetServerState(TDMS self, slim_int in_state);

DLNA_API TDMSReturn
dlnaDmsGetWebUIPort(TDMS self, slim_int *out_port);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DMS_API_H */

