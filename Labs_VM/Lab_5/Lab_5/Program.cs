using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_5
{
    class Program
    {
        public static double F(double x)
        {
            return Math.Pow(x, 3) - 3 * Math.Pow(x, 2) - 8 * Math.Abs(x);
        }
        static void Main(string[] args)
        {
            double[] X = new double[] { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18 };
            double[] Y = new double[X.Length];
            double x = 3;
            for(int i = 0; i < X.Length; i++)
            {
                Y[i] = F(X[i]);
            }
            Newton interpolation = new Newton();
            double y = interpolation.GetValue(X, Y, x);
            Console.WriteLine($"Interpolation by Newton for x = {x}, Y = {y}");
            Console.WriteLine($"True value for X = {x}, Y = {F(x)}");
            Console.WriteLine($"dY value for X = {x}, dY = {Math.Abs(F(x) - y)}");
            Console.ReadLine();

        }
    }
}
