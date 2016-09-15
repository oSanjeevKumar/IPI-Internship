/*
	cdatafmt.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/basis/cdatafmt.h 22    05/12/28 12:08 Someya $ */

#ifndef SLIM_CDATA_FORMATTER_H_PRIVATE
#define SLIM_CDATA_FORMATTER_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

/* CDATAFormatter */
#define CDATAFormatter_AddDefaultFlag(cls,c,f) ((cls)->fDefaultFlags[(c)] |= (f))
#define CDATAFormatter_RemoveDefaultFlag(cls,c,f) ((cls)->fDefaultFlags[(c)] &= ~(f))
#define CDATAFormatter_ClearDefaultFlag(cls,c) ((cls)->fDefaultFlags[(c)] = SLIM_FLAG_NONE)
#define CDATAFormatter_DefaultFlag(cls,c) ((cls)->fDefaultFlags[(c)])

#define TCDATAFormatter_AddFlag(self,c,f) ((self)->fFlags[(c)] |= (f))
#define TCDATAFormatter_RemoveFlag(self,c,f) ((self)->fFlags[(c)] &= ~(f))
#define TCDATAFormatter_ClearFlag(self,c) ((self)->fFlags[(c)] = SLIM_FLAG_NONE)
#define TCDATAFormatter_Flag(self,c) ((self)->fFlags[(c)])

#define TCDATAFormatter_SetParseReferenceProc(self, proc) ((self)->fParseReference = (proc))
#define TCDATAFormatter_SetResolveReferenceProc(self, proc) ((self)->fResolveReference = (proc))

#define TCDATAFormatter_ConvertUnicodeByCase(self,buf,code,tc,c) TCDATAFormatter_ConvertUnicode((self),(buf),(code),(tc),TCDATAFormatter_Flag((self),(c)))
#define TCDATAFormatter_ParseReferenceByCase(self,s,len,has,oc,c) TCDATAFormatter_ParseReference((self),(s),(len),(has),(oc),TCDATAFormatter_Flag((self),(c)))
#define TCDATAFormatter_ResolveReferenceByCase(self,buf,s,len,has,tc,c) TCDATAFormatter_ResolveReference((self),(buf),(s),(len),(has),(tc),TCDATAFormatter_Flag((self),(c)))
#define TCDATAFormatter_FormatByCase(self,buf,s,len,tc,fc,c) TCDATAFormatter_Format((self),(buf),(s),(len),(tc),(fc),TCDATAFormatter_Flag((self),(c)))



SLIM_END_C_LINKAGE
#endif
