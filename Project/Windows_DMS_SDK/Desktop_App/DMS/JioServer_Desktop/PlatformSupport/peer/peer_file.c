/*
 * peer_file.c
 * Copyright (C) 2007-2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

/* SLIM peer FILE APIs.  */

#include <dlna_peer.h>


// helper function to translate the peer flag to appropriate file attribute flags for windows
static DWORD translate_flag2fileAttr(slim_int in_flag)
{
  return(in_flag & DLNA_STREAM_HIDDEN ? FILE_ATTRIBUTE_HIDDEN : FILE_ATTRIBUTE_NORMAL);
}

// helper function to translate the peer flag to appropriate file access flags for windows
static DWORD translate_flag2accs(slim_int in_flag)
{
	return
		(in_flag & DLNA_STREAM_READ  ? GENERIC_READ  : 0) |
		(in_flag & DLNA_STREAM_WRITE ? GENERIC_WRITE : 0);
}

// helper function to translate the peer flag to appropriate disposition flags for windows
static DWORD translate_flag2disp(slim_int in_flag)
{
	// Determine the creation disposition
	if ((in_flag & DLNA_STREAM_EXCLUSIVE) && (in_flag & DLNA_STREAM_CREATE))
		return CREATE_NEW;
	else if ((in_flag & DLNA_STREAM_TRUNCATE) && (in_flag & DLNA_STREAM_CREATE))
		return CREATE_ALWAYS;
	else if (in_flag & DLNA_STREAM_TRUNCATE)
		return TRUNCATE_EXISTING;
	else if (in_flag & DLNA_STREAM_CREATE)
		return CREATE_NEW; // ZZZ: If the file exists, CreateFile will be failed
	else
		return OPEN_EXISTING;
}

// root function to open a windows file
static HANDLE winFileOpenPeer(slim_char *in_fname, DWORD dwDA, DWORD dwCD, DWORD dwFileAttr)
{
	HANDLE hFile = NULL;
	TCHAR *szFileName = NULL;
	
	slim_int nBufLen = dlnaCS_UTF8_to_Wide(in_fname, NULL, 0);

	if (nBufLen == 0) return NULL;
	else if (nBufLen < 0) return INVALID_HANDLE_VALUE;

	szFileName = (TCHAR *)dlna_memory_alloc(sizeof(TCHAR) * nBufLen);
	dlnaCS_UTF8_to_Wide(in_fname, szFileName, nBufLen);
#if (_WIN32_WINNT >= 0x0602 /*_WIN32_WINNT_WIN8*/)
	hFile = CreateFile2(szFileName, dwDA, FILE_SHARE_READ, dwCD, NULL);
#else
	hFile = CreateFile(szFileName,
                      dwDA,
                      FILE_SHARE_READ,
                      NULL,
                      dwCD,
                      dwFileAttr,
                      NULL);
#endif 
	dlna_memory_free(szFileName);
	return hFile;
}

// open file
dlna_file_t dlnaFileOpenPeer(const slim_char *in_fname, slim_int in_flag)
{
	// determine the access type	
	HANDLE hFile = winFileOpenPeer(in_fname,
                    translate_flag2accs(in_flag),
                    translate_flag2disp(in_flag),
                    translate_flag2fileAttr(in_flag)
                  );
	
	if (!hFile || hFile == INVALID_HANDLE_VALUE)
		return DLNA_INVALID_FILE_HANDLE;

	return (dlna_file_t)hFile;
}

// close file
void dlnaFileClosePeer(dlna_file_t in_desc)
{
	CloseHandle((HANDLE)in_desc);
}

// read data
dlna_ssize_t dlnaFileReadPeer(dlna_file_t in_desc, void *out_buf, dlna_size_t in_len)
{
	DWORD nBytesRead = 0;
	if (ReadFile((HANDLE)in_desc, out_buf, (DWORD)in_len, &nBytesRead, NULL)) {
		return (dlna_size_t)nBytesRead;
	} else {
		DWORD error = GetLastError();
		switch(error) {
			case ERROR_INVALID_USER_BUFFER:
				return (dlna_size_t)-1;
			case ERROR_NOT_ENOUGH_MEMORY:
				return (dlna_size_t)-1;
			case ERROR_NOT_ENOUGH_QUOTA:
				return (dlna_size_t)-1;
		}
		return (dlna_ssize_t)-1;
	}
}

// write data
dlna_ssize_t dlnaFileWritePeer(dlna_file_t in_desc, void *in_buf, dlna_size_t in_len)
{
	DWORD nBytesWritten = 0;
	if (WriteFile((HANDLE)in_desc, in_buf, (DWORD)in_len, &nBytesWritten, NULL) )
		return (dlna_ssize_t)nBytesWritten;
	else
		return (dlna_ssize_t)-1;
}

