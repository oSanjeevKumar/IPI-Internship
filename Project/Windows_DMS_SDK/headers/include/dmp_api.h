/*
 * dmp_api.h
 * Copyright (C) 2007-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

/* DMP/DMC API.  */

#ifndef NFLC_DMP_API_H
#define NFLC_DMP_API_H

#include <dlna_peer.h>
#ifdef HAVE_DTCP
#include <nflc_drm_api.h>
#endif /* HAVE_DTCP */
#include <dlna_api.h>

#ifdef _DOXYGEN
#undef DLNA_API
#define DLNA_API
#endif

/**
 * @addtogroup macros
 */
/*@{*/

/* DMP events.  */
#define DMP_E_FORMAT_INVAL                            DLNA_E_FORMAT_INVAL
#define DMP_EV_FOUND_DEVS                             DLNA_EV_FOUND_DEVS
#define DMP_EV_BYEBYE                                 DLNA_EV_BYEBYE
#define DMP_EV_UNAVAILABLE                            DLNA_EV_UNAVAILABLE
#define DMP_EV_DEVICE_SUID_CHG                        DLNA_EV_DEVICE_SUID_CHG
#define DMP_EV_DEVICE_CUIDS_CHG                       DLNA_EV_DEVICE_CUIDS_CHG
#define DMP_EV_DEVICE_TIDS_CHG                        DLNA_EV_DEVICE_TIDS_CHG
#define DMP_EV_DEVICE_LAST_CHG                        DLNA_EV_DEVICE_LAST_CHG
#define DMP_EV_NETIF_IF_ADD                           DLNA_EV_NETIF_IF_ADD
#define DMP_EV_NETIF_IF_DEL                           DLNA_EV_NETIF_IF_DEL
#define DMP_EV_NETIF_ADDR_ADD                         DLNA_EV_NETIF_ADDR_ADD
#define DMP_EV_NETIF_ADDR_DEL                         DLNA_EV_NETIF_ADDR_DEL
#define DMP_EV_GENA_NETWORK_INTERFACE_INFO            DLNA_EV_GENA_NETWORK_INTERFACE_INFO

/*!
TDMPEvent is a value that represents the type of event set for TDMPEventHandler() (see "4.5
TDMPEventHandler").

For more information, see "UPnP AV ContentDirectory:1 Service Template Version 1.01".

One of the following values is set for TDMPEvent.

<table>
	<tr>
		<td><b>Definition</b></td>
		<td><b>Event details</b></td>
	</tr>
	<tr>
		<td>DMP_E_FORMAT_INVAL</td>
		<td>Wrong format.</td>
	</tr>
	<tr>
		<td>DMP_EV_FOUND_DEVS</td>
		<td>DMP detected device(s)</td>
	</tr>
	<tr>
		<td>DMP_EV_BYEBYE</td>
		<td>Detected ssdp: byebye</td>
	</tr>
	<tr>
		<td>DMP_EV_UNAVAILABLE</td>
		<td>Failed to receive ssdp: alive from a device</td>
	</tr>
	<tr>
		<td>DMP_EV_DEVICE_SUID_CHG</td>
		<td>
			Received SystemUpdateID notification from DMS <br />
			DMS contents changed
		</td>
	</tr>
	<tr>
		<td>DMP_EV_DEVICE_CUIDS_CHG</td>
		<td>
			Received ContainerUpdateID notification from DMS <br />
			content when a container is modified
		</td>
	</tr>
	<tr>
		<td>DMP_EV_DEVICE_TIDS_CHG</td>
		<td>
			Received TransferIDs notification from DMS contents
			when file transfers initiated by ImportResource or
			ExportResource started or finished
		</td>
	</tr>
	<tr>
		<td>DMP_EV_DEVICE_LAST_CHG</td>
		<td>This value is notified when DMP receives a LastChange state variable (in AVTransport) change in a GENA event message.</td>
	</tr>
	<tr>
		<td>DMP_EV_NETIF_IF_ADD</td>
		<td>Add network interface.</td>
	</tr>
	<tr>
		<td>DMP_EV_NETIF_IF_DEL</td>
		<td>Delete network interface.</td>
	</tr>
	<tr>
		<td>DMP_EV_NETIF_ADDR_ADD</td>
		<td>Add IP address.</td>
	</tr>
	<tr>
		<td>DMP_EV_NETIF_ADDR_DEL</td>
		<td>Delete IP address.</td>
	</tr>
	<tr>
		<td>DMP_EV_GENA_NETWORK_INTERFACE_INFO</td>
		<td>Network interface information updated from Energy Management Service.</td>
	</tr>
</table>
*/
	
#define TDMPEvent                                     TDLNAEvent

/* DMP object event.  */
#define DMP_OBJECT_EV_START                           DLNA_OBJECT_EV_START
#define DMP_OBJECT_EV_BROWSE_END                      DLNA_OBJECT_EV_BROWSE_END
#define DMP_OBJECT_EV_BROWSE_ERROR                    DLNA_OBJECT_EV_BROWSE_ERROR
#define DMP_OBJECT_EV_SEARCH_END                      DLNA_OBJECT_EV_SEARCH_END
#define DMP_OBJECT_EV_SEARCH_ERROR                    DLNA_OBJECT_EV_SEARCH_ERROR
#define DMP_OBJECT_EV_GET_SEARCH_CAPABILITIES_END     DLNA_OBJECT_EV_GET_SEARCH_CAPABILITIES_END
#define DMP_OBJECT_EV_GET_SEARCH_CAPABILITIES_ERROR   DLNA_OBJECT_EV_GET_SEARCH_CAPABILITIES_ERROR
#define DMP_OBJECT_EV_GET_SORT_CAPABILITIES_END       DLNA_OBJECT_EV_GET_SORT_CAPABILITIES_END
#define DMP_OBJECT_EV_GET_SORT_CAPABILITIES_ERROR     DLNA_OBJECT_EV_GET_SORT_CAPABILITIES_ERROR

#define DMP_OBJECT_EV_PLAY_OPEN_OK                    DLNA_OBJECT_EV_PLAY_OPEN_OK
#define DMP_OBJECT_EV_PLAY_OPEN_FAILED                DLNA_OBJECT_EV_PLAY_OPEN_FAILED
#define DMP_OBJECT_EV_PLAY_PLAY_OK                    DLNA_OBJECT_EV_PLAY_PLAY_OK
#define DMP_OBJECT_EV_PLAY_PLAY_FAILED                DLNA_OBJECT_EV_PLAY_PLAY_FAILED
#define DMP_OBJECT_EV_PLAY_STOP_OK                    DLNA_OBJECT_EV_PLAY_STOP_OK
#define DMP_OBJECT_EV_PLAY_STOP_FAILED                DLNA_OBJECT_EV_PLAY_STOP_FAILED
#define DMP_OBJECT_EV_PLAY_PAUSE_OK                   DLNA_OBJECT_EV_PLAY_PAUSE_OK
#define DMP_OBJECT_EV_PLAY_PAUSE_FAILED               DLNA_OBJECT_EV_PLAY_PAUSE_FAILED
#define DMP_OBJECT_EV_PLAY_JUMP_OK                    DLNA_OBJECT_EV_PLAY_JUMP_OK
#define DMP_OBJECT_EV_PLAY_JUMP_FAILED                DLNA_OBJECT_EV_PLAY_JUMP_FAILED
#define DMP_OBJECT_EV_PLAY_MEDIA_INFO_OK              DLNA_OBJECT_EV_PLAY_MEDIA_INFO_OK
#define DMP_OBJECT_EV_PLAY_MEDIA_INFO_FAILED          DLNA_OBJECT_EV_PLAY_MEDIA_INFO_FAILED
#define DMP_OBJECT_EV_PLAY_UPDATED                    DLNA_OBJECT_EV_PLAY_UPDATED
#define DMP_OBJECT_EV_PLAY_STATE_CHANGED              DLNA_OBJECT_EV_PLAY_STATE_CHANGED
#define DMP_OBJECT_EV_PLAY_CLOSED                     DLNA_OBJECT_EV_PLAY_CLOSED
#define DMP_OBJECT_EV_PLAY_ERROR                      DLNA_OBJECT_EV_PLAY_ERROR
#define DMP_OBJECT_EV_PLAY_POSITION_INFO_OK		DLNA_OBJECT_EV_PLAY_POSITION_INFO_OK
#define DMP_OBJECT_EV_DL_OPEN                         DLNA_OBJECT_EV_DL_OPEN
#define DMP_OBJECT_EV_DL_UPDATE                       DLNA_OBJECT_EV_DL_UPDATE
#define DMP_OBJECT_EV_DL_PAUSE                        DLNA_OBJECT_EV_DL_PAUSE
#define DMP_OBJECT_EV_DL_CLOSE                        DLNA_OBJECT_EV_DL_CLOSE
#define DMP_OBJECT_EV_DL_CANCELED                     DLNA_OBJECT_EV_DL_CANCELED
#define DMP_OBJECT_EV_DL_ERROR                        DLNA_OBJECT_EV_DL_ERROR
#define DMP_OBJECT_EV_GET_DLNA_UPLOAD_PROFILES        DLNA_OBJECT_EV_GET_DLNA_UPLOAD_PROFILES
#define DMP_OBJECT_EV_AUTOTEST_FINISHED               DLNA_OBJECT_EV_AUTOTEST_FINISHED

#ifdef DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2
#define DMP_OBJECT_EV_DIAGC_BMS_GET_DEVICE_STATUS     DLNA_OBJECT_EV_DIAGC_BMS_GET_DEVICE_STATUS
#define DMP_OBJECT_EV_DIAGC_BMS_PING                  DLNA_OBJECT_EV_DIAGC_BMS_PING
#define DMP_OBJECT_EV_DIAGC_BMS_GET_PING_RESULT       DLNA_OBJECT_EV_DIAGC_BMS_GET_PING_RESULT
#define DMP_OBJECT_EV_DIAGC_BMS_NSLOOKUP              DLNA_OBJECT_EV_DIAGC_BMS_NSLOOKUP
#define DMP_OBJECT_EV_DIAGC_BMS_GET_NSLOOKUP_RESULT   DLNA_OBJECT_EV_DIAGC_BMS_GET_NSLOOKUP_RESULT
#define DMP_OBJECT_EV_DIAGC_BMS_TRACEROUTE            DLNA_OBJECT_EV_DIAGC_BMS_TRACEROUTE
#define DMP_OBJECT_EV_DIAGC_BMS_GET_TRACEROUTE_RESULT DLNA_OBJECT_EV_DIAGC_BMS_GET_TRACEROUTE_RESULT
#define DMP_OBJECT_EV_DIAGC_BMS_GET_TEST_IDS          DLNA_OBJECT_EV_DIAGC_BMS_GET_TEST_IDS
#define DMP_OBJECT_EV_DIAGC_BMS_GET_ACTIVE_TEST_IDS   DLNA_OBJECT_EV_DIAGC_BMS_GET_ACTIVE_TEST_IDS
#define DMP_OBJECT_EV_DIAGC_BMS_GET_TEST_INFO         DLNA_OBJECT_EV_DIAGC_BMS_GET_TEST_INFO
#endif /* DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2 */

#ifdef DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1
#define DMP_OBJECT_EV_LPC_EMS_GET_INTERFACE_INFO      DLNA_OBJECT_EV_LPC_EMS_GET_INTERFACE_INFO
#ifdef DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_SUBSCRIPTION
#define DMP_OBJECT_EV_LPC_EMS_SERVICE_SUBSCRIPTION    DLNA_OBJECT_EV_LPC_EMS_SERVICE_SUBSCRIPTION
#define DMP_OBJECT_EV_LPC_EMS_SERVICE_RENEWAL         DLNA_OBJECT_EV_LPC_EMS_SERVICE_RENEWAL
#define DMP_OBJECT_EV_LPC_EMS_SERVICE_RELEASE         DLNA_OBJECT_EV_LPC_EMS_SERVICE_RELEASE
#endif /* DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_SUBSCRIPTION */
#endif /* DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1 */


/*!
TDMPObjectEvent is a value that represents the type of event set by
TDMPObjectEventHandler().

One of the following values is set for TDMPObjectEvent.

<table>
	<tr>
		<td><b>Definition</b></td>
		<td><b>Event details</b></td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_START</td>
		<td>Initial value</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_BROWSE_END</td>
		<td>Browsing ended</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_BROWSE_ERROR</td>
		<td>Error occurred while browsing</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_SEARCH_END</td>
		<td>Search ended</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_SEARCH_ERROR</td>
		<td>Error occurred while searching</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_GET_SEARCH_CAPABILITIES_END</td>
		<td>End of obtaining search capability.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_GET_SEARCH_CAPABILITIES_ERROR</td>
		<td>Error on obtainnig search capability.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_GET_SORT_CAPABILITIES_END</td>
		<td>End of obtaining sort capability.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_GET_SORT_CAPABILITIES_ERROR</td>
		<td>Error on obtainnig sort capability.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_PLAY_OPEN_OK</td>
		<td>Preparation for playing succeded.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_PLAY_OPEN_FAILED</td>
		<td>Preparation for playing failed.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_PLAY_PLAY_OK</td>
		<td>Playing.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_PLAY_PLAY_FAILED</td>
		<td>Playback failed.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_PLAY_STOP_OK</td>
		<td>Playback stopped.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_PLAY_STOP_FAILED</td>
		<td>Playback stopping failed.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_PLAY_PAUSE_OK</td>
		<td>Playback paused.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_PLAY_PAUSE_FAILED</td>
		<td>Playback pausing failed.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_PLAY_JUMP_OK</td>
		<td>Jump is being performed.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_PLAY_JUMP_FAILED</td>
		<td>Jump process failed.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_PLAY_MEDIA_INFO_OK</td>
		<td>Completed getting media information.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_PLAY_MEDIA_INFO_FAILED</td>
		<td>Failed to get media information.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_PLAY_UPDATED</td>
		<td>Updating.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_PLAY_STATE_CHANGED</td>
		<td>Playback state has changed.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_PLAY_CLOSED</td>
		<td>Player terminated.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_PLAY_ERROR</td>
		<td>An error occurred while playing.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_PLAY_POSITION_INFO_OK</td>
		<td>Playback position information was obtained.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_DL_OPEN</td>
		<td>Preparation for download completed.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_DL_UPDATE</td>
		<td>Updating information about ongoing download.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_DL_PAUSE</td>
		<td>Paused while downloading.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_DL_CLOSE</td>
		<td>Download completed.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_DL_CANCELED</td>
		<td>Download canceled.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_DL_ERROR</td>
		<td>Error while downloading.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_GET_DLNA_UPLOAD_PROFILES</td>
		<td>Ready to get upload profiles.</td>
	</tr>
	<tr>
		<td>DMP_OBJECT_EV_AUTOTEST_FINISHED</td>
		<td>Autotest completed.</td>
	</tr>
	<tr>
		<td>UP_OBJECT_EV_UPLOAD_FILE</td>
		<td>Control point for uploading file</td>
	</tr>
	<tr>
		<td>UP_OBJECT_EV_CREATE_FOLDER</td>
		<td>Control point for creating folder</td>
	</tr>
	<tr>
		<td>UP_OBJECT_EV_DELETE_OBJECT</td>
		<td>Control point for deleting file/folder</td>
	</tr>
</table>

<b>*</b> For information about events related to upload, see "NetFront Living Connect v2.0 +UP+ API Specification"

<b>*</b> For information about events related to download, see "NetFront Living Connect v2.0 +DN+ API Specification"
*/

#define TDMPObjectEvent                               TDLNAObjectEvent

/* DMP device type.  */
#define DMP_DEV_TYPE_START                            DLNA_DEV_TYPE_START
#define DMP_DEV_TYPE_UNKNOWN                          DLNA_DEV_TYPE_UNKNOWN
#define DMP_DEV_TYPE_DMS                              DLNA_DEV_TYPE_DMS
#define DMP_DEV_TYPE_M_DMS                            DLNA_DEV_TYPE_M_DMS
#define DMP_DEV_TYPE_DMR                              DLNA_DEV_TYPE_DMR
#define DMP_DEV_TYPE_DMPr                             DLNA_DEV_TYPE_DMPr
#define DMP_DEV_TYPE_DMP                              DLNA_DEV_TYPE_DMP
#define DMP_DEV_TYPE_M_DMP                            DLNA_DEV_TYPE_M_DMP
#define DMP_DEV_TYPE_DMC                              DLNA_DEV_TYPE_DMC
#define DMP_DEV_TYPE_M_DMC                            DLNA_DEV_TYPE_M_DMC
#ifdef DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2
#define DMP_DEV_TYPE_MDD                              DLNA_DEV_TYPE_MDD
#endif /* DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2 */
#ifdef DEVELOPMENT_DLNA_SUPPORT_RA
#define DMP_DEV_TYPE_RADA                             DLNA_DEV_TYPE_RADA
#define DMP_DEV_TYPE_RAC		                          DLNA_DEV_TYPE_RAC
#define DMP_DEV_TYPE_RAS				                      DLNA_DEV_TYPE_RAS
#define DMP_DEV_TYPE_WCD				                      DLNA_DEV_TYPE_WCD
#define DMP_DEV_TYPE_LD				                        DLNA_DEV_TYPE_LD
#endif /* DEVELOPMENT_DLNA_SUPPORT_RA */

#define DMP_DEV_TYPE_ANY                              DLNA_DEV_TYPE_ANY


/*!
One of the following DLNA device types is set for TDMPCDeviceType.

<table>
	<tr>
		<td><b>Definition</b></td>
		<td><b>Event details</b></td>
	</tr>
	<tr>
		<td>DMP_DEV_TYPE_START</td>
		<td>Initial value</td>
	</tr>
	<tr>
		<td>DMP_DEV_TYPE_UNKNOWN</td>
		<td>Unknown device</td>
	</tr>
	<tr>
		<td>DMP_DEV_TYPE_DMS</td>
		<td>DMS</td>
	</tr>
	<tr>
		<td>DMP_DEV_TYPE_M_DMS</td>
		<td>M-DMS</td>
	</tr>
	<tr>
		<td>DMP_DEV_TYPE_DMR</td>
		<td>DMR</td>
	</tr>
	<tr>
		<td>DMP_DEV_TYPE_DMPr</td>
		<td>DMPr</td>
	</tr>
	<tr>
		<td>DMP_DEV_TYPE_DMP</td>
		<td>DMP</td>
	</tr>
	<tr>
		<td>DMP_DEV_TYPE_M_DMP</td>
		<td>M-DMP</td>
	</tr>
	<tr>
		<td>DMP_DEV_TYPE_DMC</td>
		<td>DMC</td>
	</tr>
	<tr>
		<td>DMP_DEV_TYPE_M_DMC</td>
		<td>M-DMC</td>
	</tr>
</table>
*/

#define TDMPDeviceType                                TDLNADeviceType

/* DMP API return code.  */

/*!
Succeeded (=0)
*/

#define DMP_E_OK                                      DLNA_E_OK

/*!
Generic error occurred
*/

#define DMP_E_GENERIC                                 DLNA_E_GENERIC

/*!
Invalid argument(s) specified
*/

