#include "Yahtzee.h"

/*************************************************************************
* Date last modified: Feb 27th, 2013
* Description: Displays the yahtzee game menu
* Input parameters: 
* Returns: 
* Precondition: 
* Postcondition: Game menu is displayed
*************************************************************************/
void displayGameMenu(void){
	printf("    Yahtzee Game Menu:    \n");
	printf("---------------------------\n");
	printf("1. Print Game Rules\n");
	printf("2. Start a Game of Yahtzee\n");
	printf("3. Exit Game\n");
}

/*************************************************************************
* Date last modified: Feb 27th, 2013
* Description: Displays yahtzee game rules
* Input parameters: 
* Returns:
* Precondition: 
* Postcondition: Rules are displayed
*************************************************************************/
void displayRules(void){
	printf("    Yahtzee Game Rules    \n");
	printf("--------------------------\n");
	printf("1. On each turn player rolls 5 dice up to 3 times in order to\n");
	printf("   achieve the best combination of dice.\n");
	printf("2. Player chooses which of the 13 categories to use dice to score\n");
	printf("3. Once each player has rolled 13 rounds game ends\n");
	printf("4. Scores are added for each category for each player, if total\n");
	printf("   score for categories 1-6 is 63 or more player gets a bonus of \n");
	printf("   35 points added to total score.\n");
	printf("\n          Scoring          \n");
	printf("---------------------------\n");
	printf("1's through 6's: Sum of all dice of selected number\n");
	printf("Three-of-a-kind: Sum of all 5 dice\n");
	printf("Four-of-a-kind: Sum of all 5 dice\n");
	printf("Full House: 25 points\n");
	printf("Small Straight: 30 points\n");
	printf("Large Straight: 40 points\n");
	printf("Yahtzee: 50 points\n");
	printf("Chance: Sum of all 5 dice\n");
}

/*************************************************************************
* Date last modified: Feb 27th, 2013
* Description: Prompts user for menu selection and validates selection
* Input parameters: 
* Returns: menu selection (int)
* Precondition: 
* Postcondition: valid menu selection is returned
*************************************************************************/
int getMenuOption(void){
	int selection = 0;
	printf("\nEnter your menu selection: ");
	scanf("%d", &selection);
	while(selection > 4 || selection < 1){
		flushall();
		printf("\nMenu choice is invalid, choose a menu option 1-3: ");
		scanf("%d", &selection);
	}
	return selection;
}

/*************************************************************************
* Date last modified: Feb 27th, 2013
* Description: Assigns a random number (1-6) to one die
* Input parameters: 
* Returns: Die roll (1-6)
* Precondition: 
* Postcondition: Random integer between 1 and 6 is returned
*************************************************************************/
int rollDie(void){
	int die = 0;
	die = (rand() % 6) + 1; 
	return die;
}

/*************************************************************************
* Date last modified: Feb 27th, 2013
* Description: Sets each die that is not being kept by the player to a 
* random number between 1 and 6
* Input parameters: dice, keep dice
* Returns: 
* Precondition: 
* Postcondition: each die that is not being held is assigned a new random
* number between 1 and 6
*************************************************************************/
void setDice(int *dice, int *keep){
	int i = 0;
	for (i = 0; i < NUM_DICE; i++){
		if(keep[i] == AVAILABLE){
			dice[i] = rollDie();
		}
	}
}

/*************************************************************************
* Date last modified: Feb 27th, 2013
* Description: Displays current roll of 5 dice and the roll number
* Input parameters: dice, roll number
* Returns: 
* Precondition: 
* Postcondition: Dice and roll number are displayed
*************************************************************************/
void displayDice(int *dice, int roll){
	int i = 0;
	printf("\nRoll Number %d\n", roll);
	printf("--------------\n");
	for(i = 0; i < 5; i++){
		printf("Die #%d:  %d\n", i+1, dice[i]);
	}
}

/*************************************************************************
* Date last modified: Feb 27th, 2013
* Description: Displays available combinations to user
* Input parameters: all combinations, combinations used
* Returns: 
* Precondition: 
* Postcondition: Each available combination is displayed
*************************************************************************/
void displayRoundMenu(char roundMenu[][20], int *combinationUsed){
	int i = 0;
	printf("\nAvailable Categories: \n");
	printf("----------------------\n");
	for(i = 0; i < 13; i++){
		if(combinationUsed[i] == AVAILABLE){
			printf("%s", roundMenu[i]);
		}
		printf("\n");
	}
}

/*************************************************************************
* Date last modified: Feb 27th, 2013
* Description: Prompts user as to whether or not they want to use their 
* current roll for one of their remaining combinations and validates their
* response
* Input parameters: 
* Returns: Y or N
* Precondition: 
* Postcondition: Valid choice (Y or N) is returned
*************************************************************************/
char useRoll(void){
	char use = '\0';
	do{
		flushall();
		printf("\nWould you like to use the current dice for one of\n");
		printf("your remaining game combinations? (Y/N) ");
		use = getchar();
		use = toupper(use);
		if(!(use == 'Y' || use == 'N')){
			printf("Invalid input, please enter Y or N\n");
		}
	} while(!(use == 'Y' || use == 'N'));
	return use;
}

