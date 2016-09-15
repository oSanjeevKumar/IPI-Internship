/*
	util.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/basis/util.h 24    06/05/09 17:27 Someya $ */

#ifndef SLIM_SLIM_UTIL_H
#define SLIM_SLIM_UTIL_H

SLIM_BEGIN_C_LINKAGE

/*
 * VersionInfo
 */
typedef struct {
	slim_char *fModule;
	slim_int fMajor;
	slim_int fMinor;
	slim_int fPatch;	/* means ServicePack number, it's have a point in stable version only. */
	slim_char *fExtension;
} TVersionInfo;

/*
 * ExpandingBuf
 */
typedef struct TExpandingBuf_ TExpandingBuf;
struct TExpandingBuf_ {
	slim_int fType;
	union {
		void *Memory;
		slim_vhandle Vhandle;
	}u;
	TElasticBuf fElasticBuf;
};

/*
 * VarLenBitFlag
 */
typedef struct TVarLenBitFlag_ TVarLenBitFlag;
struct TVarLenBitFlag_ {
	slim_int fLength;
	slim_byte *fField; /* array of slim_byte */
};

/*
 * SerializeReadWriteVal
 */
/* !!CAUTION!!
 * The value of named constants are NOT persistent (i.e. may be changed).
 * So, serialized data MUST NOT retain those values as is.
 */

enum {
	SLIM_SRLZRWVAL_TYPE_INT = 0,
	SLIM_SRLZRWVAL_TYPE_BOOL,
	SLIM_SRLZRWVAL_TYPE_BYTES,
	SLIM_SRLZRWVAL_TYPE_SS, /* I18N sub string */
	SLIM_SRLZRWVAL_TYPEs
};

typedef union TSerializeReadWriteVal_ TSerializeReadWriteVal;
union TSerializeReadWriteVal_ {
	slim_int uInt;
	slim_bool uBool;
	struct {
		slim_byte *fData;
		slim_int fLength;
	}uBytes;
	struct {
		slim_char *fStr;
		slim_int fLength;
		slim_int fCharSet; /* DO NOT serialize this value as is */
	}uSS;
};

/*
 * TSerializeVersionInfo
 */

#define SLIM_SRLZVERINFO_MAX_MODULE_LEN 35
typedef struct TSerializeVersionInfo_ TSerializeVersionInfo;
struct TSerializeVersionInfo_ {
	TVersionInfo fBase;
	slim_char fModuleBuf[SLIM_SRLZVERINFO_MAX_MODULE_LEN + 1];
};

/*
 * SerializeOutput (Interface)
 */

enum {
	SLIM_SRLZOUTPUT_MODE_START,
	SLIM_SRLZOUTPUT_MODE_END,
	SLIM_SRLZOUTPUT_MODE_CANCEL
};

typedef struct TSerializeOutput_ TSerializeOutput;

typedef slim_bool (*SerializeOutput_SetVersionInfoProc)(TSerializeOutput *self, TVersionInfo *in_info);
typedef slim_int (*SerializeOutput_StartEndCancelUnitProc)(TSerializeOutput *self, slim_int in_which);
typedef slim_int (*SerializeOutput_StartEndCancelWriteProc)(TSerializeOutput *self, slim_int in_which);
typedef slim_int (*SerializeOutput_WriteXProc)(TSerializeOutput *self, slim_int in_type, TSerializeReadWriteVal *in_val);
typedef slim_int (*SerializeOutput_WriteStreamProc)(TSerializeOutput *self, slim_byte *in_buf, slim_int in_len, slim_bool in_eof, slim_int *out_written_len);
typedef void (*SerializeOutput_WriteEOFProc)(TSerializeOutput *self);
typedef slim_int (*SerializeOutput_ProgressProc)(TSerializeOutput *self);

struct TSerializeOutput_ {
	slim_opaque fImplement;
	SerializeOutput_SetVersionInfoProc fSetVersionInfo;
	SerializeOutput_StartEndCancelUnitProc fStartEndCancelUnit;
	SerializeOutput_StartEndCancelWriteProc fStartEndCancelWrite;
	SerializeOutput_WriteXProc fWriteX;
	SerializeOutput_WriteStreamProc fWriteStream;
	SerializeOutput_WriteEOFProc fWriteEOF;
	SerializeOutput_ProgressProc fProgress;
};


/*
 * Serializable (Interface)
 */

typedef struct TSerializable_ TSerializable;

typedef void (*Serializable_VersionInfoProc)(TSerializable *self, TSerializeVersionInfo *out_info);
typedef slim_int (*Serializable_NextUnitProc)(TSerializable *self, slim_opaque *inout_unit);
typedef void (*Serializable_CancelUnitProc)(TSerializable *self, slim_opaque in_unit);
typedef slim_int (*Serializable_SerializeProc)(TSerializable *self, slim_opaque in_unit, TSerializeOutput *in_output);

struct TSerializable_ {
	slim_opaque fImplement;
	Serializable_VersionInfoProc fVersionInfo;
	Serializable_NextUnitProc fNextUnit;
	Serializable_CancelUnitProc fCancelUnit;
	Serializable_SerializeProc fSerialize;
};

