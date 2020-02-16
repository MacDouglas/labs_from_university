using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AutoProps
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("***Fun with Automatic properties ***\n");

            Car c = new Car();
            c.PetName = "Ford";
            c.Color = "Red";
            c.Speed = 240;
            c.Display();

            Garage g = new Garage();
            g.MyAuto = c;
            Console.WriteLine("Number of cars in garage is {0}",g.NumberOfCars);
            Console.WriteLine("Your car is named: {0}",g.MyAuto.PetName);

            Console.ReadLine();
        }
    }
}
