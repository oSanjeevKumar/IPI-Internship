/*
* dms_ahl.h
* Copyright (C) 2015 ACCESS CO.,LTD.
* All rights are reserved by ACCESS CO.,LTD.,
* whether the whole or part of the source code
* including any modifications is concerned.
*
* This is an unpublished source code of ACCESS CO.,LTD., and must be
* treated as confidential material.  The above copyright notice does
* not evidence any actual or intended publication of this source code.
*/

#ifndef DMS_AHL_H
#define DMS_AHL_H

#include <ahl.h>
#include <dms_api.h>
#include <dms_publish_storage_api.h>

/* dmsInstance_t is the instance of the library */
typedef void *dmsInstance_t;

/* Generic Callback function of application */
#ifdef WIN32
typedef void (__stdcall *dmsCallbackHandler) (void * in_arg, dmsEvent in_event, void *in_param);
#else
typedef void(*dmsCallbackHandler) (void * in_arg, dmsEvent in_event, void *in_param);
#endif

/* Initial parameter for NFLC dms core initialization */
struct dmsInitParams {
  slim_char *dmsDataDirectory; // Path of Data directory of DMS
  slim_char *configDirectory;  // Configuration file path of xml files.
  slim_half upnpPort;          // DMS UPnP Server Port Number
  dmsCallbackHandler callback; // Callback function to inform application layer
  slim_int callbackCategory;   // Bitwise OR-ed of dmsEvent to register state update
  void *callbackArg;           // Argument specified by application layer that is used to call callback function
#ifdef ENABLE_WEBSOCKETINTERFACE
  slim_bool enableWebInterface;
  slim_int webInterfacePort;
  slim_char *webInterfaceDirectory;
#endif /* ENABLE_WEBSOCKETINTERFACE */
};

typedef struct dmsInitParams dmsInitParams_t;

typedef enum dmsStorageDatabaseLocationType_ {
  DMS_STORAGE_DATABASE_LOCATION_TYPE_LOCAL,  //storage database created locally in the storage root folder
  DMS_STORAGE_DATABASE_LOCATION_TYPE_CENTRAL //storage database created centrally in the storage root folder
} dmsStorageDatabaseLocationType;

typedef enum dmsPGLevelType_ {
  DMS_PG_LEVEL_TYPE_DEVICE, //PG level of device
  DMS_PG_LEVEL_TYPE_CONTENT //PG level of content
} dmsPGLevelType;

typedef enum contentUpdateEvent_ {
    CONTENT_UPDATE_EVENT_REFRESH = 0,
    CONTENT_UPDATE_EVENT_DELETE,
    CONTENT_UPDATE_EVENT_NONE
} contentUpdateEvent;

typedef enum dmsUploadFolderSelectionMode_ {
  DMS_UPLOAD_FOLDER_SELECTION_MODE_AUTO = 0,
  DMS_UPLOAD_FOLDER_SELECTION_MODE_MANUAL,
} dmsUploadFolderSelectionMode;

/* Prototypes.  */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Function Declarations */

dmsInstance_t dmsInitialize(dmsInitParams_t *in_params);

void 
dmsFinalize(dmsInstance_t in_instance);

returnValue
dmsStart(dmsInstance_t in_instance);

returnValue
dmsStop(dmsInstance_t in_instance);

slim_char*
dmsGetFriendlyName(dmsInstance_t in_instance);

returnValue 
dmsSetFriendlyName(dmsInstance_t in_instance, slim_char *in_friendlyName);

returnValue 
dmsPublishStorageAdd(dmsInstance_t in_instance, slim_char *in_path, slim_char *in_share_name, slim_char *in_id, dmsStorageDatabaseLocationType in_location_type,
                            slim_bool in_auto_index);
returnValue 
dmsPublishStorageRemove(dmsInstance_t in_instance, slim_char *in_path);

returnValue 
dmsPublishStorageUpdate(dmsInstance_t in_instance, slim_char *in_path);

returnValue 
dmsPublishStorageSetDefaultUploadFolder(dmsInstance_t in_instance, slim_char *in_path);

returnValue 
dmsPublishStorageGetDefaultUploadFolder(dmsInstance_t in_instance, const slim_char **const out_path);

returnValue
dmsPublishStorageSetUploadFolderSelectionMode(dmsInstance_t in_instance, dmsUploadFolderSelectionMode in_mode);

returnValue
dmsPublishStorageGetUploadFolderSelectionMode(dmsInstance_t in_instance, dmsUploadFolderSelectionMode *out_mode);

returnValue
dmsGetPublishStoragesCount(dmsInstance_t in_instance, slim_int *out_count);

returnValue 
dmsPublishStorageSetStorageCentralDir(dmsInstance_t in_instance, slim_char *in_config_path);

returnValue 
dmsGetPublishStorages(dmsInstance_t in_instance, XMLBuffer *out_storages);

returnValue
dmsGetServerState(dmsInstance_t in_instance, dmsState *out_server_state);

returnValue 
dmsSetServerState(dmsInstance_t in_instance, dmsState in_server_state);

returnValue 
dmsGetTotalContentsShared(dmsInstance_t in_instance, dmsContentClassType in_type, slim_int *out_result);

