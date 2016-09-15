/*
 * peer_dir.c
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

/* DLNA peer directory APIs.  */

#include <dlna_peer.h>
#include "peer_dir.h"

#define ULONG_BUFSIZ (11)

PEER_DIR *peer_dir_alloc(void) {
	PEER_DIR *dir = (PEER_DIR *)malloc(sizeof(PEER_DIR));
	dir->nReadCount = 0;
	dir->hFindFile = INVALID_HANDLE_VALUE;
	return dir;
}

void peer_dir_free(PEER_DIR *dir) {
	free(dir);
}

void peer_dirent_extract(struct peer_dirent *prDirEnt, WIN32_FIND_DATA *pFindFileData) {
	char szName[PEER_DIR_PATH_BUFSIZE];
	if (!prDirEnt || !pFindFileData) // sanity check
		return;
	dlnaCS_Wide_to_UTF8(pFindFileData->cFileName, szName, PEER_DIR_PATH_BUFSIZE);
	dlna_strcpy(prDirEnt->d_name, szName);
}

slim_bool is_dots(const TCHAR *str) {
	return
		(_tcscmp(str, _T(".")) == 0) ||
		(_tcscmp(str, _T("..")) == 0);
}

// open directory
dlna_dir_t dlnaFileSystemOpenDirPeer(slim_char *in_path)
{
	WIN32_FIND_DATA FindFileData;
	TCHAR szPath[PEER_DIR_PATH_BUFSIZE + 3];
	PEER_DIR *dir = NULL;

	// we cannot handle paths larger than BUFSIZE
	if (dlna_strlen(in_path) > PEER_DIR_PATH_BUFSIZE) return NULL;
	dir = peer_dir_alloc();
	
	dlnaCS_UTF8_to_Wide(in_path, szPath, PEER_DIR_PATH_BUFSIZE);
	_tcsncat(szPath, PEER_DIR_DIR_WILD_CARD, _tcslen(PEER_DIR_DIR_WILD_CARD));
	
	// find the first file
#if (_WIN32_WINNT >= 0x0602 /*_WIN32_WINNT_WIN8*/)
	dir->hFindFile = FindFirstFileEx(szPath, FindExInfoStandard, &FindFileData, 
								FindExSearchNameMatch, NULL, 0 );
#else
  dir->hFindFile = FindFirstFile(szPath, &FindFileData);
#endif
	if (dir->hFindFile == INVALID_HANDLE_VALUE) {
		// if the error isn't ERROR_NO_MORE_FILES then it is better to return NULL
		if (GetLastError() != ERROR_NO_MORE_FILES) {
			peer_dir_free(dir);
			dir = NULL;
		}
	} else {
		// copy the name from the file data structure to the dirent structure
		peer_dirent_extract(&(dir->rDirEnt), &FindFileData);
	}
	return (dlna_dir_t)dir;
}

// close directory
void dlnaFileSystemCloseDirPeer(dlna_dir_t in_desc)
{
	PEER_DIR *dir = (PEER_DIR *)in_desc;
	if (!dir) return;
	
	if (!dir->hFindFile ||
		dir->hFindFile == INVALID_HANDLE_VALUE ||
		FindClose(dir->hFindFile))
		peer_dir_free(dir);
}

// new directory entry
slim_int dlnaFileSystemNewDirPeer(slim_char *in_name)
{
	slim_int err = 0;
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) && WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
	_mkdir(in_name);
	/* _get_errno is returning the error even in the success case so disabling this check*/
	/* _get_errno(&err);
	if (err) {
		DLNA_LOG(DLNA_LOG_PEER_DIR, DLNA_LOG_LEVEL_ERROR, "dlnaFileSystemNewDirPeer mkdir failed error code = %d.path = %s", err, in_name);
	} */
	return SLIM_E_OK;
#else
	if (!CreateDirectoryA(in_name, NULL)) {
		err = GetLastError();
		if (err && err != ERROR_ALREADY_EXISTS) {
			DLNA_LOG(DLNA_LOG_PEER_DIR, DLNA_LOG_LEVEL_ERROR, "dlnaFileSystemNewDirPeer CreateDirectoryA at:%s  and last errorCode = %d", in_name, err);
			return err;
		}
		err = SLIM_E_OK;
	}
	return err;
#endif //WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) && WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PHONE_APP)
		
}

