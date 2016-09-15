/*
 * dmr_bms.h
 * Copyright (C) 2013 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef DMR_BMS_H
#define DMR_BMS_H

#include <upnp_bms.h>

#define STATE_VARIABLES_EVENT_TIMEVAL {1, 0}      // 1.0

typedef struct dmr_bms_subscribe_info
{
  struct dmr_bms_subscribe_info *next;
  struct dmr_bms_subscribe_info *prev;
  upnp_sid_t sid;
} dmr_bms_subscribe_info_t;

/* BasicManagement service.  */
struct dmr_bms
{
  /* DMR service base structure.  */
  struct dmr_service base;

  List(dmr_bms_subscribe_info_t *) subscribe_info_list;

  dlna_progress_handle e_all_state_variables_timer;

  struct sbuf * testids_doc;
  struct sbuf * active_testids_doc;

  upnp_bms *upnp_bms;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus__ */

struct dmr_service *
dmr_bms_alloc(struct dmr *top);

slim_int
dmr_bms_free(struct dmr_service *s);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* DMR_BMS_H */

