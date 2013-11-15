using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Review7
{
    class Program
    {
        static int giveNextNum(int num)
        {
            int num2 = num + 1;
            return num2;
        }
        static void Main(string[] args)
        {
            int num = 7;
            int newNum = giveNextNum(num);
            Console.Write(num);
        }
    }
}
