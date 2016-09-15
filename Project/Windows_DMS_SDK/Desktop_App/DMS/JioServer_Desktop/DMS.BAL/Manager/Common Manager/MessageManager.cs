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
using System.Windows;
using System.Windows.Markup;

namespace DMS.BAL.Manager.Common_Manager
{
    public class MessageManager
    {

        #region "Declaration"

        private delegate bool DelegateConfirmationMessag(string pMessage, System.Windows.Window pParentWindow);
        private delegate void DelegateMessage(string pMessage, System.Windows.Window pParentWindow);
        private static bool bResult = false;

        #endregion

        #region "Method"       

        #region "Method: ShowErrorMessage(2)"
        /// <summary>
        /// Shows the error message.
        /// </summary>
        /// <param name="pMessage">The p message.</param>
        /// <param name="pTitle">The p title.</param>
        /// <param name="pButton">The p button.</param>
        /// <param name="pIcon">The p icon.</param>
        public static void ShowErrorMessage(string pMessage, System.Windows.Window pParentWindow) // Error
        {
            if (pParentWindow.Dispatcher.CheckAccess())
            {
                MessageBox.Show(pParentWindow, pMessage, Constant.MESSAGE_TITLE, MessageBoxButton.OK, MessageBoxImage.Error);
            }
            else
            {
                pParentWindow.Dispatcher.Invoke(new DelegateMessage(ShowErrorMessage), new object[] { pMessage, pParentWindow });
            }             
        }

        #endregion

        #region "Method: ShowWarningMessage(2)"
        /// <summary>
        /// Shows the warning message.
        /// </summary>
        /// <param name="pMessage">The p message.</param>
        /// <param name="pTitle">The p title.</param>
        /// <param name="pButton">The p button.</param>
        /// <param name="pIcon">The p icon.</param>
        public static void ShowWarningMessage(string pMessage,System.Windows.Window pParentWindow) // Warning
        {
            if (pParentWindow.Dispatcher.CheckAccess())
            {
                MessageBox.Show(pParentWindow, pMessage, Constant.MESSAGE_TITLE, MessageBoxButton.OK, MessageBoxImage.Warning);      
            }
            else
            {
                pParentWindow.Dispatcher.Invoke(new DelegateMessage(ShowWarningMessage), new object[] { pMessage, pParentWindow });
            }      
        }

        #endregion

        #region "Method: ShowInformationMessage(2)"
        /// <summary>
        /// Shows the information message.
        /// </summary>
        /// <param name="pMessage">The p message.</param>
        /// <param name="pTitle">The p title.</param>
        /// <param name="pButton">The p button.</param>
        /// <param name="pIcon">The p icon.</param>
        public static void ShowInformationMessage(string pMessage, System.Windows.Window pParentWindow) // Information
        {
            if (pParentWindow.Dispatcher.CheckAccess())
            {
                MessageBox.Show(pParentWindow, pMessage, Constant.MESSAGE_TITLE, MessageBoxButton.OK, MessageBoxImage.Information);
            }
            else
            {
                pParentWindow.Dispatcher.Invoke(new DelegateMessage(ShowInformationMessage), new object[] { pMessage, pParentWindow });
            }
        }

        #endregion

        #region "Method: ShowConfirmationMessage(2)"
        /// <summary>
        /// Shows the information message.
        /// </summary>
        /// <param name="pMessage">The p message.</param>
        /// <param name="pTitle">The p title.</param>
        /// <param name="pButton">The p button.</param>
        /// <param name="pIcon">The p icon.</param>
        public static bool ShowConfirmationMessage(string pMessage, System.Windows.Window pParentWindow) // Information
        {
            if (pParentWindow.Dispatcher.CheckAccess())
            {
                if (MessageBoxResult.Yes == MessageBox.Show(pParentWindow, pMessage, Constant.MESSAGE_TITLE, MessageBoxButton.YesNo, MessageBoxImage.Information))
                {
                    bResult = true;
                    return true;
                }
                else
                {
                    bResult = false;
                    return false;
                }
            }
            else
            {
                pParentWindow.Dispatcher.Invoke(new DelegateConfirmationMessag(ShowConfirmationMessage), new object[] { pMessage, pParentWindow });
            }
            return bResult;
        }

        #endregion

        #endregion

    }
}
