#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include <ctype.h>

double computeBMR(char gender, double weight, double height, double age);
int determineActivityLevel(void);
double computeCalories(double BMR, int activityLevel);

FILE *openInputFile(void);
char readCharacter(FILE *);
double readNumber(FILE *);
int readInteger(FILE *);

char getBaseballAchievements(char []);
int determineBonus(char, int);
double computeAverage(int, int, int, int, int);
int findHighValue(int, int, int, int, int);
int findLowValue(int, int, int, int, int);
int displayMenu(void);
double calculateResult(int choice, int, int, int, int, int);
void displayResult(int choice, double result);


#endif 