/*
 * Serializer
 */

typedef struct TSerializer_ TSerializer;
struct TSerializer_ {
	slim_int fFlag;
	TSerializable *fSerializable;
	TSerializeOutput *fOutput;
	slim_opaque fUnit;
};

/*
 * DeserializeInput (interface)
 */
enum {
	SLIM_DSRLZINPUT_MODE_START,
	SLIM_DSRLZINPUT_MODE_END,
	SLIM_DSRLZINPUT_MODE_CANCEL
};

typedef struct TDeserializeInput_ TDeserializeInput;
typedef void (*DeserializeInput_VersionInfoProc)(TDeserializeInput *self, TSerializeVersionInfo *out_info);
typedef slim_int (*DeserializeInput_NextUnitProc)(TDeserializeInput *self);
typedef slim_int (*DeserializeInput_StartEndCancelReadProc)(TDeserializeInput *self, slim_int in_which);
/* returns SLIM_E_EOF at the end of unit */
typedef slim_int (*DeserializeInput_ReadXProc)(TDeserializeInput *self, slim_int in_type, TSerializeReadWriteVal *out_val);
typedef slim_int (*DeserializeInput_ReadStreamProc)(TDeserializeInput *self, slim_byte *out_buf, slim_int in_buf_len, slim_int *out_read_len);
typedef slim_int (*DeserializeInput_ProgressProc)(TDeserializeInput *self);
struct TDeserializeInput_ {
	slim_opaque fImplement;
	DeserializeInput_VersionInfoProc fVersionInfo;
	DeserializeInput_NextUnitProc fNextUnit;
	DeserializeInput_StartEndCancelReadProc fStartEndCancelRead;
	DeserializeInput_ReadXProc fReadX;
	DeserializeInput_ReadStreamProc fReadStream;
	DeserializeInput_ProgressProc fProgress;
};

/*
 * Deserializable (interface)
 */

typedef struct TDeserializable_ TDeserializable;
typedef slim_int (*Deserializable_NewUnitProc)(TDeserializable *self, slim_opaque *inout_unit);
typedef slim_int (*Deserializable_DeserializeProc)(TDeserializable *self, slim_opaque in_unit, TDeserializeInput *in_input);
typedef void (*Deserializable_EndCancelProc)(TDeserializable *self, slim_opaque in_unit, slim_int in_which);
struct TDeserializable_ {
	slim_opaque fImplement;
	Deserializable_NewUnitProc fNewUnit;
	Deserializable_DeserializeProc fDeserialize;
	Deserializable_EndCancelProc fEndCancel;
};

/*
 * Deserializer
 */

typedef struct TDeserializer_ TDeserializer;
struct TDeserializer_ {
	slim_int fFlag;
	TDeserializable *fDeserializable;
	TDeserializeInput *fInput;
	slim_opaque fUnit;
};


/*
 * PackedData
 */
/*
  |------------------------- fTotalLen ---------------------------|
  |--  consumed len ---|
                       |----------- fCurLen (contents of fBuf) ---|
                             |--- packed data len -----|
                       |-----| fStartOff
                       |----------------| fCurOff
                       |-------------------------------| fEndOff
  * can be *

      fStartOff |------|
                |------------------- packed data len --------------------|
                       |-------------------------------------------------| fEndOff
*/

typedef struct TPackedData_ TPackedData;
struct TPackedData_ {
	TExpandingBuf fBuf;
	slim_int fTotalLen;
	slim_int fCurLen;
	slim_int fStartOff; /* may be negative */
	slim_int fCurOff;
	slim_int fEndOff; /* may be > fCurLen */
};

typedef struct TPackedDataItemHdr_ TPackedDataItemHdr;
struct TPackedDataItemHdr_ {
	slim_int fFlag;
	slim_int fLength;
	slim_word fAdler32;
};

/*
 * PackedDataWriter
 */

typedef struct TPackedDataWriter_ TPackedDataWriter;
typedef slim_int (*PackedDataWriter_WriteProc)(slim_opaque in_ctx, slim_byte *in_buf, slim_int in_len, slim_int *out_written_len);

struct TPackedDataWriter_ {
	slim_int fFlag;
	TPackedData fData;
	slim_int fWritableLen;
	slim_word fAdler32;
	slim_opaque fUserData;
	PackedDataWriter_WriteProc fProc;

	TSerializeVersionInfo fVersionInfo;

	/* for Rollback */
	slim_int fPrevOff;
	slim_word fPrevAdler32;
};

/*
 * PackedDataReader
 */

typedef struct TPackedDataReader_ TPackedDataReader;
typedef slim_int (*PackedDataReader_ReadProc)(slim_opaque in_ctx, slim_byte *in_buf, slim_int in_len, slim_int *out_read_len);

struct TPackedDataReader_ {
	slim_int fFlag;
	TPackedData fData;
	slim_int fConsumableLen;
	slim_opaque fUserData;
	PackedDataReader_ReadProc fProc;
	slim_byte *fLockedBuf;

	TSerializeVersionInfo fVersionInfo;

	slim_int fPrevOff;
};

SLIM_END_C_LINKAGE
#endif
