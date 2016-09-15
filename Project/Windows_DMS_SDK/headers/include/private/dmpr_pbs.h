/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

#ifndef _DMPR_PBS_H
#define _DMPR_PBS_H

/* PrintBasic:1 Service Template Version 1.01.  */

/* PrintBasic service.  */
struct dmpr_pbs
{
  /* DMPr service base structure.  */
  struct dmpr_service base;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct dmpr_service *
dmpr_pbs_alloc (struct dmpr *top);

int
dmpr_pbs_free (struct dmpr_service *service);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _DMPR_PBS_H */
