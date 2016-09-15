/*
 * dlna_api.h
 * Copyright (C) 2007-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_DLNA_API_H
#define NFLC_DLNA_API_H

/* UPnP device types.  */
#define DLNA_DEVICE_TYPE_MSD   (1)
#define DLNA_DEVICE_TYPE_MRD   (2)

/* UPnP service types.  */
#define DLNA_SERVICE_TYPE_CDS   (1)
#define DLNA_SERVICE_TYPE_CMS   (2)
#define DLNA_SERVICE_TYPE_RCS   (3)
#define DLNA_SERVICE_TYPE_AVTS  (4)

#define DLNA_SERVICE_TYPE_USER  (1000)
#define DLNA_SERVICE_TYPE_XSRS  (DLNA_SERVICE_TYPE_USER+1)

#ifdef DLNA_SUPPORT_RUIPL
#define DLNA_SERVICE_TYPE_RUIS_LEVEL1  (5)
#define DLNA_SERVICE_TYPE_RUIS_LEVEL2  (6)
#define DLNA_RUI_UI_MAX_NUM 100
#define DLNA_RUI_URL_LEN 1024

#ifdef DEVELOPMENT_DLNA_SUPPORT_DMPR
#define DLNA_SERVICE_TYPE_DMPr	(7)
#endif /* DEVELOPMENT_DLNA_SUPPORT_DMPR */

#else

#ifdef DEVELOPMENT_DLNA_SUPPORT_DMPR
#define DLNA_SERVICE_TYPE_DMPr	(5)
#endif /* DEVELOPMENT_DLNA_SUPPORT_DMPR */

#endif /* DLNA_SUPPORT_RUIPL */

#ifdef DEVELOPMENT_DLNA_SUPPORT_RA
#define DLNA_SERVICE_TYPE_RADA	(8)
#endif /* DEVELOPMENT_DLNA_SUPPORT_RA */

enum dlna_device_icon_type_
{
  DLNA_PNG_LRG_ICO = 0,  /* PNG 120x120   */
  DLNA_PNG_SM_ICO,       /* PNG 48x48     */
  DLNA_JPEG_LRG_ICO,     /* JPEG 120x120  */
  DLNA_JPEG_SM_ICO,      /* JPEG 48x48    */
  DLNA_PNG_ANY_ICO,      /* Any PNG size  */
  DLNA_JPEG_ANY_ICO,     /* Any JPEG size */
  DLNA_ICO_END           /* End of list   */
};
typedef enum dlna_device_icon_type_ dlna_device_icon_type;


/* DLNA events.  */
enum {
  DLNA_EV_START = 0, /* Please keep this one the first one. */
  DLNA_EV_FOUND_DEVS = 1,
  DLNA_EV_BYEBYE,
  DLNA_EV_UNAVAILABLE,
  DLNA_EV_DEVICE_SUID_CHG,
  DLNA_EV_DEVICE_CUIDS_CHG,
  DLNA_EV_DEVICE_TIDS_CHG,
  DLNA_EV_DEVICE_LAST_CHG,
  DLNA_EV_DEVICE_OUT_OF_MEMORY,
#ifdef DLNA_SUPPORT_RUIPL
  DLNA_EV_FOUND_UI,
  DLNA_EV_RUI_NOTIFY,
	DLNA_EV_GENA_UI_LISTING_UPDATE,
#endif /* DLNA_SUPPORT_RUIPL */
#ifdef DEVELOPMENT_DLNA_SUPPORT_DMPR
	DLNA_EV_GENA_DMPR_PRINTER_STATE,
	DLNA_EV_GENA_DMPR_PRINTER_STATE_REASONS,
	DLNA_EV_GENA_DMPR_JOB_ID_LIST,
	DLNA_EV_GENA_DMPR_JOB_MEDIA_SHEETS_COMPLETED,
	DLNA_EV_GENA_DMPR_CONTENT_COMPLETE_LIST,
	DLNA_EV_GENA_DMPR_JOB_ABORT_STATE,
	DLNA_EV_GENA_DMPR_JOB_END_STATE,
#endif /* DEVELOPMENT_DLNA_SUPPORT_DMPR */
	DLNA_EV_GENA_DMRCMS_CURRENT_CONNECTION_IDS,
#ifdef DEVELOPMENT_ENABLE_LPC
	DLNA_EV_GENA_NETWORK_INTERFACE_INFO,
#endif /* DEVELOPMENT_ENABLE_LPC */
#ifdef DEVELOPMENT_DLNA_SUPPORT_RA
	DLNA_EV_GENA_RADA_SYSTEM_INFO_UPDATE_ID_CHANGED,
#endif
  DLNA_EV_GENA,
  DLNA_EV_END /* Please keep this one the last one. */
};

/*!
TDLNAEvent is a value that represents the type of event set for TDLNAEventHandler() (see "8.1.2
TDLNAEventHandler").

For more information about SystemUpdateID, ContainerUpdateIDs and TransferIDs, see "UPnP AV
ContentDirectory:1 Service Template Version 1.01".

One of the following values is set for TDLNAEvent.

<table>
	<tr>
		<td><b>Definition</b></td>
		<td><b>Event details</b></td>
	</tr>
	<tr>
		 <td>DLNA_EV_FOUND_DEVS</td>
		 <td>Detected device(s)</td>
	</tr>
	<tr>
		 <td>DLNA_EV_BYEBYE</td>
		 <td>Detected ssdp: byebye</td>
	</tr>
	<tr>
		 <td>DLNA_EV_UNAVAILABLE</td>
		 <td>Failed to receive ssdp: alive from a device</td>
	</tr>
	<tr>
		 <td>DLNA_EV_DEVICE_SUID_CHG</td>
		 <td>Received SystemUpdateID notification from DMS on the network</td>
	</tr>
	<tr>
		 <td>DLNA_EV_DEVICE_CUIDS_CHG</td>
		 <td>Received ContainerUpdateIDs notification from DMS on the network</td>
	</tr>
	<tr>
		 <td>DLNA_EV_DEVICE_TIDS_CHG</td>
		 <td>Received TransferIDs notification from DMS on the network</td>
	</tr>
	<tr>
		 <td>DLNA_EV_START</td>
		 <td>Initial value (not used)</td>
	</tr>
	<tr>
		 <td>DLNA_EV_DEVICE_LAST_CHG</td>
		 <td>This value is notified when DMS receives a LastChange state variable (in AVTransport) change in a GENA event message.</td>
	</tr>
	<tr>
		 <td>DLNA_EV_DEVICE_OUT_OF_MEMORY</td>
		 <td>Insufficient memory.</td>
	</tr>
	<tr>
		 <td>DLNA_EV_FOUND_UI</td>
		 <td>Indicates that a check for existance of UI list is done.</td>
	</tr>
	<tr>
		 <td>DLNA_EV_RUI_NOTIFY</td>
		 <td>3rd party notification concerning RUI received.</td>
	</tr>
	<tr>
		 <td>DLNA_EV_GENA_UI_LISTING_UPDATE</td>
		 <td>Notification about change in UI listing.</td>
	</tr>
	<tr>
		 <td>DLNA_EV_GENA_NETWORK_INTERFACE_INFO</td>
		 <td>Notification about change in network interface info.</td>
	</tr>
</table>

*/
typedef slim_int TDLNAEvent;


/* DLNA event error.  */
enum {
    DLNA_EV_ERROR_NONE = 0, /* Please keep this one the first one. */
    DLNA_EV_ERROR_TIMEOUT,
    DLNA_EV_ERROR_GENERIC,

};
typedef slim_int TDLNAEventError;


