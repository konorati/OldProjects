#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#define FILE_NAME_SIZE 30

FILE *openFile(char file[]);
double readFile(FILE *);
char taxBracket(double);
char* getFileName(void);
void printDouble(FILE *, double value);
int greatestCommonDivisor(int num1, int num2);
int readInt(FILE *);
void printInt(FILE *, int value);


#endif 