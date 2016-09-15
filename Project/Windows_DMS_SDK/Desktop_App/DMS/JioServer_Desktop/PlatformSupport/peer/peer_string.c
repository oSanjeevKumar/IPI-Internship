/*
 * peer_string.c
 * Copyright (C) 2007-2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#include <dlna_peer.h>
#include "peer_string.h"

slim_int dlna_errno = 0;

slim_int dlnaCS_CP_to_Wide(slim_word nCP,
						   const slim_char *szSrc,
						   wchar_t *szDst,
						   slim_int nBufLen)
{
	// sanity check
	if (!szSrc) return 0;
	// force the buffer length to be 0 if there is no destination string (this way it returns required length)
	if (!szDst) nBufLen = 0;

	// convert from utf8 to unicode, let the function determine the length
	return MultiByteToWideChar(nCP, 0, szSrc, -1, szDst, nBufLen);
}

slim_int dlnaCS_Wide_to_CP(slim_word nCP,
						   const wchar_t *szSrc,
						   slim_char *szDst,
						   slim_int nBufLen)
{
	// sanity check
	if (!szSrc) return 0;
	// force the buffer length to be 0 if there is no destination string (this way it returns required length)
	if (!szDst) nBufLen = 0;

	// convert from unicode to utf8, let the function determine the length
	return WideCharToMultiByte(nCP, 0, szSrc, -1, szDst, nBufLen, NULL, NULL);
}

slim_int dlnaCS_CP_to_CP(slim_word nCPsrc,
						 slim_word nCPdest,
						 const slim_char *szSrc,
						 slim_char *szDst,
						 slim_int nBufLen)
{
	slim_int nWideSize = 0, nRet = 0;
	wchar_t* szWideBuf = NULL;

	// sanity check
	if (!szSrc) return 0;
	// force the buffer length to be 0 if there is no destination string (this way it returns required length)
	if (!szDst) nBufLen = 0;

	// we need to determine the wide character buffer size needed to perform this
	nWideSize = dlnaCS_CP_to_Wide(nCPsrc, szSrc, NULL, 0);

	if (nWideSize > 0) {
		szWideBuf = (wchar_t*)dlna_memory_alloc(sizeof(wchar_t)*nWideSize);
		// now convert the string to wide
		nRet = dlnaCS_CP_to_Wide(nCPsrc, szSrc, szWideBuf, nWideSize);
		if (nRet > 0) {
			// convert the string back from wide to its new code page
			nRet = dlnaCS_Wide_to_CP(nCPdest, szWideBuf, szDst, nBufLen);
		}
		dlna_memory_free(szWideBuf);
	}
	return nRet;
}

slim_int dlnaCS_UTF8_to_CP(slim_word nCP,
						   const slim_char *szSrc,
						   slim_char *szDst,
						   slim_int nBufLen)
{
	return dlnaCS_CP_to_CP(CP_UTF8, nCP, szSrc, szDst, nBufLen);
}

slim_int dlnaCS_CP_to_UTF8(slim_word nCP,
						   const slim_char *szSrc,
						   slim_char *szDst,
						   slim_int nBufLen)
{
	return dlnaCS_CP_to_CP(nCP, CP_UTF8, szSrc, szDst, nBufLen);
}

slim_int dlnaCS_UTF8_to_Wide(const slim_char *szSrc,
							 wchar_t *szDst,
							 slim_int nBufLen)
{
	return dlnaCS_CP_to_Wide(CP_UTF8, szSrc, szDst, nBufLen);
}

slim_int dlnaCS_Wide_to_UTF8(const wchar_t *szSrc,
							 slim_char *szDst,
							 slim_int nBufLen)
{
	return dlnaCS_Wide_to_CP(CP_UTF8, szSrc, szDst, nBufLen);
}

// string length
dlna_size_t dlna_strlen(const slim_char *in_s)
{
	if(!in_s) {
		DLNA_LOG(DLNA_LOG_PEER_STRING, DLNA_LOG_LEVEL_ERROR, "dlna_strlen->null_pointer.");
		return -1;
	}
	return (dlna_size_t)strlen((char *)in_s);
}

// string compare
slim_int dlna_strcmp(const slim_char *in_s1,
					 const slim_char *in_s2)
{
	if(!in_s1 || !in_s2) {
		DLNA_LOG(DLNA_LOG_PEER_STRING, DLNA_LOG_LEVEL_ERROR, "dlna_strcmp->null_pointer.");
		return -1;
	}
	return strcmp((char *)in_s1, (char *)in_s2);
}

// string n-compare
slim_int dlna_strncmp(const slim_char *in_s1,
					  const slim_char *in_s2,
					  dlna_size_t in_count)
{
	if(!in_s1 || !in_s2) {
		DLNA_LOG(DLNA_LOG_PEER_STRING, DLNA_LOG_LEVEL_ERROR, "dlna_strcmp->null_pointer.");
		return -1;
	}
	return strncmp((char *)in_s1, (char *)in_s2, in_count);
}

// string compare no case
slim_int dlna_strcmp_nocase(const slim_char *in_s1,
							const slim_char *in_s2)
{
	if(!in_s1 || !in_s2) {
		DLNA_LOG(DLNA_LOG_PEER_STRING, DLNA_LOG_LEVEL_ERROR, "dlna_strcmp->null_pointer.");
		return -1;
	}
	return strcasecmp((char *)in_s1, (char *)in_s2);
}

// string n-compare no case
slim_int dlna_strncmp_nocase(const slim_char *in_s1,
							 const slim_char *in_s2,
							 dlna_size_t in_count)
{
	if(!in_s1 || !in_s2) {
		DLNA_LOG(DLNA_LOG_PEER_STRING, DLNA_LOG_LEVEL_ERROR, "dlna_strcmp->null_pointer.");
		return -1;
	}
	return strncasecmp((char *)in_s1, (char *)in_s2, in_count);
}

// string copy
slim_char *dlna_strcpy(slim_char *in_s1,
					   slim_char *in_s2)
{
	if(!in_s1 || !in_s2) {
		DLNA_LOG(DLNA_LOG_PEER_STRING, DLNA_LOG_LEVEL_ERROR, "dlna_strcpy->null_pointer.");
		return slim_nil;
	}
	return (slim_char *)strcpy((char *)in_s1, (char *)in_s2);
}

// string n-copy
slim_char *dlna_strncpy(slim_char *in_s1,
						slim_char *in_s2,
						dlna_size_t in_count)
{
	if(!in_s1 || !in_s2) {
		DLNA_LOG(DLNA_LOG_PEER_STRING, DLNA_LOG_LEVEL_ERROR, "dlna_strncpy->null_pointer.");
		return slim_nil;
	}
	return (slim_char *)strncpy((char *)in_s1, (char *)in_s2, in_count);
}

// string to unsigned long
slim_word dlna_strtoul(slim_char *in_buf,
					   slim_char **out_endptr,
					   slim_int in_base)
{
	if(!in_buf) {
		DLNA_LOG(DLNA_LOG_PEER_STRING, DLNA_LOG_LEVEL_ERROR, "dlna_strtoul->null_pointer.");
		return 0;
	}
	return strtoul((char *)in_buf, (char **)out_endptr, in_base);
}

// string to long
slim_int dlna_strtol(slim_char *in_buf,
					 slim_char **out_endptr,
					 slim_int in_base)
{
	slim_int val;
	errno = 0;
	if(!in_buf) {
		DLNA_LOG(DLNA_LOG_PEER_STRING, DLNA_LOG_LEVEL_ERROR, "dlna_strtol->null_pointer.");
		return 0;
	}
	val = strtol ((char *) in_buf, (char **) out_endptr, in_base);
	dlna_errno = errno;
	return val;
}

#ifdef HAVE_STRDUP
// string duplicate
slim_char *dlna_strdup(const slim_char *in_str)
{
	if (!in_str) {
		DLNA_LOG(DLNA_LOG_PEER_STRING, DLNA_LOG_LEVEL_ERROR, "dlna_strdup->null_pointer.");
		return slim_nil;
	}
	return (slim_char *)_strdup((char *)in_str);
}
#endif /* HAVE_STRDUP */

