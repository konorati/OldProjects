#include "Functions.h"

int main(void){
	time_t secSinceBirth = NULL;
	int numDayOfWeek = 0;
	char dayOfWeek[20], month[20];
	secSinceBirth = time(NULL);
	printf("seconds since 1970: %d\n", secSinceBirth);
	printf("Hours since 1970: %d\n", getHours(secSinceBirth));
	printf("Days since 1970: %d\n", getDays(secSinceBirth));
	printf("Months since 1970: %d\n", getMonths(secSinceBirth));
	printf("Years since 1970: %d\n", getYears(secSinceBirth));
	numDayOfWeek = getCurrentDayOfWeek(getDays(secSinceBirth));
	getStringDayOfWeek(numDayOfWeek, dayOfWeek);
	printf("Current day of the week: %s\n", dayOfWeek);
	getStringMonth(getCurrentMonth(getDays(secSinceBirth)), month);
	printf("Current month: %s\n", month);
	printf("Current year: %d\n", getCurrentYear(getDays(secSinceBirth)));
	printf("Days since 1970 to first of next month: %d\n", findFirstOfNextMonth(getDays(secSinceBirth)));
	printf("Days since 1970 to last of this month: %d\n", findLastDayOfCurrentMonth(getDays(secSinceBirth)));
	return 0;
}