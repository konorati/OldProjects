#ifndef MATH_EDUCATION_H
#define MATH_EDUCATION_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayMenu();
int getMenuChoice();
void displayDifficultyMenu();
int easyProblem(int roundPoints);
int fairProblem(int roundPoints);
int intermediateProblem(int roundPoints);
int hardProblem(int roundPoints);
int getRandomNum(int difficulty, int roundPoints);
char getRandomOperator(int difficulty);
int calculateResult(int *operands, char *operators, int *result);

#endif