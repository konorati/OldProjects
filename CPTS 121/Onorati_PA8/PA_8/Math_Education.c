#include "Math_Education.h"

/*************************************************************************
* Date last modified: April 26th, 2013
* Description: Displays game menu
* Input parameters: 
* Returns: 
* Precondition: 
* Postcondition: Game menu is displayed
*************************************************************************/
void displayMenu(){
	system("cls");
	printf("**** Math Education Game ****\n");
	printf("1. How to play\n");
	printf("2. Enter your initials\n");
	printf("3. Select difficulty level\n");
	printf("4. Start a new game\n");
	printf("5. Save and quit\n");
}

/*************************************************************************
* Date last modified: April 26th, 2013
* Description: Gets users menu choice
* Input parameters: 
* Returns: menu choice (integer)
* Precondition: 
* Postcondition: A number from 1 to 5 is returned
*************************************************************************/
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

/*************************************************************************
* Date last modified: April 26th, 2013
* Description: Displays game rules
* Input parameters: 
* Returns: 
* Precondition: 
* Postcondition: Game rules are displayed
*************************************************************************/
void displayRules(){
	system("cls");
	printf("**** Game Rules ****\n");
	printf("Step 1: Enter your initials\n");
	printf("Step 2: Select your difficulty level\n");
	printf("\t- Easy: Addition and subtraction of positive single digit numbers\n");
	printf("\t- Fair: Multiplication of positive single digit numbers\n");
	printf("\t- Intermediate: Division of single digit numbers\n");
	printf("\t\tNote: You must enter both the answer and the remainder\n\t\t  in the form (answer)R(remainder)\n");
	printf("\t- Hard: Addition, subtraction, multiplication, & division of positive\n\t  and negative single digit numbers\n");
	printf("\t- Impossible: Addition, subtraction, multiplication, & division of\n\t  positive and negative two and three digit numbers\n");
	printf("Step 3: You will answer a series of ten questions for the difficulty level\n\tyou choose\n");
	printf("Step 4: You will lose 10 points for each incorrect answer you give\n");
	printf("Step 5: You will gain points for each correct answer based on the difficulty\n\tof the question\n");
	printf("Step 6: Questions will get progressively more difficult as you give more\n\tcorrect answers\n");
	system("pause");
}

/*************************************************************************
* Date last modified: April 26th, 2013
* Description: Displays game difficulty menu
* Input parameters: 
* Returns: 
* Precondition: 
* Postcondition: Game difficulty menu is displayed
*************************************************************************/
void displayDifficultyMenu(){
	system("cls");
	printf("**** Difficulty Options ****\n");
	printf("1. Easy\n");
	printf("2. Fair\n");
	printf("3. Intermediate\n");
	printf("4. Hard\n");
	printf("5. Impossible\n");
}

/*************************************************************************
* Date last modified: April 26th, 2013
* Description: Gets users initials, initials may not have spaces in between
* Input parameters: character array for player initials
* Returns: 
* Precondition: 
* Postcondition: Character array is updated with players initials
*************************************************************************/
void getPlayerInitials(char *initials){
	system("cls");
	printf("Enter your initials: ");
	_flushall();
	scanf("%s", initials);
}

