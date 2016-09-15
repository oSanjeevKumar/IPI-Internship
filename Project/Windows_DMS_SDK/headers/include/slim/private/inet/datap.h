/*
	datap.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/inet/datap.h 16    06/06/20 19:24 Yamabuti $ */

#ifndef SLIM_DATAP_H_PRIVATE
#define SLIM_DATAP_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

enum {
	SLIM_DATAP_STATE_NEEDDECODE,
	SLIM_DATAP_STATE_DONE,
	SLIM_DATAP_STATES
};

#define iTDatapChannel_Class(self) ((TDatapChannelClass *)((iTContentChannel *)(self))->fClass)


#define TDatapChannel_Lock(self) ((iTDatapChannel *)slim_handle_lock((slim_handle)(self)))
#define TDatapChannel_Unlock(self) (slim_handle_unlock((slim_handle)(self)))
#define TDatapChannel_Locate(self) ((iTDatapChannel *)slim_handle_locate((slim_handle)(self)))
#define TDatapChannel_Unlocate(self) (slim_handle_unlocate((slim_handle)(self)))


SLIM_END_C_LINKAGE

#endif
