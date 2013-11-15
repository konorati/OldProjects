#include "Math_Education.h"

void displayMenu(){
	system("cls");
	printf("**** Math Education Game ****\n");
	printf("1. How to play\n");
	printf("2. Enter your initials\n");
	printf("3. Select difficulty level\n");
	printf("4. Start a new game\n");
	printf("5. Save and quit\n");
}

int getMenuChoice(){
	int choice = 0;
	do{
		printf("Enter your menu choice: ");
		_flushall();
		scanf("%d", &choice);
		if(choice < 1 || choice > 5){
			printf("Invalid menu choice.\n");
		}
	}while(choice < 1 || choice > 5);
	return choice;
}

void displayDifficultyMenu(){
	system("cls");
	printf("**** Difficulty Options ****\n");
	printf("1. Easy\n");
	printf("2. Fair\n");
	printf("3. Intermediate\n");
	printf("4. Hard\n");
	printf("5. Impossible\n");
}

int easyProblem(int roundPoints){
	int operands[4] = {0};
	int result = 0;
	char operators[3] = { '+' , '+' , '+' };
	
	operands[0] = getRandomNum(1, roundPoints);
	operands[1] = getRandomNum(1, roundPoints);
	if(roundPoints > 3){
		operators[0] = getRandomOperator(1);
	}
	if(roundPoints <= 6){
		printf("%d %c %d = ", operands[0], operators[0], operands[1]);
	}
	else{
		operands[2] = getRandomNum(1, roundPoints);
		operators[1] = getRandomOperator(1);
		printf("%d %c %d %c %d = ", operands[0], operators[0], operands[1], operators[1], operands[2]);
	}
	calculateResult(operands, operators, &result);
	return result;
}

int fairProblem(int roundPoints);
int intermediateProblem(int roundPoints);
int hardProblem(int roundPoints);

int getRandomNum(int difficulty, int roundPoints){
	int num = 0;
	switch (difficulty){
		case 1: 
		case 2:
		case 3:  
			num = rand() % 10 + 1;
			break;
		case 4: if(roundPoints <= 3){
					num = rand() % 10;
				}
				else{
					num = rand() % 19 - 9;
				}
				break;
		case 5: if(roundPoints <= 3){
					num = rand() % 90 + 10;
				}
				else{
					num = rand() % 990 + 10;
				}
				break;
	}
	return num;
}

char getRandomOperator(int difficulty){
	int randomNum = 0;
	char oper = '+';
	switch (difficulty){
		case 1: randomNum = rand() % 2;
			if(randomNum){
				oper = '-';
			}
			break;
		case 4: 
		case 5:
			randomNum = rand() % 4;
			switch (randomNum){
				case 1: oper = '-';
					break;
				case 2: oper = 'x';
					break;
				case 3: oper = '/';
					break;
			}
			break;
	}
	return oper;
}

int calculateResult(int *operands, char *operators, int *result){
	int i = 1, remainder = 0;
	*result = operands[0];
	for(i = 1; i < 4; i++){
		switch (operators[i-1]){
			case '+': *result += operands[i];
				break;
			case '-': *result += operands[i];
				break;
			case 'x': *result *= operands[i];
				break;
			case '/': remainder = *result % operands[i];
				 *result /= operands[i];
				 break;
		}
	}
	return remainder;
}