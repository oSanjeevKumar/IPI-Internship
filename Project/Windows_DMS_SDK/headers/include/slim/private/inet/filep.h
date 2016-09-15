/*
	filep.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/inet/filep.h 36    05/12/28 12:08 Someya $ */

#ifndef SLIM_FILEP_H_PRIVATE
#define SLIM_FILEP_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

/*              */
/* file: stream */
/*              */

#ifndef SLIM_FILEP_DEFREADCHUNK
#define SLIM_FILEP_DEFREADCHUNK 32767
#endif

#ifndef SLIM_FILEP_MAX_OPENS
#define SLIM_FILEP_MAX_OPENS 5
#endif

enum {
	SLIM_FILEP_STATE_NEEDSTREAM,
	SLIM_FILEP_STATE_NEEDCONTENT,
	SLIM_FILEP_STATE_NEEDCLOSE,
	SLIM_FILEP_STATE_DONE,
	SLIM_FILEP_STATES
};


#define TFilepChannel_Lock(self) ((iTFilepChannel *)slim_handle_lock((slim_handle)(self)))
#define TFilepChannel_Unlock(self) (slim_handle_unlock((slim_handle)(self)))
#define TFilepChannel_Locate(self) ((iTFilepChannel *)slim_handle_locate((slim_handle)(self)))
#define TFilepChannel_Unlocate(self) (slim_handle_unlocate((slim_handle)(self)))

/* protected member */

SLIM_END_C_LINKAGE

#endif
