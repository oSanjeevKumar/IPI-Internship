/*
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* WARNING: DO NOT EDIT! This file is generated automatically. */



/* slim_clib.c */


/* slim_clib_format.c */


/* slim_clib_memxxx.c */


/* slim_clib_numeric.c */


/* slim_clib_rsplit.c */


/* slim_clib_split.c */


/* slim_clib_ss.c */

SLIM_API slim_bool slim_ss_istreq_cs(slim_char *in_s, slim_int in_slen, slim_char *in_t);

/* slim_clib_strtoxxx.c */


/* slim_clib_strxxx.c */


/* slim_clib_time.c */

SLIM_API void slim_time_utcdate(slim_time *in_time, slim_date *out_date);
SLIM_API void slim_time_regiondate(slim_time *in_time, slim_date *out_date);
SLIM_API void slim_time_utctime(slim_date *in_date, slim_time *out_time);
SLIM_API void slim_time_regiontime(slim_date *in_date, slim_time *out_time);
SLIM_API slim_int slim_time_format(slim_char *out_s, slim_int in_maxsize, slim_char *in_format, slim_date *in_date);

/* slim_coll.c */

#ifdef SLIM_CONFIG_DEBUG
SLIM_API void * TObjectIterator_Lock(TObjectIterator *self);
SLIM_API void TObjectIterator_Unlock(TObjectIterator *self);
SLIM_API slim_bool TObjectIterator_Next(TObjectIterator *self);
SLIM_API void TObjectIterator_Finalize(TObjectIterator *self);
#endif /* SLIM_CONFIG_DEBUG */

/* slim_coll_array.c */


/* slim_coll_array_alt.c */


/* slim_coll_bag.c */


/* slim_coll_bag_alt.c */


/* slim_coll_hash.c */


/* slim_coll_linear_array.c */


/* slim_coll_list.c */


/* slim_coll_list_alt.c */


/* slim_coll_tree.c */


/* slim_coll_tree_alt.c */


/* slim_coll_tree_ptr.c */


/* slim_coll_vbag.c */


/* slim_coll_vbag_alt.c */


/* slim_coll_vbag_ptr.c */


/* slim_guibase_color.c */

SLIM_API TColor Color_FromHSV(slim_int in_h, slim_int in_s, slim_int in_v);
SLIM_API void TColor_ToHSV(TColor self, slim_int *out_h, slim_int *out_s, slim_int *out_v);

/* slim_guibase_rect.c */

SLIM_API slim_bool TRect_SetXYWH(TRect *self, slim_int in_x, slim_int in_y, slim_int in_width, slim_int in_height);
SLIM_API slim_bool TRect_SetXYXY(TRect *self, slim_int in_x1, slim_int in_y1, slim_int in_x2, slim_int in_y2);
SLIM_API void TRect_SetRect(TRect *self, TRect *in_r);
SLIM_API void TRect_Swap(TRect *self, TRect *inout_r);
SLIM_API slim_bool TRect_IsEmpty(TRect *self);
SLIM_API slim_bool TRect_IsEqual(TRect *self, TRect *in_r);
SLIM_API slim_bool TRect_IsPointIn(TRect *self, slim_int in_x, slim_int in_y);
SLIM_API slim_bool TRect_IsRectIn(TRect *self, TRect *in_r);
SLIM_API slim_bool TRect_IntersectRect(TRect *self, TRect *in_r, TRect *out_r);
SLIM_API slim_bool TRect_UnionRect(TRect *self, TRect *in_r, TRect *out_r);
SLIM_API slim_int TRect_SubRect(TRect *self, TRect *in_r, TRect *out_r);
SLIM_API void TRect_Offset(TRect *self, slim_int in_dx, slim_int in_dy);
SLIM_API void TRect_Offset0(TRect *self);
SLIM_API slim_bool TRect_Inflate(TRect *self, slim_int in_dx, slim_int in_dy);
SLIM_API slim_bool TRect_Inset(TRect *self, slim_int in_dx, slim_int in_dy);
SLIM_API slim_bool TRect_InsetEdges(TRect *self, slim_int in_dtop, slim_int in_dright, slim_int in_dbottom, slim_int in_dleft);
SLIM_API slim_bool TRect_Resize(TRect *self, slim_int in_width, slim_int in_height, slim_int in_twidth, slim_int in_theight);

