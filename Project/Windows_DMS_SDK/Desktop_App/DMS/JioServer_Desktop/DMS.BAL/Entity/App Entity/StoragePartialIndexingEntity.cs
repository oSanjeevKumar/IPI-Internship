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
    public class StoragePartialIndexingEntity
    {
        public string contentID { get; set; }

        public string partialIndexingMode { get; set; }

        public string partialIndexingState { get; set; }

        public string errorCode { get; set; }
    }
}
