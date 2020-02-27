using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IClonableExample
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("*** First look at Interfaces ***\n");
            string myString = "Hello";
            OperatingSystem unixOS = new OperatingSystem(PlatformID.Unix, new Version());
            System.Data.SqlClient.SqlConnection sqlCnn = new System.Data.SqlClient.SqlConnection();
            CloneMe(myString);
            CloneMe(unixOS);
            CloneMe(sqlCnn);

            Console.ReadLine();
        }
        private static void CloneMe(ICloneable e)
        {
            object theClone = e.Clone();
            Console.WriteLine("You clone is a: {0} ",theClone.GetType().Name);
        }
    }
}