/* slim_guibase_region.c */

SLIM_API TRegion Region_New(void);
SLIM_API void TRegion_Delete(TRegion self);
SLIM_API void TRegion_MakeEmpty(TRegion self);
SLIM_API slim_bool TRegion_IsEmpty(TRegion self);
SLIM_API slim_int TRegion_Length(TRegion self);
SLIM_API TRegion TRegion_Duplicate(TRegion self);
SLIM_API void TRegion_Offset(TRegion self, slim_int in_dx, slim_int in_dy);
SLIM_API slim_bool TRegion_AddRect(TRegion self, TRect *in_r);
SLIM_API slim_bool TRegion_SubRect(TRegion self, TRect *in_r);
SLIM_API slim_bool TRegion_IntersectRect(TRegion self, TRect *in_r);
SLIM_API slim_bool TRegion_IntersectRegion(TRegion self, TRegion in_rgn);
SLIM_API slim_bool TRegion_IsIntersectRect(TRegion self, TRect *in_r);
SLIM_API void TRegion_Sort(TRegion self, slim_bool in_horiz);
SLIM_API slim_bool TRegion_BeginVisit(TRegion self, TRegionVisit *out_visit);
SLIM_API void TRegion_EndVisit(TRegion self, TRegionVisit *in_visit);
SLIM_API TRect * TRegion_VisitFirst(TRegion self, TRegionVisit *inout_visit);
SLIM_API TRect * TRegion_VisitLast(TRegion self, TRegionVisit *inout_visit);
SLIM_API TRect * TRegion_VisitNext(TRegion self, TRegionVisit *inout_visit);
SLIM_API TRect * TRegion_VisitPrev(TRegion self, TRegionVisit *inout_visit);

/* slim_i18n.c */

SLIM_API slim_int CharSet_Guess(slim_int in_langset, void *in_s, slim_int in_len, slim_bool in_eof, slim_int *out_score);

/* slim_i18n_arabic.c */


/* slim_i18n_baltic.c */


/* slim_i18n_central_european.c */


/* slim_i18n_chinese.c */


/* slim_i18n_cyrillic.c */


/* slim_i18n_greek.c */


/* slim_i18n_hebrew.c */


/* slim_i18n_isctype.c */


/* slim_i18n_japanese.c */


/* slim_i18n_korean.c */


/* slim_i18n_nordic.c */


/* slim_i18n_south_european.c */


/* slim_i18n_split.c */


/* slim_i18n_thai.c */


/* slim_i18n_turkish.c */


/* slim_i18n_unicode.c */


/* slim_i18n_western.c */


/* slim_token_chset_aux0.c */


/* slim_token_lngset_aux0.c */


/* slim_bignum.c */


/* slim_bignum_64.c */


/* slim_bignum_64_x.c */


/* slim_bignum_addsub.c */


/* slim_bignum_divmod.c */


/* slim_bignum_divmod_x.c */


/* slim_bignum_expmod.c */


/* slim_bignum_expmod_x.c */


/* slim_bignum_mulshift.c */


/* slim_bignum_x.c */


/* slim_memory.c */

