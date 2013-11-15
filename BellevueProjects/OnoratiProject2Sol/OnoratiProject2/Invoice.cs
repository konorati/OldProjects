// PROG 110, Fall 2012
// File: Invoice.cs
// Class: Invoice
// Author: Kristin Onorati
// Date: 10/15/12
using System;

namespace OnoratiProject2
{
    /* Purpose: This class creates an invoice for the user
     * based on their input
     */
    class Invoice
    {
        /* Method: Main 
         * Purpose: retrieves input from the user,
         * calculates cost based on the input, and creates and
         * displays an invoice based on the input.
         * 
         * Input: full name (string), shipping address (string), city (string), zip code (string), # of tribbles (int)
         * Output: Subtotal (string), tax (string), total (string), price (string)
         */
        static void Main(string[] args)
        {
            //Display an introduction
            Console.WriteLine("\n* Thank you for choosing Tribbles Habitat for Happiness! *");
            Console.WriteLine("* This program will create an invoice for your purchase  *");
            Console.WriteLine("----------------------------------------------------------");

            //Declare the needed variables
            string fullName, shippingAddress, city, state, zipCode, tribblesString, priceString, subtotalString, taxString, totalString;
            int tribbles = 0;
            double subtotal, tax, total, price;

            //Declare constant tax rate
            const double TAX_RATE = .089;
            const double HIGH_PRICE = 129.99;
            const double MED_PRICE = 89.45;
            const double LOW_PRICE = 65.00;

            //Ask for necessary customer information
            //Ask for full name
            Console.Write("\n\nEnter your full name: ");
            fullName = Console.ReadLine();
            
            //Ask for shipping address
            Console.Write("Enter your shipping street adress: ");
            shippingAddress = Console.ReadLine();
            
            //Ask for city
            Console.Write("Enter your city: ");
            city = Console.ReadLine();
            
            //Ask for state
            Console.Write("Enter your state <2 letter abbreviation>: ");
            state = Console.ReadLine();
            
            //Ask for zip code
            Console.Write("Enter your zip code: ");
            zipCode = Console.ReadLine();
            
            //Ask for # of tribbles
            Console.Write("Enter the number of tribbles you would like to purchase today: ");
            tribblesString = Console.ReadLine();

            //Assigns tribbles to 0 if not an int or to its numerical value if the string can be converted to an int
            int.TryParse(tribblesString, out tribbles); 
            
            //Determines if errors exist in user input
            if (fullName.Length == 0) //Reports error if user didn't enter a name
                Console.WriteLine("\nError: You did not enter your name\nPlease restart the program");

            else if (shippingAddress.Length == 0) //Reports error if user did not enter a shipping address
                Console.WriteLine("\nError: You did not enter your shipping address\nPlease restart the program");
            
            else if (city.Length == 0) //Reports error if user did not enter a city
                Console.WriteLine("\nError: You did not enter your city\nPlease restart the program");
            
            else if (state.Length != 2) //Reports error if user did not enter a 2 digit state code
                Console.WriteLine("\nError: You did not enter a valid 2 digit state code\nPlease restart the program");
            
            else if (zipCode.Length == 0) //Reports error if user did not enter a zip code
                Console.WriteLine("\nError: You did not enter your zip code\nPlease restart the program");
            
            else if (tribbles <= 0) //Reports error if user did not enter a valid number of tribbles
                Console.WriteLine("\nError: You did not enter a valid number of tribbles\nPlease restart the program");
            
            else //Continues on with program if no errors were found
            {
                //Clear screen
                Console.Clear();

                //Calculate price per tribble
                if (tribbles <= 5) //price for 1-5 tribbles
                    price = HIGH_PRICE;

                else if (tribbles > 12) //price for 13+ tribbles
                    price = LOW_PRICE;
                
                else //price for 6-12 tribbles
                    price = MED_PRICE;

                //Convert price to a string with a currency format
                priceString = price.ToString("C");

                //Give summary of number of tribbles ordered and price per tribble
                Console.WriteLine("\nYou ordered {0} tribbles at {1} per tribble", tribbles, priceString);

                //Convert state code to uppercase
                state = state.ToUpper();
                
                //Restate shipping address
                Console.WriteLine("\n\nYour tribbles will be shipped to:");
                Console.WriteLine("---------------------------------");
                Console.WriteLine("\t{0}", fullName);
                Console.WriteLine("\t{0}", shippingAddress);
                Console.WriteLine("\t{0}, {1}   {2}", city, state, zipCode);


                //Calculate subtotal, tax, total
                subtotal = price * tribbles;
                tax = subtotal * TAX_RATE;
                total = subtotal + tax;

                //Convert subtotal, tax, and total to strings in a currency format
                subtotalString = subtotal.ToString("C");
                taxString = tax.ToString("C");
                totalString = total.ToString("C");

                //Display subtotal, tax, total
                Console.WriteLine("\n\nSubtotal:" + "{0, 24}", subtotalString);
                Console.WriteLine("Tax Amount:" + "{0, 22}", taxString);
                Console.WriteLine("---------------------------------");
                Console.WriteLine("Total:" + "{0, 27}", totalString);
                

                //Give concluding remarks
                Console.WriteLine("\n\nThank you for purchasing from Tribbles Habitat for Happiness!");
                Console.WriteLine("Please think of us the next time you need cuddly tribbles!");
                Console.WriteLine("\t-Kristin Onorati");
            }
            //Allows user to exit the program
            Console.WriteLine("\nPress any key to exit the program");
            Console.ReadKey();
            
        }
    }
}
