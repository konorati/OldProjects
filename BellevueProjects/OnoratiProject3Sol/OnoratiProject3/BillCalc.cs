// PROG 110, Fall 2012
// File: BillCalc.cs
// Class: BillCalculator
// Author: Kristin Onorati
// Date: 10/29/12
using System;

namespace OnoratiProject3
{
    /* Purpose: This class creates a bill for the user
     * based on their input
     */
    class BillCalculator
    {
        /* Method: Main 
         * Purpose: retrieves input from the user,
         * calculates bill based on the input, and creates and
         * displays a bill and tipping table based on the input.
         * 
         * Input: cost of meals (string), cost of beverages (string), number of diners (string)
         * Output: Subtotal, total tax, total, cost per diner, total tip amount, total cost with tip, tip amount per diner
         */
        static void Main(string[] args)
        {
            string response, strFood, strBeverages, strDiners;
            double food, beverages;
            int diners;
            const double TAX = .089;

            do
            {   //Introduction
                Console.WriteLine("     *** Welcome to the Klingon Kafe ***");
                Console.WriteLine("Enter the information for your table and this program \nwill calculate the totals for your bill.\n");

                //Get user input for the food cost and validate the info.
                do
                {
                    Console.Write("\nEnter the total cost for all the meals: ");
                    strFood = Console.ReadLine();
                    if (strFood.Length == 0 || double.Parse(strFood) < 0 )
                        Console.WriteLine("Cost must be a positive number.");
                } while (strFood.Length == 0 || double.Parse(strFood) < 0);

                //Get user input for the beverage cost and validate the info.
                do
                {
                    Console.Write("\nEnter the total cost for all the beverages: ");
                    strBeverages = Console.ReadLine();
                    if (strFood.Length == 0 || double.Parse(strBeverages) < 0)
                        Console.WriteLine("Cost must be a positive number.");
                } while (strFood.Length == 0 || double.Parse(strBeverages) < 0);
                
                //Get user input for total number of diners and validate the info.
                do
                {
                    Console.Write("\nEnter the number of diners: ");
                    strDiners = Console.ReadLine();
                    if (strDiners.Length == 0 || int.Parse(strDiners) < 1)
                        Console.WriteLine("Number of diners must be greater than 0.");
                } while (strDiners.Length == 0 || int.Parse(strDiners) < 1 );

                //Convert strings to usable doubles and ints
                food = double.Parse(strFood);
                beverages = double.Parse(strBeverages);
                diners = int.Parse(strDiners);

                Console.WriteLine("\nThank you for entering the information,");
                Console.Write("press any key to see the calculations.");
                Console.ReadKey();
                Console.Clear();

                //Calculate bill information
                double subtotal, taxTotal, totalCost, costPerDiner;
                subtotal = food + beverages;
                taxTotal = subtotal * TAX;
                totalCost = subtotal + taxTotal;
                costPerDiner = totalCost / diners;

                //Display calculated bill
                Console.WriteLine("********** Table Amounts **********");
                Console.WriteLine("Food       Beverages   No of Diners");
                Console.WriteLine(String.Format("{0,-11:N}{1,-12:N}{2}", food, beverages, diners));
                Console.WriteLine("\nSubtotal:{0,21:C}", subtotal);
                Console.WriteLine("Taxes @ {0:P}:{1,15:N}", TAX, taxTotal);
                Console.WriteLine("Total Cost:{0,19:N}", totalCost);
                Console.WriteLine("$ per diner:{0,18:N}", costPerDiner);

                //Calculate and display tip table
                Console.WriteLine("\n            Tipping Table");
                for(int i = 1; i <=38; i++) //Underlines the table title
                    Console.Write("-");
                Console.WriteLine("\nTip%  Tip Amt  Total Cost  $ Per Diner");
                for (double i = .1; i <= .25; i += .05) //Calculates and displays the tip amounts
                {
                    double tipAmount = totalCost * i;
                    double totalWithTip = totalCost + tipAmount;
                    Console.WriteLine("{0}{1,-4}{2,7:N}{3,12:N}{4,13:N}", i*100, "%",tipAmount, totalWithTip, totalWithTip / diners);
                }
                
                //Ask user if they want to run another scenario and validate the input
                Console.Write("\nWould you like to run another scenario? <Y or N>: ");
                response = Console.ReadLine().ToUpper();
                while (response != "Y" && response != "N")
                {
                    Console.Write("Input is invalid please enter Y or N: ");
                    response = Console.ReadLine().ToUpper();
                }
                if (response == "Y")//Clear console if user want to rerun the program
                    Console.Clear();
            //if user wants to run another scenario rerun the program
            } while (response == "Y");
        }
    }
}
