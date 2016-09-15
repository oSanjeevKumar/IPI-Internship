/*
	i18nrslv.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/basis/i18nrslv.h 3     05/12/28 12:08 Someya $ */

#ifndef SLIM_I18N_RESOLVE_H_PRIVATE
#define SLIM_I18N_RESOLVE_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

/* TLangSetInfo */
#define LangSetInfo_Init() ((void)0)
extern SLIM_ROM TLangSetInfo cSlim_LangSetInfo[SLIM_I18N_LANGSETS];
extern SLIM_ROM TLangSetInfo cSlim_I18N_LangSet_Anon;
#define LangSetInfo_IDToInfo(id) (((id) < 0 || SLIM_I18N_LANGSETS <= (id)) ? (TLangSetInfo *)&cSlim_I18N_LangSet_Anon : (TLangSetInfo *)&cSlim_LangSetInfo[(id)])

/* T18NCharProc */
#define I18NCharProc_Init() ((void)0)
extern SLIM_ROM TI18NCharProc cSlim_I18NCharProc[SLIM_TOKEN_CHSET_TOKENS];
extern SLIM_ROM TI18NCharProc cSlim_I18NCharProc_UNKNOWN;
#define I18NCharProc_Find(id) (((id) < 0 || SLIM_TOKEN_CHSET_TOKENS <= (id)) ? &cSlim_I18NCharProc_UNKNOWN : &cSlim_I18NCharProc[(id)])

SLIM_END_C_LINKAGE

#endif
