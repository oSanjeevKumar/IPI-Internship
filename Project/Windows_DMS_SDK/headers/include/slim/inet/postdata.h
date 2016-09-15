/*
	postdata.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/inet/postdata.h 5     05/12/28 12:07 Someya $ */

#ifndef SLIM_POSTDATA_H
#define SLIM_POSTDATA_H

SLIM_BEGIN_C_LINKAGE

#ifndef SLIM_POSTDATA_BUFFER_SIZE
#define SLIM_POSTDATA_BUFFER_SIZE (SLIM_HTTP_STREAM_MSS)
#endif

#define SLIM_POSTDATA_TYPE_ONDEMAND 0x01
#define SLIM_POSTDATA_TYPE_ACTUAL 0x02
#define SLIM_POSTDATA_HAS_FILE 0x04
#define SLIM_POSTDATA_HAS_SPECIAL_FILE 0x08

typedef slim_bool (*PostData_FetchSpecialFileProc)(slim_opaque in_userdata, slim_char *in_buffer, slim_int in_buffer_len, slim_int *out_wrote_len, slim_bool in_write);
typedef void (*PostData_DeleteSpecialFileProc)(slim_opaque in_userdata);

struct iTPostData_ {
	slim_int fFlag;
	slim_int fEncoding;
	slim_int fDataSize;
	slim_int fRefCount;
	slim_vhandle fData;
	PostData_FetchSpecialFileProc fFetchSpecialFileProc;
	PostData_DeleteSpecialFileProc fDeleteSpecialFileProc;
};
typedef struct iTPostData_ iTPostData;
typedef iTPostData **TPostData;

enum {
	SLIM_POSTDATACUR_ST_START,
	SLIM_POSTDATACUR_ST_URL_NAME_WRITE,
	SLIM_POSTDATACUR_ST_URL_NAME_END,
	SLIM_POSTDATACUR_ST_URL_VALUE_WRITE,
	SLIM_POSTDATACUR_ST_URL_VALUE_END,
	SLIM_POSTDATACUR_ST_PLAIN_START,
	SLIM_POSTDATACUR_ST_PLAIN_NAME_WRITE,
	SLIM_POSTDATACUR_ST_PLAIN_NAME_END,
	SLIM_POSTDATACUR_ST_PLAIN_VALUE_WRITE,
	SLIM_POSTDATACUR_ST_PLAIN_VALUE_END,
	SLIM_POSTDATACUR_ST_MIME_DELIMITER,
	SLIM_POSTDATACUR_ST_MIME_DISPOSITION,
	SLIM_POSTDATACUR_ST_MIME_NAME_WRITE,
	SLIM_POSTDATACUR_ST_MIME_NAME_END,
	SLIM_POSTDATACUR_ST_MIME_FNAME,
	SLIM_POSTDATACUR_ST_MIME_FNAME_WRITE,
	SLIM_POSTDATACUR_ST_MIME_FNAME_END,
	SLIM_POSTDATACUR_ST_MIME_MIMETYPE,
	SLIM_POSTDATACUR_ST_MIME_HEADEREND,
	SLIM_POSTDATACUR_ST_MIME_VALUE,
	SLIM_POSTDATACUR_ST_MIME_BODYEND,
	SLIM_POSTDATACUR_ST_MIME_READFILE,
	SLIM_POSTDATACUR_ST_MIME_READFILE_SPECIAL,
	SLIM_POSTDATACUR_ST_MIME_CLOSEDELIMITER,
	SLIM_POSTDATACUR_ST_RAW_READVALUE,
	SLIM_POSTDATACUR_ST_RAW_READFILE,
	SLIM_POSTDATACUR_ST_END,
	SLIM_POSTDATACUR_STS
};

struct TPostDataCursor_ {
	slim_int fState;
	TPostData fPostData;
	slim_int fPostDataOff;
	slim_char *fBuffer;
	slim_int fBufferSize;
	slim_offlen fOfflen;

	/* temporary data */
	TString fBoundary;
	slim_int fType;
	slim_iaddr_word fFileDesc;
	slim_int fLen;
};
typedef struct TPostDataCursor_ TPostDataCursor;

SLIM_END_C_LINKAGE
#endif
