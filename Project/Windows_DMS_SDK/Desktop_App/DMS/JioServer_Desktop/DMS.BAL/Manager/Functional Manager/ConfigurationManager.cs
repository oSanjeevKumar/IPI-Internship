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
using DMS.BAL.Manager.Common_Manager;
using DMS.BAL.Entity.Service_Entity;
using System.Windows;

namespace DMS.BAL.Manager.Functional_Manager
{
    public class ConfigurationManager
    {
        #region "Property"
        public static IntPtr DMSWrapperObject
        {
            get
            {
                return ServiceManager.intptrWrapperobj;
            }
            set
            {
                ServiceManager.intptrWrapperobj = value;
            }
        }
        public static bool IsDMSWrapperCreated = false;

        #endregion

        #region "Function"

        #region "Function: DMS_CreateDMSWrapperClass(0)"
        /// <summary>
        /// Dms the s_ create DMS wrapper class.
        /// </summary>
        /// <returns></returns>
        public static IntPtr DMS_CreateDMSWrapperClass()
        {
            IsDMSWrapperCreated = true;
            return ServiceManager.DMS_CreateDMSWrapperClass();
        }

        #endregion

        #region "Function: DMS_DeleteDMSWrapperClass(0)"
        /// <summary>
        /// Delete DMS wrapper class.
        /// </summary>
        /// <returns></returns>
        public static void DMS_DeleteDMSWrapperClass()
        {
            ServiceManager.DMS_DeleteDMSWrapperClass();
        }

        #endregion

        #region "Function: DMS_AHLdmsInitialize(1)"
        /// <summary>
        /// Dms the s_ ah LDMS initialize.
        /// </summary>
        /// <param name="pDmsInitializeParams">initialize parameters.</param>
        /// <returns></returns>
        public static bool DMS_AHLdmsInitialize(ref DMS.BAL.Entity.Service_Entity.DMSParameters.dmsInitParams pDmsInitializeParams)
        {
            return ServiceManager.DMS_AHLdmsInitialize(ref pDmsInitializeParams);
        }

        #endregion

        #region "Function: DMS_AHLdmsFinalize(1)"
        /// <summary>
        /// Call the finalize method of DMS wrapper
        /// </summary>
        /// <returns></returns>
        public static bool DMS_AHLdmsFinalize()
        {
            return ServiceManager.DMS_AHLdmsFinalize();
        }

        #endregion

        #region "Function: DMS_AHLdmsGetFriendlyName(0)"
        /// <summary>
        /// Dms the name of the s_ ah LDMS get friendly.
        /// </summary>
        /// <returns></returns>
        public static string DMS_AHLdmsGetFriendlyName()
        {
            bool dmsStatus = GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsGetFriendlyName();
            }
            return Constant.STRING_EMPTY;
        }

        #endregion

