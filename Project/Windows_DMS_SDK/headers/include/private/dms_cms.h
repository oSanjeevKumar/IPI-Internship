/*
 * dms_cms.h
 * Copyright (C) 2007 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */

#ifndef NFLC_DMS_CMS_H
#define NFLC_DMS_CMS_H

/* ConnectionManager service.  */
struct dms_cms
{
  /* DMS service base structure.  */
  struct dms_service base;
  
  /* Media manager for SourceProtocolInfo */
  media_manager_t *mim;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus__ */

struct dms_service *
dms_cms_alloc (struct dms *top, media_manager_t *mim);

void
dms_cms_free (struct dms_service *s);

slim_char *
dms_source_pinfo_str(struct dms_cms *s);

slim_char *
dms_source_pinfo_str_for_upload(struct dms_cms *s);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DMS_CMS_H */
