using System;
using System.Collections.Generic;
using System.Text;

namespace SimpleExeption
{
    class Radio
    {
        public void TurnON(bool on)
        {
            Console.WriteLine(on?" Jaming" : "Quiet time");
        }
    }
}
