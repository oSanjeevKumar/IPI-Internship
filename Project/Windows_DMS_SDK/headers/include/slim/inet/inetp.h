/*
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* WARNING: DO NOT EDIT! This file is generated automatically. */



/* slim_cache.c */


/* slim_channel_about.c */


/* slim_channel_datap.c */


/* slim_channel_filep.c */


/* slim_channel_http.c */


/* slim_channel_pictp.c */


/* slim_content.c */

SLIM_API TURLString TContentRequest_Referer(TContentRequest *self);
#ifdef SLIM_CONFIG_USE_HTTP
SLIM_API slim_bool TContentRequest_AddHTTPHeaderX(TContentRequest *self, slim_opaque in_name, slim_int in_name_len, slim_char *in_val, slim_int in_val_len);
#endif
SLIM_API slim_int TContentRequest_MakeURLReadableString(TContentRequest *self, slim_int in_to_charset, slim_int in_mode, TString *out_str);
SLIM_API slim_bool TContentRequest_IsNetworkConnectionRequired(TContentRequest *self);
SLIM_API slim_int (TContent_By)(TContent self);
SLIM_API void (TContent_DoNotCache)(TContent self);
SLIM_API slim_int (TContent_ErrorCode)(TContent self);
SLIM_API slim_int (TContent_HeaderCharSet)(TContent self);
SLIM_API TString (TContent_HTTPHeader)(TContent self);
SLIM_API slim_bool (TContent_IsAbort)(TContent self);
SLIM_API slim_bool (TContent_IsError)(TContent self);
SLIM_API slim_bool (TContent_IsComplete)(TContent self);
SLIM_API slim_bool (TContent_IsHTTPS)(TContent self);
SLIM_API slim_bool TContent_IsSecure(TContent self);
SLIM_API TCertList TContent_CertList(TContent self);
SLIM_API slim_int (TContent_MakeDispositionFileName)(TContent self, TString *out_fname);
SLIM_API slim_int (TContent_MakeFileName)(TContent self, TString *out_fname);
SLIM_API slim_int (TContent_StatusCode)(TContent self);
SLIM_API void (TContent_Time)(TContent self, slim_time *out_time);
SLIM_API TURLString (TContent_URL)(TContent self);
SLIM_API slim_bool TContent_CheckDone(TContent self);
SLIM_API void TContent_Abort(TContent self);
SLIM_API slim_int TContent_ContentType(TContent self);
SLIM_API slim_int TContent_ContentLength(TContent self);
SLIM_API slim_int TContent_CurrentLength(TContent self);
SLIM_API slim_vhandle TContent_Content(TContent self);
SLIM_API slim_bool (TStreamContent_CheckDone)(TStreamContent self);
SLIM_API slim_vhandle (TStreamContent_Content)(TStreamContent self);
SLIM_API slim_int (TStreamContent_ContentLength)(TStreamContent self);
SLIM_API slim_int (TStreamContent_CurrentLength)(TStreamContent self);
SLIM_API void (TStreamContent_DoNotCache)(TStreamContent self);
SLIM_API slim_int (TStreamContent_ErrorCode)(TStreamContent self);
SLIM_API TString (TStreamContent_HTTPHeader)(TStreamContent self);
SLIM_API slim_int (TStreamContent_HeaderCharSet)(TStreamContent self);
SLIM_API slim_bool (TStreamContent_IsAbort)(TStreamContent self);
SLIM_API slim_bool (TStreamContent_IsError)(TStreamContent self);
SLIM_API slim_bool (TStreamContent_IsComplete)(TStreamContent self);
SLIM_API slim_bool (TStreamContent_IsHTTPS)(TStreamContent self);
SLIM_API slim_bool (TStreamContent_IsSecure)(TStreamContent self);
SLIM_API TCertList (TStreamContent_CertList)(TStreamContent self);
SLIM_API slim_int (TStreamContent_MakeDispositionFileName)(TStreamContent self, TString *out_fname);
SLIM_API slim_int (TStreamContent_MakeFileName)(TStreamContent self, TString *out_fname);
SLIM_API slim_int (TStreamContent_StatusCode)(TStreamContent self);
SLIM_API void (TStreamContent_Time)(TStreamContent self, slim_time *out_time);
SLIM_API TURLString (TStreamContent_URL)(TStreamContent self);
SLIM_API slim_int TStreamContent_Consume(TStreamContent self, slim_int in_len);
SLIM_API slim_int TStreamContent_AvailLength(TStreamContent self);
SLIM_API void TStreamContent_SetWindowSize(TStreamContent self, slim_int in_size);
SLIM_API void* TStreamContent_LockData(TStreamContent self);
SLIM_API void TStreamContent_UnlockData(TStreamContent self);
SLIM_API void TStreamContent_Abort(TStreamContent self);
SLIM_API slim_int TStreamContent_ContentType(TStreamContent self);

