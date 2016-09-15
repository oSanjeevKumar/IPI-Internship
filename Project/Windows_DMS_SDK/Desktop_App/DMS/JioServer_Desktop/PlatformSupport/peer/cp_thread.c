/* cp_thread.c
* Copyright (C) 2011 ACCESS CO.,LTD.
* All rights are reserved by ACCESS CO.,LTD., whether the whole or part
* of the source code including any modifications is concerned.
*
* This is an unpublished source code of ACCESS CO.,LTD., and must be
* treated as confidential material.  The above copyright notice does
* not evidence any actual or intended publication of this source code.
*/

#include <dlna_peer.h>
#include <stdlib.h>


#if defined(UNDER_CE) || defined(WINAPI_PARTITION_DESKTOP) || defined(WINAPI_PARTITION_PC_APP) || defined(WINAPI_PARTITION_PHONE_APP)
#define _endthreadex ExitThread
#define _beginthreadex CreateThread
#else
#include <process.h>
#endif

#include "cp_thread.h"

struct cp_thread_info
{
	struct cp_thread base;
	HANDLE hThread;
};

// The start of a thread, calls the underlying function with the arguments 
static unsigned __stdcall cp_thread_main( LPVOID pThdInfo )
{
  thread_args_t* pArgs = (thread_args_t*) pThdInfo;
  //busy loop inside func() --> event_loop
  DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_DEBUG, "cp_thread_main started");
  pArgs->func( pArgs->args );
  DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_DEBUG, "cp_thread_main exit.");
  return 0;
}

// Start a windows thread using _beginthreadex, returns a thread record that can be later used 
struct cp_thread *
cp_thread_start (thread_func func, void* args)
{
  struct cp_thread_info *prThread;
  unsigned int		nThreadID;

  prThread = (struct cp_thread_info *) malloc(sizeof (struct cp_thread_info));
  prThread->base.args.func = func;
  prThread->base.args.args = args;
  prThread->base.args.bContinue = TRUE;

  prThread->hThread = (HANDLE) _beginthreadex( NULL, 0, &cp_thread_main, (void*) &(prThread->base.args), 0, &nThreadID );
  DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_ERROR, "cp_thread_start:id:%d", nThreadID);
  prThread->base.id = nThreadID;

  return &prThread->base;
}

// Wait for the thread to exit
int
cp_thread_wait_exit (struct cp_thread *thread)
{
  struct cp_thread_info *prThread = (struct cp_thread_info *) thread;
  DWORD nStatus, idself, idtarget;
  
#if (_WIN32_WINNT >= 0x0602 /*_WIN32_WINNT_WIN8*/)
  nStatus = WaitForSingleObjectEx((prThread)->hThread, INFINITE, slim_false);
#else
  DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_DEBUG, "WaitForSingleObject enter.");
  nStatus = WaitForSingleObject((prThread)->hThread, INFINITE);
  DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_DEBUG, "WaitForSingleObject exit.");
#endif

  if ( nStatus == WAIT_TIMEOUT ) {
    // Timeout while waiting for thread to exit...
    return FALSE;
  }

  DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_ERROR, "CloseHandle of thread id:%d.", prThread->base.id);
  CloseHandle ( prThread->hThread );
  free( prThread );
  prThread = NULL;
  return TRUE;
}

// Tell the thread to stop looping
void
cp_thread_stop (struct cp_thread *thread)
{
  DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_ERROR, "cp_thread_stop enter.");
  /*_endthreadex is not required as we are exiting from WaitForSingleObject,
  Keeping this method for future if we need to handle in stop case.
  */
  //_endthreadex(0);
  DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_ERROR, "cp_thread_stop exit.");
}
