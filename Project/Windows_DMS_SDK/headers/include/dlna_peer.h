/*
 * dlna_peer.h
 * Copyright (C) 2007-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

/* DLNA peer header file.  This is platform independent
   definition.  */

#ifndef NFLC_DLNA_PEER_H
#define NFLC_DLNA_PEER_H

/* Include config.h  */
#ifdef HAVE_CONFIG_H
#include <dlna_config_target.h>
#endif /* HAVE_CONFIG_H */

/* DLNA configuration.  */
#include <dlna_config.h>

/* SLIM header.  */
#ifdef USE_SLIM_LIB
#include <slim/libcore.h>
#else  /* USE_SLIM_LIB */
#include <slim_dummy.h>
#endif /* USE_SLIM_LIB */

/* Generic list macros.  */
#include <dlna_peer_list.h>

#define USE_TRICK_PLAY

#include <dlna_debug.h>
#include <dlna_debug_id.h>
#include <stdio.h>
#include <stdarg.h>

#ifndef DLNA_API
#define DLNA_API  /* DO NOT set this value here */
#endif /* !DLNA_API */

#define PARAMETER_NOT_USED(p) ((void)(p))

/**
 * @addtogroup enums
 */
/*@{*/

/**
 * QOS priority for dlna
 */
enum {
	DLNAQOS_0 = 1,
	DLNAQOS_1 = 0,
	DLNAQOS_2 = 5,
	DLNAQOS_3 = 7
};

/*@}*/

/**
 * @addtogroup enums
 */
/*@{*/

/*
 * Language set
 */
enum {
  DLNA_I18N_LANGSET_JAPANESE = 1,
  DLNA_I18N_LANGSET_WESTERN,
  DLNA_I18N_LANGSET_KOREAN,
  DLNA_I18N_LANGSET_SIMPLIFIED_CHINESE,
  DLNA_I18N_LANGSET_TRADITIONAL_CHINESE,
  DLNA_I18N_LANGSET_ARMENIAN,
  DLNA_I18N_LANGSET_BALTIC,
  DLNA_I18N_LANGSET_CELTIC,
  DLNA_I18N_LANGSET_CENTRAL_EUROPEAN,
  DLNA_I18N_LANGSET_CROATIAN,
  DLNA_I18N_LANGSET_CYRILLIC,
  DLNA_I18N_LANGSET_RUSSIAN_CYRILLIC,
  DLNA_I18N_LANGSET_UKRANIAN_CYRILLIC,
  DLNA_I18N_LANGSET_GREEK,
  DLNA_I18N_LANGSET_ICELANDIC,
  DLNA_I18N_LANGSET_NORDIC,
  DLNA_I18N_LANGSET_ROMANIAN,
  DLNA_I18N_LANGSET_SOUTH_EUROPEAN,
  DLNA_I18N_LANGSET_THAI,
  DLNA_I18N_LANGSET_TURKISH,
  DLNA_I18N_LANGSET_VIETNAMESE,
  DLNA_I18N_LANGSET_ARABIC,
  DLNA_I18N_LANGSET_HEBREW,
  DLNA_I18N_LANGSET_UNIVERSAL
};

enum {
  DLNA_CHARSET_UNCERTAIN = -2,
  DLNA_CHARSET_UNKNOWN = -1,
  DLNA_CHARSET_US_ASCII = 1,
  DLNA_CHARSET_SHIFT_JIS,
  DLNA_CHARSET_EUC_JP,
  DLNA_CHARSET_ISO_2022_JP,
  DLNA_CHARSET_ISO_8859_1,
  DLNA_CHARSET_WINDOWS_1252,
  DLNA_CHARSET_EUC_KR,
  DLNA_CHARSET_UHC,
  DLNA_CHARSET_GB2312,
  DLNA_CHARSET_GBK,
  DLNA_CHARSET_GB18030,
  DLNA_CHARSET_BIG5,
  DLNA_CHARSET_ISO_8859_4,
  DLNA_CHARSET_WINDOWS_1257,
  DLNA_CHARSET_ISO_8859_2,
  DLNA_CHARSET_WINDOWS_1250,
  DLNA_CHARSET_ISO_8859_5,
  DLNA_CHARSET_WINDOWS_1251,
  DLNA_CHARSET_KOI8_R,
  DLNA_CHARSET_ISO_8859_7,
  DLNA_CHARSET_WINDOWS_1253,
  DLNA_CHARSET_ISO_8859_10,
  DLNA_CHARSET_ISO_8859_3,
  DLNA_CHARSET_WINDOWS_874,
  DLNA_CHARSET_ISO_8859_9,
  DLNA_CHARSET_WINDOWS_1254,
  DLNA_CHARSET_ISO_8859_6,
  DLNA_CHARSET_WINDOWS_1256,
  DLNA_CHARSET_ISO_8859_8,
  DLNA_CHARSET_ISO_8859_8_I,
  DLNA_CHARSET_WINDOWS_1255,
  DLNA_CHARSET_UTF_8,
  DLNA_CHARSET_UTF_16BE,
  DLNA_CHARSET_UTF_16LE,
  DLNA_CHARSET_UCS_2BE,
  DLNA_CHARSET_UCS_2LE,
  DLNA_CHARSET_UCS_4BE,
  DLNA_CHARSET_UCS_4LE
};

/*@}*/


/**
 * @addtogroup datatypes
 */
/*@{*/

/* slim_long -- Signed type.  Greater than or equal to 32 bit.  */
/*!
Signed 32-bit
*/
typedef long slim_long;
#ifdef USE_SLIM_LIB
/*!
Unsigned 32-bit
*/
typedef unsigned long slim_ulong;
#endif /* USE_SLIM_LIB */


/* DLNA peer definitions.  */

/* DLNA extended types.  */
/*!
Type for DLNA time (32-bit unsigned integer).
*/
#if __x86_64__
typedef slim_int64 dlna_time_t;
#else
typedef slim_word dlna_time_t;
#endif /* __x86_64__ */
/*!
Type for DLNA file/memory size (32-bit unsigned integer).
*/
typedef slim_size dlna_size_t;
/*!
Type for DLNA file/memory size (32-bit signed integer).
*/
typedef slim_int dlna_ssize_t;
/*!
Type for file pointer management.
*/
typedef slim_long dlna_off_t;
/*!
Type for file pointer descriptor.
*/
typedef slim_iaddr_word dlna_file_t;

/*@}*/

/**
 * @addtogroup macros
 */
/*@{*/

#define DLNA_INVALID_FILE_HANDLE ((dlna_file_t)-1)

/* Utility macro for list. */
#define DLNA_VA_START(LIST, PARM)  va_start (LIST, PARM)
#define DLNA_VA_ARG(LIST, T)  (T) va_arg (LIST, T)
#define DLNA_VA_END(LIST)  va_end (LIST)

/* Flag manipulation.  */
#define CHECK_FLAG(A, B)    ((A) & (B))
#define SET_FLAG(A, B)      ((A) |= (B))
#define UNSET_FLAG(A, B)    ((A) &= ~(B))

/*@}*/

#ifdef __cplusplus
extern "C" {
#endif

/*** Type definitions ***/
/**
 * @addtogroup structures
 */
/*@{*/

struct dlna_sint64_
{
  slim_int high;
  slim_word low; /* Note: low part does not contains the sign. */
};

#define SINT_64_INIT { 0 , 0 }

/*!
Signed 64-bit
\code
typedef struct _dlna_sint64 {
slim_int high;
slim_word low;
} dlna_sint64;
\endcode
\par Member:

<table>
	<tr>
		<td>high</td>
		<td>High-order 32 bits</td>
	</tr>
	<tr>
		<td>low</td>
		<td>Low-order 32 bits</td>
	</tr>
</table>

*/
typedef struct dlna_sint64_ dlna_sint64;

struct dlna_uint64_
{
  slim_word high;
  slim_word low;
};

#define UINT_64_INIT { 0 , 0 }

/*!
Unsigned 64-bit

\code
typedef struct _dlna_uint64 {
 slim_word high;
 slim_word low;
} dlna_uint64;
\endcode
\par Member:

<table>
	<tr>
		<td>high</td>
		<td>High-order 32 bits</td>
	</tr>
	<tr>
		<td>low</td>
		<td>Low-order 32 bits</td>
	</tr>
</table>

*/
typedef struct dlna_uint64_ dlna_uint64;

struct dlna_contents_file_info_ {
  slim_char *path;
  slim_char *title;
  slim_char *extension;
};
typedef struct dlna_contents_file_info_ dlna_contents_file_info;

/*@}*/

/* Global variables */
extern slim_int dlna_errno;

/* Memory API. */

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Allocates memory area.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_size</td>
		<td>Size of memory to allocate (bytes)</td>
	</tr>
</table>

\return != slim_nil Pointer to allocated memory area
\return == slim_nil Unable to allocate
\par Description:
This function allocates the in_size size of memory area, and returns the start address.

If this function fails to allocate the memory area, it returns slim_nil.

The memory area allocated by this function is released by dlna_memory_free().
*/
void *
dlna_memory_alloc(slim_int in_size);

/*!
\par Function:
Reallocates memory area.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_memory</td>
		<td>Pointer to allocated memory area</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_size</td>
		<td>Memory area size after change (bytes)</td>
	</tr>
</table>

\return != slim_nil Pointer to reallocated memory area
\return == slim_nil Unable to reallocate
\par Description:
This function reallocates the memory area, in_memory, with the in_size size, and returns the start
address.

Data saved in the original memory area needs to be copied to a new memory area.

If this function fails to allocate the memory area, it returns slim_nil.

The memory area specified for in_memory must hold the state before the call.

The memory area reallocated by this function is released by dlna_memory_free().

If a new memory area is reallocated to an address other than in_memory, in_memory is assumed to be
released when returning from this function call, and, dlna_memory_free() will not be called.
*/
void *
dlna_memory_realloc(void *in_memory, slim_int in_size);


/*!
\par Function:
Allocates memory area (initialize with 0).
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_size</td>
		<td>Size of memory area to allocate (bytes)</td>
	</tr>
</table>

\return != slim_nil Pointer to allocated memory area
\return == slim_nil Unable to allocate

\par Description:
This function allocates a memory area of in_size size, and returns the start address.

It initializes the allocated memory content with 0.

If this function fails to allocate the memory area, it returns slim_nil.

The memory area allocated by this function is released by dlna_memory_free().
*/
void *
dlna_memory_zeroalloc (slim_int in_size);

/*!
\par Function:
Releases memory area.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_memory</td>
		<td>Pointer to memory area to release</td>
	</tr>
</table>

\return None
\par Description:
This function releases the memory area allocated by dlna_memory_alloc(),
dlna_memory_realloc(), dlna_memory_zeroalloc(), or dlna_strdup().
*/
void
dlna_memory_free(void *in_memory);

/*  Memory utility API.  */
/*!
\par Function:
Sets memory area.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_dest</td>
		<td>Pointer to memory area to set</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_c</td>
		<td>Character to set</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_count</td>
		<td>Number of bytes to set</td>
	</tr>
</table>

\return Pointer to memory area set for character
\par Description:
This function sets character in_c to in_count bytes from the start of the area represented by in_dest.

*/
void *
dlna_memset(void *in_dest, slim_int in_c, slim_int in_count);

/*!
\par Function:
Copies memory area.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_dest</td>
		<td>Pointer to copy destination memory area</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_src</td>
		<td>Pointer to copy source memory area</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_count</td>
		<td>Number of bytes to copy</td>
	</tr>
</table>

\return Pointer to copied memory area
\par Description:
This function copies the area specified by in_src and in_count to the area specified by in_dest and
in_count.

These two areas are assumed not to overlap.

*/
void *
dlna_memcpy(void *in_dest, void *in_src, slim_int in_count);

/*!
\par Function:
Compares memory area.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_s1</td>
		<td>Pointer to memory area to compare</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_s2</td>
		<td>Pointer to memory area to compare</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_count</td>
		<td>Number of bytes to compare</td>
	</tr>
</table>

\return <0 Memory area in_s1 is smaller than memory area in_s2
\return 0 Memory area in_s1 is equal to memory area in_s2
\return >0 Memory area in_s1 is larger than memory area in_s2
\par Description:
This function compares two memory areas in_s1 and in_s2 from the start up to in_count bytes and
returns the magnitude relationship.
*/
slim_int
dlna_memcmp(void *in_s1, void *in_s2, slim_int in_count);

/*!
\par Function:
Moves memory area.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_dest</td>
		<td>Pointer to move destination memory area</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_src</td>
		<td>Pointer to move source memory area</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_count</td>
		<td>Number of bytes to move<br/>
			Specify the size of memory area to move.</td>
	</tr>
</table>

\return Pointer to moved memory area
\par Description:
This function moves the area specified by in_src and in_count to the area specified by in_dest and
in_count.

These two areas can be moved normally, even if they overlap.
*/
void *
dlna_memmove(void *in_dest, void *in_src, slim_int in_count);

/*!
\par Function:
Gets string length.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_s</td>
		<td>Pointer to string</td>
	</tr>
</table>

\return Length of string in_s
\par Description:
This function returns the number of characters of length of string in_s.

The NULL terminator is not included in the length of string.

*/
/* String utility API.  */
dlna_size_t
dlna_strlen(const slim_char *in_s);

/*!
\par Function:
Compares string.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_s1</td>
		<td>Pointer to string to compare</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_s2</td>
		<td>Pointer to string to compare</td>
	</tr>
</table>

\return <0 String in_s1 is smaller than string in_s2
\return	0 String in_s1 is equal to string in_s2
\return >0 String in_s1 is larger than string in_s2
\par Description:
This function compares in_s1 and in_s2 from the start in lexicographic order and returns the magnitude
relationship.

*/
slim_int
dlna_strcmp(const slim_char *in_s1, const slim_char *in_s2);

/*!
\par Function:
Compares strings by specifying number of bytes.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_s1</td>
		<td>Pointer to string to compare</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_s2</td>
		<td>Pointer to string to compare</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_count</td>
		<td>Number of bytes to compare</td>
	</tr>
</table>

\return <0 String in_s1 is smaller than string in_s2
\return	0 String in_s1 is equal to string in_s2
\return >0 String in_s1 is larger than string in_s2
\par Description:
This function compares in_s1 and in_s2 from the start in lexicographic order up to the number of bytes
specified for in_count and returns the magnitude relationship.
*/
slim_int
dlna_strncmp(const slim_char *in_s1, const slim_char *in_s2, dlna_size_t in_count);

/*!
\par Function:
Compares strings ignoring case.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_s1</td>
		<td>Pointer to string to compare</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_s2</td>
		<td>Pointer to string to compare</td>
	</tr>
</table>

\return <0 String in_s1 is smaller than string in_s2
\return	0 String in_s1 is equal to string in_s2
\return >0 String in_s1 is larger than string in_s2
\par Description:
This function compares in_s1 and in_s2 from the start in lexicographic order, while ignoring the case of
the characters, and returns the magnitude relationship.
*/
slim_int
dlna_strcmp_nocase(const slim_char *in_s1, const slim_char *in_s2);

/*!
\par Function:
Compares strings by specifying number of bytes and ignoring case.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_s1</td>
		<td>Pointer to string to compare</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_s2</td>
		<td>Pointer to string to compare</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_count</td>
		<td>Number of bytes to compare</td>
	</tr>
</table>

\return <0 String in_s1 is smaller than string in_s2
\return	0 String in_s1 is equal to string in_s2
\return >0 String in_s1 is larger than string in_s2
\par Description:
This function compares in_s1 and in_s2 from the start in lexicographic order, while ignoring the case of
the characters, up to the number of bytes specified for in_count, and returns the magnitude relationship.
*/
slim_int
dlna_strncmp_nocase(const slim_char *in_s1, const slim_char *in_s2, dlna_size_t in_count);

/*!
\par Function:
Copies string.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_s1</td>
		<td>Pointer to copy destination string</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_s2</td>
		<td>Pointer to copy source string</td>
	</tr>
</table>

\return Start address of copy destination string
\par Description:
This function copies the string specified for in_s2 including the NULL terminator to the memory area
specified for in_s1, and returns the start address.

The memory areas specified for in_s1 and in_s2 cannot overlap one another. A memory area sufficient
to store the string being copied is specified for the copy destination in_s1.
*/
slim_char *
dlna_strcpy(slim_char *in_s1, slim_char *in_s2);

/*!
\par Function:
Copies string by specifying number of bytes.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_s1</td>
		<td>Pointer to copy destination string</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_s2</td>
		<td>Pointer to copy source string</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_count</td>
		<td>Number of bytes of characters to copy</td>
	</tr>
</table>

\return Start address of copy destination string
\par Description:
This function copies the string specified for in_s2 for the number of bytes of in_count to the memory area
specified for in_s1, and returns the start address.

If a NULL terminator does not exist within the size in_count from the start of the in_s1 string, the copied
string does not have to end with a null.

The memory areas specified for n_s1 and in_s2 cannot overlap one another. A memory area sufficient
to store the string being copied is specified for the copy destination in_s1.
*/
slim_char *
dlna_strncpy(slim_char *in_s1, slim_char *in_s2, dlna_size_t in_count);

/*!
\par Function:
Converts string to slim_word value.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_buf</td>
		<td>Pointer to string to convert</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_endptr</td>
		<td>Pointer to string that cannot be converted</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_base</td>
		<td>Base to convert</td>
	</tr>
</table>

\return Converted slim_word value
\par Description:
This function converts in_buf to slim_word value, following the base specified for in_base.

When conversion fails, the pointer to the string of which conversion failed is stored in out_endptr.
*/
slim_word
dlna_strtoul(slim_char *in_buf, slim_char **out_endptr, slim_int in_base);

/*!
\par Function:

\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td> inbuf </td>
		<td> string containing the representation of an integral number </td>
	</tr>
	<tr>
		<td>[out]</td>
		<td> out_endptr </td>
		<td> Reference to an object of type slim_char*, whose value is set by the function to the next character in str after the numerical value.
This parameter can also be a slim_nil pointer, in which case it is not used </td>
	</tr>
	<tr>
		<td>[in]</td>
		<td> in_base </td>
		<td> base of the stored in string number </td>
	</tr>
</table>
\return an integer with stored in string number
\par Return Values:
<table>
	<tr>
		<td> \b not 0 </td>
		<td> \b Returning number stored in string</td>
	</tr>
	<tr>
		<td> 0 </td>
		<td> no valid conversion in current base could be performed </td>
	</tr>
</table>

\par Description:
it is dlna version of strtol function
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes as many characters as possible that are valid following a syntax that depends on the base parameter, and interprets them as a numerical value. Finally, a pointer to the first character following the integer representation in str is stored in the object pointed by endptr.

If the value of base is zero, the syntax expected is similar to that of integer constants, which is formed by a succession of:

    * An optional plus or minus sign
    * An optional prefix indicating octal or hexadecimal base ("0" or "0x" respectively)
    * A sequence of decimal digits (if no base prefix was specified) or either octal or hexadecimal digits if a specific prefix is present


If the base value is between 2 and 36, the format expected for the integral number is a succession of the valid digits and/or letters needed to represent integers of the specified radix (starting from '0' and up to 'z'/'Z' for radix 36). The sequence may optionally be preceded by a plus or minus sign and, if base is 16, an optional "0x" or "0X" prefix.

If the first sequence of non-whitespace characters in str is not a valid integral number as defined above, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
*/

slim_int
dlna_strtol (slim_char *in_buf, slim_char **out_endptr, slim_int in_base);

/*!
\par Function:
Duplicates string.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_str</td>
		<td>Pointer to string to duplicate</td>
	</tr>
</table>

\return != slim_nil Pointer to new string
\return == slim_nil Unable to create new string
\par Description:
This function duplicates the string specified for in_str in a new string, and returns a pointer to the new
string.

The memory area allocated by this function is released by dlna_memory_free().
*/
slim_char *
dlna_strdup(const slim_char *in_str);

/*!
\par Function:
Locates first occurrence of specified string from last of another string.
\par Parameters:

<table>
<tr>
<td>[in]</td>
<td>in_string1</td>
<td>Pointer to string to be located</td>
</tr>
<tr>
<td>[in]</td>
<td>in_string2</td>
<td>Pointer to string to locate</td>
</tr>
</table>

\return != slim_nil Pointer to the first occurrence of character from last
\return == slim_nil No match
\par Description:
This function starts searching for the string in_string2 from the last of the string specified for in_string1
(excluding the NULL terminator), and returns the pointer to the string located first.
*/
slim_char *dlna_strrstr(slim_char *in_string1,
	slim_char *in_string2);
/*!
\par Function:
Locates first occurrence of specified string from start of another string.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_string1</td>
		<td>Pointer to string to be located</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_string2</td>
		<td>Pointer to string to locate</td>
	</tr>
</table>

\return != slim_nil Pointer to the first occurrence of character
\return == slim_nil No match
\par Description:
This function starts searching for the string in_string2 from the start of the string specified for in_string1
(excluding the NULL terminator), and returns the pointer to the string located first.
*/
slim_char *
dlna_strstr(const slim_char *in_string1, const slim_char *in_string2);

/*!
\par Function:
Locates first occurrence of specified character from start of string.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_str</td>
		<td>Pointer to string to be located</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_c</td>
		<td>Character to locate</td>
	</tr>
</table>

\return != slim_nil Pointer to the first occurrence of character
\return == slim_nil No match
\par Description:
This function starts searching for the character in_c from the start of the string specified for in_str
(including the NULL terminator), and returns the pointer to the character located first.
*/
slim_char *
dlna_strchr(slim_char *in_str, slim_int in_c);

/*!
\par Function:
Locates last occurrence of specified character from start of string.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_str</td>
		<td>Pointer to string to be located</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_c</td>
		<td>Character to locate</td>
	</tr>
</table>

\return != slim_nil Pointer to the last occurrence of character
\return == slim_nil No match
\par Description:
This function starts searching for the character in_c from the start of the string specified for in_str
(including the NULL terminator), and returns the pointer to the character located last.
*/
slim_char *
dlna_strrchr(slim_char *in_str, slim_int in_c);

/*!
\par Function:
Appends string to end of another string.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_string1</td>
		<td>Pointer to destination string</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_string2</td>
		<td>Pointer to string to append</td>
	</tr>
</table>

\return Pointer to in_string1
\par Description:
This function appends a copy of the string specified for in_string2 (including the NULL terminator) to the
end of the string in_string1.The lead byte of in_string2 overwrites the NULL terminator of in_string1.
*/
slim_char *
dlna_strcat(slim_char *in_string1, slim_char *in_string2);

/*!
\par Function:
Appends given number of characters of string to end of another string.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_string1</td>
		<td>Pointer to destination string</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_string2</td>
		<td>Pointer to string to append</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_count</td>
		<td>Number of characters to be copied</td>
	</tr>
</table>

\return Pointer to in_string1
\par Description:
This function appends a copy of in_count characters of the string specified for in_string2 (including the
NULL terminator) to the end of the string in_string1.The lead byte of in_string2 overwrites the NULL
terminator of in_string1.
*/
slim_char *
dlna_strncat (slim_char *in_string1, slim_char *in_string2, dlna_size_t in_count);

/*!
\par Function:
Gets length of first segment of string that consists only of characters contained in specified string,
located in another string.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_string1</td>
		<td>Pointer to string to be located</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_string2</td>
		<td>Pointer to string to locate</td>
	</tr>
</table>

\return >0 Length of first segment of in_string1 that consists only of characters from in_string2
\return 0 No match
\par Description:
This function locates the first segment of a string that consists only of the characters contained in
in_string2 in the string specified for in_string1, and returns its length.
*/
dlna_size_t
dlna_strspn(slim_char *in_string1, slim_char *in_string2);

/*!
\par Function:
A sequence of calls to this function split str into tokens, which are sequences of contiguous
characters separated by any of the characters that are part of delimiters.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_str</td>
		<td>C string to truncate.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_delim</td>
		<td>C string containing the delimiter characters.</td>
	</tr>
</table>

\return A pointer to the last token found in string.
\par Description:
A pointer to the last token found in string.
*/
slim_char *
dlna_strtok (slim_char *in_str, const slim_char *in_delim);

/*!
\par Function:
Converts string to slim_int value.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_string</td>
		<td>Pointer to string to convert</td>
	</tr>
</table>

\return Converted slim_int value
\par Description:
This function converts in_string to an slim_int value.
*/
slim_int
dlna_atoi(slim_char *in_string);


/*!
\par Function:
Converts string to slim_long value.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_string</td>
		<td>Pointer to string to convert</td>
	</tr>
</table>

\return Converted slim_long value
\par Description:
This function converts in_string to an slim_long value.
*/
slim_long
dlna_atol(slim_char *in_string);


/*!
\par Function:
Returns the common (base-10) logarithm of x.
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>x</td>
    <td>Value whose logarithm is calculated.</td>
  </tr>
</table>

\return Common logarithm of x.
\par Description:
This function Common logarithm of x.
*/
slim_double
dlna_log10(slim_double x);
/*!
\par Function:
Converts string to slim_double value.
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_string</td>
    <td>Pointer to string to convert</td>
  </tr>
</table>

\return Converted slim_double value
\par Description:
This function converts in_string to an slim_double value.
*/
slim_double
dlna_atof (slim_char *in_string);

/*!
\par Function:
Outputs string to string buffer according to specified format.
\par Parameters:

<table>
	<tr>
		<td>[out]</td>
		<td>in_string</td>
		<td>String buffer to output to</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_size</td>
		<td>Length of string to output to string buffer (bytes)</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_format</td>
		<td>String to specify format</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>... (argument list)</td>
		<td>Input data</td>
	</tr>
</table>


\return >=0 Length of string output to in_string (bytes)

If the result of conversion of input data in argument list is longer than in_size, it returns the length of converted input data.
\return 0<	Failed

\par Description:
This function converts the string specified for the argument list according to the format string specified
for in_format, and outputs up to in_size bytes of it to in_string.

This function must not output any string beyond in_size to in_string.If the result of converting the inputdata in the argument list is longer than in_size, it outputs up to in_size bytes from the start to in_string.

If in_size is 0, no string is output.
*/
slim_int
dlna_snprintf(slim_char *in_string, dlna_size_t in_size, const slim_char *in_format, ...);

slim_int
dlna_vsnprintf (slim_char *in_string, dlna_size_t in_size, const slim_char *in_format, va_list in_ap);

/*!
\par Function:
Inputs string from string buffer according to specified format.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_buf</td>
		<td>Source string buffer</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_format</td>
		<td>String to specify format</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>... (argument list)</td>
		<td>Output data</td>
	</tr>
</table>

\return Number of strings that match the format string specified for in_format and that are stored in the argument list
\par Description:
This function reads strings from in_buf according to the format string specified for in_format, and stores
them in the argument list.
*/
slim_int
dlna_sscanf(slim_char *in_buf, slim_char *in_format, ...);

/*!
\par Function:
Inputs string from sdtin according to specified format.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_format</td>
		<td>String to specify format</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>... (argument list)</td>
		<td>Output data</td>
	</tr>
</table>

\return On success, the function returns the number of items successfully read. This count can match the expected number of readings or fewer, even zero, if a matching failure happens.
In the case of an input failure before any data could be successfully read, EOF is returned.
\par Description:
This function reads strings from stdin according to the format string specified for in_format, and stores
them in the argument list.
*/
slim_int
dlna_scanf(slim_char *in_format, ...);

/*!
\par Function:
Checks whether character is white space.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_c</td>
		<td>Character to check</td>
	</tr>
</table>

\return Other than 0	in_c is a white space
\return 0	in_c is not a white space
\par Description:
This function returns whether a character is a white space in the 'C' locale.

A white space means a white space (' '), formfeed ('\\f'), linefeed ('\\n'), carriage return ('\\r'), horizontal
tab ('\\t'), or vertical tab ('\\v') in the 'C' locale.

in_c must be a value represented by unsigned char, or EOF. 0 is returned otherwise.
*/
slim_int
dlna_isspace(slim_int in_c);

/*!
\par Function:
Checks whether character is alphabatic.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_c</td>
		<td>Character to check</td>
	</tr>
</table>

\return Other than 0	in_c is a alphabatic character
\return 0	in_c is not a alphabatic character
\par Description:
This function returns whether a character is alphabetic.

in_c must be a value represented by unsigned char, or EOF. 0 is returned otherwise.
*/
slim_int
dlna_isalpha(slim_int in_c);

/*!
\par Function:
Checks whether character is printable.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_c</td>
		<td>Character to check</td>
	</tr>
</table>

\return Other than 0	in_c is a printable character
\return 0	in_c is not a printable character
\par Description:
This function returns whether a character is printable.

A value different from zero if indeed in_c is a printable character. 0 is returned otherwise.
*/
slim_int
dlna_isprint(slim_int in_c);

/*!
\par Function:
Checks whether character is alphanumeric.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_c</td>
		<td>Character to check</td>
	</tr>
</table>

\return Other than 0	in_c is a alphanumeric character
\return 0	in_c is not a alphanumeric character
\par Description:
This function returns whether a character is alphanumeric.

in_c must be a value represented by unsigned char, or EOF. 0 is returned otherwise.
*/
slim_int
dlna_isalnum(slim_int in_c);

/*!
\par Function:
Checks whether character is decimal digit.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_c</td>
		<td>Character to check</td>
	</tr>
</table>

\return Other than 0	in_c is a decimal digit
\return 0	in_c is not a decimal digit
\par Description:
This function returns whether a character is decimal digit.

in_c must be a value represented by unsigned char, or EOF. 0 is returned otherwise.
*/
slim_int
dlna_isdigit(slim_int in_c);

/*!
\par Function:
Checks whether character is hexadecimal digit.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_c</td>
		<td>Character to check</td>
	</tr>
</table>

\return Other than 0	in_c is a hexadecimal digit
\return 0	in_c is not hexadecimal digit
\par Description:
This function returns whether a character is hexadecimal digit.

in_c must be a value represented by unsigned char, or EOF. 0 is returned otherwise.
*/
slim_int
dlna_isxdigit(slim_int in_c);

/*!
\par Function:
Checks whether string represents valid int.
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_str</td>
    <td>String to check</td>
  </tr>
</table>

\return Other than 0 in_str is a valid integer
\return 0 in_str is not a valid integer
\par Description:
This function returns whether a string is valid integer number.

in_str must be a NULL terminated string
*/
slim_int
dlna_isint(slim_char *in_str);

/*!
\par Function:
Checks if string is made of digits only.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_s</td>
		<td>String to check</td>
	</tr>
</table>

\return Other than 0	in_s is made of digits only
\return 0	in_s is not made of digits only
\par Description:
This function checks, if the string contains digits only
*/
slim_int
dlna_isstringofdigits (const slim_char *in_s);

/*!
\par Function:
Converts uppercase character to lowercase.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_c</td>
		<td>Character to convert</td>
	</tr>
</table>

\return Lowercase letter for character specified for in_c When lowercase letter of in_c is available
\return Character specified for in_c When lowercase letter of in_c is not available
\par Description:
This function coverts an uppercase character to lowercase and returns it.

If the character cannot be converted to lowercase, the function returns the character specified for in_c.

If a value that cannot be represented by unsigned char or EOF is specified for in_c, it also returns the
character specified for in_c.
*/
slim_int
dlna_tolower(slim_int in_c);

/*!
\par Function:
Converts lowercase character to uppercase.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_c</td>
		<td>Character to convert</td>
	</tr>
</table>

\return Uppercase letter for character specified for in_c When uppercase letter of in_c is available
\return Character specified for in_c When uppercase letter of in_c is not available
\par Description:
This function coverts a lowercase character to uppercase and returns it.

If the character cannot be converted to uppercase, the function returns the character specified for in_c.

When a value that cannot be represented by unsigned char or EOF is specified for in_c, it also returns
the character specified for in_c.
*/
slim_int
dlna_toupper(slim_int in_c);

/*@}*/

/*Error api*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Return last system error number.
\par Parameters: none
\Return last error number.
\par Description:
Return last error number.
*/
slim_int
dlna_get_last_error( void );

/*@}*/

/*Error api*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Terminates the process normally,
performing the regular cleanup for terminating processes.
\par Parameters: Status value returned to the parent process. Generally,
 a return value of 0 or EXIT_SUCCESS indicates success,
 and any other value or the constant EXIT_FAILURE.
\Return: none
\par Description:
Terminates process.
*/
void
dlna_exit( slim_int stat );

/*@}*/

/**
 * @addtogroup structures
 */
/*@{*/

/* DLNA substring structure.  */
struct dlna_split_ss_
{
  slim_char *s;
  slim_word len;
};
/*!
dlna_split_ss is the structure that stores substring.

\code
struct dlna_split_ss_ {
slim_char *s;
slim_int len;
};
typedef struct _dlna_split_ss dlna_split_ss;
\endcode
\par Member:

<table>
	<tr>
		<td>s</td>
		<td>Pointer to substring</td>
	</tr>
	<tr>
		<td>len</td>
		<td>length of s(bytes)</td>
	</tr>
</table>

*/
typedef struct dlna_split_ss_ dlna_split_ss;

/*@}*/

/**
 * @addtogroup enums
 */
/*@{*/

/*! DLNA peer for target system APIs.  */
enum {
  NFLC_SYS_PROP_USERAGENT = 1,
  NFLC_SYS_PROP_PLATFORM,
  NFLC_SYS_PROP_SYSTEMID

};

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Gets target system-dependent property value.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_key</td>
		<td>Property type (Enumeration variable shown in Table 3)</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_value</td>
		<td>Pointer to buffer that stores the property</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_value_buf_len</td>
		<td>Length of out_value</td>
	</tr>
</table>

\return >=0 Succeeded (number of bytes in string)
\return -1 Failed
\par Description:
This function gets the property value depending on the target system. The type in Table 4 can be
specified for in_key.

If out_value is not slim_nil, this function must store the value of property in out_value as a UTF-8
encoded and null-terminated string.

If out_value is slim_nil, this function must return the length of the property corresponding to in_key as
a return value. In this case, the caller calls this function again later setting a buffer with length "(length
of property) + 1" in out_value.

