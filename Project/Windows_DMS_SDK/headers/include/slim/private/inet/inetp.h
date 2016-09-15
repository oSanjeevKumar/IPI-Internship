/*
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* WARNING: DO NOT EDIT! This file is generated automatically. */



/* slim_cache.c */

#ifdef SLIM_CONFIG_USE_HTTP
void THTTPCacheKey_Tidy(THTTPCacheKey *iself, slim_bool in_new);
slim_bool THTTPCacheKey_DeepCopy(THTTPCacheKey *iself, THTTPCacheKey *in_src);
slim_bool THTTPCacheKey_Equal(THTTPCacheKey *iself, THTTPCacheKey *in_key);
void THTTPCacheEntry_Tidy(THTTPCacheEntry *iself, slim_bool in_new);
#ifdef SLIM_CONFIG_HTTP_CACHE_DEBUG
void THTTPCache_SetDebugProc(THTTPCache *iself, void (*in_printf_proc)(char *in_format, ...), THTTPCache_NotifyProc in_notify_proc);
#endif /* SLIM_CONFIG_HTTP_CACHE_DEBUG */
slim_int THTTPL1Cache_GetTotalSize(THTTPL1Cache *iself, slim_bool in_only_content, slim_bool in_only_sticky);
#ifdef SLIM_CONFIG_USE_L2CACHE
slim_int THTTPL2Cache_GetTotalSize(THTTPL2Cache *iself, slim_bool in_only_content, slim_bool in_only_sticky);
#else
#endif /* SLIM_CONFIG_USE_L2CACHE */
slim_bool THTTPContentCache_Initialize(THTTPContentCache *iself);
void THTTPContentCache_Finalize(THTTPContentCache *iself);
void THTTPContentCache_Restart(THTTPContentCache *iself);
#ifdef SLIM_CONFIG_HTTP_CACHE_DEBUG
void THTTPContentCache_SetDebugProc(THTTPContentCache *iself, void (*in_printf_proc)(char *in_format, ...), THTTPContentCache_NotifyProc in_notify_proc);
#endif /* SLIM_CONFIG_HTTP_CACHE_DEBUG */
void THTTPContentCache_Delete(THTTPContentCache *iself, THTTPCacheKey *in_key);
slim_pix THTTPContentCache_Find(THTTPContentCache *iself, slim_bool in_resolve_redirect_url, THTTPCacheKey *in_key, slim_int *out_cache_type);
void THTTPContentCache_GetCoreSpecInfo(THTTPContentCache *iself, slim_int in_cache_type, slim_pix in_pix, TContentCoreSpecInfo *out_info);
slim_int THTTPContentCache_Realize(THTTPContentCache *iself, THTTPCacheKey *in_key, slim_pix *out_pix, TContentSpec out_spec, slim_bool in_resolve_redirect_url);
slim_pix THTTPContentCache_Write(THTTPContentCache *iself, TContentSpec in_spec);
slim_pix THTTPContentCache_PrependRedirectURL(THTTPContentCache *iself, TURLString in_url, TURLString in_original_url);
void THTTPContentCache_RemoveRedirectURL(THTTPContentCache *iself, TURLString in_url);
void THTTPContentCache_Read(THTTPContentCache *iself, slim_pix in_pix, TContentSpec out_spec, slim_bool in_resolve_redirect_url);
slim_int THTTPContentCache_Use(THTTPContentCache *iself, slim_pix in_pix, slim_int in_use);
slim_bool THTTPContentCache_Stick(THTTPContentCache *iself, THTTPCacheKey *in_key, slim_int in_stick, slim_bool in_resolve_redirect_url);
slim_bool THTTPContentCache_MakePersistent(THTTPContentCache *iself, slim_pix in_pix);
void THTTPContentCache_UpdatePersistentContent(THTTPContentCache *iself, slim_pix in_pix);
void THTTPContentCache_SyncL2CacheInfo(THTTPContentCache *iself);
void THTTPContentCache_SetLimitSize(THTTPContentCache *iself, slim_int *inout_l1_entries, slim_int *inout_l1_total_size, slim_int *inout_l1_content_size, slim_int *inout_l2_entries, slim_int *inout_l2_total_size, slim_int *inout_l2_content_size);
slim_bool THTTPContentCache_ClearL1LRUEntry(THTTPContentCache *iself);
slim_bool THTTPContentCache_Clear(THTTPContentCache *iself, slim_bool in_no_memory_allocate);
slim_bool THTTPContentCache_ClearL1(THTTPContentCache *iself, slim_bool in_all);
slim_bool THTTPContentCache_ClearL2(THTTPContentCache *iself, slim_bool in_all);
slim_int THTTPContentCache_ChangeL2CacheDir(THTTPContentCache *iself, slim_char *in_dir_name, slim_int in_dir_len);
slim_pix THTTPContentCache_KeepCacheEntry(THTTPContentCache *self, THTTPCacheKey *in_key);
#endif /* SLIM_CONFIG_USE_HTTP */

/* slim_channel_about.c */

slim_int iTAboutChannel_DefaultWriteContent(iTAboutChannel *in_channel, TContentSpec in_spec, slim_split_ss *in_ss, slim_opaque in_userdata, slim_int *out_mimetype);
slim_bool AboutChannel_SetWriteContentProc(TAboutChannelClass *in_class, AboutChannel_WriteContentProc in_proc, slim_opaque in_userdata);
slim_bool AboutChannel_Initialize(TAboutChannelClass *in_class, TMIMEInfoClass *in_mime_class, TURLSchemeInfoClass *in_scheme_class);
void AboutChannel_Finalize(TAboutChannelClass *in_class);
slim_bool TURLString_IsAboutBlank(TURLString in_url);

/* slim_channel_datap.c */

slim_bool DatapChannel_Initialize(TDatapChannelClass *in_class, TMIMEInfoClass *in_mime_class, TURLSchemeInfoClass *in_scheme_class);
void DatapChannel_Finalize(TDatapChannelClass *in_class);

/* slim_channel_filep.c */

slim_bool iTFilepChannel_Init(iTFilepChannel *iself, TFilepChannelClass *in_class, TContentSpec in_spec, slim_int in_flag);
slim_int iTFilepChannel_PrepareDoOpen(iTFilepChannel *iself, TContentSpec in_spec, TURLString in_url, TString *out_path);
slim_int iTFilepChannel_FinishDoOpen(iTFilepChannel *iself, TContentSpec in_spec, slim_int in_stream);
slim_int iTFilepChannel_DoOpen(iTFilepChannel *iself, TContentSpec in_spec, TURLString in_url);
slim_int iTFilepChannel_PrepareDoRead(iTFilepChannel *iself, TContentSpec in_spec, void **out_buf, slim_int *out_buflen);
slim_int iTFilepChannel_FinishDoRead(iTFilepChannel *iself, TContentSpec in_spec, slim_int in_nread);
slim_int iTFilepChannel_DoRead(iTFilepChannel *iself, TContentSpec in_spec);
void iTFilepChannel_DoClose(iTFilepChannel *iself);
slim_bool FilepChannel_Common_Initialize(TFilepChannelClass *in_class, TMIMEInfoClass *in_mime_class, TURLSchemeInfoClass *in_scheme_class, slim_int in_objsize);
slim_bool FilepChannel_Initialize(TFilepChannelClass *in_class, TMIMEInfoClass *in_mime_class, TURLSchemeInfoClass *in_scheme_class);
void FilepChannel_Finalize(TFilepChannelClass *in_class);

/* slim_channel_http.c */

