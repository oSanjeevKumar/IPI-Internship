/*
* Copyright (C) 2015-2016 ACCESS CO.,LTD.
* All rights are reserved by ACCESS CO.,LTD.,
* whether the whole or part of the source code
* including any modifications is concerned.
*
* This is an unpublished source code of ACCESS CO.,LTD., and must be
* treated as confidential material.  The above copyright notice does
* not evidence any actual or intended publication of this source code.
*/
namespace dmsdllbridge{
  extern "C" DllExport DMSWrapper* CreateDMSWrapperClass();
  extern "C" DllExport void DeleteDMSWrapperClass(DMSWrapper* inObject);
  extern "C" DllExport bool AHLdmsInitialize(DMSWrapper* inObject, dmsInitParams_t *in_params);
  extern "C" DllExport returnValue AHLdmsStart(DMSWrapper* inObject);
  extern "C" DllExport void AHLdmsFinalize(DMSWrapper* inObject);
  extern "C" DllExport returnValue AHLdmsStop(DMSWrapper* inObject);
  extern "C" DllExport slim_char* AHLdmsGetFriendlyName(DMSWrapper* inObject);
  extern "C" DllExport returnValue AHLdmsSetFriendlyName(DMSWrapper* inObject, slim_char *in_friendlyName);
  extern "C" DllExport returnValue AHLdmsPublishStorageAdd(DMSWrapper* inObject, slim_char *in_path, slim_char *in_share_name, slim_char *in_id, dmsStorageDatabaseLocationType in_location_type,
                                                            slim_bool in_auto_index);
  extern "C" DllExport returnValue AHLdmsPublishStorageRemove(DMSWrapper* inObject, slim_char *in_path);
  extern "C" DllExport returnValue AHLdmsPublishStorageUpdate(DMSWrapper* inObject, slim_char *in_path);
  extern "C" DllExport returnValue AHLdmsPublishStorageSetDefaultUploadFolder(DMSWrapper* inObject, slim_char *in_path);
  extern "C" DllExport returnValue AHLdmsPublishStorageGetDefaultUploadFolder(DMSWrapper* inObject, const slim_char **const out_path);
  extern "C" DllExport returnValue AHLdmsGetPublishStoragesCount(DMSWrapper* inObject, slim_int *out_count);
  extern "C" DllExport returnValue AHLdmsPublishStorageSetStorageCentralDir(DMSWrapper* inObject, slim_char *in_config_path);
  extern "C" DllExport returnValue AHLdmsGetPublishStorages(DMSWrapper* inObject, XMLBuffer *out_storages);
  extern "C" DllExport returnValue AHLdmsGetServerState(DMSWrapper* inObject, dmsState *out_server_state);
  extern "C" DllExport returnValue AHLdmsSetServerState(DMSWrapper* inObject, dmsState in_server_state);
  extern "C" DllExport returnValue AHLdmsGetTotalContentsShared(DMSWrapper* inObject, dmsContentClassType in_type, slim_int *out_result);
  extern "C" DllExport returnValue AHLdmsGetDeviceDescription(DMSWrapper* inObject, XMLBuffer *out_deviceDescription);
  extern "C" DllExport returnValue AHLdmsRefreshContentIndex(DMSWrapper* inObject);
  extern "C" DllExport returnValue AHLdmsGetContentTree(DMSWrapper* inObject, slim_char *in_containerID, slim_int in_startIndex, slim_int in_requestedCount, XMLBuffer *out_buf);
  extern "C" DllExport returnValue AHLdmsSetContentShare(DMSWrapper* inObject, slim_char *in_contentID, slim_bool in_share, slim_bool in_recusive);
  extern "C" DllExport returnValue AHLdmsGetSupportedLanguages(DMSWrapper* inObject, XMLBuffer *out_languages);
  extern "C" DllExport returnValue AHLdmsSetLanguage(DMSWrapper* inObject, const slim_char* in_language);
  extern "C" DllExport returnValue AHLdmsSetLanguage(DMSWrapper* inObject, const slim_char* in_language);
  extern "C" DllExport returnValue AHLdmsBrowseContent(DMSWrapper* inObject, slim_char* in_id, XMLBuffer *out_response_doc, slim_word start_index, slim_word request_count);
  extern "C" DllExport returnValue AHLdmsSearchContent(DMSWrapper* inObject, slim_char* in_id, slim_char *criteria, XMLBuffer *out_response_doc, slim_word start_index, slim_word request_count);
  extern "C" DllExport returnValue AHLdmsGetCoreInfo(DMSWrapper* inObject, XMLBuffer *out_info);
  extern "C" DllExport void AHLdmsNotify(DMSWrapper* inObject, notifyEvent in_event, XMLBuffer in_param);

#ifdef ENABLE_PARENTAL_GUIDANCE	
  extern "C" DllExport returnValue AHLdmsPGGetDefaultLevel(DMSWrapper* inObject, dmsPGLevelType in_levelType, slim_int *out_level);
  extern "C" DllExport returnValue AHLdmsPGSetDefaultLevel(DMSWrapper* inObject, dmsPGLevelType in_levelType, slim_int in_newDefaultLevel);
  extern "C" DllExport returnValue AHLdmsPGSetContentLevel(DMSWrapper* inObject, slim_char *in_contentID, slim_int in_level);
  extern "C" DllExport returnValue AHLdmsPGGetDeviceList(DMSWrapper* inObject, XMLBuffer *out_PGDeviceList);
  extern "C" DllExport returnValue AHLdmsPGGetLevelList(DMSWrapper* inObject, XMLBuffer *out_PGLevelList);
  extern "C" DllExport returnValue AHLdmsPGSetDeviceParams(DMSWrapper* inObject, slim_char *in_deviceMAC, slim_int *in_level, slim_char *in_description);
  extern "C" DllExport returnValue AHLdmsPGDeleteDeviceByMac(DMSWrapper* inObject, slim_char *in_deviceMAC);
#endif //ENABLE_PARENTAL_GUIDANCE

#ifdef DEVELOPMENT_CONTENT_AGGREGATION
  extern "C" DllExport returnValue AHLdmsCASetDefaultIndexing(DMSWrapper* inObject, dmsCAIndex in_index);
  extern "C" DllExport returnValue AHLdmsCAGetDefaultIndexing(DMSWrapper* inObject, dmsCAIndex *out_index);
  extern "C" DllExport returnValue AHLdmsCAGetDeviceList(DMSWrapper* inObject, XMLBuffer *out_CADeviceList);
  extern "C" DllExport returnValue AHLdmsCASetDeviceIndexing(DMSWrapper* inObject, slim_char *in_uuid, dmsCAIndex in_index);
  extern "C" DllExport returnValue AHLdmsCASetDatabaseSizeLimit(DMSWrapper* inObject, slim_int in_size);
  extern "C" DllExport returnValue AHLdmsCAGetDatabaseSizeLimit(DMSWrapper* inObject, slim_int *out_size);
  extern "C" DllExport returnValue AHLdmsCASetPurgeInterval(DMSWrapper* inObject, slim_int in_interval);
  extern "C" DllExport returnValue AHLdmsCAGetPurgeInterval(DMSWrapper* inObject, slim_int *out_interval);
  extern "C" DllExport returnValue AHLdmsCASetRescanInterval(DMSWrapper* inObject, slim_int in_interval);
  extern "C" DllExport returnValue AHLdmsCAGetRescanInterval(DMSWrapper* inObject, slim_int *out_interval);
  extern "C" DllExport returnValue AHLdmsCASetEnabled(DMSWrapper* inObject, slim_bool in_enable);
  extern "C" DllExport returnValue AHLdmsCAIsEnabled(DMSWrapper* inObject, slim_bool *out_enabled);
  extern "C" DllExport returnValue AHLdmsCASetDBLocation(DMSWrapper* inObject, slim_char *in_databaseLocation);
  extern "C" DllExport slim_char* AHLdmsCAGetDBLocation(DMSWrapper* inObject);
  extern "C" DllExport returnValue AHLdmsCASetDBSelectionMode(DMSWrapper* inObject, dmsCADatabaseSelectionMode in_mode);
  extern "C" DllExport returnValue AHLdmsCAGetDBSelectionMode(DMSWrapper* inObject, dmsCADatabaseSelectionMode *out_mode);
  extern "C" DllExport returnValue AHLdmsCAExecuteCommand(DMSWrapper* inObject, dmsCACommand in_cmd);
  extern "C" DllExport returnValue AHLdmsCAGetState(DMSWrapper* inObject, dmsCAState *out_state);
#endif //DEVELOPMENT_CONTENT_AGGREGATION
}