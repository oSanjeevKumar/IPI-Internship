/*
	isctype.h
	Copyright(c) 1996-2002 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/basis/isctype.h 31    06/06/09 1:45 Yamabuti $ */

/* DO NOT EDIT! This file is generated automatically. */
	
#ifndef SLIM_ISCTYPE_H
#define SLIM_ISCTYPE_H

#ifndef SLIM_BASE_H
#include <slim/basis/base.h>
#endif

SLIM_BEGIN_C_LINKAGE

#define SLIM_CLIB_CTYPE_UPPER 0x00000001
#define SLIM_CLIB_CTYPE_LOWER 0x00000002
#define SLIM_CLIB_CTYPE_CNTRL_LOW 0x00000004
#define SLIM_CLIB_CTYPE_OCT 0x00000008
#define SLIM_CLIB_CTYPE_DIGIT 0x00000010
#define SLIM_CLIB_CTYPE_SPACE 0x00000020
#define SLIM_CLIB_CTYPE_TAB 0x00000040
#define SLIM_CLIB_CTYPE_HEX 0x00000080
#define SLIM_CLIB_CTYPE_PUNCT 0x00000100
#define SLIM_CLIB_CTYPE_ASCII_SP 0x00000200
#define SLIM_CLIB_CTYPE_EOL 0x00000400
#define SLIM_CLIB_CTYPE_NONASCII 0x00000800
#define SLIM_CLIB_CTYPE_HYPHEN 0x00001000
#define SLIM_CLIB_CTYPE_UNDER_SCORE 0x00002000
#define SLIM_CLIB_CTYPE_COMMA 0x00004000
#define SLIM_CLIB_CTYPE_PLUS 0x00008000
#define SLIM_CLIB_CTYPE_EQUAL 0x00010000
#define SLIM_CLIB_CTYPE_CSS_SEL_MOD 0x00020000
#define SLIM_CLIB_CTYPE_CSS_SEL_TERM 0x00040000
#define SLIM_CLIB_CTYPE_CSS_PROPVAL_DELIM 0x00080000
#define SLIM_CLIB_CTYPE_FORM_NO_ENCODE_CHARS 0x00100000
#define SLIM_CLIB_CTYPE_RFC2396_MARK 0x00200000
#define SLIM_CLIB_CTYPE_RFC2396_RESERVED 0x00400000
#define SLIM_CLIB_CTYPE_RFC3986_UNRESERVED 0x00800000
#define SLIM_CLIB_CTYPE_RFC3986_GEN_DELIMS 0x01000000
#define SLIM_CLIB_CTYPE_RFC3986_SUB_DELIMS 0x02000000
#define SLIM_CLIB_CTYPE_RFC822_SPECIALS 0x04000000
#define SLIM_CLIB_CTYPE_XML_NAME_1ST_EXT 0x08000000
#define SLIM_CLIB_CTYPE_XML_NAME_EXT 0x10000000
#define SLIM_CLIB_CTYPE_XML_CLOSE_PAREN 0x20000000

