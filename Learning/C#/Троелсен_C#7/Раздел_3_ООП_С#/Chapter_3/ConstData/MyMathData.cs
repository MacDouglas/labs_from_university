﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConstData
{
    class MyMathClass
    {
        public static readonly double PI;
        static MyMathClass() {
            PI = 3.1418;
        }



    }
    class MyMathData
    {
        public const double PI = 3.14;
    }
}
