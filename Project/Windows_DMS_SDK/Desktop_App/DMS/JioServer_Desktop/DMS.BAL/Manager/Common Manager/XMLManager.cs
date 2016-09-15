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
using System.IO;
using System.Xml.Serialization;
using System.Xml;
using System.Reflection;
using DMS.BAL.Entity;
using DMS.BAL.Entity.App_Entity;

namespace DMS.BAL.Manager.Common_Manager
{
    class XMLManager
    {
        #region "Functions"

        #region "Function: readDeviceXml(1)"
        /// <summary>
        /// Reads the device XML.
        /// </summary>
        /// <param name="pXmlDevice">The p XML device.</param>
        /// <returns></returns>
        public static List<DeviceEntity> readDeviceXml(string pXmlDevice)
        {
            XmlDocument xmlDoc = new XmlDocument();
            XmlNodeList xmlNode;
            XmlNodeList isNodeExist;
            XmlNodeList isFriendlyNameNodeExist;
            XmlNodeList isDeviceIpAddressNodeExist;
            XmlElement NodeElement;

            StringReader srDevice = new StringReader(pXmlDevice);
            XmlTextReader xmlDevice = new XmlTextReader(srDevice);
            xmlDevice.Namespaces = false;

            DeviceEntity oDevice = new DeviceEntity();
            List<DeviceEntity> oDeviceList = new List<DeviceEntity>();

            //pXmlDevice = removeNonXml(pXmlDevice);

            try
            {
                xmlDoc.Load(xmlDevice);
                xmlNode = xmlDoc.SelectNodes(Constant.DEVICE_PARENT_NODE);

                foreach (XmlNode oNode in xmlNode)
                {
                    oDevice = new DeviceEntity();

                    NodeElement = (XmlElement)oNode;
                    isNodeExist = NodeElement.GetElementsByTagName(Constant.DEVICE_MAC_ADDRESS);
                    if (isNodeExist.Count > 0)
                    {
                        oDevice.MacAddress = isNodeExist[0].InnerText.ToString().Trim();
                    }

                    isDeviceIpAddressNodeExist = NodeElement.GetElementsByTagName(Constant.DEVICE_IP_ADDRESS);
                    if (isDeviceIpAddressNodeExist.Count > 0)
                    {
                        oDevice.IpAddress = isDeviceIpAddressNodeExist[0].InnerText.ToString().Trim();
                    }

                    isFriendlyNameNodeExist = NodeElement.GetElementsByTagName(Constant.DEVICE_FRIENDLY_NAME);
                    if (isFriendlyNameNodeExist.Count > 0)
                    {
                        oDevice.FriendlyName = isFriendlyNameNodeExist[0].InnerText.ToString().Trim();
                    }

                    isNodeExist = NodeElement.GetElementsByTagName(Constant.DEVICE_DESCRIPTION);
                    if (isNodeExist.Count > 0)
                    {
                        oDevice.DeviceDescription = isNodeExist[0].InnerText.ToString().Trim();
                    }

                    isNodeExist = NodeElement.GetElementsByTagName(Constant.DEVICE_LEVEL);
                    if (isNodeExist.Count > 0)
                    {
                        oDevice.Level = Convert.ToInt16(isNodeExist[0].InnerText);
                    }

                    if ((isFriendlyNameNodeExist.Count > 0) && (isDeviceIpAddressNodeExist.Count > 0))
                    {
                        oDevice.DeviceName = isFriendlyNameNodeExist[0].InnerText.ToString().Trim() + Constant.STRING_SPACE + Constant.ROUND_START_BRACKET + isDeviceIpAddressNodeExist[0].InnerText.ToString().Trim() + Constant.ROUND_END_BRACKET;
                    }
                    oDeviceList.Add(oDevice);
                }

                return oDeviceList;
            }
            catch (Exception ex)
            {
                //LOG
                LogManager.logExceptionMessage(Constant.XMLManager_CLASSNAME, Constant.FUNC_NAME_readDeviceXml, ex);
            }
            return oDeviceList;
        }