#ifdef SLIM_CONFIG_USE_HTTP
slim_bool iTHTTPChannel_ResetValidating(iTHTTPChannel *iself);
slim_int HTTPChannel_CacheProgress(THTTPChannelClass *in_class);
void iTHTTPChannel_CacheMaintenance(iTHTTPChannel *iself);
void THTTPChannel_Delete(TContentChannel self, TContentSpec in_spec);
void THTTPChannel_MakePersistent(TContentChannel self, slim_bool in_persistent);
slim_int THTTPChannel_DetermineRetriever(TContentChannelClass *in_class, TURLString in_url, slim_int in_method, TPostData in_post_data, slim_int in_cache_mode, slim_int in_flag, slim_int *out_cache_type);
slim_bool HTTPChannel_FindCache(THTTPChannelClass *in_class, THTTPCacheKey *in_key, slim_bool in_resolve_redirect_url, slim_int *inout_cache_type, slim_opaque *out_cache_item_id);
slim_bool HTTPChannel_GetCoreSpecInfo(THTTPChannelClass *in_class, slim_int in_cache_type, slim_opaque in_cache_item_id, TContentCoreSpecInfo *out_info);
void HTTPChannel_TidyCoreSpecInfo(THTTPChannelClass *in_class, slim_int in_cache_type, slim_opaque in_cache_item_id, TContentCoreSpecInfo *in_info);
slim_bool iTHTTPChannel_UseOrStickCache(iTHTTPChannel *iself, slim_int in_delta, slim_bool *out_stick);
slim_int iTHTTPChannel_ReadCache(iTHTTPChannel *iself, slim_bool in_resolve_redirect_url, slim_bool in_validated);
slim_int iTHTTPChannel_DeleteCache(iTHTTPChannel *iself);
slim_bool HTTPChannel_Initialize(THTTPChannelClass *in_class, TMIMEInfoClass *in_mime_class, TURLSchemeInfoClass *in_scheme_class);
void HTTPChannel_SetConnectCallback(THTTPChannelClass *in_class, THTTPChannel_ConnectCallback in_cb, slim_opaque in_aux);
void HTTPChannel_SetRedirectCallback(THTTPChannelClass *in_class, THTTPChannel_RedirectCallback in_cb, slim_opaque in_aux);
void HTTPChannel_SetAuthCallback(THTTPChannelClass *in_class, THTTPChannel_AuthCallback in_cb, slim_opaque in_aux);
void HTTPChannel_SetHeaderReceivedCallback(THTTPChannelClass *in_class, THTTPChannel_HeaderReceivedCallback in_cb, slim_opaque in_aux);
void HTTPChannel_Finalize(THTTPChannelClass *in_class);
void HTTPChannel_SetFetchAuthInfoProc(THTTPChannelClass *in_class, HTTPChannel_FetchAuthInfoProc in_proc, slim_opaque in_aux);
void THTTPChannel_ConfirmRedirectDialog(THTTPChannel self, slim_int in_method, TURLString in_new_url);
void THTTPChannel_AbortRedirectDialog(THTTPChannel self);
slim_bool THTTPChannel_IsReposting(THTTPChannel self);
void THTTPChannel_ConfirmConnectDialog(THTTPChannel self);
void THTTPChannel_AbortConnectDialog(THTTPChannel self);
void THTTPChannel_ConfirmAuthDialogX(THTTPChannel self, slim_int in_type, slim_int in_target, slim_split_ss *in_challenge_ss, slim_split_ss *in_realm_ss, TString in_user, TString in_pass, TFixedString in_proxy_host, slim_int in_proxy_port, slim_bool in_keep_user, slim_bool in_keep_pass);
void THTTPChannel_AbortAuthDialog(THTTPChannel self);
slim_bool THTTPChannel_IsSecure(THTTPChannel self);
slim_opaque THTTPChannel_UserData(THTTPChannel self);
void THTTPChannel_SetUserData(THTTPChannel self, slim_opaque in_user_data);
#ifdef SLIM_CONFIG_HTTP_CHANNEL_DEBUG
void HTTPChannel_SetDebugProc(THTTPChannelClass *in_class, void (*in_printf_proc)(char *in_format, ...));
#endif /* SLIM_CONFIG_HTTP_CHANNEL_DEBUG */
#ifdef SLIM_CONFIG_HTTP_CHANNEL_RECORD_STATS
void HTTPChannel_ShowStatistic(THTTPChannelClass *in_class);
#endif /* SLIM_CONFIG_HTTP_CHANNEL_RECORD_STATS */
#endif /* SLIM_CONFIG_USE_HTTP */

/* slim_channel_pictp.c */

void TPictgramInfo_Init(TPictgramInfo *self);
slim_bool PictpChannel_Initialize(TPictpChannelClass *in_class, PictpChannel_GetInfoProc in_getinfo, PictpChannel_ReadProc in_read, TMIMEInfoClass *in_mime_class, TURLSchemeInfoClass *in_scheme_class);
void PictpChannel_Finalize(TPictpChannelClass *in_class);

/* slim_content.c */

