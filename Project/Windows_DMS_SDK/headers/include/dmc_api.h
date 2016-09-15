/*
 * dmc_api.h
 * Copyright (C) 2007-2014 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */
  
/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

/* DMC/DMC API.  */

#ifndef NFLC_DMC_API_H
#define NFLC_DMC_API_H

#include <dlna_peer.h>
#include <dlna_api.h>
#include <nflc_sxml.h>

#ifdef _DOXYGEN
#undef DLNA_API
#define DLNA_API
#endif

/**
 * @addtogroup macros
 */
/*@{*/

/* DMC events.  */
#define DMC_E_FORMAT_INVAL                            DLNA_E_FORMAT_INVAL
#define DMC_EV_FOUND_DEVS                             DLNA_EV_FOUND_DEVS
#define DMC_EV_BYEBYE                                 DLNA_EV_BYEBYE
#define DMC_EV_UNAVAILABLE                            DLNA_EV_UNAVAILABLE
#define DMC_EV_DEVICE_SUID_CHG                        DLNA_EV_DEVICE_SUID_CHG
#define DMC_EV_DEVICE_CUIDS_CHG                       DLNA_EV_DEVICE_CUIDS_CHG
#define DMC_EV_DEVICE_TIDS_CHG                        DLNA_EV_DEVICE_TIDS_CHG
#define DMC_EV_DEVICE_LAST_CHG                        DLNA_EV_DEVICE_LAST_CHG
#define DMC_EV_DEVICE_OUT_OF_MEMORY                   DLNA_EV_DEVICE_OUT_OF_MEMORY
#define DMC_EV_GENA_NETWORK_INTERFACE_INFO            DLNA_EV_GENA_NETWORK_INTERFACE_INFO

/*!
TDMCEvent is a value that represents the type of event set for TDMCEventHandler() (see "4.5 TDMCEventHandler").

For more information, see "UPnP AV ContentDirectory:1 Service Template Version 1.01".

One of the following values is set for TDMCEvent.

<table>	
	<tr>
		<td><b>Definition</b></td>
		<td><b>Event details</b></td>
	</tr>
	<tr>
		<td>DMC_EV_FOUND_DEVS</td>
		<td>DMC detected device(s)</td>
	</tr>
	<tr>
		<td>DMC_EV_BYEBYE</td>
		<td>Detected ssdp:byebye</td>
	</tr>
	<tr>
		<td>DMC_EV_UNAVAILABLE</td>
		<td>Failed to receive ssdp:alive from a device</td>
	</tr>
	<tr>
		<td>DMC_EV_DEVICE_SUID_CHG</td>
		<td>Received SystemUpdateID notification from DMS <br />
							DMS contents changed</td>
	</tr>
	<tr>
		<td>DMC_EV_DEVICE_CUIDS_CHG</td>
		<td>Received ContainerUpdateIDs notification from DMS <br />
			contents when a container is modified</td>
	</tr>
	<tr>
		<td>DMC_EV_DEVICE_TIDS_CHG</td>
		<td>Received TransferIDs notification from DMS contents when file transfers initiated by ImportResource or ExportResource started or finished</td>
	</tr>
 	<tr>
		<td>DMC_EV_DEVICE_LAST_CHG</td>
		<td>Received LastChange notification from DMR.Notification is given every time the AVTransport state changes</td>
	</tr>
	<tr>
		<td>DMC_EV_DEVICE_OUT_OF_MEMORY</td>
		<td>Insufficient memory.</td>
	</tr>
	<tr>
		<td>DMC_EV_GENA_NETWORK_INTERFACE_INFO</td>
		<td>Network interface information updated from Energy Management Service.</td>
	</tr>
</table>
*/

#define TDMCEvent                                     TDLNAEvent

#define TDMCEventError                                TDLNAEventError

/* DMC object event.  */
#define DMC_OBJECT_EV_START                           DLNA_OBJECT_EV_START
#define DMC_OBJECT_EV_BROWSE_END                      DLNA_OBJECT_EV_BROWSE_END
#define DMC_OBJECT_EV_BROWSE_ERROR                    DLNA_OBJECT_EV_BROWSE_ERROR
#define DMC_OBJECT_EV_SEARCH_END                      DLNA_OBJECT_EV_SEARCH_END
#define DMC_OBJECT_EV_SEARCH_ERROR                    DLNA_OBJECT_EV_SEARCH_ERROR

#define DMC_OBJECT_EV_PLAY_OPEN_OK                    DLNA_OBJECT_EV_PLAY_OPEN_OK
#define DMC_OBJECT_EV_PLAY_OPEN_FAILED                DLNA_OBJECT_EV_PLAY_OPEN_FAILED
#define DMC_OBJECT_EV_PLAY_OPEN_NEXT_OK               DLNA_OBJECT_EV_PLAY_OPEN_NEXT_OK
#define DMC_OBJECT_EV_PLAY_OPEN_NEXT_FAILED           DLNA_OBJECT_EV_PLAY_OPEN_NEXT_FAILED
#define DMC_OBJECT_EV_PLAY_PLAY_OK                    DLNA_OBJECT_EV_PLAY_PLAY_OK
#define DMC_OBJECT_EV_PLAY_PLAY_FAILED                DLNA_OBJECT_EV_PLAY_PLAY_FAILED
#define DMC_OBJECT_EV_PLAY_STOP_OK                    DLNA_OBJECT_EV_PLAY_STOP_OK
#define DMC_OBJECT_EV_PLAY_STOP_FAILED                DLNA_OBJECT_EV_PLAY_STOP_FAILED
#define DMC_OBJECT_EV_PLAY_PAUSE_OK                   DLNA_OBJECT_EV_PLAY_PAUSE_OK
#define DMC_OBJECT_EV_PLAY_PAUSE_FAILED               DLNA_OBJECT_EV_PLAY_PAUSE_FAILED
#define DMC_OBJECT_EV_PLAY_JUMP_OK                    DLNA_OBJECT_EV_PLAY_JUMP_OK
#define DMC_OBJECT_EV_PLAY_JUMP_FAILED                DLNA_OBJECT_EV_PLAY_JUMP_FAILED
#define DMC_OBJECT_EV_PLAY_NEXT_OK                    DLNA_OBJECT_EV_PLAY_NEXT_OK
#define DMC_OBJECT_EV_PLAY_NEXT_FAILED                DLNA_OBJECT_EV_PLAY_NEXT_FAILED
#define DMC_OBJECT_EV_PLAY_PREVIOUS_OK                    DLNA_OBJECT_EV_PLAY_PREVIOUS_OK
#define DMC_OBJECT_EV_PLAY_PREVIOUS_FAILED                DLNA_OBJECT_EV_PLAY_PREVIOUS_FAILED
#define DMC_OBJECT_EV_PLAY_FF_OK                      DLNA_OBJECT_EV_PLAY_FF_OK
#define DMC_OBJECT_EV_PLAY_FF_FAILED                  DLNA_OBJECT_EV_PLAY_FF_FAILED
#define DMC_OBJECT_EV_PLAY_RW_OK                      DLNA_OBJECT_EV_PLAY_RW_OK
#define DMC_OBJECT_EV_PLAY_RW_FAILED                  DLNA_OBJECT_EV_PLAY_RW_FAILED
#define DMC_OBJECT_EV_PLAY_MEDIA_INFO_OK              DLNA_OBJECT_EV_PLAY_MEDIA_INFO_OK
#define DMC_OBJECT_EV_PLAY_MEDIA_INFO_FAILED          DLNA_OBJECT_EV_PLAY_MEDIA_INFO_FAILED
#define DMC_OBJECT_EV_PLAY_POSITION_INFO_OK           DLNA_OBJECT_EV_PLAY_POSITION_INFO_OK
#define DMC_OBJECT_EV_PLAY_POSITION_INFO_FAILED       DLNA_OBJECT_EV_PLAY_POSITION_INFO_FAILED
#define DMC_OBJECT_EV_PLAY_UPDATED                    DLNA_OBJECT_EV_PLAY_UPDATED
#define DMC_OBJECT_EV_PLAY_STATE_CHANGED              DLNA_OBJECT_EV_PLAY_STATE_CHANGED
#define DMC_OBJECT_EV_PLAY_CLOSED                     DLNA_OBJECT_EV_PLAY_CLOSED
#define DMC_OBJECT_EV_PLAY_ERROR                      DLNA_OBJECT_EV_PLAY_ERROR
#define DMC_OBJECT_EV_RENDERER_LIST_PRESETS           DLNA_OBJECT_EV_RENDERER_LIST_PRESETS
#define DMC_OBJECT_EV_RENDERER_SELECT_PRESET          DLNA_OBJECT_EV_RENDERER_SELECT_PRESET
#define DMC_OBJECT_EV_RENDERER_VOL_GET                DLNA_OBJECT_EV_RENDERER_VOL_GET
#define DMC_OBJECT_EV_RENDERER_VOL_SET                DLNA_OBJECT_EV_RENDERER_VOL_SET
#define DMC_OBJECT_EV_RENDERER_VOLDB_GET              DLNA_OBJECT_EV_RENDERER_VOLDB_GET
#define DMC_OBJECT_EV_RENDERER_VOLDB_RANGE_GET        DLNA_OBJECT_EV_RENDERER_VOLDB_RANGE_GET
#define DMC_OBJECT_EV_RENDERER_VOLDB_SET              DLNA_OBJECT_EV_RENDERER_VOLDB_SET
#define DMC_OBJECT_EV_RENDERER_MUTE_GET               DLNA_OBJECT_EV_RENDERER_MUTE_GET
#define DMC_OBJECT_EV_RENDERER_MUTE_SET               DLNA_OBJECT_EV_RENDERER_MUTE_SET
#define DMC_OBJECT_EV_GET_SERVICE_DESCRIPTION_END     DLNA_OBJECT_EV_GET_SERVICE_DESCRIPTION_END
#define DMC_OBJECT_EV_GET_SERVICE_DESCRIPTION_ERROR   DLNA_OBJECT_EV_GET_SERVICE_DESCRIPTION_ERROR

#ifdef DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2
#define DMC_OBJECT_EV_DIAGC_BMS_GET_DEVICE_STATUS     DLNA_OBJECT_EV_DIAGC_BMS_GET_DEVICE_STATUS
#define DMC_OBJECT_EV_DIAGC_BMS_PING                  DLNA_OBJECT_EV_DIAGC_BMS_PING
#define DMC_OBJECT_EV_DIAGC_BMS_GET_PING_RESULT       DLNA_OBJECT_EV_DIAGC_BMS_GET_PING_RESULT
#define DMC_OBJECT_EV_DIAGC_BMS_NSLOOKUP              DLNA_OBJECT_EV_DIAGC_BMS_NSLOOKUP
#define DMC_OBJECT_EV_DIAGC_BMS_GET_NSLOOKUP_RESULT   DLNA_OBJECT_EV_DIAGC_BMS_GET_NSLOOKUP_RESULT
#define DMC_OBJECT_EV_DIAGC_BMS_TRACEROUTE            DLNA_OBJECT_EV_DIAGC_BMS_TRACEROUTE
#define DMC_OBJECT_EV_DIAGC_BMS_GET_TRACEROUTE_RESULT DLNA_OBJECT_EV_DIAGC_BMS_GET_TRACEROUTE_RESULT
#define DMC_OBJECT_EV_DIAGC_BMS_GET_TEST_IDS          DLNA_OBJECT_EV_DIAGC_BMS_GET_TEST_IDS
#define DMC_OBJECT_EV_DIAGC_BMS_GET_ACTIVE_TEST_IDS   DLNA_OBJECT_EV_DIAGC_BMS_GET_ACTIVE_TEST_IDS
#define DMC_OBJECT_EV_DIAGC_BMS_GET_TEST_INFO         DLNA_OBJECT_EV_DIAGC_BMS_GET_TEST_INFO
#endif /* DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2 */

#ifdef DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1
#define DMC_OBJECT_EV_LPC_EMS_GET_INTERFACE_INFO      DLNA_OBJECT_EV_LPC_EMS_GET_INTERFACE_INFO
#ifdef DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_SUBSCRIPTION
#define DMC_OBJECT_EV_LPC_EMS_SERVICE_SUBSCRIPTION    DLNA_OBJECT_EV_LPC_EMS_SERVICE_SUBSCRIPTION
#define DMC_OBJECT_EV_LPC_EMS_SERVICE_RENEWAL         DLNA_OBJECT_EV_LPC_EMS_SERVICE_RENEWAL
#define DMC_OBJECT_EV_LPC_EMS_SERVICE_RELEASE         DLNA_OBJECT_EV_LPC_EMS_SERVICE_RELEASE
#endif /* DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_SUBSCRIPTION */
#endif /* DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1 */

#ifdef DEVELOPMENT_DLNA_SUPPORT_RADACP
#define DMC_OBJECT_EV_RADA_GET_SYSTEM_INFO            DLNA_OBJECT_EV_RADA_GET_SYSTEM_INFO
#define DMC_OBJECT_EV_RADA_EDIT_FILTER                DLNA_OBJECT_EV_RADA_EDIT_FILTER
#endif /* DEVELOPMENT_DLNA_SUPPORT_RADACP */

/*!
TDMCObjectEvent is a value that represents the type of event set for
TDMCObjectEventHandler().

One of the following values is set for TDMCObjectEvent.

<table>	
	<tr>
		<td><b>Definition</b></td>
		<td><b>Event details</b></td>
	</tr>
	<tr>
		<td>DMC_OBJECT_EV_START</td>
		<td>Initial value (not used)</td>
	</tr>
	<tr>
		<td>DMC_OBJECT_EV_BROWSE_END</td>
		<td>Browsing ended</td>
	</tr>
 	<tr>
		<td>DMC_OBJECT_EV_BROWSE_ERROR</td>
		<td>Error occurred while browsing</td>
	</tr>				
	<tr>
		<td>DMC_OBJECT_EV_SEARCH_END</td>
		<td>Search ended</td>
	</tr>
	<tr>
		<td>DMC_OBJECT_EV_SEARCH_ERROR</td>
		<td>Error occurred while searching</td>
	</tr>
 	<tr>
		<td>DMC_OBJECT_EV_PLAY_OPEN_OK</td>
		<td>Preparation of player completed</td>
	</tr>
	<tr>
		<td>DMC_OBJECT_EV_PLAY_OPEN_FAILED</td>
		<td>Preparation of player failed</td>
	</tr>
 	<tr>
		<td>DMC_OBJECT_EV_PLAY_PLAY_OK</td>
		<td>Playing</td>
	</tr>			
 	<tr>
		<td>DMC_OBJECT_EV_PLAY_PLAY_FAILED</td>
		<td>Playback failed</td>
	</tr>			
 	<tr>
		<td>DMC_OBJECT_EV_PLAY_PAUSE_OK</td>
		<td>Pausing</td>
	</tr>
	<tr>
		<td>DMC_OBJECT_EV_PLAY_PAUSE_FAILED</td>
		<td>Pausing failed</td>
	</tr>
	<tr>
		<td>DMC_OBJECT_EV_PLAY_JUMP_OK</td>
		<td>Jump process is being performed</td>
	</tr>
 	<tr>
		<td>DMC_OBJECT_EV_PLAY_JUMP_FAILED</td>
		<td>Jump processing failed</td>
	</tr>	
 	<tr>
		<td>DMC_OBJECT_EV_PLAY_UPDATED</td>
		<td>Updating</td>
	</tr>			
 	<tr>
		<td>DMC_OBJECT_EV_PLAY_STOP_OK</td>
		<td>Player stopped</td>
	</tr>		
 	<tr>
		<td>DMC_OBJECT_EV_PLAY_STOP_FAILED</td>
		<td>Player failed to stop</td>
	</tr>			
	<tr>
		<td>DMC_OBJECT_EV_PLAY_CLOSED</td>
		<td>Player terminated</td>
	</tr>			
 	<tr>
		<td>DMC_OBJECT_EV_PLAY_MEDIA_INFO_OK</td>
		<td>Completed getting media information</td>
	</tr>		
 	<tr>
		<td>DMC_OBJECT_EV_PLAY_MEDIA_INFO_FAILED</td>
		<td>Failed to get media information</td>
	</tr>			
 	<tr>
		<td>DMC_OBJECT_EV_PLAY_STATE_CHANGED</td>
		<td>Play state has been changed</td>
	</tr>	
 	<tr>
		<td>DMC_OBJECT_EV_PLAY_ERROR</td>
		<td>Error occurred while playing</td>
	</tr>
	 	<tr>
		<td>DMC_OBJECT_EV_RENDERER_VOL_GET</td>
		<td>Volume value was obtained</td>
	</tr>	
 	<tr>
		<td>DMC_OBJECT_EV_RENDERER_MUTE_GET</td>
		<td>Mute was obtained</td>
	</tr>			
 	<tr>
		<td>DMC_OBJECT_EV_RENDERER_VOL_SET</td>
		<td>Volume value was set</td>
	</tr>		
 	<tr>
		<td>DMC_OBJECT_EV_RENDERER_VOLDB_GET</td>
		<td>Volume value (dB) was obtained</td>
	</tr>	
 	<tr>
		<td>DMC_OBJECT_EV_RENDERER_VOLDB_RANGE_GET</td>
		<td>Range of volume value (dB) was obtained</td>
	</tr>		
 	<tr>
		<td>DMC_OBJECT_EV_RENDERER_VOLDB_SET</td>
		<td>Volume value (dB) was set</td>
	</tr>
 	<tr>
		<td>DMC_OBJECT_EV_RENDERER_MUTE_SET</td>
		<td>Mute was set</td>
	</tr>
 	<tr>
		<td>DMC_OBJECT_EV_PLAY_FF_OK</td>
		<td>Fast forwarding</td>
	</tr>
	<tr>
		<td>DMC_OBJECT_EV_GET_SERVICE_DESCRIPTION_END</td>
		<td>Get service description ended.</td>
	</tr>
	<tr>
		<td>DMC_OBJECT_EV_GET_SERVICE_DESCRIPTION_ERROR</td>
		<td>Failed to get service description</td>
	</tr>
</table>
<br />
<table>	
	<tr>
		<td><b>Definition</b></td>
		<td><b>Event details</b></td>
	</tr>
 	<tr>
		<td>DMC_OBJECT_EV_PLAY_FF_FAILED</td>
		<td>Failed in fast forwarding</td>
	</tr>	
 	<tr>
		<td>DMC_OBJECT_EV_PLAY_RW_OK</td>
		<td>Rewinding</td>
	</tr>			
 	<tr>
		<td>DMC_OBJECT_EV_PLAY_RW_FAILED</td>
		<td>Failed in rewinding</td>
	</tr>		
 	<tr>
		<td>DMC_OBJECT_EV_PLAY_POSITION_INFO_OK</td>
		<td>Playback position information was obtained</td>
	</tr>			
	<tr>
		<td>DMC_OBJECT_EV_PLAY_POSITION_INFO_FAILED</td>
		<td>Failed to get playback position information</td>
	</tr>
	<tr>
		<td>DMC_OBJECT_EV_PLAY_NEXT_OK</td>
		<td>Playing next track</td>
	</tr>
 	<tr>
		<td>DMC_OBJECT_EV_PLAY_NEXT_FAILED</td>
		<td>Playback of next track failed</td>
	</tr>		
 	<tr>
		<td>DMC_OBJECT_EV_PLAY_PREVIOUS_OK</td>
		<td>Playing previous track</td>
	</tr>	
	<tr>
		<td>DMC_OBJECT_EV_PLAY_PREVIOUS_FAILED</td>
		<td>Playback of previous track failed</td>
	</tr>
</table>
*/

