/*
 * inbound_connection_config.h
 * Copyright (C) 2007-2011 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */


#ifndef _INBOUND_CONNECTION_CONFIG_H
#define _INBOUND_CONNECTION_CONFIG_H

/* InboundConectionConfig:1 Service Template Version 1.01.  */

/* RATAConfig service.  */
struct inbound_connection_config
{
  /* RAS service base structure.  */
  struct ra_service base;

	struct sbuf	DynamicDNSSupportedProtocols ;
	struct sbuf	DynamicDNSConfigInfo ;
	struct sbuf	STUNServerAddress ;
	struct sbuf	NetworkTopologyInfo ;

};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct ra_service *
inbound_connection_config_alloc (struct ra_device *top);

int
inbound_connection_config_free (struct ra_service *service);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _INBOUND_CONNECTION_CONFIG_H */
