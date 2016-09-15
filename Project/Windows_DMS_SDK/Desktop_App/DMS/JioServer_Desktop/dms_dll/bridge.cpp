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

#include "dmswrapper.hpp"
#include "bridge.hpp"
#include <iostream>

namespace dmsdllbridge
{

  extern "C" DllExport DMSWrapper* CreateDMSWrapperClass()
  {
    return new DMSWrapper();
  }

  extern "C" DllExport void DeleteDMSWrapperClass(DMSWrapper* inObject)
  {
    if (inObject != NULL){
      delete inObject;
      inObject = NULL;
    }
  }

  extern "C" DllExport bool AHLdmsInitialize(DMSWrapper* inObject, dmsInitParams_t *in_params)
  {
    bool ret = false;
    if (inObject != NULL) {
      ret = inObject->dmsInitialize(in_params);
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsStart(DMSWrapper* inObject)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsStart();
    }
    return ret;
  }

  extern "C" DllExport void AHLdmsFinalize(DMSWrapper* inObject)
  {
    if (inObject != NULL) {
      inObject->dmsFinalize();
    }
  }

  extern "C" DllExport returnValue AHLdmsStop(DMSWrapper* inObject)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsStop();
    }
    return ret;
  }

  extern "C" DllExport slim_char* AHLdmsGetFriendlyName(DMSWrapper* inObject)
  {
    slim_char* readOnlynameFromCore = slim_nil;
    slim_char * tempName = slim_nil;
    if (inObject != NULL) {
      readOnlynameFromCore = inObject->dmsGetFriendlyName();
      if (readOnlynameFromCore) {
        tempName = dlna_strdup(readOnlynameFromCore);
      }
    }
    return tempName;
  }

  extern "C" DllExport returnValue AHLdmsSetFriendlyName(DMSWrapper* inObject, slim_char *in_friendlyName)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsSetFriendlyName(in_friendlyName);;
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsPublishStorageAdd(DMSWrapper* inObject, slim_char *in_path, slim_char *in_share_name, slim_char *in_id, dmsStorageDatabaseLocationType in_location_type,
                          slim_bool in_auto_index)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsPublishStorageAdd(in_path, in_share_name, in_id, in_location_type, in_auto_index);
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsPublishStorageRemove(DMSWrapper* inObject, slim_char *in_path)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsPublishStorageRemove(in_path);
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsPublishStorageUpdate(DMSWrapper* inObject, slim_char *in_path)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsPublishStorageUpdate(in_path);
    }
    return ret;
  }
	
  extern "C" DllExport returnValue AHLdmsPublishStorageSetDefaultUploadFolder(DMSWrapper* inObject, slim_char *in_path)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsPublishStorageSetDefaultUploadFolder(in_path);
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsPublishStorageGetDefaultUploadFolder(DMSWrapper* inObject, const slim_char **const out_path)
  {
    returnValue ret = NFLC_E_ERROR;
    slim_char *returnUploadFolderPath = slim_nil;
    if (inObject != NULL) {
      ret = inObject->dmsPublishStorageGetDefaultUploadFolder(out_path);
      if (*out_path){
        returnUploadFolderPath = dlna_strdup(*out_path);
        *out_path = returnUploadFolderPath;
      }

    }
    return ret;
  }
	
  extern "C" DllExport returnValue AHLdmsGetPublishStoragesCount(DMSWrapper* inObject, slim_int *out_count)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsGetPublishStoragesCount(out_count);
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsPublishStorageSetStorageCentralDir(DMSWrapper* inObject, slim_char *in_config_path)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsPublishStorageSetStorageCentralDir(in_config_path);
    }
    return ret;
  }


  extern "C" DllExport returnValue AHLdmsGetPublishStorages(DMSWrapper* inObject, XMLBuffer *out_storages)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsGetPublishStorages(out_storages);
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsGetServerState(DMSWrapper* inObject, dmsState *out_server_state)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsGetServerState(out_server_state);
    }
    return ret;
  }
	
  extern "C" DllExport returnValue AHLdmsSetServerState(DMSWrapper* inObject, dmsState in_server_state)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsSetServerState(in_server_state);
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsGetTotalContentsShared(DMSWrapper* inObject, dmsContentClassType in_type, slim_int *out_result)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsGetTotalContentsShared(in_type, out_result);
    }
    return ret;
  }
	
  extern "C" DllExport returnValue AHLdmsGetDeviceDescription(DMSWrapper* inObject, XMLBuffer *out_deviceDescription)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsGetDeviceDescription(out_deviceDescription);
    }
    return ret;
  }
	
  extern "C" DllExport returnValue AHLdmsRefreshContentIndex(DMSWrapper* inObject)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsRefreshContentIndex();
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsGetContentTree(DMSWrapper* inObject, slim_char *in_containerID, slim_int in_startIndex, slim_int in_requestedCount, XMLBuffer *out_buf)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsGetContentTree(in_containerID, in_startIndex, in_requestedCount, out_buf);
    }
    return ret;
  }
	
  extern "C" DllExport returnValue AHLdmsSetContentShare(DMSWrapper* inObject, slim_char *in_contentID, slim_bool in_share, slim_bool in_recusive)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsSetContentShare(in_contentID, in_share, in_recusive);
    }
    return ret;
  }
	
  extern "C" DllExport returnValue AHLdmsGetSupportedLanguages(DMSWrapper* inObject, XMLBuffer *out_languages)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsGetSupportedLanguages(out_languages);
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsSetLanguage(DMSWrapper* inObject, const slim_char* in_language)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsSetLanguage(in_language);
    }
    return ret;
  }
	
  extern "C" DllExport returnValue AHLdmsGetSelectedLanguage(DMSWrapper* inObject, slim_char **out_language)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsGetSelectedLanguage(out_language);
    }
    return ret;
  }
	
  extern "C" DllExport returnValue AHLdmsBrowseContent(DMSWrapper* inObject, slim_char* in_id, XMLBuffer *out_response_doc, slim_word start_index, slim_word request_count)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsBrowseContent(in_id, out_response_doc, start_index, request_count);
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsSearchContent(DMSWrapper* inObject, slim_char* in_id, slim_char *criteria, XMLBuffer *out_response_doc, slim_word start_index, slim_word request_count)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsSearchContent(in_id, criteria, out_response_doc, start_index, request_count);
    }
    return ret;
  }
