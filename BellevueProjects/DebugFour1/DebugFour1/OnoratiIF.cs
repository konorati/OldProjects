//Kristin Onorati
//PROG 110
//DebugFour1

// Program takes a hot dog order
// And determines price
using System;
public class DebugFour1
{
    public static void Main()
   {
      //Declares the variables and constants
      const double BASIC_DOG_PRICE = 2.00;
      const double CHILI_PRICE = 0.69;
      const double CHEESE_PRICE = 0.49;
      String wantChili, wantCheese;          
      double price;
     
      //Asks user if they want chili and/or cheese on their hotdog  
      Console.Write("Do you want chili on your dog? (Y/N) ");
      wantChili = Console.ReadLine();
      Console.Write("Do you want cheese on your dog? (Y/N) ");
      wantCheese = Console.ReadLine();

      //Determines price if they want chili and cheese on their hotdog
      if (wantChili == "Y" && wantCheese == "Y")
              price = BASIC_DOG_PRICE + CHILI_PRICE + CHEESE_PRICE;
      //Determines price if they just want chili on their hotdog
      else if (wantChili == "Y")
              price = BASIC_DOG_PRICE + CHILI_PRICE;
      //Determines price if they just want cheese on their hotdog
      else if (wantCheese == "Y")
          price = BASIC_DOG_PRICE + CHEESE_PRICE;
      //Determines price if they don't want chili and they don't want cheese on their hotdog
      else
          price = BASIC_DOG_PRICE;

      //Gives user their total price
      Console.WriteLine("Your total is {0}", price.ToString("C"));
      Console.ReadKey();
   }
}
