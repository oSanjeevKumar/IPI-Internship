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
#include <iostream>

using namespace std;


DMSWrapper::DMSWrapper() :
  m_instance(slim_nil)
{
}

DMSWrapper::~DMSWrapper()
{
  if (this->m_instance) {
    this->dmsFinalize();
  }
}

slim_bool
DMSWrapper::dmsInitialize(dmsInitParams_t *in_params)
{
  slim_bool ret = slim_false;

  if(!in_params) {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "in_params is null");
    return ret;
  }
  if (this->m_instance == slim_nil) {
    this->m_instance = ::dmsInitialize(in_params);
    if (this->m_instance) {
      ret = slim_true;
    } else {
      DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "dmsInitialize() fails this->m_instance is still NULL");
    }
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "dmsInitialize() fails this->m_instance is not NULL."
                                                                "dmsInitialize() was called already.");
  }

  return ret;
}

void
DMSWrapper::dmsFinalize(void)
{
  if(this->m_instance) {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_DEBUG, "dmsFinalize() is called");
    ::dmsFinalize(m_instance);
    this->m_instance = slim_nil;
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }
}

returnValue
DMSWrapper::dmsStart(void)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsStart(this->m_instance);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsStop(void)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsStop(this->m_instance);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}


slim_char*
DMSWrapper::dmsGetFriendlyName(void)
{
  slim_char *ret = slim_nil;

  if(this->m_instance) {
    ret = ::dmsGetFriendlyName(this->m_instance);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsSetFriendlyName(slim_char *in_friendlyName)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsSetFriendlyName(this->m_instance, in_friendlyName);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsPublishStorageAdd(slim_char *in_path, slim_char *in_share_name, slim_char *in_id, dmsStorageDatabaseLocationType in_location_type, slim_bool in_auto_index)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsPublishStorageAdd(this->m_instance, in_path, in_share_name, in_id, in_location_type, in_auto_index);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsPublishStorageRemove(slim_char *in_path)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsPublishStorageRemove(this->m_instance, in_path);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsPublishStorageUpdate(slim_char *in_path)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsPublishStorageUpdate(this->m_instance, in_path);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsPublishStorageSetDefaultUploadFolder(slim_char *in_path)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsPublishStorageSetDefaultUploadFolder(this->m_instance, in_path);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsPublishStorageGetDefaultUploadFolder(const slim_char **const out_path)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsPublishStorageGetDefaultUploadFolder(this->m_instance, out_path);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsGetPublishStoragesCount(slim_int *out_count)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsGetPublishStoragesCount(this->m_instance, out_count);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}


returnValue
DMSWrapper::dmsPublishStorageSetStorageCentralDir(slim_char *in_config_path)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsPublishStorageSetStorageCentralDir(this->m_instance, in_config_path);
  }  else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsGetPublishStorages(XMLBuffer *out_storages)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsGetPublishStorages(this->m_instance, out_storages);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsGetServerState(dmsState *out_server_state)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsGetServerState(this->m_instance, out_server_state);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsSetServerState(dmsState out_server_state)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsSetServerState(this->m_instance, out_server_state);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsGetTotalContentsShared(dmsContentClassType in_type, slim_int *out_result)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsGetTotalContentsShared(this->m_instance, in_type, out_result);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsGetDeviceDescription( XMLBuffer *out_deviceDescription)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsGetDeviceDescription(this->m_instance, out_deviceDescription);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsRefreshContentIndex()
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsRefreshContentIndex(this->m_instance);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

 return ret;
}

returnValue
DMSWrapper::dmsGetContentTree(slim_char *in_containerID, slim_int in_startIndex, slim_int in_requestedCount, XMLBuffer *out_buf)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsGetContentTree(this->m_instance, in_containerID, in_startIndex, in_requestedCount, out_buf);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsSetContentShare(slim_char *in_contentID, slim_bool in_share, slim_bool in_recusive)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsSetContentShare(m_instance, in_contentID, in_share, in_recusive);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsGetSupportedLanguages(XMLBuffer *out_languages)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsGetSupportedLanguages(m_instance, out_languages);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsSetLanguage(const slim_char* in_language)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsSetLanguage(m_instance, in_language);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsGetSelectedLanguage(slim_char **out_language)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsGetSelectedLanguage(m_instance, out_language);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}


returnValue
DMSWrapper::dmsBrowseContent(slim_char* in_id, XMLBuffer *out_response_doc, slim_word start_index, slim_word request_count)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsBrowseContent(m_instance, in_id, out_response_doc, start_index, request_count);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsSearchContent(slim_char* in_id, slim_char *criteria, XMLBuffer *out_response_doc, slim_word start_index, slim_word request_count)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsSearchContent(m_instance, in_id, criteria, out_response_doc, start_index, request_count);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

