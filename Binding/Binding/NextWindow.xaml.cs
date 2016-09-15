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

namespace Binding
{
    /// <summary>
    /// Interaction logic for NextWindow.xaml
    /// </summary>
    public partial class NextWindow : Window
    {
        public NextWindow()
        {
            InitializeComponent();
            google.Source = new BitmapImage(new Uri("https://www.vivadigital.net/wp-content/uploads/2016/04/google.jpg"));
             

        }
    }
}
