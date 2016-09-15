/*
 * peer_thread.c
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
#include "peer_thread.h"

#if defined(WINAPI_PARTITION_DESKTOP) || defined(WINAPI_PARTITION_PC_APP) || defined(WINAPI_PARTITION_PHONE_APP)
#define _endthreadex ExitThread
#define _beginthreadex CreateThread
#endif

HANDLE get_current_thread()
{
  HANDLE result = INVALID_HANDLE_VALUE;
  DuplicateHandle(GetCurrentProcess(),
    GetCurrentThread(),
    GetCurrentProcess(),
    &result,
    DUPLICATE_SAME_ACCESS,
    FALSE,
    0);
  CloseHandle(result);
  return result;
}

slim_bool dlnaThreadMutexLockPeer(dlna_mutex self)
{
  if (!self) {
    DLNA_LOG(DLNA_LOG_PEER_THREAD, DLNA_LOG_LEVEL_ERROR, "dlnaThreadMutexLockPeer!!!");
    return slim_false;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)self);
  return slim_true;
}

slim_bool dlnaThreadMutexUnlockPeer(dlna_mutex self)
{
  if (!self) {
    DLNA_LOG(DLNA_LOG_PEER_THREAD, DLNA_LOG_LEVEL_ERROR, "dlnaThreadMutexUnlockPeer!!!");
    return slim_false;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)self);
  return slim_true;
}

dlna_mutex dlnaThreadMutexAllocPeer()
{
  LPCRITICAL_SECTION pzCS = (LPCRITICAL_SECTION)malloc(sizeof(CRITICAL_SECTION));
  if (!pzCS) return (dlna_mutex)slim_nil;
#if (_WIN32_WINNT >= 0x0603 /*_WIN32_WINNT_WIN8*/)
  InitializeCriticalSectionEx(pzCS, 0, 0);
#else
  InitializeCriticalSection(pzCS);
#endif
  return (dlna_mutex)pzCS;
}

void dlnaThreadMutexFreePeer(dlna_mutex self)
{
  if (self) {
    DeleteCriticalSection((LPCRITICAL_SECTION)self);
    free(self);
  }
}

dlna_thread dlnaThreadAllocPeer(dlna_thread_proc in_proc,
								void *in_arg)
{
  thread_info *pt = slim_nil;
  if (!in_proc) return slim_nil;
  pt = (thread_info *)malloc(sizeof(thread_info));
  if (!pt) return slim_nil;
  pt->thread_proc = in_proc;
  pt->thread_proc_param = in_arg;
  return (dlna_thread)pt;
}

void dlnaThreadFreePeer(dlna_thread self)
{
  thread_info *pt = (thread_info *)self;
  if (pt) {
    if (pt->handle)
      CloseHandle(pt->handle);
      free(pt);
  }
}

slim_int dlnaThreadStartPeer(dlna_thread self)
{
  thread_info *pt = (thread_info *)self;
  if (!pt) return SLIM_E_GENERIC;
  pt->handle = (HANDLE)_beginthreadex(NULL, 0, (unsigned int (__stdcall *)(void *))pt->thread_proc, pt->thread_proc_param, 0, &pt->id);
  return SLIM_E_OK;
}

void dlnaThreadWaitForExitPeer(dlna_thread self)
{
  thread_info *pt = (thread_info *)self;
  DWORD idself, idtarget;
  if (!pt) return;
  idself = GetCurrentThreadId();
  idtarget = pt->id;
  if (idself == idtarget) return;
#if (_WIN32_WINNT >= 0x0603 /*_WIN32_WINNT_WIN8*/)
  WaitForSingleObjectEx(pt->handle, INFINITE, slim_false);
#else
  WaitForSingleObject(pt->handle, INFINITE);
#endif
}

void dlnaThreadSleepPeer(slim_word in_time_us)
{
  Sleep(in_time_us / 1000);
}

slim_bool dlnaThreadIsSelf(dlna_thread self)
{
  thread_info *pt = (thread_info *)self;
  if (!pt) return slim_false;
  return (slim_bool)pt->handle == get_current_thread;
}

void dlnaThreadGetSelf(dlna_thread self)
{
  thread_info *arg = (thread_info *)self;
  if (!arg) {
    DLNA_LOG(DLNA_LOG_PEER_THREAD, DLNA_LOG_LEVEL_ERROR,"[DLNA_THREAD_PEAR] Get curret thread id -> Null pointer");
    return;
  }
  arg->handle = get_current_thread();
  arg->thread_proc = slim_nil;
  arg->thread_proc_param = slim_nil;
}

slim_bool dlnaThreadSetPolicy(dlna_thread thread,
							  enum dlna_thread_policy policy)
{
  return slim_true;
}

slim_bool dlnaThreadSetPriority(dlna_thread thread,
								slim_int priority)
{
  slim_bool ret = slim_false;
  slim_int prev_priority;
  thread_info *info = (thread_info*)thread;;

  if (!info) {
    DLNA_LOG(DLNA_LOG_PEER_THREAD, DLNA_LOG_LEVEL_ERROR, "[DLNA_THREAD_PEER] Dlna_thread null pointer ");
    return slim_false;
  }

  ret = dlnaThreadGetPriority(thread, &prev_priority);
  if (ret && (priority != prev_priority)) {
    if (info->handle && info->thread_proc_param) {
      ret = SetThreadPriority(info->handle, priority);
      DLNA_LOG(DLNA_LOG_PEER_THREAD, DLNA_LOG_LEVEL_DEBUG, "[DLNA_THREAD_PEER] Set priority called %d ", priority);
    } else {
      DLNA_LOG(DLNA_LOG_PEER_THREAD, DLNA_LOG_LEVEL_DEBUG, "[DLNA_THREAD_PEER] Set priority call failed %d ", priority);
    }
  }
  return ret;
}

slim_bool dlnaThreadGetPolicy(dlna_thread thread,
							  enum dlna_thread_policy *policy)
{
  *policy = Dlna_Thread_Policy_RoundRobin;
  return slim_true;
}

slim_bool dlnaThreadGetPriority(dlna_thread thread,
								slim_int *priority)
{
  slim_int ret;
  thread_info *info = (thread_info*)thread;

  if (info && info->handle && info->thread_proc_param) {
    ret = GetThreadPriority(info->handle);
    if (ret != THREAD_PRIORITY_ERROR_RETURN) {
      *priority = ret;
      DLNA_LOG(DLNA_LOG_PEER_THREAD, DLNA_LOG_LEVEL_ERROR, "[DLNA_THREAD_PEER] Getpriority called = %d", ret);
      return slim_true;
    } else {
      DLNA_LOG(DLNA_LOG_PEER_THREAD, DLNA_LOG_LEVEL_ERROR, "[DLNA_THREAD_PEER] THREAD_PRIORITY_ERROR_RETURN ");
    }
  }
  return slim_false;
}

slim_int dlnaThreadGetMinPriority(enum dlna_thread_policy policy)
{
  return THREAD_PRIORITY_ABOVE_NORMAL;
}

slim_int dlnaThreadGetMaxPriority(enum dlna_thread_policy policy)
{
  return THREAD_PRIORITY_HIGHEST;
}
