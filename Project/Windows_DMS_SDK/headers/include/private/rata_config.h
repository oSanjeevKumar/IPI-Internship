/*
 * rata_config.h
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


#ifndef _RATA_CONFIG_H
#define _RATA_CONFIG_H

/* RATAConfig:1 Service Template Version 1.01.  */

/* RATAConfig service.  */
struct rata_config
{
  /* RAS service base structure.  */
  struct ra_service base;

	struct sbuf	SystemInfo ;
	struct sbuf	TransportAgentCapabilities ;
	struct sbuf	CredentialDelivery ;
	struct sbuf	CredentialsList ;
	struct sbuf	ProfileList ;
	struct sbuf	A_ARG_TYPE_ProfileConfigInfo ;
	struct sbuf	A_ARG_TYPE_ProfileID ;

	struct sbuf	Last_CredentialsList ;

};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct ra_service *
rata_config_alloc (struct ra_device *top);

int
rata_config_free (struct ra_service *service);



#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _RAtA_CONFIG_H */
