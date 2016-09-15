/*
	reader.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/basis/reader.h 43    05/12/28 12:08 Someya $ */

#ifndef SLIM_READER_H_PRIVATE
#define SLIM_READER_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

/*
 * ReaderInput
 */
#define TReaderInput_Buffer(self) ((self)->fBuffer ? (self)->fBuffer : &(self)->fDefaultBuf)
#define TReaderInput_String(self) (TIOBuffer_Head(TReaderInput_Buffer((self))))
#define TReaderInput_Length(self) (TIOBuffer_Length(TReaderInput_Buffer((self))))
#define TReaderInput_Offset(self) (TIOBuffer_ReadOffset(TReaderInput_Buffer((self))))
#define TReaderInput_Ptr(self) (TIOBuffer_ReadPtr(TReaderInput_Buffer((self))))
#define TReaderInput_Remain(self) (TIOBuffer_ReadRemain(TReaderInput_Buffer((self))))
#define TReaderInput_SetPrecedingLength(self, len) ((self)->fPrecedingLength = (len))
#define TReaderInput_PrecedingLength(self) ((self)->fPrecedingLength)
#define TReaderInput_SetEOF(self) ((self)->fHasEOF = slim_true)
#define TReaderInput_HasEOF(self) ((self)->fHasEOF)
#define TReaderInput_EOF(self) (TReaderInput_HasEOF((self)) && TReaderInput_Remain((self)) == 0)
#define TReaderInput_SetEncoding(self, enc) ((self)->fEncoding = (enc))
#define TReaderInput_Encoding(self) ((self)->fEncoding)

#define TReaderInput_OffsetOf(self, s) (TIOBuffer_OffsetOf(TReaderInput_Buffer((self)),(s)) + (self)->fPrecedingLength)
#define TReaderInput_SetSS(self, ss) ((ss)->s = TReaderInput_Ptr((self)), (ss)->len = TReaderInput_Remain((self)))
#define TReaderInput_Copy(self, src) (*(self) = *(src))
#define TReaderInput_Seek(self,off,whc) (TIOBuffer_ReadSeek(TReaderInput_Buffer((self)),(off),(whc)))

/*
 * TxxToken
 */

#define TxxToken_ReadLen(self, input) ((self)->fWhole.len + ((self)->fWhole.s - TReaderInput_Ptr((input))))
#define TxxToken_SetCharSet(self, cs) ((self)->fCharSet = (cs))

/*
 * TTokenizer
 */


/*
 * TTokenHandler
 */


/*
 * TReader
 */

/*
 * WriterBuffer
 */
#define TWriterBuffer_Ensure(self,len) (TElasticBuf_Ensure(&(self)->fElasticBuf,TRingBuffer_WriteOffset(&(self)->fRingBuf) + (len)))
#define TWriterBuffer_Lock(self) (TElasticBuf_LockWithBuffer(&(self)->fElasticBuf,&(self)->fRingBuf.fBase))
#define TWriterBuffer_Unlock(self) (TElasticBuf_Unlock(&(self)->fElasticBuf))
#define TWriterBuffer_Remain(self) (TRingBuffer_WriteRemain(&(self)->fRingBuf))
#define TWriterBuffer_Ptr(self) (TRingBuffer_WritePtr(&(self)->fRingBuf))
#define TWriterBuffer_Offset(self) (TRingBuffer_WriteOffset(&(self)->fRingBuf))
#define TWriterBuffer_Seek(self,off,whc) (TRingBuffer_WriteSeek(&(self)->fRingBuf,(off),(whc)))
#define TWriterBuffer_SetEOF(self) ((self)->fHasEOF = slim_true)
#define TWriterBuffer_HasEOF(self) ((self)->fHasEOF)
#define TWriterBuffer_SetEncoding(self,enc) ((self)->fEncoding = (enc))
#define TWriterBuffer_Encoding(self) ((self)->fEncoding)
#define TWriterBuffer_SetThresholdToFlush(self,t) ((self)->fThresholdToFlush = (t), TElasticBuf_SetBlockSize(&(self)->fElasticBuf,(t)/2))
#define TWriterBuffer_ThresholdToFlush(self) ((self)->fThresholdToFlush)

/*
 * WriterOutput
 */
#define TWriterOutput_Write(self,buf,len,wlen) ((*(self)->fWrite)((self)->fUserData,(buf),(len),(wlen)))

/*
 * TokenGenerator
 */
#define TTokenGenerator_Generate(self) ((*(self)->fGenerate)((self)))
#define TTokenGenerator_LockToken(self) ((*(self)->fLockUnlockToken)((self),slim_true))
#define TTokenGenerator_UnlockToken(self) ((*(self)->fLockUnlockToken)((self),slim_false))

/*
 * TokenFormatter
 */
#define TTokenFormatter_Format(self,tk,out) ((*(self)->fClass->fFormat)((self),(tk),(out)))

/*
 * Writer
 */
#define TWriter_SetThresholdToFlush(self,t) (TWriterBuffer_SetThresholdToFlush(&(self)->fBuffer,(t)))

/*
 * TParallelTokenizer
 */
enum {
	SLIM_OFFLEN_LEFT,
	SLIM_OFFLEN_LEFT_OVERLAP,
	SLIM_OFFLEN_INCLUDES,
	SLIM_OFFLEN_EQUAL,
	SLIM_OFFLEN_INCLUDED,
	SLIM_OFFLEN_RIGHT_OVERLAP,
	SLIM_OFFLEN_RIGHT
};

#define TParallelTokenizer_Class(self) ((TParallelTokenizerClass *)(self)->fBase.fClass)
#define TParallelTokenizer_DefaultTokenID(self) (((TParallelTokenizerClass *)((TTokenizer *)(self))->fClass)->fDefaultTokenID)
#define TParallelTokenizer_SetMaxStayTime(self, each, whole) ((self)->fMaxStayEach = SLIM_MAX(0, (each)), (self)->fMaxStayWhole = SLIM_MAX(0, (whole)))

#define TParallelTokenizer_MaxDeterminedTokens(self) (TParallelTokenizer_Class(self)->fMaxDeterminedTokens)
#define TParallelTokenizer_LimitLenIncrement(self) (TParallelTokenizer_Class(self)->fLimitLenIncrement)


#define ParallelTokenizer_SetMaxDeterminedTokens(cls,num) ((cls)->fMaxDeterminedTokens = (num))
#define ParallelTokenizer_SetLimitLenIncrement(cls,num) ((cls)->fLimitLenIncrement = (num))

SLIM_END_C_LINKAGE
#endif