#ifdef HAVE_STRSTR
// string search-string
slim_char *dlna_strstr(slim_char *in_string1,
					   slim_char *in_string2)
{
	if (!in_string1 || !in_string2) {
		DLNA_LOG(DLNA_LOG_PEER_STRING, DLNA_LOG_LEVEL_ERROR, "dlna_strstr->null_pointer.");
		return slim_nil;
	}
	return (slim_char *)strstr((char *)in_string1, (char *)in_string2);
}
#endif /* HAVE_STRSTR */

#ifdef HAVE_STRRSTR
/*
* The dlna_strstr() function finds the last occurrence of the substring needle
* in the string haystack. The terminating nul characters are not compared.
*/
slim_char *
dlna_strrstr(const slim_char *haystack, const slim_char *needle)
{
	char *r = NULL;

	if (!needle[0])
		return (slim_char*)haystack + strlen(haystack);
	while (1) {
		char *p = strstr(haystack, needle);
		if (!p)
			return r;
		r = p;
		haystack = p + 1;
	}
}
#endif /* ! HAVE_STRSTR */

#ifdef HAVE_STRCHR
// string search-character
slim_char *dlna_strchr(slim_char *in_str,
					   slim_int in_c)
{
	if (!in_str) {
		DLNA_LOG(DLNA_LOG_PEER_STRING, DLNA_LOG_LEVEL_ERROR, "dlna_strchr->null_pointer.");
		return slim_nil;
	}
	return (slim_char *)strchr((char *)in_str, in_c);
}
#endif /* HAVE_STRCHR */