/* slim_content_determiner.c */


/* slim_drm.c */


/* slim_mime.c */

SLIM_API slim_int MIMEInfo_RegisterX(TMIMEInfoClass *in_class, slim_char *in_mimetype, slim_char *in_suffixes, slim_int in_id, slim_int in_flag, slim_bool in_override);
SLIM_API slim_bool MIMEInfo_BindSuffix(TMIMEInfoClass *in_class, slim_char *in_suffixes, slim_int in_id);
SLIM_API slim_int MIMEInfo_IDFindByX(TMIMEInfoClass *in_class, slim_char *in_s, slim_int in_id_or_len, slim_int in_type);
SLIM_API slim_char * MIMEInfo_IDToCS(TMIMEInfoClass *in_class, slim_int in_id);

/* slim_multicontent.c */


/* slim_multicontent_mimemp.c */


/* slim_multicontent_user.c */

SLIM_API slim_pix TUserContent_AddDataX(TUserContent self, slim_char *in_url, slim_int in_url_len, slim_int in_mime_type, void *in_data, slim_int in_data_len, slim_pix in_index);
SLIM_API slim_int TUserContent_ListLength(TUserContent self);
SLIM_API void TUserContent_SetRootItem(TUserContent self, slim_pix in_pix);
SLIM_API TURLString TUserContent_GetURL(TUserContent self, slim_pix in_index);
SLIM_API slim_pix TUserContent_FindItemByURL(TUserContent self, slim_char *in_url, slim_int in_len);
SLIM_API slim_int TUserContent_GetSetContentType(TUserContent self, slim_pix in_index, slim_int in_mime_type, slim_bool in_set);
SLIM_API slim_int TUserContent_OpenContentX(TUserContent self, slim_char *in_url, slim_int in_len, slim_pix in_index, TContent *out_cont);
SLIM_API TUserContent UserContent_New(TUserContentClass *in_class);
SLIM_API void TUserContent_Close(TUserContent self);
SLIM_API void UserContent_Initialize(TUserContentClass *in_class, TContentClass *in_cont_cls, TDataArena *in_arena, TMultiContentChannelClass *in_channelcls);
SLIM_API void UserContent_Finalize(TUserContentClass *in_class);

/* slim_viruschecker.c */

#ifdef SLIM_CONFIG_USE_VIRUSCHECKER
SLIM_API void TVirusCheckLog_Delete(TVirusCheckLog *self);
SLIM_API slim_int TVirusCheckLog_Length(TVirusCheckLog *self);
SLIM_API slim_bool TVirusCheckLog_GetRawData(TVirusCheckLog *self, slim_opaque *out_rawdata);
#endif

/* slim_http_auth.c */

#ifdef SLIM_CONFIG_USE_HTTP
SLIM_API void THTTPAuthInfo_Tidy(THTTPAuthInfo *iself, slim_bool in_new);
SLIM_API slim_int slim_http_auth_read_header(slim_split_ss *in_header, slim_split_ss *out_challenge);
SLIM_API slim_bool slim_http_auth_read_challenge(slim_split_ss *in_challenge_ss, slim_char *in_token, slim_split_ss *out_ss);
#endif /* SLIM_CONFIG_USE_HTTP */

/* slim_http_cookie.c */

