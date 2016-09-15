/*
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* WARNING: DO NOT EDIT! This file is generated automatically. */



/* slim_clib.c */

void slim_clib_initialize(void);
void slim_clib_finalize(void);

/* slim_clib_format.c */

slim_int slim_format_int(slim_char *out_s, slim_int in_n);
slim_int slim_format_uint(slim_char *out_s, slim_word in_n);
slim_int slim_format_char(slim_char *out_s, slim_int in_c);
slim_int slim_format_wchar(slim_char *out_s, slim_int in_c, slim_int in_charset);
slim_int slim_format_ss_case(slim_char *out_s, slim_char *in_s, slim_int in_len, slim_bool in_lower);
slim_int slim_format_ss(slim_char *out_s, slim_char *in_s, slim_int in_len);
slim_int slim_format_cs(slim_char *out_s, slim_char *in_s);
slim_int slim_format_printf(slim_char *out_s, slim_char *in_format, ...);
slim_int slim_format_ts(slim_char *out_s, TString in_s);
slim_int slim_format_fs(slim_char *out_s, TFixedString in_s);
slim_int slim_format_int_radix_case(slim_char *out_s, slim_int in_n, slim_int in_radix, slim_bool in_upper);
slim_int slim_format_uint_any(slim_char *out_s, slim_word in_n, slim_int in_radix, slim_bool in_upper);
slim_int slim_format_uintX(slim_char *out_s, slim_word in_n, slim_int in_radix, slim_char in_padding, slim_int in_min_width, slim_bool in_upper);
slim_int slim_format_rfc2396_escape(slim_char *out_s, slim_char *in_s, slim_int in_len, slim_bool in_upper);
slim_int slim_format_rfc2396_unescape(slim_char *out_s, slim_char *in_s, slim_int in_len);
slim_int slim_format_rfc3986_pct_encode(slim_char *out_s, slim_char *in_s, slim_int in_len, slim_bool in_upper);
slim_int slim_format_rfc3986_pct_decode(slim_char *out_s, slim_char *in_s, slim_int in_len);
slim_int slim_format_squeeze_white(slim_char *out_s, slim_char *in_s, slim_int in_len, slim_bool in_zap);
slim_int slim_format_binary(slim_char *out_s, slim_byte *in_bin, slim_int in_len, slim_bool in_upper);

/* slim_clib_memxxx.c */

void * slim_memchr(void *in_buf, slim_int in_c, slim_int in_count);
void * slim_imemchr(void *in_buf, slim_int in_c, slim_int in_count);
slim_int slim_memcmp(void *in_buf1, void *in_buf2, slim_int in_count);
void * slim_memcpy(void *in_dest, void *in_src, slim_int in_count);
void * slim_memmove(void *in_dest, void *in_src, slim_int in_count);
void * slim_memset(void *in_dest, slim_int in_c, slim_int in_count);

/* slim_clib_numeric.c */

void slim_set_random_seed(slim_int in_seed);
slim_int slim_random(slim_int in_n);
slim_int slim_log2_u(slim_word in_n);
slim_int slim_log(slim_int in_n, slim_int in_base);

/* slim_clib_rsplit.c */

slim_bool slim_rsplxxx_char(slim_split_ss *inout_ss, slim_int in_c, slim_int in_xxx);
slim_bool slim_rsplxxx_ichar(slim_split_ss *inout_ss, slim_int in_c, slim_int in_xxx);
slim_bool slim_rsplxxx_delim_ctype(slim_split_ss *inout_ss, slim_int in_ctype, slim_int in_xxx);
slim_bool slim_rsplxxx_delim_ctype_proc(slim_split_ss *inout_ss, slim_ctype_proc in_ctype_proc, slim_int in_xxx);
slim_bool slim_rsplxxx_span_ctype(slim_split_ss *inout_ss, slim_int in_ctype, slim_int in_xxx);
slim_bool slim_rsplxxx_span_ctype_proc(slim_split_ss *inout_ss, slim_ctype_proc in_ctype_proc, slim_int in_xxx);

/* slim_clib_split.c */

void slim_splxxx_split(slim_split_ss *inout_ss, slim_char *in_s, slim_int in_slen, slim_bool in_found, slim_int in_found_len, slim_int in_xxx);
slim_bool slim_spltoken_delim_ctype(slim_split_ss *inout_ss, slim_int in_ctype);
slim_bool slim_spltoken_delim_ctype_proc(slim_split_ss *inout_ss, slim_ctype_proc in_ctype_proc);
slim_bool slim_spltoken_span_ctype(slim_split_ss *inout_ss, slim_int in_ctype);
slim_bool slim_spltoken_span_ctype_proc(slim_split_ss *inout_ss, slim_ctype_proc in_ctype_proc);
slim_bool slim_spltoken_delim(slim_split_ss *inout_ss, slim_char *in_chars);
slim_bool slim_spltoken_span(slim_split_ss *inout_ss, slim_char *in_chars);
slim_bool slim_splxxx_delim_ctype(slim_split_ss *inout_ss, slim_int in_ctype, slim_int in_xxx);
slim_bool slim_splxxx_delim_ctype_or_chars(slim_split_ss *inout_ss, slim_int in_ctype, slim_int in_xxx, slim_char *in_chars);
slim_bool slim_splxxx_delim_ctype_proc(slim_split_ss *inout_ss, slim_ctype_proc in_ctype_proc, slim_int in_xxx);
slim_bool slim_splxxx_span_ctype(slim_split_ss *inout_ss, slim_int in_ctype, slim_int in_xxx);
slim_bool slim_splxxx_span_ctype_or_chars(slim_split_ss *inout_ss, slim_int in_ctype, slim_int in_xxx, slim_char *in_chars);
slim_bool slim_splxxx_span_ctype_proc(slim_split_ss *inout_ss, slim_ctype_proc in_ctype_proc, slim_int in_xxx);
slim_bool slim_splxxx_delim(slim_split_ss *inout_ss, slim_char *in_chars, slim_int in_xxx);
slim_bool slim_splxxx_span(slim_split_ss *inout_ss, slim_char *in_chars, slim_int in_xxx);
slim_bool slim_splxxx_str(slim_split_ss *inout_ss, slim_char *in_str, slim_int in_xxx);
slim_bool slim_splxxx_istr(slim_split_ss *inout_ss, slim_char *in_str, slim_int in_xxx);
slim_bool slim_splxxx_char(slim_split_ss *inout_ss, slim_int in_c, slim_int in_xxx);
slim_bool slim_splxxx_ichar(slim_split_ss *inout_ss, slim_int in_c, slim_int in_xxx);
slim_bool slim_splxxx_eol(slim_split_ss *inout_ss, slim_int in_xxx);

/* slim_clib_ss.c */

void slim_ss_skipwhite(slim_char **inout_s, slim_int *inout_len);
void slim_ss_zapwhite(slim_char **inout_s, slim_int *inout_len);
void slim_ss_skipdquote(slim_char **inout_s, slim_int *inout_len);
void slim_ss_zapdquote(slim_char **inout_s, slim_int *inout_len);
slim_int slim_ss_hash(slim_char *in_s, slim_int in_len);
slim_int slim_cs_hash(slim_char *in_s);
slim_int slim_ss_ihash(slim_char *in_s, slim_int in_len);
slim_int slim_cs_ihash(slim_char *in_s);
slim_bool slim_ss_streq_cs(slim_char *in_s, slim_int in_slen, slim_char *in_t);
slim_bool slim_ss_streq_ss(slim_char *in_s, slim_int in_slen, slim_char *in_t, slim_int in_tlen);
slim_bool slim_ss_istreq_ss(slim_char *in_s, slim_int in_slen, slim_char *in_t, slim_int in_tlen);
slim_bool slim_ss_prefix_cs(slim_char *in_s, slim_int in_slen, slim_char *in_t);
slim_bool slim_ss_prefix_ss(slim_char *in_s, slim_int in_slen, slim_char *in_t, slim_int in_tlen);
slim_bool slim_ss_iprefix_cs(slim_char *in_s, slim_int in_slen, slim_char *in_t);
slim_bool slim_ss_iprefix_ss(slim_char *in_s, slim_int in_slen, slim_char *in_t, slim_int in_tlen);

/* slim_clib_strtoxxx.c */

slim_int slim_ctoi(slim_char in_c);
slim_int slim_ss_safe_strtoi(slim_char *in_s, slim_int in_len, slim_char **out_s, slim_int *out_len, slim_int in_base, slim_bool *out_overflow);
slim_word slim_ss_safe_strtoui32(slim_char *in_s, slim_int in_len, slim_char **out_s, slim_int *out_len, slim_int in_base, slim_bool *out_overflow);

/* slim_clib_strxxx.c */

#ifdef USE_DLNA_STRING_PEER
typedef slim_size dlna_size_t;
dlna_size_t dlna_strlen(const slim_char *in_s);
slim_char *dlna_strcpy(slim_char *in_s1, slim_char *in_s2);
slim_char *dlna_strncpy(slim_char *in_s1, slim_char *in_s2, dlna_size_t in_count);
slim_char *dlna_strcat(slim_char *in_string1, slim_char *in_string2);
slim_char *dlna_strncat (slim_char *in_string1, slim_char *in_string2, dlna_size_t in_count);
slim_int dlna_strcmp(const slim_char *in_s1, const slim_char *in_s2);
slim_int dlna_strcmp_nocase(const slim_char *in_s1, const slim_char *in_s2);
slim_int dlna_strncmp(const slim_char *in_s1, const slim_char *in_s2, dlna_size_t in_count);
slim_int dlna_strncmp_nocase(const slim_char *in_s1, const slim_char *in_s2, dlna_size_t in_count);
#define slim_strlen dlna_strlen
#define slim_strcpy dlna_strcpy
#define slim_strncpy dlna_strncpy
#define slim_strcat dlna_strcat
#define slim_strncat dlna_strncat
#define slim_strcmp dlna_strcmp
#define slim_strncmp dlna_strncmp
#define slim_strcmp_nocase dlna_strcmp_nocase
#define slim_strncmp_nocase dlna_strncmp_nocase
#else /* USE_DLNA_STRING_PEER */
slim_int slim_strlen(slim_char *in_s);
slim_char * slim_strcpy(slim_char *in_s1, slim_char *in_s2);
slim_char * slim_strcat(slim_char *in_s1, slim_char *in_s2);
slim_char * slim_strncat(slim_char *in_s1, slim_char *in_s2, slim_int in_count);
slim_char * slim_strncpy(slim_char *in_s1, slim_char *in_s2, slim_int in_count);
slim_int slim_strcmp(slim_char *in_s, slim_char *in_t);
slim_int slim_strcmp_nocase(slim_char *in_s, slim_char *in_t);
slim_int slim_strncmp(slim_char *in_s, slim_char *in_t, slim_int in_n);
slim_int slim_strncmp_nocase(slim_char *in_s, slim_char *in_t, slim_int in_n);
#endif /* USE_DLNA_STRING_PEER */
slim_int slim_sprintf(slim_char *out_s, slim_char *format, ...);
slim_int slim_sscanf(slim_char *in_s, slim_char *format, ...);
slim_int slim_ss_strcmpX_ss(slim_char *in_s, slim_int in_slen, slim_char *in_t, slim_int in_tlen, slim_int in_flag);

/* slim_clib_time.c */

slim_int slim_time_tzoffset(void);
void slim_time_offset_sec(slim_time *out_time, slim_int in_sec);
slim_bool slim_time_currenttime(slim_time *out_time);
slim_bool slim_time_cmp(slim_time *in_t1, slim_time *in_t2, slim_int in_mode);
slim_bool slim_time_parse(slim_char *in_s, slim_int in_len, slim_int in_flag, slim_time *out_time);
slim_int slim_time_difference_sec(slim_time *in_t1, slim_time *in_t2);

/* slim_coll.c */

#ifdef SLIM_CONFIG_DEBUG
void TObjectIterator_Initialize(TObjectIterator *self);
#endif /* SLIM_CONFIG_DEBUG */
void TSpecList_InitIterator(TSpecList *self, TObjectIterator *out_itr);
void TOpaqueList_InitIterator(TOpaqueList *self, TObjectIterator *out_itr);

/* slim_coll_array.c */

#ifndef SLIM_CONFIG_MEMORY_ALTERNATIVE
slim_bool TArray_Initialize(TArray *self, slim_int in_itemsize);
void TArray_Finalize(TArray *self);
void * TArray_AllocItem(TArray *self);
void TArray_FreeItem(TArray *self);
slim_int TArray_CalcOffset(TArray *self, slim_int in_index);
slim_int TArray_AppendSpec(TArray *self, void *in_item);
slim_int TArray_AppendOpaque(TArray *self, slim_opaque in_item);
void TArray_GetSpec(TArray *self, slim_int in_index, void *out_item);
void TArray_SetSpec(TArray *self, slim_int in_index, void *out_item);
slim_opaque TArray_GetOpaque(TArray *self, slim_int in_index);
void TArray_SetOpaque(TArray *self, slim_int in_index, slim_opaque in_item);
slim_int TArray_BeginVisit(TArray *self, slim_int in_index, TArrayVisit *out_visit);
void TArray_EndVisit(TArray *self, TArrayVisit *out_visit);
void * TArray_VisitAt(TArray *self, slim_int in_index, TArrayVisit *inout_visit);
slim_bool TFastArray_Initialize(TFastArray *self, slim_int in_itemsize);
void TFastArray_Finalize(TFastArray *self);
void * TFastArray_AllocItem(TFastArray *self);
void TFastArray_FreeItem(TFastArray *self);
slim_int TFastArray_AppendSpec(TFastArray *self, void *in_item);
slim_int TFastArray_AppendOpaque(TFastArray *self, slim_opaque in_item);
void TFastArray_GetSpec(TFastArray *self, slim_int in_index, void *out_item);
void TFastArray_SetSpec(TFastArray *self, slim_int in_index, void *out_item);
slim_opaque TFastArray_GetOpaque(TFastArray *self, slim_int in_index);
void TFastArray_SetOpaque(TFastArray *self, slim_int in_index, slim_opaque in_item);
slim_int TFastArray_BeginVisit(TFastArray *self, slim_int in_index, TArrayVisit *out_visit);
void TFastArray_EndVisit(TFastArray *self, TArrayVisit *out_visit);
void * TFastArray_VisitAt(TFastArray *self, slim_int in_index, TArrayVisit *inout_visit);
#endif /* SLIM_CONFIG_MEMORY_ALTERNATIVE */

/* slim_coll_array_alt.c */

#ifdef SLIM_CONFIG_MEMORY_ALTERNATIVE
slim_bool TArray_Initialize(TArray *self, slim_int in_itemsize);
void TArray_Finalize(TArray *self);
void * TArray_AllocItem(TArray *self);
void TArray_FreeItem(TArray *self);
slim_int TArray_CalcOffset(TArray *self, slim_int in_index);
void * TArray_CalcAddr(TArray *self, slim_int in_index);
slim_int TArray_AppendSpec(TArray *self, void *in_item);
slim_int TArray_AppendOpaque(TArray *self, slim_opaque in_item);
void TArray_GetSpec(TArray *self, slim_int in_index, void *out_item);
void TArray_SetSpec(TArray *self, slim_int in_index, void *out_item);
slim_opaque TArray_GetOpaque(TArray *self, slim_int in_index);
void TArray_SetOpaque(TArray *self, slim_int in_index, slim_opaque in_item);
slim_int TArray_BeginVisit(TArray *self, slim_int in_index, TArrayVisit *out_visit);
slim_bool TFastArray_Initialize(TFastArray *self, slim_int in_itemsize);
void TFastArray_Finalize(TFastArray *self);
void * TFastArray_AllocItem(TFastArray *self);
void TFastArray_FreeItem(TFastArray *self);
void * TFastArray_CalcAddr(TFastArray *self, slim_int in_index);
slim_int TFastArray_AppendSpec(TFastArray *self, void *in_item);
slim_int TFastArray_AppendOpaque(TFastArray *self, slim_opaque in_item);
void TFastArray_GetSpec(TFastArray *self, slim_int in_index, void *out_item);
void TFastArray_SetSpec(TFastArray *self, slim_int in_index, void *out_item);
slim_opaque TFastArray_GetOpaque(TFastArray *self, slim_int in_index);
void TFastArray_SetOpaque(TFastArray *self, slim_int in_index, slim_opaque in_item);
slim_int TFastArray_BeginVisit(TFastArray *self, slim_int in_index, TArrayVisit *out_visit);
#endif /* SLIM_CONFIG_MEMORY_ALTERNATIVE */

