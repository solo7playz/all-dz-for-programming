using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Microsoft.CodeAnalysis.CSharp.Scripting;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace Calcar
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox1.Text += "1";
        }
        private void num2_Click(object sender, EventArgs e)
        {
            textBox1.Text += "2";
        }

        private void num3_Click(object sender, EventArgs e)
        {
            textBox1.Text += num3.Text;
        }
        private void num4_Click(object sender, EventArgs e)
        {
            textBox1.Text += num4.Text;
        }

        private void num5_Click(object sender, EventArgs e)
        {
            textBox1.Text += "5";
        }
        private void num6_Click(object sender, EventArgs e)
        {
            textBox1.Text += "6";
        }

        private void num7_Click(object sender, EventArgs e)
        {
            textBox1.Text += "7";
        }
        private void num8_Click(object sender, EventArgs e)
        {
            textBox1.Text += "8";
        }

        private void num9_Click(object sender, EventArgs e)
        {
            textBox1.Text += "9";
        }

        private void zero_Click(object sender, EventArgs e)
        {
            textBox1.Text += "0";
        }

        static double Parse(string expression)
        {
            return CSharpScript.EvaluateAsync<double>(expression).Result;
        }

        private void skobkaL_Click(object sender, EventArgs e)
        {
            textBox1.Text += "(";
        }

        private void skobkaR_Click(object sender, EventArgs e)
        {
            textBox1.Text += ")";
        }

        private void sum_Click(object sender, EventArgs e)
        {
            textBox1.Text += "+";
        }

        private void substraction_Click(object sender, EventArgs e)
        {
            textBox1.Text += "-";
        }

        private void multiplication_Click(object sender, EventArgs e)
        {
            textBox1.Text += "*";
        }

        private void division_Click(object sender, EventArgs e)
        {
            textBox1.Text += "/";
        }

        private void root_Click(object sender, EventArgs e)
        {
            textBox1.Text += "√";
        }

        private void point_Click(object sender, EventArgs e)
        {
            textBox1.Text += ".";
        }

        private void ravno_Click(object sender, EventArgs e)
        {
            string resultText;
            string finalResult;
            if (textBox1.Text[0] != '√')
            {
                finalResult = textBox1.Text[0].ToString();
            }

            else { finalResult = "0+"; }
            char item;
            int counter = 0;
            int c = 0;
            foreach(var itemI in textBox1.Text)
            {
                if(itemI == '√')
                {
                    counter++;
                }
            }
            int[] start = new int[counter];
            for (int i = 0; i < textBox1.Text.Length; ++i)
            {
                item = textBox1.Text[i];
                if (item == '√')
                {
                    start[c] = i;
                    c++;
                }
            }
            if (start.Length != 0)
            {
                resultText = textBox1.Text[start[0] + 1].ToString();
                for (int j = 1; j < start.Length; ++j)
                {
                    resultText = textBox1.Text[start[j] + 1].ToString();
                    for (int i = start[j] + 2; i < textBox1.Text.Length; ++i)
                    {
                        item = textBox1.Text[i];
                        if (item == '√' || item == '+' || item == '-' || item == '*' || item == '/')
                        {
                            break;
                        }
                        else { resultText += item.ToString(); }
                    }
                    MessageBox.Show(resultText);
                }
                Math.Sqrt(double.Parse(resultText));
                foreach (var item1 in textBox1.Text)
                {
                    string tmp = item1.ToString();
                    if (item1 != '√')
                    {
                        tmp += item1.ToString();
                    }
                    else
                    {
                        tmp += Math.Sqrt(double.Parse(resultText)).ToString();
                    }
                }
                if (finalResult == "0+")
                {
                    for (int j = 0; j < textBox1.Text.Length; ++j)
                    {
                        if (textBox1.Text[j] == '√'/* || tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/'*/)
                        {
                            finalResult += Math.Sqrt(double.Parse(resultText)).ToString();
                            j += resultText.Length;
                        }
                        else { finalResult += textBox1.Text[j].ToString(); }
                        MessageBox.Show(finalResult);
                    }
                }
                else
                {
                    for (int j = 1; j < textBox1.Text.Length; ++j)
                    {
                        if (textBox1.Text[j] == '√'/* || tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/'*/)
                        {
                            finalResult += Math.Sqrt(double.Parse(resultText)).ToString();
                            j += resultText.Length;
                        }
                        else { finalResult += textBox1.Text[j].ToString(); }
                        MessageBox.Show(finalResult);
                    }
                }
            }
            else
            {
                finalResult = textBox1.Text;
            }
            var result = Parse(finalResult);
            finalResult = null;
            textBox1.Clear();
            textBox1.Text = result.ToString();
        }
    }
}
