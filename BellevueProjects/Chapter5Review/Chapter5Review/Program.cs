using System;

namespace Chapter5Review
{
    class Program
    {
        static void Main(string[] args)
        {
            int count = 0;
            do
            {
                count += 2;
                Console.Write("{0} ", count);
                
            } while (count < 10);
            string num;
            Console.Write("Enter a whole number: ");
            num = Console.ReadLine();
            while (int.Parse(num) < 70 || int.Parse(num) > 100)
            {
                Console.WriteLine("Number entered is not valid.");
                Console.Write("Enter a number between 70 and 100: ");
                num = Console.ReadLine();
            }
            count = 4;
            for (int ctrlVar = 1; ctrlVar <= count; ctrlVar++)
            {
                Console.WriteLine("Current value of ctrlVar is " + ctrlVar.ToString());
            }
            count = 4;
            int ctrlVar = 1;
            do
            {
                Console.WriteLine("Current value of ctrlVar is " + ctrlVar.ToString());
                ctrVar++;
            } while (ctrlVar <= count);
            Console.ReadKey();
        }
    }
}
