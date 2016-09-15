/*
	split.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/basis/split.h 16    05/12/28 12:08 Someya $ */

#ifndef SLIM_SPLIT_H_PRIVATE
#define SLIM_SPLIT_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

/*              */
/* string split */
/*              */

#define SLIM_SPLIT_SS_SET(ss,s_,len_) { (ss).s = (s_); (ss).len = (len_); }

enum {
	SLIM_CLIB_SPLIT_TOKEN,
	SLIM_CLIB_SPLIT_BOTH,
	SLIM_CLIB_SPLIT_AFTER,
	SLIM_CLIB_SPLIT_BEFORE,
	SLIM_CLIB_SPLIT_SPLITTYPES
};





#define slim_splboth_delim_ctype(ss,proc) (slim_splxxx_delim_ctype((ss),(proc),SLIM_CLIB_SPLIT_BOTH))
#define slim_splboth_span_ctype(ss,proc) (slim_splxxx_span_ctype((ss),(proc),SLIM_CLIB_SPLIT_BOTH))
#define slim_splboth_delim_ctype_or_chars(ss,flag,chars) (slim_splxxx_delim_ctype_or_chars((ss),(flag),SLIM_CLIB_SPLIT_BOTH,(chars)))
#define slim_splboth_span_ctype_or_chars(ss,flag,chars) (slim_splxxx_span_ctype_or_chars((ss),(flag),SLIM_CLIB_SPLIT_BOTH,(chars)))
#define slim_splboth_delim_ctype_proc(ss,proc) (slim_splxxx_delim_ctype_proc((ss),(proc),SLIM_CLIB_SPLIT_BOTH))
#define slim_splboth_span_ctype_proc(ss,proc) (slim_splxxx_span_ctype_proc((ss),(proc),SLIM_CLIB_SPLIT_BOTH))
#define slim_splboth_delim(ss,chars) (slim_splxxx_delim((ss),(chars),SLIM_CLIB_SPLIT_BOTH))
#define slim_splboth_span(ss,chars) (slim_splxxx_span((ss),(chars),SLIM_CLIB_SPLIT_BOTH))
#define slim_splboth_str(ss,str) (slim_splxxx_str((ss),(str),SLIM_CLIB_SPLIT_BOTH))
#define slim_splboth_istr(ss,str) (slim_splxxx_istr((ss),(str),SLIM_CLIB_SPLIT_BOTH))
#define slim_splboth_char(ss,c) (slim_splxxx_char((ss),(c),SLIM_CLIB_SPLIT_BOTH))
#define slim_splboth_ichar(ss,c) (slim_splxxx_ichar((ss),(c),SLIM_CLIB_SPLIT_BOTH))
#define slim_splboth_eol(ss) (slim_splxxx_eol((ss),SLIM_CLIB_SPLIT_BOTH))

#define slim_splafter_delim_ctype(ss,proc) (slim_splxxx_delim_ctype((ss),(proc),SLIM_CLIB_SPLIT_AFTER))
#define slim_splafter_span_ctype(ss,proc) (slim_splxxx_span_ctype((ss),(proc),SLIM_CLIB_SPLIT_AFTER))
#define slim_splafter_delim_ctype_or_chars(ss,flag,chars) (slim_splxxx_delim_ctype_or_chars((ss),(flag),SLIM_CLIB_SPLIT_AFTER,(chars)))
#define slim_splafter_span_ctype_or_chars(ss,flag,chars) (slim_splxxx_span_ctype_or_chars((ss),(flag),SLIM_CLIB_SPLIT_AFTER,(chars)))
#define slim_splafter_delim_ctype_proc(ss,proc) (slim_splxxx_delim_ctype_proc((ss),(proc),SLIM_CLIB_SPLIT_AFTER))
#define slim_splafter_span_ctype_proc(ss,proc) (slim_splxxx_span_ctype_proc((ss),(proc),SLIM_CLIB_SPLIT_AFTER))
#define slim_splafter_delim(ss,chars) (slim_splxxx_delim((ss),(chars),SLIM_CLIB_SPLIT_AFTER))
#define slim_splafter_span(ss,chars) (slim_splxxx_span((ss),(chars),SLIM_CLIB_SPLIT_AFTER))
#define slim_splafter_str(ss,str) (slim_splxxx_str((ss),(str),SLIM_CLIB_SPLIT_AFTER))
#define slim_splafter_istr(ss,str) (slim_splxxx_istr((ss),(str),SLIM_CLIB_SPLIT_AFTER))
#define slim_splafter_char(ss,c) (slim_splxxx_char((ss),(c),SLIM_CLIB_SPLIT_AFTER))
#define slim_splafter_ichar(ss,c) (slim_splxxx_ichar((ss),(c),SLIM_CLIB_SPLIT_AFTER))
#define slim_splafter_eol(ss) (slim_splxxx_eol((ss),SLIM_CLIB_SPLIT_AFTER))

