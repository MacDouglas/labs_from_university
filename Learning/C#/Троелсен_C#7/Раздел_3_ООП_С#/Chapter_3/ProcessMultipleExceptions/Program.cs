﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ProcessMultipleExceptions
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("*** Fun with Handling Multiple Exeptions ***");
            Car myCar = new Car("Rusty", 90);
            myCar.Accelerate(2000);
            //try
            //{
            //    myCar.Accelerate(-10);
            //}
            //catch (CarIsDeadException ex)
            //when(ex.ErrorTimeStamp.DayOfWeek != DayOfWeek.Friday)
            //{
            //    FileStream fs = File.Open(@"C:\carErrors.txt", FileMode.Open);   
            //    Console.WriteLine(ex.Message);
            //}
            //catch(ArgumentOutOfRangeException e)
            //{
            //    Console.WriteLine(e.Message);
            //}
            //catch (Exception e)
            //{
            //    Console.WriteLine(e.Message);
            //}
            //finally
            //{
            //    myCar.CrankTunes(false);
            //}

            Console.ReadLine();
        }
    }
}