/* slim_coll_bag.c */

#ifndef SLIM_CONFIG_MEMORY_ALTERNATIVE
slim_bool TBag_InitializeX(TBag *self, slim_int in_headersize, slim_int in_itemsize);
slim_bool TBag_Initialize(TBag *self, slim_int in_itemsize);
void TBag_Finalize(TBag *self);
slim_pix TBag_AllocHolder(TBag *self, TBagItemHolder **out_holder);
void TBag_FreeHolder(TBag *self, slim_pix in_pix);
#ifdef SLIM_CONFIG_DEBUG
TBagItemHolder * TBag_Locate(TBag *self, slim_pix in_pix);
void TBag_Unlocate(TBag *self, slim_pix in_pix);
#endif
void TBag_MakeEmpty(TBag *self);
void TBag_GetSpec(TBag *self, slim_pix in_pix, void *out_item);
void TBag_SetSpec(TBag *self, slim_pix in_pix, void *in_item);
slim_opaque TBag_GetOpaque(TBag *self, slim_pix in_pix);
void TBag_SetOpaque(TBag *self, slim_pix in_pix, slim_opaque in_item);
slim_pix TBag_NewItem(TBag *self);
slim_pix TBag_ZeroNewItem(TBag *self);
#ifdef SLIM_CONFIG_DEBUG
void * TBag_LockItem(TBag *self, slim_pix in_pix);
void TBag_UnlockItem(TBag *self, slim_pix in_pix);
#endif
#endif /* SLIM_CONFIG_MEMORY_ALTERNATIVE */

/* slim_coll_bag_alt.c */

#ifdef SLIM_CONFIG_MEMORY_ALTERNATIVE
slim_bool TBag_InitializeX(TBag *self, slim_int in_headersize, slim_int in_itemsize);
slim_bool TBag_Initialize(TBag *self, slim_int in_itemsize);
void TBag_Finalize(TBag *self);
slim_pix TBag_AllocHolder(TBag *self, TBagItemHolder **out_holder);
void TBag_FreeHolder(TBag *self, slim_pix in_pix);
#ifdef SLIM_CONFIG_DEBUG
TBagItemHolder * TBag_Locate(TBag *self, slim_pix in_pix);
void TBag_Unlocate(TBag *self, slim_pix in_pix);
#endif
void TBag_MakeEmpty(TBag *self);
void TBag_GetSpec(TBag *self, slim_pix in_pix, void *out_item);
void TBag_SetSpec(TBag *self, slim_pix in_pix, void *in_item);
slim_opaque TBag_GetOpaque(TBag *self, slim_pix in_pix);
void TBag_SetOpaque(TBag *self, slim_pix in_pix, slim_opaque in_item);
slim_pix TBag_NewItem(TBag *self);
slim_pix TBag_ZeroNewItem(TBag *self);
#ifdef SLIM_CONFIG_DEBUG
void * TBag_LockItem(TBag *self, slim_pix in_pix);
void TBag_UnlockItem(TBag *self, slim_pix in_pix);
#endif
#endif /* SLIM_CONFIG_MEMORY_ALTERNATIVE */

/* slim_coll_hash.c */

void THash_Initialize(THash *self, slim_int in_table_size, slim_int in_next_offset, slim_opaque in_item_coll, slim_opaque in_key_coll, THashGetKeyProc in_get_key_proc, THashItemHashProc in_item_hash_proc, THashExtHashProc in_ext_hash_proc, THashEqualProc in_equal_proc, THashLockItemProc in_lock_item_proc, THashUnlockItemProc in_unlock_item_proc, slim_opaque *in_table);
void THash_Finalize(THash *self);
#ifdef SLIM_CONFIG_DEBUG_HASH_DISTRIBUTION
slim_bool THash_DebugEnableDistribution(THash *self);
void THash_DebugDumpDistribution(THash *self);
#endif
slim_opaque THash_Find1(THash *self, slim_opaque in_ext_key, slim_int *out_hash);
void THash_Insert1(THash *self, slim_opaque in_item, void *in_iitem, slim_int in_hash);
slim_bool THash_Insert2(THash *self, slim_opaque in_item, slim_opaque *out_item, slim_int in_flag);
slim_bool THash_Remove1(THash *self, slim_opaque in_item);

/* slim_coll_linear_array.c */

void* TLinearArray_VisitAtX_Checked(TLinearArray* self, slim_int in_i, TLinearArrayVisit* in_visit);
slim_bool TLinearArray_InitializeX(TLinearArray *self, slim_int in_item_size, slim_int in_capacity);
void TLinearArray_Finalize(TLinearArray *self);
void TLinearArray_MakeEmpty(TLinearArray *self);
void TLinearArray_SetRoundup(TLinearArray *self, slim_int in_roundup);
slim_bool TLinearArray_SetLength(TLinearArray *self, slim_int in_req_len);
slim_int TLinearArray_AppendN3(TLinearArray *self, void* in_item, slim_int in_n);
void TLinearArray_GetAt(TLinearArray *self, slim_int in_i, void* out_item);
void TLinearArray_SetItem(TLinearArray *self, slim_int in_i, void *in_item);
slim_int TLinearArray_BeginVisit(TLinearArray *self, slim_int in_index, TLinearArrayVisit *out_visit);

/* slim_coll_list.c */

#ifndef SLIM_CONFIG_MEMORY_ALTERNATIVE
slim_bool TList_Initialize(TList *self, slim_int in_header_size, slim_int in_itemsize);
slim_pix TList_Last(TList *self);
slim_pix TList_Next(TList *self, slim_pix in_pix);
slim_pix TList_Prev(TList *self, slim_pix in_pix);
void TList_Remove(TList *self, slim_pix in_pix);
void TList_Unchain(TList *self, slim_pix in_pix);
void TList_ChainAfter(TList *self, slim_pix in_after_this, slim_pix in_pix);
void TList_ChainBefore(TList *self, slim_pix in_before_this, slim_pix in_pix);
slim_bool TList_IsChained(TList *self, slim_pix in_pix);
slim_pix TList_Nth(TList *self, slim_int in_n);
slim_int TList_Order(TList *self, slim_pix in_pix);
slim_bool TSpecList_Initialize(TSpecList *self, slim_int in_itemsize);
slim_pix TSpecList_InsertAfter(TSpecList *self, slim_pix in_pix, void *in_item);
slim_pix TSpecList_InsertBefore(TSpecList *self, slim_pix in_pix, void *in_item);
slim_bool TOpaqueList_Initialize(TOpaqueList *self);
slim_pix TOpaqueList_InsertAfter(TOpaqueList *self, slim_pix in_pix, slim_opaque in_item);
slim_pix TOpaqueList_InsertBefore(TOpaqueList *self, slim_pix in_pix, slim_opaque in_item);
slim_bool TList_BeginVisit(TList *self, slim_pix in_pix, TListVisit *out_visit);
void TList_EndVisit(TList *self, TListVisit *in_visit);
void * TList_VisitAt(TList *self, slim_pix in_pix, TListVisit *inout_visit);
void * TList_VisitFirst(TList *self, TListVisit *inout_visit);
void * TList_VisitLast(TList *self, TListVisit *inout_visit);
void * TList_VisitNext(TList *self, TListVisit *inout_visit);
void * TList_VisitPrev(TList *self, TListVisit *inout_visit);
#endif /* SLIM_CONFIG_MEMORY_ALTERNATIVE */

/* slim_coll_list_alt.c */

#ifdef SLIM_CONFIG_MEMORY_ALTERNATIVE
slim_bool TList_Initialize(TList *self, slim_int in_header_size, slim_int in_itemsize);
slim_pix TList_Last(TList *self);
slim_pix TList_Next(TList *self, slim_pix in_pix);
slim_pix TList_Prev(TList *self, slim_pix in_pix);
void TList_Remove(TList *self, slim_pix in_pix);
void TList_Unchain(TList *self, slim_pix in_pix);
void TList_ChainAfter(TList *self, slim_pix in_after_this, slim_pix in_pix);
void TList_ChainBefore(TList *self, slim_pix in_before_this, slim_pix in_pix);
slim_bool TList_IsChained(TList *self, slim_pix in_pix);
slim_pix TList_Nth(TList *self, slim_int in_n);
slim_int TList_Order(TList *self, slim_pix in_pix);
slim_bool TSpecList_Initialize(TSpecList *self, slim_int in_itemsize);
slim_pix TSpecList_InsertAfter(TSpecList *self, slim_pix in_pix, void *in_item);
slim_pix TSpecList_InsertBefore(TSpecList *self, slim_pix in_pix, void *in_item);
slim_bool TOpaqueList_Initialize(TOpaqueList *self);
slim_pix TOpaqueList_InsertAfter(TOpaqueList *self, slim_pix in_pix, slim_opaque in_item);
slim_pix TOpaqueList_InsertBefore(TOpaqueList *self, slim_pix in_pix, slim_opaque in_item);
slim_bool TList_BeginVisit(TList *self, slim_pix in_pix, TListVisit *out_visit);
void * TList_VisitFirst(TList *self, TListVisit *inout_visit);
void * TList_VisitLast(TList *self, TListVisit *inout_visit);
void * TList_VisitNext(TList *self, TListVisit *inout_visit);
void * TList_VisitPrev(TList *self, TListVisit *inout_visit);
#endif /* SLIM_CONFIG_MEMORY_ALTERNATIVE */

/* slim_coll_tree.c */

#ifndef SLIM_CONFIG_MEMORY_ALTERNATIVE
slim_bool TTree_Initialize(TTree *self);
void TTree_MakeEmpty(TTree *self);
slim_pix TTree_NewItem(TTree *self, slim_int in_item_size);
slim_pix TTree_ZeroNewItem(TTree *self, slim_int in_item_size);
void TTree_ChainChildAfter(TTree *self, slim_pix in_parent_pix, slim_pix in_after_this, slim_pix in_pix);
void TTree_ChainChildBefore(TTree *self, slim_pix in_parent_pix, slim_pix in_before_this, slim_pix in_pix);
void TTree_Unchain(TTree *self, slim_pix in_pix);
slim_bool TTree_IsChained(TTree *self, slim_pix in_pix);
#ifdef SLIM_CONFIG_DEBUG
slim_pix TTree_Parent(TTree *self, slim_pix in_pix);
slim_pix TTree_FirstChild(TTree *self, slim_pix in_pix);
slim_pix TTree_Next(TTree *self, slim_pix in_pix);
#endif
slim_pix TTree_Prev(TTree *self, slim_pix in_pix);
void TTree_SetRoot(TTree *self, slim_pix in_pix);
slim_pix TTree_LastChild(TTree *self, slim_pix in_pix);
void TTree_Remove(TTree *self, slim_pix in_pix);
void TTree_TidyRemove(TTree *self, slim_pix in_pix, TTreeTidyProc in_tidy_proc, slim_opaque in_arg);
slim_bool TTree_IsDescendant(TTree *self, slim_pix in_pix1, slim_pix in_pix2);
slim_pix TTree_DuplicateItem(TTree *self, slim_pix in_pix);
slim_bool TTree_BeginVisit(TTree *self, slim_pix in_pix, TTreeVisit *out_visit);
void TTree_EndVisit(TTree *self, TTreeVisit *in_visit);
void * TTree_VisitAt(TTree *self, slim_pix in_pix, TTreeVisit *inout_visit);
void * TTree_VisitRoot(TTree *self, TTreeVisit *inout_visit);
void * TTree_VisitNext(TTree *self, TTreeVisit *inout_visit);
void * TTree_VisitPrev(TTree *self, TTreeVisit *inout_visit);
void * TTree_VisitParent(TTree *self, TTreeVisit *inout_visit);
void * TTree_VisitFirstChild(TTree *self, TTreeVisit *inout_visit);
void * TTree_VisitLastChild(TTree *self, TTreeVisit *inout_visit);
void TTreeTraverse_Initialize(TTreeTraverse *self, slim_pix in_pix, slim_int in_dir);
slim_bool TTreeTraverse_Visited(TTreeTraverse *self, slim_pix in_pix, slim_int in_dir);
slim_int TTreeTraverse_Next(TTreeTraverse *self, TTree *in_tree, slim_pix *out_pix, slim_int *out_dir);
slim_int TTreeTraverse_Prev(TTreeTraverse *self, TTree *in_tree, slim_pix *out_pix, slim_int *out_dir);
void TTreeTraverse_LastVisited(TTreeTraverse *self, slim_pix *out_pix, slim_int *out_dir);
void TTreeTraverse_SkipDescendants(TTreeTraverse *self);
void TTreeTraverse_SkipSiblings(TTreeTraverse *self, slim_pix in_parent);
slim_bool TTreeTraverseVisit_Initialize(TTreeTraverseVisit *self, TTree *in_tree, slim_pix in_pix, slim_int in_dir);
void TTreeTraverseVisit_Finalize(TTreeTraverseVisit *self);
slim_bool TTreeTraverseVisit_Visited(TTreeTraverseVisit *self, slim_pix in_pix, slim_int in_dir);
slim_int TTreeTraverseVisit_Next(TTreeTraverseVisit *self, slim_pix *out_pix, slim_int *out_dir, void **out_ptr);
void TTreeTraverseVisit_LastVisited(TTreeTraverseVisit *self, slim_pix *out_pix, slim_int *out_dir, void **out_ptr);
void TTreeTraverseVisit_SkipDescendants(TTreeTraverseVisit *self);
void TTreeTraverseVisit_SkipSiblings(TTreeTraverseVisit *self, slim_pix in_parent);
#endif /* SLIM_CONFIG_MEMORY_ALTERNATIVE */

/* slim_coll_tree_alt.c */

#ifdef SLIM_CONFIG_MEMORY_ALTERNATIVE
slim_bool TTree_Initialize(TTree *self);
void TTree_MakeEmpty(TTree *self);
slim_pix TTree_NewItem(TTree *self, slim_int in_item_size);
slim_pix TTree_ZeroNewItem(TTree *self, slim_int in_item_size);
void TTree_ChainChildAfter(TTree *self, slim_pix in_parent_pix, slim_pix in_after_this, slim_pix in_pix);
void TTree_ChainChildBefore(TTree *self, slim_pix in_parent_pix, slim_pix in_before_this, slim_pix in_pix);
void TTree_Unchain(TTree *self, slim_pix in_pix);
slim_bool TTree_IsChained(TTree *self, slim_pix in_pix);
slim_pix TTree_Parent(TTree *self, slim_pix in_pix);
slim_pix TTree_Next(TTree *self, slim_pix in_pix);
slim_pix TTree_Prev(TTree *self, slim_pix in_pix);
slim_pix TTree_FirstChild(TTree *self, slim_pix in_pix);
void TTree_SetRoot(TTree *self, slim_pix in_pix);
slim_pix TTree_LastChild(TTree *self, slim_pix in_pix);
void TTree_Remove(TTree *self, slim_pix in_pix);
void TTree_TidyRemove(TTree *self, slim_pix in_pix, TTreeTidyProc in_tidy_proc, slim_opaque in_arg);
slim_bool TTree_IsDescendant(TTree *self, slim_pix in_pix1, slim_pix in_pix2);
slim_pix TTree_DuplicateItem(TTree *self, slim_pix in_pix);
slim_bool TTree_BeginVisit(TTree *self, slim_pix in_pix, TTreeVisit *out_visit);
void * TTree_VisitRoot(TTree *self, TTreeVisit *inout_visit);
void * TTree_VisitNext(TTree *self, TTreeVisit *inout_visit);
void * TTree_VisitPrev(TTree *self, TTreeVisit *inout_visit);
void * TTree_VisitParent(TTree *self, TTreeVisit *inout_visit);
void * TTree_VisitFirstChild(TTree *self, TTreeVisit *inout_visit);
void * TTree_VisitLastChild(TTree *self, TTreeVisit *inout_visit);
void TTreeTraverse_Initialize(TTreeTraverse *self, slim_pix in_pix, slim_int in_dir);
slim_bool TTreeTraverse_Visited(TTreeTraverse *self, slim_pix in_pix, slim_int in_dir);
slim_int TTreeTraverse_Next(TTreeTraverse *self, TTree *in_tree, slim_pix *out_pix, slim_int *out_dir);
slim_int TTreeTraverse_Prev(TTreeTraverse *self, TTree *in_tree, slim_pix *out_pix, slim_int *out_dir);
void TTreeTraverse_LastVisited(TTreeTraverse *self, slim_pix *out_pix, slim_int *out_dir);
void TTreeTraverse_SkipDescendants(TTreeTraverse *self);
void TTreeTraverse_SkipSiblings(TTreeTraverse *self, slim_pix in_parent);
slim_bool TTreeTraverseVisit_Initialize(TTreeTraverseVisit *self, TTree *in_tree, slim_pix in_pix, slim_int in_dir);
void TTreeTraverseVisit_Finalize(TTreeTraverseVisit *self);
slim_bool TTreeTraverseVisit_Visited(TTreeTraverseVisit *self, slim_pix in_pix, slim_int in_dir);
slim_int TTreeTraverseVisit_Next(TTreeTraverseVisit *self, slim_pix *out_pix, slim_int *out_dir, void **out_ptr);
void TTreeTraverseVisit_LastVisited(TTreeTraverseVisit *self, slim_pix *out_pix, slim_int *out_dir, void **out_ptr);
void TTreeTraverseVisit_SkipDescendants(TTreeTraverseVisit *self);
void TTreeTraverseVisit_SkipSiblings(TTreeTraverseVisit *self, slim_pix in_parent);
#endif /* SLIM_CONFIG_MEMORY_ALTERNATIVE */