The length of string to be stored in out_value must not exceed the length of in_value_buf_len including
the null character. If the buffer length is not long enough for the string, this function must return -1.

If in_key is an unknown value, this function must return -1.

If the return value is -1, the default property value defined in dlna_config.h is used.

The property value must not be changed once this function is called.

<table>
	<tr>
		<td></td>
		<td><b>Table 5</b></td>
		<td></td>
	</tr>
	<tr>
		<td><b>Type</b></td>
		<td><b>Description</b></td>
		<td><b>Property value</b></td>
	</tr>
	<tr>
		<td>NFLC_SYS_PROP_USERAGENT</td>
		<td>User Agent specified in the HTTP header</td>
		<td>User Agent string

			- Encoding: UTF-8
			- Null-terminated

			The string "UPnP1.0 DLNADOC/1.50" must be included in the string</td>
	</tr>
</table>
*/
slim_int
dlnaSystemGetPropertyPeer(slim_int in_key, slim_char *out_value, slim_int in_value_buf_len);

/*@}*/


/* API for dynamic link libraries */

/**
 * @addtogroup datatypes
 */
/*@{*/

typedef void * TNFLCMODULE;
typedef void * TNFLCFUNC;

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/**
 * \par Function
 * Load a dynamic link module.
 * \par Parameters
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_path</td>
 *     <td>Full path pointing to the dynamic link library dot</td>
 *   </tr>
 *   <tr>
 *     <td>[out]</td>
 *     <td>out_module_handle</td>
 *     <td>Handle to the dynamic link library</td>
 *   </tr>
 * </table>
 *
 * \return SLIM_E_OK Module successfully loaded
 * \return SLIM_E_GENERIC Any other error
 *
 * \par Description
 * This function loads a dynamic link library from the specified path and outputs a handle to the module.
 *
 * \par Note
 * Linux implementation does not provide error codes. In case of failure DMS_GENERIC is returned and detailed error description is logged to console.
 */
slim_int dlnaSystemLoadModulePeer (const slim_char * in_path, TNFLCMODULE * out_module_handle);

/**
 * \par Function
 * Unload a dynamic link module.
 * \par Parameters
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_module_handle</td>
 *     <td>Handle to the dynamic link library</td>
 *   </tr>
 * </table>
 *
 * \return SLIM_E_OK Module successfully loaded
 * \return SLIM_E_GENERIC Any other error
 *
 * \par Description
 * This function unloads a dynamic link library.
 */
slim_int dlnaSystemUnloadModulePeer (TNFLCMODULE in_module_handle);

/**
 * \par Function
 * Access function with given name from a dynamic link module.
 * \par Parameters
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_module_handle</td>
 *     <td>Handle to the dynamic link library</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_function_name</td>
 *     <td>Name of the function stored in dynamic link library</td>
 *   </tr>
 *   <tr>
 *     <td>[out]</td>
 *     <td>out_address</td>
 *     <td>Address of the function stored in the dynamic link library dot</td>
 *   </tr>
 * </table>
 *
 * \return SLIM_E_OK Module successfully loaded
 * \return SLIM_E_GENERIC Any other error
 *
 * \par Description
 * This function access function stored in a dynamic link library and outputs its address.
 *
 * \par Note
 * Linux implementation does not provide error codes. In case of failure DMS_GENERIC is returned and detailed error description is logged to console.
 */
slim_int dlnaSystemGetProcAddressPeer (TNFLCMODULE in_module_handle, const slim_char * in_function_name, TNFLCFUNC * out_address);

/*@}*/


/* DLNA peer for file APIs.  */

/**
 * @addtogroup macros
 */
/*@{*/

/*! dlnaFileOpenPeer() flags.  */
#define DLNA_STREAM_READ                  (1 << 0)
#define DLNA_STREAM_WRITE                 (1 << 1)
#define DLNA_STREAM_CREATE                (1 << 2)
#define DLNA_STREAM_TRUNCATE              (1 << 3)
#define DLNA_STREAM_EXCLUSIVE             (1 << 4)
#define DLNA_STREAM_NONBLOCK		  (1 << 5)
#define DLNA_STREAM_APPEND		  (1 << 6)
#define DLNA_STREAM_LOCAL                 (1 << 7)
#define DLNA_STREAM_ONLINE                (1 << 8)
#define DLNA_STREAM_DECRYPT               (1 << 9)
#define DLNA_STREAM_DRM_PROTECTED         (1 << 10)
#define DLNA_STREAM_SYNC                  (1 << 11)
#define DLNA_STREAM_HIDDEN                (1 << 12)
/*@}*/

/**
 * @addtogroup enums
 */
/*@{*/

/*! dlnaFileSeekPeer() flags.  */
enum {
  DLNA_SEEK_SET,
  DLNA_SEEK_CUR,
  DLNA_SEEK_END
};

/*@}*/

/* File API. */

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Opens file.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_fname</td>
		<td>Path to file name to open</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_flag</td>
		<td>Specify logical OR of access mode and open mode<br/> Access mode must be specified.</td>
	</tr>
</table>

\par Access Mode:
One of the following is always specified as the access mode.

<table>
	<tr>
		<td>DLNA_STREAM_READ</td>
		<td>Opens file for read only</td>
	</tr>
	<tr>
		<td>DLNA_STREAM_WRITE</td>
		<td>Opens file for write only</td>
	</tr>
	<tr>
		<td>DLNA_STREAM_READ | DLNA_STREAM_WRITE</td>
		<td>Opens file for both read/write</td>
	</tr>
</table>

\par Open Mode:
This function specifies a logical OR combination of the access mode and one of the following.

If any other combination not shown below is specified, a file is opened in the specified access mode
when the file exists, or an error is returned if the file does not exist.

<table>
	<tr>
		<td>DLNA_STREAM_CREATE</td>
		<td>Opens files<br/>Creates new file if specified file does not exist</td>
	</tr>
	<tr>
		<td>DLNA_STREAM_TRUNCATE</td>
		<td>Opens file and makes file size zero bytes If specified file does not exist, error is returned</td>
	</tr>
	<tr>
		<td>DLNA_STREAM_APPEND</td>
		<td>Opens files with writes guaranteed at the end</td>
	</tr>
	<tr>
		<td>DLNA_STREAM_CREATE | DLNA_STREAM_TRUNCATE</td>
		<td>Creates new file If specified file exists, that file is overwritten</td>
	</tr>
	<tr>
		<td>DLNA_STREAM_CREATE | DLNA_STREAM_EXCLUSIVE or DLNA_STREAM_CREATE | DLNA_STREAM_TRUNCATE | DLNA_STREAM_EXCLUSIVE</td>
		<td>Creates new file If specified file exists, error is returned</td>
	</tr>
</table>

\return >=0 File descriptor
\return DLNA_INVALID_FILE_HANDLE Unable to open file

\par Description:
This function opens the file specified for in_fname, and returns its file descriptor.

The file descriptor must be a positive integer.
*/
dlna_file_t
dlnaFileOpenPeer(const slim_char *in_fname, slim_int in_flag);

/*!
\par Function:
Closes file.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>File descriptor</td>
	</tr>
</table>

\return None
\par Description:
This function closes the file of the file descriptor specified for in_desc.
*/
void
dlnaFileClosePeer(dlna_file_t in_desc);

/*!
\par Function:
Reads file.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>File descriptor</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_buf</td>
		<td>Pointer to buffer to read</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_len</td>
		<td>Number of bytes to read</td>
	</tr>
</table>

\return >0 Succeeded (number of bytes actually read)
\return 0 Reached end of file
\return -1 Failed
\par Description:
This function reads the in_len bytes of data from the current reading position of in_desc and stores it in
out_buf.

The reading position after completing the process moves by the number of bytes actually read
regardless of the file open mode.
*/
dlna_ssize_t
dlnaFileReadPeer(dlna_file_t in_desc, void *out_buf, dlna_size_t in_len);

/*!
\par Function:
Writes file.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>File descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_buf</td>
		<td>Pointer to buffer to be written to</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_len</td>
		<td>Number of bytes to write</td>
	</tr>
</table>

\return >0 Succeeded (number of bytes actually read)
\return -1 Failed
\par Description:
This function writes the in_len bytes of data from in_buf at the current writing position of in_desc.

The writing position after completing the process moves by the number of bytes actually written
regardless of the file open mode.
*/
dlna_ssize_t
dlnaFileWritePeer(dlna_file_t in_desc, void *in_buf, dlna_size_t in_len);

/*!
\par Function:
Deletes file.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_fname</td>
		<td>Path to name of file to delete</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return -1 Failed
\par Description:
This function deletes the file specified for in_fname.

It returns -1 if the file cannot be deleted because the specified file does not exist, or any other condition
that causes an error.

This function is called only when the file is closed.
*/
slim_int
dlnaFileDeletePeer(slim_char *in_fname);

/*!
\par Function:
Moves file pointer.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>File descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_offset</td>
		<td>Amount of movement (bytes)</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_origin</td>
		<td>Start point of moving. One of the following is specified:<br />
			DLNA_SEEK_SET Start of file (0)<br />
			DLNA_SEEK_CUR Current position of file pointer (1)<br />
			DLNA_SEEK_END End of file (2)</td>
	</tr>
</table>

\return >=0 Offset between start of file and position of file pointer after moving (bytes)
\return -1 Error occurred


\par Description:
This function moves the file pointer of in_desc by in_offset bytes from the position specified for in_origin.

If in_offset is a positive number, it moves the file pointer to the end of the file, and if it is a negative
number, it moves the file pointer to the start of the file.

If it is specified to move beyond the end of the file or beyond the start of the file, this function returns an
error code without changing the current position of the pointer.
*/
dlna_off_t
dlnaFileSeekPeer(dlna_file_t in_desc, dlna_off_t in_offset, slim_int in_origin);

/*!
\par Function:
Moves file pointer of 2GB file or more.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>File descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_offset</td>
		<td>Amount of movement (bytes)</td>
	</tr>
</table>

\return slim_true Succeeded
\return slim_false Failed



\par Description:
This function moves the in_desc file pointer in_offset bytes.

This function is equivalent to dlnaFileSeekPeer() with 64-bit length offset values support.

This function is used for seeking in files of 2GB or more from the NFLC core.
*/
slim_bool
dlnaFileSeek64Peer(dlna_file_t in_desc, dlna_uint64 in_offset);

/*!
\par Function:
Moves file pointer of 2GB file or more from first position.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>File descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_offset</td>
		<td>Amount of movement (bytes)</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_pos</td>
		<td>Bytes between start of file and position of file pointer after moving</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return -1 Failed
\par Description:
This function moves the in_desc file pointer in_offset bytes from the start of the file toward its end.

If the move succeeds, the function stores the bytes from the start of the file to the file pointer position
after moving to out_pos.

If the move fails, it returns -1.

This function is used for seeking in files of 2GB or more from the NFLC core.
*/
slim_int
dlnaFileSeek64PeerForward(dlna_file_t in_desc, dlna_uint64 in_offset, dlna_uint64 *out_pos);

/*!
\par Function:
Moves file pointer of 2GB file or more from last position.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>File descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_offset</td>
		<td>Amount of movement (bytes)</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_pos</td>
		<td>Bytes between start of file and position of file pointer after moving</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return -1 Failed
\par Description:
This function moves the in_desc file pointer in_offset bytes from the end of the file toward the file top.

If the move succeeds, the function stores the bytes from the start of the file to the file pointer position
after moving to out_pos.

If the move fails, it returns -1.

This function is used for seeking in files of 2GB or more from the NFLC core.
*/
slim_int
dlnaFileSeek64PeerBackward(dlna_file_t in_desc, dlna_uint64 in_offset, dlna_uint64 *out_pos);

/*!
\par Function:
Moves file pointer of 2GB file or more from current position.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>File descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_offset</td>
		<td>Amount of movement (bytes)</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_pos</td>
		<td>Bytes between start of file and position of file pointer after moving</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return -1 Failed



\par Description:
This function moves the in_desc file pointer in_offset bytes from the current position.

If in_offset is a positive number, it moves the file pointer to the end of the file, and if it is a negative
number, it moves the file pointer to the start of the file.

If the move succeeds, the function stores the bytes from the start of the file to the file pointer position
after moving to out_pos.

If the move fails, it returns -1.

This function is used for seeking in files of 2GB or more from the NFLC core.
*/
slim_int
dlnaFileSeek64PeerCurrent(dlna_file_t in_desc, dlna_sint64 in_offset, dlna_uint64 *out_pos);

/*!
\par Function:
 Function generates and stores file path to out_contents_path, path contains file directory, file name and file extension.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_contents_file_info</td>
		<td> file info</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_contents_path</td>
		<td>pointer where generated path can be stored</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_contents_path_len</td>
		<td> lenght of pointer where path will be stored</td>
	</tr>
</table>
\return slim_int error value
\par Return Values:
<table>
	<tr>
		<td> \b 0</td>
		<td> \b Path was generated succesfull</td>
	</tr>
	<tr>
		<td> -1 </td>
		<td> directory path, extension or file title was slim_nil or there was not enough space in out_content_path</td>
	</tr>
</table>
*/

slim_int
dlnaGenerateNewFileNamePeer(dlna_contents_file_info *in_contents_file_info, slim_char *out_contents_path, slim_int in_contents_path_len);

/*!
\par Function:
Creates FIFO file.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_fname</td>
		<td>File name including absolute path</td>
	</tr>
</table>

\return slim_true FIFO was created.
\return slim_false FIFO was not created.
\par Description:
This function creates a FIFO file specified by in_fname. It returns slim_true if FIFO file could be
created successful, otherwise slim_false.
*/
slim_bool
dlnaFIFOMakePeer (slim_char *in_fname);

/*!
\par Function:

\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_oldpath</td>
		<td>path to original file</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_newpath</td>
		<td>new filename</td>
	</tr>
</table>
\return return slim_bool value
\par Return Values:
<table>
	<tr>
		<td> \b slim_true</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td> slim_false </td>
		<td> Fail</td>
	</tr>
</table>
\par Description:
Function renames file specified in in_oldpath to name given in in_newpath
*/

slim_bool
dlnaRenameFilePeer (slim_char *in_oldpath, slim_char *in_newpath);

/*!
\par Function:
Clears the buffer
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>stream</td>
		<td>Pointer to a FILE object that specifies a buffered stream.</td>
	</tr>
</table>

\return A zero value indicates success.
If an error occurs, EOF is returned and the error indicator is set (see feof).

\par Description:
If the given stream was open for writing and the last i/o operation was an output operation,
 any unwritten data in the output buffer is written to the file.
If it was open for reading and the last operation was an input operation,
 the behavior depends on the specific library implementation.
If the argument is a null pointer, all open files are flushed.
The stream remains open after this call.
When a file is closed, either because of a call to fclose or because the program terminates,
 all the buffers associated with it are automatically flushed.
*/
slim_int
dlna_fflush(FILE * stream);

/*!
\par Function:
Read characters from stream.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>out_buf</td>
		<td>Pointer to buffer to read</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>len</td>
		<td>Maximum number of characters to be read</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>stream</td>
		<td>Pointer to a FILE object that identifies the stream where characters are read from.</td>
	</tr>
</table>

\return:
On success, the function returns the same str parameter.
If the End-of-File is encountered and no characters have been read, the contents of str remain unchanged and a null pointer is returned.
If an error occurs, a null pointer is returned.
\par Description:
Reads characters from stream and stores them as a C string into str until (num-1) characters have been read
 or either a newline or the End-of-File is reached, whichever comes first.
*/
slim_char*
dlna_fgets(void *in_buf, dlna_size_t len, FILE * stream);

/*@}*/

/**
 * @addtogroup datatypes
 */
/*@{*/

/* Directory API.  */
/*!
Type for directory desriptor.
*/
typedef void *dlna_dir_t;
/*!
Type for directory entry.
*/
typedef void *dlna_dirent;

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

#if defined(MEDIA_PROCESSING_EXTENSION) || defined(DEVELOPMENT_CONTENT_AGGREGATION)
/* Function required only when MPE is enabled */

/*!
\par Function:
Translates relative path to absolute path.
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>in_path</td>
                <td>Relative path</td>
        </tr>
        <tr>
                <td>[out]</td>
                <td>out_path</td>
                <td>Absolute path</td>
        </tr>
</table>

\return Pointer to absolute path
\return 0 Error occurred
\par Description:
This function translates relative in_path, and returns absolute path.
If out_path is slim_nil funtion allocates memory (needs to be freed by user), otherwise it fills out_path buffer.

*/
slim_char*
dlnaFileSystemRelativeToAbsolutePathPeer (const slim_char *in_path, slim_char *out_path);
#endif /* MEDIA_PROCESSING_EXTENSION || DEVELOPMENT_CONTENT_AGGREGATION*/
/*!
\par Function:
Opens directory.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_path</td>
		<td>Path to directory to open</td>
	</tr>
</table>

\return >0 Directory descriptor
\return 0 Error occurred
\par Description:
This function opens the directory specified for in_path, and returns the descriptor of the directory.

The directory descriptor is the dlna_dir_t type (void type pointer).

The directory descriptor is an argument to dlnaFileSystemCloseDirPeer() and
dlnaFileSystemReadDirPeer().
*/
dlna_dir_t
dlnaFileSystemOpenDirPeer(slim_char *in_path);

/*!
\par Function:
Closes directory.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>Directory descriptor</td>
	</tr>
</table>

\return None
\par Description:
This function closes the directory descriptor of the directory specified for in_desc.
*/
void
dlnaFileSystemCloseDirPeer(dlna_dir_t in_desc);

/*!
\par Function:
Creates directory.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_name</td>
		<td>Path to directory to create</td>
	</tr>
</table>

\return 0 Succeeded
\return -1 Failed
\par Description:
This function creates a directory on the path specified for in_name.

If write is not enabled for the parent directory of the directory specified by in_name, the function does not
create any directory and returns -1.

If the directory specified by in_name already exists on the file system, it returns -1.
*/
slim_int
dlnaFileSystemNewDirPeer(slim_char *in_name);

/*!
\par Function:
Deletes directory.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_name</td>
		<td>Path to directory to delete</td>
	</tr>
	        <tr>
                <td>[in]</td>
                <td>delelte_self</td>
                <td>Boolean indicating the directory itself to be deleted or not</td>
        </tr>
</table>

\return 0 Succeeded
\return -1 Failed
\par Description:
This function deletes the directory in the path specified for in_name.

If the directory is not empty, it does not delete the directory and returns -1.

If there is no directory specified by in_name or the specified one is not a directory, it returns -1.
*/
slim_int
dlnaFileSystemDeleteDirPeer(slim_char *in_name, slim_bool delete_self);

/*!
\par Function:
Reads next directory entry.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>Directory descriptor</td>
	</tr>
</table>

\return != slim_nil Descriptor of next directory entry
\return == slim_nil No descriptor for next directory entry
\par Description:
This function returns a directory entry from the directory descriptor specified for in_desc.

This function is used to obtain entries in a directory sequentially by being called repeatedly.

For the first call, it returns the first directory entry, and does the next directory entry for the following
call.

If there is no next directory entry, this function returns NULL.
\par Example:
An example of calling this function is shown below:

\code
	desc = dlnaFileSystemOpenDirPeer (in_full_path);
	if (! desc)
	{
		return slim_false;
		while ((dirent = dlnaFileSystemReadDirPeer (desc))) {
		slim_char *name;
		// Name of the file or directory.
		name = dlnaFileSystemDirentNamePeer (dirent);
		if (!name)
		{
			continue;
		}
	}
	dlnaFileSystemCloseDirPeer (desc);
  }
\endcode

*/
dlna_dirent
dlnaFileSystemReadDirPeer(dlna_dir_t in_desc);

/*!
\par Function:
Gets directory or file name.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_dirent</td>
		<td>Directory entry</td>
	</tr>
</table>

\return != slim_nil Directory or file name of the directory entry
\return == slim_nil Failed in getting directory or file name
\par Description:
This function returns the directory name or file name of the directory entry obtained by
dlnaFileSystemReadDirPeer().

The memory area that stores directory and file names must be retained until the next entry is obtained
by dlnaFileSystemReadDirPeer() or until dlnaFileSystemCloseDirPeer() is called.
*/
slim_char *
dlnaFileSystemDirentNamePeer(dlna_dirent in_dirent);

/*!
\par Function:

\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_path</td>
		<td>path with file on filesystem which we want check</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_size</td>
		<td>avaliable space on filesystem</td>
	</tr>
</table>
\return slim_int error value
\par Return Values:
<table>
	<tr>
		<td> \b 0</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td> -1 </td>
		<td> Fail</td>
	</tr>
</table>
\par Description:
Function gets availible space on filesystem on which in_path is located
*/

slim_int
dlnaFileSystemGetAvailSpacePeer(slim_char *in_path, dlna_uint64 *out_size);

/*@}*/

/**
 * @addtogroup structures
 */
/*@{*/

struct dlna_stat_
{
  /* File mode.  */
  slim_word mode;

  /* Total size of the file.  */
  dlna_uint64 size;

  /* Time of last modification time.  */
  dlna_time_t mtime;
  /* Creation time.  */
   dlna_time_t ctime;
};
/*!
dlna_stat is the structure that stores file state.
\code
struct _dlna_stat {

	slim_word mode;
	dlna_uint64 size;
	dlna_time_t mtime;
	dlna_time_t ctime;
};
typedef struct _dlna_stat dlna_stat;
\endcode
\par Member:

<table>
	<tr>
		<td>mode</td>
		<td>File mode</td>
	</tr>
	<tr>
		<td>size</td>
		<td>File length (bytes)</td>
	</tr>
	<tr>
		<td>mtime</td>
		<td>File update time (seconds since 01 January, 1970 UTC)</td>
	</tr>
	<tr>
		<td>ctime</td>
		<td>File creation / metadata change and content change time (seconds since 01January, 1970 UTC)</td>
	</tr>
</table>

\note
The value set for mode, depends on the target system. At a minimum, the parameter for determining
whether file attribute is for a directory or a normal file needs to be set.
*/
typedef struct dlna_stat_ dlna_stat;

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Gets file state.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_path</td>
		<td>Path to the file for getting state</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_stat</td>
		<td>Pointer to structure that retains file state</td>
	</tr>
</table>

\return 0 Succeeded
\return -1 Failed
\par Description:
This function gets the current file state and stores it in out_stat.
*/
slim_int
dlnaFileSystemStatPeer(const slim_char *in_path, dlna_stat *out_stat);

slim_bool
dlnaFileSystemAccessPeer (const slim_char * in_path, slim_int in_type);

/*!
\par Function:
Checks if file system is FAT based.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_path</td>
		<td>Absolute path to file system</td>
	</tr>
</table>

\return slim_true Filesystem is FAT
\return slim_false Filesystem is nonFat
\par Description:
This function checks if file system specified by in_path is FAT16 or FAT32. It returns slim_true if it is
FAT based, otherwise slim_false.
*/
slim_bool
dlnaFileSystemMSDOS (slim_char *in_path);

/*@}*/

/**
 * @addtogroup structures
 */
/*@{*/

/* Time API.  */
struct dlna_timeval_
{
  slim_word tv_sec;
  slim_word tv_usec;
};

#define DLNA_TIMEVAL_INIT { 0, 0 }

/*!
dlna_timeval is the structure that stores time information. Coordinated Universal Time (UTC) is
always stored. Setting a date that is prior to January 1, 1970 UTC is not requested from the API.
\code
struct _dlna_timeval {

slim_word tv_sec;
slim_word tv_usec;

};
typedef struct _dlna_timeval dlna_timeval;
\endcode
\par Member:

<table>
	<tr>
		<td>tv_sec</td>
		<td>Seconds since 01 January, 1970 UTC</td>
	</tr>
	<tr>
		<td>tv_usec</td>
		<td>Microsecods</td>
	</tr>
</table>
*/
typedef struct dlna_timeval_ dlna_timeval;

struct dlna_tm_
{
  slim_int sec;
  slim_int min;
  slim_int hour;
  slim_int mday;
  slim_int mon;
  slim_int year;
  slim_int wday;
  slim_int yday;
  slim_int isdst;
};

/*!
dlna_tm_t is the structure that stores date and time information.

\code
struct dlna_tm_
{
  slim_int year;
  slim_int mon;
  slim_int mday;
  slim_int wday;
  slim_int yday;
  slim_int hour;
  slim_int min;
  slim_int sec;
  slim_int isdst;
};
typedef struct dlna_tm_ dlna_tm_t;

\endcode
\par Member:

<table>
	<tr>
		<td>year</td>
		<td>Anno Domini year (0 or lower value means year before Christ) </td>
	</tr>
	<tr>
		<td>mon</td>
		<td>Months since January (0-11)</td>
	</tr>
	<tr>
		<td>mday</td>
		<td>Date (1-28, 29, 30, 31)</td>
	</tr>
	<tr>
		<td>wday</td>
		<td>Days since Sunday (0-6)</td>
	</tr>
	<tr>
		<td>yday</td>
		<td>Days since January 1 (0-364, 365)</td>
	</tr>
	<tr>
		<td>hour</td>
		<td>Hours since midnight (0-23)</td>
	</tr>
	<tr>
		<td>min</td>
		<td>Minutes after the hour (0-59)</td>
	</tr>
	<tr>
		<td>sec</td>
		<td>Seconds after the minute (0-59)</td>
	</tr>
	<tr>
		<td>isdst</td>
		<td>The Daylight Saving Time flag. Greater than zero - is in effect. Equals zero - not in effect. Less than zero - no information available.</td>
	</tr>
</table>

*/
typedef struct dlna_tm_ dlna_tm_t;

struct dlna_date_
{
  slim_int year;
  slim_int mon;
  slim_int mday;
  slim_int wday;
  slim_int yday;
  slim_int hour;
  slim_int min;
  slim_int sec;
  slim_int msec;
};

/*!
dlna_date is the structure that stores date and time information. This stores Coordinated Universal
Time (UTC) or regional standard time.

\code
struct _dlna_date {

	slim_int year;
	slim_int mon;
	slim_int mday;
	slim_int wday;
	slim_int yday;
	slim_int hour;

	slim_int min;
	slim_int sec;
	slim_int msec;
};
typedef struct _dlna_date dlna_date;

\endcode
\par Member:

<table>
	<tr>
		<td>year</td>
		<td>Anno Domini year (0 or lower value means year before Christ) </td>
	</tr>
	<tr>
		<td>mon</td>
		<td>Months since January (0-11)</td>
	</tr>
	<tr>
		<td>mday</td>
		<td>Date (1-28, 29, 30, 31)</td>
	</tr>
	<tr>
		<td>wday</td>
		<td>Days since Sunday (0-6)</td>
	</tr>
	<tr>
		<td>yday</td>
		<td>Days since January 1 (0-364, 365)</td>
	</tr>
	<tr>
		<td>hour</td>
		<td>Hours since midnight (0-23)</td>
	</tr>
	<tr>
		<td>min</td>
		<td>Minutes after the hour (0-59)</td>
	</tr>
	<tr>
		<td>sec</td>
		<td>Seconds after the minute (0-59)</td>
	</tr>
	<tr>
		<td>msec</td>
		<td>Milliseconds after the second (0-999)</td>
	</tr>
</table>

*/
typedef struct dlna_date_ dlna_date;

struct dlna_duration_
{
  slim_bool is_negative;
  slim_word hour; /*hour */
  slim_char min;  /*minute, 0-59*/
  slim_char sec;  /*second, 0-59*/
  slim_half msec; /*micro second, 0-999*/
};

/*!
dlna_duration is the structure that stores duration information.


\par Member:

<table>
	<tr>
		<td>is_negative</td>
		<td>value is negative or not<br/>
			slim_true value is negative<br/>
			slim_false value is positive
		</td>
	</tr>
	<tr>
		<td>hour</td>
		<td>hour</td>
	</tr>
	<tr>
		<td>min</td>
		<td>minute</td>
	</tr>
	<tr>
		<td>sec</td>
		<td>second</td>
	</tr>
	<tr>
		<td>msec</td>
		<td>micro second</td>
	</tr>
</table>

*/
typedef struct dlna_duration_ dlna_duration;

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Converts dlna_time_t to local time using dlna_tm_t representation.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_time</td>
		<td>Pointer to dlna_time_t type</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_tm</td>
		<td>Pointer to dlna_tm_t type</td>
	</tr>
</table>

\return None
\par Description:
This function uses dlna_time_t to fill dlna_tm_t structure with local time values.
*/
void
dlna_time_localtime (const dlna_time_t *in_time, dlna_tm_t *out_tm );

/*!
\par Function:
Converts dlna_tm_t to readable string.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_tm</td>
		<td>Pointer to dlna_tm_t type</td>
	</tr>
</table>

\return slim_char* type pointer to date and time in a readable string format.
\par Description:
This function takes pointer to dlna_tm_t structure and returns pointer to string
representation of date and time in the following format: Www Mmm dd hh:mm:ss yyyy
*/
slim_char*
dlna_time_asctime (const dlna_tm_t *in_tm );

/*!
\par Function:
Gets current time in seconds.
\par Parameters:

<table>
	<tr>
		<td>[out]</td>
		<td>out_time</td>
		<td>Pointer to dlna_time_t type current time</td>
	</tr>
</table>

\return dlna_time_t type current time
\par Description:
This function gets the current time in seconds and returns it as a return value.

If out_time is not slim_nil, it also stores the same current time as the return value in out_time.

The current time will be measured by seconds since January 1, 1970, 00:00:00AM Greenwich Mean
Time (GMT).
*/
dlna_time_t
dlna_time_currenttime(dlna_time_t *out_time);

/*!
\par Function:
Converts dlna_time_t type to dlna_date type UTC standard time.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_time</td>
		<td>Pointer to dlna_time_t type</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_date</td>
		<td>Pointer to dlna_date type</td>
	</tr>
</table>

\return None
\par Description:
This function converts in_time (seconds since January 1, 1970 UTC) to the dlna_date type in UTC
standard time and stores it in out_date.
*/
void
dlna_time_utcdate(dlna_time_t *in_time, dlna_date *out_date);

/*!
\par Function:
Converts dlna_time_t type to dlna_date type Local time.
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>in_time</td>
                <td>Pointer to dlna_time_t type</td>
        </tr>
        <tr>
                <td>[out]</td>
                <td>out_date</td>
                <td>Pointer to dlna_date type</td>
        </tr>
</table>

\return None
\par Description:
This function converts in_time (seconds since January 1, 1970 UTC) to the dlna_date type in Local
standard time and stores it in out_date.
*/
void
dlna_time_localdate(dlna_time_t *in_time, dlna_date *out_date);

/*!
\par Function:
Generates formatted string from dlna_date type.
\par Parameters:

<table>
	<tr>
		<td>[out]</td>
		<td>out_s</td>
		<td>Pointer to buffer that stores conversion result</td>
	</tr>
</table>
<br />
<table>
	<tr>
		<td>[in]</td>
		<td>in_maxsize</td>
		<td>Maximum length of out_s (bytes)</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_format</td>
		<td>Format to convert<br/>

		\%a Abbreviated day of week (Sun, Mon, ...)

		\%A Day of week (Sunday, Monday, ...)

		\%b Abbreviated month (Jan, Feb, ...)

		\%B Month (January, February)

		\%d Date in month (decimal number) (1-28, 29, 30, 31)

		\%E Year expressed in Common era (Decimal number. Adds B.C. for year before Common era)

		\%F Millisecond (decimal number) (0-999)

		\%H Time expressed in 24 hours (decimal number) (0-23)

		\%I Time expressed in 12 hours (decimal number) (1-12)

		\%j Date in year (decimal number) (0-364, 365)

		\%m Month (decimal number) (1-12)

		\%M Minute (0-59)

		\%p AM or PM determined from given time

		\%S Second (0-59)

		\%w Day of week (decimal number starting from 0, which is Sunday)(0-6)

		\%y Year expressed in last 2 digits of Common era (decimal number) (00-99)

		\%Y Year expressed in 4 digits of Common era (decimal number)

		\%Z Time zone offset (decimal number)

		\%\% Character that represents "%"</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_date</td>
		<td>Pointer to dlna_date type date data of string to convert</td>
	</tr>
</table>

\return >0 Length of conversion result string (in bytes, excluding NULL terminator)
\return 0 Insufficient buffer or in_format is invalid
\par Description:
This function converts the dlna_date type date information specified for in_date to the format
specified for in_format, and returns the length (in bytes, excluding the NULL terminator) as a return
value.

If the conversion is successful, this function stores the conversion result in out_s. It returns 0 if the out_s
buffer size is not sufficient or in_format is invalid.

If slim_nil is specified for out_s, the function does not store the result but returns number of bytes of
the conversion result.

If "#" is added to formats when specifying them as shown below, this function returns the conversion
result, deleting leading 0s.

\%\#d

\%\#F

\%\#H

\%\#I

\%\#m

\%\#M

\%\#S

\%\#y

It ignores "#" added to formats other than the above.

\par Example:
Example of in_format and out_s when in_date is Wednesday, August 10, 2005, 01:02:03AM, in the Linux
socket or Windows® socket is shown below.

- in_format \code %a, %d %b %H:%M:%S GMT%Z \endcode
- out_s \code Wed, 10 Aug 2005 01:02:03 GMT+0900 \endcode

*/
slim_int
dlna_time_format(slim_char *out_s, slim_int in_maxsize, slim_char *in_format,
                 dlna_date *in_date);