TContentAuth ContentAuth_New(slim_int in_type, slim_int in_target);
void TContentAuth_Delete(TContentAuth self);
void TContentAuth_SetFlag(TContentAuth self, slim_int in_flag, slim_bool in_set);
slim_bool TContentAuth_SetRealm(TContentAuth self, slim_char *in_str, slim_int in_len);
slim_bool TContentAuth_SetChallenge(TContentAuth self, slim_char *in_str, slim_int in_len);
slim_bool TContentAuth_SetUserID(TContentAuth self, slim_char *in_str, slim_int in_len, slim_bool in_keep);
slim_bool TContentAuth_SetPassword(TContentAuth self, slim_char *in_str, slim_int in_len, slim_bool in_keep);
slim_bool TContentAuth_SetProxyHostPort(TContentAuth self, TFixedString in_host, slim_int in_port);
slim_int TContentRequest_InitializeByContent(TContentRequest *self, slim_int in_flag, TContent in_content);
slim_int TContentRequest_I18NInitializeSS(TContentRequest *self, TContentClass *in_content_class, slim_int in_flag, slim_int in_method, TURLString in_referer_url, TURLString in_base, slim_char *in_s, slim_int in_len, slim_int in_charset, TContent in_referer_content);
slim_int TContentRequest_I18NInitializeUS(TContentRequest *self, TContentClass *in_content_class, slim_int in_flag, slim_int in_method, TURLString in_referer_url, TURLString in_url, slim_int in_url_charset, TContent in_referer_content );
slim_bool TContentRequest_SetQueryX(TContentRequest *self, TString in_query, slim_bool in_add);
slim_bool TContentRequest_SetFragment(TContentRequest *self, slim_char *in_s, slim_int in_len, slim_int in_charset);
slim_bool TContentRequest_SetPostData(TContentRequest *self, TPostData in_postdata);
slim_bool TContentRequest_SetPostDataSS(TContentRequest *self, slim_int in_post_encoding, slim_char *in_post_data, slim_int in_post_data_len);
void TContentRequest_SetPageAuth(TContentRequest *self, TContentAuth in_auth);
void TContentRequest_SetProxyAuth(TContentRequest *self, TContentAuth in_auth);
void TContentRequest_Move(TContentRequest *iself, TContentRequest *in_src);
slim_bool TContentRequest_IsSame(TContentRequest *self, TContentRequest *in_another, slim_int in_flag);
void TContentRequest_Finalize(TContentRequest *self);
void ContentChannel_Initialize(TContentChannelClass *in_class, TMIMEInfoClass *in_mime_class, TURLSchemeInfoClass *in_scheme_class);
void ContentChannel_Finalize(TContentChannelClass *in_class);
slim_pix TContentSpecList_FirstItem(TContentSpecList *self);
slim_pix TContentSpecList_NextItem(TContentSpecList *self, slim_pix in_pix);
void TContentSpecList_ChangeState(TContentSpecList *self, TContentSpec in_spec, slim_bool in_inactive);
void TContentSpecList_DoNotShare(TContentSpecList *self, TContentSpec in_spec);
slim_pix TContentSpecList_Append(TContentSpecList *self, TContentSpec in_spec, slim_int in_flag);
void TContentSpecList_Remove(TContentSpecList *self, TContentSpec in_spec);
TContentSpec TContentSpecList_Find(TContentSpecList *self, TContentSpecKey *in_key);
void TContentSpecList_ClearPriority(TContentSpecList *self);
void TContentSpecList_ClearVisited(TContentSpecList *self);
slim_bool TContentSpecList_Initialize(TContentSpecList *self);
void TContentSpecList_Finalize(TContentSpecList *self);
void TContentCoreSpec_WriteOpen(TContentCoreSpec self, slim_int in_len);
slim_bool TContentCoreSpec_WriteEnd(TContentCoreSpec self, slim_int in_written_len);
slim_bool TContentCoreSpec_WriteClose(TContentCoreSpec self, slim_int in_window_size, slim_int in_consumed_length);
void TContentCoreSpec_ReadOpen(TContentCoreSpec self, void **out_buf, slim_int *out_len);
void TContentCoreSpec_ReadClose(TContentCoreSpec self);
TContentCoreSpec ContentCoreSpec_New(void);
void TContentCoreSpec_Delete(TContentCoreSpec self);
TContentCoreSpec TContentCoreSpec_Copy(TContentCoreSpec self);
void TContentCoreSpec_Time(TContentCoreSpec self, slim_time *out_time);
void TContentCoreSpec_Expires(TContentCoreSpec self, slim_int *out_type, slim_time *out_expires);
void TContentCoreSpec_SetFlag(TContentCoreSpec self, slim_int in_flag, slim_bool in_set);
void TContentCoreSpec_SetCurrentLength(TContentCoreSpec self, slim_int in_length);
void TContentCoreSpec_SetContentLength(TContentCoreSpec self, slim_int in_length);
void TContentCoreSpec_SetOriginLength(TContentCoreSpec self, slim_int in_length);
void TContentCoreSpec_SetContentType(TContentCoreSpec self, slim_int in_type);
void TContentCoreSpec_SetHeader(TContentCoreSpec self, TString in_header);
void TContentCoreSpec_SetContent(TContentCoreSpec self, slim_vhandle in_content);
void TContentCoreSpec_SetCertList(TContentCoreSpec self, TCertList in_list);
void TContentCoreSpec_SetValidatorETag(TContentCoreSpec self, TString in_etag);
void TContentCoreSpec_SetValidatorDate(TContentCoreSpec self, TString in_date);
void TContentCoreSpec_SetExpiresX(TContentCoreSpec self, slim_int in_type, slim_time *in_expires);
void TContentCoreSpec_SetTime(TContentCoreSpec self, slim_time *in_time);
void TContentCoreSpec_GetCoreSpecInfo(TContentCoreSpec self, TContentCoreSpecInfo *out_info);
void TContentCoreSpecInfo_Initialize(TContentCoreSpecInfo *self);
void TContentCoreSpecInfo_Finalize(TContentCoreSpecInfo *self);
slim_int TContentCopeSpecInfo_ReadHTTPHeaderSS(TContentCoreSpecInfo *self, slim_char* in_header, slim_int in_header_len, slim_time *in_current_time, slim_int in_default_expire, slim_int in_flag);
slim_int TContentCopeSpecInfo_ReadHTTPHeader(TContentCoreSpecInfo *self, TString in_header, slim_time *in_current_time, slim_int in_default_expire, slim_int in_flag);
slim_int TContentSpec_Use(TContentSpec self);
slim_int TContentSpec_DisuseX(TContentSpec self, slim_bool in_aborted);
void TContentSpec_SetStatusCode(TContentSpec self, slim_int in_code);
void TContentSpec_SetCacheType(TContentSpec self, slim_int in_cache_type);
void TContentSpec_SetChannelState(TContentSpec self, slim_int in_state);
void TContentSpec_SetErrorCode(TContentSpec self, slim_int in_error);
void TContentSpec_SetRedirectURL(TContentSpec self, TURLString in_url);
void TContentSpec_SetURL(TContentSpec self, TURLString in_url);
void TContentSpec_SetMethod(TContentSpec self, slim_int in_method);
void TContentSpec_SetPostData(TContentSpec self, TPostData in_post_data);
void TContentSpec_SetRequestSent(TContentSpec self, slim_int in_req_len, slim_int in_req_sent);
void TContentSpec_SetURLByRedirect(TContentSpec self, TURLString in_url);
void TContentSpec_DoNotCache(TContentSpec self);
void TContentSpec_SetFlag(TContentSpec self, slim_int in_flag, slim_bool in_set);
void TContentSpec_SetExtFlag(TContentSpec self, slim_int in_flag, slim_bool in_set);
void TContentSpec_SetCacheMode(TContentSpec self, slim_int in_cache_mode);
void TContentSpec_SetWindowSize(TContentSpec self, slim_int in_window_size);
void TContentSpec_SetPriority(TContentSpec self, slim_bool in_high);
void TContentSpec_ChangeCoreSpec(TContentSpec self, TContentCoreSpec in_core_spec);
void TContentSpec_RobContentCoreSpecInfo(TContentSpec self, TContentCoreSpecInfo *in_info);
slim_bool TContentSpec_CheckAuthCount(TContentSpec self, slim_int in_target);
slim_bool TContentSpec_CheckRedirectCount(TContentSpec self);
void TContentSpec_DetermineMIMEType(TContentSpec self);
void TContentSpec_Tidy(TContentSpec self, slim_bool in_new);
slim_int TContentSpec_Progress(TContentSpec self, slim_int *out_sleep);
TURLString TContentSpec_Referer(TContentSpec self);
slim_bool TContentSpec_FindHTTPHeaderByX(TContentSpec self, slim_char *in_s, slim_int in_id_or_len, slim_offlen *out_offlen);
slim_int TContentSpec_HeaderMIMEType(TContentSpec self);
slim_int TContentSpec_SuffixMIMEType(TContentSpec self);
slim_int TContentSpec_HeaderCharSet(TContentSpec self);
slim_int TContentSpec_SuffixMIMETypeOrMakeFileNameX(TContentSpec self, TString *out_fname, slim_int *out_mimetype, slim_int in_which);
void TContentSpec_WriteOpen(TContentSpec self, slim_int in_content_len);
void TContentSpec_WriteClose(TContentSpec self);
void * TContentSpec_WriteStart(TContentSpec self, slim_int in_reserve, slim_int *out_size);
void TContentSpec_WriteEnd(TContentSpec self, slim_int in_nwritten);
void TContentSpec_ClearAuth(TContentSpec self);
slim_bool TContentSpecFactory_Initialize(TContentSpecFactory *self, TContentClass *in_class, ContentSpecFactory_PrepareProc in_proc, slim_opaque in_userdata);
TContentSpec Content_NewContentSpec(TContentClass *in_class, TContentRequest *in_req);
TContentSpec Content_NewNullContentSpec(TContentClass *in_class, TContentRequest *in_req);
TContent Content_New(TContentClass *in_class, TContentRequest *in_req);
slim_bool Content_Initialize(TContentClass *in_class, Content_NotifyProc in_proc, slim_opaque in_aux, TMIMEInfoClass *in_mime_class, TURLSchemeInfoClass *in_scheme_class);
void Content_Finalize(TContentClass *in_class);
slim_bool Content_RegisterChannel(TContentClass *in_class, slim_int in_scheme, TContentChannelClass *in_channel_class);
void Content_UnregisterChannel(TContentClass *in_class, slim_int in_scheme);
TContentChannelClass * Content_ChannelClass(TContentClass *in_class, TURLString in_url, slim_int in_scheme_id);
slim_int Content_Progress(TContentClass *in_class, slim_int *out_count);
TContentSpec Content_FindContentSpec(TContentClass *in_class, TContentRequest *in_req, slim_bool *out_can_share, slim_int *out_cachemode);
slim_int Content_PrepareContentSpecWithChannel(TContentClass *in_class, TContentRequest *in_req, TContentSpec *out_spec);
slim_int Content_DefaultPrepareContentSpec(TContentClass *in_class, TContentRequest *in_req, TContentSpec *out_spec);
slim_int Content_Open(TContentClass *in_class, TContentRequest *in_req, TContent *out_cont);
void Content_NotifyStartReload(TContentClass *in_class);
void Content_RegisterSizeLimit(TContentClass *in_class, slim_int in_mimetype, slim_int in_limit);
void TContent_SetCacheMode(TContent self, slim_int in_cache_mode);
void TContent_SetContentSpec(TContent self, TContentSpec in_spec);
slim_bool TContent_SetReferer(TContent self, TURLString in_referer);
TURLString TContent_Referer(TContent self);
void TContent_SetMultiContent(TContent self, TMultiContent in_multicont);
slim_bool TContent_CheckMultiContentClassID(TContent self, slim_int in_id);
TContent TContent_Duplicate(TContent self);
void TContent_Close(TContent self);
TString TContent_TextContent(TContent self, TI18NConverter *in_i18n_conv, TContentDeterminer *in_determiner);
TURLString TContent_MakeURLWithFragment(TContent self);
slim_int TContent_MakeURLReadableString(TContent self, slim_int in_charset, slim_int in_mode, TString *out_str);
TURLString TContent_MakeI18NURLWithFragment(TContent self, slim_int *out_charset);
slim_bool TContent_SetFragmentTS(TContent self, TString in_url, slim_int in_charset);
slim_bool TContent_SetFragmentSS(TContent self, slim_char *in_s, slim_int in_len, slim_int in_charset);
TString TContent_Fragment(TContent self);
TString TContent_MakeUnescapedFragment(TContent self);
slim_int TContent_FragmentCharSet(TContent self);
slim_int TContent_URLCharSet(TContent self);
void TContent_SetClearInstanceFlag(TContent self, slim_int in_flag, slim_bool in_clear);
slim_int Content_OpenDocumentWrite(TContentClass *in_class, TURLString in_pretended_url, slim_int in_content_type, slim_int in_charset, slim_int in_flag, TContent *out_content);
slim_bool TContent_DocumentWrite(TContent self, void *in_data, slim_int in_len);
void TContent_CloseDocumentWrite(TContent self);
slim_int TContent_Progress(TContent self, slim_int *out_sleep);
slim_int TContent_DRMMediaContentType(TContent self);
void TContent_SetContentTypeX(TContent self, slim_int in_mime, slim_bool in_is_requested);
slim_bool TContent_IsDRM(TContent self);
slim_bool TContent_HasDRMMediaContent(TContent self);
slim_int TContent_GetDRMMediaObject(TContent self, TDRMUsageContext *in_context, TDRMMediaObject *out_object);
slim_bool TContent_IsForwardLocked(TContent self);
slim_int TContent_OriginalLength(TContent self);
#ifdef SLIM_CONFIG_DEBUG
slim_handle TContent_Check(TContent self);
void TContent_DebugDump(TContent self, slim_bool in_precise);
#endif /* SLIM_CONFIG_DEBUG */
slim_int StreamContent_OpenByContent(TContentClass *in_class, TContent in_src, TStreamContent *out_content);
void TStreamContent_Close(TStreamContent self);
TURLString TStreamContent_Referer(TStreamContent self);
void TContentReader_SetReadProc(TContentReader *self, ContentReader_ReadProc in_read, slim_opaque in_arg);
slim_int TContentReader_Progress(TContentReader *self);
void TContentReader_Finalize(TContentReader *self);
slim_bool TContentReader_Write(TContentReader *self, void *in_data, slim_int in_len);
slim_bool TBinaryContentReader_Initialize(TBinaryContentReader *self, TContent in_cont, ContentReader_ReadProc in_read, slim_opaque in_arg);
slim_bool TTextContentReader_Initialize(TTextContentReader *self, TContent in_cont, ContentReader_ReadProc in_read, slim_opaque in_arg, TI18NConverter *in_conv, TContentDeterminer *in_dtmn);

