/* PROG 110
 * Quiz 1
 * Kristin Onorati
 * 10/27/12
 */

using System;

class Quiz1
{
    static void Main()
    {
        // Problem 1 -- enter the solution between the opening and closing brace
        {// start of problem 1
            int units;
            double payPerUnit, totalPay;
            string strUnits;
            
            Console.WriteLine("\n\tProblem 1\n");
            Console.Write("\nEnter the number of units produced: ");
            strUnits = Console.ReadLine();
            units = int.Parse(strUnits);

            if (units >=1 && units < 200)
                payPerUnit = 12.50;
            else if (units >= 200 && units < 400)
                payPerUnit = 23.55;
            else if (units >= 400 && units < 600)
                payPerUnit = 34.75;
            else
                payPerUnit = 56.25;

            totalPay = payPerUnit * units;

            Console.WriteLine("{0} units at {1:F}, you earned {2:C}.", units, payPerUnit, totalPay);

        } // end of problem 1



        // Problem 2 -- enter the solution between the opening and closing brace
        {// start of problem 2
            int units;
            double payPerUnit, totalPay;
            string strUnits;

            Console.WriteLine("\n\tProblem 1\n");
            Console.Write("\nEnter the number of units produced: ");
            strUnits = Console.ReadLine();
            units = int.Parse(strUnits);

            if (units < 200)
                payPerUnit = 12.50;
            else if (units < 400)
                payPerUnit = 23.55;
            else if (units < 600)
                payPerUnit = 34.75;
            else
                payPerUnit = 56.25;

            totalPay = payPerUnit * units;

            Console.WriteLine("{0} units at {1:F}, you earned {2:C}.", units, payPerUnit, totalPay);

        }// end of problem 2



        // Problem 3 -- enter the solution between the opening and closing brace
        {// start of problem 3
            int groupID;
            string strGroupID = "", animalFam = "", commonName = "";
            bool notValid = false;
            
            Console.WriteLine("\n\tProblem 3\n");
            Console.Write("\nEnter the group identification: ");
            strGroupID = Console.ReadLine();
            groupID = int.Parse(strGroupID);

            switch (groupID)
            {
                case 15:
                    animalFam = "Felidae";
                    commonName = "Cat";
                    break;
                case 25:
                    animalFam = "Canidae";
                    commonName = "Dog";
                    break;
                case 30:
                    animalFam = "Mustelidae";
                    commonName = "Ferret";
                    break;
                case 35:
                    animalFam = "Cricetinae";
                    commonName = "Hamster";
                    break;
                default:
                    notValid = true;
                    break;
            }
            if (notValid)
                Console.WriteLine("Group ID {0} is an Invalid Identification", groupID);
            else
                Console.WriteLine("Group ID {0} is transcribed to {1} - {2}", groupID, animalFam, commonName);

        }// end of problem 3



        // Problem 4 -- enter the solution between the opening and closing brace
        {// start of problem 4

            const string GREETING = "Hello";
            string lastName, gender, title;
            

            Console.WriteLine("\n\tProblem 4");
            Console.Write("\nEnter your last name: ");
            lastName = Console.ReadLine();
            Console.Write("Enter your gender <M or F>: ");
            gender = Console.ReadLine();

            if (gender.ToUpper() != "M" && gender.ToUpper() != "F")
                Console.WriteLine("You must enter an M or an F.");
            else {
                if (gender.ToUpper() == "M")
                    title = "Mr.";
                else 
                    title = "Ms.";
                Console.WriteLine("{0} {1} {2}", GREETING, title, lastName);
            }
            
                

           

        }// end of problem 4


        // Problem 5 -- rewrite the solution in the appropriate location
        {// start of problem 5
            const string SECRET_WORD = "enterprise";
            string guess;
            
            Console.WriteLine("\n\tProblem 5");
            Console.Write("\nEnter a word: ");
            guess = Console.ReadLine();

            if (guess.ToLower() == SECRET_WORD)
                Console.WriteLine("You guessed it!");
            else
                Console.WriteLine("You guessed incorrectly");


        }// end of problem 5


        // Challenge -- enter the solution between the opening and closing brace
        //                      only if you have time, this will not count against you
        {// start of Challenge 
            string strNum1, strNum2;
            int num1, num2;
            string result;

            Console.WriteLine("\n\tChallenge\n");
            Console.Write("\nEnter an integer value: ");
            strNum1 = Console.ReadLine();
            Console.Write("Enter a second integer value: ");
            strNum2 = Console.ReadLine();

            num1 = int.Parse(strNum1);
            num2 = int.Parse(strNum2);

            result = num1 < num2 ? "<" :">=";

            Console.WriteLine("{0} {1} {2}", num1, result, num2);


        }// end of Challenge


        // pause
        Console.WriteLine("\n\tPress any key to end the program");
        Console.ReadKey();

    }
}

