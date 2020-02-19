using System;

namespace ObjectOverrides
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("*** Fun with System.Object ***");
            Person p1 = new Person("Homer", "Simpson", 50);
            Person p2 = new Person("Homer", "Simpson", 50);

            Console.WriteLine("p1.ToString: {0}", p1.ToString());
            Console.WriteLine("p2.ToString: {0}", p2.ToString());
            Console.WriteLine("P1 = P2?: {0}",p1.Equals(p2));

            Console.WriteLine("Same Hash Codes ?: {0}",p1.GetHashCode() == p2.GetHashCode());
            Console.WriteLine();
            p2.Age = 42;

            Console.WriteLine("p1.ToString: {0}", p1.ToString());
            Console.WriteLine("p2.ToString: {0}", p2.ToString());
            Console.WriteLine("P1 = P2?: {0}", p1.Equals(p2));

            Console.WriteLine("Same Hash Codes ?: {0}", p1.GetHashCode() == p2.GetHashCode());
            Console.WriteLine();

            MembersOfObjects();

            //Console.ReadLine();
        }
        static void MembersOfObjects()
        {
            Person p3 = new Person("Sally", "Jones", 4);
            Person p4 = new Person("Sally", "Jones", 4);
            Console.WriteLine("p3 and p4 have some state: {0}",object.Equals(p3,p4));
            Console.WriteLine("p3 and p4 are pointing to same object: {0}",object.ReferenceEquals(p3,p4));
        }
    }
}