// delete the file
slim_int dlnaFileDeletePeer(slim_char *in_fname)
{
	slim_int nRetVal;
	slim_int nBufLen = dlna_strlen(in_fname) + 10;
	TCHAR *szFileName = (TCHAR *)dlna_memory_alloc(sizeof(TCHAR) * nBufLen);
	dlnaCS_UTF8_to_Wide(in_fname, szFileName, nBufLen);

	nRetVal = DeleteFile(szFileName) ? SLIM_E_OK : SLIM_E_GENERIC;
	dlna_memory_free(szFileName);

	return nRetVal;
}

// seek the file pointer
dlna_off_t dlnaFileSeekPeer(dlna_file_t in_desc, dlna_off_t in_offset, slim_int in_origin)
{
	DWORD dwMoveMethod = 0;
	LARGE_INTEGER liDistanceToMove;
	LARGE_INTEGER liNewFilePointer;
	slim_bool fileRet = slim_false;

	liDistanceToMove.QuadPart = in_offset;

	// Sign extend in_offset if its only 4 bytes long
	if (sizeof(dlna_off_t) == 4 && (in_offset < 0))
		liDistanceToMove.HighPart = 0xFFFFFFFF;

	switch (in_origin)
	{
	case DLNA_SEEK_SET:
		dwMoveMethod = FILE_BEGIN;
		break;
	case DLNA_SEEK_CUR:
		dwMoveMethod = FILE_CURRENT;
		break;
	case DLNA_SEEK_END:
		dwMoveMethod = FILE_END;
		break;
	default:
		return -1;
	};
#if (_WIN32_WINNT >= 0x0602 /*_WIN32_WINNT_WIN8*/)
	fileRet = SetFilePointerEx((HANDLE)in_desc, liDistanceToMove, &liNewFilePointer, dwMoveMethod);
#else
	liNewFilePointer.LowPart = SetFilePointer((HANDLE)in_desc, liDistanceToMove.LowPart, &(liDistanceToMove.HighPart), dwMoveMethod);
#endif
 
	// test for failure
	if (liNewFilePointer.LowPart == INVALID_SET_FILE_POINTER && GetLastError() != NO_ERROR) // fail
		liNewFilePointer.QuadPart = -1;
	else
		liNewFilePointer.HighPart = liDistanceToMove.HighPart;

	return (dlna_off_t)liNewFilePointer.QuadPart;
}

// seek the file pointer
slim_bool dlnaFileSeek64Peer(dlna_file_t in_desc, dlna_uint64 in_offset)
{
	LARGE_INTEGER liDistanceToMove;
	LARGE_INTEGER liSaveFilePointer;
	slim_bool fileRet = slim_false;

	liDistanceToMove.HighPart = in_offset.high;
	liDistanceToMove.LowPart = in_offset.low;
	liSaveFilePointer = liDistanceToMove;
#if (_WIN32_WINNT >= 0x0602 /*_WIN32_WINNT_WIN8*/)
	fileRet = SetFilePointerEx((HANDLE)in_desc, liDistanceToMove, &liSaveFilePointer, FILE_BEGIN);
#else
	liDistanceToMove.LowPart = SetFilePointer((HANDLE)in_desc, liDistanceToMove.LowPart, &(liDistanceToMove.HighPart), FILE_BEGIN);
#endif
	// test for failure
	if (INVALID_SET_FILE_POINTER == liDistanceToMove.LowPart && GetLastError() != NO_ERROR ) // fail
		return slim_false;

	return
		(liSaveFilePointer.HighPart == liDistanceToMove.HighPart) &&
		(liSaveFilePointer.LowPart == liDistanceToMove.LowPart);
}

