#include "Functions.h"

double computeBMR(char gender, double weight, double height, double age){
	double bmr = 0;
	if(toupper(gender) == 'F'){
		bmr = 655 + (4.35 * weight) + (4.7 * height) - (4.7 * age);
	}
	else {
		bmr = 66 + (6.23 * weight) + (12.7 * height) - (6.8 * age);
	}
	return bmr;
}

int determineActivityLevel(void){
	int activityLevel = 0;
	printf("Enter activity level from the choices below:\n\t1: Sedentary\n\t2: Low Activity\n\t3: Moderate Activity\n\t4: High Activity\n\t5: Extra Activity\nEnter your selection: ");
	scanf("%d", &activityLevel);
	return activityLevel;
}

double computeCalories(double bmr, int activityLevel){
	double calories = 0;
	switch (activityLevel) {
		case 1: 
			calories = bmr * 1.2;
			break;
		case 2:
			calories = bmr * 1.375;
			break;
		case 3:
			calories = bmr * 1.55;
			break;
		case 4: 
			calories = bmr * 1.725;
			break;
		case 5:
			calories = bmr * 1.9;
			break;
		default:
			printf("Activity level does not exist");
			break;
	}
	return calories;
}
FILE *openInputFile(void){
	FILE *file = NULL;
	file = fopen("input.dat", "r");
	return file;
}

double readNumber(FILE *inFile){
	double num = 0;
	fscanf(inFile, "%lf", &num);
	return num;
}
int readInteger(FILE *inFile){
	int num = 0;
	fscanf(inFile, "%d", &num);
	return num;
}


char readCharacter(FILE *inFile){
	char character = '\0';
	fscanf(inFile, "%c", &character);
	return character;
}

char getBaseballAchievements(char achievement[]){
	char completed = '\0';
	printf("Did the player achieve: %s? <y or n>: ", achievement);
	scanf(" %c", &completed);
	return completed;
}

int determineBonus(char achievement, int bonus){
	if(toupper(achievement) == 'N'){
		bonus = 0;
	}
	return bonus;
}

double computeAverage(int num1, int num2, int num3, int num4, int num5){
	double average = 0;
	average = (num1 + num2 + num3 + num4 + num5)/(double)5;
	return average;
}
int findHighValue(int num1, int num2, int num3, int num4, int num5){
	int high = num1;
	if (high < num2){
		high = num2;
	}
	if (high < num3){
		high = num3;
	}
	if (high < num4){
		high = num4;
	}
	if (high < num4){
		high = num5;
	}
	return high;
}
int findLowValue(int num1, int num2, int num3, int num4, int num5){
	int low = num1;
	if (low > num2){
		low = num2;
	}
	if (low > num3){
		low = num3;
	}
	if (low > num4){
		low = num4;
	}
	if (low > num4){
		low = num5;
	}
	return low;
}

int displayMenu(void){
	int choice;
	printf("Please choose an option:\n\t1: Find average\n\t2: Find high value\n\t3: Find low value\nEnter your choice:");
	scanf("%d", &choice);
	return choice;
}

double calculateResult(int choice, int num1, int num2, int num3, int num4, int num5){
	double result = 0;
	switch(choice){
		case 1: 
			result = computeAverage(num1, num2, num3, num4, num5);
			break;
		case 2:
			result = findHighValue(num1, num2, num3, num4, num5);
			break;
		case 3: 
			result = findLowValue(num1, num2, num3, num4, num5);
			break;
		default:
			printf("Not a valid menu choice");
			break;
	}
	return result;
}

void displayResult(int choice, double result){
	switch (choice){
		case 1: 
			printf("Average = %.2lf\n", result);
			break;
		case 2:
			printf("High Value = %d\n", (int)result);
			break;
		case 3:
			printf("Low Value = %d\n", (int)result);
			break;
		default:
			break;
	}
}