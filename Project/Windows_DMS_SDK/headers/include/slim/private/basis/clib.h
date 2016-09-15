/*
	clib.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/basis/clib.h 78    05/12/28 12:08 Someya $ */

#ifndef SLIM_CLIB_H_PRIVATE
#define SLIM_CLIB_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

/*               */
/* birth & death */
/*               */


/*         */
/* numeric */
/*         */

#define slim_log2(n) (slim_log2_u((slim_word)(n)))

/*        */
/* memxxx */
/*        */


/*           */
/* substring */
/*           */

#define SLIM_SS_FORWARD(s,len,n)	((s)+=(n),(len)-=(n))
#define SLIM_SS_INC(s,len)			((s)++,(len)--)
#define SLIM_SS_DEC(s,len)			((s)--,(len)++)

/*          */
/* C string */
/*          */


/*          */
/* strtoxxx */
/*          */

extern SLIM_ROM slim_byte cSlim_clib_tolower_table[256];
extern SLIM_ROM slim_byte cSlim_clib_toupper_table[256];


#define slim_ss_atoi(is,il,os,ol) (slim_ss_strtoi((is),(il),(os),(ol),10))
#define slim_ss_atoui(is,il,os,ol) ((slim_int)slim_ss_strtoui32((is),(il),(os),(ol),10))
#define slim_ss_atoui32(is,il,os,ol) (slim_ss_strtoui32((is),(il),(os),(ol),10))
#define slim_ss_strtoi(is, il, os, ol, b) (slim_ss_safe_strtoi((is),(il),(os),(ol),(b),slim_nil))
#define slim_ss_strtoui(is,il,os,ol,b) ((slim_int)slim_ss_strtoui32((is),(il),(os),(ol),(b)))
#define slim_ss_strtoui32(is, il, os, ol, b) (slim_ss_safe_strtoui32((is),(il),(os),(ol),(b),slim_nil)) 

#define slim_tolower(c) ((slim_int)cSlim_clib_tolower_table[(c)])
#define slim_toupper(c) ((slim_int)cSlim_clib_toupper_table[(c)])

/*               */
/* string format */
/*               */

#define slim_format_ss_lower(os, is, len) slim_format_ss_case((os),(is),(len),slim_true)
#define slim_format_ss_upper(os, is, len) slim_format_ss_case((os),(is),(len),slim_false)

#define slim_format_int_radix_lower(buf, n, r) slim_format_int_radix_case((buf), (n), (r), slim_false)
#define slim_format_int_radix_upper(buf, n, r) slim_format_int_radix_case((buf), (n), (r), slim_true)

#define slim_format_binary_lower(os,b,l) slim_format_binary((os),(b),(l),slim_false)
#define slim_format_binary_upper(os,b,l) slim_format_binary((os),(b),(l),slim_true)

/*        */
/* strxxx */
/*        */


/*                */
/* string compare */
/*                */


#define slim_cs_streq_cs(in_s1, in_s2)	slim_ss_streq_ss((in_s1), slim_strlen(in_s1), (in_s2), slim_strlen(in_s2))
#define slim_cs_istreq_cs(in_s1, in_s2)  slim_ss_istreq_ss((in_s1), slim_strlen(in_s1), (in_s2), slim_strlen(in_s2))

#define SLIM_STRCMP_NOCASE	0x00000001
#define SLIM_STRCMP_PREFIX	0x00000002

#define slim_ss_strcmp_ss(s,sl,t,tl) slim_ss_strcmpX_ss((s), (sl), (t), (tl), SLIM_FLAG_NONE)
#define slim_ss_strcmp_nocase_ss(s,sl,t,tl) slim_ss_strcmpX_ss((s), (sl), (t), (tl), SLIM_STRCMP_NOCASE)
#define slim_ss_strncmp_ss(s,sl,t,tl) slim_ss_strcmpX_ss((s), (sl), (t), (tl), SLIM_STRCMP_PREFIX)
#define slim_ss_strncmp_nocase_ss(s,sl,t,tl) slim_ss_strcmpX_ss((s), (sl), (t), (tl), SLIM_STRCMP_PREFIX|SLIM_STRCMP_NOCASE)

/*      */
/* time */
/*      */
/* for in_mode of slim_time_cmp(). */
enum {
	SLIM_TIME_CMP_LESS_THAN,			/* < */
	SLIM_TIME_CMP_GREATER_THAN,			/* > */
	SLIM_TIME_CMP_LESS_THAN_EQUAL,		/* <= */
	SLIM_TIME_CMP_GREATER_THAN_EQUAL,	/* >= */
	SLIM_TIME_CMP_EQUAL,				/* == */
	SLIM_TIME_CMP_NOT_EQUAL,			/* != */
	SLIM_TIME_CMP_MODES
};

/* flags for slim_time_parse() */
/* the way of correcting it when year is under 100. */
#define SLIM_TIME_YEAR_CORRECT_STATIC	0x00000001	/* added 1900 simply(the same as JavaScript). */
#define SLIM_TIME_YEAR_CORRECT_DYNAMIC	0x00000002	/* corrected within 80 before and 19 after the current year(the same as Java). */

/* treating of time zone when it isn't specifed. */
#define SLIM_TIME_TMZ_CORRECT_GMT		0x00000004	/* treat as GMT */

#define SLIM_TIME_MSECS_PER_SEC		1000
#define SLIM_TIME_SECS_PER_MIN		60
#define SLIM_TIME_MINS_PER_HOUR		60
#define SLIM_TIME_HOURS_PER_DAY		24
#define SLIM_TIME_MINS_PER_DAY		(SLIM_TIME_HOURS_PER_DAY * SLIM_TIME_MINS_PER_HOUR)
#define SLIM_TIME_SECS_PER_DAY		(SLIM_TIME_MINS_PER_DAY * SLIM_TIME_SECS_PER_MIN)
#define SLIM_TIME_MSECS_PER_MIN		(SLIM_TIME_MSECS_PER_SEC * SLIM_TIME_SECS_PER_MIN)
#define SLIM_TIME_MSECS_PER_HOUR 	(SLIM_TIME_MSECS_PER_MIN * SLIM_TIME_MINS_PER_HOUR)
#define SLIM_TIME_MSECS_PER_DAY		(SLIM_TIME_MSECS_PER_HOUR * SLIM_TIME_HOURS_PER_DAY)

#define slim_time_cmp_less_than(t1, t2) slim_time_cmp((t1), (t2), SLIM_TIME_CMP_LESS_THAN)
#define slim_time_cmp_greater_than(t1, t2) slim_time_cmp((t1), (t2), SLIM_TIME_CMP_GREATER_THAN)
#define slim_time_cmp_less_than_equal(t1, t2) slim_time_cmp((t1), (t2), SLIM_TIME_CMP_LESS_THAN_EQUAL)
#define slim_time_cmp_greater_than_equal(t1, t2) slim_time_cmp((t1), (t2), SLIM_TIME_CMP_GREATER_THAN_EQUAL)
#define slim_time_cmp_equal(t1, t2) slim_time_cmp((t1), (t2), SLIM_TIME_CMP_EQUAL)
#define slim_time_cmp_not_equal(t1, t2) slim_time_cmp((t1), (t2), SLIM_TIME_CMP_NOT_EQUAL)

SLIM_END_C_LINKAGE

#endif
