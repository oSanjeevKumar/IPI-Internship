/*
* dmc_ahl.h
* Copyright (C) 2015 ACCESS CO.,LTD.
* All rights are reserved by ACCESS CO.,LTD.,
* whether the whole or part of the source code
* including any modifications is concerned.
*
* This is an unpublished source code of ACCESS CO.,LTD., and must be
* treated as confidential material.  The above copyright notice does
* not evidence any actual or intended publication of this source code.
*/

#ifndef DMC_AHL_H
#define DMC_AHL_H

#include <ahl.h>

/** full path of upload file */
#define UP_APP_FILE_PATH_MAX 256

/* dmcInstance_t is the instance of the library */
typedef void *dmcInstance_t;

/* enum for play control related commands */
typedef enum dmcPlayControlCommand_ {
  PLAY_CONTROL_NEXT = 0,
  PLAY_CONTROL_PREV,
  PLAY_CONTROL_PAUSE,
  PLAY_CONTROL_PLAY,
  PLAY_CONTROL_STOP,
  PLAY_CONTROL_END // Last item in list, no control command
} dmcPlayControlCommand;

/* enum for preset control related commands */
typedef enum dmcPresetControlCommand_ {
  PRESET_CONTROL_LIST = 0,
  PRESET_CONTROL_SELECT,
  PRESET_CONTROL_END
} dmcPresetControlCommand;

/* enum for volume control related commands */
typedef enum dmcVolumeControlCommand_ {
  VOLUME_CONTROL_GET_VALUE = 0,
  VOLUME_CONTROL_SET_VALUE,
  VOLUME_CONTROL_GET_MUTESTATE,
  VOLUME_CONTROL_SET_MUTESTATE,
  VOLUME_CONTROL_END // Last item in list, no control command
} dmcVolumeControlCommand;

typedef enum dmcFileTransferControlCommand_ {
  FILETRANSFER_CONTROL_START = 0,
  FILETRANSFER_CONTROL_CANCEL,
  FILETRANSFER_CONTROL_PAUSE,
  FILETRANSFER_CONTROL_RESUME,
  FILETRANSFER_CONTROL_END // Last item in list, no control command
} dmcFileTransferControlCommand;

typedef enum dmcFileTransferErrorCode_ {
  FILE_TRANSFER_OK = 0,
  FILE_TRANSFER_GENERIC,
  FILE_TRANSFER_INVAL,
  FILE_TRANSFER_IGNORE,
  FILE_TRANSFER_BAD_METADATA,
  FILE_TRANSFER_HTTP_TIMEOUT, /* 5 */
  FILE_TRANSFER_HTTP_SESSION_ERROR,
  FILE_TRANSFER_HTTP_ERROR,
  FILE_TRANSFER_NO_SUCH_OBJ,
  FILE_TRANSFER_RESTRICTED_OBJ,
  FILE_TRANSFER_RESTRICTED_PARENT_OBJ, /* 10 */
  FILE_TRANSFER_NO_SUCH_RESOURCE,
  FILE_TRANSFER_RESOURCE_ACCESS_DENIED,
  FILE_TRANSFER_NO_SUCH_CONTAINER,
  FILE_TRANSFER_NO_SPACE_AVAILABLE,
  FILE_TRANSFER_NO_UPLOAD_CONTAINER, /* 15 */
  FILE_TRANSFER_INTERNAL_SERVER_ERROR
} dmcFileTransferErrorCode;

typedef enum dmcObjectControlCommand_ {
  OBJECT_CONTROL_CREATE = 0,
  OBJECT_CONTROL_DESTROY,
  OBJECT_CONTROL_END // Last item in list, no control command
} dmcObjectControlCommand;

/*enum for dmc object type */
typedef enum contentClass_ {
  CONTENT_CLASS_CONTAINER = 0,
  CONTENT_CLASS_ITEM
} contentClass;


