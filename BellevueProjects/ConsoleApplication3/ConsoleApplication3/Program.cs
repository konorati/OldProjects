using System;


namespace Chapter6Review
{
    class Program
    {
        static void Main(string[] args)
        {
            /*int[] amount = new int[] { 2, 3, 4, 5 };
            for (int index = 0; index <= 3; ++index)
            {
                amount[index] *= 3;
                Console.Write(amount[index].ToString() + " ");
            }*/
            int[] pips = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
            for (int index = 0; index < pips.Length; index++)
            {
                pips[index] += 5;
            }
            foreach(int num in pips){
                Console.Write("{0} ", num);
            }
            Console.WriteLine();
            int[] numbers = new int[] { 2, 3, 4, 5 };
            for (int index = numbers.Length - 1; index >= 0; index--)
            {
                Console.Write("{0} ", numbers[index]);
            }
        }
    }
}
