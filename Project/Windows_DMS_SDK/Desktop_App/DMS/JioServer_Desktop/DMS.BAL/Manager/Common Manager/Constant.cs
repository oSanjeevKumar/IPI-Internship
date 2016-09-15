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

 
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DMS.BAL.Manager.Common_Manager
{
    public class Constant
    {
        #region "Decaraion"

        #region "common"
        
        public const string SLASH_SIGN = "\\";
        public const string COMMA_SIGN = ",";
        public const string WARNING = "Warning";
        public const string NFLC_XML = "nflc_xml";
        public const string DMS_DATA = "dms_data";
        public const int UPNP_PORT = 2871;
        public const int DRIVE_LENGTH = 3;
        public const string DEFAULT_UPLOAD_FOLDER = "DEFAULT_UPLOAD_FOLDER";
        public const string COLOR_CODE_VLIDATATION_REMOVAL = "#C8C8C8";
        public const string COLOR_CODE_VLIDATATION = "#FFFF0000";
        public const string FIRST_INITLIZE_PROPERTY = "IsFirstinitialize";
        public const string STRING_EMPTY = "";
        public const string STRING_COLON = ":";

        public const string STRING_SPACE = " ";
        public const string STRING_DES = "-";
        public const string STRING_ZERO = "0";
        public const string ROUND_START_BRACKET = "(";
        public const string ROUND_END_BRACKET = ")";
        public const Char DirectorySeparatorChar = '\\';

        public const string INDEXING_STARTED_IMAGE = "..\\Images\\indexingInProgress.png"; // indexing started image
        public const string INDEXING_DONE_IMAGE = "..\\Images\\indexingDone.png"; // indexing done image
        public const string INDEXING_ERROR_IMAGE = "..\\Images\\indexingStopped.png"; // indexing stopped image
        public const string INDEXING_NOTSTARTED_IMAGE = "..\\Images\\indexingNotStarted.png"; // indexing not started image

        public const string INDEXING_LEVEL_FILESCAN = "0";
        public const string INDEXING_LEVEL_METADATA = "1";
        public const string INDEXING_LEVEL_REFERENCES = "2";
        public const string INDEXING_LEVEL_UNKNOWN = "3";


        public const string INDEXING_STATE_STARTED = "0";
        public const string INDEXING_STATE_DONE = "1";
        public const string INDEXING_STATE_ABORTED = "2";

        public const string CONTENT_PARTIAL_INDEXING_SHARE = "0";
        public const string CONTENT_PARTIAL_INDEXING_PG = "1";
        public const string CONTENT_PARTIAL_INDEXING_UNKNOWN = "2";

        #endregion

        //#region "AddSharedFolder"

        //public const string DRIVE_WARNING = "You Cannot Share Drive.";
        //public const string PGLEVEL_UPDATE_ERROR = "Error in saving PG Level.";

        //#endregion

        #region "SharedUserControl"
        public const string SHARE_FOLDER_ERROR = "Can't share:";
        public const string ERROR_FOLDER_ALREADY_SHARED = "already shared";
        public const string SHARED_USERCONTROL_CLASSNAME = "SharedUserControl";
        public const string MENU_TREEFOLDER_CLICKED_METHODNAME = "MenuTreeFolder_Clicked";
        public const string SHARED_INITIALIZE_FORM_METHODNAME = "initializeForm";
        public const string SHARED_DEVICETHREAD_FORM_METHODNAME = "DeviceThreadCall";
        public const string PGLEVEL_MENU_NAME_PREFIX = "mi";
        public const string SHARE_FOLDER_MESSAGE = "Folder shared successfully";
        public const string SHARE_DRIVE_MESSAGE = "Drive shared successfully";
        public const string SHARE_DRIVE_ERROR = "Can't share";
        public const string ERROR_UNSHARE_FOLDER = "Failed to remove share on:";
        public const string DEVICE_PGLEVEL_UPDATE_ERROR = "Failed to set Parental Guidance level:";
        public const string FOLDER_PGLEVEL_UPDATE_ERROR = "Failed to set Parental Guidance level:";
        public const string SHARE_DRIVE_LIMIT_ERROR = "Maximum storage limit 50 reached sharing not allowed";

        public const string DEVICE_PGLEVEL_UPDATE_SUCCESS = "Device PG Level updated successfully";
        public const string FOLDER_PGLEVEL_UPDATE_SUCCESS = "Folder PG Level updated successfully";
        public const string UPLOAD_FOLDER_NOT_SET = "Can't set upload folder since there are no shared folders.";
        public const string UPLOAD_FOLDER_FAILED = "Failed to get upload folder path, please check write permission of shared folder/s";
        public const string UPLOAD_FOLDER_NOT_WRITABLE = "Shared folder is not writable. Can't set it up for upload";
        //  public const string SHARE_FOLDER_UNSHARE_MESSAGE = "Folder unShared successfully";
        public const string UNPUBLISH_FOLDER = "Unsharing folder..";
        public const string PUBLISH_FOLDER = "Sharing folder..";
        public const string SETTING_DEVICE_PGLEVEL = "Setting device PG level..";
        public const string SETTING_FOLDER_PGLEVEL = "Setting folder PG level..";
        public const string PLEASE_WAIT = "Please wait..";
        public const string DEVICE_SHARE_CONFIRMATION = "New storage device detected";
        public const string DEVICE_SHARE_CONFIRMATION_MESSAGE = "Share media on this device?";
        public const string QUESTION_MARK = "?";
        public const string PUBLISH_DRIVE = "Sharing drive : ";
        public const string UNPUBLISH_DRIVE = "Unsharing drive : ";
        public const string SUB_FOLDER_UNSHARE = "Subfolder Unshared :";
        public const string BLOCK_DEVICE = "Blocked device";
        public const string STRING_DOT = ".";
        public const string SUCCESS_DRIVE_UNSHARE = "Storage device disconnected. Not sharing media anymore";
        public const string Application_DISPATCHEUNHANDLEEXCEPTION_METHODNAME = "Application_DispatcherUnhandledException";
        public const string SHAREDUSERCONTROL_EXTERNALDEVICEARRIVED_METHODNAME = "ExternalDeviceEventArrived";
        public const string Application_LogUnhandledException_METHODNAME = "LogUnhandledException";
        public const string Application_STARTUP_CLASSNAME = "Application_DispatcherUnhandledException";
        public const string UPNPCLASS_CONTAINER = "object.container";
        public const string AddShareFolders_Click = "AddShareFolders_Click";
        public const string UNSHARE_SUCCESSFULLY = "Unshared successfully :";
        public const string WARN_SHARING_ROOT_FOLDER = "Sharing a root directory is not recommended.";
        public const string DEVICE_REMOVE_CONFIRMATION = "Would you like to delete the devices(s) from the list?";
        #endregion

        #region "configuration
        public const string FUNC_NAME_DMS_AHLdmsStart = "DMS_AHLdmsStart";
        public const string FUNC_NAME_DMS_AHLdmsStop = "DMS_AHLdmsStop";

        public const string CONFIG_SAVE = "Configuration saved";
        public const string CONFIG_SAVE_ERROR = "Something went wrong while saving configurations.";
        public const string CHILD_FOLDER_SHARE_ERROR = "Unshared child folder,";
        public const string PARENT_FOLDER_SHARE_ERROR = "Parent folder already shared : ";
        public const string SAME_FOLDER_SHARE_ERROR = "Folder already shared";
        public const string ERROR_DMS_INITIALIZE = "Media sharing is disabled. Please enable it and continue.";
        public const string CONFIG_PROCESS = "Saving configuration..";
        public const string DEVICE_EMPTY = "Your media server must have a name!";
        public const string DEVICE_PGLEVEL = "Please Select PGlevel for Device.";
        public const string FOLDER_PGLEVEL = "Please Select PGlevel for Folder.";
        public const string DISPLAY_PATH_PROPERTY = "FolderName";
        public const string SERVICE_START ="Starting service..";
        public const string SERVICE_STOP = "Stoping service..";
        public const string SERVICE_START_ERROR = "Failed to start Media Share. Please try again.";
        public const string DEVICE_EXCEED = "Your media server name is too long. Please limit it to 128 characters.";

        public const string SSERVICEON_METHOD_NAME = "rdbtnServiceOn_Checked";
        public const string SSERVICEOFF_METHOD_NAME = "rdbtnServiceOff_Checked";
        #endregion

        #region "XMLManager"

        public const string XMLManager_CLASSNAME = "XMLManager";

        //FUNCTION NAME 
        public const string FUNC_NAME_readDeviceXml = "readDeviceXml";
        public const string FUNC_NAME_readPGLevelXml = "readPGLevelXml";
        public const string FUNC_NAME_readShareFolderXml = "readShareFolderXml";
        public const string FUNC_NAME_readIndexingCallbackResult = "readIndexingCallbackResult";
        public const string FUNC_NAME_readShareFolderPGLevel = "readShareFolderPGLevel";
        public const string FUNC_NAME_getconfigValue = "getConfigValue";
        public const string FUNC_NAME_writeConfigValue = "WriteConfigXML";

        //DEVICE
        public const string DEVICE_PARENT_NODE = "//parentalGuidanceDeviceList//device";
        public const string DEVICE_MAC_ADDRESS = "mac_address";
        public const string DEVICE_IP_ADDRESS = "ip_address";
        public const string DEVICE_DESCRIPTION = "device_description";
        public const string DEVICE_LEVEL = "level";
        public const string DEVICE_FRIENDLY_NAME = "friendly_name";

        //PGLEVEL
        public const string PGLEVEL_PARENT_NODE = "//parentalGuidanceLevelList//level";
        public const string PGLEVEL_ID = "id";
        public const string PGLEVEL_NAME = "name";
        public const string PGLEVEL_DESCRIPTION = "description";

        //SHAREFOLDER
        public const string SHAREFOLDER_PARENT_NODE = "//nflc//storage";
        public const string SHAREFOLDER_NAME = "name";
        public const string SHAREFOLDER_PATH = "path";

        public const string SHAREFOLDER_CONTAINER = "//content//container";
        public const string SHAREFOLDER_ITEM = "//content//item";
        public const string SHAREFOLDER_CONTENT = "//content";
        public const string SHAREFOLDER_ID = "id";
        public const string SHAREFOLDER_TITLE = "dc:title";
        public const string SHARE_PGLEVEL = "pgLevel";

        public const string CONFIG_FILE_NAME = "Config.xml";
        public const string CONFIG_CLASS_NAME = "Config.cs";
        public const string SERVICE_STATE = "ServiceState";
        public const string CA_SERVICE_STATE = "CAServiceState";
        public const string CA_RUNNING_STATE = "CARunningState";
        public const string DMS_START_ERROR = "Starting DMS failed";
        public const string DMS_STOP_ERROR = "Stopping DMS failed";
        public const string CA_ENABLE_ERROR = "Enabling Content Aggregation failed";
        public const string CA_DISABLE_ERROR = "Disabling Content Aggregation failed";
        public const string CA_PAUSE_RESUME_ERROR = "Pause/Resume of Content Aggregation failed";
        public const string IS_LOG_ENABLE = "IsLogEnable";        
        public const string IS_FIRST_TIME_INITIALIZE = "IsFirstinitialize";
        public const bool CA_RESUME_ENABLE = true;
        public const bool CA_PAUSE_ENABLE = false;
        public const bool CA_ENABLE = true;
        public const bool CA_DISABLE = false;

        #endregion

        #region "ServiceManager"

        public const string ServiceManager_CLASSNAME = "ServiceManager";

        //FUNCTION NAME 
        public const string FUNC_NAME_DMS_CreateDMSWrapperClass = "DMS_CreateDMSWrapperClass";
        public const string FUNC_NAME_DMS_AHLdmsInitialize = "DMS_AHLdmsInitialize";
        public const string FUNC_NAME_DMS_DeleteDMSWrapperClass = "DMS_DeleteDMSWrapperClass";
        public const string FUNC_NAME_DMS_AHLdmsFinalize = "DMS_AHLdmsFinalize";
        public const string FUNC_NAME_DMS_AHLdmsGetFriendlyName = "DMS_AHLdmsGetFriendlyName";
        public const string FUNC_NAME_DMS_AHLdmsSetFriendlyName = "DMS_AHLdmsSetFriendlyName";
        public const string FUNC_NAME_DMS_AHLdmsPublishStorageAdd = "DMS_AHLdmsPublishStorageAdd";
        public const string FUNC_NAME_DMS_AHLdmsPublishStorageRemove = "DMS_AHLdmsPublishStorageRemove";
        public const string FUNC_NAME_DMS_AHLdmsPublishStorageUpdate = "DMS_AHLdmsPublishStorageUpdate";
        public const string FUNC_NAME_DMS_AHLdmsPublishStorageSetDefaultUploadFolder = "DMS_AHLdmsPublishStorageSetDefaultUploadFolder";
        public const string FUNC_NAME_DMS_AHLdmsPublishStorageGetDefaultUploadFolder = "DMS_AHLdmsPublishStorageGetDefaultUploadFolder";
        public const string FUNC_NAME_DMS_AHLdmsGetPublishStorages = "DMS_AHLdmsGetPublishStorages";
        public const string FUNC_NAME_DMS_AHLdmsGetServerState = "DMS_AHLdmsGetServerState";
        public const string FUNC_NAME_DMS_AHLdmsSetServerState = "DMS_AHLdmsSetServerState";
        public const string FUNC_NAME_DMS_AHLdmsPublishStorageSetStorageCentralDir = "DMS_AHLdmsPublishStorageSetStorageCentralDir";
        public const string FUNC_NAME_DMS_AHLdmsGetPublishStoragesCount = "DMS_AHLdmsGetPublishStoragesCount";
        public const string FUNC_NAME_DMS_AHLdmsGetTotalContentsShared = "DMS_AHLdmsGetTotalContentsShared";
        public const string FUNC_NAME_DMS_AHLdmsGetDeviceDescription = "DMS_AHLdmsGetDeviceDescription";
        public const string FUNC_NAME_DMS_AHLdmsRefreshContentIndex = "DMS_AHLdmsRefreshContentIndex";
        public const string FUNC_NAME_DMS_AHLdmsGetContentTreeForTopLevel = "DMS_AHLdmsGetContentTreeForTopLevel";
        public const string FUNC_NAME_DMS_AHLdmsGetContentTreeForChild = "DMS_AHLdmsGetContentTreeForChild";
        public const string FUNC_NAME_DMS_AHLdmsSetContentShare = "DMS_AHLdmsSetContentShare";
        public const string FUNC_NAME_DMS_AHLdmsGetSupportedLanguages = "DMS_AHLdmsGetSupportedLanguages";
        public const string FUNC_NAME_DMS_AHLdmsSetLanguage = "DMS_AHLdmsSetLanguage";
        public const string FUNC_NAME_DMS_AHLdmsGetSelectedLanguage = "DMS_AHLdmsGetSelectedLanguage";
        public const string FUNC_NAME_DMS_AHLdmsBrowseContent = "DMS_AHLdmsBrowseContent";
        public const string FUNC_NAME_DMS_AHLdmsSearchContent = "DMS_AHLdmsSearchContent";
        public const string FUNC_NAME_DMS_AHLdmsPGGetDefaultLevel = "DMS_AHLdmsPGGetDefaultLevel";
        public const string FUNC_NAME_DMS_AHLdmsPGSetDefaultDeviceLevel = "DMS_AHLdmsPGSetDefaultDeviceLevel";
        public const string FUNC_NAME_DMS_AHLdmsPGSetContentLevel = "DMS_AHLdmsPGSetContentLevel";
        public const string FUNC_NAME_DMS_AHLdmsPGGetDeviceList = "DMS_AHLdmsPGGetDeviceList";
        public const string FUNC_NAME_DMS_AHLdmsPGGetLevelList = "DMS_AHLdmsPGGetLevelList";
        public const string FUNC_NAME_DMS_AHLdmsPGSetDeviceParams = "DMS_AHLdmsPGSetDeviceParams";
        public const string FUNC_NAME_DMS_AHLdmsPGDeleteDeviceByMac = "DMS_AHLdmsPGDeleteDeviceByMac";
        public const string FUNC_NAME_DMS_AHLdmsCASetEnabled = "DMS_AHLdmsCASetEnabled";
        public const string FUNC_NAME_DMS_AHLdmsCAIsEnabled = "DMS_AHLdmsCAIsEnabled";
        public const string FUNC_NAME_DMS_AHLdmsCAExecuteCommand = "DMS_AHLdmsCAExecuteCommand";
        

        //ERROR STRING
        public const string ERROR_STRING_DMS_CreateDMSWrapperClass = "Error in creating the DMS Wrapper";
        public const string ERROR_STRING_DMS_AHLdmsInitialize = "Error in initialilze the DMS wrapper";
        public const string ERROR_STRING_DMS_AHLdmsFInalize = "Error in finalize the DMS wrapper";
        public const string ERROR_STRING_DMS_AHLdmsGetFriendlyName = "Error fetching DMS friendly name";
        public const string ERROR_STRING_DMS_AHLdmsSetFriendlyName = "Error setting DMS friendly name, Error code : ";
        public const string ERROR_STRING_DMS_AHLdmsPublishStorageAdd = "Error in ading publish folder, Error code : ";
        public const string ERROR_STRING_DMS_AHLdmsPublishStorageRemove = "Error in removing publish folder, Error code : ";
        public const string ERROR_STRING_DMS_AHLdmsPublishStorageUpdate = "Error in updating the publish folder, Error code : ";
        public const string ERROR_STRING_DMS_AHLdmsPublishStorageSetDefaultUploadFolder = "Error in setting default publish upload folder, Error code : ";
        public const string ERROR_STRING_DMS_AHLdmsPublishStorageGetDefaultUploadFolder = "Error fetching default publish storage folder default path";
        public const string ERROR_STRING_DMS_AHLdmsGetPublishStorages = "Error fetching default publish storage folder list";
        public const string ERROR_STRING_DMS_AHLdmsGetServerState = "Error in fetching service state, Error code : ";
        public const string ERROR_STRING_DMS_AHLdmsSetServerState = "Error while set the service state, Error code : ";
        public const string ERROR_STRING_DMS_AHLdmsPublishStorageSetStorageCentralDir = "Error while set the publih storage central directory, Error code : ";
        public const string ERROR_STRING_DMS_AHLdmsGetPublishStoragesCount = "Error while fetching the publish storaeg count, Error code : ";
        public const string ERROR_STRING_DMS_AHLdmsGetTotalContentsShared = "Error while fetching the total content shared count, Error code : ";
        public const string ERROR_STRING_DMS_AHLdmsGetDeviceDescription = "Error fetching device description";
        public const string ERROR_STRING_DMS_AHLdmsRefreshContentIndex = "Error while refreshing content index, Error code : ";
        public const string ERROR_STRING_DMS_AHLdmsGetContentTree = "Error fetching content tree";
        public const string ERROR_STRING_DMS_AHLdmsSetContentShare = "Error while setting content share, Error code : ";
        public const string ERROR_STRING_DMS_AHLdmsGetSupportedLanguages = "Error fetching supported language list";
        public const string ERROR_STRING_DMS_AHLdmsSetLanguage = "Error while setting current language, Error code : ";
        public const string ERROR_STRING_DMS_AHLdmsGetSelectedLanguage = "Error fetching selected language";
        public const string ERROR_STRING_DMS_AHLdmsBrowseContent = "Error fetching browse content";
        public const string ERROR_STRING_DMS_AHLdmsSearchContent = "Error fetching search content";
        public const string ERROR_STRING_DMS_AHLdmsPGGetDefaultLevel = "Error in fetching default pg level, Error code : ";
        public const string ERROR_STRING_DMS_AHLdmsPGSetDefaultDeviceLevel = "Error in fetching default device level, Error code : ";
        public const string ERROR_STRING_DMS_AHLdmsPGSetContentLevel = "Error in set the content level, Error code : ";
        public const string ERROR_STRING_DMS_AHLdmsPGGetDeviceList = "Error fetching device list";
        public const string ERROR_STRING_DMS_AHLdmsPGGetLevelList = "Error fetching level list";
        public const string ERROR_STRING_DMS_AHLdmsPGSetDeviceParams = "Error in set the device params, Error code : ";
        public const string ERROR_STRING_DMS_AHLdmsPGDeleteDeviceByMac = "Error in deleting the device, Error code : ";

        //LOG
        public const string LOG_RESPONCE = "Responce : ";

        //PARAMETER
        public const string PARAM_pDmsInitializeParams = "pDmsInitializeParams : ";
        public const string PARAM_pDMSFriendlyname = "pDMSFriendlyname : ";
        public const string PARAM_pState = "pState : ";
        public const string PARAM_pIntPtrWrapperobj = "pIntPtrWrapperobj : ";
        public const string PARAM_pLanguage = "pLanguage : ";
        public const string PARAM_pPath = "pPath : ";
        public const string PARAM_pShareName = "pShareName : ";
        public const string PARAM_pID = "pID : ";
        public const string PARAM_pLocation = "pLocation : ";
        public const string PARAM_pAutoIndex = "pAutoIndex : ";
        public const string PARAM_pOutputPath = "pOutputPath : ";
        public const string PARAM_pCount = "pCount : ";
        public const string PARAM_pContentClassType = "pContentClassType : ";
        public const string PARAM_pResult = "pResult : ";
        public const string PARAM_pContainerID = "pContainerID : ";
        public const string PARAM_pStartIndex = "pStartIndex : ";
        public const string PARAM_pRequestCount = "pRequestCount : ";
        public const string PARAM_pShareFolderList = "pShareFolderList : ";
        public const string PARAM_pContentId = "pContentId : ";
        public const string PARAM_pIsShare = "pIsShare : ";
        public const string PARAM_pIsRecursive = "pIsRecursive : ";
        public const string PARAM_pCriteria = "pCriteria : ";
        public const string PARAM_pLevelType = "pLevelType : ";
        public const string PARAM_pDefaultLevel = "pDefaultLevel : ";
        public const string PARAM_pLevel = "pLevel : ";
        public const string PARAM_pDeviceMAC = "pDeviceMAC : ";
        public const string PARAM_pDescription = "pDescription : ";

        #endregion

        #region "LogManager"

        public const string DIRECTORY_PATH = ".\\DMS LOGS\\";
        public const string LIBRARY_DIRECTORY_PATH = ".\\LIBRARY LOGS\\";
        public const string STR_DATE_FORMAT = "ddMMyyyy";
        public const string STR_TIME_FORMATE = "hh:mm:ss:fff tt";        
        public const string FILE_EXTENTION = ".log";
        public const string PREFIX_TEXT_FOR_FOLDER_NAME = "\\Log";
        public const string PREFIX_TEXT_FOR_LIB_FOLDER_NAME = "\\Lib_Log";
        public const string MSG_TIME = "# T: [ ";
        public const string MSG_CLASS = " ] ::  C: ";
        public const string MSG_METHOD = " ::  M: ";
        public const string STR_MSG = " ::  Msg: ";
        public const string STR_EX_MSG = " ::  exMsg: ";
        public const string STR_EX_STACK = " ::  exStack: ";

        #endregion

        #region "MessageManager"

        public const string MESSAGE_TITLE = "Jio Server";

        #endregion

        #endregion
    }
}