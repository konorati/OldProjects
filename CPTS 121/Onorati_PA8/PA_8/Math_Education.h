#ifndef MATH_EDUCATION_H
#define MATH_EDUCATION_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void displayMenu();
int getMenuChoice();
void displayRules();
void displayDifficultyMenu();
void getPlayerInitials(char *initials);
int easyProblem(int roundPoints);
int fairProblem(int roundPoints);
int intermediateProblem(int roundPoints, int *remainder);
int hardProblem(int roundPoints);
int impossibleProblem(int roundPoints);
int getRandomNum(int difficulty, int roundPoints);
char getRandomOperator(int difficulty);
int calculateResult(int *operands, char *operators, int *result);
int runGameRound(int difficulty);
int getPlayerAnswer(int difficulty, int *remainder);
int checkPlayerAnswer(int correctResult, int answer, int correctRemainder, int remainder);
int calculatePoints(int difficulty, int numberCorrect, int isCorrect);
int findCommonDenominator(int num);

#endif