/*
 * nflc_upnp.h
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

#ifndef NFLC_UPNP_H
#define NFLC_UPNP_H

#include <nflc_upnp_api.h>

#include <nflc_sxml.h>
#ifdef DLNA_SUPPORT_XSRS
#include <nflc_xsrs.h>
#endif /* DLNA_SUPPORT_XSRS */

typedef enum {
  UPNP_CONTROL_ACTION_REQUEST,
  UPNP_CONTROL_ACTION_RESULT,
  UPNP_CONTROL_ACTION_REPLY,
  UPNP_CONTROL_GET_VAR_REQUEST,
  UPNP_CONTROL_GET_VAR_RESULT,

  UPNP_DISCOVERY_DEVICE_UPDATE,
  UPNP_DISCOVERY_DEVICE_BYEBYE,
  UPNP_DISCOVERY_DEVICE_TIMEOUT,

  UPNP_DESCRIPTION_SERVICE_RESULT,

  UPNP_EVENT_SUBSCRIPTION_START,        /* Send to service after every addition of subscription */
  UPNP_EVENT_SUBSCRIPTION_REQUEST,      /* Request subscription information from service */
  UPNP_EVENT_SUBSCRIPTION_UPDATE,       /* Update subscription information so that service can remove VALIABLE changes */
  UPNP_EVENT_SUBSCRIPTION_STOP,         /* Send to service before every remove of subscription */
  UPNP_EVENT_VARIABLE_UPDATE,
  UPNP_EVENT_RENEWAL_COMPLETE,
  UPNP_EVENT_SUBSCRIBE_COMPLETE,
  UPNP_EVENT_UNSUBSCRIBE_COMPLETE,
  UPNP_EVENT_AUTORENEWAL_FAILED,
  UPNP_EVENT_SUBSCRIPTION_EXPIRED,
  UPNP_EVENT_OUT_OF_MEMORY,
#ifdef DEVELOPMENT_CONTENT_AGGREGATION
  UPNP_EVENT_UDN_UPDATE,                /* Notify UDN update event */
#endif /* DEVELOPMENT_CONTENT_AGGREGATION */

  UPNP_CONTENT_PLAY_UPDATE,
  UPNP_CONTENT_DOWNLOAD_UPDATE,
  UPNP_CONTENT_UPLOAD_UPDATE, 
  UPNP_CONTENT_UPLOAD_CHECK,

#ifdef DLNA_SUPPORT_RUIPL
    UPNP_RUI_UILIST_UPDATE,
//KKRUI
// 3rd party notifications
    UPNP_RUI_EV_NOTIFY,
    UPNP_RUI_EV_NOTIFY_EMERGENCY,
    UPNP_RUI_EV_NOTIFY_FAULT,
    UPNP_RUI_EV_NOTIFY_WARNING,
    UPNP_RUI_EV_NOTIFY_INFO,
    UPNP_RUI_EV_NOTIFY_GENERAL,
//CEA-2014-B
    UPNP_RUI_EV_NOTIFY_TIMEEVENT_REMINDER,
    UPNP_RUI_EV_NOTIFY_TIMEEVENT_ALERT,
    UPNP_RUI_EV_NOTIFY_TIMEEVENT_TASKFINISHED,

	UPNP_RUI_EV_NOTIFY_MEDIAEVENT_RECOMMENDATION,
	UPNP_RUI_EV_NOTIFY_MEDIAEVENT_NEWCONTENT,
	UPNP_RUI_EV_NOTIFY_MEDIAEVENT_RSS,
	UPNP_RUI_EV_NOTIFY_MEDIAEVENT_EXPIRATION,

	UPNP_RUI_EV_NOTIFY_INFRASTRUCTURE_MAINTENANCE,
	UPNP_RUI_EV_NOTIFY_INFRASTRUCTURE_RECONFIGURATION,

	UPNP_RUI_EV_NOTIFY_NAMEDEVENT,
#endif /* DLNA_SUPPORT_RUIPL */

	UPNP_SERVER_INTERFACE_ADDR_UP,
	UPNP_SERVER_INTERFACE_ADDR_DOWN,
	UPNP_SERVER_INITIALIZED,
	UPNP_SERVER_FINALIZED
} upnp_event_t;

