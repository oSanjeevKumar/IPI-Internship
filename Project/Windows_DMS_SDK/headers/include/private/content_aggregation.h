/*
* content_aggregation.h
* Copyright (C) 2011 ACCESS CO.,LTD.
* All rights are reserved by ACCESS CO.,LTD.,
* whether the whole or part of the source code
* including any modifications is concerned.
*
* This is an unpublished source code of ACCESS CO.,LTD., and must be
* treated as confidential material.  The above copyright notice does
* not evidence any actual or intended publication of this source code.
*/

#include <dlna_peer.h>

#ifndef CONTENT_AGGREGATION_H
#define CONTENT_AGGREGATION_H

typedef void *ca_t;

/* CA states */
typedef enum ca_state
{
  CA_STATE_DISABLED,
  CA_STATE_IDLE,
  CA_STATE_PROCESSING,
  CA_STATE_PAUSED,
  CA_STATE_STOPPED
} ca_state_t;

typedef enum ca_event
{
  CA_EV_STATE_CHANGED,
  CA_EV_DB_UPDATE,
  CA_EV_DB_PURGE_START,
  CA_EV_DB_PURGE_END
} ca_event_t;

typedef slim_int (*ca_callback_t) (struct dms *top, ca_event_t event);

ca_t
content_aggregation_alloc(struct dms *top, ca_callback_t in_callback, slim_char *db_folder_path,
                          slim_int in_purge, slim_int in_rescan);

void
content_aggregation_free(ca_t in_ca);

slim_int
content_aggregation_start(ca_t in_ca);

slim_int
content_aggregation_set_db_location(ca_t in_ca, slim_char *in_db_folder_path);

slim_int
content_aggregation_pause(ca_t in_ca);

slim_int
content_aggregation_resume(ca_t in_ca);

ca_state_t
content_aggregation_get_state(ca_t in_ca);

slim_int
content_aggregation_set_default_indexing (ca_t in_ca, slim_int in_index);

slim_int
content_aggregation_get_default_indexing (ca_t in_ca, slim_int *out_index);

slim_int
content_aggregation_get_first_device (ca_t in_ca, TDMSCADeviceObject **out_dev);

slim_int
content_aggregation_set_device_indexing (ca_t in_ca, slim_char *in_uuid, slim_int in_index);

slim_int
content_aggregation_set_purge_time (ca_t in_ca, slim_int in_time);

slim_int
content_aggregation_set_rescan_interval (ca_t in_ca, slim_int in_interval);
#endif /* CONTENT_AGGREGATION_H */
