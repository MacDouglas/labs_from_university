using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CustomExeption
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("*** Fun with Custom exception ***");
            Car myCar = new Car("Rusty", 50);

            try
            {
                myCar.Accelerate(10);
            }
            catch(CarIsDeadException e)
            {
                Console.WriteLine(e.Message);
                Console.WriteLine(e.ErrorTimeStamp);
                Console.WriteLine(e.CauseOfError);
         
            }

            Console.ReadLine();
        }

    }
}
