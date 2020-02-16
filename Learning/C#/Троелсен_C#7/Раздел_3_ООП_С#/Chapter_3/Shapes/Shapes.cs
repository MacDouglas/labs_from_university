using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shapes
{
    abstract class Shape
    {
        public string PetName { get; set; }
        public Shape(string name = "No name")
        {
            PetName = name;
        }
        public abstract void Draw();
    }
    class Circle : Shape
    {
        public Circle(){}
        public Circle(string name) : base(name) { }
        public override void Draw()
        {
            Console.WriteLine("Drowing {0} the Circle",PetName);
        }

    }
    class ThreeDCircle : Circle
    {
        public new string PetName { get; set; }
        public new void Draw()
        {
            Console.WriteLine("Drawing a 3D Circle");
        }
    }
    class Hexagon : Shape
    {
        public Hexagon() { }
        public Hexagon(string name) : base(name) { }
        public override void Draw()
        {
            Console.WriteLine("Drowing {0} the Hexagon ",PetName);
        }
    }
}
