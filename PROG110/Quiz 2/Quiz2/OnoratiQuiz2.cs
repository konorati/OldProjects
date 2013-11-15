/* PROG 110
 * Quiz 2
 * Date: 12/4/12
 * Kristin Onorati
 */

using System;

class Quiz2
{
    static void Main()
    {
        // Problem 1 -- enter the solution between the opening and closing brace
        {  /***************** start of problem 1  *******************/
            Console.WriteLine("\n\tProblem 1\n");
            const int SIZE = 25;
            int[] arrNum = new int[25];
            Random rand = new Random();

            for (int i = 0; i < arrNum.Length; i++)
            {
                arrNum[i] = rand.Next(1, 11);
            }

            int sum = 0;
            int index = 0;
            do {
                sum += arrNum[index];
                index++;
            } while (index < arrNum.Length);

            index = 0;
            int lowest = arrNum[index];
            while (index < arrNum.Length)
            {
                if (arrNum[index] < lowest)
                {
                    lowest = arrNum[index];
                }
                index++;
            }

            int numLowest = 0;
            foreach (int num in arrNum)
            {
                Console.Write("{0} ", num);
                if (num == lowest)
                {
                    numLowest++;
                }

            }

            Console.WriteLine("\nSum of values: {0}", sum);
            Console.WriteLine("Lowest value: {0} occurs {1} time(s).", lowest, numLowest);

        }  /***************** end of problem 1   *******************/



    // Problem 2 -- enter the solution between the opening and closing brace
        {      /***************** start of problem 2  *******************/
            Console.WriteLine("\n\tProblem 2\n");
            string[] arrSection = new string[] {"orchestra", "mezzanine", "general", "balcony"};
            double[] arrTicketPrice = new double[] {60.50, 41.75, 35.00, 25.25};

            string strSection = GetSection();
            int numTickets = GetNumberOfTickets();
            int section = -1;
            int index = 0;
            while (index < arrSection.Length)
            {
                if (strSection == arrSection[index])
                {
                    section = index;
                }
                index++;
            }

            if (section == -1)
            {
                Console.WriteLine("\nInvalid entry, {0} section does not exist.", strSection);
            }
            else
            {
                double cost = CalcTicketCost(numTickets, arrTicketPrice[section]);
                Console.WriteLine("\nTotal cost for the tickets are: {0}", cost.ToString("C"));
            }
           
        }   /******************** end of problem 2 *****************/


        // Problem 3 -- enter the solution between the opening and closing brace
        {  /***************** start of problem 3  *******************/
            Console.WriteLine("\n\tProblem 3\n");
            int num1, num2, num3;
            
            Console.Write("Enter number 1: ");
            string str1 = Console.ReadLine();
            int.TryParse(str1, out num1);

            Console.Write("\nEnter number 2: ");
            string str2 = Console.ReadLine();
            int.TryParse(str2, out num2);

            Console.Write("\nEnter number 3: ");
            string str3 = Console.ReadLine();
            int.TryParse(str3, out num3);

            int product = Product(num1, num2, num3);
            double division = Division(num2, num3);

            Console.WriteLine("The results of the two method calls are:\nProduct: {0}\nDivision: {1}", product.ToString("N0"), division.ToString("F2"));


        }    /******************** end of problem 3 *****************/


        // Optional Challenge -- enter the solution between the opening and closing brace
        {  /***************** start of Challenge  *******************/
            Console.WriteLine("\n\tChallenge\n");

            Console.Write("Enter your savings account balance: ");
            string strSavings = Console.ReadLine();
            double savings;
            double.TryParse(strSavings, out savings);

            double interestRate = savings > 10000 ? .04 : .02;
            double totInterest = interestRate * savings;

            Console.WriteLine("\nInterest of {0} was added to your balance of {1}", totInterest.ToString("N2"), savings.ToString("N2"));


        }    /******************** end of Challenge *****************/

 
        // call the pause method
        Pause();

    }   // end of Main


     /********** Define methods for Problem 2 below this line ********/
    //Prompt user for the seating section
    public static string GetSection()
    {
        Console.Write("What section would you like to sit in? ");
        string section = Console.ReadLine();
        return section;
    }

    //Prompt user for the number of tickets they want
    public static int GetNumberOfTickets()
    {
        Console.Write("How many tickets would you like to purchase? ");
        string strTickets = Console.ReadLine();
        return int.Parse(strTickets);
    }

    //Calculate total cost for ticket(s) and fees
    public static double CalcTicketCost(int numTickets, double costPerTicket)
    {
        const double FEE = 1.50;
        return (costPerTicket * numTickets) + FEE;
       
    }

    /********** Define methods for Problem 3 below this line ********/
    //Calculate the product of 3 numbers and return the value
    public static int Product(int number1, int number2, int number3)
    {
        return number1 * number2 * number3;
    }

    //Divide 2 numbers and return the result
    public static double Division(int dividend, int divisor)
    {
        double result = -999.99;
        if (divisor != 0)
        {
            result = ((double)dividend) / divisor;
        }
        return result;
    }



    /******** Do not write below this line   *********************
    /* Name of method: Pause
     * Purpose: to allow the console to wait for user input.
     * Input: none
     * Return: none
     */
    private static void Pause()
    {
        // pause
        Console.WriteLine("\n\tPress any key to end the program");
        Console.ReadKey();
    }

}

