#include "Craps.h"
/*************************************************************************************
* Programmer: Kristin Onorati
* Class: CPTS 121, Spring 2013, Lab Section 1
* Programming Assignment: 4
* Date: February 15th, 2013
* Description: This program runs a craps game allowing user to bet, add money to bank
* balance, check bank balance. Displays messages based on win/loss record, rolls 2
* dice, and determines win/loss/or no point.
**************************************************************************************/

int main(void){
	double balance = 0, wager = 0;
	int choice = 0;

	printGameRules();
	balance = getBankBalance();
	
	//Display game menu and allow user to continually choose options until they quit
	while(choice != 4){
		displayGameMenu();
		choice = getChoice();
		switch (choice){
			case 1: 
				printf("Current bank balance: $%.2lf\n", balance);
				break;
			case 2: 
				balance = addMoney(balance);
				printf("You now have $%.2lf in the bank\n", balance);
				break;
			case 3:
				balance = playRound(balance);
				break;
			case 4:
				break;
			default:
				printf("\nMenu choice is invalid, Please choose a number between 1 and 4\n"); //Validates menu choice
				break;
		}

	}


	return 0;
}