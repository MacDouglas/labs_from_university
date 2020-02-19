using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IterationsAndDecisions
{
    class Program
    {
        static void Main(string[] args)
        {
            //ForLoopExample();

            //ForeachLoopExample();
            //WhileLoopExample();

            //ExecutelfElseUsingConditionalOperator();

            //SwitchExamle();

            //SwitchOnStringExample();

            //SwitchOnEnumExample();

            //ExecutePatternMatchingSwitch();

            ExecutePatternMatchingSwitchWithWhen();


            Console.ReadLine();
        }
        static void ExecutePatternMatchingSwitchWithWhen()
        {
            Console.WriteLine("1 [C#], 2[VB]");
            Console.WriteLine("Please pick your language:");
            object langChoice = Console.ReadLine();
            var choice = int.TryParse(langChoice.ToString(), out int c) ? c : langChoice;
            switch (choice)
            {
                case int i when i == 2:
                case string s when s.Equals("VB", StringComparison.OrdinalIgnoreCase):
                    Console.WriteLine("VB");
                    break;
                case int i when i == 1:
                case string s when s.Equals("C#", StringComparison.OrdinalIgnoreCase):
                    Console.WriteLine("C#");
                    break;
                default:
                    Console.WriteLine("You choosed smth else");
                    break;
            }
        }

        static void ExecutePatternMatchingSwitch()
        {
            Console.WriteLine("1 [Integer (2), 2 [String (\"Hi\")], 3 [Decimal (2,5)]");
            Console.WriteLine("Please pick your type: ");
            string userChoice = Console.ReadLine();
            object choice;

            switch (userChoice)
            {
                case "1":
                    choice = 2;
                    break;
                case "2":
                    choice = "Hi";
                    break;
                case "3":
                    choice = 2.5m;
                    break;
                default:
                    choice = 2;
                    Console.WriteLine("You choosed nothing");
                    break;
            }

            switch (choice)
            {
                case int i:
                    Console.WriteLine("You choice is Int {0}", i);
                    break;
                case string s:
                    Console.WriteLine("You choice is String {0}",s );
                    break;
                case decimal d:
                    Console.WriteLine("You choice is Decimal {0} ", d);
                    break;
                default:
                    Console.WriteLine("You choise is something else");
                    break;
            }
        }
        static void SwitchOnEnumExample()
        {
            Console.WriteLine("Enter your favorite day of the week:");
            DayOfWeek favDay;
            try
            {
                favDay = (DayOfWeek)Enum.Parse(typeof(DayOfWeek), Console.ReadLine());
            }
            catch (Exception)
            {
                Console.WriteLine("Bad input!");
                return;
            }
            switch (favDay)
            {
                case DayOfWeek.Saturday:
                case DayOfWeek.Sunday:
                    Console.WriteLine("Weekend!");
                    break;
                case DayOfWeek.Monday:
                    Console.WriteLine("Monday");
                    break;
                case DayOfWeek.Tuesday:
                    Console.WriteLine("Tuesday");

                    break;
                case DayOfWeek.Wednesday:
                    Console.WriteLine("Wednesday");

                    break;
                case DayOfWeek.Thursday:
                    Console.WriteLine("Thursday");

                    break;
                case DayOfWeek.Friday:
                    Console.WriteLine("Friday");

                    break;

                default:
                    Console.WriteLine(" ");
                    break;
            }
            Console.WriteLine();
        }
        static void SwitchOnStringExample()
        {
            Console.WriteLine("C# or VB");
            Console.WriteLine("Please pick your language preference");
            string langChoice = Console.ReadLine();
            switch (langChoice)
            {
                case "C#":
                    Console.WriteLine("You choosed C#");
                    break;
                case "VB":
                    Console.WriteLine("You choosed VB");
                    break;
                default:
                    Console.WriteLine("You choosed nothing");
                    break;
            }
        }

        static void SwitchExamle()
        {
            Console.WriteLine("1 [C#], 2 [VB]");
            Console.WriteLine("Please pick your language preference");
            string LangChoice = Console.ReadLine();

            int n = int.Parse(LangChoice);
            switch (n)
            {
                case 1:
                    Console.WriteLine("Good choice, c# good language");
                    break;
                case 2:
                    Console.WriteLine("VB good choice too");
                    break;
                default:
                    Console.WriteLine("You choosed nothing");
                    break;
            }
        }

        private static void ExecutelfElseUsingConditionalOperator()
        {
            string stringData = "My textual data";
            Console.WriteLine(stringData.Length > 0 ? "string is greater than 0 characters"
            : "string is not greater than 0 characters");
            Console.WriteLine();
        }
        static void DoWhileLoopExample()
        {
            string userlsDone = "";
            do
            {
                Console.WriteLine("In do/while loop");
                Console.Write("Are you done? [yes] [no]: ");
                userlsDone = Console.ReadLine();
            }while (userlsDone.ToLower() != "yes"); //Обратите внимание на точку с запятой!
        }

        static void WhileLoopExample()
        {
            string userIsDone = "";
            while(userIsDone.ToLower() != "yes")
            {
                Console.WriteLine("in while loop");
                Console.WriteLine("Are you done? [yes] [no]");
                userIsDone = Console.ReadLine();
            }
        }

        static void ForeachLoopExample()
        {
            string[] sportCars = { "Ford", "Ferrari", "Toyota", "Bently"};
            foreach ( string c in sportCars)
            {
                Console.WriteLine(c);
            }
            int[] myInt = { 10, 20, 30, 40 };
            foreach (var item in myInt)
            {
                Console.WriteLine(item);
            }

        }
        static void ForLoopExample()
        {
            for (int i = 0; i < 4; i++)
            {
                Console.WriteLine($"Number is {i}");
            }
        }
    }
}
