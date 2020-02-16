using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FunWithTypls
{
    class Program
    {
        static void Main(string[] args)
        {
            (string, int, string) value = ("Hello", 10, "world");
            var values = ("Epic", 5005, "Game");

            Console.WriteLine("First element: {0}", value.Item1);
            Console.WriteLine("Second element: {0}", value.Item2);
            Console.WriteLine("Third element: {0}", value.Item3);

            (string firstLetter, int theNumber, string secondLetter) valuesWithNames = ("a", 1, "b");
            Console.WriteLine("First element: {0}", valuesWithNames.firstLetter);
            Console.WriteLine("Second element: {0}", valuesWithNames.theNumber);
            Console.WriteLine("Third element: {0}", valuesWithNames.secondLetter);

            (int, int) example = (custom1: 5, custom2: 35);
            (int Fieldl, int Field2) example1 = (Customl: 5, Custom2: 7);

            Console.WriteLine("=> Inferred Tuple Names");
            var foo = new { prop1 = "first", prop2 = "second" };
            var bar = (foo.prop1, foo.prop2);
            Console.WriteLine($"{bar.prop1}, {bar.prop2},{bar.ToString()}");

            var sample = FillTheseValues();
            Console.WriteLine("First = {0}",sample.a);
            Console.WriteLine("Second = {0}", sample.b);
            Console.WriteLine("Third = {0}", sample.c);


            //Прочерк - отбрасывание ненужных значений.
            var (first, _, last) = SplitName("Jake j james");
            Console.WriteLine($"{first} , {last}");

            Console.WriteLine();
            Point P = new Point(5, 7);
            var pointValues = P.Deconstruct();
            Console.WriteLine($"X is: {pointValues.XPos}, Y is: {pointValues.YPos}");

            Console.ReadLine();
        }
        static (string first, string middle,string last) SplitName(string name)
        {
            return ("Jake", "J", "Mandle");
        }

        static void FillTheseValues(out int a,out string b,out bool c)
        {
            a = 9;
            b = "String";
            c = true;
        }
        static (int a, string b,bool c) FillTheseValues()
        {
            return (12, "Hello world", false);
        }
    }
    struct Point
    {
        public int X;
        public int Y;
        public Point(int XPos, int YPos)
        {
            X = XPos;
            Y = YPos;
        }
        public (int XPos, int YPos) Deconstruct() => (X, Y);
    }
}
