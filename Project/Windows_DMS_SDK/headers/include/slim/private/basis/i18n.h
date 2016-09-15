/*
	i18n.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/basis/i18n.h 139   06/07/31 9:20 Someya $ */

#ifndef SLIM_I18N_H_PRIVATE
#define SLIM_I18N_H_PRIVATE

#ifndef SLIM_I18NTYPE_H_PRIVATE
#include <slim/private/basis/i18ntype.h>
#endif
#ifndef SLIM_TOKEN_CHSET_H
#include <slim/private/token/chset.h>
#endif

SLIM_BEGIN_C_LINKAGE

#include <slim/private/basis/i18nrslv.h>

/*
 * CharSetInfo
 */
extern SLIM_ROM TCharSetInfo cSlim_Token_CHSET_unknown;

#define TCharSetInfo_LangSet(self) ((self)->fLangSet)
#define TCharSetInfo_FixedLength(self) ((self)->fInfo[0])
#define TCharSetInfo_MaxLength(self) ((self)->fInfo[1])
#define TCharSetInfo_MinLength(self) ((self)->fInfo[2])
#define TCharSetInfo_Flag(self) ((self)->fInfo[3])
#define TCharSetInfo_DoesUseISO2022(self) ((TCharSetInfo_Flag(self) & SLIM_CHARSET_FLAG_USE_ISO2022) != 0)
#define TCharSetInfo_IsGLASCII(self) ((TCharSetInfo_Flag(self) & SLIM_CHARSET_FLAG_GL_ISNOT_ASCII) == 0)
#define TCharSetInfo_IsNonOctet(self) (TCharSetinfo_FixedLength((self)) > 1)
#define TCharSetInfo_IsMultiPattern(self) ((TCharSetInfo_Flag(self) & SLIM_CHARSET_FLAG_MULTI_PATTERN) != 0)
#define TCharSetInfo_CTypeFlags(self) (&((self)->fCTypeFlags[0]))

#define CharSetInfo_IDToInfo(id) ((id) < 0 || SLIM_TOKEN_CHSET_TOKENS <= (id) ? (TCharSetInfo *)&cSlim_Token_CHSET_unknown : CharSetInfo_GetItem((id)))
#define TCharSetInfo_InfoToID(info) (!(info) ? SLIM_CHARSET_UNKNOWN : (info)->fBase.fID)
#define CharSetInfo_GetLangSet(id) (CharSetInfo_IDToInfo((id))->fLangSet)



#define CharSet_CheckMultiByte(s,len,charset) slim_i18n_charlen((s),(len),(charset))


#define CharSet_ChopString(s,l,cs) CharSet_ChopString2((s),(l),slim_nil,(cs))


#define CharSet_SplBefore_Char(ss,c,charset) (CharSet_Splxxx_CharOrIChar((ss),(c),(charset),SLIM_CLIB_SPLIT_BEFORE,slim_false))
#define CharSet_SplAfter_Char(ss,c,charset) (CharSet_Splxxx_CharOrIChar((ss),(c),(charset),SLIM_CLIB_SPLIT_AFTER,slim_false))
#define CharSet_SplBoth_Char(ss,c,charset) (CharSet_Splxxx_CharOrIChar((ss),(c),(charset),SLIM_CLIB_SPLIT_BOTH,slim_false))
#define CharSet_SplBefore_IChar(ss,c,charset) (CharSet_Splxxx_CharOrIChar((ss),(c),(charset),SLIM_CLIB_SPLIT_BEFORE,slim_true))
#define CharSet_SplAfter_IChar(ss,c,charset) (CharSet_Splxxx_CharOrIChar((ss),(c),(charset),SLIM_CLIB_SPLIT_AFTER,slim_true))
#define CharSet_SplBoth_IChar(ss,c,charset) (CharSet_Splxxx_CharOrIChar((ss),(c),(charset),SLIM_CLIB_SPLIT_BOTH,slim_true))

#define CharSet_SplBefore_Str(ss, p, charset) (CharSet_Splxxx_StrOrIStr((ss), (p), (charset), SLIM_CLIB_SPLIT_BEFORE,slim_false))
#define CharSet_SplAfter_Str(ss, p, charset) (CharSet_Splxxx_StrOrIStr((ss), (p), (charset), SLIM_CLIB_SPLIT_AFTER,slim_false))
#define CharSet_SplBoth_Str(ss, p, charset) (CharSet_Splxxx_StrOrIStr((ss), (p), (charset), SLIM_CLIB_SPLIT_BOTH,slim_false))
#define CharSet_SplBefore_IStr(ss, p, charset) (CharSet_Splxxx_StrOrIStr((ss), (p), (charset), SLIM_CLIB_SPLIT_BEFORE,slim_true))
#define CharSet_SplAfter_IStr(ss, p, charset) (CharSet_Splxxx_StrOrIStr((ss), (p), (charset), SLIM_CLIB_SPLIT_AFTER,slim_true))
#define CharSet_SplBoth_IStr(ss, p, charset) (CharSet_Splxxx_StrOrIStr((ss), (p), (charset), SLIM_CLIB_SPLIT_BOTH,slim_true))


/*              */
/* language set */
/*              */

#define LangSetInfo_GetItem(id) LangSetInfo_IDToInfo((id))
#define LangSetInfo_GetArchCharSet(id) (LangSetInfo_IDToInfo((id))->fArchCharSet)

/*                */
/* i18n converter */
/*                */

/* class method */

/* method */
#define TI18NConverter_DeterminedCharSet(self) ((slim_int)(self)->fDeterminedCharSet)
#define TI18NConverter_DeterminedLangSet(self) ((slim_int)(self)->fDeterminedLangSet)

/*
 * I18N Character
 */

#define TI18NChar_ToUpper(ch) TI18NChar_ToLowerOrUpper((ch), slim_true)
#define TI18NChar_ToLower(ch) TI18NChar_ToLowerOrUpper((ch), slim_false)


