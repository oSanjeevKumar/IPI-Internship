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

 
﻿using DMS.BAL.Entity;
using DMS.BAL.Entity.Service_Entity;
using DMS.BAL.Entity.App_Entity;
using DMS.BAL.Manager.Common_Manager;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace DMS.BAL.Manager.Functional_Manager
{
    public class ServerManager
    {
        #region "Declarations(0)"

        public static List<SharedFolder> oSharedFolderList { get; set; }
        public static List<StorageStateEntity> oStorageStateList { get; set; }
        public static List<StoragePartialIndexingEntity> oStoragePartialIndexingList { get; set; }
        public static List<PGLevelEntity> oPGLevelList { get; set; }
        public static int oDefaultFolderPglevel { get; set; }
        public static int oDefaultDevicePglevel { get; set; }
        public static List<DeviceEntity> oDeviceList { get; set; }

        public static string DeviceFriednlyName { get; set; }
        public static string DefaultUploadFolder { get; set; }

        public delegate void updateTreeView();
        public static event updateTreeView eUpdateTreeView;

        public delegate void updateIndexingStatusView(bool isRefresh);
        public static event updateIndexingStatusView eUpdateIndexingStatusView;

        public delegate void updatePartialIndexingStatusView();
        public static event updatePartialIndexingStatusView eUpdatePartialIndexingStatusView;

        public delegate void updateDMSStateView(int DMSState);
        public static event updateDMSStateView eUpdateDMSStateView;

        // Used as flag, It will be true when new folder is published else false
        public static bool IsCalledAfterIndexing = false;

        #endregion

        #region "Enumerations(0)"
        #endregion

        #region "Properties(0)"

        #endregion

        #region "Methods(0)"

        #region "Method: dmsCallbackFunc(0)"
        /// <summary>
        /// Initializes the form.
        /// </summary>
        public static void dmsCallbackFunc(IntPtr arg, DMSParameters.dmsEvent in_event, IntPtr param)
        {
            //string paramString =  Marshal.PtrToStringAnsi(param);
            string argString = Marshal.PtrToStringAnsi(arg);
            string paramString = null;
            int paramInt = 0;
            if (in_event == DMSParameters.dmsEvent.DMS_EVENT_CA_STATE || in_event == DMSParameters.dmsEvent.DMS_EVENT_DMS_STATE)
            {
                paramInt = Marshal.ReadInt32(param);
                LogManager.logMessage(Constant.SHARED_USERCONTROL_CLASSNAME, " dmsCallbackFunc ", "arg: " + arg +
                    " in_event " + in_event + " param " + paramInt);
            }
            else
            {
                paramString = Marshal.PtrToStringAnsi(param);
                byte[] bytes = Encoding.Default.GetBytes(paramString);
                paramString = Encoding.UTF8.GetString(bytes);
                LogManager.logMessage(Constant.SHARED_USERCONTROL_CLASSNAME, " dmsCallbackFunc ", "arg: " + arg +
                    " in_event " + in_event + " param " + paramString);

            }
            
            switch (in_event)
            {
                case DMSParameters.dmsEvent.DMS_EVENT_CA_STATE:
                    break;
                case DMSParameters.dmsEvent.DMS_EVENT_DMS_STATE:
                    if (eUpdateDMSStateView != null)
                    {
                        eUpdateDMSStateView(paramInt);
                    }
                    break;
                case DMSParameters.dmsEvent.DMS_EVENT_INDEXING_STATE:
                    //Function to parse the param and update the variable in the oSharedList and update the UI.
                    StorageStateEntity entity = XMLManager.readIndexingCallbackResult(paramString);
                    bool flag = false;
                    if (oStorageStateList == null)
                    {
                      oStorageStateList = new List<StorageStateEntity>();
                    }
                    if (oStorageStateList != null && entity != null)
                    {
                        foreach (StorageStateEntity oState in oStorageStateList)
                        {
                          if (oState.storagePath.Equals(entity.storagePath))
                            {
                                if (entity.indexingLevel.Equals(Constant.INDEXING_LEVEL_FILESCAN))
                                {
                                    oState.indexingLevel = entity.indexingLevel;
                                    oState.indexingState = entity.indexingState;
                                }
                                flag = true;
                            }
                        }
                        if (flag == false)
                        {
                            oStorageStateList.Add(entity);
                        }
                        if (entity.indexingLevel.Equals(Constant.INDEXING_LEVEL_FILESCAN))
                        {
                            if (eUpdateIndexingStatusView != null)
                            {
                                eUpdateIndexingStatusView(false);
                            }
                        }
                    }

                    break;
                case DMSParameters.dmsEvent.DMS_EVENT_PARTIAL_INDEXING_STATE:
                    //Function to parse the param and update the variable in the storagePartialIndexingList and update the UI.
                    StoragePartialIndexingEntity partialEntity = XMLManager.readPartialIndexingCallbackResult(paramString);
                    flag = false;
                    if (oStoragePartialIndexingList == null)
                    {
                        oStoragePartialIndexingList = new List<StoragePartialIndexingEntity>();
                    }
                    if (oStoragePartialIndexingList != null && partialEntity != null)
                    {
                        foreach (StoragePartialIndexingEntity oState in oStoragePartialIndexingList)
                        {
                            if (oState.contentID.Equals(partialEntity.contentID))
                            {
                                if (partialEntity.partialIndexingMode.Equals(Constant.CONTENT_PARTIAL_INDEXING_PG))
                                {
                                    oState.partialIndexingMode = partialEntity.partialIndexingMode;
                                    oState.partialIndexingState = partialEntity.partialIndexingState;
                                }
                                flag = true;
                            }
                        }
                        if (flag == false)
                        {
                            oStoragePartialIndexingList.Add(partialEntity);
                        }
                        if (partialEntity.partialIndexingMode.Equals(Constant.CONTENT_PARTIAL_INDEXING_PG))
                        {
                            if (eUpdatePartialIndexingStatusView != null)
                            {
                                eUpdatePartialIndexingStatusView();
                            }
                        }
                    }
                    break;

                default:
                    LogManager.logMessage(Constant.SHARED_USERCONTROL_CLASSNAME, "dmsCallback", "callback arg: " + arg + " , in_event: " + in_event + "  param: " + param);
                    break;
            }
        }
        #endregion

        #region "Method: fillShareFolderList(0)"

        public static async Task<bool> fillShareFolderList()
        {
            return await Task.Run<bool>(() =>
            {               
                List<SharedFolder> pShareList = SharedFolderManager.DMS_AHLdmsGetPublishStorages();
                oSharedFolderList = pShareList;
                return true;
            });           
        }

        #endregion

        #region "Method: fillPGLevel(0)"
        /// <summary>
        /// Fills the pg level.
        /// </summary>
        public static async Task<bool> fillPGLevel()
        {
            return await Task.Run<bool>(() =>
            {
                oPGLevelList = PGLevelManager.DMS_AHLdmsPGGetLevelList();
                return true;
            });               
        }
        #endregion

        #region "Method: fillDefaultPGLevel(0)"
        /// <summary>
        /// fill Default Folder PGLevel
        /// </summary>
        public static async Task<bool> fillDefaultFolderPGLevel()
        {
            return await Task.Run<bool>(() =>
            {
                oDefaultFolderPglevel = PGLevelManager.DMS_AHLdmsPGGetDefaultLevel(DMSParameters.dmsPGLevelType.DMS_PG_LEVEL_TYPE_CONTENT);
                return true;
            }); 
            
        }
        #endregion

        #region "Method: fillDefaultDevicePGLevel(0)"
        /// <summary>
        /// fill Default Device PGLevel
        /// </summary>
        public static async Task<bool> fillDefaultDevicePGLevel()
        {
            return await Task.Run<bool>(() =>
            {
                oDefaultDevicePglevel = PGLevelManager.DMS_AHLdmsPGGetDefaultLevel(DMSParameters.dmsPGLevelType.DMS_PG_LEVEL_TYPE_DEVICE);
                return true;
            });             
        }
        #endregion

        #region "Method: fillDevice(0)"
        /// <summary>
        /// Fills the device.
        /// </summary>
        public static void fillDevice()
        {
            oDeviceList = PGLevelManager.DMS_AHLdmsPGGetDeviceList();    
            //File device pg level short name
            if (oDeviceList != null)
            {
                foreach (DeviceEntity oDevice in oDeviceList)
                {
                    if (oPGLevelList != null)
                    {
                        PGLevelEntity oPGLevel = oPGLevelList.Where(index => index.Id == oDevice.Level).FirstOrDefault();
                        if (oPGLevel != null)
                        {
                            oDevice.ShortPGLevel = oPGLevel.Name;
                        }
                    }
                }                
            }
        }

        #endregion

        #region "Method: dmsLogPrint(2)"
        /// <summary>
        /// Library Log
        /// </summary>
        /// <param name="arg"></param>
        /// <param name="str"></param>
        public static void dmsLogPrint(IntPtr arg, string str)
        {
            string argString = Marshal.PtrToStringAnsi(arg);
            LogManager.WriteLibraryLog(" arg: " + argString + " , str: " + str);
        }
        #endregion

        #region "UnshareNotAvailableFolder"
        /// <summary>
        /// UnshareNotAvailableFolder
        /// </summary>
        public async static Task<bool> UnshareNotAvailableFolder()
        {
            List<SharedFolder> oShareList = new List<SharedFolder>();
            oShareList = ServerManager.oSharedFolderList;
            bool isFolderUnshare = false;

            if ((oShareList != null) && (oShareList.Count > 0))
            {
                foreach (SharedFolder oItem in oShareList)
                {
                    if (!Directory.Exists(oItem.SharedFolderPath))
                    {
                        //Unshare
                        await Task.Run(() =>
                        {
                            isFolderUnshare = true;
                            SharedFolderManager.DMS_AHLdmsPublishStorageRemove(oItem.SharedFolderPath);
                        });
                    }
                }

                if (isFolderUnshare)
                {
                    await Task.Run(() => 
                    {
                        System.Threading.Thread.Sleep(3000);
                    });

                    await fillShareFolderList();
                    oShareList = ServerManager.oSharedFolderList;
                    await Task.Run(() =>
                    {
                        SharedFolderManager.DMS_AHLdmsGetContentTree(ref oShareList);
                    });

                    ServerManager.oSharedFolderList = oShareList;
                }
            }

            return true;
        }
        #endregion

        #endregion

        #region "Events(0)"
        #endregion
    }
}
