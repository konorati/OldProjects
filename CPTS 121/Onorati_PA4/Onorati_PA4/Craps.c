#include "Craps.h"

/*************************************************************************
* Date last modified: Feb 15th, 2013
* Description: Prints rules of craps to console
* Input parameters: None
* Returns: None
* Precondition: 
* Postcondition: Rules are displayed
*************************************************************************/
void printGameRules(void){
	printf("Rules:\n\t1: Player rolls 2 six-sided dice\n\t2: First throw\n\t\t- 7 or 11 = win\n\t\t- 2, 3, or 12 = lose\n\t\t- Other = point");
	printf("\n\t3: After first throw\n\t\t- 7 = lose\n\t\t- Point = win\n\t\t- Other = Keep rolling\n");
}

/*************************************************************************
* Date last modified: Feb 15th, 2013
* Description: Prompts user for starting bank balance
* Input parameters: None
* Returns: bank balance (double)
* Precondition: 
* Postcondition: balance is returned
*************************************************************************/
double getBankBalance(void){
	double balance = 0;
	printf("\nEnter starting bank balance for player 1: ");
	scanf("%lf", &balance);
	return balance;
}

/*************************************************************************
* Date last modified: Feb 15th, 2013
* Description: Prompts user for single wager for current roll
* Input parameters: None
* Returns: Wager (double)
* Precondition: 
* Postcondition: Positive wager is returned
*************************************************************************/
double getWagerAmount(void){
	double wager = -1;
	while (wager < 0){
		printf("\nEnter your wager for this roll: ");
		scanf("%lf", &wager);
		if(wager < 0){
			printf("\nWager must be greater than or equal to 0.");
		} 
	}

	return wager;
}

/*************************************************************************
* Date last modified: Feb 15th, 2013
* Description: Determines if player has enough money for wager
* Input parameters: Wager (double), bank balance (double)
* Returns: 0 if not enough money, 1 if user has enough money for wager
* Precondition: 
* Postcondition: 0 or 1 is returned
*************************************************************************/
int checkWagerAmount(double wager, double balance){
	int enoughMoney = 0;
	if (balance >= wager){
		enoughMoney = 1;
	}
	return enoughMoney;
}

/*************************************************************************
* Date last modified: Feb 15th, 2013
* Description: Assigns a random number (1-6) to one die
* Input parameters: 
* Returns: Die roll (1-6)
* Precondition: 
* Postcondition: Random integer between 1 and 6 is returned
*************************************************************************/
int rollDie(void){
	int roll = 0;
	srand((unsigned int) time(NULL));
	roll = (rand() % 6) + 1;
	return roll;
}

/*************************************************************************
* Date last modified: Feb 15th, 2013
* Description: Calculates the sum of 2 dice
* Input parameters: die 1 (int), die 2 (int)
* Returns: sum of dice (int)
* Precondition: die1 and die2 are positive integers from 1-6
* Postcondition: sum of dice is returned
*************************************************************************/
int calculateSumDice(int die1, int die2){
	int diceSum = die1 + die2;
	return diceSum;
}

/*************************************************************************
* Date last modified: Feb 15th, 2013
* Description: Determines if first roll of game is a win, loss, or point
* Input parameters: sum of dice (integer)
* Returns: 1 if win, 0 if loss, -1 if other
* Precondition: 
* Postcondition: 1, 0, or -1 is returned
*************************************************************************/
int isWinLossOrPoint(int diceSum){
	int isWin = -1; //Point
	if(diceSum == 7 || diceSum == 11){ //Win
		isWin = 1;
	}
	if(diceSum == 2 || diceSum == 3 || diceSum == 12){ //Loss
		isWin = 0;
	}
	return isWin;
}

/*************************************************************************
* Date last modified: Feb 15th, 2013
* Description: Determines if subsequent roll is point, loss, or neither
* Input parameters: sum of dice (int), current point (int)
* Returns: 1 if point, 0 if loss, -1 if neither
* Precondition: 
* Postcondition: returns 1, 0, or -1
*************************************************************************/
int isPointLossOrNeither(int diceSum, int point){
	int isPoint = -1;
	if(diceSum == point){ //Win
		isPoint = 1;
	}
	else if(diceSum == 7){ //Loss
		isPoint = 0;
	}
	return isPoint;
}

/*************************************************************************
* Date last modified: Feb 15th, 2013
* Description: Adjusts bank balance based on wager and win or loss
* Input parameters: Current bank balance (double), total wager (double),
*	win (1) or loss (0) (int)
* Returns: New bank balance (double)
* Precondition: 
* Postcondition: New balance is returned
*************************************************************************/
double adjustBankBalance(double balance, double wager, int addSubtract){
	if(addSubtract = 1){
		balance += wager;
	}
	else if(addSubtract = 0){
		balance -= wager;
	}
	return balance;
}

