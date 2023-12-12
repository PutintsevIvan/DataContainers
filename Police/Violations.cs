using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Police
{
     internal class Violations
    {
        public static readonly Dictionary<int, string> list = new Dictionary<int, string>()
        {
            [0]="N/A",
            [1]="Парковка в неполложенном месте",
            [2]="Ремень безопасности",
            [3]="Пересечение сплошной",
            [4]="Превышение скорости",
            [5]="Проезд на красный",
            [6]="Езда в не трезвом состоянии",
            [7]="Оскорбление офицера",
            [8]="Сопротивление при аресте",
            [9]="Не пропустил пешехода",
            [10]="Езда по встречной полосе",
            [11]="Нарушение переезда ж/д путей",
            [12]="Оставление места ДТП"
        };
        
    }
}
