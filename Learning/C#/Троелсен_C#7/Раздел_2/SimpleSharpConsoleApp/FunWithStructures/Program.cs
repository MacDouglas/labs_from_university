using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FunWithStructures
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("*** A first look at the Structures ***");

            Point myPoint;
            myPoint.X = 100;
            myPoint.Y = -100;
            myPoint.Display();

            Point newPoint = new Point(5,5);
            newPoint.Display();

            Console.ReadLine();

        }

        struct Point
        {
            public int X,Y;

            public Point(int XPos,int YPos)
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