#define TI18NChar_FastReadString(self,s,len,cs,orl) {\
	SLIM_ASSERT(!TCharSetInfo_DoesUseISO2022(CharSetInfo_IDToInfo((cs))));\
	(*I18NCharProc_Find((cs))->uGetChar.Normal)((s),(len),(self));\
	*(orl) = SLIM_ABS((self)->fBytes);\
}
#define TI18NChar_ReadI18NStr(self, str, off) TI18NChar_ReadString((self), TI18NString_String((str)) + (off), TI18NString_Bytes((str)) - (off), TI18NString_CharSet((str)))
#define TI18NChar_FastReadI18NStr(self, str, off, orl) TI18NChar_FastReadString((self), TI18NString_String((str)) + (off), TI18NString_Bytes((str)) - (off), TI18NString_CharSet((str)), (orl))

#define TI18NChar_ReadString_ISO2022(self,s,len,cs,ctx) (SLIM_ASSERT(TCharSetInfo_DoesUseISO2022(CharSetInfo_IDToInfo((cs)))), (*I18NCharProc_Find((cs))->uGetChar.ISO2022)((s),(len),(self),(ctx)), SLIM_ABS((self)->fBytes))
#define TI18NChar_ReadI18NStr_ISO2022(self, str, off, ctx) TI18NChar_ReadString_ISO2022((self), TI18NString_String((str)) + (off), TI18NString_Bytes((str)) - (off), TI18NString_CharSet((str)), ctx)

#define SLIM_I18N_CMP_NOCASE	SLIM_STRCMP_NOCASE
#define SLIM_I18N_CMP_PREFIX	SLIM_STRCMP_PREFIX
#define SLIM_I18N_CMP_BY_UCS2	0x00000010
#define TI18NChar_Compare(self, t) TI18NChar_CompareX((self),(t), SLIM_FLAG_NONE)
#define TI18NChar_ICompare(self, t) TI18NChar_CompareX((self),(t), SLIM_I18N_CMP_NOCASE)
/* Ugh! too heavy */
#define TI18NChar_CompareByUCS2(self, t) TI18NChar_CompareX((self),(t), SLIM_I18N_CMP_BY_UCS2)
#define TI18NChar_ICompareByUCS2(self, t) TI18NChar_CompareX((self),(t), SLIM_I18N_CMP_BY_UCS2 | SLIM_I18N_CMP_NOCASE) 

#define TI18NChar_Init(self, charset) ((self)->fCharSet = (charset), (self)->fBytes = 0, (self)->fType = SLIM_I18NCHAR_TYPE_UNKNOWN)

/* ISO2022Ctx */

/*
 * I18NString
 */
#define TI18NStrForeachArg_Init(self,type) ((self)->fType = (type), (self)->fChars = (self)->fBytes = 0)

#define TI18NString_String(self) ((self)->fString)
#define TI18NString_CharSet(self) (TCharSetInfo_InfoToID((self)->fCharSetInfo))
#define TI18NString_CharSetInfo(self) ((self)->fCharSetInfo)
#define TI18NString_Bytes(self) ((self)->fBytes)

#define TI18NString_Foreach(self,proc,arg) TI18NString_ForeachX((self),(proc),(arg),slim_false)
#define TI18NString_StrictForeach(self,arg) TI18NString_ForeachX((self),(arg),slim_true)
#define TI18NString_ConvertToUpper(self,rl,ob) TI18NString_ConvertToLowerOrUpper((self),(rl),(ob),slim_true)
#define TI18NString_ConvertToLower(self,rl,ob) TI18NString_ConvertToLowerOrUpper((self),(rl),(ob),slim_false)

#define TI18NString_CharsToBytes(self,n,oc,ob) TI18NString_CharsBytes((self),(n),(oc),(ob),slim_true)
#define TI18NString_BytesToChars(self,n,oc,ob) TI18NString_CharsBytes((self),(n),(oc),(ob),slim_false)



/*
 * CharLenInfo
 */

#define TI18NCharLenInfo_Init(self, cs) ( \
	(self)->fCTypeFlags = TCharSetInfo_CTypeFlags(CharSetInfo_IDToInfo((cs))), \
	(self)->fGLIsASCII = TCharSetInfo_IsGLASCII(CharSetInfo_IDToInfo((cs))), \
	(self)->fCheckCharProc = I18NCharProc_Find((cs))->uCheckChar.Normal \
)

#define slim_i18n_fastcharlen(s,l,info) ( (l) < 1 ? 0 : ( \
	((info)->fGLIsASCII && !((s)[0] & 0x80)) ? 1 \
	: (\
		((info)->fCTypeFlags[0] != SLIM_FLAG_NONE && (l) >= 2 && slim_i18n_isctype((s)[0],(info)->fCTypeFlags[0]) && slim_i18n_isctype((s)[1],(info)->fCTypeFlags[1])) ? 2 \
		: ( \
			(info)->fCheckCharProc ? \
				(*(info)->fCheckCharProc)((s),(l), &(info)->fCharType) : 1 \
		) \
	) \
))

/* returns a number of bytes of the first character of in_s.
 * zero means that in_len is too short to determine (incomplete character).
 * negative values means that the character has a invalid byte; an ablosute value of a returned value is a number of bytes to be skipped.
 */

/*
 * I18NStringIterator
 */

#define TI18NStringIterator_Ptr(self) (TI18NString_String((self)->fString) + (self)->fOffset)
#define TI18NStringIterator_Remain(self) (TI18NString_Bytes((self)->fString) - (self)->fOffset)
#define TI18NStringIterator_Offset(self) ((self)->fOffset)
#define TI18NStringIterator_ReadLen(self) ((self)->fReadLen)
#define TI18NStringIterator_CurChar(self) ((self)->fReadLen < 0 ? (TI18NStringIterator_DoGetChar((self)), &(self)->fCurChar) : &(self)->fCurChar)
#define TI18NStringIterator_Chars(self) ((self)->fLeadingChars)
#define TI18NStringIterator_RemainChars(self) (TI18NString_Chars((self)->fString) - (self)->fLeadingChars)
#define TI18NStringIterator_IsEnd(self) (TI18NStringIterator_Remain(self) < 1 || (self)->fReadLen == 0)

#define TI18NStringIterator_Next(self) TI18NStringIterator_NextX((self), slim_false)
#define TI18NStringIterator_StrictNext(self) TI18NStringIterator_NextX((self), slim_true)
#define TI18NStringIterator_ForwardByChars(self,num,oi) TI18NStringIterator_Forward((self),(num),(oi),slim_true,slim_false)
#define TI18NStringIterator_ForwardByBytes(self,num,oi) TI18NStringIterator_Forward((self),(num),(oi),slim_false,slim_false)
#define TI18NStringIterator_StrictForwardByChars(self,num,oi) TI18NStringIterator_Forward((self),(num),(oi),slim_true,slim_true)
#define TI18NStringIterator_StrictForwardByBytes(self,num,oi) TI18NStringIterator_Forward((self),(num),(oi),slim_false,slim_true)



