using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Intefaces
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Choose theme style:\n 1. Dark\n 2. White");
            int choice = int.Parse(Console.ReadLine());
            IThemeFactory factory = null;
            switch (choice)
            {
                case 1:
                    factory = new DarkFactory();
                    break;
                case 2:
                    factory = new WhiteFactory();
                    break;
            }
            var theme = new Theme(factory);
            theme.Start();
            theme = new Theme(new DarkFactory());
            theme.Start();
            theme = new Theme(new WhiteFactory());
            theme.Start();
        }
    }
    
    public interface ITheme
    {
        void Describe();
    }
    public interface ITextTheme
    {
        void Describe();
    }
    public class DarkTheme : ITheme, ITextTheme
    {
        public void Describe()
        {
            Console.BackgroundColor = ConsoleColor.Black;
            Console.WriteLine("Black theme :)");
        }
    }
    public class DarkTextTheme : ITheme, ITextTheme
    {
        public void Describe()
        {
            Console.ForegroundColor = ConsoleColor.DarkBlue;
            Console.WriteLine("Black theme :)");
        }
    }
    public class WhiteTheme : ITheme, ITextTheme
    {
        public void Describe()
        {
            Console.BackgroundColor = ConsoleColor.White;
            Console.WriteLine("White theme :)");
        }
    }
    public class WhiteTextTheme : ITheme, ITextTheme
    {
        public void Describe()
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("White theme :)");
        }
    }
    public interface IThemeFactory
    {
        ITheme CreateTheme();
        ITextTheme CreateTextTheme();
    }
    public class DarkFactory : IThemeFactory
    {
        public ITheme CreateTheme()
        {
            return new DarkTheme();
        }
        public ITextTheme CreateTextTheme()
        {
            return new DarkTextTheme();
        }
    }
    public class WhiteFactory : IThemeFactory
    {
        public ITheme CreateTheme()
        {
            return new WhiteTheme();
        }
        public ITextTheme CreateTextTheme()
        {
            return new WhiteTextTheme();
        }
    }
    public class Theme
    {
        private ITheme _theme;
        private ITextTheme _text;
        public Theme(IThemeFactory factory)
        {
            _theme = factory.CreateTheme();
            _text = factory.CreateTextTheme();
        }
        public void Start()
        {
            Console.WriteLine("Welcome");
            _theme.Describe();
            _text.Describe();
        }
    }
}
