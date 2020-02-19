using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BasicStrings
{
    class Program
    {
        static void Main(string[] args)
        {
            //DigitSeparators();

            //BinaryLiterals();

            //BasicStringFunctionality();

            //StringConcatination();

            //EscapeChars();

            //StringEquality();

            //StringEqualitySpecifyingCompareRules();

            FunWithStringBuilder();

            Console.ReadLine();
        }
        static void StringInterpolation()
        {
            int age = 14;
            string name = "Elias";
            string greeting1 = string.Format("Hello {0} you are {1} years old?", name.ToUpper(), age+=2);
            string greeting2 = $"Hello {name.ToUpper()} you are {age += 1} years old?";
        }
        static void FunWithStringBuilder()
        {
            Console.WriteLine("=> Using the StringBuilder");
            StringBuilder sb = new StringBuilder("*** Fantastic book ***");
            sb.Append("\n");
            sb.AppendLine("C# 7.0");
            sb.AppendLine("123" + "456");
            Console.WriteLine("StringBuilder without ToString: {0}",sb);
            Console.WriteLine(sb.ToString());
            sb.Replace("4", "Jopa");
            Console.WriteLine(sb.ToString());
            Console.WriteLine("SB has {0} chars",sb.Length);
            Console.WriteLine();


        }
        static void StringEqualitySpecifyingCompareRules()
        {
            Console.WriteLine("=> String equality (Case Insensitive:");
            string s1 = "Hello!";
            string s2 = "HELLO!";
            Console.WriteLine("s1 = {0}",s1);
            Console.WriteLine("s2 = {0}",s2);
            Console.WriteLine();

            Console.WriteLine("Default rules: s1={0},s2={1} s1.Equals(s2): {2}",s1,s2,s1.Equals(s2));
            Console.WriteLine("Ignore case: s1.Equals(s2,StringComparison.OrdinalIgnoreCase : {0}",
                s1.Equals(s2,StringComparison.OrdinalIgnoreCase));
            
            Console.WriteLine("Ignore case, Invarariant Culture:" +
            "s1.Equals(s2, StringComparison.InvariantCultureIgnoreCase) : {0}",
            s1.Equals(s2, StringComparison.InvariantCultureIgnoreCase) ) ;
            Console.WriteLine();

            Console.WriteLine("Default rules: s1={0},s2={1} s1.IndexOf(\"E\"): {2}", 
                s1, s2, s1.IndexOf("E"));
            
            Console.WriteLine("Ignore case: s1.IndexOf(\"E\",StringComprison.OrdinalIgnoreCase) : {0}",
                s1.IndexOf("E", StringComparison.OrdinalIgnoreCase));
            
            Console.WriteLine("Ignore case, Invarariant Culture: si.IndexOf(\"E\",StringComparison.InvanantCulturelgnoreCase) : {0}",
                s1.IndexOf("E", StringComparison.InvariantCultureIgnoreCase));
            Console.WriteLine();
        }
        static void StringEquality()
        {
            Console.WriteLine("=>String equality:");
            string s1 = "Hello";
            string s2 = "Yo!";
            Console.WriteLine("s1 = {0}",s1);
            Console.WriteLine("s2 = {0}",s2);
            Console.WriteLine();

            Console.WriteLine("s1 == s2: {0}",s1==s2);
            Console.WriteLine("s1 == Hello: {0}",s1 == "Hello");
            Console.WriteLine("s1 == HELLO: {0}",s1 == "HELLO");
            Console.WriteLine("s1 == hello: {0}",s1 == "hello");
            Console.WriteLine("s1.Equals(s2): {0}",s1.Equals(s2));
            Console.WriteLine("Yo!.Equals(s2): {0}","Yo!".Equals(s2));
            Console.WriteLine();
        }
        static void EscapeChars()
        {
            Console.WriteLine("=> Escape characters:\a");
            string strWithTabs = "Model\tColor\tSpeed\tPet Name\a";
            Console.WriteLine(strWithTabs);
            Console.WriteLine("Everyone loves \"Hello wolrd\"\a");
            Console.WriteLine("C:\\MyApp\\bin\\Debug\a");

            Console.WriteLine("All finished.\n\n\n\a");

            // Следующая строка воспроизводится дословно,
            // так что отображаются все управляющие символы.
            Console.WriteLine(@"С:\MyApp\bin\Debug");
            
            string myLongString = @"This is a very
                very
                    very
                        long string";
            Console.WriteLine(myLongString);

            Console.WriteLine(@"Cerebus said ""Darrr! Pret - ty sun - sets""");

            Console.WriteLine();
        }
        static void StringConcatination()
        {
            Console.WriteLine("=> String Concatination");
            string s1 = "Programming the";
            string s2 = "PsychoDrill (PTR)";
            string s3 = s1 + s2;
            Console.Write(s3);
            Console.WriteLine();
        }
        static void BasicStringFunctionality()
        {
            Console.WriteLine("=> Basic string Functionality");
            string firstName = "Freddy";
            Console.WriteLine("Value of firstName: {0}",firstName);
            Console.WriteLine("firstName has {0} characters.", firstName.Length);
            Console.WriteLine("firstName in uppercase: {0}",firstName.ToUpper());
            Console.WriteLine("firstName in lowercase: {0}",firstName.ToLower());
            Console.WriteLine("firstName contains the letter y? : {0}",firstName.Contains("y"));
            Console.WriteLine("firstName after replace: {0}",firstName.Replace("dy",""));
            Console.WriteLine("Value of firstName: {0}", firstName);
            Console.WriteLine();
        }
        private static void BinaryLiterals()
        {
            Console.WriteLine("=> Use Binary Literals:");
            Console.WriteLine("16: {0}",0b0001_0000);
            Console.WriteLine("32: {0}", 0b0010_0000);
            Console.WriteLine("64: {0}", 0b0100_0000);
        }
        static void DigitSeparators()
        {
            Console.WriteLine("=> Use Digit separators: ");
            Console.Write("Integer:");
            Console.WriteLine(123_456);
            Console.Write("Long:");
            Console.WriteLine(123_456_1234L);
            Console.Write("Float:");
            Console.WriteLine(123_456.1234F);
            Console.Write("Double:");
            Console.WriteLine(123_456.123);
            Console.Write("Decimal:");
            Console.WriteLine(123_456.12M);

        }
        
    }
}