/* compare */
#define SLIM_I18N_STRCOMP_STREQ (SLIM_FLAG_NONE)
#define SLIM_I18N_STRCOMP_ISTREQ (SLIM_I18N_CMP_NOCASE)
#define SLIM_I18N_STRCOMP_PREFIX (SLIM_I18N_CMP_PREFIX)
#define SLIM_I18N_STRCOMP_IPREFIX (SLIM_I18N_CMP_PREFIX|SLIM_I18N_CMP_NOCASE)
#define slim_i18n_ss_xxx_ss(s,sl,sc,t,tl,tc,oc,flag) (0 == slim_i18n_strcmpX((s),(sl),(sc),(t),(tl),(tc),(oc),(flag)))

#define slim_i18n_ss_streq_ss(s,sl,sc,t,tl,tc,oc) slim_i18n_ss_xxx_ss((s),(sl),(sc),(t),(tl),(tc),(oc),SLIM_I18N_CMP_EQUAL)
#define slim_i18n_ss_istreq_ss(s,sl,sc,t,tl,tc,oc) slim_i18n_ss_xxx_ss((s),(sl),(sc),(t),(tl),(tc),(oc),SLIM_I18N_CMP_EQUAL|SLIM_I18N_CMP_NOCASE)
#define slim_i18n_ss_prefix_ss(s,sl,sc,t,tl,tc,oc) slim_i18n_ss_xxx_ss((s),(sl),(sc),(t),(tl),(tc),(oc),SLIM_I18N_CMP_PREFIX)
#define slim_i18n_ss_iprefix_ss(s,sl,sc,t,tl,tc,oc) slim_i18n_ss_xxx_ss((s),(sl),(sc),(t),(tl),(tc),(oc),SLIM_I18N_CMP_PREFIX|SLIM_I18N_CMP_NOCASE)

/* Ugh! too heavy */
#define slim_i18n_ss_streq_ss_ucs2(s,sl,sc,t,tl,tc,oc) slim_i18n_ss_xxx_ss((s),(sl),(sc),(t),(tl),(tc),(oc),SLIM_I18N_CMP_EQUAL|SLIM_I18N_CMP_BY_UCS2)
#define slim_i18n_ss_istreq_ss_ucs2(s,sl,sc,t,tl,tc,oc) slim_i18n_ss_xxx_ss((s),(sl),(sc),(t),(tl),(tc),(oc),SLIM_I18N_CMP_EQUAL|SLIM_I18N_CMP_NOCASE|SLIM_I18N_CMP_BY_UCS2)
#define slim_i18n_ss_prefix_ss_ucs2(s,sl,sc,t,tl,tc,oc) slim_i18n_ss_xxx_ss((s),(sl),(sc),(t),(tl),(tc),(oc),SLIM_I18N_CMP_PREFIX|SLIM_I18N_CMP_BY_UCS2)
#define slim_i18n_ss_iprefix_ss_ucs2(s,sl,sc,t,tl,tc,oc) slim_i18n_ss_xxx_ss((s),(sl),(sc),(t),(tl),(tc),(oc),SLIM_I18N_CMP_PREFIX|SLIM_I18N_CMP_NOCASE|SLIM_I18N_CMP_BY_UCS2)

#define CharSet_Collate(s, slen, t, tlen, chset) slim_i18n_strcmpX((s), (slen), (chset), (t), (tlen), (chset), slim_nil, SLIM_I18N_STRCOMP_STREQ)

#define CharSet_SS_Streq_SS(s, slen, t, tlen, chset) slim_i18n_ss_streq_ss((s),(slen),(chset),(t),(tlen),(chset),slim_nil)
#define CharSet_SS_IStreq_SS(s, slen, t, tlen, chset) slim_i18n_ss_istreq_ss((s),(slen),(chset),(t),(tlen),(chset),slim_nil)
#define CharSet_SS_Prefix_SS(s, slen, t, tlen, chset) slim_i18n_ss_prefix_ss((s),(slen),(chset),(t),(tlen),(chset),slim_nil)
#define CharSet_SS_IPrefix_SS(s, slen, t, tlen, chset) slim_i18n_ss_iprefix_ss((s),(slen),(chset),(t),(tlen),(chset),slim_nil)

/*
 * slim_i18n_xxx
 */

#define slim_i18n_ucs_ucs4_is_be(ch) ((ch)->fCharSet == SLIM_CHARSET_UCS_4BE)
#define slim_i18n_ucs_ucs2_is_be(ch) ((ch)->fCharSet == SLIM_CHARSET_UCS_2BE)

#define slim_i18n_ucs_ucs4_is_pua(ch) (0xE000 <= slim_i18n_ucs_ucs4_to_int((ch)) && slim_i18n_ucs_ucs4_to_int((ch)) < 0xE900)
#define slim_i18n_ucs_ucs2_is_pua(ch) (0xE000 <= slim_i18n_ucs_ucs2_to_int((ch)) && slim_i18n_ucs_ucs2_to_int((ch)) < 0xE900)

#define slim_i18n_ucs_ucs4_to_int(ch) (((ch)->fChar[slim_i18n_ucs_ucs4_is_be((ch))?0:3] << 24)|((ch)->fChar[slim_i18n_ucs_ucs4_is_be((ch))?1:2] << 16)|((ch)->fChar[slim_i18n_ucs_ucs4_is_be((ch))?2:1] << 8)|(ch)->fChar[slim_i18n_ucs_ucs4_is_be((ch))?3:0])
#define slim_i18n_ucs_ucs2_to_int(ch) (((ch)->fChar[slim_i18n_ucs_ucs2_is_be((ch))?0:1] << 8)|(ch)->fChar[slim_i18n_ucs_ucs2_is_be((ch))?1:0])

/* Unknown */
#define slim_i18n_checkch_unknown(s,l,ot) slim_i18n_checkch_en_us_ascii((s),(l),(ot))

