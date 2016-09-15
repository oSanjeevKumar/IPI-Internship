/*
	postdata.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/inet/postdata.h 4     06/03/02 13:04 Iida $ */

#ifndef SLIM_POSTDATA_H_PRIVATE
#define SLIM_POSTDATA_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

#define TPostData_Lock(self) ((iTPostData *)slim_handle_lock((slim_handle)(self)))
#define TPostData_Unlock(self) (slim_handle_unlock((slim_handle)(self)))
#define TPostData_Locate(self) ((iTPostData *)slim_handle_locate((slim_handle)(self)))
#define TPostData_Unlocate(self) (slim_handle_unlocate((slim_handle)(self)))
#define TPostData_GetInt(self, off) (slim_handle_peek_int((slim_handle)(self), (off)))
#define TPostData_DataSize(self) (TPostData_GetInt((self), SLIM_OFFSETOF(iTPostData, fDataSize)))
#define TPostData_Encoding(self) (TPostData_GetInt((self), SLIM_OFFSETOF(iTPostData, fEncoding)))
#define TPostData_HasFile(self) (TPostData_GetInt((self), SLIM_OFFSETOF(iTPostData, fFlag)) & SLIM_POSTDATA_HAS_FILE)

#define TPostDataCursor_Buffer(self) ((self)->fBuffer + (self)->fOfflen.off)
#define TPostDataCursor_BufferLength(self) ((self)->fOfflen.len)

#ifdef SLIM_CONFIG_POSTDATA_DEBUG
#define SLIM_POSTDATA_DP(arg) SLIM_DP((arg))
#else
#define SLIM_POSTDATA_DP(arg) ((void)0)
#endif

SLIM_END_C_LINKAGE
#endif