/* DLNA object event.  */
enum {
  DLNA_OBJECT_EV_START = 0, /* Please keep this one the first one. */
  DLNA_OBJECT_EV_BROWSE_END,
  DLNA_OBJECT_EV_BROWSE_ERROR,
  DLNA_OBJECT_EV_SEARCH_END,
  DLNA_OBJECT_EV_SEARCH_ERROR,
  DLNA_OBJECT_EV_GET_SEARCH_CAPABILITIES_END,
  DLNA_OBJECT_EV_GET_SEARCH_CAPABILITIES_ERROR,
  DLNA_OBJECT_EV_GET_SORT_CAPABILITIES_END,
  DLNA_OBJECT_EV_GET_SORT_CAPABILITIES_ERROR,
  DLNA_OBJECT_EV_GET_SYSTEM_UPDATE_ID_END,
  DLNA_OBJECT_EV_GET_SYSTEM_UPDATE_ID_ERROR,
  DLNA_OBJECT_EV_QUERY_RESULT,

  DLNA_OBJECT_EV_PLAY_OPEN_OK    = 100,
  DLNA_OBJECT_EV_PLAY_OPEN_FAILED,
  DLNA_OBJECT_EV_PLAY_PLAY_OK,
  DLNA_OBJECT_EV_PLAY_PLAY_FAILED,
  DLNA_OBJECT_EV_PLAY_STOP_OK,
  DLNA_OBJECT_EV_PLAY_STOP_FAILED,
  DLNA_OBJECT_EV_PLAY_PAUSE_OK,
  DLNA_OBJECT_EV_PLAY_PAUSE_FAILED,
  DLNA_OBJECT_EV_PLAY_JUMP_OK,
  DLNA_OBJECT_EV_PLAY_JUMP_FAILED,
  DLNA_OBJECT_EV_PLAY_NEXT_OK,
  DLNA_OBJECT_EV_PLAY_NEXT_FAILED,
  DLNA_OBJECT_EV_PLAY_PREVIOUS_OK,
  DLNA_OBJECT_EV_PLAY_PREVIOUS_FAILED,
  DLNA_OBJECT_EV_PLAY_FF_OK,
  DLNA_OBJECT_EV_PLAY_FF_FAILED,
  DLNA_OBJECT_EV_PLAY_RW_OK,
  DLNA_OBJECT_EV_PLAY_RW_FAILED,
  DLNA_OBJECT_EV_PLAY_MEDIA_INFO_OK,
  DLNA_OBJECT_EV_PLAY_MEDIA_INFO_FAILED,
  DLNA_OBJECT_EV_PLAY_POSITION_INFO_OK,
  DLNA_OBJECT_EV_PLAY_POSITION_INFO_FAILED,
  DLNA_OBJECT_EV_PLAY_UPDATED,
  DLNA_OBJECT_EV_PLAY_STATE_CHANGED,
  DLNA_OBJECT_EV_PLAY_CLOSED ,
  DLNA_OBJECT_EV_PLAY_ERROR,
  DLNA_OBJECT_EV_PLAY_OPEN_NEXT_OK,
  DLNA_OBJECT_EV_PLAY_OPEN_NEXT_FAILED,

  DLNA_OBJECT_EV_DL_OPEN           = 200,
  DLNA_OBJECT_EV_DL_UPDATE,
  DLNA_OBJECT_EV_DL_PAUSE,
  DLNA_OBJECT_EV_DL_CLOSE,
  DLNA_OBJECT_EV_DL_CANCELED,
  DLNA_OBJECT_EV_DL_ERROR,

  DLNA_OBJECT_EV_UPLOAD_FILE    = 300,
  DLNA_OBJECT_EV_UPLOAD_STREAM,
  /* sub-event type for +up+ */
  SUB_EVENT_CREATE_OBJECT_SUCCESS                   =400, /* create object success */ 
  SUB_EVENT_UPLOAD_BEGIN,     /* upload begin */
  SUB_EVENT_UPLOAD_END,       /* upload end */
  SUB_EVENT_UPLOAD_CANCELED,  /* upload canceled */
  SUB_EVENT_UPLOAD_STOPPED,  /* upload stopped */
  SUB_EVENT_UPLOAD_PROGRESS,  /* upload progress */
  SUB_EVENT_ERROR,            /* upload error */
  SUB_EVENT_AKE_SUCCESS,
  SUB_EVENT_AKE_FAILED,
  DLNA_OBJECT_EV_CREATE_FOLDER,
  DLNA_OBJECT_EV_DELETE_OBJECT, 
  DLNA_OBJECT_EV_UPDATE_OBJECT,

  DLNA_OBJECT_EV_STATUS_CHANGED,
  DLNA_OBJECT_EV_AUTOTEST_FINISHED,
#ifdef DLNA_SUPPORT_SRS
  DLNA_OBJECT_EV_CREATE_SCHEDULE_END,
  DLNA_OBJECT_EV_GET_CONFLICT_LIST_END,
  DLNA_OBJECT_EV_DELETE_SCHEDULE_END,
  DLNA_OBJECT_EV_GET_SCHEDULE_LIST_END,
  DLNA_OBJECT_EV_UPDATE_SCHEDULE_END,
  DLNA_OBJECT_EV_GET_TITLE_LIST_END,
  DLNA_OBJECT_EV_DELETE_TITLE_END,
  DLNA_OBJECT_EV_UPDATE_TITLE_END,
  DLNA_OBJECT_EV_SCHEDULE_GET_END,
#endif /* DLNA_SUPPORT_SRS */
#ifdef DLNA_SUPPORT_HDRL
  DLNA_OBJECT_EV_GETRECDESLIST_END,
  DLNA_OBJECT_EV_GETRECDESINFO_END,
  DLNA_OBJECT_EV_GETCONTAINERID_END,
#endif /* DLNA_SUPPORT_HDRL */

  DLNA_OBJECT_EV_GET_DLNA_UPLOAD_PROFILES,
  DLNA_OBJECT_EV_RENDERER_LIST_PRESETS,
  DLNA_OBJECT_EV_RENDERER_SELECT_PRESET,
  DLNA_OBJECT_EV_RENDERER_VOL_GET,
  DLNA_OBJECT_EV_RENDERER_VOL_SET,
  DLNA_OBJECT_EV_RENDERER_VOLDB_GET,
  DLNA_OBJECT_EV_RENDERER_VOLDB_RANGE_GET,
  DLNA_OBJECT_EV_RENDERER_VOLDB_SET,
  DLNA_OBJECT_EV_RENDERER_MUTE_GET,
  DLNA_OBJECT_EV_RENDERER_MUTE_SET,
#ifdef DEVELOPMENT_DLNA_SUPPORT_DMPR
  DLNA_OBJECT_EV_DMPr_PRINT_OK,
  DLNA_OBJECT_EV_DMPr_PRINT_FAILED,
  DLNA_OBJECT_EV_DMPr_GET_PRINTER_ATTRIBUTES,
  DLNA_OBJECT_EV_DMPr_CANCEL_JOB,
  DLNA_OBJECT_EV_DMPr_PRINT_FILE_SUCCESS,
  DLNA_OBJECT_EV_DMPr_PRINT_FILE_FAILED,
  DLNA_OBJECT_EV_DMPr_PRINT_URI_SUCCESS,
  DLNA_OBJECT_EV_DMPr_PRINT_URI_FAILED,
#endif /* DEVELOPMENT_DLNA_SUPPORT_DMPR */

#ifdef DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2
  /* C.K.20131024: Modify the event to be compliant with naming rule.
   * DLNA_OBJECT_EV_{device class|device capability}_{service}_{actions}
   * {device capability} := DIAGC (Diagnostic Controller)
   * {service} := BMS (Basic Management Service) */
  DLNA_OBJECT_EV_DIAGC_BMS_GET_DEVICE_STATUS,
  DLNA_OBJECT_EV_DIAGC_BMS_PING,
  DLNA_OBJECT_EV_DIAGC_BMS_GET_PING_RESULT,
  DLNA_OBJECT_EV_DIAGC_BMS_NSLOOKUP,
  DLNA_OBJECT_EV_DIAGC_BMS_GET_NSLOOKUP_RESULT,
  DLNA_OBJECT_EV_DIAGC_BMS_TRACEROUTE,
  DLNA_OBJECT_EV_DIAGC_BMS_GET_TRACEROUTE_RESULT,
  DLNA_OBJECT_EV_DIAGC_BMS_GET_TEST_IDS,
  DLNA_OBJECT_EV_DIAGC_BMS_GET_ACTIVE_TEST_IDS,
  DLNA_OBJECT_EV_DIAGC_BMS_GET_TEST_INFO,
#endif /* DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2 */

#ifdef DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1
  /* DLNA_OBJECT_EV_{device class|device capability}_{service}_{actions}
   * {device capability} := LPC (Low Power Controller)
   * {service} := EMS (Energy Management Service) */
  DLNA_OBJECT_EV_LPC_EMS_GET_INTERFACE_INFO,
  DLNA_OBJECT_EV_LPC_EMS_SERVICE_SUBSCRIPTION,
  DLNA_OBJECT_EV_LPC_EMS_SERVICE_RENEWAL,
  DLNA_OBJECT_EV_LPC_EMS_SERVICE_RELEASE, 
#endif /* DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1 */

