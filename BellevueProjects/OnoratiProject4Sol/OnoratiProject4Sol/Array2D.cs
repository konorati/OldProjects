// PROG 110, Fall 2012
// File: Array2D.cs
// Class: Array2D
// Author: Kristin Onorati
// Date: 11/14/12
using System;

namespace OnoratiProject4
{
    /* Purpose: This class creates table of the ages
     * of movie goers using a random number generator
     */
    class Array2D
    {
        /* Method: Main 
         * Purpose: Create and display a table of the ages of moviegoers
         * using a random number generator and calculate and display
         * the total age and average age.
         * Input: none
         * Output: ages of moviegoers, total age, mean age
         */
        static void Main(string[] args)
        {
            //Declare constants
            const int ROW = 10;
            const int COLS = 5;
            const int MAX = 100;

            //Introduction
            Console.WriteLine("This program will display a table showing the ages");
            Console.WriteLine("of {0} moviegoers on Thanksgiving day", ROW*COLS);
            Console.WriteLine("and display their total and average age.\n");

            string response;

            do
            {

                //Declare array
                int[,] numbers = new int[ROW, COLS];

                //Create random number generator
                Random rand = new Random();

                //Populate the 2D array using random number generator
                for (int row = 0; row < ROW; row++)
                {
                    for (int column = 0; column < COLS; column++)
                    {
                        numbers[row, column] = rand.Next(1, MAX);
                    }
                }

                //Calculate the total
                int total = 0;
                foreach (int num in numbers)
                {
                    total += num;
                }
                //Calculate the mean
                double mean = ((double)total / (ROW * COLS));

                //Display table title
                Console.WriteLine("** Ages of {0} moviegoers on Thanksgiving Day **\n", ROW*COLS);

                //Display table
                for (int row = 0; row < ROW; row++)
                {
                    for (int column = 0; column < COLS; column++)
                    {
                        Console.Write("{0,6:}", numbers[row,column]);
                    }
                    Console.WriteLine();
                }
                Console.WriteLine("\n  Sum: {0,0:N0}  Average: {1,0:N}\n", total, mean);

                Console.WriteLine("Would you like to see another table? <Y or N>: ");
                response = Console.ReadLine().ToUpper();
                while (response != "Y" && response != "N")
                {
                    Console.WriteLine("Response is not valid, please enter Y or N: ");
                    response = Console.ReadLine().ToUpper();
                }

            } while(response == "Y");

            Console.WriteLine("Thank you for using this program. Press any key to exit.");
            Console.ReadKey();
        }
    }
}
