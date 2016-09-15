/*
	aboutch.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/inet/aboutch.h 8     05/12/28 12:07 Someya $ */

#ifndef SLIM_ABOUT_CHANNEL_H
#define SLIM_ABOUT_CHANNEL_H

SLIM_BEGIN_C_LINKAGE

typedef struct iTAboutChannel_ iTAboutChannel;
struct iTAboutChannel_ {
	iTContentChannel fBase;
};

typedef iTAboutChannel **TAboutChannel;

typedef slim_int (*AboutChannel_WriteContentProc)(iTAboutChannel *base, TContentSpec in_spec, slim_split_ss *in_ss, slim_opaque in_userdata, slim_int *out_mimetype);

typedef struct TAboutChannelClass_ TAboutChannelClass;
struct TAboutChannelClass_ {
	TContentChannelClass fBase;
	AboutChannel_WriteContentProc fWriteContent;
};

SLIM_END_C_LINKAGE
#endif