/*************************************************************************
* Date last modified: Feb 27th, 2013
* Description: Prompts user for which combination they would like to use 
* their current roll for and validates the selection
* Input parameters: combinations used
* Returns: selection
* Precondition: There are combinations still available
* Postcondition: Valid selection is returned
*************************************************************************/
int getRoundSelection(int *combinationUsed){
	int selection = 0, used = -1, valid = 0;
	printf("\nWhich game combination would you like to use this roll for? ");
	scanf("%d", &selection);
	do{
		if(selection > 0 && selection <= NUM_COMBINATIONS){
			used = combinationUsed[selection-1];
		}
		if(used != AVAILABLE || selection > NUM_COMBINATIONS || selection <= 0){
			printf("Invalid selection. Choose an available number between 1 and 13: ");
			scanf("%d", &selection);
		}
		else{
			valid = 1;
		}
	}while(valid != 1);
	return selection;
}

/*************************************************************************
* Date last modified: Feb 27th, 2013
* Description: Sets players combination selection to not available
* Input parameters: combination selected, combinations used
* Returns: 
* Precondition: 
* Postcondition: selection is updated to unavailable
*************************************************************************/
void setRoundSelection(int selection, int *combinationUsed){
	combinationUsed[selection-1] = NOT_AVAILABLE;
}

/*************************************************************************
* Date last modified: Feb 27th, 2013
* Description: Calculates the points the player receives based on their 
* selected combination and current dice
* Input parameters: selected combination, current dice
* Returns: points for the current round
* Precondition: 
* Postcondition: correct amount of points is returned 
*************************************************************************/
int calculatePoints(int roundSelection, int *dice){
	int numPoints = 0, i = 0;
	int numEachDie[DIE_FACES] = {0};
	//Count the number of each value from dice
	for(i = 0; i < NUM_DICE; i++){
		numEachDie[dice[i]-1]++;
	}
	switch (roundSelection){
		// 1-6
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
			numPoints = roundSelection * numEachDie[roundSelection-1];
			break;
		// Three of a kind
		case 7:
			if(calculatePointsOfKind(3, numEachDie) == 1){
				numPoints = totalDice(dice);
			}
			break;
		// Four of a kind
		case 8:
			if(calculatePointsOfKind(4, numEachDie) == 1){
				numPoints = totalDice(dice);
			}
			break;
		// Full House
		case 9:
			numPoints = calculatePointsFullHouse(numEachDie);
			break;
		// Small straight
		case 10:
			numPoints = calculatePointsStraight(SMALL_STRAIGHT, numEachDie);
			break;
		// Large straight
		case 11:
			numPoints = calculatePointsStraight(LARGE_STRAIGHT, numEachDie);
			break;
		// Yahtzee
		case 12:
			numPoints = calculatePointsYahtzee(numEachDie);
			break;
		// Chance
		case 13:
			numPoints = totalDice(dice);
			break;
	}
	return numPoints;
}

/*************************************************************************
* Date last modified: Feb 27th, 2013
* Description: Determines whether or not player has rolled a 3 or 4 of a kind
* Input parameters: multiples needed (3 or 4), number of each die face
* Returns: 0 if user has not rolled a 3/4 of a kind, 1 if they have
* Precondition: 
* Postcondition: 0 or 1 is returned
*************************************************************************/
int calculatePointsOfKind(int countNeeded, int *numFaces){
	int i = 0, count = 0, hasDice = 0;
	for(i = 0; i < DIE_FACES; i++){
		if (numFaces[i] > count){
			count = numFaces[i];
		}
	}
	if(count >= countNeeded){
		hasDice = 1;
	}
	return hasDice;
}

/*************************************************************************
* Date last modified: Feb 27th, 2013
* Description: Determines if user has rolled a full house
* Input parameters: number of each die face
* Returns: 25 points if they do have a full house, 0 if not
* Precondition: 
* Postcondition: Either 25 or 0 is returned
*************************************************************************/
int calculatePointsFullHouse(int *numFaces){
	int i = 0, j = 0, points = 0;
	for(i = 0; i < DIE_FACES; i++){
		if(numFaces[i] == 3){
			for(j = 0; j < DIE_FACES; j++){
				if(numFaces[j] == 2){
					points = 25;
				}
			}
		}
	}
	return points;
}

/*************************************************************************
* Date last modified: Feb 27th, 2013
* Description: Determines if player has rolled a small or large straight
* Input parameters: size of straight, number of each die face
* Returns: if straight is rolled returns 30 for small, 40 for large, else 
* returns 0
* Precondition: 
* Postcondition: 0, 30, or 40 is returned
*************************************************************************/
int calculatePointsStraight(int straight, int *numFaces){
	int i = 0, count = 0, points = 0;
	for(i = 0; i < DIE_FACES; i++){
		if(numFaces[i] != 0){
			count++;
		}
		else if (count < straight){
			count = 0;
		}
	}
	if (count >= straight){
		if (straight == SMALL_STRAIGHT){
			points = 30;
		}
		else {
			points = 40;
		}
	}
	return points;
}

