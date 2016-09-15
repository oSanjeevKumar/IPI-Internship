/*
	url.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/inet/url.h 90    06/08/01 15:53 Yamabuti $ */

#ifndef SLIM_URL_H
#define SLIM_URL_H

#include <slim/token/schemeid.h>

SLIM_BEGIN_C_LINKAGE

/* declare */
typedef struct TURLSchemeInfoClass_ TURLSchemeInfoClass;

/*
 * URLString
 */
enum {
	SLIM_SPLITURL_SCHEME = 0,
	SLIM_SPLITURL_AUTHORITY,
	SLIM_SPLITURL_USERINFO,
	SLIM_SPLITURL_HOST,
	SLIM_SPLITURL_PORT,
	SLIM_SPLITURL_FILE,
	SLIM_SPLITURL_PATH,
	SLIM_SPLITURL_QUERY,
	SLIM_SPLITURL_FRAGMENT,
	SLIM_SPLITURL_SPLITS
};

typedef TFixedString TURLString;

#define SLIM_URLSS_CMP_SCHEME		0x00000001
#define SLIM_URLSS_CMP_USERINFO		0x00000002
#define SLIM_URLSS_CMP_HOST			0x00000004
#define SLIM_URLSS_CMP_PORT			0x00000008
#define SLIM_URLSS_CMP_PATH			0x00000010
#define SLIM_URLSS_CMP_QUERY		0x00000020
#define SLIM_URLSS_CMP_FRAGMENT		0x00000040
#define SLIM_URLSS_CMP_ALL			(SLIM_URLSS_CMP_SCHEME|SLIM_URLSS_CMP_USERINFO|SLIM_URLSS_CMP_HOST|SLIM_URLSS_CMP_PORT|SLIM_URLSS_CMP_PATH|SLIM_URLSS_CMP_QUERY|SLIM_URLSS_CMP_FRAGMENT)
#define SLIM_URLSS_CMP_NOFRAGMENT	(SLIM_URLSS_CMP_SCHEME|SLIM_URLSS_CMP_USERINFO|SLIM_URLSS_CMP_HOST|SLIM_URLSS_CMP_PORT|SLIM_URLSS_CMP_PATH|SLIM_URLSS_CMP_QUERY)

/* API */
#define URLString_NewSS(in_s, in_len) (FixedString_NewSS((in_s), (in_len)))
#define URLString_NewCS(in_s) (FixedString_NewCS(in_s))
#define URLString_NewFS(in_fs) (FixedString_NewFS(in_fs))
#define URLString_NewUS(in_us) (FixedString_NewFS(in_us))
#define URLString_NewTS(in_ts) (FixedString_NewTS(in_ts))

#define TURLString_Delete(self) (TFixedString_Delete(self))
#define TURLString_Lock(self) (TFixedString_Lock(self))
#define TURLString_Unlock(self) (TFixedString_Unlock(self))
#define TURLString_Length(self) (TFixedString_Length(self))

#define TURLString_EqualHost(s,t)	TURLString_CompareUS((s),(t),(SLIM_URLSS_CMP_SCHEME|SLIM_URLSS_CMP_HOST|SLIM_URLSS_CMP_PORT))

/*
 * SchemeInfo
 */

#define SLIM_URL_SCHEMEFLAG_HIERARCHICAL		0x00000001
#define SLIM_URL_SCHEMEFLAG_CONVERT_CHSET		0x00000002
#define SLIM_URL_SCHEMEFLAG_KEEP_EOL			0x00000004
#define SLIM_URL_SCHEMEFLAG_HAS_FRAGMENT		0x00000008
#define SLIM_URL_SCHEMEFLAG_HAS_QUERY			0x00000010
#define SLIM_URL_SCHEMEFLAG_HAS_USERINFO		0x00000020
#define SLIM_URL_SCHEMEFLAG_COMPLETE_EMPTY_PATH	0x00000040
#define SLIM_URL_SCHEMEFLAG_USE_IDN_HOST		0x00000080

	/* internal */
#define SLIM_URL_SCHEMEFLAG_CONVCH_UTF8			0x00010000	/* interlock with SLIM_URLSCHEMEINFO_FLAG_USE_UTF8 flag */

	/* obsolete */
#define SLIM_URL_SCHEMEFLAG_OPAQUE			SLIM_FLAG_NONE
#define SLIM_URL_SCHEMEFLAG_SPLIT_FRAGMENT	SLIM_URL_SCHEMEFLAG_HAS_FRAGMENT

