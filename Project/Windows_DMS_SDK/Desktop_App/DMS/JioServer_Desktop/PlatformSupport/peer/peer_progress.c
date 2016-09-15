/*
 * peer_progress.c
 * Copyright (C) 2007-2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#include <dlna_peer.h>
#include "peer_progress.h"
#include <cp_thread.h>

dlna_progress dlnaProgressAllocPeer(void)
{
	return (dlna_progress)event_manager_alloc();
}

void dlnaProgressFreePeer(dlna_progress in_p)
{
	struct event_manager *em = (struct event_manager *)in_p;
	event_manager_free(em);
}

void dlnaProgressStartPeer(dlna_progress in_p)
{
	struct event_manager *em = (struct event_manager *)in_p;

	if (CHECK_FLAG(em->flags, EVENT_FLAG_LOOP)) return;
	
	em->init(em);
	em->t_loop = cp_thread_start((void *)em->loop, (void *)em);
	if (!em->t_loop) return;
	
	SET_FLAG(em->flags, EVENT_FLAG_LOOP);
	
	event_signal_wakeloop(em);
}

void dlnaProgressStopPeer(dlna_progress in_p)
{
  struct event_manager *em = (struct event_manager *)in_p;
  DLNA_FUNC_ENTER(dlnaProgressStopPeer);
  if (!CHECK_FLAG(em->flags, EVENT_FLAG_LOOP)) {
    DLNA_LOG(DLNA_LOG_PEER_PROGRESS, DLNA_LOG_LEVEL_ERROR, "EVENT_FLAG_LOOP is not set in dlnaProgressStopPeer()");
    return;
  }
	
  dlnaProgressLockPeer(in_p);
	
  // stop the event
  em->stop(em);

  // stop the thread
  if (em->t_loop)
    cp_thread_stop(em->t_loop);

  UNSET_FLAG(em->flags, EVENT_FLAG_LOOP);

  dlnaProgressUnlockPeer(in_p);
  cp_thread_wait_exit(em->t_loop);
  em->t_loop = NULL;
  DLNA_FUNC_EXIT(dlnaProgressStopPeer);
}

slim_bool dlnaEventManagerLockPeer(dlna_progress in_p)
{
	struct event_manager* em = (struct event_manager *)in_p;
	if(!em) {
		DLNA_LOG(DLNA_LOG_PEER_PROGRESS, DLNA_LOG_LEVEL_ERROR, "dlnaEventManagerLockPeer!!!");
		return slim_false;
	}
	EnterCriticalSection(em->pzCS_em);
	return slim_true;
}

slim_bool dlnaEventManagerUnlockPeer(dlna_progress in_p)
{
	struct event_manager* em = (struct event_manager *)in_p;
	if(!em) {
		DLNA_LOG(DLNA_LOG_PEER_PROGRESS, DLNA_LOG_LEVEL_ERROR, "dlnaEventManagerUnlockPeer!!!");
		return slim_false;
	}
	LeaveCriticalSection(em->pzCS_em);
	return slim_true;
}

slim_bool dlnaProgressLockPeer(dlna_progress in_p)
{
	struct event_manager* em = (struct event_manager *)in_p;
	EnterCriticalSection(em->pzCS);
	return slim_true;
}

slim_bool dlnaProgressUnlockPeer(dlna_progress in_p)
{
	struct event_manager* em = (struct event_manager *)in_p;
	LeaveCriticalSection(em->pzCS);
	return slim_true;
}

dlna_progress_handle dlnaProgressEventAddPeer(dlna_progress in_p,
											  dlna_progress_callback in_func,
											  void *in_arg)
{
	struct event_manager *em = (struct event_manager *)in_p;
	struct event *e = event_add_event(em, (EVENT_CALLBACK)in_func, in_arg);
	
	return (dlna_progress_handle)e;
}

void dlnaProgressEventRemovePeer(dlna_progress in_p,
								 dlna_progress_callback in_func,
								 void *in_arg,
								 enum dlna_event_remove_mode in_remove_mode)
{
	// TODO: dlnaProgressEventRemovePeer
	//event_remove_events_with_specific_arg_or_callback((struct event_manager *) in_p, in_remove_mode, in_arg, in_func);
}

dlna_progress_handle dlnaProgressReadAddPeer(dlna_progress in_p,
											 dlna_progress_io_callback in_func,
											 void *in_arg,
											 slim_int in_desc)
{
	struct event_manager *em = (struct event_manager *)in_p;
	struct event *e = event_add_read(em, (EVENT_IO_CALLBACK)in_func, in_arg, in_desc);
	
	return (dlna_progress_handle)e;
}

dlna_progress_handle dlnaProgressWriteAddPeer(dlna_progress in_p,
											  dlna_progress_io_callback in_func,
											  void *in_arg,
											  slim_int in_desc)
{
	struct event_manager *em = (struct event_manager *)in_p;
	struct event *e = event_add_write(em, (EVENT_IO_CALLBACK)in_func, in_arg, in_desc);
	
	return (dlna_progress_handle)e;
}

dlna_progress_handle dlnaProgressTimerAddPeer(dlna_progress in_p,
											  dlna_progress_callback in_func,
											  void *in_arg,
											  dlna_timeval *in_timeval)
{
	struct event_manager *em = (struct event_manager *)in_p;
	if (!em) {
		DLNA_LOG(DLNA_LOG_PEER_PROGRESS, DLNA_LOG_LEVEL_ERROR, "dlnaEventManagerLockPeer!!!");
		return slim_nil;
	}
	struct event *e = event_add_timer(em, (EVENT_CALLBACK)in_func, in_arg, in_timeval);
	
	return (dlna_progress_handle)e;
}

void dlnaProgressEntryCancelPeer(dlna_progress in_p,
								 dlna_progress_handle in_pdesc)
{
	event_cancel((struct event *)in_pdesc);
}

void
dlnaProgressEntryCancelByArgPeer (dlna_progress in_p,  void *in_arg)
{
  struct event_manager *em = (struct event_manager *) in_p;

  if (em && in_arg) {
	  event_cancel_event (em, in_arg);
  }
}

