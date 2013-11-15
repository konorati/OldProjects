#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void test(int *x);
void task();
void charges(double hours, double *totCharges, double *aveCharges);
double roundMoney(double num);
void revenue(double *rev, int years);
void predict(double rev, int *years);
void bubbleSort(int *list, int size);
typedef struct{
		int idNum;
		char firstName[20];
		char lastName[20];
		int age;
		double gpa;
	} student_t;


#endif 