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

namespace DMS.BAL.Entity.App_Entity
{
    public class ContentTreeItems
    {

        #region "Properties(3)"

        public string ContainerID { get; set; }

        public int childCount { get; set; }

        public string dctitle { get; set; }

        public string upnpclass { get; set; }

        public string url { get; set; }

        public int pgLevel { get; set; }

        public string shareState { get; set; }

        #endregion

    }

    public class ContentTree
    {
        #region "Properties(3)"

        public string NumberReturned { get; set; }

        public string TotalMatches { get; set; }

        public List<ContentTreeItems> contentTreeEntityList { get; set; }

        #endregion
    }
}
