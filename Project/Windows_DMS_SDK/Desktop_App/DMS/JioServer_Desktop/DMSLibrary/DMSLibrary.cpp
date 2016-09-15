/*
 * Copyright (C) 2015-2016 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

 
// DMSLibrary.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "DMSLibrary.h"

typedef bool(__cdecl *f_funcInitialize)(DMSWrapper *ptr, dmsInitParams_t *);
typedef returnValue(__cdecl *f_funcStart)(DMSWrapper *ptr);
typedef returnValue(__cdecl *f_funcStop)(DMSWrapper *ptr);
typedef returnValue(__cdecl *f_funcSetFriendly)(DMSWrapper *ptr, slim_char *);
typedef slim_char*(__cdecl *f_funcGetFriendly)(DMSWrapper *ptr);
typedef void(__cdecl *f_funcFinalize)(DMSWrapper *ptr);
typedef void(__cdecl *f_funcDeleteDMSWapperClass)(DMSWrapper *ptr);
typedef DMSWrapper*(__cdecl *f_createDmsWrapper)();
typedef returnValue(__cdecl *f_funcPublishStorageAdd)(DMSWrapper *ptr, slim_char *, slim_char *, slim_char*, dmsStorageDatabaseLocationType, slim_bool);
typedef returnValue(__cdecl *f_funcPublishStorageRemove)(DMSWrapper *ptr, slim_char *);
typedef returnValue(__cdecl *f_funcPublishStorageUpdate)(DMSWrapper *ptr, slim_char *);
typedef returnValue(__cdecl *f_funcPublishSetDefUpload)(DMSWrapper *ptr, slim_char *);
typedef returnValue(__cdecl *f_funcPublishGetDefUpload)(DMSWrapper *ptr, const slim_char **const out_path);
typedef returnValue(__cdecl *f_funcPublishGetStorageCount)(DMSWrapper *ptr, slim_int *);
typedef returnValue(__cdecl *f_funcPublishSetCentralDir)(DMSWrapper *ptr, slim_char *);

typedef returnValue(__cdecl *f_funcPublishGetStorages)(DMSWrapper *ptr, XMLBuffer *);
typedef returnValue(__cdecl *f_funcGetServerState)(DMSWrapper *ptr, dmsState *);
typedef returnValue(__cdecl *f_funcSetServerState)(DMSWrapper *ptr, dmsState);

typedef returnValue(__cdecl *f_funcGetTotalContentShared)(DMSWrapper *ptr, dmsContentClassType, slim_int*);
typedef returnValue(__cdecl *f_funcGetDeviceDescription)(DMSWrapper *ptr, XMLBuffer*);
typedef returnValue(__cdecl *f_funcRefreshContentIndex)(DMSWrapper *ptr);
typedef returnValue(__cdecl *f_funcGetContentTree)(DMSWrapper *ptr, slim_char*, slim_int, slim_int, XMLBuffer *);
typedef returnValue(__cdecl *f_funcSetContentShare)(DMSWrapper *ptr, slim_char *, slim_bool, slim_bool);
typedef returnValue(__cdecl *f_funcGetSupportedLang)(DMSWrapper *ptr, XMLBuffer *);
typedef returnValue(__cdecl *f_funcSetLanguage)(DMSWrapper *ptr, slim_char*);
typedef returnValue(__cdecl *f_funcGetSelectedLang)(DMSWrapper *ptr, slim_char**);
typedef returnValue(__cdecl *f_funcDmsBrowseContent)(DMSWrapper *ptr, slim_char*, XMLBuffer*, slim_word, slim_word);
typedef returnValue(__cdecl *f_funcDmsSearchContent)(DMSWrapper *ptr, slim_char*, slim_char*, XMLBuffer*, slim_word, slim_word);

typedef returnValue(__cdecl *f_funcDmsPGSetDefaultLevel)(DMSWrapper *ptr, dmsPGLevelType, slim_int);
typedef returnValue(__cdecl *f_funcDmsPGGetDefaultLevel)(DMSWrapper *ptr, dmsPGLevelType, slim_int *);
typedef returnValue(__cdecl *f_funcDmsPGGetDeviceList)(DMSWrapper *ptr, XMLBuffer *);

typedef returnValue(__cdecl *f_funcDmsPGSetContentLevel)(DMSWrapper* inObject, slim_char *in_contentID, slim_int in_level);
typedef returnValue(__cdecl *f_funcDmsPGGetLevelList)(DMSWrapper *ptr, XMLBuffer *);
typedef returnValue(__cdecl *f_funcDmsPGSetDeviceParams)(DMSWrapper* inObject, slim_char *in_deviceMAC, slim_int *in_level, slim_char *in_description);
typedef returnValue(__cdecl *f_funcDmsPGDeleteDeviceByMac)(DMSWrapper* inObject, slim_char *in_deviceMAC);

typedef returnValue(__cdecl *f_funcDmsCASetDefaultIndexing)(DMSWrapper* inObject, dmsCAIndex in_enable);
typedef returnValue(__cdecl *f_funcDmsCAGetDefaultIndexing)(DMSWrapper* inObject, dmsCAIndex *out_enable);
typedef returnValue(__cdecl *f_funcDmsCAGetDeviceList)(DMSWrapper* inObject, XMLBuffer *out_CADeviceList);
typedef returnValue(__cdecl *f_funcDmsCASetDeviceIndexing)(DMSWrapper* inObject, slim_char *in_uuid, dmsCAIndex in_index);
typedef returnValue(__cdecl *f_funcDmsCASetDatabaseSizeLimit)(DMSWrapper* inObject, slim_int in_size);
typedef returnValue(__cdecl *f_funcDmsCAGetDatabaseSizeLimit)(DMSWrapper* inObject, slim_int *out_size);
typedef returnValue(__cdecl *f_funcDmsCASetPurgeInterval)(DMSWrapper* inObject, slim_int in_interval);
typedef returnValue(__cdecl *f_funcDmsCAGetPurgeInterval)(DMSWrapper* inObject, slim_int *out_interval);
typedef returnValue(__cdecl *f_funcDmsCASetRescanInterval)(DMSWrapper* inObject, slim_int in_interval);
typedef returnValue(__cdecl *f_funcDmsCAGetRescanInterval)(DMSWrapper* inObject, slim_int *out_interval);
typedef returnValue(__cdecl *f_funcDmsCASetEnabled)(DMSWrapper* inObject, slim_bool in_enable);
typedef returnValue(__cdecl *f_funcDmsCAIsEnabled)(DMSWrapper* inObject, slim_bool *out_enabled);
typedef returnValue(__cdecl *f_funcDmsCASetDBLocation)(DMSWrapper* inObject, slim_char *in_databaseLocation);
typedef slim_char* (__cdecl *f_funcDmsCAGetDBLocation)(DMSWrapper* inObject);
typedef returnValue(__cdecl *f_funcDmsCASetDBSelectionMode)(DMSWrapper* inObject, dmsCADatabaseSelectionMode in_mode);
typedef returnValue(__cdecl *f_funcDmsCAGetDBSelectionMode)(DMSWrapper* inObject, dmsCADatabaseSelectionMode *out_mode);
typedef returnValue(__cdecl *f_funcDmsCAExecuteCommand)(DMSWrapper* inObject, dmsCACommand in_cmd);
typedef returnValue(__cdecl *f_funcDmsCAGetState)(DMSWrapper* inObject, dmsCAState *out_state);


HINSTANCE hGetProcIDDLL;

DMSWrapper* CreateDMSWrapperClass()
{
	const TCHAR dllName[] = TEXT("dms_dll.dll");
	hGetProcIDDLL = LoadLibrary(dllName);


	if (!hGetProcIDDLL) {
		// log the error: std::cout << "could not load the dynamic library" << std::endl;
		return NULL;
	}

	f_createDmsWrapper funcDmsCreateWrapper = (f_createDmsWrapper)GetProcAddress(hGetProcIDDLL, "CreateDMSWrapperClass");
	if (!funcDmsCreateWrapper) {
		//log the error: std::cout << "could not locate the function" << std::endl;
		return NULL;
	}
	return funcDmsCreateWrapper();
}

void DeleteDMSWrapperClass(DMSWrapper* inObject)
{
	f_funcDeleteDMSWapperClass funcDmsDeleteWrapper = (f_funcDeleteDMSWapperClass)GetProcAddress(hGetProcIDDLL, "DeleteDMSWrapperClass");
	if (funcDmsDeleteWrapper) {
		funcDmsDeleteWrapper(inObject);
	}
}

bool AHLdmsInitialize(DMSWrapper* inObject, dmsInitParams_t *in_params)
{
	bool ret = false;
	f_funcInitialize funcAHLdmsInitialize = (f_funcInitialize)GetProcAddress(hGetProcIDDLL, "AHLdmsInitialize");
	if (!funcAHLdmsInitialize) {
		// log error: std::cout << "could not locate the function" << std::endl;
		return EXIT_FAILURE;
	}
	ret = funcAHLdmsInitialize(inObject, in_params);
	return ret;
}

returnValue AHLdmsStart(DMSWrapper* inObject)
{
	returnValue ret = NFLC_E_ERROR;
	f_funcStart funcAHLdmsStart = (f_funcStart)GetProcAddress(hGetProcIDDLL, "AHLdmsStart");
	if (!funcAHLdmsStart) {
		return ret;
	}
	ret = funcAHLdmsStart(inObject);
	return ret;
}
//
returnValue AHLdmsStop(DMSWrapper* inObject)
{
	returnValue ret = NFLC_E_ERROR;
	f_funcStop funcAHLdmsStop = (f_funcStop)GetProcAddress(hGetProcIDDLL, "AHLdmsStop");
	if (!funcAHLdmsStop) {
		return ret;
	}
	ret = funcAHLdmsStop(inObject);
	return ret;
}
//
bool AHLdmsFinalize(DMSWrapper* inObject)
{
	f_funcFinalize funcAHLdmsFinalize = (f_funcFinalize)GetProcAddress(hGetProcIDDLL, "AHLdmsFinalize");
	if (!funcAHLdmsFinalize) {
		return false;
	}
	funcAHLdmsFinalize(inObject);
	return true;
}

wchar_t* ConvertAnsiToUTF8(slim_char *pLibData)
{	
  if (!pLibData)
    return NULL;
  
  wchar_t *convertedData;
  slim_int convertedDataLength = 0;
  convertedDataLength = MultiByteToWideChar(CP_UTF8, 0, (char*)pLibData, -1, slim_nil, slim_nil);
  if (convertedDataLength > 0){
    convertedData = new wchar_t[convertedDataLength];
    if (convertedData){
      convertedDataLength = MultiByteToWideChar(CP_UTF8, 0, (char*)pLibData, -1, convertedData, convertedDataLength);
    }
  }
  //Free the core library allocated memory
  dlna_memory_free(pLibData);
  return convertedData;
}

slim_char* ConvertUTF8ToAnsi(wchar_t* pExternalData)
{
  if (!pExternalData)
    return NULL;
  slim_int convertedDataLength = 0;
  char *convertedData = slim_nil;
  size_t origsize = wcslen(pExternalData) + 1;
  convertedDataLength = WideCharToMultiByte(CP_UTF8, 0, pExternalData, origsize, slim_nil, slim_nil, slim_nil, slim_nil);
  if (convertedDataLength > 0){
    convertedData = new char[convertedDataLength];
    if (convertedData){
      convertedDataLength = WideCharToMultiByte(CP_UTF8, 0, pExternalData, origsize, convertedData, convertedDataLength, slim_nil, slim_nil);
    }
  }
  return (slim_char*)convertedData;
}

wchar_t* AHLdmsGetFriendlyName(DMSWrapper* inObject)
{
  f_funcGetFriendly funcAHLdmsGetFriendlyName = (f_funcGetFriendly)GetProcAddress(hGetProcIDDLL, "AHLdmsGetFriendlyName");
  if (!funcAHLdmsGetFriendlyName) {
    //log error std::cout << "could not locate the function" << std::endl;
    return 0;
  }
	
  slim_char* sFriedlyName = funcAHLdmsGetFriendlyName(inObject);
  wchar_t *convertedData;
  convertedData = ConvertAnsiToUTF8(sFriedlyName);
  return convertedData;
}

returnValue AHLdmsSetFriendlyName(DMSWrapper* inObject, wchar_t *in_friendlyName)
{
  f_funcSetFriendly funcAHLdmsSetFriendlyName = (f_funcSetFriendly)GetProcAddress(hGetProcIDDLL, "AHLdmsSetFriendlyName");
  if (!funcAHLdmsSetFriendlyName) {
    //log error std::cout << "could not locate the function" << std::endl;
    return NFLC_E_ERROR;
  }

  slim_char* convertedData = ConvertUTF8ToAnsi(in_friendlyName);
  returnValue  ret = funcAHLdmsSetFriendlyName(inObject, convertedData);

  free(convertedData);
  return ret;
}

returnValue AHLdmsPublishStorageAdd(DMSWrapper* inObject, wchar_t *in_path, wchar_t *in_share_name, wchar_t *in_id, dmsStorageDatabaseLocationType in_location_type, slim_bool in_auto_index)
{
  returnValue ret = NFLC_E_ERROR;

  f_funcPublishStorageAdd funcAHLPublishStorageAdd = (f_funcPublishStorageAdd)GetProcAddress(hGetProcIDDLL, "AHLdmsPublishStorageAdd");

  if (!funcAHLPublishStorageAdd) {
    //log error std::cout << "could not locate the function" << std::endl;
    return NFLC_E_ERROR;
  }
  slim_char* convertedAnsiPath = ConvertUTF8ToAnsi(in_path);
  slim_char* convertedAnsiShareName = ConvertUTF8ToAnsi(in_share_name);
  slim_char* convertedAnsiId = ConvertUTF8ToAnsi(in_path);

  ret = funcAHLPublishStorageAdd(inObject, convertedAnsiPath, convertedAnsiShareName, convertedAnsiId, in_location_type, in_auto_index);

  free(convertedAnsiPath);
  free(convertedAnsiShareName);
  free(convertedAnsiId);

  return ret;
}

returnValue AHLdmsPublishStorageRemove(DMSWrapper* inObject, wchar_t *in_path)
{
  returnValue ret = NFLC_E_ERROR;
  f_funcPublishStorageRemove funcAHLPublishStorageRemove = (f_funcPublishStorageRemove)GetProcAddress(hGetProcIDDLL, "AHLdmsPublishStorageRemove");

  if (!funcAHLPublishStorageRemove) {
    //log error std::cout << "could not locate the function" << std::endl;
    return NFLC_E_ERROR;
  }

  slim_char* convertedAnsiPath = ConvertUTF8ToAnsi(in_path);

  ret = funcAHLPublishStorageRemove(inObject, convertedAnsiPath);

  free(convertedAnsiPath);

  return ret;
}

returnValue AHLdmsPublishStorageUpdate(DMSWrapper* inObject, wchar_t *in_path)
{
  returnValue ret = NFLC_E_ERROR;
  f_funcPublishStorageUpdate funcAHLPublishStorageUpdate = (f_funcPublishStorageUpdate)GetProcAddress(hGetProcIDDLL, "AHLdmsPublishStorageUpdate");

  if (!funcAHLPublishStorageUpdate) {
    //log error std::cout << "could not locate the function" << std::endl;
    return NFLC_E_ERROR;
  }

  slim_char* convertedAnsiPath = ConvertUTF8ToAnsi(in_path);

  ret = funcAHLPublishStorageUpdate(inObject, convertedAnsiPath);

  free(convertedAnsiPath);

  return ret;
}

returnValue AHLdmsPublishStorageSetDefaultUploadFolder(DMSWrapper* inObject, wchar_t *in_path)
{
  returnValue ret = NFLC_E_ERROR;
  f_funcPublishSetDefUpload funcAHLPublishSetDefaultUpload = (f_funcPublishSetDefUpload)GetProcAddress(hGetProcIDDLL, "AHLdmsPublishStorageSetDefaultUploadFolder");

  if (!funcAHLPublishSetDefaultUpload) {
    //log error std::cout << "could not locate the function" << std::endl;
    return NFLC_E_ERROR;
  }

  slim_char* convertedAnsiPath = ConvertUTF8ToAnsi(in_path);

  ret = funcAHLPublishSetDefaultUpload(inObject, convertedAnsiPath);

  free(convertedAnsiPath);

  return ret;
}

wchar_t* AHLdmsPublishStorageGetDefaultUploadFolder(DMSWrapper* inObject, slim_char *out_path)
{
  returnValue ret = NFLC_E_ERROR;
  f_funcPublishGetDefUpload funcAHLPublishGetDefaultUpload = (f_funcPublishGetDefUpload)GetProcAddress(hGetProcIDDLL, "AHLdmsPublishStorageGetDefaultUploadFolder");

  if (!funcAHLPublishGetDefaultUpload) {
    //log error std::cout << "could not locate the function" << std::endl;
    return 0;
  }
  ret = funcAHLPublishGetDefaultUpload(inObject, (const slim_char **const)&out_path);
  if (ret != NFLC_E_OK) {
    return NULL;
  }
  return ConvertAnsiToUTF8(out_path);
}

returnValue AHLdmsGetPublishStoragesCount(DMSWrapper* inObject, slim_int *out_count)
{
	returnValue ret = NFLC_E_ERROR;
	f_funcPublishGetStorageCount funcAHLPublishStorageCount = (f_funcPublishGetStorageCount)GetProcAddress(hGetProcIDDLL, "AHLdmsGetPublishStoragesCount");

	if (!funcAHLPublishStorageCount) {
		//log error std::cout << "could not locate the function" << std::endl;
		return NFLC_E_ERROR;
	}
	ret = funcAHLPublishStorageCount(inObject, out_count);
	return ret;
}

returnValue AHLdmsPublishStorageSetStorageCentralDir(DMSWrapper* inObject, wchar_t *in_config_path)
{
  returnValue ret = NFLC_E_ERROR;
  f_funcPublishSetCentralDir funcAHLPublishSetCentralDir = (f_funcPublishSetCentralDir)GetProcAddress(hGetProcIDDLL, "AHLdmsPublishStorageSetStorageCentralDir");

  if (!funcAHLPublishSetCentralDir) {
    //log error std::cout << "could not locate the function" << std::endl;
    return NFLC_E_ERROR;
  }

  slim_char* convertedAnsiPath = ConvertUTF8ToAnsi(in_config_path);

  ret = funcAHLPublishSetCentralDir(inObject, convertedAnsiPath);

  free(convertedAnsiPath);
  return ret;
}

wchar_t* AHLdmsGetPublishStorages(DMSWrapper* inObject, XMLBuffer out_storages)
{
  returnValue ret = NFLC_E_ERROR;
  f_funcPublishGetStorages funcAHLPublishGetStorages = (f_funcPublishGetStorages)GetProcAddress(hGetProcIDDLL, "AHLdmsGetPublishStorages");
  if (!funcAHLPublishGetStorages) {
    //log error std::cout << "could not locate the function" << std::endl;
    return 0;
  }
  ret = funcAHLPublishGetStorages(inObject, &out_storages);
  if (ret != NFLC_E_OK) {
    return NULL;
  }
  return ConvertAnsiToUTF8(out_storages);
}

returnValue AHLdmsGetServerState(DMSWrapper* inObject, dmsState *out_server_state)
{
	returnValue ret = NFLC_E_ERROR;
	f_funcGetServerState funcAHLGetServerState = (f_funcGetServerState)GetProcAddress(hGetProcIDDLL, "AHLdmsGetServerState");

	if (!funcAHLGetServerState) {
		//log error std::cout << "could not locate the function" << std::endl;
		return NFLC_E_ERROR;
	}
	ret = funcAHLGetServerState(inObject, out_server_state);
	return ret;
}

returnValue AHLdmsSetServerState(DMSWrapper* inObject, dmsState in_server_state)
{
	returnValue ret = NFLC_E_ERROR;
	f_funcSetServerState funcAHLSetServerState = (f_funcSetServerState)GetProcAddress(hGetProcIDDLL, "AHLdmsSetServerState");

	if (!funcAHLSetServerState) {
		//log error std::cout << "could not locate the function" << std::endl;
		return NFLC_E_ERROR;
	}
	ret = funcAHLSetServerState(inObject, in_server_state);
	return ret;
}


returnValue AHLdmsGetTotalContentsShared(DMSWrapper* inObject, dmsContentClassType in_type, slim_int *out_result)
{
	returnValue ret = NFLC_E_ERROR;
	f_funcGetTotalContentShared funcAHLGetTotalContentShared = (f_funcGetTotalContentShared)GetProcAddress(hGetProcIDDLL, "AHLdmsGetTotalContentsShared");
	if (!funcAHLGetTotalContentShared) {
		// log error std::cout << "could not locate the function" << std::endl;
		return NFLC_E_ERROR;
	}
	ret = funcAHLGetTotalContentShared(inObject, in_type, out_result);
	return ret;
}

wchar_t* AHLdmsGetDeviceDescription(DMSWrapper* inObject, XMLBuffer out_deviceDescription)
{
  returnValue ret = NFLC_E_ERROR;
  f_funcGetDeviceDescription funcAHLGetDeviceDecp = (f_funcGetDeviceDescription)GetProcAddress(hGetProcIDDLL, "AHLdmsGetDeviceDescription");
  if (!funcAHLGetDeviceDecp) {
    // log the error std::cout << "could not locate the function" << std::endl;
    return 0;
  }
  ret = funcAHLGetDeviceDecp(inObject, &out_deviceDescription);
  if (ret != NFLC_E_OK) {
    return NULL;
  }
  return ConvertAnsiToUTF8(out_deviceDescription);
}

returnValue AHLdmsRefreshContentIndex(DMSWrapper* inObject)
{
	returnValue ret = NFLC_E_ERROR;
	f_funcRefreshContentIndex funcAHLRefreshContentIndex = (f_funcRefreshContentIndex)GetProcAddress(hGetProcIDDLL, "AHLdmsRefreshContentIndex");
	if (!funcAHLRefreshContentIndex) {
		// log the error std::cout << "could not locate the function" << std::endl;
		return NFLC_E_ERROR;
	}
	ret = funcAHLRefreshContentIndex(inObject);
	return ret;
}

wchar_t* AHLdmsGetContentTree(DMSWrapper* inObject, wchar_t *in_containerID, slim_int in_startIndex, slim_int in_requestedCount, XMLBuffer out_buf)
{
  returnValue ret = NFLC_E_ERROR;
  f_funcGetContentTree funcAHLGetContentTree = (f_funcGetContentTree)GetProcAddress(hGetProcIDDLL, "AHLdmsGetContentTree");
  if (!funcAHLGetContentTree) {
    return 0;
  }
  
  slim_char* convertedContainerID = ConvertUTF8ToAnsi(in_containerID);
  ret = funcAHLGetContentTree(inObject, convertedContainerID, in_startIndex, in_requestedCount, &out_buf);

  free(convertedContainerID);

  if (ret != NFLC_E_OK) {
    return NULL;
  }
  return ConvertAnsiToUTF8(out_buf);
}

returnValue AHLdmsSetContentShare(DMSWrapper* inObject, wchar_t *in_contentID, slim_bool in_share, slim_bool in_recusive)
{
  returnValue ret = NFLC_E_ERROR;
  f_funcSetContentShare funcAHLSetContentShare = (f_funcSetContentShare)GetProcAddress(hGetProcIDDLL, "AHLdmsSetContentShare");
  if (!funcAHLSetContentShare) {
    return NFLC_E_ERROR;
  }

  slim_char* convertedContainerID = ConvertUTF8ToAnsi(in_contentID);

  ret = funcAHLSetContentShare(inObject, convertedContainerID, in_share, in_recusive);

  free(convertedContainerID);

  return ret;
}

wchar_t* AHLdmsGetSupportedLanguages(DMSWrapper* inObject, XMLBuffer out_languages)
{
  returnValue ret = NFLC_E_ERROR;
  f_funcGetSupportedLang funcAHLGetSuppLang = (f_funcGetSupportedLang)GetProcAddress(hGetProcIDDLL, "AHLdmsGetSupportedLanguages");
  if (!funcAHLGetSuppLang) {
    return 0;
  }
  ret = funcAHLGetSuppLang(inObject, &out_languages);
  if (ret != NFLC_E_OK) {
    return NULL;
  }
  return ConvertAnsiToUTF8(out_languages);
}

returnValue AHLdmsSetLanguage(DMSWrapper* inObject, wchar_t* in_language)
{
  returnValue ret = NFLC_E_ERROR;
  f_funcSetLanguage funcAHLSetLanguage = (f_funcSetLanguage)GetProcAddress(hGetProcIDDLL, "AHLdmsSetLanguage");
  if (!funcAHLSetLanguage) {
    return NFLC_E_ERROR;
  }

  slim_char* convertedLanguage = ConvertUTF8ToAnsi(in_language);

  ret = funcAHLSetLanguage(inObject, convertedLanguage);

  free(convertedLanguage);

  return ret;
}

wchar_t* AHLdmsGetSelectedLanguage(DMSWrapper* inObject, XMLBuffer out_language)
{
  returnValue ret = NFLC_E_ERROR;
  f_funcGetSelectedLang funcAHLGetSelectedLang = (f_funcGetSelectedLang)GetProcAddress(hGetProcIDDLL, "AHLdmsGetSelectedLanguage");
  if (!funcAHLGetSelectedLang) {
    return 0;
  }
  ret = funcAHLGetSelectedLang(inObject, &out_language);
  if (ret != NFLC_E_OK) {
    return NULL;
  }
  return ConvertAnsiToUTF8(out_language);
}

wchar_t* AHLdmsBrowseContent(DMSWrapper* inObject, wchar_t* in_id, XMLBuffer out_response_doc, slim_word start_index, slim_word request_count)
{
  returnValue ret = NFLC_E_ERROR;
  f_funcDmsBrowseContent funcAHLBrowseContent = (f_funcDmsBrowseContent)GetProcAddress(hGetProcIDDLL, "AHLdmsBrowseContent");
  if (!funcAHLBrowseContent) {
    return 0;
  }

  slim_char* ConvertedId = ConvertUTF8ToAnsi(in_id);
  ret = funcAHLBrowseContent(inObject, ConvertedId, &out_response_doc, start_index, request_count);
  free(ConvertedId);
  if (ret != NFLC_E_OK) {
    return NULL;
  }
  return ConvertAnsiToUTF8(out_response_doc);
}

wchar_t* AHLdmsSearchContent(DMSWrapper* inObject, wchar_t* in_id, wchar_t *criteria, XMLBuffer out_response_doc, slim_word start_index, slim_word request_count)
{
  returnValue ret = NFLC_E_ERROR;
  f_funcDmsSearchContent funcAHLSearchContent = (f_funcDmsSearchContent)GetProcAddress(hGetProcIDDLL, "AHLdmsSearchContent");
  if (!funcAHLSearchContent) {
    return 0;
  }

  slim_char* ConvertedId = ConvertUTF8ToAnsi(in_id);
  slim_char* ConvertedCriteria = ConvertUTF8ToAnsi(in_id);

  ret = funcAHLSearchContent(inObject, ConvertedId, ConvertedCriteria, &out_response_doc, start_index, request_count);

  free(ConvertedId);
  free(ConvertedCriteria);

  if (ret != NFLC_E_OK) {
    return NULL;
  }
  return ConvertAnsiToUTF8(out_response_doc);
}


returnValue AHLdmsPGGetDefaultLevel(DMSWrapper* inObject, dmsPGLevelType in_levelType, slim_int *out_level)
{
	returnValue ret = NFLC_E_ERROR;
	f_funcDmsPGGetDefaultLevel funcAHLGetefualtLevel = (f_funcDmsPGGetDefaultLevel)GetProcAddress(hGetProcIDDLL, "AHLdmsPGGetDefaultLevel");
	if (!funcAHLGetefualtLevel) {
		//log the error std::cout << "could not locate the function" << std::endl;
		return NFLC_E_ERROR;
	}
	ret = funcAHLGetefualtLevel(inObject, in_levelType, out_level);
	return ret;
}

returnValue AHLdmsPGSetDefaultDeviceLevel(DMSWrapper* inObject, dmsPGLevelType in_levelType, slim_int in_newDefaultLevel)
{
	returnValue ret = NFLC_E_ERROR;
	f_funcDmsPGSetDefaultLevel funcAHLSetefualtLevel = (f_funcDmsPGSetDefaultLevel)GetProcAddress(hGetProcIDDLL, "AHLdmsPGSetDefaultLevel");
	if (!funcAHLSetefualtLevel) {
		//log the error std::cout << "could not locate the function" << std::endl;
		return NFLC_E_ERROR;
	}
	ret = funcAHLSetefualtLevel(inObject, in_levelType, in_newDefaultLevel);
	return ret;
}

returnValue AHLdmsPGSetContentLevel(DMSWrapper* inObject, wchar_t *in_contentID, slim_int in_level)
{
  returnValue ret = NFLC_E_ERROR;
  f_funcDmsPGSetContentLevel funcAHLSetContentLevel = (f_funcDmsPGSetContentLevel)GetProcAddress(hGetProcIDDLL, "AHLdmsPGSetContentLevel");
  if (!funcAHLSetContentLevel) {
    return NFLC_E_ERROR;
  }
  slim_char* ConvertedContentId = ConvertUTF8ToAnsi(in_contentID);
  ret = funcAHLSetContentLevel(inObject, ConvertedContentId, in_level);
  free(ConvertedContentId);

  return ret;
}

wchar_t* AHLdmsPGGetDeviceList(DMSWrapper* inObject, XMLBuffer out_PGDeviceList)
{
  returnValue ret = NFLC_E_ERROR;
  f_funcDmsPGGetDeviceList funcAHLGetDeviceList = (f_funcDmsPGGetDeviceList)GetProcAddress(hGetProcIDDLL, "AHLdmsPGGetDeviceList");
  if (!funcAHLGetDeviceList) {
    return 0;
  }
  ret = funcAHLGetDeviceList(inObject, &out_PGDeviceList);
  if (ret != NFLC_E_OK) {
    return NULL;
  }
  return ConvertAnsiToUTF8(out_PGDeviceList);
}

wchar_t* AHLdmsPGGetLevelList(DMSWrapper* inObject, XMLBuffer out_PGLevelList)
{
  returnValue ret = NFLC_E_ERROR;
  f_funcDmsPGGetLevelList funcAHLGetLevelList = (f_funcDmsPGGetLevelList)GetProcAddress(hGetProcIDDLL, "AHLdmsPGGetLevelList");
  if (!funcAHLGetLevelList) {
    return 0;
  }
  ret = funcAHLGetLevelList(inObject, &out_PGLevelList);
  if (ret != NFLC_E_OK) {
    return NULL;
  }
  return ConvertAnsiToUTF8(out_PGLevelList);
}

returnValue AHLdmsPGSetDeviceParams(DMSWrapper* inObject, wchar_t *in_deviceMAC, slim_int in_level, wchar_t *in_description)
{
  returnValue ret = NFLC_E_ERROR;
  f_funcDmsPGSetDeviceParams funcAHLSetDeviceParams = (f_funcDmsPGSetDeviceParams)GetProcAddress(hGetProcIDDLL, "AHLdmsPGSetDeviceParams");
  if (!funcAHLSetDeviceParams) {
    return NFLC_E_ERROR;
  }

  slim_char* ConvertedDeviceMAC = ConvertUTF8ToAnsi(in_deviceMAC);
  slim_char* ConvertedDescription = ConvertUTF8ToAnsi(in_description);

  ret = funcAHLSetDeviceParams(inObject, ConvertedDeviceMAC, &in_level, ConvertedDescription);

  free(ConvertedDeviceMAC);
  free(ConvertedDescription);

  return ret;
}

returnValue AHLdmsPGDeleteDeviceByMac(DMSWrapper* inObject, wchar_t *in_deviceMAC)
{
  returnValue ret = NFLC_E_ERROR;
  f_funcDmsPGDeleteDeviceByMac funcAHLDeleteDeviceByMac = (f_funcDmsPGDeleteDeviceByMac)GetProcAddress(hGetProcIDDLL, "AHLdmsPGDeleteDeviceByMac");
  if (!funcAHLDeleteDeviceByMac) {
    return NFLC_E_ERROR;
  }
  slim_char* ConvertedDeviceMAC = ConvertUTF8ToAnsi(in_deviceMAC);
  ret = funcAHLDeleteDeviceByMac(inObject, ConvertedDeviceMAC);
  free(ConvertedDeviceMAC);
  return ret;
}

returnValue AHLdmsCASetDefaultIndexing(DMSWrapper* inObject, dmsCAIndex in_index)
{
	returnValue ret = NFLC_E_ERROR;
	f_funcDmsCASetDefaultIndexing funcDmsCASetDefaultIndexing = (f_funcDmsCASetDefaultIndexing)GetProcAddress(hGetProcIDDLL, "AHLdmsCASetDefaultIndexing");
	if (!funcDmsCASetDefaultIndexing) {
		//log the error std::cout << "could not locate the function" << std::endl;
		return NFLC_E_ERROR;
	}
	ret = funcDmsCASetDefaultIndexing(inObject, in_index);
	return ret;
}

returnValue AHLdmsCAGetDefaultIndexing(DMSWrapper* inObject, dmsCAIndex *out_enable)
{
	returnValue ret = NFLC_E_ERROR;
	f_funcDmsCAGetDefaultIndexing funcDmsCAGetDefaultIndexing = (f_funcDmsCAGetDefaultIndexing)GetProcAddress(hGetProcIDDLL, "AHLdmsCAGetDefaultIndexing");
	if (!funcDmsCAGetDefaultIndexing) {
		//log the error std::cout << "could not locate the function" << std::endl;
		return NFLC_E_ERROR;
	}
	ret = funcDmsCAGetDefaultIndexing(inObject, out_enable);
	return ret;
}

returnValue AHLdmsCAGetDeviceList(DMSWrapper* inObject, XMLBuffer *out_CADeviceList)
{
	returnValue ret = NFLC_E_ERROR;
	f_funcDmsCAGetDeviceList funcDmsCAGetDeviceList = (f_funcDmsCAGetDeviceList)GetProcAddress(hGetProcIDDLL, "AHLdmsCAGetDeviceList");
	if (!funcDmsCAGetDeviceList) {
		//log the error std::cout << "could not locate the function" << std::endl;
		return NFLC_E_ERROR;
	}
	ret = funcDmsCAGetDeviceList(inObject, out_CADeviceList);
	return ret;
}

returnValue AHLdmsCASetDeviceIndexing(DMSWrapper* inObject, slim_char *in_uuid, dmsCAIndex in_index)
{
	returnValue ret = NFLC_E_ERROR;
	f_funcDmsCASetDeviceIndexing funcDmsCASetDeviceIndexing = (f_funcDmsCASetDeviceIndexing)GetProcAddress(hGetProcIDDLL, "AHLdmsCASetDeviceIndexing");
	if (!funcDmsCASetDeviceIndexing) {
		//log the error std::cout << "could not locate the function" << std::endl;
		return NFLC_E_ERROR;
	}
	ret = funcDmsCASetDeviceIndexing(inObject, in_uuid, in_index);
	return ret;
}

returnValue AHLdmsCASetDatabaseSizeLimit(DMSWrapper* inObject, slim_int in_size)
{
	returnValue ret = NFLC_E_ERROR;
	f_funcDmsCASetDatabaseSizeLimit funcDmsCASetDatabaseSizeLimit = (f_funcDmsCASetDatabaseSizeLimit)GetProcAddress(hGetProcIDDLL, "AHLdmsCASetDatabaseSizeLimit");
	if (!funcDmsCASetDatabaseSizeLimit) {
		//log the error std::cout << "could not locate the function" << std::endl;
		return NFLC_E_ERROR;
	}
	ret = funcDmsCASetDatabaseSizeLimit(inObject, in_size);
	return ret;
}

returnValue AHLdmsCAGetDatabaseSizeLimit(DMSWrapper* inObject, slim_int *out_size)
{
	returnValue ret = NFLC_E_ERROR;
	f_funcDmsCAGetDatabaseSizeLimit funcDmsCAGetDatabaseSizeLimit = (f_funcDmsCAGetDatabaseSizeLimit)GetProcAddress(hGetProcIDDLL, "AHLdmsCAGetDatabaseSizeLimit");
	if (!funcDmsCAGetDatabaseSizeLimit) {
		//log the error std::cout << "could not locate the function" << std::endl;
		return NFLC_E_ERROR;
	}
	ret = funcDmsCAGetDatabaseSizeLimit(inObject, out_size);
	return ret;
}

returnValue AHLdmsCASetPurgeInterval(DMSWrapper* inObject, slim_int in_interval)
{
	returnValue ret = NFLC_E_ERROR;
	f_funcDmsCASetPurgeInterval funcDmsCASetPurgeInterval = (f_funcDmsCASetPurgeInterval)GetProcAddress(hGetProcIDDLL, "AHLdmsCASetPurgeInterval");
	if (!funcDmsCASetPurgeInterval) {
		//log the error std::cout << "could not locate the function" << std::endl;
		return NFLC_E_ERROR;
	}
	ret = funcDmsCASetPurgeInterval(inObject, in_interval);
	return ret;
}

returnValue AHLdmsCAGetPurgeInterval(DMSWrapper* inObject, slim_int *out_enable)
{
	returnValue ret = NFLC_E_ERROR;
	f_funcDmsCAGetPurgeInterval funcDmsCAGetPurgeInterval = (f_funcDmsCAGetPurgeInterval)GetProcAddress(hGetProcIDDLL, "AHLdmsCAGetPurgeInterval");
	if (!funcDmsCAGetPurgeInterval) {
		//log the error std::cout << "could not locate the function" << std::endl;
		return NFLC_E_ERROR;
	}
	ret = funcDmsCAGetPurgeInterval(inObject, out_enable);
	return ret;
}

returnValue AHLdmsCASetRescanInterval(DMSWrapper* inObject, slim_int in_interval)
{
	returnValue ret = NFLC_E_ERROR;
	f_funcDmsCASetRescanInterval funcDmsCASetRescanInterval = (f_funcDmsCASetRescanInterval)GetProcAddress(hGetProcIDDLL, "AHLdmsCASetRescanInterval");
	if (!funcDmsCASetRescanInterval) {
		//log the error std::cout << "could not locate the function" << std::endl;
		return NFLC_E_ERROR;
	}
	ret = funcDmsCASetRescanInterval(inObject, in_interval);
	return ret;
}

returnValue AHLdmsCAGetRescanInterval(DMSWrapper* inObject, slim_int *out_enable)
{
	returnValue ret = NFLC_E_ERROR;
	f_funcDmsCAGetRescanInterval funcDmsCAGetRescanInterval = (f_funcDmsCAGetRescanInterval)GetProcAddress(hGetProcIDDLL, "AHLdmsCAGetRescanInterval");
	if (!funcDmsCAGetRescanInterval) {
		//log the error std::cout << "could not locate the function" << std::endl;
		return NFLC_E_ERROR;
	}
	ret = funcDmsCAGetRescanInterval(inObject, out_enable);
	return ret;
}

returnValue AHLdmsCASetEnabled(DMSWrapper* inObject, slim_bool in_enable)
{
	returnValue ret = NFLC_E_ERROR;
	f_funcDmsCASetEnabled funcDmsCASetEnabled = (f_funcDmsCASetEnabled)GetProcAddress(hGetProcIDDLL, "AHLdmsCASetEnabled"); 
	if (!funcDmsCASetEnabled) {
		//log the error std::cout << "could not locate the function" << std::endl;
		return NFLC_E_ERROR;
	}
	ret = funcDmsCASetEnabled(inObject, in_enable);
	return ret;
}

returnValue AHLdmsCAIsEnabled(DMSWrapper* inObject, slim_bool *out_enabled)
{
	returnValue ret = NFLC_E_ERROR;
	f_funcDmsCAIsEnabled funcDmsCAIsEnabled = (f_funcDmsCAIsEnabled)GetProcAddress(hGetProcIDDLL, "AHLdmsCAIsEnabled");
	if (!funcDmsCAIsEnabled) {
		//log the error std::cout << "could not locate the function" << std::endl;
		return NFLC_E_ERROR;
	}
	ret = funcDmsCAIsEnabled(inObject, out_enabled);
	return ret;
}

returnValue AHLdmsCASetDBLocation(DMSWrapper* inObject, wchar_t *in_databaseLocation)
{
  returnValue ret = NFLC_E_ERROR;
  f_funcDmsCASetDBLocation funcDmsCASetDBLocation = (f_funcDmsCASetDBLocation)GetProcAddress(hGetProcIDDLL, "AHLdmsCASetDBLocation");
  if (!funcDmsCASetDBLocation) {
    return NFLC_E_ERROR;
  }
  slim_char* convertedData = ConvertUTF8ToAnsi(in_databaseLocation);
  ret = funcDmsCASetDBLocation(inObject, convertedData);
  free(convertedData);
  return ret;
}
 
wchar_t* AHLdmsCAGetDBLocation(DMSWrapper* inObject)
{
  slim_char *dbLocation = slim_nil;
  wchar_t *convertedData = NULL;
  f_funcDmsCAGetDBLocation funcDmsCAGetDBLocation = (f_funcDmsCAGetDBLocation)GetProcAddress(hGetProcIDDLL, "AHLdmsCAGetDBLocation");
  if (!funcDmsCAGetDBLocation) {
    return convertedData;
  }

  dbLocation = funcDmsCAGetDBLocation(inObject);
  convertedData = ConvertAnsiToUTF8(dbLocation);
  return convertedData;
}

returnValue AHLdmsCASetDBSelectionMode(DMSWrapper* inObject, dmsCADatabaseSelectionMode in_mode)
{
  returnValue ret = NFLC_E_ERROR;
  f_funcDmsCASetDBSelectionMode funcDmsCASetDBSelectionMode = (f_funcDmsCASetDBSelectionMode)GetProcAddress(hGetProcIDDLL, "AHLdmsCASetDBSelectionMode");
  if (!funcDmsCASetDBSelectionMode) {
    return NFLC_E_ERROR;
  }
  ret = funcDmsCASetDBSelectionMode(inObject, in_mode);
  return ret;
}

returnValue AHLdmsCAGetDBSelectionMode(DMSWrapper* inObject, dmsCADatabaseSelectionMode *out_mode)
{
	returnValue ret = NFLC_E_ERROR;
	f_funcDmsCAGetDBSelectionMode funcDmsCAGetDBSelectionMode = (f_funcDmsCAGetDBSelectionMode)GetProcAddress(hGetProcIDDLL, "AHLdmsCAGetDBSelectionMode");
	if (!funcDmsCAGetDBSelectionMode) {
		//log the error std::cout << "could not locate the function" << std::endl;
		return NFLC_E_ERROR;
	}
	ret = funcDmsCAGetDBSelectionMode(inObject, out_mode);
	return ret;
}

returnValue AHLdmsCAExecuteCommand(DMSWrapper* inObject, dmsCACommand in_cmd)
{
	returnValue ret = NFLC_E_ERROR;
	f_funcDmsCAExecuteCommand funcDmsCAExecuteCommand = (f_funcDmsCAExecuteCommand)GetProcAddress(hGetProcIDDLL, "AHLdmsCAExecuteCommand");
	if (!funcDmsCAExecuteCommand) {
		//log the error std::cout << "could not locate the function" << std::endl;
		return NFLC_E_ERROR;
	}
	ret = funcDmsCAExecuteCommand(inObject, in_cmd);
	return ret;
}

returnValue AHLdmsCAGetState(DMSWrapper* inObject, dmsCAState *out_state)
{
	returnValue ret = NFLC_E_ERROR;
	f_funcDmsCAGetState funcDmsCAGetState = (f_funcDmsCAGetState)GetProcAddress(hGetProcIDDLL, "AHLdmsCAGetState");
	if (!funcDmsCAGetState) {
		//log the error std::cout << "could not locate the function" << std::endl;
		return NFLC_E_ERROR;
	}
	ret = funcDmsCAGetState(inObject, out_state);
	return ret;
}
