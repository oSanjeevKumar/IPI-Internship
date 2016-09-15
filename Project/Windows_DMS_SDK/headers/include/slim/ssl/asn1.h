/*
	asn1.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/ssl/asn1.h 33    06/06/23 14:17 Siu $ */

#ifndef SLIM_ASN1_H
#define SLIM_ASN1_H

SLIM_BEGIN_C_LINKAGE

typedef struct TASN1Schema_ TASN1Schema;
typedef struct TASN1Object_ TASN1Object;
typedef struct TASN1StackFrame_ TASN1StackFrame;

/*-----------
	Config
 -----------*/

#ifdef SLIM_CONFIG_DEBUG
/* #define SLIM_CONFIG_ASN1_DEBUG */
#endif /* SLIM_CONFIG_DEBUG */


/*-------------
	Bit Flag
 -------------*/

#define SLIM_ASN1_BF_NONE					0x00000000
#define SLIM_ASN1_BF(i)						(1 << (i))
#define SLIM_ASN1_BF_CLEAR(flag, val)		{ (flag) = (val); }
#define SLIM_ASN1_BF_CHECK(flag, val)		( ((flag) & (val)) != 0 )
#define SLIM_ASN1_BF_SET(flag, val, set)	{ (flag) = ( (set) ? ((flag) | (val)) : ((flag) & ~(val)) ); }


/*-------------------
	Encoding Rules
 -------------------*/

enum {
	SLIM_ASN1_ENCODING_TYPE_NONE = -1,
	SLIM_ASN1_ENCODING_TYPE_BER = 0,
	SLIM_ASN1_ENCODING_TYPE_CER,
	SLIM_ASN1_ENCODING_TYPE_DER,
	SLIM_ASN1_ENCODING_TYPE_WER,
	SLIM_ASN1_ENCODING_TYPE_PER,
	SLIM_ASN1_ENCODING_TYPES
};


/*----------------------
	Objec/Syntax Type
 ----------------------*/

enum {
	SLIM_ASN1_TYPE_END = -1,
	SLIM_ASN1_TYPE_UNKNOWN = 0,
	SLIM_ASN1_TYPE_PRIMITIVE,
	SLIM_ASN1_TYPE_STRUCTURE,
	SLIM_ASN1_TYPE_ARRAY,
	SLIM_ASN1_TYPE_CHOICE,
	SLIM_ASN1_TYPE_IMPLICIT,
	SLIM_ASN1_TYPE_EXPLICIT,
	SLIM_ASN1_TYPE_ALIAS,
	SLIM_ASN1_TYPE_ANY,
	SLIM_ASN1_TYPE_ELEMENT,
	SLIM_ASN1_TYPES
};


/*---------------
	Error Code
 ---------------*/

#define SLIM_ASN1_E_NOT_IMPLEMENTED		(-101)
#define SLIM_ASN1_E_LENGTH				(-103)
#define SLIM_ASN1_E_UNKNOWN_OID			(-105)
#define SLIM_ASN1_E_TAG_UNMATCH			(-106)
#define SLIM_ASN1_E_TAG_FORMAT			(-107)
#define SLIM_ASN1_E_LEN_FORMAT			(-109)
#define SLIM_ASN1_E_TOO_MANY_ELEMENTS	(-110)
#define SLIM_ASN1_E_NO_EOC				(-111)
#define SLIM_ASN1_E_NO_OBJECTS			(-112)


/*---------
	Flag
 ---------*/

#define SLIM_ASN1_FLAG_NONE				SLIM_ASN1_BF_NONE
#define SLIM_ASN1_FLAG_OPTIONAL			SLIM_ASN1_BF(0)
#define SLIM_ASN1_FLAG_DEFAULT			SLIM_ASN1_BF(1)
#define SLIM_ASN1_FLAG_BREAK			SLIM_ASN1_BF(2)
#define SLIM_ASN1_FLAG_END_OF_OBJECT	SLIM_ASN1_BF(25)
#define SLIM_ASN1_FLAG_CHOICE			SLIM_ASN1_BF(26)
#define SLIM_ASN1_FLAG_SKIP_TAG_CHECK	SLIM_ASN1_BF(27)
#define SLIM_ASN1_FLAG_SELECTED			SLIM_ASN1_BF(28)
#define SLIM_ASN1_FLAG_UNSUPPORTED		SLIM_ASN1_BF(29)
#define SLIM_ASN1_FLAG_INDEFINITE		SLIM_ASN1_BF(30)
#define SLIM_ASN1_FLAG_EMPTY			SLIM_ASN1_BF(31)


