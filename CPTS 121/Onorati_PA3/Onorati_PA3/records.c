#include "records.h"

/*************************************************************************
* Date last modified: Feb 1st, 2013
* Description: Reads a number(double) from a file and returns the number
* Input parameters: File
* Returns: number (double)
* Precondition: File must already be open
* Postcondition: number is returned
*************************************************************************/
double readDouble(FILE *infile){
	double num = 0;
	fscanf(infile, "%lf", &num);
	return num;
}

/*************************************************************************
* Date last modified: Feb 1st, 2013
* Description: Reads a number(integer) from a file and returns the number
* Input parameters: File
* Returns: number (integer)
* Precondition: File must already be open
* Postcondition: number is returned
*************************************************************************/
int readInteger(FILE *infile){
	int num = 0;
	fscanf(infile, "%d", &num);
	return num;
}

/*************************************************************************
* Date last modified: Feb 1st, 2013
* Description: calculates and returns the sum of 5 numbers (doubles)
* Input parameters: 5 numbers (doubles)
* Returns: sum (double)
* Precondition: numbers must be real
* Postcondition: sum is returned
*************************************************************************/
double calculateSum(double num1, double num2, double num3, double num4, double num5){
	double sum = 0;
	sum = num1 + num2 + num3 + num4 + num5;
	return sum;
}

/*************************************************************************
* Date last modified: Feb 1st, 2013
* Description: Calcultes and returns the mean if number does not equal 0
*	if number is 0 returns -1
* Input parameters: sum of numbers, number of variables
* Returns: mean (double)
* Precondition: 
* Postcondition: mean is returned
*************************************************************************/
double calculateMean(double sum, int num){
	double mean = -1;
	if (num != 0){
		mean = sum/num;
	}
	return mean;
}

/*************************************************************************
* Date last modified: Feb 1st, 2013
* Description: Calculates the deviation from the mean for one value
* Input parameters: value (double), mean of values (double)
* Returns: deviation (double)
* Precondition: 
* Postcondition: deviation is returned
*************************************************************************/
double calculateDeviation(double num, double mean){
	double dev = 0;
	dev = num - mean;
	return dev;
}

/*************************************************************************
* Date last modified: Feb 1st, 2013
* Description: Calculates the variance using deviations and number of variables
* Input parameters: 5 deviations (doubles), number of variables
* Returns: variance (double)
* Precondition: number of variables must be greater than 0
* Postcondition: variance is returned
*************************************************************************/
double calculateVariance(double dev1, double dev2, double dev3, double dev4, double dev5, int num){
	double variance = 0;
	variance = ((dev1*dev1) + (dev2*dev2) + (dev3*dev3) + (dev4*dev4) + (dev5*dev5))/num;
	return variance;
}

/*************************************************************************
* Date last modified: Feb 1st, 2013
* Description: Calculates the standard deviation using the variance
* Input parameters: variance (double)
* Returns: standar deviation (double)
* Precondition: variance must be positive
* Postcondition: standard deviation is returned
*************************************************************************/
double calculateStandardDeviation(double variance){
	double stdDev = 0;
	stdDev = sqrt(variance);
	return stdDev;
}

/*************************************************************************
* Date last modified: Feb 1st, 2013
* Description: Finds the maximum of 5 numbers
* Input parameters: 5 numbers (doubles)
* Returns: maximum value (double)
* Precondition: 
* Postcondition: maximum is returned
*************************************************************************/
double findMax(double num1, double num2, double num3, double num4, double num5){
	double max = num1;

	if (max < num2){
		max = num2;
	}
	if (max < num3){
		max = num3;
	}
	if (max < num4){
		max = num4;
	}
	if (max < num5){
		max = num5;
	}
	return max;
}

/*************************************************************************
* Date last modified: Feb 1st, 2013
* Description: Finds the minimum of 5 numbers
* Input parameters: 5 numbers (doubles)
* Returns: minimum value (double)
* Precondition: 
* Postcondition: minimum is returned
*************************************************************************/
double findMin(double num1, double num2, double num3, double num4, double num5){
	double min = num1;

	if (min > num2){
		min = num2;
	}
	if (min > num3){
		min = num3;
	}
	if (min > num4){
		min = num4;
	}
	if (min > num5){
		min = num5;
	}

	return min;
}

/*************************************************************************
* Date last modified: Feb 1st, 2013
* Description: Prints a number to the hundreths place to the output file
* Input parameters: output file, number(double)
* Returns: 
* Precondition: file must be open for writing
* Postcondition: number is written to file
*************************************************************************/
void printFile(FILE *outfile, double num){
	fprintf(outfile, "%.2f\n", num);
}