/* Western */
#define slim_i18n_checkch_en_us_ascii(s,l,ot) ((l) < 1 ? 0 : (*(ot) = ((s)[0] < 0x80 ? ((s)[0] < 0x20 || (s)[0] == 0x7F ? SLIM_I18NCHAR_TYPE_CTRL : SLIM_I18NCHAR_TYPE_ASCII) : SLIM_I18NCHAR_TYPE_UNKNOWN), 1) )
#define slim_i18n_checkch_la_iso8859_1(s,l,ot) slim_i18n_checkch_la_iso8859_x((s),(l),(ot))
#define slim_i18n_checkch_la_iso8859_15(s,l,ot) slim_i18n_checkch_la_iso8859_x((s),(l),(ot))
#define slim_i18n_checkch_la_windows_1252(s,l,ot) slim_i18n_checkch_la_iso8859_x((s),(l),(ot))

/* Baltic */
#define slim_i18n_checkch_lv_iso8859_4(s,l,ot) slim_i18n_checkch_la_iso8859_x((s),(l),(ot))
#define slim_i18n_checkch_lv_windows_1257(s,l,ot) slim_i18n_checkch_la_iso8859_x((s),(l),(ot))

/* Central European */
#define slim_i18n_checkch_la_iso8859_2(s,l,ot) slim_i18n_checkch_la_iso8859_x((s),(l),(ot))
#define slim_i18n_checkch_la_windows_1250(s,l,ot) slim_i18n_checkch_la_iso8859_x((s),(l),(ot))

/* Cyrillic */
#define slim_i18n_checkch_la_iso8859_5(s,l,ot) slim_i18n_checkch_la_iso8859_x((s),(l),(ot))
#define slim_i18n_checkch_la_windows_1251(s,l,ot) slim_i18n_checkch_la_iso8859_x((s),(l),(ot))
#define slim_i18n_checkch_ru_koi8r(s,l,ot) slim_i18n_checkch_la_iso8859_x((s),(l),(ot))

/* Greek */
#define slim_i18n_checkch_el_iso8859_7(s,l,ot) slim_i18n_checkch_la_iso8859_x((s),(l),(ot))
#define  slim_i18n_checkch_el_windows_1253(s,l,ot) slim_i18n_checkch_la_iso8859_x((s),(l),(ot))

/* Nordic */
#define slim_i18n_checkch_la_iso8859_10(s,l,ot) slim_i18n_checkch_la_iso8859_x((s),(l),(ot))

/* South European */
#define slim_i18n_checkch_la_iso8859_3(s,l,ot) slim_i18n_checkch_la_iso8859_x((s),(l),(ot))

/* Thai */
#define slim_i18n_checkch_th_windows_874(s,l,ot) slim_i18n_checkch_la_iso8859_x((s),(l),(ot))

/* Turkish */
#define slim_i18n_checkch_tr_iso8859_9(s,l,ot) slim_i18n_checkch_la_iso8859_x((s),(l),(ot))
#define slim_i18n_checkch_tr_windows_1254(s,l,ot) slim_i18n_checkch_la_iso8859_x((s),(l),(ot))

/* Arabic */
#define slim_i18n_checkch_ar_iso8859_6(s,l,ot) slim_i18n_checkch_la_iso8859_x((s),(l),(ot))
#define slim_i18n_checkch_ar_windows_1256(s,l,ot) slim_i18n_checkch_la_iso8859_x((s),(l),(ot))

/* Hebrew */
#define slim_i18n_checkch_he_iso8859_8(s,l,ot) slim_i18n_checkch_la_iso8859_x((s),(l),(ot))
#define slim_i18n_checkch_he_windows_1255(s,l,ot) slim_i18n_checkch_la_iso8859_x((s),(l),(ot))

/*
 * get char
 */

#define CharSet_GetChar(cs,s,len,orl,oc) (*(orl) = TI18NChar_ReadString((oc),(s),(len),(cs)))

#define SLIM_I18N_GETCH_ANY(s,l,oc,cs,checkch_macro,tmpnum) \
{\
	TI18NChar_Init((oc), (cs));\
	checkch_macro ((s), (l), &(oc)->fType, &tmpnum);\
	if(tmpnum != 0) \
		SLIM_I18N_GETCH_READ_CHAR((oc), (s), tmpnum);\
}

#define SLIM_I18N_GETCH_READ_CHAR(och,s,num) { \
	(och)->fBytes = num; \
	num = SLIM_ABS(num); \
	(och)->fChar[0] = (s)[0]; num--;\
	if(num > 0){ \
		(och)->fChar[1] = (s)[1]; num--; \
		for(; num > 0; num--) (och)->fChar[num+1] = (s)[num+1]; \
	} \
}

/* Unknown */
#define slim_i18n_getch_unknown(s,len,oc) slim_i18n_getch_any((s),(len),(oc),SLIM_CHARSET_UNKNOWN)

/* Western */
#define slim_i18n_getch_la_iso8859_1(s,l,c) slim_i18n_getch_la_iso8859_X((s),(l),(c),SLIM_CHARSET_ISO_8859_1)
#define slim_i18n_getch_la_iso8859_15(s,l,c) slim_i18n_getch_la_iso8859_X((s),(l),(c),SLIM_CHARSET_ISO_8859_15)
#define slim_i18n_getch_la_windows_1252(s,l,c) slim_i18n_getch_la_iso8859_X((s),(l),(c),SLIM_CHARSET_WINDOWS_1252)

/* Baltic */
#define slim_i18n_getch_lv_iso8859_4(s,l,c) slim_i18n_getch_la_iso8859_X((s),(l),(c),SLIM_CHARSET_ISO_8859_4)
#define slim_i18n_getch_lv_windows_1257(s,l,c) slim_i18n_getch_la_iso8859_X((s),(l),(c),SLIM_CHARSET_WINDOWS_1257)

/* Central European */
#define slim_i18n_getch_la_iso8859_2(s,l,c) slim_i18n_getch_la_iso8859_X((s),(l),(c),SLIM_CHARSET_ISO_8859_2)
#define slim_i18n_getch_la_windows_1250(s,l,c) slim_i18n_getch_la_iso8859_X((s),(l),(c),SLIM_CHARSET_WINDOWS_1250)

