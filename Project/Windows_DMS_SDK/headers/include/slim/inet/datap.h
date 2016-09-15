/*
	datap.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/inet/datap.h 13    06/06/20 19:24 Yamabuti $ */

#ifndef SLIM_DATAP_H
#define SLIM_DATAP_H

SLIM_BEGIN_C_LINKAGE


typedef struct iTDatapChannel_ iTDatapChannel;
typedef TContentChannel TDatapChannel;

struct iTDatapChannel_ {
	iTContentChannel fBase;
	TURLString fURL;
	slim_bool fBase64Encoding;
	slim_int fDataOffset;/*data part offset from url start point.*/
};

struct TDatapChannelClass_ {
	TContentChannelClass fBase;
};
typedef struct TDatapChannelClass_ TDatapChannelClass;

#define SLIM_DATAP_E_NOMEM SLIM_E_NOMEM
enum {
	SLIM_DATAP_E_OPEN = SLIM_DATAP_ERROR_START,
	SLIM_DATAP_E_READ,
	SLIM_DATAP_ERROR_END
};

SLIM_END_C_LINKAGE
#endif
