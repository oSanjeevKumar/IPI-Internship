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

namespace Binding
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private Employee employee;
        public MainWindow()
        {
            InitializeComponent();              
            employee = new Employee { txtboxtext = " Welcome to Binding World", labeltext= "Click on Image" };
            this.DataContext = employee;
            image.Source = new BitmapImage(new Uri("C:/Users/vinaya.swamy/Documents/Visual Studio 2015/Projects/Binding/Binding/Images/finger.jpg"));
        }
        private void Command_Click(object sender, RoutedEventArgs e)
        {
            NextWindow n1 = new NextWindow();
            n1.ShowDialog();
        }
    }
}
