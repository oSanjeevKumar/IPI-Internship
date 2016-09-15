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

 
﻿using DMS.APP.Forms;
using MahApps.Metro.Controls;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Forms;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Diagnostics;

using System.ComponentModel; // CancelEventArgs 

namespace DMS.APP
{
    /// <summary>
    /// Interaction logic for StartUpScreen.xaml
    /// </summary>
    public partial class StartUpScreen : MetroWindow
    {
        #region "Declaration"

        // System.Windows.Forms.Timer closeFormTimer = new System.Windows.Forms.Timer();
        public SharedUserControl oForm = new SharedUserControl();
        private delegate void SetProgressBarValueDelegate(int pProgressValue);
        Thread loadingThread;

        #endregion

        #region "Methods"

        #region "Method: StartUpScreen()"
        /// <summary>
        /// Initializes a new instance of the <see cref="StartUpScreen"/> class.
        /// </summary>
        public StartUpScreen()
        {
            InitializeComponent();
            Closing += MetroWindow_OnClose;
            this.Loaded += MetroWindow_Loaded;
            oForm.eUpdateProgress += closeForm;
        }

        #endregion

        #endregion

        #region "Method: StartIntitialization(0)"
        /// <summary>
        /// Starts the intitialization.
        /// </summary>
        public void StartIntitialization()
        {
            Thread.Sleep(500);
            oForm.initializeForm();            
        }

        #endregion

        #region "Event"

        #region "Event: MetroWindow_Loaded(2)"
        /// <summary>
        /// Handles the Loaded event of the MetroWindow control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="EventArgs"/> instance containing the event data.</param>
        private void MetroWindow_Loaded(object sender, EventArgs e)
        {
            loadingThread = new Thread(new ThreadStart(StartIntitialization));
            loadingThread.Start();
        }

        #endregion

        #region "Event: MetroWindow_OnClose(2)"
        /// <summary>
        /// Handles the OnClose event of the MetroWindow control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="CancelEventArgs"/> instance containing the event data.</param>
        private void MetroWindow_OnClose(object sender, CancelEventArgs e)
        {
            oForm.Show();
        }

        #endregion

        #region "Event: closeForm(1)"
        /// <summary>
        /// Closes the form.
        /// </summary>
        /// <param name="pProgress">The p progress.</param>
        private void closeForm(int pProgress)
        {
            if (this.pgrSplash.Dispatcher.CheckAccess())
            {
                pgrSplash.Value = pProgress;
                if (pgrSplash.Value == pgrSplash.Maximum)
                {
                    this.Close();
                }
            }
            else
            {
                this.pgrSplash.Dispatcher.Invoke(new SetProgressBarValueDelegate(closeForm), new object[] { pProgress });
            }
        }

        #endregion

        #endregion

        #region "Function"

        #endregion
    }
}
