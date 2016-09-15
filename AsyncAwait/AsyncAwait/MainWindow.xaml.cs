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
using System.Net.Http;

namespace AsyncAwait
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
        //The event handler with async so we can use await here.
        private async void StartButton_Click(object sender, RoutedEventArgs e)
        {
            //Calling Synchronous method.
            DoIndependentWork(); 

            //Call and Await the AccessTheWebAsync
            int contentLength = await AccessTheWebAsync();

            //Print the Result in TextBox
            resultsTextBox.Text += String.Format("\r\nLength of the downloaded string: {0}.\r\n", contentLength);

            //Calling Synchronous method
            DoIndependentWorkTwo();

            //Calling Synchronous method
            DoIndependentWorkThree();

        }

        async Task<int> AccessTheWebAsync()
        {
            HttpClient client = new HttpClient();

            // GetStringAsync returns a Task<string>. That means that when we await the
            // task we'll get a string (urlContents).
            Task<string> getStringTask = client.GetStringAsync("http://www.itwriting.com/blog/4913-a-simple-example-of-async-and-await-in-c-5.html");

            // The await operator suspends AccessTheWebAsync.
            //  - AccessTheWebAsync can't continue until getStringTask is complete.
            //  - Meanwhile, control returns to the caller of AccessTheWebAsync.
            //  - Control resumes here when getStringTask is complete. 
            //  - The await operator then retrieves the string result from getStringTask.
            string urlContents = await getStringTask;

            // The return statement specifies an integer result.
            return urlContents.Length;
        }

        void DoIndependentWork()
        {
            resultsTextBox.Text += " It's Working  . . . . . . .\r\n";
        }

        void DoIndependentWorkTwo()
        {
            resultsTextBox.Text += " \r\n It's Working... Two. . . . . . .\r\n";
        }
        
       void DoIndependentWorkThree()
        {
            resultsTextBox.Text += " \r\n It's Working... Three. . . . . . .\r\n";
        }
    }
}
