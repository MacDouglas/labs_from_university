using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ValueAdReferenceTypes
{
    class Program
    {
        static void Main(string[] args)
        {
            ValueTypeAssignment();

            Console.WriteLine();

            ValueTypeContainingRefType();

            Console.ReadLine();
        }

        static void ValueTypeContainingRefType()
        {
            Console.WriteLine("=> Creating R1");
            Rectangle R1 = new Rectangle("First rect", 10, 10, 50, 50);

            Console.WriteLine("Assigning R2 to R1");
            Rectangle R2 = R1;

            Console.WriteLine("Changing value of r2");
            R2.RectInfo.InfoString = "This is new info";
            R2.RectBottom = 1488;

            R1.Display();
            R2.Display();
        }
        struct Rectangle
        {
            public ShapeInfo RectInfo;
            public int RectTop, RectLeft, RectBottom, RectRight;
            public Rectangle(string info, int top, int left, int bottom, int right)
            {
                RectInfo = new ShapeInfo(info);
                RectTop = top; RectBottom = bottom;
                RectLeft = left;RectRight = right;
            }
            public void Display()
            {
                Console.WriteLine($"String = {RectInfo.InfoString}, Top = {RectTop}, Bottom = {RectBottom}" +
                    $"Left = {RectLeft}, Right = {RectRight}");
            }
        }
        class ShapeInfo
        {
            public string InfoString;
            public ShapeInfo(string info)
            {
                InfoString = info;
            }
        }
        static void ValueTypeAssignment()
        {
            Console.WriteLine("=> Assigning type values\n");

            PointRef p1 = new PointRef(10, 10);
            PointRef p2 = p1;

            p1.Display();
            p2.Display();

            p1.X = 100;
            Console.WriteLine("=> Changed P1.X");

            p1.Display();
            p2.Display();
        }
        class PointRef
        {
            public int X, Y;

            public PointRef(int XPos, int YPos)
            {
                X = XPos;
                Y = YPos;
            }
            public void Increment()
            {
                X++;
                Y++;
            }
            public void Decrement()
            {
                X--;
                Y--;
            }
            public void Display()
            {
                Console.WriteLine($"X = {X}, Y = {Y}");
            }

        }
        struct Point
        {
            public int X, Y;

            public Point(int XPos, int YPos)
            {
                X = XPos;
                Y = YPos;
            }
            public void Increment()
            {
                X++;
                Y++;
            }
            public void Decrement()
            {
                X--;
                Y--;
            }
            public void Display()
            {
                Console.WriteLine($"X = {X}, Y = {Y}");
            }
        }
    }
}