  DLNA_OBJECT_EV_GET_SERVICE_DESCRIPTION_END,
  DLNA_OBJECT_EV_GET_SERVICE_DESCRIPTION_ERROR,

#ifdef DEVELOPMENT_DLNA_SUPPORT_RA
  /* RADA Sync */
  DLNA_OBJECT_EV_RADA_ADD_REMOTE_DEVICES,
  DLNA_OBJECT_EV_RADA_REMOVE_REMOTE_DEVICES,
  DLNA_OBJECT_EV_RADA_SET_DDD_LOCATION,
  DLNA_OBJECT_EV_RADA_HEARTBEAT_UPDATE,
  /* RADAConfig */
  DLNA_OBJECT_EV_RADA_GET_SYSTEM_INFO,
  DLNA_OBJECT_EV_RADA_EDIT_FILTER,
  /* RATAConfig */
  DLNA_OBJECT_EV_RATA_GET_TRANSPORT_AGENT_CAPABILITIES,
  DLNA_OBJECT_EV_RATA_GET_SUPPORTED_CREDENTIAL_DELIVERY,
  DLNA_OBJECT_EV_RATA_GET_CREDENTIALS_LIST,
  DLNA_OBJECT_EV_RATA_GET_PROFILE_LIST,
  DLNA_OBJECT_EV_RATA_ADD_PROFILE,
  DLNA_OBJECT_EV_RATA_EDIT_PROFILE,
  DLNA_OBJECT_EV_RATA_DELETE_PROFILE,
  DLNA_OBJECT_EV_RATA_GET_PROFILE_CONFIG_INFO,
#endif /* DEVELOPMENT_DLNA_SUPPORT_RA */

  DLNA_OBJECT_EV_END /* Please keep this one the last one. */
};

/* DLNA object PLAY STATE.  */
enum {
  DLNA_OBJECT_STATE_UNKNOWN = 0,         /* Please keep this one the first one. */
  DLNA_OBJECT_STATE_NO_MEDIA_SPECIFIED,
  DLNA_OBJECT_STATE_STOPPED,
  DLNA_OBJECT_STATE_PLAYING,
  DLNA_OBJECT_STATE_PAUSED,
  DLNA_OBJECT_STATE_TRANSITIONING,
  DLNA_OBJECT_STATE_MAX,

};

/*!
TDLNAObjectEvent is a value that represents the type of event specified for
TDLNAObjectEventHandler() (see "4.2 TDLNAObjectEventHandler").

One of the following values is set for TDLNAObjectEvent.

<table>
	<tr>
		<td><b>Definition</b></td>
		<td><b>Event details</b></td>
	</tr>
	<tr>
		<td>DLNA_OBJECT_EV_DL_OPEN</td>
		<td>Preparation for download is completed</td>
	</tr>
	<tr>
		<td>DLNA_OBJECT_EV_DL_UPDATE</td>
		<td>Processing updates</td>
	</tr>
	<tr>
		<td>DLNA_OBJECT_EV_DL_PAUSE</td>
		<td>Paused while downloading</td>
	</tr>
	<tr>
		<td>DLNA_OBJECT_EV_DL_CLOSE</td>
		<td>Download is completed</td>
	</tr>
	<tr>
		<td>DLNA_OBJECT_EV_DL_ERROR</td>
		<td>Error occurred while downloading</td>
	</tr>
	<tr>
		<td>DLNA_OBJECT_EV_DL_CANCELED</td>
		<td>Canceled while downloading</td>
	</tr>
</table>
*/
typedef slim_int TDLNAObjectEvent;

typedef slim_int TDLNAObjectEventError;

/* DLNA object DRM type.  */
enum {
  DLNA_OBJECT_DRM_TYPE_UNKNOWN = -1,
  DLNA_OBJECT_DRM_TYPE_NONE,
  DLNA_OBJECT_DRM_TYPE_DTCP,
  DLNA_OBJECT_DRM_TYPE_WMDRM,
  DLNA_OBJECT_DRM_TYPE_END /* Please keep this one the last one. */
};

/*!
One of the following bits of DRM information is set for TDLNAObjectDRMType.

<table>
	<tr>
		<td><b>Definition</b></td>
		<td><b>Meaning</b></td>
	</tr>
	<tr>
		<td>DLNA_OBJECT_DRM_TYPE_UNKNOWN</td>
		<td>Unknown DRM information</td>
	</tr>
	<tr>
		<td>DLNA_OBJECT_DRM_TYPE_NONE</td>
		<td>No DRM information</td>
	</tr>
	<tr>
		<td>DLNA_OBJECT_DRM_TYPE_DTCP</td>
		<td>DRM information of DTCP-IP</td>
	</tr>
	<tr>
		<td>DLNA_OBJECT_DRM_TYPE_WMDRM</td>
		<td>DRM information of Windows Media DRM</td>
	</tr>
	<tr>
		<td>DLNA_OBJECT_DRM_TYPE_END</td>
		<td>Maximum value of this type</td>
	</tr>
</table>

*/

typedef slim_int TDLNAObjectDRMType;

/* DLNA object OP type. */
enum {
  DLNA_OBJECT_OP_TYPE_INVALID = -1,
  DLNA_OBJECT_OP_TYPE_NONE, 
  DLNA_OBJECT_OP_TYPE_SEEK_BYTE, 
  DLNA_OBJECT_OP_TYPE_SEEK_TIME, 
  DLNA_OBJECT_OP_TYPE_SEEK_BOTH, 
  DLNA_OBJECT_OP_TYPE_END /* Please keep this one the last one. */
};

/*!
One of the following bits of support information is set for TDLNAObjectOPType.

<table>
	<tr>
		<td><b>Definition</b></td>
		<td><b>Meaning</b></td>
	</tr>
	<tr>
		<td>DLNA_OBJECT_OP_TYPE_NONE</td>
		<td>DLNA.ORG_OP does not exist</td>
	</tr>
	<tr>
		<td>DLNA_OBJECT_OP_TYPE_INVALID</td>
		<td>DLNA.ORG_OP is specified, but is invalid or all 0</td>
	</tr>
	<tr>
		<td>DLNA_OBJECT_OP_TYPE_SEEK_BYTE</td>
		<td>Supports byte seek</td>
	</tr>
	<tr>
		<td>DLNA_OBJECT_OP_TYPE_SEEK_TIME</td>
		<td>Supports time seek</td>
	</tr>
	<tr>
		<td>DLNA_OBJECT_OP_TYPE_SEEK_BOTH</td>
		<td>Supports both byte seek and time seek</td>
	</tr>
	<tr>
		<td>DLNA_OBJECT_OP_TYPE_END</td>
		<td>Maximum value of this type</td>
	</tr>
</table>
*/

typedef slim_int TDLNAObjectOPType;

