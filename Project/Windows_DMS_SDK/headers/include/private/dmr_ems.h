/*
 * dmr_ems.h
 * Copyright (C) 2013 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef DMR_EMS_H
#define DMR_EMS_H

#include <upnp_ems.h>

typedef struct dmr_ems_subscribe_info
{
  struct dmr_ems_subscribe_info *next;
  struct dmr_ems_subscribe_info *prev;
  upnp_sid_t sid;
} dmr_ems_subscribe_info_t;

/* EnergyManagement service.  */
struct dmr_ems
{
	/* DMR service base structure.  */
	struct dmr_service base;

	List(dmr_ems_subscribe_info_t *) subscribe_info_list;

	upnp_ems *upnp_ems;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus__ */

struct dmr_service *
dmr_ems_alloc (struct dmr *top);

slim_int
dmr_ems_free (struct dmr_service *s);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* DMR_EMS_H */

