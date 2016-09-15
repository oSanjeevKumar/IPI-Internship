/*
	base.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/basis/base.h 101   06/08/23 16:22 Someya $ */

#ifndef SLIM_BASE_H_PRIVATE
#define SLIM_BASE_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

/* Ugh!: deprecated */
#define SLIM_SS(text_literal) SLIM_T(text_literal), (sizeof(text_literal)-1)

/* obsoleted */
struct slim_locked_handle_ {
	slim_handle h;
	void *p;
};
typedef struct slim_locked_handle_ slim_locked_handle;
struct slim_locked_vhandle_ {
	slim_vhandle h;
	void *p;
};
typedef struct slim_locked_vhandle_ slim_locked_vhandle;
struct slim_locked_pix_ {
	slim_pix pix;
	slim_handle h;
	void *ptr;
};
typedef struct slim_locked_pix_ slim_locked_pix;

/*              */
/* debug macros */
/*              */

#ifdef SLIM_CONFIG_DEBUG
#define SLIM_D(tokens) tokens;
#define SLIM_DP(arg) slimDebugPrintfPeer arg
#define SLIM_DPW(arg) slimDebugPrintfWPeer arg
#define SLIM_ASSERT(test) ((test) ? (void)0 : slimDebugAssertFailPeer(#test, __FILE__, __LINE__, 0, 0))
#define SLIM_ASSERT_MSG(test,msg) ((test) ? (void)0 : slimDebugAssertFailPeer(#test, __FILE__, __LINE__, 0, (msg)))
#define SLIM_ASSERT_INFO(test) ((test) ? (void)0 : slimDebugAssertFailPeer(#test, __FILE__, __LINE__, 1, 0))
#define SLIM_ASSERT_TYPE(var,type) SLIM_ASSERT_MSG(sizeof(var) == sizeof(type), "Type mismatch.")
#define SLIM_VERIFY(test) SLIM_ASSERT(test)
#else
/* Dummy */
#define SLIM_D(tokens) ((void)0);
#define SLIM_DP(arg) ((void)0)
#define SLIM_DPW(arg) ((void)0)
#define SLIM_ASSERT(test) ((void)0)
#define SLIM_ASSERT_MSG(test,msg) ((void)0)
#define SLIM_ASSERT_INFO(test) ((void)0)
#define SLIM_ASSERT_TYPE(var,type) ((void)0)
#define SLIM_VERIFY(test) (test)
#endif

#define SLIM_IF_THEN(test, then) (!(test)||(then))

#ifdef SLIM_CONFIG_DEBUG_STACK
#define SLIM_ENTER(func) slimDebugStackPeer(#func)
#else
#define SLIM_ENTER(func)
#endif

/*
 * Log
 */
#ifdef SLIM_CONFIG_DEBUG_LOG

slim_char* slimGetPollName(slim_int in_poll);
slim_char* slimGetErrorName(slim_int in_err);

#define SLIM_LOG_FUNCENTER(obj,method,id,msg) { slimLogEnterFunctionPeer(#obj,#method,(int)id); slimLogMessagePeer msg; }
#define SLIM_LOG_FUNCEXIT(msg) { slimLogExitFunctionPeer(); slimLogMessagePeer msg; }
#define SLIM_LOG_FUNC(func,obj,method,id,entermsg,exitmsg) { SLIM_LOG_FUNCENTER(obj,method,id,entermsg); func; SLIM_LOG_FUNCEXIT(exitmsg); }
#define SLIM_LOG_MSG(msg) slimLogMessagePeer msg
#define SLIM_LOG_SIGNAL(sig) slimLogSignalPeer(SLIM_LOG_SIGNAL_##sig)

#else

#define SLIM_LOG_FUNCENTER(obj,method,id,msg)
#define SLIM_LOG_FUNCEXIT(msg)
#define SLIM_LOG_FUNC(func,obj,method,id,entermsg,exitmsg)
#define SLIM_LOG_MSG(msg)
#define SLIM_LOG_SIGNAL(sig)

