/*
	slim_regexp.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/basis/regexp.h 29    05/12/28 12:08 Someya $ */

#ifndef SLIM_REGEXP_H_PRIVATE
#define SLIM_REGEXP_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

/*
	Disjunction =  Alternative | Disjunction
	Alternative =  Empty
	Alternative =  Term | Alternative
	Term =	Atom [?+*] [?]
		 =	^
		 =	$
		 =	\b
		 =	\B
	Atom =	( Disjunction )
		 =	(?: Disjunction )
		 =	(?= Disjunction )
		 =	(?! Disjunction )
		 =	PatternCharacter
		 =	.
		 =	\ 0
		 =	\ Number
		 =	\ [fnrtv]
		 =	\ c [a-zA-Z]
		 =	\ x hex hex
		 =	\ u hex hex hex hex
		 =	\ [dDsSwW]
		 =	\ OtherCharater
		 =	\[ [^] []] (ClassAtom - ClassAtom)* \]
	ClassAtom
		 =	\b
		 =	\ c [a-zA-Z]
		 =	\ x hex hex
		 =	\ u hex hex hex hex
		 =	\ [dDsSwW]
		 =	Character

	PatternCharacter = SourceCharacter but not any of
		^ $ \ . * + ? ( ) [ ] { } |

	ControlEscape = [fnrtv]
	ControlLetter = [a-zA-Z]
	CharacterClassEscape = [dDsSwW]
		
*/

/* TRegExpTree */


#define SLIM_REGEXP_FLAG_NORMAL		0x0000
#define SLIM_REGEXP_FLAG_MULTILINE	0x0001
#define SLIM_REGEXP_FLAG_ICASE		0x0002
#define SLIM_REGEXP_FLAG_GLOBAL		0x0004
#define SLIM_REGEXP_FLAG_WILDSPACE	0x0008
#define SLIM_REGEXP_FLAG_DEBUG		0x8000

/*
	RegExp_NewSS
	in_last_char:
	  If you want to stop parsing at a specific char, set in_last_char be its char. 
	If in_last_char is found in the given string in_s, parsing is aborted and
	out_s is setted to a pointer to chars following it. 
	  For example, if in_last_char equals SLIM_C('/') and in_s equals SLIM_T('abc/gmi'), 
	out_s is setted to a pointer to SLIM_T('gmi'). 
	If you want to parse the whole string, set in_last_char be -1. 

	in_last_char may not be one of
		, ? ^ ] - ) | 0-9
*/

#define RegExp_IndexToChars(s, ix, charset) (CharSet_StringChars(s, ix, charset))

#define TRegExp_NumOfParen(classe, self) (TRegExpRoot_ParenCount((classe), (slim_pix)(self)))
#define TRegExp_Flag(classe, self) (TRegExpRoot_Flag((classe), (slim_pix)(self)))
#define TRegExp_SetFlag(classe, self, flag) (TRegExpRoot_SetFlag((classe), (slim_pix)(self), (flag)))


SLIM_END_C_LINKAGE

#endif /* SLIM_REGEXP_H */
