#include "Functions.h"

FILE *openFile(char file[]){
	FILE *input = NULL;
	input = fopen(file, "r");
	return input;
}

double readFile(FILE *input){
	double salary = 0;
	fscanf(input, "%lf", &salary);
	return salary;
}

char taxBracket(double salary){
	char bracket = 'l';
	if(salary > 200000){
		bracket = 'h';
	}
	else if(salary >= 15000){
		bracket = 'm';
	}
	return bracket;
}

char* getFileName(void){
	char fileName[FILE_NAME_SIZE];
	printf("\nEnter the name of the file to read from: ");
	scanf("%s", fileName);
	return fileName;
}

void printDouble(FILE *outfile, double value){
	fprintf(outfile, "%.2lf", value);
}

int greatestCommonDivisor(int num1, int num2){
	int remainder = -1;
	if(num1 < 0){
		num1 = -num1;
	}
	if(num2 < 0){
		num2 = -num2;
	}
	while (remainder != 0){
		remainder = num1 % num2;
		num1 = num2;
		num2 = remainder;
	}
	return num1;

}

int readInt(FILE *input){
	int num = 0;
	fscanf(input, "%d", &num);
	return num;
}

void printInt(FILE *output, int value){
	fprintf(output, "%d\n", value);
}
