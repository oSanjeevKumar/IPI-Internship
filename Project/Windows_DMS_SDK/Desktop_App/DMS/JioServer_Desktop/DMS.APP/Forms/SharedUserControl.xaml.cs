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

 
﻿
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
using System.Data;
using System.IO;
using System.Windows.Markup;
using MahApps.Metro.Controls;
using System.Threading;
using System.Management;
using MahApps.Metro.Controls.Dialogs;
using Microsoft.WindowsAPICodePack.Dialogs;
using DMS.BAL.Entity;
using DMS.BAL.Entity.App_Entity;
using DMS.BAL.Manager.Common_Manager;
using DMS.BAL.Manager.Functional_Manager;
using DMS.BAL.Entity.Service_Entity;
using System.Runtime.InteropServices;
using System.Collections.ObjectModel;
using System.Windows.Threading;
using System.ComponentModel;
using System.Collections;

namespace DMS.APP.Forms
{
    /// <summary>
    /// Interaction logic for SharedUserControl.xaml
    /// </summary>
    public partial class SharedUserControl : MetroWindow, INotifyPropertyChanged
    {
        #region "Declaration"

        public delegate void updateStartProgress(int pCompletedPercentage);
        public event updateStartProgress eUpdateProgress;
        private delegate Task<bool> UpdateTreeViewUI();
        private delegate Task<bool> UpdateUIAsync();
        private delegate void UpdateUI();
        private delegate void UpdateIndexingUI(bool isRefresh);
        private delegate void StopLoader();
        private delegate void ServiceStatusChangeHandle(bool pValue);
        private delegate void ScreenLoaderFetchMainScreenSize();
        private delegate void StartLoader(object LoadingParam);
        private delegate void EnabledGridDelegate();
        private delegate void StartProcessDelegate(string pIntializeText, Window pOwnerWIndow, double xPos, double yPos);

        private static LoadingWindow objLoadingForm;
        private Window oMainWindow;
        private System.Windows.Forms.NotifyIcon MyNotifyIcon;
        private ManagementEventWatcher watcher = null;
        System.Threading.Thread DeviceThread;

        //MessageWindow oMessage = new MessageWindow(this);

        private object dummyNode = null;

        public Point LocationPoint;
        private double XPosition = 0.0;
        private double YPosition = 0.0;
        List<BindingFolder> selectedTreeViewItemList = new List<BindingFolder>();
        List<BindingFolder> changedTreeViewItemList = new List<BindingFolder>();
        // private TreeViewItem expandedTreeviewItem;

        ////HSC Added
        private string _SuccessMsg = String.Empty;
        private string _SharingErrorMsg = String.Empty;
        private string _ValidateErrorMsg = String.Empty;
        private string _ValidateRootDirWarningMsg = string.Empty;

        public bool IsInitializeSuccess = true;
        public static BAL.Manager.Common_Manager.ServiceManager.dmsCallbackHandler_applayer CallBackHandler;

        private ObservableCollection<BindingFolder> _SharedBindedFolderList = new ObservableCollection<BindingFolder>();
        #endregion

        #region "Structure"

        public struct LoadingParams
        {
            public string ContentText;
            public double xPos;
            public double yPos;
        };

        #endregion

        #region "Function"

        #endregion

        void NotifiyPropertyChanged(string property)
        {
            if (PropertyChanged != null)
                PropertyChanged(this, new PropertyChangedEventArgs(property));
        }

        public event PropertyChangedEventHandler PropertyChanged;

        #region "Property"
        public ObservableCollection<BindingFolder> SharedBindedFolderList
        {
            get
            {
                return _SharedBindedFolderList;
            }
            set
            {
                _SharedBindedFolderList = value;
                NotifiyPropertyChanged("SharedBindedFolderList");
            }
        }

        #endregion

        #region "Event"

        #region "Event: MenuDevice_Clicked(2)"
        /// <summary>
        /// Handles the Clicked event of the MenuDevice control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="RoutedEventArgs"/> instance containing the event data.</param>
        private async void MenuDevice_Clicked(object sender, RoutedEventArgs e)
        {
            FillMainScreenParameters();

            startProcess(Constant.SETTING_DEVICE_PGLEVEL, this, XPosition, YPosition);
            MenuItem oMenu = (MenuItem)sender;
            //DeviceEntity oDevice = (DeviceEntity)grvDeviceLevel.SelectedItem;
            List<DeviceEntity> oSelectedDeviceList = grvDeviceLevel.SelectedItems.Cast<DeviceEntity>().ToList();

            int iLevel = 0;
            if (int.TryParse(oMenu.Tag.ToString(), out iLevel) == false)
                iLevel = 0;
            if (oSelectedDeviceList != null && oSelectedDeviceList.Count > 0)
            {
                string sErrorDeviceList = string.Empty;
                await Task.Run(() =>
                {
                    foreach (DeviceEntity oDevice in oSelectedDeviceList)
                    {
                        DMSParameters.returnValue response = PGLevelManager.DMS_AHLdmsPGSetDeviceParams(oDevice.MacAddress, iLevel, "");

                        if (DMSParameters.returnValue.NFLC_E_OK != response)
                        {
                            sErrorDeviceList = sErrorDeviceList + oDevice.DeviceName + Environment.NewLine;
                        }
                        System.Threading.Thread.Sleep(500);
                    }
                    fillDevice();
                    stopProcess();
                    EnabledGrid();

                    //if (DMSParameters.returnValue.NFLC_E_OK != PGLevelManager.DMS_AHLdmsPGSetDeviceParams(oDevice.MacAddress, iLevel, ""))
                    //{
                    //    System.Threading.Thread.Sleep(1000);
                    //    fillDevice();
                    //    stopProcess();
                    //    EnabledGrid();
                    //    MessageManager.ShowErrorMessage(Constant.PGLEVEL_UPDATE_ERROR, this);
                    //}
                    //else
                    //{
                    //    System.Threading.Thread.Sleep(1000);
                    //    fillDevice();
                    //    stopProcess();
                    //    EnabledGrid();
                    //}
                });

                if (sErrorDeviceList != string.Empty && sErrorDeviceList.Length > 0)
                {
                    MessageManager.ShowErrorMessage(Constant.DEVICE_PGLEVEL_UPDATE_ERROR + Environment.NewLine + sErrorDeviceList, this);
                }
                else
                {
                    MessageManager.ShowInformationMessage(Constant.DEVICE_PGLEVEL_UPDATE_SUCCESS, this);
                }
            }
            else
            {
                stopProcess();
                EnabledGrid();

            }
        }

        #endregion

        #region "Event: ConfigurationMenuItem_Click(2)"
        /// <summary>
        /// Handles the Click event of the ConfigurationMenuItem control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="RoutedEventArgs"/> instance containing the event data.</param>
        private async void ConfigurationMenuItem_Click(object sender, RoutedEventArgs e)
        {
            FillMainScreenParameters();

            startProcess(Constant.PLEASE_WAIT, this, XPosition, YPosition);
            Config oConfigForm = new Config(this);
            oConfigForm.Owner = this;
            stopProcess();
            EnabledGrid();

            oConfigForm.ShowDialog();

            bool bServerState = ConfigurationManager.GetServiceLastState();

            startProcess(Constant.PLEASE_WAIT, this, XPosition, YPosition);
            if (bServerState == false)
            {
                miAddShareFolder.IsEnabled = false;
                SharedBindedFolderList.Clear();
                miSetPGLevel.Items.Clear();
                grvDeviceLevel.ItemsSource = null;
            }
            else
            {
                miAddShareFolder.IsEnabled = true;
                await ServerManager.fillShareFolderList();
                List<SharedFolder> pShareList = ServerManager.oSharedFolderList;

                await Task.Run(() =>
                {
                    SharedFolderManager.DMS_AHLdmsGetContentTree(ref pShareList);
                    ServerManager.oSharedFolderList = pShareList;
                });
                await GetShareFolderList();
                //fillShareFolderTree();
                grvDeviceLevel.ItemsSource = ServerManager.oDeviceList;
            }
            stopProcess();
            EnabledGrid();
        }

        #endregion

        #region "Event: AboutMenuItem_Click(2)"
        /// <summary>
        /// Handles the Click event of the ConfigurationMenuItem control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="RoutedEventArgs"/> instance containing the event data.</param>
        private void AboutMenuItem_Click(object sender, RoutedEventArgs e)
        {
            About oAboutForm = new About();
            oAboutForm.Owner = this;

            oAboutForm.ShowDialog();
        }

        #endregion

        #region "Event: AddShareFolders_Click(2)"
        /// <summary>
        /// Handles the Click event of the AddShareFolders control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="RoutedEventArgs"/> instance containing the event data.</param>
        private async void AddShareFolders_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                DMSParameters.returnValue returnValue = DMSParameters.returnValue.NFLC_E_ERROR;
                bool bServerState = ConfigurationManager.GetServiceLastState();
                if (bServerState == false)
                    return;

                CommonOpenFileDialog oDialog = new CommonOpenFileDialog();
                oDialog.IsFolderPicker = true;
                oDialog.Multiselect = true;

                if (ServerManager.oSharedFolderList != null && ServerManager.oSharedFolderList.Count > 0)
                {
                    SharedFolder oSharedFolder = ServerManager.oSharedFolderList.Where(s => s.FolderName != Constant.STRING_EMPTY).LastOrDefault();
                    if (oSharedFolder != null)
                    {
                        DirectoryInfo sPath = System.IO.Directory.GetParent(oSharedFolder.SharedFolderPath);
                        if (sPath != null)
                        {
                            oDialog.InitialDirectory = sPath.ToString();
                        }
                    }
                }