typedef enum dmcPlaybackMoveContentStep_ {
  PLAYBACK_MOVE_STEP_INITIALIZE = 0,
  PLAYBACK_MOVE_STEP_PREPARE_DESTINATION,
  PLAYBACK_MOVE_STEP_SEEK_DESTINATION,
  PLAYBACK_MOVE_STEP_FINISH_PROCESSING,
  PLAYBACK_MOVE_STEP_END  // Last item in list, no control command
} dmcPlaybackMoveContentStep;


typedef enum dmcPlaybackMoveContentErrorCode_ {
  PLAYBACK_MOVE_OK = 0,
  PLAYBACK_MOVE_GENERIC_ERROR,
  PLAYBACK_MOVE_FAILED_TIMEDOUT,
  PLAYBACK_MOVE_SOURCE_DMR_DISAPPEARED,
  PLAYBACK_MOVE_SOURCE_DMR_STATE_NOMEDIA,
  PLAYBACK_MOVE_SOURCE_DMR_GETTRANSPORTINFO_FAILED, /* 5 */
  PLAYBACK_MOVE_SOURCE_DMR_GETMEDIAINFO_FAILED,
  PLAYBACK_MOVE_SOURCE_DMR_GETPLAYPOSITION_FAILED,
  PLAYBACK_MOVE_DESTINATION_DMR_DISAPPEARED,
  PLAYBACK_MOVE_DESTINATION_DMR_GETTRANSPORTINFO_FAILED,
  PLAYBACK_MOVE_DESTINATION_DMR_SETURI_FAILED, /* 10 */
  PLAYBACK_MOVE_DESTINATION_DMR_PLAY_CONTROL_FAILED,
  PLAYBACK_MOVE_DESTINATION_DMR_CONTENT_NOT_SUPPORTED
} dmcPlaybackMoveContentErrorCode;

/* enum for play speed list */
typedef enum dmcPlaySpeedListType_ {
  PLAY_SPEED_LIST_TYPE_FAST = 0,
  PLAY_SPEED_LIST_TYPE_SLOW
} dmcPlaySpeedListType;

/* DMC Events  */
/*!
The DMC Events are shown below.

<table>
	<tr>
		<td> \b Definition</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>DMC_EVENT_NEW_DEVICE</td>
		<td>New device in network detected</td>
	</tr>
	<tr>
		<td>DMC_EVENT_DELETE_DEVICE</td>
		<td>Device disappears from network</td>
	</tr>
	<tr>
		<td>DMC_EVENT_DEVICE_LAST_CHANGE</td>
		<td>Last change event received from a device</td>
	</tr>
	<tr>
		<td>DMC_EVENT_GET_DEVICE_RESULT</td>
		<td>Result of dmcGetDevices()</td>
	</tr>
	<tr>
		<td>DMC_EVENT_GET_SERVICE_DESCRIPTION_RESULT</td>
		<td>Result of dmcGetServiceDescription()</td>
	</tr>
	<tr>
		<td>DMC_EVENT_BROWSE_DIRECTCHILDREN_RESULT</td>
		<td>Result of dmcBrowseDirectChildren()</td>
	</tr>
	<tr>
		<td>DMC_EVENT_BROWSE_METADATA_RESULT</td>
		<td>Result of dmcBrowseMetadata()</td>
	</tr>
	<tr>
		<td>DMC_EVENT_SEARCH_RESULT</td>
		<td>Result of dmcObjectSearch()</td>
	</tr>
	<tr>
		<td>DMC_EVENT_PLAYBACK_PREPARE_RESULT</td>
		<td>Result of dmcPlaybackPrepare()</td>
	</tr>
	<tr>
		<td>DMC_EVENT_PLAYBACK_CONTROL_RESULT</td>
		<td>Result of dmcPlaybackControl()</td>
	</tr>
	<tr>
		<td>DMC_EVENT_PLAYBACK_SEEK_RESULT</td>
		<td>Result of dmcPlaybackTimeSeek()</td>
	</tr>
	<tr>
		<td>DMC_EVENT_PRESET_CONTROL_RESULT</td>
		<td>Result of dmcListPresets() and dmcSelectPreset()</td>
	</tr>
	<tr>
		<td>DMC_EVENT_VOLUME_CONTROL_RESULT</td>
		<td>Result of dmcVolumeControl()</td>
	</tr>
	<tr>
		<td>DMC_EVENT_GET_MEDIA_INFO_RESULT</td>
		<td>Result of dmcGetMediaInfo()</td>
	</tr>
	<tr>
		<td>DMC_EVENT_GET_TRANSPORT_INFO_RESULT</td>
		<td>Result of dmcGetTransportInfo()</td>
	</tr>
	<tr>
		<td>DMC_EVENT_GET_POSITION_INFO_RESULT</td>
		<td>Result of dmcGetPositionInfo() and dmcRegisterPositionInfoEvent()</td>
	</tr>
	<tr>
		<td>DMC_EVENT_GET_SORT_CAPABILITIES_RESULT</td>
		<td>Result of dmcGetSortCapabilities()</td>
	</tr>
	<tr>
		<td>DMC_EVENT_GET_SEARCH_CAPABILITIES_RESULT</td>
		<td>Result of dmcGetSearchCapabilities()</td>
	</tr>
   <tr>
		<td>DMC_EVENT_DOWNLOAD_CONTROL_RESULT</td>
		<td>Result of dmcDownloadControl()</td>
	</tr>
   <tr>
		<td>DMC_EVENT_DOWNLOAD_PROGRESS</td>
		<td>Result of dmcDownloadControl()</td>
	</tr>
	<tr>
    <td>DMC_EVENT_GET_ALLOWED_PLAY_SPEED_RESULT</td>
    <td>Result of dmcGetAllowedPlaySpeed()</td>
  </tr>
</table>
*/