/* DLNA object TRANSFERMODE */
enum {
  DLNA_OBJECT_TRANSFER_MODE_UNKNOWN = -2,
  DLNA_OBJECT_TRANSFER_MODE_INVALID = -1,
  DLNA_OBJECT_TRANSFER_MODE_STREAMING = 0, 
  DLNA_OBJECT_TRANSFER_MODE_INTERACTIVE, 
  DLNA_OBJECT_TRANSFER_MODE_BACKGROUND, 
  DLNA_OBJECT_TRANSFER_MODE_END /* Please keep this one the last one. */
};

typedef slim_int TDLNAObjectTransferMode;



/* DLNA device type.  */
enum {
  DLNA_DEV_TYPE_START = 0, /* Please keep this one the first one. */
  DLNA_DEV_TYPE_UNKNOWN,
  DLNA_DEV_TYPE_DMS,
  DLNA_DEV_TYPE_M_DMS,
  DLNA_DEV_TYPE_DMR,
  DLNA_DEV_TYPE_DMPr,
  DLNA_DEV_TYPE_DMP,
  DLNA_DEV_TYPE_M_DMP,
  DLNA_DEV_TYPE_DMC,
  DLNA_DEV_TYPE_M_DMC,
  DLNA_DEV_TYPE_M_DMU,
  DLNA_DEV_TYPE_M_DMD,
  DLNA_DEV_TYPE_RUIS_LEVEL1,		
  DLNA_DEV_TYPE_RUIS_LEVEL2,		
  DLNA_DEV_TYPE_RUIS_IBOX,		
  DLNA_DEV_TYPE_LIGHTPOWER,
  DLNA_DEV_TYPE_SATIP,
  DLNA_DEV_TYPE_MDD,
  DLNA_DEV_TYPE_RADA,
  DLNA_DEV_TYPE_RAC,
  DLNA_DEV_TYPE_RAS,
  DLNA_DEV_TYPE_WCD,
  DLNA_DEV_TYPE_IGD,
  DLNA_DEV_TYPE_LD,
  DLNA_DEV_TYPE_ANY,  /* All Device */

  DLNA_DEV_TYPE_END /* Please keep this one the last one. */
};

typedef slim_int TDLNADeviceType;

#ifdef DLNA_SUPPORT_RUIPL
/* RUI Level. */
enum {
  DLNA_DEV_RUI_LEVEL_UNKNOWN = -1,
  DLNA_DEV_RUI_LEVEL0,
  DLNA_DEV_RUI_LEVEL1,
  DLNA_DEV_RUI_LEVEL2,
  DLNA_DEV_RUI_END
};

typedef slim_int TDLNADeviceRUILevel;
#endif /* DLNA_SUPPORT_RUIPL */

/* DLNA API return code.  */
/* Please use minus value because plus value is used to return HTTP error code */
enum {
  /* error code for +up+ */
  DLNA_E_UP_HTTP_TIMEOUT = -65535,
  DLNA_E_UP_HTTP_ERROR,
  DLNA_E_UP_INTERNAL_SERVER_ERROR,
  DLNA_E_UP_NO_SUCH_OBJ,
  DLNA_E_UP_RESTRICTED_OBJ,
  DLNA_E_UP_RESTRICTED_PARENT_OBJ,
  DLNA_E_UP_NO_SUCH_RESOURCE, 
  DLNA_E_UP_RESOURCE_ACCESS_DENIED, 
  DLNA_E_UP_NO_SUCH_CONTAINER, 
  DLNA_E_UP_BAD_METADATA, 
  DLNA_E_UP_BAD_MIME, 
  DLNA_E_UP_NO_SPACE_AVAILABLE,
  DLNA_E_UP_NO_UPLOAD_CONTAINER,
  DLNA_E_UP_INVAL, 
  DLNA_E_UP_GENERIC, 
  DLNA_E_UP_HTTP_SESSION_ERROR,
  DLNA_E_UP_IGNORE,
  DLNA_E_UP_OK        = 0,

  DLNA_E_EXPIRED= -16,
  DLNA_E_FORMAT_INVAL = -15,
  DLNA_E_OBJ_INVAL = -14,
  DLNA_E_NOTFOUND = -13,
  DLNA_E_NOT_SUPPORT = -12,
  DLNA_E_FILE_EX = -11, 
  DLNA_E_FILE_IO = -10,
  DLNA_E_NOFILE  = -9,
  DLNA_E_COMM    = -8,
  DLNA_E_URI     = -7,
  DLNA_E_ITEM_EX = -6,
  DLNA_E_OBJ     = -5,
  DLNA_E_DEV     = -4,
  DLNA_E_NOMEM   = -3,
  DLNA_E_INVAL   = -2,
  DLNA_E_GENERIC = -1,
  DLNA_E_OK      = 0
};

enum {
  /* item is playable according to SinkProtocolInfo from DMR and protocol info from item */
  DLNA_ITEM_PLAYABLE               = 0,
  /* item is NOT playable according to SinkProtocolInfo from DMR and protocol info from item */
  DLNA_ITEM_NOT_PLAYABLE           = -1,
  /* Can not get SinkProtocolInfo from DMR, but you can still also try to play it */
  DLNA_SINK_PROTOCOL_INFO_MISS = -2
};

typedef slim_int DLNA_API_ERROR;


struct _TDLNADnEventHandlerParam {
  slim_char *uri;
  slim_char *title;
  slim_char *path;
  slim_char *percent;

  slim_char *current_bytes;
  slim_char *total_bytes;
};

/*!
TDLNADnEventHandlerParam is a structure of parameters to be notified to the downloader application during the callback.

The memory area of this structure is allocated and released within the NFLC core.

\code

	typedef struct _TDLNADnEventHandlerParam {
		slim_char *uri;
		slim_char *title;
		slim_char *path;
		slim_char *percent;
		
		slim_char *current_bytes;
		slim_char *total_bytes;
	} TDLNADnEventHandlerParam;

\endcode

\par Member:

<table>
	<tr>
		<td>uri</td>
		<td>URI of download object</td>
	</tr>
	<tr>
		<td>title</td>
		<td>Title of download object</td>
	</tr>
	<tr>
		<td>path</td>
		<td>Local file path name of download destination</td>
	</tr>
	<tr>
		<td>percent</td>
		<td>
			Rate of progress accessing content (%) <br />
			Numeric string of value "current_bytes / total_bytes * 100". Set "\0" if "Content-Length" is not found in HTTP header.
		</td>
	</tr>
	<tr>
		<td>current_bytes</td>
		<td>
			Size transferred while accessing content (bytes) <br />
			Numeric string. Always set actual value, regardless of whether Content-Length is in HTTP header.
		</td>
	</tr>
	<tr>
		<td>total_bytes</td>
		<td>
			Size of total content (bytes) <br />
			Numeric string. Set "\0" if "Content-Length" is not found in HTTP header.
		</td>
	</tr>
</table>
*/
typedef struct _TDLNADnEventHandlerParam TDLNADnEventHandlerParam;


#define DLNA_SORT_CRITERIA_TITLE                                               \
  "+dc:title"

#define DLNA_SORT_CRITERIA_ARTIST                                              \
  "+upnp:artist"

#define DLNA_SORT_CRITERIA_DATE                                                \
  "-dc:date"

#define DLNA_SORT_CRITERIA_TRACK                                                \
  "+upnp:originalTrackNumber"

#define DLNA_SORT_CRITERIA_TRACK_TITLE                                        \
	DLNA_SORT_CRITERIA_TRACK "," DLNA_SORT_CRITERIA_TITLE

#define DLNA_SORT_CRITERIA_TITLE_ARTIST                                        \
  DLNA_SORT_CRITERIA_TITLE "," DLNA_SORT_CRITERIA_ARTIST

#define DLNA_SEARCH_CRITERIA_VIDEO                                             \
  "upnp:class derivedfrom \"object.item.videoItem\" and @refID exists false " \
  "and res exists true"

