/*
 * dms_bms.h
 * Copyright (C) 2013 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef DMS_BMS_H
#define DMS_BMS_H

#include <upnp_bms.h>

#define DEVICE_STATUS_EVENT_TIMEVAL {1, 0}      // 1.0
#define TEST_IDS_EVENT_TIMEVAL {0, (200 * 1000)}           // 0.2
#define ACTIVE_TEST_IDS_EVENT_TIMEVAL {0, (200 * 1000)}    // 0.2

struct dms_bms_subscribe_info
{
  struct dms_bms_subscribe_info *next;
  struct dms_bms_subscribe_info *prev;
  upnp_sid_t sid;
};
typedef struct dms_bms_subscribe_info dms_bms_subscribe_info_t;

/* BasicManagement service.  */
struct dms_bms
{
  /* DMS service base structure.  */
  struct dms_service base;

  List(dms_bms_subscribe_info_t *) subscribe_info_list;

  dlna_progress_handle e_all_state_variables_timer;

  struct sbuf * testids_doc;
  struct sbuf * active_testids_doc;

  upnp_bms *upnp_bms;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus__ */

struct dms_service *
dms_bms_alloc (struct dms *top);

slim_int
dms_bms_free (struct dms_service *s);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* DMS_BMS_H */

