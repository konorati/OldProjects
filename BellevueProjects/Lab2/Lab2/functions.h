#ifndef FUNCTIONS_H_INCLUDE
#define FUNCTIONS_H_INCLUDE
#include <stdio.h>

FILE *openFile(void);
int readCredits(FILE*);
double readGradePoint(FILE*);

double getDataPoint(char, int);
double computeSlope(double, double, double, double);
double computeMidpoint(double, double);
double computeSlopeOfBisector(double);
double computeYInterceptOfBisector(double, double, double);
void outputResults(double, double, double, double, double, double);
double getHeight();
double getWeight();
double convertFeetToInches(double);
double computeBodyMassIndex(double, double);
void displayBMI(double);
double getHarrisPoll();
double getCoachesPoll();
double getComputerRanking();
double computeBcsScore(double, double, double);
double computePoll(double, double);
void displayIntermediateResult(double, double, double);
void displayBcsScore(double);

#endif
