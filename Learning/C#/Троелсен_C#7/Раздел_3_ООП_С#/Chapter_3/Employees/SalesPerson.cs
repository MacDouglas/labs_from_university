using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Employees
{
    class SalesPerson : Employee
    {
        public int SalesNumber { get; set; }
        public SalesPerson(string fullName,int age,int empID, float currPay, string ssn,int numbOfSales)
            : base(fullName,age,empID,currPay,ssn)
        {
            SalesNumber = numbOfSales;
        }

        public SalesPerson()
        {
        }
        public override sealed void GiveBonus(float amount)
        {
            int salesBonus = 0;
            if (salesBonus >= 0 && SalesNumber <= 100)
                salesBonus = 10;
            else
            {
                if (SalesNumber >= 101 && SalesNumber <= 200)
                    salesBonus = 15;
                else
                    salesBonus = 20;
            }

            base.GiveBonus(amount * salesBonus);
        }
        public override void Display()
        {
            base.Display();
            Console.WriteLine("Number of sales is: {0}",SalesNumber);
        }
    }
    sealed class PTSaledPerson : SalesPerson
    {
        public PTSaledPerson()
        {

        }
        public PTSaledPerson(string fullName, int age, int empID, float currPay, string ssn, int numbOfSales)
            : base(fullName,age,empID,currPay,ssn,numbOfSales)
        {

        }
        public override void Display()
        {
            base.Display();
            Console.WriteLine("PTSalesPerson Class");
        }
    }
}
