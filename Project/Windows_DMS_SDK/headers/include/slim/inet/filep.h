/*
	filep.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/inet/filep.h 38    06/07/13 21:15 Siu $ */

#ifndef SLIM_FILEP_H
#define SLIM_FILEP_H

SLIM_BEGIN_C_LINKAGE

typedef struct iTFilepChannel_ iTFilepChannel;
struct iTFilepChannel_ {
	iTContentChannel fBase;	/* inherited: must be the first field */
	slim_int fStream;
};

typedef struct TFilepChannelClass_ TFilepChannelClass;

struct TFilepChannelClass_ {
	TContentChannelClass fBase;
	slim_int fObjectSize;
	slim_int fOpens;
	slim_int fReadChunk;
	slim_int (*fFileOpenPeer)(slim_char *in_fname, slim_int in_flag);
	void (*fFileClosePeer)(slim_int in_desc);
	slim_int (*fFileReadPeer)(slim_int in_desc, void *out_buf, slim_int in_len);

	slim_bool (*fInit)(iTFilepChannel *iself, TFilepChannelClass *in_class, TContentSpec in_spec, slim_int in_flag);
	slim_int (*fDoOpen)(iTFilepChannel *iself, TContentSpec in_spec, TURLString in_url);
	slim_int (*fDoRead)(iTFilepChannel *iself, TContentSpec in_spec);
	void (*fDoClose)(iTFilepChannel *iself);
};

/* errors */
#define SLIM_FILEP_E_GENERIC SLIM_E_GENERIC
enum {
	SLIM_FILEP_E_OPEN = SLIM_FILEP_ERROR_START,
	SLIM_FILEP_E_READ,
	SLIM_FILEP_ERROR_END
};


SLIM_END_C_LINKAGE
#endif