typedef enum {
  UPNP_UPLOAD_FILE,
  UPNP_CREATE_CHILDCONTAINER,
  UPNP_UPLOAD_STREAM,
  UPNP_OTHER
} create_object_type;

#ifdef DLNA_SUPPORT_RUIPL
typedef enum
  {
    UPNP_RUI_WINDOW_TYPE_POPUP,
    UPNP_RUI_WINDOW_TYPE_BAR
} upnp_rui_window_type ;

/* RUI Level. */
enum {
  UPNP_DEV_RUI_LEVEL_UNKNOWN = -1,
  UPNP_DEV_RUI_LEVEL0,
  UPNP_DEV_RUI_LEVEL1,
  UPNP_DEV_RUI_LEVEL2,
  UPNP_DEV_RUI_END
};

typedef slim_int upnp_rui_level_type;
#endif /* DLNA_SUPPORT_RUIPL */

/* SOAP error number.  */
#define SOAP_INVALID_ACTION                     (401)
#define SOAP_INVALID_ARGS                       (402)
#define SOAP_OUT_OF_SYNC                        (403)
#define SOAP_INVALID_VAR                        (404)
#define SOAP_ACTION_FAILED                      (501)
#define SOAP_OUT_OF_MEMORY                      (601)
#define SOAP_ACTION_NOT_IMPLEMENTED             (602)

#define SOAP_CDS_NO_SUCH_OBJECT                 (701)
#define SOAP_CDS_NO_MATCH_CURRENT_STATE         (702)
#define SOAP_CDS_INVALID_NEW_TAG_VALUE          (703)
#define SOAP_CDS_NO_MATCH_UPDATA_COUNT          (706)
#define SOAP_CDS_INVALID_SEARCH_CRITERIA        (708)
#define SOAP_CDS_INVALID_SORT_CRITERIA          (709)
#define SOAP_CDS_NO_SUCH_CONTAINER              (710)
#define SOAP_CDS_RESTRICTED_OBJECT              (711)
#define SOAP_CDS_BAD_METADATA                   (712)
#define SOAP_CDS_RESTRICTED_PARENT_OBJECT       (713)
#define SOAP_CDS_NO_SUCH_RESOURCE               (714)
/* Following are proprietary error code, starting from 800 */
#define SOAP_CDS_NO_SPACE_AVAILABLE             (800)
#define SOAP_CDS_NO_UPLOAD_CONTAINER            (801)

#ifdef DEVELOPMENT_CDS2
#define SOAP_CDS_SOURCE_RESOURCE_ACCESS_DENIED  (715)
#endif /* DEVELOPMENT_CDS2 */

#define SOAP_CMS_INCOMPATIBLE_PROTOCOL_INFO     (701)
#define SOAP_CMS_INCOMPATIBLE_DIRECTIONS        (702)
#define SOAP_CMS_INSUFFICIENT_NETWORK_RESOURCES (703)
#define SOAP_CMS_LOCAL_RESTRICTIONS             (704)
#define SOAP_CMS_ACCESS_DENIED                  (705)
#define SOAP_CMS_INVALID_CONNECTION_REFERENCE   (706)
#define SOAP_CMS_NOT_IN_NETWORK                 (707)

#ifdef DEVELOPMENT_CMS2

/*maximum number of simultaneous connections we can't use it
 * because we don't know how big will be connection table*/
#define SOAP_CMS_V2_CONNECTION_TABLE_OVERFLOW								(708)

/*device does not have sufficient internal processing resources to handle the new connection
 * we don't use it because we don't know how big will be internal processing resources*/
#define SOAP_CMS_V2_INTERNAL_PROCESSING_RESOURCES_EXCEEDED	(709)

/*device does not have sufficient internal memory resources to handle the new connection*/
#define SOAP_CMS_V2_INTERNAL_MEMORY_RESOURCES_EXCEEDED			(710)

/*device does not have sufficient internal storage system capabilities to handle the new connection
 * we don't use it because we don't know how big will be internal storage system capabilities*/
