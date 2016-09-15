/*
 * rada_config.h
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


#ifndef _RADA_CONFIG_H
#define _RADA_CONFIG_H

/* RADAConfig:1 Service Template Version 1.01.  */


/* RADAConfig service.  */
struct rada_config
{
  /* RAS service base structure.  */
  struct ra_service base;
  struct sbuf SystemInfo ;
  slim_int SystemInfoUpdateID ;
  struct sbuf A_ARG_TYPE_FilterList ;
  struct sbuf A_ARG_TYPE_UUID ;
  slim_int last_SystemInfoUpdateID ;
  List(rada_config_filter_list_t  *) filter_list;
};


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct ra_service *
rada_config_alloc (struct ra_device *top);

int
rada_config_free (struct ra_service *service);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _RADA_CONFIG_H */