/* Cyrillic */
#define slim_i18n_getch_la_iso8859_5(s,l,c) slim_i18n_getch_la_iso8859_X((s),(l),(c),SLIM_CHARSET_ISO_8859_5)
#define slim_i18n_getch_la_windows_1251(s,l,c) slim_i18n_getch_la_iso8859_X((s),(l),(c),SLIM_CHARSET_WINDOWS_1251)
#define slim_i18n_getch_ru_koi8r(s,l,oc) slim_i18n_getch_any((s),(l),(oc), SLIM_CHARSET_KOI8_R)

/* Greek */
#define slim_i18n_getch_el_iso8859_7(s,l,c) slim_i18n_getch_la_iso8859_X((s),(l),(c),SLIM_CHARSET_ISO_8859_7)
#define slim_i18n_getch_el_windows_1253(s,l,c) slim_i18n_getch_la_iso8859_X((s),(l),(c),SLIM_CHARSET_WINDOWS_1253)

/* Nordic */
#define slim_i18n_getch_la_iso8859_10(s,l,c) slim_i18n_getch_la_iso8859_X((s),(l),(c),SLIM_CHARSET_ISO_8859_10)

/* South European */
#define slim_i18n_getch_la_iso8859_3(s,l,c) slim_i18n_getch_la_iso8859_X((s),(l),(c),SLIM_CHARSET_ISO_8859_3)

/* Thai */
#define slim_i18n_getch_th_windows_874(s,l,oc) slim_i18n_getch_any((s),(l),(oc), SLIM_CHARSET_WINDOWS_874)

/* Turkish */
#define slim_i18n_getch_tr_iso8859_9(s,l,c) slim_i18n_getch_la_iso8859_X((s),(l),(c),SLIM_CHARSET_ISO_8859_9)
#define slim_i18n_getch_tr_windows_1254(s,l,c) slim_i18n_getch_la_iso8859_X((s),(l),(c),SLIM_CHARSET_WINDOWS_1254)

/* Arabic */
#define slim_i18n_getch_ar_iso8859_6(s,l,c) slim_i18n_getch_la_iso8859_X((s),(l),(c), SLIM_CHARSET_ISO_8859_6)
#define slim_i18n_getch_ar_windows_1256(s,l,c) slim_i18n_getch_la_iso8859_X((s),(l),(c),SLIM_CHARSET_WINDOWS_1256)

/* Hebrew */
#define slim_i18n_getch_he_iso8859_8(s,l,c)  slim_i18n_getch_la_iso8859_X((s),(l),(c), SLIM_CHARSET_ISO_8859_8)
#define slim_i18n_getch_he_windows_1255(s,l,c) slim_i18n_getch_la_iso8859_X((s),(l),(c),SLIM_CHARSET_WINDOWS_1255)

/*
 * convert character
 */

typedef void (*slim_i18n_convch_proc)(TI18NChar *in_char, TI18NChar *out_char);

#define SLIM_I18N_CONVCH_WRITE_CHAR(ptr,ich,num) { \
	if((ptr)){ \
		for(num = (ich)->fBytes; num > 0; num--) (ptr)[num-1] = (ich)->fChar[num-1]; \
		ptr += (ich)->fBytes; \
	} \
}

/* UCS */
#define slim_i18n_convch_ucs_utf8_to_ucs4be(ich, och) slim_i18n_convch_ucs_utf8_to_ucs4((ich), (och), slim_true)
#define slim_i18n_convch_ucs_utf8_to_ucs4le(ich, och) slim_i18n_convch_ucs_utf8_to_ucs4((ich), (och), slim_false)
#define slim_i18n_convch_ucs_utf16_to_ucs4be(ich, och) slim_i18n_convch_ucs_utf16_to_ucs4((ich), (och), slim_true)
#define slim_i18n_convch_ucs_utf16_to_ucs4le(ich, och) slim_i18n_convch_ucs_utf16_to_ucs4((ich), (och), slim_false)
#define slim_i18n_convch_ucs_ucs4_to_utf16be(ich,och) slim_i18n_convch_ucs_ucs4_to_utf16((ich),(och),slim_true)
#define slim_i18n_convch_ucs_ucs4_to_utf16le(ich,och) slim_i18n_convch_ucs_ucs4_to_utf16((ich),(och),slim_false)
#define slim_i18n_convch_ucs_ucs4_to_ucs2be(ich, och) slim_i18n_convch_ucs_ucs4_to_ucs2((ich), (och), slim_true)
#define slim_i18n_convch_ucs_ucs4_to_ucs2le(ich, och) slim_i18n_convch_ucs_ucs4_to_ucs2((ich), (och), slim_false)
#define slim_i18n_convch_ucs_ucs2_to_ucs4be(ich, och) slim_i18n_convch_ucs_ucs2_to_ucs4((ich), (och), slim_true)
#define slim_i18n_convch_ucs_ucs2_to_ucs4le(ich, och) slim_i18n_convch_ucs_ucs2_to_ucs4((ich), (och), slim_false)

#define slim_i18n_convch_ucs_ucs2_to_ucs2(ic,oc,cs) ((ic)->fCharSet == (cs) ? (*(oc) = *(ic), slim_true) : (TI18NChar_Init((oc), (cs)), (oc)->fType = (ic)->fType, (oc)->fChar[1] = (ic)->fChar[0], (oc)->fChar[0] = (ic)->fChar[1], (oc)->fBytes = 2, slim_true))
#define slim_i18n_convch_ucs_ucs2_to_ucs2be(ic,oc) slim_i18n_convch_ucs_ucs2_to_ucs2((ic),(oc),SLIM_CHARSET_UCS_2BE)
#define slim_i18n_convch_ucs_ucs2_to_ucs2le(ic,oc) slim_i18n_convch_ucs_ucs2_to_ucs2((ic),(oc),SLIM_CHARSET_UCS_2LE)

#define slim_i18n_convch_ucs_ucs4_to_ucs4(ic,oc,cs) ((ic)->fCharSet == (cs) ? (*(oc) = *(ic), slim_true) : (TI18NChar_Init((oc), (cs)), (oc)->fType = (ic)->fType, (oc)->fChar[3] = (ic)->fChar[0], (oc)->fChar[2] = (ic)->fChar[1], (oc)->fChar[1] = (ic)->fChar[2], (oc)->fChar[0] = (ic)->fChar[3], (oc)->fBytes = 4, slim_true))
#define slim_i18n_convch_ucs_ucs4_to_ucs4be(ic,oc) slim_i18n_convch_ucs_ucs4_to_ucs4((ic),(oc),SLIM_CHARSET_UCS_4BE)
#define slim_i18n_convch_ucs_ucs4_to_ucs4le(ic,oc) slim_i18n_convch_ucs_ucs4_to_ucs4((ic),(oc),SLIM_CHARSET_UCS_4LE)