#define slim_splbefore_delim_ctype(ss,proc) (slim_splxxx_delim_ctype((ss),(proc),SLIM_CLIB_SPLIT_BEFORE))
#define slim_splbefore_span_ctype(ss,proc) (slim_splxxx_span_ctype((ss),(proc),SLIM_CLIB_SPLIT_BEFORE))
#define slim_splbefore_delim_ctype_or_chars(ss,flag,chars) (slim_splxxx_delim_ctype_or_chars((ss),(flag),SLIM_CLIB_SPLIT_BEFORE,(chars)))
#define slim_splbefore_span_ctype_or_chars(ss,flag,chars) (slim_splxxx_span_ctype_or_chars((ss),(flag),SLIM_CLIB_SPLIT_BEFORE,(chars)))
#define slim_splbefore_delim_ctype_proc(ss,proc) (slim_splxxx_delim_ctype_proc((ss),(proc),SLIM_CLIB_SPLIT_BEFORE))
#define slim_splbefore_span_ctype_proc(ss,proc) (slim_splxxx_span_ctype_proc((ss),(proc),SLIM_CLIB_SPLIT_BEFORE))
#define slim_splbefore_delim(ss,chars) (slim_splxxx_delim((ss),(chars),SLIM_CLIB_SPLIT_BEFORE))
#define slim_splbefore_span(ss,chars) (slim_splxxx_span((ss),(chars),SLIM_CLIB_SPLIT_BEFORE))
#define slim_splbefore_str(ss,str) (slim_splxxx_str((ss),(str),SLIM_CLIB_SPLIT_BEFORE))
#define slim_splbefore_istr(ss,str) (slim_splxxx_istr((ss),(str),SLIM_CLIB_SPLIT_BEFORE))
#define slim_splbefore_char(ss,c) (slim_splxxx_char((ss),(c),SLIM_CLIB_SPLIT_BEFORE))
#define slim_splbefore_ichar(ss,c) (slim_splxxx_ichar((ss),(c),SLIM_CLIB_SPLIT_BEFORE))
#define slim_splbefore_eol(ss) (slim_splxxx_eol((ss),SLIM_CLIB_SPLIT_BEFORE))

#define slim_rsplboth_delim_ctype(ss,proc) (slim_rsplxxx_delim_ctype((ss),(proc),SLIM_CLIB_SPLIT_BOTH))
#define slim_rsplboth_span_ctype(ss,proc) (slim_rsplxxx_span_ctype((ss),(proc),SLIM_CLIB_SPLIT_BOTH))
#define slim_rsplboth_delim_ctype_proc(ss,proc) (slim_rsplxxx_delim_ctype_proc((ss),(proc),SLIM_CLIB_SPLIT_BOTH))
#define slim_rsplboth_span_ctype_proc(ss,proc) (slim_rsplxxx_span_ctype_proc((ss),(proc),SLIM_CLIB_SPLIT_BOTH))
#define slim_rsplboth_delim(ss,chars) (slim_rsplxxx_delim((ss),(chars),SLIM_CLIB_SPLIT_BOTH))
#define slim_rsplboth_span(ss,chars) (slim_rsplxxx_span((ss),(chars),SLIM_CLIB_SPLIT_BOTH))
#define slim_rsplboth_str(ss,str) (slim_rsplxxx_str((ss),(str),SLIM_CLIB_SPLIT_BOTH))
#define slim_rsplboth_istr(ss,str) (slim_rsplxxx_istr((ss),(str),SLIM_CLIB_SPLIT_BOTH))
#define slim_rsplboth_char(ss,c) (slim_rsplxxx_char((ss),(c),SLIM_CLIB_SPLIT_BOTH))
#define slim_rsplboth_ichar(ss,c) (slim_rsplxxx_ichar((ss),(c),SLIM_CLIB_SPLIT_BOTH))

