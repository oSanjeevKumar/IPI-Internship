/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */
/* Copyright (C) 2011 Access Co. Ltd. All Rights Reserved.  */

#ifndef _DMPR_JOB_H
#define _DMPR_JOB_H


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

TDMPrJob *dmpr_job_alloc();
slim_int dmpr_job_free(  TDMPrJob *in_job);
slim_int	dmpr_job_copy( TDMPrJob *dst, TDMPrJob *src );
slim_int		dmpr_job_add(struct dmpr *self, TDMPrJob *in_job);
slim_int	dmpr_job_delete(struct dmpr *self, slim_int in_job_id);
TDMPrJob *	dmpr_job_lookup(struct dmpr *self, slim_int in_job_id);
TDMPrJob *	dmpr_job_update(struct dmpr *self, TDMPrJob *in_job);

slim_int	dmpr_job_free_all(struct dmpr *self);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _DMPR_JOB_H */
