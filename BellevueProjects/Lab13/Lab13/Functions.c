#include "Functions.h"

int getHours(int sec){
	int hours = sec/3600;
	return hours;
}
int getDays(int sec){
	int days = getHours(sec)/24;
	return days;
}
int getMonths(int sec){
	int months = getDays(sec)/30.433;
	return months;
}
int getYears(int sec){
	int years = getMonths(sec)/12;
	return years;
}
int getCurrentDayOfWeek(int days){
	int dayOfWeek = days%7;
	return dayOfWeek;
}
int getCurrentMonth(int days){
	int month = getMonths(convertDaysToSeconds(days))%12;
	return month;
}
int getCurrentYear(int days){
	int year =  getYears(convertDaysToSeconds(days)) + 1970;
	return year;
}
void getStringDayOfWeek(int day, char *str){
	switch(day){
		case 0: strcpy(str, "Thursday");
				break;
		case 1: strcpy(str, "Friday");
				break;
		case 2: strcpy(str, "Saturday");
				break;
		case 3: strcpy(str, "Sunday");
				break;
		case 4: strcpy(str, "Monday");
				break;
		case 5: strcpy(str, "Tuesday");
				break;
		case 6: strcpy(str, "Wednesday");
				break;
	}
}
void getStringMonth(int month, char *str){
	switch(month){
		case 0: strcpy(str, "January");
			break;
		case 1: strcpy(str, "February");
			break;
		case 2: strcpy(str, "March");
			break;
		case 3: strcpy(str, "April");
			break;
		case 4: strcpy(str, "May");
			break;
		case 5: strcpy(str, "June");
			break;
		case 6: strcpy(str, "July");
			break;
		case 7: strcpy(str, "August");
			break;
		case 8: strcpy(str, "September");
			break;
		case 9: strcpy(str, "October");
			break;
		case 10: strcpy(str, "November");
			break;
		case 11: strcpy(str, "December");
			break;
	}

}
int findFirstOfNextMonth(int days){
	int newDays = days;
	int currentMonth = getMonths(convertDaysToSeconds(days));
	do{
		newDays++;
		
	}while(getMonths(convertDaysToSeconds(newDays)) == currentMonth);
	return newDays;
}
int findLastDayOfCurrentMonth(int days){
	int lastDay = findFirstOfNextMonth(days) - 1;
	return lastDay;
}
int convertDaysToSeconds(int days){
	int sec = days*24*3600;
	return sec;
}