/* slim_coll_tree_ptr.c */

#ifdef SLIM_CONFIG_POINTER_MEMNODE
slim_bool TPtrTree_Initialize(TPtrTree *self);
void TPtrTree_MakeEmpty(TPtrTree *self);
slim_pix TPtrTree_NewItem(TPtrTree *self, slim_int in_item_size);
slim_pix TPtrTree_ZeroNewItem(TPtrTree *self, slim_int in_item_size);
void TPtrTree_ChainChildAfter(TPtrTree *self, slim_pix in_parent_pix, slim_pix in_after_this, slim_pix in_pix);
void TPtrTree_ChainChildBefore(TPtrTree *self, slim_pix in_parent_pix, slim_pix in_before_this, slim_pix in_pix);
void TPtrTree_Unchain(TPtrTree *self, slim_pix in_pix);
slim_bool TPtrTree_IsChained(TPtrTree *self, slim_pix in_pix);
#ifdef SLIM_CONFIG_DEBUG
slim_pix TPtrTree_Parent(TPtrTree *self, slim_pix in_pix);
slim_pix TPtrTree_FirstChild(TPtrTree *self, slim_pix in_pix);
slim_pix TPtrTree_Next(TPtrTree *self, slim_pix in_pix);
#endif
slim_pix TPtrTree_Prev(TPtrTree *self, slim_pix in_pix);
void TPtrTree_SetRoot(TPtrTree *self, slim_pix in_pix);
slim_pix TPtrTree_LastChild(TPtrTree *self, slim_pix in_pix);
void TPtrTree_Remove(TPtrTree *self, slim_pix in_pix);
void TPtrTree_TidyRemove(TPtrTree *self, slim_pix in_pix, TPtrTreeTidyProc in_tidy_proc, slim_opaque in_arg);
slim_bool TPtrTree_IsDescendant(TPtrTree *self, slim_pix in_pix1, slim_pix in_pix2);
slim_pix TPtrTree_DuplicateItem(TPtrTree *self, slim_pix in_pix);
slim_bool TPtrTree_BeginVisit(TPtrTree *self, slim_pix in_pix, TPtrTreeVisit *out_visit);
void TPtrTree_EndVisit(TPtrTree *self, TPtrTreeVisit *in_visit);
void * TPtrTree_VisitAt(TPtrTree *self, slim_pix in_pix, TPtrTreeVisit *inout_visit);
void * TPtrTree_VisitRoot(TPtrTree *self, TPtrTreeVisit *inout_visit);
void * TPtrTree_VisitNext(TPtrTree *self, TPtrTreeVisit *inout_visit);
void * TPtrTree_VisitPrev(TPtrTree *self, TPtrTreeVisit *inout_visit);
void * TPtrTree_VisitParent(TPtrTree *self, TPtrTreeVisit *inout_visit);
void * TPtrTree_VisitFirstChild(TPtrTree *self, TPtrTreeVisit *inout_visit);
void * TPtrTree_VisitLastChild(TPtrTree *self, TPtrTreeVisit *inout_visit);
void TPtrTreeTraverse_Initialize(TPtrTreeTraverse *self, slim_pix in_pix, slim_int in_dir);
slim_bool TPtrTreeTraverse_Visited(TPtrTreeTraverse *self, slim_pix in_pix, slim_int in_dir);
slim_int TPtrTreeTraverse_Next(TPtrTreeTraverse *self, TPtrTree *in_tree, slim_pix *out_pix, slim_int *out_dir);
slim_int TPtrTreeTraverse_Prev(TPtrTreeTraverse *self, TPtrTree *in_tree, slim_pix *out_pix, slim_int *out_dir);
void TPtrTreeTraverse_LastVisited(TPtrTreeTraverse *self, slim_pix *out_pix, slim_int *out_dir);
void TPtrTreeTraverse_SkipDescendants(TPtrTreeTraverse *self);
void TPtrTreeTraverse_SkipSiblings(TPtrTreeTraverse *self, slim_pix in_parent);
slim_bool TPtrTreeTraverseVisit_Initialize(TPtrTreeTraverseVisit *self, TPtrTree *in_tree, slim_pix in_pix, slim_int in_dir);
void TPtrTreeTraverseVisit_Finalize(TPtrTreeTraverseVisit *self);
slim_bool TPtrTreeTraverseVisit_Visited(TPtrTreeTraverseVisit *self, slim_pix in_pix, slim_int in_dir);
slim_int TPtrTreeTraverseVisit_Next(TPtrTreeTraverseVisit *self, slim_pix *out_pix, slim_int *out_dir, void **out_ptr);
void TPtrTreeTraverseVisit_LastVisited(TPtrTreeTraverseVisit *self, slim_pix *out_pix, slim_int *out_dir, void **out_ptr);
void TPtrTreeTraverseVisit_SkipDescendants(TPtrTreeTraverseVisit *self);
void TPtrTreeTraverseVisit_SkipSiblings(TPtrTreeTraverseVisit *self, slim_pix in_parent);
#endif /* SLIM_CONFIG_POINTER_MEMNODE */

/* slim_coll_vbag.c */

#ifndef SLIM_CONFIG_MEMORY_ALTERNATIVE
slim_bool TVarBag_InitializeX(TVarBag *self, slim_int in_header_sz);
slim_bool TVarBag_Initialize(TVarBag *self);
void TVarBag_Finalize(TVarBag *self);
slim_pix TVarBag_AllocHolder(TVarBag *self, slim_int in_item_size, void **out_holder);
void TVarBag_FreeHolder(TVarBag *self, slim_pix in_pix);
#ifdef SLIM_CONFIG_DEBUG
void * TVarBag_Locate(TVarBag *self, slim_pix in_pix);
void TVarBag_Unlocate(TVarBag *self, slim_pix in_pix);
#endif
void TVarBag_MakeEmpty(TVarBag *self);
slim_bool TVarBag_IsEmpty(TVarBag *self);
void TVarBag_CopyOut(TVarBag *self, slim_pix in_pix, slim_int in_off, slim_int in_len, void *out_buf);
void TVarBag_CopyIn(TVarBag *self, slim_pix in_pix, slim_int in_off, slim_int in_len, void *in_buf);
slim_pix TVarBag_NewItem(TVarBag *self, slim_int in_item_size);
slim_pix TVarBag_ZeroNewItem(TVarBag *self, slim_int in_item_size);
void TVarBag_Remove(TVarBag *self, slim_pix in_pix);
slim_pix TVarBag_DuplicateItem(TVarBag *self, slim_pix in_pix);
#ifdef SLIM_CONFIG_DEBUG
void * TVarBag_LockItem(TVarBag *self, slim_pix in_pix);
void TVarBag_UnlockItem(TVarBag *self, slim_pix in_pix);
#endif
#ifdef SLIM_CONFIG_DEBUG
void TVarBag_DebugOutStatisticsX(TVarBag *self, slim_bool in_newline, slim_int in_header_size);
#endif
#endif /* SLIM_CONFIG_MEMORY_ALTERNATIVE */

/* slim_coll_vbag_alt.c */

#ifdef SLIM_CONFIG_MEMORY_ALTERNATIVE
slim_bool TVarBag_InitializeX(TVarBag *self, slim_int in_header_sz);
slim_bool TVarBag_Initialize(TVarBag *self);
void TVarBag_Finalize(TVarBag *self);
slim_pix TVarBag_AllocHolder(TVarBag *self, slim_int in_item_size, void **out_holder);
void TVarBag_FreeHolder(TVarBag *self, slim_pix in_pix);
#ifdef SLIM_CONFIG_DEBUG
void * TVarBag_Locate(TVarBag *self, slim_pix in_pix);
void TVarBag_Unlocate(TVarBag *self, slim_pix in_pix);
#endif
void TVarBag_MakeEmpty(TVarBag *self);
slim_bool TVarBag_IsEmpty(TVarBag *self);
void TVarBag_CopyOut(TVarBag *self, slim_pix in_pix, slim_int in_off, slim_int in_len, void *out_buf);
void TVarBag_CopyIn(TVarBag *self, slim_pix in_pix, slim_int in_off, slim_int in_len, void *in_buf);
slim_pix TVarBag_NewItem(TVarBag *self, slim_int in_item_size);
slim_pix TVarBag_ZeroNewItem(TVarBag *self, slim_int in_item_size);
void TVarBag_Remove(TVarBag *self, slim_pix in_pix);
slim_pix TVarBag_DuplicateItem(TVarBag *self, slim_pix in_pix);
#ifdef SLIM_CONFIG_DEBUG
void * TVarBag_LockItem(TVarBag *self, slim_pix in_pix);
void TVarBag_UnlockItem(TVarBag *self, slim_pix in_pix);
#endif
#ifdef SLIM_CONFIG_DEBUG
void TVarBag_DebugOutStatisticsX(TVarBag *self, slim_bool in_newline, slim_int in_header_size);
#endif
#endif /* SLIM_CONFIG_MEMORY_ALTERNATIVE */

/* slim_coll_vbag_ptr.c */

#ifdef SLIM_CONFIG_POINTER_MEMNODE
slim_int TPtrMemNode_GetOff(TPtrMemNode *self, void* in_addr, void** out_page);
void TPtrVarBag_VerifyPix(TPtrVarBag *self, slim_pix in_pix);
void TPtrVarBag_VerifyPixOrNil(TPtrVarBag *self, slim_pix in_pix);
slim_bool TPtrVarBag_InitializeX(TPtrVarBag *self, slim_int in_header_sz);
slim_bool TPtrVarBag_Initialize(TPtrVarBag *self);
void TPtrVarBag_Finalize(TPtrVarBag *self);
slim_pix TPtrVarBag_AllocHolder(TPtrVarBag *self, slim_int in_item_size, void **out_holder);
void TPtrVarBag_FreeHolder(TPtrVarBag *self, slim_pix in_pix);
void TPtrVarBag_MakeEmpty(TPtrVarBag *self);
slim_bool TPtrVarBag_IsEmpty(TPtrVarBag *self);
void TPtrVarBag_CopyOut(TPtrVarBag *self, slim_pix in_pix, slim_int in_off, slim_int in_len, void *out_buf);
void TPtrVarBag_CopyIn(TPtrVarBag *self, slim_pix in_pix, slim_int in_off, slim_int in_len, void *in_buf);
slim_pix TPtrVarBag_NewItem(TPtrVarBag *self, slim_int in_item_size);
slim_pix TPtrVarBag_ZeroNewItem(TPtrVarBag *self, slim_int in_item_size);
void TPtrVarBag_Remove(TPtrVarBag *self, slim_pix in_pix);
slim_pix TPtrVarBag_DuplicateItem(TPtrVarBag *self, slim_pix in_pix);
#ifdef SLIM_CONFIG_DEBUG
void TPtrVarBag_DebugOutStatisticsX(TPtrVarBag *self, slim_bool in_newline, slim_int in_header_size);
#endif
#endif /* SLIM_CONFIG_POINTER_MEMNODE */

/* slim_guibase_color.c */


/* slim_guibase_rect.c */

void TRect_UnionRect2(TRect *self, TRect *in_r, TRect *out_r);

/* slim_guibase_region.c */

#ifdef SLIM_CONFIG_DEBUG
void TRegion_DebugDump(TRegion self);
#endif

/* slim_i18n.c */

