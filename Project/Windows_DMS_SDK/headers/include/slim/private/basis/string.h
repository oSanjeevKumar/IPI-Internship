/*
	string.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/basis/string.h 87    06/03/24 17:27 Someya $ */

#ifndef SLIM_STRING_H_PRIVATE
#define SLIM_STRING_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

/*        */
/* string */
/*        */

#define TStringFormatCookie_CurrentLength(self) ((self)->fOffset)

#define TString_Locate(self) ((slim_char *)slim_vhandle_locate((slim_vhandle)(self)))
#define TString_Unlocate(self) (slim_vhandle_unlocate((slim_vhandle)(self)))

/* format */




/*  String Formater */

typedef slim_int  (*slim_string_formatter)(slim_opaque in_obj, slim_char *in_buf);

/*              */
/* fixed string */
/*              */

#ifndef SLIM_CONFIG_FIXEDSTRING_REPLACE_STRING
#define TFixedString_Locate(self) (&((iTFixedString *)slim_handle_locate((slim_handle)(self)))->fString[0])
#define TFixedString_Unlocate(self) (slim_handle_unlocate((slim_handle)(self)))
#define TFixedString_EqualFS(self,fs) ((self)==(fs))
#define TFixedString_EqualCS(self,cs) (TFixedString_EqualSS((self), (cs), slim_strlen(cs)))
#define TFixedString_Length(self)	(slim_handle_peek_int((slim_handle)(self), SLIM_OFFSETOF(iTFixedString, fLen)))
#define TFixedString_Delete(self) ((void)TFixedString_Use((self), -1))
#else /* SLIM_CONFIG_FIXEDSTRING_REPLACE_STRING */
#define FixedString_Initialize() ((void)0)
#define FixedString_Finalize() ((void)0)
#define TFixedString_Locate(self) TString_Locate(self)
#define TFixedString_Unlocate(self) TString_Unlocate(self)
#define TFixedString_Hash(self) TString_Hash(self)
#define TFixedString_EqualFS(self,fs) TString_EqualTS(self, fs)
#define TFixedString_EqualCS(self,cs) (TFixedString_EqualSS((self), (cs), slim_strlen(cs)))
#define TFixedString_EqualTS(self, s) TString_EqualTS(self, s)
#define TFixedString_IEqualSS(self, s, len) TString_IEqualSS(self, s, len)
#define TFixedString_IEqualFS(self,fs) TString_IEqualTS(self, fs)
#define TFixedString_IsWhite(self) TString_IsWhite(self)
#ifdef SLIM_CONFIG_DEBUG
#define FixedString_DebugDump() ((void)0)
#define TFixedString_DebugDump(self, in_linebreak) ((void)0)
#endif
#endif /* SLIM_CONFIG_FIXEDSTRING_REPLACE_STRING */

SLIM_END_C_LINKAGE

#endif