#ifdef SLIM_CONFIG_USE_HTTP
#ifdef SLIM_CONFIG_HTTP_COOKIE_DEBUG
SLIM_API void THTTPCookies_SetDebugNotifyProc(THTTPCookies *self, THTTPCookiesDebugNotifyProc in_proc, slim_opaque in_aux);
SLIM_API iTHTTPCookieEntry * THTTPCookies_Debug_LockEntry(THTTPCookies *self, THTTPCookieEntry in_entry);
SLIM_API void THTTPCookies_Debug_UnlockEntry(THTTPCookies *self, THTTPCookieEntry in_entry);
SLIM_API void THTTPCookies_Debug_DeleteCookieEntry(THTTPCookies *self, THTTPCookieEntry in_entry);
#endif
#endif /* SLIM_CONFIG_USE_HTTP */

/* slim_stream_http.c */

#ifdef SLIM_CONFIG_USE_HTTP
SLIM_API slim_bool HTTPStream_Initialize(THTTPStreamClass *in_class);
SLIM_API slim_int HTTPStream_SetCookie(THTTPStreamClass *in_class, TURLString in_url, slim_char *in_cookie, slim_int in_cookie_len);
SLIM_API TString HTTPStream_MakeCookiesString(THTTPStreamClass *in_class, TURLString in_url, slim_bool in_secure);
SLIM_API slim_bool HTTPStream_MakeAuthInfo(THTTPStreamClass *in_class, slim_int in_target, TURLString in_url, TFixedString in_proxy_host, slim_int in_proxy_port, slim_split_ss *in_realm_ss, THTTPAuthInfo *out_info);
SLIM_API void HTTPStream_CloseAllKeepAlive(THTTPStreamClass *in_class);
SLIM_API slim_bool HTTPStream_SetUserPassX(THTTPStreamClass *in_class, slim_int in_type, slim_int in_target, slim_split_ss *in_challenge_ss, slim_split_ss *in_realm_ss, TString in_user, TString in_pass, TURLString in_url, TFixedString in_host, slim_int in_port, slim_bool in_keep_user, slim_bool in_keep_pass);
#ifdef SLIM_CONFIG_HTTP_STREAM_DEBUG
SLIM_API void HTTPStream_SetDebugProc(THTTPStreamClass *in_class, void (*in_printf_proc)(char *in_format, ...), void (*in_notify_proc)(iTHTTPStream *stream));
#endif /* SLIM_CONFIG_HTTP_STREAM_DEBUG */
SLIM_API void HTTPStream_Finalize(THTTPStreamClass *in_class);
SLIM_API slim_bool HTTPStream_SetProxy(THTTPStreamClass *in_class, TFixedString in_proxy_host, slim_int in_proxy_http_port, slim_int in_proxy_https_port, TString in_no_proxy_hosts);
SLIM_API void HTTPStream_MakeProxy(THTTPStreamClass *in_class, TFixedString *out_proxy_host, slim_int *out_proxy_http_port, slim_int *out_proxy_https_port, TString *out_no_proxy_hosts);
SLIM_API slim_bool HTTPStream_SetUserAgent(THTTPStreamClass *in_class, TFixedString in_user_agent);
SLIM_API slim_bool HTTPStream_SetDefaultHeaders(THTTPStreamClass *in_class, TString in_default_headers);
SLIM_API slim_bool HTTPStream_SetDefaultConnectHeaders(THTTPStreamClass *in_class, TString in_default_headers);
SLIM_API void HTTPStream_SetCookieMode(THTTPStreamClass *in_class, slim_int in_cookie_mode, slim_bool (*in_cookie_callback)(THTTPCookies *in_cookies, TURLString in_url, slim_char *in_cookie_str, slim_int in_cookie_len, slim_opaque in_aux), slim_opaque in_cookie_aux);
SLIM_API void HTTPStream_SetMaxTotalCookiesLen(THTTPStreamClass *in_class, slim_int in_max_len);
SLIM_API void HTTPStream_ClearDNSCache(THTTPStreamClass *in_class);
SLIM_API void HTTPStream_ClearAuthCache(THTTPStreamClass *in_class);
SLIM_API void HTTPStream_SetNotifyStateProc(THTTPStreamClass *in_class, THTTPStreamNotifyStateProc in_proc, slim_opaque in_aux);
SLIM_API void HTTPStream_SetDNSPort(THTTPStreamClass *in_class, slim_int in_port);
SLIM_API void HTTPStream_SetDNSServer(THTTPStreamClass *in_class, slim_ip_addr *in_prim_svr, slim_ip_addr *in_sec_svr);
SLIM_API slim_int HTTPStream_KeepAliveTimeout(THTTPStreamClass *in_class);
SLIM_API THTTPStream HTTPStream_New(THTTPStreamClass *in_class);
SLIM_API void THTTPStream_Delete(THTTPStream self);
SLIM_API slim_bool THTTPStream_AddHeaderLineSS(THTTPStream self, slim_char *in_str, slim_int in_len);
SLIM_API slim_bool THTTPStream_AddHeaderSS(THTTPStream self, slim_int in_type, slim_char *in_str, slim_int in_len);
SLIM_API slim_bool THTTPStream_AddHeaderTS(THTTPStream self, slim_int in_type, TString in_str);
SLIM_API slim_bool THTTPStream_GetHeaderSSWithOffset(THTTPStream self, slim_int in_type, slim_int in_ofs, slim_int *out_ofs, slim_int *out_len);
SLIM_API slim_int THTTPStream_CreateSimpleRequest(THTTPStream self, slim_int in_method, TURLString in_url, TString in_header, slim_int in_version, slim_int in_cache_control, slim_bool in_pipeline, slim_int in_ssl_flag);
SLIM_API slim_int THTTPStream_CreateRequest(THTTPStream self, slim_int in_method, TURLString in_url, TString in_header, TURLString in_referer, slim_int in_version, slim_int in_cache_control, slim_bool in_pipeline, slim_int in_ssl_flag);
SLIM_API slim_int THTTPStream_SendRequest(THTTPStream self, slim_int *out_sleep);
SLIM_API slim_int THTTPStream_SendRequestWithPostData(THTTPStream self, slim_byte *in_buf, slim_int in_len, slim_int *out_len, slim_int *out_sleep);
SLIM_API slim_int THTTPStream_ReceiveResponse(THTTPStream self, slim_char* out_buf, slim_int in_len, slim_int *out_len, slim_int *out_sleep);
SLIM_API void THTTPStream_Close(THTTPStream self);
SLIM_API slim_int THTTPStream_GetScheme(THTTPStream self);
SLIM_API slim_int THTTPStream_GetState(THTTPStream self);
SLIM_API slim_bool THTTPStream_IsHeaderReceived(THTTPStream self);
SLIM_API slim_int THTTPStream_GetStatusCode(THTTPStream self);
SLIM_API slim_int THTTPStream_GetResponseHeaderLength(THTTPStream self);
SLIM_API slim_vhandle THTTPStream_GetResponseHeader(THTTPStream self);
SLIM_API slim_int THTTPStream_GetContentLength(THTTPStream self);
SLIM_API slim_int THTTPStream_GetEntityLength(THTTPStream self);
SLIM_API slim_int THTTPStream_SetPostDataSS(THTTPStream self, slim_int in_encoding, slim_char *in_data, slim_int in_len);
SLIM_API slim_int THTTPStream_SetPostData(THTTPStream self, TPostData in_postdata);
SLIM_API slim_bool THTTPStream_SSLVersion(THTTPStream self, TSSLVersion *out_version);
SLIM_API slim_bool THTTPStream_SSLCipherSuite(THTTPStream self, TSSLCipherSuite *out_cipher_suite);
SLIM_API TCertList THTTPStream_MakeCertList(THTTPStream self);
SLIM_API void THTTPStream_SuspendTimer(THTTPStream self);
SLIM_API void THTTPStream_ResumeTimer(THTTPStream self);
SLIM_API slim_bool HTTPStream_SetWakeUpCallback(THTTPStreamClass *in_class, HTTPStreamWakeUpCallbackProc in_proc, slim_opaque in_aux);
SLIM_API slim_bool HTTPStream_SetSSLServerCertConfirmProc(THTTPStreamClass *in_class, TSSLServerCertConfirmProc in_proc, slim_opaque in_aux);
SLIM_API slim_bool HTTPStream_SetSSLClientCertSelectProc(THTTPStreamClass *in_class, TSSLClientCertSelectProc in_proc, slim_opaque in_aux);
SLIM_API slim_int HTTPStream_RegisterSSLSessionDB(THTTPStreamClass *in_class, TSSLSessionDB *in_db, TSSLSessionDB *out_old);
SLIM_API slim_int HTTPStream_RegisterCertStore(THTTPStreamClass *in_class, TCertStore *in_store);
SLIM_API void HTTPStream_WakeUpByTCP(THTTPStreamClass *in_class, slim_int in_desc);
SLIM_API void HTTPStream_WakeUpByDNS(THTTPStreamClass *in_class, slim_int in_ticket_id);
SLIM_API slim_int HTTPStream_AddCookie(THTTPStreamClass *in_class, TURLString in_url, slim_char *in_str, slim_int in_len);
SLIM_API slim_bool THTTPStream_AddHeaderCS(THTTPStream self, slim_int in_type, slim_char *in_str);
#endif /* SLIM_CONFIG_USE_HTTP */