#define TDMCEventError                                TDLNAEventError
#define TDMCObjectEventError                          TDLNAObjectEventError

#define DMC_EV_ERROR_TIMEOUT            DLNA_EV_ERROR_TIMEOUT
#define DMC_EV_ERROR_UNAVAILABLE        DLNA_EV_ERROR_UNAVAILABLE
#define DMC_EV_ERROR_GENERIC            DLNA_EV_ERROR_GENERIC


#define  TDMCObjectEvent                              TDLNAObjectEvent

/* DMC device type.  */
#define DMC_DEV_TYPE_START                            DLNA_DEV_TYPE_START
#define DMC_DEV_TYPE_UNKNOWN                          DLNA_DEV_TYPE_UNKNOWN
#define DMC_DEV_TYPE_DMS                              DLNA_DEV_TYPE_DMS
#define DMC_DEV_TYPE_M_DMS                            DLNA_DEV_TYPE_M_DMS
#define DMC_DEV_TYPE_DMR                              DLNA_DEV_TYPE_DMR
#define DMC_DEV_TYPE_DMPr                             DLNA_DEV_TYPE_DMPr
#define DMC_DEV_TYPE_DMP                              DLNA_DEV_TYPE_DMP
#define DMC_DEV_TYPE_M_DMP                            DLNA_DEV_TYPE_M_DMP
#define DMC_DEV_TYPE_DMC                              DLNA_DEV_TYPE_DMC
#define DMC_DEV_TYPE_M_DMC                            DLNA_DEV_TYPE_M_DMC
#ifdef DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2
#define DMC_DEV_TYPE_MDD                              DLNA_DEV_TYPE_MDD
#endif /* DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2 */
#ifdef DEVELOPMENT_DLNA_SUPPORT_RADACP
#define DMC_DEV_TYPE_RAS                              DLNA_DEV_TYPE_RAS
#endif /* DEVELOPMENT_DLNA_SUPPORT_RADACP */

#define DMC_DEV_TYPE_ANY                              DLNA_DEV_TYPE_ANY

/*!
One of the following DLNA device types is set for TDMCDeviceType.

<table>	
	<tr>
		<td><b>Definition</b></td>
		<td><b>Event details</b></td>
	</tr>
	<tr>
		<td>DMC_DEV_TYPE_START</td>
		<td>Initial value (not used)</td>
	</tr>
	<tr>
		<td>DMC_DEV_TYPE_UNKNOWN</td>
		<td>Unknown device</td>
	</tr>
	<tr>
		<td>DMC_DEV_TYPE_DMS</td>
		<td>DMS</td>
	</tr>
	<tr>
		<td>DMC_DEV_TYPE_M_DMS</td>
		<td>M-DMS</td>
	</tr>
	<tr>
		<td>DMC_DEV_TYPE_DMR</td>
		<td>DMR</td>
	</tr>
	<tr>
		<td>DLNA_DEV_TYPE_DMPr</td>
		<td>DMPr</td>
	</tr>
	<tr>
		<td>DLNA_DEV_TYPE_DMP</td>
		<td>DMP</td>
	</tr>
	<tr>
		<td>DLNA_DEV_TYPE_M_DMP</td>
		<td>M-DMP</td>
	</tr>
 	<tr>
		<td>DLNA_DEV_TYPE_DMC</td>
		<td>DMC</td>
	</tr>
 	<tr>
		<td>DLNA_DEV_TYPE_M_DMC</td>
		<td>M-DMC</td>
	</tr>
	<tr>
		<td>DLNA_DEV_TYPE_M_DMU</td>
		<td>M-DMU</td>
	</tr>
	<tr>
		<td>DLNA_DEV_TYPE_M_DMD</td>
		<td>M-DMD</td>
	</tr>
	<tr>
		<td>DLNA_DEV_TYPE_RUIS_LEVEL1</td>
		<td>Level 1 RUI server device.</td>
	</tr>
	<tr>
		<td>DLNA_DEV_TYPE_RUIS_LEVEL2</td>
		<td>Level 2 RUI server device.</td>
	</tr>
	<tr>
		<td>DLNA_DEV_TYPE_RUIS_IBOX</td>
		<td>I-Box RUI server device.</td>
	</tr>
</table>
*/
#define TDMCDeviceType                                TDLNADeviceType

/* DMC API return code.  */

/*!
Succeeded (=0)
*/

#define DMC_E_OK                                      DLNA_E_OK

/*!
Generic error
*/

#define DMC_E_GENERIC                                 DLNA_E_GENERIC

/*!
Invalid argument(s) specified
*/

#define DMC_E_INVAL                                   DLNA_E_INVAL

/*!
Insufficient memory
*/

#define DMC_E_NOMEM                                   DLNA_E_NOMEM

/*!
Device not available
*/

#define DMC_E_DEV                                     DLNA_E_DEV

/*!
Invalid object
*/

#define DMC_E_OBJ                                     DLNA_E_OBJ

/*!
Specified Item already exists
*/
	
#define DMC_E_ITEM_EX                                 DLNA_E_ITEM_EX

/*!
Invalid URI
*/

#define DMC_E_URI                                     DLNA_E_URI

/*!
Communication error
*/

#define DMC_E_COMM                                    DLNA_E_COMM

/*!
File not found
*/

#define DMC_E_NOFILE                                  DLNA_E_NOFILE

/*!
File I/O error
*/

#define DMC_E_FILE_IO                                 DLNA_E_FILE_IO

/*!
File already exists
*/

#define DMC_E_FILE_EX                                 DLNA_E_FILE_EX
#define DMC_E_NOT_SUPPORT                             DLNA_E_NOT_SUPPORT
#define DMC_E_NOTFOUND                                DLNA_E_NOTFOUND

#define DMC_API_ERROR                                 DLNA_API_ERROR

/*DMC PLAY STATE*/

/*!
Undefined state
*/

#define DMC_PLAY_STATE_UNKNOWN                        DLNA_OBJECT_STATE_UNKNOWN

/*!
Media not set
*/

#define DMC_PLAY_STATE_NO_MEDIA_SPECIFIED             DLNA_OBJECT_STATE_NO_MEDIA_SPECIFIED	

/*!
Stopped
*/

#define DMC_PLAY_STATE_STOPPED                        DLNA_OBJECT_STATE_STOPPED

/*!
Playing
*/

#define DMC_PLAY_STATE_PLAYING                        DLNA_OBJECT_STATE_PLAYING

/*!
Paused
*/

#define DMC_PLAY_STATE_PAUSED                         DLNA_OBJECT_STATE_PAUSED
#define DMC_PLAY_STATE_TRANSITIONING                  DLNA_OBJECT_STATE_TRANSITIONING

/*!
Maximum value of this type
*/

#define DMC_PLAY_STATE_MAX                            DLNA_OBJECT_STATE_MAX


/* DMC Jump Mode */
#define DMC_JUMP_MODE_TRACK_NR      DLNA_JUMP_MODE_TRACK_NR
#define DMC_JUMP_MODE_ABS_TIME      DLNA_JUMP_MODE_ABS_TIME
#define DMC_JUMP_MODE_REL_TIME      DLNA_JUMP_MODE_REL_TIME
#define DMC_JUMP_MODE_ABS_COUNT     DLNA_JUMP_MODE_ABS_COUNT
#define DMC_JUMP_MODE_REL_COUNT     DLNA_JUMP_MODE_REL_COUNT
#define DMC_JUMP_MODE_CHANNEL_FREQ  DLNA_JUMP_MODE_CHANNEL_FREQ
#define DMC_JUMP_MODE_TAPE_INDEX    DLNA_JUMP_MODE_TAPE_INDEX
#define DMC_JUMP_MODE_FRAME         DLNA_JUMP_MODE_FRAME

/*@}*/

/* DMC API types.  */

/**
 * @addtogroup datatypes
 */
/*@{*/

/*!
TDMC is a DMC instance.

DMC applications must not access the TDMC.
*/

typedef void *TDMC;

/*!
TDMCObject is a pointer to a generic object that allows the DMP library to handle data internally.

DMC applications must not access the TDMCObject (hereafter DMC object).
*/

typedef void *TDMCObject;


/*!
TDMCPlayState is the play state of a DMR managed by a DMC.

One of the following states is set for TDMCPlayState.
<table>	
	<tr>
		<td><b>Definition</b></td>
		<td><b>Event details</b></td>
	</tr>
	<tr>
		<td>DMC_PLAY_STATE_UNKNOWN</td>
		<td>Undefined state</td>
	</tr>
	<tr>
		<td>DMC_PLAY_STATE_NO_MEDIA_SPECIFIED</td>
		<td>Media not set</td>
	</tr>
	<tr>
		<td>DMC_PLAY_STATE_STOPPED</td>
		<td>Stopped</td>
	</tr>
 	<tr>
		<td>DMC_PLAY_STATE_PLAYING</td>
		<td>Playing</td>
	</tr>		
 	<tr>
		<td>DMC_PLAY_STATE_PAUSED</td>
		<td>Paused</td>
	</tr>
 	<tr>
		<td>DMC_PLAY_STATE_TRANSITIONING</td>
		<td>Transitioning</td>
	</tr>
</table>
*/

typedef slim_int TDMCPlayState;

/*@}*/


/**
 * @addtogroup macros
 */
/*@{*/

/* DMC event handler.  */

/*!
\par Function:
Callback function that notifies of internally generated event.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMC object</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>event</td>
		<td>Value that indicates type of internally generated event</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument specified by dlnaDmcOpen()</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_param</td>
		<td>Notification parameter specified for every in_event</td>
	</tr>
</table>

\return DMC_E_OK Succeeded
\return Other Failed
\par Description:
This function notifies the DMC application of the detection, withdrawal, and update of a DLNA device.

The value of in_param varies depending on the received in_event notification.

DMC_EV_FOUND_DEVS is sent once, when device lookup is completed.

DMC_EV_BYEBYE/DMC_EV_UNAVAILABLE is specified for in_event when DMC realizes that the DMS
is not available. And, before deleting the DMS device information, the container information and item
information relating to the DMS must be deleted. Use dlnaDmcObjectClose() to delete each item
of information.

DMC_EV_DEVICE_SUIDS_CHG is notified when DMC receives a SystemUpdateIDs state variable
change in a GENA event message. When this event is notified, DMC should browse all of containers
on the system updated DMS.

DMC_EV_DEVICE_CUIDS_CHG is notified when DMC receives a ContainerUpdateIDs state variable
change in a GENA event message. When this event is notified, DMC should browse the updated
containers.

DMC_EV_DEVICE_TIDS_CHG is notified when DMC receives a TransferIDs state variable change in a
GENA event message.

DMC_EV_DEVICE_LAST_CHG is notified when DMC receives a LastChange state variable change in a
GENA event message.

For more information about SystemUpdateID, ContainerUpdateIDs, TransferIDs and LastChange, see
"UPnP AV ContentDirectory:3 Service Template Version 1.01".

The following are the data types and content of the in_param corresponding to each in_event.

<table>	
	<tr>
		<td><b>DMC event code</b></td>
		<td><b>Type of in_param</b></td>
		<td><b>Content of in_param</b></td>
	</tr>
	<tr>
		<td>DMC_EV_FOUND_DEVS</td>
		<td>slim_int*</td>
		<td>Pointer to total number of detected devices</td>
	</tr>
	<tr>
		<td>DMC_EV_BYEBYE</td>
		<td>TDMCObject</td>
		<td>Pointer to device that was removed</td>
	</tr>
	<tr>
		<td>DMC_EV_UNAVAILABLE</td>
		<td>TDMCObject</td>
		<td>Pointer to device that was removed</td>
	</tr>
	<tr>
		<td>DMC_EV_DEVICE_SUID_CHG</td>
		<td>TDMCGenaNotifyEHParam *</td>
		<td>Pointer to TDMCGenaNotifyEHParam structure</td>
	</tr>
	<tr>
		<td>DMC_EV_DEVICE_CUIDS_CHG</td>
		<td>TDMCGenaNotifyEHParam *</td>
		<td>Pointer to TDMCGenaNotifyEHParam structure</td>
	</tr>
	<tr>
		<td>DMC_EV_DEVICE_TIDS_CHG</td>
		<td>TDMCGenaNotifyEHParam *</td>
		<td>Pointer to TDMCGenaNotifyEHParam structure</td>
	</tr>
	<tr>
		<td>DMC_EV_DEVICE_LAST_CHG</td>
		<td>TDMCGenaNotifyEHParam *</td>
		<td>Pointer to TDMCGenaNotifyEHParam structure</td>
	</tr>
</table>
*/

#define TDMCEventHandler TDLNAEventHandler

/*!
\par Function:
Callback function that notifies of API processing result.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to device, container, or item information specified for API</td>
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

\return DMC_E_OK Succeeded
\return Other Failed
\par Description:
This function notifies the DMC application of an API processing result. This function is called from the
context where the DMC is running.

The following is information of which this function is notified when executing each respective API.

The TDMCObjectParam structure that is generated and released on the DMC library is only enabled
within this function.

<table>	
	<tr>
		<td><b>API name</b></td>
		<td><b>in_event</b></td>
		<td><b>in_param</b></td>
	</tr>
	<tr>
		<td>dlnaDmcObjectBrowse</td>
		<td>DMC_OBJECT_EV_BROWSE_END</td>
		<td>TDMCObjectParam*</td>
	</tr>
	<tr>
		<td></td>
		<td>DMC_OBJECT_EV_BROWSE_ERROR</td>
		<td>TDMCObjectParam*</td>
	</tr>
	<tr>
		<td>dlnaDmcObjectSearch</td>
		<td>DMC_OBJECT_EV_SEARCH_END</td>
		<td>TDMCObjectParam*</td>
	</tr>
	<tr>
		<td></td>
		<td>DMC_OBJECT_EV_SEARCH_ERROR</td>
		<td>TDMCObjectParam*</td>
	</tr>
	<tr>
		<td>dlnaDmcPlayOpen</td>
		<td>DMC_OBJECT_EV_PLAY_OPEN_OK</td>
		<td>slim_nil</td>
	</tr>
	<tr>
		<td></td>
		<td>DMC_OBJECT_EV_PLAY_OPEN_FAILED</td>
		<td>slim_nil</td>
	</tr>
	<tr>
		<td>dlnaDmcPlayPlay</td>
		<td>DMC_OBJECT_EV_PLAY_PLAY_OK</td>
		<td>slim_nil</td>
	</tr>
	<tr>
		<td></td>
		<td>DMC_OBJECT_EV_PLAY_PLAY_FAILED</td>
		<td>slim_nil</td>
	</tr>
	<tr>
		<td></td>
		<td>DMC_OBJECT_EV_PLAY_CLOSED</td>
		<td>slim_nil</td>
	</tr>
	<tr>
		<td></td>
		<td>DMC_OBJECT_EV_PLAY_ERROR</td>
		<td>slim_nil</td>
	</tr>
	<tr>
		<td>dlnaDmcPlayStop</td>
		<td>DMC_OBJECT_EV_PLAY_STOP_OK</td>
		<td>slim_nil</td>
	</tr>
	<tr>
		<td></td>
		<td>DMC_OBJECT_EV_PLAY_STOP_FAILED</td>
		<td>slim_nil</td>
	</tr>
	<tr>
		<td>dlnaDmcPlayPause</td>
		<td>DMC_OBJECT_EV_PLAY_PAUSE_OK</td>
		<td>slim_nil</td>
	</tr>
	<tr>
		<td></td>
		<td>DMC_OBJECT_EV_PLAY_PAUSE_FAILED</td>
		<td>slim_nil</td>
	</tr>
	<tr>
		<td>dlnaDmcPlayJump</td>
		<td>DMC_OBJECT_EV_PLAY_JUMP_OK</td>
		<td>slim_nil</td>
	</tr>
	<tr>
		<td></td>
		<td>DMC_OBJECT_EV_PLAY_JUMP_FAILED</td>
		<td>slim_nil</td>
	</tr>
	<tr>
		<td>dlnaDmcPlayFastForward</td>
		<td>DMC_OBJECT_EV_PLAY_FF_OK</td>
		<td>slim_nil</td>
	</tr>
	<tr>
		<td></td>
		<td>DMC_OBJECT_EV_PLAY_FF_FAILED</td>
		<td>slim_nil</td>
	</tr>
	<tr>
		<td>dlnaDmcPlayRewind</td>
		<td>DMC_OBJECT_EV_PLAY_RW_OK</td>
		<td>slim_nil</td>
	</tr>
</table>
<br />
<table>
	<tr>
		<td><b>API name</b></td>
		<td><b>in_event</b></td>
		<td><b>in_param</b></td>
	</tr>
	<tr>
		<td></td>
		<td>DMC_OBJECT_EV_PLAY_RW_FAILED</td>
		<td>slim_nil</td>
	</tr>
	<tr>
		<td>dlnaDmcPlayNext</td>
		<td>DMC_OBJECT_EV_PLAY_NEXT_OK</td>
		<td>slim_nil</td>
	</tr>
	<tr>
		<td></td>
		<td>DMC_OBJECT_EV_PLAY_NEXT_FAILED</td>
		<td>slim_nil</td>
	</tr>
	<tr>
		<td>dlnaDmcPlayPrevious</td>
		<td>DMC_OBJECT_EV_PLAY_PREVIOUS_OK</td>
		<td>slim_nil</td>
	</tr>
	<tr>
		<td></td>
		<td>DMC_OBJECT_EV_PLAY_PREVIOUS_FAILED</td>
		<td>slim_nil</td>
	</tr>
	<tr>
		<td>dlnaDmcPlayerGetVolume</td>
		<td>DMC_OBJECT_EV_RENDERER_VOL_GET</td>
		<td>TDMCObjectVolumeControlEHParam*</td>
	</tr>
	<tr>
		<td>dlnaDmcPlayerSetVolume</td>
		<td>DMC_OBJECT_EV_RENDERER_VOL_SET</td>
		<td>TDMCObjectVolumeControlEHParam*</td>
	</tr>
	<tr>
		<td>dlnaDmcPlayerGetVolumeDB</td>
		<td>DMC_OBJECT_EV_RENDERER_VOLDB_GET</td>
		<td>TDMCObjectVolumeControlEHParam*</td>
	</tr>
	<tr>
		<td>dlnaDmcPlayerSetVolumeDB</td>
		<td>DMC_OBJECT_EV_RENDERER_VOLDB_SET</td>
		<td>TDMCObjectVolumeControlEHParam*</td>
	</tr>
	<tr>
		<td>dlnaDmcPlayerGetMuteState</td>
		<td>DMC_OBJECT_EV_RENDERER_MUTE_GET</td>
		<td>TDMCObjectVolumeControlEHParam*</td>
	</tr>
	<tr>
		<td>dlnaDmcPlayerSetMuteState</td>
		<td>DMC_OBJECT_EV_RENDERER_MUTE_SET</td>
		<td>TDMCObjectVolumeControlEHParam*</td>
	</tr>
	<tr>
		<td>dlnaDmcPlayerGetVolumeDBRange</td>
		<td>DMC_OBJECT_EV_RENDERER_VOLDB_RANGE_GET</td>
		<td>TDMCObjectVolumeControlEHParam*</td>
	</tr>
	<tr>
		<td>dlnaDmcPlayGetMediaInfo</td>
		<td>DMC_OBJECT_EV_PLAY_MEDIA_INFO_OK</td>
		<td>TDMCObjectMediaInfoParam*</td>
	</tr>
	<tr>
		<td></td>
		<td>DMC_OBJECT_EV_PLAY_MEDIA_INFO_FAILED</td>
		<td>slim_nil*</td>
	</tr>
	<tr>
		<td>dlnaDmcPlayGetPosition</td>
		<td>DMC_OBJECT_EV_PLAY_POSITION_INFO_OK</td>
		<td>TDMCObjectPositionParam*</td>
	</tr>
	<tr>
		<td></td>
		<td>DMC_OBJECT_EV_PLAY_POSITION_INFO_FAILED</td>
		<td>slim_nil*</td>
	</tr>
	<tr>
		<td>T.B.D.</td>
		<td>DMC_OBJECT_EV_PLAY_UPDATED</td>
		<td>T.B.D.</td>
	</tr>
	<tr>
		<td>dlnaDmcPlayXXX</td>
		<td>DMC_OBJECT_EV_PLAY_STATE_CHANGED</td>
		<td>slim_int*</td>
	</tr>
</table>

T.B.D. means that it is not currently supported. Schedule has not been determined.
*/

