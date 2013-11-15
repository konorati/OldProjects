#include "functions.h"

//Open grades file
FILE *openFile(void){
	FILE *inputFile = NULL;
	inputFile = fopen ("grades.txt", "r");
	return inputFile;
}

double readGradePoint(FILE *inputHandle){
	double gradePoint = 0;
	fscanf(inputHandle, "%lf", &gradePoint);
	return gradePoint;
}
//precondition: the file must already be open
int readCredits(FILE *inputHandle){
	int credits = 0;
	fscanf(inputHandle, "%d", &credits);
	return credits;
}

//Prompt user for coordinate points
double getDataPoint(char axis, int num){
	double point = 0;
	printf("Enter the %c coordinate for data point #%d: ", axis, num);
	scanf("%lf", &point);
	return point;
}

//Compute the slope of the point
double computeSlope(double x1, double x2, double y1, double y2){
	double slope = (y2-y1)/(x2-x1);
	return slope;
}

//Date last modified:
//Description: Compute midpoint
//Input parameters:
//Returns:
//Preconditions:
//Postconditions:
double computeMidpoint(double p1, double p2){
	double midpoint = (p2-p1)/2;
	return midpoint;
}

//Compute slope of perpendicular bisector
double computeSlopeOfBisector(double slope){
	double perpSlope = -1/(slope);
	return perpSlope;
}

//Compute the y intercept of the perpendicular bisector
double computeYInterceptOfBisector(double slope, double yMid, double xMid){
	double yIntercept = yMid - (slope * xMid);
	return yIntercept;
}

//Output results
void outputResults(double x1, double x2, double y1, double y2, double perpSlope, double yIntercept){
	printf("Point 1 = (%.2f, %.2f)\nPoint 2 = (%.2f, %.2f)\nPerpendicular Bisector: Y = %.2fX + %.2f\n", x1, y1, x2, y2, perpSlope, yIntercept);
}

//Get height
double getHeight(){
	double height = 0;
	printf("\nPlease enter your height in feet: ");
	scanf("%lf", &height);
	return height;
}

//Get weight
double getWeight(){
	double weight = 0;
	printf("Please enter your weight in pounds: ");
	scanf("%lf", &weight);
	return weight;
}

double convertFeetToInches(double feet){
	double inches = feet*12;
	return inches;
}

double computeBodyMassIndex(double height, double weight){
	double bodyMassIndex = (weight/(height*height)) * 703;
	return bodyMassIndex;
}

void displayBMI(double BMI){
	printf("Your BMI is: %.2f\n", BMI);
}

double getHarrisPoll(){
	double poll = 0;
	printf("\nEnter the results of the Harris Poll: ");
	scanf("%lf", &poll);
	return poll;
}

double computePoll(double rawScore, double weight){
	double poll = rawScore/weight;
	return poll;
}

double getCoachesPoll(){
	double poll = 0;
	printf("Enter the results of the Coaches Poll: ");
	scanf("%lf", &poll);
	return poll;
}

double getComputerRanking(){
	double ranking = 0;
	printf("Enter the computer ranking: ");
	scanf("%lf", &ranking);
	return ranking;
}

double computeBcsScore(double harrisPoll, double coachesPoll, double computerRank){
	double bcsRank = (harrisPoll + coachesPoll + computerRank)/3;
	return bcsRank;
}

void displayIntermediateResult(double harris, double coaches, double computer){
	double total = harris + coaches + computer;
	printf("Harris Poll Score = %.2f\nCoaches Poll Score = %.2f\nComputer Rank = %.2f\nTotal score = %.2f", harris, coaches, computer, total);
}

void displayBcsScore(double bcsScore){
	printf("\nBCS Score = %.2f\n", bcsScore);
}
