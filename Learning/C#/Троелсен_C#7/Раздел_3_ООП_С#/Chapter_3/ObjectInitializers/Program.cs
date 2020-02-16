using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ObjectInitializers
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("*** Fun witn object Init Syntax ***\n");

            //Point firstPoint = new Point();
            //firstPoint.X = 10;
            //firstPoint.Y = 10;
            //firstPoint.Display();

            //Point anotherPoint = new Point(20, 20);
            //anotherPoint.Display();

            //Point finalPoint = new Point { X = 30, Y = 30 };
            //finalPoint.Display();

            //Point goldPoint = new Point(PointColor.Gold) { X = 90, Y = 20 };
            //goldPoint.Display();

            Rectangle myRect = new Rectangle
            {
                TopLeft = new Point { X = 10, Y = 10 },
                BottomRight = new Point { X = 200, Y = 200 }

            };
            myRect.Display();

            Console.ReadLine();
        
        }

    }
}