#ifdef SLIM_CONFIG_MEMORY_STANDARD
SLIM_API slim_bool slim_std_memory_initialize(void *in_start, slim_int in_len);
SLIM_API slim_bool slim_std_memory_set_new_handler(SLIM_MemoryNewHandlerProc in_callback, slim_opaque in_arg);
SLIM_API slim_bool slim_std_memory_clear_new_handler(SLIM_MemoryNewHandlerProc in_callback, slim_opaque in_arg);
SLIM_API void slim_std_memory_finalize(void);
#ifdef SLIM_CONFIG_MULTITHREAD
SLIM_API void slim_std_memory_set_mutex(slim_opaque in_mutex);
#endif
SLIM_API void * slim_std_memory_alloc(slim_int in_size);
SLIM_API void * slim_std_memory_zeroalloc(slim_int in_size);
SLIM_API void slim_std_memory_free(void *in_memory);
SLIM_API void * slim_std_memory_realloc(void *in_memory, slim_int in_size);
SLIM_API slim_handle slim_std_handle_alloc(slim_int in_size);
SLIM_API slim_handle slim_std_handle_zeroalloc(slim_int in_size);
SLIM_API slim_handle slim_std_handle_calloc(slim_int in_elements, slim_int in_element_size);
SLIM_API void slim_std_handle_free(slim_handle in_handle);
SLIM_API slim_int slim_std_handle_size(slim_handle in_handle);
SLIM_API void * slim_std_handle_lock(slim_handle in_handle);
SLIM_API void slim_std_handle_unlock(slim_handle in_handle);
#ifdef SLIM_CONFIG_MEMORY_DEBUG
SLIM_API void * slim_std_vhandle_locate_d(slim_vhandle in_vhandle);
SLIM_API void slim_std_vhandle_unlocate_d(slim_vhandle in_vhandle);
SLIM_API void * slim_std_handle_locate_d(slim_handle in_handle);
SLIM_API void slim_std_handle_unlocate_d(slim_handle in_handle);
#endif
SLIM_API slim_vhandle slim_std_vhandle_alloc(slim_int in_size);
SLIM_API slim_vhandle slim_std_vhandle_zeroalloc(slim_int in_size);
SLIM_API slim_vhandle slim_std_vhandle_calloc(slim_int in_elements, slim_int in_element_size);
SLIM_API void slim_std_vhandle_free(slim_vhandle in_vhandle);
SLIM_API slim_int slim_std_vhandle_size(slim_vhandle in_vhandle);
SLIM_API void * slim_std_vhandle_lock(slim_vhandle in_vhandle);
SLIM_API void slim_std_vhandle_unlock(slim_vhandle in_vhandle);
SLIM_API slim_bool slim_std_vhandle_realloc(slim_vhandle in_vhandle, slim_int in_size);
SLIM_API void slim_std_memory_disable_compact(slim_bool in_disable);
SLIM_API void slim_std_memory_compact(void);
#ifdef SLIM_CONFIG_MEMORY_DEBUG
SLIM_API void slim_std_memory_debug_set_notify_proc( SLIM_MemoryAllocFreeDebugNotifyProc in_proc );
#endif
#else
#endif

/* slim_memory_alt.c */

#ifdef SLIM_CONFIG_MEMORY_ALTERNATIVE
#ifdef SLIM_CONFIG_MULTITHREAD
SLIM_API void slim_alt_memory_set_mutex(slim_opaque in_mutex);
#endif /* SLIM_CONFIG_MULTITHREAD */
#ifdef SLIM_CONFIG_MEMORY_DEBUG_ALTERNATIVE
SLIM_API void slim_alt_memory_debug_set_notify_proc(SLIM_MemoryAllocFreeDebugNotifyProc in_proc);
#else
#endif
SLIM_API slim_bool slim_alt_memory_initialize(void *in_ptr, slim_int in_len);
SLIM_API void slim_alt_memory_finalize(void);
SLIM_API slim_bool slim_alt_memory_set_new_handler(SLIM_MemoryNewHandlerProc in_callback, slim_opaque in_arg);
SLIM_API slim_bool slim_alt_memory_clear_new_handler(SLIM_MemoryNewHandlerProc in_callback, slim_opaque in_arg);
SLIM_API void * slim_alt_memory_alloc(slim_int in_size);
SLIM_API void * slim_alt_memory_zeroalloc(slim_int in_size);
SLIM_API void slim_alt_memory_free(void *in_memory);
SLIM_API void * slim_alt_memory_realloc(void *in_memory, slim_int in_size);
SLIM_API slim_int slim_alt_handle_size(slim_handle in_handle);
SLIM_API slim_vhandle slim_alt_vhandle_alloc(slim_int in_size);
SLIM_API slim_vhandle slim_alt_vhandle_zeroalloc(slim_int in_size);
SLIM_API void slim_alt_vhandle_free(slim_vhandle in_vhandle);
SLIM_API slim_bool slim_alt_vhandle_realloc(slim_vhandle in_vhandle, slim_int in_size);
SLIM_API slim_int slim_alt_vhandle_size(slim_vhandle in_vhandle);
#endif

/* slim_memory_node.c */


/* slim_memory_node_alt.c */


/* slim_memory_node_ptr.c */


/* slim_memory_protect.c */


/* slim_cdataformatter.c */


/* slim_reader.c */


/* slim_tokenizer_inetmsg.c */


/* slim_tokenizer_ptext.c */


/* slim_tokenizer_xxml.c */

SLIM_API void XMLTokenizer_Initialize(TXMLTokenizerClass *in_class);
SLIM_API void XMLTokenizer_Finalize(TXMLTokenizerClass *in_class);