// delete directory entry
slim_int dlnaFileSystemDeleteDirPeer(slim_char *in_name, slim_bool delete_self)
{
	HANDLE hFindFile;
	WIN32_FIND_DATA FindFileData;
	TCHAR szDirPath[PEER_DIR_PATH_BUFSIZE + 3];
	TCHAR szFileName[PEER_DIR_PATH_BUFSIZE + 3];	
	slim_char recursivePath[PEER_DIR_PATH_BUFSIZE + 3];	
	slim_bool bSearch = slim_true;
	if (dlna_strlen(in_name) > PEER_DIR_PATH_BUFSIZE) return 0;

	dlnaCS_UTF8_to_Wide(in_name, szDirPath, PEER_DIR_PATH_BUFSIZE);
	dlnaCS_UTF8_to_Wide(in_name, szFileName, PEER_DIR_PATH_BUFSIZE);
	_tcsncat(szDirPath, PEER_DIR_DIR_WILD_CARD, _tcslen(PEER_DIR_DIR_WILD_CARD));
	_tcsncat(szFileName, PEER_DIR_FILE_WILD_CARD, _tcslen(PEER_DIR_FILE_WILD_CARD));
	
	// find the first file
#if (_WIN32_WINNT >= 0x0602 /*_WIN32_WINNT_WIN8*/)
	hFindFile = FindFirstFileEx(szDirPath, FindExInfoStandard, &FindFileData,
								FindExSearchNameMatch, NULL, 0);
#else
	hFindFile = FindFirstFile(szDirPath, &FindFileData);
#endif
	
	if (hFindFile == INVALID_HANDLE_VALUE) return 0;
	_tcscpy(szDirPath, szFileName);
	
	// until we find an entry
	while (bSearch) {
		if (FindNextFile(hFindFile, &FindFileData)) {
			if (is_dots(FindFileData.cFileName)) continue;
			_tcscat(szFileName, FindFileData.cFileName);
			if ((FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				// we have found a directory, recurse
				dlnaCS_Wide_to_UTF8(szFileName, recursivePath, PEER_DIR_PATH_BUFSIZE);
				if (!dlnaFileSystemDeleteDirPeer(recursivePath, slim_true)) {
					// directory couldn't be deleted
					FindClose(hFindFile);
					return 0;
				}
				// remove the empty directory
				RemoveDirectory(szFileName);
				_tcscpy(szFileName, szDirPath);
			} else {
				if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_READONLY)
					// change read-only file mode
					_chmod(szFileName, _S_IWRITE);
				if (!DeleteFile(szFileName)) {
					// delete the file
					FindClose(hFindFile);
                    return 0;
				}
				_tcscpy(szFileName, szDirPath);
			}
		} else {
			// no more files there
			if(GetLastError() == ERROR_NO_MORE_FILES) {
				bSearch = slim_false;
			} else {
				// some error occurred; close the handle and return 0
				FindClose(hFindFile);
				return 0;
			}
		}
	}
	// close the file handle
	FindClose(hFindFile);
	// remove the empty directory
	if(delete_self) {
		dlnaCS_UTF8_to_Wide(in_name, szDirPath, PEER_DIR_PATH_BUFSIZE);
		return RemoveDirectory(szDirPath);
	}
	return -1;
}

// read next directory entry
dlna_dirent dlnaFileSystemReadDirPeer(dlna_dir_t in_desc)
{
	PEER_DIR *dir = (PEER_DIR *) in_desc;
	WIN32_FIND_DATA FindFileData;
	
	// sanity check, also return NULL if there was an invalid handle
	if (!dir || dir->hFindFile == INVALID_HANDLE_VALUE || !dir->hFindFile) return NULL;
	
	// check to see if this is the first time reading this directory
	// (if it is the first time, then the dirent struct already contains the filename)
	if (dir->nReadCount > 0) { // in this case find the next file
		if (FindNextFile(dir->hFindFile, &FindFileData))
			// copy the name from the file data structure to the dirent structure
			peer_dirent_extract(&(dir->rDirEnt), &FindFileData);
		else
			return NULL;
    }
	dir->nReadCount ++;
	return (dlna_dirent)&(dir->rDirEnt);
}

// return name of the entry
slim_char *dlnaFileSystemDirentNamePeer(dlna_dirent in_dirent)
{
	return (slim_char *)((struct peer_dirent *)in_dirent)->d_name;
}