/* enum for DMC related core events*/
typedef enum dmcEvent_ {
  DMC_EVENT_NEW_DEVICE = 0,
  DMC_EVENT_DELETE_DEVICE,
  DMC_EVENT_DEVICE_LAST_CHANGE,
  DMC_EVENT_GET_DEVICES_RESULT,
  DMC_EVENT_GET_SERVICE_DESCRIPTION_RESULT,
  DMC_EVENT_BROWSE_DIRECTCHILDREN_RESULT,
  DMC_EVENT_BROWSE_METADATA_RESULT,
  DMC_EVENT_OBJECT_SEARCH_RESULT,
  DMC_EVENT_PLAYBACK_PREPARE_RESULT,
  DMC_EVENT_PLAYBACK_CONTROL_RESULT,
  DMC_EVENT_PLAYBACK_SEEK_RESULT, /* 10 */
  DMC_EVENT_VOLUME_CONTROL_RESULT,
  DMC_EVENT_GET_MEDIA_INFO_RESULT,
  DMC_EVENT_GET_TRANSPORT_INFO_RESULT,
  DMC_EVENT_GET_POSITION_INFO_RESULT,
  DMC_EVENT_GET_SORT_CAPABILITIES_RESULT,
  DMC_EVENT_GET_SEARCH_CAPABILITIES_RESULT,
  DMC_EVENT_SYSTEM_UPDATE_ID,
  DMC_EVENT_CONTAINER_UPDATE_IDS,
  DMC_EVENT_DOWNLOAD_CONTROL_RESULT,
  DMC_EVENT_DOWNLOAD_PROGRESS, /* 20 */
  DMC_EVENT_OBJECT_CONTROL_RESULT,
  DMC_EVENT_UPLOAD_CONTROL_RESULT,
  DMC_EVENT_UPLOAD_PROGRESS,
  DMC_EVENT_UPLOAD_FINISHED,
  DMC_EVENT_GET_ALLOWED_PLAY_SPEED_RESULT,
  DMC_EVENT_PRINT_GET_MEDIA_LIST_RESULT,
  DMC_EVENT_PRINT_GET_PRINTER_ATTRIB_RESULT,
  DMC_EVENT_PRINT_CANCEL_JOB_RESULT,
  DMC_EVENT_PRINT_FILE_RESULT,
  DMC_EVENT_PRINT_URI_RESULT, /* 30 */
  DMC_EVENT_PRINTER_STATE,
  DMC_EVENT_PRINT_JOB_END_STATE,
  DMC_EVENT_PLAYBACK_MOVE_RESULT,
  DMC_EVENT_UPDATE_DEVICE,
  DMC_EVENT_PRESET_CONTROL_RESULT
} dmcEvent;

