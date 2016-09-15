/*
 * ras_api.h
 * Copyright (C) 2015 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */


#ifndef NFLC_RAS_API_H
#define NFLC_RAS_API_H

#include <nflc_ra_def.h>

/* TRAS is a RAS library instance. */
typedef void * TRAS;

#define RAS_SERVICE_MAX	3


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/** Allocates Remote Access Server (RAS)
 *  @param in_p Progress Manager descriptor
 *  @param ra_device_callback_t callback
 *  @param in_port Port at which RAS runs
 *  @param in_config_dir Configuration directory containing xml files
 *  @return RAS device instance
 */
TRAS
dlnaRasAlloc (dlna_progress in_p, ra_device_callback_t in_callback, void *in_callback_arg,
                                              slim_half in_port,slim_char *in_config_dir);

/** Releases resources occupied by RAS.
 *  @param self RAS device instance
 */
void
dlnaRasFree (TRAS self);

/** Starts RAS.
 *  @param self RAS device instance
 */
slim_int
dlnaRasStart (TRAS self);

/** Stops RAS.
 *  @param self RAS device instance
 */
slim_int
dlnaRasStop (TRAS self);

/** Starts RAS RADA component.
 *  @param self RAS device instance
 */
slim_int
dlnaRasStartRAService (TRAS self) ;

/** Stops RAS RADA component.
 *  @param self RAS device instance
 */
slim_int
dlnaRasStopRAService (TRAS self) ;

#if 0
/** set cloud communication credentials 
 *  @param self RAS device instance
 *  @param serial HGW serial number
 *  @param token RAS-token
 */
slim_int
dlnaRASSetCredentials(TRAS self, slim_char *serial, slim_char *token);
#endif

/** Get settings
 *  @param self RAS device instance
 *  @param out settings xml list ! buffer has to be freed by the caller
 */
slim_int
dlnaRasGetSettings (TRAS self, slim_char **out_settings)  ;

/** Provision with cloud 
 *  @param self RAS device instance
 *  @param serial Gateway serial number
 *  @param pwd token RAS-token
 */
slim_int
dlnaRasProvision (TRAS self, slim_char *in_uid, slim_char *in_pwd, slim_char *in_serial) ;


/** Authenticate with cloud 
 *  @param self RAS device instance
 *  @param serial HGW serial number
 *  @param pwd token RAS-token
 */
slim_int
dlnaRasAuthenticate (TRAS self, slim_char *in_uid, slim_char *in_pwd, slim_char *in_serial) ;

/** Sets RAS friendly name.
 *  @param self RA device instance
 *  @param in_friendly_name New friendly name
 */

slim_int
dlnaRasSetFriendlyName (TRAS self, slim_char *in_friendly_name);

/** Gets RA friendly name.
 *  @param self RAS device instance
 *  @param out_name  friendly name
 *  @return slim_int
 */
slim_int
dlnaRasGetFriendlyName(TRAS self, slim_char **out_name);



/** get current connected peers list
 *  @param self  RAS device instance
 *  @param out_peers pointer to RAPeers list
 * return slim_int
 */
slim_int
dlnaRAGetRemotePeers (TRAS self, RAPeers_t *out_peers);

/** Deletes target/peers list
 *  @param self  RAS device instance
 *  @param in_peers pointer to RAPeers list
 */
void
dlnaRAListFree ( RAPeers_t *in_peers);

/** Sets URL to backend.
 *  @param self RA device instance
 *  @param in_url url to backend
 *  @return slim_int
 */
slim_int
dlnaRasSetBackendURL (TRAS self, slim_char *in_url) ;


/** Set properties obtained from external service such as tr69 to backend.
 *  @param self RA device instance
 *  @param in_api api to describe api name in request send to the backend
 *  @param in_data data to be send to the backend
 *  @return slim_int
 */
slim_int
dlnaRasSetExtProp (TRAS self, slim_char *in_api, slim_char *in_data) ;

/** Get properties obtained from external service such as tr69 to backend.
 *  @param self RAS device instance
 *  @param in_api api to describe api name in request send to the backend
 *  @return slim_int
 *  result comes with async event 
 */
slim_int
dlnaRasGetExtProp (TRAS self, slim_char *in_api);

/** Utility method to get and display current channels
 *  @param self RAS device instance
 */
void
dlnaRasDisplayChannels (TRAS self);

/** Utility method to get and display current proxy devices
 *  @param self RAS device instance
 */
void
dlnaRasDisplayProxyDevices(TRAS self);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_RAS_API_H */
