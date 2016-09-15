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
using System.Windows.Forms;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using DMS.BAL.Entity;
using DMS.BAL.Manager.Functional_Manager;
using DMS.BAL.Entity.Service_Entity;
using DMS.BAL.Manager.Common_Manager;
using System.Runtime.InteropServices;
using System.Threading;

namespace DMS.APP.Forms
{
    /// <summary>
    /// Interaction logic for Settings.xaml
    /// </summary>
    public partial class Config : MetroWindow
    {

        #region "Declaration"
        BrushConverter oBrushConvert = new BrushConverter();
        List<SharedFolder> oSharedFolderList = new List<SharedFolder>();
        private bool bInitializeRunning = false;
        private SharedUserControl oOwnerForm;
        #endregion

        #region "Events"
      //  public delegate void ServiceStateChange();
       // public static event ServiceStateChange eServiceStateChagnge;
        #endregion

        #region "Methods"

        #region "Method: Config(0)"
        /// <summary>
        /// Initializes a new instance of the <see cref="Config"/> class.
        /// </summary>
        public Config(SharedUserControl pOwnerForm)
        {
            bInitializeRunning = true;
            InitializeComponent();
            bool bServerState = ConfigurationManager.GetServiceLastState();

            oOwnerForm = pOwnerForm;

            InitConfig();
            
            if (bServerState == false)         
            {
                rdbtnServiceOff.IsChecked = true;
                //rdbtnServiceOff_Checked(rdbtnServiceOff, new RoutedEventArgs());
            }
            bInitializeRunning = false;
            
        }

        private void InitConfig()
        {
            fillPGLevel();
            fillShareFolder();
            GetDeviceName();
            setSevice();
        }

        #endregion

        #region "Method: GetDeviceName(0)"
        /// <summary>
        /// Gets the name of the device.
        /// </summary>
        private void GetDeviceName()
        {
            string sDeviceName=string.Empty;
                           
            sDeviceName = ServerManager.DeviceFriednlyName;            

            tbDeviceName.Text = sDeviceName;
        }

        #endregion

        #region "Method: setSevice(0)"
        /// <summary>
        /// Sets the sevice.
        /// </summary>
        public async void setSevice()
        {
            DMSParameters.dmsState IsService = DMSParameters.dmsState.DMS_STATE_DISABLE;
            DMSParameters.returnValue ret = DMSParameters.returnValue.NFLC_E_ERROR;
            bool isCAOn = false;

            await Task.Run(() =>
            {
                IsService = ConfigurationManager.DMS_AHLdmsGetServerState();
            });
           
            if (IsService == DMSParameters.dmsState.DMS_STATE_ENABLE)
            {
                rdbtnServiceOn.IsChecked = true;
            }
            else
            {
                rdbtnServiceOff.IsChecked = true;
                //rdbtnServiceOff_Checked(rdbtnServiceOff, new RoutedEventArgs());
            }

            isCAOn = ConfigurationManager.GetCAServiceLastState();
            if (isCAOn)
            {
                caBtnServiceOn.IsChecked = true;
            }
            else
            {
                caBtnServiceOff.IsChecked = true;
                //caRdbtnServiceOff_Checked(caBtnServiceOff, new RoutedEventArgs());
            }
            
        }

        #endregion

        #region "Method: fillPGLevel(0)"
        /// <summary>
        /// Fills the pg level.
        /// </summary>
        public void fillPGLevel()
        {
            if (ServerManager.oPGLevelList != null)
            {
                cbSetPgLevelFolder.ItemsSource = ServerManager.oPGLevelList.Where(p => p.Description != Constant.BLOCK_DEVICE.Trim()).Select(p => p.Description + " (" + p.Name + ")").ToList();
                cbSetPgLevelDevice.ItemsSource = ServerManager.oPGLevelList.Select(p => p.Description + " (" + p.Name + ")").ToList();

                cbSetPgLevelFolder.SelectedItem = ServerManager.oPGLevelList.Where(p => p.Id == ServerManager.oDefaultFolderPglevel).Select(p => p.Description + " (" + p.Name + ")").FirstOrDefault();
                cbSetPgLevelDevice.SelectedItem = ServerManager.oPGLevelList.Where(p => p.Id == ServerManager.oDefaultDevicePglevel).Select(p => p.Description + " (" + p.Name + ")").FirstOrDefault();
            }
        }

        #endregion

