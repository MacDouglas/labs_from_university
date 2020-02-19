using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RefTypeValTypeParams
{

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("*** Passing Person object by value ***");
            Person Fred = new Person("Fred", 12);
            Console.WriteLine("\nBefore by value call,person is:");
            Fred.Display();
            //SendAPersonByValue(Fred);
            SendAPersonByRef(ref Fred);
            Console.WriteLine("\n After by value call,Person is:");
            Fred.Display();

            Console.ReadLine();

        }
        static void SendAPersonByRef(ref Person p)
        {
            p.personAge = 99;
            p = new Person("Kate", 999);
        }
        static void SendAPersonByValue(Person p)
        {
            p.personAge = 99;
            p = new Person("Jones", 999);
        }
    }

    class Person
    {
        public string personName;
        public int personAge;

        public Person(string name, int age)
        {
            personAge = age;
            personName = name;
        }
        public Person() { }

        public void Display()
        {
            Console.WriteLine("Name: {0}, Age {1} ",personName,personAge);
        }
    }
}
