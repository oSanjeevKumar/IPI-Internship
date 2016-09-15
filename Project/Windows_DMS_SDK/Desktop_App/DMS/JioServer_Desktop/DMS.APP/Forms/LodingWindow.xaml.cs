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

 
﻿using MahApps.Metro.Controls;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace DMS.APP.Forms
{
    /// <summary>
    /// Interaction logic for LodingWindow.xaml
    /// </summary>
    public partial class LoadingWindow : Window
    {
        public delegate void AsynchronousSendMessegeDelegate();
        
        public LoadingWindow(Window pWnerForm)
        {
            InitializeComponent();

            this.Owner = pWnerForm;            

        }
    }
}