/* slim_content_determiner.c */

void TContentDeterminer_SkipMIMETypeProcess(TContentDeterminer *self);
void TContentDeterminer_OmitCharSetProcess(TContentDeterminer *self);
slim_int TContentDeterminer_Default_GuessText(TContentDeterminer *self, slim_byte *in_data, slim_int in_len, slim_bool in_eod);
slim_int TContentDeterminer_Default_GuessBinary(TContentDeterminer *self, slim_byte *in_data, slim_int in_len, slim_bool in_eod);
slim_int TContentDeterminer_GuessMIMEType(TContentDeterminer *self);
slim_int TContentDeterminer_Default_AdoptMIMEType(TContentDeterminer *self, slim_bool in_first_time, slim_bool in_final_answer);
slim_int TContentDeterminer_AdoptMIMEType(TContentDeterminer *self);
slim_int TContentDeterminer_GuessCharSet(TContentDeterminer *self);
slim_int TContentDeterminer_DetectCharSet(TContentDeterminer *self);
slim_int TContentDeterminer_Default_AdoptCharSet(TContentDeterminer *self, slim_bool in_first_time, slim_bool in_final_answer);
slim_int TContentDeterminer_AdoptCharSet(TContentDeterminer *self);
void TContentDeterminer_InitI18NConverter(TContentDeterminer *self, TI18NConverter *in_converter);
slim_int TContentDeterminer_Progress(TContentDeterminer *self);
slim_bool TContentDeterminer_Start(TContentDeterminer *self, TContentDeterminerClass *in_class, TContent in_content, TCharSetGuessParam *in_param);
slim_bool TContentDeterminer_Restart(TContentDeterminer *self, TContentDeterminerClass *in_class, TContent in_content);
slim_int TContentDeterminer_MaxGuessLen(TContentDeterminer *self);
slim_bool TContentDeterminer_SetMaxGuessLen(TContentDeterminer *self, slim_int in_state, slim_int in_max_len);
void TContentDeterminer_TidyX(TContentDeterminer *self, TContentDeterminerClass *in_class, TContent in_content);
void TContentDeterminer_Tidy(TContentDeterminer *self);
void TContentDeterminer_Abort(TContentDeterminer *self);
slim_bool ContentDeterminer_SetMaxGuessLen(TContentDeterminerClass *in_class, slim_int in_state, slim_int in_max_len);
slim_int ContentDeterminer_MaxGuessLen(TContentDeterminerClass *in_class, slim_int in_state);
void ContentDeterminer_Initialize(TContentDeterminerClass *in_class, TI18NConverterClass *in_convclass, TMIMEInfoClass *in_mimeclass);
void ContentDeterminer_Finalize(TContentDeterminerClass *in_class);

/* slim_drm.c */

void TDRMMediaObject_SetContent(TDRMMediaObject *self, slim_vhandle in_vh);
void TDRMMediaObject_SetContentID(TDRMMediaObject *self, TFixedString in_fs);
slim_bool TDRMMediaObject_Initialize(TDRMMediaObject *self);
void TDRMMediaObject_Finalize(TDRMMediaObject *self);
TDRMMediaObject * DRMMediaObject_New(void);
void TDRMMediaObject_Delete(TDRMMediaObject *self);
slim_bool TDRMUsageContext_Initialize(TDRMUsageContext *self);
void TDRMUsageContext_Finalize(TDRMUsageContext *self);
TDRMUsageContext * DRMUsageContext_New(void);
void TDRMUsageContext_Delete(TDRMUsageContext *self);

/* slim_mime.c */

slim_bool MIMEInfo_Initialize(TMIMEInfoClass *in_class, TDataArena *in_arena);
void MIMEInfo_Finalize(TMIMEInfoClass *in_class);
slim_bool MIMEInfo_SSIsX(TMIMEInfoClass *in_class, slim_char *in_s, slim_int in_len, slim_int in_mask);
slim_bool MIMEInfo_IDIsX(TMIMEInfoClass *in_class, slim_int in_mime_type, slim_int in_mask);
slim_int MIMEInfo_GuessText(slim_byte *in_data, slim_int in_len);
slim_int MIMEInfo_GuessBinary(slim_byte *in_data, slim_int in_len);
slim_int MIMEInfo_Guess(void *in_content, slim_int in_content_len, slim_int in_flag, slim_int in_type);
slim_bool MIMEInfo_ReadContentTypeHeader(TMIMEInfoClass *in_class, slim_char *in_s, slim_int in_len, slim_int *out_content_type, slim_int *out_charset);

/* slim_multicontent.c */

void iTMultiContentReviver_Init(iTMultiContentReviver *self, TMultiContentReviverClass *in_class);
void MultiContentReviver_Initialize(TMultiContentReviverClass *in_class, TMultiContentClass *in_contcls);
slim_int TMultiContentReviver_Revive(TMultiContentReviver self, TMultiContent *out_content);
slim_bool TMultiContentReviver_IsEqual(TMultiContentReviver self, TMultiContentReviver in_another);
TMultiContentReviver TMultiContentReviver_Copy(TMultiContentReviver self);
slim_int MultiContentReviver_New(TMultiContentReviverClass *in_class, iTMultiContent *in_content, TMultiContentReviver *out_reviver);
void TMultiContentReviver_Delete(TMultiContentReviver self);
void TMultiContentChannel_SetMultiContent(TMultiContentChannel self, TMultiContent in_cont);
void MultiContentChannel_Initialize(TMultiContentChannelClass *in_class, TMIMEInfoClass *in_mime_class, TURLSchemeInfoClass *in_scheme_class);
slim_pix iTMultiContent_NthItem(iTMultiContent *self, slim_int in_index);
slim_int iTMultiContent_ItemIndex(iTMultiContent *self, slim_pix in_pix);
slim_pix iTMultiContent_AppendItemX(iTMultiContent *self, TMultiContentItem *in_item, slim_int in_size, slim_bool in_pending);
void iTMultiContent_InitItem(iTMultiContent *self, TMultiContentItem *in_item);
void iTMultiContent_TidyItemX(iTMultiContent *self, TMultiContentItem *in_item, slim_bool in_pending);
void iTMultiContent_DeleteItem(iTMultiContent *self, slim_pix in_pix);
slim_pix iTMultiContent_ForeachItemX(iTMultiContent *self, slim_pix in_start, MultiContent_ForeachItemProc in_proc, slim_opaque in_arg, slim_bool in_pending);
slim_pix iTMultiContent_FindItemBySpecX(iTMultiContent *self, slim_pix in_start, TContentSpec in_spec, slim_bool in_pending);
slim_pix iTMultiContent_FindItemByURLX(iTMultiContent *self, slim_pix in_start, TURLString in_url, slim_bool in_pending);
slim_int iTMultiContent_NewPendingContentSpec(iTMultiContent *self, TContentRequest *in_req, TContentSpec *out_spec);
slim_int iTMultiContent_NewContentSpec(iTMultiContent *self, TContentRequest *in_req, TContentSpec *out_spec);
void iTMultiContent_MovePendingSpec(iTMultiContent *self, slim_pix in_pend_pix, slim_pix in_pix);
slim_pix iTMultiContent_PendingRootItem(iTMultiContent *self);
slim_pix iTMultiContent_AddPendingRootItem(iTMultiContent *self);
slim_bool iTMultiContent_Init(iTMultiContent *self, TMultiContent in_handle, TMultiContentClass *in_class);
void iTMultiContent_Tidy(iTMultiContent *self);
void MultiContent_Initialize(TMultiContentClass *in_class, TContentClass *in_contcls, TDataArena *in_arena, TMultiContentChannelClass *in_channelcls);
void MultiContent_Finalize(TMultiContentClass *in_class);
slim_int TMultiContent_OpenContentX(TMultiContent self, TContentRequest *in_req, slim_pix in_index, TContent *out_cont);
TMultiContent TMultiContent_Copy(TMultiContent self);
slim_int TMultiContent_NewReviver(TMultiContent self, TMultiContentReviver *out_reviver);
void TMultiContent_Close(TMultiContent self);
void TMultiContent_Abort(TMultiContent self);
slim_int TMultiContent_GetInfo(TMultiContent self, TMultiContentInfo *out_info);