/*--------------
	ASN.1 Tag
 --------------*/

struct TASN1Tag_ {
	slim_word fPackedData;
	/* TID[0 - 27], N/A[28], P/S[29], CID[30 - 31] */
};
typedef struct TASN1Tag_ TASN1Tag;

/* tag id */
#define SLIM_ASN1TAG_TID_MASK			0x0fffffff

/* primitive or strucutre */
#define SLIM_ASN1TAG_PRIMITIVE			0x00000000
#define SLIM_ASN1TAG_CONSTRUCTED		0x20000000

/* class id */
#define SLIM_ASN1TAG_CID_UNIV			0x00000000
#define SLIM_ASN1TAG_CID_APP			0x40000000
#define SLIM_ASN1TAG_CID_CTXSP			0x80000000
#define SLIM_ASN1TAG_CID_PRIV			0xc0000000
#define SLIM_ASN1TAG_CID_MASK			0xc0000000

#define SLIM_ASN1TAG(cid, tid)			( (cid) | (tid) )
#define SLIM_ASN1TAG_UNIV(tid)			SLIM_ASN1TAG(SLIM_ASN1TAG_CID_UNIV, tid)
#define SLIM_ASN1TAG_APP(tid)			SLIM_ASN1TAG(SLIM_ASN1TAG_CID_APP, tid)
#define SLIM_ASN1TAG_CTXSP(tid)			SLIM_ASN1TAG(SLIM_ASN1TAG_CID_CTXSP, tid)
#define SLIM_ASN1TAG_PRIVATE(tid)		SLIM_ASN1TAG(SLIM_ASN1TAG_CID_PRIVATE, tid)

#define SLIM_ASN1TAG_EOC				SLIM_ASN1TAG_UNIV(0)
#define SLIM_ASN1TAG_BOOLEAN			SLIM_ASN1TAG_UNIV(1)
#define SLIM_ASN1TAG_INTEGER			SLIM_ASN1TAG_UNIV(2)
#define SLIM_ASN1TAG_BIT_STRING			SLIM_ASN1TAG_UNIV(3)
#define SLIM_ASN1TAG_OCTET_STRING		SLIM_ASN1TAG_UNIV(4)
#define SLIM_ASN1TAG_NULL				SLIM_ASN1TAG_UNIV(5)
#define SLIM_ASN1TAG_OBJECT_IDENTIFIER	SLIM_ASN1TAG_UNIV(6)
#define SLIM_ASN1TAG_OBJECT_DESCRIPTOR	SLIM_ASN1TAG_UNIV(7)
#define SLIM_ASN1TAG_EXTERNAL			SLIM_ASN1TAG_UNIV(8)
#define SLIM_ASN1TAG_REAL				SLIM_ASN1TAG_UNIV(9)
#define SLIM_ASN1TAG_ENUM				SLIM_ASN1TAG_UNIV(10)
/* 11 */
#define SLIM_ASN1TAG_UTF8_STRING		SLIM_ASN1TAG_UNIV(12)
/* 13 */
/* 14 */
/* 15 */
#define SLIM_ASN1TAG_SEQUENCE			SLIM_ASN1TAG_UNIV(16)
#define SLIM_ASN1TAG_SET				SLIM_ASN1TAG_UNIV(17)
#define SLIM_ASN1TAG_NUMERIC_STRING		SLIM_ASN1TAG_UNIV(18)
#define SLIM_ASN1TAG_PRINTABLE_STRING	SLIM_ASN1TAG_UNIV(19)
#define SLIM_ASN1TAG_T61_STRING			SLIM_ASN1TAG_UNIV(20)
#define SLIM_ASN1TAG_VIDEO_STRING		SLIM_ASN1TAG_UNIV(21)
#define SLIM_ASN1TAG_IA5_STRING			SLIM_ASN1TAG_UNIV(22)
#define SLIM_ASN1TAG_UTC_TIME			SLIM_ASN1TAG_UNIV(23)
#define SLIM_ASN1TAG_GENERALIZED_TIME	SLIM_ASN1TAG_UNIV(24)
#define SLIM_ASN1TAG_GRAPHIC_STRING		SLIM_ASN1TAG_UNIV(25)
#define SLIM_ASN1TAG_VISIBLE_STRING		SLIM_ASN1TAG_UNIV(26)
#define SLIM_ASN1TAG_GENERAL_STRING		SLIM_ASN1TAG_UNIV(27)
#define SLIM_ASN1TAG_UNIVERSAL_STRING	SLIM_ASN1TAG_UNIV(28)
/* 29 */
#define SLIM_ASN1TAG_BMP_STRING			SLIM_ASN1TAG_UNIV(30)

