using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CustomInterface
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("*** Fun with Interface ***\n");
            //Hexagon hex = new Hexagon();
            //Console.WriteLine("Points: {0}", hex.Points);

            //Circle c = new Circle("C");
            //IPointy itfPt = null;
            //try
            //{
            //    itfPt = (IPointy)c;
            //    Console.WriteLine(itfPt.Points);
            //}
            //catch (InvalidCastException e)
            //{
            //    Console.WriteLine(e.Message);
            //    Console.WriteLine(e.Source);
            //    Console.WriteLine(e.StackTrace);
            //    Console.WriteLine(e.TargetSite);
            //    //throw;
            //}

            //Hexagon hex2 = new Hexagon("Hexagon");
            //IPointy ipnt = hex2 as IPointy;
            //if (ipnt == null )
            //    Console.WriteLine("Points: ", ipnt.Points);
            //else
            //    Console.WriteLine("Not pointy");

            Shape[] myShaes = { new Hexagon("Hex"), new Circle("circle"), new Triangle("Triangle"), new Circle("ABCDEF") };
            for (int i = 0; i < myShaes.Length; i++)
            {
                if (myShaes[i] is IDraw3D)
                    DrawIn3D((IDraw3D)myShaes[i]);

                //myShaes[i].Draw();
                //if (myShaes[i] is IPointy ip)
                //{
                //    Console.WriteLine("-> Points: {0} ", ip.Points);
                //}
                //else
                //{
                //    Console.WriteLine("No Points in {0}",myShaes[i].PetName);
                //}
            }
            IPointy firstPointyItem = FindFirstPointyShape(myShaes);
            Console.WriteLine("The first item has {0} points",firstPointyItem.Points);



            Console.ReadLine();
        }
        static IPointy FindFirstPointyShape(Shape[] shapes)
        {
            foreach (Shape s in shapes)
            {
                if (s is IPointy ip)
                    return ip;
            }
            return null;
        }
        static void DrawIn3D(IDraw3D itf3d)
        {
            Console.WriteLine("\n-> Drawing IDraw3D compatable type");
            itf3d.Draw3D();
        }
    }
}
