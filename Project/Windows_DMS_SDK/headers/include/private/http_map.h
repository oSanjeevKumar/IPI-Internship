/*
 * http_map.h
 * Copyright (C) 2007-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */

#ifndef NFLC_HTTP_MAP_H
#define NFLC_HTTP_MAP_H

/* HTTP methods. */
enum http_method
{
  HTTP_METHOD_UNKNOWN = -1,
  HTTP_METHOD_GET = 0,
  HTTP_METHOD_HEAD, 
  HTTP_METHOD_MPOST, 
  HTTP_METHOD_MSEARCH, 
  HTTP_METHOD_NOTIFY, 
  HTTP_METHOD_POST, 
  HTTP_METHOD_SUBSCRIBE, 
  HTTP_METHOD_UNSUBSCRIBE, 
  HTTP_METHOD_SOAP_POST,
  HTTP_METHOD_GET_09,
};

typedef enum http_method http_method_t;

/* HTTP headers.  */
enum
{
  HTTP_HEADER_UNKNOWN = -1,
  HTTP_HEADER_01_NLS = 0,
  HTTP_HEADER_ACCEPT,
  HTTP_HEADER_ACCEPT_CHARSET,
  HTTP_HEADER_ACCEPT_ENCODING,
  HTTP_HEADER_ACCEPT_LANGUAGE,
  HTTP_HEADER_ACCEPT_RANGE,
#ifdef DLNA_SUPPORT_UPLOADER_DTCP_MV
  HTTP_HEADER_BLKMOVE_DTCP_COM,
#endif
#if defined(DLNA_SUPPORT_RUIPL) || defined(DLNA_SUPPORT_SATIP)
	HTTP_HEADER_BOOTID,
#endif /* DLNA_SUPPORT_RUIPL || DLNA_SUPPORT_SATIP */
  HTTP_HEADER_CACHE_CONTROL,
  HTTP_HEADER_CALLBACK,
#ifdef DEVELOPMENT_SAMSUNG_SUBTITLE
  HTTP_HEADER_CAPTION_INFO,
#endif /* DEVELOPMENT_SAMSUNG_SUBTITLE */
#ifdef DLNA_SUPPORT_SATIP
  HTTP_HEADER_CONFIGID,
#endif /* DLNA_SUPPORT_SATIP */
  HTTP_HEADER_CONNECTION,
  HTTP_HEADER_CONTENT_ENCODING,
  HTTP_HEADER_CONTENT_LANGUAGE,
  HTTP_HEADER_CONTENT_LENGTH,
  HTTP_HEADER_CONTENT_LOCATION,
  HTTP_HEADER_CONTENT_RANGE,
#ifdef HAVE_DTCP
  HTTP_HEADER_DTCP_CONTENT_RANGE,
#endif /* HAVE_DTCP */
  HTTP_HEADER_CONTENT_TYPE,
  HTTP_HEADER_CONTENT_FEATURES,
  HTTP_HEADER_DATE,
#ifdef DLNA_SUPPORT_SATIP
  HTTP_HEADER_SATIP,
#endif /* DLNA_SUPPORT_SATIP */
  HTTP_HEADER_EXPECT,
  HTTP_HEADER_EXT,
  HTTP_HEADER_FRIENDLY_NAME,
  HTTP_HEADER_AVAILABLE_SEEK_RANGE,
#ifdef DEVELOPMENT_SAMSUNG_SUBTITLE
  HTTP_HEADER_GET_CAPTION_INFO,
#endif /* DEVELOPMENT_SAMSUNG_SUBTITLE */
  HTTP_HEADER_GET_CONTENT_FEATURES,
  HTTP_HEADER_HOST,
  HTTP_HEADER_IF_RANGE,
  HTTP_HEADER_LAST_MODIFIED,
  HTTP_HEADER_LOCATION,
#ifdef DLNA_SUPPORT_RUIPL
  HTTP_HEADER_LVL,
#endif /* DLNA_SUPPORT_RUIPL */
  HTTP_HEADER_MAN,
  HTTP_HEADER_MX,
  HTTP_HEADER_NT,
  HTTP_HEADER_NTS,
  HTTP_HEADER_OPT,
  HTTP_HEADER_PLAYSPEED,
  HTTP_HEADER_PRAGMA,
  HTTP_HEADER_RANGE,
  HTTP_HEADER_DTCP_RANGE,
#ifdef HAVE_WMDRM
  HTTP_HEADER_WMDRMND,
  HTTP_HEADER_WMDRMND_STATUS,
#endif /* HAVE_WMDRM */
  HTTP_HEADER_REALTIME_INFO,
  HTTP_HEADER_SCMS_FLAG,
  HTTP_HEADER_SEQ,
  HTTP_HEADER_SERVER,
  HTTP_HEADER_SID,
  HTTP_HEADER_SOAPACTION,
  HTTP_HEADER_ST,
#ifdef DLNA_SUPPORT_RUIPL
	HTTP_HEADER_SVCID,
#endif /* DLNA_SUPPORT_RUIPL */
  HTTP_HEADER_TE,
  HTTP_HEADER_TIMEOUT,
  HTTP_HEADER_TIMESEEK_RANGE,
  HTTP_HEADER_TRANSFER_ENCODING,
  HTTP_HEADER_TRANSFER_MODE,
  HTTP_HEADER_USER_AGENT,
  HTTP_HEADER_USN,
  HTTP_HEADER_VARY,
  HTTP_HEADER_X_AV_CLIENT_INFO,
#if defined (RA_USE_RID_HEADER)
  HTTP_HEADER_X_RID,
#endif //#if defined (RA_USE_RID_HEADER)
  HTTP_HEADER_FPS
};

