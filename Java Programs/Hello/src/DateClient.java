//Kristin Onorati
//CS 210
//Project 4
//File: Date.java
//Program: Birthday/Date
import java.util.*;
public class DateClient {

	public static void main(String[] args) {
		//declare variables and create scanner object
		Scanner console = new Scanner(System.in);
		int yearToday, monthToday, dayToday, yearBirth, monthBirth, dayBirth;
		
		//Get user input and create date objects for current day and day of birth
		System.out.print("What is today's date (month day year)? ");
		monthToday = console.nextInt();
		dayToday = console.nextInt();
		yearToday = console.nextInt();
		Date currentDay = new Date(yearToday, monthToday, dayToday);
		System.out.print("What is your birthday (month day year)? ");
		monthBirth = console.nextInt();
		dayBirth = console.nextInt();
		yearBirth = console.nextInt();
		Date birthday = new Date(yearBirth, monthBirth, dayBirth);
		
		//print info to console
		System.out.print("You were born on " + birthday.toString());
		System.out.println(", which was a " + birthday.getDayOfWeek() + ".");
		if (birthday.isLeapYear()){
			System.out.println(birthday.getYear() + " was a leap year.");
		}
		System.out.println("You are " + birthday.advanceTo(currentDay) + " days old.");
	}

}