/* slim_multicontent_mimemp.c */

slim_int MIMEMPContentReviver_NewWithRequest(TMIMEMPContentReviverClass *in_class, TContentRequest *in_req, TMultiContentReviver *out_reviver);
void MIMEMPContentReviver_Initialize(TMIMEMPContentReviverClass *in_class, TMIMEMPContentClass *in_psvcontcls);
slim_int iTMIMEMPContent_WritePartBody(iTMIMEMPContent *self, TMIMEMPContentItem *in_item, TContentSpec inout_spec);
slim_int iTMIMEMPContent_NewContentSpec(iTMultiContent *base, TContentRequest *in_req, TContentSpec *out_spec);
void iTMIMEMPContent_Tidy(iTMultiContent *base);
void iTMIMEMPContent_TidyItem(iTMultiContent *base, TMultiContentItem *in_item, slim_bool in_pending);
slim_int iTMIMEMPContent_UpdateContentSpec(iTMultiContent *base, TContentSpec in_spec);
void iTMIMEMPContent_Abort(iTMultiContent *ibase);
slim_int iTMIMEMPContent_GetInfo(iTMultiContent *ibase, TMultiContentInfo *out_info);
slim_int TMIMEMPContent_Progress(TMIMEMPContent self);
slim_int TMIMEMPContent_OpenRootContentByX(TMIMEMPContent self, TContent in_src_cont, slim_int in_index, slim_int in_mimetype, TURLString in_url, TContent *out_cont);
TMIMEMPContent MIMEMPContent_New(TMIMEMPContentClass *in_class, TContent in_cont);
void MIMEMPContent_Initialize(TMIMEMPContentClass *in_class, TContentClass *in_cont_cls, TDataArena *in_arena, TMultiContentChannelClass *in_channelcls);
void MIMEMPContent_Finalize(TMIMEMPContentClass *in_class);

/* slim_multicontent_user.c */

slim_bool iTUserContent_PrepareItem(iTUserContent *self, TUserContentItem *out_item, slim_char *in_url, slim_int in_url_len, void *in_data, slim_int in_data_len, slim_int in_mime_type);
slim_bool iTUserContent_InitItem(iTUserContent *self, TUserContentItem *out_item);
slim_int iTUserContent_NewContentSpec(iTMultiContent *base, TContentRequest *in_req, TContentSpec *out_spec);
slim_bool iTUserContent_Init(iTUserContent *self, TUserContent in_handle, TUserContentClass *in_class);
void iTUserContent_Tidy(iTMultiContent *base);

/* slim_viruschecker.c */

#ifdef SLIM_CONFIG_USE_VIRUSCHECKER
void TVirusCheckLog_Tidy(TVirusCheckLog *self);
void ContentVirusCheckLog_Initialize(TContentVirusCheckLogClass *in_class);
void ContentVirusCheckLog_Finalize(TContentVirusCheckLogClass *in_class);
void URLVirusCheckLog_Initialize(TURLVirusCheckLogClass *in_class);
void URLVirusCheckLog_Finalize(TURLVirusCheckLogClass *in_class);
slim_int TVirusChecker_NewLog(TVirusChecker *self, TVirusCheckLog **out_log);
void TVirusChecker_IgnoreVirus(TVirusChecker *self, slim_int in_method);
void TVirusChecker_Tidy(TVirusChecker *self);
void TVirusChecker_Delete(TVirusChecker *self);
void TContentVirusChecker_SetMIMEType(TContentVirusChecker *self, slim_int in_mimetype);
void TContentVirusChecker_SetCharSet(TContentVirusChecker *self, slim_int in_charset);
slim_int TContentVirusChecker_Analyze(TContentVirusChecker *self, slim_byte *in_data, slim_int in_len, slim_bool in_eof, slim_int *out_safelen);
slim_int TContentVirusChecker_SafeLength(TContentVirusChecker *self);
slim_int TContentVirusChecker_InitLog(TContentVirusChecker *self, TContentVirusCheckLog *out_log);
void ContentVirusChecker_Initialize(TContentVirusCheckerClass *in_class, TContentVirusCheckLogClass *in_log_class);
void ContentVirusChecker_Finalize(TContentVirusCheckerClass *in_class);
slim_int TURLVirusChecker_Analyze(TURLVirusChecker *self, slim_char *in_url, slim_int in_len, slim_int in_charset);
slim_int TURLVirusChecker_InitLog(TURLVirusChecker *self, TURLVirusCheckLog *out_log);
void URLVirusChecker_Initialize(TURLVirusCheckerClass *in_class, TURLVirusCheckLogClass *in_log_class);
void URLVirusChecker_Finalize(TURLVirusCheckerClass *in_class);
slim_int TVirusCheckerFactory_InitContentChecker(TVirusCheckerFactory *self, TContentVirusChecker *out_checker);
slim_int TVirusCheckerFactory_InitURLChecker(TVirusCheckerFactory *self, TURLVirusChecker *out_checker);
slim_int TVirusCheckerFactory_NewChecker(TVirusCheckerFactory *self, slim_int in_type, TVirusChecker **out_chcker);
void TVirusCheckerFactory_Initialize(TVirusCheckerFactory *self, TContentVirusCheckerClass *in_content_class, TURLVirusCheckerClass *in_url_class);
void TVirusCheckerFactory_Finalize(TVirusCheckerFactory *self);
#endif

/* slim_http_auth.c */