#define SOAP_CMS_V2_INTERNAL_STORAGE_SYSTEM_CAPABILITIES_EXCEEDED	(711)
#endif /*DEVELOPMENT_CMS2*/

#define SOAP_AVTS_INVALID_TRANSITION            (701)
#define SOAP_AVTS_TRANSPORT_LOCKED              (705)
#define SOAP_AVTS_SEEK_MODE_NOT_SUPPORTED       (710)
#define SOAP_AVTS_ILLEGAL_SEEK_TARGET           (711)
#define SOAP_AVTS_ILLEGAL_MIME_TYPE             (714)
#define SOAP_AVTS_CONTENT_BUSY                  (715)
#define SOAP_AVTS_RESOURCE_NOT_FOUND            (716)
#define SOAP_AVTS_PLAY_SPEED_NOT_SUPPORTED      (717)
#define SOAP_AVTS_INVALID_INSTANCE_ID           (718)

#define SOAP_RCS_INVALID_NAME                   (701)
#define SOAP_RCS_INVALID_INSTANCE_ID            (702)

#ifdef DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2
#define SOAP_BMS_ACTION_NOT_AUTHORIZED          (606)
#define SOAP_BMS_INTERFACE_NOT_FOUND            (701)
#define SOAP_BMS_INTERFACE_NOT_RESETTABLE       (702)
#define SOAP_BMS_TEST_ALREADY_ACTIVE            (703)
#define SOAP_BMS_CAPABILITIES_PRECLUDE_TEST     (704)
#define SOAP_BMS_STATE_PRECLUDES_TEST           (705)
#define SOAP_BMS_NO_SUCH_TEST                   (706)
#define SOAP_BMS_WRONG_TEST_TYPE                (707)
#define SOAP_BMS_INVALID_TEST_STATE             (708)
#define SOAP_BMS_STATE_PRECLUDES_CANCEL         (709)
#define SOAP_BMS_NO_SUCH_LOG                    (710)
#define SOAP_BMS_LOG_NOT_CONFIGURABLE           (711)
#define SOAP_BMS_INVALID_TEST_ENDPOINT          (712)
#endif /* DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2 */

#ifdef DEVELOPMENT_ENABLE_LPE
#define SOAP_LPE_INVALID_VALUE         (600)
#define SOAP_LPE_STRING_TOO_LONG       (605)
#define SOAP_LPE_INVALID_ID            (701)
#endif /* DEVELOPMENT_ENABLE_LPE */
/* Buffer line size.  */
#ifndef NFLC_LINE_SIZE
#define NFLC_LINE_SIZE  (180)
#endif /* NFLC_LINE_SIZE */

#ifndef NFLC_URL_SIZE
#define NFLC_URL_SIZE (1024)
#endif

#ifndef NFLC_OBJECT_ID_SIZE
#define NFLC_OBJECT_ID_SIZE (256)
#endif

/* UPnP control point type.  */
typedef enum {
  UPNP_CP_TYPE_UNKNOWN,
#ifdef DLNA_SUPPORT_RUIPL
	UPNP_CP_TYPE_RUISCP_LEVEL1, //KKRUI
	UPNP_CP_TYPE_RUISCP_LEVEL2, //KKRUI
#endif /* DLNA_SUPPORT_RUIPL */
#ifdef DEVELOPMENT_DLNA_SUPPORT_DMPR
  UPNP_CP_TYPE_DMPrCP, //KK DMPr
#endif /* DEVELOPMENT_DLNA_SUPPORT_DMPR */
#ifdef DEVELOPMENT_DLNA_SUPPORT_HMA
	UPNP_CP_TYPE_LIGHTPOWERCP,
#endif	
#ifdef DLNA_SUPPORT_SATIP
  UPNP_CP_TYPE_SATIP,
#endif /* DLNA_SUPPORT_SATIP */
#ifdef DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2
  UPNP_CP_TYPE_DMCP,
#endif /* DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2 */
#ifdef DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1
  UPNP_CP_TYPE_LPCP,
#endif /* DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1 */
#ifdef DEVELOPMENT_DLNA_SUPPORT_RA
  UPNP_CP_TYPE_RADACP, 	
  UPNP_CP_TYPE_RACCP, 
  UPNP_CP_TYPE_RASCP, 	
  UPNP_CP_TYPE_WCDCP, 	
  UPNP_CP_TYPE_IGDCP, 	
  UPNP_CP_TYPE_LDCP, 
#endif /* DEVELOPMENT_DLNA_SUPPORT_RA */
  UPNP_CP_TYPE_ANYCP,
  UPNP_CP_TYPE_MSCP,
  UPNP_CP_TYPE_MRCP
} upnp_cp_t;

