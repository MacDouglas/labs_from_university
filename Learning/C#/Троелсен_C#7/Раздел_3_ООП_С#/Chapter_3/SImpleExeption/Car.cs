using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SimpleExeption
{
    class Car
    {
        public const int maxSpeed = 100;
        public string PetName { get; set; } = "";
        public int CurrentSpeed { get; set; } = 0;

        private bool carIsDead;

        private Radio MusicBox = new Radio();
        public Car()
        {

        }
        public Car(string name,int speed)
        {
            CurrentSpeed = speed;
            PetName = name;
        }
        public void CrankTunes(bool state)
        {
            MusicBox.TurnON(state);
        }
        public void Accelerate(int delta)
        {
            if(carIsDead)
                Console.WriteLine("{0} is out of order",PetName);
            else
            {
                CurrentSpeed += delta;
                if(CurrentSpeed>maxSpeed)
                {
                    //Console.WriteLine("{0} has overhiated ",PetName);
                    CurrentSpeed = 0;
                    carIsDead = true;
                    
                    Exception ex = new Exception($"{PetName} has overheated");
                    ex.HelpLink = "http://www.carsRUs.com";

                    ex.Data.Add("Times stamp", $"The car exploded ad {DateTime.Now}");
                    ex.Data.Add("Cause", "You have a lead foot.");

                    throw ex;
                    //throw new Exception($"{PetName} has overheated!");
                }
                else
                    Console.WriteLine("=> Current speed = {0} ",CurrentSpeed);
            }
        }
    }
}
