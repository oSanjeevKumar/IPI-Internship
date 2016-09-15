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

namespace DMS.BAL.Entity
{
    public class DeviceEntity
    {
        #region "Properties(5)"

        public string FriendlyName { get; set; }

        public int Level { get; set; }

        public string MacAddress { get; set; }

        public string IpAddress { get; set; }

        public string DeviceDescription { get; set; }

        public string DeviceName { get; set; }

        public string ShortPGLevel { get; set; }

        #endregion

    }
}
