//Kristin Onorati
//CS 210
//Project 4
//File: Date.java
//Program: Birthday/Date
public class Date {
	//Declare fields
	private int dateYear, dateMonth, dateDay;

	//Constructs a new Date representing the given year, month, and day
	public Date(int year, int month, int day){
		dateYear = year;
		dateMonth = month;
		dateDay = day;
	}
	//Returns this Date object's year
	public int getYear(){
		return dateYear;
	}
	//Returns this Date object's month
	public int getMonth(){
		return dateMonth;
	}
	//Returns this Date object's day
	public int getDay(){
		return dateDay;
	}
	//Returns a string representation of this date in year/month/day format
	public String toString(){
		return dateYear + "/" + dateMonth + "/" + dateDay;
	}
	//Returns true when Date object represents the same date as given date
	public boolean equals(Date d){
	
		return (d.dateYear == dateYear && d.dateMonth == dateMonth && d.dateDay == dateDay);
	}
	//Returns whether this Date's year is a leap year
	public boolean isLeapYear(){
		boolean leapYear = false;
		if (dateYear % 4 == 0){
			leapYear = true;
			if (dateYear % 100 == 0 && dateYear % 400 != 0){
				leapYear = false;
			}
		}
		return leapYear;
	}
	//Advances date object one day
	public void nextDay(){
		if (dateDay == daysInMonth()){
			if (dateMonth == 12){
				dateMonth = 1;
				dateDay = 1;
				dateYear++;
			}
			else{
				dateMonth++;
				dateDay = 1;
			}
		}
		else
			dateDay++;
	}
	//Advances date object to the given end date
	//and returns number of days it advanced
	public int advanceTo(Date endDay){
		int numDays = 0;
		while (!equals(endDay)){
			nextDay();
			numDays++;
		}	
		return numDays;
	}
	//Returns String representing what day of the week this date falls on
	public String getDayOfWeek(){
		String[] dayOfWeek = {"Monday", "Tuesday", "Wednesday", 
				"Thursday", "Friday", "Saturday", "Sunday"};
		Date firstMonday = new Date(1753, 1, 1);
		return dayOfWeek[(firstMonday.advanceTo(this)) % 7];
	}
	//Returns the number of days in the month 
	public int daysInMonth(){
		int[] daysPerMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if (isLeapYear() && dateMonth == 2){
			return 29;
		}
		else {
			return daysPerMonth[dateMonth - 1];
		}
		
	}
	
}