#define DLNA_SEARCH_CRITERIA_AUDIO                                             \
  "(upnp:class derivedfrom \"object.item.audioItem\" and @refID exists false "\
  "and res exists true) or (upnp:class derivedfrom "                          \
  "\"object.container.album.musicAlbum\" and upnp:albumArtURI exists true) "  \
  "or upnp:class derivedfrom \"object.container.playlistContainer\""

#define DLNA_SEARCH_CRITERIA_IMAGE                                             \
  "upnp:class derivedfrom \"object.item.imageItem\" and @refID exists false " \
  "and res exists true"

#define DLNA_SEARCH_FILTER_VIDEO                                               \
  "res,res@protocolInfo,res@resolution,res@size,res@duration,res@bitrate,"    \
  "res@sampleFrequency,res@bitsPerSample,res@nrAudioChannels,dc:date,"        \
  "upnp:genre,upnp:album,upnp:scheduledStartTime,upnp:scheduledEndTime,"      \
  "upnp:channelNr,upnp:icon"

#define DLNA_SEARCH_FILTER_AUDIO                                               \
  "res,res@protocolInfo,res@size,res@duration,res@bitrate,"                   \
  "res@sampleFrequency,res@bitsPerSample,res@nrAudioChannels,dc:date,"        \
  "dc:creator,upnp:artist,upnp:genre,upnp:album,upnp:originalTrackNumber,"    \
  "upnp:albumArtURI,upnp:icon,upnp:playlist"

#define DLNA_SEARCH_FILTER_IMAGE                                               \
  "res,res@protocolInfo,res@resolution,res@size,dc:date,upnp:album,upnp:icon"

/* DLNA API types.  */
typedef void *TDLNA;

/*!
TDLNAObject (hereafter DLNA object) is a pointer to a generic object that allows the DLNA library to handle data internally.

The downloader application must not access the TDLNAObject.
*/
typedef void *TDLNAObject;
typedef void *TDLNAPlayStat;

enum {
  DLNA_BROWSE_DIRECTCHILDREN,
  DLNA_BROWSE_METADATA
};

/* dlnaObjectXXX callback parameter.  */
struct _TDLNAObjectParam
{
  slim_int  err_code;

  /* NumberReturned items.  */
  slim_word NumberReturned;

  /* TotalMatches matches items.  */
  slim_word TotalMatches;

  /* Array of items.  */
  TDLNAObject *ObjectArray;

  slim_char *result;
  slim_char *udn;

  /* String 1 */
  slim_char *String1;

  /* String 2 */
  slim_char *String2;

  slim_int browseType;
};
typedef struct _TDLNAObjectParam TDLNAObjectParam;

struct _TDLNAObjectPresetParam
{
  slim_int    err_code;           /* SOAP error code */
  slim_char   *err_description;   /* SOAP error description */

  slim_char   *presets;           /* Presets in CSV format */
};
typedef struct _TDLNAObjectPresetParam TDLNAObjectPresetParam;

struct _TDLNAObjectVolumeControlEHParam
{
  slim_int   err_code;
  slim_char* err_description;

  slim_char* channel;
  slim_bool mute_state;
  slim_word volume;
  slim_int volume_db;
  slim_int min_volume_db;
  slim_int max_volume_db;
};
typedef struct _TDLNAObjectVolumeControlEHParam TDLNAObjectVolumeControlEHParam;

struct _TDLNAPlayObjectEHParam
{
  slim_int   error;
};

/* The structure is used to stored <res> information of one item. */
struct _TDLNAResPropInfoParam
{
  /* Attributes of <res> element. */
  dlna_uint64 size;            /* unit:bytes  */ 
  slim_word duration;         /* unit:second */
  slim_word bitrate;          /* unit:bits/second */
  slim_word sampleFrequency;  /* unit:HZ */
  slim_word bitsPerSample;
  slim_word nrAudioChannels;
  slim_word colorDepth;
  slim_char* resolution;
  slim_char* protocolInfo;
  slim_char* protection;
  slim_char* importUri;
  /* Value of <res> element. */
  slim_char* uri;
};
typedef struct _TDLNAResPropInfoParam TDLNAResPropInfoParam;

#ifdef ENABLE_SUBTITLE_SUPPORT
struct _TDLNASubtitle {
  slim_char *resURI;
  slim_char *uri;
  slim_char *type;
  slim_char *lang;
  slim_int  streamNo;
};
typedef struct _TDLNASubtitle TDLNASubtitle;
#endif /* ENABLE_SUBTITLE_SUPPORT */

enum {
  DLNA_DTCP_DISABLE_MOVECOPY = 0x00,
  DLNA_DTCP_ENABLE_MOVE = 0x01,
  DLNA_DTCP_ENABLE_COPY = 0x02,
  DLNA_DTCP_ENABLE_MOVECOPY = 0x03
};

struct _TDLNAResPropDtcpInfoParam
{
  slim_int  fMoveCopy;          /* Indicate possibile of Move or Copy  */
  dlna_ip_addr fDstAddr;       /* Source Dest IP Address  */
  slim_int  fDstPort;               /* Source Dest Port number */
};
typedef struct _TDLNAResPropDtcpInfoParam TDLNAResPropDtcpInfoParam;

#ifdef DLNA_SUPPORT_RUIPL
struct _TDLNARUIUIProfile
{
  slim_char *name;
  /* There are some extended attributes in <ui_profile> tag. */
  slim_bool have_ext_atr;
};
typedef struct _TDLNARUIUIProfile TDLNARUIUIProfile;

struct _TDLNARUIMediaProfile
{
  struct _TDLNARUIMediaProfile *prev;
  struct _TDLNARUIMediaProfile *next;

  slim_char *name;
  slim_char *type;

  /* Following attributes belong to audio profile and video profile,
     but now don't support these. */ 
#if 0
  slim_word nrstreams;
  slim_char *scaling;
  slim_char *aspectratio;
  slim_char *transport;
#endif
};
typedef struct _TDLNARUIMediaProfile TDLNARUIMediaProfile;

struct _TDLNARUIUriProfilelistInfo
{
  struct _TDLNARUIUriProfilelistInfo *prev;
  struct _TDLNARUIUriProfilelistInfo *next;

  slim_char *ui_uri;
  slim_int audio_pro_num;
  slim_int video_pro_num;
  TDLNARUIUIProfile ui_profile;

  List (TDLNARUIMediaProfile *) audio_profile;
  List (TDLNARUIMediaProfile *) video_profile;
};
typedef struct _TDLNARUIUriProfilelistInfo TDLNARUIUriProfilelistInfo;

struct _TDLNARUIUriIconlistInfo
{
  struct _TDLNARUIUriIconlistInfo *prev;
  struct _TDLNARUIUriIconlistInfo *next;

  slim_char *icon_uri;
};
typedef struct _TDLNARUIUriIconlistInfo TDLNARUIUriIconlistInfo;

struct _TDLNARUIUIInfo
{
  slim_int uri_profilelist_number;
  slim_int uri_iconlist_number;

  slim_char *ui_name;
  slim_char *ui_description;
  slim_char *ui_short_name;

  List (TDLNARUIUriProfilelistInfo *) uri_profilelist_info;
  List (TDLNARUIUriIconlistInfo *) uri_iconlist_info;
};
typedef struct _TDLNARUIUIInfo TDLNARUIUIInfo;


struct _TDLNARuiNotifyEHParam
{

  /* UDN in SSDP packet.  */
  slim_char *usn;

	slim_int	event_type ;
//	slim_char	*msg ;
	slim_char	*url ;
//	sXML	*doc ;
//	sXML	*profilelist ;
	slim_int	seq ;
	/* CEA-2014-B */
	slim_int	window_type ;
	slim_int	window_width ;
	slim_int	window_height ;
	
};
typedef struct _TDLNARuiNotifyEHParam TDLNARuiNotifyEHParam ;

#endif /* DLNA_SUPPORT_RUIPL */