#ifdef ENABLE_PARENTAL_GUIDANCE

returnValue
DMSWrapper::dmsPGGetDefaultLevel(dmsPGLevelType in_levelType, slim_int *out_level)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsPGGetDefaultLevel(m_instance, in_levelType, out_level);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsPGSetDefaultLevel(dmsPGLevelType in_levelType, slim_int in_newDefaultLevel)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsPGSetDefaultLevel(m_instance, in_levelType, in_newDefaultLevel);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsPGSetContentLevel(slim_char *in_contentID, slim_int in_level)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsPGSetContentLevel(m_instance, in_contentID, in_level);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsPGGetDeviceList(XMLBuffer *out_PGDeviceList)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsPGGetDeviceList(m_instance, out_PGDeviceList);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsPGGetLevelList(XMLBuffer *out_PGLevelList)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsPGGetLevelList(m_instance, out_PGLevelList);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsPGSetDeviceParams(slim_char *in_deviceMAC, slim_int *in_level, slim_char *in_description)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsPGSetDeviceParams(m_instance, in_deviceMAC, in_level, in_description);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsPGDeleteDeviceByMac(slim_char *in_deviceMAC)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsPGDeleteDeviceByMac(m_instance, in_deviceMAC);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}
#endif /* ENABLE_PARENTAL_GUIDANCE */

#ifdef DEVELOPMENT_CONTENT_AGGREGATION
returnValue
DMSWrapper::dmsCASetDefaultIndexing(dmsCAIndex in_index)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsCASetDefaultIndexing(m_instance, in_index);
  }
  else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsCAGetDefaultIndexing(dmsCAIndex *out_index)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsCAGetDefaultIndexing(m_instance, out_index);
  }
  else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsCAGetDeviceList(XMLBuffer *out_CADeviceList)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsCAGetDeviceList(m_instance, out_CADeviceList);
  }
  else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsCASetDeviceIndexing(slim_char *in_uuid, dmsCAIndex in_index)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsCASetDeviceIndexing(m_instance, in_uuid, in_index);
  }
  else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsCASetDatabaseSizeLimit(slim_int in_size)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsCASetDatabaseSizeLimit(m_instance, in_size);
  }
  else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsCAGetDatabaseSizeLimit(slim_int *out_size)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsCAGetDatabaseSizeLimit(m_instance, out_size);
  }
  else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsCASetPurgeInterval(slim_int in_interval)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsCASetPurgeTime(m_instance, in_interval);
  }
  else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsCAGetPurgeInterval(slim_int *out_interval)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsCAGetPurgeTime(m_instance, out_interval);
  }
  else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsCASetRescanInterval(slim_int in_interval)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsCASetRescanInterval(m_instance, in_interval);
  }
  else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsCAGetRescanInterval(slim_int *out_interval)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsCAGetRescanInterval(m_instance, out_interval);
  }
  else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsCASetEnabled(slim_bool in_enable)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsCASetEnabled(m_instance, in_enable);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsCAIsEnabled(slim_bool *out_enabled)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsCAIsEnabled(m_instance, out_enabled);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsCASetDBLocation(slim_char *in_databaseLocation)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsCASetDatabaseLocation(m_instance, in_databaseLocation);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

slim_char*
DMSWrapper::dmsCAGetDBLocation()
{
  slim_char *ret = slim_nil;

  if(this->m_instance) {
    ret = ::dmsCAGetDatabaseLocation(this->m_instance);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsCASetDBSelectionMode(dmsCADatabaseSelectionMode in_mode)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsCASetDatabaseSelectionMode(m_instance, in_mode);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsCAGetDBSelectionMode(dmsCADatabaseSelectionMode *out_mode)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsCAGetDatabaseSelectionMode(m_instance, out_mode);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsCAExecuteCommand(dmsCACommand in_cmd)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsCAExecuteCommand(m_instance, in_cmd);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}

returnValue
DMSWrapper::dmsCAGetState(dmsCAState *out_state)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsCAGetState(m_instance, out_state);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}
#endif /* DEVELOPMENT_CONTENT_AGGREGATION */

returnValue
DMSWrapper::dmsGetCoreInfo(XMLBuffer *out_info)
{
  returnValue ret = NFLC_E_INVALID_INSTANCE;

  if (this->m_instance) {
    ret = ::dmsGetCoreInfo(m_instance, out_info);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }

  return ret;
}


void
DMSWrapper::dmsNotify(notifyEvent in_event, XMLBuffer in_param)
{
  if (this->m_instance) {
    ::dmsNotify(m_instance, in_event, in_param);
  } else {
    DLNA_LOG(DLNA_LOG_DEVICECLASS_DEVICE, DLNA_LOG_LEVEL_ERROR, "this->m_instance is NULL");
  }
}
