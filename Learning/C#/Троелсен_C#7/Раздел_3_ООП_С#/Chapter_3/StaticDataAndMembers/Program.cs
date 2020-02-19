using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StaticDataAndMembers
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("*** Fun with Static Data ***\n");
            SavingsAccaunt s1 = new SavingsAccaunt(40);
            SavingsAccaunt s2 = new SavingsAccaunt(50);
            Console.WriteLine("Interest Rate is {0}",SavingsAccaunt.GetInterestRate());
            SavingsAccaunt.SetInterestRate(0.08);
            SavingsAccaunt s3 = new SavingsAccaunt(100);
            Console.WriteLine("Interest Rate is {0}", SavingsAccaunt.GetInterestRate());


            Console.ReadLine();
        }
    }
}