/* Western */
#define slim_i18n_convch_ucs_iso8859_1_to_ucs2be(ic,oc) slim_i18n_convch_ucs_iso8859_1_to_ucs2((ic),(oc),slim_true)
#define slim_i18n_convch_ucs_iso8859_1_to_ucs2le(ic,oc) slim_i18n_convch_ucs_iso8859_1_to_ucs2((ic),(oc),slim_false)

#define slim_i18n_convch_ucs_iso8859_15_to_ucs2be(ic,oc) slim_i18n_convch_ucs_iso8859_15_to_ucs2((ic),(oc),slim_true)
#define slim_i18n_convch_ucs_iso8859_15_to_ucs2le(ic,oc) slim_i18n_convch_ucs_iso8859_15_to_ucs2((ic),(oc),slim_false)

#define slim_i18n_convch_ucs_windows1252_to_ucs2be(ic,oc) slim_i18n_convch_ucs_windows1252_to_ucs2((ic),(oc),slim_true)
#define slim_i18n_convch_ucs_windows1252_to_ucs2le(ic,oc) slim_i18n_convch_ucs_windows1252_to_ucs2((ic),(oc),slim_false)

/* Baltic */
#define slim_i18n_convch_ucs_iso8859_4_to_ucs2be(ic,oc) slim_i18n_convch_ucs_iso8859_4_to_ucs2((ic),(oc),slim_true)
#define slim_i18n_convch_ucs_iso8859_4_to_ucs2le(ic,oc) slim_i18n_convch_ucs_iso8859_4_to_ucs2((ic),(oc),slim_false)

#define slim_i18n_convch_ucs_windows1257_to_ucs2be(ic,oc) slim_i18n_convch_ucs_windows1257_to_ucs2((ic),(oc),slim_true)
#define slim_i18n_convch_ucs_windows1257_to_ucs2le(ic,oc) slim_i18n_convch_ucs_windows1257_to_ucs2((ic),(oc),slim_false)

/* Central European */
#define slim_i18n_convch_ucs_iso8859_2_to_ucs2be(ic,oc) slim_i18n_convch_ucs_iso8859_2_to_ucs2((ic),(oc),slim_true)
#define slim_i18n_convch_ucs_iso8859_2_to_ucs2le(ic,oc) slim_i18n_convch_ucs_iso8859_2_to_ucs2((ic),(oc),slim_false)

#define slim_i18n_convch_ucs_windows1250_to_ucs2be(ic,oc) slim_i18n_convch_ucs_windows1250_to_ucs2((ic),(oc),slim_true)
#define slim_i18n_convch_ucs_windows1250_to_ucs2le(ic,oc) slim_i18n_convch_ucs_windows1250_to_ucs2((ic),(oc),slim_false)

/* Cyrillic */
#define slim_i18n_convch_ucs_iso8859_5_to_ucs2be(ic,oc) slim_i18n_convch_ucs_iso8859_5_to_ucs2((ic),(oc),slim_true)
#define slim_i18n_convch_ucs_iso8859_5_to_ucs2le(ic,oc) slim_i18n_convch_ucs_iso8859_5_to_ucs2((ic),(oc),slim_false)

#define slim_i18n_convch_ucs_windows1251_to_ucs2be(ic,oc) slim_i18n_convch_ucs_windows1251_to_ucs2((ic),(oc),slim_true)
#define slim_i18n_convch_ucs_windows1251_to_ucs2le(ic,oc) slim_i18n_convch_ucs_windows1251_to_ucs2((ic),(oc),slim_false)

#define slim_i18n_convch_ucs_koi8_r_to_ucs2be(ic,oc) slim_i18n_convch_ucs_koi8_r_to_ucs2((ic),(oc),slim_true)
#define slim_i18n_convch_ucs_koi8_r_to_ucs2le(ic,oc) slim_i18n_convch_ucs_koi8_r_to_ucs2((ic),(oc),slim_false)

/* Greek */
#define slim_i18n_convch_ucs_iso8859_7_to_ucs2be(ic,oc) slim_i18n_convch_ucs_iso8859_7_to_ucs2((ic),(oc),slim_true)
#define slim_i18n_convch_ucs_iso8859_7_to_ucs2le(ic,oc) slim_i18n_convch_ucs_iso8859_7_to_ucs2((ic),(oc),slim_false)

#define slim_i18n_convch_ucs_windows1253_to_ucs2be(ic,oc) slim_i18n_convch_ucs_windows1253_to_ucs2((ic),(oc),slim_true)
#define slim_i18n_convch_ucs_windows1253_to_ucs2le(ic,oc) slim_i18n_convch_ucs_windows1253_to_ucs2((ic),(oc),slim_false)

/* Nordic */
#define slim_i18n_convch_ucs_iso8859_10_to_ucs2be(ic,oc) slim_i18n_convch_ucs_iso8859_10_to_ucs2((ic),(oc),slim_true)
#define slim_i18n_convch_ucs_iso8859_10_to_ucs2le(ic,oc) slim_i18n_convch_ucs_iso8859_10_to_ucs2((ic),(oc),slim_false)

/* South European */
#define slim_i18n_convch_ucs_iso8859_3_to_ucs2be(ic,oc) slim_i18n_convch_ucs_iso8859_3_to_ucs2((ic),(oc),slim_true)
#define slim_i18n_convch_ucs_iso8859_3_to_ucs2le(ic,oc) slim_i18n_convch_ucs_iso8859_3_to_ucs2((ic),(oc),slim_false)

/* Thai */
#define slim_i18n_convch_ucs_windows874_to_ucs2be(ic,oc) slim_i18n_convch_ucs_windows874_to_ucs2((ic),(oc),slim_true)
#define slim_i18n_convch_ucs_windows874_to_ucs2le(ic,oc) slim_i18n_convch_ucs_windows874_to_ucs2((ic),(oc),slim_false)

