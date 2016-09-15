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
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace PageNavigation
{
    /// <summary>
    /// Interaction logic for settingspage1.xaml
    /// </summary>
    public partial class settingspage1 : Page
    {
        public settingspage1()
        {
            InitializeComponent();
            image.Source = new BitmapImage(new Uri("c:/users/vinaya.swamy/documents/visual studio 2015/Projects/ImageSource/ImageSource/Images/settings.jpg"));
        }

        private void settings_Click(object sender, RoutedEventArgs e)
        {
            settingspage2 st2 = new settingspage2();
            this.NavigationService.Navigate(st2);
        }
    }
}