        #endregion

        #region "Function: readPGLevelXml(1)"
        /// <summary>
        /// Reads the pg level XML.
        /// </summary>
        /// <param name="pLevelList">The p level list.</param>
        /// <returns></returns>
        public static List<PGLevelEntity> readPGLevelXml(string pLevelList)
        {
            XmlDocument xmlDoc = new XmlDocument();
            XmlNodeList xmlNode;
            XmlElement NodeElement;
            XmlNodeList isNodeExist;
            StringReader srPGLevel = new StringReader(pLevelList);
            XmlTextReader xmlPGLevel = new XmlTextReader(srPGLevel);
            xmlPGLevel.Namespaces = false;

            PGLevelEntity oPGLevel = new PGLevelEntity();
            List<PGLevelEntity> oPGLevelList = new List<PGLevelEntity>();

            try
            {
                xmlDoc.Load(xmlPGLevel);
                xmlNode = xmlDoc.SelectNodes(Constant.PGLEVEL_PARENT_NODE);

                foreach (XmlNode oNode in xmlNode)
                {
                    oPGLevel = new PGLevelEntity();
                    NodeElement = (XmlElement)oNode;

                    isNodeExist = NodeElement.GetElementsByTagName(Constant.PGLEVEL_ID);
                    if (isNodeExist.Count > 0)
                    {
                        oPGLevel.Id = ((isNodeExist[0].InnerText != null) && (isNodeExist[0].InnerText.ToString().Trim().Length > 0)) ? Convert.ToInt16(isNodeExist[0].InnerText) : 0;
                    }

                    isNodeExist = NodeElement.GetElementsByTagName(Constant.PGLEVEL_ID);
                    if (isNodeExist.Count > 0)
                    {
                        oPGLevel.Name = oNode[Constant.PGLEVEL_NAME].InnerText.ToString().Trim();
                    }

                    isNodeExist = NodeElement.GetElementsByTagName(Constant.PGLEVEL_ID);
                    if (isNodeExist.Count > 0)
                    {
                        oPGLevel.Description = oNode[Constant.PGLEVEL_DESCRIPTION].InnerText.ToString().Trim();
                    }


                    if (oPGLevel.Description != null && oPGLevel.Description.Length > 0)
                    {
                        string sLastDegit = oPGLevel.Description.Substring(oPGLevel.Description.Length - 1, 1);
                        if (sLastDegit == Constant.STRING_DOT)
                        {
                            oPGLevel.Description = oPGLevel.Description.Substring(0, oPGLevel.Description.Length - 1);
                        }
                    }
                    oPGLevel.DisplayDescription = oPGLevel.Description + Constant.STRING_SPACE + Constant.ROUND_START_BRACKET + oPGLevel.Name + Constant.ROUND_END_BRACKET;

                    oPGLevelList.Add(oPGLevel);
                }
            }
            catch (Exception ex)
            {
                //LOG
                LogManager.logExceptionMessage(Constant.XMLManager_CLASSNAME, Constant.FUNC_NAME_readPGLevelXml, ex);
            }
            return oPGLevelList;
        }

        #endregion

