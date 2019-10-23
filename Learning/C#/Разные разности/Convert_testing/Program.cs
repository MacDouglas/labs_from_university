using System;
using System.Globalization;


namespace Convert_testing
{
    class Program
    {
        static void Main(string[] args)
        {

            //NumberFormatInfo numberFormatInfo = new NumberFormatInfo()
            //{
            //    NumberDecimalSeparator = ".",
            //};
            //double a = Convert.ToDouble(Console.ReadLine(), numberFormatInfo);
            //Console.WriteLine(a);

            int a = int.Parse("55"),b;
            Console.WriteLine(a);
            
            bool result = int.TryParse("55asdas",out b);
            Console.WriteLine(result + " " + b);

            double rubles, dollars;

            Console.WriteLine("Введи количество рублей");
            rubles = Convert.ToDouble(Console.ReadLine());

            dollars = rubles / 65;
            Console.WriteLine(dollars);

            Console.WriteLine("Введи количество долларов");
            dollars = Convert.ToDouble(Console.ReadLine());

            rubles = dollars * 65;
            Console.WriteLine(rubles);
        }
    }
}