        #region "Method: fillShareFolder(0)"
        /// <summary>
        /// Fills the share folder.
        /// </summary>
        private async void fillShareFolder()
        {                          
            oSharedFolderList = ServerManager.oSharedFolderList;

            if (oSharedFolderList != null && ConfigurationManager.GetServiceLastState())
            {
                cbSetUploadPath.ItemsSource = oSharedFolderList;
                cbSetUploadPath.DisplayMemberPath = Constant.DISPLAY_PATH_PROPERTY;
                string sSelectedFolderpath = string.Empty;
                await Task.Run(() =>
                {
                    sSelectedFolderpath = SharedFolderManager.DMS_AHLdmsPublishStorageGetDefaultUploadFolder();
                });
                if (sSelectedFolderpath.Equals("") && (oSharedFolderList.Count != 0))
                {
                    MessageManager.ShowErrorMessage(Constant.UPLOAD_FOLDER_FAILED, this);
                    return;
                }
                cbSetUploadPath.SelectedValue = oSharedFolderList.Where(s => s.SharedFolderPath == sSelectedFolderpath).FirstOrDefault();
            }
        }

        #endregion

        #endregion

        #region "Event"

        #region "Event: btnCancel_Click(2)"
        /// <summary>
        /// Handles the Click event of the btnCancel control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="RoutedEventArgs"/> instance containing the event data.</param>
        private void btnCancel_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }

        #endregion

