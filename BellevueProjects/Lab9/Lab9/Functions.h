#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include <string.h>

#define EMPLOYEES 50

typedef struct student{
	char *name;
	unsigned int idNum;
	double gpa;
}Student

int strLen(const char* str);
char *stringReverse(char *str);
char *stringReversePoint(char *str);
char *stringCopy(char *destination, const char *source);
char *stringCat(char *destination, const char * source);
int stringCompare(const char *str1, const char *str2);
void stringSort(char str[][50]);
int findCEO(int list[4][2]);

void setStudent(Student student, unsigned int id, double gpa, char *name);


#endif