#ifdef SLIM_CONFIG_USE_HTTP
void THTTPAuthEntry_Tidy(THTTPAuthEntry *iself, slim_bool in_new);
slim_bool THTTPAuthInfo_SetUser(THTTPAuthInfo *iself, TString in_user);
slim_bool THTTPAuthInfo_SetPass(THTTPAuthInfo *iself, TString in_pass);
slim_bool THTTPAuthInfo_SetRealm(THTTPAuthInfo *iself, TString in_realm);
slim_bool THTTPAuthInfo_SetChallenge(THTTPAuthInfo *iself, TString in_challenge);
slim_bool THTTPAuthInfo_Set(THTTPAuthInfo *iself, TString in_user, TString in_pass, TString in_realm, TString in_challenge);
slim_bool THTTPAuthInfo_Duplicate(THTTPAuthInfo *iself, THTTPAuthInfo *in_src);
void THTTPAuthNode_Tidy(THTTPAuthNode *iself, slim_bool in_new);
slim_bool THTTPAuthNode_SetType(THTTPAuthNode *iself, slim_int in_type);
slim_bool THTTPAuthNode_SetPath(THTTPAuthNode *iself, TString in_path);
slim_bool THTTPAuthNode_Set(THTTPAuthNode *iself, slim_int in_type, TString in_path);
void THTTPAuthCache_RemoveInfo(THTTPAuthCache *iself, slim_pix in_pix);
void THTTPAuthCache_RemoveEntry(THTTPAuthCache *iself, slim_pix in_pix);
slim_bool THTTPAuthCache_FindCandidate(THTTPAuthCache *iself, TFixedString in_host, slim_int in_port, TString in_path, TString *inout_realm, TString *out_user, TString *out_pass, slim_bool *out_keep_user, slim_bool *out_keep_pass);
slim_bool THTTPAuthCache_IsAuthorized(THTTPAuthCache *iself, TFixedString in_host, slim_int in_port, TString in_path, TString *inout_realm);
void THTTPAuthCache_InvalidateInfo(THTTPAuthCache *iself, slim_pix in_pix);
slim_bool THTTPAuthCache_Initialize(THTTPAuthCache *iself, slim_int in_max_entries);
void THTTPAuthCache_Finalize(THTTPAuthCache *iself);
void THTTPAuthCache_RemoveEntries(THTTPAuthCache *iself, TFixedString in_host, slim_int in_port, slim_int in_target_bit);
void THTTPAuthCache_SetMakeCredProc(THTTPAuthCache *iself, slim_int in_type, THTTPAuthMakeCredProc in_proc);
slim_pix THTTPAuthCache_SetUserPassX(THTTPAuthCache *iself, slim_int in_target, slim_int in_type, TFixedString in_host, slim_int in_port, TString in_user, TString in_pass, TString in_path, TString in_realm, TString in_challenge, slim_bool in_keep_user, slim_bool in_keep_pass);
slim_pix THTTPAuthCache_FindByPath(THTTPAuthCache *iself, TFixedString in_host, slim_int in_port, TString in_path, slim_pix *out_pix);
slim_pix THTTPAuthCache_FindByRealm(THTTPAuthCache *iself, TFixedString in_host, slim_int in_port, TString in_realm);
slim_bool THTTPAuthCache_MakeInfo(THTTPAuthCache *iself, slim_pix in_pix, THTTPAuthInfo *out_info);
TString THTTPAuthCache_MakeCred(THTTPAuthCache *iself, slim_pix in_info_pix, slim_pix in_node_pix, slim_char *in_method, TURLString in_url, slim_byte *in_entity_hash);
slim_int THTTPAuthCache_AuthType(THTTPAuthCache *iself, slim_pix in_pix);
slim_bool THTTPAuthCache_UpdateNextNonce(THTTPAuthCache *iself, slim_pix in_pix, slim_split_ss *in_challenge_ss);
slim_int THTTPAuthCache_SetNextNonce(THTTPAuthCache *iself, slim_pix in_pix, TString in_next_nonce, slim_word in_nc);
slim_int THTTPAuthCache_Serialize(THTTPAuthCache *iself, slim_byte *out_buf, slim_int in_len, slim_byte *in_key);
slim_int THTTPAuthCache_Deserialize(THTTPAuthCache *iself, slim_byte *in_buf, slim_int in_len, slim_byte *in_key);
#ifdef SLIM_CONFIG_HTTP_AUTH_DEBUG
void THTTPAuthCache_SetDebugProc(THTTPAuthCache *iself, void (*in_printf_proc)(char *in_format, ...), void (*in_notify_proc)(THTTPAuthCache *in_auth));
#endif /* SLIM_CONFIG_HTTP_AUTH_DEBUG */
#endif /* SLIM_CONFIG_USE_HTTP */

/* slim_http_cookie.c */

#ifdef SLIM_CONFIG_USE_HTTP
slim_bool THTTPCookies_Initialize(THTTPCookies *self, slim_int in_max_total_cookies, slim_int in_max_cookies_per_domain, slim_int in_max_len_per_cookie);
void THTTPCookies_Finalize(THTTPCookies *self);
void THTTPCookies_SetMax(THTTPCookies *self, slim_int in_max_total_cookies, slim_int in_max_cookies_per_domain, slim_int in_max_len_per_cookie);
void THTTPCookies_SetMaxTotalCookiesLen(THTTPCookies *self, slim_int in_max_len);
slim_int THTTPCookies_Default_HandleReceivedCookie(THTTPCookies *self, THTTPCookie *inout_cookie, slim_time *in_cur_time);
slim_int THTTPCookies_SetCookieX(THTTPCookies *self, TURLString in_url, slim_char *in_header, slim_int in_headerlen);
slim_int THTTPCookies_SetCookie(THTTPCookies *self, TURLString in_url, slim_char *in_header, slim_int in_headerlen);
TString THTTPCookies_MakeCookiesString(THTTPCookies *self, slim_char *in_url, slim_int in_urllen, slim_bool in_secure, slim_int *out_len);
TString THTTPCookies_SaveEntries(THTTPCookies *self, slim_int *out_len);
slim_bool THTTPCookies_LoadEntries(THTTPCookies *self, slim_char *in_s, slim_int in_slen);
void THTTPCookies_MakeEmpty(THTTPCookies *self);
slim_bool HTTPCookies_LimitSizeSavedEntries(slim_int in_limit, slim_char **inout_s, slim_int *inout_len);
#endif /* SLIM_CONFIG_USE_HTTP */

/* slim_stream_http.c */

#ifdef SLIM_CONFIG_USE_HTTP
void HTTPStream_FindAuthCandidate(THTTPStreamClass *in_class, TURLString in_url, slim_int in_target, TFixedString in_proxy_host, slim_int in_proxy_port, TString *inout_realm, TString *out_user, TString *out_pass, slim_bool *out_keep_user, slim_bool *out_keep_pass);
slim_bool HTTPStream_IsAuthorized(THTTPStreamClass *in_class, TURLString in_url, slim_int in_target, TFixedString in_proxy_host, slim_int in_proxy_port, TString *inout_realm);
slim_pix HTTPStream_FindAuthInfoPix(THTTPStreamClass *in_class, slim_int in_target, TURLString in_url, TFixedString in_proxy_host, slim_int in_proxy_port, slim_split_ss *in_realm_ss, slim_pix *out_pix);
slim_int iTHTTPStream_DoRspEntityReceivingX(iTHTTPStream *iself, slim_char *out_buf, slim_int in_len, slim_int *out_len);
slim_int iTHTTPStream_Request_Default(iTHTTPStream *iself, slim_int in_state);
slim_int iTHTTPStream_Response_Default(iTHTTPStream *iself, slim_int in_state, slim_char *out_buf, slim_int in_len, slim_int *out_len);
void HTTPStream_SetTunnelingCallback(THTTPStreamClass *in_class, slim_int (*in_tunneling_callback)(iTHTTPStream *iself, slim_char *in_buf, slim_int in_len, slim_opaque in_aux), slim_opaque in_tunneling_aux);
void HTTPStream_SetMakeCredProc(THTTPStreamClass *in_class, slim_int in_type, THTTPAuthMakeCredProc in_proc);
slim_bool HTTPStream_FindAuthInfo(THTTPStreamClass *in_class, slim_int in_target, TURLString in_url, TFixedString in_proxy_host, slim_int in_proxy_port, slim_split_ss *in_realm_ss, THTTPAuthInfo *out_info);
slim_int HTTPStream_InvalidateAuthInfo(THTTPStreamClass *in_class, TURLString in_url);
slim_int HTTPStream_SetUserPassByInfo(THTTPStreamClass *in_class, slim_int in_target, TURLString in_url, slim_int in_type, THTTPAuthInfo *in_info);
slim_int HTTPStream_MakeProxyURL(THTTPStreamClass *in_class, slim_bool in_secure, TURLString *out_url);
void HTTPStream_SetHeaderRestrictions(THTTPStreamClass *in_class, THTTPHdrRestriction *in_req, THTTPHdrRestriction *in_rsp);
void THTTPStream_GetRequestSent(THTTPStream self, slim_int *out_total, slim_int *out_sent);
void THTTPStream_GetResponseRecv(THTTPStream self, slim_int *out_total, slim_int *out_recv);
slim_int THTTPStream_GetFlag(THTTPStream self);
void THTTPStream_SetFlag(THTTPStream self, slim_int in_flag, slim_bool in_set);
void THTTPStream_SetTimeLimit(THTTPStream self, slim_int in_tmev, slim_int in_msec);
void THTTPStream_SetMaxReqMsgHeader(THTTPStream self, slim_int in_size);
void THTTPStream_SetNotifyStateProc(THTTPStream self, THTTPStreamNotifyStateProc in_proc, slim_opaque in_aux);
void THTTPHdrRestriction_Clear(THTTPHdrRestriction *iself, slim_bool in_on);
void THTTPHdrRestriction_Set(THTTPHdrRestriction *iself, slim_int in_type, slim_bool in_on);
slim_bool HTTPStream_SetSSLDeleteCallback(THTTPStreamClass *in_class, TSSLDeleteCallback in_proc, slim_opaque in_aux);
slim_bool HTTPStream_SetSSLPrivateKeyEncryptProc(THTTPStreamClass *in_class, TSSLPrivateKeyEncryptProc in_proc, slim_opaque in_aux);
#ifdef SLIM_CONFIG_HTTP_STREAM_DEBUG
void THTTPStream_DebugDump(THTTPStream self, slim_bool in_precise);
void HTTPStream_DebugDump_CacheDNSEntry(THTTPStreamClass *in_class, TDNSCacheEntry *in_entry);
void HTTPStream_DebugDump(THTTPStreamClass *in_class);
#endif /* SLIM_CONFIG_HTTP_STREAM_DEBUG */
#endif /* SLIM_CONFIG_USE_HTTP */

