/*
	mime.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/inet/mime.h 41    05/12/28 12:08 Someya $ */

#ifndef SLIM_MIME_H_PRIVATE
#define SLIM_MIME_H_PRIVATE

#include <slim/private/token/mime.h>

SLIM_BEGIN_C_LINKAGE

/*      */
/* MIME */
/*      */

enum {
	SLIM_MIME_DUMMY_START = SLIM_MIMES,
	SLIM_MIME_APPLICATION_X_VIEWER_ROOT,
	SLIM_MIME_APPLICATION_X_MULTICONT_PEND_ROOT,
	SLIM_MIME_DUMMY_END
};

#define MIMEInfo_IDIsText(cls, mime) (MIMEInfo_IDIsX((cls), (mime), SLIM_MIMEINFO_FLAG_TEXT))
#define MIMEInfo_IDIsImage(cls, mime) (MIMEInfo_IDIsX((cls), (mime), SLIM_MIMEINFO_FLAG_IMAGE))
#define MIMEInfo_IDIsXML(cls, mime) (MIMEInfo_IDIsX((cls), (mime), SLIM_MIMEINFO_FLAG_XML))
#define MIMEInfo_IDIsHTML(cls, mime) (MIMEInfo_IDIsX((cls), (mime), SLIM_MIMEINFO_FLAG_HTML))
#define MIMEInfo_IDIsWML(cls, mime) (MIMEInfo_IDIsX((cls), (mime), SLIM_MIMEINFO_FLAG_WML))
#define MIMEInfo_IDIsDRM(cls, mime) (MIMEInfo_IDIsX((cls), (mime), SLIM_MIMEINFO_FLAG_DRM))
#define MIMEInfo_IDIsMultipart(cls, mime) (MIMEInfo_IDIsX((cls), (mime), SLIM_MIMEINFO_FLAG_MULTIPART))
#define MIMEInfo_IDIsDefault(cls, mime) (MIMEInfo_IDIsX((cls), (mime), SLIM_MIMEINFO_FLAG_DEFAULT))

#define MIMEInfo_RegisterWithFlag(cls, type, suf, id, flag) (MIMEInfo_RegisterX((cls), (type), (suf), (id), (flag), slim_true))

SLIM_END_C_LINKAGE
#endif
