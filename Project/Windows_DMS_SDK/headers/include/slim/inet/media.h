/*
	media.h
	Copyright(c) 2005-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD. whether the whole
	or part of the source code including any modifications.
*/

#ifndef SLIM_MEDIA_SCHEME_H
#define SLIM_MEDIA_SCHEME_H

SLIM_BEGIN_C_LINKAGE

#define SLIM_MEDIASCHEMEINFO_CALLSIGN_MAXLENGTH		(64)
#define SLIM_MEDIASCHEMEINFO_MEDIATYPE_MAXLENGTH	(64)
#define SLIM_MEDIASCHEMEINFO_COUNTRYCODE_MAXLENGTH	(4)
#define SLIM_MEDIAOPTIONINFO_NAME_MAXLENGTH			(64)
#define SLIM_MEDIAOPTIONINFO_VALUECS_MAXLENGTH		(362)

#define	SLIM_MEDIAOPTION_TYPE_UNKNOWN				(0)
#define	SLIM_MEDIAOPTION_TYPE_INTEGER				(1)
/* ADD 2005/05/17 begin */
#define	SLIM_MEDIAOPTION_TYPE_STRING				(2)
#define	SLIM_MEDIAOPTION_TYPE_DATE					(3)
/* ADD 2005/05/17 end */

typedef struct TMediaSchemeInfo_ {
    slim_char fCallSign[SLIM_MEDIASCHEMEINFO_CALLSIGN_MAXLENGTH];
    slim_char fMediaType[SLIM_MEDIASCHEMEINFO_MEDIATYPE_MAXLENGTH];
    slim_char fCountryCode[SLIM_MEDIASCHEMEINFO_COUNTRYCODE_MAXLENGTH];
    TFixedString fOptions;
    slim_int fCurrentOptionOff;
} TMediaSchemeInfo;

typedef struct TMediaOptionInfo_ {
    slim_char fName[SLIM_MEDIAOPTIONINFO_NAME_MAXLENGTH];
    slim_char fValueCS[SLIM_MEDIAOPTIONINFO_VALUECS_MAXLENGTH];
    slim_int fValueType; /* SLIM_DTV_MEDIAOPTION_TYPE_{INTEGER, UNKNOWN} */
    union {
        slim_int uInteger;
    } fValue;
} TMediaOptionInfo;

typedef struct {
	slim_char	*fOptionName;
	slim_int	fType;
	slim_int	fDescription;
} TMediaOptions;

SLIM_END_C_LINKAGE

#endif	/* SLIM_MEDIA_SCHEME_H */