/*!
\par Function:
Gets current time in microseconds.
\par Parameters:

<table>
	<tr>
		<td>[out]</td>
		<td>out_timeval</td>
		<td>Pointer to dlna_timeval type current time</td>
	</tr>
</table>

\return None
\par Description:
This function obtains the current time in microseconds and stores it in out_timeval.

If the target system cannot return the dlna_timeval value in microseconds, it can be supported by
setting the field for microseconds, tv_usec, to 0.

However, it is best to ensure the accuracy of milliseconds as described in "3.1.5 Elapsed Time
Acquisition Function".
*/
void
dlna_timeval_get(dlna_timeval *out_timeval);

/*!
\par Function:
Function reads time from par_datetime and store it into a par_out_time regarding specfied format for example to read yyyy.mm.dd hh.mm.ss date format should looks like "%d:%d:%d %d:%d:%d".
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>par_datetime</td>
		<td>string with date time</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>par_format</td>
		<td>format of time stored in datetime string</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>par_out_time</td>
		<td>structure where time can be stored</td>
	</tr>
</table>
\return slim_bool value
\par Return Values:
<table>
	<tr>
		<td> \b slim_true </td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td> slim_false </td>
		<td> Fail</td>
	</tr>
</table>
*/

slim_bool
dlna_time_mktime( const slim_char *par_datetime, const slim_char* par_format, dlna_time_t *par_out_time );

/*!
\par Function:
Function to retreive the current date
\par Parameters:
<table>
	<tr>
		<td>[out]</td>
		<td>out_year</td>
		<td></td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_mon</td>
		<td></td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_mday</td>
		<td></td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_hour</td>
		<td></td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_min</td>
		<td></td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_sec</td>
		<td></td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_msec</td>
		<td></td>
	</tr>
</table>
\return slim_bool value
\par Return Values:
<table>
	<tr>
		<td> \b SLIM_E_OK </td>
		<td> \b Success</td>
	</tr>
</table>
\par Description:
This function returns in the current Date in Years, Months, Day, Hours, Minutes, Seconds and Milliseconds
*/

slim_int
dlnaGetCurrentDatePeer(slim_int *out_year, slim_int *out_mon, slim_int *out_mday,
                slim_int *out_hour, slim_int *out_min, slim_int *out_sec, slim_int *out_msec);


/*!
\par Function:
Gets current date in dlna_date structure.
\par Parameters:

<table>
        <tr>
                <td>[out]</td>
                <td>out_date</td>
                <td>Pointer to dlna_date type current date</td>
        </tr>
</table>

\return None
\par Description:
This function obtains the current date and stores it in dlna_date. Advantage is the availability of milliseconds.
*/
void
dlnaGetCurrentDlnaDate(dlna_date *out_date);

/*!
\par Function:
Gets current date in dlna_date structure from dlna_timeval input.
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>in_timeval</td>
                <td>Pointer to dlna_timeval type representing time to be converted</td>
        </tr>
        <tr>
                <td>[out]</td>
                <td>out_date</td>
                <td>Pointer to dlna_date type representing date</td>
        </tr>
</table>

\return None
\par Description:
This function converts dlna_timeval to the date and stores it in out_date. Advantage is the availability of milliseconds.
*/
void
dlnaGetDlnaDate(dlna_timeval *in_timeval, dlna_date *out_date);

/* Random APIs. */

/*!
\par Function:
Sets random number series obtained by dlna_random().
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_seed</td>
		<td>Value to use for generating random number</td>
	</tr>
</table>

\return None
\par Description:
This function sets the value (seed) needed for generating a random number.
*/
void
dlna_set_random_seed(slim_int in_seed);

/*!
\par Function:
Gets random value.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_n</td>
		<td>Range of random numbers to generate</td>
	</tr>
</table>

\return Random value between 0 and in_n-1
\par Description:
This function returns a random value between 0 and in_n-1.
*/
slim_word
dlna_random(slim_word in_n);

/*!
\par Function:
Outputs information (with linefeeds).
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>format</td>
		<td>Format string (C string)<br/> Conforms to printf() function</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>... (argument list)</td>
		<td>Output data</td>
	</tr>
</table>

\return None
\par Description:
This function outputs information with linefeeds.

The actual output device depends on the target system.
*/
void
dlna_printf(const char *format, ...);

/*!
\par Function:
Outputs one character.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>character</td>
		<td>Output data</td>
	</tr>
</table>

\return
If there are no errors, the same character that has been written is returned.
If an error occurs, EOF is returned and the error indicator is set.
\par Description:
This function outputs one character.

The actual output device depends on the target system.
*/
slim_int
dlna_putchar(slim_int character);

/*!
\par Function:
Inputs one character.
\par Parameters: none
\return
The character read is returned as an int value.
If the End Of File is reached or a reading error happens, the function returns EOF.
\par Description:
Returns the next character from the standard input (stdin).

The actual intput device depends on the target system.
*/
slim_int
dlna_getchar( void );



/* Network APIs.  */

/**
 * @addtogroup enums
 */
/*@{*/

/*! DLNA IPv4 and IPv6 types.  */
enum  {
  DLNA_IP_ADDR_TYPE_V4,
  DLNA_IP_ADDR_TYPE_V6
};

/*@}*/

/**
 * @addtogroup structures
 */
/*@{*/

/*! DLNA IP address.  */
struct dlna_ip_addr_
{
  /* Interface protocol version.  */
  slim_int fType;

  /* Address.  */
  slim_byte fAddr[4];
};
/*!
dlna_duration is the structure that stores duration information.

\code
struct _dlna_ip_addr {
slim_int fType;
slim_byte fAddr[4];
};
typedef struct _dlna_ip_addr dlna_ip_addr;
\endcode
\par Member:

<table>
	<tr>
		<td>fType</td>
		<td>Internet protocol version<br/>
			DLNA_IP_ADDR_TYPE_V4 IPv4<br/>
			DLNA_IP_ADDR_TYPE_V6 IPv6
		</td>
	</tr>
	<tr>
		<td>fAddr</td>
		<td>IP Address(big endian)<br/>
			Stores 8-bit boundary value from fAddr[0].
		</td>
	</tr>
</table>

*/
typedef struct dlna_ip_addr_ dlna_ip_addr;

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/* DLNA Network API.  */
/*!
\par Function:
Sets socket option for DLNAQoS.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>sock</td>
		<td>TCP connection descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>priority</td>
		<td>DLNAQoS priority value
			DLNAQOS_3 (7) : Highest priority
			DLNAQOS_2 (5)
			DLNAQOS_1 (0)
			DLNAQOS_0 (1) : Lowest priority</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\par Description:
This function sets socket options for DLNAQoS.

The NFLC only calls DLNAQOS_0, DLNAQOS_1 or DLNAQOS_2 as the priority value. The DLNAQOS_3 is
not used currently.

This value is set in the SO_PRIORITY socket option of the TCP connection and also set in the Type of
Service (TOS) field in the IPv4 header.

For more information about the DLNAQoS specification, see "DLNA Networked Device Interoperability
Guidelines".

For more information about the implementation, see the sample code.
*/
slim_int
dlnaSockSetPriority (slim_int sock, slim_int priority);

/*!
\par Function:
Initializes network function.
\par Parameters:
none
\return SLIM_E_OK Succeeded
\par Description:
This function initializes the network functions of NFLC.

The NFLC core calls this function at startup to initialize network functions.
*/
slim_int
dlnaNetInitializePeer(void);

/*!
\par Function:
Finalizes network functions.
\par Parameters:
none
\return SLIM_E_OK Succeeded
\par Description:
This function finalizes the network function of NFLC.
*/
slim_int
dlnaNetFinalizePeer(void);

/*!
\par Function:
Opens TCP protocol endpoint.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_domain</td>
		<td>Internet protocol version<br/>
			DLNA_IP_ADDR_TYPE_V4 IPv4<br/>
			DLNA_IP_ADDR_TYPE_V6 IPv6</td>
	</tr>
</table>

\return TCP connection descriptor. If an error occurred, -1 is returned.
\par Description:
This function allocates a TCP connection endpoint, then returns the descriptor. It allocates an endpoint
on the TCP client.

The returned descriptor is used as an API argument later for reading and/or writing data.
Since network operation APIs need to run in non-blocking mode, this function specifies the setting for
that.

If IPv6 is not supported on the target system, the function must return -1 when
DLNA_IP_ADDR_TYPE_V6 is specified for in_domain.
*/
slim_int
dlnaTCPOpenPeer(slim_int in_domain);

/*!
\par Function:
Opens server side TCP connection endpoint.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_domain</td>
		<td>Internet protocol version<br/>
			DLNA_IP_ADDR_TYPE_V4 IPv4<br/>
			DLNA_IP_ADDR_TYPE_V6 IPv6</td>
	</tr>
</table>

\return TCP connection descriptor. If an error occurred, -1 is returned.
\par Description:
This function allocates a TCP server-side connection endpoint, then returns the descriptor.

The returned descriptor is used as an API argument later for reading and/or writing data.

Since network operation APIs need to run in non-blocking mode, this function specifies the setting for
that.

If IPv6 is not supported on the target system, the function must return -1 when
DLNA_IP_ADDR_TYPE_V6 is specified for in_domain.

Since messages are sometimes sent to a broadcast address, the setting to allow transmission to the
broadcast address needs to be specified using this function.

If error (-1) is returned as return value, HTTP session does not start.
*/
slim_int
dlnaTCPServerOpenPeer(slim_int in_domain);

/*!
\par Function:
Terminates TCP connection.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>Descriptior of TCP connection</td>
	</tr>
</table>

\return None
\par Description:
This function terminates the TCP connection, then releases all associated data.

The TCP close process must be completed within this function.
*/
void
dlnaTCPClosePeer(slim_int in_desc);

/*!
\par Function:
Checks whether TCP connection is established or not.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>Descriptior of TCP connection</td>
	</tr>
</table>

\return 1 Connection is established
\return 0 Connection is not established
\return SLIM_E_GENERIC Error
\par Description:
This function checks whether a TCP connection has been established by dlnaTCPConnectPeer().
*/
slim_int
dlnaTCPIsConnectedPeer(slim_int in_desc);

/*!
\par Function:
Connects to specified IP address and port.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>Descriptior of TCP connection</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_addr</td>
		<td>IP address of destination host</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_port</td>
		<td>Port number of destination host</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\return SLIM_E_WOULDBLOCK Unable to establish connection immediately
\par Description:
This function establishes a TCP connection to the specified IP address and port.

If the TCP connection is not established immediately, it returns SLIM_E_WOULDBLOCK. When
SLIM_E_WOULDBLOCK is returned, NFLC core internally adds a function to call
dlnaTCPIsConnectedPeer() to the event queue. dlnaTCPIsConnectedPeer() is called by the
event manager, which separately checks whether a TCP connection has been established.
*/
slim_int
dlnaTCPConnectPeer(slim_int in_desc, dlna_ip_addr *in_addr, slim_int in_port);

/*!
\par Function:
Reads from TCP connection.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>Descriptior of TCP connection</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_buf</td>
		<td>Pointer to buffer that stores read data</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_len</td>
		<td>Read length(bytes)</td>
	</tr>
</table>

\return >0 Succeeded
\return 0 Received FIN
\return SLIM_E_GENERIC Failed
\return SLIM_E_WOULDBLOCK Unable to immediately read data
\par Description:
This function reads in_len bytes data from the TCP connection specified for in_desc, then writes it to
out_buf.

If the reading process succeeds, it returns the number of bytes read.

If the number of bytes read is less than in_len, this function is consecutively called from the NFLC core.
When the length of the return value reaches in_len, NFLC core determines that reading is completed.

If SLIM_E_GENERIC is returned, NFLC core executes error processing.

If SLIM_E_WOULDBLOCK is returned, NFLC core calls this function again after receiving data.
*/
slim_int
dlnaTCPReadPeer(slim_int in_desc, slim_byte *out_buf, slim_int in_len);

/*!
\par Function:
Writes to TCP connection.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>Descriptior of TCP connection</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_buf</td>
		<td>Pointer to buffer that stores data to write</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_len</td>
		<td>Write length(bytes)</td>
	</tr>
</table>

\return >0 Succeeded
\return SLIM_E_GENERIC Failed
\return SLIM_E_WOULDBLOCK Unable to immediately write data
\par Description:
This function reads in_len bytes data from the buffer specified for in_buf, then writes it to the TCP
connection specified for in_desc.

If the writing process succeeds, it returns the number of bytes written.

If the number of bytes written is less than in_len, this function is consecutively called from the NFLC
core. When the length of the return value reaches in_len, NFLC core determines that writing is
completed.

If SLIM_E_GENERIC is returned, NFLC core executes error processing.

If SLIM_E_WOULDBLOCK is returned, NFLC core calls this function again when it is ready for
transmission.
*/
slim_int
dlnaTCPWritePeer(slim_int in_desc, slim_byte *in_buf, slim_int in_len);

/*!
\par Function:
Binds TCP connection to specified local IP address and port.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>Descriptior of TCP connection</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_addr</td>
		<td>Local IP address</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_port</td>
		<td>Port number which accepts remote connection</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\par Description:
This function binds the TCP connection to the specified local IP address and port.

If SLIM_E_GENERIC is returned, dlnaTCPClosePeer() is called from the NFLC core and the TCP
connection terminates.
*/
slim_int
dlnaTCPBindPeer(slim_int in_desc, dlna_ip_addr *in_addr, slim_int in_port);

/*!
\par Function:
Listens to TCP.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>Descriptior of TCP connection</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_queuelen</td>
		<td>Queue length which holds connection requests</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\par Description:
This function listens to the TCP connection.

The maximum queue length for connection requests is specified by in_queuelen.

If SLIM_E_GENERIC is returned, dlnaTCPClosePeer() is called from the NFLC core and the TCP
connection terminates.

This function is never re-tried from the NFLC core.
*/
slim_int
dlnaTCPListenPeer(slim_int in_desc, slim_int in_queuelen);

/*!
\par Function:
Accepts TCP connection request.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>Descriptior of TCP connection</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_addr</td>
		<td>IP Address of remote host</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_port</td>
		<td>Port number of remote host</td>
	</tr>
</table>

\return >=0 Descriptor of accepted TCP connection
\return <0 Failed
\par Description:
This function accepts a TCP connection request.

The IP address and port number of the remote host are stored in out_addr and out_port respectively.

If it successfully accepts a TCP connection request, it returns the descriptor of the accepted TNP
connection.

Since network operation APIs need to run in non-blocking mode, this function specifies the setting for
that.

This function is called when the communication partner requests TCP connection.

Even if a negative value is returned, the NFLC core waits for the next TCP connection request.
*/
slim_int
dlnaTCPAcceptPeer(slim_int in_desc, dlna_ip_addr *out_addr,
                  slim_int *out_port);

/*!
\par Function:
Gets local IP address and port number of TCP connection.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>Descriptior of TCP connection</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_addr</td>
		<td>Local IP Address</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_port</td>
		<td>Local Port number</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\par Description:
This function stores the local IP address and port number of the TCP connection in out_addr and
out_port respectively.
*/
slim_int
dlnaTCPGetLocalAddrPortPeer(slim_int in_desc, dlna_ip_addr *out_addr,
                            slim_int *out_port);

/*!
\par Function:
Gets remote IP address and port number of TCP connection.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>Descriptior of TCP connection</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_addr</td>
		<td>Remote IP Address</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_port</td>
		<td>Remote Port number</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\par Description:
This function stores the IP address and port number of the TCP connection destination in out_addr and
out_port respectively.
*/
slim_int
dlnaTCPGetRemoteAddrPortPeer(slim_int in_desc, dlna_ip_addr *out_addr,
                             slim_int *out_port);

/*!
\par Function:
Gets IP address corresponding to specified host name.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>Host name string</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_addr</td>
		<td>IP Address</td>
	</tr>
</table>

\return 1 Succeeded
\return 0 Failed
\par Description:
This function stores the IP address corresponding to the specified host name, in out_addr.
*/
slim_int
dlnaTCPGetHostByNamePeer (slim_char *in_desc, dlna_ip_addr *out_addr);

/*!
\par Function:
 checks to see if any sockets are ready for reading/writing or have an exeptional condition pending.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>sock</td>
		<td>socket descriptor</td>
	</tr>
</table>
\return slim_int error code
\par Return Values:
<table>
	<tr>
		<td> \b >0</td>
		<td> <b>Number of ready descriptor</b></td>
	</tr>
	<tr>
		<td>-1</td>
		<td>error occured</td>
	</tr>
</table>
\par Description:
Check the first NFDS descriptors each in READFDS (if not NULL) for read
   readiness, in WRITEFDS (if not NULL) for write readiness, and in EXCEPTFDS
   (if not NULL) for exceptional conditions.  If TIMEOUT is not NULL, time out
   after waiting the interval specified therein.  Returns the number of ready
   descriptors, or -1 for errors.
*/
slim_int
dlnaTCPSelectPeer(slim_int sock);

/*
* Peer api's added to support blocking I/O 
*/

slim_int
dlnaTCPOpenExPeer (slim_int in_domain, slim_int blocking) ;

slim_int
dlnaTCPServerOpenExPeer (slim_int in_domain, slim_int blocking) ;

slim_int
dlnaTCPAcceptExPeer (slim_int in_desc, dlna_ip_addr * out_addr, slim_int * out_port, slim_int blocking) ;

slim_int
dlnaTCPShutdownPeer (slim_int in_desc, slim_int in_how) ;

slim_int
dlnaGetErrnoPeer (void) ;


/*!
\par Function:
Allocates UDP connection.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_domain</td>
		<td>Internet protocol version<br/>
			DLNA_IP_ADDR_TYPE_V4 IPv4<br/>
			DLNA_IP_ADDR_TYPE_V6 IPv6</td>
	</tr>
</table>

\return >=0 Descriptor which represents UDP connection
\return -1 Error occurred
\par Description:
This function allocates a connection for UDP protocol communication, then returns the descriptor.

The returned descriptor is used as an API argument later for reading and/or writing data.

Since network operation APIs need to run in non-blocking mode, this function specifies the setting for
that.

If an error (-1) is returned, the NFLC core does not retry this function.

If IPv6 is not supported on the target system, the function must return -1 when
DLNA_IP_ADDR_TYPE_V6 is specified for in_domain.
*/
slim_int
dlnaUDPOpenPeer(slim_int in_domain);

/*!
\par Function:
Terminates UDP connection.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>Descriptor of UDP connection</td>
	</tr>
</table>

\return None
\par Description:
This function terminates a UDP connection, then releases all the associated data.

The UDP closing process must be completed within this function.
*/
void
dlnaUDPClosePeer(slim_int in_desc);

/*!
\par Function:
Sends data using UDP connection.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>UDP connection descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_buf</td>
		<td>Pointer to data buffer</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_len</td>
		<td>Send length (bytes)</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_addr</td>
		<td>IP Address of remote host</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_port</td>
		<td>Port number of remote host</td>
	</tr>
</table>

\return >=0 Succeeded (sent data length)
\return SLIM_E_GENERIC Failed
\par Description:
This function sends data to remote host specified by ip_addr and in_port via UDP.

The data to send and its length are specified for in_buf and in_len respectively.

If SLIM_E_GENERIC is returned, the NFLC core executes error processing.

If the number of written bytes is less than in_len, this function is consecutively called from the NFLC
core.
*/
slim_int
dlnaUDPSendToPeer(slim_int in_desc, void *in_buf, slim_int in_len,
                  dlna_ip_addr *in_addr, slim_int in_port);

/*!
\par Function:
Sends data using UDP connection.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>UDP connection descriptor</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_buf</td>
		<td>Pointer to data buffer</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_len</td>
		<td>Receive length (bytes)</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_addr</td>
		<td>IP Address of remote host</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_port</td>
		<td>Port number of remote host</td>
	</tr>
</table>

\return >=0 Succeeded (sent data length)
\return SLIM_E_GENERIC Failed
\par Description:
This function receives data via UDP then stores the received data in out_buf.

The maximum size of receive buffer is set for in_len.

The IP address and port number of the remote host (sender of data) are stored in out_addr and out_port
respectively.

If SLIM_E_GENERIC is returned, the NFLC core executes error processing.

If the number of received bytes is less than in_len, this function is consecutively called from the NFLC
core. When the length of return value reaches in_len, the NFLC core determines that receiving is
completed.
*/
slim_int
dlnaUDPRecvFromPeer(slim_int in_desc, void *out_buf, slim_int in_len,
                    dlna_ip_addr *out_addr, slim_int *out_port);

/*!
\par Function:
Binds UDP connection to specified local IP address and port.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>UDP connection descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_addr</td>
		<td>Local IP address</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_port</td>
		<td>Port number which accepts remote connection</td>
	</tr>
</table>

\return SLIME_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\par Description:
This function binds a UDP connection to the specified local IP address and port.

If SLIM_E_GENERIC is returned, dlnaUDPClosePeer() is called from the NFLC core and the UDP
connection terminates.
*/
slim_int
dlnaUDPBindPeer(slim_int in_desc, dlna_ip_addr *in_addr, slim_int in_port);

/*@}*/

/**
 * @addtogroup enums
 */
/*@{*/

enum {
    DLNA_UDP_OP_MULTICAST_TTL
};

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Sets UDP option.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>UDP connection descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_opt</td>
		<td>UDP option to set<br/>
			DLNA_UDP_OP_MULTICAST_TTL Multicast TTL</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_value</td>
		<td>Value of UDP option(4)</td>
	</tr>
</table>

\return SLIME_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\par Description:
This function sets a UDP option.

In NFLC, 4 is specified for in_value.

This function is used in NFLC to specify the in_value value as the time to live (TTL) for the multicast
datagram to be sent.
*/
slim_int
dlnaUDPSetOptionPeer(slim_int in_desc, slim_int in_opt, slim_int in_value);

/* DLNA multicast related API.  */

/*!
\par Function:
Enables and binds multicast communication to specified interface.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>UDP connection descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_ifaddr</td>
		<td>Interface IP address</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_ifindex</td>
		<td>Value that identifies interface</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\par Description:
This function enables multicast communication for UDP communication and binds it to the specified
interface.

The NFLC core sets the value obtained using the network interface manager for in_ifindex.

When the in_ifindex value is other than 0, the value is used to specify the interface.

When the in_ifindex value is 0, in_ifaddr is used to specify the interface.

In the case of Linux/Windows sockets, this function is used to specify the output destination interface.
Interfaces can be specified using in_ifaddr as the key. If this function is not used, the multicast output
destination interface is determined based on the kernel routing table.
*/
slim_int
dlnaMulticastInterfacePeer(slim_int in_desc, dlna_ip_addr *in_ifaddr,
                           slim_int in_ifindex);
/*!
\par Function:
Joins multicast group on specified interface.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>UDP connection descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_maddr</td>
		<td>Multicast group address</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_ifaddr</td>
		<td>Interface IP address</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_ifindex</td>
		<td>Value that identifies interface</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\par Description:
This function joins the multicast group in_maddr on the interface that is specified by in_ifaddr or
in_ifindex.

The NFLC core sets the value obtained using the network interface manager for in_ifindex.

When the in_ifindex value is other than 0, the value is used to specify the interface.

When the in_ifindex value is 0, in_ifaddr is used to specify the interface.

This function is used to send an IGMP message that notifies the multicast router of participation in a
multicast group. The multicast router that receives this message forwards multicast packets to the
participating hosts.
*/
slim_int
dlnaMulticastJoinPeer(slim_int in_desc, dlna_ip_addr *in_maddr,
                      dlna_ip_addr *in_ifaddr, slim_int in_ifindex);
/*!
\par Function:
Withdraws from multicast group on specified interface.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>UDP connection descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_maddr</td>
		<td>Multicast group address</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_ifaddr</td>
		<td>Interface IP address</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_ifindex</td>
		<td>Value that identifies interface</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\par Description:
This function withdraws from the multicast group in_maddr on the interface that is specified by in_ifaddr
or in_ifindex.

The NFLC core sets the value obtained using the network interface manager for in_ifindex.

When the in_ifindex value is other than 0, the value is used to specify the interface.

When the in_ifindex value is 0, in_ifaddr is used to specify the interface.

This function is used to send an IGMP message that notifies the multicast router of withdrawal from a
multicast group.
*/
slim_int
dlnaMulticastLeavePeer(slim_int in_desc, dlna_ip_addr *in_maddr,
                       dlna_ip_addr *in_ifaddr, slim_int in_ifindex);

/* DLNA network utility API.  */

/*!
\par Function:
Converts IP address string to dlna_ip_addr structure.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_cp</td>
		<td>Pointer to IP address string</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_addr</td>
		<td>Pointer to dlna_ip_addr structure for which an IP address was set</td>
	</tr>
</table>

\return != slim_nil Succeeded
\return == slim_nil Failed
\par Description:
This function converts the IP address string of the specified Internet host, sets it in the dlna_ip_addr
structure, and stores it in out_addr.

The behavior of string conversion conforms to inet_aton() of the standard library.

This function references and writes to the memory area of in_cp and out_addr allocated on the caller
side.
*/
slim_int
dlna_inet_aton(slim_char *in_cp, dlna_ip_addr *out_addr);

/*!
\par Function:
Converts IP address of dlna_ip_addr structure to string expressed in dot-decimal notation.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_addr</td>
		<td>Pointer to dlna_ip_addr structure for which IP address was set</td>
	</tr>
</table>

\return String of IP address set for the dlna_ip_addr structure in dot-decimal notation expression (Example:192.168.1.1)
\par Description:
This function converts the IP address set for the dlna_ip_addr structure to a string expressed in
dot-decimal notation and returns it.

The behavior of string conversion conforms to inet_ntoa() of the standard library.

The function references the memory area of in_addr allocated on the caller side.
*/
slim_char *
dlna_inet_ntoa(dlna_ip_addr in_addr);

#define DLNA_INET4_ADDRSTRLEN 16 

slim_char *
dlna_inet_ntoa2 (dlna_ip_addr *in_addr, slim_char *in_buf, slim_int in_buf_len ) ;

/*!
\par Function:
Converts IP address of dlna_ip_addr structure to MAC address string.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_addr</td>
		<td>Pointer to dlna_ip_addr structure for which IP address was set</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_mac</td>
		<td>Pointer to MAC address string</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\par Description:
This function converts the IP address set for the dlna_ip_addr structure to an MAC address string
using ARP.

Unless the following functions are used, however, this function does not need to be implemented.

- DMS client authentication functions
- dlnaDmpDeviceMACAddress()
*/
slim_int
dlna_inet_iptomac(dlna_ip_addr *in_addr, slim_char *out_mac);
/*!
\par Function:
Converts network byte order to host byte order.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_netshort</td>
		<td>16-bit network byte order</td>
	</tr>
</table>

\return Host byte order of specified in_netshort
\par Description:
This function converts the network byte order specified for in_netshort to the host byte order.

The behavior of conversion conforms to ntohs() of the standard library.

The function references the memory area of in_netshort allocated on the caller side.
*/
slim_half
dlna_ntohs(slim_half in_netshort);

/*!
\par Function:
Looksup the interface name corresponding to ip address.
\par Parameters:

<table>
	<tr>
		<td>TBD</td>
		<td>TBD</td>
		<td>TBD</td>
	</tr>
</table>

\return TBD
\par Description:
TBD

*/
slim_int
dlna_inet_iptoifn (dlna_ip_addr * in_addr, slim_char * out_ifname,
                   slim_int buf_len);

/*@}*/

/* Progress API.  */

/**
 * @addtogroup datatypes
 */
/*@{*/

/*!
DLNA progress manager descriptor
*/
typedef void *dlna_progress;
/*!
DLNA progress handle descriptor.
*/
typedef void *dlna_progress_handle;

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
DLNA progress callback descriptor.

\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>in_arg specified using dlnaDCNAllocPeer()</td>
	</tr>
</table>

\return Not currently used
*/

typedef slim_int (*dlna_progress_callback) (void *in_arg);

/*!
DLNA progress I/O callback descriptor.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>in_desc specified using dlnaProgressReadAddPeer()</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>in_arg specified using dlnaProgressReadAddPeer()</td>
	</tr>
</table>

\return Not currently used
*/
typedef slim_int (*dlna_progress_io_callback) (slim_int in_desc, void *in_arg);

/*@}*/

/**
 * @addtogroup macros
 */
/*@{*/

#define DLNA_INVALID_PROGRESS_HANDLE ((dlna_progress_handle) 0)

/*@}*/

/**
 * @addtogroup enums
 */
/*@{*/

/*!
dlna_event_remove_mode represents the type of criteria that is used to find the event to be
removed.

<table>
	<tr>
		<td><b> Definition</b></td>
		<td><b> Event detailes</b></td>
	</tr>
	<tr>
		<td>DLNA_JUST_ARGUMENT</td>
		<td>Remove event with specific argument</td>
	</tr>
	<tr>
		<td>DLNA_JUST_CALLBACK</td>
		<td>Remove event with specific callback function</td>
	</tr>
	<tr>
		<td>DLNA_BOTH_ARGUMENT_AND_CALLBACK</td>
		<td>Remove event with specific argument and callback function</td>
	</tr>
</table>

*/
enum dlna_event_remove_mode {
  DLNA_JUST_ARGUMENT,
  DLNA_JUST_CALLBACK,
  DLNA_BOTH_ARGUMENT_AND_CALLBACK
};

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Allocates DLNA progress.
\par Parameters:
none
\return != slim_nil DLNA progress manager descriptor
\return == slim_nil Error occurred
\par Description:
This function allocates a DLNA progress and returns the progress manager descriptor.

The returned descriptor becomes an argument of APIs that are subsequently called.

This function is called during initialization.

The DLNA progress manager descriptor allocated by this function is used when generating instances of
DLNA device classes (DMS, DMP, DMR, DMC, and others).

Allocating multiple DLNA progresses for each DLNA device class is not allowed.
*/
dlna_progress
dlnaProgressAllocPeer(void);

/*!
\par Function:
Releases DLNA progress.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_p</td>
		<td>DLNA progress manager descriptor</td>
	</tr>
</table>

\return None
\par Description:
This function releases the DLNA progress.

This function is called during finalization of each DLNA device class.

*/
void
dlnaProgressFreePeer(dlna_progress in_p);

/*!
\par Function:
Starts DLNA progress.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_p</td>
		<td>DLNA progress manager descriptor</td>
	</tr>
</table>

\return None
This function starts up the DLNA progress.

Calling this function starts executing events registered by the following functions.

- dlnaProgressEventAddPeer()
- dlnaProgressReadAddPeer()
- dlnaProgressWriteAddPeer()
- dlnaProgressTimerAddPeer()

*/
void
dlnaProgressStartPeer(dlna_progress in_p);

/*!
\par Function:
Stops DLNA progress.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_p</td>
		<td>DLNA progress manager descriptor</td>
	</tr>
</table>

\return None
\par Description:
This function stops the DLNA progress.

Calling this function stops executing events registered by the following functions. Registered events are
discarded.

- dlnaProgressEventAddPeer()
- dlnaProgressReadAddPeer()
- dlnaProgressWriteAddPeer()
- dlnaProgressTimerAddPeer()

*/
void
dlnaProgressStopPeer(dlna_progress in_p);

/*!
\par Function:
Function locks progress manager.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_p</td>
		<td>progress manager instance</td>
	</tr>
</table>
\return slim_bool value
\par Return Values:
<table>
	<tr>
		<td> \b slim_true </td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td> slim_false </td>
		<td> Fail</td>
	</tr>
</table>
*/

slim_bool
dlnaEventManagerLockPeer (dlna_progress in_p);

/*!
\par Function:
Function unlocks progress manager.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_p</td>
		<td>progress manager instance</td>
	</tr>
</table>
\return slim_bool value
\par Return Values:
<table>
	<tr>
		<td> \b slim_true </td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td> slim_false </td>
		<td> Fail</td>
	</tr>
</table>
*/

slim_bool
dlnaEventManagerUnlockPeer (dlna_progress in_p);

/*!
\par Function:
Locks DLNA progress.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_p</td>
		<td>DLNA progress manager descriptor</td>
	</tr>
</table>

\return slim_true Succeeded
\par Description:
This function locks the DLNA progress.

The target system must support recursive locking.
*/
slim_bool
dlnaProgressLockPeer(dlna_progress in_p);

/*!
\par Function:
Unlocks DLNA progress.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_p</td>
		<td>DLNA progress manager descriptor</td>
	</tr>
</table>

\return slim_true Succeeded
\par Description:
This function unlocks the DLNA progress.

The target system must support recursive locking.
*/
slim_bool
dlnaProgressUnlockPeer(dlna_progress in_p);