/* slim_regexp.c */


/* slim_fixed_string.c */

#ifndef SLIM_CONFIG_FIXEDSTRING_REPLACE_STRING
SLIM_API void (TFixedString_Delete)(TFixedString self);
SLIM_API TFixedString FixedString_NewSS(slim_char *in_s, slim_int in_len);
SLIM_API TFixedString FixedString_NewCS(slim_char *in_s);
SLIM_API TFixedString FixedString_NewFS(TFixedString in_fs);
SLIM_API TFixedString FixedString_NewTS(TString in_ts);
SLIM_API slim_int (TFixedString_Length)(TFixedString self);
#else
#endif

/* slim_string.c */

SLIM_API TString String_NewCS(slim_char *in_cstring);
SLIM_API TString String_NewSS(slim_char *in_s, slim_int in_len);
SLIM_API TString String_NewTS(TString in_string);
SLIM_API slim_int TString_Length(TString self);

/* mem_resolve.c */


/* slim_memory_replay.c */

#ifdef SLIM_TANK_REPLAY
SLIM_API slim_bool slim_replay_memory_initialize(void *in_start, slim_int in_len);
SLIM_API void slim_replay_memory_finalize(void);
SLIM_API void slim_replay_memory_compact(void);
SLIM_API void slim_replay_memory_disable_compact(slim_bool in_disable);
SLIM_API void * slim_replay_memory_alloc(slim_int in_size);
SLIM_API void * slim_replay_memory_zeroalloc(slim_int in_size);
SLIM_API void slim_replay_memory_free(void *in_memory);
SLIM_API void * slim_replay_memory_realloc(void *in_memory, slim_int in_size);
SLIM_API slim_handle slim_replay_handle_alloc(slim_int in_size);
SLIM_API slim_handle slim_replay_handle_zeroalloc(slim_int in_size);
SLIM_API slim_handle slim_replay_handle_calloc(slim_int in_elements, slim_int in_element_size);
SLIM_API void slim_replay_handle_free(slim_handle in_handle);
SLIM_API slim_int slim_replay_handle_size(slim_handle in_handle);
SLIM_API void * slim_replay_handle_lock(slim_handle in_handle);
SLIM_API void slim_replay_handle_unlock(slim_handle in_handle);
SLIM_API slim_vhandle slim_replay_vhandle_alloc(slim_int in_size);
SLIM_API slim_vhandle slim_replay_vhandle_zeroalloc(slim_int in_size);
SLIM_API slim_vhandle slim_replay_vhandle_calloc(slim_int in_elements, slim_int in_element_size);
SLIM_API void slim_replay_vhandle_free(slim_vhandle in_vhandle);
SLIM_API void * slim_replay_vhandle_lock(slim_vhandle in_vhandle);
SLIM_API void slim_replay_vhandle_unlock(slim_vhandle in_vhandle);
SLIM_API slim_bool slim_replay_vhandle_realloc(slim_vhandle in_vhandle, slim_int in_size);
SLIM_API slim_int slim_replay_vhandle_size(slim_vhandle in_vhandle);
SLIM_API slim_bool slim_replay_memory_set_new_handler(SLIM_MemoryNewHandlerProc in_callback, slim_opaque in_arg);
SLIM_API slim_bool slim_replay_memory_clear_new_handler(SLIM_MemoryNewHandlerProc in_callback, slim_opaque in_arg);
#endif /* defined(SLIM_TANK_REPLAY) */