        #region "Function: readShareFolderXml(1)"
        /// <summary>
        /// Reads the share folder XML.
        /// </summary>
        /// <param name="pXmlShareFolder">The p XML share folder.</param>
        /// <returns></returns>
        public static List<SharedFolder> readShareFolderXml(string pXmlShareFolder)
        {
            XmlDocument xmlDoc = new XmlDocument();
            XmlNodeList xmlNode;
            XmlElement NodeElement;
            XmlAttribute isAttributeExist;
            StringReader srShareFolder = new StringReader(pXmlShareFolder);
            XmlTextReader xmlShareFolder = new XmlTextReader(srShareFolder);
            xmlShareFolder.Namespaces = false;

            SharedFolder oShareFolder = new SharedFolder();
            List<SharedFolder> oShareFolderList = new List<SharedFolder>();

            try
            {
                xmlDoc.Load(xmlShareFolder);
                xmlNode = xmlDoc.SelectNodes(Constant.SHAREFOLDER_PARENT_NODE);

                for (int iIndex = 0; iIndex < xmlNode.Count; iIndex++)
                {
                    oShareFolder = new SharedFolder();

                    NodeElement = (XmlElement)xmlNode[iIndex];
                    isAttributeExist = NodeElement.GetAttributeNode(Constant.SHAREFOLDER_NAME);
                    if (isAttributeExist != null)
                    {
                        oShareFolder.FolderName = isAttributeExist.InnerText.ToString().Trim();
                        oShareFolder.ContainerID = isAttributeExist.InnerText.ToString().Trim();
                    }

                    isAttributeExist = NodeElement.GetAttributeNode(Constant.SHAREFOLDER_PATH);
                    if (isAttributeExist != null)
                    {
                        oShareFolder.SharedFolderPath = isAttributeExist.InnerText.ToString().Trim();
                    }

                    if (oShareFolder.SharedFolderPath != null)
                    {
                        oShareFolder.DisplayFolderPath = oShareFolder.SharedFolderPath.Replace("\\", "\"");
                        oShareFolder.updatedFolderPath = oShareFolder.SharedFolderPath + "\\";
                    }

                    oShareFolder.DisplayFolderName = System.IO.Path.GetFileName(oShareFolder.SharedFolderPath);
                    if (oShareFolder.DisplayFolderName == Constant.STRING_EMPTY)
                        oShareFolder.DisplayFolderName = oShareFolder.DisplayFolderPath;

                    oShareFolderList.Add(oShareFolder);
                }
                return oShareFolderList;
            }
            catch (Exception ex)
            {
                //LOG
                LogManager.logExceptionMessage(Constant.XMLManager_CLASSNAME, Constant.FUNC_NAME_readShareFolderXml, ex);
            }
            return oShareFolderList;
        }

        #endregion

