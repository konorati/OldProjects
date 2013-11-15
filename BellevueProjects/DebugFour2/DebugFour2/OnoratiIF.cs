// Program asks user to enter three integers
// Program displays a message indicating whether the numbers
// are in sequential order
// in reverse order
// or in neither order
using System;
public class DebugFour2
{
    public static void Main()
    {
        //Declares variables
        int num1, num2, num3;
        string snum1, snum2, snum3;

        //Asks for first number from user
        Console.Write("Enter first number ");
        snum1 = Console.ReadLine();
        //Converts string to int
        num1 = Convert.ToInt32(snum1);

        //Asks for second number from user
        Console.Write("Enter second number ");
        snum2 = Console.ReadLine();
        //Converts string to int
        num2 = Convert.ToInt32(snum2);

        //Asks for third number from user
        Console.Write("Enter third number ");
        snum3 = Console.ReadLine();
        //Converts string to int
        num3 = Convert.ToInt32(snum3);

        //Determines if numbers are sequential
        if (num1 <= num2 && num2 <= num3)
            Console.WriteLine("Numbers are in sequential order");
        //Determines if numbers are reversed
        else if (num1 >= num2 && num2 >= num3)
            Console.WriteLine("Numbers are in reverse order");
        //Used if numbers are neither sequential or reversed
        else
            Console.WriteLine("Numbers are in neither sequential nor reverse order");

        Console.ReadKey();
    }
}
