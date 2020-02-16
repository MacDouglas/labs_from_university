using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using static System.Console;
using static System.DateTime;


namespace SimpleUntilityClass
{
    static class TimeUntilClass
    {
        public static void PrintTime() => WriteLine(Now.ToShortTimeString());
        public static void PrintData() => WriteLine(Today.ToShortDateString());
    }
}