        #region "Function: readShareFolderPGLevel(1)"
        /// <summary>
        /// Reads the share folder pg level.
        /// </summary>
        /// <param name="pXmlShareFolder">The p XML share folder.</param>
        /// <param name="pSharedFolderList">The p shared folder list.</param>
        /// <returns></returns>
        public static void readShareFolderPGLevel(string pXmlShareFolder, ref List<SharedFolder> pSharedFolderList)
        {
            XmlDocument xmlDoc = new XmlDocument();
            XmlNodeList xmlNode;
            XmlElement NodeElement;
            XmlNodeList isNodeExist;
            XmlAttribute isAttributeExist;

            pXmlShareFolder = pXmlShareFolder.Replace("&", "&amp;");
            StringReader srShareFolder = new StringReader(pXmlShareFolder);
            XmlTextReader xmlShareFolder = new XmlTextReader(srShareFolder);
            xmlShareFolder.Namespaces = false;

            SharedFolder oShareFolder = new SharedFolder();

            try
            {
                xmlDoc.Load(xmlShareFolder);
                xmlNode = xmlDoc.SelectNodes(Constant.SHAREFOLDER_CONTAINER);

                for (int iIndex = 0; iIndex < xmlNode.Count; iIndex++)
                {
                    if ((pSharedFolderList != null) && (pSharedFolderList.Count > 0))
                    {
                        NodeElement = (XmlElement)xmlNode[iIndex];
                        isNodeExist = NodeElement.GetElementsByTagName(Constant.SHAREFOLDER_TITLE);
                        if (isNodeExist.Count > 0)
                        {
                            oShareFolder = pSharedFolderList.Where(s => s.FolderName == isNodeExist[0].InnerText.ToString().Trim()).FirstOrDefault();
                        }

                        if (oShareFolder != null)
                        {
                            isNodeExist = NodeElement.GetElementsByTagName(Constant.SHARE_PGLEVEL);
                            if (isNodeExist.Count > 0)
                            {
                                oShareFolder.PGLevel = ((isNodeExist[0].InnerText != null) && (isNodeExist[0].InnerText.Trim().Length > 0)) ? Convert.ToInt16(isNodeExist[0].InnerText) : 0;
                            }

                            isAttributeExist = NodeElement.GetAttributeNode(Constant.PGLEVEL_ID);
                            if (isAttributeExist != null)
                            {
                                oShareFolder.ContainerID = isAttributeExist.Value;
                            }

                            isAttributeExist = NodeElement.GetAttributeNode("childCount");
                            if (isAttributeExist != null)
                            {
                                oShareFolder.childCount = Convert.ToInt16(isAttributeExist.Value);
                            }
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                return;
            }
            catch (Exception ex)
            {
                //LOG
                LogManager.logExceptionMessage(Constant.XMLManager_CLASSNAME, Constant.FUNC_NAME_readShareFolderPGLevel, ex);
            }
            return;
        }

        #endregion

        #region "Function: getConfigValue(1)"
        /// <summary>
        /// get value of Node from Integration Config xml
        /// </summary>
        /// <param name="pStrNodeName"></param>
        /// <returns></returns>
        /// <remarks></remarks>
        public static bool GetConfigValue(string pStrNodeName)
        {
            System.Xml.XmlDocument objXMLDoc = new System.Xml.XmlDocument();
            string value = "False";
            try
            {
                //Get Xml File Path.
                string strAppPath = "";
                strAppPath = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);

                string integrationConfigXmlFilePath = strAppPath + Constant.SLASH_SIGN + Constant.CONFIG_FILE_NAME;

                objXMLDoc.Load(integrationConfigXmlFilePath);

                System.Xml.XmlNode xmlRootNode = objXMLDoc.SelectSingleNode("//TREEROOT/DMS");
                System.Xml.XmlNodeList xmlNodeName = xmlRootNode.SelectNodes(pStrNodeName);

                value = xmlNodeName[0].InnerText.Trim();

                if (value.ToLower() == "true")
                    return true;
                else
                    return false;
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.XMLManager_CLASSNAME, Constant.FUNC_NAME_getconfigValue, ex);
            }
            finally
            {
                objXMLDoc = null;
            }
            return false;
        }
        #endregion

        #region "Function: WriteConfigXML(1)"
        /// <summary>
        /// get value of Node from Integration Config xml
        /// </summary>
        /// <param name="strNodeName"></param>
        /// <returns></returns>
        /// <remarks></remarks>
        public static bool WriteConfigXML(string pStrNodeName, bool pValue)
        {
            System.Xml.XmlDocument objXMLDoc = new System.Xml.XmlDocument();
            try
            {
                //Get Xml File Path.
                string strAppPath = "";
                strAppPath = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);

                string integrationConfigXmlFilePath = strAppPath + Constant.SLASH_SIGN + Constant.CONFIG_FILE_NAME;

                objXMLDoc.Load(integrationConfigXmlFilePath);

                System.Xml.XmlNode xmlRootNode = objXMLDoc.SelectSingleNode("//TREEROOT/DMS");
                System.Xml.XmlNodeList xmlNodeName = xmlRootNode.SelectNodes(pStrNodeName);

                if (pValue == true)
                    xmlNodeName[0].InnerText = "True";
                else
                    xmlNodeName[0].InnerText = "False";

                objXMLDoc.Save(integrationConfigXmlFilePath);
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.XMLManager_CLASSNAME, Constant.FUNC_NAME_writeConfigValue, ex);
            }
            finally
            {
                objXMLDoc = null;
            }
            return false;
        }
        #endregion