/* Turkish */
#define slim_i18n_convch_ucs_iso8859_9_to_ucs2be(ic,oc) slim_i18n_convch_ucs_iso8859_9_to_ucs2((ic),(oc),slim_true)
#define slim_i18n_convch_ucs_iso8859_9_to_ucs2le(ic,oc) slim_i18n_convch_ucs_iso8859_9_to_ucs2((ic),(oc),slim_false)

#define slim_i18n_convch_ucs_windows1254_to_ucs2be(ic,oc) slim_i18n_convch_ucs_windows1254_to_ucs2((ic),(oc),slim_true)
#define slim_i18n_convch_ucs_windows1254_to_ucs2le(ic,oc) slim_i18n_convch_ucs_windows1254_to_ucs2((ic),(oc),slim_false)

/* Arabic */
#define slim_i18n_convch_ucs_iso8859_6_to_ucs2be(ic,oc) slim_i18n_convch_ucs_iso8859_6_to_ucs2((ic),(oc),slim_true)
#define slim_i18n_convch_ucs_iso8859_6_to_ucs2le(ic,oc) slim_i18n_convch_ucs_iso8859_6_to_ucs2((ic),(oc),slim_false)

#define slim_i18n_convch_ucs_windows1256_to_ucs2be(ic,oc) slim_i18n_convch_ucs_windows1256_to_ucs2((ic),(oc),slim_true)
#define slim_i18n_convch_ucs_windows1256_to_ucs2le(ic,oc) slim_i18n_convch_ucs_windows1256_to_ucs2((ic),(oc),slim_false)

/* Hebrew */
#define slim_i18n_convch_ucs_iso8859_8_to_ucs2be(ic,oc) slim_i18n_convch_ucs_iso8859_8_to_ucs2((ic),(oc),slim_true)
#define slim_i18n_convch_ucs_iso8859_8_to_ucs2le(ic,oc) slim_i18n_convch_ucs_iso8859_8_to_ucs2((ic),(oc),slim_false)

#define slim_i18n_convch_ucs_windows1255_to_ucs2be(ic,oc) slim_i18n_convch_ucs_windows1255_to_ucs2((ic),(oc),slim_true)
#define slim_i18n_convch_ucs_windows1255_to_ucs2le(ic,oc) slim_i18n_convch_ucs_windows1255_to_ucs2((ic),(oc),slim_false)

/*
 * i18n_split
 */

#define SLIM_I18NSPL_FLAG_BOTH	0x00000001
#define SLIM_I18NSPL_FLAG_AFTER	0x00000002
#define SLIM_I18NSPL_FLAG_BEFORE	0x00000004
#define SLIM_I18NSPL_MASK_TYPE	(SLIM_I18NSPL_FLAG_BOTH|SLIM_I18NSPL_FLAG_AFTER|SLIM_I18NSPL_FLAG_BEFORE)
#define SLIM_I18NSPL_FLAG_DELIM	0x00000008
#define SLIM_I18NSPL_FLAG_IGNORECASE	0x00000010
#define SLIM_I18NSPL_FLAG_SKIPINCOMPLETE	0x00000020

#define slim_i18n_spl_type(flag) ( ((flag) & SLIM_I18NSPL_FLAG_BOTH) ? SLIM_CLIB_SPLIT_BOTH : (\
	((flag) & SLIM_I18NSPL_FLAG_AFTER) ? SLIM_CLIB_SPLIT_AFTER : SLIM_CLIB_SPLIT_BEFORE))
#define slim_i18n_spl_is_ignorecase(flag) ((flag) & SLIM_I18NSPL_FLAG_IGNORECASE)
#define slim_i18n_spl_is_delim(flag) ((flag) & SLIM_I18NSPL_FLAG_DELIM)
#define slim_i18n_spl_skipincomplete(flag) ((flag) & SLIM_I18NSPL_FLAG_SKIPINCOMPLETE)

#define slim_i18n_splboth_char(ss, chset, ch, len, chset2) slim_i18n_splxxx_char_or_ichar((ss), (chset), (ch), (len), (chset2),slim_nil, SLIM_I18NSPL_FLAG_BOTH)
#define slim_i18n_splafter_char(ss, chset, ch, len, chset2) slim_i18n_splxxx_char_or_ichar((ss), (chset), (ch), (len), (chset2),slim_nil, SLIM_I18NSPL_FLAG_AFTER)
#define slim_i18n_splbefore_char(ss, chset, ch, len, chset2) slim_i18n_splxxx_char_or_ichar((ss), (chset), (ch), (len), (chset2),slim_nil, SLIM_I18NSPL_FLAG_BEFORE)
#define slim_i18n_splboth_ichar(ss, chset, ch, len, chset2) slim_i18n_splxxx_char_or_ichar((ss), (chset), (ch), (len), (chset2),slim_nil, SLIM_I18NSPL_FLAG_BOTH|SLIM_I18NSPL_FLAG_IGNORECASE)
#define slim_i18n_splafter_ichar(ss, chset, ch, len, chset2) slim_i18n_splxxx_char_or_ichar((ss), (chset), (ch), (len), (chset2),slim_nil, SLIM_I18NSPL_FLAG_AFTER|SLIM_I18NSPL_FLAG_IGNORECASE)
#define slim_i18n_splbefore_ichar(ss, chset, ch, len, chset2) slim_i18n_splxxx_char_or_ichar((ss), (chset), (ch), (len), (chset2),slim_nil, SLIM_I18NSPL_FLAG_BEFORE|SLIM_I18NSPL_FLAG_IGNORECASE)

