using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace BinaryTree
{
    internal class TreePreformance<T>
    {
        public delegate T Method();
        public static void Measure(string message,Method method)
        {
            Stopwatch sw = new Stopwatch();
            sw.Start();
            T value = method();
            sw.Stop();
            Console.WriteLine($"{message.PadRight(42)} {value.ToString().PadLeft(12)},вычесленно за{sw.Elapsed.ToString(/*"ss\\fffffff"*/)}Секунд.");

        }
    }
}
