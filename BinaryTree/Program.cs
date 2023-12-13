#define BASE_CHECK
//#define ERASE_CHECK
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace BinaryTree
{
    internal  class Program
    {
        static  void Main(string[] args)
        {
#if BASE_CHECK
            Random random = new Random(0);
            Console.WriteLine("Введите размер дерева:");
            int n = Convert.ToInt32(Console.ReadLine());
            Tree tree = new Tree();
            for (int i = 0; i<n; i++)
            {
                tree.Insert(random.Next(100));
            }
            //tree.Print();
            //tree.Clear();
            Stopwatch sw = new Stopwatch();
            try
            {
                sw.Start();
                Console.WriteLine($"Минимальное значение в дереве:{tree.MinValue()}");
                sw.Stop();
                Console.WriteLine($"Вычесленно за :{sw.Elapsed}");
                //Console.WriteLine($"Максимальное значение в дереве:{tree.MaxValue()}");
                //Console.WriteLine($"Сумма элементов дерева:{tree.Sum()}");
                //Console.WriteLine($"Количество элементов дерева:{tree.Count()}");
                //Console.WriteLine($"средне-арифметическое элементов дерева:{tree.Avarage()}");
                //Console.WriteLine($"Глубина дерева:{tree.Depth()}");
                Console.Write("Введите удаляемое значение:");
                TreePreformance<int>.Measure("Максимальное значение в дереве: ", tree.MaxValue);
                TreePreformance<int>.Measure("Сумма элементов дерева:", tree.Sum);
                TreePreformance<int>.Measure("Количество элементов дерева:", tree.Count);
                TreePreformance<double>.Measure("Среднее-арифметическое элементов дерева:", tree.Avarage);
                TreePreformance<int>.Measure("Глубина дерева:", tree.Depth);
                int value = Convert.ToInt32(Console.ReadLine());
                tree.Erase(value);
                tree.Print();

            }
            catch (Exception e)
            {

                Console.WriteLine(e.Message);
            } 
            Console.WriteLine($"Количество элементов дерева:{tree.Count()}");


            UniqueTree u_tree = new UniqueTree();
            for (int i = 0; i<n; i++)
            {
                u_tree.Insert(random.Next(100));
            }
            u_tree.Print();
            tree.Clear();
            Console.WriteLine($"Минимальное значение в дереве:{u_tree.MinValue()}");
            Console.WriteLine($"Максимальное значение в дереве:{u_tree.MaxValue()}");
            Console.WriteLine($"Сумма элементов дерева:{u_tree.Sum()}");
            Console.WriteLine($"Количество элементов дерева:{u_tree.Count()}");
            Console.WriteLine($"средне-арифметическое элементов дерева:{u_tree.Avarage()}");

#endif
#if ERASE_CHECK
            Tree tree = new Tree(50, 25, 75, 16, 32, 64, 80,17);
            tree.Print();
            Console.WriteLine($"Глубина дерева:{tree.Depth()}");
            Console.Write("Введите удаляемое значение: ");
            int value = Convert.ToInt32(Console.ReadLine());
            tree.Erase(value);
            tree.Print(); 
#endif
        }
    }
}
