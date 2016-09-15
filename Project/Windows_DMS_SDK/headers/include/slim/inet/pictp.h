/*
	pictp.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/inet/pictp.h 16    05/12/28 12:07 Someya $ */

#ifndef SLIM_PICTP_H
#define SLIM_PICTP_H

SLIM_BEGIN_C_LINKAGE

#define SLIM_PICTP_E_NOMEM SLIM_E_NOMEM
enum {
	SLIM_PICTP_E_NOENT = SLIM_PICTP_ERROR_START,
	SLIM_PICTP_E_READ,
	SLIM_PICTP_ERROR_END
};

typedef struct TPictgramInfo_ TPictgramInfo;
struct TPictgramInfo_ {
	slim_opaque fID;
	slim_int fSize;
	slim_int fMIMEType;
};

typedef struct iTPictpChannel_ iTPictpChannel;
struct iTPictpChannel_ {
	iTContentChannel fBase;
	TPictgramInfo fInfo;
};

typedef TContentChannel TPictpChannel;

typedef slim_bool (*PictpChannel_GetInfoProc)(TURLString in_url, TPictgramInfo *out_info);
typedef slim_int (*PictpChannel_ReadProc)(TPictgramInfo *in_info, slim_int in_offset, void *out_buf, slim_int in_buf_len);

struct TPictpChannelClass_ {
	TContentChannelClass fBase;
	PictpChannel_GetInfoProc fGetInfoProc;
	PictpChannel_ReadProc fReadProc;
};
typedef struct TPictpChannelClass_ TPictpChannelClass;

/* API */
#define PictpChannel_SetGetInfoProc(cls, proc) ((cls)->fGetInfoProc = (proc))
#define PictpChannel_SetReadProc(cls, proc) ((cls)->fReadProc = (proc))

SLIM_END_C_LINKAGE
#endif
