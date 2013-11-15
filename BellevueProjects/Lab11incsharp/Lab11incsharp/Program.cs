using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Lab11incsharp
{
    class Program
    {
        static void Main(string[] args)
        {
            int[,] list = new int[10, 10];
            int[] list2 = new int[] {0, 0, 1, 2, 5, 6, 7, 9, 9, 11};
            Random rand = new Random();
            /*for (int i = 0; i < 20; i++)
            {
                list2[i] = rand.Next(-20, 20);
                Console.Write("{0} ", list2[i]);
            }*/
            /*int age;
            string strAge;
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    list[i, j] = i;
                    Console.Write(list[i,j] + " ");
                }
                Console.WriteLine();
            }
            do
            {
                Console.Write("Enter your age: ");
                strAge = Console.ReadLine();

            } while (!(int.TryParse(strAge, out age)));

            Console.WriteLine("Age is {0}", age);

            int end = 19, temp = 0;*/
           
            //Bubble sort
            /*for(int i = 0; i<end; end--){
                for (int start = 0; start < end; start++)
                {
                    if (list2[start] > list2[start + 1])
                    {
                        temp = list2[start];
                        list2[start] = list2[start + 1];
                        list2[start + 1] = temp;
                    }
                }
            }*/
            //Selection Sort
            /*int last = list2.Length;
            for (int i = 1; i < last; last--)
            {
                int largest = list2[0], index = 0;
                for (int j = 0; j < last; j++)
                {
                    if (largest < list2[j])
                    {
                        largest = list2[j];
                        index = j;
                    }
                }
                list2[index] = list2[last - 1];
                list2[last - 1] = largest;
            }
            Console.WriteLine("New list:");
            for (int i = 0; i < 20; i++)
            {
                Console.Write("{0} ", list2[i]);
            }*/
            //Binary search
            int begin = 0, end = list2.Length - 1, mid = 0, value = 12;
            bool found = false;
            while (begin <= end && !found)
            {
                mid = (end + begin) / 2;
                if (list2[mid] == value)
                {
                    found = true;
                }
                else if (value < list2[mid])
                {
                    end = mid - 1;
                }
                else
                {
                    begin = mid + 1;
                }
            }
            if (found)
            {
                Console.WriteLine("Value found at position {0}", mid + 1);
            }
            else
            {
                Console.WriteLine("Value not found");
            }
        }
    }
}