/* slim_memory_tank.c */
#ifndef SLIM_CONFIG_MEMORY_ALTERNATIVE
#if 0 /* Declared in tmtank.h */
SLIM_API slim_bool slim_tank_memory_initialize(void *in_start, slim_int in_len);
SLIM_API slim_bool slim_tank_memory_set_new_handler(SLIM_MemoryNewHandlerProc in_callback, slim_opaque in_arg);
SLIM_API slim_bool slim_tank_memory_clear_new_handler(SLIM_MemoryNewHandlerProc in_callback, slim_opaque in_arg);
SLIM_API void slim_tank_memory_finalize(void);
#endif /* 0 */
#ifdef SLIM_CONFIG_MULTITHREAD
SLIM_API void slim_tank_memory_set_mutex(slim_opaque in_mutex);
#endif /* defined(SLIM_CONFIG_MULTITHREAD) */
#if 0 /* Declared in tmtank.h */
SLIM_API void * slim_tank_memory_alloc(slim_int in_size);
SLIM_API void * slim_tank_memory_zeroalloc(slim_int in_size);
SLIM_API void slim_tank_memory_free(void *in_memory);
SLIM_API void * slim_tank_memory_realloc(void *in_memory, slim_int in_size);
SLIM_API slim_handle slim_tank_handle_alloc(slim_int in_size);
SLIM_API slim_handle slim_tank_handle_zeroalloc(slim_int in_size);
SLIM_API slim_handle slim_tank_handle_calloc(slim_int in_elements, slim_int in_element_size);
SLIM_API void slim_tank_handle_free(slim_handle in_handle);
SLIM_API slim_int slim_tank_handle_size(slim_handle in_handle);
SLIM_API void * slim_tank_handle_lock(slim_handle in_handle);
SLIM_API void slim_tank_handle_unlock(slim_handle in_handle);
#endif /* 0 */
#ifdef SLIM_CONFIG_MEMORY_DEBUG
SLIM_API void * slim_tank_handle_locate_d(slim_handle in_handle);
#endif /* defined(SLIM_CONFIG_MEMORY_DEBUG) */
#ifdef SLIM_CONFIG_MEMORY_DEBUG
SLIM_API void slim_tank_handle_unlocate_d(slim_handle in_handle);
#endif /* defined(SLIM_CONFIG_MEMORY_DEBUG) */
#ifdef SLIM_CONFIG_MEMORY_DEBUG
SLIM_API void * slim_tank_vhandle_locate_d(slim_vhandle in_vhandle);
#endif /* defined(SLIM_CONFIG_MEMORY_DEBUG) */
#ifdef SLIM_CONFIG_MEMORY_DEBUG
SLIM_API void slim_tank_vhandle_unlocate_d(slim_vhandle in_vhandle);
#endif /* defined(SLIM_CONFIG_MEMORY_DEBUG) */
#if 0 /* Declared in tmtank.h */
SLIM_API slim_vhandle slim_tank_vhandle_alloc(slim_int in_size);
SLIM_API slim_vhandle slim_tank_vhandle_zeroalloc(slim_int in_size);
SLIM_API slim_vhandle slim_tank_vhandle_calloc(slim_int in_elements, slim_int in_element_size);
SLIM_API void slim_tank_vhandle_free(slim_vhandle in_vhandle);
SLIM_API slim_int slim_tank_vhandle_size(slim_vhandle in_vhandle);
SLIM_API void * slim_tank_vhandle_lock(slim_vhandle in_vhandle);
SLIM_API void slim_tank_vhandle_unlock(slim_vhandle in_vhandle);
SLIM_API slim_bool slim_tank_vhandle_realloc(slim_vhandle in_vhandle, slim_int in_size);
SLIM_API void slim_tank_memory_disable_compact(slim_bool in_disable);
SLIM_API void slim_tank_memory_compact(void);
#endif /* 0 */
#ifdef SLIM_CONFIG_MEMORY_DEBUG
SLIM_API void slim_tank_memory_debug_set_notify_proc(SLIM_MemoryAllocFreeDebugNotifyProc in_proc);
#endif /* defined(SLIM_CONFIG_MEMORY_DEBUG) */
#if 0 /* Declared in tmtank.h */
SLIM_API void slim_tank_set_peer_procs(TTankPeerProcs *in_peer_procs);
SLIM_API void slim_tank_set_tank_info(TTankInfo *in_tank_info);
SLIM_API void slim_tank_get_tank_info(TTankInfo *out_tank_info);
SLIM_API TAttachTank slim_tank_attach(void *in_start, slim_int in_len);
SLIM_API slim_bool slim_tank_detach(TAttachTank in_tank);
#endif /* 0 */
#endif /* !SLIM_CONFIG_MEMORY_ALTERNATIVE */

/* slim_memory_tank_node.c */


/* slim_memory_tank_node_ptr.c */


/* slim_memory_test.c */


/* slim_memory_verify.c */


/* slim_token.c */


/* slim_resolve.c */


/* slim_util.c */

SLIM_API slim_bool slim_lib_initialize(void *in_heap, slim_int in_heap_size);
SLIM_API void slim_lib_finalize(void);