/*!
\par Function:
Adds event to DLNA progress.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_p</td>
		<td>DLNA progress manager descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_func</td>
		<td>Event callback function</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument of in_func</td>
	</tr>
</table>

\return != slim_nil DLNA progress handle descriptor
\return == slim_nil Error occurred
\par Description:
This function registers the event callback function and its arguments with the DLNA progress.
*/
dlna_progress_handle
dlnaProgressEventAddPeer(dlna_progress in_p, dlna_progress_callback in_func,
                         void *in_arg);

/*!
\par Function:
Removes an event from event list based on given argument or callback function.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_p</td>
		<td>DLNA progress manager descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_func</td>
		<td>Callback function for event to be removed</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument for event to be removed</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_remove_mode</td>
		<td>Type of criteria that is used to find the event to be removed (see "5.2.8 dlna_event_remove_modedlna_event_remove_mode")</td>
	</tr>
</table>

\return None
\par Description:
This function searches an event in internal event list. If the event specified by in_arg and/or in_func exist
the event is removed from list.

If DLNA_JUST_ARGUMENT is specified for in_remove_mode, event is removed based on argument
specified for in_arg.

if DLNA_JUST_CALLBACK is specified for in_remove_mode, event is removed based on callback function
specified for in_func.

if DLNA_BOTH_ARGUMENT_AND_CALLBACK is specified for in_remove_mode, event is removed based
on both argument specified for in_arg and callback function specified for in_func.
*/
void
dlnaProgressEventRemovePeer(dlna_progress in_p, dlna_progress_callback in_func,
			  	  	  	  	void *in_arg, enum dlna_event_remove_mode in_remove_mode);

/*!
\par Function:
Adds read event to DLNA progress.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_p</td>
		<td>DLNA progress manager descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_func</td>
		<td>Event callback function</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument of in_func</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>Read descriptor</td>
	</tr>
</table>

\return != slim_nil DLNA progress handle descriptor
\return == slim_nil Error occurred
\par Description:
This function registers the event callback function that is called when reading of the file descriptor or
network descriptor specified for in_desc is enabled and its argument, with the DLNA progress.
*/
dlna_progress_handle
dlnaProgressReadAddPeer(dlna_progress in_p, dlna_progress_io_callback in_func,
                        void *in_arg, slim_int in_desc);

/*!
\par Function:
Adds write event to DLNA progress.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_p</td>
		<td>DLNA progress manager descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_func</td>
		<td>Event callback function</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument of in_func</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_desc</td>
		<td>Write descriptor</td>
	</tr>
</table>

\return != slim_nil DLNA progress handle descriptor
\return == slim_nil Error occurred
\par Description:
This function registers the event callback function that is called when writing of the file descriptor or
network descriptor specified for in_desc is enabled and its argument, with the DLNA progress.
*/
dlna_progress_handle
dlnaProgressWriteAddPeer(dlna_progress in_p,
                         dlna_progress_io_callback in_func,
                         void *in_arg, slim_int in_desc);

/*!
\par Function:
Adds timer event to DLNA progress.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_p</td>
		<td>DLNA progress manager descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_func</td>
		<td>Event callback function</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument of in_func</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_timeval</td>
		<td>Delay time</td>
	</tr>
</table>

\return != slim_nil DLNA progress handle descriptor
\return == slim_nil Error occurred
\par Description:
This function registers the event callback function that is called when the delay time specified for
in_timeval has elapsed and its argument, with the DLNA progress.

For this function only, the time elapsed since the current time is specified for in_timeval as the delay
time, not the Coordinated Universal Time (UTC).
*/
dlna_progress_handle
dlnaProgressTimerAddPeer(dlna_progress in_p, dlna_progress_callback in_func,
                         void *in_arg, dlna_timeval *in_timeval);


void
dlnaProgressEntryCancelByArgPeer (dlna_progress in_p,  void *in_arg);

/*!
\par Function:
Cancels event from DLNA progress.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_p</td>
		<td>DLNA progress manager descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_pdesc</td>
		<td>DLNA progress handle descriptor</td>
	</tr>
</table>

\return None
\par Description:
This function cancels an event from the DLNA progress.

The descriptor of events added by the following functions is specified for in_pdesc.

- dlnaProgressEventAddPeer()
- dlnaProgressReadAddPeer()
- dlnaProgressWriteAddPeer()
- dlnaProgressTimerAddPeer()

*/
void
dlnaProgressEntryCancelPeer(dlna_progress in_p, dlna_progress_handle in_pdesc);

/*@}*/

/* Progress API macros.  */

/**
 * @addtogroup macros
 */
/*@{*/

#define EVENT_ADD_EVENT(E,M,F,V)                                             \
  do {                                                                       \
    dlnaEventManagerLockPeer(M);                                                 \
    if ((E) == DLNA_INVALID_PROGRESS_HANDLE) {                               \
      (E) = dlnaProgressEventAddPeer(M, F, V);                               \
    }                                                                        \
   dlnaEventManagerUnlockPeer(M);                                               \
  } while (0)

#define EVENT_ADD_READ(E,M,F,V,S)                                            \
  do {                                                                       \
    dlnaEventManagerLockPeer(M);                                                 \
    if ((E) == DLNA_INVALID_PROGRESS_HANDLE) {                               \
      (E) = dlnaProgressReadAddPeer(M, F, V, S);                             \
    }                                                                        \
    dlnaEventManagerUnlockPeer(M);                                               \
  } while (0)

#define EVENT_ADD_WRITE(E,M,F,V,S,R)                                           \
  do {                                                                       \
    dlnaEventManagerLockPeer(M);                                                 \
    if ((E) == DLNA_INVALID_PROGRESS_HANDLE) {                               \
      (E) = dlnaProgressWriteAddPeer(M, F, V, S);                            \
    }                                              \
    if (!E) {                                                                \
      R = -1;                                                                \
    } else {                                                                 \
      R = 0;                                                                 \
    }                                                                        \
    dlnaEventManagerUnlockPeer(M);                                                                         \
  } while (0)

#define EVENT_ADD_TIMER(E,M,F,V,T)                                           \
  do {                                                                       \
    dlna_timeval DT;                                                         \
    DT.tv_sec = T;                                                           \
    DT.tv_usec = 0;                                                          \
    dlnaEventManagerLockPeer(M);                                                 \
    if ((E) == DLNA_INVALID_PROGRESS_HANDLE) {                               \
      (E) = dlnaProgressTimerAddPeer(M, F, V, &DT);                          \
    }                                                                        \
    dlnaEventManagerUnlockPeer(M);                                               \
  } while (0)

#define EVENT_ADD_TIMER_TIMEVAL(E,M,F,V,T)                                   \
  do {                                                                       \
    dlnaEventManagerLockPeer(M);                                                 \
    if ((E) == DLNA_INVALID_PROGRESS_HANDLE) {                               \
      (E) = dlnaProgressTimerAddPeer(M, F, V, T);                            \
    }                                                                        \
    dlnaEventManagerUnlockPeer(M);                                               \
  } while (0)

#define EVENT_CANCEL(X,M)                                                     \
  do {                                                                        \
    dlnaEventManagerLockPeer(M);                                                 \
    if ((X) != DLNA_INVALID_PROGRESS_HANDLE)                                  \
      {                                                                       \
        dlnaProgressEntryCancelPeer(M,X);                                    \
        (X) = DLNA_INVALID_PROGRESS_HANDLE;                                   \
      }                                                                       \
    dlnaEventManagerUnlockPeer(M);                                               \
  } while (0)

#define EVENT_CANCEL_BY_ARG(M,V)           \
  do {                                     \
    dlnaEventManagerLockPeer(M);           \
    dlnaProgressEntryCancelByArgPeer(M,V); \
    dlnaEventManagerUnlockPeer(M);         \
  } while (0)

/*@}*/


struct dlnaSignalContext_ {
  slim_opaque instance;
  dlna_progress progress;
#ifdef HAVE_DTCP
  slim_opaque dtcp;
#endif /*HAVE_DTCP*/
};

typedef struct dlnaSignalContext_ dlnaSignalContext;

slim_int
dlnaSignalAllocPeer(dlnaSignalContext *in_signalcontext);

void
dlnaSignalFreePeer(void	);


/**
 * @addtogroup datatypes
 */
/*@{*/

/*!
DLNA thread mutex descriptor.
*/
typedef void * dlna_mutex;
/**
 * DLNA thread recursive mutex descriptor
 */
typedef void * dlna_recursive_mutex;
/*!
DLNA thread manager descriptor.
*/
typedef void * dlna_thread;
/**
 * DLNA thread conditional variable descriptor
 */
typedef void * dlna_conditional_variable;

/*@}*/

/**
 * @addtogroup enums
 */
/*@{*/

/**
 * DLNA thread scheduling policies
 */
enum dlna_thread_policy
{
  Dlna_Thread_Policy_Other,     //!< Other - Default policy
  Dlna_Thread_Policy_Fifo,      //!< Fifo
  Dlna_Thread_Policy_RoundRobin,//!< Round robin
  Dlna_Thread_Policy_Batch,     //!< batch
};
enum dlna_thread_priority
{
  DLNA_THREAD_PRIO_DEFAULT = 0,
  DLNA_THREAD_PRIO_MIN = -100,   // lazy
  DLNA_THREAD_PRIO_MAX = 100,     // fasted
};


/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
DLNA thread procedure descriptor.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>in_arg specified using dlnaThreadAllocPeer()</td>
	</tr>
</table>

\return Not currently used
*/
typedef slim_int (*dlna_thread_proc) (void *in_arg);

/*!
\par Function:
Allocates DLNA thread mutex object.
\par Parameters:
none
\return != slim_nil DLNA thread mutex descriptor
\return == slim_nil Error occurred
\par Description:
This function allocates and returns a DLNA thread mutex object.

This mutex object must be in the unlocked status before this function returns.

The returned descriptor will be the first input argument of other DLNA thread mutex-related Peer APIs.
*/
dlna_mutex
dlnaThreadMutexAllocPeer(void);

/*!
\par Function:
Releases DLNA thread mutex object.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA thread mutex descriptor</td>
	</tr>
</table>

\return None
\par Description:
This function releases the DLNA thread mutex object.
*/
void
dlnaThreadMutexFreePeer(dlna_mutex self);

/*!
\par Function:
Locks DLNA thread mutex object.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA thread mutex descriptor</td>
	</tr>
</table>

\return slim_true Succeeded
\return slim_false Failed
\par Description:
This function locks the DLNA thread mutex object specified by the self argument.
*/
slim_bool
dlnaThreadMutexLockPeer(dlna_mutex self);

/*!
\par Function:
Unlocks DLNA thread mutex object.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA thread mutex descriptor</td>
	</tr>
</table>

\return slim_true Succeeded
\return slim_false Failed
\par Description:
This function unlocks the DLNA thread mutex object specified by the self argument.
*/
slim_bool
dlnaThreadMutexUnlockPeer(dlna_mutex self);

/*!
\par Function:
Unlocks DLNA thread mutex object with possible timeout.
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>self</td>
    <td>DLNA thread mutex descriptor</td>
  </tr>
    <tr>
    <td>[in]</td>
    <td>timeout</td>
    <td>Timeout value in seconds</td>
  </tr>
</table>

\return slim_true Succeeded
\return slim_false Failed
\par Description:
This function unlocks the DLNA thread mutex object specified by the self argument or waits until timeout.
*/
slim_bool
dlnaThreadMutexTimedLockPeer(dlna_mutex self, slim_int timeout);

/**
 * \par Function:
 * Allocate recursive mutex object
 * \par Parameters:
 * none
 * \return 0 Failed
 * \return Pointer to allocated instance
 * \par Description
 * Function allocate and initialize instance of recursive mutex.
 */
dlna_recursive_mutex
dlnaThreadRecursiveMutexAllocPeer(void);

/**
 * \par Function:
 * Free recursive mutex object
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Recursive mutex object</td>
 *   </tr>
 * </table>
 * \par Description
 * Function free instance of recursive mutex.
 * \par Warning
 * Object will not be unlocked before release.
 */
void
dlnaThreadRecursiveMutexFreePeer(dlna_recursive_mutex self);

/**
 * \par Function:
 * Locks recursive mutex
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Recursive mutex instance</td>
 *   </tr>
 * </table>
 * \par Description
 * Function locks an object.
 * \par Warning
 * Note that recursive mutex locked multiple times by one thread has to be unlocked multiple times before it can be locked by another thread.
 */
void
dlnaThreadRecursiveMutexLockPeer(dlna_recursive_mutex self);

/**
 * \par Function:
 * Unlock recursive mutex
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance</td>
 *   </tr>
 * </table>
 * \par Description
 * Unlocks object. Check dlnaThreadRecursiveMutexLockPeer for more info.
 */
void
dlnaThreadRecursiveMutexUnlockPeer(dlna_recursive_mutex self);

/**
 * \par Function:
 * Allocates conditional variable object
 * \par Parameters:
 * none
 * \return Pointer to allocated instance
 * \return 0 Failed
 * \par Description
 * Allocate and initialize object.
 */
dlna_conditional_variable
dlnaThreadConditionalVariableAllocPeer(void);

/**
 * \par Function:
 * Free object
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>cv</td>
 *     <td>Conditional variable instance</td>
 *   </tr>
 * </table>
 * \par Description
 * Function free object
 * \par Warning
 * Note that it does not signal before release.
 */
void
dlnaThreadConditionalVariableFreePeer(dlna_conditional_variable cv);

/**
 * \par Function:
 * Starts waiting for variable
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>cv</td>
 *     <td>Instance of conditional variable</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>mutex</td>
 *     <td>Instance of mutex</td>
 *   </tr>
 * </table>
 * \par Description
 *
 */
void
dlnaThreadConditionalVariableWaitPeer(dlna_conditional_variable cv,
    dlna_mutex mutex);

/**
 * \par Function:
 * Signals object
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>cv</td>
 *     <td>Instance of conditional variable</td>
 *   </tr>
 * </table>
 * \par Description
 * Signals conditional variable.
 */
void
dlnaThreadConditionalVariableSignalPeer(dlna_conditional_variable cv);

/*!
\par Function:
Allocates DLNA thread.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_proc</td>
		<td>First function called by new thread to be generated</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument for in_proc</td>
	</tr>
</table>

\return != slim_nil DLNA thread manager descriptor
\return == slim_nil Error occurred
\par Description:
This function allocates a DLNA thread that will be started by dlnaThreadStartPeer()and returns
its manager descriptor.

The returned descriptor will be the first input argument of other DLNA thread-related Peer APIs.
*/
dlna_thread
dlnaThreadAllocPeer(dlna_thread_proc in_proc, void *in_arg);

/*!
\par Function:
Allocates DLNA thread.
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_proc</td>
    <td>First function called by new thread to be generated</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_arg</td>
    <td>Argument for in_proc</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_stack_size</td>
    <td>Argument for in_stack_size</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_joinable</td>
    <td>Argument for in_joinable</td>
  </tr>
</table>

\return != slim_nil DLNA thread manager descriptor
\return == slim_nil Error occurred
\par Description:
This function allocates a DLNA thread that will be started by dlnaThreadStartPeer()and returns
its manager descriptor.

The returned descriptor will be the first input argument of other DLNA thread-related Peer APIs.
*/
dlna_thread
dlnaThreadAllocExPeer(dlna_thread_proc in_proc, void *in_arg, slim_int in_stack_size, slim_int in_joinable, slim_int in_prio, slim_int in_policy);

/*!
\par Function:
Releases DLNA thread.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA thread manager descriptor</td>
	</tr>
</table>

\return None
\par Description:
This function releases the DLNA thread.
*/
void
dlnaThreadFreePeer(dlna_thread self);

/*!
\par Function:
Starts DLNA thread.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA thread manager descriptor</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\par Description:
This function starts the thread specified by the self argument.
\par Warning
Be noted that DLNA thread may be created with in_proc set to NULL. It is not possible to start such thread, but descriptor still can be useful with other functions like changing priority.
*/
slim_int
dlnaThreadStartPeer(dlna_thread self);

/*!
\par Function:
Waits until specified thread exists.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA thread manager descriptor</td>
	</tr>
</table>

\return None
\par Description:
This function waits until the specified thread exits. This function should block the current thread until
another thread (specified by the self argument) exits.
*/
void
dlnaThreadWaitForExitPeer(dlna_thread self);

/*!
\par Function:
Blocks current thread for number of seconds specified by in_time.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_time_us</td>
		<td>Time in seconds to sleep</td>
	</tr>
</table>

\return None
\par Description:
This function makes the current thread sleep for the number of seconds specified by in_time.
*/
void
dlnaThreadSleepPeer(slim_word in_time_us);

/*!
\par Function:
cancels the thread that is being run
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>DLNA thread manager descriptor</td>
        </tr>
</table>

\return None
\par Description:
This function cancels the thread that is being run.
*/
void
dlnaThreadCancelPeer(dlna_thread self);

/**
 * \par Function:
 * Check if self is current thread
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Thread descriptor instance</td>
 *   </tr>
 * </table>
 * \return slim_true self is current thread
 * \return slim_false self is not current thread
 * \par Description
 * Function compare current thread id with one specified by self.
 */
slim_bool
dlnaThreadIsSelf(dlna_thread self);

/**
 * \par Function:
 * Get current thread id.
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of thread descriptor</td>
 *   </tr>
 * </table>
 * \par Description
 * Function acquires current thread id and stores it in descriptor
 * \par Warning
 * Function does not allocate thread descriptor.\n Function does not provide routine or argument. Descriptor obtained this way cannot be started.
 */
void
dlnaThreadGetSelf(dlna_thread self);

/**
 * \par Function:
 * Change scheduling policy.
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>thread</td>
 *     <td>Instance of thread descriptor</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>policy</td>
 *     <td>Requested policy</td>
 *   </tr>
 * </table>
 * \return slim_true Success
 * \return slim_false Failure
 * \par Description
 * Function change scheduling policy of thread. In case of failure function will log system error code. More info in proper documentation.
 */
slim_bool
dlnaThreadSetPolicy(dlna_thread thread, enum dlna_thread_policy policy);

/**
 * \par Function:
 * Retrieve current scheduling policy of thread
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>thread</td>
 *     <td>Instance of thread descriptor</td>
 *   </tr>
 *   <tr>
 *     <td>[out]</td>
 *     <td>policy</td>
 *     <td>Current policy</td>
 *   </tr>
 * </table>
 * \return slim_true Success
 * \return slim_false Failure
 * \par Description
 * If function fails to retrieve current policy, parameter policy is not modified.
 */
slim_bool
dlnaThreadGetPolicy(dlna_thread thread, enum dlna_thread_policy * policy);

/**
 * \par Function:
 * Retrieve current scheduling priority of thread
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>thread</td>
 *     <td>Instance of thread descriptor</td.
 *   </tr>
 *   <tr>
 *     <td>[out]</td>
 *     <td>priority</td>
 *     <td>Current priority</td>
 *   </tr>
 * </table>
 * \return slim_true Success
 * \return slim_false Failure
 * \par Description
 * If function fails parameter priority is not modified.
 */
slim_bool
dlnaThreadGetPriority(dlna_thread thread, slim_int * priority);

/**
 * \par Function:
 * Change thread priority
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>thread</td>
 *     <td>Instance of thread descriptor</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>priority</td>
 *     <td>Requested priority</td>
 *   </tr>
 * </table>
 * \return slim_true Success
 * \return slim_false Failure
 * \par Description
 * Change thread priority. In case of failure system error code is logged. More info in proper documentation.
 * \par Warning
 * Acceptable priority range differs from one policy to another. User should verify value with dlnaThreadGetMinPriority and dlnaThreadGetMaxPriority.
 */
slim_bool
dlnaThreadSetPriority(dlna_thread thread, slim_int priority);

/**
 * \par Function:
 * Retrieve minimum priority for policy
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>policy</td>
 *     <td>Requested policy</td>
 *   </tr>
 * </table>
 * \return -1 Failure
 * \return Minimum priority
 */
slim_int
dlnaThreadGetMinPriority(enum dlna_thread_policy policy);

/**
 * \par Function:
 * Retrieve maximum priority for policy
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>policy</td>
 *     <td>Requested policy</td>
 *   </tr>
 * </table>
 * \return -1 Failure
 * \return Maximum priority
 */
slim_int
dlnaThreadGetMaxPriority(enum dlna_thread_policy policy);

/**
 * \par Function:
 * Set current thread's signal policy to block all signals
 */
void
dlnaThreadBlockSignals(void);

slim_bool
dlnaThreadSetThisScheduling(enum dlna_thread_policy in_policy, slim_int in_priority);

/*@}*/

/**
 * @addtogroup datatypes
 */
/*@{*/

/* DLNA player API.  */
/*!
DLNA plyer engine descriptor.
*/
typedef void *dlna_player;
/*!
DLNA plyer stream descriptor.
*/
typedef void *dlna_player_stream;
/*!
DLNA plyer display descriptor.
*/
typedef void *dlna_player_display;
/*!
Item group information. Not currently used.
*/
typedef void *dlna_item_group;

/*@}*/

/**
 * @addtogroup structures
 */
/*@{*/

/*! Player callback parameter.  */
struct dlna_player_param_
{
  /* Player stream.  */
  dlna_player_stream stream;

  /* Duration.  */
  slim_word duration;

  /* Progress percent.  */
  slim_int percent;

  /* File path.  */
  slim_char *path;

  /* Buffer poniter used by the DLNA_EVENT_WRITE_READY
     and DLNA_EVENT_READ_READY events.  */
  slim_byte *buffer;

  /* Buffer size used by the DLNA_EVENT_WRITE_READY
     and DLNA_EVENT_READ_READY events.  */
  dlna_size_t buffer_size;

#ifdef DEVELOPMENT_ENABLE_UPNPTRANSPORT_SEEK
	/* seek position */
	dlna_uint64 position;
#endif

};

/*!
dlna_player_param is the structure that stores player information.

\code
struct _dlna_player_param {
dlna_player_stream stream;
slim_word duration;
slim_int percent;
slim_char *path;
slim_byte *buffer;
dlna_size_t buffer_size;
};
typedef struct _dlna_player_param dlna_player_param;
\endcode
\par Member:

<table>
	<tr>
		<td>stream</td>
		<td>Player stream handle</td>
	</tr>
	<tr>
		<td>duration</td>
		<td>Total content duration (seconds) (Specify 0 since this is not currently used)</td>
	</tr>
	<tr>
		<td>percent</td>
		<td>Progress since content play started (%)</td>
	</tr>
	<tr>
		<td>path</td>
		<td>Path to content</td>
	</tr>
	<tr>
		<td>buffer</td>
		<td>Pointer to buffer used while notifying of following events (Specify slim_nil
			since this is not currently used)<br/>
			DLNA_EVENT_WRITE_READY<br/>
			DLNA_EVENT_READ_READY</td>
	</tr>
	<tr>
		<td>buffer_size</td>
		<td>Size of buffer used while notifying of following events (bytes) (Specify
			slim_nil since this is not currently used)<br/>
			DLNA_EVENT_WRITE_READY<br/>
			DLNA_EVENT_READ_READY</td>
	</tr>
</table>

*/
typedef struct dlna_player_param_ dlna_player_param;

/* Player display parameter.  */
struct dlna_player_display_param_
{
  /* Player display handler.  */
  dlna_player_display display;

  /* Display X position.  */
  slim_word xpos;

  /* Display position.  */
  slim_word ypos;

  /* Width of the display.  */
  slim_word width;

  /* Height of the display.  */
  slim_word height;

  /* TNFLCItemGrup */
  dlna_item_group item_group;
};
/*!
This structure is not currently used.

dlna_player_display_param is the structure that retains player display window information.

\code
struct _dlna_player_display_param {
dlna_player_display display;
slim_word xpos;
slim_word ypos;
slim_word width;
slim_word height;
dlna_item_group item_group;
};
typedef struct _dlna_player_display_param dlna_player_display_param;
\endcode
\par Member:

<table>
	<tr>
		<td>display</td>
		<td>Display window handler</td>
	</tr>
	<tr>
		<td>xpos</td>
		<td>x coordinate of upper left edge of window</td>
	</tr>
	<tr>
		<td>ypos</td>
		<td>y coordinate of upper left edge of window</td>
	</tr>
	<tr>
		<td>width</td>
		<td>Width of window</td>
	</tr>
	<tr>
		<td>height</td>
		<td>Height of window</td>
	</tr>
	<tr>
		<td>item_group</td>
		<td>Item group information (not currently used)</td>
	</tr>
</table>

*/
typedef struct dlna_player_display_param_ dlna_player_display_param;

/*@}*/

/**
 * @addtogroup enums
 */
/*@{*/

/*! Player events.  */
enum dlna_player_event_
{
  DLNA_PLAYER_OPEN = 0,
  DLNA_PLAYER_CLOSE,
  DLNA_PLAYER_PLAY,
  DLNA_PLAYER_PAUSE,
  DLNA_PLAYER_STOP,
  DLNA_PLAYER_PREVIOUS, /* 5 */
  DLNA_PLAYER_NEXT,
  DLNA_PLAYER_UPDATE,
  DLNA_PLAYER_READ_READY,
  DLNA_PLAYER_WRITE_READY,
  DLNA_PLAYER_FF, /* 10 */
  DLNA_PLAYER_SF,
  DLNA_PLAYER_FR,
  DLNA_PLAYER_SR,
  DLNA_PLAYER_ERROR,
  DLNA_PLAYER_ENGINE_ERROR, /* 15 */
  DLNA_PLAYER_END_OF_MEDIA,
  DLNA_PLAYER_SEEKTIME,
  DLNA_PLAYER_SEEKBYTES,
  DLNA_PLAYER_TRANSITIONING,
  DLNA_PLAYER_VOLUME_CONTROL, /* 20 */
  DLNA_PLAYER_GET_POSITION_INFO,
  DLNA_PLAYER_PREPARE_NEXT,
  DLNA_PLAYER_TRANSITIONING_NEXT,
  DLNA_PLAYER_SELECT_PRESET,
  DLNA_PLAYER_EVENT_MAX
};
/*!
dlna_player_event represents the player engine state specified for dlna_player_callback().

<table>
	<tr>
		<td><b> Definition</b></td>
		<td><b> Event detailes</b></td>
	</tr>
	<tr>
		<td>DLNA_PLAYER_OPEN</td>
		<td>Opened</td>
	</tr>
	<tr>
		<td>DLNA_PLAYER_CLOSE</td>
		<td>Closed</td>
	</tr>
	<tr>
		<td>DLNA_PLAYER_PLAY</td>
		<td>Playing</td>
	</tr>
	<tr>
		<td>DLNA_PLAYER_PAUSE</td>
		<td>Pausing</td>
	</tr>
	<tr>
		<td>DLNA_PLAYER_STOP</td>
		<td>Stopped</td>
	</tr>
	<tr>
		<td>DLNA_PLAYER_FF</td>
		<td>Fast forwarding</td>
	</tr>
	<tr>
		<td>DLNA_PLAYER_SF</td>
		<td>Slow forwarding</td>
	</tr>
	<tr>
		<td>DLNA_PLAYER_FR</td>
		<td>Fast rewinding</td>
	</tr>
	<tr>
		<td>DLNA_PLAYER_SR</td>
		<td>Slow rewinding</td>
	</tr>
	<tr>
		<td>DLNA_PLAYER_SEEKTIME</td>
		<td>Time seeking</td>
	</tr>
	<tr>
		<td>DLNA_PLAYER_SEEKBYTES</td>
		<td>Byte seeking</td>
	</tr>
	<tr>
		<td>DLNA_PLAYER_END_OF_MEDIA</td>
		<td>Reached end of media</td>
	</tr>
	<tr>
		<td>DLNA_PLAYER_ERROR</td>
		<td>Error occurred</td>
	</tr>
	<tr>
		<td>DLNA_PLAYER_WRITE_READY</td>
		<td>Not used</td>
	</tr>
	<tr>
		<td>DLNA_PLAYER_READ_READY</td>
		<td>Not used</td>
	</tr>
	<tr>
		<td>DLNA_PLAYER_PREVIOUS</td>
		<td>Not used</td>
	</tr>
	<tr>
		<td>DLNA_PLAYER_NEXT</td>
		<td>Not used</td>
	</tr>
	<tr>
		<td>DLNA_PLAYER_UPDATE</td>
		<td>Not used</td>
	</tr>
	<tr>
		<td>DLNA_PLAYER_ENGINE_ERROR</td>
		<td>Not used</td>
	</tr>
</table>

*/
typedef enum dlna_player_event_ dlna_player_event;

/*@}*/

/**
 * @addtogroup macros
 */
/*@{*/

#define DLNA_PLAYER_XINE          (1)


#define DLNA_PLAYER_FLAG_IMAGE		(1L << 0)
#define DLNA_PLAYER_FLAG_AUDIO		(1L << 1)
#define DLNA_PLAYER_FLAG_VIDEO		(1L << 2)
#define DLNA_PLAYER_FLAG_PLAY		(1L << 3)
#define DLNA_PLAYER_FLAG_DOWNLOAD	(1L << 4)
#define DLNA_PLAYER_FLAG_UPLOAD		(1L << 5)
#define DLNA_PLAYER_FLAG_LOCAL		(1L << 6)
#define DLNA_PLAYER_FLAG_STREAM		(1L << 7)
#define DLNA_PLAYER_FLAG_EXTERNAL	(1L << 8)
#define DLNA_PLAYER_FLAG_DRM		(1L << 9)
#define DLNA_PLAYER_FLAG_PLAYLIST (1L << 10)
#define DLNA_PLAYER_FLAG_REOPEN   (1L << 11)
#define DLNA_PLAYER_FLAG_PROBE_PINFO (1L << 12)
#define DLNA_PLAYER_FLAG_DMR (1L << 13) /* ZZZ: indicates upnp transport instance is created by dmr */
#define DLNA_PLAYER_FLAG_UP_LOCAL       (1L << 14)
#define DLNA_PLAYER_FLAG_UP_STREAM      (1L << 15)
#define DLNA_PLAYER_FLAG_CHUNKED        (1L << 16)
#if defined (HAVE_DTCP) && defined (DLNA_SUPPORT_UPLOADER)
#define DLNA_PLAYER_FLAG_DTCP           (1L << 17)
#define DLNA_PLAYER_FLAG_RADIO          (1L << 18)
#endif /* defined (HAVE_DTCP) && defined (DLNA_SUPPORT_UPLOADER) */
#define DLNA_PLAYER_FLAG_DOCUMENT       (1L << 19)

#if defined (HAVE_DTCP)
#define SLIM_HEAP_SIZE (2 * 1024 * 1024)
#endif /* defined (HAVE_DTCP) */

/*@}*/

/**
 * @addtogroup enums
 */
/*@{*/
#ifdef ENABLE_AHL
typedef slim_int (*dmr_ahl_callback) (dlna_player_event in_event, void *in_arg, void *in_param);
#endif

enum dlna_player_channel_
{
  DLNA_CHANNEL_UNKNOWN = -1,
  DLNA_CHANNEL_MASTER = 0,	/* Master */
  DLNA_CHANNEL_LF,			    /* Left Front */
  DLNA_CHANNEL_RF,			    /* Right Front */
  DLNA_CHANNEL_CF,			    /* Center Front */
  DLNA_CHANNEL_LFE,			    /* Low Frequency Enhancement */
  DLNA_CHANNEL_LS,			    /* Left Surround */
  DLNA_CHANNEL_RS,			    /* Right Surround */
  DLNA_CHANNEL_LFC,			    /* Left of Center */
  DLNA_CHANNEL_RFC,			    /* Right of Center */
  DLNA_CHANNEL_SD,			    /* Surround */
  DLNA_CHANNEL_SL,			    /* Side Left */
  DLNA_CHANNEL_SR,			    /* Side Right */
  DLNA_CHANNEL_T,			      /* Top */
  DLNA_CHANNEL_B			      /* Bottom */
};
/*!
dlna_player_channel represents the channel ID supported by the player.

<table>
	<tr>
		<td><b> Definition</b></td>
		<td><b> Event detailes</b></td>
	</tr>
	<tr>
		<td>DLNA_CHANNEL_UNKNOWN</td>
		<td>Unknown channel</td>
	</tr>
	<tr>
		<td>DLNA_CHANNEL_MASTER</td>
		<td>Master channel</td>
	</tr>
	<tr>
		<td>DLNA_CHANNEL_LF</td>
		<td>Left front channel</td>
	</tr>
	<tr>
		<td>DLNA_CHANNEL_RF</td>
		<td>Right front channel</td>
	</tr>
	<tr>
		<td>DLNA_CHANNEL_CF</td>
		<td>Center channel</td>
	</tr>
	<tr>
		<td>DLNA_CHANNEL_LFE</td>
		<td>LFE channel</td>
	</tr>
	<tr>
		<td>DLNA_CHANNEL_LS</td>
		<td>Left surround channel</td>
	</tr>
	<tr>
		<td>DLNA_CHANNEL_RS</td>
		<td>Right surround channel</td>
	</tr>
	<tr>
		<td>DLNA_CHANNEL_LFC</td>
		<td>Left center channel</td>
	</tr>
	<tr>
		<td>DLNA_CHANNEL_RFC</td>
		<td>Right center channel</td>
	</tr>
	<tr>
		<td>DLNA_CHANNEL_SD</td>
		<td>Surround channel</td>
	</tr>
	<tr>
		<td>DLNA_CHANNEL_SL</td>
		<td>Left side channel</td>
	</tr>
	<tr>
		<td>DLNA_CHANNEL_SR</td>
		<td>Right side channel</td>
	</tr>
	<tr>
		<td>DLNA_CHANNEL_T</td>
		<td>Top channel</td>
	</tr>
	<tr>
		<td>DLNA_CHANNEL_B</td>
		<td>Bottom channel</td>
	</tr>
</table>

*/

