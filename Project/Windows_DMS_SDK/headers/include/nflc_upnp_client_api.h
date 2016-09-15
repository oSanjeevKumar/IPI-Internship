/*
 * nflc_upnp_client_api.h
 * Copyright (C) 2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_UPNP_CLIENT_API_H
#define NFLC_UPNP_CLIENT_API_H

#define NFLC_UPNP_API

typedef void *TNflcUPnPClient;
typedef void *TNflcSoapClient;

struct TNflcUPnPControlPoint_ {
  slim_char *fUuid;
  slim_char *fFriendlyName;
  slim_int fType;
};
typedef struct TNflcUPnPControlPoint_ TNflcUPnPControlPoint;

typedef void *TNflcSoapSession;
typedef void *TNflcGenaObserver;

enum {
  NFLC_UPNP_DEVICE_TYPE_MSD = 1,
  NFLC_UPNP_DEVICE_TYPE_MRD,
  NFLC_UPNP_DEVICE_TYPE_ANY
};

#define NFLC_UPNP_SERVICE_TYPE_CDS	UPNP_SERVICE_TYPE_CDS
#define NFLC_UPNP_SERVICE_TYPE_CMS	UPNP_SERVICE_TYPE_CMS
#define NFLC_UPNP_SERVICE_TYPE_RCS	UPNP_SERVICE_TYPE_RCS
#define NFLC_UPNP_SERVICE_TYPE_AVTS	UPNP_SERVICE_TYPE_AVTS


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus__ */

typedef void (*TNflcUPnPClient_SSDPCallback)(TNflcUPnPClient self, slim_int in_event_id, 
                                             TNflcUPnPControlPoint *in_cp, void *in_owner_info);
typedef void (*TNflcGenaObserver_Callback)(TNflcGenaObserver self, void *in_owner_info,
                                           slim_char *in_name, slim_char *in_value);
typedef slim_int (*TNflcSoapSessionCallback)(TNflcSoapSession self, void *in_owner_info, sXML *in_result_doc);


NFLC_UPNP_API TNflcUPnPClient
TNflcUPnPClient_New();

NFLC_UPNP_API void
TNflcUPnPClient_Free(TNflcUPnPClient self);

NFLC_UPNP_API slim_int
TNflcUPnPClient_Start(TNflcUPnPClient self, 
                      TNflcUPnPClient_SSDPCallback in_ssdp_callback, void *in_owner_info);

NFLC_UPNP_API slim_int
TNflcUPnPClient_Stop(TNflcUPnPClient self);

NFLC_UPNP_API slim_int
TNflcUPnPClient_SSDPMSearch(TNflcUPnPClient self);

NFLC_UPNP_API TNflcSoapClient
TNflcUPnPClient_GetSoapClient(TNflcUPnPClient self);

/* Soap Session */

NFLC_UPNP_API TNflcSoapSession
NflcSoapSession_Create(TNflcUPnPClient self, 
                        slim_char *in_device_uuid, 
                        slim_char *in_service_type,
                        TNflcSoapSessionCallback in_callback,
                        void *in_userdata);

NFLC_UPNP_API sXML *
TNflcSoapSession_PrepareAction(TNflcSoapSession self, slim_char *in_action_name);

NFLC_UPNP_API slim_int
TNflcSoapSession_PrepareQuery(TNflcSoapSession self, slim_char *in_var_name);

NFLC_UPNP_API slim_int
TNflcSoapSession_Post(TNflcSoapSession self);

NFLC_UPNP_API void
TNflcSoapSession_Delete(TNflcSoapSession self);

/* Gena Observer */

NFLC_UPNP_API TNflcGenaObserver
NflcGenaObserver_New(slim_char *in_device_uuid, slim_char *in_service_type,
                     TNflcGenaObserver_Callback in_callback, void *in_owner_info);

NFLC_UPNP_API void
NflcGenaObserver_Free(TNflcGenaObserver self);

NFLC_UPNP_API slim_int
TNflcUPnPClient_AddObserver(TNflcUPnPClient self, TNflcGenaObserver in_observer);

NFLC_UPNP_API void
TNflcUPnPClient_RemoveObserver(TNflcUPnPClient self, TNflcGenaObserver in_observer);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_UPNP_CLIENT_API_H */