/* UPnP callback function.  */
typedef slim_int (*upnp_callback_t) (upnp_event_t event, void *param, void *info);

/* UPnP transport state.  */
typedef enum {
  UPNP_TRANSPORT_STATE_NO_MEDIA = 0,
  UPNP_TRANSPORT_STATE_STOPPED,
  UPNP_TRANSPORT_STATE_PLAYING,
  UPNP_TRANSPORT_STATE_PAUSED_PLAY,
  UPNP_TRANSPORT_STATE_TRANSITION,
#ifdef USE_TRICK_PLAY
  UPNP_TRANSPORT_STATE_FASTFORWARD,
  UPNP_TRANSPORT_STATE_REWIND,
#endif /* USE_TRICK_PLAY */
  UPNP_TRANSPORT_STATE_IGNORE,
  UPNP_TRANSPORT_STATE_MAX
} upnp_transport_state_t;

/* UPnP transport events.  */
typedef enum {
  UPNP_TRANSPORT_EVENT_OPEN = 0,
  UPNP_TRANSPORT_EVENT_PLAY,
  UPNP_TRANSPORT_EVENT_PAUSE,
  UPNP_TRANSPORT_EVENT_JUMP,
  UPNP_TRANSPORT_EVENT_STOP,
#ifdef USE_TRICK_PLAY
  UPNP_TRANSPORT_EVENT_FASTFORWARD,
  UPNP_TRANSPORT_EVENT_REWIND,
#endif /* USE_TRICK_PLAY */    
  UPNP_TRANSPORT_EVENT_UPDATE,
  UPNP_TRANSPORT_EVENT_READ,
  UPNP_TRANSPORT_EVENT_WRITE,
  UPNP_TRANSPORT_EVENT_CLOSE,
#ifdef HAVE_WMDRM
  UPNP_TRANSPORT_EVENT_SEEKTIME,
#endif /* HAVE_WMDRM */
  UPNP_TRANSPORT_EVENT_ERROR,
  UPNP_TRANSPORT_EVENT_CANCEL,
  UPNP_TRANSPORT_EVENT_EOS,
  UPNP_TRANSPORT_EVENT_PREV,
  UPNP_TRANSPORT_EVENT_NEXT,
  UPNP_TRANSPORT_EVENT_MAX
} upnp_transport_event_t;

/* UPnP transport error value.  */
typedef enum {
  UPNP_TRANSPORT_ERROR_OK = 0,
  UPNP_TRANSPORT_ERROR_GENERIC,
  UPNP_TRANSPORT_ERROR_TIMEOUT,
  UPNP_TRANSPORT_ERROR_SESSION_ERROR,
  UPNP_TRANSPORT_ERROR_AKE_FAILED,
  UPNP_TRANSPORT_ERROR_AKE_SUCCESS,
  UPNP_TRANSPORT_ERROR_MAX
} upnp_transport_error_t;

/* UPnP parameter for the transport update.  */
struct upnp_param_transport
{
  /* Transport ID.  */
  slim_int tid;

  /* Transport state.  */
  upnp_transport_state_t state;

  /* Transport event.  */
  upnp_transport_event_t event;

  /* Event error.  */
  slim_int transport_error;

  /* DLNA player flags.  */
  slim_word flags;

  /* Title. */
  slim_char *title;

  /* URI.  */
  slim_char *uri;

  /* Path.  */
  slim_char *path;

  /* Current bytes.  */
  dlna_uint64 current_bytes;

