#include "Functions.h"

int main (){
	FILE *salaryFile = NULL, *infile = NULL, *outfile = NULL;
	double salaryTotal = 0, salaryQuarter = 0, value = 0, sumValues = 0, averageValues = 0;
	char taxBrack = '\0';
	char fileName[FILE_NAME_SIZE];
	int numValues = 0, num1 = 0, num2 = 0, gcd = 0, numLow = 0, numHigh = 0;


	//PROBLEM NUMBER 1
	
	salaryFile = openFile("salaries.txt");

	if (salaryFile != NULL){
		while (!(feof(salaryFile))){
			salaryQuarter = readFile(salaryFile);
			salaryTotal += salaryQuarter;
		}
		taxBrack = taxBracket(salaryTotal);
		printf("Salary = $%.0lf, Tax Bracket = %c\n", salaryTotal, taxBrack);
		fclose(salaryFile);
	}


	//PROBLEM NUMBER 2
	/*printf("Enter the name of the file to read from: ");
	scanf("%s", fileName);
	infile = openFile(fileName);

	if(infile != NULL){
		while (!(feof(infile))){
			value = readFile(infile);
			sumValues += value;
			numValues++;
		}

		outfile = fopen("output.dat", "w");
		averageValues = sumValues/numValues;
		printDouble(outfile, averageValues);

		fclose(infile);
		fclose(outfile);
	}*/

	//PROBLEM NUMBER 3
	
	/*infile = openFile("input.txt");
	outfile = fopen("output.dat", "w");

	if(infile != NULL){
		num1 = readInt(infile);
		num2 = readInt(infile);
		gcd = greatestCommonDivisor(num1, num2);
		printInt(outfile, gcd);
	}*/

	//PROBLEM NUMBER 4

	/*infile = openFile("input1.txt");
	outfile = fopen("output.dat", "w");
		
	num1 = readInt(infile);
	numLow = num1;
	numHigh = num1;
		
	while (!(feof(infile))){
		num1 = readInt(infile);
		if(num1 < numLow){
			numLow = num1;
		}
		if(num1 > numHigh){
			numHigh = num1;
		}
	}
	printf("High =  %d, Low = %d\n", numHigh, numLow);
	printInt(outfile, numLow);
	printInt(outfile, numHigh);*/

	return 0;
}