#ifdef HAVE_STRRCHR
// string search-character (last)
slim_char *dlna_strrchr(slim_char *in_str,
						slim_int in_c)
{
	if (!in_str) {
		DLNA_LOG(DLNA_LOG_PEER_STRING, DLNA_LOG_LEVEL_ERROR, "dlna_strrchr->null_pointer.");
		return slim_nil;
	}
	return (slim_char *)strrchr((char *)in_str, in_c);
}
#endif /* HAVE_STRRCHR */

#ifdef HAVE_STRCAT
slim_char *dlna_strcat(slim_char *in_string1,
					   slim_char *in_string2)
{
	if (!in_string1 || !in_string2) {
		DLNA_LOG(DLNA_LOG_PEER_STRING, DLNA_LOG_LEVEL_ERROR, "dlna_strcat->null_pointer.");
		return slim_nil;
	}
	return (slim_char *)strcat((char *)in_string1, (char *)in_string2);
}
#endif /* HAVE_STRCAT */

#ifdef HAVE_STRNCAT
slim_char *dlna_strncat(slim_char *in_string1,
						slim_char *in_string2,
						dlna_size_t in_count)
{
	if (!in_string1 || !in_string2) {
		DLNA_LOG(DLNA_LOG_PEER_STRING, DLNA_LOG_LEVEL_ERROR, "dlna_strncat->null_pointer.");
		return slim_nil;
	}
	return (slim_char *)strncat((char *)in_string1, (char *)in_string2, in_count);
}
#endif /* HAVE_STRNCAT */

#ifdef HAVE_STRSPN
// string span
dlna_size_t dlna_strspn(slim_char *in_string1,
						slim_char *in_string2)
{
	if (!in_string1 || !in_string2) {
		DLNA_LOG(DLNA_LOG_PEER_STRING, DLNA_LOG_LEVEL_ERROR, "dlna_strspn->null_pointer.");
		return 0;
	}
	return (dlna_size_t)strspn((char *)in_string1, (char *)in_string2);
}
#endif /* HAVE_STRSPN */

