using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BankC_
{
    internal class Program
    {
        static void Main(string[] args)
        {
            LongContrybution a = new LongContrybution();
            a.month = 1;
            a.contrybution = 2500;
            a.SumContrybutions();
        }
    }
    class Bank
    {
        public string name { get; set; }
    }
    class Felial
    {
        public string name { get; set; }
        public double sumOfContrybution { get; set; }
    }
    class Contrybution
    {
        public string fullName { get; set; }
        public double contrybution
        {
            get { return contrybution; }
            set
            {
                try
                {
                    if (contrybution < 0) throw new ArgumentException("negative num");
                    else contrybution = value;
                }
                catch (ArgumentException e)
                {
                    Console.WriteLine(e.Message);
                }
            }
        }
        public int month
        {
            get { return month; }
            set
            {
                try
                {
                    if (month < 0) throw new Exception("negative num");
                    else month = value;
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.Message);
                }
            }
        }
        public double SumContrybutions()
        {
            double sum = 0;
            sum = contrybution * month;
            return sum;
        }
    }

    internal class LongContrybution : Contrybution
    {
        public double SumContrybutions()
        {
            double sum = 0;
            sum = 1.16 * (contrybution * month);
            return sum;
        }
    }
    internal class ShortContrybution : Contrybution
    {
        public double SumContrybutions()
        {
            double sum = 0;
            sum = 1.03 * (contrybution * month);
            return sum;
        }
    }
}
