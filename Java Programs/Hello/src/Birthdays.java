//Kristin Onorati
//CS 210
//Project 3
import java.util.*;

public class Birthdays {

	/**This class retrieves 2 birthdays from the user and 
	 * determines the absolute day of the year their birthday
	 * falls on, how many days until their next birthday, what
	 * percent of year until their next birthday, and whose 
	 * birthday comes first. It also displays a fun fact about 
	 * my birthday (January 11th).
	 */
	public static final int MONTH_TODAY = 1; //Class constant for todays month
	public static final int DAY_TODAY = 1; //Class constant for todays day
	public static final int YEAR_TODAY = 2012; //Class constant for todays year
	
	//Main method uses static methods to get birthdays, print info about the
	//birthdays, and compare the birthdays.
	public static void main(String[] args) {
		// 
		int absoluteBDay1, absoluteBDay2, absoluteDayNow, 
			daysUntilNextBDay1, daysUntilNextBDay2;
		Scanner console = new Scanner(System.in);
		
		//Calls method to find absolute day for todays date
		absoluteDayNow = absoluteDay(MONTH_TODAY, DAY_TODAY); 
				
		//Calls method to display introduction
		intro(absoluteDayNow); 
	
		//Retrieve and print info for person 1
		absoluteBDay1 = getBirthday(console, 1);
		daysUntilNextBDay1 = untilNextBirthday(absoluteDayNow, absoluteBDay1);
		printBirthdayInfo(absoluteBDay1, absoluteDayNow, daysUntilNextBDay1, 1);
		
		//Retrieve and print info for person 2
		absoluteBDay2 = getBirthday(console, 2);
		daysUntilNextBDay2 = untilNextBirthday(absoluteDayNow, absoluteBDay2);
		printBirthdayInfo(absoluteBDay2, absoluteDayNow, daysUntilNextBDay2, 2);
		
		//Calls method to compare birthdays of person 1 and person 2
		compareBirthdays(daysUntilNextBDay1, daysUntilNextBDay2);
		
		//Calls method to display fun birthday fact
		birthdayFact();
		
	}
	//Determines the absolute day of the year
	public static int absoluteDay(int month, int day) {
		int absoluteDay = 0;
		
		for (int i = 1; i < month; i++){
			absoluteDay += daysInMonth(i);
		}
		absoluteDay += day;
		
		return absoluteDay;
	}
	//Returns the number of days in any particular month
	public static int daysInMonth(int month){
		int numDays = 0;
		
		if(month == 1)
			numDays = 31;
		else if(month == 2)
			numDays = 29;
		else if (month == 3)
			numDays = 31;
		else if (month == 4)
			numDays = 30;
		else if (month == 5)
			numDays = 31;
		else if (month == 6)
			numDays = 30;
		else if (month == 7)
			numDays = 31;
		else if (month == 8)
			numDays = 31;
		else if (month == 9)
			numDays = 30;
		else if (month == 10)
			numDays = 31;
		else if (month == 11)
			numDays = 30;
		else if (month == 12)
			numDays = 31;
		
		return numDays;
	}
	//Calculates and prints days until next birthday and percent
	//of a year until next birthday
	public static int untilNextBirthday(int absoluteDayNow, int absoluteBDay){
		
		int daysUntilNextBDay = 0;
		
		if (absoluteDayNow < absoluteBDay) {
			daysUntilNextBDay = absoluteBDay - absoluteDayNow;
		}
		else if (absoluteDayNow > absoluteBDay ){
			daysUntilNextBDay = (366 - absoluteDayNow) + absoluteBDay;
		}
		return daysUntilNextBDay;
	}
	//Finds month, day, and year from absoluteBDay
	public static void birthdayDate(int absoluteBDay, int absoluteDayNow){
		int month;
		int day = absoluteBDay;
		
		for(month = 1; daysInMonth(month) < day; month++)
			day -= daysInMonth(month);
		
		System.out.print(month + "/" + day + "/" + YEAR_TODAY);
		
	}
	//Prints info about the persons birthday
	public static void printBirthdayInfo(int absoluteBDay, int absoluteDayNow, 
				int daysUntilNextBDay, int person){
		
		double percentOfYear = (daysUntilNextBDay/366.0)*100;
		
		birthdayDate(absoluteBDay, absoluteDayNow);
		System.out.println(" falls on day #" + absoluteBDay + " of 366.");
		System.out.println("Your next birthday is in " + daysUntilNextBDay + " day(s).");
		if (daysUntilNextBDay != 0){
			System.out.print("That is ");
			System.out.printf("%.1f", percentOfYear);
			System.out.println("% of a year away.\n");
		}
		else
			System.out.println("Happy Birthday!\n");
	}
	//Compares birthdays and displays who's birthday is sooner
	public static void compareBirthdays(int daysUntilNextBDay1, int daysUntilNextBDay2){
		if (daysUntilNextBDay1 < daysUntilNextBDay2)
			System.out.println("Person 1's birthday is sooner.");
		else if (daysUntilNextBDay1 > daysUntilNextBDay2)
			System.out.println("Person 2's birthday is sooner.");
		else
			System.out.println("Wow! You share the same birthday!");
	}
	//Prints the introduction and todays date for the program
	public static void intro(int absoluteDayNow){
		System.out.println("This program will compare two birthdays");
		System.out.println("and display which one is sooner.");
		System.out.print("Today is " + MONTH_TODAY + "/" + DAY_TODAY + "/" + YEAR_TODAY);
		System.out.print(", day #" + absoluteDayNow);
		System.out.println(" of the year.\n");
		
	}
	//Displays a fact about my birthday (January 11th)
	public static void birthdayFact(){
		System.out.println("\nDid you know January 11th is step in ");
		System.out.println("a puddle and splash your friends day!");
	}
	//Retrieves and validates birthday
	public static int getBirthday(Scanner console, int person){
		
		System.out.println("Person " + person + ":");
		System.out.print("What is your birthday? ");
		int month = console.nextInt();
		int day = console.nextInt();
		
		for (int i = month; i < 1 || i > 12; i = month) {
			System.out.println("Month entered is not valid");
			System.out.print("Enter a month between 1 and 12: ");
			month = console.nextInt();
		}
		
		if (month == 2) {
			for (int i = day; i < 1 || i > 29; i = day) {
				System.out.println("Day entered is not valid");
				System.out.print("Enter a day between 1 and 29: ");
				day = console.nextInt();
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11){
			for (int i = day; i < 1 || i > 30; i = day) {
				System.out.println("Day entered is not valid");
				System.out.print("Enter a day between 1 and 30: ");
				day = console.nextInt();
			}
		}
		else {
			for (int i = day; i < 1 || i > 31; i = day) {
				System.out.println("Day entered is not valid");
				System.out.print("Enter a day between 1 and 31: ");
				day = console.nextInt();
			}
		}
		
		return absoluteDay(month, day);
	}
	
}