#ifdef HAVE_ATOI
// ascii to integer converter
slim_int dlna_atoi(slim_char *in_string)
{
	if (!in_string) {
		DLNA_LOG(DLNA_LOG_PEER_STRING, DLNA_LOG_LEVEL_ERROR, "dlna_atoi->null_pointer.");
		return 0;
	}
	return (slim_int)atoi((const char *)in_string);
}
#endif /* HAVE_ATOI */

#ifdef HAVE_ATOF
// ascii to integer converter
slim_double dlna_atof(slim_char *in_string)
{
	if (!in_string) {
		DLNA_LOG(DLNA_LOG_PEER_STRING, DLNA_LOG_LEVEL_ERROR, "dlna_atof->null_pointer.");
		return 0;
	}
	return (slim_double)atof((const char *)in_string);
}
#endif /* HAVE_ATOF */

#ifdef HAVE_ISSPACE
// character is space
slim_int dlna_isspace(slim_int in_c)
{
	// only call this function with a valid ansi character
	if ((0 <= in_c && in_c <= 255) || EOF == in_c)
		return isspace(in_c);
	return 0;
}
#endif /* HAVE_ISSPACE */

#ifdef HAVE_ISALPHA
// character is alpha
slim_int dlna_isalpha(slim_int in_c)
{
	// only call this function with a valid ansi character
	if ((0 <= in_c && in_c <= 255) || EOF == in_c) {
		return isalpha(in_c);
	}
	return 0;
}
#endif /* HAVE_ISALPHA */

#ifdef HAVE_ISALNUM
// character is alpha-numeric
slim_int dlna_isalnum(slim_int in_c)
{
	// only call this function with a valid ansi character
	if ((0 <= in_c && in_c <= 255) || EOF == in_c) {
		return isalnum(in_c);
	}
	return 0;
}
#endif /* HAVE_ISALNUM */

#ifdef HAVE_ISDIGIT
// character is digit
slim_int dlna_isdigit(slim_int in_c)
{
	// only call this function with a valid ansi character
	if ((0 <= in_c && in_c <= 255) || (EOF == in_c)) {
		return isdigit(in_c);
	}
	return 0;
}
#endif /* HAVE_ISDIGIT */

#ifdef HAVE_ISXDIGIT
// character is hex digit
slim_int dlna_isxdigit(slim_int in_c)
{
	// only call this function with a valid ansi character
	if ((0 <= in_c && in_c <= 255) || (EOF == in_c)) {
		return isxdigit(in_c);
	}
	return 0;
}
#endif /* HAVE_ISXDIGIT */

// string is made of digits only
slim_int dlna_isstringofdigits(const slim_char *in_s)
{
	dlna_size_t length;
	slim_int i;

	length = dlna_strlen(in_s);

	for (i = 0; i < length; ++i) {
		if (!dlna_isdigit(*(in_s + i)))
			return 0;
	}
	return 1;
}

/* A sequence of calls to this function split str into tokens, which are sequences of contiguous characters separated by any of the characters that are part of delimiters.  */
slim_char *
dlna_strtok (slim_char *in_str, const slim_char *in_delim)
{
  if(!in_delim){
      DLNA_LOG(DLNA_LOG_PEER_STRING, DLNA_LOG_LEVEL_ERROR, "dlna_strtok->null_pointer.");
      return slim_nil;
  }

  return (slim_char *)strtok((char *) in_str, (const char *) in_delim);
}

#ifdef HAVE_TOLOWER
// character to lowercase
slim_int dlna_tolower(slim_int in_c)
{
	return tolower(in_c);
}
#endif /* HAVE_TOLOWER */

#ifdef HAVE_TOUPPER
// character to uppercase
slim_int dlna_toupper(slim_int in_c)
{
	return toupper(in_c);
}
#endif /* HAVE_TOUPPER */

#ifdef HAVE_ISPRINT
/* Character is printable.  */
slim_int
dlna_isprint(slim_int in_c)
{
	/* Only call this function with a valid ansi character.  */
	if ((0 <= in_c && in_c <= 255) || EOF == in_c) {
		return isprint(in_c);
	}
	return 0;
}
#endif /* HAVE_ISPRINT */

