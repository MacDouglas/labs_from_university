using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InterfaceNameClash
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("*** Fun with intarface name calshes ***\n");
            Octagon oct = new Octagon();

            IDrowToForm idtf = (IDrowToForm)oct;
            idtf.Draw();

            IDrawToMemory idtm = (IDrawToMemory)oct;
            idtm.Draw();

            IDrawToPrinter idtp = (IDrawToPrinter)oct;
            idtp.Draw();

            ((IDrowToForm)oct).Draw();

            if (oct is IDrawToPrinter dp)
                dp.Draw();

            Console.ReadLine();
        }
    }
}