        #region "Function: readContentTreeXml(1)"
        /// <summary>
        /// Reads the ContentTree of Share Folder XML.
        /// </summary>
        /// <param name="pXmlShareFolder">The p XML share folder.</param>
        /// <returns></returns>
        public static ContentTree readContentTreeXml(string pXmlShareFolder)
        {
            XmlDocument xmlDoc = new XmlDocument();
            XmlNodeList xmlNode;
            XmlElement NodeElement;
            XmlNodeList isNodeExist;
            XmlAttribute isAttributeExist;                              

            ContentTreeItems oContentTreeEntity = new ContentTreeItems();
            ContentTree oContentTree = new ContentTree();
            oContentTree.contentTreeEntityList = new List<ContentTreeItems>();

            try
            {        
                pXmlShareFolder = pXmlShareFolder.Replace(">\\", ">");
               pXmlShareFolder = pXmlShareFolder.Replace("&", "&amp;");
                StringReader srShareFolder = new StringReader(pXmlShareFolder);
                XmlTextReader xmlShareFolder = new XmlTextReader(srShareFolder);
                xmlShareFolder.Namespaces = false; 

                xmlDoc.Load(xmlShareFolder);      
                xmlNode = xmlDoc.SelectNodes("//content");
                NodeElement = (XmlElement)xmlNode[0];

                isAttributeExist = NodeElement.GetAttributeNode("TotalMatches");
                if (isAttributeExist != null)
                {
                    oContentTree.TotalMatches = isAttributeExist.InnerText.ToString().Trim();
                }

                isAttributeExist = NodeElement.GetAttributeNode("NumberReturned");
                if (isAttributeExist != null)
                {
                    oContentTree.NumberReturned = isAttributeExist.InnerText.ToString().Trim();
                }

                xmlNode = xmlDoc.SelectNodes(Constant.SHAREFOLDER_CONTAINER);
                for (int iIndex = 0; iIndex < xmlNode.Count; iIndex++)
                {
                    oContentTreeEntity = new ContentTreeItems();

                    NodeElement = (XmlElement)xmlNode[iIndex];
                    isAttributeExist = NodeElement.GetAttributeNode("id");
                    if (isAttributeExist != null)
                    {
                        oContentTreeEntity.ContainerID = xmlNode[iIndex].Attributes["id"].InnerText.ToString().Trim();
                    }

                    isAttributeExist = NodeElement.GetAttributeNode("childCount");
                    if (isAttributeExist != null)
                    {
                        oContentTreeEntity.childCount = ((isAttributeExist.InnerText != null) && (isAttributeExist.InnerText.Trim().Length > 0)) ? Convert.ToInt16(isAttributeExist.InnerText) : 0;
                    }

                    isNodeExist = NodeElement.GetElementsByTagName("dc:title");
                    if (isNodeExist.Count > 0)
                    {
                        string[] dcTitleArray = isNodeExist[0].InnerText.Trim().Split('\\');
                        if (dcTitleArray.Length > 0)
                            oContentTreeEntity.dctitle = dcTitleArray[dcTitleArray.Length - 1];
                        else
                            oContentTreeEntity.dctitle = isNodeExist[0].InnerText.ToString().Trim().Replace("\\", "");
                    }

                    isNodeExist = NodeElement.GetElementsByTagName("upnp:class");
                    if (isNodeExist.Count > 0)
                    {
                        oContentTreeEntity.upnpclass = isNodeExist[0].InnerText.ToString().Trim();
                    }

                    isNodeExist = NodeElement.GetElementsByTagName("url");
                    if (isNodeExist.Count > 0)
                    {
                        oContentTreeEntity.url = isNodeExist[0].InnerText.ToString().Trim();
                    }

                    isNodeExist = NodeElement.GetElementsByTagName("pgLevel");
                    if (isNodeExist.Count > 0)
                    {
                        oContentTreeEntity.pgLevel = ((isNodeExist[0].InnerText != null) && (isNodeExist[0].InnerText.Trim().Length > 0)) ? Convert.ToInt16(isNodeExist[0].InnerText) : 0;
                    }

                    isNodeExist = NodeElement.GetElementsByTagName("shareState");
                    if (isNodeExist.Count > 0)
                    {
                        oContentTreeEntity.shareState = isNodeExist[0].InnerText.ToString().Trim();
                    }
                    
                    oContentTree.contentTreeEntityList.Add(oContentTreeEntity);
                }

                xmlNode = xmlDoc.SelectNodes(Constant.SHAREFOLDER_ITEM);
                for (int iIndex = 0; iIndex < xmlNode.Count; iIndex++)
                {
                    oContentTreeEntity = new ContentTreeItems();

                    NodeElement = (XmlElement)xmlNode[iIndex];
                    isAttributeExist = NodeElement.GetAttributeNode("id");
                    if (isAttributeExist != null)
                    {
                        oContentTreeEntity.ContainerID = xmlNode[iIndex].Attributes["id"].InnerText.ToString().Trim();
                    }
                    
                    isNodeExist = NodeElement.GetElementsByTagName("dc:title");
                    if (isNodeExist.Count > 0)
                    {
                        string[] dcTitleArray = isNodeExist[0].InnerText.Trim().Split('\\');
                        if (dcTitleArray.Length > 0)
                            oContentTreeEntity.dctitle = dcTitleArray[dcTitleArray.Length - 1];
                        else
                            oContentTreeEntity.dctitle = isNodeExist[0].InnerText.ToString().Trim().Replace("\\", "");
                    }

                    isNodeExist = NodeElement.GetElementsByTagName("upnp:class");
                    if (isNodeExist.Count > 0)
                    {
                        oContentTreeEntity.upnpclass = isNodeExist[0].InnerText.ToString().Trim();
                    }

                    isNodeExist = NodeElement.GetElementsByTagName("url");
                    if (isNodeExist.Count > 0)
                    {
                        oContentTreeEntity.url = xmlNode[iIndex]["url"].InnerText.ToString().Trim();
                    }

                    isNodeExist = NodeElement.GetElementsByTagName("pgLevel");
                    if (isNodeExist.Count > 0)
                    {
                        oContentTreeEntity.pgLevel = Convert.ToInt16(xmlNode[iIndex]["pgLevel"].InnerText);
                    }

                    isNodeExist = NodeElement.GetElementsByTagName("shareState");
                    if (isNodeExist.Count > 0)
                    {
                        oContentTreeEntity.shareState = xmlNode[iIndex]["shareState"].InnerText.ToString().Trim();
                    }
                    
                    oContentTree.contentTreeEntityList.Add(oContentTreeEntity);
                }
                return oContentTree;
            }
            catch (Exception ex)
            {
                //LOG
                LogManager.logExceptionMessage(Constant.XMLManager_CLASSNAME, Constant.FUNC_NAME_readShareFolderXml, ex);
            }
            return oContentTree;
        }

