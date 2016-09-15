/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

#ifndef _DMPR_PELS_H
#define _DMPR_PELS_H

/* PrintEnhancedLayout:1 Service Template Version 1.01.  */

/* PrintEnhancedLayout service.  */
struct dmpr_pels
{
  /* DMPr service base structure.  */
  struct dmpr_service base;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct dmpr_service *
dmpr_pels_alloc (struct dmpr *top);

slim_int
dmpr_pels_free (struct dmpr_service *service);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _DMPR_PELS_H */