/* alias */
#define SLIM_URL_SCHEME_UNKNOWN		(-1)
#define SLIM_URL_SCHEME_HTTP		SLIM_TKID_SCHEME_http_
#define SLIM_URL_SCHEME_HTTPS		SLIM_TKID_SCHEME_https_
#define SLIM_URL_SCHEME_FILEP		SLIM_TKID_SCHEME_file_
#define SLIM_URL_SCHEME_JAVASCRIPT	SLIM_TKID_SCHEME_javascript_
#define SLIM_URL_SCHEME_PICTP		SLIM_TKID_SCHEME_pict_
#define SLIM_URL_SCHEME_DATAP		SLIM_TKID_SCHEME_data_
#define SLIM_URL_SCHEME_ABOUT		SLIM_TKID_SCHEME_about_

#define SLIM_URLSCHEMEINFO_FLAG_USE_UTF8		0x00000001
#define SLIM_URLSCHEMEINFO_FLAG_USE_IDN			0x00000002
#define SLIM_URLSCHEMEINFO_FLAG_STRICT			0x00000004
#define SLIM_URLSCHEMEINFO_FLAG_KEEP_BACKSLASH	0x00000008
#define SLIM_URLSCHEMEINFO_FLAG_USE_RFC2396		0x00000010

/* modes */

#define SLIM_URL_RESOLVE_DEFAULT_NOIDN		0x00000000
#define SLIM_URL_RESOLVE_DEFAULT_IDN		0x00000001

#define SLIM_URL_NORMALIZE_DEFAULT_NOIDN	0x00000000
#define SLIM_URL_NORMALIZE_DEFAULT_IDN		0x00000001

#define SLIM_URL_READABLE_DEFAULT_NOIDN		0x00000000
#define SLIM_URL_READABLE_DEFAULT_IDN		0x00000001


struct TURLSchemeInfoClass_ {
	TDataArena *fDataArena;
	slim_pix fSchemeInfoList;
	slim_int fNextID;
	slim_int fFlag;
	slim_int fHTTPDefaultPort;
	slim_int fHTTPSDefaultPort;
	slim_int fFilepCharSet;
};

typedef slim_int (*URLSchemeMakeAbsoluteProc)(TURLString in_base, slim_char *in_s, slim_int in_len, TURLString *out_url);

struct TURLSchemeUserInfo_ {
	slim_char *fName;
	slim_short fID;
	slim_short fLength;
	slim_int fSchemeFlag;
	slim_char *fDefaultHost;
	slim_int fDefaultPort;
	slim_int fCharSet;
	URLSchemeMakeAbsoluteProc fMakeAbsoluteURLProc;
};
typedef struct TURLSchemeUserInfo_ TURLSchemeUserInfo;

/*
 * MailToInfo
 */
enum {
	SLIM_MAILTOINFO_TYPE_TO = 0,
	SLIM_MAILTOINFO_TYPE_CC,
	SLIM_MAILTOINFO_TYPE_BCC,
	SLIM_MAILTOINFO_TYPE_FROM,
	SLIM_MAILTOINFO_TYPE_KEYWORDS,

	SLIM_MAILTOINFO_TYPES_CONCAT,

	SLIM_MAILTOINFO_TYPE_SUBJECT = SLIM_MAILTOINFO_TYPES_CONCAT,
	SLIM_MAILTOINFO_TYPE_COMMENTS,
	SLIM_MAILTOINFO_TYPE_BODY,

	SLIM_MAILTOINFO_TYPES_NUM
};

#define SLIM_MAILTOINFO_FLAG_TO       0x00000001
#define SLIM_MAILTOINFO_FLAG_CC       0x00000002
#define SLIM_MAILTOINFO_FLAG_BCC      0x00000004
#define SLIM_MAILTOINFO_FLAG_FROM     0x00000008
#define SLIM_MAILTOINFO_FLAG_KEYWORDS 0x00000010

#define SLIM_MAILTOINFO_FLAG_SUBJECT  0x00000020
#define SLIM_MAILTOINFO_FLAG_COMMENTS 0x00000040
#define SLIM_MAILTOINFO_FLAG_BODY     0x00000080

#define SLIM_MAILTOINFO_FLAG_SCHEME   0x00010000
#define SLIM_MAILTOINFO_FLAG_NOHEADER 0x00020000

struct TMailToInfo_ {
	TString fValue[SLIM_MAILTOINFO_TYPES_NUM];
	TString fSeparator;
	slim_int fFlag;
};
typedef struct TMailToInfo_ TMailToInfo;

#define TMailToInfo_GetValue(self, type) ((self)->fValue[(type)])

SLIM_END_C_LINKAGE
#endif
