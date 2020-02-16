using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EmployeeApp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("*** Fun with Encapsulation ***");
            Employee emp = new Employee("Jake", 30, 30000);
            emp.GiveBonus(1000);
            emp.Display();

            emp.SetName("Mike");
            Console.WriteLine("Employee is named: {0}",emp.GetName());

            Employee emp2 = new Employee();
            emp2.Name = "Xena";
            Console.WriteLine("Name of Employee: {0}",emp2.Name);

            Employee joe = new Employee();
            joe.Age++;
            joe.Display();
            
            Console.ReadLine();
        }
    }
}