/*************************************************************************
* Date last modified: Feb 27th, 2013
* Description: Determine if player has rolled a yahtzee and return correct points
* Input parameters: number of die faces
* Returns: if yahtzee is rolled return 50 otherwise return 0
* Precondition: 
* Postcondition: 0, 30, or 40 is returned
*************************************************************************/
int calculatePointsYahtzee(int *numFaces){
	int i = 0, points = 0;
	for(i = 0; i < DIE_FACES; i++){
		if(numFaces[i] == 5){
			points = 50;
		}
	}
	return points;
}

/*************************************************************************
* Date last modified: Feb 27th, 2013
* Description: Adds points for current round to array of points for current
* player is round selection position
* Input parameters: combination selection, points for round, array of points
* Returns:  
* Precondition: 
* Postcondition: points array is updated with current rounds points
*************************************************************************/
void addPoints(int roundSelection, int currentPoints, int *points){
	points[roundSelection-1] = currentPoints;
}

/*************************************************************************
* Date last modified: Feb 27th, 2013
* Description: Calculates the total of all current dice
* Input parameters: array of dice
* Returns: dice total 
* Precondition: 
* Postcondition: total of dice is returned
*************************************************************************/
int totalDice(int *dice){
	int i = 0, points = 0;
	for(i = 0; i < NUM_DICE; i++){
		points += dice[i];
	}
	return points;
}

/*************************************************************************
* Date last modified: Feb 27th, 2013
* Description: Ask player how many dice they would like to keep, validate
* number of dice, and set that die to not available
* Input parameters: array of dice to keep
* Returns: 
* Precondition: 
* Postcondition: correct number and position of each die is set to not available
*************************************************************************/
void setKeepDice(int *keep){
	int numKeep = 0, i = 0, die = 0;

	// Get number user would like to keep
	printf("\nHow many dice would you like to keep? ");
	scanf("%d", &numKeep);
	while(numKeep < 0 || numKeep > NUM_DICE - 1){
		printf("\nInvalid number, enter a number between 0 and 4: ");
		scanf("%d", &numKeep);
	}
	for(i = 0; i < numKeep; i++){
		printf("Enter the number of one die you would like to keep: ");
		scanf("%d", &die);
		while(die < 1 || die > NUM_DICE){
			printf("\nInvalid selection. Enter a die between 1 and 5: ");
			scanf("%d", &die);
		}
		keep[die-1] = NOT_AVAILABLE;
	}

}

/*************************************************************************
* Date last modified: Feb 27th, 2013
* Description: Reset array of dice to keep to all available
* Input parameters: array of dice to keep
* Returns: 
* Precondition: 
* Postcondition: Entire array is reset to avaialable
*************************************************************************/
void resetKeepDice(int *keep){
	int i = 0;
	for(i = 0; i < NUM_DICE; i++){
		keep[i] = AVAILABLE;
	}
}

/*************************************************************************
* Date last modified: Feb 27th, 2013
* Description: Calculate total number of points for the game for each player
* Input parameters: Array of each players points for each round, array of total points
* Returns: 
* Precondition: 
* Postcondition: Array of total points is updated with total game points
*************************************************************************/
void calculateTotalPoints(int points[][NUM_COMBINATIONS], int *totalPoints){
	int totPointsBegin = 0, totPointsEnd = 0, bonus = 0, i = 0, j = 0;
	for(i = 0; i < PLAYERS; i++){
		totPointsBegin = 0;
		totPointsEnd = 0;
		bonus = 0;
		for(j = 0; j < NUM_COMBINATIONS; j++){
			if (j < 6){
				totPointsBegin += points[i][j];
			}
			else{
				totPointsEnd += points[i][j];
			}
		}
		if (totPointsBegin >= 63){
			bonus = 35;
		}
		totalPoints[i] = (bonus + totPointsBegin + totPointsEnd);
	}

}

/*************************************************************************
* Date last modified: Feb 27th, 2013
* Description: Display the total points for each player and declare the winner
* Input parameters: array of total points for each player
* Returns: 
* Precondition: 
* Postcondition: points for each player are displayed and winner is announced
*************************************************************************/
void displayWinner(int *totalPoints){
	int i = 0, highest = -1;
	for(i = 0; i < PLAYERS; i++){
		if(totalPoints[i] > highest){
			highest = i;
		}
		printf("\nTotal points for player %d: %d", i+1, totalPoints[i]);
	}
	printf("\nPlayer %d, You Win!!!", highest+1);
}

/*************************************************************************
* Date last modified: Feb 27th, 2013
* Description: Clears input buffer if not already empty
* Input parameters: 
* Returns: 
* Precondition: 
* Postcondition: Input buffer is empty
*************************************************************************/
