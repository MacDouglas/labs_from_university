using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InterfaceNameClash
{
    class Octagon : IDrawToMemory, IDrowToForm, IDrawToPrinter
    {
        void IDrowToForm.Draw()
        {
            Console.WriteLine("Drawing to form ...\n");
        }
        void IDrawToMemory.Draw()
        {
            Console.WriteLine("Drawing to memory\n");
        }
        void IDrawToPrinter.Draw()
        {
            Console.WriteLine("Drawing to Printer\n");
        }
        public void Draw()
        {
            Console.WriteLine("Drawing Octagon");
        }
    }
}
