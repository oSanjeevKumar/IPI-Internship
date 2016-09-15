#ifndef DMSWRAPPER_H
#define DMSWRAPPER_H

extern "C"{
#include <dms_ahl.h>
}

class DMSWrapper
{
  public:
    DMSWrapper();
    ~DMSWrapper();

    slim_bool
    dmsInitialize(dmsInitParams_t *in_params);

    void
    dmsFinalize(void);

    returnValue
    dmsStart(void);

    returnValue
    dmsStop(void);

    slim_char*
    dmsGetFriendlyName();

    returnValue
    dmsSetFriendlyName(slim_char *in_friendlyName);

    returnValue
    dmsPublishStorageAdd(slim_char *in_path, slim_char *in_share_name, slim_char *in_id, dmsStorageDatabaseLocationType in_location_type, slim_bool in_auto_index);

    returnValue
    dmsPublishStorageRemove(slim_char *in_path);

    returnValue
    dmsPublishStorageUpdate(slim_char *in_path);

    returnValue
    dmsPublishStorageSetDefaultUploadFolder(slim_char *in_path);

    returnValue
    dmsPublishStorageGetDefaultUploadFolder(const slim_char ** const out_path);

    returnValue
    dmsPublishStorageSetUploadFolderSelectionMode(dmsUploadFolderSelectionMode in_mode);

    returnValue
    dmsPublishStorageGetUploadFolderSelectionMode(dmsUploadFolderSelectionMode *out_mode);

    returnValue
    dmsGetPublishStoragesCount(slim_int *out_count);

    returnValue
    dmsPublishStorageSetStorageCentralDir(slim_char *in_config_path);

    returnValue
    dmsGetPublishStorages(XMLBuffer *out_storages);

    returnValue
    dmsGetServerState(dmsState *out_server_state);

    returnValue
    dmsSetServerState(dmsState in_server_state);

    returnValue
    dmsGetTotalContentsShared(dmsContentClassType in_type, slim_int *out_result);

    returnValue
    dmsGetDeviceDescription(XMLBuffer *out_deviceDescription);

    returnValue
    dmsRefreshContentIndex(void);

    returnValue
    dmsGetContentTree(slim_char *in_containerID, slim_int in_startIndex, slim_int in_requestedCount, XMLBuffer *out_buf);

    returnValue
    dmsSetContentShare(slim_char *in_contentID, slim_bool in_share, slim_bool in_recusive);

    returnValue
    dmsGetSupportedLanguages(XMLBuffer *out_languages);

    returnValue
    dmsSetLanguage(const slim_char* in_language);

    returnValue
    dmsGetSelectedLanguage(slim_char **out_language);

    returnValue
    dmsSetStreamingSessionsLimit(slim_int in_session_count);

    returnValue
    dmsGetStreamingSessionsLimit(slim_int *out_session_count);

    returnValue
    dmsBrowseContent(slim_char* in_id, XMLBuffer *out_response_doc, slim_word start_index, slim_word request_count);

    returnValue
    dmsSearchContent(slim_char* in_id, slim_char *criteria, XMLBuffer *out_response_doc, slim_word start_index, slim_word request_count);

#ifdef ENABLE_PARENTAL_GUIDANCE
    returnValue
    dmsPGGetDefaultLevel(dmsPGLevelType in_levelType, slim_int *out_level);

    returnValue
    dmsPGSetDefaultLevel(dmsPGLevelType in_levelType, slim_int in_newDefaultLevel);

    returnValue
    dmsPGSetContentLevel(slim_char *in_contentID, slim_int in_level);

    returnValue
    dmsPGGetDeviceList(XMLBuffer *out_PGDeviceList);

    returnValue
    dmsPGGetLevelList(XMLBuffer *out_PGLevelList);

    returnValue
    dmsPGSetDeviceParams(slim_char *in_deviceMAC, slim_int *in_level, slim_char *in_description);

    returnValue
    dmsPGDeleteDeviceByMac(slim_char *in_deviceMAC);
#endif /* ENABLE_PARENTAL_GUIDANCE */

#ifdef DEVELOPMENT_CONTENT_AGGREGATION
    returnValue
    dmsCASetEnabled(slim_bool in_enable);

    returnValue
    dmsCAIsEnabled(slim_bool *out_enabled);

    returnValue
    dmsCASetDBLocation(slim_char *in_databaseLocation);

    slim_char*
    dmsCAGetDBLocation();

    returnValue
    dmsCASetDBSelectionMode(dmsCADatabaseSelectionMode in_mode);

    returnValue
    dmsCAGetDBSelectionMode(dmsCADatabaseSelectionMode *out_mode);

    returnValue
    dmsCAExecuteCommand(dmsCACommand in_cmd);

    returnValue
    dmsCAGetState(dmsCAState *out_state);

    returnValue
    dmsCASetDefaultIndexing(dmsCAIndex in_index);

    returnValue
    dmsCAGetDefaultIndexing(dmsCAIndex *out_index);

    returnValue
    dmsCAGetDeviceList(XMLBuffer *out_CADeviceList);

    returnValue
    dmsCASetDeviceIndexing(slim_char *in_uuid, dmsCAIndex in_index);

    returnValue
    dmsCASetDatabaseSizeLimit(slim_int in_size);

    returnValue
    dmsCAGetDatabaseSizeLimit(slim_int *out_size);

    returnValue
    dmsCASetPurgeTime(slim_int in_time);

    returnValue
    dmsCAGetPurgeTime(slim_int *out_time);

    returnValue
    dmsCASetRescanInterval(slim_int in_interval);

    returnValue
    dmsCAGetRescanInterval(slim_int *out_interval);
#endif /* DEVELOPMENT_CONTENT_AGGREGATION */

    returnValue
    dmsGetCoreInfo(XMLBuffer *out_info);

    void
    dmsNotify(notifyEvent in_event, XMLBuffer in_param);

    returnValue
    dmsContentUpdate(contentUpdateEvent in_event, slim_char *in_path);

  private:
    dmsInstance_t m_instance; // dms Instance pointer
};

#endif /* DMSWRAPPER_H */
