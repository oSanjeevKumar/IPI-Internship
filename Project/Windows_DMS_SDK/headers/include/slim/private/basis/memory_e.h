/*
	memory_e.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/basis/memory_e.h 11    05/12/28 12:08 Someya $ */

#ifndef SLIM_MEMORY_EXTERNAL_H_PRIVATE
#define SLIM_MEMORY_EXTERNAL_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

/* multithread */
void slim_memory_mutex_lock(void);
void slim_memory_mutex_unlock(void);

/* handle */
slim_int slim_handle_peek_int(slim_handle in_handle, slim_int in_offset);
slim_short slim_handle_peek_short(slim_handle in_handle, slim_int in_offset);
slim_pix slim_handle_peek_pix(slim_handle in_handle, slim_int in_offset);
slim_handle slim_handle_peek_handle(slim_handle in_handle, slim_int in_offset);
slim_vhandle slim_handle_peek_vhandle(slim_handle in_handle, slim_int in_offset);
void *slim_handle_peek_ptr(slim_handle in_handle, slim_int in_offset);
slim_opaque slim_handle_peek_opaque(slim_handle in_handle, slim_int in_offset);

/* vhandle */
slim_int slim_vhandle_peek_int(slim_vhandle in_vhandle, slim_int in_offset);
slim_short slim_vhandle_peek_short(slim_vhandle in_vhandle, slim_int in_offset);
slim_pix slim_vhandle_peek_pix(slim_vhandle in_vhandle, slim_int in_offset);
slim_handle slim_vhandle_peek_handle(slim_vhandle in_vhandle, slim_int in_offset);
slim_vhandle slim_vhandle_peek_vhandle(slim_vhandle in_vhandle, slim_int in_offset);
void *slim_vhandle_peek_ptr(slim_vhandle in_vhandle, slim_int in_offset);
slim_opaque slim_vhandle_peek_opaque(slim_vhandle in_vhandle, slim_int in_offset);

/* MemNode */ 

slim_bool MemNode_IsPixInSamePage(slim_int in_off1, slim_int in_off2);
slim_bool TMemNode_Initialize(TMemNode *self);
void TMemNode_Finalize(TMemNode *self);
slim_handle TMemNode_GetPageHandle(TMemNode *self, slim_int in_off);
slim_handle TMemNode_GetPageHandleAndCheck(TMemNode *self, slim_int in_off);
slim_handle TMemNode_ZeroAlloc(TMemNode *self, slim_int in_offset);
void *TMemNode_Lock(TMemNode *self, slim_int in_offset, slim_handle *out_locked_handle);
void TMemNode_Unlock(TMemNode *self, slim_int in_offset);
void *TMemNode_Locate(TMemNode *self, slim_int in_offset);
void TMemNode_Unlocate(TMemNode *self, slim_int in_offset);

slim_pix TMemNode_PeekPix(TMemNode *self, slim_int in_off);

void TMemNode_Free(TMemNode *self, slim_int in_offset);
void TMemNode_FreeAll(TMemNode *self);

slim_int TMemNode_UsedPages(TMemNode *self);
slim_int TMemNode_TotalPages(TMemNode *self);

/*
 * Debug
 */

#define slim_memory_debug_is_alloc_failure() (slim_false)
#define slim_memory_debug_set_random_alloc_failure_proc(proc) ((void)0)

#define slim_memory_block_from(addr) (0)
#define slim_memory_block_set_from(addr, from) ((void)0)

#define TMemNode_IsValidPix(self,pix)	(slim_true)
#define TMemNode_IsValidPixOrNil(self,pix)	(slim_true)

#define TMemNode_LocateX(self,off) (TMemNode_Locate((self),(off)))
#define TMemNode_UnlocateX(self,off) (TMemNode_Unlocate((self),(off)))

#define MemNode_DebugSetNotifyProc(proc) ((void)0)
#define TMemNode_DebugNotifyAlloc(self, off, size) ((void)0)
#define TMemNode_DebugNotifyFree(self, off) ((void)0)
#define TMemNode_DebugNotifyLocate(self, off, count) ((void)0)
#define TMemNode_VerifyPix(self, off) ((void)0)

SLIM_END_C_LINKAGE
#endif /* SLIM_MEMORY_EXTERNAL_H */
