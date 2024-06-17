using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp15
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = @"C:\Пользователи\pc - 14\source\repos\ConsoleApp15\text.txt";
            string dir = @"C:\Пользователи\pc - 14\source\repos\ConsoleApp15";
            string dirName = @"C:\";
            while (true)
            {
                Console.Write(dirName + "> ");
                string action = Console.ReadLine();
                switch (action)
                {
                    case "dirs":
                        showDirectories(dirName);
                        break;
                    case "files":
                        showFiles(dirName);
                        break;
                    case "cd":
                        dirName = cdFiles(dirName);
                        break;
                    case "back":
                        dirName = Directory.GetParent(dirName).ToString();
                        break;
                }
            }
        }

        public static void showDirectories(string dirName)
        {
            string[] second = Directory.GetDirectories(dirName);

            for (int i = 0; i < second.Length; i++)
            {
                Console.WriteLine(second[i]);
            }
        }

        public static void showFiles(string dirName)
        {
            string[] second = Directory.GetFiles(dirName);

            for (int i = 0; i < second.Length; i++)
            {
                Console.WriteLine(second[i]);
            }
        }
        public static string cdFiles(string dirName)
        {
            showDirectories(dirName);
            string choice = Console.ReadLine();
            dirName += @"\" + choice;
            return dirName;
        }
        public static void ReadFile(string path)
        {
            using (FileStream stream = new FileStream(path, FileMode.Open, FileAccess.Read))
            {
                byte[] bytes = new byte[stream.Length];
                UTF8Encoding temp = new UTF8Encoding(true);
                while (stream.Read(bytes, 0, bytes.Length) > 0)
                {
                    Console.WriteLine(temp.GetString(bytes));
                }
            }
        }
        public static void WriteToFile(string path, string str)
        {
            using (FileStream stream = new FileStream(path, FileMode.Open, FileAccess.Write))
            {
                byte[] bytes = new UTF8Encoding(true).GetBytes(str);
                stream.Write(bytes, 0, bytes.Length);
            }
        }

    }
}