#define slim_rsplafter_delim_ctype(ss,proc) (slim_rsplxxx_delim_ctype((ss),(proc),SLIM_CLIB_SPLIT_AFTER))
#define slim_rsplafter_span_ctype(ss,proc) (slim_rsplxxx_span_ctype((ss),(proc),SLIM_CLIB_SPLIT_AFTER))
#define slim_rsplafter_delim_ctype_proc(ss,proc) (slim_rsplxxx_delim_ctype_proc((ss),(proc),SLIM_CLIB_SPLIT_AFTER))
#define slim_rsplafter_span_ctype_proc(ss,proc) (slim_rsplxxx_span_ctype_proc((ss),(proc),SLIM_CLIB_SPLIT_AFTER))
#define slim_rsplafter_delim(ss,chars) (slim_rsplxxx_delim((ss),(chars),SLIM_CLIB_SPLIT_AFTER))
#define slim_rsplafter_span(ss,chars) (slim_rsplxxx_span((ss),(chars),SLIM_CLIB_SPLIT_AFTER))
#define slim_rsplafter_str(ss,str) (slim_rsplxxx_str((ss),(str),SLIM_CLIB_SPLIT_AFTER))
#define slim_rsplafter_istr(ss,str) (slim_rsplxxx_istr((ss),(str),SLIM_CLIB_SPLIT_AFTER))
#define slim_rsplafter_char(ss,c) (slim_rsplxxx_char((ss),(c),SLIM_CLIB_SPLIT_AFTER))
#define slim_rsplafter_ichar(ss,c) (slim_rsplxxx_ichar((ss),(c),SLIM_CLIB_SPLIT_AFTER))

#define slim_rsplbefore_delim_ctype(ss,proc) (slim_rsplxxx_delim_ctype((ss),(proc),SLIM_CLIB_SPLIT_BEFORE))
#define slim_rsplbefore_span_ctype(ss,proc) (slim_rsplxxx_span_ctype((ss),(proc),SLIM_CLIB_SPLIT_BEFORE))
#define slim_rsplbefore_delim_ctype_proc(ss,proc) (slim_rsplxxx_delim_ctype_proc((ss),(proc),SLIM_CLIB_SPLIT_BEFORE))
#define slim_rsplbefore_span_ctype_proc(ss,proc) (slim_rsplxxx_span_ctype_proc((ss),(proc),SLIM_CLIB_SPLIT_BEFORE))
#define slim_rsplbefore_delim(ss,chars) (slim_rsplxxx_delim((ss),(chars),SLIM_CLIB_SPLIT_BEFORE))
#define slim_rsplbefore_span(ss,chars) (slim_rsplxxx_span((ss),(chars),SLIM_CLIB_SPLIT_BEFORE))
#define slim_rsplbefore_str(ss,str) (slim_rsplxxx_str((ss),(str),SLIM_CLIB_SPLIT_BEFORE))
#define slim_rsplbefore_istr(ss,str) (slim_rsplxxx_istr((ss),(str),SLIM_CLIB_SPLIT_BEFORE))
#define slim_rsplbefore_char(ss,c) (slim_rsplxxx_char((ss),(c),SLIM_CLIB_SPLIT_BEFORE))
#define slim_rsplbefore_ichar(ss,c) (slim_rsplxxx_ichar((ss),(c),SLIM_CLIB_SPLIT_BEFORE))

SLIM_END_C_LINKAGE

#endif
