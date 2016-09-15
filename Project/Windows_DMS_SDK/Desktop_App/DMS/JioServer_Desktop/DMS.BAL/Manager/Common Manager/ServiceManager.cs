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
using System.Runtime.InteropServices;
using System.Windows;
using DMS.BAL.Entity;
using DMS.BAL.Entity.Service_Entity;
using System.Runtime.CompilerServices;
using DMS.BAL.Entity.App_Entity;

namespace DMS.BAL.Manager.Common_Manager
{
    [System.Runtime.Remoting.Contexts.Synchronization()]
   public class ServiceManager
    {
        #region "Declaration"

        public static IntPtr intptrWrapperobj; //DMSWrapper Object   
        private static System.Threading.Mutex LibraryCallMutex = new System.Threading.Mutex();
       //Added delegate same as in DMC
        public delegate void dmsCallbackHandler_applayer(IntPtr arg, DMSParameters.dmsEvent ev, IntPtr param);
       
        #endregion

        #region "Service Function"
        [DllImport("DMSLibrary.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr CreateDMSWrapperClass();
        [DllImport("DMSLibrary.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr DeleteDMSWrapperClass(IntPtr WrapperObj);
        [DllImport("DMSLibrary.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Unicode)]
        private static extern bool AHLdmsInitialize(IntPtr WrapperObj, ref DMS.BAL.Entity.Service_Entity.DMSParameters.dmsInitParams dmsInitializeParams);
        [DllImport("DMSLibrary.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern DMSParameters.returnValue AHLdmsStart(IntPtr WrapperObj);
        [DllImport("DMSLibrary.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern DMSParameters.returnValue AHLdmsStop(IntPtr WrapperObj);
        [DllImport("DMSLibrary.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern bool AHLdmsFinalize(IntPtr WrapperObj);
        [DllImport("DMSLibrary.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr AHLdmsGetFriendlyName(IntPtr WrapperObj);
        [DllImport("DMSLibrary.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        public static extern DMSParameters.returnValue AHLdmsSetFriendlyName(IntPtr WrapperObj, string Friedlyname);


        [DllImport("DMSLibrary.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        private static extern DMSParameters.returnValue AHLdmsPublishStorageAdd(IntPtr WrapperObj, string path, string share_name, string id, DMSParameters.dmsStorageDatabaseLocationType location, bool auto_index);
        //pending
        [DllImport("DMSLibrary.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        private static extern DMSParameters.returnValue AHLdmsPublishStorageRemove(IntPtr WrapperObj, string path);
        //pending
        [DllImport("DMSLibrary.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        private static extern DMSParameters.returnValue AHLdmsPublishStorageUpdate(IntPtr WrapperObj, string path);
        [DllImport("DMSLibrary.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        private static extern DMSParameters.returnValue AHLdmsPublishStorageSetDefaultUploadFolder(IntPtr WrapperObj, string path);

        [DllImport("DMSLibrary.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr AHLdmsPublishStorageGetDefaultUploadFolder(IntPtr WrapperObj, string out_path);

        [DllImport("DMSLibrary.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr AHLdmsGetPublishStorages(IntPtr WrapperObj, string out_storages);

        [DllImport("DMSLibrary.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern DMSParameters.returnValue AHLdmsGetServerState(IntPtr WrapperObj, out DMSParameters.dmsState state);
        [DllImport("DMSLibrary.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern DMSParameters.returnValue AHLdmsSetServerState(IntPtr WrapperObj, DMSParameters.dmsState state);

        //pending
        [DllImport("DMSLibrary.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        private static extern DMSParameters.returnValue AHLdmsPublishStorageSetStorageCentralDir(IntPtr WrapperObj, string out_path);//pending

        [DllImport("DMSLibrary.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern DMSParameters.returnValue AHLdmsGetPublishStoragesCount(IntPtr WrapperObj, out int count);

        [DllImport("DMSLibrary.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern DMSParameters.returnValue AHLdmsGetTotalContentsShared(IntPtr WrapperObj, DMSParameters.dmsContentClassType contentClassType, out int result);
        [DllImport("DMSLibrary.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr AHLdmsGetDeviceDescription(IntPtr WrapperObj, string deviceDescription);
        [DllImport("DMSLibrary.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern DMSParameters.returnValue AHLdmsRefreshContentIndex(IntPtr WrapperObj);
        //pending
        [DllImport("DMSLibrary.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr AHLdmsGetContentTree(IntPtr WrapperObj, string containerId, int startIndex, int requestedCount, string outData);
        //pending
        [DllImport("DMSLibrary.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        private static extern DMSParameters.returnValue AHLdmsSetContentShare(IntPtr WrapperObj, string contentId, bool inShare, bool inRecusive);
        [DllImport("DMSLibrary.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr AHLdmsGetSupportedLanguages(IntPtr WrapperObj, string languageData);
        [DllImport("DMSLibrary.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        private static extern DMSParameters.returnValue AHLdmsSetLanguage(IntPtr WrapperObj, string language);
        [DllImport("DMSLibrary.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr AHLdmsGetSelectedLanguage(IntPtr WrapperObj, string languageData);
        [DllImport("DMSLibrary.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr AHLdmsBrowseContent(IntPtr WrapperObj, string inID, string responseData, uint start_index, uint request_count);
        [DllImport("DMSLibrary.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr AHLdmsSearchContent(IntPtr WrapperObj, string inID, string criteria, string responseData, uint startIndex, uint requestCount);
        [DllImport("DMSLibrary.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern DMSParameters.returnValue AHLdmsPGGetDefaultLevel(IntPtr WrapperObj, DMSParameters.dmsPGLevelType inLevelType, out int outLevel);
        [DllImport("DMSLibrary.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern DMSParameters.returnValue AHLdmsPGSetDefaultDeviceLevel(IntPtr WrapperObj, DMSParameters.dmsPGLevelType levelType, int defaultLevel);
        [DllImport("DMSLibrary.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        private static extern DMSParameters.returnValue AHLdmsPGSetContentLevel(IntPtr WrapperObj, string contentID, int inLevel);
        [DllImport("DMSLibrary.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr AHLdmsPGGetDeviceList(IntPtr WrapperObj, string deviceList);
        [DllImport("DMSLibrary.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr AHLdmsPGGetLevelList(IntPtr WrapperObj, string levelList);
        [DllImport("DMSLibrary.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        private static extern DMSParameters.returnValue AHLdmsPGSetDeviceParams(IntPtr WrapperObj, string deviceMAC, int level, string description);

        [DllImport("DMSLibrary.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        private static extern DMSParameters.returnValue AHLdmsPGDeleteDeviceByMac(IntPtr WrapperObj, string deviceMAC);

        [DllImport("DMSLibrary.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern DMSParameters.returnValue AHLdmsCASetEnabled(IntPtr WrapperObj, bool in_enable);
        [DllImport("DMSLibrary.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern DMSParameters.returnValue AHLdmsCAIsEnabled(IntPtr WrapperObj, out bool out_enabled);
        [DllImport("DMSLibrary.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern DMSParameters.returnValue AHLdmsCASetDBLocation(IntPtr WrapperObj, string in_databaseLocation);
        [DllImport("DMSLibrary.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern string AHLdmsCAGetDBLocation(IntPtr WrapperObj);
        [DllImport("DMSLibrary.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern DMSParameters.returnValue AHLdmsCASetDBSelectionMode(IntPtr WrapperObj, DMSParameters.dmsCADatabaseSelectionMode in_mode);
        [DllImport("DMSLibrary.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern DMSParameters.returnValue AHLdmsCAGetDBSelectionMode(IntPtr WrapperObj, out DMSParameters.dmsCADatabaseSelectionMode out_mode);
        [DllImport("DMSLibrary.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern DMSParameters.returnValue AHLdmsCAExecuteCommand(IntPtr WrapperObj, DMSParameters.dmsCACommand in_cmd);
        [DllImport("DMSLibrary.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern DMSParameters.returnValue AHLdmsCAGetState(IntPtr WrapperObj, out DMSParameters.dmsCAState out_state);

        #endregion

        #region "Native Function"

        #region "Configuration manager"

        #region "Function: DMS_CreateDMSWrapperClass(1)"
        /// <summary>
        /// create DMS wrapper class.
        /// </summary>
        /// <returns></returns>
        public static IntPtr DMS_CreateDMSWrapperClass()
        {
            IntPtr intPtrCreateWrapperClass;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_CreateDMSWrapperClass);
                
                LibraryCallMutex.WaitOne();
                intPtrCreateWrapperClass = CreateDMSWrapperClass();               
                
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_CreateDMSWrapperClass, Constant.LOG_RESPONCE + intPtrCreateWrapperClass.ToString());
                if (intPtrCreateWrapperClass == IntPtr.Zero)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_CreateDMSWrapperClass, Constant.ERROR_STRING_DMS_CreateDMSWrapperClass);
                }
                return intPtrCreateWrapperClass;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_CreateDMSWrapperClass, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return IntPtr.Zero;
        }

        #endregion

        #region "Function: DMS_CreateDMSWrapperClass()"
        /// <summary>
        /// create DMS wrapper class.
        /// </summary>
        /// <returns></returns>
        public static void DMS_DeleteDMSWrapperClass()
        {
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_DeleteDMSWrapperClass);
                
                LibraryCallMutex.WaitOne();
                DeleteDMSWrapperClass(intptrWrapperobj);                

                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_DeleteDMSWrapperClass);
                
                return;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_DeleteDMSWrapperClass, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return;
        }

        #endregion

        #region "Function: DMS_AHLdmsInitialize(1)"
        /// <summary>
        /// initialize.
        /// </summary>
        /// <param name="pDmsInitializeParams">initialize parameters.</param>
        /// <returns></returns>
        public static bool DMS_AHLdmsInitialize(ref DMS.BAL.Entity.Service_Entity.DMSParameters.dmsInitParams pDmsInitializeParams)
        {
            bool initializeResult = false;
            DMSParameters.returnValue retResponse;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsInitialize, Constant.PARAM_pDmsInitializeParams + "pDmsInitializeParams.dmsDataDirectory : " + pDmsInitializeParams.dmsDataDirectory.ToString() + Constant.COMMA_SIGN + Constant.STRING_SPACE + "pDmsInitializeParams.configDirectory : " + pDmsInitializeParams.configDirectory.ToString() + Constant.COMMA_SIGN + Constant.STRING_SPACE + "pDmsInitializeParams.upnpPort : " + pDmsInitializeParams.upnpPort.ToString());

                LibraryCallMutex.WaitOne();
                initializeResult = AHLdmsInitialize(intptrWrapperobj, ref pDmsInitializeParams);                

                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsInitialize, Constant.LOG_RESPONCE + initializeResult.ToString());

                if (initializeResult == false)
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsInitialize, Constant.ERROR_STRING_DMS_AHLdmsInitialize);
                else
                    retResponse = AHLdmsStart(intptrWrapperobj);
                return initializeResult;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsInitialize, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return initializeResult;
        }

        #endregion

        #region "Function: DMS_AHLdmsFinalize(1)"
        /// <summary>
        /// initialize.
        /// </summary>
        /// <param name="pDmsInitializeParams">initialize parameters.</param>
        /// <returns></returns>
        public static bool DMS_AHLdmsFinalize()
        {
            bool finitializeResult = false;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsFinalize);
                
                LibraryCallMutex.WaitOne();
                finitializeResult = AHLdmsFinalize(intptrWrapperobj);

                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsFinalize, Constant.LOG_RESPONCE + finitializeResult.ToString());
                if (finitializeResult == false)
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsFinalize, Constant.ERROR_STRING_DMS_AHLdmsFInalize);
                return finitializeResult;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsFinalize, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return finitializeResult;
        }

        #endregion

        #region "Function: DMS_AHLdmsGetFriendlyName(0)"
        /// <summary>
        /// get friendly name.
        /// </summary>
        /// <returns></returns>
        public static string DMS_AHLdmsGetFriendlyName()
        {
            string sFriendlyName = Constant.STRING_EMPTY;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetFriendlyName);

                LibraryCallMutex.WaitOne();
                IntPtr intptrGetFrinedlyName = AHLdmsGetFriendlyName(intptrWrapperobj);                

                if (intptrGetFrinedlyName == IntPtr.Zero)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetFriendlyName, Constant.ERROR_STRING_DMS_AHLdmsGetFriendlyName);
                    return Constant.STRING_EMPTY;
                }
                else
                {
                    sFriendlyName = Marshal.PtrToStringUni(intptrGetFrinedlyName); //StringFromNativeUtf8(intptrGetFrinedlyName);
                    LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetFriendlyName, Constant.LOG_RESPONCE + sFriendlyName.ToString());
                }
                return sFriendlyName;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetFriendlyName, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return sFriendlyName;
        }
        #endregion

        #region "Function: DMS_AHLdmsSetFriendlyName(1)"
        /// <summary>
        /// Dms the name of the s_ ah LDMS set friendly.
        /// </summary>
        /// <param name="pDMSFriendlyname">friendlyname to set.</param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsSetFriendlyName(string pDMSFriendlyname)
        {
            DMSParameters.returnValue retResponse = DMSParameters.returnValue.NFLC_E_ERROR;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsSetFriendlyName, Constant.PARAM_pDMSFriendlyname + pDMSFriendlyname.ToString());

                LibraryCallMutex.WaitOne();
                retResponse = AHLdmsSetFriendlyName(intptrWrapperobj, pDMSFriendlyname);                
                
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsSetFriendlyName, Constant.LOG_RESPONCE + retResponse.ToString());
                if (retResponse != DMSParameters.returnValue.NFLC_E_OK)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsSetFriendlyName, Constant.ERROR_STRING_DMS_AHLdmsSetFriendlyName + retResponse.ToString());
                    return retResponse;
                }
                return retResponse;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsSetFriendlyName, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return retResponse;
        }

        #endregion

        #region "Function: DMS_AHLdmsGetServerState(1)"
        /// <summary>
        /// get server state.
        /// </summary>
        /// <returns></returns>
        public static DMSParameters.dmsState DMS_AHLdmsGetServerState()
        {
            DMSParameters.dmsState pState = DMSParameters.dmsState.DMS_STATE_DISABLE;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetServerState);

                LibraryCallMutex.WaitOne();
                DMSParameters.returnValue retResponse = AHLdmsGetServerState(intptrWrapperobj, out pState);                
                
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetServerState, Constant.LOG_RESPONCE + pState.ToString());

                if (retResponse != DMSParameters.returnValue.NFLC_E_OK)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetServerState, Constant.ERROR_STRING_DMS_AHLdmsGetServerState + retResponse.ToString());
                    return DMSParameters.dmsState.DMS_STATE_DISABLE;
                }
                return pState;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetServerState, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return pState;
        }

        #endregion

        #region "Function: DMS_AHLdmsSetServerState(1)"
        /// <summary>
        /// set server state.
        /// </summary>
        /// <param name="pState"></param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsSetServerState(DMSParameters.dmsState pState)
        {
            DMSParameters.returnValue retResponse = DMSParameters.returnValue.NFLC_E_ERROR;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsSetServerState, Constant.PARAM_pState + pState.ToString());

                LibraryCallMutex.WaitOne();
                retResponse = AHLdmsSetServerState(intptrWrapperobj, pState);                
                
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsSetServerState, Constant.LOG_RESPONCE + retResponse.ToString());

                if (retResponse != DMSParameters.returnValue.NFLC_E_OK)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsSetServerState, Constant.ERROR_STRING_DMS_AHLdmsSetServerState + retResponse.ToString());
                    return retResponse;
                }
                return retResponse;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsSetServerState, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return retResponse;
        }

        #endregion

        #region "Function: DMS_AHLdmsGetDeviceDescription(0)"

        /// <summary>
        /// get device description.
        /// </summary>
        /// <returns></returns>
        public static string DMS_AHLdmsGetDeviceDescription()
        {
            string sDeviceDescription = Constant.STRING_EMPTY;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetDeviceDescription);

                LibraryCallMutex.WaitOne();
                IntPtr intPtrGetDeviceDescription = ServiceManager.AHLdmsGetDeviceDescription(intptrWrapperobj, sDeviceDescription);                

                if (intPtrGetDeviceDescription == IntPtr.Zero)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetDeviceDescription, Constant.ERROR_STRING_DMS_AHLdmsGetDeviceDescription);
                    return Constant.STRING_EMPTY;
                }
                else
                {
                    sDeviceDescription = Marshal.PtrToStringUni(intPtrGetDeviceDescription);
                    LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetDeviceDescription, Constant.LOG_RESPONCE + sDeviceDescription.ToString());
                }
                return sDeviceDescription;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetDeviceDescription, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return sDeviceDescription;
        }

        #endregion

        #region "Function: DMS_AHLdmsRefreshContentIndex(1)"
        /// <summary>
        /// refresh content.
        /// </summary>
        /// <param name="pIntPtrWrapperobj"></param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsRefreshContentIndex(IntPtr pIntPtrWrapperobj)
        {
            DMSParameters.returnValue retResponse = DMSParameters.returnValue.NFLC_E_ERROR;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsRefreshContentIndex, Constant.PARAM_pIntPtrWrapperobj + pIntPtrWrapperobj.ToString());

                LibraryCallMutex.WaitOne();
                retResponse = AHLdmsRefreshContentIndex(pIntPtrWrapperobj);                
                
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsRefreshContentIndex, Constant.LOG_RESPONCE + retResponse.ToString());

                if (retResponse != DMSParameters.returnValue.NFLC_E_OK)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsRefreshContentIndex, Constant.ERROR_STRING_DMS_AHLdmsRefreshContentIndex + retResponse.ToString());
                    return retResponse;
                }
                return retResponse;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsRefreshContentIndex, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return retResponse;
        }

        #endregion

        #region "Function: DMS_AHLdmsGetSupportedLanguages(1)"
        /// <summary>
        /// get supported languages.
        /// </summary>
        /// <param name="pIntPtrWrapperobj"></param>
        /// <returns></returns>
        public static string DMS_AHLdmsGetSupportedLanguages(IntPtr pIntPtrWrapperobj)
        {
            string sLanguageData = Constant.STRING_EMPTY;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetSupportedLanguages, Constant.PARAM_pIntPtrWrapperobj + pIntPtrWrapperobj.ToString());

                LibraryCallMutex.WaitOne();
                IntPtr intPtrGetSupportedlanguages = ServiceManager.AHLdmsGetSupportedLanguages(pIntPtrWrapperobj, sLanguageData);                

                if (intPtrGetSupportedlanguages == IntPtr.Zero)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetSupportedLanguages, Constant.ERROR_STRING_DMS_AHLdmsGetSupportedLanguages);
                    return Constant.STRING_EMPTY;
                }
                else
                {
                    sLanguageData = Marshal.PtrToStringUni(intPtrGetSupportedlanguages);
                    LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetSupportedLanguages, Constant.LOG_RESPONCE + sLanguageData.ToString());
                }
                return sLanguageData;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetSupportedLanguages, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return sLanguageData;
        }

        #endregion

        #region "Function: DMS_AHLdmsSetLanguage(1)"
        /// <summary>
        /// set language.
        /// </summary>
        /// <param name="pLanguage"></param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsSetLanguage(string pLanguage)
        {
            DMSParameters.returnValue retResponse = DMSParameters.returnValue.NFLC_E_ERROR;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsSetLanguage, Constant.PARAM_pLanguage + pLanguage.ToString());

                LibraryCallMutex.WaitOne();
                retResponse = AHLdmsSetLanguage(intptrWrapperobj, pLanguage);                

                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsSetLanguage, Constant.LOG_RESPONCE + retResponse.ToString());

                if (retResponse != DMSParameters.returnValue.NFLC_E_OK)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsSetLanguage, Constant.ERROR_STRING_DMS_AHLdmsSetLanguage + retResponse.ToString());
                    return retResponse;
                }
                return retResponse;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsSetLanguage, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return retResponse;
        }

        #endregion

        #region "Function: DMS_AHLdmsGetSelectedLanguage(1)"
        /// <summary>
        /// get selected language.
        /// </summary>
        /// <param name="pIntPtrWrapperobj"></param>
        /// <returns></returns>
        public static string DMS_AHLdmsGetSelectedLanguage(IntPtr pIntPtrWrapperobj)
        {
            string sSelectedLanguage = Constant.STRING_EMPTY;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetSelectedLanguage, Constant.PARAM_pIntPtrWrapperobj + pIntPtrWrapperobj.ToString());
                
                LibraryCallMutex.WaitOne();
                IntPtr intPtrGetSelectedlanguages = ServiceManager.AHLdmsGetSelectedLanguage(intptrWrapperobj, sSelectedLanguage);                

                if (intPtrGetSelectedlanguages == IntPtr.Zero)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetSelectedLanguage, Constant.ERROR_STRING_DMS_AHLdmsGetSelectedLanguage);
                    return Constant.STRING_EMPTY;
                }
                else
                {
                    sSelectedLanguage = Marshal.PtrToStringUni(intPtrGetSelectedlanguages);
                    LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetSelectedLanguage, Constant.LOG_RESPONCE + sSelectedLanguage.ToString());
                }
                return sSelectedLanguage;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetSelectedLanguage, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return sSelectedLanguage;
        }

        #endregion

        #endregion

        #region "Shared Folder Manager"

        #region "Function: DMS_AHLdmsPublishStorageAdd(5)"
        /// <summary>
        /// Add publish storage.
        /// </summary>
        /// <param name="pPath">Folder path</param>
        /// <param name="pShareName">Folder Name</param>
        /// <param name="pID">Folder ID</param>
        /// <param name="pLocation"></param>
        /// <param name="pAutoIndex"></param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsPublishStorageAdd(string pPath, string pShareName, string pID, DMSParameters.dmsStorageDatabaseLocationType pLocation, bool pAutoIndex)
        {
            DMSParameters.returnValue retResponse = DMSParameters.returnValue.NFLC_E_ERROR;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPublishStorageAdd, Constant.PARAM_pPath + pPath.ToString() + Constant.COMMA_SIGN + Constant.STRING_SPACE + Constant.PARAM_pShareName + pShareName.ToString() + Constant.COMMA_SIGN + Constant.STRING_SPACE + Constant.PARAM_pID + pID.ToString() + Constant.COMMA_SIGN + Constant.STRING_SPACE + Constant.PARAM_pLocation + pLocation.ToString() + Constant.COMMA_SIGN + Constant.STRING_SPACE + Constant.PARAM_pAutoIndex + pAutoIndex.ToString());

                LibraryCallMutex.WaitOne();
                retResponse = AHLdmsPublishStorageAdd(intptrWrapperobj, pPath, pShareName, pID, pLocation, pAutoIndex);                
                
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPublishStorageAdd, Constant.LOG_RESPONCE + retResponse.ToString());

                if (retResponse != DMSParameters.returnValue.NFLC_E_OK)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPublishStorageAdd, Constant.ERROR_STRING_DMS_AHLdmsPublishStorageAdd + retResponse.ToString());
                    return retResponse;
                }
                return retResponse;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPublishStorageAdd, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return retResponse;
        }

        #endregion

        #region "Function: DMS_AHLdmsPublishStorageRemove(1)"
        /// <summary>
        /// Remove Publish Storage.
        /// </summary>
        /// <param name="pPath">FolderPath</param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsPublishStorageRemove(string pPath)
        {
            DMSParameters.returnValue retResponse = DMSParameters.returnValue.NFLC_E_ERROR;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPublishStorageRemove, Constant.PARAM_pPath + pPath.ToString());

                LibraryCallMutex.WaitOne();
                retResponse = AHLdmsPublishStorageRemove(intptrWrapperobj, pPath);                
                
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPublishStorageRemove, Constant.LOG_RESPONCE + retResponse.ToString());

                if (retResponse != DMSParameters.returnValue.NFLC_E_OK)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPublishStorageRemove, Constant.ERROR_STRING_DMS_AHLdmsPublishStorageRemove + retResponse.ToString());
                    return retResponse;
                }
                return retResponse;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPublishStorageRemove, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return retResponse;
        }

        #endregion

        #region "Function: DMS_AHLdmsPublishStorageUpdate(1)"
        /// <summary>
        /// Update publish storage.
        /// </summary>
        /// <param name="pPath">FolderPath</param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsPublishStorageUpdate(string pPath)
        {
            DMSParameters.returnValue retResponse = DMSParameters.returnValue.NFLC_E_ERROR;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPublishStorageUpdate, Constant.PARAM_pPath + pPath.ToString());

                LibraryCallMutex.WaitOne();
                retResponse = AHLdmsPublishStorageUpdate(intptrWrapperobj, pPath);                
                
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPublishStorageUpdate, Constant.LOG_RESPONCE + retResponse.ToString());

                if (retResponse != DMSParameters.returnValue.NFLC_E_OK)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPublishStorageUpdate, Constant.ERROR_STRING_DMS_AHLdmsPublishStorageUpdate + retResponse.ToString());
                    return retResponse;
                }
                return retResponse;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPublishStorageUpdate, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return retResponse;
        }

        #endregion

        #region "Function: DMS_AHLdmsPublishStorageSetDefaultUploadFolder(1)"
        /// <summary>
        /// Set Default upload folder Path from publish storage.
        /// </summary>
        /// <param name="pPath">FolderPath</param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsPublishStorageSetDefaultUploadFolder(string pPath)
        {
            DMSParameters.returnValue retResponse = DMSParameters.returnValue.NFLC_E_ERROR;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPublishStorageSetDefaultUploadFolder, Constant.PARAM_pPath + pPath.ToString());

                LibraryCallMutex.WaitOne();
                retResponse = AHLdmsPublishStorageSetDefaultUploadFolder(intptrWrapperobj, pPath);                
                
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPublishStorageSetDefaultUploadFolder, Constant.LOG_RESPONCE + retResponse.ToString());

                if (retResponse != DMSParameters.returnValue.NFLC_E_OK)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPublishStorageSetDefaultUploadFolder, Constant.ERROR_STRING_DMS_AHLdmsPublishStorageSetDefaultUploadFolder + retResponse.ToString());
                    return retResponse;
                }
                return retResponse;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPublishStorageSetDefaultUploadFolder, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return retResponse;
        }

        #endregion

        #region "Function: DMS_AHLdmsPublishStorageGetDefaultUploadFolder(0)"
        /// <summary>
        /// get default upload folder from publish storage.
        /// </summary>
        /// <returns></returns>
        public static string DMS_AHLdmsPublishStorageGetDefaultUploadFolder()
        {
            string sDefaultUploadFoler = Constant.STRING_EMPTY;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPublishStorageGetDefaultUploadFolder);

                LibraryCallMutex.WaitOne();
                IntPtr intPtrGtDefaultFolder = ServiceManager.AHLdmsPublishStorageGetDefaultUploadFolder(intptrWrapperobj, sDefaultUploadFoler);                

                if (intPtrGtDefaultFolder == IntPtr.Zero)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPublishStorageGetDefaultUploadFolder, Constant.ERROR_STRING_DMS_AHLdmsPublishStorageGetDefaultUploadFolder);
                    return Constant.STRING_EMPTY;
                }
                else
                {
                    sDefaultUploadFoler = Marshal.PtrToStringUni(intPtrGtDefaultFolder);
                    LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPublishStorageGetDefaultUploadFolder, Constant.LOG_RESPONCE + sDefaultUploadFoler.ToString());
                }
                return sDefaultUploadFoler;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPublishStorageGetDefaultUploadFolder, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return sDefaultUploadFoler;
        }

        #endregion

        #region "Function: DMS_AHLdmsGetPublishStorages(0)"
        /// <summary>
        /// Get publish storages.
        /// </summary>
        /// <returns></returns>
        public static List<SharedFolder> DMS_AHLdmsGetPublishStorages()
        {
            string sGetPublishFolder = Constant.STRING_EMPTY;
            List<SharedFolder> oShareFolderList = new List<SharedFolder>();
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetPublishStorages);

                LibraryCallMutex.WaitOne();
                IntPtr intPtrGtDefaultFolder = ServiceManager.AHLdmsGetPublishStorages(intptrWrapperobj, sGetPublishFolder);                

                if (intPtrGtDefaultFolder == IntPtr.Zero)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetPublishStorages, Constant.ERROR_STRING_DMS_AHLdmsGetPublishStorages);
                }
                else
                {
                    sGetPublishFolder = Marshal.PtrToStringUni(intPtrGtDefaultFolder);
                    LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetPublishStorages, Constant.LOG_RESPONCE + Environment.NewLine + sGetPublishFolder.ToString());
                }

                if ((sGetPublishFolder != null) && (sGetPublishFolder.Length > 0))
                {
                    oShareFolderList = XMLManager.readShareFolderXml(sGetPublishFolder);
                }
                return oShareFolderList;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetPublishStorages, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return oShareFolderList;
        }

        #endregion

        #region "Function: DMS_AHLdmsPublishStorageSetStorageCentralDir(1)"
        /// <summary>
        /// set publish storage central dir.
        /// </summary>
        /// <param name="pOutputPath"></param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsPublishStorageSetStorageCentralDir(string pOutputPath)
        {
            DMSParameters.returnValue retResponse = DMSParameters.returnValue.NFLC_E_ERROR;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPublishStorageSetStorageCentralDir, Constant.PARAM_pOutputPath + pOutputPath);

                LibraryCallMutex.WaitOne();
                retResponse = AHLdmsPublishStorageSetStorageCentralDir(intptrWrapperobj, pOutputPath);                
                
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPublishStorageSetStorageCentralDir, Constant.LOG_RESPONCE + retResponse.ToString());

                if (retResponse != DMSParameters.returnValue.NFLC_E_OK)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPublishStorageSetStorageCentralDir, Constant.ERROR_STRING_DMS_AHLdmsPublishStorageSetStorageCentralDir + retResponse.ToString());
                    return retResponse;
                }
                return retResponse;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPublishStorageSetStorageCentralDir, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return retResponse;
        }

        #endregion

        #region "Function: DMS_AHLdmsGetPublishStoragesCount(1)"
        /// <summary>
        /// Get publish storages count.
        /// </summary>
        /// <param name="pCount">Total Count of Folder</param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsGetPublishStoragesCount(out int pCount)
        {
            DMSParameters.returnValue retResponse = DMSParameters.returnValue.NFLC_E_ERROR;
            pCount = 0;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetPublishStoragesCount, Constant.PARAM_pCount + pCount.ToString());

                LibraryCallMutex.WaitOne();
                retResponse = AHLdmsGetPublishStoragesCount(intptrWrapperobj, out pCount);                
                
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetPublishStoragesCount, Constant.LOG_RESPONCE + pCount.ToString());

                if (retResponse != DMSParameters.returnValue.NFLC_E_OK)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetPublishStoragesCount, Constant.ERROR_STRING_DMS_AHLdmsGetPublishStoragesCount + retResponse.ToString());
                    return retResponse;
                }
                return retResponse;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetPublishStoragesCount, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return retResponse;
        }

        #endregion

        #region "Function: DMS_AHLdmsGetTotalContentsShared(2)"
        /// <summary>
        /// Get total shared contents.
        /// </summary>
        /// <param name="pContentClassType"></param>
        /// <param name="pResult"></param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsGetTotalContentsShared(DMSParameters.dmsContentClassType pContentClassType, out int pResult)
        {
            DMSParameters.returnValue retResponse = DMSParameters.returnValue.NFLC_E_ERROR;
            pResult = 0;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetTotalContentsShared, Constant.PARAM_pContentClassType + pContentClassType.ToString() + Constant.COMMA_SIGN + Constant.STRING_SPACE + Constant.PARAM_pResult + pResult.ToString());

                LibraryCallMutex.WaitOne();
                retResponse = AHLdmsGetTotalContentsShared(intptrWrapperobj, pContentClassType, out pResult);                
                
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetTotalContentsShared, Constant.LOG_RESPONCE + pResult.ToString());

                if (retResponse != DMSParameters.returnValue.NFLC_E_OK)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetTotalContentsShared, Constant.ERROR_STRING_DMS_AHLdmsGetTotalContentsShared + retResponse.ToString());
                    return retResponse;
                }
                return retResponse;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetTotalContentsShared, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return retResponse;
        }

        #endregion

        #region "Function: DMS_AHLdmsGetContentTree(4)"
        /// <summary>
        /// Get content tree.
        /// </summary>
        /// <param name="pContainerID"></param>
        /// <param name="pStartIndex"></param>
        /// <param name="pRequestCount"></param>
        /// <param name="pShareFolderList"></param>
        /// <returns></returns>
        public static void DMS_AHLdmsGetContentTree(string pContainerID, int pStartIndex, int pRequestCount, ref List<SharedFolder> pShareFolderList)
        {
            string sContentTree = Constant.STRING_EMPTY;

            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetContentTreeForTopLevel, Constant.PARAM_pContainerID + pContainerID.ToString() + Constant.COMMA_SIGN + Constant.STRING_SPACE + Constant.PARAM_pStartIndex + pStartIndex.ToString() + Constant.COMMA_SIGN + Constant.STRING_SPACE + Constant.PARAM_pRequestCount + pRequestCount.ToString() + Constant.COMMA_SIGN + Constant.STRING_SPACE + Constant.PARAM_pShareFolderList + pShareFolderList.ToString());

                LibraryCallMutex.WaitOne();
                IntPtr intPtrGetDeviceDescription = ServiceManager.AHLdmsGetContentTree(intptrWrapperobj, pContainerID, pStartIndex, pRequestCount, sContentTree);                

                if (intPtrGetDeviceDescription == IntPtr.Zero)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetContentTreeForTopLevel, Constant.ERROR_STRING_DMS_AHLdmsGetContentTree);
                }
                else
                {
                    sContentTree = Marshal.PtrToStringUni(intPtrGetDeviceDescription);
                    LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetContentTreeForTopLevel, Constant.LOG_RESPONCE + sContentTree.ToString());
                }

