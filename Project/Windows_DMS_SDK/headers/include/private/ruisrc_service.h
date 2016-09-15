/*
 * ruisrc_service.h
 * Copyright (C) 2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */

#ifndef __RUISRC_SERVICE_H__
#define __RUISRC_SERVICE_H__

#ifdef DLNA_SUPPORT_RUISRC

#include <rui_defines.h>

#define RUIS_SERVICE_INVALID_VALUE                   (703)
#define RUIS_SERVICE_REQUIRED_PROPERTY               (708)

/* RemoteUI service.  */
struct ruis_service
{
	/* DMS service base structure.  */
	struct dms_service base;
	dlna_dcn dcn;
	dlna_progress em;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus__ */

struct dms_service *
ruisrc_service_alloc (struct dms *top);

void
ruisrc_service_free (struct dms_service *s);

rui_result_t 
ruisrc_service_notify_uilisting_update (const slim_char * in_ui_id_list);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* DLNA_SUPPORT_RUISRC */

#endif /* __RUISRC_SERVICE_H__ */