                string sSuccessMsg = Constant.STRING_EMPTY;
                string sSharingErrorMsg = Constant.STRING_EMPTY;
                string sValidateErrorMsg = Constant.STRING_EMPTY;
                string sValidateRootDir = Constant.STRING_EMPTY;
                if (oDialog.ShowDialog(this) == CommonFileDialogResult.Ok)
                {
                    FillMainScreenParameters();
                    startProcess(Constant.PUBLISH_FOLDER, this, XPosition, YPosition);

                    foreach (var oFolder in oDialog.FileNames.ToList())
                    {
                        SharedFolder oSelectedSharedFolder = new SharedFolder();
                        oSelectedSharedFolder.FolderName = oFolder.ToString().Trim();
                        oSelectedSharedFolder.SharedFolderPath = oFolder.ToString().Trim();
                        oSelectedSharedFolder.PGLevel = ServerManager.oDefaultFolderPglevel;

                        /* In case of root folder, Displaying a pop-up for warning sharing a root folder */
                        if (oSelectedSharedFolder.SharedFolderPath == "C:\\")
                        {
                            sValidateRootDir = Constant.WARN_SHARING_ROOT_FOLDER + Environment.NewLine;
                        }

                        bool isValid = true;
                        await Task.Run(() =>
                        {
                            isValid = SharedFolderManager.ValidateSharedFolder(oSelectedSharedFolder, ServerManager.oSharedFolderList, ref sValidateErrorMsg);
                        });

                        if (!isValid)
                        {
                            continue;
                        }

                        await Task.Run(() =>
                        {
                            returnValue = SharedFolderManager.DMS_AHLdmsPublishStorageAdd(oFolder.ToString().Trim(), oFolder.ToString().Trim(), oFolder.ToString().Trim(), DMSParameters.dmsStorageDatabaseLocationType.DMS_STORAGE_DATABASE_LOCATION_TYPE_CENTRAL, true);
                            if (returnValue == DMSParameters.returnValue.NFLC_E_OK)
                            {
                                if (sSuccessMsg.Trim() == Constant.STRING_EMPTY)
                                {
                                    sSuccessMsg = Constant.SHARE_FOLDER_MESSAGE + Environment.NewLine;
                                }
                                sSuccessMsg = sSuccessMsg + oFolder.ToString().Trim() + Environment.NewLine;
                            }
                            else
                            {
                                if (returnValue == DMSParameters.returnValue.NFLC_E_STORAGE_LIMIT_REACHED)
                                {
                                    sSharingErrorMsg = Constant.SHARE_DRIVE_LIMIT_ERROR;
                                }
                                else
                                {
                                    sSharingErrorMsg = String.IsNullOrEmpty(sSharingErrorMsg) ? oFolder.ToString().Trim() + Environment.NewLine : sSharingErrorMsg + Environment.NewLine + oFolder.ToString().Trim();
                                }
                            }
                        });
                        if (returnValue == DMSParameters.returnValue.NFLC_E_STORAGE_LIMIT_REACHED)
                        {
                            LogManager.logMessage(Constant.ServiceManager_CLASSNAME, "NFLC_E_STORAGE_LIMIT_REACHED, so breaking the loop");
                            break;
                        }
                    }

                    _SuccessMsg = sSuccessMsg;
                    _SharingErrorMsg = sSharingErrorMsg;
                    _ValidateErrorMsg = sValidateErrorMsg;
                    _ValidateRootDirWarningMsg = sValidateRootDir;

                    if (returnValue == DMSParameters.returnValue.NFLC_E_OK)
                    {
                        ServerManager.IsCalledAfterIndexing = true;
                    }
                    UpdateTreeView();
                   
                }
            }
            catch (Exception ex)
            {
                stopProcess();
                EnabledGrid();
                LogManager.logExceptionMessage(Constant.SHARED_USERCONTROL_CLASSNAME, Constant.AddShareFolders_Click, ex);
            }
        }

        #endregion

        #region "Event: MetroWindow_Loaded(2)"
        /// <summary>
        /// Handles the Loaded event of the MetroWindow control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="RoutedEventArgs"/> instance containing the event data.</param>
        private void MetroWindow_Loaded(object sender, RoutedEventArgs e)
        {
            FirstInitlize();
            bool bServerState = ConfigurationManager.GetServiceLastState();
            miAddShareFolder.IsEnabled = bServerState;
            StartDeviceThread();
            lineShareFolder.X2 = HeaderPanel.ActualWidth;// this.ActualWidth - 138;
        }

        #endregion

        #region "Event: grvDeviceLevel_MouseRightButtonDown(2)"
        /// <summary>
        /// Handles the MouseRightButtonDown event of the grvDeviceLevel control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="MouseButtonEventArgs"/> instance containing the event data.</param>
        private void grvDeviceLevel_MouseRightButtonDown(object sender, MouseButtonEventArgs e)
        {
            //DependencyObject oDep = (DependencyObject)e.OriginalSource;
            //SelectFocusedGridRow(oDep, grvDeviceLevel);
            miContextTreeShareFolder.Visibility = Visibility.Hidden;
            TextBlock textblock = e.OriginalSource as TextBlock;
            List<DeviceEntity> oSelectedItemsList = new List<DeviceEntity>();
            if (textblock != null)
                oSelectedItemsList = ServerManager.oDeviceList.Where(a => a.DeviceName.Equals(textblock.Text)).ToList();

            if (oSelectedItemsList.Count == 0)
            {
                oSelectedItemsList = grvDeviceLevel.SelectedItems.Cast<DeviceEntity>().ToList();
            }
            int count = oSelectedItemsList.Count;
            //DeviceEntity oSelectedDevice = (DeviceEntity)grvDeviceLevel.SelectedItems;

            if (oSelectedItemsList != null && oSelectedItemsList.Count > 0)
            {
                miDevicePGLevel.Visibility = Visibility.Visible;
                miSetPGLevel.Visibility = Visibility.Visible;
                if (oSelectedItemsList.Count > 1)
                {
                    foreach (MenuItem oItem in miSetPGLevel.Items)
                    {
                        oItem.IsChecked = false;
                    }
                }
                else
                {
                    foreach (MenuItem oItem in miSetPGLevel.Items)
                    {
                        if (oItem.Header.ToString() == ServerManager.oPGLevelList.Where(p => p.Id == oSelectedItemsList[0].Level).Select(p => p.DisplayDescription.ToString()).FirstOrDefault())
                        {
                            oItem.IsChecked = true;
                        }
                        else
                        {
                            oItem.IsChecked = false;
                        }
                    }
                }
                //foreach (MenuItem oItem in miDevicePGLevel.Items)
                //{
                //    if (oItem.Header.ToString() == ServerManager.oPGLevelList.Where(p => p.Id == oSelectedDevice.Level).Select(p => p.DisplayDescription.ToString()).FirstOrDefault())
                //    {
                //        oItem.IsChecked = true;
                //    }
                //    else
                //    {
                //        oItem.IsChecked = false;
                //    }
                //}
            }
            else
            {
                miDevicePGLevel.Visibility = Visibility.Hidden;
            }
        }

        #endregion

        #endregion

        #region "Method"

        #region "Method: SharedUserControl()"
        /// <summary>
        /// Initializes a new instance of the <see cref="SharedUserControl"/> class.
        /// </summary>
        public SharedUserControl()
        {
            InitializeComponent();
            MyNotifyIcon = new System.Windows.Forms.NotifyIcon();
            MyNotifyIcon.Icon = new System.Drawing.Icon("DMS.ico");
            MyNotifyIcon.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler(MyNotifyIcon_MouseDoubleClick);
            MyNotifyIcon.MouseDown += new System.Windows.Forms.MouseEventHandler(MyNotifyIcon_MouseDown);
            StartExternalDeviceWatch();

            ServerManager.eUpdateTreeView += UpdateTreeView;
            ServerManager.eUpdateIndexingStatusView += UpdateIndexingStatusView;
            ServerManager.eUpdatePartialIndexingStatusView += UpdatePartialIndexingStatusView;
            ServerManager.eUpdateDMSStateView += UpdateDMSStateView;
        }
        #endregion

        void MyNotifyIcon_MouseDown(object sender, System.Windows.Forms.MouseEventArgs e)
        {
            if (e.Button == System.Windows.Forms.MouseButtons.Right)
            {
                ContextMenu menu = (ContextMenu)this.FindResource("NotifierContextMenu");
                menu.IsOpen = true;
            }
        }

        #region "Method: MyNotifyIcon_MouseDoubleClick(2)"
        /// <summary>
        /// It will used to send application on system try on minimize
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        void MyNotifyIcon_MouseDoubleClick(object sender, System.Windows.Forms.MouseEventArgs e)
        {
            this.WindowState = WindowState.Normal;
        }
        #endregion

        #region "Method: Window_StateChanged(2)"
        /// <summary>
        /// It will used to send application on system try on minimize
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Window_StateChanged(object sender, EventArgs e)
        {
            if (this.WindowState == WindowState.Minimized)
            {
                this.ShowInTaskbar = true;
                //MyNotifyIcon.BalloonTipTitle = "DMS Minimized.";
                //MyNotifyIcon.Visible = true;
                ////MyNotifyIcon.ShowBalloonTip(400);                
                //trvContent.Height = this.ActualHeight - 130;
                //MyNotifyIcon.ShowBalloonTip(400);                
                //trvContent.Height = this.ActualHeight - 130;
            }
            else if (this.WindowState == WindowState.Normal || this.WindowState == WindowState.Maximized)
            {
                MyNotifyIcon.Visible = false;
                this.ShowInTaskbar = true;
            }
        }
        #endregion

        #region "Method: SelectFocusedGridRow(2)"
        /// <summary>
        /// Selects the focused grid row.
        /// </summary>
        /// <param name="pDep">The DependencyObject pdep.</param>
        /// <param name="pGrid">grid.</param>
        private void SelectFocusedGridRow(DependencyObject pDep, DataGrid pGrid)
        {
            while ((pDep != null) && !(pDep is DataGridCell))
            {
                pDep = VisualTreeHelper.GetParent(pDep);
            }

            if (pDep is DataGridCell)
            {
                DataGridCell cell = pDep as DataGridCell;
                cell.Focus();

                while ((pDep != null) && !(pDep is DataGridRow))
                {
                    pDep = VisualTreeHelper.GetParent(pDep);
                }
                DataGridRow row = pDep as DataGridRow;
                pGrid.SelectedItem = row.DataContext;
            }
        }

        #endregion

        public async Task<bool> initializeForm()
        {
            try
            {
                eUpdateProgress(10);
                bool bServerState = ConfigurationManager.GetServiceLastState();

                if (bServerState == true)
                {
                    //if (ConfigurationManager.IsDMSWrapperCreated == false)
                    //{
                    CallBackHandler = new BAL.Manager.Common_Manager.ServiceManager.dmsCallbackHandler_applayer(ServerManager.dmsCallbackFunc);
                    //LogPrintCallbackFunc = new BAL.Manager.Common_Manager.ServiceManager.dmsLogPrintCallbackFunc(ServerManager.dmsLogPrint);

                    //DMSParameters.dmsWrapperInitParams oDMSWrapperInitParam = new DMSParameters.dmsWrapperInitParams();
                    ////                  GCHandle handle = GCHandle.Alloc(this);
                    ////                  oDMSWrapperInitParam.arg = (IntPtr)handle;
                    //oDMSWrapperInitParam.func = dmsLogPrint;
                    ConfigurationManager.DMSWrapperObject = ConfigurationManager.DMS_CreateDMSWrapperClass();

                    LogManager.IsLogEnable = ConfigurationManager.GetIsLogEnableStatus();

                    DMSParameters.dmsInitParams oDMSInitParam = new DMSParameters.dmsInitParams();
                    oDMSInitParam.configDirectory = System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location) + Constant.SLASH_SIGN + Constant.NFLC_XML;
                    oDMSInitParam.dmsDataDirectory = System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location) + Constant.SLASH_SIGN + Constant.DMS_DATA;
                    oDMSInitParam.upnpPort = Constant.UPNP_PORT;
                    oDMSInitParam.funccb = CallBackHandler;
                    oDMSInitParam.arg = (DMSParameters.dmsEvent.DMS_EVENT_INDEXING_STATE | DMSParameters.dmsEvent.DMS_EVENT_PARTIAL_INDEXING_STATE | DMSParameters.dmsEvent.DMS_EVENT_CA_STATE | DMSParameters.dmsEvent.DMS_EVENT_DMS_STATE);
                    oDMSInitParam.callbackarg = IntPtr.Zero;
                    eUpdateProgress(20);
                    bool bResult = ConfigurationManager.DMS_AHLdmsInitialize(ref oDMSInitParam);
                    if (bResult == false)
                    {
                        MessageManager.ShowErrorMessage(Constant.ERROR_DMS_INITIALIZE, this);
                        System.Environment.Exit(1);
                    }
                    IsInitializeSuccess = true;
                    //System.Threading.Thread.Sleep(2000);
                    //}
                    //else
                    //{
                    //    DMSParameters.returnValue retStateResult = DMSParameters.returnValue.NFLC_E_ERROR;
                    //    retStateResult = ConfigurationManager.DMS_AHLdmsSetServerState(DMSParameters.dmsState.DMS_STATE_ENABLE);

                    //    if (retStateResult != DMSParameters.returnValue.NFLC_E_OK)
                    //    {
                    //        IsInitializeSuccess = false;
                    //        eUpdateProgress(100);
                    //        return true;
                    //    }
                    //    else
                    //        IsInitializeSuccess = true;
                    //}
                    eUpdateProgress(40);
                    await ServerManager.fillDefaultFolderPGLevel();
                    //System.Threading.Thread.Sleep(1500);
                    await ServerManager.fillDefaultDevicePGLevel();
                    // System.Threading.Thread.Sleep(1500);
                    eUpdateProgress(50);
                    await ServerManager.fillPGLevel();
                    await fillDevice();
                    eUpdateProgress(60);
                    // System.Threading.Thread.Sleep(1500);

                    //// HSC changes
                    if (ServerManager.oSharedFolderList == null)
                    {
                        ServerManager.oSharedFolderList = new List<SharedFolder>();
                    }
                    if (ServerManager.oStorageStateList == null)
                    {
                        ServerManager.oStorageStateList = new List<StorageStateEntity>();
                    }
                    await ServerManager.fillShareFolderList();

                    List<SharedFolder> pShareList = ServerManager.oSharedFolderList;

                    await Task.Run(() =>
                    {
                        SharedFolderManager.DMS_AHLdmsGetContentTree(ref pShareList);
                        ServerManager.oSharedFolderList = pShareList;
                    });

                    ////					
                    await GetShareFolderList();
                    eUpdateProgress(70);
                    fillDevicePGLevelMenu();
                    eUpdateProgress(80);
                    fillPGLevelShareFolderTree();
                    eUpdateProgress(90);
                    await Task.Run(() =>
                    {
                        ServerManager.DeviceFriednlyName = ConfigurationManager.DMS_AHLdmsGetFriendlyName();
                    });
                    /* Updating the previous CA state */
                    fillCAMenu();
                    eUpdateProgress(100);
                }
                else
                {
                    eUpdateProgress(100);
                    ServiceStatusChange(false);
                }
            }
            catch (Exception ex)
            {
                eUpdateProgress(100);
                LogManager.logExceptionMessage(Constant.SHARED_USERCONTROL_CLASSNAME, Constant.SHARED_INITIALIZE_FORM_METHODNAME, ex);
            }

            return true;
        }

        #endregion

        #region "Method: FirstInitlize(0)"
        /// <summary>
        /// Firsts the initlize.
        /// </summary>
        public async void FirstInitlize()
        {
            DMSParameters.returnValue response = DMSParameters.returnValue.NFLC_E_ERROR;
            if (ConfigurationManager.readFirstInitlize() == false)
            {
                //set Service On
                await Task.Run(() =>
                {
                    response = ConfigurationManager.DMS_AHLdmsSetServerState(DMSParameters.dmsState.DMS_STATE_ENABLE);
                });
                if (response == DMSParameters.returnValue.NFLC_E_OK)
                    ConfigurationManager.writeFirstInitlize();
            }
        }

        #endregion

        #region "Method: fillDevicePGLevelMenu(0)"
        /// <summary>
        /// Fills the device pg level menu.
        /// </summary>
        public void fillDevicePGLevelMenu()
        {
            if (this.miSetPGLevel.Dispatcher.CheckAccess())
            {
                miSetPGLevel.Items.Clear();
                foreach (var oItem in ServerManager.oPGLevelList)
                {
                    MenuItem subMenuItem = new MenuItem();
                    subMenuItem.Click += MenuDevice_Clicked;

                    //place Array of symbol to check there should not be any symbol in name
                    string sName = Constant.PGLEVEL_MENU_NAME_PREFIX + oItem.Name.ToString().Trim().Replace(Constant.STRING_SPACE, Constant.STRING_EMPTY);
                    sName = Constant.PGLEVEL_MENU_NAME_PREFIX + oItem.Name.ToString().Trim().Replace(Constant.STRING_DES, Constant.STRING_EMPTY);

                    subMenuItem.Name = sName;
                    subMenuItem.Header = oItem.Description.ToString().Trim() + " (" + oItem.Name + ")";
                    subMenuItem.IsCheckable = true;
                    subMenuItem.Tag = oItem.Id;
                    miSetPGLevel.Items.Add(subMenuItem);
                }
            }
            else
                this.miSetPGLevel.Dispatcher.Invoke(new UpdateUI(fillDevicePGLevelMenu));
        }

        #endregion

        #region "Method: fillCAMenu(0)"
        /// <summary>
        /// Fills the device pg level menu.
        /// </summary>
        public async void fillCAMenu()
        {
            DMSParameters.returnValue ret = DMSParameters.returnValue.NFLC_E_ERROR;
            if (this.miCATab.Dispatcher.CheckAccess())
            {
                if (ConfigurationManager.GetCAServiceLastState())
                {
                    await Task.Run(() =>
                    {
                        ret = ConfigurationManager.DMS_AHLdmsCASetEnabled(true);
                    });
                    if (ret != DMSParameters.returnValue.NFLC_E_OK)
                    {
                        MessageManager.ShowErrorMessage(Constant.CA_ENABLE_ERROR + Environment.NewLine, this);
                        return;
                    }
                    miCATab.Visibility = Visibility.Visible;
                    miPauseCA.IsEnabled = true;
                    miResumeCA.IsEnabled = false;
                    ConfigurationManager.SetCARunningState(Constant.CA_RESUME_ENABLE);
                }
                else
                {
                    miCATab.Visibility = Visibility.Collapsed;
                    miPauseCA.IsEnabled = false;
                    miResumeCA.IsEnabled = false;
                }
            }
            else
                this.miCATab.Dispatcher.Invoke(new UpdateUI(fillCAMenu));
        }

        #endregion

        #region "Method: SetAddSharedFolderVisibility(1)"
        /// <summary>
        /// Setting add share foler menu item visibility.
        /// </summary>
        public void ServiceStatusChange(bool pValue)
        {
            if (this.miAddShareFolder.Dispatcher.CheckAccess())
            {
                miAddShareFolder.IsEnabled = pValue;
            }
            else
                this.miAddShareFolder.Dispatcher.Invoke(new ServiceStatusChangeHandle(ServiceStatusChange), new object[] { pValue });
        }

        #endregion

        #region "Method: fillDevice(0)"
        /// <summary>
        /// Fills the device.
        /// </summary>
        public async Task<bool> fillDevice()
        {
            if (this.grvDeviceLevel.Dispatcher.CheckAccess())
            {
                await Task.Run(() =>
                {
                    ServerManager.fillDevice();
                });

                grvDeviceLevel.ItemsSource = ServerManager.oDeviceList;
            }
            else
                this.grvDeviceLevel.Dispatcher.Invoke(new UpdateUIAsync(fillDevice));

            return true;
        }

        #endregion

        #region "Method: FillMainScreenParameters(0)"

        public void FillMainScreenParameters()
        {
            if (this.Dispatcher.CheckAccess())
            {
                double windowTop = this.Top;
                double windowLeft = this.Left;

                if (this.WindowState == System.Windows.WindowState.Maximized)
                {
                    windowTop = 0;
                    windowLeft = 0;
                }
                YPosition = (windowTop + (this.ActualHeight / 2));
                XPosition = (windowLeft + (this.ActualWidth / 2));
            }
            else
            {
                this.Dispatcher.Invoke(new ScreenLoaderFetchMainScreenSize(FillMainScreenParameters));
            }
        }

        #endregion

        #region "Method: startProcess(3)"
        /// <summary>
        /// Starts the process.
        /// </summary>
        public void startProcess(string pIntializeText, Window pOwnerWindow, double xPos = 0.0, double yPos = 0.0)
        {
            if (MainGrid.Dispatcher.CheckAccess())
            {
                if (objLoadingForm != null)
                {
                    stopProcess();
                }

                oMainWindow = pOwnerWindow;
                pOwnerWindow.IsEnabled = false;
                MainGrid.IsEnabled = false;
                LoadingParams oLoadingParams;
                oLoadingParams.ContentText = pIntializeText;
                oLoadingParams.xPos = xPos;
                oLoadingParams.yPos = yPos;

                objLoadingForm = new LoadingWindow(pOwnerWindow);

                System.Threading.Thread oLoaderThread = new Thread(new ParameterizedThreadStart(startLoader));
                oLoaderThread.IsBackground = true;
                oLoaderThread.SetApartmentState(ApartmentState.STA);
                oLoaderThread.Priority = ThreadPriority.Highest;
                oLoaderThread.Start(oLoadingParams);
            }
            else
            {
                MainGrid.Dispatcher.Invoke(new StartProcessDelegate(startProcess), pIntializeText, pOwnerWindow, xPos, yPos);
            }
        }
        #endregion

        #region "Method: startLoader(1)"
        /// <summary>
        /// Starts the loader.
        /// </summary>
        private static void startLoader(object pLoadingParams)
        {
            if (objLoadingForm == null)
                return;

            if (objLoadingForm.Dispatcher.CheckAccess())
            {
                LoadingParams oLodingParam = (LoadingParams)pLoadingParams;
                objLoadingForm.lblLoadingtext.Content = oLodingParam.ContentText;
                // objLoadingForm.Owner = objLoadingForm.OwnerForm;

                double screenWidth = System.Windows.SystemParameters.PrimaryScreenWidth;
                double screenHeight = System.Windows.SystemParameters.PrimaryScreenHeight;

                oLodingParam.xPos = oLodingParam.xPos - (objLoadingForm.Width / 2);
                oLodingParam.yPos = oLodingParam.yPos - (objLoadingForm.Height / 2);

                if ((screenWidth < (oLodingParam.xPos + objLoadingForm.Width)) || (screenHeight < (oLodingParam.yPos + objLoadingForm.Height)))
                {
                    objLoadingForm.WindowStartupLocation = WindowStartupLocation.CenterScreen;
                }
                else
                {
                    objLoadingForm.Left = oLodingParam.xPos;
                    objLoadingForm.Top = oLodingParam.yPos;
                }

                objLoadingForm.Activate();
                objLoadingForm.Show();

            }
            else
            {
                objLoadingForm.Dispatcher.Invoke(new StartLoader(startLoader), pLoadingParams);
            }
        }
        #endregion

        #region "Method: stopProcess(0)"
        /// <summary>
        /// Stops the process.
        /// </summary>
        /// <ModifiedDatetime>9/8/2015-4:22 PM</ModifiedDatetime>
        public static void stopProcess()
        {
            if (objLoadingForm != null)
            {
                if (objLoadingForm.Dispatcher.CheckAccess())
                {
                    objLoadingForm.Close();
                    objLoadingForm = null;
                }
                else
                {
                    objLoadingForm.Dispatcher.Invoke(new StopLoader(stopProcess));
                }
            }
        }

        #endregion

        public void EnabledGrid()
        {
            if (MainGrid.Dispatcher.CheckAccess())
            {
                MainGrid.IsEnabled = true;
                if (oMainWindow != null)
                    oMainWindow.IsEnabled = true;
            }
            else
            {
                MainGrid.Dispatcher.Invoke(new EnabledGridDelegate(EnabledGrid));
            }
        }

        // private DriveDetector driveDetector = null;
        #region "Method: StartExternalDeviceWatch(0)"
        /// <summary>
        /// Starts the watch for exxternal devices.
        /// </summary>      
        public void StartExternalDeviceWatch()
        {
            watcher = new ManagementEventWatcher();
            WqlEventQuery query = new WqlEventQuery("SELECT * FROM Win32_VolumeChangeEvent WHERE EventType = 2 or EventType = 3");
            //WqlEventQuery query = new WqlEventQuery();//"SELECT * FROM __InstanceCreationEvent WITHIN 1 WHERE TargetInstance ISA 'Win32_USBHub'");
            //query.EventClassName = "__InstanceOperationEvent";
            //query.WithinInterval = new TimeSpan(0, 0, 1);
            //query.Condition = @"TargetInstance ISA 'Win32_USBControllerdevice'";


            //WqlEventQuery q_creation = new WqlEventQuery();
            //query.EventClassName = "__InstanceCreationEvent";
            //query.WithinInterval = new TimeSpan(0, 0, 3);
            //query.Condition = "TargetInstance ISA 'Win32_USBControllerdevice'";
            //watcher = new ManagementEventWatcher(q_creation);
            // WqlEventQuery query = new WqlEventQuery("SELECT * FROM Win32_VolumeChangeEvent WHERE TargetInstance ISA 'Win32_USBControllerDevice'");
            //WqlEventQuery query = new WqlEventQuery("SELECT * FROM Win32_DeviceChangeEvent where EventType = 1 or EventType = 2");
            watcher.EventArrived += new EventArrivedEventHandler(ExternalDeviceEventArrived);
            watcher.Query = query;
            watcher.Start();
            ///watcher.WaitForNextEvent();
        }
        #endregion

        #region "Method: ExternalDeviceEventArrived(2)"
        /// <summary>
        /// Starts the watch for exxternal devices.
        /// </summary>      
        public async void ExternalDeviceEventArrived(object sender, EventArrivedEventArgs e)
        {
            bool bServerState = ConfigurationManager.GetServiceLastState();
            if (bServerState == false)
                return;
            try
            {
                foreach (PropertyData pd in e.NewEvent.Properties)
                {
                    if ((pd.Value != null) && (pd.Value.ToString().Length > 0))
                    {
                        if (DriveInfo.GetDrives().Where(x => x.Name == pd.Value.ToString().Trim() + "\\").Count() > 0)
                        {
                            if (MessageManager.ShowConfirmationMessage(Constant.DEVICE_SHARE_CONFIRMATION + Constant.STRING_SPACE +pd.Value.ToString() + Constant.STRING_SPACE + Constant.DEVICE_SHARE_CONFIRMATION_MESSAGE, this))
                            {
                                string sPenDrive = pd.Value.ToString().Trim();
                                FillMainScreenParameters();

                                startProcess(Constant.PUBLISH_DRIVE + pd.Value.ToString(), this, XPosition, YPosition);
                                DMSParameters.returnValue retAddStorageResult = DMSParameters.returnValue.NFLC_E_ERROR;
                                await Task.Run(() =>
                                {
                                    retAddStorageResult = SharedFolderManager.DMS_AHLdmsPublishStorageAdd(sPenDrive, pd.Value.ToString().Trim(), pd.Value.ToString().Trim(), DMSParameters.dmsStorageDatabaseLocationType.DMS_STORAGE_DATABASE_LOCATION_TYPE_CENTRAL, true);
                                });

                                if (retAddStorageResult == DMSParameters.returnValue.NFLC_E_OK)
                                {
                                    List<SharedFolder> pShareList = new List<SharedFolder>();
                                    await ServerManager.fillShareFolderList();
                                    await Task.Run(() =>
                                    {
                                        pShareList = ServerManager.oSharedFolderList;
                                        SharedFolderManager.DMS_AHLdmsGetContentTree(ref pShareList);
                                    });

                                    ServerManager.oSharedFolderList = pShareList;
                                    await GetShareFolderList();
                                    //fillShareFolderTree();
                                    ServerManager.IsCalledAfterIndexing = true;
                                    stopProcess();
                                    EnabledGrid();
                                    MessageManager.ShowInformationMessage(Constant.SHARE_DRIVE_MESSAGE, this);
                                    return;
                                }
                                else
                                {
                                    stopProcess();
                                    EnabledGrid();
                                    if (retAddStorageResult == DMSParameters.returnValue.NFLC_E_STORAGE_LIMIT_REACHED)
                                    {
                                        MessageManager.ShowInformationMessage(Constant.SHARE_DRIVE_LIMIT_ERROR, this);
                                    }
                                    else
                                    {
                                        MessageManager.ShowInformationMessage(Constant.SHARE_DRIVE_ERROR, this);
                                    }
                                    return;
                                }
                            }
                            else
                            {
                                return;
                            }
                        }
                        else
                        {
                            if ((ServerManager.oSharedFolderList != null) && (ServerManager.oSharedFolderList.Count > 0))
                            {
                                List<SharedFolder> unShareFolderList = ServerManager.oSharedFolderList.Where(folder => folder.SharedFolderPath.StartsWith(pd.Value.ToString().Trim())).ToList();

                                if (unShareFolderList != null && unShareFolderList.Count > 0)
                                {
                                    FillMainScreenParameters();

                                    startProcess(Constant.UNPUBLISH_DRIVE + pd.Value.ToString(), this, XPosition, YPosition);

                                    await Task.Run(() =>
                                    {
                                        foreach (SharedFolder unShareFolder in unShareFolderList)
                                        {
                                            if (unShareFolder.SharedFolderPath != null)
                                            {
                                                SharedFolderManager.DMS_AHLdmsPublishStorageRemove(unShareFolder.SharedFolderPath);

                                            }
                                        }
                                    });

                                    await ServerManager.fillShareFolderList();
                                    List<SharedFolder> pShareList = ServerManager.oSharedFolderList;

                                    await Task.Run(() =>
                                    {
                                        SharedFolderManager.DMS_AHLdmsGetContentTree(ref pShareList);
                                    });

                                    ServerManager.oSharedFolderList = pShareList;
                                    await GetShareFolderList();
                                    stopProcess();
                                    EnabledGrid();
                                    MessageManager.ShowInformationMessage(Constant.SUCCESS_DRIVE_UNSHARE + Constant.STRING_SPACE + pd.Value.ToString().Trim(), this);

                                    return;
                                }
                            }
                        }

                    }

                }
            }
            catch (Exception ex)
            {
                stopProcess();
                EnabledGrid();
                LogManager.logExceptionMessage(Constant.SHARED_USERCONTROL_CLASSNAME, Constant.SHAREDUSERCONTROL_EXTERNALDEVICEARRIVED_METHODNAME, ex);
            }

            stopProcess();
            EnabledGrid();
        }

        #endregion

        #region "Method: MetroWindow_Closing(2)"
        /// <summary>
        /// stop watcher for External Device.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void MetroWindow_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            if(this.WindowState == System.Windows.WindowState.Minimized)
            {
                //End task manager trigger shutdown.
                MyNotifyIcon.Visible = true;
                MyNotifyIcon.BalloonTipTitle = "Jio Server";
                this.ShowInTaskbar = false;
                MyNotifyIcon.BalloonTipText = "Jio Server is shutting down.";
                MyNotifyIcon.Text = "Jio Server";
                MyNotifyIcon.ShowBalloonTip(400);
                e.Cancel = true;
                ShutDownApplication();
                return;
            }
            else
            {
                this.WindowState = System.Windows.WindowState.Minimized;
            }

            MyNotifyIcon.Visible = true;
            MyNotifyIcon.BalloonTipTitle = "Jio Server";
            this.ShowInTaskbar = false;
            MyNotifyIcon.BalloonTipText = "Running in System Tray.";
            MyNotifyIcon.Text = "Jio Server";
            MyNotifyIcon.ShowBalloonTip(400);
            e.Cancel = true;
        }

        #endregion

        #region "Method: Open_DMS_Click(2)"
        /// <summary>
        /// Open Window from system tray.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Open_DMS_Click(object sender, RoutedEventArgs e)
        {
            this.WindowState = WindowState.Maximized;
            this.Focus();
        }

        #endregion

        #region "Method: ShutDownApplication()"
        /// <summary>
        /// Shutdown Application.
        /// </summary>
        private async void ShutDownApplication()
        {
            bool bServerState = ConfigurationManager.GetServiceLastState();
            bool bFinalizeResult = false;
            if (bServerState == true)
            {
                await Task.Run(() =>
                {
                    bFinalizeResult = ConfigurationManager.DMS_AHLdmsFinalize();
                });

                if (bFinalizeResult == true)
                {
                    ConfigurationManager.DMS_DeleteDMSWrapperClass();
                }
            }
            Environment.Exit(1);
        }
        #endregion

        #region "Method: Close_DMS_Click(2)"
        /// <summary>
        /// Close Application From System tray.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Close_DMS_Click(object sender, RoutedEventArgs e)
        {
            ShutDownApplication();
        }

        #endregion

        #region "Method: StartDeviceThread(0)"
        /// <summary>
        /// Start Thread For Device Refresh.
        /// </summary>
        private void StartDeviceThread()
        {
            DeviceThread = new System.Threading.Thread(new System.Threading.ThreadStart(DeviceThreadCall));
            DeviceThread.Name = "DEVICE_THREAD";
            DeviceThread.IsBackground = true;
            DeviceThread.Start();
        }

        #endregion

        #region "Method: DeviceThreadCall(0)"
        /// <summary>
        /// DeviceThreadCall
        /// </summary>
        private void DeviceThreadCall()
        {
            while (DeviceThread.IsAlive)
            {
                try
                {
                    System.Threading.Thread.Sleep(60000);
                    bool bServiceLastStatus = ConfigurationManager.GetServiceLastState();
                    if (bServiceLastStatus == true)
                        fillDevice();
                }
                catch (Exception ex)
                {
                    LogManager.logExceptionMessage(Constant.SHARED_USERCONTROL_CLASSNAME, Constant.SHARED_DEVICETHREAD_FORM_METHODNAME, ex);
                }
            }
        }

        #endregion

        #region "DoEvents"
        /// <summary>
        /// DoEvents
        /// </summary>
        private delegate void EmptyDelegate();
        public static void DoEvents()
        {
            Dispatcher.CurrentDispatcher.Invoke(DispatcherPriority.Background, new EmptyDelegate(delegate { }));
        }
        #endregion

        //private void trvContent_Collapsed(object sender, RoutedEventArgs e)
        //{
        //    TreeViewItem oNode = e.Source as TreeViewItem; ;
        //    oNode.Items.Clear();
        //    oNode.Items.Add(dummyNode);
        //}
        #region "Method: trvContent_Expanded(2)"
        /// <summary>
        /// Fill Child node on Expand.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private async void trvContent_Expanded(object sender, RoutedEventArgs e)
        {
            //return;
            TreeViewItem oNode1 = e.OriginalSource as TreeViewItem;
            // TreeViewItem oNode = new TreeViewItem();
            //if (oNode != null)
            //{
            //    selectedTreeViewItemListClear();              
            //    multiSelectTree(oNode);

            //    oNode.Focus();
            //    e.Handled = true;
            //}
            FillMainScreenParameters();

            startProcess(Constant.PLEASE_WAIT, this, XPosition, YPosition);

            await Task.Run(() =>
            {
                Thread.Sleep(100);
            });
            //oNode.Items.Clear();
            DoEvents();
            try
            {
                List<ContentTreeItems> oContentTreeList = new List<ContentTreeItems>();
                if (oNode1 != null && oNode1.Header != null)
                {

                    BindingFolder oFolder = (BindingFolder)oNode1.Header;

                    SharedFolder oShareFolder = ServerManager.oSharedFolderList.Where(folder => folder.ContainerID.Trim() == oFolder.ContainerID.Trim()).FirstOrDefault();
                    if (oShareFolder != null && oShareFolder.SharedFolderPath != null)
                    {
                        StorageStateEntity oStateEntity = ServerManager.oStorageStateList.Where(index => index.storagePath == oShareFolder.SharedFolderPath).FirstOrDefault();
                        if (oStateEntity != null)
                        {
                            if (!oStateEntity.indexingState.Equals(Constant.INDEXING_STATE_DONE))
                            {
                                stopProcess();
                                EnabledGrid();
                                return;
                            }
                        }
                    }
                    await Task.Run(() =>
                    {
                        ContentTree oContentTree = new ContentTree();
                        SharedFolderManager.DMS_AHLdmsGetContentTree(oFolder.ContainerID, 0, oFolder.ChildCount, ref oContentTree);
                        oContentTreeList = oContentTree.contentTreeEntityList;
                    });

                    if (oContentTreeList != null)
                    {
                        FillTreeViewNodes(oContentTreeList, ref oFolder);
                        DoEvents();
                    }
                    else
                    {
                        oFolder.Folders.Clear();
                    }
                }

                if ((selectedTreeViewItemList != null) && (selectedTreeViewItemList.Count > 0))
                    selectedTreeViewItemListClear();

                stopProcess();
                EnabledGrid();
            }
            catch (Exception ex)
            {
                stopProcess();
                EnabledGrid();
                LogManager.logExceptionMessage(Constant.SHARED_USERCONTROL_CLASSNAME, Constant.MENU_TREEFOLDER_CLICKED_METHODNAME, ex);
            }
        }

        #endregion

        public static int count = 0;
        private void FillTreeViewNodes(List<ContentTreeItems> pContentTreeList, ref BindingFolder pNode1)
        {
            count = 0;
            pNode1.Folders.Clear();
            foreach (ContentTreeItems oItem in pContentTreeList)
            {
                BindingFolder oChildFolder = new BindingFolder();
                oChildFolder.Name = oItem.dctitle.Replace("_", "__"); ;
                oChildFolder.DisplayName = oItem.dctitle.Replace("_", "__");
                oChildFolder.GifImageVissible = System.Windows.Visibility.Collapsed;
                oChildFolder.PGLevel = oItem.pgLevel;
                oChildFolder.DisplayPGLevel = ServerManager.oPGLevelList.Where(p => p.Id == oItem.pgLevel).Select(p => p.Name).FirstOrDefault();
                oChildFolder.ContainerID = oItem.ContainerID;
                oChildFolder.ChildCount = oItem.childCount;
                oChildFolder.IsParent = false;
                oChildFolder.ParentFolder = pNode1;
                oChildFolder.BackgroudColor = Brushes.White;
                oChildFolder.ForegroundColor = Brushes.Black;

                getPglevelTooltip(oItem.pgLevel, oChildFolder);

                if (oItem.upnpclass.ToLower() == Constant.UPNPCLASS_CONTAINER.ToLower())
                {
                    oChildFolder.Folders = new ObservableCollection<BindingFolder>();
                    BindingFolder oDummyFamilyMember = new BindingFolder();
                    oDummyFamilyMember.Name = "";
                    oChildFolder.Folders.Add(oDummyFamilyMember);
                }

                pNode1.Folders.Add(oChildFolder);

                DoEvents();
                count++;
                // objLoadingForm.lblLoadingtext.Content = "Loading : " + count.ToString();
            }
        }

        #region "Method: GetShareFolderList(2)"
        /// <summary>
        /// Get ShareFolderList
        /// </summary>
        private async Task<bool> GetShareFolderList()
        {
            if (this.trvContent.Dispatcher.CheckAccess())
            {
                await ServerManager.UnshareNotAvailableFolder();

                if ((ServerManager.oSharedFolderList != null) && (ServerManager.oSharedFolderList.Count > 0))
                {
                    SharedBindedFolderList.Clear();
                    foreach (SharedFolder oShareFolder in ServerManager.oSharedFolderList)
                    {
                        BindingFolder oSharedFolderForBinding = new BindingFolder();

                        string sDisplayName = oShareFolder.FolderName.Replace("_", "__");
                        string sSharedFolderPath = oShareFolder.SharedFolderPath.Replace("_", "__");
                        oSharedFolderForBinding.GifImageVissible = System.Windows.Visibility.Visible;
                        oSharedFolderForBinding.vissible = System.Windows.Visibility.Collapsed;
                       
                        oSharedFolderForBinding.DisplayName = sDisplayName + " (" + sSharedFolderPath + ")";
                        oSharedFolderForBinding.Name = sDisplayName;
                        oSharedFolderForBinding.FolderPath = sSharedFolderPath;
                        oSharedFolderForBinding.PGLevel = oShareFolder.PGLevel;
                        oSharedFolderForBinding.DisplayPGLevel = ServerManager.oPGLevelList.Where(p => p.Id == oShareFolder.PGLevel).Select(p => p.Name).FirstOrDefault();
                        oSharedFolderForBinding.ContainerID = oShareFolder.ContainerID;
                        oSharedFolderForBinding.ChildCount = oShareFolder.childCount;
                        oSharedFolderForBinding.IsParent = true;

                        oSharedFolderForBinding.BackgroudColor = Brushes.White;
                        oSharedFolderForBinding.ForegroundColor = Brushes.Black;

                        getPglevelTooltip(oShareFolder.PGLevel, oSharedFolderForBinding);

                        oSharedFolderForBinding.Folders = new ObservableCollection<BindingFolder>();
                        StorageStateEntity oStateEntity = ServerManager.oStorageStateList.Where(index => index.storagePath == oShareFolder.SharedFolderPath).FirstOrDefault();
                        if (oStateEntity != null)
                        {
                            if (oStateEntity.indexingState.Equals(Constant.INDEXING_STATE_DONE))
                            {
                                BindingFolder oDummyFamilyMember = new BindingFolder();
                                oDummyFamilyMember.Name = "";
                                oSharedFolderForBinding.Folders.Add(oDummyFamilyMember);
                            }
                        }

                        SharedBindedFolderList.Add(oSharedFolderForBinding);
                        // Updating the UI with current indexing state 
                        UpdateIndexingStatusView(true);
                    }

                    trvContent.ItemsSource = SharedBindedFolderList;
                }
                else
                {
                    SharedBindedFolderList.Clear();
                }
            }
            else
                this.trvContent.Dispatcher.Invoke(new UpdateTreeViewUI(GetShareFolderList));

            return true;
        }
        #endregion

        private BindingFolder VisualUpwardSearch(DependencyObject source)
        {
            while (source != null && !(source is TreeViewItem))
                source = VisualTreeHelper.GetParent(source);

            if (source == null)
                return null;

            TreeViewItem oItem = source as TreeViewItem;

            return oItem.Header as BindingFolder;
        }


        private void trvTree_RightClick(object sender, MouseButtonEventArgs e)
        {
            miContextTreeShareFolder.Visibility = Visibility.Hidden;
        }

        private void trvTree_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            miContextTreeShareFolder.Visibility = Visibility.Hidden;
        }


        #region "Method: trvContent_RightClick(2)"
        /// <summary>
        /// Right Click of Tree node
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void trvContent_RightClick(object sender, MouseButtonEventArgs e)
        {
            if (miContextTreeShareFolder.Visibility != System.Windows.Visibility.Visible)
                miContextTreeShareFolder.Visibility = System.Windows.Visibility.Visible;

            miDevicePGLevel.Visibility = Visibility.Hidden;

            BindingFolder treeViewItem = (sender as TreeViewItem).Header as BindingFolder;

            if (treeViewItem != null)
            {
                miContextTreeShareFolder.Visibility = System.Windows.Visibility.Visible;
                treeViewItem.IsSelected = true;
                e.Handled = true;
                ChangeTreeviewSelectionState(treeViewItem, e);
            }
            else
            {
                miContextTreeShareFolder.Visibility = System.Windows.Visibility.Hidden;
                return;
            }

            if (treeViewItem.IsParent == true)
            {
                StorageStateEntity oStateEntity = ServerManager.oStorageStateList.Where(index => index.storagePath == treeViewItem.FolderPath).FirstOrDefault();
                if (oStateEntity != null)
                {
                    if (oStateEntity.indexingState.Equals(Constant.INDEXING_STATE_DONE))
                    {
                        ParentNodeRightClick(treeViewItem);
                    }
                    else
                    {
                        setContextVisibility(System.Windows.Visibility.Visible, System.Windows.Visibility.Collapsed,
                        System.Windows.Visibility.Collapsed, System.Windows.Visibility.Collapsed);
                    }
                }
            }
            else
            {
                trvSubItemContent_RightClick(treeViewItem);
            }
        }

        #endregion

        private void ParentNodeRightClick(BindingFolder treeViewItem)
        {
            bool isParent = false;
            bool isChild = false;
            if ((selectedTreeViewItemList != null) && (selectedTreeViewItemList.Count > 1))
            {
                foreach (BindingFolder oTree in selectedTreeViewItemList)
                {
                    foreach (MenuItem oItem in miTreeShareFolder.Items)
                    {
                        oItem.IsChecked = false;
                    }
                    if (oTree.IsParent == true)
                    {
                        isParent = true;
                    }
                    else
                    {
                        isChild = true;
                    }
                }

                if ((isParent) && (isChild))
                {
                    setContextVisibility(System.Windows.Visibility.Collapsed, System.Windows.Visibility.Collapsed,
                        System.Windows.Visibility.Collapsed, System.Windows.Visibility.Visible);
                }
                else if ((isParent) && (!isChild))
                {
                    if (selectedTreeViewItemList.Count > 1)
                        setContextVisibility(System.Windows.Visibility.Visible, System.Windows.Visibility.Collapsed,
                            System.Windows.Visibility.Visible, System.Windows.Visibility.Visible);
                    else
                        setContextVisibility(System.Windows.Visibility.Visible, System.Windows.Visibility.Visible,
                            System.Windows.Visibility.Visible, System.Windows.Visibility.Visible);
                }
                else if ((!isParent) && (isChild))
                {
                    setContextVisibility(System.Windows.Visibility.Collapsed, System.Windows.Visibility.Collapsed,
                        System.Windows.Visibility.Collapsed, System.Windows.Visibility.Visible);
                }
            }
            else
            {
                setContextVisibility(System.Windows.Visibility.Visible, System.Windows.Visibility.Visible,
                            System.Windows.Visibility.Visible, System.Windows.Visibility.Visible);

                BindingFolder oTreeItem = trvContent.SelectedValue as BindingFolder;
                if (oTreeItem != null)
                {
                    if (oTreeItem.IsParent == true)
                    {
                        if (oTreeItem.ContainerID != null)
                        {
                            if ((ServerManager.oSharedFolderList != null) && (ServerManager.oSharedFolderList.Count > 0))
                            {
                                SharedFolder oSelectedShareFolder = ServerManager.oSharedFolderList.Where(s => s.ContainerID == oTreeItem.ContainerID.Trim()).FirstOrDefault();

                                if (oSelectedShareFolder != null)
                                {
                                    foreach (MenuItem oItem in miTreeShareFolder.Items)
                                    {
                                        //string sPgLevel = "";
                                        //if (oItem.DisplayMemberPath != null && oItem.DisplayMemberPath.Length > 0)
                                        //{
                                        //    sPgLevel = oItem.DisplayMemberPath.ToString().Split(':').FirstOrDefault();
                                        //}
                                        if (oItem.DisplayMemberPath.ToString().ToLower() == oSelectedShareFolder.PGLevel.ToString().ToLower())
                                        {
                                            oItem.IsChecked = true;
                                        }
                                        else
                                        {
                                            oItem.IsChecked = false;
                                        }
                                    }
                                }
                            }
                        }

                    }
                    else
                    {
                        //Child
                        BindingFolder oSelectedItem = (BindingFolder)trvContent.SelectedItem;

                        if (oSelectedItem != null)
                        {
                            foreach (MenuItem oItem in miTreeShareFolder.Items)
                            {
                                if (oItem.DisplayMemberPath.ToString().ToLower() == oSelectedItem.PGLevel.ToString().ToLower())
                                {
                                    oItem.IsChecked = true;
                                }
                                else
                                {
                                    oItem.IsChecked = false;
                                }
                            }
                        }
                    }
                }
            }

        }

        #region "Method: trvSubItemContent_RightClick(2)"
        /// <summary>
        /// Right Click 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void trvSubItemContent_RightClick(BindingFolder treeViewItem)
        {
            if ((selectedTreeViewItemList != null) && (selectedTreeViewItemList.Count > 1))
            {
                foreach (MenuItem oItem in miTreeShareFolder.Items)
                {
                    oItem.IsChecked = false;
                }
            }
            else
            {
                foreach (MenuItem oItem in miTreeShareFolder.Items)
                {
                    //int iPgLevel = 0;
                    //if (oNode.DisplayMemberPath != null)
                    //{
                    //    bool isPgLevel = int.TryParse(oNode.DisplayMemberPath.Split(':').FirstOrDefault(), out iPgLevel);
                    //}

                    if (oItem.DisplayMemberPath == treeViewItem.PGLevel.ToString())
                    {
                        oItem.IsChecked = true;
                    }
                    else
                    {
                        oItem.IsChecked = false;
                    }
                }
            }

            miUnShareFolder.Visibility = System.Windows.Visibility.Collapsed;
            miTreeOpenFileLocation.Visibility = System.Windows.Visibility.Collapsed;
            miMenuSeprator.Visibility = System.Windows.Visibility.Collapsed;
            miTreeShareFolder.Visibility = System.Windows.Visibility.Visible;
        }

        #endregion

        public void fillPGLevelShareFolderTree()
        {
            if (this.miTreeShareFolder.Dispatcher.CheckAccess())
            {
                miTreeShareFolder.Items.Clear();
                foreach (var oItem in ServerManager.oPGLevelList)
                {
                    //if (oItem.Description.ToLower().Trim() == Constant.BLOCK_DEVICE.ToLower().Trim())
                    //{
                    //    continue;
                    //}

                    if (oItem.Id > 0)
                    {
                        MenuItem subMenuItem = new MenuItem();
                        subMenuItem.Click += MenuTreeFolder_Clicked;

                        //place Array of symbol to check there should not be any symbol in name
                        string sName = Constant.PGLEVEL_MENU_NAME_PREFIX + oItem.Name.ToString().Trim().Replace(Constant.STRING_SPACE, Constant.STRING_EMPTY);
                        sName = Constant.PGLEVEL_MENU_NAME_PREFIX + oItem.Name.ToString().Trim().Replace(Constant.STRING_DES, Constant.STRING_EMPTY);

                        subMenuItem.Name = sName;
                        subMenuItem.Header = oItem.Description.Trim() + " (" + oItem.Name.Trim() + ")";
                        subMenuItem.IsCheckable = true;
                        subMenuItem.DisplayMemberPath = oItem.Id.ToString();
                        miTreeShareFolder.Items.Add(subMenuItem);
                    }
                }
            }
            else
                this.miTreeShareFolder.Dispatcher.Invoke(new UpdateUI(fillPGLevelShareFolderTree));
        }

        #region "Event: MenuTreeFolder_Clicked(2)"
        /// <summary>
        /// Handles the Clicked event of the MenuShareFolder control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="RoutedEventArgs"/> instance containing the event data.</param>
        private async void MenuTreeFolder_Clicked(object sender, RoutedEventArgs e)
        {
            try
            {
                FillMainScreenParameters();
                string pErrorMsg = Constant.STRING_EMPTY;

                int level = 0;
                bool IsContextMenuDisable = false;
                DMSParameters.returnValue returnValue = DMSParameters.returnValue.NFLC_E_OK;

                startProcess(Constant.SETTING_FOLDER_PGLEVEL, this, XPosition, YPosition);

                if ((selectedTreeViewItemList != null) && (selectedTreeViewItemList.Count > 0))
                {
                    foreach (BindingFolder oTreeItem in selectedTreeViewItemList)
                    {
                        if (oTreeItem.ContainerID != null)
                        {
                            if (changedTreeViewItemList == null)
                            {
                                changedTreeViewItemList = new List<BindingFolder>();
                            }
                            changedTreeViewItemList.Add(oTreeItem);
                            MenuItem oMenu = (MenuItem)sender;
                            string sTreeItemTag = oTreeItem.ContainerID.ToString();
                            string sMenuHeader = oMenu.Header.ToString();
                            string FolderName = oTreeItem.Name;// GetHeader(oTreeItem);
                            await Task.Run(() =>
                            {
                                if (IsContextMenuDisable == false)
                                {
                                    Thread.Sleep(500);
                                    IsContextMenuDisable = true;
                                }
                                level = ServerManager.oPGLevelList.Where(p => p.DisplayDescription.Equals(sMenuHeader)).Select(p => p.Id).FirstOrDefault();
                                returnValue = PGLevelManager.DMS_AHLdmsPGSetContentLevel(sTreeItemTag, level);
                                if (returnValue != DMSParameters.returnValue.NFLC_E_OK)
                                {
                                    pErrorMsg = pErrorMsg + FolderName + Environment.NewLine;
                                }
                            });
                            if (returnValue == DMSParameters.returnValue.NFLC_E_OK)
                            {
                                //oTreeItem.DisplayMemberPath = level.ToString();
                                SharedFolder oSelectedShareFolder = ServerManager.oSharedFolderList.Where(s => s.ContainerID == sTreeItemTag).FirstOrDefault();
                                if (oSelectedShareFolder != null)
                                    oSelectedShareFolder.PGLevel = level;

                                UpdatePgLevelLable(level, oTreeItem);
                                getPglevelTooltip(level, oTreeItem);

                                //Expand if parent pglevel change
                                ExpandIfParentPGlevelChange();

                                await Task.Run(() =>
                                {
                                    System.Threading.Thread.Sleep(500);
                                });

                                //Change pglevel of parent folder
                                await ChangeParentPGlevelIfRequired(oTreeItem);
                            }
                        }
                    }
                }

                selectedTreeViewItemListClear();
                selectedTreeViewItemList = new List<BindingFolder>();// = new List<TreeViewItem>();

                stopProcess();
                EnabledGrid();
                if (pErrorMsg != Constant.STRING_EMPTY)
                    MessageManager.ShowErrorMessage(Constant.FOLDER_PGLEVEL_UPDATE_ERROR + Environment.NewLine + pErrorMsg, this);
                else
                    MessageManager.ShowInformationMessage(Constant.FOLDER_PGLEVEL_UPDATE_SUCCESS, this);

            }
            catch (Exception ex)
            {
                selectedTreeViewItemList = new List<BindingFolder>();// = new List<TreeViewItem>();
                stopProcess();
                EnabledGrid();
                LogManager.logExceptionMessage(Constant.SHARED_USERCONTROL_CLASSNAME, Constant.MENU_TREEFOLDER_CLICKED_METHODNAME, ex);
            }

        }

        #endregion

        #region "ExpandIfParentPGlevelChange"
        /// <summary>
        /// ExpandIfParentPGlevelChange
        /// </summary>
        private void ExpandIfParentPGlevelChange()
        {
            if (selectedTreeViewItemList != null && selectedTreeViewItemList.Count > 0)
            {
                foreach (BindingFolder oBindingFolder in selectedTreeViewItemList)
                {
                    //Check if Parent FOlder then Collapse
                    if (oBindingFolder.ChildCount > 0)
                    {
                        oBindingFolder.IsNodeExpanded = false;
                    }
                }
            }
        }
        #endregion

        #region "ChangeParentPGlevelIfRequired"
        /// <summary>
        /// ChangeParentPGlevelIfRequired - Update the parent's PG level if needed 
        /// </summary>
        private async Task<bool> ChangeParentPGlevelIfRequired(BindingFolder oBindingFolder)
        {
            BindingFolder oParentFolder = new BindingFolder();

            oParentFolder = oBindingFolder.ParentFolder;

            if (oParentFolder != null)
            {
                while (true)
                {
                    string sParentTag = oParentFolder.ContainerID.ToString();
                    ContentTree oContentTree = new ContentTree();

                    await Task.Run(() =>
                    {
                        SharedFolderManager.DMS_AHLdmsGetContentTree(sParentTag, 0, oParentFolder.ChildCount, ref oContentTree);
                    });

                    foreach (BindingFolder oTreeItem in oParentFolder.Folders)
                    {
                        ContentTreeItems oContentItem = oContentTree.contentTreeEntityList.Where(c => c.ContainerID == oTreeItem.ContainerID.ToString()).FirstOrDefault();
                        if (oContentItem != null)
                        {
                            UpdatePgLevelLable(oContentItem.pgLevel, oTreeItem);
                            getPglevelTooltip(oContentItem.pgLevel, oTreeItem);
                            //ChangeDisplayMemberPath(oTreeItem, oContentItem.pgLevel);
                        }
                    }

                    if (oParentFolder.ParentFolder == null)
                    {
                        List<SharedFolder> oShareList = ServerManager.oSharedFolderList;
                        await Task.Run(() =>
                        {
                            SharedFolderManager.DMS_AHLdmsGetContentTree(ref oShareList);
                        });

                        ServerManager.oSharedFolderList = oShareList;

                        SharedFolder oShareFolder = ServerManager.oSharedFolderList.Where(s => s.ContainerID.ToLower() == oParentFolder.ContainerID.ToString().ToLower()).FirstOrDefault();
                        if (oShareFolder != null)
                        {
                            UpdatePgLevelLable(oShareFolder.PGLevel, oParentFolder);
                            getPglevelTooltip(oShareFolder.PGLevel, oParentFolder);
                        }
                        break;
                    }
                    oParentFolder = oParentFolder.ParentFolder;
                }
            }

            return true;
        }
        #endregion

        private async void miUnShareFolder_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                string sErrorMsg = Constant.STRING_EMPTY;
                string sSuccessMsg = Constant.STRING_EMPTY;

                FillMainScreenParameters();

                startProcess(Constant.UNPUBLISH_FOLDER, this, XPosition, YPosition);

                if ((selectedTreeViewItemList != null) && (selectedTreeViewItemList.Count > 0))
                {
                    foreach (BindingFolder oTreeItem in selectedTreeViewItemList)
                    {
                        if (oTreeItem.ContainerID != null)
                        {
                            if ((ServerManager.oSharedFolderList != null) && (ServerManager.oSharedFolderList.Count > 0))
                            {
                                SharedFolder oSelectedShareFolder = ServerManager.oSharedFolderList.Where(s => s.ContainerID.ToLower() == oTreeItem.ContainerID.ToString().ToLower()).FirstOrDefault();
                                if (oSelectedShareFolder != null)
                                {
                                    await Task.Run(() =>
                                    {
                                        if (DMSParameters.returnValue.NFLC_E_OK != SharedFolderManager.DMS_AHLdmsPublishStorageRemove(oSelectedShareFolder.SharedFolderPath))
                                        {
                                            sErrorMsg = sErrorMsg + oSelectedShareFolder.SharedFolderPath + Environment.NewLine;
                                            //sErrorMsg = sErrorMsg + Constant.ERROR_UNSHARE_FOLDER + oSelectedShareFolder.SharedFolderPath + Environment.NewLine;
                                        }
                                        else
                                        {
                                            sSuccessMsg = sSuccessMsg + oSelectedShareFolder.SharedFolderPath + Environment.NewLine;
                                            //sSuccessMsg = oSelectedShareFolder.SharedFolderPath + Constant.UNSHARE_SUCCESSFULLY;
                                            //MessageManager.ShowInformationMessage(oSelectedShareFolder.SharedFolderPath + Constant.UNSHARE_SUCCESSFULLY, this);
                                        }
                                    });
                                    StorageStateEntity oStateEntity = ServerManager.oStorageStateList.Where(index => index.storagePath == oSelectedShareFolder.SharedFolderPath).FirstOrDefault();
                                    if (oStateEntity != null)
                                    {
                                        ServerManager.oStorageStateList.Remove(oStateEntity);
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    BindingFolder oSelectedTreeItem = trvContent.SelectedItem as BindingFolder;
                    if (oSelectedTreeItem != null)
                    {
                        if (oSelectedTreeItem.ContainerID != null)
                        {
                            if ((ServerManager.oSharedFolderList != null) && (ServerManager.oSharedFolderList.Count > 0))
                            {
                                SharedFolder oSelectedShareFolder = ServerManager.oSharedFolderList.Where(s => s.ContainerID.ToLower() == oSelectedTreeItem.ContainerID.ToString().ToLower()).FirstOrDefault();
                                if (oSelectedShareFolder != null)
                                {
                                    await Task.Run(() =>
                                    {
                                        if (DMSParameters.returnValue.NFLC_E_OK != SharedFolderManager.DMS_AHLdmsPublishStorageRemove(oSelectedShareFolder.SharedFolderPath))
                                        {
                                            //sErrorMsg = sErrorMsg + Constant.ERROR_UNSHARE_FOLDER + oSelectedShareFolder.SharedFolderPath + Environment.NewLine;
                                            sErrorMsg = sErrorMsg + oSelectedShareFolder.SharedFolderPath + Environment.NewLine;
                                        }
                                        else
                                        {
                                            sSuccessMsg = oSelectedShareFolder.SharedFolderPath;
                                            //sSuccessMsg = oSelectedShareFolder.SharedFolderPath + Constant.UNSHARE_SUCCESSFULLY ;
                                            //MessageManager.ShowInformationMessage(oSelectedShareFolder.SharedFolderPath + Constant.UNSHARE_SUCCESSFULLY, this);
                                        }
                                    });
                                    StorageStateEntity oStateEntity = ServerManager.oStorageStateList.Where(index => index.storagePath == oSelectedShareFolder.SharedFolderPath).FirstOrDefault();
                                    if (oStateEntity != null)
                                    {
                                        ServerManager.oStorageStateList.Remove(oStateEntity);
                                    }
                                }
                            }
                        }
                    }
                }


                await ServerManager.fillShareFolderList();

                List<SharedFolder> pShareList = ServerManager.oSharedFolderList;
                await Task.Run(() =>
                {
                    SharedFolderManager.DMS_AHLdmsGetContentTree(ref pShareList);
                });

                ServerManager.oSharedFolderList = pShareList;
                await GetShareFolderList();

                selectedTreeViewItemList = new List<BindingFolder>();// = new List<TreeViewItem>();

                foreach (BindingFolder oItem in SharedBindedFolderList)
                {
                    //string FolderPath = "";
                    //if (oItem.DisplayMemberPath != null && oItem.DisplayMemberPath.Length > 0)
                    //{
                    //    FolderPath = oItem.DisplayMemberPath.Substring(0, oItem.DisplayMemberPath.LastIndexOf(':'));
                    //}
                    SharedFolder oSharedFolder = ServerManager.oSharedFolderList.Where(index => index.ContainerID == oItem.ContainerID).FirstOrDefault();
                    if (oSharedFolder != null)
                    {
                        if (oSharedFolder.ContainerID == null)
                            oItem.ContainerID = oSharedFolder.FolderName;
                        else
                            oItem.ContainerID = oSharedFolder.ContainerID;

                        getPglevelTooltip(oSharedFolder.PGLevel, oItem);

                        oItem.DisplayPGLevel = ServerManager.oPGLevelList.Where(p => p.Id == oSharedFolder.PGLevel).Select(p => p.Name).FirstOrDefault();

                        //DockPanel oDockPanel = (DockPanel)oItem.Header;
                        //foreach (Label oLable in oDockPanel.Children)
                        //{
                        //    if (ServerManager.oPGLevelList != null)
                        //    {
                        //        if (oLable == (Label)oDockPanel.Children[1])
                        //            oLable.Content = ServerManager.oPGLevelList.Where(p => p.Id == oSharedFolder.PGLevel).Select(p => p.Name).FirstOrDefault();
                        //    }
                        //}
                    }

                }
                stopProcess();
                EnabledGrid();

                string sPopupMessage = "";
                if ((sErrorMsg != null) && (sErrorMsg.Length > 0))
                {
                    sPopupMessage = Constant.ERROR_UNSHARE_FOLDER + Environment.NewLine + sErrorMsg;
                    //MessageManager.ShowWarningMessage(sErrorMsg, this);
                }
                if ((sSuccessMsg != null) && (sSuccessMsg.Length > 0))
                {
                    if (sPopupMessage != null && sPopupMessage != Constant.STRING_EMPTY)
                    {
                        sPopupMessage = sPopupMessage + Environment.NewLine;
                    }

                    sPopupMessage = sPopupMessage + Constant.UNSHARE_SUCCESSFULLY + Environment.NewLine + sSuccessMsg;
                    //MessageManager.ShowInformationMessage(sSuccessMsg, this);
                }

                if (sPopupMessage != null && sPopupMessage.Length > 0)
                {
                    MessageWindow win = new MessageWindow(MessageEntity.MessageType.MESSAGE_TYPE_INFORMATION, sPopupMessage, this);
                    win.Show();
                    //MessageManager.ShowInformationMessage(sPopupMessage, this);
                }

            }
            catch (Exception ex)
            {
                stopProcess();
                EnabledGrid();
               // MessageManager.ShowWarningMessage(Constant.ERROR_UNSHARE_FOLDER, this);
                MessageWindow win = new MessageWindow(MessageEntity.MessageType.MESSAGE_TYPE_WARNING, Constant.ERROR_UNSHARE_FOLDER, this);
                win.Show();
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, Constant.FUNC_NAME_DMS_AHLdmsSearchContent, ex);
            }
            stopProcess();
            EnabledGrid();
        }

        private void miTreeOpenFileLocation_Click(object sender, RoutedEventArgs e)
        {
            if (trvContent.SelectedItem != null)
            {
                BindingFolder oSelectedNode = (BindingFolder)trvContent.SelectedItem;

                if (oSelectedNode.ContainerID != null)
                {
                    SharedFolder oSelectedShareFolder = ServerManager.oSharedFolderList.Where(s => s.ContainerID.ToLower() == oSelectedNode.ContainerID.ToString().ToLower().Trim()).FirstOrDefault();
                    if (oSelectedShareFolder != null)
                    {
                        System.Diagnostics.Process.Start(oSelectedShareFolder.SharedFolderPath);
                    }
                }

            }
        }

        private void ChangeTreeviewSelectionState(BindingFolder pNode, MouseButtonEventArgs pEvent)
        {
            if ((Keyboard.IsKeyDown(Key.LeftCtrl) || Keyboard.IsKeyDown(Key.RightCtrl)) && (pEvent.ChangedButton == MouseButton.Left))
            {
                foreach (BindingFolder oItem in trvContent.Items)
                {
                    if (oItem.ContainerID == pNode.ContainerID)
                    {
                        if ((selectedTreeViewItemList != null) && (selectedTreeViewItemList.Count > 0))
                        {
                            if (!selectedTreeViewItemList.Contains(pNode))
                            {
                                multiSelectTree(pNode);
                                return;
                            }
                            else
                            {
                                multiDeselectTree(pNode);
                                return;
                            }
                        }
                        else
                        {
                            multiSelectTree(pNode);
                            return;
                        }
                    }
                }
            }
            else
            {
                if (pEvent.ChangedButton == MouseButton.Right)
                {
                    if (selectedTreeViewItemList.Contains(pNode) == false)
                    {
                        selectedTreeViewItemListClear();
                    }
                }
                else
                {
                    selectedTreeViewItemListClear();
                }

                multiSelectTree(pNode);
            }
        }

        private void trvContent_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            BindingFolder oNode = new BindingFolder();

            if (sender is TreeView)
            {
                oNode = (sender as TreeView).SelectedItem as BindingFolder;
            }

            if (sender is TreeViewItem)
            {
                oNode = (sender as TreeViewItem).Header as BindingFolder;
            }

            if (oNode != null)
            {
                //oNode.Focus();
                e.Handled = true;
            }
            else
            {
                return;
            }

            if (oNode.IsParent == true)
            {
                ChangeTreeviewSelectionState(oNode, e);
                grvDeviceLevel.SelectedIndex = -1;
            }
            else
            {
                subitem_MouseLeftButtonUp(oNode, e.ChangedButton);
            }
        }

        private void multiSelectTree(BindingFolder pTreeNode)
        {
            //pTreeNode.Background = Brushes.SkyBlue;
            BrushConverter bc = new BrushConverter();
            pTreeNode.BackgroudColor = (Brush)bc.ConvertFrom("#70C5E9");
            pTreeNode.ForegroundColor = Brushes.White;

            //DockPanel oDockPanel = (DockPanel)pTreeNode.Header;
            //foreach (Label oItem in oDockPanel.Children)
            //{
            //    oItem.Foreground = Brushes.White;
            //}

            pTreeNode.IsSelected = true;
            if (selectedTreeViewItemList.Contains(pTreeNode) == false)
                selectedTreeViewItemList.Add(pTreeNode);
        }

        private void multiDeselectTree(BindingFolder pTreeNode)
        {
            DeselectTree(pTreeNode);
            selectedTreeViewItemList.Remove(pTreeNode);
        }

        private void DeselectTree(BindingFolder pTreeNode)
        {
            pTreeNode.BackgroudColor = Brushes.White;
            pTreeNode.ForegroundColor = Brushes.Black;

            //pTreeNode.Background = Brushes.White;
            //DockPanel oDockPanel = (DockPanel)pTreeNode.Header;
            //foreach (Label oItem in oDockPanel.Children)
            //{
            //    oItem.Foreground = Brushes.Black;
            //}
            pTreeNode.IsSelected = false;
        }

        private void selectedTreeViewItemListClear()
        {
            if (selectedTreeViewItemList != null && selectedTreeViewItemList.Count > 0)
            {
                foreach (BindingFolder oTreeItem in selectedTreeViewItemList)
                {
                    oTreeItem.BackgroudColor = Brushes.White;
                    oTreeItem.ForegroundColor = Brushes.Black;
                    //DockPanel oDockPanel = (DockPanel)oTreeItem.Header;
                    //foreach (Label oItem in oDockPanel.Children)
                    //{
                    //    oItem.Foreground = Brushes.Black;
                    //}
                    oTreeItem.IsSelected = false;
                }
            }
            selectedTreeViewItemList = new List<BindingFolder>();// = new List<TreeViewItem>();
        }

        private void setContextVisibility(System.Windows.Visibility pUnshareVisibility, System.Windows.Visibility pOpenFileLocationVisibility, System.Windows.Visibility pMenuSepratorVisibility, System.Windows.Visibility pTreeShareFolderVisibility)
        {
            miUnShareFolder.Visibility = pUnshareVisibility;
            miTreeOpenFileLocation.Visibility = pOpenFileLocationVisibility;
            miMenuSeprator.Visibility = pMenuSepratorVisibility;
            miTreeShareFolder.Visibility = pTreeShareFolderVisibility;
        }

        #region "Method: subitem_MouseLeftButtonUp(2)"
        /// <summary>
        /// Left click of Child node
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void subitem_MouseLeftButtonUp(BindingFolder oNode, MouseButton pPressedButton)
        {
            BindingFolder oSubTree = new BindingFolder();

            if (oNode.ParentFolder != null)
            {
                oSubTree = oNode.ParentFolder;
            }

            if ((Keyboard.IsKeyDown(Key.LeftCtrl) || Keyboard.IsKeyDown(Key.RightCtrl)) && (pPressedButton == MouseButton.Left))
            {
                foreach (BindingFolder oItem in oSubTree.Folders)
                {
                    if (oItem.ContainerID == oNode.ContainerID)
                    {
                        if ((selectedTreeViewItemList != null) && (selectedTreeViewItemList.Count > 0))
                        {
                            if (!selectedTreeViewItemList.Contains(oNode))
                            {
                                multiSelectTree(oNode);
                            }
                            else
                            {
                                multiDeselectTree(oNode);
                            }
                        }
                        else
                        {
                            multiSelectTree(oNode);
                        }
                        break;
                    }
                }
            }
            else
            {
                selectedTreeViewItemListClear();
                foreach (BindingFolder oItem in oSubTree.Folders)
                {
                    if (oItem.ContainerID == oNode.ContainerID)
                    {
                        multiSelectTree(oNode);
                    }
                }
            }
        }

        #endregion


        //#region "Method:ScrollViewer_ScrollChanged"
        ///// <summary>
        ///// Listener on scrollChanged
        ///// </summary>
        ///// <param name="sender"></param>
        ///// <param name="e"></param>
        //private void ScrollViewer_ScrollChanged(object sender, ScrollChangedEventArgs e)
        //{
        //    try
        //    {
        //        if (e.VerticalChange > 0 && e.VerticalOffset > (e.ExtentHeight / 2))
        //        {
        //            if (totalMatches > startIndex)
        //            {
        //                UpdateContentTree(startIndex, fixedCount);
        //                startIndex = fixedCount + startIndex;
        //                LogManager.logMessage("SharedUserControl", "ScrollViewer_ScrollChanged", "startIndex " + startIndex + " totalMatches " + totalMatches);
        //            }
        //        }
        //    }
        //    catch (Exception ex)
        //    {
        //        LogManager.logExceptionMessage("SharedUserControl", "ScrollViewer_ScrollChanged", ex);
        //    }
        //}
        //#endregion      

        private async void UpdateTreeView()
        {
            if (this.trvContent.Dispatcher.CheckAccess())
            {
                //// HSC changes      
                if (ServerManager.oSharedFolderList == null)
                {
                    ServerManager.oSharedFolderList = new List<SharedFolder>();
                }
                /* adding return value to make it syncronous as we need updated list in UpdateContentTreeWithPG() */
                bool ret = await ServerManager.fillShareFolderList();
                await UpdateContentTreeWithPG();
                stopProcess();
                EnabledGrid();
                ShowMessageOnUI();
            }
            else
                this.trvContent.Dispatcher.Invoke(new UpdateUI(UpdateTreeView));
        }

        /* Function: It is to event for callback from BAL for content indexing */
        private void UpdateIndexingStatusView(bool isRefresh)
        {
            if (this.trvContent.Dispatcher.CheckAccess())
            {
                if (ServerManager.oStorageStateList == null)
                {
                    ServerManager.oStorageStateList = new List<StorageStateEntity>();
                }
                UpdateContentTreeWithIndexingStates(isRefresh);
            }
            else
                this.trvContent.Dispatcher.Invoke(new UpdateIndexingUI(UpdateIndexingStatusView), new object[] { isRefresh });
        }

        /* Function: It is to event for callback from BAL for content partial indexing*/
        private void UpdatePartialIndexingStatusView()
        {
            if (this.trvContent.Dispatcher.CheckAccess())
            {
                if (ServerManager.oStoragePartialIndexingList == null)
                {
                    ServerManager.oStoragePartialIndexingList = new List<StoragePartialIndexingEntity>();
                }
                UpdateContentTreeWithPartialIndexingStates();
            }
            else
                this.trvContent.Dispatcher.Invoke(new UpdateUI(UpdatePartialIndexingStatusView));
        }
        
        private void UpdateDMSStateView(int DMSState)
        {
            if(DMSState == (int)DMSParameters.dmsState.DMS_STATE_ENABLE)
            {
                /*
                 * TODO : Add CA start if previous CA state is enabled.
                 */
                stopProcess();
                EnabledGrid();
            } else
            {
                stopProcess();
                EnabledGrid();
            }
        }

        private void ShowMessageOnUI()
        {
            string errorMsg = Constant.STRING_EMPTY;
            if (_ValidateRootDirWarningMsg.Trim() != Constant.STRING_EMPTY)
            {
                errorMsg = _ValidateRootDirWarningMsg;
            }

            if (_ValidateErrorMsg.Trim() != Constant.STRING_EMPTY)
            {
                errorMsg = _ValidateErrorMsg;
            }

            if (_SharingErrorMsg.Trim() != Constant.STRING_EMPTY)
            {
                errorMsg = errorMsg + Environment.NewLine + Constant.SHARE_FOLDER_ERROR + Environment.NewLine + _SharingErrorMsg;
            }

            if ((_SuccessMsg != null) && (_SuccessMsg.Length > 0) && (errorMsg != null) && (errorMsg.Length > 0))
            {
                //MessageManager.ShowInformationMessage(_SuccessMsg + Environment.NewLine + errorMsg, this);
                MessageWindow win = new MessageWindow(MessageEntity.MessageType.MESSAGE_TYPE_INFORMATION, _SuccessMsg + Environment.NewLine + errorMsg, this);
                win.Show();
            }
            else if ((_SuccessMsg != null) && (_SuccessMsg.Length > 0))
            {
                //MessageManager.ShowInformationMessage(_SuccessMsg, this);
                MessageWindow win = new MessageWindow(MessageEntity.MessageType.MESSAGE_TYPE_INFORMATION, _SuccessMsg, this);
                win.Show();
            }
            else if ((errorMsg != null) && (errorMsg.Length > 0))
            {
                //MessageManager.ShowErrorMessage(errorMsg, this);
                MessageWindow win = new MessageWindow(MessageEntity.MessageType.MESSAGE_TYPE_ERROR, errorMsg, this);
                win.Show();
            }
            _SuccessMsg = String.Empty;
            _SharingErrorMsg = String.Empty;
            _ValidateErrorMsg = String.Empty;
        }

        private async Task<bool> UpdateContentTreeWithPG()
        {
            List<SharedFolder> pShareList = ServerManager.oSharedFolderList;

            await Task.Run(() =>
            {
                SharedFolderManager.DMS_AHLdmsGetContentTree(ref pShareList);
            });

            ServerManager.oSharedFolderList = pShareList;
            await GetShareFolderList();

            foreach (BindingFolder oItem in SharedBindedFolderList)
            {
                //string FolderPath = "";
                //if (oItem.DisplayMemberPath != null && oItem.DisplayMemberPath.Length > 0)
                //{
                //    FolderPath = oItem.DisplayMemberPath.Substring(0, oItem.DisplayMemberPath.LastIndexOf(':'));
                //}

                SharedFolder oSharedFolder = ServerManager.oSharedFolderList.Where(index => index.ContainerID == oItem.ContainerID).FirstOrDefault();
                if (oSharedFolder != null)
                {
                    if (oSharedFolder.ContainerID == null)
                        oItem.ContainerID = oSharedFolder.FolderName;
                    else
                        oItem.ContainerID = oSharedFolder.ContainerID;

                    oItem.PGLevel = oSharedFolder.PGLevel;
                    oItem.DisplayPGLevel = ServerManager.oPGLevelList.Where(p => p.Id == oSharedFolder.PGLevel).Select(p => p.Name).FirstOrDefault();

                    getPglevelTooltip(oSharedFolder.PGLevel, oItem);


                    //DockPanel oDockPanel = (DockPanel)oItem.Header;
                    //foreach (Label oLable in oDockPanel.Children)
                    //{
                    //    if (ServerManager.oPGLevelList != null)
                    //    {
                    //        if (oLable == (Label)oDockPanel.Children[1])
                    //            oLable.Content = ServerManager.oPGLevelList.Where(p => p.Id == oSharedFolder.PGLevel).Select(p => p.Name).FirstOrDefault();
                    //    }
                    //}
                }
            }

            return true;
        }

        /* Function: It is to update the UI with current indexing state */
        private async void UpdateContentTreeWithIndexingStates(bool isRefresh)
        {
            ToolTip oItemToolTip = null;
            try
            {
                foreach (BindingFolder oItem in SharedBindedFolderList)
                {
                    StorageStateEntity oStateEntity = ServerManager.oStorageStateList.Where(index => index.storagePath == oItem.FolderPath).FirstOrDefault();
                    if (oStateEntity != null)
                    {
                        oItemToolTip = new ToolTip();
                        oItemToolTip.Placement = System.Windows.Controls.Primitives.PlacementMode.Top;
                        if (oStateEntity.indexingState.Equals(Constant.INDEXING_STATE_STARTED))
                        {
                            // oItem.IndexingState = new BitmapImage(new Uri(Constant.INDEXING_STARTED_IMAGE, UriKind.Relative));
                            oItem.GifImageVissible = System.Windows.Visibility.Visible;
                            oItem.vissible = System.Windows.Visibility.Collapsed;
                            oItemToolTip.Content = "Indexing Started";
                            oItem.indexingToolTip = oItemToolTip;
                        }
                        else if (oStateEntity.indexingState.Equals(Constant.INDEXING_STATE_DONE))
                        {
                            oItem.GifImageVissible = System.Windows.Visibility.Collapsed;
                            oItem.vissible = System.Windows.Visibility.Visible;
                            oItem.IndexingState = new BitmapImage(new Uri(Constant.INDEXING_DONE_IMAGE, UriKind.Relative));
                            oItemToolTip.Content = "Indexing Completed";
                            oItem.indexingToolTip = oItemToolTip;
                            if (!isRefresh)
                            {
                                await updateStorageChildCount();
                                SharedFolder oSharedFolderPG = ServerManager.oSharedFolderList.Where(index => index.ContainerID == oItem.ContainerID).FirstOrDefault();
                                if (oSharedFolderPG != null)
                                {
                                    oItem.DisplayPGLevel = ServerManager.oPGLevelList.Where(p => p.Id == oSharedFolderPG.PGLevel).Select(p => p.Name).FirstOrDefault();
                                    oItem.ChildCount = oSharedFolderPG.childCount;
                                }
                            }
                            /* Enabling the expand option after indexing is complete */
                            if (oItem.Folders.Count() == 0)
                            {
                                BindingFolder oDummyFamilyMember = new BindingFolder();
                                oDummyFamilyMember.Name = "";
                                oItem.Folders.Add(oDummyFamilyMember);
                            }
                        }
                        else if (oStateEntity.indexingState.Equals(Constant.INDEXING_STATE_ABORTED))
                        {
                            oItem.GifImageVissible = System.Windows.Visibility.Collapsed;
                            oItem.IndexingState = new BitmapImage(new Uri(Constant.INDEXING_ERROR_IMAGE, UriKind.Relative));
                            oItem.vissible = System.Windows.Visibility.Visible;
                            oItemToolTip.Content = "Indexing Failed, Retrying !! ";
                            oItem.indexingToolTip = oItemToolTip;
                        }
                        else
                        {
                            oItem.GifImageVissible = System.Windows.Visibility.Collapsed;
                            oItem.IndexingState = new BitmapImage(new Uri(Constant.INDEXING_NOTSTARTED_IMAGE, UriKind.Relative));
                            oItem.vissible = System.Windows.Visibility.Visible;
                            oItemToolTip.Content = "Indexing Not Yet Started ";
                            oItem.indexingToolTip = oItemToolTip;
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, "UpdateContentTreeWithIndexingStates", ex);
            }
        }


        /* Function: It is to update the UI with current partial indexing state */
        private async void UpdateContentTreeWithPartialIndexingStates()
        {
            try
            {
                foreach (BindingFolder oItem in changedTreeViewItemList)
                {
                    StoragePartialIndexingEntity oStateEntity = ServerManager.oStoragePartialIndexingList.Where(index => index.contentID == oItem.ContainerID).FirstOrDefault();
                    if (oStateEntity != null)
                    {
                        if (oStateEntity.partialIndexingState.Equals(Constant.INDEXING_STATE_DONE))
                        {
                            BindingFolder oParentFolder = new BindingFolder();
                            oParentFolder = oItem.ParentFolder;
                            string sParentTag;
                            int count;
                            ContentTree oContentTree = new ContentTree();
                            if (oParentFolder != null)
                            {
                                sParentTag = oParentFolder.ContainerID.ToString();
                                count = oParentFolder.ChildCount;
                            }
                            else
                            {
                                sParentTag = "0";
                                count = 10;
                            }
                            await Task.Run(() =>
                            {
                                SharedFolderManager.DMS_AHLdmsGetContentTree(sParentTag, 0, count, ref oContentTree);
                            });
                            ContentTreeItems oContentItem = oContentTree.contentTreeEntityList.Where(c => c.ContainerID == oItem.ContainerID.ToString()).FirstOrDefault();
                            if (oContentItem != null)
                            {
                                UpdatePgLevelLable(oContentItem.pgLevel, oItem);
                                getPglevelTooltip(oContentItem.pgLevel, oItem);
                                //Change pglevel of parent folder
                                await ChangeParentPGlevelIfRequired(oItem);
                            }
                            changedTreeViewItemList.Remove(oItem);
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                LogManager.logExceptionMessage(Constant.ServiceManager_CLASSNAME, "UpdateContentTreeWithPartialIndexingStates", ex);
            }
        }


        /* Function: It is to update the oSharedFolderList child count for each storage */
        private async Task updateStorageChildCount()
        {
            List<SharedFolder> pShareList = ServerManager.oSharedFolderList;

            await Task.Run(() =>
            {
                SharedFolderManager.DMS_AHLdmsGetContentTree(ref pShareList);
            });

            ServerManager.oSharedFolderList = pShareList;
        }

        private void getPglevelTooltip(int pPgLevel, BindingFolder pItem)
        {
            ToolTip oItemToolTip = null;
            if (ServerManager.oPGLevelList != null)
            {
                oItemToolTip = new ToolTip();
                PGLevelEntity oPGLevel = ServerManager.oPGLevelList.Where(pg => pg.Id == pPgLevel).FirstOrDefault();
                if (oPGLevel != null)
                {
                    oItemToolTip.Placement = System.Windows.Controls.Primitives.PlacementMode.Top;
                    // oItemToolTip.PlacementTarget = pItem;
                    oItemToolTip.Content = oPGLevel.Description;
                    pItem.oToolTip = oItemToolTip;
                }
            }
            //pItem.oToolTip = oItemToolTip;
        }

        private void UpdatePgLevelLable(int pPgLevel, BindingFolder pItem)
        {
            pItem.DisplayPGLevel = ServerManager.oPGLevelList.Where(p => p.Id == pPgLevel).Select(p => p.Name).FirstOrDefault();
            pItem.PGLevel = pPgLevel;
            //DockPanel oDockPanel = (DockPanel)pItem.Header;
            //foreach (Label oItem in oDockPanel.Children)
            //{
            //    if (oItem == (Label)oDockPanel.Children[1])
            //        oItem.Content = ServerManager.oPGLevelList.Where(p => p.Id == pPgLevel).Select(p => p.Name).FirstOrDefault();
            //}
        }

        private void MetroWindow_SizeChanged(object sender, SizeChangedEventArgs e)
        {
            lineShareFolder.X2 = HeaderPanel.ActualWidth;
        }

        //#region DeselectAll()
        ///// <summary>
        ///// DeselectAll
        ///// </summary>
        //private void DeselectAll()
        //{
        //    foreach (TreeViewItem oTreeItem in trvContent.Items)
        //    {
        //        multiDeselectTree(oTreeItem);
        //    }
        //}
        //#endregion

        #region grvDeviceLevel_MouseLeftButtonUp()
        /// <summary>
        /// DeselectAll
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void grvDeviceLevel_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            if ((selectedTreeViewItemList != null) && (selectedTreeViewItemList.Count > 0))
                selectedTreeViewItemListClear();
        }
        #endregion

        //private string GetHeader(TreeViewItem pItem)
        //{
        //    string sFolderLabel = "";
        //    DockPanel oDockPanel = (DockPanel)pItem.Header;
        //    foreach (Label oItem in oDockPanel.Children)
        //    {
        //        if (oItem == (Label)oDockPanel.Children[0])
        //            sFolderLabel = oItem.Content.ToString().Split('(')[0];
        //    }

        //    if (sFolderLabel.StartsWith("_") == true)
        //    {
        //        sFolderLabel = sFolderLabel.Remove(0, 1);
        //    }

        //    return sFolderLabel;
        //}

        //private int GetHeaderPglevel(TreeViewItem pItem)
        //{
        //    DockPanel oDockPanel = (DockPanel)pItem.Header;
        //    foreach (Label oItem in oDockPanel.Children)
        //    {
        //        if (oItem == (Label)oDockPanel.Children[1])
        //            return Convert.ToInt16(oItem.Content);
        //    }
        //    return 0;
        //}

        //private void scrollServerLeftPanel_PreviewMouseWheel(object sender, MouseWheelEventArgs e)
        //{
        //    ScrollViewer scv = (ScrollViewer)sender;
        //    scv.ScrollToVerticalOffset(scv.VerticalOffset - e.Delta);
        //    e.Handled = true;
        //}

        //#region "ChangeDisplayMemberPath"
        ///// <summary>
        ///// ChangeDisplayMemberPath
        ///// </summary>
        ///// <param name="pReturnValue"></param>
        ///// <param name="pLevel"></param>
        //private void ChangeDisplayMemberPath(TreeViewItem pTreeViewItem, int pLevel)
        //{
        //    if (pTreeViewItem != null && pTreeViewItem.DisplayMemberPath != null)
        //    {
        //        int iChildCount = 0;
        //        int iPgLevel = 0;
        //        bool isChildCount = false;
        //        bool isPgLevel = false;
        //        if (pTreeViewItem.DisplayMemberPath != null && pTreeViewItem.DisplayMemberPath.Length > 0)
        //        {
        //            isChildCount = int.TryParse(pTreeViewItem.DisplayMemberPath.Split(':').LastOrDefault(), out iChildCount);
        //            isPgLevel = int.TryParse(pTreeViewItem.DisplayMemberPath.Split(':').FirstOrDefault(), out iPgLevel);
        //        }

        //        if (isChildCount && isPgLevel)
        //        {
        //            pTreeViewItem.DisplayMemberPath = pLevel + ":" + iChildCount;
        //        }
        //    }
        //}
        //#endregion

        #region "Refresh_Click"
        /// <summary>
        /// Refresh_Click
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private async void Refresh_Click(object sender, RoutedEventArgs e)
        {
            //Refresh Shared Folder
            //Refresh Device
            FillMainScreenParameters();
            startProcess("Refreshing UI...", this, XPosition, YPosition);
            bool bServerState = ConfigurationManager.GetServiceLastState();

            if (bServerState == true)
            {
                await ServerManager.fillShareFolderList();

                await Task.Run(() =>
                {
                    List<SharedFolder> pShareList = ServerManager.oSharedFolderList;

                    SharedFolderManager.DMS_AHLdmsGetContentTree(ref pShareList);
                    ServerManager.oSharedFolderList = pShareList;
                });

                await GetShareFolderList();
            }
            UpdateIndexingStatusView(true);
            stopProcess();
            EnabledGrid();
            this.Focus();
        }
        #endregion

        private void scrollServerLeftPanel_PreviewMouseWheel(object sender, MouseWheelEventArgs e)
        {
            ScrollViewer scv = (ScrollViewer)sender;
            scv.ScrollToVerticalOffset(scv.VerticalOffset - e.Delta);
            e.Handled = true;
        }

        private async void PauseMenuItem_Click(object sender, RoutedEventArgs e)
        {
            DMSParameters.returnValue ret = DMSParameters.returnValue.NFLC_E_ERROR;
            DMSParameters.dmsCACommand cmd = DMSParameters.dmsCACommand.DMS_CA_CMD_PAUSE;
            bool outVal = false;
            await Task.Run(() =>
            {
                ret = ConfigurationManager.DMS_AHLdmsCAIsEnabled(out outVal);
            });
            if (outVal == true && ret == DMSParameters.returnValue.NFLC_E_OK)
            {
                bool bCARunningState = ConfigurationManager.GetCARunningLastState();
                if (bCARunningState == true)
                {
                    await Task.Run(() =>
                    {
                        ret = ConfigurationManager.DMS_AHLdmsCAExecuteCommand(cmd);
                    });
                    if (ret == DMSParameters.returnValue.NFLC_E_OK)
                    {
                        ConfigurationManager.SetCARunningState(Constant.CA_PAUSE_ENABLE);
                        miPauseCA.IsEnabled = false;
                        miResumeCA.IsEnabled = true;
                    }
                    else
                    {
                        MessageManager.ShowErrorMessage(Constant.CA_PAUSE_RESUME_ERROR + Environment.NewLine, this);
                    }
                }
                else
                {
                    miPauseCA.IsEnabled = false;
                }
            }
        }

        private async void ResumeMenuItem_Click(object sender, RoutedEventArgs e)
        {
            DMSParameters.returnValue ret = DMSParameters.returnValue.NFLC_E_ERROR;
            DMSParameters.dmsCACommand cmd = DMSParameters.dmsCACommand.DMS_CA_CMD_RESUME;
            bool outVal = false;
            await Task.Run(() =>
            {
                ret = ConfigurationManager.DMS_AHLdmsCAIsEnabled(out outVal);
            });
            if (outVal == true && ret == DMSParameters.returnValue.NFLC_E_OK)
            {
                bool bCARunningState = ConfigurationManager.GetCARunningLastState();
                if (bCARunningState == false)
                {
                    await Task.Run(() =>
                    {
                        ret = ConfigurationManager.DMS_AHLdmsCAExecuteCommand(cmd);
                    });
                    if (ret == DMSParameters.returnValue.NFLC_E_OK)
                    {
                        ConfigurationManager.SetCARunningState(Constant.CA_RESUME_ENABLE);
                        miPauseCA.IsEnabled = true;
                        miResumeCA.IsEnabled = false;
                    }
                    else
                    {
                        MessageManager.ShowErrorMessage(Constant.CA_PAUSE_RESUME_ERROR + Environment.NewLine, this);
                    }
                }
                else
                {
                    miResumeCA.IsEnabled = false;
                }
            }
        }

        private async void miRemoveDevice_Click(object sender, RoutedEventArgs e)
        {
            if (MessageManager.ShowConfirmationMessage(Constant.DEVICE_REMOVE_CONFIRMATION, this))
            {
                List<DeviceEntity> oSelectedItemsList = grvDeviceLevel.SelectedItems.Cast<DeviceEntity>().ToList();

                foreach (DeviceEntity item in oSelectedItemsList)
                {
                    await Task.Run(() =>
                    {
                        PGLevelManager.DMS_AHLdmsPGDeleteDeviceByMac(item.MacAddress);
                    });
                }
                fillDevice();
            }
        }
    }
    public class BindingFolder : INotifyPropertyChanged
    {
        public BindingFolder()
        {
            Folders = new List<BindingFolder>();
            // Files = new List<BindingFile>();
        }

        private string _DisplayPGLevel;
        private bool _IsSelected;
        private ToolTip _oToolTIp;
        private ToolTip _indexingToolTip;
        private Brush _BackGroundColor;
        private Brush _ForeGroundColor;
        private bool _IsNodeExpanded;
        private ImageSource _IndexingState;

        public string Name { get; set; }
        public string DisplayName { get; set; }
        public ImageSource IndexingState 
        {
            get
            {
                return _IndexingState;
            }
            set
            {
                _IndexingState = value;
                NotifiyPropertyChanged("IndexingState");
            }
        }
        private Visibility _vissible = Visibility.Collapsed;
        private Visibility _gifImageVissible = Visibility.Visible;
        public Visibility vissible
        {
            get
            {
                return _vissible;
            }
            set
            {
                _vissible = value;
                NotifiyPropertyChanged("vissible");
            }
        }
        public Visibility GifImageVissible
        {
            get
            {
                return _gifImageVissible;
            }
            set
            {
                _gifImageVissible = value;
                NotifiyPropertyChanged("GifImageVissible");
            }
        }
        public string FolderPath { get; set; }
        public int PGLevel { get; set; }
        public string DisplayPGLevel 
        { 
            get       
            {
                return _DisplayPGLevel;
            }        
            set
            {
                _DisplayPGLevel = value;
                NotifiyPropertyChanged("DisplayPGLevel");
            }
        }
        public string ContainerID { get; set; }
        public BindingFolder ParentFolder { get; set; }
        public int ChildCount { get; set; }
        public bool IsSelected 
        {
            get
            {
                return _IsSelected;
            }
            set
            {
                _IsSelected = value;
                NotifiyPropertyChanged("IsSelected");
            }
        }
        public bool IsParent { get; set; }
        public bool IsNodeExpanded 
        {
            get
            {
                return _IsNodeExpanded;
            }
            set
            {
                _IsNodeExpanded = value;
                NotifiyPropertyChanged("IsNodeExpanded");
            }
        }
        public Brush BackgroudColor 
        {
            get
            {
                return _BackGroundColor;
            }
            set
            {
                _BackGroundColor = value;
                NotifiyPropertyChanged("BackgroudColor");
            }
        }
        public Brush ForegroundColor 
        {
            get
            {
                return _ForeGroundColor;
            }
            set
            {
                _ForeGroundColor = value;
                NotifiyPropertyChanged("ForegroundColor");
            }
        }
        public ToolTip oToolTip 
        {
            get
            {
                return _oToolTIp;
            }
            set
            {
                _oToolTIp = value;
                NotifiyPropertyChanged("oToolTip");
            }
        }
        public ToolTip indexingToolTip
        {
            get
            {
                return _indexingToolTip;
            }
            set
            {
                _indexingToolTip = value;
                NotifiyPropertyChanged("indexingToolTip");
            }
        }
        public ICollection<BindingFolder> Folders { get; set; }
        // public ICollection<BindingFile> Files { get; set; }

        public IEnumerable Items
        {
            get
            {
                var items = new CompositeCollection();
                items.Add(new CollectionContainer { Collection = Folders });
                //items.Add(new CollectionContainer { Collection = Files });
                return items;
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;

        void NotifiyPropertyChanged(string property)
        {
            if (PropertyChanged != null)
                PropertyChanged(this, new PropertyChangedEventArgs(property));
        }

    }

}

