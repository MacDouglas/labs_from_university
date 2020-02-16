using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace BasicDataTypes
{
    class Program
    {
        static void Main(string[] args)
        {
            //LocalVarDeclarations();

            //DefaultDeclaration();

            //NewingDataTypes();

            //ObjectFunctionality();

            //DataTypeFunctionality();

            //CharFunctionality();

            //ParseFromStrings();

            //ParseFromStringsWithTryParse();

            //UseDataAndTime();

            UseBigInteger();

            Console.ReadLine();
        }
        static void UseBigInteger()
        {
            Console.WriteLine("=> Use BigInteger");
            BigInteger big = BigInteger.Parse("9999999999999999999999999999999999999999999999");

            Console.WriteLine("Value of big: {0}",big);
            Console.WriteLine("Is big an even value?: {0}",big.IsEven);
            Console.WriteLine("Is big a pawor of two?: {0}",big.IsPowerOfTwo);

            BigInteger biggy = BigInteger.Multiply(big, BigInteger.Parse("8888888888888888888888888888888888888888888"));
            Console.WriteLine("Value of biggy is {0}",biggy);
        }
        static void UseDataAndTime()
        {
            Console.WriteLine("=> Dates and Times:");
            DateTime dt = new DateTime(2015, 10, 17);

            Console.WriteLine("The day of {0} is {1}", dt.Date, dt.DayOfWeek);

            dt = dt.AddMonths(2);
            Console.WriteLine("Dayling savings: {0}", dt.IsDaylightSavingTime());

            TimeSpan ts = new TimeSpan(4, 30, 0);
            Console.WriteLine(ts);

            Console.WriteLine(ts.Subtract(new TimeSpan(0,15,0)));
        }
        static void ParseFromStringsWithTryParse()
        {
            Console.WriteLine("=> Data type parsing with TryParse");

            if (bool.TryParse("False", out bool b))
            {
                Console.WriteLine("Value of b: {0}",b);
            }
            string value = "Hello";
            if (double.TryParse(value,out double d))
            {
                Console.WriteLine("Value of d: {0}",d);
            }
            else
            {
                Console.WriteLine("Failed to convert the input({0}) to a double",value);
            }
            Console.WriteLine();
        }
        static void ParseFromStrings()
        {
            Console.WriteLine("=> Data type parsing");
            bool b = bool.Parse("false");
            Console.WriteLine("Value of b: {0}",b);

            double d = double.Parse("89,352");
            Console.WriteLine("Value of d: {0}", d);

            int i = int.Parse("213");
            Console.WriteLine("Value of i: {0}", i);

            char c = char.Parse("w");
            Console.WriteLine("Value of c: {0}", c);
            Console.WriteLine();

        }
        static void CharFunctionality()
        {
            Console.WriteLine("=> char type functionality:");
            char myChar = 'a';
            Console.WriteLine("char.IsDigit(myChar) : {0}", char.IsDigit(myChar));
            Console.WriteLine("char.IsLetter(myChar) : {0}", char.IsLetter(myChar));
            Console.WriteLine("char.IsWhiteSpace('Hello there',5) : {0}", char.IsWhiteSpace("Hello there",5));
            Console.WriteLine("char.IsWhiteSpace('Hello there', 6) : {0}", char.IsWhiteSpace("Hello there", 6));
            Console.WriteLine("char.IsPunctuation('?') : {0}", char.IsPunctuation('?'));
            Console.WriteLine();
        }
        static void DataTypeFunctionality()
        {
            Console.WriteLine("=> Data type Functionality");

            Console.WriteLine("Max of int: {0}",int.MaxValue);
            Console.WriteLine("Min of int: {0}",int.MinValue);
            Console.WriteLine("Double.Epsilon: {0}",double.Epsilon);
            Console.WriteLine("double.PositiveInfinity: {0}", double.PositiveInfinity);
            Console.WriteLine("double.NegativeInfinity: {0}", double.NegativeInfinity);

            Console.WriteLine("bool.TrueString: {0}", bool.TrueString);
            Console.WriteLine("bool.FalseString: {0}", bool.FalseString);
            Console.WriteLine();

        }
        static void ObjectFunctionality()
        {
            Console.WriteLine("=> System.Object Functionality");

            Console.WriteLine("12.GetHashCode() = {0} ", 12.GetHashCode());
            Console.WriteLine("12.Equals(23) = {0} ", 12.Equals(23));
            Console.WriteLine("12.ToString() = {0}", 12.ToString());
            Console.WriteLine("12.GetType() = {0}", 12.GetType());
            Console.WriteLine();
        }
        static void NewingDataTypes()
        {
            Console.WriteLine("=> Using new to create variables ");

            bool b = new bool();
            int i = new int();
            double d = new double();
            DateTime dt = new DateTime();

            Console.WriteLine("{0},{1},{2},{3}", b, i, d, dt);
            Console.WriteLine();
        }
        static void DefaultDeclaration()
        {
            Console.WriteLine("=> Default Declaration:");
            int myInt = default;
            Console.WriteLine("Default int: {0}",myInt);
        }
        static void LocalVarDeclarations()
        {
            Console.WriteLine("=> Data Declarations");

            int myInt = 12;
            string myString = "this is my character data";

            bool b1 = true, b2 = false, b3 = b1;

            System.Boolean b4 = false;

            Console.WriteLine("Your data: {0},{1},{2},{3},{4},{5}",myInt,myString,b1,b2,b3,b4);
            Console.WriteLine();
        }
    }
    
}
