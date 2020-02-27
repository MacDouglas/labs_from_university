using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IntaerfaceHierarchy
{
    class BitmapImage : IDrawable,IAdvancedDraw
    {
        public void Draw()
        {
            Console.WriteLine("Drawing ...");
        }
        public void DrawUpsideDown()
        {
            Console.WriteLine("Drawing upside down ...");
        }
        public void DrawInBoundingBox(int top,int left,int bottom,int right)
        {
            Console.WriteLine("Drawing in a box ...");
        }
    }
}
