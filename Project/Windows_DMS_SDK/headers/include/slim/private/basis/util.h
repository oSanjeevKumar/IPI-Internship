/*
	util.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/basis/util.h 23    05/12/28 12:08 Someya $ */

#ifndef SLIM_SLIM_UTIL_H_PRIVATE
#define SLIM_SLIM_UTIL_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

/*
 * ExpandingBuf
 */
enum {
	SLIM_EXPBUF_PTRTYPE_MEMORY,
	SLIM_EXPBUF_PTRTYPE_VHANDLE
};

#define TExpandingBuf_Ensure(self,len) TElasticBuf_Ensure(&(self)->fElasticBuf,(len))
#define TExpandingBuf_Lock(self) TElasticBuf_Lock(&(self)->fElasticBuf)
#define TExpandingBuf_Unlock(self) TElasticBuf_Unlock(&(self)->fElasticBuf)
#define TExpandingBuf_PtrType(self) ((self)->fType)

/*
 * VarLenBitFlag
 */
enum {
	SLIM_VARLENBITFLAG_CHECK,
	SLIM_VARLENBITFLAG_SET,
	SLIM_VARLENBITFLAG_CLEAR
};
#define TVarLenBitFlag_Set(self, id) TVarLenBitFlag_SetClearCheck((self), (id), SLIM_VARLENBITFLAG_SET)
#define TVarLenBitFlag_Clear(self, id) TVarLenBitFlag_SetClearCheck((self), (id), SLIM_VARLENBITFLAG_CLEAR)
#define TVarLenBitFlag_Check(self, id) TVarLenBitFlag_SetClearCheck((self), (id), SLIM_VARLENBITFLAG_CHECK)


/*
 * SerializeOutput (Interface)
 */

#define TSerializeOutput_SetVersionInfo(self, ver) ((*(self)->fSetVersionInfo)((self),(ver)))
#define TSerializeOutput_StartUnit(self) ((*(self)->fStartEndCancelUnit)((self), SLIM_SRLZOUTPUT_MODE_START))
#define TSerializeOutput_EndUnit(self) ((*(self)->fStartEndCancelUnit)((self), SLIM_SRLZOUTPUT_MODE_END))
#define TSerializeOutput_CancelUnit(self) ((*(self)->fStartEndCancelUnit)((self), SLIM_SRLZOUTPUT_MODE_CANCEL))
#define TSerializeOutput_StartWrite(self) ((*(self)->fStartEndCancelWrite)((self), SLIM_SRLZOUTPUT_MODE_START))
#define TSerializeOutput_EndWrite(self) ((*(self)->fStartEndCancelWrite)((self), SLIM_SRLZOUTPUT_MODE_END))
#define TSerializeOutput_CancelWrite(self) ((*(self)->fStartEndCancelWrite)((self), SLIM_SRLZOUTPUT_MODE_CANCEL))
#define TSerializeOutput_WriteStream(self,buf,len,eof,olen) ((*(self)->fWriteStream)((self),(buf),(len),(eof),(olen)))
#define TSerializeOutput_WriteEOF(self) ((*(self)->fWriteEOF)((self)))
#define TSerializeOutput_Progress(self) ((*(self)->fProgress)((self)))

/*
 * Serializable (Interface)
 */

#define TSerializable_VersionInfo(self,ver) ((*(self)->fVersionInfo)((self),(ver)))
#define TSerializable_NextUnit(self,unit) ((*(self)->fNextUnit)((self),(unit)))
#define TSerializable_CancelUnit(self,unit) ((*(self)->fCancelUnit)((self),(unit)))
#define TSerializable_Serialize(self,itr,output) ((*(self)->fSerialize)((self),(itr),(output)))

/*
 * DeserializeInput (Interface)
 */
#define TDeserializeInput_VersionInfo(self,info) ((*(self)->fVersionInfo)((self),(info)))
#define TDeserializeInput_NextUnit(self) ((*(self)->fNextUnit)((self)))
#define TDeserializeInput_StartRead(self) ((*(self)->fStartEndCancelRead)((self),SLIM_DSRLZINPUT_MODE_START))
#define TDeserializeInput_EndRead(self) ((*(self)->fStartEndCancelRead)((self),SLIM_DSRLZINPUT_MODE_END))
#define TDeserializeInput_CancelRead(self) ((*(self)->fStartEndCancelRead)((self),SLIM_DSRLZINPUT_MODE_CANCEL))
#define TDeserializeInput_ReadStream(self,buf,len,olen) ((*(self)->fReadStream)((self),(buf),(len),(olen)))
#define TDeserializeInput_Progress(self) ((*(self)->fProgress)((self)))

/*
 * Deerializable (Interface)
 */
#define TDeserializable_NewUnit(self,unit) ((*(self)->fNewUnit)((self),(unit)))
#define TDeserializable_Deserialize(self,unit,input) ((*(self)->fDeserialize)((self),(unit),(input)))
#define TDeserializable_End(self,unit) ((self)->fEndCancel ? (*(self)->fEndCancel)((self),(unit),SLIM_DSRLZINPUT_MODE_END) : (void)0)
#define TDeserializable_Cancel(self,unit) ((self)->fEndCancel ? (*(self)->fEndCancel)((self),(unit),SLIM_DSRLZINPUT_MODE_CANCEL) : (void)0)

SLIM_END_C_LINKAGE
#endif
