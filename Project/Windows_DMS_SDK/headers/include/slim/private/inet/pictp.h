/*
	pictp.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/inet/pictp.h 18    05/12/28 12:08 Someya $ */

#ifndef SLIM_PICTP_H_PRIVATE
#define SLIM_PICTP_H_PRIVATE

SLIM_BEGIN_C_LINKAGE


enum {
	SLIM_PICTP_STATE_NEEDOPEN,
	SLIM_PICTP_STATE_NEEDREAD,
	SLIM_PICTP_STATE_DONE,
	SLIM_PICTP_STATES
};


#define iTPictpChannel_Class(self) ((TPictpChannelClass *)((iTContentChannel *)(self))->fClass)
#define iTPictpChannel_GetPictgramInfo(self, url) (iTPictpChannel_Class(self)->fGetInfoProc ? iTPictpChannel_Class(self)->fGetInfoProc((url), &(self)->fInfo) : slim_false)
#define iTPictpChannel_ReadPictgram(self, off, buf, len) (iTPictpChannel_Class(self)->fReadProc ? iTPictpChannel_Class(self)->fReadProc(&(self)->fInfo, (off), (buf), (len)) : -1)


#define TPictpChannel_Lock(self) ((iTPictpChannel *)slim_handle_lock((slim_handle)(self)))
#define TPictpChannel_Unlock(self) (slim_handle_unlock((slim_handle)(self)))
#define TPictpChannel_Locate(self) ((iTPictpChannel *)slim_handle_locate((slim_handle)(self)))
#define TPictpChannel_Unlocate(self) (slim_handle_unlocate((slim_handle)(self)))


SLIM_END_C_LINKAGE

#endif
