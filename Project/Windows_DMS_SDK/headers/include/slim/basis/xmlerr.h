/*
	xmlerr.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/basis/xmlerr.h 13    06/06/30 4:11 Someya $ */

#ifndef SLIM_XMLERR_H
#define SLIM_XMLERR_H

/* error type */
enum {
	SLIM_XMLERR_TYPE_GRAMMAR,
	SLIM_XMLERR_TYPE_WELLFORMEDNESS,
	SLIM_XMLERR_TYPE_VALIDITY,
	SLIM_XMLERR_TYPES
};

/* error number */
enum {
	/* Grammer Vaiolation */
	SLIM_XMLERR_GV_NONE = 0,
	SLIM_XMLERR_GV_Document = 1,
	SLIM_XMLERR_GV_Comment = 15,
	SLIM_XMLERR_GV_PI = 16,
	SLIM_XMLERR_GV_CDSect = 18,
	SLIM_XMLERR_GV_CDStart = 19,
	SLIM_XMLERR_GV_CDEnd = 21,
	SLIM_XMLERR_GV_prolog = 22,
	SLIM_XMLERR_GV_XMLDecl = 23,
	SLIM_XMLERR_GV_doctypedecl = 28,
	SLIM_XMLERR_GV_Element = 39,
	SLIM_XMLERR_GV_STag = 40,
	SLIM_XMLERR_GV_Attribute = 41,
	SLIM_XMLERR_GV_ETag = 42,
	SLIM_XMLERR_GV_content = 43,
	SLIM_XMLERR_GV_CharRef = 66,
	SLIM_XMLERR_GV_Reference = 67,
	SLIM_XMLERR_GV_EntityRef = 68,
	SLIM_XMLERR_GV_ExternalID = 75,
	SLIM_XMLERR_GVs
};

#endif
