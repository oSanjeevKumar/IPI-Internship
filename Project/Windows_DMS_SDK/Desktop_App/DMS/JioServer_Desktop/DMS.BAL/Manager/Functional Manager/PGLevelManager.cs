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
using DMS.BAL.Entity.Service_Entity;
using DMS.BAL.Manager.Common_Manager;
using DMS.BAL.Entity;

namespace DMS.BAL.Manager.Functional_Manager
{
    public class PGLevelManager
    {
        #region "Function"

        #region "Function: DMS_AHLdmsPGGetDefaultLevel(1)"
        /// <summary>
        /// Dms the s_ ah LDMS pg get default level.
        /// </summary>
        /// <param name="pLevelType">It indicates pg level type, whether its device or content.</param>
        /// <returns></returns>
        public static int DMS_AHLdmsPGGetDefaultLevel(DMSParameters.dmsPGLevelType pLevelType)
        {
            bool dmsStatus = ConfigurationManager.GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsPGGetDefaultLevel(pLevelType);
            }
            return -1;
        }

        #endregion

        #region "Function: DMS_AHLdmsPGSetDefaultDeviceLevel(2)"
        /// <summary>
        /// Dms the s_ ah LDMS pg set default device level.
        /// </summary>
        /// <param name="pLevelType">It indicates pg level type, whether its device or content.</param>
        /// <param name="pDefaultLevel">indicated level id</param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsPGSetDefaultDeviceLevel(DMSParameters.dmsPGLevelType pLevelType, int pDefaultLevel)
        {
            bool dmsStatus = ConfigurationManager.GetServiceLastState();
            if (dmsStatus)
            {
                DMSParameters.returnValue value = ServiceManager.DMS_AHLdmsPGSetDefaultDeviceLevel(pLevelType, pDefaultLevel);
                return value;
            }
            return DMSParameters.returnValue.NFLC_E_ERROR;
        }

        #endregion

        #region "Function: DMS_AHLdmsPGSetContentLevel(2)"
        /// <summary>
        /// Dms the s_ ah LDMS pg set content level.
        /// </summary>
        /// <param name="pContentID">ID for content</param>
        /// <param name="pLevel">Level ID</param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsPGSetContentLevel(string pContentID, int pLevel)
        {
            bool dmsStatus = ConfigurationManager.GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsPGSetContentLevel(pContentID, pLevel);
            }
            return DMSParameters.returnValue.NFLC_E_ERROR;
        }

        #endregion

        #region "Function: DMS_AHLdmsPGGetDeviceList(0)"      
        /// <summary>
        /// Dms the s_ ah LDMS pg get device list.
        /// </summary>
        /// <returns></returns>
        public static List<DeviceEntity> DMS_AHLdmsPGGetDeviceList()
        {
            bool dmsStatus = ConfigurationManager.GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsPGGetDeviceList();
            }
            return new List<DeviceEntity>();
        }

        #endregion

        #region "Function: DMS_AHLdmsPGGetLevelList(0)"       
        /// <summary>
        /// Dms the s_ ah LDMS pg get level list.
        /// </summary>
        /// <returns></returns>
        public static List<PGLevelEntity> DMS_AHLdmsPGGetLevelList()
        {
            bool dmsStatus = ConfigurationManager.GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsPGGetLevelList();
            }
            return new List<PGLevelEntity>();
        }

        #endregion

        #region "Function: DMS_AHLdmsPGSetDeviceParams(3)"
        /// <summary>
        /// Dms the s_ ah LDMS pg set device parameters.
        /// </summary>
        /// <param name="pDeviceMAC">Device MAC address</param>
        /// <param name="pLevel">Level ID</param>
        /// <param name="pDescription">Description of device</param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsPGSetDeviceParams(string pDeviceMAC, int pLevel, string pDescription)
        {
            bool dmsStatus = ConfigurationManager.GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsPGSetDeviceParams(pDeviceMAC, pLevel, pDescription);
            }
            return DMSParameters.returnValue.NFLC_E_ERROR;
        }

        #endregion

        #region "Function: DMS_AHLdmsPGDeleteDeviceByMac(1)"
        /// <summary>
        /// Dms the s_ ah LDMS pg delete device by mac.
        /// </summary>
        /// <param name="pDeviceMAC">Its device MAC address</param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsPGDeleteDeviceByMac(string pDeviceMAC)
        {
            bool dmsStatus = ConfigurationManager.GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsPGDeleteDeviceByMac(pDeviceMAC);
            }
            return DMSParameters.returnValue.NFLC_E_ERROR;
        }

        #endregion

        #endregion
    }
}