#define SLIM_CLIB_CTYPE_CNTRL (SLIM_CLIB_CTYPE_CNTRL_LOW|SLIM_CLIB_CTYPE_NONASCII)
#define SLIM_CLIB_CTYPE_ALPHA (SLIM_CLIB_CTYPE_UPPER|SLIM_CLIB_CTYPE_LOWER)
#define SLIM_CLIB_CTYPE_ALNUM (SLIM_CLIB_CTYPE_ALPHA|SLIM_CLIB_CTYPE_DIGIT)
#define SLIM_CLIB_CTYPE_WHITE (SLIM_CLIB_CTYPE_CNTRL_LOW|SLIM_CLIB_CTYPE_ASCII_SP)
#define SLIM_CLIB_CTYPE_XDIGIT (SLIM_CLIB_CTYPE_DIGIT|SLIM_CLIB_CTYPE_HEX)
#define SLIM_CLIB_CTYPE_GRAPH (SLIM_CLIB_CTYPE_ALNUM|SLIM_CLIB_CTYPE_PUNCT)
#define SLIM_CLIB_CTYPE_NONGRAPH (SLIM_CLIB_CTYPE_CNTRL|SLIM_CLIB_CTYPE_ASCII_SP)
#define SLIM_CLIB_CTYPE_PRINT (SLIM_CLIB_CTYPE_GRAPH|SLIM_CLIB_CTYPE_ASCII_SP)
#define SLIM_CLIB_CTYPE_WHITE_OR_EQUAL (SLIM_CLIB_CTYPE_WHITE|SLIM_CLIB_CTYPE_EQUAL)
#define SLIM_CLIB_CTYPE_WHITE_OR_COMMA (SLIM_CLIB_CTYPE_WHITE|SLIM_CLIB_CTYPE_COMMA)
#define SLIM_CLIB_CTYPE_CSS_NMSTART (SLIM_CLIB_CTYPE_ALPHA|SLIM_CLIB_CTYPE_NONASCII|SLIM_CLIB_CTYPE_UNDER_SCORE)
#define SLIM_CLIB_CTYPE_CSS_NMCHAR (SLIM_CLIB_CTYPE_ALNUM|SLIM_CLIB_CTYPE_HYPHEN|SLIM_CLIB_CTYPE_NONASCII|SLIM_CLIB_CTYPE_UNDER_SCORE)
#define SLIM_CLIB_CTYPE_CSS_ESCAPE (SLIM_CLIB_CTYPE_PRINT|SLIM_CLIB_CTYPE_GRAPH|SLIM_CLIB_CTYPE_NONASCII)
#define SLIM_CLIB_CTYPE_CSS_SEL_DELIM (SLIM_CLIB_CTYPE_CSS_SEL_MOD|SLIM_CLIB_CTYPE_CSS_SEL_TERM)
#define SLIM_CLIB_CTYPE_FORM_NO_ENCODE (SLIM_CLIB_CTYPE_ALNUM|SLIM_CLIB_CTYPE_FORM_NO_ENCODE_CHARS)
#define SLIM_CLIB_CTYPE_RFC2396_UNRESERVED (SLIM_CLIB_CTYPE_ALNUM|SLIM_CLIB_CTYPE_RFC2396_MARK)
#define SLIM_CLIB_CTYPE_RFC3986_RESERVED (SLIM_CLIB_CTYPE_RFC3986_GEN_DELIMS|SLIM_CLIB_CTYPE_RFC3986_SUB_DELIMS)
#define SLIM_CLIB_CTYPE_RFC822_NONATOM (SLIM_CLIB_CTYPE_NONGRAPH|SLIM_CLIB_CTYPE_RFC822_SPECIALS)
#define SLIM_CLIB_CTYPE_RFC822_WSP (SLIM_CLIB_CTYPE_ASCII_SP|SLIM_CLIB_CTYPE_TAB)
#define SLIM_CLIB_CTYPE_XML_VER_NUM (SLIM_CLIB_CTYPE_ALNUM|SLIM_CLIB_CTYPE_XML_NAME_EXT|SLIM_CLIB_CTYPE_XML_NAME_1ST_EXT)
#define SLIM_CLIB_CTYPE_XML_ENCODING_NAME (SLIM_CLIB_CTYPE_ALNUM|SLIM_CLIB_CTYPE_XML_NAME_EXT|SLIM_CLIB_CTYPE_UNDER_SCORE)
#define SLIM_CLIB_CTYPE_XML_NAME_1ST (SLIM_CLIB_CTYPE_ALPHA|SLIM_CLIB_CTYPE_XML_NAME_1ST_EXT)
#define SLIM_CLIB_CTYPE_XML_NAME (SLIM_CLIB_CTYPE_ALNUM|SLIM_CLIB_CTYPE_XML_NAME_EXT|SLIM_CLIB_CTYPE_XML_NAME_1ST_EXT)
#define SLIM_CLIB_CTYPE_XML_DELIM_ELEM_NAME (SLIM_CLIB_CTYPE_WHITE|SLIM_CLIB_CTYPE_XML_CLOSE_PAREN)
#define SLIM_CLIB_CTYPE_XML_DELIM_ATTR_NAME (SLIM_CLIB_CTYPE_WHITE_OR_EQUAL|SLIM_CLIB_CTYPE_XML_CLOSE_PAREN)
#define SLIM_CLIB_CTYPE_XML_DELIM_ATTR_VALUE (SLIM_CLIB_CTYPE_WHITE|SLIM_CLIB_CTYPE_XML_CLOSE_PAREN)
#define SLIM_CLIB_CTYPE_WML_VAR_NAME_1ST (SLIM_CLIB_CTYPE_ALPHA|SLIM_CLIB_CTYPE_UNDER_SCORE)
#define SLIM_CLIB_CTYPE_WML_VAR_NAME (SLIM_CLIB_CTYPE_WML_VAR_NAME_1ST|SLIM_CLIB_CTYPE_DIGIT)