// get file's stat
slim_int dlnaFileSystemStatPeer(const slim_char *in_path, dlna_stat *out_stat)
{
	static DWORD s_attrNotRegular =
		FILE_ATTRIBUTE_COMPRESSED |
		FILE_ATTRIBUTE_ENCRYPTED |
		FILE_ATTRIBUTE_OFFLINE |
		FILE_ATTRIBUTE_SYSTEM |
		FILE_ATTRIBUTE_TEMPORARY |
		FILE_ATTRIBUTE_HIDDEN;
	WIN32_FILE_ATTRIBUTE_DATA rFileAttr;
	TCHAR *szFileName = NULL;
	SYSTEMTIME rSysTime;
	DWORD attr;
	slim_int nBufLen;
	slim_int nRetVal = SLIM_E_GENERIC;

	// sanity check
	if (!in_path || !out_stat) return SLIM_E_GENERIC;
	nBufLen = dlnaCS_UTF8_to_Wide(in_path, NULL, 0);
	if (nBufLen == 0) return SLIM_E_OK;
	else if (nBufLen < 0) return SLIM_E_GENERIC;

	// convert the file name to unicode (if necessary)
	szFileName = (TCHAR *)dlna_memory_alloc(sizeof(TCHAR) * nBufLen);
	dlnaCS_UTF8_to_Wide(in_path, szFileName, nBufLen);

	// get the extended file information
	if (GetFileAttributesEx(szFileName, GetFileExInfoStandard, &rFileAttr))	{
		out_stat->mtime = 0;
		out_stat->mode = 0;
		// get the file creation time
		if (FileTimeToSystemTime(&(rFileAttr.ftCreationTime), &rSysTime))
			out_stat->ctime = winConvertSys2Timet(&rSysTime);
		// get the file modification time
		if (FileTimeToSystemTime(&(rFileAttr.ftLastWriteTime), &rSysTime))
			out_stat->mtime = winConvertSys2Timet(&rSysTime);
		// get the file mode
		attr = rFileAttr.dwFileAttributes;
		if (attr & FILE_ATTRIBUTE_DIRECTORY) {
			if (dlnaIsNTFSDrive(szFileName)) {
				out_stat->mode = _S_IFDIR;
			}
			if (!(attr & FILE_ATTRIBUTE_HIDDEN)) {
				out_stat->mode = _S_IFDIR;
			}
		} else if (!(attr & s_attrNotRegular)) {
			out_stat->mode = _S_IFREG;
		}
		if (attr & FILE_ATTRIBUTE_READONLY)
			out_stat->mode |= FILE_ATTRIBUTE_READONLY | _S_IREAD;
		else
			out_stat->mode |= FILE_ATTRIBUTE_READONLY | _S_IREAD | _S_IWRITE;
		// get the file size
		out_stat->size.high = rFileAttr.nFileSizeHigh;
		out_stat->size.low = rFileAttr.nFileSizeLow;

		nRetVal = SLIM_E_OK;
	}

	dlna_memory_free(szFileName);
	return nRetVal;
}

static slim_bool
dlnaCheckDirIsReadOnly(const slim_char* in_path)
{
  slim_bool retVal = slim_false;
  dlna_file_t hFile = NULL;
  slim_char *temp_file = "temp.tmp";
  slim_char *temp = slim_nil;

  if (!in_path){
    return retVal;
  }

  temp = (slim_char*)dlna_memory_alloc(dlna_strlen(in_path) + dlna_strlen(temp_file) + 4);
  if (!temp){
    return retVal;
  }

  dlna_strcpy(temp, in_path);
  dlna_strcat(temp, PATH_SEPARATOR);
  dlna_strcat(temp, temp_file);

  hFile = dlnaFileOpenPeer(temp,
    (slim_int)(DLNA_STREAM_WRITE | DLNA_STREAM_CREATE | DLNA_STREAM_TRUNCATE | DLNA_STREAM_HIDDEN));
  
  if (hFile < 0){
    retVal = slim_true;
  }
  else{
    dlnaFileClosePeer(hFile);
    dlnaFileDeletePeer(temp);
    retVal = slim_false;
  }

  hFile = NULL;
  dlna_memory_free(temp);
  return retVal;
}
slim_bool
dlnaFileSystemAccessPeer(const slim_char* in_path, slim_int in_type)
{
  slim_int retVal = -1;

  switch (in_type) {
  case DLNA_ACCESS_F: /* Existence */
    retVal = _access((const char*)in_path, 00);
    break;
  case DLNA_ACCESS_X: /* Execute permission. */
    //Execute permission check is unsupported in windows
    break;
  case DLNA_ACCESS_W: /* Write permission. */
    retVal = dlnaCheckDirIsReadOnly(in_path);
    break;
  case DLNA_ACCESS_R: /* Read permission. */
    retVal = _access((const char*)in_path, 04);
    break;
  default:
    /* do nothing */
    break;
  }

  if (retVal == 1){
    return slim_false;
  }
  else{
    return slim_true;
  }
	
}

