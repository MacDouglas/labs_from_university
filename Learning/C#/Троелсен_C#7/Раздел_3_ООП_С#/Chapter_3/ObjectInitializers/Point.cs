using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ObjectInitializers
{
    enum PointColor
    {
        LightBlue,
        BloodRed,
        Gold
    }
    class Point
    {
        public int X { get; set; }
        public int Y { get; set; }
        public PointColor Color { get; set; }
        public Point(int xPos,int yPos)
        {
            X = xPos;
            Y = yPos;
            Color = PointColor.Gold;
        }
        public Point(PointColor ptColor)
        {
            Color = ptColor;
        }
        public Point() : this(PointColor.BloodRed) { }
        public void Display()
        {
            Console.WriteLine("[{0} , {1}]",X,Y);
            Console.WriteLine("Point color is: {0}", Color);
        }
        
    }
}