/*************************************************************************
* Date last modified: April 26th, 2013
* Description: Creates and displays an easy level math problem and returns
*			the solution to the math problem
* Input parameters: Total questions correct so far in this round (integer)
* Returns: Solution to current math problem
* Precondition: 
* Postcondition: Easy level math problem is displayed, correct solution is returned
*************************************************************************/
int easyProblem(int roundPoints){
	int operands[4] = {0};
	int result = 0, remainder = 0;
	char operators[3] = { '+' , '+' , '+' };
	
	operands[0] = getRandomNum(1, roundPoints);
	operands[1] = getRandomNum(1, roundPoints);
	if(roundPoints > 3 && roundPoints < 7){
		operators[0] = '-';
	}
	if(roundPoints > 6){
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
	result = calculateResult(operands, operators, &remainder);
	return result;
}

/*************************************************************************
* Date last modified: April 26th, 2013
* Description: Creates and displays a fair level math problem and returns
*			the solution to the math problem
* Input parameters: Total questions correct so far in this round (integer)
* Returns: Solution to current math problem
* Precondition: 
* Postcondition: Fair level math problem is displayed, correct solution is returned
*************************************************************************/
int fairProblem(int roundPoints){
	int operands[4] = {0};
	int result = 0;
	char operators[3] = { 'x' , '+' , '+' };
	
	if(roundPoints < 3){
		operands[0] = 1;
	}
	else if(roundPoints >= 3 && roundPoints < 5){
		operands[0] = 2;
	}
	else{
		operands[0] = getRandomNum(2, roundPoints);
	}
	operands[1] = getRandomNum(2, roundPoints);
	printf("%d %c %d = ", operands[0], operators[0], operands[1]);

	result = calculateResult(operands, operators, &result);
	return result;
}

/*************************************************************************
* Date last modified: April 26th, 2013
* Description: Creates and displays an intermediate level math problem and returns
*			the solution to the math problem
* Input parameters: Total questions correct so far in this round (integer)
* Returns: Solution to current math problem
* Precondition: 
* Postcondition: Intermediate level math problem is displayed, correct solution is returned
*************************************************************************/
int intermediateProblem(int roundPoints, int *remainder){
	int operands[4] = {0};
	int result = 0;
	char operators[3] = { '/' , '+' , '+' };
	
	if(roundPoints < 3){
		operands[1] = 1;
	}
	else if(roundPoints >= 3 && roundPoints < 5){
		operands[1] = 2;
	}
	else{
		operands[1] = getRandomNum(3, roundPoints);
	}
	operands[0] = getRandomNum(3, roundPoints);
	printf("%d %c %d = ", operands[0], operators[0], operands[1]);

	result = calculateResult(operands, operators, remainder);
	return result;
}

/*************************************************************************
* Date last modified: April 26th, 2013
* Description: Creates and displays a hard level math problem and returns
*			the solution to the math problem
* Input parameters: Total questions correct so far in this round (integer)
* Returns: Solution to current math problem
* Precondition: 
* Postcondition: Hard level math problem is displayed, correct solution is returned
*************************************************************************/
int hardProblem(int roundPoints){
	int operands[4] = {0}, tempNum = 0;
	int result = 0, remainder = 0;
	char operators[3] = { '+' , '+' , '+' };
	
	operands[0] = getRandomNum(4, roundPoints);
	operators[0] = getRandomOperator(4);
	if(operators[0] == '/'){
		operands[1] = findCommonDenominator(operands[0]);
	}
	else{
		operands[1] = getRandomNum(4, roundPoints);
	}
	if(roundPoints < 5){
		printf("%d %c %d = ", operands[0], operators[0], operands[1]);
	}
	else{
		tempNum = findCommonDenominator(calculateResult(operands, operators, &remainder));
		operators[1] = getRandomOperator(4);
		if(operators[1] == '/'){
			operands[2] = tempNum;
		}
		else{
			operands[2] = getRandomNum(4, roundPoints);
		}
		printf("%d %c %d %c %d = ", operands[0], operators[0], operands[1], operators[1], operands[2]);
	}
	result = calculateResult(operands, operators, &remainder);
	return result;
}

/*************************************************************************
* Date last modified: April 26th, 2013
* Description: Creates and displays an impossible level math problem and returns
*			the solution to the math problem
* Input parameters: Total questions correct so far in this round (integer)
* Returns: Solution to current math problem
* Precondition: 
* Postcondition: Impossible level math problem is displayed, correct solution is returned
*************************************************************************/
int impossibleProblem(int roundPoints){
	int operands[4] = {0}, tempNum = 0;
	int result = 0, remainder = 0;
	char operators[3] = { '+' , '+' , '+' };
	
	operands[0] = getRandomNum(5, roundPoints);
	operators[0] = getRandomOperator(5);
	if(operators[0] == '/'){
		operands[1] = findCommonDenominator(operands[0]);
	}
	else{
		operands[1] = getRandomNum(5, roundPoints);
	}
	tempNum = findCommonDenominator(calculateResult(operands, operators, &remainder));
	operators[1] = getRandomOperator(5);
	if(operators[1] == '/'){
		operands[2] = tempNum;
	}
	else{
		operands[2] = getRandomNum(5, roundPoints);
	}
	if(roundPoints < 4){
		printf("%d %c %d %c %d = ", operands[0], operators[0], operands[1], operators[1], operands[2]);
	}
	else{
		tempNum = findCommonDenominator(calculateResult(operands, operators, &remainder));
		operators[2] = getRandomOperator(5);
		if(operators[2] == '/'){
			operands[3] = tempNum;
		}
		else{
			operands[3] = getRandomNum(5, roundPoints);
		}
		printf("%d %c %d %c %d %c %d = ", operands[0], operators[0], operands[1], operators[1], operands[2], operators[2], operands[3]);
	}
	result = calculateResult(operands, operators, &remainder);
	return result;
}

/*************************************************************************
* Date last modified: April 26th, 2013
* Description: Supplies a random number in a range determined by question difficulty level
* Input parameters: Current difficulty level (integer), total question correct this round (integer)
* Returns: Random integer 
* Precondition: 
* Postcondition: Random integer in correct range is returned
*************************************************************************/
int getRandomNum(int difficulty, int roundPoints){
	int num = 0;
	switch (difficulty){
		case 1: 
		case 2:
		case 3:  
			num = rand() % 10 + 1;
			break;
		case 4: if(roundPoints <= 3){
					num = rand() % 10 + 1;
				}
				else{
					num = rand() % 19 - 9;
				}
				break;
		case 5: if(roundPoints < 7){
					do{
						num = rand() % 198 - 99;
					}while(num == 0);
				}
				else{
					do{
					num = rand() % 1998 - 999;
					}while(num == 0);
				}
				break;
	}
	return num;
}

/*************************************************************************
* Date last modified: April 26th, 2013
* Description: Returns a random operator determined by difficulty level of question
* Input parameters: Current questions difficulty level
* Returns: Math operator
* Precondition: 
* Postcondition: Operator is returned
*************************************************************************/
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

/*************************************************************************
* Date last modified: April 26th, 2013
* Description: Calculates correct solution to current problem, sets remainder to fraction
*		as output variable, returns correct answer
* Input parameters: array of operands (int), array of operators(int), remainder(as output parameter)
* Returns: Correct solution
* Precondition: 
* Postcondition: Correct answer is returned, remainder is updated
*************************************************************************/
int calculateResult(int *operands, char *operators, int *remainder){
	int i = 1, result = 0;
	result = operands[0];
	for(i = 1; i < 4; i++){
		switch (operators[i-1]){
			case '+': result += operands[i];
				break;
			case '-': result -= operands[i];
				break;
			case 'x': result *= operands[i];
				break;
			case '/': *remainder = result % operands[i];
				 result /= operands[i];
				 break;
		}
	}
	return result;
}

/*************************************************************************
* Date last modified: April 26th, 2013
* Description: Runs one 10 round game at set difficulty level, returns total points for round
* Input parameters: Difficulty level for current questions
* Returns: Total points from round
* Precondition: 
* Postcondition: 10 subsequent questions are displayed
*************************************************************************/
int runGameRound(int difficulty){
	int numQuestions = 0, numCorrect = 0, correctResult = 0, correctRemainder = 0, result = 0, remainder = 0, isCorrect = 0, points = 0;
	for(numQuestions = 1; numQuestions <= 10; numQuestions++){
		correctResult = 0, correctRemainder = 0, result = 0, remainder = 0, isCorrect = 0;
		system("cls");
		printf("Problem #%d:\n", numQuestions);
		switch (difficulty){
			case 1: correctResult = easyProblem(numCorrect);
				break;
			case 2: correctResult = fairProblem(numCorrect);
				break;
			case 3: correctResult = intermediateProblem(numCorrect, &correctRemainder);
				break;
			case 4: correctResult = hardProblem(numCorrect);
				break;
			case 5: correctResult = impossibleProblem(numCorrect);
		}
		result = getPlayerAnswer(difficulty, &remainder);
		isCorrect = checkPlayerAnswer(correctResult, result, correctRemainder, remainder);
		points += calculatePoints(difficulty, numCorrect, isCorrect);
		if(isCorrect){
			numCorrect++;
			printf("Correct Answer!\nTotal correct this round: %d\nTotal Points: %d\n", numCorrect, points);
		}
		else{
			if(difficulty == 3){
				printf("Incorrect. The correct answer is %d R %d\nTotal Points: %d\n", correctResult, correctRemainder, points);
			}
			else{
				printf("Incorrect. The correct answer is %d \nTotal Points: %d\n", correctResult, points);
			}
		}
		system("pause");
	}
	return points;
}

/*************************************************************************
* Date last modified: April 26th, 2013
* Description: Gets player answer to single math question
* Input parameters: Difficulty level, remainder (as output variable)
* Precondition: 
* Postcondition: Players answer is returned, remainder is updated (if level 3)
*************************************************************************/
int getPlayerAnswer(int difficulty, int *remainder){
	int answer = 0;
	_flushall();
	scanf("%d", &answer);
	if(difficulty == 3){
		getchar();
		scanf("%d", remainder);
	}	
	return answer;
}

/*************************************************************************
* Date last modified: April 26th, 2013
* Description: Determines if players answer is correct
* Input parameters: correct result, players answer, correct remainder, players remainder
* Returns: 1 if correct, 0 if not correct
* Precondition: 
* Postcondition: 1 or 0 is returned
*************************************************************************/
int checkPlayerAnswer(int correctResult, int answer, int correctRemainder, int remainder){
	int isCorrect = 0;
	if(answer == correctResult && remainder == correctRemainder){
		isCorrect = 1;
	}
	return isCorrect;
}

/*************************************************************************
* Date last modified: April 26th, 2013
* Description: Calculates the number of points to award player for current question
* Input parameters: Question difficulty, total number of questions current this round, whether they got the question correct
* Returns: Number of points awarded to player
* Precondition: 
* Postcondition: points are returned
*************************************************************************/
int calculatePoints(int difficulty, int numberCorrect, int isCorrect){
	int points = 0;
	if(!isCorrect){
		points = -10;
	}
	else{
		switch(difficulty){
			case 1: if(numberCorrect < 3){
						points = 10;
					}
					else if(numberCorrect < 7){
						points = 14;
					}
					else{
						points = 18;
					}
					break;
			case 2: if(numberCorrect < 3){
						points = 20;
					}
					else if(numberCorrect < 5){
						points = 24;
					}
					else{
						points = 28;
					}
					break;
			case 3: if(numberCorrect < 3){
						points = 30;
					}
					else if(numberCorrect < 5){
						points = 34;
					}
					else{
						points = 38;
					}
					break;
			case 4: if(numberCorrect < 4){
						points = 40;
					}
					else if(numberCorrect < 6){
						points = 44;
					}
					else{
						points = 48;
					}
				break;
			case 5: if(numberCorrect < 4){
						points = 50;
					}
					else if(numberCorrect < 7){
						points = 54;
					}
					else{
						points = 58;
					}
				break;
		}
	}
	return points;
}

/*************************************************************************
* Date last modified: April 26th, 2013
* Description: Finds a number that divides evenly into given number
* Input parameters: Current number (solution to problem)
* Returns: Common denominator
* Precondition: 
* Postcondition: denominator is returned
*************************************************************************/
int findCommonDenominator(int num){
	int divisor = 20;
	if(num < 10 && num > 1){
		divisor = num-1;
	}
	while((num % divisor) != 0){
		divisor--;
	}
	return divisor;
}


