/*
 * dmr_cms.h
 * Copyright (C) 2007-2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

#ifndef NFLC_DMR_CMS_H
#define NFLC_DMR_CMS_H

/* ConnectionManager:1 2.4.2 PrepareForConnection parameter.  */
struct dmr_prepare_param
{
  slim_char *RemoteProtocolInfo;
  slim_char *PeerConnectionManager;
  slim_char *PeerConnectionID;
  slim_char *Direction;
};

/* CMS connection instance.  */
struct dmr_connection
{
  /* Flags.  */
  slim_word status;
#define DMR_STATUS_OK				0
#define DMR_STATUS_FORMAT_MISMATCH		1
#define DMR_STATUS_INSUFFICIENT_BANDWIDTH	2
#define DMR_STATUS_UNRELIABLE_CHANNEL		3
#define DMR_STATUS_UNKNOWN			4

  /* Connection ID.  */
  slim_word id;

  /* Peer connection ID.  */
  slim_word peer_id;

  /* UPnP transport ID.  */
  slim_int tid;

  /* Peer protocol info.  */
  slim_char *pinfo;

  /* Peer URI.  */
  slim_char *uri;
};

/* ConnectionManager service.  */
struct dmr_cms
{
  /* DMR service base structure.  */
  struct dmr_service base;

  /* Connection vector.  */
  struct _vector *v_conn;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus__ */

struct dmr_connection *
dmr_connection_lookup (struct dmr_cms *s, slim_char *id);

struct dmr_connection *
dmr_connection_lookup_by_tid(struct dmr_cms *cms, slim_int tid);

slim_int
dmr_connection_get (struct dmr_cms *s, slim_char *id, slim_char *pinfo, slim_char *uri, 
struct dmr_connection ** out_c);

slim_int
dmr_set_connection_info (struct dmr_cms *s, slim_char *id, slim_char *pinfo, slim_char *uri);

struct dmr_service *
dmr_cms_alloc (struct dmr *top);

slim_int
dmr_cms_free (struct dmr_service *s);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DMR_CMS_H */