/* method */
#define TASN1Tag_CID(self)					((self)->fPackedData & SLIM_ASN1TAG_CID_MASK)
#define TASN1Tag_TID(self)					((self)->fPackedData & SLIM_ASN1TAG_TID_MASK)
#define TASN1Tag_SetCID(self, cid)			{ (self)->fPackedData = ( (cid) | ((self)->fPackedData & ~SLIM_ASN1TAG_CID_MASK) ); }
#define TASN1Tag_SetTID(self, tid)			{ (self)->fPackedData = ( (tid) | ((self)->fPackedData & ~SLIM_ASN1TAG_TID_MASK) ); }
#define TASN1Tag_IsConstructed(self)		SLIM_ASN1_BF_CHECK((self)->fPackedData, SLIM_ASN1TAG_CONSTRUCTED)
#define TASN1Tag_SetConstructed(self, set)	SLIM_ASN1_BF_SET((self)->fPackedData, SLIM_ASN1TAG_CONSTRUCTED, set)


/*-----------------
	ASN.1 Schema
 -----------------*/

struct TASN1Schema_ {
	slim_int fType;
	slim_int fData0, fData1, fData2;

#ifdef SLIM_CONFIG_ASN1_DEBUG
	slim_int fDebugNameOfs;
#endif /* SLIM_CONFIG_ASN1_DEBUG */
};

#define TASN1Schema_Type(self)			((self)->fType)
#define TASN1Schema_IsPrimitive(self)	(TASN1Schema_Type(self) == SLIM_ASN1_TYPE_PRIMITIVE)
#define TASN1Schema_IsStructure(self)	(TASN1Schema_Type(self) == SLIM_ASN1_TYPE_STRUCTURE)
#define TASN1Schema_IsArray(self)		(TASN1Schema_Type(self) == SLIM_ASN1_TYPE_ARRAY)
#define TASN1Schema_IsChoice(self)		(TASN1Schema_Type(self) == SLIM_ASN1_TYPE_CHOICE)
#define TASN1Schema_IsImplicit(self)	(TASN1Schema_Type(self) == SLIM_ASN1_TYPE_IMPLICIT)
#define TASN1Schema_IsExplicit(self)	(TASN1Schema_Type(self) == SLIM_ASN1_TYPE_EXPLICIT)
#define TASN1Schema_IsAlias(self)		(TASN1Schema_Type(self) == SLIM_ASN1_TYPE_ALIAS)
#define TASN1Schema_IsAny(self)			(TASN1Schema_Type(self) == SLIM_ASN1_TYPE_ANY)
#define TASN1Schema_IsUnknown(self)		(TASN1Schema_Type(self) == SLIM_ASN1_TYPE_UNKNOWN)
#define TASN1Schema_IsElement(self)		(TASN1Schema_Type(self) == SLIM_ASN1_TYPE_ELEMENT)

#ifdef SLIM_CONFIG_ASN1_DEBUG
#define TASN1Schema_DebugName(self)		(ASN1_DebugName((self)->fDebugNameOfs))
#else
#define TASN1Schema_DebugName(self)		(slim_nil)
#endif

