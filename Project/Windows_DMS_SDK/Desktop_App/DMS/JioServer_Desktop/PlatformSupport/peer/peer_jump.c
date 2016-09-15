/*
 * peer_jump.c
 * Copyright (C) 2007-2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

#include <dlna_peer.h>
#include <setjmp.h>

#define MAX_JMP_BUF_SIZE 20

struct dlna_jmp_buf_elem
{
  dlna_jmp_buf  buf;
  DWORD         nThreadID;
  BOOLEAN       bActive;
};

struct dlna_jmp_buf_list
{
  struct dlna_jmp_buf_elem JmpBufList[MAX_JMP_BUF_SIZE];
  slim_int nCount;
};

static dlna_jmp_buf *
dlnaJumpGetBufferPeer(BOOLEAN bSetJmp)
{
  static struct dlna_jmp_buf_list s_JumpBufferList;
  static slim_int s_nInitializer = 0;
  dlna_jmp_buf* pBuf = NULL;

  // Initialize the jump buffer list
  if (0 == s_nInitializer) {
    s_nInitializer++;
    s_JumpBufferList.nCount = 0;
  }

  // sanity check
  if (s_JumpBufferList.nCount < 0) {
    return NULL;
  }
  if (TRUE == bSetJmp) {
    // In this case, this is a set jmp, use a new buffer and increase the count
    if (s_JumpBufferList.nCount < MAX_JMP_BUF_SIZE) {
      s_JumpBufferList.JmpBufList[s_JumpBufferList.nCount].nThreadID = GetCurrentThreadId();
      s_JumpBufferList.JmpBufList[s_JumpBufferList.nCount].bActive = TRUE;
      pBuf = &(s_JumpBufferList.JmpBufList[s_JumpBufferList.nCount].buf);
      s_JumpBufferList.nCount++;
    }
  } else {
    // In this case, used by long jmp, return a previous buffer used by set jmp
    if ( s_JumpBufferList.nCount > 0 ) {
      // Find the proper buffer to return based on the thread ID
      slim_int nIndex = s_JumpBufferList.nCount - 1;
      while ( (nIndex > 0) && GetCurrentThreadId() != s_JumpBufferList.JmpBufList[s_JumpBufferList.nCount-1].nThreadID ) {
        nIndex--;
      }
      // If we found one to return, then use that buffer
      if (nIndex > -1) {
        pBuf = &(s_JumpBufferList.JmpBufList[nIndex].buf);
        s_JumpBufferList.JmpBufList[nIndex].bActive = FALSE;

        /* Now go down the list and decrement the count to represent the
           next valid index.*/
        if (nIndex == s_JumpBufferList.nCount - 1) {
          while ( (s_JumpBufferList.nCount > 0) && 
                 !(s_JumpBufferList.JmpBufList[s_JumpBufferList.nCount-1].bActive) ) {
            s_JumpBufferList.nCount--;
          }
        }
      }
    }
  }
  return pBuf;
}

dlna_jmp_buf *
dlnaSetJmpGetBufferPeer(void)
{
  return dlnaJumpGetBufferPeer(TRUE);
}

dlna_jmp_buf *
dlnaLongJmpGetBufferPeer(void)
{
  return dlnaJumpGetBufferPeer(FALSE);
}
