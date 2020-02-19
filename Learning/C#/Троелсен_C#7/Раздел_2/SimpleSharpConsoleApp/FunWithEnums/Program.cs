using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FunWithEnums
{
    //enum empType : byte
    enum empType        //System.Int32
    {
       Manager = 100,
       Grant,          //101
       Contractor,     //102
       VicePresident   //103
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("*** Fun with Enums ***");
            empType emp = empType.Grant;
            //AskForBonus(emp);

            //Console.WriteLine("empType uses a {0} for storge",Enum.GetUnderlyingType(emp.GetType()));
            //Console.WriteLine("empType uses a {0} for storge", Enum.GetUnderlyingType(typeof(empType)));

            //Console.WriteLine("emp is a {0} = {1}",emp.ToString(),(byte)emp);

            EvaluateEnum(emp);

            DayOfWeek d = DayOfWeek.Monday;
            ConsoleColor cc = ConsoleColor.Red;

            EvaluateEnum(d);
            EvaluateEnum(cc);

            Console.ReadLine();

        }
        static void EvaluateEnum(System.Enum e)
        {
            Console.WriteLine("=> information about {0}",e.GetType().Name);
            Console.WriteLine("Underlying storage type: {0}",Enum.GetUnderlyingType(typeof(empType)));

            Array enumData = Enum.GetValues(e.GetType());
            Console.WriteLine("This enum has {0} elements",enumData.Length);
            for (int i = 0; i < enumData.Length; i++)
            {
                Console.WriteLine("Name: {0}, value: {0:D}",enumData.GetValue(i));
         
            }
            Console.WriteLine();

        }
        static void AskForBonus(empType e)
        {
            switch (e)
            {
                case empType.Manager:
                    Console.WriteLine("Manager");
                    break;
                case empType.Grant:
                    Console.WriteLine("Grant");
                    break;
                case empType.Contractor:
                    Console.WriteLine("Contractor");
                    break;
                case empType.VicePresident:
                    Console.WriteLine("Vice President");
                    break;
            }
        }
    }
}
