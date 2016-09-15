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

 
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the DMSLIBRARY_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// DMSLIBRARY_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

#include "dmswrapper.hpp"

#ifdef DMSLIBRARY_EXPORTS
#define DMSLIBRARY_API __declspec(dllexport)
#else
#define DMSLIBRARY_API __declspec(dllimport)
#endif

DMSLIBRARY_API DMSWrapper* CreateDMSWrapperClass();
DMSLIBRARY_API void DeleteDMSWrapperClass(DMSWrapper* inObject);
DMSLIBRARY_API bool AHLdmsInitialize(DMSWrapper* inObject, dmsInitParams_t *in_params);
DMSLIBRARY_API returnValue AHLdmsStart(DMSWrapper* inObject);
DMSLIBRARY_API returnValue AHLdmsStop(DMSWrapper* inObject);
DMSLIBRARY_API bool AHLdmsFinalize(DMSWrapper* inObject);
DMSLIBRARY_API wchar_t* AHLdmsGetFriendlyName(DMSWrapper* inObject);
DMSLIBRARY_API returnValue  AHLdmsSetFriendlyName(DMSWrapper* inObject, wchar_t *in_friendlyName);
DMSLIBRARY_API returnValue AHLdmsPublishStorageAdd(DMSWrapper* inObject, wchar_t *in_path, wchar_t *in_share_name, wchar_t *in_id, dmsStorageDatabaseLocationType in_location_type, slim_bool in_auto_index);
DMSLIBRARY_API returnValue AHLdmsPublishStorageRemove(DMSWrapper* inObject, wchar_t *in_path);
DMSLIBRARY_API returnValue AHLdmsPublishStorageUpdate(DMSWrapper* inObject, wchar_t *in_path);
DMSLIBRARY_API returnValue AHLdmsPublishStorageSetDefaultUploadFolder(DMSWrapper* inObject, wchar_t *in_path);
DMSLIBRARY_API wchar_t* AHLdmsPublishStorageGetDefaultUploadFolder(DMSWrapper* inObject, wchar_t *out_path);
DMSLIBRARY_API returnValue AHLdmsGetPublishStoragesCount(DMSWrapper* inObject, slim_int *out_count);
DMSLIBRARY_API returnValue AHLdmsPublishStorageSetStorageCentralDir(DMSWrapper* inObject, wchar_t *in_config_path);
DMSLIBRARY_API wchar_t* AHLdmsGetPublishStorages(DMSWrapper* inObject, XMLBuffer out_storages);
DMSLIBRARY_API returnValue AHLdmsGetServerState(DMSWrapper* inObject, dmsState *out_server_state);
DMSLIBRARY_API returnValue AHLdmsSetServerState(DMSWrapper* inObject, dmsState in_server_state);

DMSLIBRARY_API returnValue AHLdmsGetTotalContentsShared(DMSWrapper* inObject, dmsContentClassType in_type, slim_int *out_result);
DMSLIBRARY_API wchar_t* AHLdmsGetDeviceDescription(DMSWrapper* inObject, XMLBuffer out_deviceDescription);
DMSLIBRARY_API returnValue AHLdmsRefreshContentIndex(DMSWrapper* inObject);
DMSLIBRARY_API wchar_t* AHLdmsGetContentTree(DMSWrapper* inObject, wchar_t *in_containerID, slim_int in_startIndex, slim_int in_requestedCount, XMLBuffer out_buf);
DMSLIBRARY_API returnValue AHLdmsSetContentShare(DMSWrapper* inObject, wchar_t *in_contentID, slim_bool in_share, slim_bool in_recusive);
DMSLIBRARY_API wchar_t* AHLdmsGetSupportedLanguages(DMSWrapper* inObject, XMLBuffer out_languages);
DMSLIBRARY_API returnValue AHLdmsSetLanguage(DMSWrapper* inObject, slim_char* in_language);
DMSLIBRARY_API wchar_t* AHLdmsGetSelectedLanguage(DMSWrapper* inObject, XMLBuffer out_language);
DMSLIBRARY_API wchar_t* AHLdmsBrowseContent(DMSWrapper* inObject, wchar_t* in_id, XMLBuffer *out_response_doc, slim_word start_index, slim_word request_count);
DMSLIBRARY_API wchar_t* AHLdmsSearchContent(DMSWrapper* inObject, wchar_t* in_id, wchar_t *criteria, XMLBuffer out_response_doc, slim_word start_index, slim_word request_count);

