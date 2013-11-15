#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string.h>
#include <time.h>
#include <stdio.h>

int getDays(int sec);
int getMonths(int sec);
int getYears(int sec);
int getHours(int sec);
int getCurrentDayOfWeek(int days);
int getCurrentMonth(int sec);
int getCurrentYear(int sec);
void getStringDayOfWeek(int day, char *str);
void getStringMonth(int month, char *str);
int findFirstOfNextMonth(int days);
int findLastDayOfCurrentMonth(int days);
int convertDaysToSeconds(int days);

#endif