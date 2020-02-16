using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FunWithMethods
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("*** Fun with Methods ***");
            //int x = 10, y = 9;
            //Console.WriteLine("Before call: X: {0}, Y: {1}",x,y);
            //Console.WriteLine("Answer is: {0}",Add(x,y));
            //Console.WriteLine("After call: X: {0}, Y: {1}",x,y);

            //int ans;
            //Add(90, 90, out ans);
            //Console.WriteLine("90 + 90 = {0}", ans);

            //int i;string s;bool b;
            //FillThisValues(out i, out s,out b);
            //Console.WriteLine("Int i is {0}",i);
            //Console.WriteLine("String s is {0}", s);
            //Console.WriteLine("Bool b is {0}", b);

            //string s1 = "Hello ", s2 = "World";
            //Console.WriteLine("Before call: S1: {0}, S1: {1}",s1,s2);
            //SwapStrings(ref s1,ref s2);
            //Console.WriteLine("After call: S1: {0}, S1: {1}", s1, s2);

            //string[] str = {"One","two","three"};
            //Console.WriteLine("Before call: \n {0}\t{1}\t{2}",str[0],str[1],str[2]);
            //ref var refOutput = ref SampleRefReturn(str, 1);
            //refOutput = "New";
            //Console.WriteLine("After call: \n {0}\t{1}\t{2}", str[0], str[1], str[2]);ъ

            //double avarage = CalculateAverage(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
            //Console.WriteLine("Avarage of data is: {0}",avarage);

            //double[] data = { 1, 2, 3, 4, 5, 6, 7 };
            //avarage = CalculateAverage(data);
            //Console.WriteLine("Avarage of data is: {0}", avarage);

            //Console.WriteLine("Avarage of data is: {0}", CalculateAverage());

            DisplayFuncMessage(message: "Wow!", textColor: ConsoleColor.DarkRed, backgroundColor: ConsoleColor.DarkBlue);
            DisplayFuncMessage(backgroundColor: ConsoleColor.DarkCyan,message: "Wow!", textColor: ConsoleColor.Magenta);


            Console.ReadLine();
        }
        static void DisplayFuncMessage(ConsoleColor textColor, ConsoleColor backgroundColor,string message)
        {
            ConsoleColor oldTextColor = Console.ForegroundColor;
            ConsoleColor oldBackgroundColor = Console.BackgroundColor;

            Console.ForegroundColor = textColor;
            Console.BackgroundColor = backgroundColor;
            Console.WriteLine(message);

            Console.ForegroundColor = oldTextColor;
            Console.BackgroundColor = oldBackgroundColor;
        }

        static double CalculateAverage(params double[] value)
        {
            Console.WriteLine("You set me {0} doubles ", value.Length);

            double sum = 0;
            if (value.Length == 0)
                return sum;
            else
                for (int i = 0; i < value.Length; i++)
                {
                    sum += value[i];
                }
            return sum / value.Length;
        }
        public static ref string SampleRefReturn(string[] str,int pos)
        {
            return ref str[pos];
        }
        public static void SwapStrings(ref string s1,ref string s2)
        {
            string tempStr = s1;
            s1 = s2;
            s2 = tempStr;
        }
        static void FillThisValues(out int a,out string b, out bool c)
        {
            a = 9;
            b = "Hello world!";
            c = false;
        }

        static void Add(int x, int y, out int ans)
        {
            ans = x + y;
        }

        //static void Add(int x, int y, out int ans) => ans = x + y;
 
        static int Add(int x,int y)
        {
            int sum = x + y;
            x = 9999;
            y = 8888;

            return sum;
        }
    }
}