/* DLNA seek mode */
typedef enum 
{
  DLNA_JUMP_MODE_TRACK_NR = 0,
  DLNA_JUMP_MODE_ABS_TIME,
  DLNA_JUMP_MODE_REL_TIME,
  DLNA_JUMP_MODE_ABS_COUNT,
  DLNA_JUMP_MODE_REL_COUNT,
  DLNA_JUMP_MODE_CHANNEL_FREQ,
  DLNA_JUMP_MODE_TAPE_INDEX,
  DLNA_JUMP_MODE_FRAME
}dlna_jump_mode;

struct _TDLNAObjectJumpParam
{
  dlna_jump_mode jump_mode;
  union {
    slim_word track_nr;
    dlna_duration abs_time;
    dlna_duration rel_time;
    slim_word abs_count;
    slim_word rel_count;
    slim_char *channel_freq;
    slim_word tape_index;
    slim_word frame;
  }u;
};
typedef struct _TDLNAObjectJumpParam TDLNAObjectJumpParam;


struct _TDLNAObjectPositionParam
{
  /*Track*/
  slim_word track;
  /*TrackURI*/
  slim_char *track_uri;
  /*TrackDuration, value equal to slim_nil means "NOT IMPLEMENTED"*/
  dlna_duration *track_duration;
  /*RelTime,  value equal to slim_nil means "NOT IMPLEMENTED"*/
  dlna_duration *rel_time;
  /*AbsTime, value equal to slim_nil means "NOT IMPLEMENTED"*/
  dlna_duration *abs_time;
  /*RelCount, value equal to SLIM_INT_MAX (0x7FFFFFFF) means "NOT IMPLEMENTED"*/
  slim_int  rel_count;
  /*AbsCount, value equal to SLIM_INT_MAX (0x7FFFFFFF) means "NOT IMPLEMENTED"*/
  slim_int  abs_count;
  slim_char *track_metadata;
  slim_char *result;
};
typedef struct _TDLNAObjectPositionParam TDLNAObjectPositionParam;

struct _TDLNAObjectMediaInfoParam
{
  /*NumberOfTracks*/
  slim_word track_num;
  /*CurrentMediaDuration*/
  dlna_duration *media_duration;
  /*AVTransportURI*/
  slim_char *uri;
  /*AVTransportURIMetaData*/
  void *uri_metadata;  
  /*NextAVTransportURI,value equal to slim_nil means "NOT IMPLEMENTED"*/
  slim_char *next_uri;
  /*NextAVTransportURIMetaData,value equal to slim_nil means "NOT IMPLEMENTED"*/
  void *next_uri_metadata;
  /*PlaybackStorageMedium,value equal to slim_nil means "NOT IMPLEMENTED"*/
  slim_char *storage_medium;
  /*RecordStorageMedium,value equal to slim_nil means "NOT IMPLEMENTED"*/
  slim_char *rec_storageMedium;  
  /*RecordMediumWriteStatus, value equal to slim_nil means "NOT IMPLEMENTED"*/
  slim_char *rec_status;
  slim_char *result;
};
typedef struct _TDLNAObjectMediaInfoParam TDLNAObjectMediaInfoParam;

struct _TDLNAObjectTransportInfoParam {
  /* TransportState */
  slim_char *state;
  /* TransportStatus */
  slim_char *status;
  /* CurrentSpeed */
  slim_char *current_speed;
};
typedef struct _TDLNAObjectTransportInfoParam TDLNAObjectTransportInfoParam;


#ifdef DEVELOPMENT_DLNA_SUPPORT_DMPR
enum dlna_dmpr_orientation_
{
	DLNA_DMPR_ORIENTATION_LANDSCAPE,
	DLNA_DMPR_ORIENTATION_PORTRAIT,
	DLNA_DMPR_ORIENTATION_REVERSE_LANDSCAPE,
	DLNA_DMPR_ORIENTATION_REVERSE_PORTRAIT,
	DLNA_DMPR_ORIENTATION_DEVICESETTING
};

enum dlna_dmpr_quality_
{
	DLNA_DMPR_QUALITY_NORMAL,
	DLNA_DMPR_QUALITY_DRAFT,
	DLNA_DMPR_QUALITY_HIGH,
	DLNA_DMPR_QUALITY_DEVICESETTING
};

enum dlna_dmpr_sides_
{
	DLNA_DMPR_SIDES_ONE_SIDE,
	DLNA_DMPR_SIDES_TWO_SIDED_LONG_EDGE,
	DLNA_DMPR_SIDES_TWO_SIDED_SHORT_EDGE,
	DLNA_DMPR_SIDES_DEVICESETTING
};


typedef enum dlna_dmpr_orientation_ dlna_dmpr_orientation;
typedef enum dlna_dmpr_quality_ dlna_dmpr_quality;
typedef enum dlna_dmpr_sides_ dlna_dmpr_sides;


struct _TDMPrMediaList
{
  struct _TDMPrMediaList *next;
  struct _TDMPrMediaList *prev;

	slim_char	*media_type ;
	slim_char	*media_size ;
};
typedef struct _TDMPrMediaList TDMPrMediaList ;


struct _TDLNAObjectDmprParam
{
  dlna_dmpr_orientation orientation;
  slim_char *jobname;
  slim_char *title;
  slim_char *mediatype;
  slim_char *mediasize;
	slim_int	copies ;
	slim_int	fontsize ;
	slim_int	margins ;
	slim_int	border ;
  dlna_dmpr_quality quality;
  slim_int  sides ;

};
typedef struct _TDLNAObjectDmprParam TDLNAObjectDmprParam;

struct _TDLNAObjectDmprParamPrivate
{
  dlna_dmpr_orientation orientation;
  slim_char *jobname;
  slim_char *title;
  slim_char *mediatype;
  slim_char *mediasize;
	slim_int	copies ;
	slim_int	fontsize ;
	slim_int	margins ;
	slim_int	border ;
  dlna_dmpr_quality quality;
  slim_int sides ;

	//internal only
	slim_int	image_width ;
	slim_int	image_height ;
	slim_char	*image_uri ;
	slim_char *page_margins ;
	slim_int	fullbleed ;
};
typedef struct _TDLNAObjectDmprParamPrivate TDLNAObjectDmprParamPrivate;

struct _TDLNAObjectDmprEHParam
{
	slim_int	jobID ;
	slim_int	soap_error_code ;
	slim_int	http_error_code ;
  slim_char* err_description;
};
typedef struct _TDLNAObjectDmprEHParam TDLNAObjectDmprEHParam;

struct _TDLNAObjectDmprAttributesEHParam
{
  slim_int   soap_error_code;
  slim_char* err_description;

	slim_char	*printer_state ;
	slim_char *printer_state_reasons ;
	slim_char *job_id_list ;
	slim_char *job_id ;
	slim_char *internet_connect_state ;
};
typedef struct _TDLNAObjectDmprAttributesEHParam TDLNAObjectDmprAttributesEHParam;

struct _TDLNAObjectDmprJobAttributesEHParam
{
  slim_int   soap_error_code;
  slim_char* err_description;

	slim_char *job_id ;

	slim_char *job_name ;
	slim_char *job_originating_user_name ;
	slim_char *job_media_sheets_completed ;
};
typedef struct _TDLNAObjectDmprJobAttributesEHParam TDLNAObjectDmprJobAttributesEHParam;

#endif /* DEVELOPMENT_DLNA_SUPPORT_DMPR */

#ifdef DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2
struct _TDLNAObjectPingParam
{
  slim_int  soap_error_code;
  slim_char *err_description;
  slim_char *testId;
  slim_char *status;
  slim_char *additionalInfo;
  slim_int   successCount;
  slim_int   failureCount;
  slim_double averageResponseTime;
  slim_double minimumResponseTime;
  slim_double maximumResponseTime;
};
typedef struct _TDLNAObjectPingParam TDLNAObjectPingParam;

struct _TDLNAObjectNSLookupParam {
  slim_int   soap_error_code;
  slim_char* err_description;

  slim_char* testId;
};
typedef struct _TDLNAObjectNSLookupParam TDLNAObjectNSLookupParam;