        #region "Event: btnConfigSave_Click(2)"
        /// <summary>
        /// Handles the Click event of the btnConfigSave control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="RoutedEventArgs"/> instance containing the event data.</param>
        private async void btnConfigSave_Click(object sender, RoutedEventArgs e)
        {
            bool isValid = false;
            //bool isService = false;
            bool bResult = false;
            string pErrorMsg = Constant.STRING_EMPTY;


            Brush brush = (Brush)oBrushConvert.ConvertFrom(Constant.COLOR_CODE_VLIDATATION);
            brush.Freeze();
     
            bool bLastServerState = ConfigurationManager.GetServiceLastState();
           
            if ((tbDeviceName.Text.Trim() == string.Empty) || (tbDeviceName.Text.Trim().Length < 0))
            {
                tbDeviceName.BorderBrush = brush;
                isValid = true;
                pErrorMsg = Constant.DEVICE_EMPTY;
            }
            else if (tbDeviceName.Text.Trim().Length > 128)
            {
                tbDeviceName.BorderBrush = brush;
                isValid = true;
                pErrorMsg = Constant.DEVICE_EXCEED;
            }
            if (cbSetPgLevelFolder.SelectedIndex < 0)
            {
                cbSetPgLevelFolder.BorderBrush = brush;
                isValid = true;
                if (pErrorMsg == null)
                {
                    pErrorMsg = Constant.FOLDER_PGLEVEL;
                }
            }

            if (cbSetPgLevelDevice.SelectedIndex < 0)
            {
                cbSetPgLevelDevice.BorderBrush = brush;
                isValid = true;
                if (pErrorMsg == null)
                {
                    pErrorMsg = Constant.DEVICE_PGLEVEL;
                }
            }

            if (isValid)
            {
                MessageManager.ShowWarningMessage(pErrorMsg, this);
                return;
            }          

            bResult = false;

            double windowTop = this.Top;
            double windowLeft = this.Left;

            if (this.WindowState == System.Windows.WindowState.Maximized)
            {
                windowTop = 0;
                windowLeft = 0;
            }
            double loadingWindowTop = (windowTop + (this.ActualHeight / 2)); //- 60;  // windowTop + (this.ActualHeight / 2);
            double loadingWindowLeft = (windowLeft + (this.ActualWidth / 2)); //-83.5;  // windowLeft + (this.ActualWidth / 2);

            oOwnerForm.startProcess(Constant.CONFIG_PROCESS, this, loadingWindowLeft, loadingWindowTop);

            DMSParameters.returnValue responce = DMSParameters.returnValue.NFLC_E_ERROR;
            string sDeviceName = tbDeviceName.Text.ToString().Trim();

            await Task.Run(() =>
            {
                responce = ConfigurationManager.DMS_AHLdmsSetFriendlyName(sDeviceName);
            });


            if (bResult == false && responce != DMSParameters.returnValue.NFLC_E_OK)
            {
                bResult = true;
            }

            if (responce == DMSParameters.returnValue.NFLC_E_OK )
            {
                ServerManager.DeviceFriednlyName = sDeviceName;
            }

            if (cbSetUploadPath.HasItems && cbSetUploadPath.SelectionBoxItem != null && cbSetUploadPath.SelectionBoxItem != "")
            {
                SharedFolder oShareFolder = (SharedFolder)cbSetUploadPath.SelectionBoxItem;

                if (oShareFolder != null)
                {
                    DMSParameters.returnValue oReturnValue = DMSParameters.returnValue.NFLC_E_ERROR;
                    await Task.Run(() =>
                    {
                        oReturnValue = SharedFolderManager.DMS_AHLdmsPublishStorageSetDefaultUploadFolder(oShareFolder.SharedFolderPath);
                    });

                    if (bResult == false && oReturnValue != DMSParameters.returnValue.NFLC_E_OK)
                    {
                        if (oReturnValue == DMSParameters.returnValue.NFLC_E_FILESYSTEM_PATH_NOT_WRITABLE)
                        {
                            MessageManager.ShowErrorMessage(Constant.UPLOAD_FOLDER_NOT_WRITABLE, this);
                            SharedUserControl.stopProcess();
                            oOwnerForm.EnabledGrid();
                            return;
                        }
                        bResult = true;
                    }

                    if (oReturnValue == DMSParameters.returnValue.NFLC_E_OK)
                    {
                        ServerManager.DefaultUploadFolder = oShareFolder.SharedFolderPath;
                    }
                }
            }

            int iDevicePGLevel = ServerManager.oPGLevelList.Where(p => p.DisplayDescription == cbSetPgLevelDevice.SelectionBoxItem.ToString().Trim()).Select(p => p.Id).FirstOrDefault();
            DMSParameters.returnValue DeviceLevelResponse = PGLevelManager.DMS_AHLdmsPGSetDefaultDeviceLevel(DMSParameters.dmsPGLevelType.DMS_PG_LEVEL_TYPE_DEVICE, iDevicePGLevel);

            //if (DeviceLevelResponse != DMSParameters.returnValue.NFLC_E_OK)
            //{
                //pPglevelError = Constant.PGLEVEL_UPDATE_ERROR + "Default Folder PgLevel" + Environment.NewLine;
            //}

            if (bResult == false && DeviceLevelResponse != DMSParameters.returnValue.NFLC_E_OK)
            {
                bResult = true;
            }
            else
            {
                ServerManager.oDefaultDevicePglevel = iDevicePGLevel;
            }

            int iContentPGLevel = ServerManager.oPGLevelList.Where(p => p.DisplayDescription == cbSetPgLevelFolder.SelectionBoxItem.ToString().Trim()).Select(p => p.Id).FirstOrDefault();
            DMSParameters.returnValue ContentLevelResponse = PGLevelManager.DMS_AHLdmsPGSetDefaultDeviceLevel(DMSParameters.dmsPGLevelType.DMS_PG_LEVEL_TYPE_CONTENT, iContentPGLevel);
            //if (ContentLevelResponse != DMSParameters.returnValue.NFLC_E_OK)
            //{
                //pPglevelError = pPglevelError + "Default Device PgLevel";
            //}

            if (bResult == false && ContentLevelResponse != DMSParameters.returnValue.NFLC_E_OK)
            {
                bResult = true;
            }
            else
            {
                ServerManager.oDefaultFolderPglevel = iContentPGLevel;
            }
           
            SharedUserControl.stopProcess();
            oOwnerForm.EnabledGrid();
            if (bResult == false)
            {
                MessageManager.ShowInformationMessage(Constant.CONFIG_SAVE, this);
            }
            else
            {
                MessageManager.ShowWarningMessage(Constant.CONFIG_SAVE_ERROR, this);
            }
            this.Close();
        }

        #endregion

