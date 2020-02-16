using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SimpleClassExample
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("*** Fun with Class types *** \n");

            //Car myCar = new Car();
            //myCar.petName = "Ford";
            //myCar.currSpeed = 15;
            //for (int i = 0; i < 10; i++)
            //{
            //    myCar.SpeedUp(5);
            //    myCar.PrintState();
            //}
            //Console.WriteLine();

            //Car chuckCar = new Car();
            //chuckCar.PrintState();
            Motorcycle myMoto = new Motorcycle();
            //myMoto.SetDriverName("Mitsu");
            Console.WriteLine("Rider name is {0}",myMoto.name);

            MakeSomeBikes();

            Console.ReadLine();
        }

        static void MakeSomeBikes()
        {
            Motorcycle m1 = new Motorcycle();
            Console.WriteLine($"Name = {m1.name}, Speed = {m1.driverIntensity}");

            Motorcycle m2 = new Motorcycle(9);
            Console.WriteLine($"Name = {m2.name}, Speed = {m2.driverIntensity}");

            Motorcycle m3 = new Motorcycle(name:"Ford");
            Console.WriteLine($"Name = {m3.name}, Speed = {m3.driverIntensity}");


        }
    }
}
