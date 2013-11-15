#include "Yahtzee.h"

/*************************************************************************************
* Programmer: Kristin Onorati
* Class: CPTS 121, Spring 2013, Lab Section 1
* Programming Assignment: 5
* Date: February 27th, 2013
* Description: This program runs a yahtzee game for 2 players (more can be added before
* starting the program. Game allows user to roll dice, decide which dice to keep, and 
* decide which combination to use dice for. Displays points for each player for each
* round and displays total points and determines winner after 13 rounds
**************************************************************************************/

int main(void){

	int combinationsUsed[PLAYERS][NUM_COMBINATIONS] = {0},
		points[PLAYERS][NUM_COMBINATIONS] = {0},
		dice[NUM_DICE] = {0},
		keepDice[NUM_DICE] = {0},
		totalPoints[PLAYERS] = {0};

	char roundMenu[NUM_COMBINATIONS][20] = {
	{"1. 1's"}, 
	{"2. 2's"},
	{"3. 3's"},
	{"4. 4's"},
	{"5. 5's"},
	{"6. 6's"},
	{"7. Three-of-a-Kind"},
	{"8. Four-of-a-Kind"},
	{"9. Full House"},
	{"10. Small Straight"},
	{"11. Large Straight"},
	{"12. Yahtzee"},
	{"13. Chance"}
};

	int menuSelection = 0, rollNum = 1, roundNum = 1, playerNum = 1, roundSelection = 0, currentPoints = 0;
	char useDice = '\0', enter = '\0';
	srand((unsigned int) time(NULL));

	do {
		system("cls"); // Clear console
		displayGameMenu();
		menuSelection = getMenuOption();
		switch (menuSelection){
			case 1: 
				system("cls");
				displayRules();
				flushall(); // Clear buffer
				printf("\nPress enter to return to menu ");
				enter = getchar();
				break;
			case 2: 
				while (roundNum <= 13){
					system("cls");
					while (rollNum <= 3){
						system("cls");
						printf("\nRound Number %d", roundNum);
						printf("\n--------------");
						flushall(); // Clear buffer
						printf("\nPlayer %d's Turn, Press enter to roll the dice.", playerNum);
						enter = getchar();
						setDice(dice, keepDice);
						displayDice(dice, rollNum);
						// If not 3rd roll ask if they want to use current dice or continue rolling
						if(rollNum < 3){ 
							useDice = useRoll();
						}
						// If third roll they must use the current dice
						else{ 
							useDice = 'Y';
						}
						if(useDice == 'Y'){
							// Get which combination they would like to use the current dice for
							displayRoundMenu(roundMenu, combinationsUsed[playerNum-1]);
							roundSelection = getRoundSelection(combinationsUsed[playerNum-1]);
							// Set combination chosen to used
							setRoundSelection(roundSelection, combinationsUsed[playerNum-1]);
							// Calculate points for current dice and combination, set points, and display points
							currentPoints = calculatePoints(roundSelection, dice);
							addPoints(roundSelection, currentPoints, points[playerNum-1]);
							printf("Points for player %d for this round are %d", playerNum, currentPoints);
							flushall(); // Clear buffer
							printf("\nPress enter to continue");
							enter = getchar();
							rollNum = 4;
						}
						else{
							resetKeepDice(keepDice);
							setKeepDice(keepDice);	
							rollNum++;
						}
					}
					if(playerNum == PLAYERS){
						playerNum = 1;
						roundNum++;
					}
					else{
						playerNum++;
					}
					rollNum = 1;
					resetKeepDice(keepDice);
				}
				system("cls");
				calculateTotalPoints(points, totalPoints);
				displayWinner(totalPoints);
				flushall();
				printf("\nPress any key to return to the main menu ");
				break;
			case 3:
			default:
				printf("Thank you for playing Yahtzee!\n");
				break;
		}
	} while(menuSelection != 3);
	

	return 0;
}