/* slim_stream_inflate.c */


/* slim_stream_pool.c */


/* slim_idn.c */

SLIM_API TString slim_idn_convert_to_ascii(slim_byte *in_url, slim_int in_url_len, slim_int in_charset);
SLIM_API TString slim_idn_convert_to_unicode(slim_byte *in_url, slim_int in_url_len, slim_int in_charset);
SLIM_API TURLString TURLString_IDNConvetToASCII(TURLString self, slim_int in_charset);
SLIM_API TURLString TURLString_IDNConvetToUnicode(TURLString self, slim_int in_charset);

/* slim_idn_nameprep.c */


/* slim_idn_nfkc.c */


/* slim_idn_punycode.c */


/* pictprom.c */


/* slim_pictp_rominfo.c */

SLIM_API void PictpChannel_SetDefaultPictogram(TPictpChannelClass *in_class);

/* slim_dns.c */


/* slim_media_scheme.c */

#ifdef SLIM_CONFIG_USE_MEDIA_SCHEME
SLIM_API slim_int TMediaSchemeInfo_Initialize(TMediaSchemeInfo *self, TURLString in_url);
SLIM_API void TMediaSchemeInfo_Finalize(TMediaSchemeInfo *self);
SLIM_API slim_int TMediaSchemeInfo_GetOption(TMediaSchemeInfo *self, slim_char *in_option_name, TMediaOptionInfo *out_info);
#endif /* SLIM_CONFIG_USE_MEDIA_SCHEME */

