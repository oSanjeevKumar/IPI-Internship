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

namespace DMS.BAL.Entity.Service_Entity
{
    public class DMSParameters
    {
        #region "ENUM"
        public enum returnValue
        {
            NFLC_E_OK = 0,
            NFLC_E_ERROR = -1,
            NFLC_E_INVALID_PARAM = -2,
            NFLC_E_DEVICE_NOT_FOUND = -3,
            NFLC_E_DEVICE_SERVICE_NOT_FOUND = -4,
            NFLC_E_INVALID_WEBSOCKET_REQUEST = -5,
            NFLC_E_UNKNOWN_WEBSOCKET_REQUEST = -6,
            NFLC_E_OK_WARNING = -7,
            NFLC_E_INVALID_INSTANCE = -8,
            NFLC_E_FILESYSTEM_PATH_NOT_EXIST = -9,
            NFLC_E_FILESYSTEM_PATH_NOT_A_FOLDER = -10,
            NFLC_E_FILESYSTEM_PATH_NOT_A_FILE = -11,
            NFLC_E_FILESYSTEM_PATH_NOT_WRITABLE = -12,
            NFLC_E_NOT_STARTED = -13,
            NFLC_E_FILESYSTEM_FILE_NOT_EXIST = -14,
            NFLC_E_FILE_UPLOAD_IN_PROGRESS = -15,
            NFLC_E_UPLOAD_NOT_SUPPORTED = -16,
            NFLC_E_UPLOAD_OBJECT_RESTRICTED = -17,
            NFLC_E_UPLOAD_MIME_NOT_SUPPORTED = -18,
            NFLC_E_NOT_SUPPORT = -19,
            NFLC_E_STORAGE_LIMIT_REACHED = -20
        }

        public enum dmsStorageDatabaseLocationType
        {
            DMS_STORAGE_DATABASE_LOCATION_TYPE_LOCAL, //storage database created locally in the storage root folder
            DMS_STORAGE_DATABASE_LOCATION_TYPE_CENTRAL //storage database created centrally in the storage root folder
        } ;

        public enum dmsState
        {
            DMS_STATE_DISABLE = 0, //dms is disabled
            DMS_STATE_ENABLE  //dms is enbled
        };

        public enum dmsContentClassType
        {
            DMS_AHL_CONTENTS_CLASS_TYPE_IMAGE = 0,    //Content type is Image
            DMS_AHL_CONTENTS_CLASS_TYPE_AUDIO,    //Content type is Audio
            DMS_AHL_CONTENTS_CLASS_TYPE_VIDEO,    //Content type is Video
            DMS_AHL_CONTENTS_CLASS_TYPE_PLAYLIST, //Content type is Playlist
            DMS_AHL_CONTENTS_CLASS_TYPE_DOCUMENT
        }

        public enum dmsPGLevelType
        {
            DMS_PG_LEVEL_TYPE_DEVICE, //PG level of device
            DMS_PG_LEVEL_TYPE_CONTENT  //PG level of content
        }


        public enum  dmsCADatabaseSelectionMode {
            DMS_CA_DB_SELECTION_MODE_AUTO,  // Databse location selected automatically
            DMS_CA_DB_SELECTION_MODE_MANUAL // Database location selected manually
        }

        public enum dmsCACommand {
            DMS_CA_CMD_PAUSE = 1,
            DMS_CA_CMD_RESUME
        }

        public enum dmsCAState {
            DMS_CA_STATE_DISABLED,
            DMS_CA_STATE_IDLE,
            DMS_CA_STATE_PROCESSING,
            DMS_CA_STATE_PAUSED,
            DMS_CA_STATE_STOPPED
        }
        #endregion

        //public delegate void dmsCallbackFunc(IntPtr arg, DMSParameters.dmsEvent ev, int param);
        public delegate void dmsCallbackHandler_applayer(IntPtr arg, DMSParameters.dmsEvent ev, IntPtr param);
        #region "Structure"
        public struct dmsInitParams
        {
            public string dmsDataDirectory; //Path of Data directory of DMS
            public string configDirectory;  //Configuration file path of xml files.
            public UInt16 upnpPort; //DMS UPnP Server Port Number
            public DMS.BAL.Manager.Common_Manager.ServiceManager.dmsCallbackHandler_applayer funccb;
            public dmsEvent arg;
            public IntPtr callbackarg;

        };
        public enum dmsEvent
        {
            DMS_EVENT_INDEXING_STATE = 0x01,
            DMS_EVENT_PARTIAL_INDEXING_STATE = 0x02,
            DMS_EVENT_CA_STATE = 0x04,
            DMS_EVENT_DMS_STATE = 0x08
        };

        #endregion

        public delegate void dmsLogPrintCallbackFunc(IntPtr arg, string str);

        #region "Structure"
        public struct dmsWrapperInitParams
        {
           
            public IntPtr arg;

        };
        #endregion
    }
}