#define TDMCObjectEventHandler TDLNAObjectEventHandler

/*@}*/

/**
 * @addtogroup structures
 */
/*@{*/

/* dlnaDmcNew parameter.  */
struct TDMCNewParam_
{
  /* DLNA progress.  */
  dlna_progress progress;

  /* Flags.  */
  slim_word flags;
#define DMC_FLAG_AUTOIP (1 << 0)
};

/*!
TDMCNewParam is a structure for setting the parameters of the DMC library.

\code
	struct _TDMCNewParam
	{
		dlna_progress progress; // DLNA progress 
		slim_word flags; // Flags
	};
	typedef struct _TDMCNewParam TDMCNewParam;
\endcode

\par Member:

<table>
	<tr>
		<td>progress</td>
		<td>
			DLNA progress manager descriptor <br />
			For information about the dlna_progress type, see the description of
			"Basic Data Types" in "NetFront Living Connect v2.0 Porting Guide", and how to get the DLNA progress, see "Progress Function" of the guide.
		</td>
	</tr>
	<tr>
		<td>flags</td>
		<td>Not used</td>
	</tr>
</table>
*/

typedef struct TDMCNewParam_ TDMCNewParam;

/*@}*/

/**
 * @addtogroup macros
 */
/*@{*/

/*!
TDMCObjectParam is a structure of parameters to be notified to the DMC application during the
callback.

\code
	struct _TDLNAObjectParam
	{
		slim_int err_code;
		
		// NumberReturned items 
		slim_word NumberReturned;
		
		// TotalMatches matches items 
		slim_word TotalMatches;
		
		// Array of items 
		TDLNAObject *ObjectArray;
		
		// String 1 
		slim_char *String1;
		
		// String 2 
		slim_char *String2;
	};
	typedef struct _TDLNAObjectParam TDLNAObjectParam;
	#define TDMCObjectParam TDLNAObjectParam
\endcode

\par Member:

<table>
	<tr>
		<td>err_code</td>
		<td>
			Parameter to be notified when an error occurs (0 for successful 	completion)
		</td>
	</tr>
	<tr>
		<td>NumberReturned</td>
		<td>
			Number of content items obtained by dlnaDmcObjectBrowse() or
			dlnaDmcObjectSearch()
		</td>
	</tr>
	<tr>
		<td>TotalMatches</td>
		<td>
			Total number of content items contained in the browsed container when
			obtained by dlnaDmcObjectBrowse(); total number of content items
			matching the search criteria when obtained by
			dlnaDmcObjectSearch()
		</td>
	</tr>
	<tr>
		<td>ObjectArray</td>
		<td>
			Array of DMC objects obtained by dlnaDmcObjectBrowse()or
			dlnaDmcObjectSearch()
		</td>
	</tr>
	<tr>
		<td>String 1</td>
		<td>
			String used for notification when error occurs, etc.
		</td>
	</tr>
	<tr>
		<td>String 2</td>
		<td>
			String used for notification when error occurs, etc.
		</td>
	</tr>
</table>	
*/

#define TDMCObjectParam TDLNAObjectParam
#define TDMCUpEventHandlerParam TDLNAUpEventHandleParam

/* TODO: add document */
#define TDMCObjectPresetParam TDLNAObjectPresetParam

/*!
TDMCObjectVolumeControlEHParam is a structure for setting the volume.

\code
	struct _TDLNAObjectVolumeControlEHParam
	{
		slim_int err_code;
		slim_char* err_description;
		
		slim_bool mute_state;
		slim_word volume;
		slim_int volume_db;
		slim_int min_volume_db;
		slim_int max_volume_db;
	};
	typedef struct _TDLNAObjectVolumeControlEHParam TDLNAObjectVolumeControlEHParam;
	#define TDMCObjectVolumeControlEHParam TDLNAObjectVolumeControlEHParam
\endcode

\par Member:

<table>
	<tr>
		<td>err_code</td>
		<td>
			Parameter to be notified when an error occurs (0 for successful completion) <br />
			For more information about error codes, see "2.4.29. GetVolume" of "UPnP AV RenderingControl:1 Service Template".
		</td>
	</tr>
	<tr>
		<td>err_description</td>
		<td>Error detail</td>
	</tr>
	<tr>
		<td>mute_state</td>
		<td>Muted (slim_true)/Not muted (slim_false)</td>
	</tr>
	<tr>
		<td>volume</td>
		<td>Volume</td>
	</tr>
	<tr>
		<td>volume_db</td>
		<td>Volume (dB)</td>
	</tr>
	<tr>
		<td>min_volume_db</td>
		<td>Minimum volume (dB)</td>
	</tr>
	<tr>
		<td>max_volume_db</td>
		<td>Maximum volume (dB)</td>
	</tr>
</table>
*/

#define TDMCObjectVolumeControlEHParam TDLNAObjectVolumeControlEHParam

/*!
TDMCResPropInfoParam is a structure for setting resource properties.

\code

	struct _TDLNAResPropInfoParam
	{
		// Attributes of <res> element. 
		slim_ulong size; // unit: bytes 
		slim_word duration; // unit: second 
		slim_word bitrate; // unit: bits/second 
		slim_word sampleFrequency; // unit: HZ 
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
	#define TDMCResPropInfoParam TDLNAResPropInfoParam

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
		<td>Resources URI</td>
	</tr>
</table>
*/

#define TDMCResPropInfoParam TDLNAResPropInfoParam

/*!
TDMCObjectJumpParam is a structure for setting the seek function. This structure is used to control
seek operations for content to be played on the DMR on the same network when the DMR is selected
as a playback device. How each mode is supported depends on the player function provided by the
DMR. Individual setting values follow the definitions described in "2.2.28. A_ARG_TYPE_SeekMode"
and "2.2.29. A_ARG_TYPE_SeekTarget" of "UPnP AV Transport:1 Service Template Version 1.01".

\code
	
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
	#define TDMCObjectJumpParam TDLNAObjectJumpParam

\endcode

\par Member:

<table>
	<tr>
		<td>jump_mode</td>
		<td>
			Seek mode (see "Error! Reference source not found.3.2.2 Error!
			Reference source not found.TDMCJumpMode")
		</td>
	</tr>
	<tr>
		<td>u</td>
		<td>Setting value corresponding to seek mode</td>
	</tr>
</table>
*/

#define TDMCObjectJumpParam  TDLNAObjectJumpParam

/*!
TDMCObjectPositionParam is a structure for obtaining position information.

\code
	struct _TDLNAObjectPositionParam
	{
		slim_word track;
		slim_char *track_uri;
		dlna_duration *track_duration;
		dlna_duration *rel_time;
		dlna_duration *abs_time;
		slim_int rel_count;
		slim_int abs_count;
		slim_char *track_metadata;
	};
	typedef struct _TDLNAObjectPositionParam TDLNAObjectPositionParam;
	#define TDMCObjectPositionParam TDLNAObjectPositionParam
\endcode

\par Member:

<table>
	<tr>
		<td>track</td>
		<td>Track number</td>
	</tr>
	<tr>
		<td>track_uri</td>
		<td>URI location of track</td>
	</tr>
	<tr>
		<td>track_duration</td>
		<td>Duration of track</td>
	</tr>
	<tr>
		<td>rel_time</td>
		<td>Elapsed time from top of current track</td>
	</tr>
	<tr>
		<td>abs_time</td>
		<td>Elapsed time from top of media</td>
	</tr>
	<tr>
		<td>rel_count</td>
		<td>Counter from top of current track</td>
	</tr>
	<tr>
		<td>abs_count</td>
		<td>Counter from top of media</td>
	</tr>
</table>

\par SEE ALSO:
For information about the dlna_duration structure, see the description of "Structure" in "NetFront
Living Connect v2.0 Porting Guide".
*/

#define TDMCObjectPositionParam  TDLNAObjectPositionParam

/*!
TDMCObjectMediaInfoParam is a structure for obtaining media information.

\code
	struct _TDLNAObjectMediaInfoParam
	{
		slim_word track_num;
		dlna_duration *media_duration;
		slim_char *uri;
		void *uri_metadata;
		slim_char *next_uri;
		void *next_uri_metadata;
		slim_char *storage_medium;
		slim_char *rec_storageMedium;
		slim_char *rec_status;
	};
	typedef struct _TDLNAObjectMediaInfoParam TDLNAObjectMediaInfoParam;
	#define TDMCObjectMediaInfoParam TDLNAObjectMediaInfoParam
\endcode

\par Member:

<table>
	<tr>
		<td>track_num</td>
		<td>Number of tracks</td>
	</tr>
	<tr>
		<td>media_duration</td>
		<td>Duration of media</td>
	</tr>
	<tr>
		<td>uri</td>
		<td>URI location of media</td>
	</tr>
	<tr>
		<td>uri_metadata</td>
		<td>Metadata of media</td>
	</tr>
	<tr>
		<td>next_uri</td>
		<td>
			URI location of next media that will be played back after this media
		</td>
	</tr>
	<tr>
		<td>next_uri_metadata</td>
		<td>
			Metadata of next media
		</td>
	</tr>
	<tr>
		<td>storage_medium</td>
		<td>
			Storage medium for playing specified resource on DMR
		</td>
	</tr>
	<tr>
		<td>rec_storageMedium</td>
		<td>
			Storage medium for recording specified resource on DMR
		</td>
	</tr>
	<tr>
		<td>rec_status</td>
		<td>
			Write protection status of current media on DMR
		</td>
	</tr>
</table>
*/

#define TDMCObjectMediaInfoParam  TDLNAObjectMediaInfoParam

/*!
TDMCGenaNotifyEHParam is a structure for properties to be notified to DMC application with gena
events.

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
	#define TDMCGenaNotifyEHParam TDLNAGenaNotifyEHParam
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

#define TDMCGenaNotifyEHParam TDLNAGenaNotifyEHParam


/*!
TDMCObjectNSLookupParam is a structure for properties to be notified to DMC application with gena
events.

\code
    struct _TDLNAObjectNSLookupParam {
        slim_int   soap_error_code;
        slim_char* err_description;

        slim_char* testId;
    };
    typedef struct _TDLNAObjectNSLookupParam TDLNAObjectNSLookupParam;
	#define TDMCObjectNSLookupParam TDLNAObjectNSLookupParam
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
#define TDMCObjectNSLookupParam TDLNAObjectNSLookupParam


/*!
TDMCObjectGetNSLookupResultParam is a structure for properties to be notified to DMC application with gena
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
    #define TDMCObjectGetNSLookupResultParam TDLNAObjectGetNSLookupResultParam

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
#define TDMCObjectGetNSLookupResultParam TDLNAObjectGetNSLookupResultParam


/*!
TDMCObjectGetDeviceStatus is a structure for properties to be notified to DMC application with gena events.

\code
  struct _TDLNAObjectGetDeviceStatus
  {
    slim_int   soap_error_code;
    slim_char* err_description;

    slim_char *device_status;
  };
  typedef struct _TDLNAObjectGetDeviceStatus TDLNAObjectGetDeviceStatus;
#define TDMCObjectGetDeviceStatus TDLNAObjectGetDeviceStatus
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
#define TDMCObjectGetDeviceStatus TDLNAObjectGetDeviceStatus


/*!
TDMCObjectGetInterfaceInfoParam is a structure for properties to be notified to DMC application with gena
events.

\code
    struct _TDLNAObjectGetInterfaceInfoParam {
        slim_int   soap_error_code;
        slim_char* err_description;

        slim_char* networkInterfaceInfo;
		slim_char* proxiedNetworkInterfaceInfo;
    };
    typedef struct _TDLNAObjectGetInterfaceInfoParam TDLNAObjectGetInterfaceInfoParam;
	#define TDMCObjectGetInterfaceInfoParam TDLNAObjectGetInterfaceInfoParam
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
#define TDMCObjectGetInterfaceInfoParam TDLNAObjectGetInterfaceInfoParam

/*!
TDMCObjectServiceSubscriptionParam is a structure for properties to be notified to DMC application with gena
events.

\code
    struct _TDLNAObjectServiceSubscriptionParam {
        slim_int   soap_error_code;
        slim_char* err_description;

        slim_char* serviceSubscriptionID;
		slim_char* duration;
    };
    typedef struct _TDLNAObjectServiceSubscriptionParam TDLNAObjectServiceSubscriptionParam;
	#define TDMCObjectServiceSubscriptionParam TDLNAObjectServiceSubscriptionParam
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
#define TDMCObjectServiceSubscriptionParam TDLNAObjectServiceSubscriptionParam

/*!
TDMCObjectServiceRenewalParam is a structure for properties to be notified to DMC application with gena
events.

\code
    struct _TDLNAObjectServiceRenewalParam {
        slim_int   soap_error_code;
        slim_char* err_description;

		slim_char* duration;
    };
    typedef struct _TDLNAObjectServiceRenewalParam TDLNAObjectServiceRenewalParam;
	#define TDMCObjectServiceRenewalParam TDLNAObjectServiceRenewalParam
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
#define TDMCObjectServiceRenewalParam TDLNAObjectServiceRenewalParam

/*!
TDMCObjectServiceReleaseParam is a structure for properties to be notified to DMC application with gena
events.

\code
    struct _TDLNAObjectServiceReleaseParam {
        slim_int   soap_error_code;
        slim_char* err_description;
    };
    typedef struct _TDLNAObjectServiceReleaseParam TDLNAObjectServiceRenewalParam;
	#define TDMCObjectServiceReleaseParam TDLNAObjectServiceRenewalParam
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
#define TDMCObjectServiceReleaseParam TDLNAObjectServiceRenewalParam

enum protocolInfoType_ {
  PROTOCOL_INFO_TYPE_SINK = 0,
  PROTOCOL_INFO_TYPE_SOURCE
};

typedef enum protocolInfoType_ protocolInfoType_t;

/*@}*/

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
Generates DMC instance.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>in_param</td>
		<td>Initial parameter of DMC library</td>
	</tr>
</table>

\return != slim_nil Succeeded (DMC instance)
\return == slim_nil Initialization failed
\par Description:
This function generates a DMC instance and initializes the DMC library.

dlnaDmcDelete() is used to delete the instance generated by this function.

This function does not allow multiple DMC instances to be generated.

This function must be called first among all the DMC APIs.
*/
DLNA_API TDMC
dlnaDmcNew(TDMCNewParam *in_param, slim_char* in_config_dir);

/*!
\par Function:
Deletes DMC instance.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMC instance</td>
	</tr>
</table>

\return None
\par Description:
This function deletes a DMC instance.

When the DMC library is started (after successful dlnaDmcOpen()), dlnaDmcClose() must be called to stop the DMC library before calling this function.

If the DMC library has been started by dlnaProgressAllocPeer() and ProgressStartPeer(), stop the DLNA progress first using dlnaProgressStopPeer(), stop and delete the DMC library using dlnaDmcClose() and dlnaDmcDelete(), and then delete the DLNA progress using dlnaProgressFreePeer().
*/
DLNA_API void
dlnaDmcDelete(TDMC self);

/*!
\par Function:
Starts DMC library.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMC instance</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_dmc_eh</td>
		<td>Callback function that notifies of internally generated event</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument of in_dmc_eh</td>
	</tr>
</table>

\return DMC_E_OK Succeeded
\return Other Failed
\par Description:
This function prepares the communication protocols (SSDP, GENA, SOAP) used by a DMC. Then, it registers an event to send an SSDP packet to seek available DMS or DMR on the network.

Calling dlnaProgressStartPeer() after this function call starts operation of the DMC library (see the description of dlnaProgressStartPeer() in "NetFront Living Connect v2.0 Porting Guide").

The DLNA progress that dlnaProgressStartPeer() uses is generated by
dlnaProgressAllocPeer().

For in_dmc_eh, the pointer to the callback function that notifies of internally generated events is specified. Null cannot be specified for it.
*/
DLNA_API slim_int
dlnaDmcOpen(TDMC self, TDMCEventHandler in_dmc_eh, void *in_arg);

/*!
\par Function:
Stops DMC library.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMC instance</td>
	</tr>
</table>

\return None
\par Description:
This function stops the communication protocols (SSDP, GENA, SOAP) used by a DMC.
*/
DLNA_API void
dlnaDmcClose(TDMC self);

/*!
\par Function:
Gets number of detected devices.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMC instance</td>
	</tr>
</table>

\return Number of detected devices (>=0)
\par Description:
This function returns the number of detected devices.

When notification of TDMCEvent is given by DMC_EV_FOUND_DEVS, it is recommended to call this function within TDMCEventHandler() to get the total number of devices.
*/

DLNA_API void
dlnaDmcDiscoverDeviceStartTimer(TDMC self, slim_int in_timeout);