/* Callback function of application */
#ifdef WIN32
typedef void (__stdcall *dmcCallbackHandler) (void * in_arg, dmcEvent in_event, void *in_param);
#else
typedef void (*dmcCallbackHandler) (void * in_arg, dmcEvent in_event, void *in_param);
#endif

/* Initial parameter for NFLC dmc core initialization */
struct dmcInitParams {
  slim_char *configDirectory;  //Configuration file path
  dmcCallbackHandler callback;  //Callback function to inform application layer
  void *callbackArg; //Argument specified by application layer that is used to call callback function
#ifdef ENABLE_WEBSOCKETINTERFACE
  slim_bool enableWebInterface;
  slim_char *webInterfaceDirectory;
  slim_int webInterfacePort;
#endif /* ENABLE_WEBSOCKETINTERFACE */
};

typedef struct dmcInitParams dmcInitParams_t;

/* Function Declarations */

dmcInstance_t dmcInitialize(dmcInitParams_t *in_params);

void dmcFinalize(dmcInstance_t in_instance);

void dmcDiscoverDevices(dmcInstance_t in_instance);

returnValue
dmcGetDevices(dmcInstance_t in_instance);

returnValue
dmcRegisterGenaEvents(dmcInstance_t in_instance, slim_char *in_deviceUUID);

returnValue
dmcUnRegisterGenaEvents(dmcInstance_t in_instance, slim_char *in_deviceUUID);

returnValue
dmcGetServiceDescription(dmcInstance_t in_instance, slim_char *in_deviceUUID, slim_char
                                       *in_serviceID);

returnValue
dmcBrowseDirectChildren(dmcInstance_t in_instance, slim_char *in_deviceUUID, slim_char
                                      *in_containerID, slim_int in_startIndex, slim_int in_requestedCount, slim_char *in_sortCriteria , slim_char
                                      *in_filterCriteria);


returnValue
dmcBrowseMetadata(dmcInstance_t in_instance, slim_char *in_deviceUUID, slim_char *in_objectID,
                    contentClass in_ContentType, slim_char *in_filterCriteria);


returnValue
dmcObjectSearch(dmcInstance_t in_instance, slim_char *in_deviceUUID, slim_char
                              *in_searchCriteria, slim_int in_startIndex, slim_int in_requestedCount, slim_char *in_sortCriteria ,
                               slim_char *in_filterCriteria);

returnValue
dmcGetSortCapabilities(dmcInstance_t in_instance, slim_char *in_deviceUUID);

returnValue
dmcGetSearchCapabilities(dmcInstance_t in_instance, slim_char *in_deviceUUID);

returnValue
dmcPlaybackPrepare(dmcInstance_t in_instance, slim_char *in_dmrDeviceUUIDs,
                   slim_char *in_objectDescription, slim_char *in_url, slim_bool in_next);

returnValue
dmcPlaybackControl(dmcInstance_t in_instance, slim_char *in_deviceUUIDs,
                                 dmcPlayControlCommand in_command, slim_char *in_playSpeed);

returnValue
dmcPlaybackTimeSeek(dmcInstance_t in_instance, slim_char *in_deviceUUIDs, slim_int
                                  in_seekValue);

returnValue
dmcListPresets(dmcInstance_t in_instance, slim_char *in_deviceUUIDs);

returnValue
dmcSelectPreset(dmcInstance_t in_instance, slim_char *in_deviceUUIDs, slim_char *in_preset);

returnValue
dmcVolumeControl(dmcInstance_t in_instance, slim_char *in_deviceUUIDs,
                               dmcVolumeControlCommand in_command, slim_char *in_channel, slim_int in_value);

returnValue
dmcGetMediaInfo(dmcInstance_t in_instance, slim_char *in_deviceUUID);