#define DMP_E_INVAL                                   DLNA_E_INVAL

/*!
Insufficient memory
*/

#define DMP_E_NOMEM                                   DLNA_E_NOMEM

/*!
Device not available
*/

#define DMP_E_DEV                                     DLNA_E_DEV

/*!
Invalid object
*/

#define DMP_E_OBJ                                     DLNA_E_OBJ

/*!
Specified Item already exists
*/

#define DMP_E_ITEM_EX                                 DLNA_E_ITEM_EX

/*!
Invalid URI
*/

#define DMP_E_URI                                     DLNA_E_URI

/*!
Communication error
*/

#define DMP_E_COMM                                    DLNA_E_COMM

/*!
File not found
*/

#define DMP_E_NOFILE                                  DLNA_E_NOFILE

/*!
File I/O error
*/

#define DMP_E_FILE_IO                                 DLNA_E_FILE_IO

/*!
File already exists
*/

#define DMP_E_FILE_EX                                 DLNA_E_FILE_EX

/*!
Cannot find a target
*/

#define DMP_E_NOTFOUND                                DLNA_E_NOTFOUND
#define DMP_E_OBJ_INVAL                               DLNA_E_OBJ_INVAL

#define DMP_API_ERROR                                 DLNA_API_ERROR

/* DMP ITEM PLAYABLE return code */
#define DMP_ITEM_PLAYABLE                             DLNA_ITEM_PLAYABLE
#define DMP_ITEM_NOT_PLAYABLE                         DLNA_ITEM_NOT_PLAYABLE
#define DMP_SINK_PROTOCOL_INFO_MISS                   DLNA_SINK_PROTOCOL_INFO_MISS

/*DMP PLAY STATE*/
#define DMP_PLAY_STATE_UNKNOWN                        DLNA_OBJECT_STATE_UNKNOWN
#define DMP_PLAY_STATE_NO_MEDIA_SPECIFIED             DLNA_OBJECT_STATE_NO_MEDIA_SPECIFIED
#define DMP_PLAY_STATE_STOPPED                        DLNA_OBJECT_STATE_STOPPED
#define DMP_PLAY_STATE_PLAYING                        DLNA_OBJECT_STATE_PLAYING
#define DMP_PLAY_STATE_PAUSED                         DLNA_OBJECT_STATE_PAUSED
#define DMP_PLAY_STATE_MAX                            DLNA_OBJECT_STATE_MAX


/* DMP Jump Mode */
#define DMP_JUMP_MODE_TRACK_NR      DLNA_JUMP_MODE_TRACK_NR
#define DMP_JUMP_MODE_ABS_TIME      DLNA_JUMP_MODE_ABS_TIME
#define DMP_JUMP_MODE_REL_TIME      DLNA_JUMP_MODE_REL_TIME
#define DMP_JUMP_MODE_ABS_COUNT     DLNA_JUMP_MODE_ABS_COUNT
#define DMP_JUMP_MODE_REL_COUNT     DLNA_JUMP_MODE_REL_COUNT
#define DMP_JUMP_MODE_CHANNEL_FREQ  DLNA_JUMP_MODE_CHANNEL_FREQ
#define DMP_JUMP_MODE_TAPE_INDEX    DLNA_JUMP_MODE_TAPE_INDEX
#define DMP_JUMP_MODE_FRAME         DLNA_JUMP_MODE_FRAME

/*@}*/

/**
 * @addtogroup datatypes
 */
/*@{*/

/* DMP API types.  */

/*!
TDMP is a DMP library instance.

DMP applications must not access the TDMP.
*/

typedef void * TDMP;

/*!
TDMPObject is a pointer to a generic object that allows the DMP library to handle data internally.

DMP applications must not access the TDMPObject (hereafter, DMP object).
*/

typedef void * TDMPObject;
typedef slim_int TDMPPlayState;

/*@}*/


/**
 * @addtogroup macros
 */
/*@{*/

/* DMP event handler.  */

/*!
\par Function:
Callback function that notifies of internally generated event.

\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP instance</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>event</td>
		<td>Value that indicates type of internally generated event</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument specified by dlnaDmpOpen()</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_param</td>
		<td>Notification parameter specified for every in_event</td>
	</tr>
</table>

\return DMP_E_OK Succeeded
\return Other Failed
\par Description:
This function notifies the DMP application when a DLNA device is discovered, disconnected, or updated.

The content of in_param differs depending on the value set for in_event that is notified.

DMP_EV_FOUND_DEVS is specified just once for in_event, after searching for devices.

The device information that is obtained must be deleted within this callback if DMP_EV_BYEBYE or DMP_EV_UNAVAILABLE is specified for in_event when this callback function is called. And, before deleting the device information, the container information and item information relating to that device must be deleted. Once items of information are deleted, they cannot be used as an argument of the API. Use dlnaDmpObjectClose() to delete each item of information.

DMP_EV_DEVICE_SUIDS_CHG is notified when DMP receives a SystemUpdateIDs state variable change as a GENA event message. When this event is notified, DMP should browse all of containers on the system updated DMS.

DMP_EV_DEVICE_CUIDS_CHG is notified when DMP receives a ContainerUpdateIDs state variable change in a GENA event message. When this event is notified, DMP should browse the updated containers.

DMP_EV_DEVICE_TIDS_CHG is notified when DMP receives a TransferIDs state variable change in a GENA event message.

DMP_EV_DEVICE_LAST_CHG is notified when DMP receives a LastChange state variable change in a GENA event message.

For more information about SystemUpdateID, ContainerUpdateIDs, TransferIDs and LastChange, see "UPnP AV ContentDirectory:3 Service Template Version 1.01".

The following are the data types and content of in_param corresponding to  in_event.

<table>
	<tr>
		<td><b>DMP event code</b></td>
		<td><b>Type of in_param</b></td>
		<td><b>Content of in_param</b></td>
	</tr>
	<tr>
		<td>DMP_EV_FOUND_DEVS</td>
		<td>slim_int*</td>
		<td>Pointer to total number of detected devices</td>
	</tr>
	<tr>
		<td>DMP_EV_BYEBYE</td>
		<td>TDMPObject</td>
		<td>Pointer to device that was removed</td>
	</tr>
	<tr>
		<td>DMP_EV_UNAVAILABLE</td>
		<td>TDMPObject</td>
		<td>Pointer to device that was removed</td>
	</tr>
	<tr>
		<td>DMP_EV_DEVICE_SUID_CHG</td>
		<td>TDMPGenaNotifyEHParam*</td>
		<td>Pointer to TDMPGenaNotifyEHParam structure</td>
	</tr>
	<tr>
		<td>DMP_EV_DEVICE_CUIDS_CHG</td>
		<td>TDMPGenaNotifyEHParam*</td>
		<td>Pointer to TDMPGenaNotifyEHParam structure</td>
	</tr>
	<tr>
		<td>DMP_EV_DEVICE_TIDS_CHG</td>
		<td>TDMPGenaNotifyEHParam*</td>
		<td>Pointer to TDMPGenaNotifyEHParam structure</td>
	</tr>
	<tr>
		<td>DMP_EV_DEVICE_LAST_CHG</td>
		<td>TDMPGenaNotifyEHParam*</td>
		<td>Pointer to TDMPGenaNotifyEHParam structure</td>
	</tr>
</table>
*/

#define TDMPEventHandler TDLNAEventHandler

/*!
\par Function:
Callback function that notifies result of each API process.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to device, container, or item information specified for API
		</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>event</td>
		<td>Value that indicates event type</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument specified for API</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_param</td>
		<td>Parameter to notify of API processing result</td>
	</tr>
</table>

\return DMP_E_OK Succeeded
\return Other Failed
\par Description:
This function notified the DMP application of the processing result of each API. This function is called from the context operated by the DMP.

The following is information of which this function is notified when executing each respective API.

Since the TDMPObjectParam structure is generated and released by the DMP library, it is only valid within this function.

<table>
	<tr>
		<td><b>API name</b></td>
		<td><b>in_event</b></td>
		<td><b>in_param</b></td>
	</tr>
	<tr>
		<td>dlnaDmpObjectBrowse</td>
		<td>DMP_OBJECT_EV_BROWSE_END</td>
		<td>TDMPObjectParam*</td>
	</tr>
	<tr>
		<td>dlnaDmpObjectBrowse</td>
		<td>DMP_OBJECT_EV_BROWSE_ERROR</td>
		<td>TDMPObjectParam*</td>
	</tr>
	<tr>
		<td>dlnaDmpObjectSearch</td>
		<td>DMP_OBJECT_EV_SEARCH_END</td>
		<td>TDMPObjectParam*</td>
	</tr>
	<tr>
		<td>dlnaDmpObjectSearch</td>
		<td>DMP_OBJECT_EV_SEARCH_ERROR</td>
		<td>TDMPObjectParam*</td>
	</tr>
</table>

* For information about upload-related events, see "NetFront Living Connect v2.0 +UP+ API Specification"

* For information about download-related events, see "NetFront Living Connect v2.0 +DN+ API Specification"

\note
Browsing/Searching ends once the DMS responds. If it does not respond, then check the connection status as a rule.
 - When TCP connection exceeds 30 seconds for transmitting the SOAP response, the
connection may be terminated in some cases (see "7.2.9.3 Requirement" in "DLNA
Networked Device Interoperability Guidelines").
*/

#define TDMPObjectEventHandler TDLNAObjectEventHandler

/*!
TDMPUpEventHandlerParam is a structure of parameters to be notified to the uploader application
during the callback.

The memory area of this structure is allocated and released within the NFLC core.

\par Member:

<table>
	<tr>
		<td>event_type</td>
		<td>Event type of uploading operation for object event handler</td>
	</tr>
	<tr>
		<td>sub_event</td>
		<td>Subtype of event type for object event handler (if sub-event type exists)</td>
	</tr>
	<tr>
		<td>err_code</td>
		<td>Error code of uploading operation for object event handler<br/>
			UP_E_XXX is set for error code if sub_event is<br/>
			UP_OBJECT_EV_SUB_UPLOAD_ERROR.
		</td>
	</tr>
	<tr>
		<td>info</td>
		<td>Data attached of uploading operation for object event handler</td>
	</tr>
	<tr>
		<td>info_len</td>
		<td>Length of data attached to object event handler (bytes)</td>
	</tr>
	<tr>
		<td>percent</td>
		<td>Rate of progress accessing content (%)<br/>
			Numeric string of value "current_bytes / total_bytes * 100". Set
			"\0" if Content-Length is not found in HTTP header.</td>
	</tr>
	<tr>
		<td>current_bytes</td>
		<td>Size transferred while accessing content (bytes)<br/>
			Numeric string. Always set actual value, regardless of whether Content-
			Length is in HTTP header.
		</td>
	</tr>
	<tr>
		<td>total_bytes</td>
		<td>Size of total content (bytes)<br/>
			Numeric string. Set "\0" if Content-Length is not found in HTTP header.</td>
	</tr>
</table>

*/
#define TDMPUpEventHandlerParam TDLNAUpEventHandleParam
#define TDMPDnEventHandlerParam TDLNADnEventHandlerParam

/*!
TDMPResPropInfoParam is a structure for setting resource properties.

\code
	struct _TDLNAResPropInfoParam
	{
		// Attributes of <res> element. 
		slim_ulong size; // unit:bytes 
		slim_word duration; // unit:second 
		slim_word bitrate; // unit:bits/second 
		slim_word sampleFrequency; // unit:HZ 
		slim_word bitsPerSample;
		slim_word nrAudioChannels;
		slim_word colorDepth;
		slim_char* resolution;
		slim_char* protocolInfo;
		slim_char* protection;
		slim_char* importUri;
		// Value of <res> element. 
		slim_char* uri;
	};
	typedef struct _TDLNAResPropInfoParam TDLNAResPropInfoParam;
	#define TDMPResPropInfoParam TDLNAResPropInfoParam
\endcode

\par Member:

<table>
	<tr>
		<td>size</td>
		<td>Size (bytes)</td>
	</tr>
	<tr>
		<td>duration</td>
		<td>Duration (sec)</td>
	</tr>
	<tr>
		<td>bitrate</td>
		<td>Bit rate</td>
	</tr>
	<tr>
		<td>sampleFrequency</td>
		<td>Sampling frequency (Hz)</td>
	</tr>
	<tr>
		<td>bitsPerSample</td>
		<td>Sampling rate</td>
	</tr>
	<tr>
		<td>nrAudioChannels</td>
		<td>Number of audio channels</td>
	</tr>
	<tr>
		<td>colorDepth</td>
		<td>Color depth</td>
	</tr>
	<tr>
		<td>resolution</td>
		<td>Resolution</td>
	</tr>
	<tr>
		<td>protocolInfo</td>
		<td>Protocol information</td>
	</tr>
	<tr>
		<td>protection</td>
		<td>Encryption information</td>
	</tr>
	<tr>
		<td>importUri</td>
		<td>URI to import</td>
	</tr>
	<tr>
		<td>uri</td>
		<td>Resource URI</td>
	</tr>
</table>
*/

#define TDMPResPropInfoParam TDLNAResPropInfoParam
#define TDMPObjectJumpParam  TDLNAObjectJumpParam

/*!
TDMPResPropDtcpInfoParam is a structure for DTCP information.

\code
struct _TDLNAResPropDtcpInfoParam
{
	slim_int fMoveCopy; // Indicates MOVE/COPY enabled 
	dlna_ip_addr fDstAddr; // Start address in Source device IP address 
	slim_int fDstPort; // DTCP-IP socket port number of Source device 
};
typedef struct _TDLNAResPropDtcpInfoParam _TDLNAResPropDtcpInfoParam;
#define TDMPResPropDtcpInfoParam TDLNAResPropDtcpInfoParam
\endcode

\par Member:

<table>
	<tr>
		<td>fMoveCopy</td>
		<td>
			Shows MOVE or COPY availability status <br />
			DLNA_DTCP_DISABLE_MOVECOPY(0x00) MOVE/COPY disabled <br />
			DLNA_DTCP_ENABLE_MOVE(0x01) MOVE enabled <br />
			DLNA_DTCP_ENABLE_COPY(0x02) COPY enabled <br />
			DLNA_DTCP_ENABLE_MOVECOPY(0x03) MOVE/COPY enabled
		</td>
	</tr>
	<tr>
		<td>fDstAddr</td>
		<td>Source IP address <br />
			For information about the dlna_ip_addr type, see the description of
			"Structures" in "NetFront Living Connect v2.0 Porting Guide". 
		</td>
	</tr>
	<tr>
		<td>fDstPort</td>
		<td>DTCP-IP socket port number of Source</td>
	</tr>
</table>

* This structure is only enabled with the DTCP-IP package
*/

#define TDMPResPropDtcpInfoParam TDLNAResPropDtcpInfoParam

/*!
TDMPGenaNotifyEHParam is a structure for properties to be notified to DMP application with gena events.

\code
	struct _TDLNAGenaNotifyEHParam
	{
		slim_char *device_udn;
		slim_char *service_type;
		slim_char *sid;
		slim_char *name;
		slim_char *value;
	};
	typedef struct _TDLNAGenaNotifyEHParam TDLNAGenaNotifyEHParam;
	#define TDMPGenaNotifyEHParam TDLNAGenaNotifyEHParam
\endcode

\par Member:

<table>
	<tr>
		<td>device_udn</td>
		<td>Unique device name</td>
	</tr>
	<tr>
		<td>service_type</td>
		<td>Service type</td>
	</tr>
	<tr>
		<td>sid</td>
		<td>Subscription ID</td>
	</tr>
	<tr>
		<td>name</td>
		<td>Evented property name</td>
	</tr>
	<tr>
		<td>value</td>
		<td>Evented property value</td>
	</tr>
</table>
*/

#define TDMPGenaNotifyEHParam TDLNAGenaNotifyEHParam
#ifdef ENABLE_SUBTITLE_SUPPORT

/*!
TDMPSubtitle is the structure that stores subtitle information.

\code
	struct _TDMPSubtitle {
		slim_char *resURI;
		slim_char *uri;
		slim_char *type;
		slim_char *lang;
		slim_int streamNo;
	};
	typedef struct _TDMPSubtitle TDMPSubtitle;
\endcode

\par Member:

<table>
	<tr>
		<td>resURI</td>
		<td>Resource URI</td>
	</tr>
	<tr>
		<td>uri</td>
		<td>Subtitle URI</td>
	</tr>
	<tr>
		<td>type</td>
		<td>
			Subtitle type <br />
			embedded embedded <br />
			srt SubRip <br />
			ssa SubStation Alpha <br />
			ass Advanced SubStation Alpha <br />
			usf Universal Subtitle Format <br />
			smi SAMI <br />
			aqt AQTitle <br />
			jss JACOSub <br />
			ttxt MPEG-4 Timed Text <br />
			sub MPSub <br />
			pjs Phoenix Subtitle <br />
			psb PowerDivX <br />
			rt RealText <br />
			ssf Structured Subtitle Format <br />
			sub MicroDVD Subtitle File <br />
			gsub Gloss Subtitle <br />
			idx VobSub
		</td>
	</tr>
	</tr>
	<tr>
		<td>lang</td>
		<td>Subtitle language</td>
	</tr>
	<tr>
		<td>streamNo</td>
		<td>Subtitle stream number, if subtitle is embedded type</td>
	</tr>
</table>
*/

#define TDMPSubtitle TDLNASubtitle
#endif /* ENABLE_SUBTITLE_SUPPORT */

/*@}*/

/**
 * @addtogroup structures
 */
/*@{*/

/* dlnaDmpNew parameter.  */
struct _TDMPNewParam
{
  /* DLNA progress.  */
  dlna_progress progress;

  /* Display parameter.  */
  dlna_player_display_param *display;

  /* Flags.  */
  slim_word flags;
#define DMP_FLAG_AUTOIP (1 << 0)
};

/*!
TDMPNewParam is a structure for setting the parameters of the DMP library.

\code
	struct _TDMPNewParam
	{
		// DLNA progress. 
		dlna_progress progress;
		// Display parameter. 
		dlna_player_display_param *display;
		// Flags. 
		slim_word flags;
	#define DMP_FLAG_AUTOIP (1 << 0)
	};
	typedef struct _TDMPNewParam TDMPNewParam;
\endcode

\par Member:

<table>
	<tr>
		<td>progress</td>
		<td>
			DLNA progress handle <br />
			For information about the dlna_progress type, see the description of
			"Basic Data Types" in "NetFront Living Connect v2.0 Porting Guide", and how to get the DLNA progress, see "Progress Function" of the guide.
		</td>
	</tr>
</table>
*/

typedef struct _TDMPNewParam TDMPNewParam;

/*@}*/

/**
 * @addtogroup macros
 */
/*@{*/

