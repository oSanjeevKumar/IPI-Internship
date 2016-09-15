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
    public class LogManager
    {
        #region "Declaration"

        public static bool IsLogEnable = true;        

        #endregion


        #region "Method"

        #region "Method: LogWriterForLibrary()"
        /// <summary>
        /// Return the textwritter for library logs
        /// </summary>
        /// <returns></returns>
        public static void WriteLibraryLog(string pMessage)
        {
            try
            {
                System.IO.TextWriter integrationLog = default(System.IO.TextWriter);

                DateTime currentTime = DateTime.Now;

                string folderName = currentTime.ToString(Constant.STR_DATE_FORMAT);
                string directoryPath = Constant.LIBRARY_DIRECTORY_PATH;

                string path = directoryPath + folderName;
                if ((System.IO.Directory.Exists(path) == false))
                {
                    System.IO.Directory.CreateDirectory(path);
                }


                string fullFilePath = path + Constant.PREFIX_TEXT_FOR_LIB_FOLDER_NAME + folderName + Constant.FILE_EXTENTION;
                integrationLog = new System.IO.StreamWriter(fullFilePath, true);
                string writelogmessage = Constant.MSG_TIME + currentTime.ToString(Constant.STR_TIME_FORMATE);
                if (!(string.IsNullOrEmpty(pMessage)))
                {
                    writelogmessage += Constant.STR_MSG + pMessage;
                }

                integrationLog.WriteLine(writelogmessage);
                integrationLog.Close();
            }
            catch(Exception ex)
            {
                return ;
            }
        }
        #endregion

        #region "Method: logMessage(3)"
        /// <summary>
        /// Logs the string message.
        /// </summary>
        /// <param name="pClassname">classname.</param>
        /// <param name="pMethodname">methodname.</param>
        /// <param name="pMessage">message.</param>
        public static void logMessage(string pClassname, string pMethodname, string pMessage = Constant.STRING_EMPTY)
        {
            try
            {
                if (IsLogEnable == true)
                {
                    System.IO.TextWriter integrationLog = default(System.IO.TextWriter);

                    DateTime currentTime = DateTime.Now;

                    string folderName = currentTime.ToString(Constant.STR_DATE_FORMAT);
                    string directoryPath = Constant.DIRECTORY_PATH;

                    string path = directoryPath + folderName;
                    if ((System.IO.Directory.Exists(path) == false))
                    {
                        System.IO.Directory.CreateDirectory(path);
                    }


                    string fullFilePath = path + Constant.PREFIX_TEXT_FOR_FOLDER_NAME + folderName + Constant.FILE_EXTENTION;
                    integrationLog = new System.IO.StreamWriter(fullFilePath, true);
                                        
                    string writelogmessage = Constant.MSG_TIME + currentTime.ToString(Constant.STR_TIME_FORMATE) + Constant.MSG_CLASS + pClassname + Constant.MSG_METHOD + pMethodname;
                    if (!(string.IsNullOrEmpty(pMessage)))
                    {
                        writelogmessage += Constant.STR_MSG + pMessage;
                    }

                    integrationLog.WriteLine(writelogmessage);                    
                    integrationLog.Close();
                }               
            }
            catch (Exception ex)
            {
                //logExceptionMessage(Constant.LogManager_CLASSNAME, Constant.FUNC_NAME_logStringMessage, ex);
            }
        }

        #endregion

        #region "Method: logExceptionMessage(3)"
        /// <summary>
        /// Logs the exception message.
        /// </summary>
        /// <param name="pclassname">The pclassname.</param>
        /// <param name="pmethodname">The pmethodname.</param>
        /// <param name="pex">The pex.</param>
        public static void logExceptionMessage(string pclassname, string pmethodname, Exception pex = null)
        {
            try
            {
                if (IsLogEnable == true)
                {
                    System.IO.TextWriter integrationLog = default(System.IO.TextWriter);

                    DateTime currentTime = DateTime.Now;

                    string folderName = currentTime.ToString(Constant.STR_DATE_FORMAT);
                    string directoryPath = Constant.DIRECTORY_PATH;

                    string path = directoryPath + folderName;
                    if ((System.IO.Directory.Exists(path) == false))
                    {
                        System.IO.Directory.CreateDirectory(path);
                    }


                    string fullFilePath = path + Constant.PREFIX_TEXT_FOR_FOLDER_NAME + folderName + Constant.FILE_EXTENTION;
                    integrationLog = new System.IO.StreamWriter(fullFilePath, true);
                    
                    string writelogmessage = Constant.MSG_TIME + currentTime.ToString(Constant.STR_TIME_FORMATE) + Constant.MSG_CLASS + pclassname + Constant.MSG_METHOD + pmethodname;

                    if (pex != null)
                    {
                        writelogmessage += Constant.STR_EX_MSG + pex.Message + Constant.STR_EX_STACK + pex.StackTrace;
                    }

                    integrationLog.WriteLine(writelogmessage);                                        
                    integrationLog.Close();
                }
            }
            catch (Exception ex)
            {
                //logExceptionMessage(Constant.LogManager_CLASSNAME, Constant.FUNC_NAME_logExceptionMessage, ex);
            }
        }

        #endregion

        #region "Method: logRequestResponceMessage(2)"
        /// <summary>
        /// Logs Request.
        /// </summary>
        /// <param name="pClassname">classname.</param>
        /// <param name="pMethodname">methodname.</param>
        /// <param name="pMessage">message.</param>
        public static void logRequestResponceMessage(string pClassname, string pMethodname, string pMessage = Constant.STRING_EMPTY)
        {
            try
            {
                if (IsLogEnable == true)
                {
                    System.IO.TextWriter integrationLog = default(System.IO.TextWriter);

                    DateTime currentTime = DateTime.Now;

                    string folderName = currentTime.ToString(Constant.STR_DATE_FORMAT);
                    string directoryPath = Constant.DIRECTORY_PATH;

                    string path = directoryPath + folderName;
                    if ((System.IO.Directory.Exists(path) == false))
                    {
                        System.IO.Directory.CreateDirectory(path);
                    }


                    string fullFilePath = path + Constant.PREFIX_TEXT_FOR_FOLDER_NAME + folderName + Constant.FILE_EXTENTION;
                    integrationLog = new System.IO.StreamWriter(fullFilePath, true);
                                        
                    string writelogmessage = Constant.MSG_TIME + currentTime.ToString(Constant.STR_TIME_FORMATE) + Constant.MSG_CLASS + pClassname + Constant.MSG_METHOD + pMethodname;
                    if (!(string.IsNullOrEmpty(pMessage)))
                    {
                        writelogmessage += Constant.STR_MSG + pMessage;
                    }

                    integrationLog.WriteLine(writelogmessage);                                        
                    integrationLog.Close();
                }
            }
            catch (Exception ex)
            {
                //logExceptionMessage(Constant.LogManager_CLASSNAME, Constant.FUNC_NAME_logStringMessage, ex);
            }
        }

        #endregion

        #endregion
    }
}