/* slim_stream_inflate.c */

#ifdef SLIM_CONFIG_USE_ZLIB
slim_int HTTPStreamInflate_UseZlib_Read(THTTPStreamInflate *iself, iTHTTPStream *in_stream, slim_char* out_buf, slim_int in_len, slim_int *out_len);
#endif
slim_int HTTPStreamInflate_Ident_Read(THTTPStreamInflate *iself, iTHTTPStream *in_stream, slim_char* out_buf, slim_int in_len, slim_int *out_len);
THTTPStreamInflate * HTTPStreamInflate_New(slim_int in_type, THTTPStreamPool *in_pool, slim_int in_desc);
slim_int THTTPStreamInflate_Read(THTTPStreamInflate *iself, iTHTTPStream *in_stream, slim_char* out_buf, slim_int in_len, slim_int *out_len);
void THTTPStreamInflate_Delete(THTTPStreamInflate *iself);

/* slim_stream_pool.c */

slim_bool THTTPStreamPool_SSLVersion(THTTPStreamPool *iself, slim_int in_desc, TSSLVersion *out_version);
slim_bool THTTPStreamPool_SSLCipherSuite(THTTPStreamPool *iself, slim_int in_desc, TSSLCipherSuite *out_cipher_suite);
TCertList THTTPStreamPool_MakeServerCertList(THTTPStreamPool *iself, slim_int in_desc);
void THTTPStreamPool_RegisterTCPInterface(THTTPStreamPool *iself, TTCPSocketClass *in_tcp_class);
void THTTPStreamPool_RegisterSSLInterface(THTTPStreamPool *iself, TSSLSocketClass *in_ssl_class);
slim_bool THTTPStreamPool_IsRelatedToSSL(THTTPStreamPool *iself, slim_int in_desc, TSSL in_ssl);
slim_bool THTTPStreamPool_IsRelatedToTCP(THTTPStreamPool *iself, slim_int in_tcp_desc);
slim_int THTTPStreamPool_StartSSL(THTTPStreamPool *iself, slim_int in_desc, slim_int in_ssl_flag);
slim_int HTTPStreamUtil_FindEndOfResponse(slim_char *in_s, slim_int in_len);
slim_bool THTTPStreamPool_Initialize(THTTPStreamPool *iself);
void THTTPStreamPool_Finalize(THTTPStreamPool *iself);
slim_int THTTPStreamPool_Open(THTTPStreamPool *iself);
void THTTPStreamPool_Close(THTTPStreamPool *iself, slim_int in_desc);
void THTTPStreamPool_Shutdown(THTTPStreamPool *iself, slim_int in_desc);
void THTTPStreamPool_SetKeepAlive(THTTPStreamPool *iself, slim_int in_desc, slim_bool in_keep_alive, slim_int in_timeout, slim_int in_max);
slim_int THTTPStreamPool_IsConnected(THTTPStreamPool *iself, slim_int in_desc);
slim_int THTTPStreamPool_ProxyConnect(THTTPStreamPool *iself, slim_int in_desc, TString in_connect_req);
slim_int THTTPStreamPool_IsProxyConnected(THTTPStreamPool *iself, slim_int in_desc, slim_byte **out_buf, slim_int *out_len);
slim_int THTTPStreamPool_IsHandshakeFinished(THTTPStreamPool *iself, slim_int in_desc);
slim_int THTTPStreamPool_Connect(THTTPStreamPool *iself, slim_int in_desc, slim_ip_addr *in_addr, slim_int in_port, slim_bool in_pipeline, slim_bool in_ssl, slim_bool in_proxy, TFixedString in_url_host, slim_int in_url_port);
slim_int THTTPStreamPool_Write(THTTPStreamPool *iself, slim_int in_desc, slim_byte *in_buf, slim_int in_len);
slim_int THTTPStreamPool_FinishWrite(THTTPStreamPool *iself, slim_int in_desc);
slim_int THTTPStreamPool_Read(THTTPStreamPool *iself, slim_int in_desc, slim_byte **out_buf, slim_int in_len, slim_int in_flag);
void THTTPStreamPool_SkipReadBuf(THTTPStreamPool *iself, slim_int in_desc, slim_int in_len);
slim_int THTTPStreamPool_PeekReadBuf(THTTPStreamPool *iself, slim_int in_desc, slim_byte **out_buf, slim_int *out_len, slim_bool *out_eof);
void THTTPStreamPool_FinishRead(THTTPStreamPool *iself, slim_int in_desc);
slim_bool THTTPStreamPool_CheckFlag(THTTPStreamPool *iself, slim_int in_desc, slim_int in_flag);
void THTTPStreamPool_CloseAll(THTTPStreamPool *iself);
void THTTPStreamPool_CloseAllKeepAlive(THTTPStreamPool *iself);
slim_int THTTPStreamPool_KeepAliveTimeout(THTTPStreamPool *iself);
slim_int THTTPStreamPool_SSLState(THTTPStreamPool *iself, slim_int in_desc);
slim_int THTTPStreamPool_CheckTimer(THTTPStreamPool *iself, slim_int in_desc, slim_int *out_event);
void THTTPStreamPool_SuspendTimer(THTTPStreamPool *iself, slim_int in_desc);
void THTTPStreamPool_ResumeTimer(THTTPStreamPool *iself, slim_int in_desc);
slim_bool THTTPStreamPool_VerifyVersionForKeepAlive(THTTPStreamPool *iself, slim_int in_desc, slim_short in_version);
#ifdef SLIM_CONFIG_HTTP_STREAM_DEBUG
void THTTPStreamPool_SetDebugProc(THTTPStreamPool *iself, HTTPStreamPool_DebugPrintProc in_printf_proc, HTTPStreamPool_DebugNotifyProc in_notify_proc);
void THTTPStreamPool_DebugDump(THTTPStreamPool *iself);
#endif /* SLIM_CONFIG_HTTP_STREAM_DEBUG */

/* slim_idn.c */

slim_int slim_convert_idn_to_ascii_x(slim_split_ss *in_ss, slim_int in_charset, TString *out_str);
slim_int slim_convert_idn_to_unicode_x(slim_split_ss *in_ss, slim_int in_charset, TString *out_str);

/* slim_idn_nameprep.c */

slim_int slim_nameprep(slim_word *inout_buf, slim_int in_len);

/* slim_idn_nfkc.c */

slim_int slim_idn_nfkc_decomposition(slim_int in_len, slim_word *in_buf, slim_int *out_len, slim_word *out_buf);
slim_int slim_idn_nfkc_composition(slim_int in_len, slim_word *in_buf, slim_int *out_len, slim_word *out_buf);

/* slim_idn_punycode.c */

slim_int slim_punycode_encode(slim_word *in_buf, slim_int in_len, slim_int in_limit, slim_char *out_buf);
slim_int slim_punycode_decode(slim_word *in_buf, slim_int in_len, slim_int in_limit, slim_word *out_buf);

/* pictprom.c */


/* slim_pictp_rominfo.c */

slim_bool PictpChannel_DefaultGetInfo(TURLString in_url, TPictgramInfo *out_info);
slim_int PictpChannel_DefaultRead(TPictgramInfo *in_info, slim_int in_offset, void *out_buf, slim_int in_buf_len);

/* slim_dns.c */

#ifdef SLIM_CONFIG_USE_DNS
slim_int TDNS_Initialize(TDNS *self, TDNSWakeUpCallbackProc in_callback, slim_opaque in_callback_aux);
void TDNS_Finalize(TDNS *self);
void TDNS_SetServer(TDNS *self, slim_ip_addr *in_prim_svr, slim_ip_addr *in_sec_svr);
slim_int TDNS_GetTicket(TDNS *self, slim_char *in_domain, slim_int in_len);
void TDNS_ReleaseTicket(TDNS *self, slim_int in_ticket_id);
slim_int TDNS_LookUp(TDNS *self, slim_int in_ticket_id);
slim_int TDNS_GetAddress(TDNS *self, slim_int in_ticket_id, slim_ip_addr *out_addr, slim_int in_n, slim_word *out_ttl);
void TDNS_SetMode(TDNS *self, slim_int in_mode);
void TDNS_SetDNSPort(TDNS *self, slim_int in_port);
void TDNS_SetMaxRetry(TDNS *self, slim_int in_retry);
void TDNS_SetRetryInterval(TDNS *self, slim_int in_interval);
#endif /* SLIM_CONFIG_USE_DNS */

