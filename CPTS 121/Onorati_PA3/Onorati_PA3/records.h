#ifndef RECORDS_H
#define RECORDS_H
#include <stdio.h>
#include <math.h>

double readDouble(FILE *infile);
int readInteger(FILE *infile);
double calculateSum(double num1, double num2, double num3, double num4, double num5);
double calculateMean(double sum, int num);
double calculateDeviation(double num, double mean);
double calculateVariance(double dev1, double dev2, double dev3, double dev4, double dev5, int num);
double calculateStandardDeviation(double variance);
double findMax(double num1, double num2, double num3, double num4, double num5);
double findMin(double num1, double num2, double num3, double num4, double num5);
void printFile(FILE *outFile, double);


#endif