extern SLIM_ROM slim_word cSlim_clib_ctype_table[256];

typedef slim_bool (*slim_ctype_proc)(slim_int c);
#define slim_isctype(c,type) (cSlim_clib_ctype_table[(c)] & (type))
slim_bool (slim_isctype)(slim_int in_c, slim_int in_type);

#define slim_isupper(c) (slim_isctype((c),SLIM_CLIB_CTYPE_UPPER))
#define slim_islower(c) (slim_isctype((c),SLIM_CLIB_CTYPE_LOWER))
#define slim_iscntrl_low(c) (slim_isctype((c),SLIM_CLIB_CTYPE_CNTRL_LOW))
#define slim_isoct(c) (slim_isctype((c),SLIM_CLIB_CTYPE_OCT))
#define slim_isdigit(c) (slim_isctype((c),SLIM_CLIB_CTYPE_DIGIT))
#define slim_isspace(c) (slim_isctype((c),SLIM_CLIB_CTYPE_SPACE))
#define slim_istab(c) (slim_isctype((c),SLIM_CLIB_CTYPE_TAB))
#define slim_ishex(c) (slim_isctype((c),SLIM_CLIB_CTYPE_HEX))
#define slim_ispunct(c) (slim_isctype((c),SLIM_CLIB_CTYPE_PUNCT))
#define slim_isascii_sp(c) (slim_isctype((c),SLIM_CLIB_CTYPE_ASCII_SP))
#define slim_iseol(c) (slim_isctype((c),SLIM_CLIB_CTYPE_EOL))
#define slim_isnonascii(c) (slim_isctype((c),SLIM_CLIB_CTYPE_NONASCII))
#define slim_ishyphen(c) (slim_isctype((c),SLIM_CLIB_CTYPE_HYPHEN))
#define slim_isunder_score(c) (slim_isctype((c),SLIM_CLIB_CTYPE_UNDER_SCORE))
#define slim_iscomma(c) (slim_isctype((c),SLIM_CLIB_CTYPE_COMMA))
#define slim_isplus(c) (slim_isctype((c),SLIM_CLIB_CTYPE_PLUS))
#define slim_isequal(c) (slim_isctype((c),SLIM_CLIB_CTYPE_EQUAL))
#define slim_iscss_sel_mod(c) (slim_isctype((c),SLIM_CLIB_CTYPE_CSS_SEL_MOD))
#define slim_iscss_sel_term(c) (slim_isctype((c),SLIM_CLIB_CTYPE_CSS_SEL_TERM))
#define slim_iscss_propval_delim(c) (slim_isctype((c),SLIM_CLIB_CTYPE_CSS_PROPVAL_DELIM))
#define slim_isform_no_encode_chars(c) (slim_isctype((c),SLIM_CLIB_CTYPE_FORM_NO_ENCODE_CHARS))
#define slim_isrfc2396_mark(c) (slim_isctype((c),SLIM_CLIB_CTYPE_RFC2396_MARK))
#define slim_isrfc2396_reserved(c) (slim_isctype((c),SLIM_CLIB_CTYPE_RFC2396_RESERVED))
#define slim_isrfc3986_unreserved(c) (slim_isctype((c),SLIM_CLIB_CTYPE_RFC3986_UNRESERVED))
#define slim_isrfc3986_gen_delims(c) (slim_isctype((c),SLIM_CLIB_CTYPE_RFC3986_GEN_DELIMS))
#define slim_isrfc3986_sub_delims(c) (slim_isctype((c),SLIM_CLIB_CTYPE_RFC3986_SUB_DELIMS))
#define slim_isrfc822_specials(c) (slim_isctype((c),SLIM_CLIB_CTYPE_RFC822_SPECIALS))
#define slim_isxml_name_1st_ext(c) (slim_isctype((c),SLIM_CLIB_CTYPE_XML_NAME_1ST_EXT))
#define slim_isxml_name_ext(c) (slim_isctype((c),SLIM_CLIB_CTYPE_XML_NAME_EXT))
#define slim_isxml_close_paren(c) (slim_isctype((c),SLIM_CLIB_CTYPE_XML_CLOSE_PAREN))
#define slim_iscntrl(c) (slim_isctype((c),SLIM_CLIB_CTYPE_CNTRL))
#define slim_isalpha(c) (slim_isctype((c),SLIM_CLIB_CTYPE_ALPHA))
#define slim_isalnum(c) (slim_isctype((c),SLIM_CLIB_CTYPE_ALNUM))
#define slim_iswhite(c) (slim_isctype((c),SLIM_CLIB_CTYPE_WHITE))
#define slim_isxdigit(c) (slim_isctype((c),SLIM_CLIB_CTYPE_XDIGIT))
#define slim_isgraph(c) (slim_isctype((c),SLIM_CLIB_CTYPE_GRAPH))
#define slim_isnongraph(c) (slim_isctype((c),SLIM_CLIB_CTYPE_NONGRAPH))
#define slim_isprint(c) (slim_isctype((c),SLIM_CLIB_CTYPE_PRINT))
#define slim_iswhite_or_equal(c) (slim_isctype((c),SLIM_CLIB_CTYPE_WHITE_OR_EQUAL))
#define slim_iswhite_or_comma(c) (slim_isctype((c),SLIM_CLIB_CTYPE_WHITE_OR_COMMA))
#define slim_iscss_nmstart(c) (slim_isctype((c),SLIM_CLIB_CTYPE_CSS_NMSTART))
#define slim_iscss_nmchar(c) (slim_isctype((c),SLIM_CLIB_CTYPE_CSS_NMCHAR))
#define slim_iscss_escape(c) (slim_isctype((c),SLIM_CLIB_CTYPE_CSS_ESCAPE))
#define slim_iscss_sel_delim(c) (slim_isctype((c),SLIM_CLIB_CTYPE_CSS_SEL_DELIM))
#define slim_isform_no_encode(c) (slim_isctype((c),SLIM_CLIB_CTYPE_FORM_NO_ENCODE))
#define slim_isrfc2396_unreserved(c) (slim_isctype((c),SLIM_CLIB_CTYPE_RFC2396_UNRESERVED))
#define slim_isrfc3986_reserved(c) (slim_isctype((c),SLIM_CLIB_CTYPE_RFC3986_RESERVED))
#define slim_isrfc822_nonatom(c) (slim_isctype((c),SLIM_CLIB_CTYPE_RFC822_NONATOM))
#define slim_isrfc822_wsp(c) (slim_isctype((c),SLIM_CLIB_CTYPE_RFC822_WSP))
#define slim_isxml_ver_num(c) (slim_isctype((c),SLIM_CLIB_CTYPE_XML_VER_NUM))
#define slim_isxml_encoding_name(c) (slim_isctype((c),SLIM_CLIB_CTYPE_XML_ENCODING_NAME))
#define slim_isxml_name_1st(c) (slim_isctype((c),SLIM_CLIB_CTYPE_XML_NAME_1ST))
#define slim_isxml_name(c) (slim_isctype((c),SLIM_CLIB_CTYPE_XML_NAME))
#define slim_isxml_delim_elem_name(c) (slim_isctype((c),SLIM_CLIB_CTYPE_XML_DELIM_ELEM_NAME))
#define slim_isxml_delim_attr_name(c) (slim_isctype((c),SLIM_CLIB_CTYPE_XML_DELIM_ATTR_NAME))
#define slim_isxml_delim_attr_value(c) (slim_isctype((c),SLIM_CLIB_CTYPE_XML_DELIM_ATTR_VALUE))
#define slim_iswml_var_name_1st(c) (slim_isctype((c),SLIM_CLIB_CTYPE_WML_VAR_NAME_1ST))
#define slim_iswml_var_name(c) (slim_isctype((c),SLIM_CLIB_CTYPE_WML_VAR_NAME))