/* primitive, structure, array, implicit, explicit */
#define TASN1Schema_Tag(self)					((self)->fData0)
#define TASN1Schema_TID(self)					((self)->fData0 & SLIM_ASN1TAG_TID_MASK)
#define TASN1Schema_CID(self)					((self)->fData0 & SLIM_ASN1TAG_CID_MASK)
#define TASN1Schema_IsBoolean(self)				(TASN1Schema_IsPrimitive(self) && TASN1Schema_Tag(self) == SLIM_ASN1TAG_BOOLEAN)
#define TASN1Schema_IsInteger(self)				(TASN1Schema_IsPrimitive(self) && TASN1Schema_Tag(self) == SLIM_ASN1TAG_INTEGER)
#define TASN1Schema_IsBitString(self)			(TASN1Schema_IsPrimitive(self) && TASN1Schema_Tag(self) == SLIM_ASN1TAG_BIT_STRING)
#define TASN1Schema_IsObjectIdentifier(self)	(TASN1Schema_IsPrimitive(self) && TASN1Schema_Tag(self) == SLIM_ASN1TAG_OBJECT_IDENTIFIER)
#define TASN1Schema_IsUTCTime(self)				(TASN1Schema_IsPrimitive(self) && TASN1Schema_Tag(self) == SLIM_ASN1TAG_UTC_TIME)
#define TASN1Schema_IsGeneralizedTime(self)		(TASN1Schema_IsPrimitive(self) && TASN1Schema_Tag(self) == SLIM_ASN1TAG_GENERALIZED_TIME)
#define TASN1Schema_IsSequence(self)			(TASN1Schema_IsStructure(self) && TASN1Schema_Tag(self) == SLIM_ASN1TAG_SEQUENCE)
#define TASN1Schema_IsSet(self)					(TASN1Schema_IsStructure(self) && TASN1Schema_Tag(self) == SLIM_ASN1TAG_SET)
#define TASN1Schema_IsSequenceOf(self)			(TASN1Schema_IsArray(self) && TASN1Schema_Tag(self) == SLIM_ASN1TAG_SEQUENCE)
#define TASN1Schema_IsSetOf(self)				(TASN1Schema_IsArray(self) && TASN1Schema_Tag(self) == SLIM_ASN1TAG_SET)

/* primitive, structure, array, choice */
#define TASN1Schema_ObjectSize(self)	((self)->fData1)

/* alias, element */
#define TASN1Schema_SchemaID(self)		((self)->fData0)

/* primitive */
#define TASN1Schema_PrimitiveTag(self)		((self)->fData0)
#define TASN1Schema_PrimitiveSize(self)		((self)->fData1)

/* structure */
#define TASN1Schema_StructureTag(self)		((self)->fData0)
#define TASN1Schema_StructureSize(self)		((self)->fData1)
#define TASN1Schema_StructureElements(self)	((self)->fData2)

/* array */
#define TASN1Schema_ArrayTag(self)			((self)->fData0)

/* choice */
#define TASN1Schema_ChoiceSize(self)		((self)->fData1)
#define TASN1Schema_ChoiceElements(self)	((self)->fData2)

/* implicit */
#define TASN1Schema_ImplicitTag(self)		((self)->fData0)
#define TASN1Schema_ImplicitSchemaID(self)	((self)->fData1)

/* explicit */
#define TASN1Schema_ExplicitTag(self)		((self)->fData0)
#define TASN1Schema_ExplicitSchemaID(self)	((self)->fData1)

/* alias */
#define TASN1Schema_AliasSchemaID(self)		((self)->fData0)

/* any */
#define TASN1Schema_AnyDefinedBy(self)		((self)->fData0)

/* element */
#define TASN1Schema_ElementSchemaID(self)	((self)->fData0)
#define TASN1Schema_ElementFlag(self)		((self)->fData1)
#define TASN1Schema_ElementOffset(self)		((self)->fData2)

/* template */
#ifdef SLIM_CONFIG_ASN1_DEBUG
#define SLIM_ASN1SCHEMA(name, type, data0, data1, data2)	{type, data0, data1, data2, name}
#else
#define SLIM_ASN1SCHEMA(name, type, data0, data1, data2)	{type, data0, data1, data2}
#endif
#define SLIM_ASN1SCHEMA_END \
	SLIM_ASN1SCHEMA(-1, SLIM_ASN1_TYPE_END, 0, 0, 0)
#define SLIM_ASN1SCHEMA_UNKNOWN(name) \
	SLIM_ASN1SCHEMA(name, SLIM_ASN1_TYPE_UNKNOWN, 0, 0, 0)