typedef enum dlna_player_channel_ dlna_player_channel;

/*@}*/

/**
 * @addtogroup enums
 */
/*@{*/

/*! Player trick-mode types.  */
enum dlna_player_trickmode_
{
  DLNA_TRICKMODE_NORMAL,
  DLNA_TRICKMODE_BY_TIMESEEK,
  DLNA_TRICKMODE_BY_BYTESEEK,
  DLNA_TRICKMODE_BY_PLAYSPEED,
  DLNA_TRICKMODE_BY_CONNECTION_STALLING,
  DLNA_TRICKMODE_MAX
};
/*!
dlna_player_trickmode represents trick modes to be assigned to player.

<table>
	<tr>
		<td><b> Definition</b></td>
		<td><b> Mode detailes</b></td>
	</tr>
	<tr>
		<td>DLNA_TRICKMODE_NORMAL</td>
		<td>Play in normal</td>
	</tr>
	<tr>
		<td>DLNA_TRICKMODE_BY_TIMESEEK</td>
		<td>Pause/Seek/FF/SF/FR/SR with time-based seek</td>
	</tr>
	<tr>
		<td>DLNA_TRICKMODE_BY_BYTESEEK</td>
		<td>Pause/Seek/FF/SF/FR/SR with byte-based seek</td>
	</tr>
	<tr>
		<td>DLNA_TRICKMODE_BY_PLAYSPEED</td>
		<td>FF/SF/FR/SR with playspeed</td>
	</tr>
	<tr>
		<td>DLNA_TRICKMODE_BY_CONNECTION_STALLING</td>
		<td>Pause with connection stalling</td>
	</tr>
</table>

*/
typedef enum dlna_player_trickmode_ dlna_player_trickmode;

/*@}*/

/**
 * @addtogroup datatypes
 */
/*@{*/

/*!
DLNA volume control handle.
*/
typedef void* dlna_volume_control_handle;

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Callback function for notifying NFLC core of player state.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_event</td>
		<td>Player state (see "5.2.2 dlna_player_event")</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument specified in dlnaPlayerAllocPeer()</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_param</td>
		<td>Pointer to player information (see "5.3.9 dlna_player_param")</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return Other Failed
\par Description:
This function notifies the NFLC core of the player state.

This function should be called every time the player state is updated.

The player state is specified for in_event.

