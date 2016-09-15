/*
 * twine_manager_impl.h
 * Copyright (C) 2007-2015 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

/* Twine manager.  */

#ifndef TWINE_MANAGER_IMPL_H
#define TWINE_MANAGER_IMPL_H


#define TGS_DEFAULT_UPDATE_INTERVAL 300
#define TGS_MIN_UPDATE_INTERVAL 5

struct twine_manager{
	void *top ;
	void	*transportmanager_context ;
	dlna_progress	em ;
	dlna_progress_handle ready_progress;
	dlna_progress_handle update_transport_event;

	TTWINEListenerCallback twine_update_cb ;
	void	*twine_update_cb_arg ;
//  slim_int fl_update_required ;
} ;


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef __cplusplus
}
#endif /* __cplusplus */




#endif /* TWINE_MANAGER_IMPL_H */
