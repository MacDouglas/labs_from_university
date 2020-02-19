using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shapes
{
    class Program    
    {
        static void Main(string[] args)
        {
            Console.WriteLine("*** Fun with abstract and virtual Class/methods ***");
            Circle cr = new Circle("Big circle");
            cr.Draw();

            Hexagon hx = new Hexagon("Little Hexagon");
            hx.Draw();
            Console.WriteLine();

            Shape[] MyShapes = { new Hexagon(), new Circle(), new Hexagon("Little"), new Circle("Big") };
            foreach (Shape i in MyShapes)
            {
                i.Draw();
            }
            Console.WriteLine();
            ThreeDCircle o = new ThreeDCircle();
            o.Draw();
            ((Circle)o).Draw();

            Console.ReadLine();
        }
    }
}