DLNA_API void
dlnaDmcDiscoverDeviceStopTimer(TDMC self);

DLNA_API slim_int
dlnaDmcDeviceCount(TDMC self);

/*!
\par Function:
Gets detected device information.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMC instance</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_devs[]</td>
		<td>Buffer for detected device information (NULL terminated)</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_beg</td>
		<td>Start position for getting device information (from 0).</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_num</td>
		<td>Number of devices for which to get device information</td>
	</tr>
</table>
 
\return DMC_E_OK Succeeded
\return DMC_E_NOMEM Insufficient memory
\par Description:
This function returns detected device information.

It sets in_num number of pointers to detected device information for out_devs[], starting from the position in_beg.

out_devs[] must be prepared with a size of in_num+1 or more. It is necessary to initialize out_devs[] with null.

If the number of devices that can be obtained is less than in_num, then the number of devices that can be obtained is specified.

When notification of TDMCEvent is given by DMC_EV_FOUND_DEVS, it is recommended to call this function within TDMCEventHandler() to get the device information.
*/
DLNA_API slim_int
dlnaDmcDeviceList(TDMC self, TDMCObject out_devs[], slim_int in_beg,
                  slim_int in_num);

/*!
\par Function:
Function searchs for device by UDN.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA DMC object.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_udn</td>
		<td>UDN to find.</td>
	</tr>
</table>
\return TDMCObject device specyfied by UDN
\par Return Values:
<table>
	<tr>
		<td> \b != slim_nil</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>slim_nil</td>
		<td>Fail</td>
	</tr>
</table>
*/
DLNA_API TDMCObject
dlnaDmcDeviceLookupByUDN(TDMC self, slim_char *in_udn);

/*!
\par Function:
Updates device information.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMC instance</td>
	</tr>
</table>

\return DMC_E_OK Succeeded
\return DMC_E_GENERIC Failed
\return DMC_E_NOMEM Insufficient memory
\par Description:
This function updates the device information with the latest information. The result is notified by TDMCEventHandler().

Updating of device information is performed regularly by the DMC library. It is not necessary to call this function for getting device information. Call this function only to force the updating of device information.
*/
DLNA_API slim_int
dlnaDmcDeviceSearch(TDMC self);

/*!
\par Function:
Determines whether DMS supports specified search capability.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to DMS device information obtained by dlnaDmcDeviceList()</td>
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

\return DMC_E_OK Succeeded
\return DMC_E_INVAL Failed
\par Description:
This function determines whether the DMS supports the search capability specified for in_search_caps (see).
*/
DLNA_API slim_int
dlnaDmcDeviceIsSupportSearchCapability(TDMCObject self,slim_char * in_search_caps, slim_bool* out_is_support);

/*!
\par Function:
Get CSV list of search capabilities.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to DMS device information obtained by dlnaDmcDeviceList()</td>
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
 
\return DMC_E_OK Succeeded
\return DMC_E_INVAL Invalid argument
\return DMC_E_GENERIC Other error
\par Description:
This function returns CSV list of search capabilities.

DMC application should check out_caps_buf to determine what search capabilities are supported by DMS specified for self.

The memory buffer of out_caps_buf and inout_caps_buf_size must be allocated in DMC application.

out_caps_buf is NULL terminated.

The DMC application gets the CSV list for search capability by the following procedure.

-# Calls this function specifying slim_nil for out_caps_buf, and gets the required string buffer size for out_caps_buf from inout_caps_buf_size.
-# Allocates memory area for CSV list for search capability, according to the required string buffer size for out_caps_buf obtained in step 1.
-# Calls this function again, specifying a pointer to the memory area allocated in step 2 for out_caps_buf, specifying the buffer size for inout_caps_buf_siz, and gets the CSV list for search capability.

For more information about search capability, see "2.5.18. SearchCapabilities", "2.7.1. GetSearchCapabilities" and " 2.8.4.1. Retrieving search capabilities" in "UPnP AV ContentDirectory:1 Service Template Version 1.01".
*/
DLNA_API slim_int
dlnaDmcDeviceGetSupportSearchCapability(TDMCObject self, slim_char *out_caps_buf, slim_int *inout_caps_buf_size);

/*!
\par Function:
Determines whether DMS supports specified sort criteria.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to DMS device information obtained by dlnaDmcDeviceList()</td>
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
			Result of search capability determination <br />
			slim_true Supported <br />
			slim_false Not supported
		</td>
	</tr>
</table>
 
\return DMC_E_OK Succeeded
\return DMC_E_INVAL Failed
\par Description:
This function determines whether the DMS supports the sort criteria specified for in_sort_crt (see).
*/
DLNA_API slim_int
dlnaDmcDeviceIsSupportSortCriteria(TDMCObject self, slim_char* in_sort_crt, slim_bool* out_is_support);

/*!
\par Function:
Get CSV list of sort criteria.
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>Pointer to DMS device information obtained by dlnaDmcDeviceList()</td>
        </tr>
        <tr>
                <td>[out]</td>
                <td>out_crt_buf</td>
                <td>Pointer to CSV list for sort criterion (NULL terminated)</td>
        </tr>
        <tr>
                <td>[inout]</td>
                <td>inout_crt_buf_size</td>
                <td>Buffer size of out_crt_buf</td>
        </tr>
</table>

\return DMC_E_OK Succeeded
\return DMC_E_INVAL Invalid argument
\return DMC_E_GENERIC Other error
\par Description:
This function returns CSV list of sort criteria.

DMC application should check out_crt_buf to determine what sort criteria are supported by DMS specified for self.

The memory buffer of out_crt_buf and inout_crt_buf_size must be allocated in DMC application.

out_crt_buf is NULL terminated.

The DMC application gets the CSV list for sort criteria by the following procedure.

-# Calls this function specifying slim_nil for out_crt_buf, and gets the required string buffer size for out_crt_buf from inout_crt_buf_size.
-# Allocates memory area for CSV list for sort criteria, according to the required string buffer size for out_crt_buf obtained in step 1.
-# Calls this function again, specifying a pointer to the memory area allocated in step 2 for out_crt_buf, specifying the buffer size for inout_crt_buf_size, and gets the CSV list for sort criteria.
*/
DLNA_API slim_int
dlnaDmcDeviceGetSupportSortCriteria(TDMCObject self, slim_char *out_sort_crt, slim_int *in_out_sort_crt_size);

/*!
\par Function:
Gets service description.
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>Pointer to DMS device information</td>
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
                <td>in_service_type</td>
                <td>Service type to find</td>
        </tr>
</table>

\return DMC_E_OK Succeeded
\return DMC_E_GENERIC Failed
\return DMC_E_NOMEM Insufficient memory
\par Description:
This function returns the service description. The result is notified by TDMCEventHandler().

*/
DLNA_API slim_int
dlnaDmcDeviceGetServiceDescription(TDMCObject self, TDLNAObjectEventHandler in_obj_eh, void *in_arg, slim_char *in_service_type);

/*!
\par Function:
Gets service description.
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>Pointer to DMS device information</td>
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
                <td>in_service_id</td>
                <td>Service id to find</td>
        </tr>
</table>

\return DMC_E_OK Succeeded
\return DMC_E_GENERIC Failed
\return DMC_E_NOMEM Insufficient memory
\par Description:
This function returns the service description. The result is notified by TDMCEventHandler().

*/
DLNA_API slim_int
dlnaDmcDeviceGetServiceDescriptionByID(TDMCObject self, TDLNAObjectEventHandler in_obj_eh, void *in_arg, slim_char *in_service_id);

/*!
\par Function:
Gets DLNA device type.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to device information obtained by dlnaDmcDeviceList()</td>
	</tr>
</table>

\return DLNA device type
\par Description:
This function returns the device type of the specified device.

When notification of TDMCEvent is given by DMC_EV_FOUND_DEVS, it is recommended to call this function within TDMCEventHandler() to get the device type.
*/
DLNA_API TDMCDeviceType
dlnaDmcDeviceType(TDMCObject self);

/*!
\par Function:
Function return url witch starts with device base url.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA device object.</td>
	</tr>
</table>
\return string containing device base url
\par Return Values:
<table>
	<tr>
		<td> \b != slim_nil</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>slim_nil</td>
		<td>Fail</td>
	</tr>
</table>
*/
DLNA_API slim_char*
dlnaDmcDeviceBaseURL(TDMCObject self);

/*!
\par Function:
Function return device IP address.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA device object.</td>
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
\return string containing device ip
\par Return Values:
<table>
	<tr>
		<td> \b != slim_nil</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>slim_nil</td>
		<td>Fail</td>
	</tr>
</table>
*/
DLNA_API slim_int
dlnaDmcDeviceIP(TDMCObject self, slim_char *out_ip, slim_int in_len);

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
\return string containing device mac address
\par Return Values:
<table>
	<tr>
		<td> \b != slim_nil</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>slim_nil</td>
		<td>Fail</td>
	</tr>
</table>
*/
DLNA_API slim_int
dlnaDmcDeviceMACAddress(TDMCObject self, slim_char *out_mac, slim_int in_len);

/*!
\par Function:
Gets device icon relative path.
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

\return pointer to specified icon relative path if Succeeded
\return slim_nil if it cannot find specified icon for item or self is a slim_nil or if self is not a device type object
\par Description:
This function returns device icon relative path on device.
*/
DLNA_API slim_char*
dlnaDmcObjectPropIconURL(TDMCObject self, dlna_device_icon_type in_icon_device_type);

/*!
\par Function:
Cancels API request for DMS or DMR on the network.
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
Not currently supported. Behavior of this function is not guaranteed. Schedule has not been determined.

This function cancels the API request for a DMS or DMR on the network.

The following are the APIs that can be canceled by this function:

- dlnaDmcObjectBrowse()
- dlnaDmcObjectSearch()
- dlnaDmcPlayOpen()
- dlnaDmcPlayPlay()
- dlnaDmcPlayPause()
- dlnaDmcPlayJump()
- dlnaDmcPlayStop()
- dlnaDmcPlayFastForward()
- dlnaDmcPlayRewind()
- dlnaDmcPlayGetState()
- dlnaDmcPlayGetPosition()
- dlnaDmcPlayerGetVolume()
- dlnaDmcPlayerSetVolume()
- dlnaDmcPlayerGetMuteState()
- dlnaDmcPlayerSetMuteState()
- dlnaDmcPlayerGetVolumeDB()
- dlnaDmcPlayerSetVolumeDB()
- dlnaDmcPlayerGetVolumeDBRange()

Specify a pointer to the device, container, or item information specified for the API to be canceled, for self.

When cancellation is successful using this function, then event notification of the request for each API is not performed. However, event notification may be performed, if execution of this function conflicts with the timing of the callback function call.

Cancellations after transmitting requests on the network are invalid.
*/

/*!
\par Function:
Determines whether DMC object is dtcp protected content.
\par Parameters:
     
<table>
  <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to item information specified for API</td>
  </tr>
</table>
 
\return
 <table>
 <tr>
 <td>slim_true</td>
 <td>DTCP protected content</td>
 </tr>
 <tr>
 <td>slim_false</td>
 <td>Not DTCP protected content</td>
 </tr>
 </table>
\par Description:
*/
DLNA_API slim_bool
dlnaDmcObjectIsDtcp (TDMCObject self);
    
    
DLNA_API void
dlnaDmcObjectCancel(TDMCObject self);

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

\return DMC_E_OK Succeeded
\return Other Failed
\par Description:
This function deletes the device, container, or item information that is specified for self.

API processing using self will be canceled.

The following are the trigger events for using this function from a DMC application:

<b>(1) When TDMCEventHandler is notified of an event </b>

<table>
	<tr>
		<td><b>Event name</b></td>
		<td><b>Description</b></td>
	</tr>
	<tr>
		<td>DMC_EV_BYEBYE</td>
		<td>
			This event notification is sent when a device (DMS/DMR) on the network 
			stops, so the device information allocated by the DMC is deleted
		</td>
	</tr>
	<tr>
		<td>DMC_EV_UNAVAILABLE</td>
		<td>
			This event notification is sent when a device (DMS/DMR)
			on the network gets disabled, so the device information
			allocated by the DMC is deleted
		</td>
	</tr>
</table>

<b> (2) When TDMCObjectEventHandler is notified of an event </b>

<table>
	<tr>
		<td><b>Event name</b></td>
		<td><b>Description</b></td>
	</tr>
	<tr>
		<td>DMC_OBJECT_EV_PLAY_OPEN_FAILED</td>
		<td>
			This event notification is sent when an error occurs in dlnaDmcPlayOpen(), 
			so the information for the first argument of which TDMCObjectEventHandler() is
			notified is deleted.
		</td>
	</tr>
	<tr>
		<td>DMC_OBJECT_EV_PLAY_CLOSED</td>
		<td>
			Notification of this event is sent when content playback is completed. <br />
			When this notification is received, the information for the first argument of which TDMCObjectEventHandler() is notified is deleted
		</td>
	</tr>
	<tr>
		<td>DMC_OBJECT_EV_PLAY_ERROR</td>
		<td>	
			This event notification is sent when an error occurs during playback, so the  information 
			for the first argument of which TDMCObjectEventHandler() is notified is deleted
		</td>
	</tr>
</table>

<b> (3) When deleting obtained device, container, or item information </b> <br />
The device, container, or item information obtained by dlnaDmcDeviceList(),
dlnaDmcObjectBrowse(), or dlnaDmcObjectSearch() is not deleted before executing this
function.

The DMC application must delete the device/container/item information using this function when the information is no longer needed.
*/
DLNA_API slim_int
dlnaDmcObjectClose(TDMCObject self);

/*@}*/

/**
 * @addtogroup macros
 */
/*@{*/

#define DMC_SORT_CRITERIA_TITLE                                               \
  "+dc:title"

#define DMC_SORT_CRITERIA_ARTIST                                              \
  "+upnp:artist"

#define DMC_SORT_CRITERIA_DATE                                                \
  "-dc:date"

#define DMC_SORT_CRITERIA_TITLE_ARTIST                                        \
  DMC_SORT_CRITERIA_TITLE "," DMC_SORT_CRITERIA_ARTIST

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
			Pointer to DMS device information (obtained by dlnaDmcDeviceList()),
			or pointer to container information (obtained by this function or dlnaDmcObjectSearch())
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

\return DMC_E_OK Succeeded (Browse started)
\return Other Failed
\par Description:
This function returns DMC_E_OK when a request to get content information for a DMS is successfully accepted.

No other APIs should be called from the time this function is called until the return of the processing result by in_obj_eh. Behavior is not guaranteed if other APIs are called.

If a pointer to the DMS device information is specified for self, the callback function sends notification of the container information of the top directory published by the DMS.

If a pointer to the container information obtained from the DMS is specified for self, the callback function sends notification of the containers on the next tier below the specified container and of the items within it.

The pointer to the callback function must be specified for in_obj_eh. The result of the request to get the content information is notified asynchronously by in_obj_eh.

Specify 0 for in_beg when getting content information from the beginning; or specify the start position in the content information when getting it from any other desired position.

Specify the total number of content information items to request for in_num. If -1 is specified for in_num, the information of 30 content items will be requested by default (the default number of requests can be set at compile time).

To get sorted content information, a sort criteria needs to be specified for in_sort_crt (see). Specify slim_nil for in_sort_crt when sorting content information is unnecessary.

When getting content information succeeds, the DMC_OBJECT_EV_BROWSE_END event is notified by in_obj_eh, and values are set for the following members in the TDMCObjectParam type. The other members must not be referenced.

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
			Array of pointers to content information obtained
			(number of array elements is equal to the value of NumberReturned)
		</td>
	</tr>
</table>

When getting content information fails, the DMC_OBJECT_EV_BROWSE_ERROR event is notified, and an error code is set for the err_code member in the TDMCObjectParam type.

