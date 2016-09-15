/*
	drm.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/inet/drm.h 9     05/12/28 12:07 Someya $ */

#ifndef SLIM_INET_DRM_H
#define SLIM_INET_DRM_H

SLIM_BEGIN_C_LINKAGE

typedef struct TDRMMediaObject_ TDRMMediaObject;
struct TDRMMediaObject_ {
	slim_int fContentType;
	TFixedString fContentID;
	slim_vhandle fContent;
	slim_int fContentLength;
	slim_int fCurrentLength;
	slim_opaque fUserData;	/* Don't set pointer to allocated memory */
};

typedef struct TDRMUsageContext_ TDRMUsageContext;
struct TDRMUsageContext_ {
	slim_int fDummy;
};

typedef struct TDRMManager_ TDRMManager;
struct TDRMManager_ {
	slim_int (*fGetMediaObject)(TDRMManager *self, TContent in_cont, TDRMUsageContext *in_ctx, TDRMMediaObject *out_mediaobj);
	slim_bool (*fIsForwardLocked)(TDRMManager *self, TContent in_cont);
	slim_opaque fUserData;
};

SLIM_END_C_LINKAGE
#endif