slim_bool (slim_isupper)(slim_int in_c);
slim_bool (slim_islower)(slim_int in_c);
slim_bool (slim_iscntrl_low)(slim_int in_c);
slim_bool (slim_isoct)(slim_int in_c);
slim_bool (slim_isdigit)(slim_int in_c);
slim_bool (slim_isspace)(slim_int in_c);
slim_bool (slim_istab)(slim_int in_c);
slim_bool (slim_ishex)(slim_int in_c);
slim_bool (slim_ispunct)(slim_int in_c);
slim_bool (slim_isascii_sp)(slim_int in_c);
slim_bool (slim_iseol)(slim_int in_c);
slim_bool (slim_isnonascii)(slim_int in_c);
slim_bool (slim_ishyphen)(slim_int in_c);
slim_bool (slim_isunder_score)(slim_int in_c);
slim_bool (slim_iscomma)(slim_int in_c);
slim_bool (slim_isplus)(slim_int in_c);
slim_bool (slim_isequal)(slim_int in_c);
slim_bool (slim_iscss_sel_mod)(slim_int in_c);
slim_bool (slim_iscss_sel_term)(slim_int in_c);
slim_bool (slim_iscss_propval_delim)(slim_int in_c);
slim_bool (slim_isform_no_encode_chars)(slim_int in_c);
slim_bool (slim_isrfc2396_mark)(slim_int in_c);
slim_bool (slim_isrfc2396_reserved)(slim_int in_c);
slim_bool (slim_isrfc3986_unreserved)(slim_int in_c);
slim_bool (slim_isrfc3986_gen_delims)(slim_int in_c);
slim_bool (slim_isrfc3986_sub_delims)(slim_int in_c);
slim_bool (slim_isrfc822_specials)(slim_int in_c);
slim_bool (slim_isxml_name_1st_ext)(slim_int in_c);
slim_bool (slim_isxml_name_ext)(slim_int in_c);
slim_bool (slim_isxml_close_paren)(slim_int in_c);
slim_bool (slim_iscntrl)(slim_int in_c);
slim_bool (slim_isalpha)(slim_int in_c);
slim_bool (slim_isalnum)(slim_int in_c);
slim_bool (slim_iswhite)(slim_int in_c);
slim_bool (slim_isxdigit)(slim_int in_c);
slim_bool (slim_isgraph)(slim_int in_c);
slim_bool (slim_isnongraph)(slim_int in_c);
slim_bool (slim_isprint)(slim_int in_c);
slim_bool (slim_iswhite_or_equal)(slim_int in_c);
slim_bool (slim_iswhite_or_comma)(slim_int in_c);
slim_bool (slim_iscss_nmstart)(slim_int in_c);
slim_bool (slim_iscss_nmchar)(slim_int in_c);
slim_bool (slim_iscss_escape)(slim_int in_c);
slim_bool (slim_iscss_sel_delim)(slim_int in_c);
slim_bool (slim_isform_no_encode)(slim_int in_c);
slim_bool (slim_isrfc2396_unreserved)(slim_int in_c);
slim_bool (slim_isrfc3986_reserved)(slim_int in_c);
slim_bool (slim_isrfc822_nonatom)(slim_int in_c);
slim_bool (slim_isrfc822_wsp)(slim_int in_c);
slim_bool (slim_isxml_ver_num)(slim_int in_c);
slim_bool (slim_isxml_encoding_name)(slim_int in_c);
slim_bool (slim_isxml_name_1st)(slim_int in_c);
slim_bool (slim_isxml_name)(slim_int in_c);
slim_bool (slim_isxml_delim_elem_name)(slim_int in_c);
slim_bool (slim_isxml_delim_attr_name)(slim_int in_c);
slim_bool (slim_isxml_delim_attr_value)(slim_int in_c);
slim_bool (slim_iswml_var_name_1st)(slim_int in_c);
slim_bool (slim_iswml_var_name)(slim_int in_c);


SLIM_END_C_LINKAGE

#endif