/* slim_url_string.c */

SLIM_API slim_int URLString_MakeAbsoluteURL(TURLString in_base, slim_char *in_s, slim_int in_len, TURLSchemeInfoClass *in_class, TURLString *out_url, slim_int *out_scheme_id);
SLIM_API slim_int slim_url_format_escape_ss(slim_char *out_buf, slim_char *in_s, slim_int in_len, slim_int in_charset);
SLIM_API slim_int slim_url_format_unescape_ss(slim_char *out_buf, slim_char *in_s, slim_int in_len);
SLIM_API slim_bool TURLString_IsHTTP(TURLString self);
SLIM_API slim_bool TURLString_IsHTTPS(TURLString self);
SLIM_API slim_bool TURLString_CompareSS(TURLString self, slim_char *in_s, slim_int in_len, slim_int in_flag);
SLIM_API slim_bool TURLString_CompareUS(TURLString self, TURLString in_url, slim_int in_flag);
SLIM_API TURLString URLString_MakeURLWithQuery(TURLString in_base, TString in_query);
SLIM_API slim_int URLSchemeInfo_Register(TURLSchemeInfoClass *in_class, slim_char *in_name, slim_int in_flag);
SLIM_API slim_bool URLSchemeInfo_SetDefaultHost(TURLSchemeInfoClass *in_class, slim_int in_id, slim_char *in_host);
SLIM_API slim_bool URLSchemeInfo_SetDefaultPort(TURLSchemeInfoClass *in_class, slim_int in_id, slim_int in_port);
SLIM_API slim_bool URLSchemeInfo_SetCharSet(TURLSchemeInfoClass *in_class, slim_int in_id, slim_int in_charset);
SLIM_API slim_bool URLSchemeInfo_SetMakeAbsoluteURLProc(TURLSchemeInfoClass *in_class, slim_int in_id, URLSchemeMakeAbsoluteProc in_proc);
SLIM_API slim_int URLSchemeInfo_URLSchemeID(TURLSchemeInfoClass *in_class, TURLString in_url);
SLIM_API slim_bool URLSchemeInfo_CompareURL(TURLSchemeInfoClass *in_class, TURLString in_url, TURLString in_target_url, slim_int in_flag);
SLIM_API TURLString URLSchemeInfo_MakeURLWithQuery(TURLSchemeInfoClass *in_class, TURLString in_base, slim_char *in_query, slim_int in_query_len);
SLIM_API slim_int URLSchemeInfo_MakeResolvedURL(TURLSchemeInfoClass *in_class, TURLString in_base, slim_char *in_s, slim_int in_len, slim_int in_src_charset, slim_int in_dest_charset, slim_int in_mode, TURLString *out_url, slim_int *out_scheme_id);
SLIM_API slim_int URLSchemeInfo_MakeNormalizedURL(TURLSchemeInfoClass *in_class, slim_char *in_s, slim_int in_len, slim_int in_src_charset, slim_int in_dest_charset, slim_int in_mode, TURLString *out_url);
SLIM_API slim_int URLSchemeInfo_ConvertURLReadable(TURLSchemeInfoClass *in_class, TURLString in_url, slim_int in_src_charset, slim_int in_dest_charset, slim_int in_mode, TString *out_str);
SLIM_API void TMailToInfo_Initialize(TMailToInfo *self, slim_int in_flag);
SLIM_API void TMailToInfo_Finalize(TMailToInfo *self);
SLIM_API slim_bool TMailToInfo_SetSeparator(TMailToInfo *self, slim_char *in_separator, slim_int in_separator_len);
SLIM_API slim_bool TMailToInfo_MakeInfo(TMailToInfo *self, slim_char *in_spec, slim_int in_len, slim_bool in_unescape);