// seek the file pointer forward
slim_int dlnaFileSeek64PeerForward(dlna_file_t in_desc, dlna_uint64 in_offset, dlna_uint64 *out_pos)
{
#if 0
  off_t loc, rloc;

  if((sizeof loc) != 8){
    DLNA_LOG(DLNA_LOG_PEER_FILE, DLNA_LOG_LEVEL_ERROR, "dlnaFileSeek64PeerForward->null_pointer");
    return -1;
  }

  loc = ((long long)in_offset.high << 32) | (in_offset.low & 0xFFFFFFFF);

  rloc = lseek64 ((int) in_desc, (off_t) loc, SEEK_SET);
  if (rloc < 0) {
    return -1;
  }
  if(out_pos) {
    out_pos->low = rloc & 0x00000000FFFFFFFFLL;
    out_pos->high = rloc >> 32;
  }
#else
  LARGE_INTEGER liDistanceToMove;
  LARGE_INTEGER liSaveFilePointer;
  slim_bool fileRet = slim_false;

  liDistanceToMove.HighPart = in_offset.high;
  liDistanceToMove.LowPart = in_offset.low;
  liSaveFilePointer = liDistanceToMove;

#if (_WIN32_WINNT >= 0x0602 /*_WIN32_WINNT_WIN8*/)
  fileRet = SetFilePointerEx((HANDLE)in_desc, liDistanceToMove, &liSaveFilePointer, FILE_BEGIN);
#else
  liDistanceToMove.LowPart = SetFilePointer((HANDLE)in_desc, liDistanceToMove.LowPart, &(liDistanceToMove.HighPart), FILE_BEGIN);
#endif
  // test for failure
  if (INVALID_SET_FILE_POINTER == liDistanceToMove.LowPart && GetLastError() != NO_ERROR ) // fail
    return -1;
#if 0
  if((liSaveFilePointer.HighPart == liDistanceToMove.HighPart) && (liSaveFilePointer.LowPart == liDistanceToMove.LowPart)) {
      return -1;
  }
#endif
  if (out_pos) {
    out_pos->low = liDistanceToMove.LowPart;
    out_pos->high = liDistanceToMove.HighPart;
  }
#endif
  return SLIM_E_OK;
}

// seek the file pointer backward
slim_int dlnaFileSeek64PeerBackward(dlna_file_t in_desc, dlna_uint64 in_offset, dlna_uint64 *out_pos)
{
#if 0
  off_t loc, rloc;

  if((sizeof loc) != 8){
    DLNA_LOG(DLNA_LOG_PEER_FILE, DLNA_LOG_LEVEL_ERROR,"dlnaFileSeek64PeerBackward->null_pointer.");
    return -1;
  }

  loc = ((long long)in_offset.high << 32) | (in_offset.low & 0xFFFFFFFF);
  if (loc & 0x8000000000000000LL) {
    return -1;
  }

  rloc = lseek64 ((int) in_desc, (off_t) -loc, SEEK_END);
  if (rloc < 0) {
    return -1;
  }
  out_pos->low = rloc & 0x00000000FFFFFFFFLL;
  out_pos->high = rloc >> 32;
#else
  LARGE_INTEGER liDistanceToMove;
  LARGE_INTEGER liSaveFilePointer;
  slim_bool fileRet = slim_false;

  liDistanceToMove.HighPart = in_offset.high;
  liDistanceToMove.LowPart = in_offset.low;
  liSaveFilePointer = liDistanceToMove;
#if (_WIN32_WINNT >= 0x0602 /*_WIN32_WINNT_WIN8*/)
  fileRet = SetFilePointerEx((HANDLE)in_desc, liDistanceToMove, &liSaveFilePointer, FILE_BEGIN);
#else
  liDistanceToMove.LowPart = SetFilePointer((HANDLE)in_desc, liDistanceToMove.LowPart, &(liDistanceToMove.HighPart), FILE_END);
#endif
  // test for failure
  if (INVALID_SET_FILE_POINTER == liDistanceToMove.LowPart && GetLastError() != NO_ERROR ) // fail
    return -1;
#if 0
  if((liSaveFilePointer.HighPart == liDistanceToMove.HighPart) && (liSaveFilePointer.LowPart == liDistanceToMove.LowPart)) {
      return -1;
  }
#endif
  if (out_pos) {
    out_pos->low = liDistanceToMove.LowPart;
	out_pos->high = liDistanceToMove.HighPart;
  }
#endif
  return SLIM_E_OK;
}

// seek the file pointer from current position
slim_int dlnaFileSeek64PeerCurrent(dlna_file_t in_desc, dlna_sint64 in_offset, dlna_uint64 *out_pos)
{
#if 0
  off_t loc, rloc;

  if((sizeof loc) != 8){
    DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "dlnaFileSeek64PeerCurrent->null_pointer");
    return -1;
  }

  loc = ((long long)in_offset.high << 32) | (in_offset.low & 0xFFFFFFFF);

  rloc = lseek64 ((int) in_desc, (off_t) loc, SEEK_CUR);
  if (rloc < 0) {
    return -1;
  }
  if(out_pos) {
    out_pos->low = rloc & 0x00000000FFFFFFFFLL;
    out_pos->high = rloc >> 32;
  }
#else
  LARGE_INTEGER liDistanceToMove;
  LARGE_INTEGER liSaveFilePointer;
  slim_bool fileRet = slim_false;

  liDistanceToMove.HighPart = in_offset.high;
  liDistanceToMove.LowPart = in_offset.low;
  liSaveFilePointer = liDistanceToMove;