#ifdef ENABLE_PARENTAL_GUIDANCE	
  extern "C" DllExport returnValue AHLdmsPGGetDefaultLevel(DMSWrapper* inObject, dmsPGLevelType in_levelType, slim_int *out_level)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsPGGetDefaultLevel(in_levelType, out_level);
    }
    return ret;
  }
	
  extern "C" DllExport returnValue AHLdmsPGSetDefaultLevel(DMSWrapper* inObject, dmsPGLevelType in_levelType, slim_int in_newDefaultLevel)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsPGSetDefaultLevel(in_levelType, in_newDefaultLevel);
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsPGSetContentLevel(DMSWrapper* inObject, slim_char *in_contentID, slim_int in_level)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsPGSetContentLevel(in_contentID, in_level);
    }
    return ret;
  }
	
  extern "C" DllExport returnValue AHLdmsPGGetDeviceList(DMSWrapper* inObject, XMLBuffer *out_PGDeviceList)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsPGGetDeviceList(out_PGDeviceList);
    }
    return ret;
  }
	
  extern "C" DllExport returnValue AHLdmsPGGetLevelList(DMSWrapper* inObject, XMLBuffer *out_PGLevelList)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsPGGetLevelList(out_PGLevelList);
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsPGSetDeviceParams(DMSWrapper* inObject, slim_char *in_deviceMAC, slim_int *in_level, slim_char *in_description)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsPGSetDeviceParams(in_deviceMAC, in_level, in_description);
    }
    return ret;
  }
	
  extern "C" DllExport returnValue AHLdmsPGDeleteDeviceByMac(DMSWrapper* inObject, slim_char *in_deviceMAC)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsPGDeleteDeviceByMac(in_deviceMAC);
    }
    return ret;
  }
