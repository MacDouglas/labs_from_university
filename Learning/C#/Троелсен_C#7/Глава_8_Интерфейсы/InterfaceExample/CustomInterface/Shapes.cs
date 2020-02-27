using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CustomInterface
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
    class Triangle: Shape, IPointy
    {
        public Triangle() { }
        public Triangle(string name) : base(name)
        {

        }
        public override void Draw()
        {
            Console.WriteLine("Drawing {0} the Triangle",PetName);
        }
        public byte Points
        {
            get { return 3; }
        }

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
    class ThreeDCircle : Circle,IDraw3D
    {
        public new string PetName { get; set; }
        public new void Draw()
        {
            Console.WriteLine("Drawing a 3D Circle");
        }
        public void Draw3D()
        {
            Console.WriteLine("Drawing circle in 3D");
        }
    }
    class Hexagon : Shape,IPointy,IDraw3D
    {
        public Hexagon() { }
        public Hexagon(string name) : base(name) { }
        public override void Draw()
        {
            Console.WriteLine("Drowing {0} the Hexagon ",PetName);
        }
        public byte Points
        {
            get { return 6; }
        }
        public void Draw3D()
        {
            Console.WriteLine("Drawing hexagon in 3d");
        }
    }
}
