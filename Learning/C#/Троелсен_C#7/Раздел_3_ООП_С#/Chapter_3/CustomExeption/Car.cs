using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CustomExeption
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

                CarIsDeadException ex = new CarIsDeadException($"{PetName} has overheated!", "You have a lead foot", DateTime.Now);
                ex.HelpLink = "http://www.CarsRus.com";
                throw ex;
            }
        }
    }
}