        #endregion

        #region "Function: readIndexingCallbackResult(1)"
        /// <summary>
        /// Reads the indexing callback details of Share Folder XML.
        /// </summary>
        /// <param name="pXmlIndexingDetails">The p XML share folder.</param>
        /// <returns></returns>
        public static StorageStateEntity readIndexingCallbackResult(string pXmlIndexingDetails)
        {
            if (pXmlIndexingDetails == null)
            {
                return null;
            }
            StorageStateEntity oStorageEntity = null;
            XmlDocument xmlDoc = new XmlDocument();
            XmlNodeList xmlNode;
            XmlElement NodeElement;
            bool levelFound = false;
            StringReader srShareFolderIndexDetails = new StringReader(pXmlIndexingDetails);
            XmlTextReader xmlShareFolderIndexDetails = new XmlTextReader(srShareFolderIndexDetails);
            try
            {
                xmlDoc.Load(xmlShareFolderIndexDetails);
                xmlNode = xmlDoc.SelectNodes("//nflc");
                oStorageEntity = new StorageStateEntity();
                while (xmlNode[0].HasChildNodes)
                {
                    xmlNode = xmlNode[0].ChildNodes;
                    if (xmlNode[0].Name.ToLower().Equals("level"))
                    {
                        levelFound = true;
                        break;
                    }
                   
                }
                        
                if(levelFound) {
                    oStorageEntity.indexingLevel = xmlNode[0].InnerText.ToString();
                }
                          
                NodeElement = (XmlElement)xmlNode[1];
                if (NodeElement != null)
                {
                    if (NodeElement.Name.ToLower().Equals("state"))
                    {
                        oStorageEntity.indexingState = NodeElement.InnerText.ToString();
                    }
                }
                NodeElement = (XmlElement)xmlNode[2];
                if (NodeElement != null)
                {
                    if (NodeElement.Name.Equals("storagePath"))
                    {
                        string sDisplayName = NodeElement.InnerText.ToString();
                        oStorageEntity.storagePath = sDisplayName.Replace("_", "__");
                    }
                }
                NodeElement = (XmlElement)xmlNode[3];
                if (NodeElement != null)
                {
                    if (NodeElement.Name.Equals("errorCode"))
                    {
                        oStorageEntity.errorCode = NodeElement.InnerText.ToString();
                    }
                }
                
            }
            catch (Exception ex)
            {
                //LOG
                LogManager.logExceptionMessage(Constant.XMLManager_CLASSNAME, Constant.FUNC_NAME_readIndexingCallbackResult, ex);
            }
            return oStorageEntity;
        }
        #endregion