  /* Total bytes.  */
  dlna_uint64 total_bytes;

  /* Duration.  */
  slim_word duration;

  /* Percent.  */
  slim_int percent;

  /* Renderer UDN.  */
  slim_char *dmr_udn;

  /* XML document.  */
  sXML *doc;
};

struct upnp_param_check 
{
  struct upnp_param_transport param_transport;
  slim_bool cancel;
  slim_bool stop;
};
typedef struct upnp_param_check upnp_param_check_t;

typedef struct upnp_update_param_
{
  slim_char *full_path;
  slim_char *url;

  dlna_uint64 size;
  slim_char *title;
  slim_char *upnp_class;
  slim_char *date;
  slim_char *pinfo;
  slim_char *import_uri;
  slim_char *parent_id;
  slim_int create_type;
  slim_word dlna_managed;

  void     *dms_device;

  slim_char *upnp_channelName;
  slim_int upnp_channelNr;
  slim_char *upnp_rating;
  slim_char *upnp_radioBand;
  slim_char **upnp_genre;
  slim_char *upnp_scheduledStartTime;
  slim_char *upnp_scheduledEndTime;
  slim_char *upnp_res_duration;

  slim_char *dc_date;
  slim_char *dc_description;  

  slim_char *arib_object_type;
  slim_char *arib_long_description;
  slim_char *arib_copy_control_info;

#if defined (HAVE_DTCP)
  slim_int drm_cci;
#endif /* defined (HAVE_DTCP) */
  slim_char *xsrs_reservationID;
  void     *object_eh;
  void *arg;
} upnp_update_param_t;

struct upnp_create_folder_param
{
  slim_char *title;
  slim_char *upnp_class;
  /* The argument can include one or more <upnp_createClass></upnp_createClass> elements. */
  slim_char *upnp_createClass;
  slim_char *parent_id;
  slim_word dlna_managed;

};
typedef struct upnp_create_folder_param upnp_create_folder_param_t;

/* UPnP SID size.  */
#define UPNP_SID_SIZE (41)

/* UPnP SID. */
typedef slim_char upnp_sid_t[44];

/* When we don't want to run timer.  */
#define UPNP_TIMER_INFINITE       (-1)

/* MAX macro.  */
#ifndef MAX
#define MAX(a,b)	((a) > (b) ? (a) : (b))
#endif /* MAX */

/* Minimum macro.  */
#ifndef MIN
#define MIN(a,b)	((a) < (b) ? (a) : (b))
#endif /* MIN */

/* Minimum delay.  */
#define MINIMUM_DELAY (10)

/* Read buffer size used by upnp_server.c and gena_client.c.  */
#define UPNP_READ_BUFSIZ   (1024)

/* Content Type of DLNA.  */
#define DLNA_CONTENT_TYPE "Content-Type: text/xml; charset=\"utf-8\"\r\n"

/* UPnP device types.  */
#define UPNP_DEVICE_TYPE_ALL	(slim_char *) "urn:schemas-upnp-org:device:"
/*To denote any device such as BMS*/
#define UPNP_DEVICE_TYPE_ANY    UPNP_DEVICE_TYPE_ALL
#define UPNP_DEVICE_TYPE_CE	(slim_char *) "urn:schemas-ce-org:device:"
#define UPNP_DEVICE_TYPE_SES  (slim_char *) "urn:ses-com:device:"

