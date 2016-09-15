/*
 * dms_ems.h
 * Copyright (C) 2013 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef DMS_EMS_H
#define DMS_EMS_H

#include <upnp_ems.h>

struct dms_ems_subscribe_info
{
	struct dms_ems_subscribe_info *next;
	struct dms_ems_subscribe_info *prev;
	upnp_sid_t sid;
};
typedef struct dms_ems_subscribe_info dms_ems_subscribe_info_t;

/* EnergyManagement service.  */
struct dms_ems
{
	/* DMS service base structure.  */
	struct dms_service base;

	List(dms_ems_subscribe_info_t *) subscribe_info_list;

	upnp_ems *upnp_ems;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus__ */

struct dms_service *
dms_ems_alloc (struct dms *top);

slim_int
dms_ems_free (struct dms_service *s);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* DMS_EMS_H */