returnValue
dmcGetTransportInfo(dmcInstance_t in_instance, slim_char *in_deviceUUID);

returnValue
dmcGetPositionInfo(dmcInstance_t in_instance, slim_char *in_deviceUUID);

returnValue
dmcRegisterPositionInfoEvent(dmcInstance_t in_instance, slim_char *in_deviceUUID,
                                           slim_int in_interval);
returnValue
dmcUnRegisterPositionInfoEvent(dmcInstance_t in_instance, slim_char *in_deviceUUID);

returnValue
dmcUploadControl(dmcInstance_t in_instance, dmcFileTransferControlCommand in_command, slim_char *in_deviceUUID,
                  slim_char *in_containerID, slim_char *in_sourcePath);

returnValue
dmcDownloadControl(dmcInstance_t in_instance, dmcFileTransferControlCommand in_command, slim_char *in_objectDescription, slim_char *in_url,
                                  slim_char *in_destinationPath);

returnValue
dmcObjectControl(dmcInstance_t in_instance, dmcObjectControlCommand in_command, slim_char *in_deviceUUID,
                                  slim_char *in_contentID, slim_char *in_containerName);

returnValue
dmcGetAllowedPlaySpeed(dmcInstance_t in_instance, slim_char *in_deviceUUID, dmcPlaySpeedListType in_playSpeedType, slim_char *out_playSpeed, slim_int *inout_len);

returnValue
dmcPlaybackMoveContent(dmcInstance_t in_instance, slim_char *in_sourceDmrDeviceUUID,
    slim_char *in_destinationDmrDeviceUUID);

#ifdef ENABLE_PRINTER_SUPPORT
returnValue
dmcPrintUri(dmcInstance_t in_instance, slim_char *in_dmprDeviceUUID,
    slim_char *in_objectDescription, slim_char *in_url, slim_char *in_printParam);

returnValue
dmcPrintFile(dmcInstance_t in_instance, slim_char *in_dmprDeviceUUID,
    slim_char *in_filePath, slim_char *in_printParam);

returnValue
dmcPrintCancelJob(dmcInstance_t in_instance, slim_char *in_dmrpDeviceUUID, slim_int in_jobId);

returnValue
dmcPrintGetMediaList(dmcInstance_t in_instance, slim_char *in_dmprDeviceUUID);

returnValue
dmcPrintGetPrinterAttributes(dmcInstance_t in_instance, slim_char *in_dmprDeviceUUID);
#endif /* ENABLE_PRINTER_SUPPORT */

#ifdef ENABLE_WEBSOCKETINTERFACE
slim_int
webinterface_sendMessageUpdateDevice(webinterfaceInstance_t *in_instance, slim_char *in_eventName, XMLBuffer in_deviceDescription, slim_char *in_baseURL);

slim_int
webinterface_sendMessageRemoveDevice(webinterfaceInstance_t *in_instance, slim_char *in_uuid);

slim_int
webinterface_sendMessageGetDevicesResult(webinterfaceInstance_t *in_instance, XMLBuffer in_deviceDescription);

#endif /* ENABLE_WEBSOCKETINTERFACE */

#ifdef DEVELOPMENT_DIRECT_DLNA_OBJECT
returnValue
dmcDirectPlayLocalFile(dmcInstance_t in_instance, slim_char *in_dmrDeviceUUIDs, slim_char *in_filePath, slim_char *in_title, slim_char **out_url);

returnValue
dmcDirectPlayRemoteOnlineFile(dmcInstance_t in_instance, slim_char *in_dmrDeviceUUIDs, slim_char *in_url,  slim_char *in_mimeType, slim_char *in_title, XMLBuffer in_itemInfo);
#endif /* DEVELOPMENT_DIRECT_DLNA_OBJECT */

returnValue
dmcGetCoreInfo(dmcInstance_t in_instance, XMLBuffer *out_info);

void
dmcNotify(dmcInstance_t in_instance, notifyEvent in_event, XMLBuffer in_param);

#endif /* DMC_AHL_H*/