returnValue 
dmsGetDeviceDescription(dmsInstance_t in_instance,   XMLBuffer *out_deviceDescription);

returnValue 
dmsRefreshContentIndex(dmsInstance_t in_instance);

returnValue 
dmsGetContentTree(dmsInstance_t in_instance, slim_char *in_containerID, slim_int in_startIndex, slim_int in_requestedCount, XMLBuffer *out_buf);

returnValue 
dmsSetContentShare(dmsInstance_t in_instance, slim_char *in_contentID, slim_bool in_share, slim_bool in_recusive);

returnValue 
dmsGetSupportedLanguages(dmsInstance_t in_instance, XMLBuffer *out_languages);

returnValue 
dmsSetLanguage(dmsInstance_t in_instance, const slim_char *in_language);
	
returnValue  
dmsGetSelectedLanguage(dmsInstance_t in_instance, slim_char **out_language);

returnValue
dmsGetStreamingSessionsLimit(dmsInstance_t in_instance, slim_int *out_session_count);

returnValue
dmsSetStreamingSessionsLimit(dmsInstance_t in_instance, slim_int in_session_count);

returnValue
dmsBrowseContent(dmsInstance_t in_instance, slim_char* in_id, XMLBuffer *out_response_doc, slim_word start_index, slim_word request_count);

returnValue
dmsSearchContent(dmsInstance_t in_instance, slim_char* in_id, slim_char *criteria, XMLBuffer *out_response_doc, slim_word start_index, slim_word request_count);

#ifdef ENABLE_PARENTAL_GUIDANCE
returnValue 
dmsPGGetDefaultLevel(dmsInstance_t in_instance, dmsPGLevelType in_levelType, slim_int *out_level);

returnValue 
dmsPGSetDefaultLevel(dmsInstance_t in_instance, dmsPGLevelType in_levelType, slim_int in_newDefaultLevel);

returnValue 
dmsPGSetContentLevel(dmsInstance_t in_instance, slim_char *in_contentID, slim_int in_level);

returnValue 
dmsPGGetDeviceList(dmsInstance_t in_instance,  XMLBuffer *out_PGDeviceList);

returnValue 
dmsPGGetLevelList(dmsInstance_t in_instance,  XMLBuffer *out_PGLevelList); 

returnValue 
dmsPGSetDeviceParams(dmsInstance_t in_instance, slim_char *in_deviceMAC, slim_int *in_level, slim_char *in_description);

returnValue 
dmsPGDeleteDeviceByMac(dmsInstance_t in_instance, slim_char *in_deviceMAC); 
#endif //ENABLE_PARENTAL_GUIDANCE

#ifdef DEVELOPMENT_CONTENT_AGGREGATION
returnValue
dmsCASetEnabled(dmsInstance_t in_instance, slim_bool in_enable);

returnValue
dmsCAIsEnabled(dmsInstance_t in_instance, slim_bool *out_enabled);

returnValue
dmsCASetDatabaseSelectionMode(dmsInstance_t in_instance, dmsCADatabaseSelectionMode in_mode);

returnValue
dmsCAGetDatabaseSelectionMode(dmsInstance_t in_instance, dmsCADatabaseSelectionMode *out_mode);

returnValue
dmsCASetDatabaseLocation(dmsInstance_t in_instance, slim_char *in_databaseLocation);

slim_char *
dmsCAGetDatabaseLocation(dmsInstance_t in_instance);

returnValue
dmsCASetDefaultIndexing(dmsInstance_t in_instance, dmsCAIndex in_index);

returnValue
dmsCAGetDefaultIndexing(dmsInstance_t in_instance, dmsCAIndex *out_index);

returnValue
dmsCAGetDeviceList(dmsInstance_t in_instance, XMLBuffer *out_CADeviceList);

returnValue
dmsCASetDeviceIndexing(dmsInstance_t in_instance, slim_char *in_uuid, dmsCAIndex in_index);

returnValue
dmsCASetDatabaseSizeLimit(dmsInstance_t in_instance, slim_int in_size);

returnValue
dmsCAGetDatabaseSizeLimit(dmsInstance_t in_instance, slim_int *out_size);

returnValue
dmsCASetPurgeTime(dmsInstance_t in_instance, slim_int in_time);

returnValue
dmsCAGetPurgeTime(dmsInstance_t in_instance, slim_int *out_time);

returnValue
dmsCASetRescanInterval(dmsInstance_t in_instance, slim_int in_interval);

returnValue
dmsCAGetRescanInterval(dmsInstance_t in_instance, slim_int *out_interval);

returnValue
dmsCAExecuteCommand(dmsInstance_t in_instance, dmsCACommand in_cmd);

returnValue
dmsCAGetState(dmsInstance_t in_instance, dmsCAState *out_state);
#endif /* DEVELOPMENT_CONTENT_AGGREGATION */

returnValue
dmsGetCoreInfo(dmsInstance_t in_instance, XMLBuffer *out_info);

void
dmsNotify(dmsInstance_t in_instance, notifyEvent in_event, XMLBuffer in_param);

returnValue
dmsContentUpdate(dmsInstance_t in_instance, contentUpdateEvent in_event, slim_char *in_path);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* DMS_AHL_H*/
