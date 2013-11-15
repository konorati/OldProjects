#include "records.h"
/*************************************************************************************
* Programmer: Kristin Onorati
* Class: CPTS 121, Spring 2013, Lab Section 1
* Programming Assignment: 3
* Date: January 6, 2013
* Description: This program opens a file, reads student data from the file, calculates
* the means and standard deviations of data, and prints results to output file.
**************************************************************************************/

int main(void){

	FILE *inputFile = NULL, *outputFile = NULL;
	int sid1 = 0, sid2 = 0, sid3 = 0, sid4 = 0, sid5 = 0, cStand1 = 0, 
		cStand2 = 0, cStand3 = 0, cStand4 = 0, cStand5 = 0;
	double gpa1 = 0, gpa2 = 0, gpa3 = 0, gpa4 = 0, gpa5 = 0, age1 = 0, 
		age2 = 0, age3 = 0, age4 = 0, age5 = 0, gpaSum = 0, cStandSum = 0, 
		ageSum = 0, gpaMean = 0, cStandMean = 0, ageMean = 0, dev1 = 0,
		dev2 = 0, dev3 = 0, dev4 = 0, dev5 = 0, gpaVar = 0, gpaStdDev = 0,
		gpaMin = 0, gpaMax = 0;
	
	//Open files for reading/writing
	inputFile = fopen("input.dat", "r");
	outputFile = fopen("output.dat", "w");

	//Check to see if files are open
	if (inputFile != NULL && outputFile != NULL){

		//Read 5 records 
		sid1 = readInteger(inputFile);
		gpa1 = readDouble(inputFile);
		cStand1 = readInteger(inputFile);
		age1 = readDouble(inputFile);
		sid2 = readInteger(inputFile);
		gpa2 = readDouble(inputFile);
		cStand2 = readInteger(inputFile);
		age2 = readDouble(inputFile);
		sid3 = readInteger(inputFile);
		gpa3 = readDouble(inputFile);
		cStand3 = readInteger(inputFile);
		age3 = readDouble(inputFile);
		sid4 = readInteger(inputFile);
		gpa4 = readDouble(inputFile);
		cStand4 = readInteger(inputFile);
		age4 = readDouble(inputFile);
		sid5 = readInteger(inputFile);
		gpa5 = readDouble(inputFile);
		cStand5 = readInteger(inputFile);
		age5 = readDouble(inputFile);
	

		//Compute sums of gpa, class standing, & age
		gpaSum = calculateSum(gpa1, gpa2, gpa3, gpa4, gpa5);
		cStandSum = calculateSum(cStand1, cStand2, cStand3, cStand4, cStand5);
		ageSum = calculateSum(age1, age2, age3, age4, age5);

		//Calculate mean of gpa, class standing, & age
		gpaMean = calculateMean(gpaSum, 5);
		cStandMean = calculateMean(cStandSum, 5);
		ageMean = calculateMean(ageSum, 5);

		//Write means to output file
		printFile(outputFile, gpaMean);
		printFile(outputFile, cStandMean);
		printFile(outputFile, ageMean);

		//Calculate deviation of each gpa
		dev1 = calculateDeviation(gpa1, gpaMean);
		dev2 = calculateDeviation(gpa2, gpaMean);
		dev3 = calculateDeviation(gpa3, gpaMean);
		dev4 = calculateDeviation(gpa4, gpaMean);
		dev5 = calculateDeviation(gpa5, gpaMean);
	
		//Calculate variance of the gpas
		gpaVar = calculateVariance(dev1, dev2, dev3, dev4, dev4, 5);

		//Calculate the standard deviation of the gpas
		gpaStdDev = calculateStandardDeviation(gpaVar);

		//Write standard deviation to output file
		printFile(outputFile, gpaStdDev);

		//Determine minimum and maximum gpa
		gpaMin = findMin(gpa1, gpa2, gpa3, gpa4, gpa5);
		gpaMax = findMax(gpa1, gpa2, gpa3, gpa4, gpa5);
	
		//Write minimum and maximum gpa to output file
		printFile(outputFile, gpaMin);
		printFile(outputFile, gpaMax);

		//Close input and output files
		fclose(inputFile);
		fclose(outputFile);
	}
	else {
		printf("Unable to open files\n");
	}

	return 0;
}