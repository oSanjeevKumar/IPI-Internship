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
using DMS.BAL.Entity;
using DMS.BAL.Entity.App_Entity;

namespace DMS.BAL.Manager.Functional_Manager
{
    public class SharedFolderManager
    {
        #region "Function"

        #region "Function: DMS_AHLdmsPublishStorageAdd(1)"
        /// <summary>
        /// add publish storage.
        /// </summary>
        /// <param name="pPath">Folder path</param>
        /// <param name="pShareName">Folder Name</param>
        /// <param name="pID">Folder ID</param>
        /// <param name="pLocation"></param>
        /// <param name="pAutoIndex"></param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsPublishStorageAdd(string pPath, string pShareName, string pID, DMSParameters.dmsStorageDatabaseLocationType pLocation, bool pAutoIndex)
        {            
            bool dmsStatus = ConfigurationManager.GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsPublishStorageAdd(pPath, pShareName, pID, pLocation, pAutoIndex);
            }
            return DMSParameters.returnValue.NFLC_E_ERROR;
        }

        #endregion

        #region "Function: DMS_AHLdmsPublishStorageRemove(1)"
        /// <summary>
        /// remove publish storage.
        /// </summary>
        /// <param name="pPath">FolderPath</param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsPublishStorageRemove(string pPath)
        {
            bool dmsStatus = ConfigurationManager.GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsPublishStorageRemove(pPath);
            }
            return DMSParameters.returnValue.NFLC_E_ERROR;
        }

        #endregion

        #region "Function: DMS_AHLdmsPublishStorageUpdate(1)"
        /// <summary>
        /// update publish storage.
        /// </summary>
        /// <param name="pPath">FolderPath</param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsPublishStorageUpdate(string pPath)
        {
            bool dmsStatus = ConfigurationManager.GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsPublishStorageUpdate(pPath);
            }
            return DMSParameters.returnValue.NFLC_E_ERROR;
        }

        #endregion

        #region "Function: DMS_AHLdmsPublishStorageSetDefaultUploadFolder(1)"
        /// <summary>
        /// set default upload publish storage folder.
        /// </summary>
        /// <param name="pPath">FolderPath</param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsPublishStorageSetDefaultUploadFolder(string pPath)
        {
            bool dmsStatus = ConfigurationManager.GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsPublishStorageSetDefaultUploadFolder(pPath);
            }
            return DMSParameters.returnValue.NFLC_E_ERROR;
        }

        #endregion

        #region "Function: DMS_AHLdmsPublishStorageGetDefaultUploadFolder(0)"
        /// <summary>
        /// Dms the s_ ah LDMS publish storage get default upload folder.
        /// </summary>
        /// <returns></returns>
        public static string DMS_AHLdmsPublishStorageGetDefaultUploadFolder()
        {
            bool dmsStatus = ConfigurationManager.GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsPublishStorageGetDefaultUploadFolder();
            }
            return Constant.STRING_EMPTY;
        }

        #endregion

        #region "Function: DMS_AHLdmsGetPublishStorages(0)"
        /// <summary>
        /// Dms the s_ ah LDMS get publish storages.
        /// </summary>
        /// <returns></returns>
        public static List<SharedFolder> DMS_AHLdmsGetPublishStorages()
        {
            bool dmsStatus = ConfigurationManager.GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsGetPublishStorages();
            }
            return new List<SharedFolder>();
        }

        #endregion

        #region "Function: DMS_AHLdmsPublishStorageSetStorageCentralDir(1)"
        /// <summary>
        /// Dms the s_ ah LDMS publish storage set storage central dir.
        /// </summary>
        /// <param name="pOutputPath">Folderpath.</param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsPublishStorageSetStorageCentralDir(string pOutputPath)
        {
            return ServiceManager.DMS_AHLdmsPublishStorageSetStorageCentralDir(pOutputPath);
        }

        #endregion

        #region "Function: DMS_AHLdmsGetPublishStoragesCount(1)"
        /// <summary>
        /// Dms the s_ ah LDMS get publish storages count.
        /// </summary>
        /// <param name="pCount">total count of folder.</param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsGetPublishStoragesCount(out int pCount)
        {
            bool dmsStatus = ConfigurationManager.GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsGetPublishStoragesCount(out pCount);
            }
            pCount = 0;
            return DMSParameters.returnValue.NFLC_E_ERROR;
        }

        #endregion

        #region "Function: DMS_AHLdmsGetTotalContentsShared(2)"
        /// <summary>
        /// Dms the s_ ah LDMS get total contents shared.
        /// </summary>
        /// <param name="pContentClassType"></param>
        /// <param name="pResult"></param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsGetTotalContentsShared(DMSParameters.dmsContentClassType pContentClassType, out int pResult)
        {
            bool dmsStatus = ConfigurationManager.GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsGetTotalContentsShared(pContentClassType, out pResult);
            }
            pResult = 0;
            return DMSParameters.returnValue.NFLC_E_ERROR;
        }
      
        #endregion

        #region "Function: DMS_AHLdmsGetContentTree(4)"
        /// <summary>
        /// Dms the s_ ah LDMS get content tree.
        /// </summary>
        /// <param name="pContainerID"></param>
        /// <param name="pStartIndex"></param>
        /// <param name="pRequestCount"></param>
        /// <param name="pShareFolderList"></param>
        /// <returns></returns>
        public static void DMS_AHLdmsGetContentTree(ref List<SharedFolder> pShareFolderList)
        {
            bool dmsStatus = ConfigurationManager.GetServiceLastState();
            if (dmsStatus == true)
            {
                ServiceManager.DMS_AHLdmsGetContentTree("0", 0, ServerManager.oSharedFolderList.Count, ref pShareFolderList);
            }
        }

        #endregion

        #region "Function: DMS_AHLdmsGetContentTree(4)"
        /// <summary>
        /// Dms the s_ ah LDMS get content tree.
        /// </summary>
        /// <param name="pContainerID"></param>
        /// <param name="pStartIndex"></param>
        /// <param name="pRequestCount"></param>
        /// <param name="pContentTree"></param>
        /// <returns></returns>
        public static void DMS_AHLdmsGetContentTree(string pContainerID, int pStartIndex, int pRequestCount, ref ContentTree pContentTreet)
        {
            bool dmsStatus = ConfigurationManager.GetServiceLastState();
            if (dmsStatus)
            {
                ServiceManager.DMS_AHLdmsGetContentTree(pContainerID, pStartIndex, pRequestCount, ref pContentTreet);
            }
        }

        #endregion

        #region "Function: DMS_AHLdmsSetContentShare(2)"
        /// <summary>
        /// Dms the s_ ah LDMS set content share.
        /// </summary>
        /// <param name="pContentId">The p content identifier.</param>
        /// <param name="pIsShare">if set to <c>true</c> [p is share].</param>
        /// <param name="pIsRecursive">if set to <c>true</c> [p is recursive].</param>
        /// <returns></returns>
        public static DMSParameters.returnValue DMS_AHLdmsSetContentShare(string pContentId, bool pIsShare, bool pIsRecursive)
        {
            bool dmsStatus = ConfigurationManager.GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsSetContentShare(pContentId, pIsShare, pIsRecursive);
            }
            return DMSParameters.returnValue.NFLC_E_ERROR;
        }

        #endregion

        #region "Function: DMS_AHLdmsBrowseContent(2)"
        /// <summary>
        /// Dms the content of the s_ ah LDMS browse.
        /// </summary>
        /// <param name="pID"></param>
        /// <param name="pStartIndex"></param>
        /// <param name="pRequestCount"></param>
        /// <returns></returns>
        public static string DMS_AHLdmsBrowseContent(string pID, uint pStartIndex, uint pRequestCount)
        {
            bool dmsStatus = ConfigurationManager.GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsBrowseContent(pID, pStartIndex, pRequestCount);
            }
            return Constant.STRING_EMPTY;
        }

        #endregion

        #region "Function: DMS_AHLdmsSearchContent(4)"
        /// <summary>
        /// Dms the content of the s_ ah LDMS search.
        /// </summary>
        /// <param name="pID"></param>
        /// <param name="pCriteria"></param>
        /// <param name="pStartIndex"></param>
        /// <param name="pRequestCount"></param>
        /// <returns></returns>
        public static string DMS_AHLdmsSearchContent(string pID, string pCriteria, uint pStartIndex, uint pRequestCount)
        {
            bool dmsStatus = ConfigurationManager.GetServiceLastState();
            if (dmsStatus)
            {
                return ServiceManager.DMS_AHLdmsSearchContent(pID, pCriteria, pStartIndex, pRequestCount);
            }
            return Constant.STRING_EMPTY;
        }

        public static bool ValidateSharedFolder(SharedFolder pSharedFolder, List<SharedFolder> pSharedFolderList,ref string pErrMsg)
        {
            if (pSharedFolderList == null || pSharedFolderList.Count == 0)
            {
                pErrMsg = Constant.STRING_EMPTY;
                return true;
            }
            else
            {
                SharedFolder oSameFolder = null;
                if (pSharedFolder.SharedFolderPath.Length == Constant.DRIVE_LENGTH)
                {
                    oSameFolder = pSharedFolderList.Where(folder => pSharedFolder.SharedFolderPath == folder.updatedFolderPath).FirstOrDefault();
                }
                else
                {
                    oSameFolder = pSharedFolderList.Where(folder => pSharedFolder.SharedFolderPath == folder.SharedFolderPath).FirstOrDefault();
                }
                
                if (oSameFolder != null)
                {
                    pErrMsg = pErrMsg + pSharedFolder.SharedFolderPath + Constant.STRING_SPACE + Constant.ERROR_FOLDER_ALREADY_SHARED + Environment.NewLine;
                    return false;
                }

                int storagePathLength = pSharedFolder.SharedFolderPath.Length;
                string updatedFolderpath = null;
                //In case of root folder, no need to append "\\"
                if (pSharedFolder.SharedFolderPath[storagePathLength - 1] == '\\')
                {
                    updatedFolderpath = pSharedFolder.SharedFolderPath;

                } else
                {
                    updatedFolderpath = pSharedFolder.SharedFolderPath + "\\";
                }
                //Check scenario if parent folder is already shared                               

                SharedFolder oParentFolder = pSharedFolderList.Where(folder => updatedFolderpath.Contains(folder.updatedFolderPath)).FirstOrDefault();
                //SharedFolder oParentFolder = pSharedFolderList.Where(folder => pSharedFolder.SharedFolderPath.Contains(folder.SharedFolderPath)).FirstOrDefault();
                if (oParentFolder != null)
                {
                    pErrMsg = pErrMsg + Constant.PARENT_FOLDER_SHARE_ERROR + pSharedFolder.SharedFolderPath + Environment.NewLine;
                    return false;
                }

                List<SharedFolder> oParentFolderList = pSharedFolderList.Where(folder => folder.updatedFolderPath.Contains(updatedFolderpath)).ToList();                
                if (oParentFolderList != null && oParentFolderList.Count > 0)
                {
                    foreach (SharedFolder oSubFolder in oParentFolderList)
                    {
                        ServiceManager.DMS_AHLdmsPublishStorageRemove(oSubFolder.SharedFolderPath);
                        pErrMsg = pErrMsg + Constant.SUB_FOLDER_UNSHARE + oSubFolder.SharedFolderPath + Environment.NewLine;
                    }

                    System.Threading.Thread.Sleep(1000);

                    return true;
                }
            }
            return true;
        }


        #endregion

        #endregion
    }
}