For more information about error codes, see "2.7.4. Browse" in "UPnP AV ContentDirectory:1 Service
Template Version 1.01".
*/
DLNA_API slim_int
dlnaDmcObjectBrowse (TDMCObject self, TDMCObjectEventHandler in_obj_eh,
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
			Pointer to DMS device information (obtained by dlnaDmcDeviceList()),
			or pointer to container information (obtained by this function or dlnaDmcObjectSearch())
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

\return DMC_E_OK Succeeded (Browse started)
\return Other Failed
\par Description:
This function returns DMC_E_OK when a request to get content information for a DMS is successfully accepted.

No other APIs should be called from the time this function is called until the return of the processing result by in_obj_eh. Behavior is not guaranteed if other APIs are called.

If a pointer to the DMS device information is specified for self, the callback function sends notification of the container information of the top directory published by the DMS.

If a pointer to the container information obtained from the DMS is specified for self, the callback function sends notification of the containers on the next tier below the specified container and of the items within it.

The pointer to the callback function must be specified for in_obj_eh. The result of the request to get the content information is notified asynchronously by in_obj_eh.

When getting content information succeeds, the DMC_OBJECT_EV_BROWSE_END event is notified by in_obj_eh, and values are set for the following members in the TDMCObjectParam type. The other members must not be referenced.

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
			(It is NOT an array as in dlnaDmcObjectBrowse, because there is always one element  by dlnaDmcObjectBrowseMetadata)
		</td>
	</tr>
</table>

When getting content information fails, the DMC_OBJECT_EV_BROWSE_ERROR event is notified, and an error code is set for the err_code member in the TDMCObjectParam type.

For more information about error codes, see "2.7.4. Browse" in "UPnP AV ContentDirectory:1 Service
Template Version 1.01".
*/
DLNA_API slim_int
dlnaDmcObjectBrowseMetadata (TDMCObject self, TDMCObjectEventHandler in_obj_eh,
                     void *in_arg, slim_char *in_filter, TDMCObject *out_obj);

/*@}*/

/**
 * @addtogroup macros
 */
/*@{*/

#define DMC_SEARCH_CAPS_UPNP_CLASS      ("upnp:class")
#define DMC_SEARCH_CAPS_UPNP_ALBUM      ("upnp:album")
#define DMC_SEARCH_CAPS_DC_TITLE        ("dc:title")
#define DMC_SEARCH_CAPS_DC_CREATOR      ("dc:creator")
#define DMC_SEARCH_CAPS_DEFAULT_ID      ("@id")
#define DMC_SEARCH_CAPS_DEFAULT_REFID   ("@refID")
#define DMC_SEARCH_CAPS_RES_RES         ("res")
#define DMC_SEARCH_CAPS_RES_PINFO       ("res@protocolInfo")

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
		<td>Pointer to DMS device information obtained by dlnaDmcDeviceList()</td>
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
		<td>Starting number of content information to get</td>
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

\return DMC_E_OK Succeeded (Search started)
\return Other Failed
 
\par Description:
This function returns DMC_E_OK when a search request for the content information of a DMS is successfully accepted.

If this function is called for a DMS that does not support this function, the behavior is not guaranteed.
Whether a device supports this function needs to be checked by dlnaDmcDeviceIsSupportSearchCapability().

A pointer to the device information of DMS is specified for self. If a pointer to other information is specified, an error is returned.

A pointer to the callback function must be specified for in_obj_eh. The result of a content information search request is notified asynchronously by in_obj_eh.

Specify 0 for in_beg when getting content information from the beginning; or specify the start position in the content information when getting it from any other desired position.

Specify the total number of content information items to request for in_num. If -1 is specified for in_num, the information of 30 content items will be requested by default (the default number of requests can be set at compile time).

To get sorted content information, the sort criteria needs to be specified for in_sort_crt (see "Error! Reference source not found.3.2.5 Error! Reference source not found.TDMCSortCriteria").

The string defined in "UPnP AV ContentDirectory:1 Service Template Version 1.01" must be specified for in_criteria. in_criteria is same as search criteria in "UPnP AV ContentDirectory:1 Service Template Version 1.01".

For more information about search criteria, see "2.5.5. A_ARG_TYPE_SearchCriteria" in "UPnP AV ContentDirectory:1 Service Template Version 1.01".

The string defined in "UPnP AV ContentDirectory:1 Service Template Version 1.01" must be specified for in_filter. in_filter is same as filter in "UPnP AV ContentDirectory:1 Service Template Version 1.01".

For more information about filter, see "2.5.7. A_ARG_TYPE_Filter" in "UPnP AV ContentDirectory:1 Service Template Version 1.01".

When getting content information succeeds, the DMC_OBJECT_EV_SEARCH_END event is notified by in_obj_eh, and values are set for the following members of the TDMCObjectParam type. Other members must not be referenced.

- err_code Error code (0 for successful completion)
- NumberReturned Number of content items obtained
- TotalMatches Total number of content items matching search condition
- ObjectArray Array of pointers to content information obtained (number of array elements is equal to the value of NumberReturned)

When getting content information fails, the DMC_OBJECT_EV_SEARCH_ERROR event is notified, and an error code is set for the err_code member in the TDMCObjectParam type.

For more information about error codes, see "2.7.5. Search" in "UPnP AV ContentDirectory:1 Service
Template Version 1.01".

<b>Example about in_criteria:</b>

\code
"upnp:class = \"object.item.imageItem.photo\" and ( dc:date >= \"2001-10-
01\" and dc:date <= \"2001-10-31\")"
\endcode

<b>Example about in_filter:</b>

\code
"@id,@parentID,@restricted,dc:title,upnp:class"
\endcode
*/
DLNA_API slim_int
dlnaDmcObjectSearch (TDMCObject self, TDMCObjectEventHandler in_obj_eh,
         void *in_arg, slim_int in_beg, slim_int in_num,
         slim_char *in_criteria, slim_char *in_filter, slim_char *in_sort_crt);

/*!
\par Function:
Function allocates dmc player for thumbnail.
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
		<td>[out]</td>
		<td>out_play</td>
		<td>output dmc player</td>
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
DLNA_API slim_int
dlnaDmcObjectThumbnailOpen (TDMCObject self, TDMCObjectEventHandler in_obj_eh,
                            void *in_arg, TDMCObject in_dmr, TDMCObject *out_play);

/*!
\par Function:
Gets playlist.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMC instance</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_obj_array</td>
		<td>Address where obtained playlist is stored</td>
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

It copies the playlists to the specified structure address.

If the maximum playlist value specified for in_obj_num is larger than the number of playlists obtained from the player, the function copies all the playlists and returns the number of obtained as a return value.

If the maximum playlist value specified for in_obj_num is smaller than the number of playlists obtained from the player, the function copies up to the specified number of playlists and returns the number as a return value.
*/
DLNA_API slim_int
dlnaDmcGetPlaylist (TDMC self, TDMCObject * out_obj_array, slim_word in_obj_num);

/*!
\par Function:
Specifies DMR and prepares to play.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to information of item to play</td>
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
		<td>in_dmr</td>
		<td>Pointer to DMR device information obtained by dlnaDmcDeviceList()</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_res_index</td>
		<td>
			>=0 Specifies resource index <br />
			-1 Specifies first resource
		</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_play</td>
		<td>Pointer to play control information</td>
	</tr>
</table>
 
\return DMC_E_OK Succeeded
\return DMC_E_NOMEM Insufficient memory
\return DMC_E_GENERIC Generic error
\par Description:
This function specifies the DMR device for playback and prepares for playing an item.

After getting the number of resources and lists of resource properties using
dlnaDmcObjectPropResCount() and dlnaDmcObjectPropResList() respectively, this function specifies the index to an arbitrary resource for in_res_index.

When the call to this function succeeds, a pointer to the play control information is set for out_play.

The play control information needs to be deleted by dlnaDmcObjectClose() when play control terminates.

The result of this function processing is notified asynchronously.

When preparation for playing succeeds, the DMC_OBJECT_EV_PLAY_OPEN_OK event is notified by in_obj_eh.  No information is set for in_param of in_obj_eh.

When preparation for playing fails, the DMC_OBJECT_EV_PLAY_OPEN_FAILED event is notified by in_obj_eh. No information is set for in_param of in_obj_eh.

No other APIs should be called before the callback function returns the processing result of this function call. Behavior is not guaranteed if other APIs are called.
*/
DLNA_API slim_int
dlnaDmcPlayOpen (TDMCObject self, TDMCObjectEventHandler in_obj_eh,
    void *in_arg, TDMCObject in_dmr, slim_int in_res_index, TDMCObject *out_play);

/*!
\par Function:
Requests DMR to start playing.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to play control information</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_speed</td>
		<td>Not used (reserved for future extension)</td>
	</tr>
</table>

\return DMC_E_OK Succeeded
\return DMC_E_INVAL Invalid argument
\return DMC_E_NOMEM Insufficient memory
\return DMC_E_GENERIC Generic error
\par Description:
This function requests a DMR to start playing an item or to restart playing from the pause state. It is necessary for the processing of dlnaDmcPlayOpen() to be completed successfully (notification of DMC_OBJECT_EV_PLAY_OPEN_OK is completed) before calling this function.

The play control information obtained by dlnaDmcPlayOpen() is specified for self.

The result of this function processing is notified asynchronously.

When playback is started successfully, the DMC_OBJECT_EV_PLAY_PLAY_OK event is notified by in_obj_eh specified in dlnaDmcPlayOpen(). No information is set for in_param of in_obj_eh.

When playback fails to start, the DMC_OBJECT_EV_PLAY_PLAY_FAILED event is notified by in_obj_eh. No information is set for in_param of in_obj_eh.

No other APIs should be called before the callback function returns the processing result of this function call. Behavior is not guaranteed if other APIs are called.
*/
DLNA_API slim_int
dlnaDmcPlayPlay (TDMCObject self, slim_char *in_speed);

#ifdef DEVELOPMENT_CLOCK_SYNC
/*!
\par Function:
Requests DMR to start playing at desired time.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to play control information</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_speed</td>
		<td>Not used (reserved for future extension)</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>time</td>
		<td>Presentation time (e.g. "P12:00:00")</td>
	</tr>	
</table>

\return DMC_E_OK Succeeded
\return DMC_E_INVAL Invalid argument
\return DMC_E_NOMEM Insufficient memory
\return DMC_E_GENERIC Generic error
\par Description:
This function requests a DMR to start playing an item or to restart playing from the pause state at desired time. It is necessary for the processing of dlnaDmcPlayOpen() to be completed successfully (notification of DMC_OBJECT_EV_PLAY_OPEN_OK is completed) before calling this function.

The play control information obtained by dlnaDmcPlayOpen() is specified for self.

The result of this function processing is notified asynchronously.

When playback is started successfully, the DMC_OBJECT_EV_PLAY_PLAY_OK event is notified by in_obj_eh specified in dlnaDmcPlayOpen(). No information is set for in_param of in_obj_eh.

When playback fails to start, the DMC_OBJECT_EV_PLAY_PLAY_FAILED event is notified by in_obj_eh. No information is set for in_param of in_obj_eh.

No other APIs should be called before the callback function returns the processing result of this function call. Behavior is not guaranteed if other APIs are called.
*/
DLNA_API slim_int
dlnaDmcPlaySyncPlay (TDMCObject self, slim_char *in_speed, slim_char *time);
#endif /* DEVELOPMENT_CLOCK_SYNC */

/*!
\par Function:
Requests DMR to pause.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to play control information</td>
	</tr>
</table>

\return DMC_E_OK Succeeded
\return DMC_E_INVAL Invalid argument
\return DMC_E_NOMEM Insufficient memory
\return DMC_E_GENERIC Generic error
\par Description:
This function requests a DMR to pause an item that is playing. It is necessary for the processing of dlnaDmcPlayPlay() to be completed successfully (notification of DMC_OBJECT_EV_PLAY_PLAY_OK is completed) before calling this function.

The play control information obtained by dlnaDmcPlayOpen() is specified for self.

The result of this function processing is notified asynchronously.

When pause succeeds, the DMC_OBJECT_EV_PLAY_PAUSE_OK event is notified by in_obj_eh
specified in dlnaDmcPlayOpen(). No information is set for in_param of in_obj_eh.

When pause fails, the DMC_OBJECT_EV_PLAY_PAUSE_FAILED event is notified by in_obj_eh. No information is set for in_param of in_obj_eh.

No other APIs should be called before the callback function returns the processing result of this function call. Behavior is not guaranteed if other APIs are called.
*/
DLNA_API slim_int
dlnaDmcPlayPause (TDMCObject self);

#ifdef DEVELOPMENT_CLOCK_SYNC
/*!
\par Function:
Requests DMR to pause at desired time.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to play control information</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>time</td>
		<td>Presentation time (e.g. "P12:00:00")</td>
	</tr>	
</table>

\return DMC_E_OK Succeeded
\return DMC_E_INVAL Invalid argument
\return DMC_E_NOMEM Insufficient memory
\return DMC_E_GENERIC Generic error
\par Description:
This function requests a DMR to pause an item that is playing at desired time. It is necessary for the processing of dlnaDmcPlayPlay() to be completed successfully (notification of DMC_OBJECT_EV_PLAY_PLAY_OK is completed) before calling this function.

The play control information obtained by dlnaDmcPlayOpen() is specified for self.

The result of this function processing is notified asynchronously.

When pause succeeds, the DMC_OBJECT_EV_PLAY_PAUSE_OK event is notified by in_obj_eh
specified in dlnaDmcPlayOpen(). No information is set for in_param of in_obj_eh.

When pause fails, the DMC_OBJECT_EV_PLAY_PAUSE_FAILED event is notified by in_obj_eh. No information is set for in_param of in_obj_eh.

No other APIs should be called before the callback function returns the processing result of this function call. Behavior is not guaranteed if other APIs are called.
*/
DLNA_API slim_int
dlnaDmcPlaySyncPause (TDMCObject self, slim_char *time);
#endif /* DEVELOPMENT_CLOCK_SYNC */

/*!
\par Function:
Requests DMR to change playback position.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to play control information</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_jump</td>
		<td>
			Pointer to information for changing playback position 
			(see. "3.3.2, TDMCObjectJumpParamTDMCObjectJumpParam")
		</td>
	</tr>
</table>

\return DMC_E_OK Succeeded
\return DMC_E_INVAL Invalid argument
\return DMC_E_NOMEM Insufficient memory
\return DMC_E_GENERIC Generic error
\par Description:
This function requests a DMR to change to the playback position specified by in_jump. The processing of dlnaDmcPlayPlay() needs to be completed successfully (notification of
DMC_OBJECT_EV_PLAY_PLAY_OK is completed) before calling this function.

The play control information obtained by dlnaDmcPlayOpen() is specified for self.

The result of this function processing is notified asynchronously.

When the playback position is changed successfully, the DMC_OBJECT_EV_PLAY_JUMP_OK event is notified by in_obj_eh specified in dlnaDmcPlayOpen(). No information is set for in_param of in_obj_eh.

When changing the playback position fails, the DMC_OBJECT_EV_PLAY_JUMP_FAILED event is notified by in_obj_eh. No information is set for in_param of in_obj_eh.

No other APIs should be called before a callback function returns the processing result of this function call. Behavior is not guaranteed if other APIs are called.
*/
DLNA_API slim_int
dlnaDmcPlayJump (TDMCObject self, TDMCObjectJumpParam *in_jump);

/*!
\par Function:
Requests DMR to stop playback.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to play control information</td>
	</tr>
</table>

\return DMC_E_OK Succeeded
\return DMC_E_INVAL Invalid argument
\return DMC_E_NOMEM Insufficient memory
\return DMC_E_GENERIC Generic error
\par Description:
This function requests a DMR to stop playback. The processing of dlnaDmcPlayPlay() needs to be completed successfully (notification of DMC_OBJECT_EV_PLAY_PLAY_OK is completed) before calling this function.

The play control information obtained by dlnaDmcPlayOpen() is specified for self.

The result of this function processing is notified asynchronously.

When playback is stopped successfully, the DMC_OBJECT_EV_PLAY_STOP_OK event is notified by in_obj_eh specified in dlnaDmcPlayOpen(). No information is set for in_param of in_obj_eh.

The play control information will be deleted when DMC_PLAY_STATE_STOPPED is provided as DMC_OBJECT_EV_PLAY_STATE_CHANGED event notification. The information must not be deleted at the time the DMC_OBJECT_EV_PLAY_STOP_OK event notification is received. However, also DMC_PLAY_STATE_STOPPED is sent when dlnaDmcPlayOpen() succeeds, so this needs to be considered.

When playback fails to stop, the DMC_OBJECT_EV_PLAY_STOP_FAILED event is notified by in_obj_eh.No information is set for in_param of in_obj_eh.

No other APIs should be called before a callback function returns the processing result of this function call. Behavior is not guaranteed if other APIs are called.
*/
DLNA_API slim_int
dlnaDmcPlayStop (TDMCObject self);

#ifdef DEVELOPMENT_CLOCK_SYNC
/*!
\par Function:
Requests DMR to stop playback at desired time.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to play control information</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>time</td>
		<td>Desired stop time (e.g. "P12:00:00")</td>
	</tr>	
</table>

\return DMC_E_OK Succeeded
\return DMC_E_INVAL Invalid argument
\return DMC_E_NOMEM Insufficient memory
\return DMC_E_GENERIC Generic error
\par Description:
This function requests a DMR to stop playback at desired time. The processing of dlnaDmcPlaySyncPlay() needs to be completed successfully (notification of DMC_OBJECT_EV_PLAY_PLAY_OK is completed) before calling this function.

The play control information obtained by dlnaDmcPlayOpen() is specified for self.

The result of this function processing is notified asynchronously.

When playback is stopped successfully, the DMC_OBJECT_EV_PLAY_STOP_OK event is notified by in_obj_eh specified in dlnaDmcPlayOpen(). No information is set for in_param of in_obj_eh.

The play control information will be deleted when DMC_PLAY_STATE_STOPPED is provided as DMC_OBJECT_EV_PLAY_STATE_CHANGED event notification. The information must not be deleted at the time the DMC_OBJECT_EV_PLAY_STOP_OK event notification is received. However, also DMC_PLAY_STATE_STOPPED is sent when dlnaDmcPlayOpen() succeeds, so this needs to be considered.

When playback fails to stop, the DMC_OBJECT_EV_PLAY_STOP_FAILED event is notified by in_obj_eh.No information is set for in_param of in_obj_eh.

No other APIs should be called before a callback function returns the processing result of this function call. Behavior is not guaranteed if other APIs are called.
*/
DLNA_API slim_int
dlnaDmcPlaySyncStop (TDMCObject self, slim_char *time);
#endif /* DEVELOPMENT_CLOCK_SYNC */

/*!
\par Function:
Requests DMR to play next track in current media.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to play control information</td>
	</tr>
</table>

\return DMC_E_OK Succeeded
\return DMC_E_INVAL Invalid argument
\return DMC_E_NOMEM Insufficient memory
\return DMC_E_GENERIC Generic error
\par Description:
This function requests a DMR to play the next track in the current media.

The play control information obtained by dlnaDmcPlayOpen() is specified for self.

The result of this function processing is notified asynchronously.

When playback of the next track is started successfully, the  DMC_OBJECT_EV_PLAY_NEXT_OK event is notified by in_obj_eh specified in dlnaDmcPlayOpen(). No information is set for in_param of in_obj_eh.

When it fails, the DMC_OBJECT_EV_PLAY_NEXT_FAILED event is notified by in_obj_eh. No
information is set for in_param of in_obj_eh.

No other APIs should be called before the callback function returns the processing result of this function call. Behavior is not guaranteed if other APIs are called.
*/
DLNA_API slim_int
dlnaDmcPlayNext (TDMCObject self);

/*!
\par Function:
Requests DMR to play previous track in current media.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to play control information</td>
	</tr>
</table>

\return DMC_E_OK Succeeded
\return DMC_E_INVAL Invalid argument
\return DMC_E_NOMEM Insufficient memory
\return DMC_E_GENERIC Generic error

\par Description:
This function requests a DMR to play the previous track in the current media.

The play control information obtained by dlnaDmcPlayOpen() is specified for self.

The result of this function processing is notified asynchronously.

When playback of previous track is started successfully, the DMC_OBJECT_EV_PLAY_PREVIOUS_OK event is notified by in_obj_eh specified in dlnaDmcPlayOpen(). No information is set for in_param of in_obj_eh.

When it fails, the DMC_OBJECT_EV_PLAY_PREVIOUS_FAILED event is notified by in_obj_eh. No information is set for in_param of in_obj_eh.

No other APIs should be called before the callback function returns the processing result of this function call. Behavior is not guaranteed if other APIs are called.
*/
DLNA_API slim_int
dlnaDmcPlayPrevious (TDMCObject self);

/*!
\par Function:
Requests DMR to play in fast-forward mode.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to play control information</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_speed</td>
		<td>Fast forward playback speed</td>
	</tr>
</table>

\return DMC_E_OK Succeeded
\return DMC_E_INVAL Invalid argument
\return DMC_E_NOMEM Insufficient memory
\return DMC_E_GENERIC Generic error
\par Description:
This function requests a DMR to play in fast-forward mode. The processing of dlnaDmcPlayPlay()
needs to be completed successfully (notification of DMC_OBJECT_EV_PLAY_PLAY_OK is completed)
before calling this function.

The play control information obtained by dlnaDmcPlayOpen() is specified for self.

Multiplier value of fast forward speed relative to standard playback speed (1) is specified for in_speed.

The result of this function processing is notified asynchronously.

When fast-forwarding succeeds, the DMC_OBJECT_EV_PLAY_FF_OK event is notified by in_obj_eh
specified in dlnaDmcPlayOpen(). No information is set for in_param of in_obj_eh.

When fast-forwarding fails, the DMC_OBJECT_EV_PLAY_FF_FAILED event is notified by in_obj_eh. No
information is set for in_param of in_obj_eh.

No other APIs should be called before the callback function returns the processing result of this
function call. Behavior is not guaranteed if other APIs are called.
*/
DLNA_API slim_int
dlnaDmcPlayFastForward(TDMCObject self, slim_int in_speed);

/*!
\par Function:
Requests DMR to play in rewind mode.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to play control information</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_speed</td>
		<td>Fast rewind playback speed</td>
	</tr>
</table>

\return DMC_E_OK Succeeded
\return DMC_E_INVAL Invalid argument
\return DMC_E_NOMEM Insufficient memory
\return DMC_E_GENERIC Generic error
\par Description:
This function requests a DMR to play in rewind mode. The processing of dlnaDmcPlayPlay()
needs to be completed successfully (notification of DMC_OBJECT_EV_PLAY_PLAY_OK is completed)
before calling this function.

The play control information obtained by dlnaDmcPlayOpen() is specified for self.

Multiplier value of fast rewind speed relative to standard playback speed (1) is specified for in_speed.

The result of this function processing is notified asynchronously.

When rewinding succeeds, the DMC_OBJECT_EV_PLAY_FR_OK event is notified by in_obj_eh
specified in dlnaDmcPlayOpen(). No information is set for in_param of in_obj_eh.

When rewinding fails, the DMC_OBJECT_EV_PLAY_FR_FAILED event is notified by in_obj_eh. No
information is set for in_param of in_obj_eh.

No other APIs should be called before the callback function returns the processing result of this
function call. Behavior is not guaranteed if other APIs are called.
*/
DLNA_API slim_int
dlnaDmcPlayRewind(TDMCObject self, slim_int in_speed);

/*!
\par Function:
 Gets DMR available playspeeds list.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to play control information</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_playspeed</td>
		<td>Obtained list</td>
	</tr>
</table>

\return DMC_E_OK Succeeded
\return DMC_E_INVAL Invalid argument
\par Description:
This function returns the DMR available playspeeds list.

Playspeed list is retrieved from X_DLNA_PS which is stored when LastChange event contain X_DLNA_PS
*/
slim_int
dlnaDmcPlayGetDLNAPlaySpeed (TDMCObject self, slim_char** out_playspeed);

/*!
\par Function:
 Gets DMR play state managed by DMC library.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to play control information</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_state</td>
		<td>Obtained state</td>
	</tr>
</table>

\return DMC_E_OK Succeeded
\return DMC_E_INVAL Invalid argument
\par Description:
This function returns the DMR play state retained by the DMC library in out_state.

Requests to get state are not made for the DMR within this function. The DMC library retains the state
of which DMR has last notified. For this reason, the state may not be the same as the actual DMR play
state when called at certain times.
*/
DLNA_API slim_int
dlnaDmcPlayGetState (TDMCObject self, TDMCPlayState *out_stat);

/*!
\par Function:
Requests DMR to get playback position.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to play control information</td>
	</tr>
</table>

\return DMC_E_OK Succeeded
\return DMC_E_INVAL Invalid argument
\par Description:
This function requests a DMR to get the playback position. The processing of dlnaDmcPlayPlay()
needs to be completed successfully (notification of DMC_OBJECT_EV_PLAY_PLAY_OK is completed)
before calling this function.

The play control information obtained by dlnaDmcPlayOpen() is specified for self.

The result of this function processing is notified asynchronously.

When getting the playback position succeeds, the DMC_OBJECT_EV_PLAY_POSITION_INFO_OK
event is notified by in_obj_eh specified in dlnaDmcPlayOpen(). A pointer to
TDMCObjectPositionParam is set for in_param of in_obj_eh.

When getting the playback position fails, the DMC_OBJECT_EV_PLAY_POSITION_INFO_FAILED
event is notified by in_obj_eh. No information is set for in_param of in_obj_eh.

No other APIs should be called before the callback function returns the processing result of this
function call. Behavior is not guaranteed if other APIs are called.
*/
DLNA_API slim_int
dlnaDmcPlayGetPosition (TDMCObject self);

/*!
\par Function:
Requests DMR to get information of current media.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to play control information</td>
	</tr>
</table>

\return DMC_E_OK Succeeded
\return DMC_E_INVAL Invalid argument
\return DMC_E_NOMEM Insufficient memory
\return DMC_E_GENERIC Generic error
\par Description:
This function requests a DMR to get information from the current media. It returns DMC_E_OK, if the
request is accepted and in process, otherwise, it returns an error code.

The play control information obtained by dlnaDmcPlayOpen() is specified for self.

The result of this function processing is notified asynchronously.

When getting media information succeeds, the DMC_OBJECT_EV_PLAY_MEDIA_INFO_OK event is
notified by in_obj_eh specified in dlnaDmcPlayOpen(). A pointer to TDMCObjectMediaInfoParam
is set for in_param of in_obj_eh.

When getting media information fails, the DMC_OBJECT_EV_PLAY_MEDIA_INFO_FAILED event is
notified by in_obj_eh. No information is set for in_param of in_obj_eh.

No other APIs should be called before the callback function returns the processing result of this
function call. Behavior is not guaranteed if other APIs are called.
*/
DLNA_API slim_int
dlnaDmcPlayGetMediaInfo (TDMCObject self);

/* TODO: Add comment */
slim_int
dlnaDmcPlayerListPresets (TDMCObject self,
                          TDMCObjectEventHandler in_obj_eh, void *in_arg);

/* TODO: Add comment */
slim_int
dlnaDmcPlayerSelectPreset (TDMCObject self,
                           TDMCObjectEventHandler in_obj_eh, void *in_arg,
                           slim_char *in_preset);

/************************ VolumeControl ***************************/

/*!
\par Function:
Function gets player vlume.
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
		<td>in_channel</td>
		<td>channel wich volume we want to get</td>
	</tr>
</table>
\return slim_int with error code
\par Return Values:
<table>
	<tr>
		<td> \b DMC_E_OK</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>DMC_E_GENERIC</td>
		<td>Generic error</td>
	</tr>
	<tr>
		<td>DMC_E_NOMEM</td>
		<td>Out of memory error</td>
	</tr>
	<tr>
		<td>DMC_E_INVAL</td>
		<td>Invalid value</td>
	</tr>
</table>
*/
DLNA_API slim_int
dlnaDmcPlayerGetVolume(TDMCObject self, 
                      TDMCObjectEventHandler in_obj_eh, void *in_arg, slim_char *in_channel);

/*!
\par Function:
Function sets player vlume.
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
		<td>in_channel</td>
		<td>channel wich volume we want to set</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_volume</td>
		<td></td>
	</tr>
</table>
\return slim_int with error code
\par Return Values:
<table>
	<tr>
		<td> \b DMC_E_OK</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>DMC_E_GENERIC</td>
		<td>Generic error</td>
	</tr>
	<tr>
		<td>DMC_E_NOMEM</td>
		<td>Out of memory error</td>
	</tr>
	<tr>
		<td>DMC_E_INVAL</td>
		<td>Invalid value</td>
	</tr>
</table>
*/
DLNA_API slim_int
dlnaDmcPlayerSetVolume(TDMCObject self, TDMCObjectEventHandler in_obj_eh, 
                              void *in_arg, slim_char *in_channel, slim_int in_volume);

/*!
\par Function:
Gets current volume (dB) of specified DMR.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to DMR device information obtained by dlnaDmcDeviceList()</td>
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
		<td>in_channel</td>
		<td>Channel information of DMR for which to get volume value</td>
	</tr>
</table>

\return DMC_E_OK Succeeded
\return DMC_E_GENERIC DMR not found, or DMR does not support volume control
\return DMC_E_INVAL Invalid parameter
\par Description:
This function returns DMC_E_OK when a request to get the volume value (dB) for a DMR is
successfully accepted.

The pointer to the device information of DMR is specified for self. If a pointer to other information is
specified, an error is returned.

The pointer to the callback function must be specified for in_obj_eh. The result of the request to get the
volume value is notified asynchronously by in_obj_eh.

For information about value which can be specified for in_channel, see "2.2.19.
A_ARG_TYPE_Channel" in "UPnP AV RenderingControl:1 Service Template".

When getting the volume value succeeds, the DMC_OBJECT_EV_RENDERER_VOLDB_GET event is
notified by in_obj_eh, and values are set for the following members in the
TDMCObjectVolumeControlEHParam type. Other members must not be referenced.
- err_code Error code (0 for successful completion)
- volume_db Decibel volume value

When getting the volume value fails, the DMC_OBJECT_EV_RENDERER_VOLDB_GET event is notified,
and an error code is set for the err_code member in the TDMCObjectVolumeControlEHParam
type. The error detail is also set for the err_description member.

For more information about error codes, see "2.4.31. GetVolumeDB" in "UPnP AV RenderingControl:1
Service Template".
*/
DLNA_API slim_int
dlnaDmcPlayerGetVolumeDB(TDMCObject self,
                      TDMCObjectEventHandler in_obj_eh, void *in_arg, slim_char *in_channel);

/*!
\par Function:
Gets current volume value range (dB) of specified DMR.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to DMR device information obtained by dlnaDmcDeviceList()</td>
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
		<td>in_channel</td>
		<td>Channel information of DMR for which to get volume value range</td>
	</tr>
</table>

\return DMC_E_OK Succeeded
\return DMC_E_GENERIC DMR not found, or DMR does not support volume control
\return DMC_E_INVAL Invalid parameter
\par Description:
This function returns DMC_E_OK when a request to get the volume value (dB) range for a DMR is
successfully accepted.

The pointer to the device information of the DMR is specified for self. If a pointer to other information is
specified, an error is returned.

The pointer to the callback function must be specified for in_obj_eh. The result of the request to get the
volume value range is notified asynchronously by in_obj_eh.

For information about value which can be specified for in_channel, see "2.2.19.
A_ARG_TYPE_Channel" in "UPnP AV RenderingControl:1 Service Template".

When getting the volume value range succeeds, the
DMC_OBJECT_EV_RENDERER_VOLDB_RANGE_GET event is notified by in_obj_eh, and values are set
for the following members in the TDMCObjectVolumeControlEHParam type. Other members must
not be referenced.
- err_code Error code (0 for successful completion)
- min_volume_db Minimum volume value
- max_volume_db Maximum volume value

When getting the volume value range fails, the DMC_OBJECT_EV_RENDERER_VOLDB_RANGE_GET
event is notified, and an error code is set for the err_code member in the
TDMCObjectVolumeControlEHParam type. The error details are also set for the
err_description member.

For more information about error codes, see "2.4.33. GetVolumeDBRange" in "UPnP AV
RenderingControl:1 Service Template".
*/
DLNA_API slim_int
dlnaDmcPlayerGetVolumeDBRange(TDMCObject self,
                      TDMCObjectEventHandler in_obj_eh, void *in_arg, slim_char *in_channel);

/*!
\par Function:
Sets volume value (dB) of specified DMR.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to DMR device information obtained by dlnaDmcDeviceList()</td>
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
		<td>in_channel</td>
		<td>Channel information of DMR for which volume value is set</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_volume_db</td>
		<td>Volume value to set</td>
	</tr>
</table>

\return DMC_E_OK Succeeded
\return DMC_E_GENERIC DMR not found, or DMR does not support volume control
\return DMC_E_INVAL Invalid parameter
\par Description:
This function returns DMC_E_OK when a request to set the volume value (dB) for a DMR is
successfully accepted.

The pointer to the device information of the DMR is specified for self. If a pointer to other information is
specified, an error is returned.

The pointer to the callback function must be specified for in_obj_eh. The result of the request for the
volume value setting is notified asynchronously by in_obj_eh.

For information about value which can be specified for in_channel, see "2.2.19.
A_ARG_TYPE_Channel" in "UPnP AV RenderingControl:1 Service Template".

When the volume value is set successfully, the DMC_OBJECT_EV_RENDERER_VOLDB_SET event is
notified by in_obj_eh, and values are set for the following members in the
TDMCObjectVolumeControlEHParam type. Other members must not be referenced.
- err_code Error code (0 for successful completion)

When setting the volume value fails, the DMC_OBJECT_EV_RENDERER_VOLDB_SET event is notified,
and an error code is set for the err_code member in the TDMCObjectVolumeControlEHParam
type. The error detail is also set for the err_description member.

For more information about error codes, see "2.4.32. SetVolumeDB" in "UPnP AV RenderingControl:1
Service Template".
*/
DLNA_API slim_int
dlnaDmcPlayerSetVolumeDB(TDMCObject self, TDMCObjectEventHandler in_obj_eh,
                              void *in_arg, slim_char *in_channel, slim_int in_volume_db);

/*!
\par Function:
Function gets player mute state.
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
		<td>in_channel</td>
		<td>channel wich volume we want to get mute state</td>
	</tr>
</table>
\return slim_int with error code
\par Return Values:
<table>
	<tr>
		<td> \b DMC_E_OK</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>DMC_E_GENERIC</td>
		<td>Generic error</td>
	</tr>
	<tr>
		<td>DMC_E_NOMEM</td>
		<td>Out of memory error</td>
	</tr>
	<tr>
		<td>DMC_E_INVAL</td>
		<td>Invalid value</td>
	</tr>
</table>
*/
DLNA_API slim_int
dlnaDmcPlayerGetMuteState(TDMCObject self,
                              TDMCObjectEventHandler in_obj_eh, void *in_arg, slim_char *in_channel);

/*!
\par Function:
Sets mute state of specified DMR.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to DMR device information obtained by dlnaDmcDeviceList()</td>
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
		<td>in_channel</td>
		<td>Channel information of DMR for which mute state is set</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_mute</td>
		<td>Mute state to set</td>
	</tr>
</table>

\return DMC_E_OK Succeeded
\return DMC_E_GENERIC DMR not found, or DMR does not support volume control
\return DMC_E_INVAL Invalid parameter
\par Description:
This function returns DMC_E_OK when a request to set the mute state for a DMR is successfully
accepted.

The pointer to the device information of DMR is specified for self. If a pointer to other information is
specified, an error is returned.

The pointer to the callback function must be specified for in_obj_eh. The result of requesting to set the
mute state is notified asynchronously by in_obj_eh.

For information about value which can be specified for in_channel, see "2.2.19.
A_ARG_TYPE_Channel" in "UPnP AV RenderingControl:1 Service Template".

When the mute state is set successfully, the DMC_OBJECT_EV_RENDERER_MUTE_SET event is notified by in_obj_eh, and values are set for the following members in the TDMCObjectVolumeControlEHParam type. Other members must not be referenced.
- err_code Error code (0 for successful completion)

When setting the mute state fails, the DMC_OBJECT_EV_RENDERER_MUTE_SET event is notified, and
an error code is set for the err_code member in the TDMCObjectVolumeControlEHParam type.
The error details are also set for the err_description member.

For more information about error codes, see "2.4.28. SetMute" in "UPnP AV RenderingControl:1
Service Template".
*/
DLNA_API slim_int
dlnaDmcPlayerSetMuteState(TDMCObject self, TDMCObjectEventHandler in_obj_eh, 
                              void *in_arg, slim_char *in_channel, slim_bool in_mute);

/******************************************************************/

/*!
\par Function:
Determines whether DMC object is device.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMC object</td>
	</tr>
</table>

\return slim_true Objec type is device
\return slim_false Object type is not device
\par Description:
This function returns whether the object type is device.
*/
DLNA_API slim_bool
dlnaDmcObjectTypeIsDevice (TDMCObject self);

/*!
\par Function:
Determines whether DMC object is container.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMC object</td>
	</tr>
</table>

\return slim_true Object type is container
\return slim_false Object type is not container
\par Description:
This function returns whether the object type is container.
*/
DLNA_API slim_bool
dlnaDmcObjectTypeIsContainer (TDMCObject self);

/*!
\par Function:
Determines whether DMC object is item.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMC object</td>
	</tr>
</table>

\return slim_true Object type is item
\return slim_false Object type is not item
\par Description:
This function returns whether the object type is item.
*/
DLNA_API slim_bool
dlnaDmcObjectTypeIsItem (TDMCObject self);

/*!
\par Function:
Function check if self type is in_type like upnp object.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA device object.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_type</td>
		<td>Type to check.</td>
	</tr>
</table>
\return slim_bool value
\par Return Values:
<table>
	<tr>
		<td> \b slim_true</td>
		<td> \b self is specyfied by in_type object type </td>
	</tr>
	<tr>
		<td>slim_false</td>
		<td>slef is not a specyfied type of object or error occured</td>
	</tr>
</table>
*/
DLNA_API slim_bool
dlnaDmcObjectTypeGet (TDMCObject self, slim_char *in_type);

#ifdef _DOXYGEN
/*!
\par Function:
Determines whether DMC object is storage folder.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>DMC object</td>
 </tr>
</table>
     
\return slim_true Object type is storage folder
\return slim_false Object type is not storage folder
\par Description:
This function returns whether the object type is storage folder.
*/
slim_bool dlnaDmcObjectTypeIsStorageFolder (TDMCObject self);

/*!
\par Function:
Determines whether DMC object is music album.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>DMC object</td>
 </tr>
</table>
     
\return slim_true Object type is music album
\return slim_false Object type is not music album
\par Description:
This function returns whether the object type is music album.
*/
slim_bool dlnaDmcObjectTypeIsAlbum (TDMCObject self);

/*!
\par Function:
Determines whether DMC object is music album.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>DMC object</td>
 </tr>
</table>
     
\return slim_true Object type is music album
\return slim_false Object type is not music album
\par Description:
This function returns whether the object type is music album.
*/
slim_bool dlnaDmcObjectTypeIsMusicAlbum (TDMCObject self);

/*!
\par Function:
Determines whether DMC object is photo album.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>DMC object</td>
 </tr>
</table>
     
\return slim_true Object type is photo album
\return slim_false Object type is not photo album
\par Description:
This function returns whether the object type is photo album.
*/
slim_bool dlnaDmcObjectTypeIsPhotoAlbum (TDMCObject self);
    
/*!
\par Function:
Determines whether DMC object is playlist.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>DMC object</td>
 </tr>
</table>
     
\return slim_true Object type is playlist
\return slim_false Object type is not playlist
\par Description:
This function returns whether the object type is playlist.	
*/
slim_bool dlnaDmcObjectTypeIsPlaylistContainer (TDMCObject self);

/*!
\par Function:
Determines whether DMC object is image item.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>DMC object</td>
 </tr>
</table>
     
\return slim_true Object type is image item
\return slim_false Object type is not image item
\par Description:
This function returns whether the object type is image item.
*/
slim_bool dlnaDmcObjectTypeIsImageItem (TDMCObject self);

/*!
\par Function:
Determines whether DMC object is photo.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>DMC object</td>
 </tr>
</table>
     
\return slim_true Object type is photo
\return slim_false Object type is not photo
\par Description:
This function returns whether the object type is photo.
*/
slim_bool dlnaDmcObjectTypeIsPhoto (TDMCObject self);

/*!
\par Function:
Determines whether DMC object is audio item.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>DMC object</td>
 </tr>
</table>
     
\return slim_true Object type is audio item
\return slim_false Object type is not audio item
\par Description:
This function returns whether the object type is audio item.
*/
slim_bool dlnaDmcObjectTypeIsAudioItem (TDMCObject self);

/*!
\par Function:
Determines whether DMC object is music track.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>DMC object</td>
 </tr>
</table>
     
\return slim_true Object type is music track
\return slim_false Object type is not music track
\par Description:
This function returns whether the object type is music track.
*/
slim_bool dlnaDmcObjectTypeIsMusicTrack (TDMCObject self);

/*!
\par Function:
Determines whether DMC object is video item.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>DMC object</td>
 </tr>
</table>
     
\return slim_true Object type is video item
\return slim_false Object type is not video item
\par Description:
This function returns whether the object type is video item.
*/
slim_bool dlnaDmcObjectTypeIsVideoItem (TDMCObject self);

/*!
\par Function:
Determines whether DMC object is movie.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>DMC object</td>
 </tr>
</table>
     
\return slim_true Object type is movie
\return slim_false Object type is not movie
\par Description:
This function returns whether the object type is movie.
*/
slim_bool dlnaDmcObjectTypeIsMovie (TDMCObject self);

/*!
\par Function:
Determines whether DMC object is music video clip.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>DMC object</td>
 </tr>
</table>
     
\return slim_true Object type is music video clip
\return slim_false Object type is not music video clip
\par Description:
This function returns whether the object type is music video clip.	
*/
slim_bool dlnaDmcObjectTypeIsMusicVideoClip (TDMCObject self);

/*!
\par Function:
Determines whether DMC object is playlist item.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>DMC object</td>
 </tr>
</table>
     
\return slim_true Object type is playlist item
\return slim_false Object type is not playlist item
\par Description:
This function returns whether the object type is playlist item.
*/
slim_bool dlnaDmcObjectTypeIsPlayListItem (TDMCObject self);

#endif


/*@}*/

/**
 * @addtogroup macros
 */
/*@{*/

#ifndef _DOXYGEN
#define dlnaDmcObjectTypeIsStorageFolder(self)      dlnaDmcObjectTypeGet (self, SLIM_T("storageFolder"))
#define dlnaDmcObjectTypeIsAlbum(self)              dlnaDmcObjectTypeGet (self, SLIM_T("album"))
#define dlnaDmcObjectTypeIsMusicAlbum(self)         dlnaDmcObjectTypeGet (self, SLIM_T("musicAlbum"))
#define dlnaDmcObjectTypeIsPhotoAlbum(self)         dlnaDmcObjectTypeGet (self, SLIM_T("photoAlbum"))
#define dlnaDmcObjectTypeIsPlaylistContainer(self)  dlnaDmcObjectTypeGet (self, SLIM_T("playlistContainer"))
#define dlnaDmcObjectTypeIsImageItem(self)          dlnaDmcObjectTypeGet (self, SLIM_T("imageItem"))
#define dlnaDmcObjectTypeIsPhoto(self)              dlnaDmcObjectTypeGet (self, SLIM_T("photo"))
#define dlnaDmcObjectTypeIsAudioItem(self)          dlnaDmcObjectTypeGet (self, SLIM_T("audioItem"))
#define dlnaDmcObjectTypeIsMusicTrack(self)         dlnaDmcObjectTypeGet (self, SLIM_T("musicTrack"))
#define dlnaDmcObjectTypeIsVideoItem(self)          dlnaDmcObjectTypeGet (self, SLIM_T("videoItem"))
#define dlnaDmcObjectTypeIsMovie(self)              dlnaDmcObjectTypeGet (self, SLIM_T("movie"))
#define dlnaDmcObjectTypeIsMusicVideoClip(self)     dlnaDmcObjectTypeGet (self, SLIM_T("musicVideoClip"))
#define dlnaDmcObjectTypeIsPlayListItem(self)       dlnaDmcObjectTypeGet (self, SLIM_T("playlistItem"))
#endif

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Gets ID property.
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

\return URI (string) ID property value
\return Null Specified object has no property value
\par Description:
This function returns the ID property.
*/
DLNA_API slim_char *
dlnaDmcObjectPropId (TDMCObject self);

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
dlnaDmcObjectPropGetAttr (TDMCObject self, slim_char* in_prop, slim_char* in_attr);


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
dlnaDmcObjectPropParentId (TDMCObject self);

/*!
\par Function:
Gets path property.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>
			Pointer to device, container, or item information for which to get 		property value
		</td>
	</tr>
</table>

\return URI (string) path property value
\return Null Specified object has no property value
\par Description:
This function returns the path property.
*/
DLNA_API slim_char *
dlnaDmcObjectPropPath (TDMCObject self);

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
		<td>
			Pointer to store resource URI property value <br />
			If the specified object does not have a property value, null is set.
		</td>
	</tr>
</table>

\return DMC_E_OK Succeeded
\return Other Failed
\par Description:
This function returns the resource URI property.
*/
DLNA_API slim_int
dlnaDmcObjectPropResURI (TDMCObject self, slim_int in_res_index, slim_char **out_ResURI);

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
		<td>Pointer to play control information</td>
	</tr>
</table>

\return DMC_E_OK Succeeded
\return Other Failed
\par Description:
This function returns the resource size property.
*/
DLNA_API slim_int
dlnaDmcObjectPropResSize (TDMCObject self, slim_int in_res_index, slim_char **out_ResSize);


DLNA_API slim_int
dlnaDmcObjectPropResPIThumbnail(TDMCObject self, slim_int *out_res_index);
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
			-1 Specifies first resource
		</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_ResDuration</td>
		<td>
			Pointer to store resource duration property value
			Supported formats are as follows: 
			
			<b>
				duration = hours ":" minutes ":" seconds <br />
				hours = 1*5 DIGIT; 0-99999 <br />
				minutes = 2 DIGIT ; 00-59 <br />
				seconds = 2 DIGIT ["." 3 DIGIT]; 00-59 (.000-.999) <br />
			</b>
			
			If the specified object does not have a property value, null is set.
		</td>
	</tr>
</table>

\return DMC_E_OK Succeeded
\return Other Failed
\par Description:
This function returns the resource duration property.
*/
DLNA_API slim_int
dlnaDmcObjectPropResDuration (TDMCObject self, slim_int in_res_index, slim_char **out_ResDuration);
/*!
\par Function:
Gets resource protocolInfo property.
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
			-1 Specifies first resource
		</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_ResProtocolInfo</td>
		<td>
			Pointer to store resource protocolInfo property value			
			If the specified object does not have a property value, null is set.
		</td>
	</tr>
</table>

\return DMC_E_OK Succeeded
\return Other Failed
\par Description:
This function returns the resource protocolInfo property.
*/
DLNA_API slim_int
dlnaDmcObjectPropResProtocolInfo (TDMCObject self, slim_int in_res_index, slim_char **out_ResProtocolInfo);

/*!
\par Function:
Gets resource mimeType property.
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
			-1 Specifies first resource
		</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_ResMimeType</td>
		<td>
			Pointer to store resource mimeType property value

			If the specified object does not have a property value, null is set.
		</td>
	</tr>
</table>

\return DMC_E_OK Succeeded
\return Other Failed
\par Description:
This function returns the resource mimeType property.
*/
DLNA_API slim_int
dlnaDmcObjectPropResMimeType (TDMCObject self, slim_int in_res_index, slim_char **out_ResMimeType);

/*!
\par Function:
Gets resource resolution property.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>
			Pointer to item information for which to get property value
		</td>
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
		<td>
			Pointer to store resource resolution property value <br />
			If the specified object does not have a property value,  	is set.
		</td>
	</tr>
</table>
 
\return DMC_E_OK Succeeded
\return Other Failed
\par Description:
This function returns the resource resolution property.
*/
DLNA_API slim_int
dlnaDmcObjectPropResResolution (TDMCObject self, slim_int in_res_index, slim_char **out_ResResolution);

/*!
\par Function:
Gets total number of resources.
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
		<td>[out]</td>
		<td>out_count</td>
		<td>Total number of resources</td>
	</tr>
</table>

\return DMC_E_OK Succeeded
\return Other Failed
\par Description:
This function returns the total number of resources.
*/
DLNA_API slim_int
dlnaDmcObjectPropResCount (TDMCObject self, slim_int* count);

/*!
\par Function:
Gets resource property list.
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
		<td>[out]</td>
		<td>out_res_info</td>
		<td>Address where resource property obtained is stored</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_req_res_num</td>
		<td>
			Number of resources to get
		</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_begin_res_index</td>
		<td>
			Resource list start index
		</td>
	</tr>
</table>
 
\return -1 Failed
\return Other Number of resources obtained
\par Description:
This function gets in_req_res_num number of resource properties from the index specified for
in_begin_res_index, and stores them in out_res_info.
*/
DLNA_API slim_int
dlnaDmcObjectPropResList (TDMCObject self,  TDMCResPropInfoParam *out_res_info, slim_int in_req_res_num, slim_int in_begin_res_index);

/*!
\par Function:
Determines whether specified DMR can play specified item.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to item information</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_dmr</td>
		<td>Pointer to DMR device information obtained by dlnaDmcDeviceList()</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_res_index</td>
		<td>	>=0 Object resource index that determines whether an object is playable <br />
				-1 Determines whether it is playable by specified DMR</td>
	</tr>
</table>
  
\return slim_true Playable by specified DMR
\return slim_false Not playable by specified DMR, or error occurred
\par Description:
When in_res_index is 0 or more, this function determines whether the item indicated by the resource
index is playable, and returns the result as a return value. When in_res_index is -1, this function
determines whether the item indicated by an original resource is playable, and returns the result as a
return value.
*/
DLNA_API slim_bool
dlnaDmcObjectIsPlayable (TDMCObject self, TDMCObject in_dmr, slim_int in_res_index);

/*!
\par Function:
Gets property value by name.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>
			Pointer to device, container, or item information for which to get 		property value
		</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>prop</td>
		<td>Property name</td>
	</tr>
</table>

\return URI (string) Property value
\return Null Specified object has no property value
\par Description:
This function returns the property value of the name specified for prop.
 
\latexonly
\newpage
\endlatexonly
*/
DLNA_API slim_char *
dlnaDmcObjectPropGet (TDMCObject self, slim_char* in_prop);

/*!
\par Function:
Counts property user metadata items.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Object with metadata we should get count</td>
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
		<td> \b DMC_E_ok</td>
		<td> <b>Success</b></td>
	</tr>
	<tr>
		<td>DMC_E_INVAL</td>
		<td>Invalid Value passed to function</td>
	</tr>
	<tr>
		<td>DMC_E_NOTFOUND</td>
		<td>user_metadata not found</td>
	</tr>
	<tr>
		<td>DMC_E_GENERIC</td>
		<td>generic error occurred</td>
	</tr>
</table>
\par Description:
This function counts property user metadata items and stores it in out_count.
*/
DLNA_API slim_int
dlnaDmcObjectPropUserMetadataCount(TDMCObject self, slim_int * out_count);

/*!
\par Function:
Gets property user metadata items.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Object with metada we should get count</td>
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
		<td> \b DMC_E_ok</td>
		<td> <b>Success</b></td>
	</tr>
	<tr>
		<td>DMC_E_INVAL</td>
		<td>Invalid Value passed to function</td>
	</tr>
	<tr>
		<td>DMC_E_NOTFOUND</td>
		<td>user_metadata not found</td>
	</tr>
	<tr>
		<td>DMC_E_GENERIC</td>
		<td>generic error occurred</td>
	</tr>
</table>
\par Description:
This function gets property user metadata item specified by in_meta_index stores name of this item in out_name and value in out_value.
*/
DLNA_API slim_int
dlnaDmcObjectPropUserMetadata(TDMCObject self, slim_int in_meta_index, slim_char ** out_name, slim_char ** out_value);

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
        Pointer to device, container, or item information for which to get property value
    </td>
 </tr>
</table>
     
\return URI (string) title property value
\return Null Specified object has no property value
\par Description:
This function returns the title property.
\latexonly
\newpage
\endlatexonly
*/
    
slim_char * dlnaDmcObjectPropTitle (TDMCObject self);
    
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
     
\return URI (string) creator property value
\return Null Specified object has no property value
\par Description:
     This function returns the creator property.
*/
slim_char * dlnaDmcObjectPropCreator (TDMCObject self);

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
     
\return URI (string) write status property value
\return Null Specified object has no property value
\par Description:
This function returns the write status property.
*/
slim_char * dlnaDmcObjectPropWriteStatus (TDMCObject self);

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
     
\return  URI (string) detailed description property value
\return Null Specified object has no property value
\par Description:
This function returns the detailed description property.
*/
slim_char * dlnaDmcObjectPropLongDescription (TDMCObject self);


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
     
\return  URI (string) description property value
\return Null Specified object has no property value
\par Description:
This function returns the description property.
*/
slim_char * dlnaDmcObjectPropDescription (TDMCObject self);
    
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
     
\return URI (string) publisher property value
\return Null Specified object has no property value
\par Description:
This function returns the publisher property.
*/
slim_char * dlnaDmcObjectPropPublisher (TDMCObject self);

    
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
     
\return URI (string) contributor property value
\return Null Specified object has no property value
\par Description:
This function returns the contributor property.
*/
slim_char * dlnaDmcObjectPropContributor (TDMCObject self);

    
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
     
\return URI (string) date property value
     
Supported formats are as follows:
     
\verbatim
CCYY-MM-DD
CCYY-MM-DDThh:mm:ss
CCYY-MM-DDThh:mm:ssZ
CCYY-MM-DDThh:mm:ss+hh:mm
CCYY-MM-DDThh:mm:ss-hh:mm
CCYY-MM-DDThh:mm:ss.sss
CCYY-MM-DDThh:mm:ss.sssZ
CCYY-MM-DDThh:mm:ss.sss+hh:mm
CCYY-MM-DDThh:mm:ss.sss-hh:mm
\endverbatim
     
\return Null Specified object has no property value
\par Description:
This function returns the date property.
*/
slim_char * dlnaDmcObjectPropDate (TDMCObject self);


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
     
\return URI (string) copyrights property value
\return Null Specified object has no property value
\par Description:
This function returns the copyrights property.
*/
slim_char * dlnaDmcObjectPropCopyrights (TDMCObject self);


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
     
\return URI (string) artist property value
\return Null Specified object has no property value
\par Description:
This function returns the artist property.
*/
slim_char * dlnaDmcObjectPropArtist (TDMCObject self);

    
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
     
\return URI (string) album property value
\return Null Specified object has no property value
\par Description:
This function returns the album property.
*/
slim_char * dlnaDmcObjectPropAlbum (TDMCObject self);
    
    
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
     
\return URI (string) genre property value
\return Null Specified object has no property value
\par Description:
This function returns the genre property.
*/
slim_char * dlnaDmcObjectPropGenre (TDMCObject self);
    
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
     
\return URI (string) producer property value
\return Null Specified object has no property value
\par Description:
This function returns the producer property.
*/
slim_char * dlnaDmcObjectPropProducer (TDMCObject self);

    
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
     
\return URI (string) album art URI property value
\return Null Specified object has no property value
\par Description:
This function returns the album art URI property.
*/
slim_char * dlnaDmcObjectPropAlbumArtURI (TDMCObject self);
    
    
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
     
\return URI (string) language property value
\return Null Specified object has no property value
\par Description:
This function returns the language property.
*/
slim_char * dlnaDmcObjectPropLanguage (TDMCObject self);
    

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
     
\return URI (string) actor property value
\return Null Specified object has no property value
\par Description:
This function returns the actor property.
*/
slim_char * dlnaDmcObjectPropActor (TDMCObject self);

/*!
\par Function:
Gets TrackNumber property.
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

\return URI (string) TrackNumber property value for Music Files
\return Null Specified object has no property value
\par Description:
This function returns the Music Track Number property.
*/
slim_char * dlnaDmcObjectPropTrackNumber(TDMCObject self);

/*!
\par Function:
Gets the device name.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by dlnaDmcDeviceList()</td>
 </tr>
</table>
     
\return Device name (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TDMCEvent is given by DMC_EV_FOUND_DEVS, it is recommended to call this
function within TDMCEventHandler() to get the device name.
*/
slim_char * dlnaDmcDeviceName (TDMCObject self);

/*!
\par Function:
Gets the device UUID.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by dlnaDmcDeviceList()</td>
 </tr>
</table>
     
\return Device UUID (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TDMCEvent is given by DMC_EV_FOUND_DEVS, it is recommended to call this
function within TDMCEventHandler() to get the device name.
*/
slim_char * dlnaDmcDeviceUuid (TDMCObject self);

/*!
\par Function:
Gets the manufacturer name.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by dlnaDmcDeviceList()</td>
 </tr>
</table>
     
\return manufacturer name (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TDMCEvent is given by DMC_EV_FOUND_DEVS, it is recommended to call this
function within TDMCEventHandler() to get the device name.
*/
slim_char * dlnaDmcManufacturerName (TDMCObject self);

/*!
\par Function:
Gets the manufacturer URL.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by dlnaDmcDeviceList()</td>
 </tr>
</table>
     
\return manufacturer URL (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TDMCEvent is given by DMC_EV_FOUND_DEVS, it is recommended to call this 
function within TDMCEventHandler() to get the device name.
*/
slim_char * dlnaDmcManufacturerURL (TDMCObject self);

/*!
\par Function:
Gets the model name.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by dlnaDmcDeviceList()</td>
 </tr>
</table>
     
\return model name (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TDMCEvent is given by DMC_EV_FOUND_DEVS, it is recommended to call this 
function within TDMCEventHandler() to get the device name.
*/
slim_char * dlnaDmcModelName (TDMCObject self);

/*!
\par Function:
Gets the model URL.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by dlnaDmcDeviceList()</td>
 </tr>
</table>
     
\return model URL (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TDMCEvent is given by DMC_EV_FOUND_DEVS, it is recommended to call this 
function within TDMCEventHandler() to get the device name.
*/
slim_char * dlnaDmcModelURL (TDMCObject self);

/*!
\par Function:
Gets the model description.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by dlnaDmcDeviceList()</td>
 </tr>
</table>
     
\return model description (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TDMCEvent is given by DMC_EV_FOUND_DEVS, it is recommended to call this 
function within TDMCEventHandler() to get the device name.
*/
slim_char * dlnaDmcModelDescription (TDMCObject self);

/*!
\par Function:
Gets the model number.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by dlnaDmcDeviceList()</td>
 </tr>
</table>
     
\return model number (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TDMCEvent is given by DMC_EV_FOUND_DEVS, it is recommended to call this 
function within TDMCEventHandler() to get the device name.
*/
slim_char * dlnaDmcModelNumber (TDMCObject self);
    
/*!
\par Function:
Gets the serial number.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by dlnaDmcDeviceList()</td>
 </tr>
</table>
     
\return serial number (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TDMCEvent is given by DMC_EV_FOUND_DEVS, it is recommended to call this 
function within TDMCEventHandler() to get the device name.
*/
slim_char * dlnaDmcSerialNumber (TDMCObject self);

/*!
\par Function:
Gets the TXT version.
\par Parameters:
     
<table>	
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by dlnaDmcDeviceList()</td>
 </tr>
</table>
     
\return TXT version (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TDMCEvent is given by DMC_EV_FOUND_DEVS, it is recommended to call this 
function within TDMCEventHandler() to get the device name.
*/
slim_char * dlnaDmcTXTVersion (TDMCObject self);    
#endif

/*@}*/



#ifndef _DOXYGEN

/** 
 * @addtogroup macros
 */
/*@{*/

#define dlnaDmcObjectPropTitle(self)            dlnaDmcObjectPropGet (self, SLIM_T("dc:title"))
#define dlnaDmcObjectPropCreator(self)          dlnaDmcObjectPropGet (self, SLIM_T("dc:creator"))
#define dlnaDmcObjectPropWriteStatus(self)      dlnaDmcObjectPropGet (self, SLIM_T("upnp:writeStatus"))    
#define dlnaDmcObjectPropLongDescription(self)  dlnaDmcObjectPropGet (self, SLIM_T("upnp:longDescription"))
#define dlnaDmcObjectPropDescription(self)      dlnaDmcObjectPropGet (self, SLIM_T("upnp:description"))
#define dlnaDmcObjectPropPublisher(self)        dlnaDmcObjectPropGet (self, SLIM_T("dc:publisher"))
#define dlnaDmcObjectPropContributor(self)      dlnaDmcObjectPropGet (self, SLIM_T("dc:contributor"))
#define dlnaDmcObjectPropDate(self)             dlnaDmcObjectPropGet (self, SLIM_T("dc:date"))
#define dlnaDmcObjectPropCopyrights(self)       dlnaDmcObjectPropGet (self, SLIM_T("dc:rights"))
#define dlnaDmcObjectPropArtist(self)           dlnaDmcObjectPropGet (self, SLIM_T("upnp:artist"))
#define dlnaDmcObjectPropAlbum(self)            dlnaDmcObjectPropGet (self, SLIM_T("upnp:album"))
#define dlnaDmcObjectPropGenre(self)            dlnaDmcObjectPropGet (self, SLIM_T("upnp:genre"))    
#define dlnaDmcObjectPropProducer(self)         dlnaDmcObjectPropGet (self, SLIM_T("upnp:producer"))
#define dlnaDmcObjectPropAlbumArtURI(self)      dlnaDmcObjectPropGet (self, SLIM_T("upnp:albumArtURI"))
#define dlnaDmcObjectPropLanguage(self)         dlnaDmcObjectPropGet (self, SLIM_T("dc:language"))
#define dlnaDmcObjectPropActor(self)            dlnaDmcObjectPropGet (self, SLIM_T("upnp:actor"))
#define dlnaDmcObjectPropTrackNumber(self)      dlnaDmcObjectPropGet (self, SLIM_T("upnp:originalTrackNumber"))
#define dlnaDmcDeviceName(self)                 dlnaDmcObjectPropGet (self, SLIM_T("friendlyName"))
#define dlnaDmcDeviceUuid(self)                 dlnaDmcObjectPropGet (self, SLIM_T("UDN"))
#define dlnaDmcManufacturerName(self)           dlnaDmcObjectPropGet (self, SLIM_T("manufacturer"))
#define dlnaDmcManufacturerURL(self)            dlnaDmcObjectPropGet (self, SLIM_T("manufacturerURL"))
#define dlnaDmcModelName(self)                  dlnaDmcObjectPropGet (self, SLIM_T("modelName"))
#define dlnaDmcModelURL(self)                   dlnaDmcObjectPropGet (self, SLIM_T("modelURL"))
#define dlnaDmcModelDescription(self)           dlnaDmcObjectPropGet (self, SLIM_T("modelDescription"))
#define dlnaDmcModelNumber(self)                dlnaDmcObjectPropGet (self, SLIM_T("modelNumber"))
#define dlnaDmcSerialNumber(self)               dlnaDmcObjectPropGet (self, SLIM_T("serialNumber"))
#define dlnaDmcTXTVersion(self)                 dlnaDmcObjectPropGet (self, SLIM_T("TXTVersion"))

#endif

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Function gets new transport object to play.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DMC instance.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_obj_eh</td>
		<td>Callback function that notifies of API processing result.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Callback arument.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_dmr</td>
		<td>dmr instance</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_id</td>
		<td>Transport ID.</td>
	</tr>
</table>
\return TDMCObject containig transport object
\par Return Values:
<table>
	<tr>
		<td> \b !=slim_nil</td>
		<td> \b if gets of new transport object to play succed</td>
	</tr>
	<tr>
		<td>slim_nil</td>
		<td>Failed</td>
	</tr>
</table>
*/

TDMCObject
dlnaDmcTransportGet (TDMC self,TDMCObjectEventHandler in_obj_eh,
                 void *in_arg, TDMCObject in_dmr,slim_int in_id) ;

/*!
\par Function:
Function gets info about transport playng object.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA transport type object.</td>
	</tr>
</table>
\return slim_int error code value
\par Return Values:
<table>
	<tr>
		<td> \b DMC_E_OK</td>
		<td> \b State get succed</td>
	</tr>
	<tr>
		<td>DMC_E_INVAL</td>
		<td>Invalid value</td>
	</tr>
	<tr>
		<td>UPNP_INVALID_PARAM</td>
		<td>Invalid upnp parameter</td>
	</tr>
	<tr>
		<td>UPNP_OUT_OF_MEMORY</td>
		<td>Out of memory</td>
	</tr>
</table>
*/

slim_int
dlnaDmcPlayQueryState (TDMCObject self) ;

/*!
\par Function:
Function gets current connections IDs.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA device object.</td>
	</tr>
</table>
\return slim_int error code value
\par Return Values:
<table>
	<tr>
		<td> \b DMC_E_OK</td>
		<td> \b State get succed</td>
	</tr>
	<tr>
		<td>DMC_E_INVAL</td>
		<td>Invalid value</td>
	</tr>
	<tr>
		<td>DMC_E_GENERIC</td>
		<td>Generic error</td>
	</tr>
	<tr>
		<td>DMC_E_NOMEM</td>
		<td>Out of memory</td>
	</tr>
</table>
*/

slim_int
dlnaDmcGetCurrentConnectionIDs (TDMCObject self);

/*!
\par Function:
Function gets info about transport playng object.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA transport type object.</td>
	</tr>
</table>
\return slim_int error code value
\par Return Values:
<table>
	<tr>
		<td> \b DMC_E_OK</td>
		<td> \b State get succed</td>
	</tr>
	<tr>
		<td>DMC_E_INVAL</td>
		<td>Invalid value</td>
	</tr>
	<tr>
		<td>UPNP_INVALID_PARAM</td>
		<td>Invalid upnp parameter</td>
	</tr>
	<tr>
		<td>UPNP_OUT_OF_MEMORY</td>
		<td>Out of memory</td>
	</tr>
</table>
*/

slim_int
dlnaDmcPlayGetTransportInfo (TDMCObject self);

/*!
\par Function:
Function stes DLNA transport URI.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA transport type object.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>item</td>
		<td>DLNA item object.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_res_index</td>
		<td>Resource index to set.</td>
	</tr>
</table>
\return slim_int error code value
\par Return Values:
<table>
	<tr>
		<td> \b DMC_E_OK</td>
		<td> \b State get succed</td>
	</tr>
	<tr>
		<td>DMC_E_INVAL</td>
		<td>Invalid value</td>
	</tr>
	<tr>
		<td>DMC_E_GENERIC</td>
		<td>Generic error</td>
	</tr>
</table>
*/

slim_int
dlnaDmcPlaySetTransportUri (TDMCObject self, TDMCObject dmr, TDMCObject item, slim_int in_res_index) ;

/*!
\par Function:
Function sets DLNA Next transport URI.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA transport type object.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>item</td>
		<td>DLNA item object.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_res_index</td>
		<td>Resource index to set.</td>
	</tr>
</table>
\return slim_int error code value
\par Return Values:
<table>
	<tr>
		<td> \b DMC_E_OK</td>
		<td> \b State get succed</td>
	</tr>
	<tr>
		<td>DMC_E_INVAL</td>
		<td>Invalid value</td>
	</tr>
	<tr>
		<td>DMC_E_GENERIC</td>
		<td>Generic error</td>
	</tr>
</table>
*/

slim_int
dlnaDmcPlaySetNextTransportUri (TDMCObject self, TDMCObject dmr, TDMCObject item, slim_int in_res_index) ;


/*!
\par Function:
Function gets query value from transport type play object.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA transport type object.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_var_name</td>
		<td>DLNA item object.</td>
	</tr>
</table>
\return slim_int error code value
\par Return Values:
<table>
	<tr>
		<td> \b DMC_E_OK</td>
		<td> \b State get succed</td>
	</tr>
	<tr>
		<td>DMC_E_INVAL</td>
		<td>Invalid value</td>
	</tr>
	<tr>
		<td>DMC_E_GENERIC</td>
		<td>Generic error</td>
	</tr>
</table>
*/

slim_int
dlnaDmcPlayQueryValue (TDMCObject self, slim_char *in_var_name) ;
/*
slim_bool
dlnaDmcPlayIsHandover (TDMCObject self) ;
*/

/*!
\par Function:
Function function check if object is transport type.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA object to check.</td>
	</tr>
</table>
\return slim_bool value
\par Return Values:
<table>
	<tr>
		<td> \b slim_true</td>
		<td> \b Object is transport type</td>
	</tr>
	<tr>
		<td>slim_false</td>
		<td>Object is other type than transport</td>
	</tr>
</table>
*/

slim_bool
dlnaDmcObjectTypeIsTransport (TDMCObject self) ;

/*!
\par Function:
Function handovers play from in_play to in_play_to object or if in_play_to is slim_nil new object to handover play is allocated.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_play</td>
		<td>DLNA transport type object with play event.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_obj_eh</td>
		<td>Callback event handler.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Input argument of callback</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_dmr</td>
		<td>active dmr</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_play_to</td>
		<td>DLNA object witch handover play or slim_nil when we want to create transport object</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_play</td>
		<td>Output object pointer where transport object will be stored</td>
	</tr>
</table>
\return slim_int error code value
\par Return Values:
<table>
	<tr>
		<td> \b DMC_E_OK</td>
		<td> \b Handover succed</td>
	</tr>
	<tr>
		<td>DMC_E_INVAL</td>
		<td>Invalid value</td>
	</tr>
	<tr>
		<td>DMC_E_INVAL</td>
		<td>Invalid value</td>
	</tr>
</table>
*/

slim_int
dlnaDmcPlayHandover (TDMCObject self, TDMCObjectEventHandler in_obj_eh,
    void *in_arg, TDMCObject in_dmr,  TDMCObject in_play_to,TDMCObject *out_play);

/*!
\par Function:
Function checks if object is local device.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_play</td>
		<td>DLNA device type object to check.</td>
	</tr>
</table>
\return slim_bool value
\par Return Values:
<table>
	<tr>
		<td> \b slim_true</td>
		<td> \b Device type object is local device</td>
	</tr>
	<tr>
		<td>slim_false</td>
		<td>Object is not local device or it is not device type object</td>
	</tr>
</table>
*/

slim_bool
dlnaDmcDeviceIsLocal (TDMCObject self) ;

slim_bool
dlnaDmcIsSeekModeSupported(TDMCObject self, slim_int in_seek_mode);

slim_int
dlnaDmcGetSupportedSeekMode(TDMCObject self);

slim_int
dlnaDmcGetProtocolInfo(TDMCObject self, protocolInfoType_t in_protocolInfoType,  slim_char **out_protocolInfo);

/*@}*/

#ifdef DEVELOPMENT_DIRECT_DLNA_OBJECT
slim_int
dlnaDmcDirectPlayOpen (TDMCObject self, TDMCObjectEventHandler in_obj_eh, void *in_arg, TDMCObject in_dmr , TDMCObject *out_play);

TDMCObject
dlnaDmcObjectCreateByMetadata(TDMC self, slim_char *in_uri, slim_char *in_mimeType, slim_char *in_title, slim_char *in_itemInfo);

TDMCObject
dlnaDmcObjectCreateForLocalFile(TDMC self, const slim_char *file_path, const slim_char *title, slim_opaque *out_album_art);
#endif /* DEVELOPMENT_DIRECT_DLNA_OBJECT */

#if defined(DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2) || defined(DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1)
/*!
\par Function:
Function checks if object has Service.
\par Parameters:
<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DMC Object Pointer</td>
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
dlnaDmcObjectHasEmbeddedService(TDMCObject self, slim_char* upnp_service_type);
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
This function Basic Management Service action GetTestInfo for the specified test.
The DIAGE sends the action response with A_ARG_TYPE_TestType and A_ARG_TYPE_TestState.
The action response can be obtained in the event handler callback function.
*/

slim_int
dlnaDmcBmsGetTestInfo(TDMCObject self, TDMCObjectEventHandler in_obj_eh, void *in_arg, slim_char* in_testId);

/*!
\par Function:
Function executes Basic Management Service Action Ping
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
This function Basic Management Service action Ping for the specified test.
The DIAGE sends the action response with A_ARG_TYPE_TestID.
The action response can be obtained in the event handler callback function.
*/

slim_int
dlnaDmcBmsPing(TDMCObject self, TDMCObjectEventHandler in_obj_eh,
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
</table>
\return slim_int value
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
This function Basic Management Service action GetPingResult for the specified test.
The DIAGE sends the action response with A_ARG_TYPE_PingStatus and A_ARG_TYPE_String.
The action response can be obtained in the event handler callback function.
*/

slim_int
dlnaDmcBmsGetPingResult(TDMCObject self, TDMCObjectEventHandler in_obj_eh, void *in_arg, slim_char* in_testId);

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
dlnaDmcBmsNSLookup(TDMCObject self, 
		         TDMCObjectEventHandler in_obj_eh,
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
dlnaDmcBmsGetNSLookupResult(TDMCObject self,
		                    TDMCObjectEventHandler in_obj_eh,
							void *in_arg,
							slim_char* in_testId);


slim_int
dlnaDmcBmsGetDeviceStatus(TDMCObject self, TDMCObjectEventHandler in_obj_eh, void *in_arg);

/*!
\par Function:
Function executes Basic Management Service Action Traceroute
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
                <td>Block Size of the test for which Traceroute is requested</td>
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
This function Basic Management Service action Traceroute for the specified test.
The DIAGE sends the action response with A_ARG_TYPE_TestID.
The action response can be obtained in the event handler callback function.
*/

slim_int
dlnaDmcBmsTraceroute(TDMCObject self, TDMCObjectEventHandler in_obj_eh,
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
This function Basic Management Service action GetTracerouteResult for the specified test.
The DIAGE sends the action response with A_ARG_TYPE_Traceroute-Status and A_ARG_TYPE_String.
The action response can be obtained in the event handler callback function.
*/

slim_int
dlnaDmcBmsGetTracerouteResult(TDMCObject self, TDMCObjectEventHandler in_obj_eh, void *in_arg, slim_char* in_testId);

/*!
\par Function:
Function executes Basic Management Service Action GetTestIDs
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
This function Basic Management Service action GetTestIDs for the specified test.
The DIAGE sends the action response with A_ARG_TYPE_TestID.
The action response can be obtained in the event handler callback function.
*/

slim_int
dlnaDmcBmsGetTestIds(TDMCObject self, TDMCObjectEventHandler in_obj_eh, void *in_arg);

/*!
\par Function:
Function executes Basic Management Service Action GetActiveTestIDs
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
This function Basic Management Service action GetActiveTestIDs for the specified test.
The DIAGE sends the action response with A_ARG_TYPE_TestID.
The action response can be obtained in the event handler callback function.
*/

slim_int
dlnaDmcBmsGetActiveTestIds(TDMCObject self, TDMCObjectEventHandler in_obj_eh, void *in_arg);

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
This function Energy Management Service action GetInterfaceInfo.
The LPE sends the action response with NetworkInterfaceInfo.
The action response can be obtained in the event handler callback function.
*/
slim_int
dlnaDmcEmsGetInterfaceInfo(TDMCObject self, TDMCObjectEventHandler in_obj_eh, void *in_arg);

#ifdef DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_SUBSCRIPTION
/*!
\par Function:
Function executes Energy Management Service Action ServiceSubscription
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
This function Energy Management Service action ServiceSubscription.
The LPE sends the action response with ServiceSubscriptionID and Duration.
The action response can be obtained in the event handler callback function.
*/
slim_int
dlnaDmcEmsSerivceSubscription(TDMCObject self,
		                      TDMCObjectEventHandler in_obj_eh,
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
This function Energy Management Service action ServiceRenewal.
The LPE sends the action response with Duration.
The action response can be obtained in the event handler callback function.
*/
slim_int
dlnaDmcEmsServiceRenewal(TDMCObject self,
		                 TDMCObjectEventHandler in_obj_eh,
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
                <td>in_serviceSubscriptionID</td>
                <td>an identifier set by the device in a previous response to the ServiceSubscription() action.</td>
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
This function Energy Management Service action ServiceRenewal.
The action response can be obtained in the event handler callback function.
*/
slim_int
dlnaDmcEmsServiceRelease(TDMCObject self,
		                 TDMCObjectEventHandler in_obj_eh,
						 void *in_arg,
						 slim_char *in_serviceSubscriptionID);

#endif /* DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_SUBSCRIPTION */
#endif /* DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1 */

#ifdef DEVELOPMENT_DLNA_SUPPORT_RA
slim_bool
dlnaDmcDeviceIsRemote (TDMCObject self) ;
#endif /* DEVELOPMENT_DLNA_SUPPORT_RA */

TDMCObject
dlnaDmcBrowseObjectGet(TDMCObject in_device, slim_char *in_id, slim_char *object_class, slim_int in_beg, slim_int in_num);

TDMCObject
dlnaDmcPrintObjectGet(TDMCObject in_dmpr, TDMCObjectEventHandler in_obj_eh, void *in_arg, sXML *item_doc);

TDMCObject
dlnaDmcContentObjectGet (TDMC self, sXML *in_item_doc);

#ifdef DEVELOPMENT_DIRECT_DLNA_OBJECT
slim_int
dlnaDmcDirectPlayFromLocalOpen (TDMCObject self, slim_opaque in_album_art, TDMCObjectEventHandler in_obj_eh,
                       void *in_arg, TDMCObject in_dmr, TDMCObject *out_play, slim_char **out_url);
slim_int
dlnaDmcPlayIsLocalContent (TDMCObject self, slim_bool *out_is_local, slim_char **out_file_path);
#endif /* DEVELOPMENT_DIRECT_DLNA_OBJECT */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DMC_API_H */
