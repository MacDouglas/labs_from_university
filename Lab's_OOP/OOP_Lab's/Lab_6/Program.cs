﻿using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Lab_6
{
    class Program
    {
        static void Main(string[] args)
        {
            //Func<int, double> ident = i => ;
            double[] arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            Matrix a = new Matrix(3, 3, arr);
            //Matrix b = a.Clone();
            //Console.WriteLine(a);
           // b += a;
            //Console.WriteLine(b);
            //Matrix c = b * a;
            //Console.WriteLine(c);

            a[0,0] = 0;
            //Console.WriteLine(a);
            Console.WriteLine(a.AsEnumerable<double>());
            Console.WriteLine(a.cols);
            Console.ReadKey();
        }
    }
}
