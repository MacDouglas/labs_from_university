using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FunWithLocalFunctions
{
    class Program
    {
        static void Main(string[] args)
        {
            AddWrapper(0, 1);

            Console.ReadLine();
        }
        static int AddWrapper(int x,int y)
        {
            if (x > 0 && y > 0)
            {
                Console.WriteLine("X & Y >= 0");
                return Add();
            }
            else
            {
                Console.WriteLine("X or Y < 0");
                return -1;
            }

            int Add() => x + y;
        }
    }
}
