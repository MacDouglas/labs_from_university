using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AutoProps
{
    class Car
    {
        public string PetName { get; set; }
        public int Speed { get; set; }
        public string Color { get; set; }
        private int NumberOfDoors = 2;
        //public int MyProperty { get; set; }   //prop

        public void Display()
        {
            Console.WriteLine("Name: {0}", PetName);
            Console.WriteLine("Speed: {0}", Speed);
            Console.WriteLine("Color: {0}", Color);
        }
    }
    class Garage
    {
        public int NumberOfCars { get; set; } = 1;
        public Car MyAuto { get; set; } = new Car();
        public Garage() { }
        public Garage(Car car,int number)
        {
            MyAuto = car;
            NumberOfCars = number;
        }
    }   
}
