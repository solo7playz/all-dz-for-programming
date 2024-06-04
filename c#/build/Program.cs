using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace с_
{
    using System;
    using System.Collections;

    class Builder : IComparable
    {
        public int Year { get; set; }
        public int NumberOfOffices { get; set; }
        public double TotalArea { get; set; }

        public int CompareTo(object obj)
        {
            Builder otherBuilder = obj as Builder;
            if (otherBuilder != null)
            {
                return this.Year.CompareTo(otherBuilder.Year);
            }
            else
            {
                throw new ArgumentException("Object is not a Builder");
            }
        }
    }

    class SortOfficceBuilderComparer : IComparer
    {
        public int Compare(object x, object y)
        {
            Builder builder1 = x as Builder;
            Builder builder2 = y as Builder;

            if (builder1 != null && builder2 != null)
            {
                return builder1.NumberOfOffices.CompareTo(builder2.NumberOfOffices);
            }
            else
            {
                throw new ArgumentException("Object is not a Builder");
            }
        }
    }

    class SortAreaBuilderComparer : IComparer
    {
        public int Compare(object x, object y)
        {
            Builder builder1 = x as Builder;
            Builder builder2 = y as Builder;

            if (builder1 != null && builder2 != null)
            {
                return builder1.TotalArea.CompareTo(builder2.TotalArea);
            }
            else
            {
                throw new ArgumentException("Object is not a Builder");
            }
        }
    }

    class Program
    {
        static void Main()
        {
            ArrayList builders = new ArrayList();

            builders.Add(new Builder { Year = 2000, NumberOfOffices = 50, TotalArea = 500 });
            builders.Add(new Builder { Year = 1990, NumberOfOffices = 40, TotalArea = 600 });
            builders.Add(new Builder { Year = 2010, NumberOfOffices = 60, TotalArea = 700 });

            builders.Sort();
            Console.WriteLine("Sorted by Year:");
            foreach (Builder builder in builders)
            {
                Console.WriteLine(builder.Year);
            }

            builders.Sort(new SortOfficceBuilderComparer());
            Console.WriteLine("\nSorted by Number of Offices:");
            foreach (Builder builder in builders)
            {
                Console.WriteLine(builder.NumberOfOffices);
            }

            builders.Sort(new SortAreaBuilderComparer());
            Console.WriteLine("\nSorted by Total Area:");
            foreach (Builder builder in builders)
            {
                Console.WriteLine(builder.TotalArea);
            }
        }
    }
}