#define SLIM_ASN1SCHEMA_PRIMITIVE(name, tag) \
	SLIM_ASN1SCHEMA(name, SLIM_ASN1_TYPE_PRIMITIVE, tag, sizeof(TASN1Object), 0)
#define SLIM_ASN1SCHEMA_STRUCTURE(name, tag, size, elements) \
	SLIM_ASN1SCHEMA(name, SLIM_ASN1_TYPE_STRUCTURE, tag, size, elements)
#define SLIM_ASN1SCHEMA_ARRAY(name, tag) \
	SLIM_ASN1SCHEMA(name, SLIM_ASN1_TYPE_ARRAY, tag, sizeof(TASN1Object), 0)
#define SLIM_ASN1SCHEMA_CHOICE(name, size, elements) \
	SLIM_ASN1SCHEMA(name, SLIM_ASN1_TYPE_CHOICE, 0, size, elements)
#define SLIM_ASN1SCHEMA_ALIAS(name, schema_id) \
	SLIM_ASN1SCHEMA(name, SLIM_ASN1_TYPE_ALIAS, schema_id, 0, 0)
#define SLIM_ASN1SCHEMA_ANY(defined_by) \
	SLIM_ASN1SCHEMA(-1, SLIM_ASN1_TYPE_ANY, defined_by, 0, 0)
#define SLIM_ASN1SCHEMA_IMPLICIT(tid, schema_id) \
	SLIM_ASN1SCHEMA(-1, SLIM_ASN1_TYPE_IMPLICIT, SLIM_ASN1TAG_CTXSP(tid), schema_id, 0)
#define SLIM_ASN1SCHEMA_EXPLICIT(tid, schema_id) \
	SLIM_ASN1SCHEMA(-1, SLIM_ASN1_TYPE_EXPLICIT, SLIM_ASN1TAG_CTXSP(tid), schema_id, 0)
#define SLIM_ASN1SCHEMA_STRUCTURE_ELEMENT(name, schema_id, flag, offset) \
	SLIM_ASN1SCHEMA(name, SLIM_ASN1_TYPE_ELEMENT, schema_id, flag, offset)
#define SLIM_ASN1SCHEMA_ARRAY_ELEMENT(schema_id) \
	SLIM_ASN1SCHEMA(-1, SLIM_ASN1_TYPE_ELEMENT, schema_id, 0, 0)
#define SLIM_ASN1SCHEMA_CHOICE_ELEMENT(name, schema_id, offset) \
	SLIM_ASN1SCHEMA(name, SLIM_ASN1_TYPE_ELEMENT, schema_id, 0, offset)


/*-----------------
	ASN.1 Object
 -----------------*/

struct TASN1Object_ {
	TASN1Schema *fSchema;
	slim_int fPackedData;	/* Header-Len[0-7], ExtID[8-15]flag, Flag[16-31] */
	slim_byte *fEntity;
	slim_int fContentLen;
};

#define SLIM_ASN1OBJ_FLAG_NONE					SLIM_ASN1_BF_NONE
#define SLIM_ASN1OBJ_FLAG_AVAIL					SLIM_ASN1_BF(16)
#define SLIM_ASN1OBJ_FLAG_INDEFINITE_LENGTH		SLIM_ASN1_BF(17)

#define SLIM_ASN1OBJ_PACKEDDATA_HEADER_LEN_MASK	0x000000ff
#define SLIM_ASN1OBJ_PACKEDDATA_CHOICE_MASK		0x0000ff00
#define SLIM_ASN1OBJ_PACKEDDATA_FLAG_MASK		0xffff0000

