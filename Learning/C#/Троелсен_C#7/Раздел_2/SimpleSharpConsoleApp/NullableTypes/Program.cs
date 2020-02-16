using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NullableTypes
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("*** Fun with Nullable data");
            DatabaseReader dr = new DatabaseReader();

            int? i = dr.GetIntFromDatabase();
            if(i.HasValue)
                Console.WriteLine("Value of i is {0}",i.Value);
            else
                Console.WriteLine("Value of i undefined");

            bool? b = dr.GetBoolFromDatabase();

            if (b.HasValue)
                Console.WriteLine("Value of b is {0}", b.Value);
            else
                Console.WriteLine("Value of b undefined");


           

            // Если значение, возвращаемое из GetlntFromDatabase(), равно
            // null, то присвоить локальной переменной значение 100.
            int moreData = dr.GetIntFromDatabase() ?? 100;
            Console.WriteLine("Value of MyData is {0}", moreData);

            //int? moreData = dr.GetIntFromDatabase();
            //if (!moreData.HasValue)
            //    moreData = 100;
            //Console.WriteLine("Value of moreData: {0}", moreData);

            TesterMethod(null);

            Console.ReadLine();




        }
        static void TesterMethod(string[] args)
        {
            //if(args != null)
            //    Console.WriteLine($"You sent me {args.Length} arguments");
            
            //Мы должны проверять на предмет null перед доступом к данным массива!
            Console.WriteLine($"You sent me {args?.Length ?? 0} argument");
        }
        static void LocalNullableVariables()
        {
            //int? nullableInt = 10;
            //double? nullableDouble = 3.14;
            //bool? nullableBool = null;
            //char? nullableChar = 'a';
            //int?[] arrayOfNullableInt = new int?[10];

            // Определить несколько типов, допускающих null, с применением Nullable<T>.
            //Nullable<int> nullableInt = 10;
            //Nullable<double> nullableDouble = 3.14;
            //Nullable<bool> nullableBool = null;
            //Nullable<int>[] arrayOfNullableInt = new Nullable<int>[10];
        }
    }
    class DatabaseReader
    {
        public int? numericalValue = null;
        public bool? boolValue = true;

        public int? GetIntFromDatabase()
        {
            return numericalValue;
        }
        public bool? GetBoolFromDatabase()
        {
            return boolValue;
        }

    }
}