        #region "Event: cbSetPgLevelFolder_SelectionChanged(2)"
        /// <summary>
        /// Handles the SelectionChanged event of the cbSetPgLevelFolder control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="SelectionChangedEventArgs"/> instance containing the event data.</param>
        private void cbSetPgLevelFolder_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            Brush brush = (Brush)oBrushConvert.ConvertFrom(Constant.COLOR_CODE_VLIDATATION_REMOVAL);
            brush.Freeze();
            cbSetPgLevelFolder.BorderBrush = brush;
        }

        #endregion

        #region "Event: cbSetPgLevelDevice_SelectionChanged(2)"
        /// <summary>
        /// Handles the SelectionChanged event of the cbSetPgLevelDevice control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="SelectionChangedEventArgs"/> instance containing the event data.</param>
        private void cbSetPgLevelDevice_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            Brush brush = (Brush)oBrushConvert.ConvertFrom(Constant.COLOR_CODE_VLIDATATION_REMOVAL);
            brush.Freeze();
            cbSetPgLevelDevice.BorderBrush = brush;
        }

        #endregion

        #region "Event: tbDeviceName_GotFocus(2)"
        /// <summary>
        /// Handles the GotFocus event of the tbDeviceName control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="RoutedEventArgs"/> instance containing the event data.</param>
        private void tbDeviceName_GotFocus(object sender, RoutedEventArgs e)
        {
            Brush brush = (Brush)oBrushConvert.ConvertFrom(Constant.COLOR_CODE_VLIDATATION_REMOVAL);
            brush.Freeze();
            tbDeviceName.BorderBrush = brush;
        }

        #endregion

        #region "Event: rdbtnServiceOff_Checked(2)"
        /// <summary>
        /// Handles the Checked event of the rdbtnServiceOff control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="RoutedEventArgs"/> instance containing the event data.</param>
        private async void rdbtnServiceOff_Checked(object sender, RoutedEventArgs e)
        {
            DMSParameters.returnValue ret = DMSParameters.returnValue.NFLC_E_ERROR;
            try
            {
                Brush brush = (Brush)oBrushConvert.ConvertFrom(Constant.COLOR_CODE_VLIDATATION_REMOVAL);
                brush.Freeze();

                tbDeviceName.BorderBrush = brush;
                cbSetUploadPath.BorderBrush = brush;
                cbSetPgLevelDevice.BorderBrush = brush;
                cbSetPgLevelFolder.BorderBrush = brush;
                caServiceState.BorderBrush = brush;

                cbSetUploadPath.IsEnabled = false;
                tbDeviceName.IsEnabled = false;
                cbSetPgLevelDevice.IsEnabled = false;
                cbSetPgLevelFolder.IsEnabled = false;
                caServiceState.IsEnabled = false;

                lblSetUploadPath.IsEnabled = false;
                lblDeviceName.IsEnabled = false;
                lblDefaultDevicePGLevel.IsEnabled = false;
                lblDefaultolderPGLevel.IsEnabled = false;

                btnCancel.IsEnabled = false;
                btnConfigSave.IsEnabled = false;
                caBtnServiceOff.IsEnabled = false;
                caBtnServiceOn.IsEnabled = false;
                oOwnerForm.miCATab.IsEnabled = false;

                if (bInitializeRunning == false)
                {
                    double windowTop = this.Top;
                    double windowLeft = this.Left;

                    if (this.WindowState == System.Windows.WindowState.Maximized)
                    {
                        windowTop = 0;
                        windowLeft = 0;
                    }
                    double loadingWindowTop = (windowTop + (this.ActualHeight / 2)); //- 60;  // windowTop + (this.ActualHeight / 2);
                    double loadingWindowLeft = (windowLeft + (this.ActualWidth / 2)); //-83.5;  // windowLeft + (this.ActualWidth / 2);

                    oOwnerForm.startProcess(Constant.SERVICE_STOP, this, loadingWindowLeft, loadingWindowTop);

                    await Task.Run(() =>
                    {
                        ConfigurationManager.SetServiceLastState(false);
                        ret = ConfigurationManager.DMS_AHLdmsStopService();
                    });
                    if(ret != DMSParameters.returnValue.NFLC_E_OK)
                    {
                        MessageManager.ShowErrorMessage(Constant.DMS_STOP_ERROR + Environment.NewLine, this);
                        rdbtnServiceOn.IsChecked = true;
                        ConfigurationManager.SetServiceLastState(true);
                        SharedUserControl.stopProcess();
                        oOwnerForm.EnabledGrid();
                    }
                }
            }
            catch (Exception ex)
            {
                SharedUserControl.stopProcess();
                oOwnerForm.EnabledGrid();
                LogManager.logExceptionMessage(Constant.CONFIG_CLASS_NAME, Constant.SSERVICEOFF_METHOD_NAME, ex);
            }
        }

        #endregion

        #region "Event: rdbtnServiceOn_Checked(2)"
        /// <summary>
        /// Handles the Checked event of the rdbtnServiceOn control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="RoutedEventArgs"/> instance containing the event data.</param>
        private async void rdbtnServiceOn_Checked(object sender, RoutedEventArgs e)
        {
            DMSParameters.returnValue ret = DMSParameters.returnValue.NFLC_E_ERROR;
            try
            {
                if (bInitializeRunning == true)
                    return;


                double windowTop = this.Top;
                double windowLeft = this.Left;

                if (this.WindowState == System.Windows.WindowState.Maximized)
                {
                    windowTop = 0;
                    windowLeft = 0;
                }
                double loadingWindowTop = (windowTop + (this.ActualHeight / 2));
                double loadingWindowLeft = (windowLeft + (this.ActualWidth / 2));

                oOwnerForm.startProcess(Constant.SERVICE_START, this, loadingWindowLeft, loadingWindowTop);
                bool bServerState = ConfigurationManager.GetServiceLastState();
                await Task.Run(() => { Thread.Sleep(1000); });
                if (bServerState == false && ConfigurationManager.IsDMSWrapperCreated == false)
                {
                    ConfigurationManager.SetServiceLastState(true);

                    await oOwnerForm.initializeForm();

                    InitConfig();
                 
                    if(oOwnerForm.IsInitializeSuccess == false)
                    {
                        SharedUserControl.stopProcess();
                        oOwnerForm.EnabledGrid();
                        ConfigurationManager.SetServiceLastState(false);
                        MessageManager.ShowWarningMessage(Constant.SERVICE_START_ERROR, this);
                        rdbtnServiceOff.IsChecked = true;
                        ConfigurationManager.SetCAServiceState(Constant.CA_DISABLE);
                        caBtnServiceOff.IsChecked = true;
                        return;
                    }                 
                }
                else
                {
                    await Task.Run(() =>
                    {
                        ret = ConfigurationManager.DMS_AHLdmsStartService();
                    });
                    if (ret != DMSParameters.returnValue.NFLC_E_OK)
                    {
                        MessageManager.ShowErrorMessage(Constant.DMS_START_ERROR + Environment.NewLine, this);
                        rdbtnServiceOff.IsChecked = true;
                        ConfigurationManager.SetServiceLastState(false);
                        SharedUserControl.stopProcess();
                        oOwnerForm.EnabledGrid();
                    }
                    else
                    {
                        ConfigurationManager.SetServiceLastState(true);
                        fillShareFolder();
                        oOwnerForm.fillDevicePGLevelMenu();
                        if (ConfigurationManager.GetCAServiceLastState())
                        {
                            await Task.Run(() =>
                            {
                                ret = ConfigurationManager.DMS_AHLdmsCASetEnabled(true);
                            });
                            if (ret != DMSParameters.returnValue.NFLC_E_OK)
                            {
                                MessageManager.ShowErrorMessage(Constant.CA_ENABLE_ERROR + Environment.NewLine, this);
                                ConfigurationManager.SetCAServiceState(false);
                                caBtnServiceOn.IsChecked = false;
                            }
                            else
                            {
                                oOwnerForm.miCATab.Visibility = Visibility.Visible;
                                oOwnerForm.miPauseCA.IsEnabled = true;
                                oOwnerForm.miResumeCA.IsEnabled = false;
                                ConfigurationManager.SetCARunningState(Constant.CA_RESUME_ENABLE);
                            }
                        }
                    }
                }

                Brush brush = (Brush)oBrushConvert.ConvertFrom(Constant.COLOR_CODE_VLIDATATION_REMOVAL);
                brush.Freeze();

                tbDeviceName.BorderBrush = brush;
                cbSetUploadPath.BorderBrush = brush;
                cbSetPgLevelDevice.BorderBrush = brush;
                cbSetPgLevelFolder.BorderBrush = brush;
                caServiceState.BorderBrush = brush;

                cbSetUploadPath.IsEnabled = true;
                tbDeviceName.IsEnabled = true;
                cbSetPgLevelDevice.IsEnabled = true;
                cbSetPgLevelFolder.IsEnabled = true;
                caServiceState.IsEnabled = true;

                lblSetUploadPath.IsEnabled = true;
                lblDeviceName.IsEnabled = true;
                lblDefaultDevicePGLevel.IsEnabled = true;
                lblDefaultolderPGLevel.IsEnabled = true;

                btnCancel.IsEnabled = true;
                btnConfigSave.IsEnabled = true;
                caBtnServiceOff.IsEnabled = true;
                caBtnServiceOn.IsEnabled = true;
                oOwnerForm.miCATab.IsEnabled = true;

            }
            catch (Exception ex)
            {

                SharedUserControl.stopProcess();
                oOwnerForm.EnabledGrid();
                LogManager.logExceptionMessage(Constant.CONFIG_CLASS_NAME, Constant.SSERVICEON_METHOD_NAME, ex);
            }
        }

        #endregion

        #region "Event: cbSetUploadPath_SelectionChanged(2)"
        /// <summary>
        /// Handles the SelectionChanged event of the cbSetUploadPath control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="SelectionChangedEventArgs"/> instance containing the event data.</param>
        private void cbSetUploadPath_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            Brush brush = (Brush)oBrushConvert.ConvertFrom(Constant.COLOR_CODE_VLIDATATION_REMOVAL);
            brush.Freeze();
            cbSetUploadPath.BorderBrush = brush;
        }


        #endregion

        #endregion

        #region "Function"

        #endregion

        private async void cbSetUploadPath_DropDownOpened(object sender, EventArgs e)
        {
            DMSParameters.returnValue ret = DMSParameters.returnValue.NFLC_E_ERROR;
            int count = -1;
            await Task.Run(() =>
            {
                ret = ConfigurationManager.DMS_AHLdmsGetStorageCount(out count);
            });
            if ((ret == DMSParameters.returnValue.NFLC_E_OK) && (count == 0))
            {
                MessageManager.ShowErrorMessage(Constant.UPLOAD_FOLDER_NOT_SET, this);
            }
        }

        private async void caRdbtnServiceOn_Checked(object sender, RoutedEventArgs e)
        {
            DMSParameters.returnValue ret = DMSParameters.returnValue.NFLC_E_ERROR;
            bool bCAServerState = ConfigurationManager.GetCAServiceLastState();
            if (bCAServerState == false)
            {
                await Task.Run(() =>
                {
                    ret = ConfigurationManager.DMS_AHLdmsCASetEnabled(true);
                });
                if (ret == DMSParameters.returnValue.NFLC_E_OK)
                {
                    ConfigurationManager.SetCAServiceState(Constant.CA_ENABLE);
                    caBtnServiceOn.IsChecked = true;
                    oOwnerForm.miCATab.Visibility = Visibility.Visible;
                    oOwnerForm.miPauseCA.IsEnabled = true;
                    oOwnerForm.miResumeCA.IsEnabled = false;
                    ConfigurationManager.SetCARunningState(Constant.CA_RESUME_ENABLE);
                }
                else
                {
                    MessageManager.ShowErrorMessage(Constant.CA_ENABLE_ERROR + Environment.NewLine, this);
                    ConfigurationManager.SetCAServiceState(Constant.CA_DISABLE);
                    caBtnServiceOff.IsChecked = true;
                    caRdbtnServiceOff_Checked(caBtnServiceOff, new RoutedEventArgs());
                }
            }
        }
        private async void caRdbtnServiceOff_Checked(object sender, RoutedEventArgs e)
        {
            DMSParameters.returnValue ret = DMSParameters.returnValue.NFLC_E_ERROR;
            if (bInitializeRunning == false)
            {
                bool bCAServerState = ConfigurationManager.GetCAServiceLastState();
                if (bCAServerState == true)
                {
                    await Task.Run(() =>
                    {
                        ret = ConfigurationManager.DMS_AHLdmsCASetEnabled(false);
                    });
                    if (ret == DMSParameters.returnValue.NFLC_E_OK)
                    {
                        ConfigurationManager.SetCAServiceState(Constant.CA_DISABLE);
                        caBtnServiceOff.IsChecked = true;
                        oOwnerForm.miCATab.Visibility = Visibility.Collapsed;
                        oOwnerForm.miPauseCA.IsEnabled = false;
                        oOwnerForm.miResumeCA.IsEnabled = false;
                    }
                    else
                    {
                        MessageManager.ShowErrorMessage(Constant.CA_DISABLE_ERROR + Environment.NewLine, this);
                        ConfigurationManager.SetCAServiceState(Constant.CA_ENABLE);
                        caBtnServiceOn.IsChecked = true;
                        caRdbtnServiceOn_Checked(caBtnServiceOn, new RoutedEventArgs());
                    }
                }
            }
        }
    }
}
