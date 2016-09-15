/*
* dmrwrapper.hpp
* Copyright (C) 2015 ACCESS CO.,LTD.
* All rights are reserved by ACCESS CO.,LTD.,
* whether the whole or part of the source code
* including any modifications is concerned.
*
* This is an unpublished source code of ACCESS CO.,LTD., and must be
* treated as confidential material.  The above copyright notice does
* not evidence any actual or intended publication of this source code.
*/

#ifndef DMR_WRAPPER_H
#define DMR_WRAPPER_H

extern "C"{
#include <dmr_ahl.h>
}

class DMRWrapper
{
  public:
    DMRWrapper();
    ~DMRWrapper();

    slim_bool
    dmrInitialize(dmrInitParams_t *in_params);

    void
    dmrFinalize(void);

    slim_char *
    dmrGetFriendlyName(void);

    returnValue
    dmrSetFriendlyName(slim_char *in_friendlyName);

    XMLBuffer
    dmrGetCurrentContentMetadata();

    returnValue
    dmrNotifyPlayState(playState in_playState, XMLBuffer in_player_info);

    returnValue
    dmrNotifyMuteState(slim_char *in_channel, slim_int in_value);

    returnValue
    dmrNotifyVolumeState(slim_char *in_channel, slim_int in_value, slim_int in_valueDB);

    returnValue
    dmrNotifyCurrentPlayPosition(slim_int in_time, slim_int in_byte);

    returnValue
    dmrGetCoreInfo(XMLBuffer *out_info);

    returnValue
    dmrNotify(notifyEvent in_event, XMLBuffer in_param);

    returnValue
    dmrStart(XMLBuffer in_info);

    returnValue
    dmrStop(void);

  private:
    dmrInstance_t m_instance; // dmr Instance pointer
};

#endif /* DMR_WRAPPER_H*/
