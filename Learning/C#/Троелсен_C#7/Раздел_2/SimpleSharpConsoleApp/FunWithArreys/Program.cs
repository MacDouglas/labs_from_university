using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FunWithArreys
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("*** Fun with arreys");
            //SimpleArreys();

            //ArreyInicialization();

            //DeclareImplicitArreys();

            //ArreyOfObjects();

            //RectMultidemensionalArray();

            //JaggedMultidemensionalArray();

            //PassAndReceiveArrays();

            SystemArrayFunctionality();

            Console.ReadLine();
        }

        static void SystemArrayFunctionality()
        {
            string[] gothicBands = { "Tones on Tail", "Bauhaus", "Sisters of mercy" };

            Console.WriteLine("-> Here is the array");
            for (int i = 0; i < gothicBands.Length; i++)
            {
                Console.WriteLine(gothicBands[i] + ", ");
            }
            Console.WriteLine("\n");
            Array.Reverse(gothicBands);

            Console.WriteLine("-> Here is the reverse array");
            for (int i = 0; i < gothicBands.Length; i++)
            {
                Console.WriteLine(gothicBands[i] + ", ");
            }
            Console.WriteLine("\n");

            Console.WriteLine("-> Cleared out all but one...");
            Array.Clear(gothicBands, 1, 2);
            for (int i = 0; i < gothicBands.Length; i++)
            {
                Console.WriteLine(gothicBands[i] + ", ");
            }

        }
        static void PrintArray(int[] myInts) 
        {
            for (int i = 0; i < myInts.Length; i++)
            {
                Console.WriteLine("Item {0} is a {1}",i,myInts[i]);
            }
        }
        static string[] GetStringArray()
        {
            string[] myString = { "Hello", "world", "!!!" };
            return myString;
        }

        static void PassAndReceiveArrays()
        {
            Console.WriteLine("=> Arrays as params and return values");
            int[] intArr = { 10, 20, 30, 40 };
            PrintArray(intArr);

            string[] str = GetStringArray();
            foreach (string s in str)
            {
                Console.WriteLine(s);
            }
            Console.WriteLine();
        }
        static void JaggedMultidemensionalArray()
        {
            Console.WriteLine("=> Jagged multidemensional array: ");
            int[][] myJagArray = new int[5][];
            for (int i = 0; i < myJagArray.Length; i++)
            {
                myJagArray[i] = new int[i + 7];
            }

            for (int i = 0; i < myJagArray.Length; i++)
            {
                for (int j = 0; j < myJagArray[i].Length; j++)
                {
                    Console.Write(myJagArray[i][j] + "  ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
        static void RectMultidemensionalArray()
        {
            int[,] myMatrix;
            myMatrix = new int[3, 4];
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    myMatrix[i, j] = i * j;
                }
            }

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    Console.Write(myMatrix[i,j] + "\t");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
        static void ArreyOfObjects()
        {
            object[] myObjects = new object[4];
            myObjects[0] = 10;
            myObjects[1] = false;
            myObjects[2] = new DateTime(2020, 2, 4);
            myObjects[3] = "Form & Void";
            foreach (object i in myObjects)
            {
                Console.WriteLine($"Type: {i.GetType()}, value: {i}" );
            }
            Console.WriteLine();

        }

        static void DeclareImplicitArreys()
        {
            Console.WriteLine("=> Implicit Arrey Inicialization");

            var a = new[] { 1, 10, 100, 1000 };
            Console.WriteLine($"A is a: {a.ToString()}");

            var b = new[] { 1, 10.5, 100, 1000.7 };
            Console.WriteLine($"B is a: {b.ToString()}");

            var c = new[] { "Hello ", "world", "null"};
            Console.WriteLine($"C is a: {c.ToString()}");
            Console.WriteLine();
        }
        static void ArreyInicialization()
        {
            string[] stringArrey = new string[] {"One","Two","Three"};
            Console.WriteLine("StringArrey has {0} elements", stringArrey.Length);

            bool[] boolArrey = { true, true, false };
            Console.WriteLine("BoolArrey has {0} elements",boolArrey.Length);

            int[] intArrey = new int[4] { 1, 2, 3, 4 };
            Console.WriteLine("intArrey has {0} elements", intArrey.Length);
            Console.WriteLine();


        }

        static void SimpleArreys()
        {
            Console.WriteLine("=> Simple Arrey creation");
            int[] myIny = new int[3];
            myIny[0] = 100;
            myIny[1] = 200;
            myIny[2] = 300;

            foreach (int i in myIny)
            {
                Console.WriteLine(i);
            }
            string[] myString = new string[100];
            Console.WriteLine();
        }
    }
}