struct _TDLNAObjectGetNSLookupResultParam {
  slim_int   soap_error_code;
  slim_char* err_description;

  slim_char* status;
  slim_char* additional_info;
  slim_char* success_count;
  slim_char* result;
};
typedef struct _TDLNAObjectGetNSLookupResultParam TDLNAObjectGetNSLookupResultParam;

struct _TDLNAObjectTracerouteParam
{
  slim_word testId;
  slim_char *status;
  slim_char *additionalInfo;
  slim_double responseTime;
  slim_char *hopHosts;
};
typedef struct _TDLNAObjectTracerouteParam TDLNAObjectTracerouteParam;

struct _TDLNAObjectTestIDsInfoParam
{
  slim_char *testIds; /* comma-separated list */
  slim_char *activeTestIds; /* comma-separated list */
  slim_char *type;
  slim_char *state;
};
typedef struct _TDLNAObjectTestIDsInfoParam TDLNAObjectTestIDsInfoParam;

struct _TDLNAObjectGetDeviceStatus
{
  slim_int   soap_error_code;
  slim_char *err_description;

  slim_char *device_status;
};
typedef struct _TDLNAObjectGetDeviceStatus TDLNAObjectGetDeviceStatus;

#endif  /* DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2 */

#ifdef DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1
struct _TDLNAInterfaceInfo {
  slim_char *name;
  slim_char *mode;
  slim_char *ipv4;
  slim_char *wop;   /* WakeOnPattern */
  slim_char *wst;   /* WakeSupportedTransport */
  slim_int  wod;   /* MaxWaitOnDelay */
  slim_int  doze;  /* DozeDuration */
};
typedef struct _TDLNAInterfaceInfo TDLNAInterfaceInfo;

struct _TDLNAObjectGetInterfaceInfoParam {
  slim_int   soap_error_code;
  slim_char *err_description;

  TDLNAInterfaceInfo major;
  TDLNAInterfaceInfo proxied;
};
typedef struct _TDLNAObjectGetInterfaceInfoParam TDLNAObjectGetInterfaceInfoParam;

struct _TDLNAObjectServiceSubscriptionParam {
  slim_int   soap_error_code;
  slim_char *err_description;

  slim_char *serviceSubscriptionID;
  slim_char *duration;
};
typedef struct _TDLNAObjectServiceSubscriptionParam TDLNAObjectServiceSubscriptionParam;

struct _TDLNAObjectServiceRenewalParam {
  slim_int   soap_error_code;
  slim_char *err_description;

  slim_char *duration;
};
typedef struct _TDLNAObjectServiceRenewalParam TDLNAObjectServiceRenewalParam;

struct _TDLNAObjectServiceReleaseParam {
  slim_int   soap_error_code;
  slim_char *err_description;
};
typedef struct _TDLNAObjectServiceReleaseParam TDLNAObjectServiceReleaseParam;
#endif  /* DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1 */

#ifdef DEVELOPMENT_DLNA_SUPPORT_RA

struct _TRADASyncDeviceInfo
{
  // SSDP fields
  slim_char *uuid;
  slim_char *server;
  slim_char *description;
  slim_int max_age;
  slim_char *credential_id;
};
typedef struct _TRADASyncDeviceInfo TRADASyncDeviceInfo;

struct _TDLNAObjectRADASystemInfoEHParam
{
  slim_int soap_error_code ;
  slim_char *err_description;
  slim_char *rada_uuid ;
  slim_char *rada_export_control_mode ;
  slim_char *rata_uuid ;
  slim_char *rata_import_control_mode ;
  TRADASyncDeviceInfo	*local_system_info[128] ;	//FIXME: make that dynamic
  TRADASyncDeviceInfo	*remote_system_info[128] ;
  slim_int count ;
};
typedef struct _TDLNAObjectRADASystemInfoEHParam TDLNAObjectRADASystemInfoEHParam;

struct _TDLNAObjectRADAEHParam
{
  slim_int	soap_error_code ;
  slim_char *err_description;
};
typedef struct _TDLNAObjectRADAEHParam TDLNAObjectRADAEHParam;

#endif /* DEVELOPMENT_DLNA_SUPPORT_RA */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* DLNA event handler.  */
/*!
\par Function:
Callback function that notifies of internally generated event.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMS instance</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>event</td>
		<td>Value that represents type of internally generated event</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument specified by dlnaDmsClientStartDiscoverDms()</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_param</td>
		<td>Notification parameter specified for every event</td>
	</tr>	
</table>

\return DMSCLIENT_E_OK Succeeded
\return Other Failed
\par Description:
This function notifies the DMS application when a DLNA device is discovered, disconnected, or
updated.

The content of in_param differs depending on the value set for event that is notified.

DLNA_EV_FOUND_DEVS is specified just once for event, after searching for devices.

The device information that is obtained must be deleted within this callback if DLNA_EV_BYEBYE or
DLNA_EV_UNAVAILABLE is specified for event when this callback function is called. And, before
deleting the device information, the container information and item information relating to that device
must be deleted. Once items of information are deleted, they cannot be used as arguments of the API.
Use dlnaDmsClientObjectClose() to delete each item of information.

DLNA_EV_DEVICE_SUID_CHG is notified when DMS receives a SystemUpdateID state variable
change in a GENA event message. When this event is notified, DMP should browse all of the
containers on the system updated by the DMS.

DLNA_EV_DEVICE_CUIDS_CHG is notified when DMS receives a ContainerUpdateIDs state variable
change in a GENA event message. When this event is notified, DMP should browse the updated
containers.

DLNA_EV_DEVICE_TIDS_CHG is notified when DMS receives a TransferIDs state variable change in a
GENA event message.

DLNA_EV_DEVICE_LAST_CHG is notified when DMS receives a LastChange state variable change in a
GENA event message.

For more information about SystemUpdateID, ContainerUpdateIDs, TransferIDs, and LastChange, see
"UPnP AV ContentDirectory:3 Service Template Version 1.01".

The following are the data types and content of in_param corresponding to each event.

<table>
	<tr>
		<td><b>DMS event code</b></td>
		<td><b>Type of in_param</b></td>
		<td><b>Content of in_param</b></td>
	</tr>
	<tr>
		<td>DLNA_EV_FOUND_DEVS</td>
		<td>slim_int*</td>
		<td>Pointer to total number of detected devices</td>
	</tr>
	<tr>
		<td>DLNA_EV_BYEBYE</td>
		<td>TDMSClientObject</td>
		<td>Pointer to device that was removed</td>
	</tr>
	<tr>
		<td>DLNA_EV_UNAVAILABLE</td>
		<td>TDMSClientObject</td>
		<td>Pointer to device that was removed</td>
	</tr>
	<tr>
		<td>DLNA_EV_DEVICE_SUID_CHG</td>
		<td>slim_char*</td>
		<td>Pointer to device UDN(UniqueDeviceName)(string)</td>
	</tr>
	<tr>
		<td>DLNA_EV_DEVICE_CUIDS_CHG</td>
		<td>slim_char*</td>
		<td>Pointer to ID (string) of parent directory of container that has changed</td>
	</tr>
	<tr>
		<td>DLNA_EV_DEVICE_TIDS_CHG</td>
		<td>slim_char*</td>
		<td>Pointer to value (string) described in "2.3.20.A_ARG_TYPE_TransferID" of "UPnP AV ContentDirectory:3 Service Template Version 1.01"</td>
	</tr>
	<tr>
		<td>DLNA_EV_DEVICE_LAST_CHG</td>
		<td>slim_char*</td>
		<td>Pointer to value (string) described in "2.3.8. LastChange" of "UPnP AV ContentDirectory:3 Service Template Version 1.01"</td>
	</tr>
</table>

*/
#ifndef DEVELOPMENT_DLNA_EVENT_API
typedef slim_int (*TDLNAEventHandler) (TDLNA self, TDLNAEvent event, void *in_arg,
                                  void *in_param);