This function must not be called directly within each DLNA Player Peer function. It must be called again
using the DLNA core thread or called by any thread other than the NFLC core, after a NFLC Player
Peer function has been called.
\note
To call this function using an NFLC core thread, an event for calling this function must be added to the
DLNA progress by using dlnaProgressEventAddPeer() (see "6.15.7
dlnaProgressEventAddPeer").
*/
typedef slim_int (*dlna_player_callback) (dlna_player_event in_event,
                                          void *in_arg,
                                          dlna_player_param *in_param);

/*!
\par Function:
Allocates new player engine.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_p</td>
		<td>DLNA progress manager descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_param</td>
		<td>Pointer to DLNA player display parameter (currently slim_nil is specified)</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_callback</td>
		<td>Callback function for notifying NFLC core of player state</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument of in_callback</td>
	</tr>
</table>

\return != slim_nil DLNA player engine descriptor
\return == slim_nil Error occurred
\par Description:
This function allocates a new player engine.

Implementation of this function is required only when creating a DMR application or a downloader
application. When creating other applications, a value other than slim_nil must be returned as
dummy implementation.

Information that the player engine uses to draw pictures and movies to the specified area in the display
is specified for in_param. Currently slim_nil is specified for in_param.

The pointer to the callback function for notifying the NFLC core of the player state from the player
engine is specified for in_callback.

The argument that the player engine passes to the NFLC core when calling in_callback is specified for
in_arg.
*/
dlna_player
dlnaPlayerAllocPeer(dlna_progress in_p, dlna_player_display_param *in_param,
                     dlna_player_callback in_callback, void *in_arg);

/*!
\par Function:
Sets display window information for rendering engine.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_player</td>
		<td>DLNA player stream descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_param</td>
		<td>Pointer to DLNA player display parameter</td>
	</tr>
</table>

\return T.B.D
\par Description:
This function is not currently used. This function does not need to be implemented.
T.B.D.
*/
slim_int
dlnaPlayerDisplayResizePeer(dlna_player in_player,
                             dlna_player_display_param *in_param);

/*!
\par Function:
Releases player engine.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_player</td>
		<td>DLNA player engine descriptor</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\par Description:
This function releases the player engine specified for in_player.

Implementation of this function is required only when creating a DMR application or a downloader
application.
*/
slim_int
dlnaPlayerFreePeer(dlna_player in_player);

/*!
\par Function:
Opens new player stream.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_player</td>
		<td>DLNA player engine descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_uri</td>
		<td>URI string of content to play</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_mime_type</td>
		<td>MIME type string of content to play</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_pinfo</td>
		<td>Protocol information string of content to play</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_title</td>
		<td>Title of the content to play</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_flags</td>
		<td>Stream type of content to play<br/>
			Specifies logical OR of the following flags:<br/>
			DLNA_PLAYER_FLAG_IMAGE Image content stream<br/>
			DLNA_PLAYER_FLAG_AUDIO Audio content stream<br/>
			DLNA_PLAYER_FLAG_VIDEO Video content stream</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_flags</td>
		<td>Streaming method<br/>
			DLNA_PLAYER_FLAG_STREAM Player engine operates streaming by itself<br/>
			DLNA_PLAYER_FLAG_EXTERNAL NFLC data transport is used
		</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Not used (Ignore value specified for in_arg)</td>
	</tr>
</table>

\return != slim_nil DLNA player stream descriptor
\return == slim_nil Error occurred
\par Description:
This function opens a new player stream for the player engine specified for in_player.

Implementation of this function is required only when creating a DMR application or a downloader
application.

The MIME type string for the content to be played is specified for in_mime_type.
\code
Example: video/mp4
\endcode

The protocol information string for the content to be played is specified for in_flags.

Example:
\code
http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_CIF15_AAC_520;DLNA.ORG_CI=0
\endcode
If the player engine performs streaming, DLNA_PLAYER_FLAG_STREAM is stored in out_flags, and if the
NFLC data transport is used instead of streaming, DLNA_PLAYER_FLAG_EXTERNAL is stored.

When the result of the opening process is determined, it notifies the NFLC core of the player engine
state through the callback function specified by dlnaPlayerAllocPeer(). Either one of the following
player engine states is specified for in_event of the callback function.

- Succeeded in opening: DLNA_PLAYER_OPEN
- Failed in opening: DLNA_PLAYER_ERROR

Callback functions must not be called within this function. For information of how to call a callback
function, see "7.1.3 dlna_player_callback".
*/
dlna_player_stream
dlnaPlayerOpenPeer(dlna_player in_player, slim_char *in_uri,
                   slim_char *in_mime_type, slim_char *in_pinfo, slim_char *in_title, slim_word in_flags,
                   slim_word *out_flags, void *in_arg);

/*!
\par Function:
Prefetch next player stream.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_player</td>
		<td>DLNA player engine descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_uri</td>
		<td>URI string of content to play</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_mime_type</td>
		<td>MIME type string of content to play</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_pinfo</td>
		<td>Protocol information string of content to play</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_title</td>
		<td>Title of the content to play</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_flags</td>
		<td>Stream type of content to play<br/>
			Specifies logical OR of the following flags:<br/>
			DLNA_PLAYER_FLAG_IMAGE Image content stream<br/>
			DLNA_PLAYER_FLAG_AUDIO Audio content stream<br/>
			DLNA_PLAYER_FLAG_VIDEO Video content stream</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\par Description:
This function informs URL of next player stream for the player engine specified for in_player.

Implementation of this function is optional but recommended by GUN JGXCT.

The MIME type string for the content to be played is specified for in_mime_type.
\code
Example: video/mp4
\endcode

The protocol information string for the content to be played is specified for in_flags.

Example:
\code
http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_BL_CIF15_AAC_520;DLNA.ORG_CI=0
\endcode
*/
slim_int
dlnaPlayerOpenNextPeer(dlna_player in_player, slim_char *in_uri,
                       slim_char *in_mime_type, slim_char *in_pinfo, slim_char *in_title, slim_word in_flags);

/*!
\par Function:
Closes player stream.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_stream</td>
		<td>DLNA player stream descriptor</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\return SLIM_E_WOULDBLOCK Processing result is not determined
\return SLIM_E_INVAL Invalid argument
\par Description:
This function discards all objects associated with the player stream specified for in_stream, and closes
the player stream.

Implementation of this function is required only when creating a DMR application or a downloader
application.

This function is also called even if the player stream is currently playing content.

When returning the result asynchronously to the NFLC core, it returns SLIM_E_WOULDBLOCK.

When returning SLIM_E_WOULDBLOCK, it notifies the NFLC core of the player engine state through the
callback function specified by dlnaPlayerAllocPeer() after the result of the closing process is
determined. Either one of the following player engine states is specified for in_event of the callback
function.

- Succeeded in closing: DLNA_PLAYER_CLOSE
- Failed in closing: DLNA_PLAYER_ERROR

Callback functions must not be called within this function. For information of how to call a callback
function, see "7.1.3 dlna_player_callback".
*/
slim_int
dlnaPlayerClosePeer(dlna_player_stream in_stream);

/*!
\par Function:
Plays content over player stream.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_stream</td>
		<td>DLNA player stream descriptor</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\return SLIM_E_WOULDBLOCK Processing result is not determined
\return SLIM_E_INVAL Invalid argument
\par Description:
This function plays the content over the player stream specified for in_stream.

Implementation of this function is required only when creating a DMR application.

When returning the result asynchronously to the NFLC core, it returns SLIM_E_WOULDBLOCK.

When returning SLIM_E_WOULDBLOCK, it notifies the NFLC core of the player engine state through the
callback function specified by dlnaPlayerAllocPeer() after the result of the playback process is
determined. Either one of the following player engine states is specified for in_event of the callback
function.

- Succeeded in playback: DLNA_PLAYER_PLAY
- Failed in playback: DLNA_PLAYER_ERROR

Callback functions must not be called within this function. For information of how to call a callback
function, see "7.1.3 dlna_player_callback".
*/
slim_int
dlnaPlayerPlayPeer(dlna_player_stream in_stream);

#ifdef DEVELOPMENT_CLOCK_SYNC
/*!
\par Function:
Plays content over player stream starting at desired presentation time.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_stream</td>
		<td>DLNA player stream descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_presentation_time</td>
		<td>Presentation time in seconds from beginning of day.</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\return SLIM_E_WOULDBLOCK Processing result is not determined
\return SLIM_E_INVAL Invalid argument
\par Description:
This function plays the content over the player stream specified for in_stream, starting at
desired number of seconds from beginning of the day, specified in in_presentation_time.

Implementation of this function is required only when creating a DMR application.

When returning the result asynchronously to the NFLC core, it returns SLIM_E_WOULDBLOCK.

When returning SLIM_E_WOULDBLOCK, it notifies the NFLC core of the player engine state through the
callback function specified by dlnaPlayerAllocPeer() after the result of the playback process is
determined. Either one of the following player engine states is specified for in_event of the callback
function.

- Succeeded in playback: DLNA_PLAYER_PLAY
- Failed in playback: DLNA_PLAYER_ERROR

Callback functions must not be called within this function. For information of how to call a callback
function, see "7.1.3 dlna_player_callback".
*/
slim_int
dlnaPlayerSyncPlayPeer(dlna_player_stream in_stream, slim_word in_presentation_time);
#endif /* DEVELOPMENT_CLOCK_SYNC */

/*!
\par Function:
Pauses content over player stream.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_stream</td>
		<td>DLNA player stream descriptor</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\return SLIM_E_WOULDBLOCK Processing result is not determined
\return SLIM_E_INVAL Invalid argument
\par Description:
This function suspends the content currently being played over the player stream specified for
in_stream.

Implementation of this function is required only when creating a DMR application.

Paused content is resumed using dlnaPlayerPlayPeer().

When returning the result asynchronously to the NFLC core, it returns SLIM_E_WOULDBLOCK.

When returning SLIM_E_WOULDBLOCK, it notifies the NFLC core of the player engine state through the
callback function specified by dlnaPlayerAllocPeer() after the result of the pause process is
determined. Either one of the following player engine states is specified for in_event of the callback
function.

- Succeeded in pausing: DLNA_PLAYER_PAUSE
- Failed in pausing: DLNA_PLAYER_ERROR

Callback functions must not be called within this function. For information of how to call a callback
function, see "7.1.3 dlna_player_callback".
*/
slim_int
dlnaPlayerPausePeer(dlna_player_stream in_stream);

/*!
\par Function:
Pauses content over player stream.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_stream</td>
		<td>DLNA player stream descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_mode</td>
		<td>Trick-mode type specifier</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\return SLIM_E_WOULDBLOCK Processing result is not determined
\return SLIM_E_INVAL Invalid argument
\par Description:
This function suspends the content currently being played over the player stream specified for
in_stream.

Implementation of this function is required only when creating a DMR application.

Paused content is resumed using dlnaPlayerPlayPeer().

When returning the result asynchronously to the NFLC core, it returns SLIM_E_WOULDBLOCK.

When returning SLIM_E_WOULDBLOCK, it notifies the NFLC core of the player engine state through the
callback function specified by dlnaPlayerAllocPeer() after the result of the pause process is
determined. Either one of the following player engine states is specified for in_event of the callback
function.

- Succeeded in pausing: DLNA_PLAYER_PAUSE
- Failed in pausing: DLNA_PLAYER_ERROR

Callback functions must not be called within this function. For information of how to call a callback
function, see "7.1.3 dlna_player_callback".
*/
slim_int
dlnaPlayerPauseByPeer(dlna_player_stream in_stream, dlna_player_trickmode in_mode);

#ifdef DEVELOPMENT_CLOCK_SYNC
/*!
\par Function:
Pauses content over player stream at desired time.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_stream</td>
		<td>DLNA player stream descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_presentation_time</td>
		<td>Presentation time in seconds from beginning of the day.</td>
	</tr>	
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\return SLIM_E_WOULDBLOCK Processing result is not determined
\return SLIM_E_INVAL Invalid argument
\par Description:
This function suspends the content currently being played over the player stream specified for
in_stream at desired number of seconds from beginning of the day, specified in in_presentation_time.

Implementation of this function is required only when creating a DMR application.

Paused content is resumed using dlnaPlayerPlayPeer() or dlnaPlayerSyncPlayPeer().

When returning the result asynchronously to the NFLC core, it returns SLIM_E_WOULDBLOCK.

When returning SLIM_E_WOULDBLOCK, it notifies the NFLC core of the player engine state through the
callback function specified by dlnaPlayerAllocPeer() after the result of the pause process is
determined. Either one of the following player engine states is specified for in_event of the callback
function.

- Succeeded in pausing: DLNA_PLAYER_PAUSE
- Failed in pausing: DLNA_PLAYER_ERROR

Callback functions must not be called within this function. For information of how to call a callback
function, see "7.1.3 dlna_player_callback".
*/
slim_int
dlnaPlayerSyncPausePeer(dlna_player_stream in_stream, slim_word in_presentation_time);
#endif /* DEVELOPMENT_CLOCK_SYNC */

/*!
\par Function:
Stopes content over player stream.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_stream</td>
		<td>DLNA player stream descriptor</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\return SLIM_E_WOULDBLOCK Processing result is not determined
\return SLIM_E_INVAL Invalid argument
\par Description:
This function stops the content currently being played over the player stream specified for in_stream.

Implementation of this function is required only when creating a DMR application.

When returning the result asynchronously to the NFLC core, it returns SLIM_E_WOULDBLOCK.

When returning SLIM_E_WOULDBLOCK, it notifies the NFLC core of the player engine state through the
callback function specified by dlnaPlayerAllocPeer() after the result of the stop process is
determined. Either one of the following player engine states is specified for in_event of the callback
function.

- Succeeded in stopping: DLNA_PLAYER_STOP
- Failed in stopping: DLNA_PLAYER_ERROR

Callback functions must not be called within this function. For information of how to call a callback
function, see "7.1.3 dlna_player_callback".
*/
slim_int
dlnaPlayerStopPeer(dlna_player_stream in_stream);

#ifdef DEVELOPMENT_CLOCK_SYNC
/*!
\par Function:
Stopes content over player stream at desired time.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_stream</td>
		<td>DLNA player stream descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_presentation_time</td>
		<td>Presentation time in seconds from beginning of day.</td>
	</tr>	
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\return SLIM_E_WOULDBLOCK Processing result is not determined
\return SLIM_E_INVAL Invalid argument
\par Description:
This function stops the content currently being played over the player stream specified for in_stream
at desired number of seconds from beginning of the day, specified in in_presentation_time.

Implementation of this function is required only when creating a DMR application.

When returning the result asynchronously to the NFLC core, it returns SLIM_E_WOULDBLOCK.

When returning SLIM_E_WOULDBLOCK, it notifies the NFLC core of the player engine state through the
callback function specified by dlnaPlayerAllocPeer() after the result of the stop process is
determined. Either one of the following player engine states is specified for in_event of the callback
function.

- Succeeded in stopping: DLNA_PLAYER_STOP
- Failed in stopping: DLNA_PLAYER_ERROR

Callback functions must not be called within this function. For information of how to call a callback
function, see "7.1.3 dlna_player_callback".
*/
slim_int
dlnaPlayerSyncStopPeer(dlna_player_stream in_stream, slim_word in_presentation_time);
#endif /* DEVELOPMENT_CLOCK_SYNC */

#ifdef USE_TRICK_PLAY

/*!
\par Function:
Fast forwards content over player stream.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_stream</td>
		<td>DLNA player stream descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_speed</td>
		<td>Fast forward playback speed. It is a multiplier value relative to standard
			playback speed. The standard playback speed is 1.</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\return SLIM_E_WOULDBLOCK Processing result is not determined
\par Description:
This function fast forwards the content over the player stream specified for in_stream.

When returning the result asynchronously to the NFLC core, it returns SLIM_E_WOULDBLOCK.

When returning SLIM_E_WOULDBLOCK, it notifies the NFLC core of the player engine state through the
callback function specified by dlnaPlayerAllocPeer() after the result of the fast forward process is
determined. Either one of the following player engine states is specified for in_event of the callback
function.

- Succeeded in fast forwarding: DLNA_PLAYER_FF
- Failed in fast forwarding: DLNA_PLAYER_ERROR

Callback functions must not be called within this function. For information of how to call a callback
function, see "7.1.3 dlna_player_callback".
*/
slim_int
dlnaPlayerFastForwardPeer (dlna_player_stream in_stream, slim_int in_speed, dlna_player_trickmode in_mode);

slim_int
dlnaPlayerSlowForwardPeer (dlna_player_stream in_stream, slim_int in_speed, dlna_player_trickmode in_mode);
/*!
\par Function:
Fast rewinds content over player stream.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_stream</td>
		<td>DLNA player stream descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_speed</td>
		<td>Fast rewind speed. It is a multiplier value relative to the standard playback
			speed. The standard playback speed is 1</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\return SLIM_E_WOULDBLOCK Processing result is not determined
\par Description:
This function fast rewinds the content over the player stream specified for in_stream..

When returning the result asynchronously to the NFLC core, it returns SLIM_E_WOULDBLOCK.

When returning SLIM_E_WOULDBLOCK, it notifies the NFLC core of the player engine state through the
callback function specified by dlnaPlayerAllocPeer() after the result of fast rewind is determined.
Either one of the following player engine states is specified for in_event of the callback function.

- Succeeded in fast rewinding: DLNA_PLAYER_FR
- Failed in fast rewinding: DLNA_PLAYER_ERROR

Callback functions must not be called within this function. For information of how to call a callback
function, see "7.1.3 dlna_player_callback".
*/
slim_int
dlnaPlayerFastRewindPeer (dlna_player_stream in_stream, slim_int in_speed, dlna_player_trickmode in_mode);

slim_int
dlnaPlayerSlowRewindPeer (dlna_player_stream in_stream, slim_int in_speed, dlna_player_trickmode in_mode);

#endif /* USE_TRICK_PLAY */

/*!
\par Function:
Seeks content over player stream based on track number.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_stream</td>
		<td>DLNA player stream descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_offset</td>
		<td>T.B.D.</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\return SLIM_E_WOULDBLOCK Processing result is not determined
\par Description:
This function is not currently used. This function does not need to be implemented.
T.B.D.
*/
slim_int
dlnaPlayerSeekTrackPeer (dlna_player_stream in_stream, dlna_off_t in_offset);

/*!
\par Function:
Seeks content over player stream based on bytes.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_stream</td>
		<td>DLNA player stream descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_offset</td>
		<td>Amount of movement from start of file (bytes)</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\return SLIM_E_WOULDBLOCK Processing result is not determined
\par Description:
This function seeks within content over the player stream based on the bytes specified for in_offset.

When returning the result asynchronously to the NFLC core, it returns SLIM_E_WOULDBLOCK.

When returning SLIM_E_WOULDBLOCK, it notifies the NFLC core of the player engine state through the
callback function specified by dlnaPlayerAllocPeer() after the result of the byte seek process is
determined. Either one of the following player engine states is specified for in_event of the callback
function.

- Succeeded in byte seeking: DLNA_PLAYER_SEEKBYTES
- Failed in byte seeking: DLNA_PLAYER_ERROR

Callback functions must not be called within this function. For information of how to call a callback
function, see "7.1.3 dlna_player_callback".
*/
slim_int
dlnaPlayerSeekBytesPeer (dlna_player_stream in_stream, dlna_uint64 in_offset);

/*!
\par Function:
Seeks content over player stream based on time.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_stream</td>
		<td>DLNA player stream descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_sec</td>
		<td>Amount of movement from start of file (seconds)</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\return SLIM_E_WOULDBLOCK Processing result is not determined
\par Description:
This function seeks within content over the player stream based on the time specified for in_sec.

When returning the result asynchronously to the NFLC core, it returns SLIM_E_WOULDBLOCK.

When returning SLIM_E_WOULDBLOCK, it notifies the NFLC core of the player engine state through the
callback function specified by dlnaPlayerAllocPeer() after the result of the time seek process is
determined. Either one of the following player engine states is specified for in_event of the callback
function.

- Succeeded in time seeking: DLNA_PLAYER_SEEKTIME
- Failed in time seeking: DLNA_PLAYER_ERROR

Callback functions must not be called within this function. For information of how to call a callback
function, see "7.1.3 dlna_player_callback".
*/
slim_int
dlnaPlayerSeekTimePeer (dlna_player_stream in_stream, dlna_off_t in_sec);

/*!
\par Function:
Writes data to player stream.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_stream</td>
		<td>DLNA player stream descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_buf</td>
		<td>Pointer to buffer of data to write</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_length</td>
		<td>Number of bytes to write</td>
	</tr>
</table>

\return >=0 Succeeded (number of bytes actually written)
\return -1 Failed
\par Description:
This function writes the data in the buffer specified for in_buf up to in_length bytes to the player stream
specified for in_stream.

Implementation of this function is required only when creating a downloader application.
*/
slim_int
dlnaPlayerWritePeer(dlna_player_stream in_stream,
                     slim_byte *in_buf, dlna_size_t in_length);

/*!
\par Function:
Reads data from player stream.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_stream</td>
		<td>DLNA player stream descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_length</td>
		<td>Number of bytes to read</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>in_buf</td>
		<td>Pointer to buffer that stores read data</td>
	</tr>
</table>

\return >0 Succeeded (number of bytes actually read)
\return 0 Reached end of content
\return -1 Failed
\par Description:
This function is not currently used. This function does not need to be implemented.

This function reads data up to in_length bytes from the player stream specified for in_stream to the buffer
specified for in_buf.
*/
slim_int
dlnaPlayerReadPeer(dlna_player_stream in_stream,
                    slim_byte *in_buf, dlna_size_t in_length);

#if defined (HAVE_DTCP) && defined (DLNA_SUPPORT_UPLOADER)
slim_bool
dlnaPlayerCheckCCIPeer(slim_int *in_cci);
#endif

/*ZZZ These two API are not listed in proting_guide doc, and they are not completely implemented.
   So comment out them*/
#if 0
slim_int
dlnaPlayerPreviousPeer(dlna_player_stream in_stream);

slim_int
dlnaPlayerNextPeer(dlna_player_stream in_stream);
#endif

/*!
\par Function:
Sets item group information.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_player</td>
		<td>DLNA player engine descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>itemgroup</td>
		<td>Item group information.</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Falied
\par Description:
This function is not currently used. This function does not need to be implemented.

This sets the item group information.
*/
slim_int
dlnaPlayerSetItemGroupPeer(dlna_player in_player, void *itemgroup);

/*!
\par Function:
Gets item group information.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_player</td>
		<td>DLNA player engine descriptor</td>
	</tr>
</table>

\return != slim_nil Item group information
\return == slim_nil Error occurred
\par Description:
This function is not currently used. This function does not need to be implemented.

This returns the item group information.
*/
void *
dlnaPlayerGetItemGroupPeer(dlna_player in_player);

/*@}*/

/**
 * @addtogroup enums
 */
/*@{*/

enum dlna_volume_mute_state_ {
  MUTE_STATE_ERROR = -1,
  MUTE_STATE_OFF = 0,
  MUTE_STATE_ON = 1
};

/*!
dlna_volume_mute_state represents the mute state of the channel supported by the player.

<table>
	<tr>
		<td><b> Definition</b></td>
		<td><b> Event detailes</b></td>
	</tr>
	<tr>
		<td>MUTE_STATE_ERROR</td>
		<td>Acquisition error</td>
	</tr>
	<tr>
		<td>MUTE_STATE_OFF</td>
		<td>Mute off</td>
	</tr>
	<tr>
		<td>MUTE_STATE_ON</td>
		<td>Mute on</td>
	</tr>
</table>

*/
typedef enum dlna_volume_mute_state_ dlna_volume_mute_state;

enum dlna_volume_control_event_ {
  DLNA_VC_EVENT_VOLUME_CHANGED,
  DLNA_VC_EVENT_MAX,
};
/*!
dlna_volume_control_event represents the volume control event type specified for
dlna_volume_control_event_callback().

<table>
	<tr>
		<td><b> Definition</b></td>
		<td><b> Event detailes</b></td>
	</tr>
	<tr>
		<td>DLNA_VC_EVENT_VOLUME_CHANGED</td>
		<td>Changed volume</td>
	</tr>
</table>

*/
typedef enum dlna_volume_control_event_ dlna_volume_control_event;

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Callback function for notifying NFLC core of volume change.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_handle</td>
		<td>DLNA volume control handle</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_event</td>
		<td>DLNA_VC_EVENT_VOLUME_CHANGED</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_param</td>
		<td>Argument specified in dlnaPlayerVolumeControlOpenPeer()</td>
	</tr>
</table>

\return None
\par Description:
This function notifies the NFLC core of volume changes when the volume on the player is changed.

DLNA_VC_EVENT_VOLUME_CHANGED is specified for in_event.
*/
typedef void (*dlna_volume_control_event_callback)(dlna_volume_control_handle in_handle, dlna_volume_control_event in_event, void *in_param);

/*!
\par Function:
Gets number of channels and channel ID that player supports.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_handle</td>
		<td>DLNA volume control handle</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_num</td>
		<td>Pointer to buffer that stores number of channels supported by player</td>
	</tr>
</table>

\return	Pointer to buffer that stores channel IDs supported by player
\par Description:
This function stores the number of channels the player supports in out_num and returns the channel ID
of each channel as a return value.

Implementation of this function is required only when creating a DMR application.

This function returns the pointer to the buffer that stores channel IDs for the supported channels, as a
return value. The NFLC core retains a copy of this buffer after calling this function.
*/
dlna_player_channel*
dlnaPlayerGetSupportedChannelsPeer(dlna_volume_control_handle in_handle, slim_int* out_num);

/*!
\par Function:
Opens volume control.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_p</td>
		<td>DLNA progress manager descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_callback</td>
		<td>Callback function for notifying NFLC core of volume change</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_param</td>
		<td>Argument of in_callback</td>
	</tr>
</table>

\return != slim_nil DLNA volume control handle
\return == slim_nil Error occurred
\par Description:
This function opens the volume control.

Implementation of this function is required only when creating a DMR application.

The pointer to the callback function for giving notification of the volume change on the player side to the
NFLC core from the player engine is specified for in_callback.

The argument that the player engine passes to the NFLC core when calling in_callback is specified for
in_param.
*/
dlna_volume_control_handle
dlnaPlayerVolumeControlOpenPeer(dlna_progress in_p, dlna_volume_control_event_callback in_callback, void* in_param);

/*!
\par Function:
Closes volume control.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_handle</td>
		<td>DLNA volume control handle</td>
	</tr>
</table>

\return None
\par Description:
This function closes the volume control.

Implementation of this function is required only when creating a DMR application.
*/
void
dlnaPlayerVolumeControlClosePeer(dlna_volume_control_handle in_handle);

/*!
\par Function:
Gets volume of specified channel.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_handle</td>
		<td>DLNA volume control handle</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_channel</td>
		<td>Channel ID (see "5.2.3 dlna_player_channel")</td>
	</tr>
</table>

\return >=0 Succeeded (volume value of specified channel)
\return -1 Failed
\par Description:
This function returns the volume value of the channel specified for in_channel as a return value.

Implementation of this function is required only when creating a DMR application.
*/
slim_int
dlnaPlayerGetVolumePeer(dlna_volume_control_handle in_handle, dlna_player_channel in_channel);

/*!
\par Function:
Sets volume of specified channel.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_handle</td>
		<td>DLNA volume control handle</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_channel</td>
		<td>Channel ID (see "5.2.3 dlna_player_channel")</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_volume</td>
		<td>Volume value of channel</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\par Description:
This function sets the volume value of the channel specified for in_channel.

Implementation of this function is required only when creating a DMR application.
*/
slim_int
dlnaPlayerSetVolumePeer(dlna_volume_control_handle in_handle, slim_int in_channel, slim_int in_volume);

/*!
\par Function:
Gets mute state of specified channel.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_handle</td>
		<td>DLNA volume control handle</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_channel</td>
		<td>Channel ID (see "5.2.3 dlna_player_channel")</td>
	</tr>
</table>

\return MUTE_STATE_ERROR Failed
\return MUTE_STATE_OFF Specified channel is not in mute state
\return MUTE_STATE_ON Specified channel is in mute state
\par Description:
This function returns the mute state of the channel specified for in_channel as a return value.

Implementation of this function is required only when creating a DMR application.
*/
dlna_volume_mute_state
dlnaPlayerGetMuteStatePeer(dlna_volume_control_handle in_handle, dlna_player_channel in_channel);

/*!
\par Function:
Sets mute state of specified channel.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_handle</td>
		<td>DLNA volume control handle</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_channel</td>
		<td>Channel ID (see "5.2.3 dlna_player_channel")</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_mute</td>
		<td>Mute state of channel</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed

\par Description:
This function sets the mute state of the channel specified for in_channel.

Implementation of this function is required only when creating a DMR application.
*/
slim_int
dlnaPlayerSetMuteStatePeer(dlna_volume_control_handle in_handle, dlna_player_channel in_channel, dlna_volume_mute_state in_mute);

/*!
\par Function:
Gets volume (dB) of specified channel.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_handle</td>
		<td>DLNA volume control handle</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_channel</td>
		<td>Channel ID (see "5.2.3 dlna_player_channel")</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_volume_db</td>
		<td>Pointer to buffer that stores volume value (dB) of specified channel</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\par Description:
This function stores the volume value (dB) of the channel specified for in_channel to out_volume_db.

Implementation of this function is required only when creating a DMR application.
*/
slim_int
dlnaPlayerGetVolumeDBPeer(dlna_volume_control_handle in_handle, dlna_player_channel in_channel, slim_int *out_volume_db);

/*!
\par Function:
Sets volume (dB) of specified channel.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_handle</td>
		<td>DLNA volume control handle</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_channel</td>
		<td>Channel ID (see "5.2.3 dlna_player_channel")</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_volume_db</td>
		<td>Volume value (dB) of channel</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed

\par Description:
This function sets the volume value (dB) of the channel specified for in_channel.

Implementation of this function is required only when creating a DMR application.
*/
slim_int
dlnaPlayerSetVolumeDBPeer(dlna_volume_control_handle in_handle, dlna_player_channel in_channel, slim_int in_volume_db);

/*!
\par Function:
Gets volume (dB) range of specified channel.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_handle</td>
		<td>DLNA volume control handle</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_channel</td>
		<td>Channel ID (see "5.2.3 dlna_player_channel")</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_min_vol_db</td>
		<td>Address that stores minimum volume (dB) of specified channel</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_max_vol_db</td>
		<td>Address that stores maximum volume (dB) of specified channel</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\par Description:
This function stores the minimum and maximum volume values (dB) of the channel specified for
in_channel in out_min_vol_db and out_max_vol_db respectively.

Implementation of this function is required only when creating a DMR application.
*/
slim_int
dlnaPlayerGetVolumeDBRangePeer(dlna_volume_control_handle in_handle, dlna_player_channel in_channel, slim_int *out_min_vol_db, slim_int *out_max_vol_db);

/*!
\par Function:
Get preset values from player engine.
\par Parameters:

\return slim_nil If no presets supported.
\return Comma separated string for presets, FactoryDefaults is mandatory.
\par Description:
This function gets preset configuration(s) from the player engine.
Library will keep one copy of it.

Example:
\code
FactoryDefaults,LivingRoom,Office
\endcode
*/
slim_char *
dlnaPlayerGetPresetsPeer (void);

/*!
\par Function:
Set preset values to player engine.
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_preset</td>
    <td>String of preset</td>
  </tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\par Description:
This function sets preset configuration(s) to the player engine.
*/
slim_int
dlnaPlayerSetPresetPeer (slim_char *in_preset);

#if defined (HAVE_DTCP) && defined (DLNA_SUPPORT_UPLOADER)
slim_bool
dlnaPlayerCheckEMIPeer(slim_int *in_emi);
#endif

/*@}*/

/**
 * @addtogroup macros
 */
/*@{*/

/*
 * Uploader
 */
#define DLNA_UPLOADER_FLAG_LOCAL		DLNA_PLAYER_FLAG_UP_LOCAL
#define DLNA_UPLOADER_FLAG_STREAM		DLNA_PLAYER_FLAG_UP_STREAM

/*@}*/

/* DLNA uploader API. */

/**
 * @addtogroup datatypes
 */
/*@{*/

/*!
DLNA uploader descriptor.
*/
typedef void *dlna_uploader;
/*!
DLNA upload stream descriptor.
*/
typedef void *dlna_uploader_stream;

/*@}*/

/**
 * @addtogroup enums
 */
/*@{*/

/* Uploader events.  */
enum dlna_uploader_event_
{
  DLNA_UPLOADER_OPEN = 0,
  DLNA_UPLOADER_CLOSE,
  DLNA_UPLOADER_STOP,
  DLNA_UPLOADER_EVENT_MAX
};
/*!
dlna_uploader_event represents to uploader state specified for dlna_uploader_callback().

<table>
	<tr>
		<td><b> Definition</b></td>
		<td><b> Event detailes</b></td>
	</tr>
	<tr>
		<td>DLNA_UPLOADER_OPEN</td>
		<td>Opened</td>
	</tr>
	<tr>
		<td>DLNA_UPLOADER_CLOSE</td>
		<td>Closed</td>
	</tr>
	<tr>
		<td>DLNA_UPLOADER_STOP</td>
		<td>Not used</td>
	</tr>
</table>

*/
typedef enum dlna_uploader_event_ dlna_uploader_event;

/*@}*/

/**
 * @addtogroup macros
 */
/*@{*/

#define DLNA_UPLOADER_READ_END           (0)
#define DLNA_UPLOADER_READ_ERROR         (-1)
#define DLNA_UPLOADER_READ_WOULD_BLOCK   (-2)


/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Callback function for notifying NFLC core of uploader state.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_event</td>
		<td>Uploader state (see "5.2.6 dlna_uploader_event")</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument specified in dlnaUploaderAllocPeer()</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_stream</td>
		<td>DLNA upload stream descriptor</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return Other Failed
\par Description:
This function notifies the NFLC core of the uploader state. This function must be called every time the
uploader state is updated. The uploader state is specified for in_event.

This function must not be called directly from within each DLNA Uploader Peer function. It must be
called after the NFLC Uploader Peer function has been called.

This function may be processed asynchronously in the NFLC core. In this case, although it returns
SLIM_E_OK, the asynchronous process may have not been completed. When a critical process fails in
such a situation, the notification of the upload failure is given to the upper application from the NFLC
core.
\note
To call this function using an NFLC core thread, an event for calling this function must be added to the
DLNA progress by using dlnaProgressEventAddPeer() (see "6.15.7
dlnaProgressEventAddPeer").
*/
typedef slim_int (*dlna_uploader_callback)(dlna_uploader_event in_event,
                                           void *in_arg, dlna_uploader_stream *in_stream);

/*!
\par Function:
Reads upload stream data while uploading.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_up_stream</td>
		<td>DLNA upload stream descriptor</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_buf</td>
		<td>Pointer to buffer that stores read data</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_length</td>
		<td>Number of bytes to read</td>
	</tr>
</table>

\return >0 Succeeded (number of bytes actually read)
\return DLNA_UPLOADER_READ_END Reached end of content
\return DLNA_UPLOADER_READ_WOULD_BLOCK Unable to read data temporarily
\return DLNA_UPLOADER_READ_ERROR Error occurred
\par Description:
This function reads in_length bytes of data from the upload stream specified by in_up_stream and stores
it in in_buf.

If it reaches the end of the content while reading data, it stores data up to the end in in_buf once and
returns the size of data read as a return value. Then if called from the NFLC core again, this function
returns DLNA_UPLOADER_READ_END.

If it cannot read data temporarily, it returns DLNA_UPLOAD_READ_WOULD_BLOCK. In this case, data
must not be stored in in_buf.
*/
slim_int
dlnaUploaderReadPeer(dlna_uploader_stream in_up_stream,
		      slim_byte *out_buf, dlna_size_t in_length);

/*!
\par Function:
Starts new upload processing.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_uploader</td>
		<td>DLNA uploader descriptor.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_uri</td>
		<td>Full path of local file to be uploaded</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_flags</td>
		<td>Type of content to be uploaded<br/>
			Specify either of the following flags:<br/>
			DLNA_UPLOADER_FLAG_LOCAL Local file<br/>
			DLNA_UPLOADER_FLAG_STREAM Streams
		</td>
	</tr>
</table>

\return != slim_nil DLNA upload stream descriptor
\return == slim_nil Error occurred
\par Description:
This function allocates a new upload stream descriptor and starts uploading.

Either of bits representing type of content to be uploaded, DLNA_UPLOADER_FLAG_LOCAL or
DLNA_UPLOADER_FLAG_STREAM, is specified for in_flags.

Although some bits other than DLNA_UPLOADER_FLAG_LOCAL and DLNA_UPLOADER_FLAG_STREAM
may be specified for in_flags, ignore them.

If in_flags is DLNA_UPLOADER_FLAG_LOCAL, a full path with "file://" scheme is specified for in_uri.

If in_flags is DLNA_UPLOADER_FLAG_STREAM, in_uri must be ignored.

When the result of the start process is determined, this function must notify the NFLC core of the
uploader state through the callback function specified by dlnaUploaderAllocPeer(). The callback
function must be called asynchronously, not within this function synchronously.
DLNA_UPLOADER_OPEN must be specified for in_event of the callback function.
*/
dlna_uploader_stream
dlnaUploaderOpenPeer(dlna_uploader in_uploader, slim_char *in_uri, slim_int in_flags);

/*!
\par Function:
Terminates upload processing.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_uploader</td>
		<td>DLNA uploader descriptor.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_up_stream</td>
		<td>DLNA upload stream descriptor</td>
	</tr>
</table>

\return None
\par Description:
This function terminates upload processing. The uploaded file descriptor should be closed here.

When the process is terminated, this function must notify the NFLC core of the uploader state through
the callback function specified by dlnaUploaderAllocPeer(). The callback function must be called
asynchronously, not within this function synchronously. DLNA_UPLOADER_CLOSE must be specified for
in_event of the callback function.
*/
void
dlnaUploaderClosePeer(dlna_uploader in_uploader, dlna_uploader_stream in_up_stream);

/*!
\par Function:
Allocates uploader descriptor to control upload sequence.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_progress</td>
		<td>DLNA progress manager descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_callback</td>
		<td>Callback function for notifying NFLC core of uploader state</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_callback_arg</td>
		<td>Argument of in_callback</td>
	</tr>
</table>

\return != slim_nil DLNA uploader descriptor.
\return == slim_nil Error occurred
\par Description:
This function allocates an uploader descriptor and sets the arguments specified for in_progress,
in_callback, and in_callback_arg in it.

If a memory allocation error or other error occurs, return slim_nil as a return value.

The structure of the uploader descriptor itself depends on the target system. The structure must be
defined in the Peer and cast to the dlna_uploader type, which represents a void pointer type.
*/
dlna_uploader
dlnaUploaderAllocPeer(dlna_progress in_progress, dlna_uploader_callback in_callback,
                      void *in_callback_arg);

/*!
\par Function:
Frees uploader descriptor.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_uploader</td>
		<td>DLNA uploader descriptor.</td>
	</tr>
</table>

\return None
\par Description:
This function frees the uploader descriptor allocated by dlnaUploaderAllocPeer().
*/
void
dlnaUploaderFreePeer(dlna_uploader in_uploader);

/*@}*/

/* DLNA Downloader API. */

/**
 * @addtogroup datatypes
 */
/*@{*/

/*!
DLNA downloader descriptor.
*/
typedef void *dlna_downloader;
/*!
DLNA download stream descriptor.
*/
typedef void *dlna_downloader_stream;

/*@}*/

/**
 * @addtogroup enums
 */
/*@{*/

/* Downloader events.  */
enum dlna_dloader_event_
{
	DLNA_DOWNLOADER_OPEN = 0,
  DLNA_DOWNLOADER_CLOSE,
	DLNA_DOWNLOADER_PLAY, /*RESUME*/
 	DLNA_DOWNLOADER_PAUSE,
  DLNA_DOWNLOADER_STOP,
	DLNA_DOWNLOADER_ERROR,
  DLNA_DOWNLOADER_EVENT_MAX
};
/*!
dlna_downloader_event represents the downloader state specified for
dlna_downloader_callback().

<table>
	<tr>
		<td><b> Definition</b></td>
		<td><b> Event detailes</b></td>
	</tr>
	<tr>
		<td>DLNA_DOWNLOADER_OPEN</td>
		<td>Opened </td>
	</tr>
	<tr>
		<td>DLNA_DOWNLOADER_CLOSE</td>
		<td>Closed</td>
	</tr>
	<tr>
		<td>DLNA_DOWNLOADER_PLAY</td>
		<td>Not used</td>
	</tr>
	<tr>
		<td>DLNA_DOWNLOADER_PAUSE</td>
		<td>Not used</td>
	</tr>
	<tr>
		<td>DLNA_DOWNLOADER_STOP</td>
		<td>Not used</td>
	</tr>
	<tr>
		<td>DLNA_DOWNLOADER_ERROR</td>
		<td>Not used</td>
	</tr>
</table>

*/
typedef enum dlna_dloader_event_ dlna_downloader_event;

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Callback function for notifying NFLC core of downloader state.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_event</td>
		<td>Downloader state (see "5.2.7 dlna_downloader_eventdlna_downloader_event")</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument specified in dlnaDownloaderAllocPeer()</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_stream</td>
		<td>DLNA download stream descriptor</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return Other Failed

\par Description:
This function notifies the NFLC core of the downloader state. This function must be called every time
the downloader state is updated. The downloader state is specified for in_event.

This function must not be called directly from within any DLNA Downloader Peer function. It must be
called after the NFLC Downloader Peer function has been called.

This function may be processed asynchronously in the NFLC core. In this case, although it returns
SLIM_E_OK, the asynchronous process may have not been completed. If a critical process fails in such
a situation, then notification of the download failure is given to the upper application from the NFLC
core.
\note
To call this function using an NFLC core thread, an event for calling this function must be added to the
DLNA progress by using dlnaProgressEventAddPeer() (see "6.15.7
dlnaProgressEventAddPeer").
*/
typedef slim_int (*dlna_downloader_callback)(dlna_downloader_event in_event,
									 void *in_arg, dlna_downloader_stream *in_stream);

/*!
\par Function:
Allocates downloader descriptor to control download sequence.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_progress</td>
		<td>DLNA progress manager descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_callback</td>
		<td>Callback function for notifying NFLC core of downloader state</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_callback_arg</td>
		<td>Argument of in_callback</td>
	</tr>
</table>

\return != slim_nil DLNA downloader descriptor
\return == slim_nil Error occurred
\par Description:
This function allocates a downloader descriptor and sets the arguments specified for in_progress,
in_callback, and in_callback_arg in it.

If a memory allocation error or other error occurs, return slim_nil as a return value.

The structure of the downloader descriptor itself depends on the target system. The structure must be
defined in the Peer and cast to the dlna_downloader type, which represents a void pointer type.
*/
dlna_downloader
dlnaDownloaderAllocPeer(dlna_progress in_progress, dlna_downloader_callback in_callback,
													void *in_callback_arg);

/*!
\par Function:
Frees downloader descriptor.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_downloader</td>
		<td>DLNA downloader descriptor</td>
	</tr>
</table>

\return None
\par Description:
This function frees the downloader descriptor allocated by dlnaDownloaderAllocPeer().
*/
void
dlnaDownloaderFreePeer(dlna_downloader in_downloader);

/*!
\par Function:
Terminates download processing.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_down_stream</td>
		<td>DLNA download stream descriptors</td>
	</tr>
</table>

\return == 0 Succeeded
\return < 0 Error occurred
\par Description:
This function terminates download processing. The file descriptor of the download destination path
should be closed here.

When the process is terminated, this function must notify the NFLC core of the downloader state
through the callback function specified by dlnaDownloaderAllocPeer(). The callback function
must be called asynchronously, not within this function synchronously. DLNA_DOWNLOADER_CLOSE
must be specified for in_event of the callback function.
*/
slim_int
dlnaDownloaderClosePeer(dlna_downloader_stream in_down_stream);

/*!
\par Function:
Starts new download processing.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_downloader</td>
		<td>DLNA downloader descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>download_path</td>
		<td>Download destination path including file name</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_flags</td>
		<td>Not used (for future use)</td>
	</tr>
</table>

\return != slim_nil DLNA download stream descriptor
\return == slim_nil Error occurred
\par Description:
This function allocates a new download stream descriptor and starts downloading.

When the result of the start process is determined, this function must notify the NFLC core of the
downloader state through the callback function specified by dlnaDownloaderAllocPeer(). The
callback function must be called asynchronously, not within this function synchronously.
DLNA_DOWNLOADER_OPEN must be specified for in_event of the callback function.
*/
dlna_downloader_stream
dlnaDownloaderOpenPeer(dlna_downloader in_downloader, slim_char *download_path, slim_int in_flags);

/*!
\par Function:
Writes received data while downloading.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_stream</td>
		<td>DLNA download stream descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_buf</td>
		<td>Pointer to buffer that stores downloaded data</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_length</td>
		<td>Number of bytes to write</td>
	</tr>
</table>


\return >=0 Succeeded (number of bytes actually written
\return < 0 Error occurred
\par Description:
This function writes in_length bytes of data from the buffer specified by in_buf and returns the size of
data written as a return value.
*/
slim_int
dlnaDownloaderWritePeer(dlna_downloader_stream in_stream, slim_byte *in_buf, dlna_size_t in_length);

slim_int
dlnaDownloaderStartPeer(dlna_downloader_stream in_stream);

slim_int
dlnaDownloaderPausePeer(dlna_downloader_stream in_stream);

slim_int
dlnaDownloaderStopPeer(dlna_downloader_stream in_stream);

/*!
\par Function:
Function creates download directory specyfied in in_path fail only when in_path is slim_nil.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_path</td>
		<td>download directory path to create</td>
	</tr>
</table>
\return slim_int error value
\par Return Values:
<table>
	<tr>
		<td> \b 0 </td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td> 0 </td>
		<td> Fail</td>
	</tr>
</table>
*/

slim_int
dlnaDownloaderCreateDownloadDir(slim_char* in_path);

/*!
\par Function:
Gets total content duration.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_stream</td>
		<td>DLNA player stream descriptor</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_duration</td>
		<td>Pointer to buffer that stores total content duration (seconds)</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_NOTSUPPORTED Not supported
\par Description:
This function stores the total content duration in out_duration.

Implementation of this function is required only when creating a DMR application.
*/
slim_int
dlnaPlayerGetDurationPeer(dlna_player_stream *in_stream, slim_word *out_duration);

/*!
\par Function:
Gets time elapsed since content play started.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_stream</td>
		<td>DLNA player stream descriptor</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_timepos</td>
		<td>Pointer to buffer that stores time elapsed since content play started (seconds)</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_NOTSUPPORTED Not supported
\par Description:
This function stores the time elapsed since content playback started in out_timepos.

Implementation of this function is required only when creating a DMR application.
*/
slim_int
dlnaPlayerGetTimePosPeer(dlna_player_stream *in_stream, slim_word *out_timepos);

/*!
\par Function:
Gets playback position.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_stream</td>
		<td>DLNA player stream descriptor</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_counterpos</td>
		<td>Pointer to buffer that stores playback position (bytes)</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\return SLIM_E_NOTSUPPORTED Not supported
\par Description:
This function stores the playback position of the content in out_counterpos.
*/
slim_int
dlnaPlayerGetCounterPosPeer (dlna_player_stream *in_stream, dlna_uint64 *out_counterpos);

/*!
\par Function:
Gets content size in bytes.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_stream</td>
		<td>DLNA player stream descriptor</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_size</td>
		<td>Pointer to buffer that stores content size in bytes which is being rendering</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\return SLIM_E_NOTSUPPORTED Not supported
\par Description:
This function stores the bytes length of the content in out_size.
*/
slim_int
dlnaPlayerGetCounterSizePeer (dlna_player_stream *in_stream, dlna_uint64 *out_size);

/*@}*/

/**
 * @addtogroup macros
 */
/*@{*/

#define PEER_DLNA_PLAYER_SUPPORT_TIME_SEEK     (1 << 0)
#define PEER_DLNA_PLAYER_SUPPORT_COUNTER_SEEK  (1 << 1)

/*@}*/

/**
 * @addtogroup structures
 */
/*@{*/

struct peer_play_speed {
    int speed;
    int speed_den;
};
typedef struct peer_play_speed peer_play_speed_t;

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Gets the seek capability flags during rendering.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_stream</td>
		<td>DLNA player stream descriptor</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_seek_capability_flag</td>
		<td>Pointer to buffer that stores flags of seekable value</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\return SLIM_E_NOTSUPPORTED Not supported
\par Description:
This function stores the seek capability flags in out_seek_capability_flag, which indicates time-seek
or/and byte-seek is available or not.

Logical OR of the following flags is stored in out_seek_capability_flag.

- Support time-controller seek operation: PEER_DLNA_PLAYER_SUPPURT_TIME_SEEK
- Support byte-controller seek operation: PEER_DLNA_PLAYER_SUPPURT_BYTE_SEEK
*/
slim_int
dlnaPlayerGetSeekCapabilityPeer (dlna_player_stream *in_stream, slim_word *out_seek_capability_flag);

/*!
\par Function:
Gets allowed playback speed list during rendering.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_stream</td>
		<td>DLNA player stream descriptor</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_ps_buf</td>
		<td>Pointer to buffer that stores allowed playback speed list</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_buf_len</td>
		<td>Length of out_ps_buf</td>
	</tr>
</table>

\return >=0 Number of the playback speed
\return -1 Failed
\par Description:
This function gets the allowed playback speed list during rendering the content in out_ps_buf.

To get allowed playback speed list, this function should be called twice by the following procedure.

-# Calls this function specifying slim_nil for out_ps_buf, and gets the number of playback
speed from return value.
-# Allocates memory area for storing playback speed list, according to the number of playback
speed obtained in step 1.
-# Calls this function again, specifying a pointer to the memory area allocated in step 2 for
out_ps_buf, and gets the playback speed list.

*/
slim_int
dlnaPlayerGetAllowedPlaySpeedPeer (dlna_player_stream in_stream, peer_play_speed_t *out_ps_buf, slim_int in_buf_len);

/*@}*/

/**
 * @addtogroup macros
 */
/*@{*/

/* DLNA network interface API.  */
#define DLNA_ETHER_ADDR_LEN        (6)

/*@}*/

/**
 * @addtogroup enums
 */
/*@{*/
enum dlna_netif_wakesupportedtransport_
{
  DLNA_NETIF_WST_UDP_BROADCAST,
  DLNA_NETIF_WST_UDP_UNICAST,
  DLNA_NETIF_WST_TCP_UNICAST,
  DLNA_NETIF_WST_OTHER
};
/*!
dlna_netif_wakesupportedtransport_ represents the DLNA network interface WakeSupportedTransport type.

<table>
	<tr>
		<td><b>Definition</b></td>
		<td><b>Type details</b></td>
	</tr>
	<tr>
		<td>DLNA_NETIF_WST_UDP_BROADCAST</td>
		<td>WakeSupportedTransport is UDP Broadcast</td>
	</tr>
	<tr>
		<td>DLNA_NETIF_WST_UDP_UNICAST</td>
		<td>WakeSupportedTransport is UDP Unicast</td>
	</tr>
	<tr>
		<td>DLNA_NETIF_WST_TCP_UNICAST</td>
		<td>WakeSupportedTransport is TCP Unicast</td>
	</tr>
	<tr>
		<td>DLNA_NETIF_WST_OTHER</td>
		<td>WakeSupportedTransport is other then above</td>
	</tr>
</table>

*/
typedef enum dlna_netif_wakesupportedtransport_ dlna_netif_wst;

/*@}*/

/**
 * @addtogroup structures
 */
/*@{*/

struct dlna_interface_
{
  /* Interface index.  */
  slim_int ifindex;

  /* Interface name.  */
  slim_char *name;

  /* Interface description.  */
  slim_char *desc;

  /* WakeOnPatter hex.  */
  slim_char *wop;

  /* WakeSupportedTransport.  */
  dlna_netif_wst wst;

  /* MaxWaitOnDelay.  */
  slim_int wod;

  /* DozeDuration.  */
  slim_int doze;

  /* Interface flags.  */
  slim_word flags;
#define DLNA_IF_UP                              (1 << 0)
#define DLNA_IF_RUNNING                         (1 << 1)
#define DLNA_IF_MULTICAST                       (1 << 2)
#define DLNA_IF_LOOPBACK                        (1 << 3)
#define DLNA_IF_BROADCAST                       (1 << 4)
#define DLNA_IF_POINTOPOINT                     (1 << 5)
#define DLNA_IF_ETHERNET                        (1 << 6)
#define DLNA_IF_WIFI                            (1 << 7)
#define DLNA_IF_MODE_UNIMPLEMENTED              (1 << 8)
#define DLNA_IF_MODE_IP_UP                      (1 << 9)
#define DLNA_IF_MODE_IP_UP_PERIODIC             (1 << 10)
#define DLNA_IF_MODE_IP_DOWN_NO_WAKE            (1 << 11)
#define DLNA_IF_MODE_IP_DOWN_WITH_WAKE_ON       (1 << 12)
#define DLNA_IF_MODE_IP_DOWN_WITH_WAKE_AUTO     (1 << 13)
#define DLNA_IF_MODE_IP_DOWN_WITH_WAKE_ON_AUTO  (1 << 14)

  /* Mac address of the interface.  */
  slim_byte mac[DLNA_ETHER_ADDR_LEN];
};

/*!
DLNA interface descriptor.

\code
struct _dlna_interface{
slim_int ifindex;
slim_char *name;
slim_char *desc;
slim_char *wop;
dlna_netif_wst wst;
slim_int wod;
slim_int doze;
slim_word flags;
slim_byte mac[6];
};
typedef struct _dlna_interface dlna_interface;
\endcode
\par Member:

<table>
	<tr>
		<td>ifindex</td>
		<td>Value that identifies interface (integer larger than 1)<br/>
			It is used to specify interfaces in multicast network operation, etc.</td>
	</tr>
	<tr>
		<td>name</td>
		<td>Interface name (option)</td>
	</tr>
	<tr>
		<td>desc</td>
		<td>Interface description (option)</td>
	</tr>
	<tr>
		<td>wop</td>
		<td>WakeOnPattern string (option)</td>
	</tr>
	<tr>
		<td>wst</td>
		<td>WakeSupportedTransport value (option)</td>
	</tr>
	<tr>
		<td>wod</td>
		<td>MaxWaitOnDelay value in seconds (option)</td>
	</tr>
	<tr>
		<td>doze</td>
		<td>DozeDuration value in milliseconds (option)</td>
	</tr>
	<tr>
		<td>flag</td>
		<td>Flag that indicates interface capability<br/>
			DLNA_IF_UP Interface is available<br/>
			DLNA_IF_RUNNING Local IP address has been obtained<br/>
			DLNA_IF_MULTICAST Multicasting is supported<br/>
			DLNA_IF_BROADCAST Broadcasting is supported<br/>
			DLNA_IF_LOOPBACK Interface for internal loopback<br/>
			DLNA_IF_POINTOPOINT Not used<br/>
      DLNA_IF_MODE_UNIMPLEMENTED No information regarding any low power interface mode<br/>
      DLNA_IF_MODE_IP_UP Interface is fully operational<br/>
      DLNA_IF_MODE_IP_UP_PERIODIC Interface will be periodically unavailable for durations of 2 second or less<br/>
      DLNA_IF_MODE_IP_DOWN_NO_WAKE Interface is down<br/>
      DLNA_IF_MODE_IP_DOWN_WITH_WAKE_ON Interface is down and can be woken externally<br/>
      DLNA_IF_MODE_IP_DOWN_WITH_WAKE_AUTO Interface is in doze state for 2 seconds or less, and will be woken internally<br/>
      DLNA_IF_MODE_IP_DOWN_WITH_WAKE_ON_AUTO Interface is in doze state for 2 seconds or less, can be woken internally or externally</td>
	</tr>
	<tr>
		<td>mac</td>
		<td>Local MAC address (used to generate UUID)</td>
	</tr>
</table>

*/
typedef struct dlna_interface_ dlna_interface;

struct dlna_prefix_
{
  /* Interface index to which the address belongs.  */
  slim_int ifindex;

#ifdef DLNA_DMS_SUPPORT_IF_STORAGE_FILTER
  /* Interface name */
  slim_char *ifname;
#endif /* DLNA_DMS_SUPPORT_IF_STORAGE_FILTER */

  /* Address.  */
  dlna_ip_addr addr;

  /* Prefix length.  */
  slim_byte prefixlen;
};
/*!
Type for IP prefix.

\code
struct _dlna_prefix{
slim_int ifindex;
dlna_ip_addr addr;
slim_byte prefixlen;
};
typedef struct _dlna_prefix dlna_prefix;
\endcode
\par Member:

<table>
	<tr>
		<td>ifindex</td>
		<td>Value that identifies interface (integer larger than 1)<br/>
		It is used to specify interfaces in multicast network operation, etc.</td>
	</tr>
	<tr>
		<td>addr</td>
		<td>IP address</td>
	</tr>
	<tr>
		<td>prefixlen</td>
		<td>Length of top part (prefix) that has common subnets</td>
	</tr>
</table>

*/
typedef struct dlna_prefix_ dlna_prefix;

/*@}*/

/**
 * @addtogroup enums
 */
/*@{*/
enum dlna_netif_event_
{
  DLNA_NETIF_IF_ADD,
  DLNA_NETIF_IF_DELETE,
  DLNA_NETIF_ADDRESS_ADD,
  DLNA_NETIF_ADDRESS_DELETE,
  DLNA_NETIF_MODE_UPDATE
};
/*!
dlna_netif_event represents the DLNA network interface event value of which NFLC core is
notified.

<table>
	<tr>
		<td><b> Definition</b></td>
		<td><b>Event details</b></td>
	</tr>
	<tr>
		<td>DLNA_NETIF_IF_ADD</td>
		<td>Add network interface</td>
	</tr>
	<tr>
		<td>DLNA_NETIF_IF_DELETE</td>
		<td>Delete network interface</td>
	</tr>
	<tr>
		<td>DLNA_NETIF_ADDRESS_ADD</td>
		<td>Add IP address</td>
	</tr>
	<tr>
		<td>DLNA_NETIF_ADDRESS_DELETE</td>
		<td>Delete IP address</td>
	</tr>
	<tr>
		<td>DLNA_NETIF_MODE_UPDATE</td>
		<td>Network interface mode update</td>
	</tr>
</table>

*/
typedef enum dlna_netif_event_ dlna_netif_event;

/*@}*/

/**
 * @addtogroup datatypes
 */
/*@{*/

/*!
DLNA network interface manager descriptor.
*/
typedef void *dlna_netif;

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
DLNA network interface callback descriptor.

\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_event</td>
		<td>DLNA network interface event value</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>in_arg specified using dlnaNetIfAllocPeer()</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_param</td>
		<td>Address of type structure of DLNA interface descriptor or IP prefix. Specify
			by distributing among DLNA network interface events. Each structure must
			be allocated by auto variable etc. in the internal function on the interface
			side.
		</td>
	</tr>
</table>
<br/>
<table>
	<tr>
		<td><b>DLNA network interface event value</b></td>
		<td><b>in_param</b></td>
	</tr>
	<tr>
		<td>DLNA_NETIF_IF_ADD<br/>
			DLNA_NETIF_IF_DELETE</td>
		<td>Address of DLNA interface descriptor(dlna_interface) structure</td>
	</tr>
	<tr>
		<td>DLNA_NETIF_ADDRESS_ADD<br/>
			DLNA_NETIF_ADDRESS_DELETE</td>
		<td>Address of IP prefix (dlna_prefix) structure</td>
	</tr>
	<tr>
		<td>DLNA_NETIF_MODE_UPDATE</td>
		<td>Address of DLNA interface descriptor(dlna_interface) structure<br/>
		Field flag and mac are required, others not in use for this event.</td>
	</tr>
</table>

\return Not currently used.

*/
typedef slim_int (*dlna_netif_callback)(dlna_netif_event in_event,
                                        void *in_arg, void *in_param);

/*!
\par Function:
Allocates DLNA network interface manager.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_p</td>
		<td>DLNA progress manager descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_callback</td>
		<td>Callback function that notifies of network interface event</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument of in_callback</td>
	</tr>
</table>

\return != slim_nil DLNA network interface manager descriptor
\return == slim_nil Error occurred
\par Description:
This function allocates a DLNA network interface manager and returns the interface manager
descriptor.

The returned interface manager descriptor becomes an argument of the API that is called
subsequently.

in_callback is enabled after dlnaNetIfStartPeer() is called.
*/
dlna_netif
dlnaNetIfAllocPeer(dlna_progress in_p, dlna_netif_callback in_callback,
                   void *in_arg);

/*!
\par Function:
Releases DLNA network interface manager.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_netif</td>
		<td>DLNA network interface manager descriptor</td>
	</tr>
</table>

\return None
\par Description:
This function releases the DLNA network interface manager.
*/
void
dlnaNetIfFreePeer(dlna_netif in_netif);

/*!
\par Function:
Starts DLNA network interface manager.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_netif</td>
		<td>DLNA network interface manager descriptor</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\par Description:
This function starts up the DLNA network interface manager.

If enabling and disabling of the network interface is switched after calling this function, the callback
function specified by dlnaNetIfAllocPeer() is called to notify the NFLC core of the change.

When the network interface is enabled, DLNA_NETIF_IF_ADD and the pointer to dlna_interface
are specified for in_event and in_param of the callback function respectively.

When the network interface is disabled, DLNA_NETIF_IF_DELETE and the pointer to
dlna_interface are specified for in_event and in_param of the callback function respectively.

Callback functions must not be called within this function.
*/
slim_int
dlnaNetIfStartPeer(dlna_netif in_netif);

slim_int
dlnaNetIfPortOpenPeer(slim_char *in_netif, slim_int in_port);

/*!
\par Function:
Stops DLNA network interface manager.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_netif</td>
		<td>DLNA network interface manager descriptor</td>
	</tr>
</table>

\return None
\par Description:
This function stops notifying of the enabling/disabling of the network interface started by
dlnaNetIfStartPeer().
*/
void
dlnaNetIfStopPeer(dlna_netif in_netif);

/*!
\par Function:
Starts notifying of IP address addition/deletion.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_netif</td>
		<td>DLNA network interface manager descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_ifindex</td>
		<td>DLNA network interface manager index</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\par Description:
This function starts notifying of IP address additions/deletions.

It adds an IP address to the specified network interface.

After this function is called, if any IP address is added to or deleted from the network interface specified
by the index in_ifindex, then the function calls the callback function specified by
dlnaNetIfAllocPeer() to notify the NFLC core of the event.

When an IP address is added, DLNA_NETIF_ADDRESS_ADD and the pointer to dlna_prefix are
specified for in_event and in_param of the callback function respectively.

When an IP address is deleted, DLNA_NETIF_ADDRESS_DELETE and the pointer to dlna_prefix
are specified for in_event and in_param of the callback function respectively.

It is not necessary to add an IP address if one has already been added, but the notification of the same
needs to be sent to the NFLC core.

in_callback cannot be called within this function.
*/
slim_int
dlnaNetIfInterfaceStartPeer(dlna_netif in_netif, slim_int in_ifindex);

/*!
\par Function:
Stops notifying of IP address addition/deletion.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_netif</td>
		<td>DLNA network interface manager descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_ifindex</td>
		<td>DLNA network interface manager index</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\par Description:
This function stops notifying of additions/deletions of IP addresses started by
dlnaNetIfInterfaceStartPeer().
*/
slim_int
dlnaNetIfInterfaceStopPeer(dlna_netif in_netif, slim_int in_ifindex);

/*@}*/

#ifdef USE_RESIZE_IMAGE_PEER

/**
 * @addtogroup macros
 */
/*@{*/

/*! Image type for dlnaResizeImagePeer(). */
#define PEER_IMAGE_TYPE_OTHER     0
#define PEER_IMAGE_TYPE_JPEG      1
#define PEER_IMAGE_TYPE_PNG       2
#define PEER_IMAGE_TYPE_GIF       3
#define PEER_IMAGE_TYPE_BMP       4

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/* Image resize PeerAPI */

/*!
\par Function:
Converts image size.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_src_filepath</td>
		<td>Path to image to convert</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_dest_filepath</td>
		<td>Path to output destination of converted image</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_width</td>
		<td>Width after image size conversion (pixels)</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_height</td>
		<td>Height after image size conversion (pixels)</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_format</td>
		<td>Image format<br/>
			PEER_IMAGE_TYPE_JPEG JPEG image<br/>
			PEER_IMAGE_TYPE_PNG PNG image<br/>
			PEER_IMAGE_TYPE_GIF GIF image<br/>
			PEER_IMAGE_TYPE_BMP BMP image<br/>
			PEER_IMAGE_TYPE_OHTER Other image format
		</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed

\par Description:
This function converts the size of the image specified by in_src_filepath. The converted image is output
to the path specified by in_dest_filepath.

Implementation of this function is required only when the macro USE_RESIZE_IMAGE_PEER in
dlna_config.h is configured during DMS implementation. If the macro is not configured, NFLC core
performs the equivalent process internally and this function does not need to be implemented. In this
case, however, only JPEG images are supported.

This function is called when a request to download thumbnail images is accepted.

The image formats for which the DMS supports image size conversion is specified by
enabling/disabling the following four macros defined in dlna_config.h:

- USE_RESIZE_IMAGE_JPEG
- USE_RESIZE_IMAGE_PNG
- USE_RESIZE_IMAGE_GIF
- USE_RESIZE_IMAGE_BMP

The format of the image specified for in_src_filepath is specified for in_format. The image format to be
output to in_dest_filepath is the same as in_format.

Width and height of the image after conversion are specified for in_width and in_height respectively.

In any of the following cases, SLIM_E_GENERIC is returned.

- An image format for which size conversion is not supported is specified for in_format
- The image specified for in_src_filepath cannot be output in the image format specified for in_format
- The image cannot be converted to the size specified by in_width and in_height

*/
slim_int
dlnaResizeImagePeer(slim_char *in_src_filepath, slim_char *in_dest_filepath,
                    slim_int in_width, slim_int in_height, slim_int in_format);

/*@}*/

#endif /* USE_RESIZE_IMAGE_PEER */

/* Directory Change Notification (DCN) PeerAPIs.  */

/**
 * @addtogroup datatypes
 */
/*@{*/

/*!
Pointer to structure that manages directory change.

Since the NFLC core never accesses it internally, porting layer-dependent information can be stored.
*/
typedef void *dlna_dcn;

/*@}*/

enum dcn_reaction_type_t {
  DLNA_DCN_REACTION_TYPE_REINDEX,
  DLNA_DCN_REACTION_TYPE_DELETE,
  DLNA_DCN_REACTION_TYPE_UNKNOWN
};
typedef enum dcn_reaction_type_t dcn_reaction_type;

#ifdef ENABLE_DCN_INOTIFY

/**
 * @addtogroup enums
 */
/*@{*/

enum {
  DLNA_DCN_CHANGE_TYPE_CREATE,
  DLNA_DCN_CHANGE_TYPE_MOVE_TO,
  DLNA_DCN_CHANGE_TYPE_MOVE_FROM,
  DLNA_DCN_CHANGE_TYPE_MOVE_SELF,
  DLNA_DCN_CHANGE_TYPE_DELETE,
  DLNA_DCN_CHANGE_TYPE_DELETE_SELF,
  DLNA_DCN_CHANGE_TYPE_CLOSE_WRITE,
  DLNA_DCN_CHANGE_TYPE_OPEN,
  DLNA_DCN_CHANGE_TYPE_UNKNOWN
};
typedef slim_int dcn_change_type;

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Allocates directory change notification object.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_p</td>
		<td>DLNA progress manager descriptor</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_callback</td>
		<td>Callback function that notifies of directory change</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument of in_callback</td>
	</tr>
</table>


\return != slim_nil Directory change notification object
\return == slim_nil Error
\par Description:
This function allocates a directory change notification object.

After dlnaDCNStartPeer() is called, the callback function specified for in_callback is called with the
argument in_arg when the content of a directory changes.

The structure of the directory change notification itself depends on the target system. The structure
must be defined in the Peer and cast to the dlna_dcn type, which represents a void pointer type.
*/

typedef slim_int (*dlna_dcn_callback) (slim_char *in_path, void *in_arg, dcn_reaction_type r_type);

typedef slim_bool (*is_file_excluded_callback)(void * in_arg,
    slim_char * in_path, slim_bool is_dir);

dlna_dcn
dlnaDCNAllocPeer(dlna_progress in_p, dlna_dcn_callback in_callback,
    is_file_excluded_callback is_file_excluded, void *in_arg);


#else /* ENABLE_DCN_INOTIFY */
dlna_dcn
dlnaDCNAllocPeer(dlna_progress in_p, dlna_progress_callback in_callback, void *in_arg);
typedef slim_bool (*is_file_excluded_callback)(void * in_arg, slim_char * in_path, slim_bool is_dir);
#endif /* ENABLE_DCN_INOTIFY */



/*!
\par Function:
Releases directory change notification object.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_dcn</td>
		<td>Directory change notification object</td>
	</tr>
</table>




\return None
\par Description:
This function releases a directory change notification object.
*/
void
dlnaDCNFreePeer(dlna_dcn in_dcn);

/*!
\par Function:
Starts directory change notification object.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_dcn</td>
		<td>Directory change notification object</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_dir</td>
		<td>Full path of directory targeted for notification</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\par Description:
This function starts the notification of changes in the specified directory.

If the content of the directory specified for in_dir changes after calling this function, the callback function
specified by dlnaDCNAllocPeer() is called with the argument in_arg specified by
dlnaDCNAllocPeer().
*/
slim_int
dlnaDCNStartPeer(dlna_dcn in_dcn, slim_char *in_dir);

/*!
\par Function:
Stops directory change notification object.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_dcn</td>
		<td>Directory change notification object</td>
	</tr>
</table>

\return None
\par Description:
This function stops the directory change notification started by dlnaDCNStartPeer().

Do not call the callback function specified by dlnaDCNAllocPeer() after this function is called.
*/
void
dlnaDCNStopPeer(dlna_dcn in_dcn);

#ifdef ENABLE_DCN_INOTIFY
/*!
\par Function:
Gets path to recently changed directory.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_dcn</td>
		<td>Directory change notification object</td>
	</tr>
</table>

\return != slim_nil Path to recently changed directory (string)
\return == slim_nil Error
\par Description:
This function returns the path to the recently changed directory.

This function can be called only when ENABLE_DCN_INOTIFY feature is defined in Rule.in.

For more information about Rule.in, see readme_e.txt in the NFLC SDK package.
*/
slim_char*
dlnaDCNGetRecentPath (dlna_dcn in_dcn);


#ifdef ENABLE_DCN_INOTIFY
/*!
\par Function:
Adds path to INOTIFY
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_dcn</td>
    <td>Directory change notification object</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_device_path</td>
    <td>Path to device</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_path</td>
    <td>Path to directory</td>
  </tr>
</table>


\par Description:
This function registers in_path in INOTIFY.
in_device_path is used to store relative path for future use.
*/
void
dlnaDCNAddDirectoryToWatchList(dlna_dcn in_dcn,
    slim_char * in_device_path,
    slim_char * in_path);

#endif /* ENABLE_DCN_INOTIFY */


/*!
\par Function:
Gets change type of the recently changed directory.
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>in_dcn</td>
                <td>Directory change notification object</td>
        </tr>
</table>

\return = 1 Content has been Created or Moved Into
\return = 0 Content has been Deleted or Moved From
\return = -1 Error
\par Description:
This function returns if a new content has been created(moved into) or deleted (moved from) from directories being watched for.
For more information about Rule.in, see readme_e.txt in the NFLC SDK package.
*/
slim_int
dlnaDCNGetChangeType(dlna_dcn in_dcn);

slim_int
dlnaDCNGetRecentChangeIsDir(dlna_dcn in_dcn);

void
dlnaDCNRemoveDirectoryFromWatchList(dlna_dcn in_dcn, slim_char* in_dir);

void
dlnaDCNResetChanged(dlna_dcn in_dcn);

void
dlnaDCNPause(dlna_dcn in_dcn);

void
dlnaDCNResume(dlna_dcn in_dcn);
#endif /* ENABLE_DCN_INOTIFY */

/* Charset converter */
#ifndef USE_SLIM_I18N
/*!
\par Function:
Converts string with known encoding to UTF-8.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_s</td>
		<td>Pointer to string to convert</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_nbytes</td>
		<td>Length of in_s (bytes)</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_charset</td>
		<td>Charset of in_s</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_buf</td>
		<td>Pointer to string with UTF-8 encoding</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_read_bytes</td>
		<td>Pointer to length of out_buf</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\par Description:
This function converts a string with a known encoding to UTF-8.

This function is controlled by the USE_SLIM_I18N macro. When macro USE_SLIM_I18N is enabled,
the encoding conversion in the SLIM library is used, so this function does not have to be implemented.

The values in Table 1 can be specified for in_charset.

<table>
	<tr>
		<td align='center'><b>Table 1</b></td>
	</tr>
	<tr>
		<td>DLNA_CHARSET_US_ASCII</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_SHIFT_JIS</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_EUC_JP</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_ISO_2022_JP</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_ISO_8859_1</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_WINDOWS_1252</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_EUC_KR</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_UHC</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_GB2312</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_GBK</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_GB18030</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_BIG5</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_ISO_8859_4</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_WINDOWS_1257</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_ISO_8859_2</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_WINDOWS_1250</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_ISO_8859_5</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_WINDOWS_1251</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_KOI8_R</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_ISO_8859_7</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_WINDOWS_1253</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_ISO_8859_10</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_ISO_8859_3</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_WINDOWS_874</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_ISO_8859_9</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_WINDOWS_1254</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_ISO_8859_6</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_WINDOWS_1256</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_ISO_8859_8</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_ISO_8859_8_I</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_WINDOWS_1255</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_UTF_8</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_UTF_16BE</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_UTF_16LE</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_UCS_2BE</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_UCS_2LE</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_UCS_4BE</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_UCS_4LE</td>
    </tr>
</table>

*/
slim_int
dlnaConvertToUTF8Peer(slim_byte *in_s, slim_int in_nbytes,
                      slim_int in_charset,
                      slim_byte *out_buf, slim_int *out_read_bytes);

/*!
\par Function:
Converts string with known encoding to UTF-8.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_s</td>
		<td>Pointer to string to convert</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_nbytes</td>
		<td>Length of in_s (bytes)</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_hints</td>
		<td>Most possible charset of in_s</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_buf</td>
		<td>Pointer to string with UTF-8 encoding</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_read_bytes</td>
		<td>Pointer to length of out_buf</td>
	</tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed
\par Description:
This function converts string with unknown encoding to UTF-8 encoding.

This function is controlled by the USE_SLIM_I18N macro. When macro USE_SLIM_I18N is enabled,
the encoding conversion in the SLIM library is used, so this function does not have to be implemented.

The values in Table 1Table 1 and Table 2Table 2 can be specified for in_hints.

<table>
	<tr>
		<td align='center'><b>Table 2</b></td>
	</tr>
	<tr>
		<td>DLNA_CHARSET_UNCERTAIN</td>
    </tr>
	<tr>
		<td>DLNA_CHARSET_UNKNOWN</td>
    </tr>
</table>
*/
slim_int
dlnaGuessConvertToUTF8Peer(slim_byte *in_s, slim_int in_nbytes,
                           slim_int in_hints,
                           slim_byte *out_buf, slim_int *out_read_bytes);
#endif /* USE_SLIM_I18N */

/*!
\par Function:
Gets SinkProtocolInfo strings from xml file on target.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_protocol_info_path</td>
		<td>Directory path of the xml file that describes the SinkProtocolInfo of the DMR</td>
	</tr>
</table>

\return != slim_nil SinkProtocolInfo strings
\return == slim_nil Error occurred
\par Description:
This function reads an xml file that describes the SinkProtocolInfo of the DMR and returns the strings
as a comma-separated-list format.

For more information about SinkProtocolInfo, see "UPnP AV ConnectionManager:1 Service Template
Version 1.01".

The file path to the xml file is composed of two strings. One is in_protocol_info_path, which describes the
directory path, and the other is DLNA_SINK_PROTOCOL_INFO_XML, which describes the xml file name.
The value of DLNA_SINK_PROTOCOL_INFO_XML is defined in dlna_config.h.

The SinkProtocolInfo strings must be described in the xml file as in the example shown below:

If the xml file does not exist on the target system or it is an invalid format, return slim_nil as a return
value.
\code
<?xml version="1.0" encoding="utf-8"?>
<SinkProtocolInfo>
<protocolInfo>http-get:*:image/jpeg:DLNA.ORG_PN=JPEG_SM</protocolInfo>
<protocolInfo>http-get:*:audio/mpeg:DLNA.ORG_PN=MP3</protocolInfo>
<protocolInfo>http-get:*:audio/mp4:DLNA.ORG_PN=AAC_ISO_320</protocolInfo>
</SinkProtocolInfo>
\endcode

The output value of this function is a comma-separated-list that describes each <protocolInfo>
value as in the example shown below.
\code
http-get:*:image/jpeg:DLNA.ORG_PN=JPEG_SM,http-get:*:audio/mpeg:DLNA.ORG_PN
=MP3,http-get:*:audio/mp4:DLNA.ORG_PN=AAC_ISO_320
\endcode

*/
slim_char*
dlnaDMRSinkProtocolInfoPeer(slim_char *in_protocol_info_path);

#ifdef DLNA_SUPPORT_RUIPL

/*!
\par Function:
Gets RUI client capability list from xml file on target.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>in_path</td>
		<td>Directory path of the xml file that describes RUI client capability list</td>
	</tr>
</table>

\return != slim_nil RUI client capability list string
\return == slim_nil Error occurred
\par Description:
This function reads an xml file that describes RUI client capability list.

For more information about the RUI client capability, see "CEA-2014 revision A"

The file path to the xml file is composed of two strings. One is in_path, which describes the directory
path, and the other is RUI_CLIENT_CAPABILITY_XML, which describes the xml file name. The value
of RUI_CLIENT_CAPABILITY_XML is defined in dlna_config.h.

The RUI client capability list must be described in the xml file as in the example shown below:

If the xml file does not exist on the target or it is an invalid format, return slim_nil as a return value.

\code
<?xml version="1.0" encoding="utf-8"?>
<profilelist>
<ui_profile name="SD_UIPROF">
<ext>
<hscroll>true</hscroll>
<notificationscripts>true</notificationscripts>
<security protocolNames="tls ssl">true</security>
</ext>
</ui_profile>
<audio_profile name="MP3" type="audio/mpeg"/>
<video_profile name="MPEG_PS_PAL" type="video/mpeg"/>
</profilelist>
\endcode

*/
slim_char *
dlnaRUIClientCapabilityPeer(slim_char *in_path);
#endif /* DLNA_SUPPORT_RUIPL */

/*@}*/

#ifdef __cplusplus
}
#endif

/**
 * @addtogroup macros
 */

#define DLNA_TIMEVAL_GET(x)    \
	dlna_timeval_get((x));     \
	DLNA_DEBUG_MSG(IS_DEBUG_TIMEVAL_VALUE, ("[dlna_timeval_get]FILE:[%s]LINE[%d] sec[%d] usec[%d]\n", __FILE__, __LINE__, (x)->tv_sec, (x)->tv_usec));


/* Platform dependent peer implementation header.  */
#include <peer_plat.h>


/* Printer support */

#ifdef DEVELOPMENT_DLNA_SUPPORT_DMPR_DEVICE

/**
 * @addtogroup enums
 */
/*@{*/

enum dlna_dmpr_unit
{
  DLNA_DMPR_UNIT_MM = 0,
  DLNA_DMPR_UNIT_INCH
};

enum dlna_dmprd_orientation
{
  DLNA_DMPRD_ORIENTATION_LANDSCAPE = 0,
  DLNA_DMPRD_ORIENTATION_PORTRAIT,
  DLNA_DMPRD_ORIENTATION_REVERSE_PORTRAIT, /* 180 deg */
  DLNA_DMPRD_ORIENTATION_REVERSE_LANDSCAPE, /* 270 deg */
  DLNA_DMPRD_ORIENTATION_DEVICESETTING 
};

enum dlna_dmpr_printquality
{
  DLNA_DMPRD_QUALITY_DRAFT = 0,
  DLNA_DMPRD_QUALITY_NORMAL,
  DLNA_DMPRD_QUALITY_HIGH,
  DLNA_DMPRD_QUALITY_DEVICESETTING
};

enum dlna_dmpr_sides
{
  DLNA_DMPRD_SIDES_ONE_SIDE = 0,
  DLNA_DMPRD_SIDES_TWO_SIDED_LONG_EDGE,
  DLNA_DMPRD_SIDES_TWO_SIDED_SHORT_EDGE,
  DLNA_DMPRD_SIDES_DEVICESETTING
};

enum dlna_dmpr_numberup
{
  DLNA_DMPRD_NUMBERUP_ONE_PAGE = 0,
  DLNA_DMPRD_NUMBERUP_TWO_PAGES,
  DLNA_DMPRD_NUMBERUP_FOUR_PAGES,
  DLNA_DMPRD_NUMBERUP_DEVICESETTING
};

enum dlna_dmpr_events
{
	DMPr_EVT_PRINT_STARTED = 0,
	DMPr_EVT_PRINT_COMPLETED,
	DMPr_EVT_PRINT_CANCELED,
	DMPr_EVT_PRINT_INIT_OK,
	DMPr_EVT_PRINT_INIT_FAILED,
	DMPr_EVT_PRINT_STATUS,
	DMPr_EVT_PRINT_CONTENT_COMPLETE,
	DMPr_EVT_PRINT_SHEETS_COMPLETED,

	DMPr_EVT_PRINT_ADD_JOB,
	DMPr_EVT_PRINT_UPD_JOB,
	DMPr_EVT_PRINT_DEL_JOB
} ;

enum dlna_dmpr_printer_states
{
	DMPr_STATE_IDLE = 1,
	DMPr_STATE_PROCESSING,
	DMPr_STATE_STOPPED
} ;
//KK add to doc
enum dlna_dmpr_job_states
{
	DMPr_JOB_STATE_SUCCESSFUL = 1,
	DMPr_JOB_STATE_CANCELED,
	DMPr_JOB_STATE_ABORTED
} ;
//KK add to doc
enum dlna_dmpr_job_abort_reasons
{
	DMPr_JOB_ABORT_REASON_NONE = 0,
	DMPr_JOB_ABORT_REASON_HARDWARE_ERROR,
	DMPr_JOB_ABORT_REASON_EXTERNAL_ACCESS_URI_NOT_FOUND,
	DMPr_JOB_ABORT_REASON_EXTERNAL_ACCESS_OBJECT_FAILURE,
	DMPr_JOB_ABORT_REASON_EXTERNAL_ACCESS_DOC_FORMAT_ERROR,
	DMPr_JOB_ABORT_REASON_EXTERNAL_ACCESS_HTTP_ERROR
} ;

enum dlna_dmpr_print_state_reasons
{
	DMPr_STATE_REASON_NONE = 0,
	DMPr_STATE_REASON_MEDIA_JAM,
	DMPr_STATE_REASON_PAUSED,
	DMPr_STATE_REASON_DOOR_OPEN,
	DMPr_STATE_REASON_MEDIA_LOW,
	DMPr_STATE_REASON_MEDIA_EMPTY,
	DMPr_STATE_REASON_OUTPUT_ALMOST_FULL,
	DMPr_STATE_REASON_OUTPUT_FULL,
	DMPr_STATE_REASON_INK_LOW,
	DMPr_STATE_REASON_INK_EMPTY,
	DMPr_STATE_REASON_INK_FAILURE,
	DMPr_STATE_REASON_MEDIA_CHANGE_REQ
} ;

/*@}*/

/**
 * @addtogroup structures
 */
/*@{*/

typedef struct DMPrMargins
{
	slim_int	unit ;
	slim_int	left;
	slim_int	right;
	slim_int	top;
	slim_int	bottom;
	slim_int	fullbleed ;
}TDMPrMargins ;

typedef struct DMPrMedia
{
	slim_char	*media_type ;	// string describing media type
	slim_char	*media_size ;	// string describing media size
} TDMPrMedia ;

typedef struct DMPrMedias
{
	slim_int	count;				// number of elements
	slim_bool	size_q;			// if question was about media size or type
	TDMPrMedia	**media ;		// array of pointers to media description pairs
} TDMPrMedias ;

typedef struct DMPrPrinterState
{
	slim_int	state;				// see DMPrPrinterState
	slim_int 	reason ;				// see DMPrPrinterStateReasons
} TDMPrPrinterState ;

typedef struct DMPrJob
{
  struct DMPrJob *next ;
  struct DMPrJob *prev ;

	slim_char *JobName;
	slim_char *JobOriginatingUserName;
	slim_char *DocumentFormat;
	slim_int  Copies;
	slim_int  Sides;
	slim_int NumberUp;
	slim_int OrientationRequested;
	slim_char *MediaSize;
	slim_char *MediaType;
	slim_int PrintQuality;
	slim_char *CriticalAttributesList;
	slim_char *SourceURI;

	slim_int	job_id ; 
	slim_int	is_content_complete ;
	slim_int	media_sheets_completed ;

	TDMPrPrinterState job_end_state ;
	TDMPrPrinterState job_abort_state ;

//  slim_int request_id;

}TDMPrJob ;

typedef List (TDMPrJob *) TDMPrJobs ;

typedef struct DMPrDeviceFeatures
{
	slim_char	*char_rep_supported ;
	slim_int  color_supported;
	slim_char *critical_attributes_supported ;
	slim_char	*device_id ;
	slim_char	*number_up ;
	slim_char	*document_format ;
	slim_char	*document_utf16_supported ;
	slim_char	*internet_connect_state ;

	slim_char *printer_location ;
	slim_char *XHTML_image_supported ;
}TDMPrDeviceFeatures ;

/*@}*/

/**
 * @addtogroup datatypes
 */
/*@{*/

typedef void * TDMPrContext ;

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

typedef void (*DMPrNotifyCallback)(slim_int in_event, void *in_data, void *in_arg) ;

TDMPrContext *dlnaPrinterInitializePeer(DMPrNotifyCallback in_callback, void *in_arg);

void dlnaPrinterFinalizePeer(TDMPrContext *in_context) ;

slim_int dlnaPrinterGetMarginsPeer(TDMPrContext *in_context, TDMPrMedia *in_media,TDMPrMargins *out_margins);

slim_int dlnaPrinterGetMediasPeer(TDMPrContext *in_context, TDMPrMedia *in_media, TDMPrMedias *out_medias);

slim_int dlnaPrinterxHTMLPrintPeer(TDMPrContext *in_context,TDMPrJob *in_job) ;

slim_int dlnaPrinterCancelPrintPeer(TDMPrContext *in_context, slim_int in_jobid);

slim_int dlnaPrinterGetDeviceFeaturesPeer(TDMPrContext *in_context, TDMPrDeviceFeatures *out_features);

/*@}*/

#endif /* DEVELOPMENT_DLNA_SUPPORT_DMPR_DEVICE */

/**
 * @addtogroup apis
 */
/*@{*/
/*!
\par Function:
Start MPE Server
\par Parameters:

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed

\par Description:
This function starts MPE Server.
*/
slim_int dlnaMPEServerStartPeer (void);
/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/
/*!
\par Function:
Stop MPE Server
\par Parameters:

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed

\par Description:
This function stops MPE Server.
*/
slim_int dlnaMPEServerStopPeer(void);
/*@}*/

#ifdef DEVELOPMENT_ENABLE_CAS_PEER
/* CAS Peer */
/**
 * @addtogroup datatypes
 */
/*@{*/
typedef void *dlna_cas;
/*@}*/


/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Allocates the integrated Conditional Access Systems
\par Parameters:


\return !=slim_nil void pointer the initialized conditional access system
\return ==slim_nil could not initialize the conditional access system

\par Description:

This function initializes the conditional access system integrated.
Integrated CA Systems can be initialized and pointer to the context of the CA can be returned

*/
dlna_cas
dlnaConditionalAccessSystemAllocPeer(void);

/*!
\par Function:
Finalizes the Conditional Access System Integrated
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>in_context</td>
                <td>Pointer to the previously initialized CA System</td>
        </tr>
</table>

\return None

\par Description:

This function finalizes the Conditional Access Systems previously initialized

*/
void
dlnaConditionalAccessSystemFreePeer(dlna_cas in_context);

/*!
\par Function:
Finalizes the Conditional Access System Integrated
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>in_cas_context</td>
                <td>Pointer to the previously initialized CA System</td>
        </tr>
        <tr>
                <td>[in_out]</td>
                <td>out_buf</td>
                <td>Pointer to the buffer to be decrypted</td>
        </tr>
        <tr>
                <td>[out]</td>
                <td>in_len</td>
                <td>size of the buffer</td>
        </tr>
</table>

\return >0 Succeeded (number of bytes actually decrypted)
\return 0 Reached end of stream, no more data to be decrypted
\return SLIM_E_GENERIC Failed

\par Description:

This function decrypts the buffer that requires to be decrypted

*/
dlna_ssize_t
dlnaConditionalAccessSystemDecryptPeer (dlna_cas in_cas_context, void *in_out_buf, dlna_size_t in_len);
/*@}*/
#endif /*DEVELOPMENT_ENABLE_CAS_PEER*/

#ifdef DEVELOPMENT_ENABLE_HTTP_STREAMING
/* Stream APIs. */
/**
 * @addtogroup datatypes
 */
/*@{*/
typedef void *dlna_stream;
/*@}*/

/**
 * @addtogroup datatypes
 */
/*@{*/
typedef void *dlna_stream_peer;
/*@}*/

/**
 * @addtogroup datatypes
 */
/*@{*/
typedef slim_int (*dlna_stream_objectrights_change_notification_callback)(void *in_arg);
/*@}*/

dlna_stream_peer
dlnaStreamAllocPeer(dlna_progress in_progress, dlna_stream_objectrights_change_notification_callback in_callback, void *in_callbackarg);

void
dlnaStreamFreePeer(dlna_stream_peer in_stream_peer);

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Opens Stream.
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>in_stream_url</td>
                <td>The url of the stream to be opened.</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>flags</td>
                <td>flags determining the type of the stream and decryption required</td>
        </tr>
</table>

\return !=slim_nil parameter to get stream data is made and managed by platform.
\return ==slim_nil Can't make a stream.

\par Description:

This function opens the stream specified for in_stream_url.<br>
<br>

slim_nil is returned, when there is already Stream of an Open state and it cannot prepare two or more streams by the platform side.<br>
Do not edit directly the parameter specified by in_info in the porting layer.<br>
If you want to store the value of parameter in the porting layer, copy the value to the memory allocated by porting layer.
<br>
<br>
This function uses unix File open for the recording content which is locally stored on any PVR.
It initializes CURL for Live Content.
flags determine if the content is online or recorded(local) and if the decryption required.
It is implied customer implement this function to suit their use-cases.
<br>

*/
dlna_stream
dlnaStreamOpenPeer(slim_char* in_stream_url, slim_int flags);
/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Reads stream.
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>in_stream_par</td>
                <td>Parameter for stream data identification.</td>
        </tr>
        <tr>
                <td>[out]</td>
                <td>out_buf</td>
                <td>Pointer to buffer to read</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_len</td>
                <td>Number of bytes to read</td>
        </tr>
</table>

\return >0 Succeeded (number of bytes actually read)
\return 0 Reached end of stream data.
\return SLIM_E_WOULDBLOCK Unable to immediately read stream data.
\return SLIM_E_GENERIC Failed
\par Description:

This function reads the in_len bytes of stream data of in_stream_par and stores it in out_buf.

This function uses unix File red for the recording content which is locally stored on any PVR.
It fetches the content from an external host for online content.
It is implied customer implement this function to suit their use-cases.

*/
dlna_ssize_t
dlnaStreamReadPeer(dlna_stream in_stream_par, void *out_buf, dlna_size_t in_len);

#ifdef DEVELOPMENT_ENABLE_HTTP_STREAMING_SEEK
slim_int
dlnaStreamSeekPeer(dlna_stream in_stream_par, dlna_uint64 *in_offset, slim_int in_origin, slim_bool is_timeseek, dlna_uint64 *out_position);
#endif /*DEVELOPMENT_ENABLE_HTTP_STREAMING_SEEK*/
/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Closes stream.
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>in_stream_par</td>
                <td>Parameter for stream data identification.</td>
        </tr>
</table>

\return None
\par Description:

This function closes the stream of specified for in_stream_par.

This function uses unix File Close for the recording content which is locally stored on any PVR.
It finalizes the connection with the external host
It is implied customer implement this function to suit their use-cases.

*/
void
dlnaStreamClosePeer(dlna_stream in_stream_par);
/*@}*/

#endif /*DEVELOPMENT_ENABLE_HTTP_STREAMING*/

#ifdef DEVELOPMENT_DIRECT_DLNA_OBJECT
slim_opaque
dlnaDMCPushLocalServerStartPeer(slim_int* out_port);
void
dlnaDMCPushLocalServerStoptPeer(slim_opaque server_context);
#endif /*DEVELOPMENT_DMC_PUSH*/

#ifdef DLNA_DMS_SUPPORT_IF_STORAGE_FILTER

/* The `dlnaGetifaddrsPeer' function generates a linked list of these structures.
   Each element of the list describes one network interface.
   This structure replace system ifaddrs structure witch may not be included in all systems*/
struct dlna_ifaddrs
{
  struct dlna_ifaddrs *ifa_next; /* Pointer to the next structure.  */

  char *ifa_name;   /* Name of this network interface.  */
  unsigned int ifa_flags; /* Flags as from SIOCGIFFLAGS ioctl.  */

  struct sockaddr *ifa_addr;  /* Network address of this interface.  */
  struct sockaddr *ifa_netmask; /* Netmask of this interface.  */
  union
  {
    /* At most one of the following two is valid.  If the IFF_BROADCAST
       bit is set in `ifa_flags', then `ifa_broadaddr' is valid.  If the
       IFF_POINTOPOINT bit is set, then `ifa_dstaddr' is valid.
       It is never the case that both these bits are set at once.  */
    struct sockaddr *ifu_broadaddr; /* Broadcast address of this interface. */
    struct sockaddr *ifu_dstaddr; /* Point-to-point destination address.  */
  } ifa_ifu;
  /* These very same macros are defined by <net/if.h> for `struct ifaddr'.
     So if they are defined already, the existing definitions will be fine.  */
# ifndef ifa_broadaddr
#  define ifa_broadaddr ifa_ifu.ifu_broadaddr
# endif
# ifndef ifa_dstaddr
#  define ifa_dstaddr ifa_ifu.ifu_dstaddr
# endif

  void *ifa_data;   /* Address-specific data (may be unused).  */
};

/**
 * @addtogroup apis
 */
/*@{*/
/*!
\par Function:
Search for interface, or sub interface name by ip address.
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_addr</td>
    <td>IP address of interface</td>
  </tr>
    <tr>
    <td>[out]</td>
    <td>out_name</td>
    <td>Place where pointer with allocated interface name will be stored</td>
  </tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed

\par Description:
This function searches interface or sub interface name by IP address.
*/

slim_int
dlnaInterfaceSearchNameByAddrPeer(dlna_ip_addr *in_addr, slim_char **out_name);
/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/
/*!
\par Function:
Search for interface, or sub interface ip address by name.
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_addr</td>
    <td>IP address of interface</td>
  </tr>
    <tr>
    <td>[out]</td>
    <td>out_name</td>
    <td>Place where pointer with allocated interface name will be stored</td>
  </tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed

\par Description:
This function searches interface or sub interface name by IP address.
*/

slim_int
dlnaInterfaceSearchAddrByNamePeer(slim_char *in_name, dlna_ip_addr *addr);
/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/
/*!
\par Function:
Replacement for getifaddrs() function.
\par Parameters:

<table>
  <tr>
    <td>[out]</td>
    <td>in_addrs</td>
    <td>Place where adresses and related to them interfaces names will be stored</td>
  </tr>
</table>

\return SLIM_E_OK Succeeded
\return -1 Failed

\par Description:
This is replacement for not always implemented system function getifaddrs
*/
/*@}*/

slim_int
dlnaGetifaddrsPeer(struct dlna_ifaddrs **in_addrs);

/**
 * @addtogroup apis
 */
/*@{*/
/*!
\par Function:
Replacement for freeifaddrs() function.
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>ifa</td>
    <td>Address list alocated in dlnaGetifaddrsPeer function to be freed</td>
  </tr>
</table>


\par Description:
This is replacement for not always implemented system function freeifaddrs
*/

void
dlnaFreeIfAddrsPeer(struct dlna_ifaddrs *ifa);
/*@}*/

#endif /*DLNA_DMS_SUPPORT_IF_STORAGE_FILTER*/

#ifdef DLNA_SUPPORT_SATIP

/**
 * @addtogroup apis
 */
/*@{*/
/*!
\par Function:
Get SAT>IP server boot ID from non-volatile memory
\par Parameters:

<table>
  <tr>
    <td>[out]</td>
    <td>o_boot_id</td>
    <td>SAT>IP boot ID</td>
  </tr>
</table>


\par Description:
The function reads SAT>IP server boot ID from non-volatile memory, and store it to o_boot_id
*/
slim_int
dlnaGetBootIDPeer(slim_int* o_boot_id);
/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/
/*!
\par Function:
Set SAT>IP server boot ID to non-volatile memory
\par Parameters:

<table>
  <tr>
    <td>[out]</td>
    <td>in_boot_id</td>
    <td>SAT>IP boot ID</td>
  </tr>
</table>


\par Description:
The function writes SAT>IP server boot ID to non-volatile memory
*/
slim_int
dlnaSetBootIDPeer(slim_int in_boot_id);
/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/
/*!
\par Function:
Get SAT>IP server device ID from non-volatile memory
\par Parameters:

<table>
  <tr>
    <td>[out]</td>
    <td>o_device_id</td>
    <td>SAT>IP device ID</td>
  </tr>
</table>


\par Description:
The function reads SAT>IP server device ID from non-volatile memory, and store it to o_device_id
*/
slim_int
dlnaGetDeviceIDPeer(slim_int* o_device_id);
/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/
/*!
\par Function:
Set SAT>IP server device ID to non-volatile memory
\par Parameters:

<table>
  <tr>
    <td>[out]</td>
    <td>in_device_id</td>
    <td>SAT>IP device ID</td>
  </tr>
</table>


\par Description:
The function writes SAT>IP server device ID to non-volatile memory
*/
slim_int
dlnaSetDeviceIDPeer(slim_int in_device_id);
/*@}*/
#endif

#ifdef DEVELOPMENT_ENABLE_OBJECT_RIGHTS_MANAGER_PEER

#define DLNA_DEVICES_ALLOWED_UNLIMITED	-1	/* to set unlimited number */

/*!
DLNA progress manager descriptor
*/
typedef void* dlna_objectrights_context;

/*!
DLNA progress I/O callback descriptor

\par Parameters:

<table>
    <tr>
        <td>[in]</td>
        <td>in_arg</td>
        <td>in_arg callback argument</td>
    </tr>
</table>

\return Not currently used
*/
typedef slim_int (*dlna_objectrights_change_notification_callback) (void *in_arg);

/*
Copy Control Information
*/
enum dlna_dtcp_cci {
    DLNA_DTCP_CCI_COPY_FREE,
    DLNA_DTCP_CCI_COPY_FREE_EPN_ASSERTED,
    DLNA_DTCP_CCI_COPY_ONE_GEN,
    DLNA_DTCP_CCI_NO_MORE_COPIES,
    DLNA_DTCP_CCI_COPY_NEVER
};

/*
Retention State
*/
enum dlna_dtcp_retention {
    DLNA_DTCP_RETENTION_FOREVER,
    DLNA_DTCP_RETENTION_1WEEK,
    DLNA_DTCP_RETENTION_2DAYS,
    DLNA_DTCP_RETENTION_1DAYS,
    DLNA_DTCP_RETENTION_12HOURS,
    DLNA_DTCP_RETENTION_6HOURS,
    DLNA_DTCP_RETENTION_3HOURS,
    DLNA_DTCP_RETENTION_90MINUTES
};

/*!
Object Rights of a stream
*/
typedef struct _dlna_objectrights {
    slim_bool is_drm_protected; /* specifies if the stream is natively protected by CA/DRM */
    slim_bool allow_dtcp_protection; /* specifies if it is to be dtcp protected for further distribution in home network */
    enum dlna_dtcp_cci cci; /* specifies cci information for dtcp */
    enum dlna_dtcp_retention retention_state; /* retention state of dtcp */
    slim_int concurrent_viewing; /* Number of concurrent viewing allowed for this content */
    slim_int playcount; /* Number of Plays allowed for the content */
    slim_bool allow_distribution; /* specifies if content is allowed for distribution in home network */
    slim_int no_of_devices_allowed; /* specifies maximum number of devices allowed for distribution of
                                    the content in home network. Set it to DLNA_DEVICES_ALLOWED_UNLIMITED
                                    for unlimited number of devices */
} dlna_objectrights;

/*!
\par Function:
Initializes the Object Rights Peer and registers the callback for object rights change notifications.
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>progress</td>
    <td>progress manager descriptor</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_callback</td>
    <td>callback to notify Object Rights Manger to notify changes in Object Rights for the stream</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_callback_arg</td>
    <td>argument of in_callback</td>
  </tr>
</table>

\return != slim_nil parameter to the object rights peer context
\return == slim_nil failed to initialize object rights peer


\par Description:
This is replacement for not always implemented system function getifaddrs
*/
dlna_objectrights_context
dlnaObjectRightsAllocPeer(dlna_progress progress, dlna_objectrights_change_notification_callback in_callback, void* in_callback_arg);

/*!
\par Function:
Gets the Object rights for the stream
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_context</td>
    <td>Object rights peer context</td>
  </tr>
  <tr>
    <td>[out]</td>
    <td>out_objectrights</td>
    <td>pointer to dlna_objectrights</td>
  </tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed

\par Description:
This function calls CA/DRM or Middleware APIs to get the Entitlements for the current stream and fills in
out_objectrights to be used by the Object Rights manager to control the content in the home
network. Object Rights Manager shall call this peer function when it receives a change in object rights
notification.
*/
slim_int
dlnaObjectRightsGetPeer(dlna_objectrights_context in_context, dlna_objectrights *out_objectrights);

/*!
\par Function:
Finalizes the Object rights peer
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_context</td>
    <td>pointer to the object rights peer context</td>
  </tr>
</table>

\par Description:
This function finalizes the object rights peer and frees all the previous allocations.
*/
void
dlnaObjectRightsFreePeer(dlna_objectrights_context in_context);

#endif /* DEVELOPMENT_ENABLE_OBJECT_RIGHTS_MANAGER_PEER */

#ifdef DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2

/**
 * @addtogroup datatypes
 */
/*@{*/

/*!
DLNA Diagnostic test action handle.
*/
typedef void *dlna_diag_test;

/*@}*/

/**
 * @addtogroup enums
 */
/*@{*/

/*! Diagnostic events.  */
enum dlna_diag_event_
{
  DLNA_DIAG_INVALID = 0,
  DLNA_DIAG_REQUESTED,
  DLNA_DIAG_IN_PROGRESS,
  DLNA_DIAG_CANCELED,
  DLNA_DIAG_COMPLETED,
  DLNA_DIAG_EVENT_MAX
};

/*!
dlna_diag_event represents the diagnostic engine state specified for dlna_diag_callback().

<table>
  <tr>
    <td><b>Definition</b></td>
    <td><b>Event detailes</b></td>
  </tr>
  <tr>
    <td>DLNA_DIAG_REQUESTED</td>
    <td>Requested</td>
  </tr>
  <tr>
    <td>DLNA_DIAG_IN_PROGRESS</td>
    <td>Testing</td>
  </tr>
  <tr>
    <td>DLNA_DIAG_CANCELED</td>
    <td>Canceled</td>
  </tr>
  <tr>
    <td>DLNA_DIAG_COMPLETED</td>
    <td>Completed</td>
  </tr>
</table>
*/
typedef enum dlna_diag_event_ dlna_diag_event;

/*! Diagnostic status.  */
enum dlna_diag_status_
{
  DLNA_DIAG_SUCCESS = 0,
  DLNA_DIAG_ERROR_CANNOT_RESOLVE_HOSTNAME,
  DLNA_DIAG_ERROR_DNS_SERVER_NOT_RESOLVED,
  DLNA_DIAG_ERROR_MAX_HOP_COUNT_EXCEEDED,
  DLNA_DIAG_ERROR_INTERNAL,
  DLNA_DIAG_ERROR_OTHER
};

/*!
dlna_diag_status represents the state specified for each diagnostic test

<table>
  <tr>
    <td><b>Definition</b></td>
    <td><b>State detailes</b></td>
  </tr>
  <tr>
    <td>DLNA_DIAG_SUCCESS</td>
    <td>Success</td>
  </tr>
  <tr>
    <td>DLNA_DIAG_ERROR_CANNOT_RESOLVE_HOSTNAME</td>
    <td>Can not resolve hostname, used by ping/traceroute</td>
  </tr>
  <tr>
    <td>DLNA_DIAG_ERROR_DNS_SERVER_NOT_RESOLVED</td>
    <td>DNS server not resolved, used by nslookup</td>
  </tr>
  <tr>
    <td>DLNA_DIAG_ERROR_MAX_HOP_COUNT_EXCEEDED</td>
    <td>Max hop count exceeded, used by traceroute</td>
  </tr>
  <tr>
    <td>DLNA_DIAG_ERROR_INTERNAL</td>
    <td>Internal error while doing test</td>
  </tr>
  <tr>
    <td>DLNA_DIAG_ERROR_OTHER</td>
    <td>Other unspecified error reason</td>
  </tr>
</table>
*/
typedef enum dlna_diag_status_ dlna_diag_status;

/*@}*/

/**
 * @addtogroup structures
 */
/*@{*/

/*! Diagnostic callback parameter for ping. */
struct dlna_diag_ping_param_
{
  dlna_diag_status  status;
  slim_char         *additionalInfo;
  slim_word         successCount;
  slim_word         failureCount;
  slim_word         avgRTT;
  slim_word         minRTT;
  slim_word         maxRTT;
};

/*!
dlna_diag_ping_param is the structure that stores player information.

\code
struct dlna_diag_ping_param_
{
  dlna_diag_status  status;
  slim_char         *additionalInfo;
  slim_word         successCount;
  slim_word         failureCount;
  slim_word         avgRTT;
  slim_word         minRTT;
  slim_word         maxRTT;
};
typedef struct dlna_diag_ping_param_ dlna_diag_ping_param;
\endcode
\par Member:

<table>
  <tr>
    <td>status</td>
    <td>Ping test result, possible values<br/>
        DLNA_DIAG_SUCCESS<br/>
        DLNA_DIAG_ERROR_CANNOT_RESOLVE_HOSTNAME<br/>
        DLNA_DIAG_ERROR_INTERNAL<br/>
        DLNA_DIAG_ERROR_OTHER</td>
  </tr>
  <tr>
    <td>additionalInfo</td>
    <td>Additional information to be send back to control point</td>
  </tr>
  <tr>
    <td>successCount</td>
    <td>Count of ICMP response received</td>
  </tr>
  <tr>
    <td>failureCount</td>
    <td>Count of ICMP response not received</td>
  </tr>
  <tr>
    <td>avgRTT</td>
    <td>Average Round Trip Time string in microsecond</td>
  </tr>
  <tr>
    <td>minRTT</td>
    <td>Minimum Round Trip Time string in microsecond</td>
  </tr>
  <tr>
    <td>maxRTT</td>
    <td>Maximum Round Trip Time string in microsecond</td>
  </tr>
</table>
*/
typedef struct dlna_diag_ping_param_ dlna_diag_ping_param;


struct dlna_diag_nslookup_param_
{
  dlna_diag_status   status;
  slim_char          *resultStatus;
  slim_char          *additionalInfo;
  slim_word          successCount;
  slim_char          *answerType;
  slim_char          *hostNameReturned;
  slim_char          *ipAddresses;
  slim_char          *dnsServerIp;
  slim_double        responseTime;
};

/*!
dlna_diag_nslookup_param is the structure that stores player information.

\code
struct dlna_diag_nslookup_param_
{
  dlna_diag_status   status;
  slim_char          *resultStatus;
  slim_char          *additionalInfo;
  slim_word          successCount;
  slim_char          *answerType;
  slim_char          *hostNameReturned;
  slim_char          *ipAddresses;
  slim_char          *dnsServerIp;
  slim_double        responseTime;
};
typedef struct dlna_diag_nslookup_param_ dlna_diag_nslookup_param;
\endcode
\par Member:

<table>
	<tr>
		<td>status</td>
		<td>NSLookup test result, possible values<br/>
        DLNA_DIAG_SUCCESS<br/>
        DLNA_DIAG_ERROR_DNS_SERVER_NOT_RESOLVED<br/>
        DLNA_DIAG_ERROR_INTERNAL<br/>
        DLNA_DIAG_ERROR_OTHER</td>
	</tr>
	<tr>
		<td>resultStatus</td>
		<td>NSLookup status value, possible values<br/>
		Success<br/>
        Error_DNSServerNotAvailable<br/>
        Error_HostNameNotResolved<br/>
        Error_Timeout<br/>
        Error_Other</td>
	</tr>
	<tr>
		<td>additionalInfo</td>
		<td>Additional information to be send back to control point</td>
	</tr>
  <tr>
    <td>successCount</td>
    <td>Count of ICMP response received</td>
  </tr>
  <tr>
		<td>answerType</td>
		<td>the answer is Authoritative or not</td>
	</tr>
	<tr>
		<td>hostNameReturned</td>
		<td>the host name in the calling parameter if no response was provided then this parameter is an empty string</td>
	</tr>
	<tr>
		<td>ipAddresses</td>
		<td>list of one or more comma-separated IPv4/IPv6 adresses returned by the NS Lookup</td>
	</tr>
	<tr>
		<td>dnsServerIp</td>
		<td>actual DNS Server IPv4/IPv6 adress</td>
	</tr>
	<tr>
		<td>responseTime</td>
		<td>the response time for the most recent probe</td>
	</tr>

</table>
*/

typedef struct dlna_diag_nslookup_param_ dlna_diag_nslookup_param;


struct dlna_diag_traceroute_param_
{
  dlna_diag_status             status;
  slim_char                    *additionalInfo;
  slim_word                    responseTime;
  slim_char                    *hopHosts;
};

/*!
dlna_diag_traceroute_param is the structure that stores player information.

\code
struct dlna_diag_traceroute_param_
{
  dlna_diag_status             status;
  slim_char                    *additionalInfo;
  slim_word                    responseTime;
  slim_char                    *hopHosts;
};
typedef struct dlna_diag_traceroute_param_ dlna_diag_traceroute_param;
\endcode
\par Member:

<table>
	<tr>
		<td>status</td>
		<td>Traceroute test result, possible values<br/>
        DLNA_DIAG_SUCCESS<br/>
        DLNA_DIAG_ERROR_CANNOT_RESOLVE_HOSTNAME<br/>
        DLNA_DIAG_ERROR_MAX_HOP_COUNT_EXCEEDED<br/>
        DLNA_DIAG_ERROR_INTERNAL<br/>
        DLNA_DIAG_ERROR_OTHER</td>
	</tr>
	<tr>
		<td>additionalInfo</td>
		<td>Additional information to be send back to control point</td>
	</tr>
	<tr>
		<td>responseTime</td>
		<td>the average response time for the most recent probe</td>
	</tr>
	<tr>
		<td>hopHosts</td>
		<td>A comma-separated list of the hosts along the discovered route</td>
	</tr>
</table>
*/
typedef struct dlna_diag_traceroute_param_ dlna_diag_traceroute_param;


struct dlna_diag_devicestatus_param_
{
  slim_char *device_status;
  slim_char *timestamp;
  slim_char *additionalInfo;
};

/*!
dlna_diag_devicestatus_param is the structure that stores player information.

\code
struct dlna_diag_devicestatus_param
{
  slim_char *device_status;
  slim_char *timestamp;
  slim_char *additionalInfo;
};
typedef struct dlna_diag_devicestatus_param_ dlna_diag_devicestatus_param;
\endcode
\par Member:

<table>
        <tr>
                <td>device_status</td>
                <td>device status string</td>
        </tr>
        <tr>
                <td>timestamp</td>
                <td>current time</td>
        </tr>
        <tr>
                <td>additionalInfo</td>
                <td>Additional Info string</td>
        </tr>
</table>
*/
typedef struct dlna_diag_devicestatus_param_ dlna_diag_devicestatus_param;

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Callback function for notifying NFLC core of ping state and result.
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_event</td>
    <td>dlna_diag_event</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_arg</td>
    <td>Argument specified in dlnaDiagPingPeer()</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_param</td>
    <td>Pointer to dlna_diag_ping_param</td>
  </tr>
</table>

\return SLIM_E_OK Succeeded
\return Other Failed
\par Description:
This function notifies the NFLC core of ping state and result.

This function should be called every time the player state is updated.

The ping status is specified for in_event.

This function must not be called directly within each DLNA Diagnostic Peer function. It must be called again
using the DLNA core thread or called by any thread other than the NFLC core, after a NFLC Diagnostic
Peer function has been called.
\note
To call this function using an NFLC core thread, an event for calling this function must be added to the
DLNA progress by using dlnaProgressEventAddPeer() (see "6.15.7
dlnaProgressEventAddPeer").
*/
typedef slim_int
(*dlna_diag_ping_callback) (dlna_diag_event in_event,
                            void *in_arg,
                            dlna_diag_ping_param *in_param);

/*!
\par Function:
Execute ping with specified parameters
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_callback</td>
    <td>Callback to be called when ping procedure finished</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_arg</td>
    <td>Parameter for callback function specified by in_callback</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_host</td>
    <td>Parameter destination of ping command on Linux</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_number</td>
    <td>Option [-c count] of ping command on Linux</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_number</td>
    <td>Option [-c count] of ping command on Linux</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_timeout</td>
    <td>Option [W timeout] of ping command on Linux</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_blockSize</td>
    <td>Option [-s packetsize] of ping command on Linux</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_dscp</td>
    <td>Option [-Q tos] of ping command on Linux</td>
  </tr>
</table>

\return pointer to dlna_diag_test if Succeeded
\return slim_nil if not succeeded

\par Description:
The function calls system utility to send ICMP protocol's mandatory ECHO_REQUEST datagram
to elicit an ICMP ECHO_RESPONSE from a host or gateway.
*/
dlna_diag_test
dlnaDiagPingPeer (dlna_diag_ping_callback in_callback,
                  void *in_arg,
                  slim_char *in_host,
                  slim_word in_number,
                  slim_word in_timeout,
                  slim_word in_blockSize,
                  slim_word in_dscp);


/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Callback function for notifying NFLC core of nslookup state and result.
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_event</td>
    <td>dlna_diag_event</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_arg</td>
    <td>Argument specified in dlnaDiagNSLookupPeer()</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_param</td>
    <td>Pointer to dlna_diag_nslookup_param</td>
  </tr>
</table>

\return SLIM_E_OK Succeeded
\return Other Failed
\par Description:
This function notifies the NFLC core of nslookup state and result.

This function should be called when nslookup action is completed.

NSLookup action status is specified for in_event.

This function must not be called directly within each DLNA Diagnostic Peer function. It must be called again
using the DLNA core thread or called by any thread other than the NFLC core, after a NFLC Diagnostic
Peer function has been called.
\note
To call this function using an NFLC core thread, an event for calling this function must be added to the
DLNA progress by using dlnaProgressEventAddPeer() (see "6.15.7
dlnaProgressEventAddPeer").
*/
typedef slim_int
(*dlna_diag_nslookup_callback) (dlna_diag_event in_event,
                                  void *in_arg,
                                  dlna_diag_nslookup_param *in_param);

/*!
\par Function:
Execute nslookup with specified parameters
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_host</td>
    <td>Parameter destination of nslookup command on Linux</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_dnsServer</td>
    <td>Option [-c count] of nslookup command on Linux</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_numberOfRepetitions</td>
    <td>Option [-c count] of nslookup command on Linux</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_timeout</td>
    <td>Option [W timeout] of nslookup command on Linux</td>
  </tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_NOTSUPPORTED Not supported
\return SLIM_E_GENERIC Failed

\par Description:
The function calls system utility to varify test arguments.
Test arguments are individually valid but, taken together, descrive a test that is beyond the service's capabilities.
*/
slim_int
dlnaDiagNSLookupCapabilitiesPrecludeTestPeer( slim_char *in_host,
                                        slim_char *in_dnsServer,
                                        slim_char *in_numberOfRepetitions,
                                        slim_char *in_timeout);

/*!
\par Function:
Execute nslookup with specified parameters
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_host</td>
    <td>Parameter destination of nslookup command on Linux</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_dnsServer</td>
    <td>Option [-c count] of nslookup command on Linux</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_numberOfRepetitions</td>
    <td>Option [-c count] of nslookup command on Linux</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_timeout</td>
    <td>Option [W timeout] of nslookup command on Linux</td>
  </tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_NOTSUPPORTED Not supported
\return SLIM_E_GENERIC Failed

\par Description:
The function calls system utility to check service state.
Service state precludes performing this test.
*/
slim_int
dlnaDiagNSLookupStatePrecludesTestPeer( slim_char *in_host,
                                        slim_char *in_dnsServer,
                                        slim_char *in_numberOfRepetitions,
                                        slim_char *in_timeout);


/*!
\par Function:
Execute nslookup with specified parameters
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_callback</td>
    <td>Callback to be called when nslookup procedure finished</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_arg</td>
    <td>Parameter for callback function specified by in_callback</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_host</td>
    <td>Parameter destination of nslookup command on Linux</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_dnsServer</td>
    <td>Option [-c count] of nslookup command on Linux</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_numberOfRepetitions</td>
    <td>Option [-c count] of nslookup command on Linux</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_timeout</td>
    <td>Option [W timeout] of nslookup command on Linux</td>
  </tr>
</table>

\return value is pointer to dlna_diag_test or slim_nil

\par Description:
The function calls system utility to send ICMP protocol's mandatory ECHO_REQUEST datagram
to elicit an ICMP ECHO_RESPONSE from a host or gateway.
*/
dlna_diag_test
dlnaDiagNSLookupPeer(dlna_diag_nslookup_callback in_callback,
                       void *in_arg,
                       slim_char *in_host,
                       slim_char *in_dnsServer,
                       slim_char *in_numberOfRepetitions,
                       slim_char *in_timeout);

/*!
\par Function:
Callback function for notifying NFLC core of traceroute state and result.
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_event</td>
    <td>dlna_diag_event</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_arg</td>
    <td>Argument specified in dlnaDiagTraceroutePeer()</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_param</td>
    <td>Pointer to dlna_diag_traceroute_param</td>
  </tr>
</table>

\return SLIM_E_OK Succeeded
\return Other Failed
\par Description:
This function notifies the NFLC core of traceroute state and result.

This function should be called every time the player state is updated.

The traceroute status is specified for in_event.

This function must not be called directly within each DLNA Diagnostic Peer function. It must be called again
using the DLNA core thread or called by any thread other than the NFLC core, after a NFLC Diagnostic
Peer function has been called.
\note
To call this function using an NFLC core thread, an event for calling this function must be added to the
DLNA progress by using dlnaProgressEventAddPeer() (see "6.15.7
dlnaProgressEventAddPeer").
*/
typedef slim_int
(*dlna_diag_traceroute_callback) (dlna_diag_event in_event,
                                  void *in_arg,
                                  dlna_diag_traceroute_param *in_param);

/*!
\par Function:
Execute traceroute with specified parameters
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_callback</td>
    <td>Callback to be called when traceroute procedure finished</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_arg</td>
    <td>Parameter for callback function specified by in_callback</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_host</td>
    <td>Parameter destination of traceout command on Linux</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_timeout</td>
    <td>Option [-w waittime] of traceout command on Linux</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_dataBlockSize</td>
    <td>Option of traceout command on Linux</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_maxHopCount</td>
    <td>Option [-m maxttl] of traceout command on Linux</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_dscp</td>
    <td>Option [-t tos] of traceout command on Linux</td>
  </tr>
</table>

\return pointer to dlna_diag_test if Succeeded
\return slim_nil if not succeeded

\par Description:
The function calls system utility which can show you the path a packet of information..
*/
dlna_diag_test
dlnaDiagTraceroutePeer(dlna_diag_traceroute_callback in_callback,
                       void *in_arg,
                       slim_char *in_host,
                       slim_char *in_timeout,
                       slim_char *in_dataBlockSize,
                       slim_char *in_maxHopCount,
                       slim_char *in_dscp);


/*!
\par Function:
Callback function for notifying NFLC core of devicestatus action state and result.
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_arg</td>
    <td>Argument specified in dlnaDiagDeviceStatusPeer()</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_param</td>
    <td>Pointer to dlna_diag_devicestatus_param</td>
  </tr>
</table>

\return SLIM_E_OK Succeeded
\return Other Failed
\par Description:
This function notifies the NFLC core of devicestatus state and result.

This function should be called every time the device status is updated.

The devicestatus status is specified for in_event.

This function must not be called directly within each DLNA Diagnostic Peer function. It must be called
using the DLNA core thread or called by any thread other than the NFLC core, after a NFLC Diagnostic
Peer function has been called.
\note
To call this function using an NFLC core thread, an event for calling this function must be added to the
DLNA progress by using dlnaProgressEventAddPeer() (see "6.15.7
dlnaProgressEventAddPeer").
*/
typedef slim_int
(*dlna_diag_devicestatus_callback) (void *in_arg, dlna_diag_devicestatus_param *in_param);
/*!
\par Function:
Get device status
\par Parameters:

<table>
  <tr>
    <td>[out]</td>
    <td>out_state</td>
    <td>Device state, possible values</br>
        OK</br>
        Warning</br>
        Error</br>
        Fatal</td>
  </tr>
  <tr>
    <td>[out]</td>
    <td>out_time</td>
    <td>Timestamp when this function called in 0001-01-01T00:00:00 format</td>
  </tr>
  <tr>
    <td>[out]</td>
    <td>out_addInfo</td>
    <td>Arbitrary string to be returned to control point</td>
  </tr>
</table>

\return SLIM_E_OK Succeeded
\return SLIM_E_NOTSUPPORTED Not supported
\return SLIM_E_GENERIC Failed

\par Description:
The function is to retrieve the system status.
*/
void
dlnaDiagDeviceStatusPeer (dlna_progress in_progress,
                          dlna_diag_devicestatus_callback in_callback,
                          void *in_arg,
                          slim_char *out_state,
                          slim_char *out_time,
                          slim_char *out_addInfo);

/*!
\par Function:
cancels a successfully requested test.
\par Parameters:
<table>
  <tr>
    <td>[in]</td>
    <td>in_action</td>
    <td>pointer to the test action handle</td>
  </tr>
</table>

\return SLIM_E_OK Succeeded
\return Other Failed

\par Description:
The function cancels a requested test which is not yet complete
*/
slim_int
dlnaDiagCancelTestPeer (dlna_diag_test in_action);

/*@}*/

#endif /* DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2 */

#ifdef DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1

/**
 * @addtogroup enums
 */
/*@{*/

/*!
\par Function:
get the current information and current mode of the power state for all of the network interfaces that the service can be discovered on.
\par Parameters:

\return SLIM_E_OK Succeeded
\return Other Failed

\par Description:
---
*/
slim_int dlnaLpGetInterfaceInfoPeer (void);

/*!
\par Function:
get values of service through ServiceSubscription action
\par Parameters:

\return SLIM_E_OK Succeeded
\return Other Failed

\par Description:
---
*/
slim_int dlnaLpServiceSubscriptionPeer (void);

/*!
\par Function:
get values of service through ServiceRelease action
\par Parameters:

\return SLIM_E_OK Succeeded
\return Other Failed

\par Description:
---
*/
slim_int dlnaLpServiceRenewalPeer (void);

/*!
\par Function:
get values of service through ServiceRelease action
\par Parameters:

\return SLIM_E_OK Succeeded
\return Other Failed

\par Description:
---
*/
slim_int dlnaLpServiceReleasePeer (void);

/*@}*/

#endif /* DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1 */

typedef void *dlna_live_content;

dlna_live_content 
dlnaLiveContentOpenPeer(slim_int in_channelNum);

slim_bool 
dlnaLiveContentByteSeekPeer(dlna_live_content in_desc, dlna_uint64 *in_seek_byte);

slim_bool 
dlnaLiveContentTimeSeekPeer(dlna_live_content in_desc, dlna_timeval in_seek_time);

dlna_ssize_t 
dlnaLiveContentReadPeer(dlna_live_content in_desc, void *out_buf, dlna_size_t in_len);

void
dlnaLiveContentClosePeer(dlna_live_content in_desc);

slim_int
dlnaLiveContentGetSeekRangePeer(slim_int in_channelNum, 
                                slim_char *out_start_time, slim_char *out_end_time,
                                dlna_uint64 *out_start, dlna_uint64 *out_end);


slim_int
dlnaReadLogConfigPeer(slim_char* in_file_path, slim_char* in_file_name);

slim_int
dlnaReadLogCmdPeer(slim_char *in_value);

void
dlnaLogMemDumpPeer(slim_char *buf, slim_int size ) ;

#ifdef DEVELOPMENT_ENABLE_XDMR_RENDER_IN_BROWSER

slim_bool peerSendPlayerEventFromHNSO (dlna_player_event);
void peerSendPlayerErrorEvent ();
void peerSendPlayerEOSEvent ();

#endif /* DDEVELOPMENT_ENABLE_XDMR_RENDER_IN_BROWSER */

#ifdef MEDIA_PROCESSING_EXTENSION
/**
 * @addtogroup apis
 */
/*@{*/
/*!
\par Function:
Start MPE Server
\par Parameters:

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed

\par Description:
This function starts MPE Server.
*/
slim_int dlnaMPEServerStartPeer (void);
/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/
/*!
\par Function:
Stop MPE Server
\par Parameters:

\return SLIM_E_OK Succeeded
\return SLIM_E_GENERIC Failed

\par Description:
This function stops MPE Server.
*/
slim_int dlnaMPEServerStopPeer(void);
/*@}*/
#endif /* MEDIA_PROCESSING_EXTENSION */



/* Debug.  */

/*!
\par Function:
Outputs debug information (with linefeeds).
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>format</td>
		<td>Format string (C string)<br/> Conforms to printf() function</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>... (argument list)</td>
		<td>Output data</td>
	</tr>
</table>

\return None
\par Description:
This function outputs debug information with linefeeds.

The actual output device depends on the target system.
*/


// these are defined in peer_log_utility.c in the /libutil 
extern dlna_file_t gLogFd ;
extern dlna_mutex gLogMutex ;

void
dlnaLogPrintPeer(dlna_mutex in_mutex, dlna_file_t in_fd, int level, int ts, const char *function, int line, const char *format, ...);
void
dlnaLogPrintRawPeer(const char *format, ...);

#define dlnaDebugPrintfPeer dlnaLogPrintRawPeer 

slim_char*
dlnaDebugAllocVAPrintfPeer (const char *format, ...);

slim_int
dlnaLogInitializePeer(slim_char* in_path);

void
dlnaLogFinalizePeer(void);

/*@}*/

#if DEBUG_SYSTEM == 1
#define DLNA_DP(arg) dlnaDebugPrintfPeer arg
/*revise: remove the old DLNA_DEBUG_MSG and clean-up its usages*/
#ifndef ENABLE_DEBUG_TIMESTAMP
#define DLNA_DEBUG_MSG(x, arg)          \
           do {                         \
             if (x) {                   \
               dlnaDebugPrintfPeer arg; \
             }                          \
           } while (0)
#else /* ENABLE_DEBUG_TIMESTAMP */
#define DLNA_DEBUG_MSG(x, arg)                          \
           do {                                         \
             if (x) {                                   \
               dlna_date _DLNADEBUGMSG_date_tmp;                     \
               dlna_timeval _DLNADEBUGMSG_current_timeval;           \
               slim_char* _DLNADEBUGMSG_buf = slim_nil;               \
               _DLNADEBUGMSG_buf = dlnaDebugAllocVAPrintfPeer arg;    \
               if (_DLNADEBUGMSG_buf) {                               \
                 dlna_timeval_get(&_DLNADEBUGMSG_current_timeval);   \
                 dlnaGetDlnaDate(&_DLNADEBUGMSG_current_timeval, &_DLNADEBUGMSG_date_tmp);\
                 dlnaDebugPrintfPeer ("[%02d:%02d:%02d.%03d] %s", _DLNADEBUGMSG_date_tmp.hour, _DLNADEBUGMSG_date_tmp.min, _DLNADEBUGMSG_date_tmp.sec, _DLNADEBUGMSG_date_tmp.msec, _DLNADEBUGMSG_buf); \
                 dlna_memory_free(_DLNADEBUGMSG_buf);                 \
               } else {                                 \
                 dlnaDebugPrintfPeer arg;               \
               }                                        \
             }                                          \
           } while (0)
#endif /* ENABLE_DEBUG_TIMESTAMP */
#else /* DEBUG_SYSTEM */

#define DLNA_DP(arg)
#define DLNA_DEBUG_MSG(x, arg)

#endif /* DEBUG_SYSTEM */

#define DLNA_FUNC_ENTER(func) DLNA_LOG(DLNA_LOG_API, DLNA_LOG_LEVEL_DEBUG, "[DLNA API] %s() Enter", #func) 
#define DLNA_FUNC_EXIT(func)  DLNA_LOG(DLNA_LOG_API, DLNA_LOG_LEVEL_DEBUG, "[DLNA API] %s() Exit", #func) 
                              

#endif /* NFLC_DLNA_PEER_H */
