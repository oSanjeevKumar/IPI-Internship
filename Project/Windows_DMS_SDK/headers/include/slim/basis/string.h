/*
	string.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/basis/string.h 86    06/03/24 17:27 Someya $ */

#ifndef SLIM_STRING_H
#define SLIM_STRING_H

SLIM_BEGIN_C_LINKAGE

/* String */
struct iTString_ {
	slim_char fString[1];	/* variable length */
};
typedef struct iTString_ iTString;

struct TStringFormatCookie_ {
	slim_char *fBuf;
	slim_int fOffset;
};
typedef struct TStringFormatCookie_ TStringFormatCookie;

#define TString_Delete(self) (slim_vhandle_free((slim_vhandle)(self)))
#define TString_Lock(self) ((slim_char *)slim_vhandle_lock((slim_vhandle)(self)))
#define TString_Unlock(self) (slim_vhandle_unlock((slim_vhandle)(self)))

/*
 * FixedString
 */

#ifndef SLIM_CONFIG_FIXEDSTRING_REPLACE_STRING

#define SLIM_FIXEDSTRING_HASHSIZE 256
#define SLIM_FIXEDSTRING_HASHMASK 0xFF
typedef struct iTFixedString_ iTFixedString;
struct iTFixedString_ {
	TFixedString fHashNext;
	slim_int fLen;
#ifdef SLIM_CONFIG_MORECOMPACT
	slim_byte fRefCount;
#else
	slim_int fRefCount;
#endif
	slim_char fString[1];	/* variable length */
};

#else /* SLIM_CONFIG_FIXEDSTRING_REPLACE_STRING */
typedef iTString iTFixedString;
#endif /* SLIM_CONFIG_FIXEDSTRING_REPLACE_STRING */

/* API */
#ifndef SLIM_CONFIG_FIXEDSTRING_REPLACE_STRING
#define TFixedString_Lock(self)	(&((iTFixedString *)slim_handle_lock((slim_handle)(self)))->fString[0])
#define TFixedString_Unlock(self) (slim_handle_unlock((slim_handle)(self)))
#else /* SLIM_CONFIG_FIXEDSTRING_REPLACE_STRING */
#define FixedString_NewSS(s, len) String_NewSS(s, len)
#define FixedString_NewCS(s) String_NewCS(s)
#define FixedString_NewFS(fs) String_NewTS(fs)
#define FixedString_NewTS(ts) String_NewTS(ts)
#define TFixedString_Delete(self) TString_Delete(self)
#define TFixedString_Lock(self)	TString_Lock(self)
#define TFixedString_Unlock(self) TString_Unlock(self)
#define TFixedString_Length(self)	TString_Length(self)
#endif /* SLIM_CONFIG_FIXEDSTRING_REPLACE_STRING */

SLIM_END_C_LINKAGE
#endif