#endif  /* ENABLE_PARENTAL_GUIDANCE */

#ifdef DEVELOPMENT_CONTENT_AGGREGATION

  extern "C" DllExport returnValue AHLdmsCASetDefaultIndexing(DMSWrapper* inObject, dmsCAIndex in_index)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsCASetDefaultIndexing(in_index);
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsCAGetDefaultIndexing(DMSWrapper* inObject, dmsCAIndex *out_index)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsCAGetDefaultIndexing(out_index);
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsCAGetDeviceList(DMSWrapper* inObject, XMLBuffer *out_CADeviceList)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsCAGetDeviceList(out_CADeviceList);
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsCASetDeviceIndexing(DMSWrapper* inObject, slim_char *in_uuid, dmsCAIndex in_index)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsCASetDeviceIndexing(in_uuid, in_index);
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsCASetDatabaseSizeLimit(DMSWrapper* inObject, slim_int in_size)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsCASetDatabaseSizeLimit(in_size);
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsCAGetDatabaseSizeLimit(DMSWrapper* inObject, slim_int *out_size)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsCAGetDatabaseSizeLimit(out_size);
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsCASetPurgeInterval(DMSWrapper* inObject, slim_int in_interval)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsCASetPurgeInterval(in_interval);
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsCAGetPurgeInterval(DMSWrapper* inObject, slim_int *out_interval)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsCAGetPurgeInterval(out_interval);
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsCASetRescanInterval(DMSWrapper* inObject, slim_int in_interval)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsCASetRescanInterval(in_interval);
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsCAGetRescanInterval(DMSWrapper* inObject, slim_int *out_interval)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsCAGetRescanInterval(out_interval);
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsCASetEnabled(DMSWrapper* inObject, slim_bool in_enable)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsCASetEnabled(in_enable);
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsCAIsEnabled(DMSWrapper* inObject, slim_bool *out_enabled)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsCAIsEnabled(out_enabled);
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsCASetDBLocation(DMSWrapper* inObject, slim_char *in_databaseLocation)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsCASetDBLocation(in_databaseLocation);
    }
    return ret;
  }

  extern "C" DllExport slim_char* AHLdmsCAGetDBLocation(DMSWrapper* inObject)
  {
    if (inObject != NULL) {
      return inObject->dmsCAGetDBLocation();
    }
    return NULL;
  }

  extern "C" DllExport returnValue AHLdmsCASetDBSelectionMode(DMSWrapper* inObject, dmsCADatabaseSelectionMode in_mode)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsCASetDBSelectionMode(in_mode);
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsCAGetDBSelectionMode(DMSWrapper* inObject, dmsCADatabaseSelectionMode *out_mode)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsCAGetDBSelectionMode(out_mode);
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsCAExecuteCommand(DMSWrapper* inObject, dmsCACommand in_cmd)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsCAExecuteCommand(in_cmd);
    }
    return ret;
  }

  extern "C" DllExport returnValue AHLdmsCAGetState(DMSWrapper* inObject, dmsCAState *out_state)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsCAGetState(out_state);
    }
    return ret;
  }
#endif /* DEVELOPMENT_CONTENT_AGGREGATION */

  extern "C" DllExport returnValue AHLdmsGetCoreInfo(DMSWrapper* inObject, XMLBuffer *out_info)
  {
    returnValue ret = NFLC_E_ERROR;
    if (inObject != NULL) {
      ret = inObject->dmsGetCoreInfo(out_info);
    }
    return ret;
  }

  extern "C" DllExport void AHLdmsNotify(DMSWrapper* inObject, notifyEvent in_event, XMLBuffer in_param)
  {
    if (inObject != NULL) {
      inObject->dmsNotify(in_event, in_param);
    }
  }
}