DMSLIBRARY_API returnValue AHLdmsPGGetDefaultLevel(DMSWrapper* inObject, dmsPGLevelType in_levelType, slim_int *out_level);
DMSLIBRARY_API returnValue AHLdmsPGSetDefaultDeviceLevel(DMSWrapper* inObject, dmsPGLevelType in_levelType, slim_int in_newDefaultLevel);
DMSLIBRARY_API returnValue AHLdmsPGSetContentLevel(DMSWrapper* inObject, wchar_t *in_contentID, slim_int in_level);
DMSLIBRARY_API wchar_t* AHLdmsPGGetLevelList(DMSWrapper* inObject, XMLBuffer out_PGLevelList);
DMSLIBRARY_API wchar_t* AHLdmsPGGetDeviceList(DMSWrapper* inObject, XMLBuffer out_PGDeviceList);
DMSLIBRARY_API returnValue AHLdmsPGSetDeviceParams(DMSWrapper* inObject, wchar_t *in_deviceMAC, slim_int in_level, wchar_t *in_description);
DMSLIBRARY_API returnValue AHLdmsPGDeleteDeviceByMac(DMSWrapper* inObject, wchar_t *in_deviceMAC);
DMSLIBRARY_API wchar_t* ConvertAnsiToUTF8(slim_char *pLibData);
DMSLIBRARY_API slim_char* ConvertUTF8ToAnsi(wchar_t* pExternalData);

DMSLIBRARY_API returnValue AHLdmsCASetDefaultIndexing(DMSWrapper* inObject, dmsCAIndex in_index);
DMSLIBRARY_API returnValue AHLdmsCAGetDefaultIndexing(DMSWrapper* inObject, dmsCAIndex *out_index);
DMSLIBRARY_API returnValue AHLdmsCAGetDeviceList(DMSWrapper* inObject, XMLBuffer *out_CADeviceList);
DMSLIBRARY_API returnValue AHLdmsCASetDeviceIndexing(DMSWrapper* inObject, slim_char *in_uuid, dmsCAIndex in_index);
DMSLIBRARY_API returnValue AHLdmsCASetDatabaseSizeLimit(DMSWrapper* inObject, slim_int in_size);
DMSLIBRARY_API returnValue AHLdmsCAGetDatabaseSizeLimit(DMSWrapper* inObject, slim_int *out_size);
DMSLIBRARY_API returnValue AHLdmsCASetPurgeInterval(DMSWrapper* inObject, slim_int in_interval);
DMSLIBRARY_API returnValue AHLdmsCAGetPurgeInterval(DMSWrapper* inObject, slim_int *out_interval);
DMSLIBRARY_API returnValue AHLdmsCASetRescanInterval(DMSWrapper* inObject, slim_int in_interval);
DMSLIBRARY_API returnValue AHLdmsCAGetRescanInterval(DMSWrapper* inObject, slim_int *out_interval);
DMSLIBRARY_API returnValue AHLdmsCASetEnabled(DMSWrapper* inObject, slim_bool in_enable);
DMSLIBRARY_API returnValue AHLdmsCAIsEnabled(DMSWrapper* inObject, slim_bool *out_enabled);
DMSLIBRARY_API returnValue AHLdmsCASetDBLocation(DMSWrapper* inObject, wchar_t *in_databaseLocation);
DMSLIBRARY_API wchar_t* AHLdmsCAGetDBLocation(DMSWrapper* inObject);
DMSLIBRARY_API returnValue AHLdmsCASetDBSelectionMode(DMSWrapper* inObject, dmsCADatabaseSelectionMode in_mode);
DMSLIBRARY_API returnValue AHLdmsCAGetDBSelectionMode(DMSWrapper* inObject, dmsCADatabaseSelectionMode *out_mode);
DMSLIBRARY_API returnValue AHLdmsCAExecuteCommand(DMSWrapper* inObject, dmsCACommand in_cmd);
DMSLIBRARY_API returnValue AHLdmsCAGetState(DMSWrapper* inObject, dmsCAState *out_state);

