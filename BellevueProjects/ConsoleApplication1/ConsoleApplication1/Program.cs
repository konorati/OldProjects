//use for Chapter 4A Review
using System;
public class CompareNumbers
{
    public static void Main()
    {
        //declare variables
        string userInput;
        int ans1, ans2, ans3;

        //get data from the user and convert appropriately
        Console.Write("Enter an integer ");
        userInput = Console.ReadLine();
        ans1 = Convert.ToInt32(userInput);

        Console.Write("Enter an integer ");
        userInput = Console.ReadLine();
        ans2 = Convert.ToInt32(userInput);

        Console.Write("Enter an integer ");
        userInput = Console.ReadLine();
        ans3 = Convert.ToInt32(userInput);

        // start the process flow
        // if first 2 numbers are the same
        if (ans1 == ans2) 
        {
            // if first 2 numbers and second 2 numbers are the same
            if (ans2 == ans3) 
                Console.WriteLine("All three numbers are the same");

           //if only the first 2 numbers are the same
            else 
                Console.WriteLine("The first two numbers are the same");
        }
        //if only the second 2 numbers are the same
        else if (ans2 == ans3) 
            Console.WriteLine("The last two numbers are the same");

        //if only the first and last numbers are the same
        else if (ans1 == ans3) 
            Console.WriteLine("The first and last numbers are the same");

        //if none of the numbers are the same
        else 
            Console.WriteLine("No two numbers are the same");
    }
}