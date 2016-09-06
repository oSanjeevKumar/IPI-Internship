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
    /// Interaction logic for settingspage3.xaml
    /// </summary>
    public partial class settingspage3 : Page
    {
        public settingspage3()
        {
            InitializeComponent();
        }

        private void proceed_Click(object sender, RoutedEventArgs e)
        {
            settingspage1 st1 = new settingspage1();
            this.NavigationService.Navigate(st1);
        }
    }
}