#define UPNP_DEVICE_TYPE_MSD	UPNP_DEVICE_TYPE_ALL "MediaServer:1"
#define UPNP_DEVICE_TYPE_MRD	UPNP_DEVICE_TYPE_ALL "MediaRenderer:1"
#define UPNP_DEVICE_TYPE_RUISD_LEVEL1	(slim_char *) "urn:schemas-ce-org:device:RemoteUIServerDevice:1"
#define UPNP_DEVICE_TYPE_RUISD_LEVEL2	(slim_char *) "urn:schemas-upnp-org:device:RemoteUIServerDevice:1"
#define UPNP_DEVICE_TYPE_BD  UPNP_DEVICE_TYPE_ALL "Basic:1"
#define UPNP_DEVICE_TYPE_MDD UPNP_DEVICE_TYPE_ALL "ManageableDevice:2"
#define UPNP_DEVICE_TYPE_DMPrD	UPNP_DEVICE_TYPE_ALL "Printer:1"
#define UPNP_DEVICE_TYPE_RADAD	UPNP_DEVICE_TYPE_ALL "RADiscoveryAgent:1"
#define UPNP_DEVICE_TYPE_RAC	UPNP_DEVICE_TYPE_ALL "RAClient:1"
#define UPNP_DEVICE_TYPE_RAS	UPNP_DEVICE_TYPE_ALL "RAServer:1"
#define UPNP_DEVICE_TYPE_LIGHTPOWER	UPNP_DEVICE_TYPE_ALL "BinaryLight:0.9"
#define UPNP_DEVICE_TYPE_SATIP  UPNP_DEVICE_TYPE_SES "SatIPServer:1"

/* UPnP service types.  */
#define UPNP_SERVICE_TYPE_ALL	(slim_char *) "urn:schemas-upnp-org:service:"
#ifdef DEVELOPMENT_CDS2
#define UPNP_SERVICE_TYPE_CDS	 UPNP_SERVICE_TYPE_ALL "ContentDirectory:2"
#else /* DEVELOPMENT_CDS2 */
#define UPNP_SERVICE_TYPE_CDS UPNP_SERVICE_TYPE_ALL "ContentDirectory:1"
#endif /* DEVELOPMENT_CDS2 */

#define UPNP_SERVICE_TYPE_CMS	UPNP_SERVICE_TYPE_ALL "ConnectionManager:1"
#define UPNP_SERVICE_TYPE_RCS	UPNP_SERVICE_TYPE_ALL "RenderingControl:1"
#define UPNP_SERVICE_TYPE_AVTS	UPNP_SERVICE_TYPE_ALL "AVTransport:1"

#ifdef DLNA_SUPPORT_SRS
#define UPNP_SERVICE_TYPE_SRS	UPNP_SERVICE_TYPE_ALL "ScheduledRecording:2"
#endif /* DLNA_SUPPORT_SRS */
																												
#ifdef DLNA_SUPPORT_RUIPL
#define UPNP_SERVICE_TYPE_RUIS_LEVEL1 (slim_char*)"urn:schemas-ce-org:service:RemoteUIServer:1"
#define UPNP_SERVICE_TYPE_RUIS_LEVEL2 (slim_char*)"urn:schemas-upnp-org:service:RemoteUIServer:1"
#endif /* DLNA_SUPPORT_RUIPL */

#ifdef DEVELOPMENT_DLNA_SUPPORT_DMPR
//TBD: we have to replace UPNP_SERVICE_TYPE_DMPr by the 2 specific ones
#define UPNP_SERVICE_TYPE_DMPr	UPNP_SERVICE_TYPE_ALL "PrintEnhanced:1"
#define UPNP_SERVICE_TYPE_PRINT_BASIC	UPNP_SERVICE_TYPE_ALL "PrintBasic:1"
#define UPNP_SERVICE_TYPE_PRINT_ENHANCED	UPNP_SERVICE_TYPE_ALL "PrintEnhanced:1"
#endif /* DEVELOPMENT_DLNA_SUPPORT_DMPR */

#ifdef DEVELOPMENT_DLNA_SUPPORT_HMA
#define UPNP_SERVICE_TYPE_LIGHTPOWER	UPNP_SERVICE_TYPE_ALL "SwitchPower:1"
#endif /* DEVELOPMENT_DLNA_SUPPORT_HMA */

#ifdef DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2
#define UPNP_SERVICE_TYPE_BMS UPNP_SERVICE_TYPE_ALL "BasicManagement:2"
#endif /* DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2 */

#ifdef DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1
#define UPNP_SERVICE_TYPE_EMS UPNP_SERVICE_TYPE_ALL "EnergyManagement:1"
#endif /* DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1 */