/* slim_inet_postdata.c */

SLIM_API TPostData PostData_New(slim_int in_type, slim_int in_encoding);
SLIM_API void TPostData_Delete(TPostData self);
SLIM_API slim_int TPostData_AppendData(TPostData self, slim_char *in_name, slim_int in_name_len, slim_char *in_value, slim_int in_value_len);
SLIM_API slim_int TPostData_AppendFileData(TPostData self, slim_char *in_name, slim_int in_name_len, slim_char *in_value, slim_int in_value_len, slim_char *in_mimetype, slim_int in_mimetype_len, slim_char *in_path, slim_int in_path_len);
SLIM_API slim_int TPostData_MakeData(TPostData self, slim_vhandle *out_vhdl, slim_int *out_len);

/* slim_inet_util.c */

SLIM_API slim_bool slim_inet_find_http_headerX(slim_split_ss *inout_ss, slim_char *in_name, slim_int in_len_or_id);
SLIM_API slim_int slim_format_base64(slim_char *out_buf, slim_char *in_s, slim_int in_len, slim_char *in_base64_table, slim_int in_fill_column, slim_char *in_eol_code);
SLIM_API slim_int slim_base64_decode(slim_char *in_s, slim_int in_len, slim_char *out_buf, slim_int in_buflen, slim_char *in_eol_code, slim_char *in_base64_rev);
SLIM_API slim_bool slim_inet_read_content_range(slim_char *in_s, slim_int in_len, slim_int *out_first_byte_pos, slim_int *out_last_byte_pos, slim_int *out_instance_length);
SLIM_API slim_int slim_inet_check_206_headers(slim_split_ss *in_header_ss, slim_split_ss *in_etag_ss, slim_split_ss *in_last_mod_ss, slim_int in_first_byte_pos, slim_int in_last_byte_pos, slim_int in_content_len, slim_int in_body_len);