/* slim_media_scheme.c */

#ifdef SLIM_CONFIG_USE_MEDIA_SCHEME
slim_bool TMediaSchemeInfo_Validate(slim_char *in_str, slim_int in_len, slim_int in_charset);
#endif /* SLIM_CONFIG_USE_MEDIA_SCHEME */

/* slim_url_string.c */

slim_int slim_url_ss_scheme(slim_char *in_s, slim_int in_len, slim_split_ss *out_ss);
slim_bool TString_FormatConvURIPart(TString self, TStringFormatCookie *inout_cookie, slim_split_ss *in_ss, slim_int in_flag);
slim_int URLString_MakeEscapedAbsURL(TURLString in_base, slim_char *in_s, slim_int in_len, slim_int in_chset, slim_int in_to_charset, TURLSchemeInfoClass *in_scheme_class, TURLString *out_url, slim_int *out_url_charset);
slim_bool TURLString_IsSameScheme(TURLString self, slim_char *in_scheme, slim_int in_len);
slim_int TURLString_MakeURLWithoutQuery(TURLString self, TURLSchemeInfoClass *in_class, TURLString *out_url);
slim_int TURLString_MakeFragmentString(TURLString self, TURLSchemeInfoClass *in_class, TString *out_fragment);
slim_int TURLString_MakeURLWithoutFragment(TURLString self, TURLSchemeInfoClass *in_class, TURLString *out_url);
slim_int TURLString_MakeCanonicalRootURL(TURLString self, TURLSchemeInfoClass *in_class, TURLString *out_url);
void slim_split_url_ss(slim_char *in_spec, slim_int in_len, slim_split_ss *out_ss);
slim_int slim_format_us(slim_char *out_s, TURLString in_s);
TURLString URLString_NewCIDSS(slim_char *in_cid, slim_int in_len);
slim_bool URLSchemeInfo_Initialize(TURLSchemeInfoClass *in_class, TDataArena *in_arena);
void URLSchemeInfo_Finalize(TURLSchemeInfoClass *in_class);
TString URLSchemeInfo_CompositURL(TURLSchemeInfoClass *in_class, slim_split_ss *in_url_ss, slim_int in_charset, slim_int in_scheme_conv_flag, slim_int in_userinfo_conv_flag, slim_int in_host_conv_flag, slim_int in_port_conv_flag, slim_int in_path_conv_flag, slim_int in_query_conv_flag, slim_int in_fragment_conv_flag);
slim_int URLSchemeInfo_MakeResolvedURLX(TURLSchemeInfoClass *in_class, TURLString in_base, slim_char *in_s, slim_int in_len, slim_int in_src_charset, slim_int in_dest_charset, slim_int in_pct_conv_flag, slim_int in_resolve_flag, TURLString *out_url, slim_int *out_scheme_id, slim_int *out_charset);
slim_int URLSchemeInfo_ConvertURLReadableX(TURLSchemeInfoClass *in_class, TURLString in_url, slim_int in_url_charset, slim_char *in_fragment, slim_int in_fragment_len, slim_int in_fragment_charset, slim_int in_dest_charset, slim_int in_mode, TString *out_str);
slim_int URLSchemeInfo_IDFindSS(TURLSchemeInfoClass *in_class, slim_char *in_s, slim_int in_len);
slim_bool URLSchemeInfo_ItemInfo(TURLSchemeInfoClass *in_class, slim_int in_id, slim_int *out_scheme_flag, slim_char **out_default_host, slim_int *out_default_port, slim_int *out_charset, URLSchemeMakeAbsoluteProc *out_alt_proc);
void URLSchemeInfo_SplitURLX(TURLSchemeInfoClass *in_class, slim_char *in_spec, slim_int in_len, slim_split_ss *out_ss, slim_int *out_scheme_id, slim_int *out_scheme_flag, slim_char **out_default_host, slim_int *out_default_port);
TURLString URLSchemeInfo_MakeURLWithQueryX(TURLSchemeInfoClass *in_class, TURLString in_base, slim_char *in_query, slim_int in_query_len, slim_bool in_add);
slim_bool URLSchemeInfo_CompareURLSS(TURLSchemeInfoClass *in_class, TURLString in_url, slim_char *in_s, slim_int in_len, slim_int in_flag);

/* slim_inet_postdata.c */

TPostData TPostData_Duplicate(TPostData self);
slim_bool TPostData_Equal(TPostData self, TPostData in_another);
slim_int TPostData_AppendSpecialFileData(TPostData self, slim_char *in_name, slim_int in_name_len, slim_char *in_value, slim_int in_value_len, slim_char *in_mimetype, slim_int in_mimetype_len, slim_opaque in_userdata, PostData_FetchSpecialFileProc in_fetch, PostData_DeleteSpecialFileProc in_delete);
slim_int TPostData_SetData(TPostData self, slim_char *in_post_data, slim_int in_post_data_len);
TPostDataCursor * TPostData_Cursor(TPostData self, slim_int in_buf_len);
void TPostDataCursor_Delete(TPostDataCursor *self);
slim_int TPostDataCursor_Fetch(TPostDataCursor *self);
slim_int TPostDataCursor_MeasureLength(TPostDataCursor *self);
void TPostDataCursor_Consume(TPostDataCursor *self, slim_int in_len);

/* slim_inet_util.c */

slim_bool slim_inet_split_header_params(slim_split_ss *inout_ss);
slim_bool slim_inet_split_headers(slim_split_ss *inout_ss);
slim_bool slim_inet_find_header(slim_split_ss *inout_ss, slim_char *in_name, slim_int in_len);
TString String_NewBase64SS(slim_char *in_s, slim_int in_len);
slim_bool TString_FormatBase64SS(TString self, TStringFormatCookie *inout_cookie, slim_char *in_s, slim_int in_len);
slim_bool TString_FormatBase64CS(TString self, TStringFormatCookie *inout_cookie, slim_char *in_s);
slim_bool TString_FormatBase64TS(TString self, TStringFormatCookie *inout_cookie, TString in_s);
void slim_base64_make_revtbl(slim_char *in_table, slim_char *out_table);
slim_int slim_base64_decode_oneline( slim_char *in_buf, slim_int in_read_len, slim_char *out_buf, slim_int *out_write_len);
slim_int slim_base64_percent_decode(slim_char *in_s, slim_int in_len, slim_char *out_buf, slim_int in_buflen, slim_char *in_eol_code, slim_char *in_base64_rev);
slim_int slim_quotedprintable_decode_oneline( slim_char *in_buf, slim_int in_read_len, slim_char *out_buf, slim_int *out_write_len);
slim_bool slim_inet_read_netaddr_v6(slim_char *in_s, slim_int in_len, slim_ip_addr *out_addr);
slim_bool slim_inet_read_netaddr(slim_char *in_s, slim_int in_len, slim_ip_addr *out_addr);
slim_int slim_inet_read_cache_control(slim_char *in_s, slim_int in_len, slim_int *out_max_age, slim_bool *out_no_cache, slim_bool *out_no_store, slim_bool *out_must_revalidate);
slim_bool slim_inet_split_content_disposition(slim_split_ss *inout_ss);
slim_bool slim_inet_read_content_disposition(slim_split_ss *inout_ss, slim_bool *out_attachment);
slim_bool slim_inet_split_multipart_x(slim_split_ss *inout_ss);
slim_int slim_inet_read_http_status_line(TString in_header, slim_int *out_off, slim_int *out_len, slim_int *out_phrase_off, slim_int *out_phrase_len);
slim_int slim_inet_normalize_http_multiline_headers(slim_vhandle in_buf, slim_int *inout_buf_len);
slim_int slim_inet_cmp_path(slim_char *in_path1, slim_int in_path1_len, slim_char *in_path2, slim_int in_path2_len);
slim_bool slim_inet_check_suffix(slim_char *in_n, slim_int in_nlen, slim_char *in_s);
slim_char * slim_inet_get_mime_boundary(slim_bool in_end);
TString slim_inet_make_boundary(void);
slim_int slim_inet_parse_content_range(TString in_header, slim_int in_status_code, slim_int in_content_length, slim_int *out_first_byte_pos, slim_int *out_partial_len, slim_int *out_instance_length);