/* Local utility structure for mapping HTTP message string and id.  */
struct mapping
{
  slim_char *name;
  slim_int id;
};

/* HTTP header map.  */
static const struct mapping http_header_map[] =
{
  { (slim_char *) "01-NLS: ",                    HTTP_HEADER_01_NLS},
  { (slim_char *) "Accept: ",                    HTTP_HEADER_ACCEPT},
  { (slim_char *) "Accept-Charset: ",            HTTP_HEADER_ACCEPT_CHARSET},
  { (slim_char *) "Accept-Encoding: ",           HTTP_HEADER_ACCEPT_ENCODING},
  { (slim_char *) "Accept-Language: ",           HTTP_HEADER_ACCEPT_LANGUAGE},
  { (slim_char *) "Accept-Ranges: ",             HTTP_HEADER_ACCEPT_RANGE},
#ifdef DLNA_SUPPORT_UPLOADER_DTCP_MV
  { (slim_char *) "BLKMove.dtcp.com: ",          HTTP_HEADER_BLKMOVE_DTCP_COM},
#endif
#if defined(DLNA_SUPPORT_RUIPL) || defined(DLNA_SUPPORT_SATIP)
  { (slim_char *) "BOOTID.UPNP.ORG: ",             HTTP_HEADER_BOOTID},
#endif /* DLNA_SUPPORT_RUIPL */
  { (slim_char *) "Cache-Control: ",             HTTP_HEADER_CACHE_CONTROL},
  { (slim_char *) "Callback: ",                  HTTP_HEADER_CALLBACK},
#ifdef DEVELOPMENT_SAMSUNG_SUBTITLE
  { (slim_char *) "CaptionInfo.sec: ",           HTTP_HEADER_CAPTION_INFO},
#endif /* DEVELOPMENT_SAMSUNG_SUBTITLE */
#ifdef DLNA_SUPPORT_SATIP
  { (slim_char *) "CONFIGID.UPNP.ORG: ",         HTTP_HEADER_CONFIGID},
#endif /* DLNA_SUPPORT_SATIP */
  { (slim_char *) "Connection: ",                HTTP_HEADER_CONNECTION},
  { (slim_char *) "Content-Encoding: ",          HTTP_HEADER_CONTENT_ENCODING},
  { (slim_char *) "Content-Language: ",          HTTP_HEADER_CONTENT_LANGUAGE},
  { (slim_char *) "Content-Length: ",            HTTP_HEADER_CONTENT_LENGTH},
  { (slim_char *) "Content-Location: ",          HTTP_HEADER_CONTENT_LOCATION},
  { (slim_char *) "Content-Range: ",             HTTP_HEADER_CONTENT_RANGE},
#ifdef HAVE_DTCP
  { (slim_char *) "Content-Range.dtcp.com: ",    HTTP_HEADER_DTCP_CONTENT_RANGE},
#endif /* HAVE_DTCP */
  { (slim_char *) "Content-Type: ",              HTTP_HEADER_CONTENT_TYPE},
  { (slim_char *) "contentFeatures.dlna.org: ",  HTTP_HEADER_CONTENT_FEATURES},
  { (slim_char *) "Date: ",                      HTTP_HEADER_DATE},
#ifdef DLNA_SUPPORT_SATIP
  { (slim_char *) "DEVICEID.SES.COM: ",          HTTP_HEADER_SATIP},
#endif /* DLNA_SUPPORT_SATIP */
  { (slim_char *) "Expect: ",                    HTTP_HEADER_EXPECT},
  { (slim_char *) "Ext: ",                       HTTP_HEADER_EXT},
  { (slim_char *) "friendlyName.dlna.org",       HTTP_HEADER_FRIENDLY_NAME},
  { (slim_char *) "getAvailableSeekRange.dlna.org: ",     HTTP_HEADER_AVAILABLE_SEEK_RANGE},
#ifdef DEVELOPMENT_SAMSUNG_SUBTITLE
  { (slim_char *) "getCaptionInfo.sec: ",        HTTP_HEADER_GET_CAPTION_INFO},
#endif /* DEVELOPMENT_SAMSUNG_SUBTITLE */
  { (slim_char *) "getcontentFeatures.dlna.org: ",HTTP_HEADER_GET_CONTENT_FEATURES},
  { (slim_char *) "Host: ",                      HTTP_HEADER_HOST},
  { (slim_char *) "If-Range: ",                  HTTP_HEADER_IF_RANGE},
  { (slim_char *) "Last-Modified: ",             HTTP_HEADER_LAST_MODIFIED},
  { (slim_char *) "Location: ",                  HTTP_HEADER_LOCATION},
#ifdef DLNA_SUPPORT_RUIPL
  { (slim_char *) "LVL: ",                       HTTP_HEADER_LVL},
#endif /* DLNA_SUPPORT_RUIPL */
  { (slim_char *) "MAN: ",                       HTTP_HEADER_MAN},
  { (slim_char *) "MX: ",                        HTTP_HEADER_MX},
  { (slim_char *) "NT: ",                        HTTP_HEADER_NT},
  { (slim_char *) "NTS: ",                       HTTP_HEADER_NTS},
  { (slim_char *) "Opt: ",                       HTTP_HEADER_OPT},
  { (slim_char *) "PlaySpeed.dlna.org: ",        HTTP_HEADER_PLAYSPEED},
  { (slim_char *) "Pragma: ",                    HTTP_HEADER_PRAGMA},
  { (slim_char *) "Range.dtcp.com: ",            HTTP_HEADER_DTCP_RANGE},
  { (slim_char *) "Range: ",                     HTTP_HEADER_RANGE},
  { (slim_char *) "realTimeInfo.dlna.org: ",     HTTP_HEADER_REALTIME_INFO},
  { (slim_char *) "scmsFlag.dlna.org: ",         HTTP_HEADER_SCMS_FLAG},
  { (slim_char *) "SEQ: ",                       HTTP_HEADER_SEQ},
  { (slim_char *) "Server: ",                    HTTP_HEADER_SERVER},
  { (slim_char *) "SID: ",                       HTTP_HEADER_SID},
  { (slim_char *) "SOAPAction: ",                HTTP_HEADER_SOAPACTION},
  { (slim_char *) "ST: ",                        HTTP_HEADER_ST},
#ifdef DLNA_SUPPORT_RUIPL
  { (slim_char *) "SVCID: ",                     HTTP_HEADER_SVCID},
#endif /* DLNA_SUPPORT_RUIPL */
  { (slim_char *) "TE: ",                        HTTP_HEADER_TE},
  { (slim_char *) "Timeout: ",                   HTTP_HEADER_TIMEOUT},
  { (slim_char *) "TimeSeekRange.dlna.org: ",    HTTP_HEADER_TIMESEEK_RANGE},
  { (slim_char *) "Transfer-Encoding: ",         HTTP_HEADER_TRANSFER_ENCODING},
  { (slim_char *) "transferMode.dlna.org: ",     HTTP_HEADER_TRANSFER_MODE},
  { (slim_char *) "User-Agent: ",                HTTP_HEADER_USER_AGENT},
  { (slim_char *) "USN: ",                       HTTP_HEADER_USN},
  { (slim_char *) "Vary: ",                      HTTP_HEADER_VARY},
  { (slim_char *) "X-AV-Client-Info: ",          HTTP_HEADER_X_AV_CLIENT_INFO},
#ifdef HAVE_WMDRM
  { (slim_char *) "WMDRM-ND-Status: ",           HTTP_HEADER_WMDRMND_STATUS},
  { (slim_char *) "WMDRM-ND: ",                  HTTP_HEADER_WMDRMND},
#endif /* HAVE_WMDRM */
#if defined (RA_USE_RID_HEADER)
  { (slim_char *) "X_ACCESS_RID: ",                     HTTP_HEADER_X_RID},
#endif //#if defined (RA_USE_RID_HEADER)

  { (slim_char *) "FrameRateInTrickMode.dlna.org: ",        HTTP_HEADER_FPS}

};

#ifdef __cplusplus
extern "C" {
#endif

slim_int
http_method_id(dlna_split_ss *strpnt);

slim_int
http_header_id(dlna_split_ss *strpnt);

slim_char *
http_method_str(slim_int method_id);

#ifdef __cplusplus
}
#endif

#endif /* NFLC_HTTP_MAP_H */