/*************************************************************************
* Date last modified: Feb 15th, 2013
* Description: Prints message based on number of rolls, bank balance, 
*	total wager, and whether the roll is a win or loss
* Input parameters: Number of rolls this game (int), current balance (double)
*	current total wager(double), whether first roll is win (1) or loss (0)
*	or neither (other int)
* Returns: None
* Precondition: 
* Postcondition: Message is displayed
*************************************************************************/
void chatterMessage(int numberRolls, int winLoss, double initBalance, double totalWager){
	if (numberRolls == 1){ //If this is the first roll
		switch(winLoss){
			case 1: 
				printf("\nWinner Winner Chicken Dinner!\n");
				break;
			case 0:
				printf("\nBetter luck next time...\n");
				break;
			default:
				printf("\nTime to start betting the big bucks!\n");
				break;
		}
	}
	else{
		switch(winLoss){
			case 1:
				printf("\nWINNER!!!!");
				break;
			case 0:
				printf("\nYikes...Losing sure isn't fun");
				break;
			default:
				if ((totalWager/initBalance) > .5){
					printf("\nYou've got a lot of money on the line...\nI hope you're feeling lucky!\n");
				}
				else{
					printf("\nCome on! You can bet more than that\n");
				}
				break;
		}
	}
	
}

/*************************************************************************
* Date last modified: Feb 15th, 2013
* Description: Prints the current roll to the console
* Input parameters: Roll number (int), sum of dice (int)
* Returns: None
* Precondition: 
* Postcondition: Roll number and dice sum is displayed on console
*************************************************************************/
void printRoll(int roll, int diceSum){
	printf("\nRoll %d: You rolled a %d", roll, diceSum);
}

/*************************************************************************
* Date last modified: Feb 15th, 2013
* Description: Plays through on round of craps: Gets wager and checks
*	to see if wager is possible, rolls dice until a win or loss occurs,
*	prints messages to player, and adjusts bank account
* Input parameters: Current bank balance(double)
* Returns: New bank balance (double)
* Precondition: 
* Postcondition: Balance is adjusted and returned based on win/loss
*************************************************************************/
double playRound(double balance){
	int die1 = 0, die2 = 0, diceSum = 0, rollNum = 0, point = 0;
	int outcome = -1;
	double wager = 0, totWager = 0;
	do{
		wager = getWagerAmount();
		while(!checkWagerAmount(wager + totWager, balance)){  //Validate wager amount
			printf("You don't have enough money for that wager! Choose a smaller amount!");
			wager = getWagerAmount();
		}
		totWager += wager;
		die1 = rollDie();
		die2 = rollDie();
		diceSum = calculateSumDice(die1, die2);
		rollNum++;
		if(rollNum != 1){							//Display point if not first roll
			printf("\nPoint is: %d", point);
		}
		printRoll(rollNum, diceSum);
		if(rollNum == 1){							//If this is the first roll
			outcome = isWinLossOrPoint(diceSum);
			if(outcome == -1){
				point = diceSum;
			}
		}
		else{										//If there is already a point
			outcome = isPointLossOrNeither(diceSum, point);
		}
		chatterMessage(rollNum, outcome, balance, totWager);

	} while(outcome == -1);
	balance = adjustBankBalance(balance, totWager, outcome);
	printf("\nNew bank balance = $%.2lf", balance);
	return balance;
}

/*************************************************************************
* Date last modified: Feb 15th, 2013
* Description: Prompts user to add money and then adds money to bank account
* Input parameters: current bank balance (double)
* Returns: New bank balance (double)
* Precondition: 
* Postcondition: New bank balance is returned
*************************************************************************/
double addMoney(double balance){
	double amount = 0, newBalance = 0;
	printf("\nHow much money would you like to add to your account? ");
	scanf("%lf", &amount);
	newBalance = balance + amount;
	return newBalance;
}

/*************************************************************************
* Date last modified: Feb 15th, 2013
* Description: Displays game menu to player
* Input parameters: None
* Returns: None
* Precondition: 
* Postcondition: Menu is displayed
*************************************************************************/
void displayGameMenu(void){
	printf("\n\nMenu Options:\n\t1. Check bank balance\n\t2. Add money to bank balance\n\t3. Play craps\n\t4. Exit game\n");
}

/*************************************************************************
* Date last modified: Feb 15th, 2013
* Description: Prompts user for game menu choice
* Input parameters: None
* Returns: Menu choice (int)
* Precondition: 
* Postcondition: Game choice is returned
*************************************************************************/
int getChoice(void){
	int choice = 0;
	printf("Which option would you like: ");
	scanf("%d", &choice);
	return choice;
}

