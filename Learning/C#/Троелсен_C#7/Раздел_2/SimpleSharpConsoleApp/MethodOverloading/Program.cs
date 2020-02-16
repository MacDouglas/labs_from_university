using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MethodOverloading
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("*** Fun with overloading Methods");
            Console.WriteLine(Add(10,20));
            Console.WriteLine(Add(2.5,2.4));
            Console.WriteLine(Add(900_000_000_000, 900_000_000_000));

            Console.ReadLine();

        }
        static int Add(int x, int y) => x + y;
        static double Add(double x, double y) => x + y;
        static long Add(long x, long y) => x + y;


    }
}
