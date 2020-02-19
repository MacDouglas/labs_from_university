using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ObjectInitializers
{
    class Rectangle
    {
        private Point topLeft = new Point();
        private Point bottomRight = new Point();

        public Point TopLeft
        {
            get => topLeft;
            set => topLeft = value;
        }
        public Point BottomRight
        {
            get => bottomRight;
            set => bottomRight = value;
        }
        public void Display()
        {
            Console.WriteLine("[TopLeft: {0},{1},{2} BottomRight: {3}, {4}, {5}]",
                TopLeft.X, TopLeft.Y, TopLeft.Color, 
                BottomRight.X, BottomRight.Y, BottomRight.Color);
        }
    }
}