#endif /* end SLIM_CONFIG_DEBUG_LOG */


/*
 * IOBuffer
 */
#define TIOBuffer_Head(self) ((self)->fBuffer)
#define TIOBuffer_Tail(self) ((self)->fBuffer ? ((self)->fBuffer + (self)->fLength) : slim_nil)
#define TIOBuffer_Length(self) ((self)->fLength)
#define TIOBuffer_ReadOffset(self) ((self)->fReadOff)
#define TIOBuffer_WriteOffset(self) ((self)->fWriteOff)
#define TIOBuffer_ReadPtr(self) ((self)->fBuffer ? ((self)->fBuffer + (self)->fReadOff) : slim_nil)
#define TIOBuffer_WritePtr(self) ((self)->fBuffer ? ((self)->fBuffer + (self)->fWriteOff) : slim_nil)
#define TIOBuffer_ReadRemain(self) ((self)->fWriteOff - (self)->fReadOff)
#define TIOBuffer_WriteRemain(self) ((self)->fLength - (self)->fWriteOff)
#define TIOBuffer_OffsetOf(self, s) ((s) - (self)->fBuffer)

#define TIOBuffer_SetBuffer(self,buf,len) TIOBuffer_SetBufferX((self),(buf),(len),slim_true)
#define TIOBuffer_ExpandBuffer(self,buf,len) TIOBuffer_SetBufferX((self),(buf),(len),slim_false)

/*
 * RingBuffer
 */
#define TRingBuffer_Head(self) TIOBuffer_Head(&(self)->fBase)
#define TRingBuffer_Tail(self) TIOBuffer_Tail(&(self)->fBase)
#define TRingBuffer_Length(self) TIOBuffer_Length(&(self)->fBase)
#define TRingBuffer_ReadOffset(self) TIOBuffer_ReadOffset(&(self)->fBase)
#define TRingBuffer_WriteOffset(self) TIOBuffer_WriteOffset(&(self)->fBase)
#define TRingBuffer_ReadPtr(self) TIOBuffer_ReadPtr(&(self)->fBase)
#define TRingBuffer_WritePtr(self) TIOBuffer_WritePtr(&(self)->fBase)
#define TRingBuffer_ReadRemain(self) TIOBuffer_ReadRemain(&(self)->fBase)
#define TRingBuffer_WriteRemain(self) TIOBuffer_WriteRemain(&(self)->fBase)
#define TRingBuffer_OffsetOf(self, s) TIOBuffer_OffsetOf(&(self)->fBase,(s))

#define TRingBuffer_SetBuffer(self,buf,len) TIOBuffer_SetBuffer(&(self)->fBase,(buf),(len))
#define TRingBuffer_ExpandBuffer(self,buf,len) TIOBuffer_ExpandBuffer(&(self)->fBase,(buf),(len))

#define TRingBuffer_ReadSeek(self,off,whc) TIOBuffer_ReadSeek(&(self)->fBase,(off),(whc))
#define TRingBuffer_WriteSeek(self,off,whc) TIOBuffer_WriteSeek(&(self)->fBase,(off),(whc))

/*
 * ElasticBuf
 */
#define TElasticBuf_Length(self) ((self)->fLength)
#define TElasticBuf_SetBlockSize(self,size) ((self)->fBlockSize = SLIM_ROUNDUP_P2((size), 32))
#define TElasticBuf_Lock(self) ((*(self)->fLockUnlock)((self)->fUserData,slim_true))
#define TElasticBuf_Unlock(self) ((*(self)->fLockUnlock)((self)->fUserData,slim_false))

#define TElasticBuf_LockWithBuffer(self,buf) TIOBuffer_ExpandBuffer((buf), TElasticBuf_Lock((self)), TElasticBuf_Length((self)))

SLIM_END_C_LINKAGE
#endif /* SLIM_BASE_H_PRIVATE */
