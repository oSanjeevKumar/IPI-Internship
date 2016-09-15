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
using DMS.BAL.Manager.Common_Manager;
using DMS.BAL.Entity.App_Entity;

namespace DMS.APP.Forms
{
    /// <summary>
    /// Interaction logic for MessageWindow.xaml
    /// </summary>
    public partial class MessageWindow : MetroWindow
    {
        public MessageWindow(Window pWnerForm)
        {
            InitializeComponent();

            this.Owner = pWnerForm;
        }

        public MessageWindow(MessageEntity.MessageType pMsgType, string pMsg, Window pWnerForm)
        {
            InitializeComponent();
            MessageForm.IsMinButtonEnabled = false;
            MessageForm.IsMaxRestoreButtonEnabled = false;

            if (pMsgType == MessageEntity.MessageType.MESSAGE_TYPE_QUESTION)
            {
                MessageForm.Title = Constant.MESSAGE_TITLE;
                //imgMsgIcon.Source = "";
                lbMessage.Content = pMsg;
            }
            else if (pMsgType == MessageEntity.MessageType.MESSAGE_TYPE_INFORMATION)
            {
                MessageForm.Title = Constant.MESSAGE_TITLE;
                //imgMsgIcon.Source = new BitmapImage(new Uri("../Images/info.jpg", UriKind.Relative));
                lbMessage.Content = pMsg;
            }
            else if (pMsgType == MessageEntity.MessageType.MESSAGE_TYPE_WARNING)
            {
                MessageForm.Title = Constant.MESSAGE_TITLE;
                //imgMsgIcon.Source = "";
                lbMessage.Content = pMsg;
            }
            else if (pMsgType == MessageEntity.MessageType.MESSAGE_TYPE_ERROR)
            {
                MessageForm.Title = Constant.MESSAGE_TITLE;
                imgMsgIcon.Source = new BitmapImage(new Uri("../Images/error.png", UriKind.Relative));;
                lbMessage.Content = pMsg;
            }

            //imgMsgIcon.Source = pImgMsgIcon;
            MessageForm.Title = Constant.MESSAGE_TITLE;
            lbMessage.Content = pMsg;

            this.Owner = pWnerForm;
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {

        }

        private void btnOk_Click(object sender, RoutedEventArgs e)
        {
            //return true;
            this.Close();
        }

        private void btnCancle_Click(object sender, RoutedEventArgs e)
        {
            //return false;
            this.Close();
        }
    }
}