#define TASN1Object_Cast(self)					((TASN1Object *)(self))
#define TASN1Object_Schema(self)				(TASN1Object_Cast(self)->fSchema)
#define TASN1Object_PackedData(self)			(TASN1Object_Cast(self)->fPackedData)
#define TASN1Object_Flag(self)					(TASN1Object_PackedData(self) & SLIM_ASN1OBJ_PACKEDDATA_FLAG_MASK)
#define TASN1Object_ChoiceIndex(self)			((TASN1Object_PackedData(self) & SLIM_ASN1OBJ_PACKEDDATA_CHOICE_MASK) >> 8)
#define TASN1Object_HeaderLen(self)				(TASN1Object_PackedData(self) & SLIM_ASN1OBJ_PACKEDDATA_HEADER_LEN_MASK)
#define TASN1Object_Entity(self)				(TASN1Object_Cast(self)->fEntity)
#define TASN1Object_ContentLen(self)			(TASN1Object_Cast(self)->fContentLen)
#define TASN1Object_SetSchema(self, schema)		{ TASN1Object_Cast(self)->fSchema = (schema); }
#define TASN1Object_SetEntity(self, ptr)		{ TASN1Object_Cast(self)->fEntity = (ptr); }
#define TASN1Object_SetHeaderLen(self, len)		{ TASN1Object_Cast(self)->fPackedData = ((TASN1Object_PackedData(self) & ~SLIM_ASN1OBJ_PACKEDDATA_HEADER_LEN_MASK) | (len)); }
#define TASN1Object_SetChoiceIndex(self, index)	{ TASN1Object_Cast(self)->fPackedData = ((TASN1Object_PackedData(self) & ~SLIM_ASN1OBJ_PACKEDDATA_CHOICE_MASK) | (index) << 8); }
#define TASN1Object_SetContentLen(self, len)	{ TASN1Object_Cast(self)->fContentLen = (len); }

#define TASN1Object_Content(self)				(TASN1Object_Entity(self) + TASN1Object_HeaderLen(self))

#define TASN1Object_Type(self)					(TASN1Schema_Type(TASN1Object_Schema(self)))
#define TASN1Object_CID(self)					(TASN1Schema_CID(TASN1Object_Schema(self)))
#define TASN1Object_TID(self)					(TASN1Schema_TID(TASN1Object_Schema(self)))
#define TASN1Object_IsPrimitive(self)			(TASN1Schema_IsPrimitive(TASN1Object_Schema(self)))
#define TASN1Object_IsStructure(self)			(TASN1Schema_IsStructure(TASN1Object_Schema(self)))
#define TASN1Object_IsArray(self)				(TASN1Schema_IsArray(TASN1Object_Schema(self)))

#define TASN1Object_IsBoolean(self)				(TASN1Schema_IsBoolean(TASN1Object_Schema(self)))
#define TASN1Object_IsInteger(self)				(TASN1Schema_IsInteger(TASN1Object_Schema(self)))
#define TASN1Object_IsBitString(self)			(TASN1Schema_IsBitString(TASN1Object_Schema(self)))
#define TASN1Object_IsObjectIdentifier(self)	(TASN1Schema_IsObjectIdentifier(TASN1Object_Schema(self)))
#define TASN1Object_IsUTCTime(self)				(TASN1Schema_IsUTCTime(TASN1Object_Schema(self)))
#define TASN1Object_IsGeneralizedTime(self)		(TASN1Schema_IsGeneralizedTime(TASN1Object_Schema(self)))
#define TASN1Object_IsSequence(self)			(TASN1Schema_IsSequence(TASN1Object_Schema(self)))
#define TASN1Object_IsSet(self)					(TASN1Schema_IsSet(TASN1Object_Schema(self)))
#define TASN1Object_IsSequenceOf(self)			(TASN1Schema_IsSequenceOf(TASN1Object_Schema(self)))
#define TASN1Object_IsSetOf(self)				(TASN1Schema_IsSetOf(TASN1Object_Schema(self)))
#define TASN1Object_IsTime(self)				(TASN1Object_IsUTCTime(self) || TASN1Object_IsGeneralizedTime(self))

#define TASN1Object_IsAvail(self)					SLIM_ASN1_BF_CHECK(TASN1Object_PackedData(self), SLIM_ASN1OBJ_FLAG_AVAIL)
#define TASN1Object_IsIndefiniteLength(self)		SLIM_ASN1_BF_CHECK(TASN1Object_PackedData(self), SLIM_ASN1OBJ_FLAG_INDEFINITE_LENGTH)
#define TASN1Object_IsEmpty(self)					(!SLIM_ASN1_BF_CHECK(TASN1Object_PackedData(self), SLIM_ASN1OBJ_FLAG_AVAIL))