/*!
TDMPObjectParam is a structure of parameters to be notified to the DMP application during the
callback.

The memory area of this structure is allocated and released within the NFLC core.

\code
	struct _TDLNAObjectParam
	{
		 slim_int err_code;
		 
		// ERROR code 
		slim_word NumberReturned;
		// Number of content items obtained 
		slim_word TotalMatches;

		// Total number of content items matching request 
		TDLNAObject *ObjectArray;
		// Array of DMP objects obtained 
		slim_char *String1;
		 
		// Notification string 
		slim_char *String2;
		// Notification string 
	};
	typedef struct _TDLNAObjectParam TDLNAObjectParam;
	#define TDMPObjectParam TDLNAObjectParam
\endcode

\par Member:

<table>
	<tr>
		<td>err_code</td>
		<td>
			Parameter to be notified when an error occurs (0 for successful completion) <br />
			For more information, see "0 Return Values". Also, positive  value not
			defined in "0 Return Values" represents a generic error (it will  abolished in the future).
		</td>
	</tr>
	<tr>
		<td>NumberReturned</td>
		<td>
			Number of content items obtained by dlnaDmpObjectBrowse() or
			dlnaDmpObjectSearch()
		</td>
	</tr>
	<tr>
		<td>TotalMatches</td>
		<td>
			Total number of content items browsed, for results obtained by
			dlnaDmpObjectBrowse(). <br />
			Total number of content items matching search criteria, for results obtained by dlnaDmpObjectSearch()
		</td>
	</tr>
	<tr>
		<td>ObjectArray</td>
		<td>
			Array of DMP objects obtained by dlnaDmpObjectBrowse() or
			dlnaDmpObjectSearch()
		</td>
	</tr>
	<tr>
		<td>String1</td>
		<td>
			String used for notification when error occurs, etc.
		</td>
	</tr>
	<tr>
		<td>String2</td>
		<td>
			String used for notification when error occurs, etc
		</td>
	</tr>
</table>
*/

#define TDMPObjectParam TDLNAObjectParam


/*!
TDMPObjectNSLookupParam is a structure for properties to be notified to DMP application with gena
events.

\code
    struct _TDLNAObjectNSLookupParam {
        slim_int   soap_error_code;
        slim_char* err_description;

        slim_char* testId;
    };
    typedef struct _TDLNAObjectNSLookupParam TDLNAObjectNSLookupParam;
	#define TDMPObjectNSLookupParam TDLNAObjectNSLookupParam
\endcode

\par Member:

<table>
	<tr>
		<td>soap_error_code</td>
		<td>soap error code</td>
	</tr>
	<tr>
		<td>err_description</td>
		<td>soap error description</td>
	</tr>
	<tr>
		<td>testId</td>
		<td>test ID</td>
	</tr>
</table>
*/
#define TDMPObjectNSLookupParam TDLNAObjectNSLookupParam


/*!
TDMPObjectGetNSLookupResultParam is a structure for properties to be notified to DMP application with gena
events.

\code
    struct _TDLNAObjectGetNSLookupResultParam {
        slim_int   soap_error_code;
        slim_char* err_description;

        slim_char* status;
        slim_char* additional_info;
        slim_char* success_count;
        slim_char* result;
    };
    typedef struct _TDLNAObjectGetNSLookupResultParam TDLNAObjectGetNSLookupResultParam;
    #define TDMPObjectGetNSLookupResultParam TDLNAObjectGetNSLookupResultParam

\endcode

\par Member:

<table>
	<tr>
		<td>soap_error_code</td>
		<td>soap error code</td>
	</tr>
	<tr>
		<td>err_description</td>
		<td>soap error description</td>
	</tr>
	<tr>
		<td>status</td>
		<td>the overall success or failure of the test </td>
	</tr>
	<tr>
		<td>additional_info</td>
		<td>a free_format string that can contain additional information about the test result</td>
	</tr>
	<tr>
		<td>success_count</td>
		<td>the number of successful DNS lookups</td>
	</tr>
	<tr>
		<td>result</td>
		<td>an XML document containing the result of the DNS lookup test</td>
	</tr>
</table>
*/
#define TDMPObjectGetNSLookupResultParam TDLNAObjectGetNSLookupResultParam

/*!
TDMPObjectGetDeviceStatus is a structure for properties to be notified to DMP application with gena events.

\code
  struct _TDLNAObjectGetDeviceStatus
  {
    slim_int   soap_error_code;
    slim_char* err_description;

    slim_char *device_status;
  };
  typedef struct _TDLNAObjectGetDeviceStatus TDLNAObjectGetDeviceStatus;
#define TDMPObjectGetDeviceStatus TDLNAObjectGetDeviceStatus
\endcode

\par Member:

<table>
  <tr>
      <td>soap_error_code</td>
      <td>soap error code</td>
  </tr>
  <tr>
      <td>error_desctiption</td>
      <td>soap error descripation</td>
  </tr>
  <tr>
      <td>device_status</td>
      <td>device status</td>
  </tr>
</table>
*/

#define TDMPObjectGetDeviceStatus TDLNAObjectGetDeviceStatus


/*!
TDMPObjectGetInterfaceInfoParam is a structure for properties to be notified to DMP application with gena
events.

\code
    struct _TDLNAObjectGetInterfaceInfoParam {
        slim_int   soap_error_code;
        slim_char* err_description;

        slim_char* networkInterfaceInfo;
		slim_char* proxiedNetworkInterfaceInfo;
    };
    typedef struct _TDLNAObjectGetInterfaceInfoParam TDLNAObjectGetInterfaceInfoParam;
	#define TDMPObjectGetInterfaceInfoParam TDLNAObjectGetInterfaceInfoParam
\endcode

\par Member:

<table>
	<tr>
		<td>soap_error_code</td>
		<td>soap error code</td>
	</tr>
	<tr>
		<td>err_description</td>
		<td>soap error description</td>
	</tr>
	<tr>
		<td>networkInterfaceInfo</td>
		<td>an XML document containing the result of the GetInterfaceInfo</td>
	</tr>
	<tr>
		<td>proxiedNetworkInterfaceInfo</td>
		<td>an XML document containing the result of the GetInterfaceInfo</td>
	</tr>

</table>
*/
#define TDMPObjectGetInterfaceInfoParam TDLNAObjectGetInterfaceInfoParam

/*!
TDMPObjectServiceSubscriptionParam is a structure for properties to be notified to DMP application with gena
events.

\code
    struct _TDLNAObjectServiceSubscriptionParam {
        slim_int   soap_error_code;
        slim_char* err_description;

        slim_char* serviceSubscriptionID;
		slim_char* duration;
    };
    typedef struct _TDLNAObjectServiceSubscriptionParam TDLNAObjectServiceSubscriptionParam;
	#define TDMPObjectServiceSubscriptionParam TDLNAObjectServiceSubscriptionParam
\endcode

\par Member:

<table>
	<tr>
		<td>soap_error_code</td>
		<td>soap error code</td>
	</tr>
	<tr>
		<td>err_description</td>
		<td>soap error description</td>
	</tr>
	<tr>
		<td>serviceSubscriptionID</td>
		<td>an identifier set by the device that is unique to each service subscription request.</td>
	</tr>
	<tr>
		<td>duration</td>
		<td>the actual duration given to the subscription request by the device.</td>
	</tr>
</table>
*/
#define TDMPObjectServiceSubscriptionParam TDLNAObjectServiceSubscriptionParam

/*!
TDMPObjectServiceRenewalParam is a structure for properties to be notified to DMP application with gena
events.

\code
    struct _TDLNAObjectServiceRenewalParam {
        slim_int   soap_error_code;
        slim_char* err_description;

		slim_char* duration;
    };
    typedef struct _TDLNAObjectServiceRenewalParam TDLNAObjectServiceRenewalParam;
	#define TDMPObjectServiceRenewalParam TDLNAObjectServiceRenewalParam
\endcode

\par Member:

<table>
	<tr>
		<td>soap_error_code</td>
		<td>soap error code</td>
	</tr>
	<tr>
		<td>err_description</td>
		<td>soap error description</td>
	</tr>
	<tr>
		<td>duration</td>
		<td>the actual duration given to the subscription request by the device.</td>
	</tr>
</table>
*/
#define TDMPObjectServiceRenewalParam TDLNAObjectServiceRenewalParam

/*!
TDMPObjectServiceReleaseParam is a structure for properties to be notified to DMP application with gena
events.

\code
    struct _TDLNAObjectServiceReleaseParam {
        slim_int   soap_error_code;
        slim_char* err_description;
    };
    typedef struct _TDLNAObjectServiceReleaseParam TDLNAObjectServiceRenewalParam;
	#define TDMPObjectServiceReleaseParam TDLNAObjectServiceRenewalParam
\endcode

\par Member:

<table>
	<tr>
		<td>soap_error_code</td>
		<td>soap error code</td>
	</tr>
	<tr>
		<td>err_description</td>
		<td>soap error description</td>
	</tr>
</table>
*/
#define TDMPObjectServiceReleaseParam TDLNAObjectServiceRenewalParam

/*@}*/

/* Prototypes.  */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function: 
Generates DMP instance. 
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>in_param</td>
		<td>Initial parameter of DMP library</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_work_path</td>
		<td>
			Absolute path to a local data directory used by DMP. If there is no data directory, slim_nil, must be specified.
		</td>
	</tr>
</table>

\return != slim_nil Succeeded (DMP instance)
\return == slim_nil Initialization failed 
\par Description: 
This function generates a DMP instance and initializes the DMP library.

