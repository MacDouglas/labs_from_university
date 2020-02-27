using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IntaerfaceHierarchy
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("*** Simple Interface Hierarchy ***\n");

            BitmapImage bitmap = new BitmapImage();
            bitmap.Draw();
            bitmap.DrawUpsideDown();
            bitmap.DrawInBoundingBox(10, 10, 30, 40);

            IAdvancedDraw advancedDraw = bitmap as IAdvancedDraw;
            if (advancedDraw != null)
                advancedDraw.DrawUpsideDown();

            Console.ReadLine();
        }
    }
}