slim_int dlnaFileSystemGetAvailSpacePeer(slim_char *in_path, dlna_uint64 *out_size)
{
	WCHAR szWDrive[4];
	slim_char szSDrive[4];
	ULARGE_INTEGER i64FreeBytesToCaller;

	if (!in_path || !out_size || in_path[1] != ':')
		return SLIM_E_GENERIC;
	
	szWDrive[0] = in_path[0];
	szWDrive[1] = ':';
	szWDrive[2] = PATH_SEPARATOR_CHAR;
	szWDrive[3] = '\0';

#ifdef UNICODE
	if (!GetDiskFreeSpaceEx((LPCTSTR)szWDrive, (PULARGE_INTEGER)&i64FreeBytesToCaller, NULL, NULL))
		return SLIM_E_GENERIC;
#else
	WideCharToMultiByte(CP_ACP, 0, (LPCTSTR)szWDrive, -1, szSDrive, 4, NULL, NULL);
	if (!GetDiskFreeSpaceEx((LPCTSTR)szSDrive, (PULARGE_INTEGER)&i64FreeBytesToCaller, NULL, NULL))
		return SLIM_E_GENERIC;
#endif
	out_size->high = i64FreeBytesToCaller.HighPart;
	out_size->low = i64FreeBytesToCaller.LowPart;
	return SLIM_E_OK;
}

// get file's stat
slim_bool dlnaFileSystemMSDOS(slim_char *in_path)
{
#if (_WIN32_WINNT >= 0x0602 /*_WIN32_WINNT_WIN8*/)
  //Because window store app doesn't reveal the file volume internals so there is no API to get this info.
  return slim_false;
#else
	// flags that describe the file system
	slim_long ulSysFlags;
	slim_char volumeName[ULONG_BUFSIZ] = { 0 };
	slim_char FileSysNameBuf[ULONG_BUFSIZ] = { 0 };
	
	if ('\\' == in_path[2])
		dlna_memcpy(volumeName, in_path, 4);
	else if ('/' == in_path[2])
		dlna_memcpy(volumeName, in_path, 3);
	else
		return slim_false;

	if (!GetVolumeInformation(volumeName, NULL, 0, NULL, NULL, &ulSysFlags, FileSysNameBuf, ULONG_BUFSIZ))
		return slim_false;
	if (!dlna_memcmp(FileSysNameBuf, "FAT", dlna_strlen("FAT")))
		return slim_true;
	return slim_true;
#endif
}

slim_bool dlnaIsNTFSDrive(TCHAR *in_drivepath) {
	slim_long ulSysFlags;
	TCHAR FileSysNameBuf[ULONG_BUFSIZ] = { 0 };
	slim_int pathlen = -1;
	slim_char volumeType[ULONG_BUFSIZ];
	
	if (!in_drivepath) {
		return slim_false;
	}
#if (_WIN32_WINNT >= 0x0602 /*_WIN32_WINNT_WIN8*/)
	//Because window store app doesn't reveal the file volume internals so there is no API to get this info.
	return slim_false;
#else
	if (GetVolumeInformation(in_drivepath, NULL, 0, NULL, NULL, &ulSysFlags, FileSysNameBuf, ULONG_BUFSIZ)) {
		dlnaCS_Wide_to_UTF8(FileSysNameBuf, volumeType, sizeof(volumeType));
		if (!dlna_strcmp(volumeType, "NTFS")) {
			return slim_true;
		}
		else {
			return slim_false;
		}
	}
	return slim_false;
#endif
}
