#ifndef CRAPS_H_INCLUDE
#define CRAPS_H_INCLUDE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printGameRules(void);
double getBankBalance(void);
double getWagerAmount(void);
int checkWagerAmount(double wager, double balance);
int rollDie(void);
int calculateSumDice(int die1, int die2);
int isWinLossOrPoint(int diceSum);
int isPointLossOrNeither(int diceSum, int point);
double adjustBankBalance(double balance, double wager, int addSubtract);
void chatterMessage(int numberRolls, int winLoss, double initBalance, double currentBalance);
double playRound(double balance);
double addMoney(double balance);
void printRoll(int roll, int diceSum);
void displayGameMenu(void);
int getChoice(void);

#endif