#define TASN1Object_SetAvail(self, set)				SLIM_ASN1_BF_SET(TASN1Object_PackedData(self), SLIM_ASN1OBJ_FLAG_AVAIL, set)
#define TASN1Object_SetIndefiniteLength(self, set)	SLIM_ASN1_BF_SET(TASN1Object_PackedData(self), SLIM_ASN1OBJ_FLAG_INDEFINITE_LENGTH, set)


/*----------------------
	ASN.1 Stack Frame
 ----------------------*/

struct TASN1StackFrame_ {
	TASN1StackFrame *fPrev;
	TASN1StackFrame *fParent;
	slim_int fState;
	slim_int fFlag;
	TASN1Schema *fSchema;
	TASN1Object *fObject;
	slim_int fEntityOfs;
	slim_int fHeaderLen;
	slim_int fContentLen;
	slim_int fCounter;	/* ARRAY/CHOICE */
	slim_int fElementSchemaID;

#ifdef SLIM_CONFIG_ASN1_DEBUG
	slim_char *fDebugTypeName;
	slim_char *fDebugElementName;
#endif /* SLIM_CONFIG_ASN1_DEBUG */
};

#ifdef SLIM_CONFIG_ASN1_DEBUG
#define TASN1StackFrame_DebugTypeName(self, name)		((self)->fDebugTypeName)
#define TASN1StackFrame_DebugElementName(self, name)	((self)->fDebugElementName)
#define TASN1StackFrame_SetDebugTypeName(self, name)	((void)((self)->fDebugTypeName = (name)))
#define TASN1StackFrame_SetDebugElementName(self, name)	((void)((self)->fDebugElementName = (name)))
#else
#define TASN1StackFrame_DebugTypeName(self, name)		(slim_nil)
#define TASN1StackFrame_DebugElementName(self, name)	(slim_nil)
#define TASN1StackFrame_SetDebugTypeName(self, name)	((void)0)
#define TASN1StackFrame_SetDebugElementName(self, name)	((void)0)
#endif /* SLIM_CONFIG_ASN1_DEBUG */


/*----------------
	ASN.1 Stack
 ----------------*/

struct TASN1Stack_ {
	TASN1StackFrame *fTop;
	slim_int fDepth;

#ifdef SLIM_CONFIG_ASN1_DEBUG
	slim_int fDebugPeakDepth;
#endif /* SLIM_CONFIG_ASN1_DEBUG */
};
typedef struct TASN1Stack_ TASN1Stack;


/*--------------------------
	ASN.1 OID Info Holder
 --------------------------*/

typedef struct TASN1OIDInfoHolder_ TASN1OIDInfoHolder;

struct TASN1OIDInfoHolder_ {
	TASN1OIDInfoHolder *fNext;
	slim_int fElementID;
	slim_int fOIDInfoID;
};


/*------------------
	ASN.1 Decoder
 ------------------*/

typedef slim_bool (*slim_asn1_is_invalid_proc)(TASN1Tag *in_tag, TASN1StackFrame *in_frame);

enum {
	SLIM_ASN1DEC_ST_DECODE = 0,
	SLIM_ASN1DEC_ST_CHECK,
	SLIM_ASN1DEC_STS
};

struct TASN1Decoder_ {
	slim_int fFlag;
	TASN1Stack fStack;
	TASN1OIDInfoHolder *fFirstHolder;
	slim_byte *fPtr;
	slim_int fLen;
	slim_int fOfs;

#ifdef SLIM_CONFIG_ASN1_DEBUG
	slim_int fDebugDepth;
#endif /* SLIM_CONFIG_ASN1_DEBUG */
};
typedef struct TASN1Decoder_ TASN1Decoder;

#define SLIM_ASN1DEC_FLAG_NONE		0x00000000
#define SLIM_ASN1DEC_FLAG_ITERATION	0x00000001


/*-------------------
	ASN.1 Iterator
 -------------------*/

struct TASN1Iterator_ {
	TASN1Decoder fDecoder;
	slim_int fSchemaID;
	slim_byte *fBuf;
	slim_int fLen;
};
typedef struct TASN1Iterator_ TASN1Iterator;

SLIM_END_C_LINKAGE

#endif /* SLIM_ASN1_H */
