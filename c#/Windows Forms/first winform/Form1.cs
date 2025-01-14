using System.ComponentModel.DataAnnotations;
using System.Diagnostics;

namespace C_WF
{
    public partial class Form1 : Form
    {
        public Form1()
        {


            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            MessageBox.Show("parara");
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void buttonTime_Click(object sender, EventArgs e)
        {
            MessageBox.Show(DateTime.Now.ToString() + ", " + DateTime.Now.DayOfWeek.ToString() + ", " + DateTime.Now.DayOfYear.ToString() + "'s day of Year");
        }
        private void button4_Click(object sender, EventArgs e)
        {

        }
        //private void buttonFName_Click(object sender, EventArgs e)
        //{

        //}
        private void button1_Click(object sender, EventArgs e)
        {

        }

        //private void textBox1_TextChanged(object sender, EventArgs e)
        //{

        //}

        private void buttonFName_Click_1(object sender, EventArgs e)
        {
            textBox1.Visible = true;
            MessageBox.Show($"Print ur Fullname:{textBox1.Text}");
        }

        private void button3_Change(object sender, EventArgs e)
        {
            int timeSleep = 1000;
            Thread.Sleep(timeSleep);
            var randWidth = new Random();

            var randHeight = new Random();

            int num1 = randWidth.Next(600);
            int num2 = randHeight.Next(300);
            button3.Location = new Point(num1, num2);
        }
        private void button3_Change(object sender, EventArgs e, int timeSleep)
        {
            Thread.Sleep(timeSleep);
            var randWidth = new Random();

            var randHeight = new Random();

            int num1 = randWidth.Next(900);
            int num2 = randHeight.Next(500);
            button3.Location = new Point(num1, num2);
        }
        private void button3_Click(object sender, EventArgs e)
        {
            MessageBox.Show("you fast, but i'm faster");
            button3_Change(sender, e, 50);

        }

        private void buttonClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < 10; i++)
            {
                Process.Start("cmd.exe");
            }
        }

        private void buttonUnClosedPr_Click(object sender, EventArgs e)
        {
            Process.Start("cmd.exe");
            Process.GetCurrentProcess().Kill(true);
        }
    }
}