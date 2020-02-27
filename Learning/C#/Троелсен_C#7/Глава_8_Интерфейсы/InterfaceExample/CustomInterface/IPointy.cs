
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CustomInterface
{
    public interface IPointy
    {
        //byte GetNumboerOfPoints();

        // Свойство, поддерживающее чтение и запись, в интерфейсе может выглядеть так:
        byte Points { get; }
    }
    public interface IDraw3D
    {
        void Draw3D();
    }
}
