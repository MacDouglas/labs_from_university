using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StaticDataAndMembers
{
    class SavingsAccaunt
    {
        public double currBalance;
        public static double currInterestRate;

        public static double InterestRate
        {
            get { return currInterestRate; }
            set { currInterestRate = value; }
        }

        public SavingsAccaunt(double balance)
        {
            //currInterestRate = 0.04;
            currBalance = balance;
        }
        static SavingsAccaunt()
        {
            Console.WriteLine("In static ctor!");
            currInterestRate = 0.04;
        }
        public static void SetInterestRate(double newRate) => currInterestRate = newRate;
        public static double GetInterestRate()
        {
            return currInterestRate;
        }
    }
}