        #region "Function: readPartialIndexingCallbackResult(1)"
        /// <summary>
        /// Reads the Partial indexing callback details of Share Folder XML.
        /// </summary>
        /// <param name="pXmlPartialIndexingDetails">The p XML share folder.</param>
        /// <returns></returns>
        public static StoragePartialIndexingEntity readPartialIndexingCallbackResult(string pXmlPartialIndexingDetails)
        {
            if (pXmlPartialIndexingDetails == null)
            {
                return null;
            }
            StoragePartialIndexingEntity oStoragePartialIndexingEntity = null;
            XmlDocument xmlDoc = new XmlDocument();
            XmlNodeList xmlNode;
            XmlElement NodeElement;
            bool modeFound = false;
            StringReader srShareFolderIndexDetails = new StringReader(pXmlPartialIndexingDetails);
            XmlTextReader xmlShareFolderIndexDetails = new XmlTextReader(srShareFolderIndexDetails);
            try
            {
                xmlDoc.Load(xmlShareFolderIndexDetails);
                xmlNode = xmlDoc.SelectNodes("//nflc");
                oStoragePartialIndexingEntity = new StoragePartialIndexingEntity();
                while (xmlNode[0].HasChildNodes)
                {
                    xmlNode = xmlNode[0].ChildNodes;
                    if (xmlNode[0].Name.ToLower().Equals("mode"))
                    {
                        modeFound = true;
                        break;
                    }

                }

                if (modeFound)
                {
                    oStoragePartialIndexingEntity.partialIndexingMode = xmlNode[0].InnerText.ToString();
                }

                NodeElement = (XmlElement)xmlNode[1];
                if (NodeElement != null)
                {
                    if (NodeElement.Name.ToLower().Equals("state"))
                    {
                        oStoragePartialIndexingEntity.partialIndexingState = NodeElement.InnerText.ToString();
                    }
                }
                NodeElement = (XmlElement)xmlNode[2];
                if (NodeElement != null)
                {
                    if (NodeElement.Name.Equals("contentID"))
                    {
                        oStoragePartialIndexingEntity.contentID = NodeElement.InnerText.ToString();
                    }
                }
                NodeElement = (XmlElement)xmlNode[3];
                if (NodeElement != null)
                {
                    if (NodeElement.Name.Equals("errorCode"))
                    {
                        oStoragePartialIndexingEntity.errorCode = NodeElement.InnerText.ToString();
                    }
                }

            }
            catch (Exception ex)
            {
                //LOG
                LogManager.logExceptionMessage(Constant.XMLManager_CLASSNAME, Constant.FUNC_NAME_readIndexingCallbackResult, ex);
            }
            return oStoragePartialIndexingEntity;
        }
        #endregion

        #endregion
    }
}
