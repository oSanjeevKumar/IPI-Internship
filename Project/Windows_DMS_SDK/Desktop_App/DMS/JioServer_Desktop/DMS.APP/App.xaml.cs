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
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading;
using System.Windows;
using System.Diagnostics;
using DMS.BAL.Manager.Common_Manager;
using System.IO;
using System.Runtime.InteropServices;
using System.Text;
using HockeyApp;

namespace DMS.APP
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
        #region "Declaration"          
        [DllImport("user32.dll", SetLastError = true)]
        static extern IntPtr FindWindow(string lpClassName, string lpWindowName);

        [DllImportAttribute("user32.dll")]
        public static extern bool ShowWindow(IntPtr hWnd, int nCmdShow);

        StartUpScreen oStartForm;
        #endregion
        protected override async void OnStartup(StartupEventArgs e)
        {           
            HockeyClient.Current.Configure("cf52a513d9774fe1b58bdf68bd90567e");
            Process thisProc = Process.GetCurrentProcess();
            Process[] existingProcessList = Process.GetProcessesByName(thisProc.ProcessName);
            if (existingProcessList.Length > 1)
            {
                IntPtr Handle = FindWindow(null, "Jio Server");
                ShowWindow(Handle, 9);             
                Environment.Exit(1);
            }

            System.Windows.Forms.Application.ThreadException += new ThreadExceptionEventHandler(LogUnhandledThreadException);

            // Set the unhandled exception mode to force all Windows Forms errors to go through 
            // our handler.
            System.Windows.Forms.Application.SetUnhandledExceptionMode(System.Windows.Forms.UnhandledExceptionMode.CatchException);

            // Add the event handler for handling non-UI thread exceptions to the event. 
            AppDomain.CurrentDomain.UnhandledException +=
                new UnhandledExceptionEventHandler(CurrentDomain_UnhandledException);

            //Open Splash Screen from
            oStartForm = new StartUpScreen();
            oStartForm.Show();
            await HockeyClient.Current.SendCrashesAsync(true);
            await HockeyClient.Current.CheckForUpdatesAsync(true, () =>
            {  //Replace MainWindow with your main Window or use another way to gracefully shutdown your app
                if (Application.Current.MainWindow != null) { Application.Current.MainWindow.Close(); }
                return true;
            });
        }

        private void Application_DispatcherUnhandledException(object sender, System.Windows.Threading.DispatcherUnhandledExceptionEventArgs e)
        {
            e.Handled = true;
            DMS.APP.Forms.SharedUserControl.stopProcess();
            oStartForm.oForm.EnabledGrid();
            LogManager.logExceptionMessage(Constant.Application_STARTUP_CLASSNAME,Constant.Application_DISPATCHEUNHANDLEEXCEPTION_METHODNAME, e.Exception);
            
        }

        void CurrentDomain_UnhandledException(object sender, UnhandledExceptionEventArgs e)
        {            
            Exception ex = (Exception) e.ExceptionObject;
            DMS.APP.Forms.SharedUserControl.stopProcess();
            oStartForm.oForm.EnabledGrid();
            LogManager.logExceptionMessage(Constant.Application_STARTUP_CLASSNAME, Constant.Application_LogUnhandledException_METHODNAME, ex);                
        }

        private void LogUnhandledThreadException(object sender, ThreadExceptionEventArgs e)
        {                  
            DMS.APP.Forms.SharedUserControl.stopProcess();
            oStartForm.oForm.EnabledGrid();
            LogManager.logExceptionMessage(Constant.Application_STARTUP_CLASSNAME, Constant.Application_LogUnhandledException_METHODNAME, e.Exception);                
        }      

    }
}
