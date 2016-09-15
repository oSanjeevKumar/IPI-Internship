#ifndef DMCWRAPPER_H
#define DMCWRAPPER_H

extern "C"{
#include <dmc_ahl.h>
}

class DMCWrapper
{
  public:
    DMCWrapper();
    ~DMCWrapper();

    slim_bool
    dmcInitialize(dmcInitParams_t *in_params);

    void
    dmcFinalize(void);

    void
    dmcDiscoverDevices(void);

    void
    dmcGetDevices(void);

    returnValue
    dmcRegisterGenaEvents(slim_char *in_deviceUUID);

    returnValue
    dmcUnRegisterGenaEvents(slim_char *in_deviceUUID);

    returnValue
    dmcGetServiceDescription(slim_char *in_deviceUUID, slim_char *in_serviceID);

    returnValue
    dmcBrowseDirectChildren(slim_char *in_deviceUUID, slim_char *in_containerID, slim_int in_startIndex, slim_int in_requestedCount, slim_char *in_sortCriteria, slim_char *in_filterCriteria);

    returnValue
    dmcBrowseMetadata(slim_char *in_deviceUUID, slim_char *in_objectID, contentClass in_dmcObjType, slim_char *in_filterCriteria);

    returnValue
    dmcObjectSearch(slim_char *in_deviceUUID, slim_char *in_searchCriteria, slim_int in_startIndex, slim_int in_requestedCount, slim_char *in_sortCriteria, slim_char *in_filterCriteria);

    returnValue
    dmcGetSortCapabilities(slim_char *in_deviceUUID);

    returnValue
    dmcGetSearchCapabilities(slim_char *in_deviceUUID);

    returnValue
    dmcPlaybackPrepare(slim_char *in_dmrDeviceUUIDs, slim_char *in_objectDescription, slim_char *in_url, slim_bool in_next);

    returnValue
    dmcPlaybackControl(slim_char *in_deviceUUIDs, dmcPlayControlCommand in_command, slim_char *in_playSpeed);

    returnValue
    dmcPlaybackTimeSeek(slim_char *in_deviceUUIDs, slim_int in_seekValue);

    returnValue
    dmcPlaybackMoveContent(slim_char *in_sourceDmrDeviceUUID, slim_char *in_destinationDmrDeviceUUID);

    returnValue
    dmcListPresets(slim_char *in_deviceUUIDs);

    returnValue
    dmcSelectPreset(slim_char *in_deviceUUIDs, slim_char *in_preset);

    returnValue
    dmcVolumeControl(slim_char *in_deviceUUIDs, dmcVolumeControlCommand in_command, slim_char *in_channel, slim_int in_value);

    returnValue
    dmcGetMediaInfo(slim_char *in_deviceUUID);

    returnValue
    dmcGetTransportInfo(slim_char *in_deviceUUID);

    returnValue
    dmcGetPositionInfo(slim_char *in_deviceUUID);

    returnValue
    dmcRegisterPositionInfoEvent(slim_char *in_deviceUUID, slim_int in_interval);

    returnValue
    dmcUnRegisterPositionInfoEvent(slim_char *in_deviceUUID);

    returnValue
    dmcUploadControl(dmcFileTransferControlCommand in_command, slim_char *in_deviceUUID, slim_char *in_containerID, slim_char *in_sourcePath);

    returnValue
    dmcDownloadControl(dmcFileTransferControlCommand in_command, slim_char *in_objectDescription, slim_char *in_url, slim_char *in_destinationPath);

    returnValue
    dmcObjectControl(dmcObjectControlCommand in_command, slim_char *in_deviceUUID, slim_char *in_contentID, slim_char *in_containerName);

    void
    dmcCallbackHandler(void * in_arg, dmcEvent in_event, void *in_param);

    returnValue
    dmcGetAllowedPlaySpeed(slim_char *in_deviceUUID, dmcPlaySpeedListType in_playSpeedType, slim_char *out_playSpeed, slim_int *inout_len);

#ifdef ENABLE_PRINTER_SUPPORT
    returnValue
    dmcPrintUri(slim_char *in_dmprDeviceUUID, slim_char *in_objectDescription, slim_char *in_url, slim_char *in_printParam);

    returnValue
    dmcPrintFile(slim_char *in_dmprDeviceUUID, slim_char *in_filePath, slim_char *in_printParam);

    returnValue
    dmcPrintCancelJob(slim_char *in_dmrpDeviceUUID, slim_int in_job_id);

    returnValue
    dmcPrintGetMediaList(slim_char *in_dmprDeviceUUID);

    returnValue
    dmcPrintGetPrinterAttributes(slim_char *in_dmprDeviceUUID);
#endif /* ENABLE_PRINTER_SUPPORT */

#ifdef DEVELOPMENT_DIRECT_DLNA_OBJECT
    returnValue
    dmcDirectPlayLocalFile(slim_char *in_dmrDeviceUUIDs, slim_char *in_filePath, slim_char *in_title, slim_char **out_url);

    returnValue
    dmcDirectPlayRemoteOnlineFile(slim_char *in_dmrDeviceUUIDs, slim_char *in_url, slim_char *in_mimeType, slim_char *in_title, XMLBuffer in_itemInfo);
#endif /* DEVELOPMENT_DIRECT_DLNA_OBJECT */

    returnValue
    dmcGetCoreInfo(XMLBuffer *out_info);

    void
    dmcNotify(notifyEvent in_event, XMLBuffer in_param);

  private:
    dmcInstance_t m_instance; // dmc Instance pointer
};

#endif /* DMCWRAPPER_H */
