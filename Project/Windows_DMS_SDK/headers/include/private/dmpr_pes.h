/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

#ifndef _DMPR_PES_H
#define _DMPR_PES_H

/* PrintEnhanced:1 Service Template Version 1.01.  */

/* PrintEnhanced service.  */
struct dmpr_pes
{
  /* DMPr service base structure.  */
  struct dmpr_service base;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct dmpr_service *
dmpr_pes_alloc (struct dmpr *top);

int
dmpr_pes_free (struct dmpr_service *service);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _DMPR_PES_H */
