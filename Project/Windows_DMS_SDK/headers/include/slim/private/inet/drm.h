/*
	drm.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/inet/drm.h 11    05/12/28 12:08 Someya $ */

#ifndef SLIM_INET_DRM_H_PRIVATE
#define SLIM_INET_DRM_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

enum {
	SLIM_DRMMAN_E_begin = SLIM_E_enum_tail,
	SLIM_DRMMAN_E_DENIED = SLIM_E_enum_tail - 1,
	SLIM_DRMMAN_E_end = SLIM_E_enum_tail - 2
};
	

#define TDRMManager_GetMediaObject(self, in_cont, in_context, out_mediaobj) ((*(self)->fGetMediaObject)((self),(in_cont),(in_context),(out_mediaobj)))
#define TDRMManager_IsForwardLocked(self, in_cont) ((*(self)->fIsForwardLocked)((self),(in_cont)))
#define TDRMManager_Initialize(self,getmo,isfl,arg) ((self)->fGetMediaObject = (getmo), (self)->fIsForwardLocked = (isfl), (self)->fUserData = (arg))

#define TDRMMediaObject_Content(self) ((self)->fContent)
#define TDRMMediaObject_ContentLength(self) ((self)->fContentLength)
#define TDRMMediaObject_CurrentLength(self) ((self)->fCurrentLength)
#define TDRMMediaObject_ContentType(self) ((self)->fContentType)
#define TDRMMediaObject_ContentID(self) ((self)->fContentID)
#define TDRMMediaObject_UserData(self) ((self)->fUserData)
#define TDRMMediaObject_SetContentLength(self,len) ((self)->fContentLength = (len))
#define TDRMMediaObject_SetCurrentLength(self,len) ((self)->fCurrentLength = (len))
#define TDRMMediaObject_SetContentType(self,type) ((self)->fContentType = (type))
#define TDRMMediaObject_SetUserData(self,user_data) ((self)->fUserData = (user_data))

#define TDRMMediaObject_Copy(self, obj) (*(self) = *(obj))


#define TDRMUsageContext_IsEqual(self, ctx) (slim_true)
#define TDRMUsageContext_Copy(self, ctx) (*(self) = *(ctx))

SLIM_END_C_LINKAGE
#endif