Set the DLNA progress manager descriptor allocated  dlnaProgressAllocPeer() for the progress member of in_param (see dlnaProgressAllocPeer() in "NetFront Living Connect v2.0
Porting Guide").

in_work_path must be specified for indicating a local directory path used by DMP. This value is used only when DMP creates a local renderer device (DMR) by using dlnaDmpCreateLocalDMRDevice(). Otherwise, slim_nil must be specified.

dlnaDmpDelete() is used to delete the instance generated by this function.

This function does not allow multiple DMP instances to be generated.

This function must be called first among all the DMP APIs.
*/
DLNA_API TDMP
dlnaDmpNew (TDMPNewParam *in_param, slim_char *in_work_path, slim_char *in_config_path);

/*!
\par Function: 
Deletes DMP instance.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP instance</td>
	</tr>
</table>

\return None 
\par Description: 
This function deletes a DMP instance.

When the DMP library is started (after successful dlnaDmpOpen()), dlnaDmpClose() must be
called to stop the DMP library before calling this function.

After this function is called, delete the DLNA progress by calling dlnaProgressFreePeer() (see
the description of dlnaProgressFreePeer() in "NetFront Living Connect v2.0 Porting Guide").
*/
DLNA_API void
dlnaDmpDelete (TDMP self);

/*!
\par Function: 
Starts DMP library.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP instance</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_dmp_eh</td>
		<td>Callback function that notifies of internally generated event</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument of in_dmp_eh </td>
	</tr>
</table>

\return DMP_E_OK Succeeded 
\return Other Failed
\par Description: 
This function prepares the protocols to be used for communication by  DMP (SSDP, GENA, SOAP).

Then, it registers an event to send an SSDP packet to seek available DMS or DMR on the network.

Calling dlnaProgressStartPeer() after this function call starts operation of the DMS library (see the description of dlnaProgressStartPeer() in "NetFront Living Connect v2.0 Porting Guide").

Specify a pointer to the callback function that notifies when internal events occur, for in_dmp_eh. Null cannot be specified for it.
*/
DLNA_API slim_int
dlnaDmpOpen (TDMP self, TDMPEventHandler in_dmp_eh, void *in_arg);

/*!
\par Function: 
Stops DMP library.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP instance</td>
	</tr>
</table>

\return None 
\par Description: 
This function stops the protocols (SSDP, GENA, SOAP) used by the DMP for communication.

If the DLNA progress was started by dlnaProgressStartPeer(), then the DLNA progress must be stopped by dlnaProgressStopPeer(), before calling this function (see the description of dlnaProgressStopPeer() in "NetFront Living Connect v2.0 Porting Guide").
*/
DLNA_API void
dlnaDmpClose (TDMP self);

/*!
\par Function: 
Gets number of detected devices. 
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP instance</td>
	</tr>
</table>

\return >= 0 Number of detected devices
\return <0 Failed 
\par Description: 
This function returns the number of detected devices.

When TDMPEvent is notified as DMP_EV_FOUND_DEVS, it is recommended to call this function within
TDMPEventHandler(), and get the total number of devices.
*/
DLNA_API slim_int
dlnaDmpDeviceCount (TDMP self);

/*!
\par Function: 
Gets detected device information.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP instance</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_devs</td>
		<td>Buffer for detected device information (NULL terminated) </td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_beg</td>
		<td>Position to start getting device information (>=0)</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_num</td>
		<td>Number of devices for which to get device information</td>
	</tr>
</table>

\return DMP_E_OK Succeeded 
\return DMP_E_INVAL Invalid argument 
\par Description: 
This function returns detected device information.

It sets in_num number of pointers to detected device information for out_devs[], starting from the position in_beg.

out_devs[] must be prepared with a size of in_num+1 or more. It is necessary to initialize out_devs[] with null.

If the number of devices that can be obtained is less than in_num, then the number of devices that can be obtained is specified.

When TDMPEvent is notified as DMP_EV_FOUND_DEVS, it is recommended to call this function within TDMPEventHandler(), and get the device information.

When DMP is terminated, the device information must be released  dlnaDmpObjectClose().
*/
DLNA_API slim_int
dlnaDmpDeviceList (TDMP self, TDMPObject out_devs[], slim_int in_beg,
                   slim_int in_num);

/*!
\par Function: 
Gets device information corresponding to specified UDN.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP instance</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_udn</td>
		<td>UDN of device information to be obtained</td>
	</tr>
</table>

\return != slim_nil Pointer to device information that matches specified UDN
\return == slim_nil Failed, or corresponding device does not exist 
\par Description: 
This function returns device information matching the specified UDN (Unique Device Name).

Specify a string starting with "uuid:" for in_udn. 
\par Example: 
\code
uuid:xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx
\endcode
*/
DLNA_API TDMPObject
dlnaDmpDeviceLookupByUDN(TDMP self, slim_char *in_udn);

/*!
\par Function:
Function removes all devices from self.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA .</td>
	</tr>
</table>
\return slim_int error code value
\par Return Values:
<table>
	<tr>
		<td> \b DMP_E_OK</td>
		<td> \b All \b devices \b removal \b succed</td>
	</tr>
	<tr>
		<td>DMP_E_GENERIC</td>
		<td>Some error occured and all or part of devices may not be removed</td>
	</tr>
</table>
\par Description:
This function removes all devices upnp client devices queue and dlna client devices queue.
*/

DLNA_API slim_int
dlnaDmpDeviceRemoveAll(TDMP self);

/*!
\par Function:
Updates device information.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP instance</td>
	</tr>
</table>

\return None
\par Description:
This function updates the device information with the latest information. The result is notified by TDMPEventHandler().

Updating of device information is performed regularly by the DMP library. It is not necessary to call this function for getting device information. Call this function only to force the updating of device information.
*/
DLNA_API void
dlnaDmpDeviceSearch(TDMP self);

/*!
\par Function: 
Gets DLNA device type.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to device information obtained by dlnaDmpDeviceList()</td>
	</tr>
</table>

\return DLNA device type (see "3.2.1 TDMPDeviceType")
\par Description: 
This function returns the device type of the specified device.

When TDMPEvent is notified as DMP_EV_FOUND_DEVS, it is recommended to call this function within TDMPEventHandler(), and get the device types.
*/
DLNA_API TDMPDeviceType
dlnaDmpDeviceType(TDMPObject self);

/*!
\par Function:
Allocates and returns string with device base URL in order: "http://address:port" .
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA device type object.</td>
	</tr>
</table>
\return slim_char* pointer to device base url
\par Return Values:
<table>
	<tr>
		<td> \b != slim_nil</td>
		<td> \b Pointer \b to \b device \b base \b URL</td>
	</tr>
	<tr>
		<td>slim_nil</td>
		<td>During getting device error occured or self was not a device type object</td>
	</tr>
</table>
\par Description:
This function allocates and returns string with device base URL.

\par Example:
Returned value looks like: "http://address:port"
*/

DLNA_API slim_char *
dlnaDmpDeviceBaseURL (TDMPObject self);

/*!
\par Function:
Function return device IP address.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA device type object.</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_ip</td>
		<td>pointer to allocated place in memory to store ip.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_len</td>
		<td>size of out_ip allocation.</td>
	</tr>
</table>
\return slim_int error code
\par Return Values:
<table>
	<tr>
		<td> \b DMP_E_OK</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>DMP_E_GENERIC</td>
		<td> Generic error</td>
	</tr>
	<tr>
		<td>DMP_E_DEV</td>
		<td> Slef is not a device type object</td>
	</tr>
	<tr>
		<td>DMP_E_URI</td>
		<td>Error in URI</td>
	</tr>
</table>
\par Description:
This function gets device IP address
remember that to store all IPv4 address allocation size of \b out_ip should be for 16 characters.
*/


DLNA_API slim_int
dlnaDmpDeviceIP (TDMPObject self, slim_char *out_ip, slim_int in_len);

/*!
\par Function:
Function return device mac address.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA device object.</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_mac</td>
		<td>pointer to allocated place in memory to store mac address.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_len</td>
		<td>size of out_mac allocation.</td>
	</tr>
</table>
\return slim_int error code
\par Return Values:
<table>
	<tr>
		<td> \b DMP_E_OK</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>DMP_E_GENERIC</td>
		<td> Generic error</td>
	</tr>
	<tr>
		<td>DMP_E_DEV</td>
		<td> Slef is not a device type object</td>
	</tr>
	<tr>
		<td>DMP_E_URI</td>
		<td>Error in URI</td>
	</tr>
	<tr>
		<td>DMP_E_NOMEM</td>
		<td>Out of memory</td>
	</tr>
</table>
\par Description:
This function gets device MAC address
remember that to store all MAC address allocation size of \b out_mac should be for 16 characters.
*/

DLNA_API slim_int
dlnaDmpDeviceMACAddress (TDMPObject self, slim_char *out_mac, slim_int in_len);

/*!
\par Function: 
Cancels API request for DMS on the network.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to device, container, or item information specified for API</td>
	</tr>
</table>

\return None 
\par Description: 
This function cancels the API request for a DMS on the network.

The following are the APIs that can be canceled by this function:

- dlnaDmpObjectBrowse()
- dlnaDmpObjectSearch()

Specify a pointer to the device, container, or item information specified for the API to be canceled, for
self.

If cancellation by this function succeeds, then event notification is not performed for the particular API requests. However, when the execution of this function conflicts with the timing of the call to the
callback, then event notification may be performed.

Cancellations after transmitting requests on the network are invalid.
*/
DLNA_API void
dlnaDmpObjectCancel (TDMPObject self);

/*!
\par Function:
Deletes device/container/item information.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to device, container, or item information to delete</td>
	</tr>
</table>

\return None 
\par Description: 
This function deletes the information of the device, container, or item that is specified for self.

API processing using self will be canceled.

If the container information or item information below containing the items to be deleted has already been obtained, then it must be deleted beforehand.

- Container and item information included in device information to be deleted
- Container and item information included in container information to be deleted

The following are the trigger events for using this function from a DMP application:

<b>(1)	When TDMPEventHandler is notified of an event</b>

<table>
	<tr>
		<td><b>Event name</b></td><td> <b>Description</b></td>
	</tr>
	<tr>
		<td>DMP_EV_BYEBYE</td>
		<td>
			This event notification is given when a device(DMS/DMR) on the network stops, so 
			the device information allocated by the DMP is deleted
		</td>
	</tr>
	<tr>
		<td>DMP_EV_UNAVAILABLE</td>
		<td>
			This event notification is given when a device (DMS/DMR) on the network gets disabled, 
			so the device information allocated by the DMP is deleted
		</td>
	</tr>
</table>

<b>(2) When deleting obtained device, container, or item information </b>

Device, container, and item information that is obtained by dlnaDmpDeviceList(), dlnaDmpObjectBrowse(), or dlnaDmpObjectSearch() cannot be deleted until this function executes.

The DMP application must delete the device, container, or item information using this function when
the information is no longer needed.
*/
DLNA_API void
dlnaDmpObjectClose (TDMPObject self);

/*@}*/

/**
 * @addtogroup macros
 */
/*@{*/

#define DMP_SORT_CRITERIA_TITLE                                               \
  "+dc:title"

#define DMP_SORT_CRITERIA_ARTIST                                              \
  "+upnp:artist"

#define DMP_SORT_CRITERIA_DATE                                                \
  "-dc:date"

#define DMP_SORT_CRITERIA_TITLE_ARTIST                                        \
  DMP_SORT_CRITERIA_TITLE "," DMP_SORT_CRITERIA_ARTIST

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function: 
Gets content information (containers/items) published by DMS devices on the network.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>
			Pointer to DMS device information (obtained by dlnaDmpDeviceList()), or container information (obtained by this function or dlnaDmpObjectSearch())
		</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_obj_eh</td>
		<td>
			Pointer to callback function that notifies of API processing result
		</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument of in_obj_eh</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_beg</td>
		<td>Starting number of content information to get (>=0)</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_num</td>
		<td>Number of content items to get</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_sort_crt</td>
		<td>Sort criteria</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_filter</td>
		<td>Browse filter</td>
	</tr>
</table>

\return DMP_E_OK Succeeded (Browse started)
\return Other Failed
\par Description: 
This function returns DMP_E_OK when a request to get content information of a DMS is successfully accepted.

No other APIs should be called from the time this function is called until the return of the processing result by in_obj_eh. Behavior is not guaranteed if other APIs are called.

If a pointer to the DMS device information is specified for self, the callback function sends notification of the container information of the top directory published by the DMS.

If a pointer to container information obtained from a DMS is specified for self, then the callback function sends notification of the container information and item information under the first level of the
specified container.

The pointer to the callback function must be specified for in_obj_eh. The result of the request to get the content information is notified asynchronously by in_obj_eh.

Specify 0 for in_beg when getting content information from the beginning, or specify the start position in the content information when getting it from any other desired position.

Specify the total number of content information items to request for in_num. If -1 is specified for in_num, the information of 30 content items will be requested by default (the default number of requests can be
set at compile time).

To get sorted content information, the sort criteria needs to be specified for in_sort_crt (see "Error! Reference source not found. Error! Reference source not found."). Specify slim_nil for in_sort_crt when sorting content information is unnecessary.

If it succeeds in getting the content information, then the DMP_OBJECT_EV_BROWSE_END event is notified depending on in_obj_eh, and values are set for the following members of the
TDMPObjectParam type. Other members must not be referenced.

- err_code Error code (0 for successful completion)
- NumberReturned Number of content items obtained
- TotalMatches Total number of content items matching request
- ObjectArray Array of pointers to content information obtained (number of array elements is equal to the value of NumberReturned)

When getting the content information fails, the DMP_OBJECT_EV_BROWSE_ERROR event is notified, and an error code is set for the err_code member of the TDMPObjectParam type.

For more information about error codes, see "2.7.4. Browse" in "UPnP AV ContentDirectory:1 Service
Template Version 1.01".
*/
DLNA_API slim_int
dlnaDmpObjectBrowse (TDMPObject self, TDMPObjectEventHandler in_obj_eh,
       void *in_arg, slim_int in_beg, slim_int in_num,
       slim_char *in_sort_crt, slim_char *in_filter);
     

/*!
\par Function:
Gets content metadata published by DMS devices on the network.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>
			Pointer to DMS device information (obtained by dlnaDmpDeviceList()),
			or pointer to container information (obtained by this function or dlnaDmpObjectSearch())
		</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_obj_eh</td>
		<td>
			Pointer to callback function that notifies of API processing result
		</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument of in_obj_eh</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_filter</td>
		<td>Browse filter</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_obj</td>
		<td>output object</td>
	</tr>
</table>

\return DMP_E_OK Succeeded (Browse started)
\return Other Failed
\par Description:
This function returns DMP_E_OK when a request to get content information for a DMS is successfully accepted.

No other APIs should be called from the time this function is called until the return of the processing result by in_obj_eh. Behavior is not guaranteed if other APIs are called.

If a pointer to the DMS device information is specified for self, the callback function sends notification of the container information of the top directory published by the DMS.

If a pointer to the container information obtained from the DMS is specified for self, the callback function sends notification of the containers on the next tier below the specified container and of the items within it.

The pointer to the callback function must be specified for in_obj_eh. The result of the request to get the content information is notified asynchronously by in_obj_eh.

When getting content information succeeds, the DMC_OBJECT_EV_BROWSE_END event is notified by in_obj_eh, and values are set for the following members in the TDMPObjectParam type. The other members must not be referenced.

<table>
	<tr>
		<td>err_code</td>
		<td>Error code (0 for successful completion)</td>
	</tr>
	<tr>
		<td>NumberReturned</td>
		<td>Number of content items obtained</td>
	</tr>
	<tr>
		<td>TotalMatches</td>
		<td>Total number of content items matching request</td>
	</tr>
	<tr>
		<td>ObjectArray</td>
		<td>
			Pointer to content information obtained
			(It is NOT an array as in dlnaDmpObjectBrowse, because there is always one element  by dlnaDmpObjectBrowseMetadata)
		</td>
	</tr>
</table>

When getting content information fails, the DMC_OBJECT_EV_BROWSE_ERROR event is notified, and an error code is set for the err_code member in the TDMCObjectParam type.

For more information about error codes, see "2.7.4. Browse" in "UPnP AV ContentDirectory:1 Service
Template Version 1.01".
*/
DLNA_API slim_int
dlnaDmpObjectBrowseMetadata (TDMPObject self, TDMPObjectEventHandler in_obj_eh,
                     void *in_arg, slim_char *in_filter, TDMPObject *out_obj);

/*@}*/

/**
 * @addtogroup macros
 */
/*@{*/

#define DMP_SEARCH_CAPS_UPNP_CLASS      ("upnp:class")
#define DMP_SEARCH_CAPS_UPNP_ALBUM      ("upnp:album")
#define DMP_SEARCH_CAPS_DC_TITLE        ("dc:title")
#define DMP_SEARCH_CAPS_DC_CREATOR      ("dc:creator")
#define DMP_SEARCH_CAPS_DEFAULT_ID      ("@id")
#define DMP_SEARCH_CAPS_DEFAULT_REFID   ("@refID")
#define DMP_SEARCH_CAPS_RES_RES         ("res")
#define DMP_SEARCH_CAPS_RES_PINFO       ("res@protocolInfo")

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function: 
Searches content information (containers/items) published by DMS on the network based on the specified criteria.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to DMS device information obtained by dlnaDmpDeviceList()</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_obj_eh</td>
		<td>Pointer to callback function that notifies of API processing result</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument of in_obj_eh</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_beg</td>
		<td>Starting number of content information to get (>=0)</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_num</td>
		<td>Number of content items to get</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_criteria</td>
		<td>Search criteria</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_filter</td>
		<td>Search filter</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_sort_crt</td>
		<td>Sort criteria</td>
	</tr>
</table>

\return DMP_E_OK Succeeded (Search started)
\return Other Failed 
\par Description: 
This function returns DMP_E_OK when a search request for content information of a DMS is
successfully accepted.

If this function is called for a DMS that does not support this function, the behavior is not guaranteed.
Whether a device supports this function needs to be checked by
dlnaDmpDeviceIsSupportSearchCapability().

A pointer to the device information of DMS is specified for self. If a pointer to other information is specified, an error is returned.

The pointer to the callback function must be specified for in_obj_eh. The result of a content information search request is notified asynchronously by in_obj_eh.

Specify 0 for in_beg when getting content information from the beginning, or specify the start position in the content information when getting it from any other desired position.

Specify the total number of content information items to request for in_num. If -1 is specified for in_num, the information of 30 content items will be requested by default (the default number of requests can be
set at compile time).

To get sorted content information, the sort criteria needs to be specified for in_sort_crt (see "Error! Reference source not found. Error! Reference source not found.").

The string defined in "UPnP AV ContentDirectory:1 Service Template Version 1.01" must be specified for in_criteria. in_criteria is same as search criteria in "UPnP AV ContentDirectory:1 Service Template
Version 1.01".

For more information about search criteria, see "2.5.5. A_ARG_TYPE_SearchCriteria" in "UPnP AV ContentDirectory:1 Service Template Version 1.01".

The string defined in "UPnP AV ContentDirectory:1 Service Template Version 1.01" must be specified for in_filter. in_filter is same as filter in "UPnP AV ContentDirectory:1 Service Template Version 1.01". 

For more information about filter, see "2.5.7. A_ARG_TYPE_Filter" in "UPnP AV ContentDirectory:1 Service Template Version 1.01".

When getting content information succeeds, the DMP_OBJECT_EV_SEARCH_END event is notified by in_obj_eh, and values are set for the following members of the TDMPObjectParam type. Other members must not be referenced.

- err_code Error code (0 for successful completion)
- NumberReturned Number of content items obtained
- TotalMatches Total number of content items matching search condition
- ObjectArray Array of pointers to content information obtained (number of array elements is equal to the value ofNumberReturned)

When getting content information fails, the DMP_OBJECT_EV_SEARCH_ERROR event is notified, and an error code is set for the err_code member of the TDMPObjectParam type.

For more information about error codes, see "2.7.5. Search" in "UPnP AV ContentDirectory:1 Service
Template Version 1.01". 

\par Example about in_criteria: 
\code
 "upnp:class = \"object.item.imageItem.photo\" and ( dc:date >= \"2001-10-
01\" and dc:date <= \"2001-10-31\")"
\endcode 

\par Example about in_filter: 
\code
 "@id,@parentID,@restricted,dc:title,upnp:class"
\endcode 
*/
DLNA_API slim_int
dlnaDmpObjectSearch (TDMPObject self, TDMPObjectEventHandler in_obj_eh,
                     void *in_arg, slim_int in_beg, slim_int in_num,
                     slim_char *in_criteria, slim_char *in_filter, slim_char *in_sort_crt);

/*!
\par Function:
Gets search capabilities of DMS.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA device type object.</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>in_obj_eh</td>
		<td>Callback to event handler.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Event handler argument.</td>
	</tr>
</table>
\return string containing device ip
\par Return Values:
<table>
	<tr>
		<td> \b DMP_E_OK</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>DMP_E_GENERIC</td>
		<td> Generic error</td>
	</tr>
	<tr>
		<td>DMP_E_DEV</td>
		<td> Slef is not a device type object</td>
	</tr>
	<tr>
		<td>DMP_E_URI</td>
		<td>Error in URI</td>
	</tr>
	<tr>
		<td>DMP_E_NOMEM</td>
		<td>Out of memory</td>
	</tr>
</table>
\par Description:
This function gets all supported search capabilities of DMS.
*/

DLNA_API slim_int
dlnaDmpDeviceIsSearchCapable (TDMPObject self, TDMPObjectEventHandler in_obj_eh, void *in_arg);

/*!
\par Function:
Determines whether DMS supports specified search capability.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to DMS device information obtained by dlnaDmpDeviceList()</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_search_caps</td>
		<td>Search capability string to determine</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_is_support</td>
		<td>
			Result of search capability determination <br />
			slim_true Supported <br />
			slim_false Not supported
		</td>
	</tr>
</table>

\return DMP_E_OK Succeeded
\return Other Failed 
\par Description: 
This function determines whether the DMS supports the search capability specified for in_search_caps
(see "Error! Reference source not found. Error! Reference source not found.").
*/
DLNA_API slim_int
dlnaDmpDeviceIsSupportSearchCapability (TDMPObject self,slim_char * in_search_caps, slim_bool* out_is_support);

/*!
\par Function: 
Get CSV list of search capabilities.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to DMS device information obtained by dlnaDmpDeviceList()</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_caps_buf</td>
		<td>Pointer to CSV list for search capability (NULL terminated)</td>
	</tr>
	<tr>
		<td>[inout]</td>
		<td>inout_caps_buf_size</td>
		<td>Buffer size of out_caps_buf</td>
	</tr>
</table>
 
\return DMP_E_OK Succeeded 
\return DMP_E_INVAL Invalid argument
\return DMP_E_NOTFOUND DMS have no search capability
\return DMP_E_GENERIC Other error 
\par Description: 
This function returns CSV list of search capabilities.

DMP application should check out_caps_buf to determine what search capabilities are supported by
DMS specified for self.

The memory buffer of out_caps_buf and inout_caps_buf_size must be allocated in DMP application.

out_caps_buf is NULL terminated.

The DMP application gets the CSV list for search capability by the following procedure.

-# Calls this function specifying slim_nil for out_caps_buf, and gets the required string buffer
size for out_caps_buf from inout_caps_buf_size.
-# Allocates memory area for CSV list for search capability, according to the required string
buffer size for out_caps_buf obtained in step 1.
-# Calls this function again, specifying a pointer to the memory area allocated in step 2 for
out_caps_buf, specifying the buffer size for inout_caps_buf_siz, and gets the CSV list for search
capability.

For more information about search capability, see "2.5.18. SearchCapabilities ", "2.7.1. GetSearchCapabilities" and " 2.8.4.1. Retrieving search capabilities" in "UPnP AV ContentDirectory:1
Service Template Version 1.01".
*/
DLNA_API slim_int
dlnaDmpDeviceGetSupportSearchCapability (TDMPObject self, slim_char *out_caps_buf, slim_int *inout_caps_buf_size);

/*!
\par Function: 
Determines whether DMS supports specified sort criteria.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to DMS device information obtained by dlnaDmpDeviceList()</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_sort_crt</td>
		<td>Sort criteria string to determine</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_is_support</td>
		<td>
			Result of sort criteria determination <br />
			slim_true Supported <br />
			slim_false Not supported
		</td>
	</tr>
</table>

\return DMP_E_OK Succeeded 
\return Other Failed 
\par Description: 
This function determines whether the DMS supports the sort criteria specified for in_sort_crt (see
"Error! Reference source not found. Error! Reference source not found."). 
\note 
Since the device sort capabilities are obtained by the DLNA GetSortCapabilites action, if this
function is called before the GetSortCapabilites action result is returned, out_is_support will be
slim_false.
*/
DLNA_API slim_int
dlnaDmpDeviceIsSupportSortCriteria (TDMPObject self, slim_char* in_sort_crt, slim_bool* out_is_support);

/*!
\par Function:
Get CSV list of sort criteria.
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>Pointer to DMS device information obtained by dlnaDmpDeviceList()</td>
        </tr>
        <tr>
                <td>[out]</td>
                <td>out_crt_buf</td>
                <td>Pointer to CSV list for sort criteria (NULL terminated)</td>
        </tr>
        <tr>
                <td>[inout]</td>
                <td>inout_crt_buf_size</td>
                <td>Buffer size of out_crt_buf</td>
        </tr>
</table>

\return DMP_E_OK Succeeded
\return DMP_E_INVAL Invalid argument
\return DMP_E_NOTFOUND DMS have no sort criteria
\return DMP_E_GENERIC Other error
\par Description:
This function returns CSV list of sort criteria.

DMP application should check out_crt_buf to determine what sort criteria are supported by
DMS specified for self.

The memory buffer of out_crt_buf and inout_crt_buf_size must be allocated in DMP application.

out_crt_buf is NULL terminated.

The DMP application gets the CSV list for sort criterion by the following procedure.

-# Calls this function specifying slim_nil for out_crt_buf, and gets the required string buffer
size for out_crt_buf from inout_crt_buf_size.
-# Allocates memory area for CSV list for sort criterion, according to the required string
buffer size for out_crt_buf obtained in step 1.
-# Calls this function again, specifying a pointer to the memory area allocated in step 2 for
out_crt_buf, specifying the buffer size for inout_crt_buf_siz, and gets the CSV list for sort criterion.
*/
DLNA_API slim_int
dlnaDmpDeviceGetSupportSortCriteria (TDMPObject self, slim_char *out_crt_buf, slim_int *inout_crt_buf_size);

#ifdef DLNA_SUPPORT_DOWNLOADER
DLNA_API TDMPObject
dlnaDmpObjectDownload (TDMPObject self, TDMPObjectEventHandler in_obj_eh,
                       void *in_arg, slim_int in_res_index, slim_char *in_download_path);
DLNA_API slim_int 
dlnaDmpObjectDNCancel (TDMPObject self);

DLNA_API slim_int
dlnaDmpObjectDNPause (TDMPObject self);

DLNA_API slim_int
dlnaDmpObjectDNResume (TDMPObject self);
#endif

/*!
\par Function:
Opens thumbnail to play.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA device object.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_obj_eh</td>
		<td>Callback function that notifies of API processing result.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument to callback.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_dmr</td>
		<td>input DMR device</td>
	</tr>
</table>
\return slim_int error code
\par Return Values:
<table>
	<tr>
		<td> \b DLNA_E_OK</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>DLNA_E_GENERIC</td>
		<td>Generic error</td>
	</tr>
	<tr>
		<td>DLNA_E_NOMEM</td>
		<td>Out of memory error</td>
	</tr>
</table>
*/

DLNA_API TDMPObject
dlnaDmpObjectThumbnailOpen (TDMPObject self, TDMPObjectEventHandler in_obj_eh,
                      void *in_arg,TDMPObject in_dmr);

/*!
\par Function:
Gets playlist.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP instance</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_obj_array</td>
		<td>Address where obtained playlist is stored </td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_obj_num</td>
		<td>Maximum value of playlists to get</td>
	</tr>
</table>

\return <0 Failed 
\return Other Total number of playlists copied to specified structure 
\par Description: 
This function gets the total number of playlists from a player.

It copies the playlists into out_obj_array.

If the maximum playlist value specified for in_obj_num is larger than the number of playlists obtained from the player, the function copies all the playlists and returns the number of obtained as a return value.

If the maximum playlist value specified for in_obj_num is smaller than the number of playlists obtained from the player, the function copies up to the specified number of playlists and returns the number as a return value.
*/
DLNA_API slim_int
dlnaDmpGetPlaylist (TDMP self, TDMPObject * out_obj_array, slim_word in_obj_num);

#ifndef	DLNA_NOT_SUPPORT_PLAYER_API

#ifdef DEVELOPMENT_DMP_DMR_DTCP_IP_FOR_CVP 
struct dmp_app_play_params
{
  slim_char *title;
  slim_char *uri;
  slim_char *pinfo;
  slim_opaque stream;
  TDMPObjectEventHandler call_back;
};

typedef struct dmp_app_play_params  dmp_app_play_params_t;
#endif /* DEVELOPMENT_DMP_DMR_DTCP_IP_FOR_CVP */

/*!
\par Function:
Allocates DMP player for object specyfied by index.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA device object.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_obj_eh</td>
		<td>Callback function that notifies of API processing result.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument to callback.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_dmr</td>
		<td>input DMR device</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_res_index</td>
		<td>input DMR device</td>
	</tr>
</table>
\return TDMPObject allocated object for play routine
\par Return Values:
<table>
	<tr>
		<td> \b !=slim_nil</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>slim_nil</td>
		<td>Generic error</td>
	</tr>
</table>
\par Description:
This function gets object and allocate DMP player to handle play routine
*/

DLNA_API TDMPObject
dlnaDmpPlayOpen (TDMPObject self, TDMPObjectEventHandler in_obj_eh,
                 void *in_arg, TDMPObject in_dmr, slim_int in_res_index);

/*!
\par Function:
Function play transport object allocated to play.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA transport object.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_speed</td>
		<td>Speed of playing routine.</td>
	</tr>
</table>
\return slim_int error code values
\par Return Values:
<table>
	<tr>
		<td> \b DMP_E_OK</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>DMP_E_GENERIC</td>
		<td>Generic error</td>
	</tr>
	<tr>
		<td>DMP_E_INVAL</td>
		<td>Invalid parameter</td>
	</tr>
</table>
\par Description:
This functions starts play routine with speed specified by in_speed.
*/

DLNA_API slim_int
dlnaDmpPlayPlay (TDMPObject self, slim_char *in_speed);

/*!
\par Function:
Function pauses play routine.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA transport object.</td>
	</tr>
</table>
\return slim_int error code values
\par Return Values:
<table>
	<tr>
		<td> \b DMP_E_OK</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>DMP_E_GENERIC</td>
		<td>Generic error</td>
	</tr>
	<tr>
		<td>DMP_E_INVAL</td>
		<td>Invalid parameter</td>
	</tr>
</table>
\par Description:
This functions pauses play routine.
If server not supports pausing playing objects function returns error.
Error can be also returned when self is not transport type.
*/

DLNA_API slim_int
dlnaDmpPlayPause (TDMPObject self);

/*!
\par Function:
Function pauses play routine.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA transport object.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>mode</td>
		<td>dlna_player_trickmode</td>
	</tr>
</table>
\return slim_int error code values
\par Return Values:
<table>
	<tr>
		<td> \b DMP_E_OK</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>DMP_E_GENERIC</td>
		<td>Generic error</td>
	</tr>
	<tr>
		<td>DMP_E_INVAL</td>
		<td>Invalid parameter</td>
	</tr>
</table>
\par Description:
This functions pauses play routine.
If server not supports pausing playing objects function returns error.
Error can be also returned when self is not transport type.
*/

DLNA_API slim_int
dlnaDmpPlayPauseBy (TDMPObject self, dlna_player_trickmode mode);

/*!
\par Function:
Function jumps to place in current played object specyfied by in_jump.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA transport object.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_jump</td>
		<td>DLNA jump parameter.</td>
	</tr>
</table>
\return slim_int error code values
\par Return Values:
<table>
	<tr>
		<td> \b DMP_E_OK</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>DMP_E_GENERIC</td>
		<td>Generic error</td>
	</tr>
	<tr>
		<td>DMP_E_INVAL</td>
		<td>Invalid parameter</td>
	</tr>
</table>
\par Description:
Function jumps using specyfied in in_jump method and place.
*/

DLNA_API slim_int
dlnaDmpPlayJump (TDMPObject self, TDMPObjectJumpParam *in_jump);

/*!
\par Function:
Function stops the play routine.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA transport object.</td>
	</tr>
</table>
\return slim_int error code values
\par Return Values:
<table>
	<tr>
		<td> \b DMP_E_OK</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>DMP_E_GENERIC</td>
		<td>Generic error</td>
	</tr>
	<tr>
		<td>DMP_E_INVAL</td>
		<td>Invalid parameter</td>
	</tr>
</table>
\par Description:
Function stops play routine on DLNA transport object.
*/

DLNA_API slim_int
dlnaDmpPlayStop (TDMPObject self);

/*!
\par Function:
Function perform fast forward action on the transport object.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA transport object.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_reserved</td>
		<td>Speed of fast forward action.</td>
	</tr>
</table>
\return slim_int error code values
\par Return Values:
<table>
	<tr>
		<td> \b DMP_E_OK</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>DMP_E_GENERIC</td>
		<td>Generic error</td>
	</tr>
	<tr>
		<td>DMP_E_INVAL</td>
		<td>Invalid parameter</td>
	</tr>
</table>
\par Description:
Function preform fast forward action on DLNA transport object.
*/

DLNA_API slim_int
dlnaDmpPlayFastForward(TDMPObject self, slim_int in_reserved);

/*!
\par Function:
Function perform rewind action on the transport object.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA transport object.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_reserved</td>
		<td>Speed of rewind action must be negative.</td>
	</tr>
</table>
\return slim_int error code values
\par Return Values:
<table>
	<tr>
		<td> \b DMP_E_OK</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>DMP_E_GENERIC</td>
		<td>Generic error</td>
	</tr>
	<tr>
		<td>DMP_E_INVAL</td>
		<td>Invalid parameter</td>
	</tr>
</table>
\par Description:
Function preform rewind action on DLNA transport object.
in_reserved param must be negative to perform this action.
*/

DLNA_API slim_int
dlnaDmpPlayRewind(TDMPObject self, slim_int in_reserved);

/*!
\par Function:
Function perform fast forward/backward action on the transport object.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA transport object.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_speed</td>
		<td>Speed of fast forward/backward action.<br>
        e.g. 2 refers 2x forward, -2 refers 2x backward.
    </td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_mode</td>
		<td>Type of trick mode.</td>
	</tr>
</table>
\return slim_int error code values
\par Return Values:
<table>
	<tr>
		<td> \b DMP_E_OK</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>DMP_E_GENERIC</td>
		<td>Generic error</td>
	</tr>
	<tr>
		<td>DMP_E_INVAL</td>
		<td>Invalid parameter</td>
	</tr>
</table>
\par Description:
Function preform fast forward/backward action on DLNA transport object.
*/

DLNA_API slim_int
dlnaDmpPlayFastPlay (TDMPObject self, slim_int in_speed, dlna_player_trickmode in_mode);

/*!
\par Function:
Function perform slow forward/backward action on the transport object.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA transport object.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_reserved</td>
		<td>Speed of slow forward/backward action.<br>
        e.g. 2 refers 0.5x forward, -2 refers 0.5x backward.
    </td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_mode</td>
		<td>Type of trick mode.</td>
	</tr>
</table>
\return slim_int error code values
\par Return Values:
<table>
	<tr>
		<td> \b DMP_E_OK</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>DMP_E_GENERIC</td>
		<td>Generic error</td>
	</tr>
	<tr>
		<td>DMP_E_INVAL</td>
		<td>Invalid parameter</td>
	</tr>
</table>
\par Description:
Function preform rewind action on DLNA transport object.
in_reserved param must be negative to perform this action.
*/

DLNA_API slim_int
dlnaDmpPlaySlowPlay (TDMPObject self, slim_int in_speed, dlna_player_trickmode in_mode);

/*!
\par Function:
Function gets state of the transport object.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA transport object.</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_state</td>
		<td>Output play state</td>
	</tr>
</table>
\return slim_int error code values
\par Return Values:
<table>
	<tr>
		<td> \b DMP_E_OK</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>DMP_E_GENERIC</td>
		<td>Generic error</td>
	</tr>
	<tr>
		<td>DMP_E_INVAL</td>
		<td>Invalid parameter</td>
	</tr>
</table>
\par Description:
Function gets state of the transport object.
State is numeric value and there is 7 states of transport object.
*/

DLNA_API slim_int
dlnaDmpPlayGetState (TDMPObject self, TDMPPlayState *out_state);
#endif

/*!
\par Function: 
Determines whether DMP object is device.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP object</td>
	</tr>
</table>

\return slim_true Object type is device
\return slim_false Object type is not device 
\par Description: 
This function returns whether the object type is device.
*/
DLNA_API slim_bool
dlnaDmpObjectTypeIsDevice (TDMPObject self);

/*!
\par Function:
Determines whether DMP object is container.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP object</td>
	</tr>
</table>

\return slim_true Object type is container
\return slim_false Object type is not container 
\par Description: 
This function returns whether the object type is container.
*/
DLNA_API slim_bool
dlnaDmpObjectTypeIsContainer (TDMPObject self);

/*!
\par Function:
Determines whether DMP object is item.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP object</td>
	</tr>
</table>

\return slim_true Object type is item
\return slim_false Object type is not item 
\par Description: 
This function returns whether the object type is item.
*/
DLNA_API slim_bool
dlnaDmpObjectTypeIsItem (TDMPObject self);

/*!
\par Function:
Determines whether DMP object is in_type like type.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP object</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_type</td>
		<td>DMP object type to check</td>
	</tr>
</table>

\return slim_true Object type is in_type like
\return slim_false Object type is not item
\par Description:
This function returns whether the object type is in_type like.
*/

DLNA_API slim_bool
dlnaDmpObjectTypeGet (TDMPObject self, slim_char *in_type);

#ifdef _DOXYGEN

/*!
\par Function:
Determines whether DMP object is storage folder.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP object</td>
	</tr>
</table>

\return slim_true Object type is storage folder
\return slim_false Object type is not storage folder
\par Description:
This function returns whether the object type is storage folder.
*/
slim_bool dlnaDmpObjectTypeIsStorageFolder (TDMPObject self);

/*!
\par Function:
Determines whether DMP object is album.
 \par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP object</td>
	</tr>
</table>

\return slim_true Object type is album
\return slim_false Object type is not album
\par Description:
This function returns whether the object type is album.
*/
slim_bool dlnaDmpObjectTypeIsAlbum (TDMPObject self);


/*!
\par Function:
Determines whether DMP object is music album.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP object</td>
	</tr>
</table>

\return slim_true Object type is music album
\return slim_false Object type is not music album
\par Description:
This function returns whether the object type is music album.
*/
slim_bool dlnaDmpObjectTypeIsMusicAlbum (TDMPObject self);


/*!
\par Function:
Determines whether DMP object is photo album.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP object</td>
	</tr>
</table>

\return slim_true Object type is photo album
\return slim_false Object type is not photo album
\par Description:
This function returns whether the object type is photo album.
*/
slim_bool dlnaDmpObjectTypeIsPhotoAlbum (TDMPObject self);


/*!
\par Function:
Determines whether DMP object is playlist container.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP object</td>
	</tr>
</table>

\return slim_true Object type is playlist
\return slim_false Object type is not playlist
\par Description:
This function returns whether the object type is playlist.
*/
slim_bool dlnaDmpObjectTypeIsPlaylistContainer (TDMPObject self);

/*!
\par Function:
Determines whether DMP object is image item.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP object</td>
	</tr>
</table>

\return slim_true Object type is image item
\return slim_false Object type is not image item
\par Description:
This function returns whether the object type is image item.
*/

slim_bool dlnaDmpObjectTypeIsImageItem (TDMPObject self);

/*!
\par Function:
Determines whether DMP object is photo.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP object</td>
	</tr>
</table>

\return slim_true Object type is photo
\return slim_false Object type is not photo
\par Description:
This function returns whether the object type is photo.
*/
slim_bool dlnaDmpObjectTypeIsPhoto (TDMPObject self);


/*!
\par Function:
Determines whether DMP object is audio item.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP object</td>
	</tr>
</table>

\return slim_true Object type is audio item
\return slim_false Object type is not audio item
\par Description:
This function returns whether the object type is audio item.
*/
slim_bool dlnaDmpObjectTypeIsAudioItem (TDMPObject self);

/*!
\par Function:
Determines whether DMP object is music track.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP object</td>
	</tr>
</table>

\return slim_true Object type is music track
\return slim_false Object type is not music track
\par Description:
This function returns whether the object type is music track.
*/
slim_bool dlnaDmpObjectTypeIsMusicTrack (TDMPObject self);

/*!
\par Function:
Determines whether DMP object is video item.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP object</td>
	</tr>
</table>

\return slim_true Object type is video item
\return slim_false Object type is not video item
\par Description:
This function returns whether the object type is video item.
*/
slim_bool dlnaDmpObjectTypeIsVideoItem (TDMPObject self);


/*!
\par Function:
Determines whether DMP object is movie.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP object</td>
	</tr>
</table>

\return slim_true Object type is movie
\return slim_false Object type is not movie
\par Description:
This function returns whether the object type is movie.
*/
slim_bool dlnaDmpObjectTypeIsMovie (TDMPObject self);

/*!
\par Function:
Determines whether DMP object is music video clip.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP object</td>
	</tr>
</table>

\return slim_true Object type is music video clip
\return slim_false Object type is not music video clip
\par Description:
This function returns whether the object type is music video clip.
*/
slim_bool dlnaDmpObjectTypeIsMusicVideoClip (TDMPObject self);

/*!
\par Function:
Determines whether DMP object is playlist item.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP object</td>
	</tr>
</table>

\return slim_true Object type is playlist item
\return slim_false Object type is not playlist item
\par Description:
This function returns whether the object type is playlist item.
*/
slim_bool dlnaDmpObjectTypeIsPlayListItem (TDMPObject self);

#endif

/*@}*/

/**
 * @addtogroup macros
 */
/*@{*/

#ifndef _DOXYGEN
#define dlnaDmpObjectTypeIsStorageFolder(self) 		dlnaDmpObjectTypeGet (self, SLIM_T("storageFolder"))
#define dlnaDmpObjectTypeIsAlbum(self) 	       		dlnaDmpObjectTypeGet (self, SLIM_T("album"))
#define dlnaDmpObjectTypeIsMusicAlbum(self)     	dlnaDmpObjectTypeGet (self, SLIM_T("musicAlbum"))
#define dlnaDmpObjectTypeIsPhotoAlbum(self)     	dlnaDmpObjectTypeGet (self, SLIM_T("photoAlbum"))
#define dlnaDmpObjectTypeIsPlaylistContainer(self) 	dlnaDmpObjectTypeGet (self, SLIM_T("playlistContainer"))
#define dlnaDmpObjectTypeIsImageItem(self) 		dlnaDmpObjectTypeGet (self, SLIM_T("imageItem"))
#define dlnaDmpObjectTypeIsPhoto(self) 			dlnaDmpObjectTypeGet (self, SLIM_T("photo"))
#define dlnaDmpObjectTypeIsAudioItem(self) 		dlnaDmpObjectTypeGet (self, SLIM_T("audioItem"))
#define dlnaDmpObjectTypeIsMusicTrack(self)		dlnaDmpObjectTypeGet (self, SLIM_T("musicTrack"))
#define dlnaDmpObjectTypeIsVideoItem(self) 		dlnaDmpObjectTypeGet (self, SLIM_T("videoItem"))
#define dlnaDmpObjectTypeIsMovie(self) 			dlnaDmpObjectTypeGet (self, SLIM_T("movie"))
#define dlnaDmpObjectTypeIsMusicVideoClip(self) 	dlnaDmpObjectTypeGet (self, SLIM_T("musicVideoClip"))
#define dlnaDmpObjectTypeIsPlayListItem(self) 		dlnaDmpObjectTypeGet (self, SLIM_T("playlistItem"))
#endif

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Determines whether DMP object is playable.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP object</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_dmr</td>
		<td>Specyfied DMR device</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_res_index</td>
		<td>Resource index</td>
	</tr>
</table>

\return slim_true Object type is playable
\return slim_false Object type is not playable
\par Description:
This function returns whether the object type is playable.
*/

DLNA_API slim_bool
dlnaDmpObjectIsPlayable (TDMPObject self, TDMPObject in_dmr, slim_int in_res_index);

/*!
\par Function: 
Determines whether the item can be playable in DMR wihch has the specified SinkProtocolInfo strings.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to item information</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>info</td>
		<td>SinkProtocolInfo string</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_res_index</td>
		<td>
			>=0 Specifies resource index <br />
			-1 Specifies default resource
		</td>
	</tr>
</table>

\return slim_true Playable in DMR which has the specified SinkProtocolInfo strings
\return slim_false Not playable, or error occurred 
\par Description: 
This function is used to check the specified item can be playable in DMR which has the specified SinkProtocolInfo.

self must be specified a pointer to the item object to be checked.

info must be specified SinkProtocolInfo strings. If the protocolInfo strings of the above item match the
SinkProtocolInfo strings, the function returns slim_true.

For more information about SinkProtocolInfo, see "UPnP AV ConnectionManager:1 Service Template
Version 1.01"

If resource index is specified for in_res_index, the item which has the specified resource index is
checked.
*/
DLNA_API slim_bool
dlnaDmpObjectIsPlayableByCaps (TDMPObject self, slim_char *info, slim_int in_res_index);

/*!
\par Function:
Gets DRM type of item within container.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to item information</td>
	</tr>
</table>

\return DRM type (see "3.2.4 TDLNAObjectDRMType")
\par Description: 
This function returns the DRM type of an item within a container.
*/
DLNA_API TDLNAObjectDRMType
dlnaDmpObjectDRMType (TDMPObject self);

/*!
\par Function:
Gets property attribute value by name.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>
			Pointer to device, container, or item information for which to get property value
		</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_prop</td>
		<td>Property name</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_attr</td>
		<td>Attribute name</td>
	</tr>
</table>

\return String Attribute value of property 
\return Null No property attribute is found in DIDL document of object 
\par Description: 
This function returns the value of the attribute specified for in_attr in the property specified for in_prop.

According to the DLNA guidelines, DMP objects can be written in DIDL-Lite, and properties, XM elements, and attributes in XML (see "DLNA Networked Device Interoperability Guidelines"). This function searches the DIDL-Lite document of the object and returns the attribute value.

Since this function returns the address to an area allocated in a DMP object as the return value, the property value can be referenced until the DMP object is deleted by dlnaDmpObjectClose().
*/
/* for get pinfo */
DLNA_API slim_char *
dlnaDmpObjectPropGetAttr (TDMPObject self, slim_char* in_prop, slim_char* in_attr);

/*!
\par Function:
Gets parentID property.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>
			Pointer to device, container, or item information for which to get property value
		</td>
	</tr>
</table>

\return URI (string) parentID property value
\return Null Specified object has no property value
\par Description:
This function returns the parentID property.
*/
DLNA_API slim_char *
dlnaDmpObjectPropParentId (TDMPObject self);

/*!
\par Function:
Gets ID property.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to device, container, or item information for which to get property value</td>
	</tr>
</table>

\return URI (string) ID property value 
\return Null Specified object has no property value 
\par Description: 
This function returns the ID property.

Since this function returns the address to an area allocated in a DMP object as the return value, the ID
property value can be referenced until the DMP object is deleted by dlnaDmpObjectClose().
*/
DLNA_API slim_char *
dlnaDmpObjectPropId (TDMPObject self);

/*!
\par Function:
Gets path property.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to device, container, or item information for which to get property value</td>
	</tr>
</table>

\return URI (string) path property value 
\return Null Specified object has no property value 
\par Description: 
This function returns the path property.

Since this function returns the address to an area allocated in a DMP object as the return value, the
property value can be referenced until the DMP object is deleted by dlnaDmpObjectClose().
*/
DLNA_API slim_char *
dlnaDmpObjectPropPath (TDMPObject self);

/*!
\par Function:
Gets property value by name.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to device, container, or item information for which to get property value</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_prop</td>
		<td>Property name</td>
	</tr>
</table>

\return URI (string) Property value 
\return Null Specified object has no property value 
\par Description: 
This function searches for the property specified by in_prop, and returns the property value string.

According to the DLNA guidelines, DMP objects can be written in DIDL-Lite, and properties, XML
elements, and attributes in XML (see "DLNA Networked Device Interoperability Guidelines"). This
function searches the DIDL-Lite document of the object and returns the property value.

Since this function returns the address to an area allocated in a DMP object as the return value, the
property value can be referenced until the DMP object is deleted by dlnaDmpObjectClose().
*/
DLNA_API slim_char *
dlnaDmpObjectPropGet (TDMPObject self, slim_char* in_prop);

#ifdef _DOXYGEN

/*!
\par Function:
Gets title property.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>
    Pointer to device, container, or item information for which to get 	property value
    </td>
 </tr>
</table>
     
\return URI(string) title property value
\return Null Specified object has no property value
\par Description:
This function returns the title property.
     
Since this function returns the address to an area allocated in a DMP object as the return value, the property value can be referenced until the DMP object is deleted by dlnaDmpObjectClose().
*/
slim_char * dlnaDmpObjectPropTitle (TDMPObject self);

/*!
\par Function:
Gets creator property.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>
    Pointer to device, container, or item information for which to get property value
    </td>
 </tr>
</table>
     
\return URI(string) creator property value
\return Null Specified object has no property value
\par Description:
This function returns the creator property.
     
Since this function returns the address to an area allocated in a DMP object as the return value, the property value can be referenced until the DMP object is deleted by dlnaDmpObjectClose().
*/
slim_char * dlnaDmpObjectPropCreator (TDMPObject self);


    
/*!
 \par Function:
 Gets creator property.
 \par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>
    Pointer to device, container, or item information for which to get property value
    </td>
 </tr>
</table>
     
\return URI(string) creator property value
\return Null Specified object has no property value
\par Description:
This function returns the creator property.
     
Since this function returns the address to an area allocated in a DMP object as the return value, the property value can be referenced until the DMP object is deleted by dlnaDmpObjectClose().
*/
slim_char * dlnaDmpObjectPropCreator (TDMPObject self);


/*!
\par Function:
Gets write status property.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>
    Pointer to device, container, or item information for which to get property value
    </td>
 </tr>
</table>
     
\return URI(string) write status property value
\return Null Specified object has no property value
\par Description:
This function returns the write status property
     
Since this function returns the address to an area allocated in a DMP object as the return value, the property value can be referenced until the DMP object is deleted by dlnaDmpObjectClose().
*/

slim_char * dlnaDmpObjectPropWriteStatus (TDMPObject self);


/*!
\par Function:
Gets detailed description property.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>
    Pointer to device, container, or item information for which to get property value
    </td>
 </tr>
</table>
     
\return URI(string) detailed description property value
\return Null Specified object has no property value
\par Description:
This function returns the detailed description property.
     
Since this function returns the address to an area allocated in a DMP object as the return value, the property value can be referenced until the DMP object is deleted by dlnaDmpObjectClose().
*/

slim_char * dlnaDmpObjectPropLongDescription (TDMPObject self);


/*!
\par Function:
Gets description property.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>
			Pointer to device, container, or item information for which to get property value
		</td>
	</tr>
</table>

\return URI (string) description property value
\return Null Specified object has no property value
\par Description:
This function returns the description property.

Since this function returns the address to an area allocated in a DMP object as the return value, the property value can be referenced until the DMP object is deleted by dlnaDmpObjectClose().
*/
slim_char * dlnaDmpObjectPropDescription (TDMPObject self);


/*!
\par Function:
Gets publisher property.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>
			Pointer to device, container, or item information for which to get property value
		</td>
	</tr>
</table>

\return URI(string) publisher property value
\return Null Specified object has no property value

\par Description:
This function returns the publisher property.

Since this function returns the address to an area allocated in a DMP object as the return value, the property value can be referenced until the DMP object is deleted by dlnaDmpObjectClose().
*/
slim_char * dlnaDmpObjectPropPublisher (TDMPObject self);

/*!
\par Function:
Gets contributor property.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>
			Pointer to device, container, or item information for which to get property value
		</td>
	</tr>
</table>

\return URI(string) contributor property value
\return Null Specified object has no property value
\par Description:
This function returns the contributor property.

Since this function returns the address to an area allocated in a DMP object as the return value, the property value can be referenced until the DMP object is deleted by dlnaDmpObjectClose().
*/
slim_char * dlnaDmpObjectPropContributor (TDMPObject self);

/*!
\par Function:
Gets date property.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>
			Pointer to device, container, or item information for which to get property value
		</td>
	</tr>
</table>

\return URI(string) date property value

Supported formats are as follows:

CCYY-MM-DD <br />
CCYY-MM-DDThh:mm:ss <br />
CCYY-MM-DDThh:mm:ssZ <br />
CCYY-MM-DDThh:mm:ss+hh:mm <br />
CCYY-MM-DDThh:mm:ss-hh:mm <br />
CCYY-MM-DDThh:mm:ss.sss <br />
CCYY-MM-DDThh:mm:ss.sssZ <br />
CCYY-MM-DDThh:mm:ss.sss+hh:mm <br />
CCYY-MM-DDThh:mm:ss.sss-hh:mm <br />

\return Null Specified object has no property value
\par Description:
This function returns the date property.

Since this function returns the address to an area allocated in a DMP object as the return value, the property value can be referenced until the DMP object is deleted by dlnaDmpObjectClose().
*/
slim_char * dlnaDmpObjectPropDate (TDMPObject self);

/*!
\par Function:
Gets copyrights property.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>
			Pointer to device, container, or item information for which to get property value
		</td>
	</tr>
</table>

\return URI(string) copyrights property value
\return Null Specified object has no property value
\par Description:
This function returns the copyrights property.

Since this function returns the address to an area allocated in a DMP object as the return value, the property value can be referenced until the DMP object is deleted by dlnaDmpObjectClose().
*/
slim_char * dlnaDmpObjectPropCopyrights (TDMPObject self);

/*!
\par Function:
Gets artist property.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>
			Pointer to device, container, or item information for which to get property value
		</td>
	</tr>
</table>

\return URI(string) artist property value
\return Null Specified object has no property value
\par Description:
This function returns the artist property.

Since this function returns the address to an area allocated in a DMP object as the return value, the property value can be referenced until the DMP object is deleted by dlnaDmpObjectClose().
*/
slim_char * dlnaDmpObjectPropArtist (TDMPObject self);


/*!
\par Function:
Gets album property.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>
			Pointer to device, container, or item information for which to get property value
		</td>
	</tr>
</table>

\return URI(string) album property value
\return Null Specified object has no property value
\par Description:
This function returns the album property.

Since this function returns the address to an area allocated in a DMP object as the return value, the property value can be referenced until the DMP object is deleted by dlnaDmpObjectClose().
*/
slim_char * dlnaDmpObjectPropAlbum (TDMPObject self);


/*!
\par Function:
Gets genre property.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>
			Pointer to device, container, or item information for which to get property value
		</td>
	</tr>
</table>

\return URI(string) genre property value
\return Null Specified object has no property value
\par Description:
This function returns the genre property.

Since this function returns the address to an area allocated in a DMP object as the return value, the property value can be referenced until the DMP object is deleted by dlnaDmpObjectClose().
*/
slim_char * dlnaDmpObjectPropGenre (TDMPObject self);


/*!
\par Function:
Gets producer property.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>
			Pointer to device, container, or item information for which to get property value
		</td>
	</tr>
</table>

\return URI(string) producer property value
\return  Null Specified object has no property value
\par Description:
This function returns the producer property.

Since this function returns the address to an area allocated in a DMP object as the return value, the property value can be referenced until the DMP object is deleted by dlnaDmpObjectClose().
*/
slim_char * dlnaDmpObjectPropProducer (TDMPObject self);

/*!
\par Function:
Gets album art URI property.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>
			Pointer to device, container, or item information for which to get property value
		</td>
	</tr>
</table>

\return URI(string) album art URI property value
\return Null Specified object has no property value
\par Description:
This function returns the album art URI property.

Since this function returns the address to an area allocated in a DMP object as the return value, the property value can be referenced until the DMP object is deleted by dlnaDmpObjectClose().
*/
slim_char * dlnaDmpObjectPropAlbumArtURI (TDMPObject self);


/*!
\par Function:
Gets language property.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>
			Pointer to device, container, or item information for which to get property value
		</td>
	</tr>
</table>

\return URI(string) language property value
\return  Null Specified object has no property value
\par Description:
This function returns the language property.

Since this function returns the address to an area allocated in a DMP object as the return value, the property value can be referenced until the DMP object is deleted by dlnaDmpObjectClose().
*/
slim_char * dlnaDmpObjectPropLanguage (TDMPObject self);

/*!
\par Function:
Gets actor property.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>
			Pointer to device, container, or item information for which to get property value
		</td>
	</tr>
</table>

\return URI(string) actor property value
\return Null Specified object has no property value
\par Description:
This function returns the actor property.

Since this function returns the address to an area allocated in a DMP object as the return value, the property value can be referenced until the DMP object is deleted by dlnaDmpObjectClose().
*/
slim_char * dlnaDmpObjectPropActor (TDMPObject self);


#endif

/*@}*/

/**
 * @addtogroup macros
 */
/*@{*/

#ifndef _DOXYGEN
#define dlnaDmpObjectPropTitle(self)                	dlnaDmpObjectPropGet (self, SLIM_T("dc:title"))
#define dlnaDmpObjectPropCreator(self)              	dlnaDmpObjectPropGet (self, SLIM_T("dc:creator"))
#define dlnaDmpObjectPropCreator(self)              	dlnaDmpObjectPropGet (self, SLIM_T("dc:creator"))
#define dlnaDmpObjectPropWriteStatus(self)          	dlnaDmpObjectPropGet (self, SLIM_T("upnp:writeStatus"))
#define dlnaDmpObjectPropLongDescription(self)      	dlnaDmpObjectPropGet (self, SLIM_T("upnp:longDescription"))
#define dlnaDmpObjectPropDescription(self)          	dlnaDmpObjectPropGet (self, SLIM_T("upnp:description"))
#define dlnaDmpObjectPropPublisher(self) 	    	dlnaDmpObjectPropGet (self, SLIM_T("dc:publisher"))
#define dlnaDmpObjectPropContributor(self) 		dlnaDmpObjectPropGet (self, SLIM_T("dc:contributor"))
#define dlnaDmpObjectPropDate(self) 			dlnaDmpObjectPropGet (self, SLIM_T("dc:date"))
#define dlnaDmpObjectPropCopyrights(self)		dlnaDmpObjectPropGet (self, SLIM_T("dc:rights"))
#define dlnaDmpObjectPropArtist(self) 			dlnaDmpObjectPropGet (self, SLIM_T("upnp:artist"))
#define dlnaDmpObjectPropAlbum(self) 			dlnaDmpObjectPropGet (self, SLIM_T("upnp:album"))
#define dlnaDmpObjectPropGenre(self) 			dlnaDmpObjectPropGet (self, SLIM_T("upnp:genre"))
#define dlnaDmpObjectPropProducer(self) 		dlnaDmpObjectPropGet (self, SLIM_T("upnp:producer"))
#define dlnaDmpObjectPropAlbumArtURI(self)		dlnaDmpObjectPropGet (self, SLIM_T("upnp:albumArtURI"))
#define dlnaDmpObjectPropLanguage(self) 		dlnaDmpObjectPropGet (self, SLIM_T("dc:language"))
#define dlnaDmpObjectPropActor(self) 			dlnaDmpObjectPropGet (self, SLIM_T("upnp:actor"))
#endif


/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Gets Container restricted property value.
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>
                        Pointer to device, container, or item information for which to get property value
                </td>
        </tr>
</table>

\return "1" or "0"(string) restricted property value. "1" is restricted and is un-uploadable and "0" is unrestricted and is uploadable
\return Null Specified object has no property value
\par Description:
This function returns the restricted property value for the containers or folders to determine if the folder can be uploadable or not.

Since this function returns the address to an area allocated in a DMP object as the return value, the property value can be referenced until the DMP object is deleted by dlnaDmpObjectClose().
*/
DLNA_API slim_char *
dlnaDmpObjectPropRestricted (TDMPObject self);

#ifdef _DOXYGEN

/*!
\par Function:
Get the device name.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to device information obtained by dlnaDmpDeviceList()</td>
	</tr>
</table>

\return !=slim_nil Device name (NULL terminated)
\return == slim_nil Failed
\par Description:
This function returns the device name of the specified device.

The device name is searched for in the following order.

-# FriendlyName in XML (if it exists, value is returned even if it is empty)
-# ModelName in XML (if it exists, value is returned even if it is empty)

If not found for both 1 and 2, then it returns an empty string.

When TDMPEvent is notified as DMP_EV_FOUND_DEVS, it is recommended to call this function within TDMPEventHandler(), and get the device names.
*/
slim_char * dlnaDmpDeviceName (TDMPObject self);


/*!
\par Function:
Gets the device UUID.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by dlnaDmpDeviceList()</td>
 </tr>
</table>
     
\return Device UUID (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TDMPEvent is given by DMC_EV_FOUND_DEVS, it is recommended to call this
function within TDMCEventHandler() to get the device name.
*/
slim_char * dlnaDmpDeviceUuid (TDMPObject self);


/*!
\par Function:
Gets the manufacturer name.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by dlnaDmpDeviceList()</td>
 </tr>
</table>
     
\return manufacturer name (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TDMPEvent is given by DMP_EV_FOUND_DEVS, it is recommended to call this
function within TDMPEventHandler() to get the device name.
*/
slim_char * dlnaDmpManufacturerName (TDMPObject self);

/*!
\par Function:
Gets the manufacturer URL.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by dlnaDmpDeviceList()</td>
 </tr>
</table>
     
\return manufacturer URL (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TDMPEvent is given by DMP_EV_FOUND_DEVS, it is recommended to call this
function within TDMPEventHandler() to get the device name.
*/
slim_char * dlnaDmpManufacturerURL (TDMPObject self);


/*!
\par Function:
Gets the model name.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by dlnaDmpDeviceList()</td>
 </tr>
</table>
     
\return model name (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TDMPEvent is given by DMP_EV_FOUND_DEVS, it is recommended to call this
function within TDMPEventHandler() to get the device name.
*/
slim_char * dlnaDmpModelName (TDMPObject self);

/*!
\par Function:
Gets the model URL.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by dlnaDmpDeviceList()</td>
 </tr>
</table>
     
\return model URL (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TDMPEvent is given by DMP_EV_FOUND_DEVS, it is recommended to call this
function within TDMPEventHandler() to get the device name.
*/
slim_char * dlnaDmpModelURL (TDMPObject self);


/*!
\par Function:
Gets the model description.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by dlnaDmpDeviceList()</td>
 </tr>
</table>
     
\return model description (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TDMPEvent is given by DMP_EV_FOUND_DEVS, it is recommended to call this
function within TDMPEventHandler() to get the device name.
*/
slim_char * dlnaDmpModelDescription (TDMPObject self);

/*!
\par Function:
Gets the model number.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by dlnaDmpDeviceList()</td>
 </tr>
</table>
     
\return model number (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TDMPEvent is given by DMP_EV_FOUND_DEVS, it is recommended to call this
function within TDMPEventHandler() to get the device name.
*/
slim_char * dlnaDmpModelNumber (TDMPObject self);


/*!
\par Function:
Gets the serial number.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by dlnaDmpDeviceList()</td>
 </tr>
</table>
     
\return serial number (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TDMPEvent is given by DMP_EV_FOUND_DEVS, it is recommended to call this
function within TDMPEventHandler() to get the device name.
*/
slim_char * dlnaDmpSerialNumber (TDMPObject self);

/*!
\par Function:
Gets the TXT version.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by dlnaDMPDeviceList()</td>
 </tr>
</table>
     
\return TXT version (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TDMPEvent is given by DMP_EV_FOUND_DEVS, it is recommended to call this
function within TDMPEventHandler() to get the device name.
*/
slim_char * dlnaDmpTXTVersion (TDMPObject self);


#endif

/*@}*/

/**
 * @addtogroup macros
 */
/*@{*/

#ifndef _DOXYGEN
#define dlnaDmpDeviceName(self)            	dlnaDmpObjectPropGet (self, SLIM_T("friendlyName"))
#define dlnaDmpDeviceUuid(self) 		dlnaDmpObjectPropGet (self, SLIM_T("UDN"))
#define dlnaDmpManufacturerName(self)     	dlnaDmpObjectPropGet (self, SLIM_T("manufacturer"))
#define dlnaDmpManufacturerURL(self)     	dlnaDmpObjectPropGet (self, SLIM_T("manufacturerURL"))
#define dlnaDmpModelName(self)            	dlnaDmpObjectPropGet (self, SLIM_T("modelName"))
#define dlnaDmpModelURL(self)            	dlnaDmpObjectPropGet (self, SLIM_T("modelURL"))
#define dlnaDmpModelDescription(self)           dlnaDmpObjectPropGet (self, SLIM_T("modelDescription"))
#define dlnaDmpModelNumber(self)            	dlnaDmpObjectPropGet (self, SLIM_T("modelNumber"))
#define dlnaDmpSerialNumber(self)            	dlnaDmpObjectPropGet (self, SLIM_T("serialNumber"))
#define dlnaDmpTXTVersion(self)            	dlnaDmpObjectPropGet (self, SLIM_T("TXTVersion"))

#endif


/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/


/*!
\par Function: 
Gets resource URI property.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to item information for which to get property value</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_res_index</td>
		<td>
			>=0 Specifies resource index <br />
			-1 Specifies default resource
		</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_ResURI</td>
		<td>resource URI storage address </td>
	</tr>
</table>

\return DLNA_E_OK Successful termination 
\return Other Specified object has no property value 
\par Description: 
This function returns the resource URI property specified by the resource index.

Since this function returns the address to an area allocated in a DMP object as the return value, the
property value can be referenced until the DMP object is deleted by dlnaDmpObjectClose().
*/
DLNA_API slim_int
dlnaDmpObjectPropResURI (TDMPObject self, slim_int in_res_index, slim_char **out_ResURI);

/*!
\par Function: 
Gets resource size property.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to item information for which to get property value</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_res_index</td>
		<td>
			>=0 Specifies resource index <br />
			-1 Specifies default resource
		</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_ResSize</td>
		<td>resource size storage address </td>
	</tr>
</table>

\return DLNA_E_OK Successful termination 
\return Other Specified object has no property value 
\par Description: 
This function returns the resource size property specified by the resource index.

Since this function returns the address to an area allocated in a DMP object as the return value, the
property value can be referenced until the DMP object is deleted by dlnaDmpObjectClose().
*/
DLNA_API slim_int
dlnaDmpObjectPropResSize (TDMPObject self, slim_int in_res_index, slim_char **out_ResSize);

/*!
\par Function: 
Gets resource duration property.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to item information for which to get property value</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_res_index</td>
		<td>
			>=0 Specifies resource index <br />
			-1 Specifies default resource
		</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_ResDuration	</td>
		<td>
			resource duration storage address
			
			Supported formats are as follows:
			
			<b>
				duration = hours ":" minutes ":" seconds <br />
				hours = 1*5 DIGIT; 0-99999 <br />
				minutes = 2 DIGIT ; 00-59 <br />
				seconds = 2 DIGIT ["." 3 DIGIT] ; 00-59 (.000-.999) <br />
			</b>
			
			If the specified object does not have a property value, null is set 
		</td>
	</tr>
</table>

\return DLNA_E_OK Successful termination
\return Other Specified object has no property value 
\par Description: 
This function returns the resource duration property specified by the resource index.

Since this function returns the address to an area allocated in a DMP object as the return value, the
property value can be referenced until the DMP object is deleted by dlnaDmpObjectClose().
*/
DLNA_API slim_int
dlnaDmpObjectPropResDuration (TDMPObject self, slim_int in_res_index, slim_char **out_ResDuration);

/*!
\par Function:
Gets resource resolution property.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to item information for which to get property value</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_res_index</td>
		<td>
			>=0 Specifies resource index <br />
			-1 Specifies default resource
		</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_ResResolution</td>
		<td>resource resolution storage address</td>
	</tr>
</table>

\return DLNA_E_OK Successful termination
\return Other Specified object has no property value
\par Description:
This function returns the resource resolution property specified by the resource index.

Since this function returns the address to an area allocated in a DMP object as the return value, the property value can be referenced until the DMP object is deleted by dlnaDmpObjectClose().
*/
DLNA_API slim_int
dlnaDmpObjectPropResResolution (TDMPObject self, slim_int in_res_index, slim_char **out_ResResolution);

/*!
\par Function:
 Gets total number of resources.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to device, container, or item information for which to get property value</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_count</td>
		<td>Total number of resources</td>
	</tr>
</table>

\return >= 0 Number of resources
\return DMP_E_GENERIC Failed
\return DMP_E_INVAL Invalid argument
\par  Description:
This function returns the total number of resources.
*/
DLNA_API slim_int
dlnaDmpObjectPropResCount(TDMPObject self, slim_int *out_count);

/*!
\par Function:
Gets resource list.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to device, container, or item information for which to get property value</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_res_info</td>
		<td>Address where resource property obtained is stored</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_req_res_num</td>
		<td>Number of resources to get</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_begin_res_index</td>
		<td>Resource list start index</td>
	</tr>
</table>

\return >= 0 Number of resources obtained
\return DMP_E_GENERIC Failed
\return DMP_E_INVAL Invalid argument
\par Description:
This function gets in_req_res_num number of resource properties from the index specified for
in_begin_res_index, and stores them in out_res_info.
*/
DLNA_API slim_int
dlnaDmpObjectPropResList(TDMPObject self, TDMPResPropInfoParam *out_res_info, slim_int in_req_res_num, slim_int in_begin_res_index);

/*!
\par Function:
Gets DRM type.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to device, container, or item information for which to get property value</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_res_index</td>
		<td>
			>=0 Specifies resource index <br />
			-1 Specifies default resource
		</td>
	</tr>
</table>

\return DRM type (see "3.2.4 TDLNAObjectDRMType")
\par Description:
This function returns the DRM type of a property.
*/
DLNA_API TDLNAObjectDRMType
dlnaDmpObjectPropResDRMType(TDMPObject self, slim_int in_res_index);

/*!
\par Function:
Gets OperationParameter type.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to device, container, or item information for which to get property value</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_res_index</td>
		<td>
			>=0 Specifies resource index <br />
			-1 Specifies default resource
		</td>
	</tr>
</table>

\return OperationParameter type (see "3.2.5 TDLNAObjectOPType")
\par Description:
This function returns the OperationParameter type of an item.
 
*/
DLNA_API TDLNAObjectOPType
dlnaDmpObjectPropResOPType(TDMPObject self, slim_int in_res_index);

/*!
\par Function:
Gets value string for protocolInfo of specified name in resource.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to device, container, or item information for which to get property value</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_res_index</td>
		<td>
			>=0 Specifies resource index <br />
			-1 Specifies default resource
		</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_name</td>
		<td>String (NULL terminated) of name to search</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_value_str</td>
		<td>Address of first letter of value string for name obtained</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_value_len</td>
		<td>Length of value string for name obtained</td>
	</tr>
</table>

\return DMP_E_OK Successful termination
\return DMP_E_INVAL Invalid argument
\return DMP_E_NOTFOUND Object has no property value
\par Description:
This function searches for the specified name in the protocolInfo of the information resource specified for self, and returns the start address and length of that value string.

The value string obtained in out_value_str for the name specified by in_name is not NULL terminated, but represents a "substring" among a series of strings. Therefore, it must reference a buffer length
equal to out_value_len obtained.

Since this function returns the address to an area allocated in a DMP object as the return value, the property value can be referenced until the DMP object is deleted by dlnaDmpObjectClose().
*/
DLNA_API slim_int
dlnaDmpObjectPropResPIByName(TDMPObject self, slim_int in_res_index,slim_char * in_name, slim_char **out_value_str, slim_int *out_value_len);

/*!
\par Function:
Gets thumbnail resource ID of protocolInfo in resource.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to device, container, or item information for which to get property value</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_res_index</td>
		<td>Thumbnail resource ID</td>
	</tr>
</table>

\return DMP_E_OK Successful termination
\return DMP_E_INVAL Invalid argument
\return DMP_E_NOTFOUND Thumbnail resource not found
\par Description:
This function gets the thumbnail resource ID from the protocolInfo in information resource specified for self.

It searches for the media PROFILE ID (DLNA.ORG_PN) in the protocolInfo of multiple resources and, if there is a resource with a JPEG_TN or PNG_TN that represents the thumbnail, then it returns that resource ID. It searches for JPEG_PN first, and then, if none are found, it searches for PNG_TN.
*/
DLNA_API slim_int
dlnaDmpObjectPropResPIThumbnail(TDMPObject self,slim_int *out_res_index);

/*!
\par Function:
Gets device information specified for container and item information.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to container, item information</td>
	</tr>
</table>

\return != slim_nil Pointer to device information
\return == slim_nil Failed
\par Description:
This function returns the device information of the device that stores specified container or item information.

This function returns the specified device information as is, even if device information is specified for self.
*/
DLNA_API TDMPObject
dlnaDmpObjectGetDevice(TDMPObject self);

/*!
\par Function:
Sets item group information.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP instance</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_itemgroup</td>
		<td>
			Item group information
			
			For information about the dlna_item_group type, see the description of "Basic Data Types" in "NetFront Living Connect v2.0 Porting Guide".
		</td>
	</tr>
</table>
 
\return DMP_E_OK Succeeded
\return Other Failed
\par Description:
Not currently supported. Behavior of this function is not guaranteed. Schedule has not been determined.

This function sets item group information.

This function can only be used with a Windows Mobile application. This function cannot be used without a Windows Mobile application.
*/
DLNA_API slim_int
dlnaDmpSetItemGroup (TDMP self, dlna_item_group in_itemgroup);

/*!
\par Function:
Gets item group information.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP instance</td>
	</tr>
</table>

\return != slim_nil Item group information

For information about the dlna_item_group type, see the description of
"Basic Data Types" in "NetFront Living Connect v2.0 Porting Guide".
\return == slim_nil Failed
\par Description:
Not currently supported. Behavior of this function is not guaranteed. Schedule has not been determined.

This function returns the item group information used in the DMP application.

This function can only be used with a Windows Mobile application. This function cannot be used without a Windows Mobile application.
*/
DLNA_API dlna_item_group
dlnaDmpGetItemGroup (TDMP self);


DLNA_API slim_bool
dlnaDmpObjectPropIsPausable (TDMPObject self, slim_int in_res_index);


/*!
\par Function:
Gets protocolInfo DTCP-IP information in resource.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to device, container, or item information for which to get property value</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_res_index</td>
		<td>
			>=0 Resource ID <br />
			-1 Specifies default resource
		</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_dtcp_info</td>
		<td>DTCP-IP information structure</td>
	</tr>
</table>

\return DMP_E_OK Successful termination
\return DMP_E_INVAL Invalid argument
\return DMP_E_NOMEM Memory error
\return DMP_E_NOTFOUND DTCP-IP information not found
\return DMP_E_GENERIC Other error
\par Description:
This function gets the DTCP-IP information from the protocolInfo in information resource specified for
self.

It searches for the following in the protocolInfo, and stores it in the specified DTCP-IP information
structure.

- Searches for DTCP1HOST, and stores the source-side IP address.
- Searches for DTCP1PORT, and stores the source-side DTCP session port number.
- Searches for DLNA.ORG_FLAGS, and stores the following information.
	
	- If BIT12 is 1, then MOVE is enabled
	- If BIT13 is 1, then COPY is enabled
	- If BIT12 and BIT13 are both 1, then MOVE and COPY are enabled
	- If BIT12 and BIT13 are both 0, then MOVE and COPY are disabled

If neither DTCP1HOST nor DTCP1PORT are found, then it returns DMP_E_NOTFOUND as the return value.
*/
DLNA_API slim_int
dlnaDmpObjectPropResDtcpInfo (TDMPObject self, slim_int in_res_index, TDMPResPropDtcpInfoParam *out_dtcp_info);

#ifdef HAVE_DTCP

/*!
\par Function:
Function adds drm entry to device
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA DMP device object</td>
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
		<td> \b DMP_E_OK</td>
		<td> \b Entry added succesfully</td>
	</tr>
	<tr>
		<td>DMP_E_GENERIC</td>
		<td>Generic error occured</td>
	</tr>
</table>
\par Description:
Function adds drm entry specyfied in in_dtcp_entry to device represented by self.
*/

DLNA_API slim_int
dlnaDmpDRMManagerAddDrmEntry (TDMP self, dtcp_device_entry_t *in_dtcp_entry, TDLNADRMManagerCallback in_proc);

/*!
\par Function:
Function deletes drm entry from device
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA DMP device object</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_type</td>
		<td>DRM type to delete from device</td>
	</tr>
</table>
\return none
\par Description:
Function deletes drm entry specyfied by in_type from device represented by self.
*/

DLNA_API void
dlnaDmpDRMManagerDeleteDrmEntry (TDMP self, media_drm_t in_type);

#if defined (HAVE_DTCP) && defined(DTCP_SUPPORT_DMP_EXPAND_API)

/*!
\par Function:
Function initializes DTCP service
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA DMP device object</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_dtcp</td>
		<td>DTCP output object</td>
	</tr>
</table>
\return slim_int error code value
\par Return Values:
<table>
	<tr>
		<td> \b DMP_E_OK</td>
		<td> \b Entry added succesfully</td>
	</tr>
	<tr>
		<td>DMP_E_GENERIC</td>
		<td>Generic error occured</td>
	</tr>
	<tr>
		<td>DMP_E_NOMEM</td>
		<td>Out of memory error</td>
	</tr>
</table>
\par Description:
Function initializes DTCP service on DMP device.
*/

slim_int
dlnaDmpDtcpInitialize (TDMP self, void **out_dtcp);

/*!
\par Function:
Function finalize DTCP device.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA DMP device object</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_dtcp</td>
		<td>DTCP object to finalize</td>
	</tr>
</table>
\return this function not returns any values
\par Description:
Function finalize DTCP service on DMP device.
*/

void
dlnaDmpDtcpFinalize (TDMP self, void *in_dtcp);

/*!
\par Function:
Function gets DTCP SNK device.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA DMP device object</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>dtcp</td>
		<td>DTCP device from witch we will get SNK device</td>
	</tr>
</table>
\return void pointer to DTCP object
\par Return Values:
<table>
	<tr>
		<td> \b !=slim_nil</td>
		<td> \b Getting SNK device success</td>
	</tr>
	<tr>
		<td>slim_nil</td>
		<td>Generic error occured</td>
	</tr>
</table>
\par Description:
Function gets DTCP SNK device from dtcp.
*/

void *
dlnaDmpDtcpGetSnkDevice (TDMP self, void *dtcp);

/*!
\par Function:
Function finalize DTCP SNK device.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA DMP device object</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>dtcp</td>
		<td>DTCP device connected with DTCP SNK to finalize</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>snk_dev</td>
		<td>DTCP SNK device to finalize</td>
	</tr>
</table>
\return this function not returns any values
\par Description:
Function finalize DTCP service on DMP device.
*/

void
dlnaDmpDtcpSnkDeviceFinalize (TDMP self, void *dtcp, void *snk_dev);
#endif /* defined (HAVE_DTCP) */

/*!
\par Function:
Gets TransferMode information from protocolInfo in resource.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to device, container, or item information for which to get property value</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_res_index</td>
		<td>
			>=0 Resource ID <br />
			-1 Specifies default resource
		</td>
	</tr>
</table>

\return DLNA_OBJECT_TRANSFER_MODE_INVALID Invalid argument, or memory error
\return DLNA_OBJECT_TRANSFER_MODE_STREAMING Streaming transfer mode
\return DLNA_OBJECT_TRANSFER_MODE_INTERACTIVE Interactive transfer mode
\return DLNA_OBJECT_TRANSFER_MODE_BACKGROUND Background mode
\par Description:
This function gets the TransferMode information from the protocolInfo in information resource
specified for self.
\note 
The following conditions exist for getting TransferMode information.

- If the background mode flag is in DLNA.FLAGS of the 4th protocolInfo field, then it changes
to background mode (download mode).
- If the background mode flag is not in DLNA.FLAGS of the 4th protocolInfo field, or
DLNA.FLAGS itself is missing, then the following occurs.


<b>-</b> For images, it changes to interactive transfer mode. <br />
<b>-</b> For audio and video, it changes to streaming transfer mode.
*/
DLNA_API TDLNAObjectTransferMode
dlnaDmpObjectPropResTransferMode(TDMPObject self, slim_int in_res_index);


#endif /* HAVE_DTCP */

/*!
\par Function:
Function sets friendly name on DMP device.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP instance</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_home_path</td>
		<td>New friendly name to set</td>
	</tr>
</table>

\return DMP_E_OK Succeeded
\return DMP_E_INVAL Invalid argument(s) specified
\return DMP_E_GENERIC Generic error occurred
\par Description:
Function sets friendly name on DMP device.
*/

DLNA_API slim_int
dlnaDmpSetFriendlyName (TDMP self, slim_char *in_friendly_name);

/*!
\par Function:
Function gets friendly name of device.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP instance</td>
	</tr>
</table>

\return pointer to string containing device friendly name
\return slim_nil if failed
\par Description:
Function gets friendly name of device specyfied by self.
*/

DLNA_API slim_char *
dlnaDmpGetFriendlyName (TDMP self);

#ifdef ENABLE_MOVIEDB_MOVIECOVER
/*!
\par Function:
Gets property cover url.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMP instance</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>out_coverurl</td>
		<td>pointer where cover url will be stored</td>
	</tr>
</table>

\return DMP_E_OK
\return DMP_E_INVAL Invalid argument(s) specified
\return DMP_E_GENERIC Generic error occurred
\par Description:
This function gets property cover URL if moviecover is supported
*/
DLNA_API slim_int
dlnaDmpObjectPropCoverURL(TDMPObject self, slim_char **out_coverurl);
#endif /*ENABLE_MOVIEDB_MOVIECOVER*/

#ifdef ENABLE_GPS_SUPPORT
/*!
\par Function:
Gets GPS position.
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to item information for which to get property value</td>
  </tr>
  <tr>
    <td>[out]</td>
    <td>out_gps_latitude</td>
    <td>GPS latitude</td>
  </tr>
  <tr>
    <td>[out]</td>
    <td>out_gps_longitude</td>
    <td>GPS longitude</td>
  </tr>
</table>

\return DMP_E_OK Succeeded
\return DMP_E_INVAL Invalid argument
\return DMP_E_GENERIC Error
\par Description:
This function returns GPS position if available. Latitude is stored in out_gps_latitude and longitude is
stored in out_gps_longitude. The out arguments are set and valid only if return value is DMP_E_OK.
*/
DLNA_API slim_int
dlnaDmpObjectPropExifGPS(TDMPObject self, slim_char **out_gps_latitude, slim_char **out_gps_longitude);
#endif /* ENABLE_GPS_SUPPORT */

#ifdef ENABLE_SUBTITLE_SUPPORT
/*!
\par Function:
Gets number of subtitles.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to item information for which to get property value</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_resURI</td>
		<td>Resource URI for which to get the number of subtitles. If slim_nil, all subtitles are counted.</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_count</td>
		<td>Number of subtitles</td>
	</tr>
</table>

\return DMP_E_OK Succeeded
\return DMP_E_INVAL Invalid argument
\return DMP_E_GENERIC Error
\par Description:
This function returns the number of existing subtitles to out_count. If in_resURI is not slim_nil, only
the subtitles that belong to the resource URI specified for in_resURI are counted.
*/
DLNA_API slim_int
dlnaDmpObjectPropSubtitleCount(TDMPObject self, slim_char *in_resURI, slim_int *out_count);

/*!
\par Function:
Gets subtitle information.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to item information for which to get property value</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_resURI</td>
		<td>Resource URI whose subtitle to take into account. If slim_nil, all subtitles are used.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_subtitle_index</td>
		<td>Subtitle index starting from 0.</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_subtitle</td>
		<td>Subtitle information</td>
	</tr>
</table>

\return DMP_E_OK Succeeded
\return DMP_E_INVAL Invalid argument
\return DMP_E_GENERIC Error
\par Description:
This function returns the subtitle information specified for in_resURI and in_subtitle_index to out_subtitle.
*/
DLNA_API slim_int
dlnaDmpObjectPropSubtitle(TDMPObject self, slim_char *in_resURI, slim_int in_subtitle_index, TDMPSubtitle *out_subtitle);
#endif /* ENABLE_SUBTITLE_SUPPORT */
/*!
\par Function:
Counts property user metadata items.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Object witch metadata we should get count</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_count</td>
		<td>place where number of user-metadata nodes will be stored.</td>
	</tr>
</table>

\return slim_int error code
\par Return Values:
<table>
	<tr>
		<td> \b DMP_E_ok</td>
		<td> <b>Success</b></td>
	</tr>
	<tr>
		<td>DMP_E_INVAL</td>
		<td>Invalid Value passed to function</td>
	</tr>
	<tr>
		<td>DMP_E_NOTFOUND</td>
		<td>user_meta not found</td>
	</tr>
	<tr>
		<td>DMP_E_GENERIC</td>
		<td>generic error occurred</td>
	</tr>
</table>
\par Description:
This function counts property user metadata items and stores it in out_count.
*/
DLNA_API slim_int
dlnaDmpObjectPropUserMetadataCount(TDMPObject self, slim_int * out_count);

/*!
\par Function:
Gets property user metadata items.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Object witch metada we should get count</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_meta_index</td>
		<td>Index of searched metadata</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_name</td>
		<td>place where name of user-metadata will be stored.</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_value</td>
		<td>place where value of user-metadata will be stored.</td>
	</tr>
</table>

\return slim_int error code
\par Return Values:
<table>
	<tr>
		<td> \b DMP_E_ok</td>
		<td> <b>Success</b></td>
	</tr>
	<tr>
		<td>DMP_E_INVAL</td>
		<td>Invalid Value passed to function</td>
	</tr>
	<tr>
		<td>DMP_E_NOTFOUND</td>
		<td>user_meta not found</td>
	</tr>
	<tr>
		<td>DMP_E_GENERIC</td>
		<td>generic error occurred</td>
	</tr>
</table>
\par Description:
This function gets property user metadata item specyfied by in_meta_index stores name of this item in out_name and value in out_value.
*/
DLNA_API slim_int
dlnaDmpObjectPropUserMetadata(TDMPObject self, slim_int in_meta_index, slim_char ** out_name, slim_char ** out_value);

/*!
\par Function:
Gets device icon URL.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to device type object for which to get property icon URL</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_icon_device_type</td>
		<td>icon type to get property URL.</td>
	</tr>
</table>

\return pointer to specyfied icon relative path if Succeeded
\return slim_nil if it cannot find specyfied icon for item or self is a slim_nil or if self is not a device type object
\par Description:
This function returns device icon relative path.
To get icon url you need concatenation of returned value of dlnaDmpDeviceBaseURL function and this function.
*/
DLNA_API slim_char *
dlnaDmpObjectPropIconURL(TDMPObject self, dlna_device_icon_type in_icon_device_type);


#if defined(DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2) || defined(DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1)
/*!
\par Function:
Function checks if object has Service.
\par Parameters:
<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMP Object Pointer</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>upnp_service_type</td>
                <td>UPnP Service Type</td>
        </tr>
</table>
\return slim_bool value
\par Return Values:
<table>
        <tr>
                <td> \b slim_true</td>
                <td> \b Object has Service</td>
        </tr>
        <tr>
                <td>slim_false</td>
                <td>Object does not have Service</td>
        </tr>
</table>
\par Description:
This function checks if object has Service or not.
*/
slim_bool
dlnaDmpObjectHasEmbeddedService(TDMPObject self, slim_char* upnp_service_type);
#endif

#ifdef DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2
/*!
\par Function:
Function executes Basic Management Service Action GetTestInfo
\par Parameters:
<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMP Object Pointer</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_obj_eh</td>
                <td>TDMPObjectEventHandler pointer (pointer to callback that handles the response)</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_arg</td>
                <td>Event handler input argument</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_testId</td>
                <td>TestID of the test for which TestInfo is requested</td>
        </tr>
</table>
\return slim_bool value
\par Return Values:
<table>
        <tr>
                <td> \b DMP_E_OK</td>
                <td> \b Action Execution succeeded</td>
        </tr>
        <tr>
                <td>DMP_E_INVAL</td>
                <td>Invalid value</td>
        </tr>
        <tr>
                <td>DMP_E_GENERIC</td>
                <td>Failed to execute action successfully</td>
        </tr>
</table>
\par Description:
This function Basic Management Service action GetTestInfo for the specified test.
The DIAGE sends the action response with A_ARG_TYPE_TestType and A_ARG_TYPE_TestState.
The action response can be obtained in the event handler callback function.
*/

slim_int
dlnaDmpBmsGetTestInfo(TDMPObject self, TDMPObjectEventHandler in_obj_eh, void *in_arg, slim_char* in_testId);

/*!
\par Function:
Function executes Basic Management Service Action Ping
\par Parameters:
<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMP Object Pointer</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_obj_eh</td>
                <td>TDMPObjectEventHandler pointer (pointer to callback that handles the response)</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_arg</td>
                <td>Event handler input argument</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_host</td>
                <td>Host of the test for which Ping is requested</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_numberOfRepetitions</td>
                <td>Repetition number of the test for which Ping is requested</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_timeout</td>
                <td>Timeout of the test for which Ping is requested</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_dataBlockSize</td>
                <td>Data block size of the test for which Ping is requested</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_dscp</td>
                <td>DSCP of the test for which Ping is requested</td>
        </tr>
</table>
\return slim_int value
\par Return Values:
<table>
        <tr>
                <td> \b DMP_E_OK</td>
                <td> \b Action Execution succeeded</td>
        </tr>
        <tr>
                <td>DMP_E_INVAL</td>
                <td>Invalid value</td>
        </tr>
        <tr>
                <td>DMP_E_GENERIC</td>
                <td>Failed to execute action successfully</td>
        </tr>
</table>
\par Description:
This function Basic Management Service action Ping for the specified test.
The DIAGE sends the action response with A_ARG_TYPE_TestID.
The action response can be obtained in the event handler callback function.
*/

slim_int
dlnaDmpBmsPing(TDMPObject self, TDMPObjectEventHandler in_obj_eh,
                            void *in_arg,
                            slim_char *in_host,
                            slim_char *in_numberOfRepetitions,
                            slim_char *in_timeout,
                            slim_char *in_dataBlockSize,
                            slim_char *in_dscp);
/*!
\par Function:
Function executes Basic Management Service Action GetPingResult
\par Parameters:
<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMP Object Pointer</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_obj_eh</td>
                <td>TDMPObjectEventHandler pointer (pointer to callback that handles the response)</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_arg</td>
                <td>Event handler input argument</td>
        </tr>
</table>
\return slim_bool value
\par Return Values:
<table>
        <tr>
                <td> \b DMP_E_OK</td>
                <td> \b Action Execution succeeded</td>
        </tr>
        <tr>
                <td>DMP_E_INVAL</td>
                <td>Invalid value</td>
        </tr>
        <tr>
                <td>DMP_E_GENERIC</td>
                <td>Failed to execute action successfully</td>
        </tr>
</table>
\par Description:
This function Basic Management Service action GetPingResult for the specified test.
The DIAGE sends the action response with A_ARG_TYPE_PingStatus and A_ARG_TYPE_String.
The action response can be obtained in the event handler callback function.
*/

slim_int
dlnaDmpBmsGetPingResult(TDMPObject self, TDMPObjectEventHandler in_obj_eh, void *in_arg, slim_char* in_testId);

/*!
\par Function:
Function executes Basic Management Service Action NSLookup
\par Parameters:
<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMC Object Pointer</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_obj_eh</td>
                <td>TDMCObjectEventHandler pointer (pointer to callback that handles the response)</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_arg</td>
                <td>Event handler input argument</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_host</td>
                <td>The name of the host to look up</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_server</td>
                <td>The name or address of the DNS server</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_count</td>
                <td>The number of lookups to perform</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_timeout</td>
                <td>The length of time to wait for response</td>
        </tr>
</table>
\return slim_bool value
\par Return Values:
<table>
        <tr>
                <td> \b DMC_E_OK</td>
                <td> \b Action Execution succeeded</td>
        </tr>
        <tr>
                <td>DMC_E_INVAL</td>
                <td>Invalid value</td>
        </tr>
        <tr>
                <td>DMC_E_GENERIC</td>
                <td>Failed to execute action successfully</td>
        </tr>
</table>
\par Description:
This function Basic Management Service action NSLookup for the specified test.
The DIAGE sends the action response with A_ARG_TYPE_TestID.
The action response can be obtained in the event handler callback function.
*/

slim_int
dlnaDmpBmsNSLookup(TDMPObject self, 
		         TDMPObjectEventHandler in_obj_eh,
                 void *in_arg, 
				 slim_char* in_host,
				 slim_char* in_server,
				 slim_char* in_count,
				 slim_char* in_timeout);


/*!
\par Function:
Function executes Basic Management Service Action GetNSLookupResult
\par Parameters:
<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMC Object Pointer</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_obj_eh</td>
                <td>TDMCObjectEventHandler pointer (pointer to callback that handles the response)</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_arg</td>
                <td>Event handler input argument</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_testId</td>
                <td>TestID of the test for which TestInfo is requested</td>
        </tr>
</table>
\return slim_bool value
\par Return Values:
<table>
        <tr>
                <td> \b DMC_E_OK</td>
                <td> \b Action Execution succeeded</td>
        </tr>
        <tr>
                <td>DMC_E_INVAL</td>
                <td>Invalid value</td>
        </tr>
        <tr>
                <td>DMC_E_GENERIC</td>
                <td>Failed to execute action successfully</td>
        </tr>
</table>
\par Description:
This function Basic Management Service action GetNSLookupResult for the specified test.
The DIAGE sends the action response with A_ARG_TYPE NSLookupStatus, A_ARG_TYPE_String, A_ARG_TYPE_UInt and A_ARG_TYPE_NSLookupResult.
The action response can be obtained in the event handler callback function.
*/

slim_int
dlnaDmpBmsGetNSLookupResult(TDMPObject self,
		                    TDMPObjectEventHandler in_obj_eh,
							void *in_arg,
							slim_char* in_testId);

slim_int
dlnaDmpBmsGetDeviceStatus(TDMPObject self, TDMPObjectEventHandler in_obj_eh, void *in_arg);

/*!
\par Function:
Function executes Basic Management Service Action Traceroute
\par Parameters:
<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMP Object Pointer</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_obj_eh</td>
                <td>TDMPObjectEventHandler pointer (pointer to callback that handles the response)</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_arg</td>
                <td>Event handler input argument</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_host</td>
                <td>Host of the test for which Traceroute is requested</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_timeout</td>
                <td>Timeout of the test for which Traceroute is requested</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_block</td>
                <td>Block size of the test for which Traceroute is requested</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_count</td>
                <td>Count of the test for which Traceroute is requested</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_dscp</td>
                <td>DSCP of the test for which Traceroute is requested</td>
        </tr>
</table>
\return slim_bool value
\par Return Values:
<table>
        <tr>
                <td> \b DMP_E_OK</td>
                <td> \b Action Execution succeeded</td>
        </tr>
        <tr>
                <td>DMP_E_INVAL</td>
                <td>Invalid value</td>
        </tr>
        <tr>
                <td>DMP_E_GENERIC</td>
                <td>Failed to execute action successfully</td>
        </tr>
</table>
\par Description:
This function Basic Management Service action Traceroute for the specified test.
The DIAGE sends the action response with A_ARG_TYPE_TestID.
The action response can be obtained in the event handler callback function.
*/

slim_int
dlnaDmpBmsTraceroute(TDMPObject self, TDMPObjectEventHandler in_obj_eh,
                            void *in_arg,
                            slim_char *in_host,
                            slim_char *in_timeout,
                            slim_char *in_block,
                            slim_char *in_count,
                            slim_char *in_dscp);
/*!
\par Function:
Function executes Basic Management Service Action GetTracerouteResult
\par Parameters:
<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMP Object Pointer</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_obj_eh</td>
                <td>TDMPObjectEventHandler pointer (pointer to callback that handles the response)</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_arg</td>
                <td>Event handler input argument</td>
        </tr>
</table>
\return slim_bool value
\par Return Values:
<table>
        <tr>
                <td> \b DMP_E_OK</td>
                <td> \b Action Execution succeeded</td>
        </tr>
        <tr>
                <td>DMP_E_INVAL</td>
                <td>Invalid value</td>
        </tr>
        <tr>
                <td>DMP_E_GENERIC</td>
                <td>Failed to execute action successfully</td>
        </tr>
</table>
\par Description:
This function Basic Management Service action GetTracerouteResult for the specified test.
The DIAGE sends the action response with A_ARG_TYPE_Traceroute-Status and A_ARG_TYPE_String.
The action response can be obtained in the event handler callback function.
*/

slim_int
dlnaDmpBmsGetTracerouteResult(TDMPObject self, TDMPObjectEventHandler in_obj_eh, void *in_arg, slim_char* in_testId);

/*!
\par Function:
Function executes Basic Management Service Action GetTestIDs
\par Parameters:
<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMP Object Pointer</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_obj_eh</td>
                <td>TDMPObjectEventHandler pointer (pointer to callback that handles the response)</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_arg</td>
                <td>Event handler input argument</td>
        </tr>
</table>
\return slim_bool value
\par Return Values:
<table>
        <tr>
                <td> \b DMP_E_OK</td>
                <td> \b Action Execution succeeded</td>
        </tr>
        <tr>
                <td>DMP_E_INVAL</td>
                <td>Invalid value</td>
        </tr>
        <tr>
                <td>DMP_E_GENERIC</td>
                <td>Failed to execute action successfully</td>
        </tr>
</table>
\par Description:
This function Basic Management Service action GetTestIDs for the specified test.
The DIAGE sends the action response with A_ARG_TYPE_TestID.
The action response can be obtained in the event handler callback function.
*/

slim_int
dlnaDmpBmsGetTestIds(TDMPObject self, TDMPObjectEventHandler in_obj_eh, void *in_arg);

/*!
\par Function:
Function executes Basic Management Service Action GetActiveTestIDs
\par Parameters:
<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMP Object Pointer</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_obj_eh</td>
                <td>TDMPObjectEventHandler pointer (pointer to callback that handles the response)</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_arg</td>
                <td>Event handler input argument</td>
        </tr>
</table>
\return slim_bool value
\par Return Values:
<table>
        <tr>
                <td> \b DMP_E_OK</td>
                <td> \b Action Execution succeeded</td>
        </tr>
        <tr>
                <td>DMP_E_INVAL</td>
                <td>Invalid value</td>
        </tr>
        <tr>
                <td>DMP_E_GENERIC</td>
                <td>Failed to execute action successfully</td>
        </tr>
</table>
\par Description:
This function Basic Management Service action GetActiveTestIDs for the specified test.
The DIAGE sends the action response with A_ARG_TYPE_TestID.
The action response can be obtained in the event handler callback function.
*/

slim_int
dlnaDmpBmsGetActiveTestIds(TDMPObject self, TDMPObjectEventHandler in_obj_eh, void *in_arg);

#endif /*DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2*/


#ifdef DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1
/*!
\par Function:
Function executes Energy Management Service Action GetInterfaceInfo
\par Parameters:
<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMP Object Pointer</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_obj_eh</td>
                <td>TDMPObjectEventHandler pointer (pointer to callback that handles the response)</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_arg</td>
                <td>Event handler input argument</td>
        </tr>
</table>
\return slim_bool value
\par Return Values:
<table>
        <tr>
                <td> \b DMP_E_OK</td>
                <td> \b Action Execution succeeded</td>
        </tr>
        <tr>
                <td>DMP_E_INVAL</td>
                <td>Invalid value</td>
        </tr>
        <tr>
                <td>DMP_E_GENERIC</td>
                <td>Failed to execute action successfully</td>
        </tr>
</table>
\par Description:
This function Energy Management Service action GetInterfaceInfo.
The LPE sends the action response with NetworkInterfaceInfo.
The action response can be obtained in the event handler callback function.
*/
slim_int
dlnaDmpEmsGetInterfaceInfo(TDMPObject self, TDMPObjectEventHandler in_obj_eh, void *in_arg);

/*!
\par Function:
Function executes Energy Management Service Action ServiceSubscription
\par Parameters:
<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMP Object Pointer</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_obj_eh</td>
                <td>TDMPObjectEventHandler pointer (pointer to callback that handles the response)</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_arg</td>
                <td>Event handler input argument</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_uniqueServiceName</td>
                <td>to indicate the specific service in the device to be subscribed.</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_resourceUri</td>
                <td>to indicate a specific content binary of interest or empty.</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_durationRequest</td>
                <td>to indicate the duration the resources are requested for. A value of "0" requests a duration of infinite.</td>
        </tr>
</table>
\return slim_bool value
\par Return Values:
<table>
        <tr>
                <td> \b DMP_E_OK</td>
                <td> \b Action Execution succeeded</td>
        </tr>
        <tr>
                <td>DMP_E_INVAL</td>
                <td>Invalid value</td>
        </tr>
        <tr>
                <td>DMP_E_GENERIC</td>
                <td>Failed to execute action successfully</td>
        </tr>
</table>
\par Description:
This function Energy Management Service action ServiceSubscription.
The LPE sends the action response with ServiceSubscriptionID and Duration.
The action response can be obtained in the event handler callback function.
*/
slim_int
dlnaDmpEmsSerivceSubscription(TDMPObject self,
		                      TDMPObjectEventHandler in_obj_eh,
						      void *in_arg,
						      slim_char *in_uniqueServiceName,
						      slim_char *in_resourceUri,
						      slim_char *in_durationRequest);

/*!
\par Function:
Function executes Energy Management Service Action ServiceRenewal
\par Parameters:
<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMP Object Pointer</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_obj_eh</td>
                <td>TDMPObjectEventHandler pointer (pointer to callback that handles the response)</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_arg</td>
                <td>Event handler input argument</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_durationRequest</td>
                <td>to indicate the duration the resources are requested for. A value of "0" requests a duration of infinite.</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_serviceSubscriptionID</td>
                <td>an identifier set by the device in a previous response to the ServiceSubscription() action.</td>
        </tr>
</table>
\return slim_bool value
\par Return Values:
<table>
        <tr>
                <td> \b DMP_E_OK</td>
                <td> \b Action Execution succeeded</td>
        </tr>
        <tr>
                <td>DMP_E_INVAL</td>
                <td>Invalid value</td>
        </tr>
        <tr>
                <td>DMP_E_GENERIC</td>
                <td>Failed to execute action successfully</td>
        </tr>
</table>
\par Description:
This function Energy Management Service action ServiceRenewal.
The LPE sends the action response with Duration.
The action response can be obtained in the event handler callback function.
*/
slim_int
dlnaDmpEmsServiceRenewal(TDMPObject self,
		                 TDMPObjectEventHandler in_obj_eh,
						 void *in_arg,
						 slim_char *in_durationRequest,
						 slim_char *in_serviceSubscriptionID);

/*!
\par Function:
Function executes Energy Management Service Action ServiceRelease
\par Parameters:
<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMP Object Pointer</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_obj_eh</td>
                <td>TDMPObjectEventHandler pointer (pointer to callback that handles the response)</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_arg</td>
                <td>Event handler input argument</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_serviceSubscriptionID</td>
                <td>an identifier set by the device in a previous response to the ServiceSubscription() action.</td>
        </tr>
</table>
\return slim_bool value
\par Return Values:
<table>
        <tr>
                <td> \b DMP_E_OK</td>
                <td> \b Action Execution succeeded</td>
        </tr>
        <tr>
                <td>DMP_E_INVAL</td>
                <td>Invalid value</td>
        </tr>
        <tr>
                <td>DMP_E_GENERIC</td>
                <td>Failed to execute action successfully</td>
        </tr>
</table>
\par Description:
This function Energy Management Service action ServiceRenewal.
The action response can be obtained in the event handler callback function.
*/
slim_int
dlnaDmpEmsServiceRelease(TDMPObject self,
		                 TDMPObjectEventHandler in_obj_eh,
						 void *in_arg,
						 slim_char *in_serviceSubscriptionID);

#endif /* DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1 */


/*@}*/
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DMP_API_H */