#ifdef DEVELOPMENT_DLNA_SUPPORT_RA
#define UPNP_SERVICE_TYPE_RADA_SYNC    UPNP_SERVICE_TYPE_ALL "RADASync:1"
#define UPNP_SERVICE_TYPE_RADA_CONFIG  UPNP_SERVICE_TYPE_ALL "RADAConfig:1"
#define UPNP_SERVICE_TYPE_RATA_CONFIG  UPNP_SERVICE_TYPE_ALL "RATAConfig:1"
#define UPNP_SERVICE_TYPE_INBOUND_CONNECTION_CONFIG	UPNP_SERVICE_TYPE_ALL "InboundConnectionConfig:1"
#endif /* DEVELOPMENT_DLNA_SUPPORT_RA */

/* UPnP Service ID prefix.  */
#define UPNP_SERVICE_ID_PREFIX          (slim_char *) "urn:upnp-org:serviceId:"
#define UPNP_SERVICE_ID_PREFIX_LEN      dlna_strlen (UPNP_SERVICE_ID_PREFIX)

#define UPNP_SERVICE_ID_CDS     UPNP_SERVICE_ID_PREFIX "ContentDirectory"
#define UPNP_SERVICE_ID_CMS     UPNP_SERVICE_ID_PREFIX "ConnectionManager"
#define UPNP_SERVICE_ID_RCS     UPNP_SERVICE_ID_PREFIX "RenderingControl"
#define UPNP_SERVICE_ID_AVTS    UPNP_SERVICE_ID_PREFIX "AVTransport"
#define UPNP_SERVICE_ID_PRINT_BASIC    UPNP_SERVICE_ID_PREFIX "PrintBasic"
#define UPNP_SERVICE_ID_PRINT_ENHANCED    UPNP_SERVICE_ID_PREFIX "PrintEnhanced"

/* Keep those strings always defined to handle the XMMRR on client site */
#define URN_MICROSOFT_SERVICE_ID_PREFIX_UPNP_COMPATIBLE       (slim_char *) "urn:microsoft-com:serviceId:"
#define URN_MICROSOFT_SERVICE_ID_PREFIX_LEN_UPNP_COMPATIBLE   dlna_strlen (URN_MICROSOFT_SERVICE_ID_PREFIX_UPNP_COMPATIBLE)
#define URN_MICROSOFT_SERVICE_ID_XMMRRS_UPNP_COMPATIBLE       URN_MICROSOFT_SERVICE_ID_PREFIX_UPNP_COMPATIBLE "X_MS_MediaReceiverRegistrar"
#define URN_MICROSOFT_SERVICE_ID_PREFIX          (slim_char *) "urn:microsoft.com:serviceId:"
#define URN_MICROSOFT_SERVICE_ID_PREFIX_LEN      dlna_strlen (URN_MICROSOFT_SERVICE_ID_PREFIX)
#define URN_MICROSOFT_SERVICE_ID_XMMRRS          URN_MICROSOFT_SERVICE_ID_PREFIX "X_MS_MediaReceiverRegistrar"
#define URN_MICROSOFT_SERVICE_TYPE_PREFIX        (slim_char *) "urn:microsoft.com:service:"
#define URN_MICROSOFT_SERVICE_TYPE_XMMRRS        URN_MICROSOFT_SERVICE_TYPE_PREFIX "X_MS_MediaReceiverRegistrar:1"

#ifdef DLNA_SUPPORT_SPTV_EXT
#include "xsrs_sprl.h"
#endif


#ifdef HAVE_WMDRM
/* WindowsMedia DRM Media Receiver Registrar Service type */
#define WMDRM_SERVICE_TYPE_RR	(slim_char *) "urn:microsoft.com:service:X_MS_MediaReceiverRegistrar:1"
#endif /* HAVE_WMDRM */


struct upnp_content_access_param
{
#define MAC_ADDRESS_STR_LEN     (24)
  slim_char mac_address[MAC_ADDRESS_STR_LEN + 1];

  slim_int id;

  dlna_uint64 current_bytes;

  slim_bool has_total_bytes;

  dlna_uint64 total_bytes;
};

typedef struct upnp_content_access_param upnp_content_access_param_t;

#endif /* _NFLC_UPNP_H */