#else /* DEVELOPMENT_DLNA_EVENT_API */
typedef slim_int (*TDLNAEventHandler) (TDLNA self, TDLNAEvent event, TDLNAEventError error, void *in_arg,
                                  void *in_param);
#endif /* DEVELOPMENT_DLNA_EVENT_API */

/*!
\par Function: 
Callback function that notifies of each API process result.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>
			Pointer to item information or download control information specified for each API
		</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>event</td>
		<td>Value representing type of event</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument specified for each API</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_param</td>
		<td>Parameter for notifying of each API result</td>
	</tr>
</table>
 
\return DLNA_E_OK Succeeded
\return Other Failed
\par Description:
This function notifies the downloader application of the respective API processing results. This function is called from the context in which the downloader runs.

The following are the items of information of which this function is notified when each API is executed.

The TDLNADnEventHandlerParam structure is only enabled within this function since it is generated or released on the +DN+ library side.

<table>
	<tr>
		<td><b>API</b></td>
		<td><b>in_event</b></td>
		<td><b>in_param</b></td>
	</tr>
	<tr>
		<td>dlnaDNObjectDownload</td>
		<td>DLNA_OBJECT_EV_DL_OPEN</td>
		<td>TDLNADnEventHandlerParam *</td>
	</tr>
	<tr>
		<td>dlnaDNObjectResume</td>
		<td>DLNA_OBJECT_EV_DL_UPDATE</td>
		<td>TDLNADnEventHandlerParam *</td>
	</tr>
	<tr>
		<td>dlnaDNObjectPause</td>
		<td>DLNA_OBJECT_EV_DL_PAUSE</td>
		<td>TDLNADnEventHandlerParam *</td>
	</tr>
	<tr>
		<td>dlnaDNObjectDownload</td>
		<td>DLNA_OBJECT_EV_DL_CLOSE</td>
		<td>TDLNADnEventHandlerParam *</td>
	</tr>
	<tr>
		<td>Respective APIs</td>
		<td>DLNA_OBJECT_EV_DL_ERROR</td>
		<td>slim_char*</td>
	</tr>
	<tr>
		<td>dlnaDNObjectCancel</td>
		<td>DLNA_OBJECT_EV_DL_CANCELED</td>
		<td>TDLNADnEventHandlerParam *</td>
	</tr>
</table>
*/

#ifndef DEVELOPMENT_DLNA_EVENT_API
typedef slim_int (*TDLNAObjectEventHandler) (TDLNAObject self, TDLNAObjectEvent event,
                                        void *in_arg, void *in_param);
#else /* DEVELOPMENT_DLNA_EVENT_API */
typedef slim_int (*TDLNAObjectEventHandler) (TDLNAObject self, TDLNAObjectEvent event, TDLNAObjectEventError error,
void *in_arg, void *in_param);
#endif /* DEVELOPMENT_DLNA_EVENT_API */


/*!
\par Function:
Returns a string with a name of an event assigned to an id supplied as a parameter.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>id</td>
		<td>Number identifying an event</td>
	</tr>
</table>
\return A string with a name of a event.
\return If the id is not recognized then the return string is "No such error".
*/

slim_char*
dlnaGetObjectEventString(slim_int id);

#ifdef __cplusplus
}
#endif /* __cplusplus */

/*
 * AVT:LastChanged status valuable format API.
 */

typedef void *TDLNAStAvtLastChanged;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*!
\par Function:
Creates a 'AVTransport state changed' variable with value specified with in_value used to for notifying that AVTransport state changed.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_value</td>
		<td>Value of the new 'AVTransport state changed' variable</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_val</td>
		<td>A pointer under which a 'AVTransport state changed' variable will be created</td>
	</tr>
</table>
\return A slim_int error code.
\par Return Values:
<table>
	<tr>
		<td> \b Definition</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>DLNA_E_OK</td>
		<td>'AVTransport state changed' variable created successfuly</td>
	</tr>
	<tr>
		<td>DLNA_E_NOMEM</td>
		<td>Not enough memory for creating the 'AVTransport state changed' variable</td>
	</tr>
	<tr>
		<td>DLNA_E_GENERIC</td>
		<td>An error other than ones above</td>
	</tr>
</table>
*/

slim_int
dlnaStAvtLastChangedCreate(slim_char *in_value, TDLNAStAvtLastChanged *out_val);

/*!
\par Function:
Extracts value of 'AVTransport state changed' variable.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>'AVTransport state changed' variable from which value is to be extracted</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_id</td>
		<td>Identificatior of instance of the 'AVTransport state changed' variable</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_name</td>
		<td>Name of the 'AVTransport state changed' variable</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_attr_name</td>
		<td>Name of XML attribute of the node in which the value of the 'AVTransport state changed' variable is stored</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_attr_val</td>
		<td>Value of XML attribute of the node in which the value of the 'AVTransport state changed' variable is stored</td>
	</tr>
</table>
\return Value of the 'AVTransport state changed' variable.
*/

slim_char*
dlnaStAvtLastChangedGetValue(TDLNAStAvtLastChanged self, slim_char *in_id, slim_char *in_name, 
                                  slim_char *in_attr_name, slim_char *in_attr_val);

/*!
\par Function:
Deallocates 'AVTransport state changed' variable given as parameter.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>'AVTransport state changed' variable to be deallocated</td>
	</tr>
</table>
\return None
*/

void
dlnaStAvtLastChangedDispose(TDLNAStAvtLastChanged self);

#ifdef __cplusplus
}
#endif /* __cplusplus */

/*
 * GENA Low Level API
 */

enum {
  DLNA_GENA_EV_START = 0,
  DLNA_GENA_EV_SUBSCRIBE_RESPONSE,
  DLNA_GENA_EV_UNSUBSCRIBE_RESPONSE,
  DLNA_GENA_EV_WARN_TIMOUT,
  DLNA_GENA_EV_NOTIFY
};

/*
 * Gena application event notification
 *
 */
struct _TDLNAGenaNotifyEHParam {
  slim_char  *device_udn;
  slim_char  *service_type;
  slim_char  *name;
  slim_char  *value;
};
typedef struct _TDLNAGenaNotifyEHParam TDLNAGenaNotifyEHParam;


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


typedef void *TGenaClient;

typedef void (*TGenaEventHandler) (TDLNA self, TGenaClient in_gena_client, 
                                   slim_int in_event_id, void *in_gena_eh_arg, 
                                   slim_char *in_name, slim_char *in_value);

/*!
\par Function:
Creates GENA client instance and subscribes it to the DLNA device service specified with in_service parameter.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>device</td>
		<td>A pointer to a DLNA object i.e. the device</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_service</td>
		<td>Type of UpnP service</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_timeout_sec</td>
		<td>Timeout for the service subscription</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_gena_eh</td>
		<td>A pointer to a GENA event handler function</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_gena_eh_arg</td>
		<td>An argument for the GENA event handler function</td>
	</tr>
</table>
\return A pointer to created GENA client.
\return If any error occurred then the returned pointer is slim_nil.
*/

TGenaClient
dlnaGenaClientOpen (TDLNAObject device, slim_int in_service, slim_int timeout_sec, TGenaEventHandler in_gena_eh, void *in_gena_eh_arg);

/*!
\par Function:
Unsubscribes GENA client from any service it was subscribed to and deallocates it.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>A pointer to GENA client</td>
	</tr>
</table>
\return A slim_int error code.
\par Return Values:
<table>
	<tr>
		<td> \b Definition</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>DLNA_E_OK</td>
		<td>Function succeded</td>
	</tr>
	<tr>
		<td>DLNA_E_NOMEM</td>
		<td>Out of memory error</td>
	</tr>
	<tr>
		<td>DLNA_E_GENERIC</td>
		<td>An error other than ones above</td>
	</tr>
</table>
*/

slim_int
dlnaGenaClientClose (TGenaClient self);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DLNA_API_H */