#if (_WIN32_WINNT >= 0x0602 /*_WIN32_WINNT_WIN8*/)
  fileRet = SetFilePointerEx((HANDLE)in_desc, liDistanceToMove, &liSaveFilePointer, FILE_BEGIN);
#else
  liDistanceToMove.LowPart = SetFilePointer((HANDLE)in_desc, liDistanceToMove.LowPart, &(liDistanceToMove.HighPart), FILE_CURRENT);
#endif
  // test for failure
  if (INVALID_SET_FILE_POINTER == liDistanceToMove.LowPart && GetLastError() != NO_ERROR ) // fail
    return -1;
#if 0
  if((liSaveFilePointer.HighPart == liDistanceToMove.HighPart) && (liSaveFilePointer.LowPart == liDistanceToMove.LowPart)) {
      return -1;
  }
#endif
  if (out_pos) {
    out_pos->low = liDistanceToMove.LowPart;
    out_pos->high = liDistanceToMove.HighPart;
  }
#endif
  return SLIM_E_OK;
}

slim_int dlnaGenerateNewFileNamePeer(dlna_contents_file_info *in_contents_file_info, slim_char *out_contents_path, slim_int in_contents_path_len)
{
	//todo: dlnaGenerateNewFileNamePeer
  if (!in_contents_file_info || !out_contents_path) {
    return -1;
  }

  if (!in_contents_file_info->path || !in_contents_file_info->title || !in_contents_file_info->extension) {
    return -1;
  }

  memset(out_contents_path, 0, in_contents_path_len);
  
  if (in_contents_path_len < strlen((const char *)in_contents_file_info->path) + 
      strlen((const char *)in_contents_file_info->title) + 1 + // '.'  
      strlen((const char *)in_contents_file_info->extension) + 1) { // null
    return -1;
  }
  strcpy((char *)out_contents_path, (const char *)in_contents_file_info->path);
  strcat((char *)out_contents_path, (const char *)in_contents_file_info->title);
  strcat((char *)out_contents_path, (const char *)SLIM_T("."));
  strcat((char *)out_contents_path, (const char *)in_contents_file_info->extension);

  return 0;
}

slim_bool dlnaRenameFilePeer(slim_char *in_oldpath, slim_char *in_newpath)
{
	//todo: dlnaGenerateNewFileNamePeer
  slim_bool ret = slim_true;

  if (-1 == rename((const char *)in_oldpath, (const char *)in_newpath)) {
    ret = slim_false;
  }

  return ret;
}

#ifdef DEVELOPMENT_CONTENT_AGGREGATION
slim_char*
dlnaFileSystemRelativeToAbsolutePathPeer(const slim_char *in_path, slim_char *out_path)
{
  WCHAR *buffer = slim_nil;
  WCHAR *inPathbuffer = slim_nil;
  TCHAR *szFileName = NULL;
  
  int ret = -1;
  slim_char *FileFullPathBuf = slim_nil;
  slim_int nBufLen = 0;
#if (_WIN32_WINNT >= 0x0602 /*_WIN32_WINNT_WIN8*/)
  return FileFullPathBuf;
#else
  nBufLen = dlnaCS_UTF8_to_Wide(in_path, NULL, 0);

  if (nBufLen == 0) {
    return NULL;
  }
  else if (nBufLen < 0) {
    return INVALID_HANDLE_VALUE;
  }

  szFileName = (TCHAR *)dlna_memory_alloc(sizeof(TCHAR) * nBufLen);
  if (szFileName) {
    dlnaCS_UTF8_to_Wide(in_path, szFileName, nBufLen);
    ret = GetFullPathName(szFileName, 0, NULL, NULL);
    if (ret > 0){
      buffer = (slim_char*)dlna_memory_alloc((sizeof(WCHAR)*ret));
      if (buffer){
        ret = GetFullPathName(szFileName, ret, buffer, NULL);
        if (ret > 0){
          FileFullPathBuf = (slim_char*)dlna_memory_alloc((sizeof(slim_char)*ret) + 1);
          if (FileFullPathBuf){
            dlna_memset(FileFullPathBuf, 0, ret);
            dlnaCS_Wide_to_UTF8(buffer, FileFullPathBuf, ret);
            FileFullPathBuf[ret] = '\0';
          }
        }
        dlna_memory_free(buffer);
      }
    }
    dlna_memory_free(szFileName);
  }
  return FileFullPathBuf;
#endif
}
#endif /*DEVELOPMENT_CONTENT_AGGREGATION*/