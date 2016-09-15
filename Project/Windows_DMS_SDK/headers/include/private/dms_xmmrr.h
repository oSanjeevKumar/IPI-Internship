/*
 * dms_xmmrr.h
 * Copyright (C) 2007-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */

#ifndef NFLC_DMS_XMMRR_H
#define NFLC_DMS_XMMRR_H

#include "nflc_dms.h"

/* X_MS_MediaReceiverRegistrar service.  */
struct dms_xmmrr
{
  /* DMS service base structure.  */
  struct dms_service base;

  /* SOAP action.  */
  sXML *action_doc;

  /* SOAP result document.  */
  sXML *result_doc;

  /* Incomming interface index used for the XML resources.  */
  slim_int ifindex;
};


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct dms_service *
dms_xmmrr_alloc (struct dms *top);

int
dms_xmmrr_free (struct dms_service *s);

slim_int
dms_xmmrr_init (struct dms_xmmrr *s);

slim_char*
map_xmmrr_virtual_structure (slim_char *id);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DMS_XMMRR_H */
