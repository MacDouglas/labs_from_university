using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SimpleClassExample
{
    class Motorcycle
    {
        public int driverIntensity;
        public string name;

        public Motorcycle() {}

        //public Motorcycle(int intensity) => driverIntensity = intensity;
        //public void SetDriverName(string name) => this.name = name;
        public Motorcycle(int intensity) : this(intensity, "") { }

        public Motorcycle(string name) : this(0, name) { }
        public Motorcycle(int intensity = 0,string name = "")
        {
            if (intensity > 10)
                intensity = 10;
            driverIntensity = intensity;
            this.name = name;
        }
        
    }
}