TCharSetInfo * CharSetInfo_Find(slim_char *in_s, slim_int in_slen);
void I18NConverter_Initialize(TI18NConverterClass *in_class, slim_int in_arch_langset);
void I18NConverter_Finalize(TI18NConverterClass *in_class);
void TI18NConverter_Initialize(TI18NConverterClass *in_class, TI18NConverter *self);
void TI18NConverter_Finalize(TI18NConverter *self);
slim_int TI18NConverter_Convert(TI18NConverter *self, void *out_p, slim_split_ss *inout_ss);
void TI18NConverter_SetDeterminedCharSet(TI18NConverter *self, slim_int in_chset);
slim_int TI18NConverter_ConvertedCharSet(TI18NConverter *self);
void TI18NStringIterator_DoGetChar(TI18NStringIterator *self);
slim_int TI18NStringIterator_NextX(TI18NStringIterator *self, slim_bool in_strict);
slim_int TI18NStringIterator_Forward(TI18NStringIterator *self, slim_int in_incr, slim_int *out_incr, slim_bool in_chars, slim_bool in_strict);
void TI18NString_Head(TI18NString *self, TI18NStringIterator *out_itr);
slim_int TI18NString_ForeachX(TI18NString *self, TI18NStrForeachProc in_proc, slim_opaque in_arg, slim_bool in_strict);
slim_int TI18NString_Trim(TI18NString *self, slim_int *out_read_len, slim_byte *out_buf);
slim_int TI18NString_CharsBytes(TI18NString *self, slim_int in_num, slim_int *out_chars, slim_int *out_bytes, slim_bool in_chars);
slim_int TI18NString_Chop(TI18NString *self, slim_int *out_chars);
slim_int TI18NString_ConvertToLowerOrUpper(TI18NString *self, slim_int *out_read_len, slim_byte *out_s, slim_bool in_upper);
slim_bool TI18NString_IsASCII(TI18NString *self);
slim_int TI18NString_Chars(TI18NString *self);
void TI18NString_Init(TI18NString *self, slim_byte *in_str, slim_int in_bytes, slim_int in_charset);
slim_int CharSet_ConvLeadingASCII(void *out_p, slim_split_ss *inout_ss);
slim_int CharSet_ChopString2(slim_char *in_s, slim_int in_len, slim_int *out_chars, slim_int in_charset);
slim_int CharSet_StringChars(slim_char *in_s, slim_int in_len, slim_int in_charset);
slim_int CharSet_CharsToBytes(slim_split_ss *inout_ss, slim_int in_chars, slim_int in_charset);
slim_int CharSet_BytesToChars(slim_split_ss *inout_ss, slim_int in_bytes, slim_int in_charset);
slim_int CharSet_ToUpperOrLower(slim_char *in_s, slim_int in_len, slim_char *out_s, slim_int in_charset, slim_bool in_upper);
slim_int CharSet_ToUpper(slim_char *in_s, slim_int in_len, slim_char *out_s, slim_int in_charset);
slim_int CharSet_ToLower(slim_char *in_s, slim_int in_len, slim_char *out_s, slim_int in_charset);
slim_int CharSet_ChangeCase(slim_char *in_s, slim_int in_len, slim_char *out_s, slim_int in_charset, slim_bool in_upper);
slim_int CharSet_Convert_SelfToSelf(void* out_p, slim_split_ss *inout_ss, slim_int in_charset);
slim_int CharSet_Convert(void *out_p, slim_split_ss *inout_ss, slim_int in_to_chset, slim_int in_from_chset);
void TI18NGuessCtx_Init(TI18NGuessCtx *self, slim_int in_chset);
slim_int CharSet_GuessCalcReliability(TI18NGuessCtx *in_ctx, slim_int in_len);
slim_bool slim_i18n_init(void);
void slim_i18n_tidy(void);
slim_int TI18NChar_ReadString(TI18NChar *self, slim_byte *in_s, slim_int in_len, slim_int in_charset);
void TI18NChar_ToLowerOrUpper(TI18NChar *inout_ch, slim_bool in_upper);
slim_bool TI18NChar_Convert(TI18NChar *self, slim_int in_to_charset);
slim_int TI18NChar_CompareX(TI18NChar *self, TI18NChar *in_t, slim_int in_flag);
slim_int slim_i18n_charlen(slim_byte *in_s, slim_int in_len, slim_int in_charset);
void slim_i18n_getch_any(slim_byte *in_str, slim_int in_len, TI18NChar *out_char, slim_int in_charset);
slim_int (slim_i18n_checkch_unknown)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
void (slim_i18n_getch_unknown)(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
slim_int slim_i18n_strcmpX(slim_char *in_s, slim_int in_slen, slim_int in_s_charset, slim_char *in_t, slim_int in_tlen, slim_int in_t_charset, slim_int *out_chars, slim_int in_flag);
void TISO2022Ctx_Init(TISO2022Ctx *self, slim_int in_charset);
void slim_i18n_getch_iso2022(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void slim_i18n_iso2022_make_esc(TI18NChar *inout_char);

/* slim_i18n_arabic.c */

#ifdef SLIM_CONFIG_USE_ARABIC
slim_int (slim_i18n_checkch_ar_iso8859_6)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
slim_int (slim_i18n_checkch_ar_windows_1256)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
void (slim_i18n_getch_ar_iso8859_6)(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void (slim_i18n_getch_ar_windows_1256)(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void slim_i18n_convch_ar_ucs2_to_iso8859_6(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_ar_ucs2_to_windows1256(TI18NChar *in_char, TI18NChar *out_char);
slim_int CharSet_GuessArabic(void *in_p, slim_int in_len, slim_bool in_eod, slim_int *out_score);
slim_int CharSet_ConvertArabic(void* out_p, slim_split_ss *inout_ss, slim_int in_to_charset, slim_int in_from_charset);
#endif /* SLIM_CONFIG_USE_ARABIC */

/* slim_i18n_baltic.c */

#ifdef SLIM_CONFIG_USE_BALTIC
slim_int (slim_i18n_checkch_lv_iso8859_4)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
slim_int (slim_i18n_checkch_lv_windows_1257)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
void (slim_i18n_getch_lv_iso8859_4)(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void (slim_i18n_getch_lv_windows_1257)(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void slim_i18n_convch_lv_ucs2_to_iso8859_4(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_ucs_ucs2_to_windows1257(TI18NChar *in_char, TI18NChar *out_char);
slim_int CharSet_GuessBaltic(void *in_p, slim_int in_len, slim_bool in_eod, slim_int *out_score);
slim_int CharSet_ConvertBaltic(void* out_p, slim_split_ss *inout_ss, slim_int in_to_charset, slim_int in_from_charset);
#endif /* SLIM_CONFIG_USE_BALTIC */

/* slim_i18n_central_european.c */

#ifdef SLIM_CONFIG_USE_CENTRAL_EUROPEAN
slim_int (slim_i18n_checkch_la_iso8859_2)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
slim_int (slim_i18n_checkch_la_windows_1250)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
void (slim_i18n_getch_la_iso8859_2)(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void (slim_i18n_getch_la_windows_1250)(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void slim_i18n_convch_ucs_ucs2_to_iso8859_2(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_ucs_ucs2_to_windows1250(TI18NChar *in_char, TI18NChar *out_char);
slim_int CharSet_GuessCentralEuropean(void *in_p, slim_int in_len, slim_bool in_eod, slim_int *out_score);
slim_int CharSet_ConvertCentralEuropean(void* out_p, slim_split_ss *inout_ss, slim_int in_to_charset, slim_int in_from_charset);
#endif /* SLIM_CONFIG_USE_CENTRAL_EUROPEAN */

/* slim_i18n_chinese.c */

#ifdef SLIM_CONFIG_USE_SIMPLIFIED_CHINESE 
slim_int CharSet_GuessSimplifiedChinese(void *in_p, slim_int in_len, slim_bool in_eod, slim_int *out_score);
slim_int CharSet_ConvertSimplifiedChinese(void *out_p, slim_split_ss *inout_ss, slim_int in_charset_out, slim_int in_charset_in);
slim_int (slim_i18n_checkch_zh_gb2312)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
slim_int (slim_i18n_checkch_zh_gbk)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
slim_int (slim_i18n_checkch_zh_gb18030)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
void slim_i18n_getch_zh_gb2312(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void slim_i18n_getch_zh_gbk(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void slim_i18n_getch_zh_gb18030(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
#endif /* SLIM_CONFIG_USE_SIMPLIFIED_CHINESE */
#ifdef SLIM_CONFIG_USE_TRADITIONAL_CHINESE
slim_int CharSet_GuessTraditionalChinese(void *in_p, slim_int in_len, slim_bool in_eod, slim_int *out_score);
slim_int CharSet_ConvertTraditionalChinese(void *out_p, slim_split_ss *inout_ss, slim_int in_charset_out, slim_int in_charset_in);
slim_int (slim_i18n_checkch_zh_big5)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
void slim_i18n_getch_zh_big5(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
#endif /* SLIM_CONFIG_USE_TRADITIONAL_CHINESE */

/* slim_i18n_cyrillic.c */

#ifdef SLIM_CONFIG_USE_CYRILLIC
slim_int (slim_i18n_checkch_la_iso8859_5)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
slim_int (slim_i18n_checkch_la_windows_1251)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
slim_int (slim_i18n_checkch_ru_koi8r)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
void (slim_i18n_getch_la_iso8859_5)(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void (slim_i18n_getch_la_windows_1251)(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void (slim_i18n_getch_ru_koi8r)(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void slim_i18n_convch_la_ucs2_to_iso8859_5(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_la_ucs2_to_windows1251(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_ru_ucs2_to_koi8r(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_la_iso8859_5_to_windows1251(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_la_iso8859_5_to_koi8_r(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_la_windows1251_to_iso8859_5(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_la_windows1251_to_koi8_r(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_ru_koi8_r_to_iso8859_5(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_ru_koi8_r_to_windows1251(TI18NChar *in_char, TI18NChar *out_char);
slim_int CharSet_GuessCyrillic(void *in_p, slim_int in_len, slim_bool in_eod, slim_int *out_score);
slim_int CharSet_ConvertCyrillic(void* out_p, slim_split_ss *inout_ss, slim_int in_to_charset, slim_int in_from_charset);
#endif /* SLIM_CONFIG_USE_CYRILLIC */

/* slim_i18n_greek.c */

#ifdef SLIM_CONFIG_USE_GREEK
slim_int (slim_i18n_checkch_el_iso8859_7)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
slim_int (slim_i18n_checkch_el_windows_1253)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
void (slim_i18n_getch_el_iso8859_7)(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void (slim_i18n_getch_el_windows_1253)(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void slim_i18n_convch_el_ucs2_to_iso8859_7(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_el_ucs2_to_windows1253(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_el_iso8859_7_to_windows1253(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_el_windows1253_to_iso8859_7(TI18NChar *in_char, TI18NChar *out_char);
slim_int CharSet_GuessGreek(void *in_p, slim_int in_len, slim_bool in_eod, slim_int *out_score);
slim_int CharSet_ConvertGreek(void* out_p, slim_split_ss *inout_ss, slim_int in_to_charset, slim_int in_from_charset);
#endif /* SLIM_CONFIG_USE_GREEK */

/* slim_i18n_hebrew.c */

#ifdef SLIM_CONFIG_USE_HEBREW
slim_int (slim_i18n_checkch_he_iso8859_8)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
slim_int (slim_i18n_checkch_he_windows_1255)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
void (slim_i18n_getch_he_iso8859_8)(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void (slim_i18n_getch_he_windows_1255)(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void slim_i18n_convch_he_ucs2_to_iso8859_8(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_he_ucs2_to_windows1255(TI18NChar *in_char, TI18NChar *out_char);
slim_int CharSet_GuessHebrew(void *in_p, slim_int in_len, slim_bool in_eod, slim_int *out_score);
slim_int CharSet_ConvertHebrew(void* out_p, slim_split_ss *inout_ss, slim_int in_to_charset, slim_int in_from_charset);
#endif /* SLIM_CONFIG_USE_HEBREW */

/* slim_i18n_isctype.c */


/* slim_i18n_japanese.c */

#ifdef SLIM_CONFIG_USE_JAPANESE
slim_int CharSet_GuessJapanese(void *in_p, slim_int in_len, slim_bool in_eod, slim_int *out_score);
slim_int TI18NString_Japanese_Convert(TI18NString *self, slim_int *out_read_len, slim_byte *out_buf, slim_int in_dest_charset);
slim_int CharSet_ConvertJapanese(void* out_p, slim_split_ss *inout_ss, slim_int in_to_charset, slim_int in_from_charset);
slim_int Charset_CheckJapaneseKinsoku(slim_char *in_s, slim_int in_len);
void slim_i18n_convch_ja_sjis_zenkaku_to_hankaku(TI18NChar *in_char, TI18NChar *out_char);
slim_int CharSet_ConvertJapanese_ZenkakuToHankaku(void *out_p, slim_split_ss *inout_ss, slim_int in_charset);
void TI18NChar_Japanese_ToLowerOrUpper(TI18NChar *inout_ch, slim_bool in_upper);
void slim_i18n_convch_ja_jis7_to_sjis(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_ja_euc_to_sjis(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_ja_sjis_to_euc(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_ja_jis7_to_euc(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_ja_sjis_to_jis7(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_ja_euc_to_jis7(TI18NChar *in_char, TI18NChar *out_char);
slim_int (slim_i18n_checkch_ja_shift_jis)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
slim_int (slim_i18n_checkch_ja_euc)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
void slim_i18n_getch_ja_shift_jis(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void slim_i18n_getch_ja_euc(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void slim_i18n_getch_ja_jis7(slim_byte *in_str, slim_int in_len, TI18NChar *out_char, TISO2022Ctx *inout_ctx);
#endif /* SLIM_CONFIG_USE_JAPANESE */

/* slim_i18n_korean.c */

#ifdef SLIM_CONFIG_USE_KOREAN
slim_int (slim_i18n_checkch_ko_euc_kr)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
slim_int (slim_i18n_checkch_ko_uhc)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
void (slim_i18n_getch_ko_euc_kr)(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void (slim_i18n_getch_ko_uhc)(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
slim_int CharSet_GuessKorean(void *in_p, slim_int in_len, slim_bool in_eod, slim_int *out_score);
slim_int CharSet_ConvertKorean(void *out_p, slim_split_ss *inout_ss, slim_int in_to_charset, slim_int in_from_charset);
#endif /* SLIM_CONFIG_USE_KOREAN */

/* slim_i18n_nordic.c */

#ifdef SLIM_CONFIG_USE_NORDIC
slim_int (slim_i18n_checkch_la_iso8859_10)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
void (slim_i18n_getch_la_iso8859_10)(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void slim_i18n_convch_la_ucs2_to_iso8859_10(TI18NChar *in_char, TI18NChar *out_char);
slim_int CharSet_GuessNordic(void *in_p, slim_int in_len, slim_bool in_eod, slim_int *out_score);
slim_int CharSet_ConvertNordic(void* out_p, slim_split_ss *inout_ss, slim_int in_to_charset, slim_int in_from_charset);
#endif /* SLIM_CONFIG_USE_NORDIC */

/* slim_i18n_south_european.c */

#ifdef SLIM_CONFIG_USE_SOUTH_EUROPEAN
slim_int (slim_i18n_checkch_la_iso8859_3)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
void (slim_i18n_getch_la_iso8859_3)(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void slim_i18n_convch_la_ucs2_to_iso8859_3(TI18NChar *in_char, TI18NChar *out_char);
slim_int CharSet_GuessSouthEuropean(void *in_p, slim_int in_len, slim_bool in_eod, slim_int *out_score);
slim_int CharSet_ConvertSouthEuropean(void* out_p, slim_split_ss *inout_ss, slim_int in_to_charset, slim_int in_from_charset);
#endif /* SLIM_CONFIG_USE_SOUTH_EUROPEAN */

/* slim_i18n_split.c */

slim_int CharSet_Splxxx_CharOrIChar(slim_split_ss *inout_ss, slim_int in_c, slim_int in_charset, slim_int in_xxx, slim_bool in_ignore_case);
slim_int CharSet_Splxxx_StrOrIStr(slim_split_ss *inout_ss, slim_char *in_p, slim_int in_charset, slim_int in_xxx, slim_bool in_ignore_case);
slim_int CharSet_Spl_Chars(slim_split_ss *inout_ss, slim_int in_chars, slim_int in_charset);
slim_bool slim_i18n_splxxx_char_or_ichar(slim_split_ss *inout_ss, slim_int in_charset, slim_char *in_char, slim_int in_len, slim_int in_char_charset, slim_int *out_chars, slim_int in_flag);
slim_bool slim_i18n_splxxx_str_or_istr(slim_split_ss *inout_ss, slim_int in_charset, slim_char *in_str, slim_int in_len, slim_int in_str_charset, slim_int *out_chars, slim_int in_flag);
slim_bool slim_i18n_splxxx_delim_or_span_chars_or_ctype(slim_split_ss *inout_ss, slim_int in_charset, slim_char *in_chars, slim_int in_len, slim_int in_chars_charset, slim_i18n_ctype_proc in_proc, slim_int *out_chars, slim_int in_flag);
slim_bool slim_i18n_splxxx_delim_or_span_ctype(slim_split_ss *inout_ss, slim_int in_charset, slim_i18n_ctype_proc in_proc, slim_int *out_chars, slim_int in_flag);

/* slim_i18n_thai.c */

#ifdef SLIM_CONFIG_USE_THAI
slim_int (slim_i18n_checkch_th_windows_874)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
void (slim_i18n_getch_th_windows_874)(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void slim_i18n_convch_th_ucs2_to_windows874(TI18NChar *in_char, TI18NChar *out_char);
slim_int CharSet_GuessThai(void *in_p, slim_int in_len, slim_bool in_eod, slim_int *out_score);
slim_int CharSet_ConvertThai(void *out_p, slim_split_ss *inout_ss, slim_int in_charset_out, slim_int in_charset_in);
#endif /* SLIM_CONFIG_USE_THAI */

/* slim_i18n_turkish.c */

#ifdef SLIM_CONFIG_USE_TURKISH
slim_int (slim_i18n_checkch_tr_iso8859_9)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
slim_int (slim_i18n_checkch_tr_windows_1254)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
void (slim_i18n_getch_tr_iso8859_9)(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void (slim_i18n_getch_tr_windows_1254)(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void slim_i18n_convch_tr_ucs2_to_iso8859_9(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_tr_ucs2_to_windows1254(TI18NChar *in_char, TI18NChar *out_char);
slim_int CharSet_GuessTurkish(void *in_p, slim_int in_len, slim_bool in_eod, slim_int *out_score);
slim_int CharSet_ConvertTurkish(void* out_p, slim_split_ss *inout_ss, slim_int in_to_charset, slim_int in_from_charset);
#endif /* SLIM_CONFIG_USE_TURKISH */

/* slim_i18n_unicode.c */

slim_int CharSet_GuessUniversal(void *in_p, slim_int in_len, slim_bool in_eod, slim_int *out_score);
slim_bool TI18NChar_ConvertFromUCSPUA(TI18NChar *inout_char, slim_int in_to_chset);
slim_bool TI18NChar_ConvertToUCSPUA(TI18NChar *inout_char);
slim_int CharSet_ConvertUniversal(void* out_p, slim_split_ss *inout_ss, slim_int in_to_charset, slim_int in_from_charset);
void slim_i18n_convch_ucs_ucs4_to_utf8(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_ucs_utf8_to_ucs4(TI18NChar *in_char, TI18NChar *out_char, slim_bool in_bigendian);
void slim_i18n_convch_ucs_utf8_to_ucs2be(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_ucs_ucs2_to_utf8(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_ucs_utf16_to_ucs4(TI18NChar *in_char, TI18NChar *out_char, slim_bool in_bigendian);
void slim_i18n_convch_ucs_ucs4_to_utf16(TI18NChar *in_char, TI18NChar *out_char, slim_bool in_bigendian);
void slim_i18n_convch_ucs_utf16_to_ucs2be(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_ucs_ucs2_to_utf16be(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_ucs_ucs2_to_utf16le(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_ucs_ucs2_to_ucs4(TI18NChar *in_char, TI18NChar *out_char, slim_bool in_bigendian);
void slim_i18n_convch_ucs_ucs4_to_ucs2(TI18NChar *in_char, TI18NChar *out_char, slim_bool in_bigendian);
void (slim_i18n_convch_ucs_ucs2_to_ucs2be)(TI18NChar *in_char, TI18NChar *out_char);
void (slim_i18n_convch_ucs_ucs2_to_ucs2le)(TI18NChar *in_char, TI18NChar *out_char);
void (slim_i18n_convch_ucs_ucs2_to_ucs4be)(TI18NChar *in_char, TI18NChar *out_char);
void (slim_i18n_convch_ucs_ucs2_to_ucs4le)(TI18NChar *in_char, TI18NChar *out_char);
void (slim_i18n_convch_ucs_ucs4_to_ucs2be)(TI18NChar *in_char, TI18NChar *out_char);
void (slim_i18n_convch_ucs_ucs4_to_ucs2le)(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_ucs_iso8859_1_to_ucs2(TI18NChar *in_char, TI18NChar *out_char, slim_bool in_bigendian);
void slim_i18n_convch_ucs_iso8859_15_to_ucs2(TI18NChar *in_char, TI18NChar *out_char, slim_bool in_bigendian);
void slim_i18n_convch_ucs_windows1252_to_ucs2(TI18NChar *in_char, TI18NChar *out_char, slim_bool in_bigendian);
void (slim_i18n_convch_ucs_iso8859_1_to_ucs2be)(TI18NChar *in_char, TI18NChar *out_char);
void (slim_i18n_convch_ucs_iso8859_15_to_ucs2be)(TI18NChar *in_char, TI18NChar *out_char);
void (slim_i18n_convch_ucs_windows1252_to_ucs2be)(TI18NChar *in_char, TI18NChar *out_char);
#ifdef SLIM_CONFIG_USE_BALTIC
void slim_i18n_convch_ucs_iso8859_4_to_ucs2(TI18NChar *in_char, TI18NChar *out_char, slim_bool in_bigendian);
void slim_i18n_convch_ucs_windows1257_to_ucs2(TI18NChar *in_char, TI18NChar *out_char, slim_bool in_bigendian);
void (slim_i18n_convch_ucs_iso8859_4_to_ucs2be)(TI18NChar *in_char, TI18NChar *out_char);
void (slim_i18n_convch_ucs_windows1257_to_ucs2be)(TI18NChar *in_char, TI18NChar *out_char);
#endif /* SLIM_CONFIG_USE_BALTIC */
#ifdef SLIM_CONFIG_USE_CENTRAL_EUROPEAN
void slim_i18n_convch_ucs_iso8859_2_to_ucs2(TI18NChar *in_char, TI18NChar *out_char, slim_bool in_bigendian);
void slim_i18n_convch_ucs_windows1250_to_ucs2(TI18NChar *in_char, TI18NChar *out_char, slim_bool in_bigendian);
void (slim_i18n_convch_ucs_iso8859_2_to_ucs2be)(TI18NChar *in_char, TI18NChar *out_char);
void (slim_i18n_convch_ucs_windows1250_to_ucs2be)(TI18NChar *in_char, TI18NChar *out_char);
#endif /* SLIM_CONFIG_USE_CENTRAL_EUROPEAN */
#ifdef SLIM_CONFIG_USE_CYRILLIC
void slim_i18n_convch_ucs_iso8859_5_to_ucs2(TI18NChar *in_char, TI18NChar *out_char, slim_bool in_bigendian);
void slim_i18n_convch_ucs_windows1251_to_ucs2(TI18NChar *in_char, TI18NChar *out_char, slim_bool in_bigendian);
void slim_i18n_convch_ucs_koi8_r_to_ucs2(TI18NChar *in_char, TI18NChar *out_char, slim_bool in_bigendian);
void (slim_i18n_convch_ucs_iso8859_5_to_ucs2be)(TI18NChar *in_char, TI18NChar *out_char);
void (slim_i18n_convch_ucs_windows1251_to_ucs2be)(TI18NChar *in_char, TI18NChar *out_char);
void (slim_i18n_convch_ucs_koi8_r_to_ucs2be)(TI18NChar *in_char, TI18NChar *out_char);
#endif /* SLIM_CONFIG_USE_CYRILLIC */
#ifdef SLIM_CONFIG_USE_GREEK
void slim_i18n_convch_ucs_iso8859_7_to_ucs2(TI18NChar *in_char, TI18NChar *out_char, slim_bool in_bigendian);
void slim_i18n_convch_ucs_windows1253_to_ucs2(TI18NChar *in_char, TI18NChar *out_char, slim_bool in_bigendian);
void (slim_i18n_convch_ucs_iso8859_7_to_ucs2be)(TI18NChar *in_char, TI18NChar *out_char);
void (slim_i18n_convch_ucs_windows1253_to_ucs2be)(TI18NChar *in_char, TI18NChar *out_char);
#endif /* SLIM_CONFIG_USE_GREEK */
#ifdef SLIM_CONFIG_USE_NORDIC
void slim_i18n_convch_ucs_iso8859_10_to_ucs2(TI18NChar *in_char, TI18NChar *out_char, slim_bool in_bigendian);
void (slim_i18n_convch_ucs_iso8859_10_to_ucs2be)(TI18NChar *in_char, TI18NChar *out_char);
#endif /* SLIM_CONFIG_USE_NORDIC */
#ifdef SLIM_CONFIG_USE_SOUTH_EUROPEAN
void slim_i18n_convch_ucs_iso8859_3_to_ucs2(TI18NChar *in_char, TI18NChar *out_char, slim_bool in_bigendian);
void (slim_i18n_convch_ucs_iso8859_3_to_ucs2be)(TI18NChar *in_char, TI18NChar *out_char);
#endif /* SLIM_CONFIG_USE_SOUTH_EUROPEAN */
#ifdef SLIM_CONFIG_USE_THAI
void slim_i18n_convch_ucs_windows874_to_ucs2(TI18NChar *in_char, TI18NChar *out_char, slim_bool in_bigendian);
void (slim_i18n_convch_ucs_windows874_to_ucs2be)(TI18NChar *in_char, TI18NChar *out_char);
#endif	/*  SLIM_CONFIG_USE_THAI */
#ifdef SLIM_CONFIG_USE_TURKISH
void slim_i18n_convch_ucs_iso8859_9_to_ucs2(TI18NChar *in_char, TI18NChar *out_char, slim_bool in_bigendian);
void slim_i18n_convch_ucs_windows1254_to_ucs2(TI18NChar *in_char, TI18NChar *out_char, slim_bool in_bigendian);
void (slim_i18n_convch_ucs_iso8859_9_to_ucs2be)(TI18NChar *in_char, TI18NChar *out_char);
void (slim_i18n_convch_ucs_windows1254_to_ucs2be)(TI18NChar *in_char, TI18NChar *out_char);
#endif /* SLIM_CONFIG_USE_TURKISH */
#ifdef SLIM_CONFIG_USE_ARABIC
void slim_i18n_convch_ucs_iso8859_6_to_ucs2(TI18NChar *in_char, TI18NChar *out_char, slim_bool in_bigendian);
void slim_i18n_convch_ucs_windows1256_to_ucs2(TI18NChar *in_char, TI18NChar *out_char, slim_bool in_bigendian);
void (slim_i18n_convch_ucs_iso8859_6_to_ucs2be)(TI18NChar *in_char, TI18NChar *out_char);
void (slim_i18n_convch_ucs_windows1256_to_ucs2be)(TI18NChar *in_char, TI18NChar *out_char);
#endif /* SLIM_CONFIG_USE_ARABIC */
#ifdef SLIM_CONFIG_USE_HEBREW
void slim_i18n_convch_ucs_iso8859_8_to_ucs2(TI18NChar *in_char, TI18NChar *out_char, slim_bool in_bigendian);
void slim_i18n_convch_ucs_windows1255_to_ucs2(TI18NChar *in_char, TI18NChar *out_char, slim_bool in_bigendian);
void (slim_i18n_convch_ucs_iso8859_8_to_ucs2be)(TI18NChar *in_char, TI18NChar *out_char);
void (slim_i18n_convch_ucs_windows1255_to_ucs2be)(TI18NChar *in_char, TI18NChar *out_char);
#endif /* SLIM_CONFIG_USE_HEBREW */
slim_int slim_i18n_checkch_ucs_utf8(slim_byte *in_str, slim_int in_len, slim_int *out_type);
slim_int slim_i18n_checkch_ucs_utf16be(slim_byte *in_str, slim_int in_len, slim_int *out_type);
slim_int slim_i18n_checkch_ucs_utf16le(slim_byte *in_str, slim_int in_len, slim_int *out_type);
slim_int slim_i18n_checkch_ucs_ucs4be(slim_byte *in_str, slim_int in_len, slim_int *out_type);
slim_int slim_i18n_checkch_ucs_ucs4le(slim_byte *in_str, slim_int in_len, slim_int *out_type);
slim_int slim_i18n_checkch_ucs_ucs2be(slim_byte *in_str, slim_int in_len, slim_int *out_type);
slim_int slim_i18n_checkch_ucs_ucs2le(slim_byte *in_str, slim_int in_len, slim_int *out_type);
void slim_i18n_getch_ucs_utf8(slim_byte *in_s, slim_int in_len, TI18NChar *out_char);
void slim_i18n_getch_ucs_ucs2be(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void slim_i18n_getch_ucs_ucs2le(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void slim_i18n_getch_ucs_utf16be(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void slim_i18n_getch_ucs_utf16le(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void slim_i18n_getch_ucs_ucs4be(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void slim_i18n_getch_ucs_ucs4le(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);

/* slim_i18n_western.c */

slim_int (slim_i18n_checkch_en_us_ascii)(slim_byte *in_s, slim_int in_len, slim_int *out_type);
slim_int slim_i18n_checkch_la_iso8859_x(slim_byte *in_str, slim_int in_len, slim_int *out_type);
slim_int (slim_i18n_checkch_la_iso8859_1)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
slim_int (slim_i18n_checkch_la_iso8859_15)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
slim_int (slim_i18n_checkch_la_windows_1252)(slim_byte *in_str, slim_int in_len, slim_int *out_type);
void slim_i18n_getch_en_us_ascii(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void slim_i18n_getch_la_iso8859_X(slim_byte *in_str, slim_int in_len, TI18NChar *out_char, slim_int in_chset);
void (slim_i18n_getch_la_iso8859_1)(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void (slim_i18n_getch_la_iso8859_15)(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void (slim_i18n_getch_la_windows_1252)(slim_byte *in_str, slim_int in_len, TI18NChar *out_char);
void slim_i18n_convch_en_ucs2_to_us_ascii(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_la_ucs2_to_iso8859_1(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_la_ucs2_to_iso8859_15(TI18NChar *in_char, TI18NChar *out_char);
void slim_i18n_convch_la_ucs2_to_windows1252(TI18NChar *in_char, TI18NChar *out_char);
slim_int CharSet_GuessWestern(void *in_p, slim_int in_len, slim_bool in_eod, slim_int *out_score);
slim_int CharSet_ConvertWestern(void* out_p, slim_split_ss *inout_ss, slim_int in_to_charset, slim_int in_from_charset);

/* slim_token_chset_aux0.c */


/* slim_token_lngset_aux0.c */


/* slim_bignum.c */

void TBignum_Initialize(TBignum *self, slim_word *in_buf, slim_word in_len);
void TBignum_Finalize(TBignum *self);
TBignum * TBignum_Malloc(slim_word in_max_len);
TBignum * TBignum_Clone(TBignum *self);
void TBignum_Free(TBignum *self);
#ifdef SLIM_CONFIG_BIGNUM_USE_MODTABLE
slim_int TBignum_CreateModTable(TBignum *in_mod);
void TBignum_DestroyModTable(TBignum *in_mod);
slim_bool TBignum_Optimize(TBignum *in_mod, TBignum *in_p);
#endif /* SLIM_CONFIG_BIGNUM_USE_MODTABLE */
slim_word TBignum_Bits(TBignum *self);
slim_bool TBignum_FromByteArray(TBignum *self, slim_byte *in_buf, slim_word in_len);
slim_bool TBignum_ToByteArray(TBignum *self, slim_byte *out_buf, slim_word in_len);
TBignum * TBignum_Cpy(TBignum *self, TBignum *in_src);
slim_int TBignum_AbsCmp(TBignum *in_b1, TBignum *in_b2);
slim_int TBignum_Cmp(TBignum *in_b1, TBignum *in_b2);
slim_int TBignum_CmpQ(TBignum *in_bn, slim_word in_val);
void TBignum_Normalize(TBignum *iself, slim_word in_len);
slim_word TBignum_NumFromNthBit(TBignum *self, slim_word in_off, slim_int in_len);
#ifdef SLIM_CONFIG_BIGNUM_DEBUG
void TBignum_DebugDump(TBignum *iself, slim_char *prefix, slim_char *suffix);
#endif /* SLIM_CONFIG_BIGNUM_DEBUG */

/* slim_bignum_64.c */

#ifndef SLIM_CONFIG_BIGNUM_USE_WORD64
slim_int slim_bignum_add64(slim_word *out_result_hi32, slim_word *out_result_lo32, slim_word in_num1_hi32, slim_word in_num1_lo32, slim_word in_num2_hi32, slim_word in_num2_lo32);
slim_int slim_bignum_sub64(slim_word *out_result_hi32, slim_word *out_result_lo32, slim_word in_num1_hi32, slim_word in_num1_lo32, slim_word in_num2_hi32, slim_word in_num2_lo32);
#ifdef SLIM_CONFIG_MORECOMPACT
void slim_bignum_mul64(slim_word *out_result_hi32, slim_word *out_result_lo32, slim_word in_num1, slim_word in_num2);
void slim_bignum_square64(slim_word *out_result_hi32, slim_word *out_result_lo32, slim_word in_num);
void slim_bignum_divmod64(slim_word *out_quotient_hi32, slim_word *out_quotient_lo32, slim_word *out_remainder, slim_word in_dividend_hi32, slim_word in_dividend_lo32, slim_word in_divisor);
void slim_bignum_divmod64_no_quotient_hi(slim_word *out_quotient_lo32, slim_word *out_remainder, slim_word in_dividend_hi32, slim_word in_dividend_lo32, slim_word in_divisor);
slim_word slim_bignum_mod64(slim_word in_dividend_hi32, slim_word in_dividend_lo32, slim_word in_divisor);
#else
void slim_bignum_mul64(slim_word *out_result_hi32, slim_word *out_result_lo32, slim_word in_num1, slim_word in_num2);
void slim_bignum_square64(slim_word *out_result_hi32, slim_word *out_result_lo32, slim_word in_num);
void slim_bignum_divmod64(slim_word *out_quotient_hi32, slim_word *out_quotient_lo32, slim_word *out_remainder, slim_word in_dividend_hi32, slim_word in_dividend_lo32, slim_word in_divisor);
void slim_bignum_divmod64_no_quotient_hi(slim_word *out_quotient_lo32, slim_word *out_remainder, slim_word in_dividend_hi32, slim_word in_dividend_lo32, slim_word in_divisor);
slim_word slim_bignum_mod64(slim_word in_dividend_hi32, slim_word in_dividend_lo32, slim_word in_divisor);
#endif /* SLIM_CONFIG_MORECOMPACT */
#endif /* SLIM_CONFIG_BIGNUM_USE_WORD64 */

/* slim_bignum_64_x.c */

#ifndef SLIM_CONFIG_BIGNUM_USE_WORD64
slim_int slim_bignum_cmp64(slim_word in_num1_hi32, slim_word in_num1_lo32, slim_word in_num2_hi32, slim_word in_num2_lo32);
void slim_bignum_add64_no_carry_out(slim_word *out_result_hi32, slim_word *out_result_lo32, slim_word in_num1_hi32, slim_word in_num1_lo32, slim_word in_num2_hi32, slim_word in_num2_lo32);
void slim_bignum_sub64_no_borrow_out(slim_word *out_result_hi32, slim_word *out_result_lo32, slim_word in_num1_hi32, slim_word in_num1_lo32, slim_word in_num2_hi32, slim_word in_num2_lo32);
#endif /* SLIM_CONFIG_BIGNUM_USE_WORD64 */

/* slim_bignum_addsub.c */

void TBignum_Add3(TBignum *self, TBignum *in_b1, TBignum *in_b2);
void TBignum_Sub3(TBignum *self, TBignum *in_b1, TBignum *in_b2);
slim_int TBignum_Sub3Mod(TBignum *self, TBignum *in_b1, TBignum *in_b2, TBignum *in_mod);
void TBignum_AddQ(TBignum *self, slim_word in_val);
void TBignum_SubQ(TBignum *self, slim_word in_val);

/* slim_bignum_divmod.c */

slim_int TBignum_DivMod(TBignum *out_q, TBignum *out_r, TBignum *in_bn, TBignum *in_mod);
slim_int TBignum_Div(TBignum *out_q, TBignum *in_bn, TBignum *in_mod);
slim_int TBignum_Mod(TBignum *out_r, TBignum *in_bn, TBignum *in_mod);
#ifdef SLIM_CONFIG_BIGNUM_USE_MODTABLE
slim_int TBignum_ModByTable(TBignum *out_r, TBignum *in_bn, TBignum *in_mod);
#endif /* SLIM_CONFIG_BIGNUM_USE_MODTABLE */
slim_int TBignum_DivModQ(TBignum *out_q, slim_word *out_r, TBignum *in_bn, slim_word in_mod);
slim_int TBignum_ModQ(slim_word *out_r, TBignum *in_bn, slim_word in_mod);
slim_int TBignum_MulMod(TBignum *out_r, TBignum *in_bn1, TBignum *in_bn2, TBignum *in_mod);
void TBignum_ModP2(TBignum *inout_bn, slim_word in_p2);

/* slim_bignum_divmod_x.c */

slim_int TBignum_DivQ(TBignum *out_q, TBignum *in_bn, slim_word in_mod);
slim_int TBignum_GCD(TBignum *out_gcd, TBignum *in_bn1, TBignum *in_bn2);
slim_int TBignum_InvMod(TBignum *out_inv, TBignum *in_bn, TBignum *in_mod);

/* slim_bignum_expmod.c */

slim_int TBignum_ExpMod(TBignum *out_r, TBignum *in_b, TBignum *in_p, TBignum *in_mod);

/* slim_bignum_expmod_x.c */

void TBignum_Exp(TBignum *out_bn, TBignum *in_bn, TBignum *in_p);

/* slim_bignum_mulshift.c */

void TBignum_Mul(TBignum *out_b, TBignum *in_b1, TBignum *in_b2);
slim_int TBignum_MulKO(TBignum *out_b, TBignum *in_b1, TBignum *in_b2);
void TBignum_MulQ(TBignum *out_bn, TBignum *in_b, slim_word in_val);
void TBignum_Square(TBignum *out_b, TBignum *in_b);
void TBignum_LShift2(TBignum *out_bn, TBignum *in_b, slim_word in_offset);
void TBignum_RShift2(TBignum *out_bn, TBignum *in_b, slim_word in_offset);
void TBignum_LShiftWord2(TBignum *out_bn, TBignum *in_b, slim_word in_offset);
void TBignum_RShiftWord2(TBignum *out_bn, TBignum *in_b, slim_word in_offset);

/* slim_bignum_x.c */

slim_int TBignum_StrToBignum(slim_char *in_str, TBignum *out_bn);
slim_int TBignum_BignumToStr(TBignum *in_bn, slim_word in_len, slim_char *out_str);
slim_int TBignum_IsPrime(TBignum *in_bn, slim_int in_i);
slim_int TBignum_IsReltvPrime(TBignum *in_bn1, TBignum *in_bn2);
slim_int TBignum_GeneratePrime(TBignum *in_bn);
void TBignum_GenerateRandom(TBignum *in_bn, slim_word in_len);

/* slim_memory.c */

#ifdef SLIM_CONFIG_MEMORY_STANDARD
#ifdef SLIM_CONFIG_MEMORY_DEBUG
slim_word slim_std_memory_block_from(void *in_addr);
void slim_std_memory_block_set_from(void *in_addr, slim_word in_from);
#endif
#ifdef SLIM_CONFIG_POINTER_MEMNODE
void * slim_std_memory_heap_base(void);
#endif
void * slim_std_memory_sparealloc(slim_int in_size, slim_int in_spare_blocks);
slim_handle slim_std_handle_sparealloc(slim_int in_size, slim_int in_spare_blocks);
slim_vhandle slim_std_vhandle_sparealloc(slim_int in_size, slim_int in_spare_blocks);
void slim_std_memory_heap_static_info(TMemoryHeapStaticInfo *out_info);
void slim_std_memory_heap_dynamic_info(TMemoryHeapDynamicInfo *out_info);
void slim_std_memory_get_free_size(slim_int *out_total, slim_int *out_longest);
#ifdef SLIM_CONFIG_MEMORY_DEBUG
slim_char * slim_memory_debug_from_name(slim_word in_from, slim_int *out_len);
slim_char * slim_std_memory_debug_from_name(slim_word in_from);
#endif
#ifdef SLIM_CONFIG_DEBUG
void slim_std_memory_debug_dump(slim_bool in_showfrag);
void slim_std_memory_debug_dump_string(slim_bool in_showfrag);
#endif
#ifdef SLIM_CONFIG_MEMORY_DEBUG
slim_word slim_std_memory_debug_from(void *in_addr);
slim_bool slim_std_memory_debug_from_equal(slim_word in_from, slim_int in_from_element);
void slim_std_memory_debug_set_random_alloc_failure_proc(Slim_MemoryRandomAllocFailureProc in_proc);
slim_bool slim_std_memory_debug_is_alloc_failure(void);
void slim_std_memory_debugout_statistics(void);
#endif
#if defined(SLIM_CONFIG_MULTITHREAD) || defined(SLIM_CONFIG_MEMORY_PROTECT_DEBUG)
slim_int slim_std_handle_peek_int(slim_handle in_handle, slim_int in_offset);
slim_short slim_std_handle_peek_short(slim_handle in_handle, slim_int in_offset);
slim_pix slim_std_handle_peek_pix(slim_handle in_handle, slim_int in_offset);
slim_handle slim_std_handle_peek_handle(slim_handle in_handle, slim_int in_offset);
slim_vhandle slim_std_handle_peek_vhandle(slim_handle in_handle, slim_int in_offset);
void * slim_std_handle_peek_ptr(slim_handle in_handle, slim_int in_offset);
slim_opaque slim_std_handle_peek_opaque(slim_handle in_handle, slim_int in_offset);
slim_int slim_std_vhandle_peek_int(slim_vhandle in_vhandle, slim_int in_offset);
slim_short slim_std_vhandle_peek_short(slim_vhandle in_vhandle, slim_int in_offset);
slim_pix slim_std_vhandle_peek_pix(slim_vhandle in_vhandle, slim_int in_offset);
slim_handle slim_std_vhandle_peek_handle(slim_vhandle in_vhandle, slim_int in_offset);
slim_vhandle slim_std_vhandle_peek_vhandle(slim_vhandle in_vhandle, slim_int in_offset);
void * slim_std_vhandle_peek_ptr(slim_vhandle in_vhandle, slim_int in_offset);
slim_opaque slim_std_vhandle_peek_opaque(slim_vhandle in_vhandle, slim_int in_offset);
#endif
#else
void slim_memory_file_is_empty(void);
#endif

/* slim_memory_alt.c */

#ifdef SLIM_CONFIG_MEMORY_ALTERNATIVE
#ifdef SLIM_CONFIG_MEMORY_DEBUG_ALTERNATIVE
void slim_alt_memory_debug_get_free_size(slim_int *out_total, slim_int *dummy);
void slim_alt_memory_debug_notify( slim_int in_code, void *in_addr1, void *in_addr2, slim_int in_sz1, slim_int in_sz2, slim_word in_from);
#else
#endif
#ifdef SLIM_CONFIG_USE_FLAT_VHANDLEPTR
#ifdef SLIM_CONFIG_MEMORY_DEBUG_ALTERNATIVE
void slim_alt_vhandle_debug_get_stat(slim_int *out_count, slim_int *out_max, slim_int *out_fail);
#else
#endif
#else
#endif
slim_handle slim_alt_handle_valloc(slim_int in_size);
slim_handle slim_alt_handle_vzeroalloc(slim_int in_size);
void slim_alt_handle_vfree(slim_handle in_handle);
#endif

/* slim_memory_node.c */

#ifdef SLIM_CONFIG_MEMORY_STANDARD
#ifdef SLIM_CONFIG_MEMNODE_DEBUG
void StdMemNode_DebugSetNotifyProc(StdMemNode_AllocFreeDebugNotifyProc in_proc);
#endif
slim_bool TStdMemNode_Initialize(TStdMemNode *self);
void TStdMemNode_Finalize(TStdMemNode *self);
void * TStdMemNode_Lock(TStdMemNode *self, slim_int in_offset, slim_handle *out_locked_handle);
void * TStdMemNode_Locate(TStdMemNode *self, slim_int in_offset);
#ifdef SLIM_CONFIG_MEMNODE_DEBUG
void * TStdMemNode_LocateX(TStdMemNode *self, slim_int in_offset);
#endif
slim_handle TStdMemNode_ZeroAlloc(TStdMemNode *self, slim_int in_offset);
void TStdMemNode_Free(TStdMemNode *self, slim_int in_offset);
void TStdMemNode_FreeAll(TStdMemNode *self);
#else
void slim_memory_node_file_is_empty(void);
#endif

/* slim_memory_node_alt.c */

#ifdef SLIM_CONFIG_MEMORY_ALTERNATIVE
slim_bool TAltMemNode_Initialize(TAltMemNode *self);
void TAltMemNode_Finalize(TAltMemNode *self);
slim_handle TAltMemNode_ZeroAlloc(TAltMemNode *self, slim_int in_offset);
void TAltMemNode_FreeAll(TAltMemNode *self);
void TAltMemNode_Free(TAltMemNode *self, slim_iaddr_word in_offset);
slim_handle TAltMemNode_GetPageHandle(TAltMemNode *self, slim_iaddr_word in_offset);
#ifdef SLIM_CONFIG_MEMNODE_DEBUG
slim_bool TAltMemNode_IsValidPix(TAltMemNode *self, slim_iaddr_word in_offset);
#endif /* SLIM_CONFIG_MEMNODE_DEBUG */
#endif /* SLIM_CONFIG_MEMORY_ALTERNATIVE */

/* slim_memory_node_ptr.c */

#ifdef SLIM_CONFIG_POINTER_MEMNODE
#ifdef SLIM_CONFIG_PTRMEMNODE_DEBUG
void PtrMemNode_DebugSetNotifyProc(PtrMemNode_AllocFreeDebugNotifyProc in_proc);
#endif
slim_bool TPtrMemNode_Initialize(TPtrMemNode *self);
void TPtrMemNode_Finalize(TPtrMemNode *self);
void * TPtrMemNode_Lock(TPtrMemNode *self, slim_int in_offset, slim_handle *out_locked_handle);
void * TPtrMemNode_Locate(TPtrMemNode *self, slim_int in_offset);
#ifdef SLIM_CONFIG_PTRMEMNODE_DEBUG
void * TPtrMemNode_LocateX(TPtrMemNode *self, slim_int in_offset);
#endif
void * TPtrMemNode_ZeroAlloc(TPtrMemNode *self, slim_int in_offset);
void TPtrMemNode_Free(TPtrMemNode *self, slim_int in_offset);
void TPtrMemNode_FreeAll(TPtrMemNode *self);
#endif /* SLIM_CONFIG_POINTER_MEMNODE */

/* slim_memory_protect.c */

void * slim_memory_protect_alloc(slim_int in_len);
void slim_memory_protect_free(void *in_ptr);
void slim_memory_protect_block(void *in_addr, slim_int in_len, slim_bool in_can_readwrite);

/* slim_cdataformatter.c */

slim_int TCDATAFormatter_ConvertUnicode(TCDATAFormatter *self, slim_char *out_buf, slim_int in_code, slim_int in_to_chset, slim_int in_mode);
slim_bool TCDATAFormatter_ParseReference(TCDATAFormatter *self, slim_char *in_s, slim_int in_len, slim_bool in_has_semicolon, slim_int *out_code, slim_int in_mode);
slim_int TCDATAFormatter_ResolveReference(TCDATAFormatter *self, slim_char *out_buf, slim_char *in_s, slim_int in_len, slim_bool in_has_semicolon, slim_int in_to_chset, slim_int in_mode);
slim_int TCDATAFormatter_Format(TCDATAFormatter *self, slim_char *out_buf, slim_char *in_s, slim_int in_len, slim_int in_to_charset, slim_int in_from_charset, slim_int in_mode);
void TCDATAFormatter_Init(TCDATAFormatter *self, TCDATAFormatterClass *in_class, slim_opaque in_userdata);
void TCDATAFormatter_Tidy(TCDATAFormatter *self);
void CDATAFormatter_Initialize(TCDATAFormatterClass *in_class, TI18NConverterClass *in_conv_class);
void CDATAFormatter_Finalize(TCDATAFormatterClass *in_class);

/* slim_reader.c */

void TReaderInput_Expand(TReaderInput *self, slim_char *in_str, slim_int in_len, slim_bool in_EOF);
void TReaderInput_InitializeWithBuffer(TReaderInput *self, TIOBuffer *in_buf, slim_int in_encoding, slim_bool in_EOF);
void TReaderInput_Initialize(TReaderInput *self, slim_char *in_str, slim_int in_len, slim_int in_encoding, slim_bool in_EOF);
void TReaderInput_Finalize(TReaderInput *self);
void TxxToken_Tidy(TxxToken *self);
TxxToken * TTokenizer_CurrentToken(TTokenizer *self);
slim_int TTokenizer_Read(TTokenizer *self, TReaderInput *in_input);
void TTokenizer_ResetToken(TTokenizer *self, slim_int in_charset);
slim_bool TTokenizer_Init(TTokenizer *self, TTokenizerClass *in_class);
void TTokenizer_Tidy(TTokenizer *self);
void Tokenizer_Initialize(TTokenizerClass *in_class, slim_int in_objsize, Tokenizer_CurrentTokenProc in_currenttoken, Tokenizer_ReadProc in_read, Tokenizer_ResetTokenProc in_reset, Tokenizer_InitProc in_init, Tokenizer_TidyProc in_tidy);
void Tokenizer_Finalize(TTokenizerClass *in_class);
TTokenizer * Tokenizer_New(TTokenizerClass *in_class);
void TTokenizer_Delete(TTokenizer *self);
slim_bool Tokenizer_SplitQuotedText(slim_split_ss *inout_ss);
slim_int TTokenHandler_HandleToken(TTokenHandler *self, TxxToken *in_token, slim_opaque in_user_data);
void TTokenHandler_Initialize(TTokenHandler *self, TTokenHandlerClass *in_class);
void TTokenHandler_Tidy(TTokenHandler *self);
void TokenHandler_Initialize(TTokenHandlerClass *in_class, TokenHandler_HandleTokenProc in_handletoken);
void TokenHandler_Finalize(TTokenHandlerClass *in_class);
slim_int TReader_Parse(TReader *self, TReaderInput *inout_input, slim_int in_max_stay);
void TReader_Initialize(TReader *self, TTokenizer *in_tokenizer, TTokenHandler *in_handler, slim_opaque in_userdata);
void TReader_Tidy(TReader *self);
slim_bool TWriterBuffer_Initialize(TWriterBuffer *self, slim_int in_threshold);
void TWriterBuffer_Finalize(TWriterBuffer *self);
slim_int TWriterOutput_WriteFromBuffer(TWriterOutput *self, TWriterBuffer *in_buf);
slim_bool TWriterOutput_Initialize(TWriterOutput *self, slim_opaque in_userdata, WriterOutput_WriteProc in_write);
void TWriterOutput_Finalize(TWriterOutput *self);
slim_bool TTokenGenerator_Initialize(TTokenGenerator *self, slim_opaque in_userdata, TokenGenerator_GenerateProc in_generate, TokenGenerator_LockUnlockTokenProc in_lockunlock);
void TTokenGenerator_Finalize(TTokenGenerator *self);
slim_bool TTokenFormatter_Init(TTokenFormatter *self, TTokenFormatterClass *in_class);
void TTokenFormatter_DefaultTidy(TTokenFormatter *self);
void TTokenFormatter_Tidy(TTokenFormatter *self);
slim_bool TokenFormatter_Initialize(TTokenFormatterClass *in_class, TokenFormatter_FormatProc in_format, TokenFormatter_TidyProc in_tidy);
void TokenFormatter_Finalize(TTokenFormatterClass *in_class);
slim_int TWriter_Write(TWriter *self, TWriterOutput *in_output, slim_int in_max_stay);
slim_bool TWriter_Initialize(TWriter *self, TTokenGenerator *in_generator, TTokenFormatter *in_formatter);
void TWriter_Finalize(TWriter *self);
slim_int slim_offlen_compare(slim_offlen *self, slim_offlen *in_competitor);
void TParallelTokenizer_RemoveTokenizer(TParallelTokenizer *self, slim_int in_token_id);
slim_bool TParallelTokenizer_AddTokenizer(TParallelTokenizer *self, slim_int in_token_id, TTokenizerClass *in_tknz_cls, slim_int in_priority);
slim_int TParallelTokenizer_GetTokenPriority(TParallelTokenizer *self, slim_int in_token_id);
void TParallelTokenizer_SetTokenPriority(TParallelTokenizer *self, slim_int in_token_id, slim_int in_priority);
slim_int TParallelTokenizer_Read(TTokenizer *base, TReaderInput *in_input);
slim_bool TParallelTokenizer_Init(TTokenizer *base, TTokenizerClass *in_baseclass);
void TParallelTokenizer_Tidy(TTokenizer *base);
void ParallelTokenizer_Initialize(TParallelTokenizerClass *in_class, slim_int in_token_id);
void ParallelTokenizer_Finalize(TParallelTokenizerClass *in_class);

/* slim_tokenizer_inetmsg.c */

slim_int InetMsgTokenizer_SplitRFCx822FWS(slim_split_ss *inout_ss, slim_bool in_eof, slim_int in_flag);
slim_int InetMsgTokenizer_SplitRFCx822CFWS(slim_split_ss *inout_ss, slim_bool in_eof, slim_int in_flag);
slim_int InetMsgTokenizer_SplitRFCx822Unstructured(slim_split_ss *inout_ss, slim_bool in_eof, slim_int in_flag);
slim_int InetMsgTokenizer_SplitRFCx822BasicToken(slim_split_ss *inout_ss, slim_bool in_eof, slim_int in_flag, slim_int in_which);
slim_int InetMsgTokenizer_SplitRFCx822DottedToken(slim_split_ss *inout_ss, slim_bool in_eof, slim_int in_flag, slim_int in_token_flag);
slim_int InetMsgTokenizer_SplitRFCx822Mailbox(slim_split_ss *inout_ss, slim_bool in_eof, slim_int in_flag);
slim_int InetMsgTokenizer_SplitRFCx822MailboxList(slim_split_ss *inout_ss, slim_bool in_eof, slim_int in_flag);
slim_int InetMsgTokenizer_SplitRFCx822Field(slim_split_ss *inout_ss, slim_bool in_eof, slim_int in_flag);
slim_int InetMsgTokenizer_SplitMIMEParameter(slim_split_ss *inout_ss, slim_bool in_eof, slim_int in_flag);
TFixedString TInetMsgTknzBStack_Nth(TInetMsgTknzBStack *self, slim_int in_nth);
slim_bool TInetMsgTokenizer_FindBoundary(TInetMsgTokenizer *self, slim_split_ss *inout_ss, slim_split_ss *out_boundary);
slim_int TInetMsgTokenizer_CurrentBoundaryDepth(TInetMsgTokenizer *self);
slim_bool TInetMsgTokenizer_PushBoundary(TInetMsgTokenizer *self, slim_char *in_s, slim_int in_len);
void TInetMsgTokenizer_SetNoMsgHeader(TInetMsgTokenizer *self);
void InetMsgTokenizer_Initialize(TInetMsgTokenizerClass *in_class);
void InetMsgTokenizer_Finalize(TInetMsgTokenizerClass *in_class);
slim_bool TInetMsgFormatter_Init(TInetMsgFormatter *self, TInetMsgFormatterClass *in_class);
slim_bool InetMsgFormatter_Initialize(TInetMsgFormatterClass *in_class);
void InetMsgFormatter_Finalize(TInetMsgFormatterClass *in_class);

/* slim_tokenizer_ptext.c */

slim_bool PTextTokenizer_CTypeIsNonASCIIOrWhite(TI18NChar *in_ch);
void PTextURLTokenizer_Initialize(TPTextURLTokenizerClass *in_class);
void PTextURLTokenizer_Finalize(TPTextURLTokenizerClass *in_class);
slim_int PTextTelTokenizer_ToASCII(TI18NChar *in_ch);
slim_bool PTextTelTokenizer_CtypeIsTelNum_ASCII(slim_int in_c);
slim_bool PTextTelTokenizer_CtypeIsTelNum_AllowZenkaku(TI18NChar *in_ch);
slim_bool PTextTelTokenizer_CtypeIsTelDelim_ASCII(slim_int in_c);
slim_bool PTextTelTokenizer_CtypeIsTelDelim_AllowZenkaku(TI18NChar *in_ch);
slim_bool PTextTelTokenizer_CtypeIsTel1st_ASCII(slim_int in_c);
slim_bool PTextTelTokenizer_CtypeIsTel1st_AllowZenkaku(TI18NChar *in_ch);
slim_bool PTextTelTokenizer_CtypeIsNotTel_ASCII(slim_int in_c);
slim_bool PTextTelTokenizer_CtypeIsNotTel_AllowZenkaku(TI18NChar *in_ch);
slim_bool PTextTelTokenizer_CtypeIsColon_AllowZenkaku(TI18NChar *in_ch);
slim_bool PTextTelTokenizer_AddAllowedScheme(TPTextTelTokenizerClass *in_class, slim_char *in_scheme);
void PTextTelTokenizer_Initialize(TPTextTelTokenizerClass *in_class);
void PTextTelTokenizer_Finalize(TPTextTelTokenizerClass *in_class);
void PTextMailTokenizer_Initialize(TPTextMailTokenizerClass *in_class);
void PTextMailTokenizer_Finalize(TPTextMailTokenizerClass *in_class);
#ifdef SLIM_CONFIG_USE_MEDIA_SCHEME
void PTextMediaTokenizer_Initialize(TPTextMediaTokenizerClass *in_class);
void PTextMediaTokenizer_Finalize(TPTextMediaTokenizerClass *in_class);
#endif /* SLIM_CONFIG_USE_MEDIA_SCHEME */
slim_bool PTextTokenizer_AddTokenizerClass(TPTextTokenizerClass *in_class, slim_int in_token_type, TTokenizerClass *in_tknz_class, slim_int in_priority);
slim_bool PTextTokenizer_Initialize(TPTextTokenizerClass *in_class);
void PTextTokenizer_Finalize(TPTextTokenizerClass *in_class);

/* slim_tokenizer_xxml.c */

void TxxMLToken_Tidy(TxxMLToken *self);
slim_bool xxMLTokenizer_SplitAfterEq(slim_split_ss *inout_ss);
slim_int xxMLTokenizer_TokenizeAsText(slim_char *in_s, slim_int in_len, slim_bool in_eof, slim_int in_flag, TxxMLToken *out_token, slim_int *out_flag, slim_int *out_err);
slim_int xxMLTokenizer_TokenizeAsReference(slim_char *in_s, slim_int in_len, slim_bool in_eof, slim_int in_flag, TxxMLToken *out_token, slim_int *out_flag, slim_int *out_err);
slim_int xxMLTokenizer_SplitAttribute(slim_split_ss *inout_ss, slim_bool in_eof, slim_int in_flag, slim_int *out_flag, slim_int *out_err);
slim_int xxMLTokenizer_TokenizeAsElementTag(slim_char *in_s, slim_int in_len, slim_bool in_eof, slim_int in_flag, TxxMLToken *out_token, slim_int *out_flag, slim_int *out_err);
slim_int xxMLTokenizer_TokenizeAsPI(slim_char *in_s, slim_int in_len, slim_bool in_eof, slim_int in_flag, TxxMLToken *out_token, slim_int *out_flag, slim_int *out_err);
slim_int xxMLTokenizer_TokenizeAsUnknownTag(slim_char *in_s, slim_int in_len, slim_bool in_eof, slim_int in_flag, TxxMLToken *out_token, slim_int *out_flag, slim_int *out_err);
slim_int xxMLTokenizer_TokenizeAsComment(slim_char *in_s, slim_int in_len, slim_bool in_eof, slim_int in_flag, TxxMLToken *out_token, slim_int *out_flag, slim_int *out_err);
slim_int xxMLTokenizer_TokenizeAsDTD(slim_char *in_s, slim_int in_len, slim_bool in_eof, slim_int in_flag, TxxMLToken *out_token, slim_int *out_flag, slim_int *out_err);
slim_int xxMLTokenizer_TokenizeAsCDSect(slim_char *in_s, slim_int in_len, slim_bool in_eof, slim_int in_flag, TxxMLToken *out_token, slim_int *out_flag, slim_int *out_err);
slim_int TxxMLTokenizer_PeekNextToken(TxxMLTokenizer *self, TReaderInput *in_input, TxxMLToken *out_token);
void xxMLTokenizer_Initialize(TxxMLTokenizerClass *in_class);
void xxMLTokenizer_Finalize(TxxMLTokenizerClass *in_class);
slim_bool xxMLTokenizer_ParseReference(slim_char *in_s, slim_int in_len, slim_int *out_code);
slim_int xxMLTokenizer_ConvertUnicodeChar(slim_char *out_buf, slim_int in_code, slim_int in_to_charset);
void HTMLTokenizer_Initialize(THTMLTokenizerClass *in_class);
void HTMLTokenizer_Finalize(THTMLTokenizerClass *in_class);
slim_bool XMLTokenizer_ParseXMLDecl(slim_char *in_str, slim_int in_len, slim_int in_charset, slim_split_ss *out_version, slim_split_ss *out_encoding, slim_bool *out_standalone);

/* slim_regexp.c */

void TRegExpRoot_SetFlag(TRegExpClass *in_class, slim_pix self, slim_int in_flag);
slim_int TRegExpRoot_ParenCount(TRegExpClass *in_class, slim_pix self);
slim_int TRegExpRoot_Flag(TRegExpClass *in_class, slim_pix self);
slim_bool TRegExp_Preview(TRegExpClass *in_class, TRegExp self, slim_char *in_s, slim_int in_l, slim_int in_charset);
slim_bool RegExp_Initialize(TRegExpClass *in_class);
void RegExp_Finalize(TRegExpClass *in_class);
TRegExp RegExp_NewSS(TRegExpClass *in_class, slim_char *in_s, slim_int in_l, slim_int in_charset, slim_int in_last_char, slim_char **out_s, slim_int *out_l, slim_int *out_err);
slim_int RegExp_ParseFlag(slim_char *in_s, slim_int in_l, slim_char **out_s, slim_int *out_l);
void TRegExp_Delete(TRegExpClass *in_class, TRegExp self);
slim_int TRegExp_MatchAt(TRegExpClass *in_class, TRegExp self, slim_char *in_s, slim_int in_l, slim_int in_index, slim_int in_charset, TRegExpResult *inout_result);
slim_int RegExp_Inc(slim_char *in_s, slim_int in_l, slim_int in_i, slim_int in_charset);
slim_int RegExp_CharsToIndex(slim_char *in_s, slim_int in_l, slim_int in_chars, slim_int in_charset);
slim_int TRegExp_MatchExec(TRegExpClass *in_class, TRegExp self, slim_char *in_s, slim_int in_l, slim_int *inout_i, slim_int in_charset, TRegExpResult *inout_result);
slim_bool TRegExpResult_Initialize(TRegExpResult *self, TRegExpClass *in_class, TRegExp in_reg_exp);
void TRegExpResult_Finalize(TRegExpResult *self);
void TRegExp_DebugPrint(TRegExpClass *in_class, TRegExp self);

/* slim_fixed_string.c */

#ifndef SLIM_CONFIG_FIXEDSTRING_REPLACE_STRING
void FixedString_Initialize(void);
void FixedString_Finalize(void);
slim_int TFixedString_Use(TFixedString self, slim_int in_count);
slim_int TFixedString_Hash(TFixedString self);
slim_bool TFixedString_EqualTS(TFixedString self, TString in_s);
slim_bool TFixedString_EqualSS(TFixedString self, slim_char *in_s, slim_int in_len);
slim_bool TFixedString_IEqualSS(TFixedString self, slim_char *in_s, slim_int in_len);
slim_bool TFixedString_IEqualFS(TFixedString self, TFixedString in_fs);
slim_bool TFixedString_IsWhite(TFixedString in_str);
#ifdef SLIM_CONFIG_DEBUG
void FixedString_DebugDump(void);
void TFixedString_DebugDump(TFixedString self, slim_bool in_linebreak);
#endif
#else
slim_bool TFixedString_EqualSS(TFixedString self, slim_char *in_s, slim_int in_len);
#endif

/* slim_string.c */

slim_bool TString_FormatReserve(TString self, TStringFormatCookie *inout_cookie, slim_int in_len);
TString TString_SetCS(TString self, slim_char *in_cs);
TString TString_SetSS(TString self, slim_char *in_s, slim_int in_len);
TString TString_SetTS(TString self, TString in_ts);
slim_bool TString_IsWhite(TString in_str);
slim_int TString_Hash(TString self);
slim_bool TString_EqualCS(TString self, slim_char *in_s);
slim_bool TString_EqualSS(TString self, slim_char *in_s, slim_int in_len);
slim_bool TString_EqualTS(TString self, TString in_string);
slim_bool TString_IEqualCS(TString self, slim_char *in_s);
slim_bool TString_IEqualSS(TString self, slim_char *in_s, slim_int in_len);
slim_bool TString_IEqualTS(TString self, TString in_string);
slim_int TString_Splice(TString self, slim_int in_pos, slim_int in_len);
slim_bool TString_AppendCS(TString self, slim_char *in_s);
slim_bool TString_AppendSS(TString self, slim_char *in_s, slim_int in_len);
slim_bool TString_AppendTS(TString self, TString in_s);
slim_bool TString_AppendFS(TString self, TFixedString in_s);
slim_bool TString_InsertSS(TString self, slim_int in_offset, slim_char *in_s, slim_int in_len);
slim_int TString_Remove(TString self, slim_int in_c);
void TString_StartFormat(TString self, TStringFormatCookie *out_cookie);
slim_int TString_EndFormat(TString self, TStringFormatCookie *in_cookie);
slim_bool TString_FormatObject(TString self, TStringFormatCookie *inout_cookie, slim_string_formatter in_formatter, slim_opaque in_obj);
slim_bool TString_FormatInt(TString self, TStringFormatCookie *inout_cookie, slim_int in_n);
slim_bool TString_FormatChar(TString self, TStringFormatCookie *inout_cookie, slim_int in_c);
slim_bool TString_FormatWChar(TString self, TStringFormatCookie *inout_cookie, slim_int in_c, slim_int in_charset);
slim_bool TString_FormatSS(TString self, TStringFormatCookie *inout_cookie, slim_char *in_s, slim_int in_len);
slim_bool TString_FormatCS(TString self, TStringFormatCookie *inout_cookie, slim_char *in_s);
slim_bool TString_FormatTS(TString self, TStringFormatCookie *inout_cookie, TString in_s);
slim_bool TString_FormatFS(TString self, TStringFormatCookie *inout_cookie, TFixedString in_s);
slim_bool TString_FormatSqueezedSS(TString self, TStringFormatCookie *inout_cookie, slim_char *in_s, slim_int in_len, slim_bool in_zap);
slim_bool TString_FormatConvertedSS(TString self, TStringFormatCookie *inout_cookie, slim_char *in_s, slim_int in_len, slim_int in_to_charset, slim_int in_from_charset, slim_int *out_len);
TString String_NewArchCharsetSS(slim_char *in_s, slim_int in_len, slim_int in_charset, slim_int *out_charset);
slim_bool TString_FormatIntX(TString self, TStringFormatCookie *inout_cookie, slim_word in_n, slim_int in_radix, slim_char in_padding, slim_int in_min_width, slim_bool in_upper);
slim_bool TString_FormatEscapeSS(TString self, TStringFormatCookie *inout_cookie, slim_char *in_s, slim_int in_len, slim_bool in_upper);
slim_bool TString_FormatEscapeTS(TString self, TStringFormatCookie *inout_cookie, TString in_str, slim_bool in_upper);
slim_bool TString_FormatUnescapeSS(TString self, TStringFormatCookie *inout_cookie, slim_char *in_s, slim_int in_len);
slim_bool TString_FormatUnescapeTS(TString self, TStringFormatCookie *inout_cookie, TString in_str);
slim_bool TString_FormatPctEncodeSS(TString self, TStringFormatCookie *inout_cookie, slim_char *in_s, slim_int in_len, slim_bool in_upper);
slim_bool TString_FormatPctEncodeTS(TString self, TStringFormatCookie *inout_cookie, TString in_str, slim_bool in_upper);
slim_bool TString_FormatPctDecodeSS(TString self, TStringFormatCookie *inout_cookie, slim_char *in_s, slim_int in_len);
slim_bool TString_FormatPctDecodeTS(TString self, TStringFormatCookie *inout_cookie, TString in_str);
slim_bool TString_FormatBinary(TString self, TStringFormatCookie *inout_cookie, slim_byte *in_bin, slim_int in_len, slim_bool in_upper);

/* mem_resolve.c */

slim_bool slim_memory_init_global_variables(void);
void slim_memory_tidy_global_variables(void);

/* slim_memory_replay.c */

#ifdef SLIM_TANK_REPLAY
slim_bool slim_replay_record_open(slim_char *in_recording_filename);
void slim_replay_record_close(void);
void slim_replay_record_write(slim_int in_replay_code, void *in_addr, slim_int in_size, slim_int in_optional, void *in_reallocated_addr);
slim_bool slim_replay_play_line(slim_char *in_play_line);
void * slim_replay_memory_sparealloc(slim_int in_size, slim_int in_spare_blocks);
slim_handle slim_replay_handle_sparealloc(slim_int in_size, slim_int in_spare_blocks);
slim_vhandle slim_replay_vhandle_sparealloc(slim_int in_size, slim_int in_spare_blocks);
#endif /* defined(SLIM_TANK_REPLAY) */

/* slim_memory_tank.c */
#ifndef SLIM_CONFIG_MEMORY_ALTERNATIVE
#ifdef SLIM_CONFIG_MEMORY_DEBUG
slim_word TTank_block_from(TTank *self, void *in_addr);
#endif /* defined(SLIM_CONFIG_MEMORY_DEBUG) */
#ifdef SLIM_CONFIG_MEMORY_DEBUG
slim_word slim_tank_memory_block_from(void *in_addr);
#endif /* defined(SLIM_CONFIG_MEMORY_DEBUG) */
#ifdef SLIM_CONFIG_MEMORY_DEBUG
void TTank_block_set_from(TTank *self, void *in_addr, slim_word in_from);
#endif /* defined(SLIM_CONFIG_MEMORY_DEBUG) */
#ifdef SLIM_CONFIG_MEMORY_DEBUG
void slim_tank_memory_block_set_from(void *in_addr, slim_word in_from);
#endif /* defined(SLIM_CONFIG_MEMORY_DEBUG) */
void * slim_tank_memory_sparealloc(slim_int in_size, slim_int in_spare_blocks);
slim_handle slim_tank_handle_sparealloc(slim_int in_size, slim_int in_spare_blocks);
slim_vhandle slim_tank_vhandle_sparealloc(slim_int in_size, slim_int in_spare_blocks);
void slim_tank_memory_get_free_size(slim_int *out_total_bytes, slim_int *out_longest_blocks);
#ifdef SLIM_CONFIG_MEMORY_DEBUG
slim_char * slim_tank_memory_debug_from_name(slim_word in_from, slim_int *out_len);
#endif /* defined(SLIM_CONFIG_MEMORY_DEBUG) */
#ifdef SLIM_CONFIG_MEMORY_DEBUG
slim_char * slim_tank_memory_debug_from_name_array(slim_word in_from);
#endif /* defined(SLIM_CONFIG_MEMORY_DEBUG) */
#ifdef SLIM_CONFIG_DEBUG
void slim_tank_memory_debug_dump(slim_bool in_showfrag);
#endif /* defined(SLIM_CONFIG_DEBUG) */
#ifdef SLIM_CONFIG_DEBUG
void slim_tank_memory_debug_dump_string(slim_bool in_showfrag);
#endif /* defined(SLIM_CONFIG_DEBUG) */
#ifdef SLIM_CONFIG_MEMORY_DEBUG
void * slim_tank_memory_debug_memory_to_tank(void *in_addr);
void * slim_tank_memory_debug_next_tank(void *in_tank);
slim_bool slim_tank_memory_debug_get_tanknum(void *in_tank, slim_int *out_tanknum, slim_int *out_alltanknum);
slim_word slim_tank_memory_debug_from(void *in_addr);
slim_bool slim_tank_memory_debug_from_equal(slim_word in_from, slim_int in_from_element);
void slim_tank_memory_debug_set_random_alloc_failure_proc(Slim_MemoryRandomAllocFailureProc in_proc);
slim_bool slim_tank_memory_debug_is_alloc_failure(void);
void slim_tank_memory_debugout_statistics(void);
#endif /* defined(SLIM_CONFIG_MEMORY_DEBUG) */
#if defined(SLIM_CONFIG_MULTITHREAD) || defined(SLIM_CONFIG_MEMORY_PROTECT_DEBUG)
slim_int slim_tank_handle_peek_int(slim_handle in_handle, slim_int in_offset);
slim_short slim_tank_handle_peek_short(slim_handle in_handle, slim_int in_offset);
slim_pix slim_tank_handle_peek_pix(slim_handle in_handle, slim_int in_offset);
slim_handle slim_tank_handle_peek_handle(slim_handle in_handle, slim_int in_offset);
slim_vhandle slim_tank_handle_peek_vhandle(slim_handle in_handle, slim_int in_offset);
void * slim_tank_handle_peek_ptr(slim_handle in_handle, slim_int in_offset);
slim_opaque slim_tank_handle_peek_opaque(slim_handle in_handle, slim_int in_offset);
slim_int slim_tank_vhandle_peek_int(slim_vhandle in_vhandle, slim_int in_offset);
slim_short slim_tank_vhandle_peek_short(slim_vhandle in_vhandle, slim_int in_offset);
slim_pix slim_tank_vhandle_peek_pix(slim_vhandle in_vhandle, slim_int in_offset);
slim_handle slim_tank_vhandle_peek_handle(slim_vhandle in_vhandle, slim_int in_offset);
slim_vhandle slim_tank_vhandle_peek_vhandle(slim_vhandle in_vhandle, slim_int in_offset);
void * slim_tank_vhandle_peek_ptr(slim_vhandle in_vhandle, slim_int in_offset);
slim_opaque slim_tank_vhandle_peek_opaque(slim_vhandle in_vhandle, slim_int in_offset);
#endif /* defined(SLIM_CONFIG_MULTITHREAD) || defined(SLIM_CONFIG_MEMORY_PROTECT_DEBUG) */

/* slim_memory_tank_node.c */

#ifdef SLIM_CONFIG_MEMNODE_DEBUG
void TankMemNode_DebugSetNotifyProc(TankMemNode_AllocFreeDebugNotifyProc in_proc);
#endif /* defined(SLIM_CONFIG_MEMNODE_DEBUG) */
slim_bool TTankMemNode_Initialize(TTankMemNode *self);
void TTankMemNode_Finalize(TTankMemNode *self);
void * TTankMemNode_Lock(TTankMemNode *self, slim_int in_offset, slim_handle *out_locked_handle);
void * TTankMemNode_Locate(TTankMemNode *self, slim_int in_offset);
#ifdef SLIM_CONFIG_MEMNODE_DEBUG
void * TTankMemNode_LocateX(TTankMemNode *self, slim_int in_offset);
#endif /* defined(SLIM_CONFIG_MEMNODE_DEBUG) */
slim_handle TTankMemNode_ZeroAlloc(TTankMemNode *self, slim_int in_offset);
void TTankMemNode_Free(TTankMemNode *self, slim_int in_offset);
void TTankMemNode_FreeAll(TTankMemNode *self);
#endif /* !SLIM_CONFIG_MEMORY_ALTERNATIVE */

/* slim_memory_tank_node_ptr.c */

#ifdef SLIM_CONFIG_POINTER_MEMNODE
#ifdef SLIM_CONFIG_PTRMEMNODE_DEBUG
void PtrMemNode_DebugSetNotifyProc(PtrMemNode_AllocFreeDebugNotifyProc in_proc);
#endif /* defined(SLIM_CONFIG_PTRMEMNODE_DEBUG) */
slim_bool TPtrMemNode_Initialize(TPtrMemNode *self);
void TPtrMemNode_Finalize(TPtrMemNode *self);
void * TPtrMemNode_Lock(TPtrMemNode *self, slim_int in_offset, slim_handle *out_locked_handle);
void * TPtrMemNode_Locate(TPtrMemNode *self, slim_int in_offset);
#ifdef SLIM_CONFIG_PTRMEMNODE_DEBUG
void * TPtrMemNode_LocateX(TPtrMemNode *self, slim_int in_offset);
#endif /* defined(SLIM_CONFIG_PTRMEMNODE_DEBUG) */
void * TPtrMemNode_ZeroAlloc(TPtrMemNode *self, slim_int in_offset);
void TPtrMemNode_Free(TPtrMemNode *self, slim_int in_offset);
void TPtrMemNode_FreeAll(TPtrMemNode *self);
#endif /* defined(SLIM_CONFIG_POINTER_MEMNODE) */

/* slim_memory_test.c */

#ifdef SLIM_CONFIG_MEMORY_DEBUG
#ifndef SLIM_TANK_TEST
slim_int slim_tank_memory_test(slim_int in_testnum);
#else /* defined(SLIM_TANK_TEST) */
slim_int slim_tank_memory_test(slim_int in_testnum);
#endif /* defined(SLIM_TANK_TEST) */
#endif /* defined(SLIM_CONFIG_MEMORY_DEBUG) */

/* slim_memory_verify.c */

#ifdef SLIM_TANK_VERIFY
void Tank_VerifyPrint(slim_char *in_s);
slim_bool TTank_VerifyTankShallow(TTank *self);
slim_bool Tank_VerifyHandleShallow(slim_handle in_handle);
slim_bool TTank_VerifyMPtrBlk(TTank *self);
slim_bool TTank_VerifyMemBlock(TTank *self, TMemBlock *in_mp);
slim_bool TTank_VerifyHeapMap(TTank *self);
slim_bool TTank_Verify(TTank *self);
slim_bool Tank_VerifyHandle(slim_handle in_handle);
slim_bool TTank_VerifyAddress(TTank *self, void *in_addr);
slim_bool TTank_VerifyBlockNumber(TTank *self, slim_int in_block);
slim_bool slim_tank_verify_all(void);
#endif /* defined(SLIM_TANK_VERIFY) */

/* slim_token.c */

void * TTokenDict_FindSS(TTokenDict *self, slim_char *in_name, slim_byte *in_table, slim_short *in_table_index, slim_char *in_s, slim_int in_slen);
void * TTokenDict_FindSS_CaseX(TTokenDict *self, slim_char *in_name, slim_byte *in_table, slim_short *in_table_index, slim_char *in_s, slim_int in_slen);
void * TTokenDict_CaseFindSS(TTokenDict *self, slim_char *in_name, slim_byte *in_table, slim_short *in_table_index, slim_char *in_s, slim_int in_slen);

/* slim_resolve.c */

slim_bool slim_init_global_variables(void);
void slim_tidy_global_variables(void);

/* slim_util.c */

slim_int slim_read_multibyteinteger(slim_byte *in_buf, slim_int in_buf_len, slim_int *out_integer);
slim_int slim_generic_seek(slim_int in_head, slim_int in_tail, slim_int *inout_cur_off, slim_int in_off, slim_int in_whence);
slim_int TIOBuffer_ReadSeek(TIOBuffer *self, slim_int in_off, slim_int in_whence);
slim_int TIOBuffer_WriteSeek(TIOBuffer *self, slim_int in_off, slim_int in_whence);
slim_bool TIOBuffer_SetBufferX(TIOBuffer *self, slim_byte *in_buf, slim_int in_len, slim_bool in_reset);
void TIOBuffer_Initialize(TIOBuffer *self);
void TIOBuffer_Finalize(TIOBuffer *self);
void TRingBuffer_Consume(TRingBuffer *self);
void TRingBuffer_Initialize(TRingBuffer *self);
void TRingBuffer_Finalize(TRingBuffer *self);
slim_bool TElasticBuf_Ensure(TElasticBuf *self, slim_int in_req_len);
slim_bool TElasticBuf_Initialize(TElasticBuf *self, slim_opaque in_userdata, ElasticBuf_LockUnlockProc in_lockunlock, ElasticBuf_ReallocProc in_realloc, slim_int in_buflen, slim_int in_blocksize);
void TElasticBuf_Finalize(TElasticBuf *self);
slim_bool TElasticBuf_InitWithMemory(TElasticBuf *self, void **in_bufptr, slim_int in_buflen, slim_int in_blocksize);
slim_bool TElasticBuf_InitWithVhandle(TElasticBuf *self, slim_vhandle in_vh, slim_int in_blocksize);
slim_bool TExpandingBuf_Initialize(TExpandingBuf *self, slim_int in_blocksize, slim_int in_type);
void TExpandingBuf_Finalize(TExpandingBuf *self);
slim_bool TVarLenBitFlag_SetClearCheck(TVarLenBitFlag *self, slim_int in_index, slim_int in_which);
void TVarLenBitFlag_Initialize(TVarLenBitFlag *self, slim_byte *in_field, slim_int in_field_bytes);
void TSerializeVersionInfo_Copy(TSerializeVersionInfo *self, TVersionInfo *in_src);
slim_int TSerializeOutput_WriteInt(TSerializeOutput *self, slim_int in_int);
slim_int TSerializeOutput_WriteBool(TSerializeOutput *self, slim_bool in_bool);
slim_int TSerializeOutput_WriteBytes(TSerializeOutput *self, slim_byte *in_data, slim_int in_len);
slim_int TSerializeOutput_WriteSS(TSerializeOutput *self, slim_char *in_str, slim_int in_len, slim_int in_charset);
slim_int TDeserializeInput_ReadInt(TDeserializeInput *self, slim_int *out_int);
slim_int TDeserializeInput_ReadBool(TDeserializeInput *self, slim_bool *out_bool);
slim_int TDeserializeInput_ReadBytes(TDeserializeInput *self, slim_byte **out_data, slim_int *out_len);
slim_int TDeserializeInput_ReadSS(TDeserializeInput *self, slim_char **out_str, slim_int *out_len, slim_int *out_chset);
slim_int TSerializer_Progress(TSerializer *self, slim_int in_max_stay);
void TSerializer_ForceWriteEOF(TSerializer *self);
slim_bool TSerializer_Initialize(TSerializer *self, TSerializable *in_serializable, TSerializeOutput *in_output);
void TSerializer_Finalize(TSerializer *self);
slim_int TDeserializer_Progress(TDeserializer *self, slim_int in_max_stay);
slim_bool TDeserializer_Initialize(TDeserializer *self, TDeserializable *in_deserializable, TDeserializeInput *in_input);
void TDeserializer_Finalize(TDeserializer *self);
void slim_adler32_init(slim_word *out_adler32);
void slim_adler32_calc(slim_word *inout_adler32, slim_byte *in_buf, slim_int in_len);
void TPackedDataWriter_SetCheckPoint(TPackedDataWriter *self);
void TPackedDataWriter_Rollback(TPackedDataWriter *self);
slim_int TPackedDataWriter_NewData(TPackedDataWriter *self, slim_int in_item_flag);
slim_int TPackedDataWriter_Write(TPackedDataWriter *self, slim_byte *in_buf, slim_int in_len);
void TPackedDataWriter_Commit(TPackedDataWriter *self, slim_int in_item_flag);
slim_int TPackedDataWriter_Flush(TPackedDataWriter *self);
slim_int TPackedDataWriter_TotalLength(TPackedDataWriter *self);
slim_bool TPackedDataWriter_Initialize(TPackedDataWriter *self, PackedDataWriter_WriteProc in_proc, slim_opaque in_arg);
void TPackedDataWriter_Finalize(TPackedDataWriter *self);
void TPackedDataWriter_GetSerializeOutput(TPackedDataWriter *self, TSerializeOutput *out_output);
void TPackedDataReader_SetCheckPoint(TPackedDataReader *self);
void TPackedDataReader_Rollback(TPackedDataReader *self);
void TPackedDataReader_Consume(TPackedDataReader *self);
slim_int TPackedDataReader_NextData(TPackedDataReader *self);
slim_int TPackedDataReader_Read(TPackedDataReader *self, slim_byte *out_buf, slim_int in_buf_len, slim_int *out_read_len);
slim_int TPackedDataReader_Refill(TPackedDataReader *self);
slim_int TPackedDataReader_TotalLength(TPackedDataReader *self);
slim_bool TPackedDataReader_Initialize(TPackedDataReader *self, PackedDataReader_ReadProc in_proc, slim_opaque in_arg);
void TPackedDataReader_Finalize(TPackedDataReader *self);
slim_bool PackedDataReader_IsPackedData(void *in_buf, slim_int in_len);
void TPackedDataReader_GetDeserializeInput(TPackedDataReader *self, TDeserializeInput *out_input);
