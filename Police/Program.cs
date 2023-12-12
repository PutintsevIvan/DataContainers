using System;
using System.Collections.Generic;
using System.Linq;
using System.Management.Instrumentation;
using System.Text;
using System.Threading.Tasks;

namespace Police
{
    internal class Program
    {
        static void Main(string[] args)
        {
            #region CHECK
            //LicencePlate plate = new LicencePlate("m137bb");
            //Console.WriteLine(plate);
            /* Dictionary<int, string> pairs = new Dictionary<int, string>()
             {
                 [1]="Ремень безопасности",
                 [2] = "Превышение скорости"
             };
             Console.WriteLine(Violations.list.Count);
             Crime crime = new Crime(1, new DateTime(2023, 05, 23), "ул.Ленина");
             Console.WriteLine(crime);*/ 
            #endregion

            Dictionary<LicencePlate,List<Crime>>police_base = new Dictionary<LicencePlate, List <Crime>>()
            {
                [new LicencePlate ("m137nb")]=new List<Crime>()
                {
                    new Crime(1,new DateTime(2023,05,23,13,30,00),"ул.Ленина"),
                    new Crime(2,new DateTime(2023,05,23,13,33,00),"ул.Ленина")
                },

                [new LicencePlate("a001bb")]=new List<Crime>()
                {
                  new Crime(3,new DateTime(2023,06,12,19,02,00),"ул.Космонавтов"),
                  new Crime(4,new DateTime(2023,06,12,19,02,00),"ул.Космонавтов"),
                  new Crime(5,new DateTime(2023,06,12,19,02,00),"ул.Космонавтов"),
                },

                [new LicencePlate("a123bb")]=new List<Crime>()
                {
                    new Crime(6,new DateTime(2023,06,12,19,02,00),"ул.Парижской коммуны"),
                    new Crime(7,new DateTime(2023,06,12,19,02,00),"ул.Парижской коммуны"),
                    new Crime(8,new DateTime(2023,06,12,19,02,00),"ул.Шолома Алейхома"),
                }
            };
            #region PrinInMain
            /* for (
                 Dictionary<LicencePlate, List<Crime>>.Enumerator en = police_base.GetEnumerator();
                 en.Current.Key !=police_base.Last().Key;
                 en.MoveNext())
             {
                 Console.WriteLine(en.Current.Key);
             }*/
            /*  foreach(KeyValuePair<LicencePlate,List<Crime>> i in police_base)
               {
                   Console.WriteLine($"{i.Key}:\n");
                   foreach(Crime j in i.Value)
                   {
                       Console.WriteLine($"\t{j}");
                   }
                   Console.WriteLine(delimiter);
               }        
               string str = "Парковка в неполложенном месте";
               Console.WriteLine(str.Length);*/
            #endregion

            Base @base = new Base(police_base);
            @base.Print();
            @base.Save("base.txt");
        }
       
    }
}
