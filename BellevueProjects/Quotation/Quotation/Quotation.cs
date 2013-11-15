// PROG 110, Fall 2012
// File: Quotation.cs
// Class: Quotation
// Author: Kristin Onorati
// Date: 9/25/12

using System;

 /* The purpose of this class is to present a quote from Albert Einstein and additional information
 * about both the quote and the author */
    public class Quotation
    {
        /* Method: Main
         * Purpose: This method with output text to the screen
         * Output: (String) Introduction, Quote, Author, Explanation, Final remarks */
        public static void Main()
        {
            //Display an introduction
            Console.WriteLine("This application will display the program creator's favorite quote \nand some information about that quote.");
            Console.WriteLine(); //This is a blank line

            //Display the quote
            Console.WriteLine("Quote: \"Great spirits have always found violent opposition from mediocrities." +
                                "\nThe latter cannot understand it when a man does not thoughtlessly submit to" +
                                "\nhereditary prejudices, but honestly and courageously uses his intelligence" +
                                "\nand fulfulls the duty to express the results of his thought in clear form.\"");
            Console.WriteLine(); //This is a blank line

            //Display the author
            Console.WriteLine("Author: Albert Einstein \nGerman born physicist [1879-1955]");
            Console.WriteLine(); //This is a blank line

            //Diplay quote explanation
            Console.WriteLine("I really enjoy this quote [and most other Albert Einstein quotes]" + 
                                "\nbecause it denounces mindless conformity and really pushes people to" +
                                "\nuse their ability to think independently and consider the honest facts." +
                                "\nThis quote is especially moving when you remember that it was said" +
                                "\nduring WWII which was a time of the most extreme hereditary prejudice.");
            Console.WriteLine(); //This is a blank line
           
            //Display source of quote
            Console.WriteLine("Source: New York Times, March 19th, 1940 \nretrieved from: www.quotationspage.com on September 25th, 2012");
            //Einstein, A. New York Times, March 19th, 1940. Retrieved September 25th, 2012 from www.quotationspage.com/quote/29604.html.
            Console.WriteLine(); //This is a blank line

            //Display final remarks
            Console.WriteLine("I hope you enjoyed this program created by Kristin Onorati \nPlease press enter to exit this application");
            Console.ReadLine(); //This is a blank line
        }
    }

