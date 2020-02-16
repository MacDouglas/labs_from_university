using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TypeConversion
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("*** Fun with type conversion");

            //  short numb1 = 30000, numb2 = 30000, answer = (short)Add(numb1,numb2);
            //Console.WriteLine($"{numb1} + {numb2} = {answer}");

            //NarrowingAttempt();

            //ProcessBytes();

           

            Console.ReadLine();
        }
       
        static void DeclareExplicitVars()
        {
            int myInt = 0;
            bool myBool = false;
            string myString = "Time marche on...";
        }
        static void ProcessBytes()
        {
            byte b1 = 100, b2 = 250;

            try
            {
                unchecked
                {
                    byte sum = (byte)Add(b1, b2);
                    Console.WriteLine($"sum = {sum}");
                }
            }
            catch(OverflowException ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
        static void NarrowingAttempt()
        {
            byte myByte = 0;
            int myInt = 200;
            myByte = (byte)myInt;
            Console.WriteLine($"Value of byte = {myByte}");
        }
        static int Add(int a,int b)
        {
            return a + b;
        }
    }
}
