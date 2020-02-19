using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace SimpleExeption
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("*** Simple Exeption Example ***");
            Console.WriteLine("Creating a car and stepping on it");
            Car myCar = new Car("Zippy", 20);
            myCar.CrankTunes(true);
            try
            {
                for (int i = 0; i < 10; i++)
                {
                    myCar.Accelerate(10);
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("\n => Custom data: ");
                foreach (DictionaryEntry item in e.Data)
                {
                    Console.WriteLine("-> {0}: {1}", item.Key,item.Value);
                }


                Console.WriteLine();
                Console.WriteLine("*** Error! ***");
                Console.WriteLine("Method: {0}", e.TargetSite);
                Console.WriteLine("Class defining member: {0} ", e.TargetSite.DeclaringType);
                Console.WriteLine("Member type: {0} ", e.TargetSite.MemberType);
                Console.WriteLine("Message: {0}", e.Message);
                Console.WriteLine("Source: {0}", e.Source);
                Console.WriteLine("Help Link: {0}",e.HelpLink);
                Console.WriteLine();
                Console.WriteLine("Stack: {0}", e.StackTrace);

            }

            Console.ReadLine();
        }
    }
}