                if ((sContentTree != null) && (sContentTree.Length > 0))
                {
                    XMLManager.readShareFolderPGLevel(sContentTree, ref pShareFolderList);

                    int DefaultFolderPgLevel = DMS_AHLdmsPGGetDefaultLevel(DMSParameters.dmsPGLevelType.DMS_PG_LEVEL_TYPE_CONTENT);

                    foreach (SharedFolder oItem in pShareFolderList)
                    {
                        if (oItem.PGLevel == 0)
                            oItem.PGLevel = DefaultFolderPgLevel;
                    }

                }
                else
                {
                    //set Default PGLevel
                    int DefaultFolderPgLevel = DMS_AHLdmsPGGetDefaultLevel(DMSParameters.dmsPGLevelType.DMS_PG_LEVEL_TYPE_CONTENT);

                    foreach (SharedFolder oItem in pShareFolderList)
                    {
                        oItem.PGLevel = DefaultFolderPgLevel;
                    }
                }
                return;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetContentTreeForTopLevel, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return;
        }

        #endregion

        #region "Function: DMS_AHLdmsGetContentTree(4)"
        /// <summary>
        /// Get content tree.
        /// </summary>
        /// <param name="pContainerID"></param>
        /// <param name="pStartIndex"></param>
        /// <param name="pRequestCount"></param>
        /// <param name="pContentTree"></param>
        /// <returns></returns>
        public static void DMS_AHLdmsGetContentTree(string pContainerID, int pStartIndex, int pRequestCount, ref ContentTree pContentTree)
        {
            string sContentTree = Constant.STRING_EMPTY;

            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetContentTreeForChild, Constant.PARAM_pContainerID + pContainerID.ToString() + Constant.COMMA_SIGN + Constant.STRING_SPACE + Constant.PARAM_pStartIndex + pStartIndex.ToString() + Constant.COMMA_SIGN + Constant.STRING_SPACE + Constant.PARAM_pRequestCount + pRequestCount.ToString() + Constant.COMMA_SIGN + Constant.STRING_SPACE + Constant.PARAM_pShareFolderList + pContentTree.ToString());

                LibraryCallMutex.WaitOne();
                IntPtr intPtrGetDeviceDescription = ServiceManager.AHLdmsGetContentTree(intptrWrapperobj, pContainerID, pStartIndex, pRequestCount, sContentTree);                

                if (intPtrGetDeviceDescription == IntPtr.Zero)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetContentTreeForChild, Constant.ERROR_STRING_DMS_AHLdmsGetContentTree);
                }
                else
                {
                    sContentTree = Marshal.PtrToStringUni(intPtrGetDeviceDescription);
                    LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetContentTreeForChild, Constant.LOG_RESPONCE + sContentTree.ToString());
                }

                if ((sContentTree != null) && (sContentTree.Length > 0))
                {
                    pContentTree = XMLManager.readContentTreeXml(sContentTree);

                }
                return;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsGetContentTreeForChild, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return;
        }

        #endregion

        #region "Function: DMS_AHLdmsSetContentShare(3)"
        /// <summary>
        /// set content share.
        /// </summary>
        /// <param name="pContentId"></param>
        /// <param name="pIsShare"></param>
        /// <param name="pIsRecursive"></param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsSetContentShare(string pContentId, bool pIsShare, bool pIsRecursive)
        {
            DMSParameters.returnValue retResponse = DMSParameters.returnValue.NFLC_E_ERROR;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsSetContentShare, Constant.PARAM_pContentId + pContentId.ToString() + Constant.COMMA_SIGN + Constant.STRING_SPACE + Constant.PARAM_pIsShare + pIsShare.ToString() + Constant.COMMA_SIGN + Constant.STRING_SPACE + Constant.PARAM_pIsRecursive + pIsRecursive.ToString());

                LibraryCallMutex.WaitOne();
                retResponse = AHLdmsSetContentShare(intptrWrapperobj, pContentId, pIsShare, pIsRecursive);

                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsSetContentShare, Constant.LOG_RESPONCE + retResponse.ToString());

                if (retResponse != DMSParameters.returnValue.NFLC_E_OK)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsSetContentShare, Constant.ERROR_STRING_DMS_AHLdmsSetContentShare + retResponse.ToString());
                    return retResponse;
                }
                return retResponse;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsSetContentShare, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return retResponse;
        }

        #endregion

        #region "Function: DMS_AHLdmsBrowseContent(3)"
        /// <summary>
        /// Browse Contant.
        /// </summary>
        /// <param name="pID"></param>
        /// <param name="pStartIndex"></param>
        /// <param name="pRequestCount"></param>
        /// <returns></returns>
        public static string DMS_AHLdmsBrowseContent(string pID, uint pStartIndex, uint pRequestCount)
        {
            string sBrowseContent = Constant.STRING_EMPTY;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsBrowseContent, Constant.PARAM_pID + pID.ToString() + Constant.COMMA_SIGN + Constant.STRING_SPACE + Constant.PARAM_pStartIndex + pStartIndex.ToString() + Constant.COMMA_SIGN + Constant.STRING_SPACE + Constant.PARAM_pRequestCount + pRequestCount.ToString());

                LibraryCallMutex.WaitOne();
                IntPtr intPtrBrowseContent = ServiceManager.AHLdmsBrowseContent(intptrWrapperobj, pID, sBrowseContent, pStartIndex, pRequestCount);                

                if (intPtrBrowseContent == IntPtr.Zero)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsBrowseContent, Constant.ERROR_STRING_DMS_AHLdmsBrowseContent);
                    return Constant.STRING_EMPTY;
                }
                else
                {
                    sBrowseContent = Marshal.PtrToStringUni(intPtrBrowseContent);
                    LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsBrowseContent, Constant.LOG_RESPONCE + sBrowseContent.ToString());
                }
                return sBrowseContent;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsBrowseContent, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return sBrowseContent;
        }

        #endregion

        #region "Function: DMS_AHLdmsSearchContent(4)"
        /// <summary>
        /// search Contant.
        /// </summary>
        /// <param name="pID"></param>
        /// <param name="pCriteria"></param>
        /// <param name="pStartIndex"></param>
        /// <param name="pRequestCount"></param>
        /// <returns></returns>
        public static string DMS_AHLdmsSearchContent(string pID, string pCriteria, uint pStartIndex, uint pRequestCount)
        {
            string sSearchContent = Constant.STRING_EMPTY;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsSearchContent, Constant.PARAM_pID + pID.ToString() + Constant.COMMA_SIGN + Constant.STRING_SPACE + Constant.PARAM_pCriteria + pCriteria.ToString() + Constant.COMMA_SIGN + Constant.STRING_SPACE + Constant.PARAM_pStartIndex + pStartIndex.ToString() + Constant.COMMA_SIGN + Constant.STRING_SPACE + Constant.PARAM_pRequestCount + pRequestCount.ToString());

                LibraryCallMutex.WaitOne();
                IntPtr intPtrSearchContent = ServiceManager.AHLdmsSearchContent(intptrWrapperobj, pID, pCriteria, sSearchContent, pStartIndex, pRequestCount);                
                if (intPtrSearchContent == IntPtr.Zero)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsSearchContent, Constant.ERROR_STRING_DMS_AHLdmsSearchContent);
                    return Constant.STRING_EMPTY;
                }
                else
                {
                    sSearchContent = Marshal.PtrToStringUni(intPtrSearchContent);
                    LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsSearchContent, Constant.LOG_RESPONCE + sSearchContent.ToString());
                }
                return sSearchContent;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsSearchContent, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return sSearchContent;
        }

        #endregion

        #endregion

        #region "PGLevelManager Functions"

        #region "Function: DMS_AHLdmsPGGetDefaultLevel(1)"
        /// <summary>
        /// It will fetch the default pg level
        /// </summary>
        /// <param name="pLevelType">It indicates pg level type, whether its device or content.</param>
        /// <returns></returns>
        public static int DMS_AHLdmsPGGetDefaultLevel(DMSParameters.dmsPGLevelType pLevelType)
        {
            int pLevel = 0;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGGetDefaultLevel, Constant.PARAM_pLevelType + pLevelType.ToString());

                LibraryCallMutex.WaitOne();
                DMSParameters.returnValue retResponse = AHLdmsPGGetDefaultLevel(intptrWrapperobj, pLevelType, out pLevel);

                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGGetDefaultLevel, Constant.LOG_RESPONCE + pLevel.ToString());

                if ((retResponse != DMSParameters.returnValue.NFLC_E_OK))
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGGetDefaultLevel, Constant.ERROR_STRING_DMS_AHLdmsPGGetDefaultLevel + retResponse.ToString());
                    return -1;
                }
                return pLevel;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGGetDefaultLevel, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return pLevel;
        }
        #endregion

        #region "Function: DMS_AHLdmsPGSetDefaultDeviceLevel(2)"
        /// <summary>
        /// It will set the default pg level
        /// </summary>
        /// <param name="pLevelType">It indicates pg level type, whether its device or content.</param>
        /// <param name="pDefaultLevel">indicated level id</param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsPGSetDefaultDeviceLevel(DMSParameters.dmsPGLevelType pLevelType, int pDefaultLevel)
        {
            DMSParameters.returnValue retResponse = DMSParameters.returnValue.NFLC_E_ERROR;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGSetDefaultDeviceLevel, Constant.PARAM_pLevelType + pLevelType.ToString() + Constant.COMMA_SIGN + Constant.STRING_SPACE + Constant.PARAM_pDefaultLevel + pDefaultLevel.ToString());

                LibraryCallMutex.WaitOne();
                retResponse = AHLdmsPGSetDefaultDeviceLevel(intptrWrapperobj, pLevelType, pDefaultLevel);                
                
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGSetDefaultDeviceLevel, Constant.LOG_RESPONCE + retResponse.ToString());

                if ((retResponse != DMSParameters.returnValue.NFLC_E_OK))
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGSetDefaultDeviceLevel, Constant.ERROR_STRING_DMS_AHLdmsPGSetDefaultDeviceLevel + retResponse.ToString());
                    return retResponse;
                }
                return retResponse;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGSetDefaultDeviceLevel, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return retResponse;
        }
        #endregion

        #region "Function: DMS_AHLdmsPGSetContentLevel(2)"
        /// <summary>
        /// It will set the pg level for content
        /// </summary>
        /// <param name="pContentId">ID for content</param>
        /// <param name="pLevel">Level ID</param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsPGSetContentLevel(string pContentId, int pLevel)
        {
            DMSParameters.returnValue retResponse = DMSParameters.returnValue.NFLC_E_ERROR;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGSetContentLevel, Constant.PARAM_pContentId + pContentId.ToString() + Constant.COMMA_SIGN + Constant.STRING_SPACE + Constant.PARAM_pLevel + pLevel.ToString());

                LibraryCallMutex.WaitOne();
                retResponse = AHLdmsPGSetContentLevel(intptrWrapperobj, pContentId, pLevel);                
                
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGSetContentLevel, Constant.LOG_RESPONCE + retResponse.ToString());

                if ((retResponse != DMSParameters.returnValue.NFLC_E_OK))
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGSetContentLevel, Constant.ERROR_STRING_DMS_AHLdmsPGSetContentLevel + retResponse.ToString());
                    return retResponse;
                }
                return retResponse;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGSetContentLevel, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return retResponse;
        }
        #endregion

        #region "Function: DMS_AHLdmsPGGetDeviceList(0)"
        /// <summary>
        /// It will return PG device list
        /// </summary>
        /// <returns>It returns list of devices</returns>
        [MethodImpl(MethodImplOptions.Synchronized)]
        public static List<DeviceEntity> DMS_AHLdmsPGGetDeviceList()
        {
            List<DeviceEntity> DeviceList = new List<DeviceEntity>();
            string sDeviceList = Constant.STRING_EMPTY;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGGetDeviceList);

                LibraryCallMutex.WaitOne();
                IntPtr intPtrDeviceList = ServiceManager.AHLdmsPGGetDeviceList(intptrWrapperobj, sDeviceList);

                if (intPtrDeviceList == IntPtr.Zero)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGGetDeviceList, Constant.ERROR_STRING_DMS_AHLdmsPGGetDeviceList);
                }
                else
                {
                    sDeviceList = Marshal.PtrToStringUni(intPtrDeviceList);
                    LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGGetDeviceList, Constant.LOG_RESPONCE + sDeviceList.ToString());
                }

                if ((sDeviceList != null) && (sDeviceList.Length > 0))
                {
                    DeviceList = XMLManager.readDeviceXml(sDeviceList);

                    LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGGetDeviceList, "Total Device Count : " + DeviceList.Count);
                }
                return DeviceList;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGGetDeviceList, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return DeviceList;
        }
        #endregion      

        #region "Function: DMS_AHLdmsPGGetLevelList(0)"
        /// <summary>
        /// It fetches PG level list
        /// </summary>
        /// <returns>It returns PG level list</returns>
        public static List<PGLevelEntity> DMS_AHLdmsPGGetLevelList()
        {
            string sLevelList = Constant.STRING_EMPTY;
            List<PGLevelEntity> oPGLevelList = new List<PGLevelEntity>();
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGGetLevelList);

                LibraryCallMutex.WaitOne();
                IntPtr intPtrLevelList = ServiceManager.AHLdmsPGGetLevelList(intptrWrapperobj, sLevelList);                

                if (intPtrLevelList == IntPtr.Zero)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGGetLevelList, Constant.ERROR_STRING_DMS_AHLdmsPGGetLevelList);
                }
                else
                {
                    sLevelList = Marshal.PtrToStringUni(intPtrLevelList);
                    LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGGetLevelList, Constant.LOG_RESPONCE + sLevelList.ToString());
                }

                if ((sLevelList != null) && (sLevelList.Length > 0))
                {
                    oPGLevelList = XMLManager.readPGLevelXml(sLevelList);
                }
                return oPGLevelList;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGGetLevelList, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return oPGLevelList;
        }
        #endregion

        #region "Function: DMS_AHLdmsPGSetDeviceParams(3)"
        /// <summary>
        /// It sets the device parameters
        /// </summary>
        /// <param name="pDeviceMAC">Device MAC address</param>
        /// <param name="pLevel">Level ID</param>
        /// <param name="pDescription">Description of device</param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsPGSetDeviceParams(string pDeviceMAC, int pLevel, string pDescription)
        {
            DMSParameters.returnValue retResponse = DMSParameters.returnValue.NFLC_E_ERROR;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGSetDeviceParams, Constant.PARAM_pDeviceMAC + pDeviceMAC.ToString() + Constant.COMMA_SIGN + Constant.STRING_SPACE + Constant.PARAM_pLevel + pLevel.ToString() + Constant.COMMA_SIGN + Constant.STRING_SPACE + Constant.PARAM_pDescription + pDescription);

                LibraryCallMutex.WaitOne();
                retResponse = AHLdmsPGSetDeviceParams(intptrWrapperobj, pDeviceMAC, pLevel, pDescription);
                
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGSetDeviceParams, Constant.LOG_RESPONCE + retResponse.ToString());

                if ((retResponse != DMSParameters.returnValue.NFLC_E_OK))
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGSetDeviceParams, Constant.ERROR_STRING_DMS_AHLdmsPGSetDeviceParams + retResponse.ToString());
                    return retResponse;
                }
                return retResponse;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGSetDeviceParams, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return retResponse;
        }
        #endregion

        #region "Function: DMS_AHLdmsPGDeleteDeviceByMac(1)"
        /// <summary>
        /// It deletes the device by Device MAC addredd
        /// </summary>
        /// <param name="pDeviceMAC">Its device MAC address</param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsPGDeleteDeviceByMac(string pDeviceMAC)
        {
            DMSParameters.returnValue retResponse = DMSParameters.returnValue.NFLC_E_ERROR;
            try
            {
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGDeleteDeviceByMac, Constant.PARAM_pDeviceMAC + pDeviceMAC.ToString());

                LibraryCallMutex.WaitOne();
                retResponse = AHLdmsPGDeleteDeviceByMac(intptrWrapperobj, pDeviceMAC);

                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGDeleteDeviceByMac, Constant.LOG_RESPONCE + retResponse.ToString());

                if ((retResponse != DMSParameters.returnValue.NFLC_E_OK))
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGDeleteDeviceByMac, Constant.ERROR_STRING_DMS_AHLdmsPGDeleteDeviceByMac + retResponse.ToString());
                    return DMSParameters.returnValue.NFLC_E_ERROR;
                }
                return retResponse;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsPGDeleteDeviceByMac, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return retResponse;
        }
        #endregion

        #region "Function: DMSStop(1)"
        /// <summary>
        /// It will start the service
        /// </summary>
        /// <returns></returns>
        public static DMSParameters.returnValue DMSStart()
        {
            DMSParameters.returnValue retValue = DMSParameters.returnValue.NFLC_E_ERROR;
            try
            {
                LibraryCallMutex.WaitOne();
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsStart);
                retValue = AHLdmsStart(intptrWrapperobj);
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsStart, Constant.LOG_RESPONCE + retValue.ToString());
                if (retValue != DMSParameters.returnValue.NFLC_E_OK)
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsFinalize, Constant.ERROR_STRING_DMS_AHLdmsFInalize);
                return retValue;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsStart, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return retValue;
        }
        #endregion

        #region "Function: DMSStop(1)"
        /// <summary>
        /// DMSStop
        /// </summary>
        /// <returns></returns>
        public static DMSParameters.returnValue DMSStop()
        {
            DMSParameters.returnValue retValue = DMSParameters.returnValue.NFLC_E_ERROR;
            try
            {
                LibraryCallMutex.WaitOne();
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsStop);
                retValue = AHLdmsStop(intptrWrapperobj);
                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsStop, Constant.LOG_RESPONCE + retValue.ToString());
                if (retValue != DMSParameters.returnValue.NFLC_E_OK)
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsStop, Constant.ERROR_STRING_DMS_AHLdmsFInalize);
                return retValue;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsStop, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return retValue;
        }
        #endregion
        #endregion

        #endregion

        #region "Content Aggregation Features"

        #region "Function: DMS_AHLdmsCASetEnabled(1)"
        /// <summary>
        /// To set CA Enable | Disable
        /// </summary>
        /// <param name="pIsEnable"></param>

        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsCASetEnabled(bool pIsEnable)
        {
            DMSParameters.returnValue retResponse = DMSParameters.returnValue.NFLC_E_ERROR;
            try
            {

                LibraryCallMutex.WaitOne();
                retResponse = ServiceManager.AHLdmsCASetEnabled(intptrWrapperobj, pIsEnable);

                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsCASetEnabled, Constant.LOG_RESPONCE + retResponse.ToString());

                if (retResponse != DMSParameters.returnValue.NFLC_E_OK)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsCASetEnabled, Constant.ERROR_STRING_DMS_AHLdmsSetContentShare + retResponse.ToString());
                    return retResponse;
                }
                return retResponse;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsCASetEnabled, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return retResponse;
        }

        #endregion

        #region "Function: DMS_AHLdmsCAIsEnabled(1)"
        /// <summary>
        /// Check CA is enabled.
        /// </summary>
        /// <param name="pIsEnable"></param>

        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsCAIsEnabled(out bool pIsEnable)
        {
            DMSParameters.returnValue retResponse = DMSParameters.returnValue.NFLC_E_ERROR;
            pIsEnable = false;
            try
            {

                LibraryCallMutex.WaitOne();
                retResponse = ServiceManager.AHLdmsCAIsEnabled(intptrWrapperobj, out pIsEnable);

                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsCAIsEnabled, Constant.LOG_RESPONCE + retResponse.ToString());

                if (retResponse != DMSParameters.returnValue.NFLC_E_OK)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsCAIsEnabled, Constant.ERROR_STRING_DMS_AHLdmsSetContentShare + retResponse.ToString());
                    return retResponse;
                }
                return retResponse;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsCAIsEnabled, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return retResponse;
        }

        #endregion


        #region "Function: DMS_AHLdmsCAExecuteCommand(1)"
        /// <summary>
        /// Set CA to Pause | Resume
        /// </summary>
        /// <param name="pIsEnable"></param>

        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsCAExecuteCommand(DMSParameters.dmsCACommand cmd)
        {
            DMSParameters.returnValue retResponse = DMSParameters.returnValue.NFLC_E_ERROR;
            try
            {

                LibraryCallMutex.WaitOne();
                retResponse = ServiceManager.AHLdmsCAExecuteCommand(intptrWrapperobj, cmd);

                LogManager.logRequestResponceMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsCAExecuteCommand, Constant.LOG_RESPONCE + retResponse.ToString());

                if (retResponse != DMSParameters.returnValue.NFLC_E_OK)
                {
                    LogManager.logMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsCAExecuteCommand, Constant.ERROR_STRING_DMS_AHLdmsSetContentShare + retResponse.ToString());
                    return retResponse;
                }
                return retResponse;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsCAExecuteCommand, ex);
            }
            finally
            {
                LibraryCallMutex.ReleaseMutex();
            }
            return retResponse;
        }

        #endregion
        #endregion
    }
}