        #region "Function: DMS_AHLdmsSetFriendlyName(1)"
        /// <summary>
        /// Dms the name of the s_ ah LDMS set friendly.
        /// </summary>
        /// <param name="pDMSFriendlyname">friendlyname.</param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsSetFriendlyName(string pDMSFriendlyname)
        {
            bool dmsStatus = GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsSetFriendlyName(pDMSFriendlyname);
            }
            return DMSParameters.returnValue.NFLC_E_ERROR;
        }

        #endregion

        #region "Function: DMS_AHLdmsGetServerState(0)"
        /// <summary>
        /// Dms the state of the s_ ah LDMS get server.
        /// </summary>
        /// <returns></returns>
        public static DMSParameters.dmsState DMS_AHLdmsGetServerState()
        {
            bool dmsStatus = GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsGetServerState();
            }
            return DMSParameters.dmsState.DMS_STATE_DISABLE;
        }

        #endregion

        #region "Function: DMS_AHLdmsSetServerState(1)"
        /// <summary>
        /// Dms the state of the s_ ah LDMS set server.
        /// </summary>
        /// <param name="pState">State of Server</param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsSetServerState(DMSParameters.dmsState pState)
        {
            bool dmsStatus = GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsSetServerState(pState);
            }
            return DMSParameters.returnValue.NFLC_E_ERROR;
        }

        #endregion

        #region "Function: DMS_AHLdmsGetDeviceDescription(0)"
        /// <summary>
        /// Dms the s_ ah LDMS get device description.
        /// </summary>
        /// <returns></returns>
        public static string DMS_AHLdmsGetDeviceDescription()
        {
            bool dmsStatus = GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsGetDeviceDescription();
            }
            return Constant.STRING_EMPTY;
        }

        #endregion

        #region "Function: DMS_AHLdmsRefreshContentIndex(1)"
        /// <summary>
        /// Dms the index of the s_ ah LDMS refresh content.
        /// </summary>
        /// <param name="pIntPtrWrapperobj">Pointer of wrapperobj.</param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsRefreshContentIndex(IntPtr pIntPtrWrapperobj)
        {
            bool dmsStatus = GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsRefreshContentIndex(pIntPtrWrapperobj);
            }
            return DMSParameters.returnValue.NFLC_E_ERROR;
        }

        #endregion

        #region "Function: DMS_AHLdmsGetSupportedLanguages(1)"
        /// <summary>
        /// Dms the s_ ah LDMS get supported languages.
        /// </summary>
        /// <param name="pIntPtrWrapperobj">Pointer of wrapperobj.</param>
        /// <returns></returns>
        public static string DMS_AHLdmsGetSupportedLanguages(IntPtr pIntPtrWrapperobj)
        {
            bool dmsStatus = GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsGetSupportedLanguages(pIntPtrWrapperobj);
            }
            return Constant.STRING_EMPTY;
        }

        #endregion

        #region "Function: DMS_AHLdmsSetLanguage(1)"
        /// <summary>
        /// set language.
        /// </summary>
        /// <param name="pLanguage">language.</param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsSetLanguage(string pLanguage)
        {
            bool dmsStatus = GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsSetLanguage(pLanguage);
            }
            return DMSParameters.returnValue.NFLC_E_ERROR;
        }

        #endregion

        #region "Function: DMS_AHLdmsGetSelectedLanguage(1)"
        /// <summary>
        /// get selected language.
        /// </summary>
        /// <param name="pIntPtrWrapperobj">Pointer of wrapperobj.</param>
        /// <returns></returns>
        public static string DMS_AHLdmsGetSelectedLanguage(IntPtr pIntPtrWrapperobj)
        {
            bool dmsStatus = GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsGetSelectedLanguage(pIntPtrWrapperobj);
            }
            return Constant.STRING_EMPTY;
        }

        #endregion

        #region "Function: DMS_AHLdmsGetStorageCount(1)"
        /// <summary>
        /// get selected language.
        /// </summary>
        /// <param name="count">out pointer for storeage count.</param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsGetStorageCount(out int count)
        {
            bool dmsStatus = GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsGetPublishStoragesCount(out count);
            }
            count = 0;
            return DMSParameters.returnValue.NFLC_E_ERROR;
        }

        #endregion

        #region "Function: DMS_AHLdmsCASetEnabled(1)"
        /// <summary>
        /// get selected language.
        /// </summary>
        /// <param name="isEnable">bool for enabling.</param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsCASetEnabled(bool isEnable)
        {
            bool dmsStatus = GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsCASetEnabled(isEnable);
            }
            return DMSParameters.returnValue.NFLC_E_ERROR;
        }

        #endregion

        #region "Function: DMS_AHLdmsCAExecuteCommand(1)"
        /// <summary>
        /// get selected language.
        /// </summary>
        /// <param name="isEnable">bool for enabling.</param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsCAExecuteCommand(DMSParameters.dmsCACommand cmd)
        {
            bool dmsStatus = GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsCAExecuteCommand(cmd);
            }
            return DMSParameters.returnValue.NFLC_E_ERROR;
        }

        #endregion

        #region "Function: DMS_AHLdmsCAIsEnabled(1)"
        /// <summary>
        /// get selected language.
        /// </summary>
        /// <param name="isEnable">bool for enabling.</param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsCAIsEnabled(out bool isEnable)
        {
            bool dmsStatus = GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsCAIsEnabled(out isEnable);
            }
            isEnable = false;
            return DMSParameters.returnValue.NFLC_E_ERROR;
        }

        #endregion

        #region "Function: DMS_AHLdmsGetDefaultUploadPath(1)"
        /// <summary>
        /// get selected language.
        /// </summary>
        /// <param name="pIntPtrWrapperobj">Pointer of wrapperobj.</param>
        /// <returns></returns>
        public static string DMS_AHLdmsGetDefaultUploadPath()
        {
            bool dmsStatus = GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsPublishStorageGetDefaultUploadFolder();
            }
            return Constant.STRING_EMPTY;
        }

        #endregion

        #region "Function: readFirstInitlize(1)"
        /// <summary>
        /// Reads the first initlize.
        /// </summary>
        /// <returns></returns>
        public static bool readFirstInitlize()
        {
            return XMLManager.GetConfigValue(Constant.IS_FIRST_TIME_INITIALIZE);
        }

        #endregion

        #region "Function: writeFirstInitlize(1)"
        /// <summary>
        /// Writes the first initlize.
        /// </summary>
        /// <returns></returns>
        public static bool writeFirstInitlize()
        {
            return XMLManager.WriteConfigXML(Constant.IS_FIRST_TIME_INITIALIZE, false);
        }
        #endregion

        public static bool GetServiceLastState()
        {
            return XMLManager.GetConfigValue(Constant.SERVICE_STATE);
        }

        public static bool GetIsLogEnableStatus()
        {
            return XMLManager.GetConfigValue(Constant.IS_LOG_ENABLE);
        }

        public static bool SetServiceLastState(bool pValue)
        {
            return XMLManager.WriteConfigXML(Constant.SERVICE_STATE, pValue);
        }

        public static bool GetCAServiceLastState()
        {
            return XMLManager.GetConfigValue(Constant.CA_SERVICE_STATE);
        }

        public static bool SetCAServiceState(bool pValue)
        {
            return XMLManager.WriteConfigXML(Constant.CA_SERVICE_STATE, pValue);
        }

        public static DMSParameters.returnValue DMS_AHLdmsStopService()
        {
            return ServiceManager.DMSStop();
        }

        public static DMSParameters.returnValue DMS_AHLdmsStartService()
        {
            return ServiceManager.DMSStart();
        }

        public static bool GetCARunningLastState()
        {
            return XMLManager.GetConfigValue(Constant.CA_RUNNING_STATE);
        }

        public static bool SetCARunningState(bool pValue)
        {
            return XMLManager.WriteConfigXML(Constant.CA_RUNNING_STATE, pValue);
        }
        #endregion
    }
}
