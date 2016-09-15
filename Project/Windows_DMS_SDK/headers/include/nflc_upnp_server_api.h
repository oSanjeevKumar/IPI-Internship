/*
 * nflc_upnp_server_api.h
 * Copyright (C) 2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_UPNP_SERVER_API_H
#define NFLC_UPNP_SERVER_API_H

#define NFLC_UPNP_API

typedef void *TNflcUPnPServer;
typedef void *TNflcSoapServer;


typedef void (*TNflcUPnPServer_SoapCallback)(TNflcUPnPServer self, slim_char *in_service_id,
											slim_char *in_action, sXML *in_action_doc, sXML *in_result_doc,
											void *in_owner_info);

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus__ */

NFLC_UPNP_API TNflcUPnPServer
NflcUPnPServer_New(dlna_progress in_progress, slim_half in_port,
					slim_char *in_config_dir, 
					slim_char *in_device_file, void *in_info);

NFLC_UPNP_API void
TNflcUPnPServer_Free(TNflcUPnPServer self);

NFLC_UPNP_API slim_int
TNflcUPnPServer_Start(TNflcUPnPServer self);

NFLC_UPNP_API slim_int
TNflcUPnPServer_Stop(TNflcUPnPServer self);

NFLC_UPNP_API slim_char *
TNflcUPnPServer_GetUDN(TNflcUPnPServer self);

/* Soap Session */
NFLC_UPNP_API void
TNflcUPnPServer_SetSoapCallback(TNflcUPnPServer self, TNflcUPnPServer_SoapCallback in_callback);

/* Gena Observer */
//NFLC_UPNP_API void
//TNflcUPnPServer_GENANotify(TNflcUPnPServer self, );


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_UPNP_CLIENT_API_H */