#define slim_i18n_splboth_str(ss, chset, str, len, chset2) slim_i18n_splxxx_str_or_istr((ss), (chset), (str), (len), (chset2),slim_nil, SLIM_I18NSPL_FLAG_BOTH)
#define slim_i18n_splafter_str(ss, chset, str, len, chset2) slim_i18n_splxxx_str_or_istr((ss), (chset), (str), (len), (chset2),slim_nil, SLIM_I18NSPL_FLAG_AFTER)
#define slim_i18n_splbefore_str(ss, chset, str, len, chset2) slim_i18n_splxxx_str_or_istr((ss), (chset), (str), (len), (chset2),slim_nil, SLIM_I18NSPL_FLAG_BEFORE)
#define slim_i18n_splboth_istr(ss, chset, str, len, chset2) slim_i18n_splxxx_str_or_istr((ss), (chset), (str), (len), (chset2),slim_nil, SLIM_I18NSPL_FLAG_BOTH|SLIM_I18NSPL_FLAG_IGNORECASE)
#define slim_i18n_splafter_istr(ss, chset, str, len, chset2) slim_i18n_splxxx_str_or_istr((ss), (chset), (str), (len), (chset2),slim_nil, SLIM_I18NSPL_FLAG_AFTER|SLIM_I18NSPL_FLAG_IGNORECASE)
#define slim_i18n_splbefore_istr(ss, chset, str, len, chset2) slim_i18n_splxxx_str_or_istr((ss), (chset), (str), (len), (chset2),slim_nil, SLIM_I18NSPL_FLAG_BEFORE|SLIM_I18NSPL_FLAG_IGNORECASE)

#define slim_i18n_splboth_delim(ss, chset, chars, len, chset2) slim_i18n_splxxx_delim_or_span_chars_or_ctype((ss), (chset), (chars), (len), (chset2),slim_nil,slim_nil, SLIM_I18NSPL_FLAG_BOTH|SLIM_I18NSPL_FLAG_DELIM)
#define slim_i18n_splafter_delim(ss, chset, chars, len, chset2) slim_i18n_splxxx_delim_or_span_chars_or_ctype((ss), (chset), (chars), (len), (chset2),slim_nil,slim_nil, SLIM_I18NSPL_FLAG_AFTER|SLIM_I18NSPL_FLAG_DELIM)
#define slim_i18n_splbefore_delim(ss, chset, chars, len, chset2) slim_i18n_splxxx_delim_or_span_chars_or_ctype((ss), (chset), (chars), (len), (chset2),slim_nil,slim_nil, SLIM_I18NSPL_FLAG_BEFORE|SLIM_I18NSPL_FLAG_DELIM)
#define slim_i18n_splboth_span(ss, chset, chars, len, chset2) slim_i18n_splxxx_delim_or_span_chars_or_ctype((ss), (chset), (chars), (len), (chset2),slim_nil,slim_nil, SLIM_I18NSPL_FLAG_BOTH)
#define slim_i18n_splafter_span(ss, chset, chars, len, chset2) slim_i18n_splxxx_delim_or_span_chars_or_ctype((ss), (chset), (chars), (len), (chset2),slim_nil,slim_nil, SLIM_I18NSPL_FLAG_AFTER)
#define slim_i18n_splbefore_span(ss, chset, chars, len, chset2) slim_i18n_splxxx_delim_or_span_chars_or_ctype((ss), (chset), (chars), (len), (chset2),slim_nil,slim_nil, SLIM_I18NSPL_FLAG_BEFORE)

#define slim_i18n_splboth_delim_chars_or_ctype(ss, chset, chars, len, chset2, proc) slim_i18n_splxxx_delim_or_span_chars_or_ctype((ss), (chset), (chars), (len), (chset2),(proc),slim_nil, SLIM_I18NSPL_FLAG_BOTH|SLIM_I18NSPL_FLAG_DELIM)
#define slim_i18n_splafter_delim_chars_or_ctype(ss, chset, chars, len, chset2, proc) slim_i18n_splxxx_delim_or_span_chars_or_ctype((ss), (chset), (chars), (len), (chset2),(proc),slim_nil, SLIM_I18NSPL_FLAG_AFTER|SLIM_I18NSPL_FLAG_DELIM)
#define slim_i18n_splbefore_delim_chars_or_ctype(ss, chset, chars, len, chset2, proc) slim_i18n_splxxx_delim_or_span_chars_or_ctype((ss), (chset), (chars), (len), (chset2),(proc),slim_nil, SLIM_I18NSPL_FLAG_BEFORE|SLIM_I18NSPL_FLAG_DELIM)
#define slim_i18n_splboth_span_chars_or_ctype(ss, chset, chars, len, chset2, proc) slim_i18n_splxxx_delim_or_span_chars_or_ctype((ss), (chset), (chars), (len), (chset2),(proc),slim_nil, SLIM_I18NSPL_FLAG_BOTH)
#define slim_i18n_splafter_span_chars_or_ctype(ss, chset, chars, len, chset2, proc) slim_i18n_splxxx_delim_or_span_chars_or_ctype((ss), (chset), (chars), (len), (chset2),(proc),slim_nil, SLIM_I18NSPL_FLAG_AFTER)
#define slim_i18n_splbefore_span_chars_or_ctype(ss, chset, chars, len, chset2, proc) slim_i18n_splxxx_delim_or_span_chars_or_ctype((ss), (chset), (chars), (len), (chset2),(proc),slim_nil, SLIM_I18NSPL_FLAG_BEFORE)


#define slim_i18n_splboth_delim_ctype(ss, chset, proc) slim_i18n_splxxx_delim_or_span_ctype((ss), (chset), (proc), slim_nil, SLIM_I18NSPL_FLAG_BOTH|SLIM_I18NSPL_FLAG_DELIM)
#define slim_i18n_splafter_delim_ctype(ss, chset, proc) slim_i18n_splxxx_delim_or_span_ctype((ss), (chset), (proc), slim_nil, SLIM_I18NSPL_FLAG_AFTER|SLIM_I18NSPL_FLAG_DELIM)
#define slim_i18n_splbefore_delim_ctype(ss, chset, proc) slim_i18n_splxxx_delim_or_span_ctype((ss), (chset), (proc), slim_nil, SLIM_I18NSPL_FLAG_BEFORE|SLIM_I18NSPL_FLAG_DELIM)
#define slim_i18n_splboth_span_ctype(ss, chset, proc) slim_i18n_splxxx_delim_or_span_ctype((ss), (chset), (proc), slim_nil, SLIM_I18NSPL_FLAG_BOTH)
#define slim_i18n_splafter_span_ctype(ss, chset, proc) slim_i18n_splxxx_delim_or_span_ctype((ss), (chset), (proc), slim_nil, SLIM_I18NSPL_FLAG_AFTER)
#define slim_i18n_splbefore_span_ctype(ss, chset, proc) slim_i18n_splxxx_delim_or_span_ctype((ss), (chset), (proc), slim_nil, SLIM_I18NSPL_FLAG_BEFORE)

SLIM_END_C_LINKAGE
#endif



