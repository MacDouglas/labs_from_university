using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Employees
{
    class Program
    {
        static void Main(string[] args)
        {                     
            Console.WriteLine("*** The Employee Class Hierarchy ***\n");

            //Manager chuck = new Manager("Chucky", 50, 92, 10000, "123-456-789", 9000);
            //chuck.GiveBonus(300);
            //chuck.Display();
            //Console.WriteLine();

            //SalesPerson frank = new SalesPerson("Frank", 43, 67, 3000, "765-356-321", 43);
            //frank.GiveBonus(200);
            //frank.Display();

            //PTSaledPerson pt = new PTSaledPerson();
            //pt.Display();

            //SalesPerson fred = new SalesPerson();
            //fred.Display();
            //Console.WriteLine();

            //Manager mike = new Manager("Mike", 20, 45, 500, "123-321", 10);
            //double cost = mike.GetBenefitsCost();
            //Console.WriteLine("Mike benefit is: {0}", cost);

            //Employee.BenefitPackage.BenefitPackageLevel myBenefitLevel =
            //    Employee.BenefitPackage.BenefitPackageLevel.Standart;

            CastingExamples();

            //object[] obj = new object[4];
            //obj[0] = new Hexagon();
            //obj[1] = false;
            //obj[2] = new Hexagon();
            //obj[3] = new Manager();

            //foreach (object item in obj)
            //{
            //    Hexagon h = item as Hexagon;
            //    if (h == null)
            //        Console.WriteLine("Item is not a hexagon");
            //    else
            //        h.Draw();
            //}

            Console.ReadLine();


        }
        static void CastingExamples()
        {
            object frank = new Manager("Frank", 40, 124, 10234, "1231231412", 100);

            Employee moonUnit = new Manager("MoonUnit Zappa", 2, 41, 5123, "123-567-8765", 10);

            SalesPerson sl = new PTSaledPerson();

            GivePromotion((Manager)frank);
            GivePromotion(moonUnit);
            GivePromotion(sl);
        }
        static void GivePromotion(Employee emp)
        {
            Console.WriteLine("{0} was promoted",emp.Name);

            switch (emp)
            {
                case SalesPerson s:
                    Console.WriteLine("{0} made {1} sales ", emp.Name, s.SalesNumber);
                    Console.WriteLine();
                    break;
                case Manager m:
                    Console.WriteLine("{0} had {1} stocks options ... ", emp.Name, m.StockOptions);
                    Console.WriteLine();
                    break;
                case Intern _:
                    break;
                
                case null:
                    break;

            }
            //if(emp is SalesPerson s)
            //{
            //    //Console.WriteLine("{0} made {1} sales ",emp.Name,((SalesPerson)emp).SalesNumber);
            //    Console.WriteLine("{0} made {1} sales ", emp.Name, s.SalesNumber);

            //    Console.WriteLine();
            //}
            //if (emp is Manager m)
            //{
            //    //Console.WriteLine("{0} had {1} stocks options ... ",emp.Name,((Manager)emp).StockOptions);
            //    Console.WriteLine("{0} had {1} stocks options ... ", emp.Name, m.StockOptions);

            //    Console.WriteLine();
            //}

        }
    }
}
