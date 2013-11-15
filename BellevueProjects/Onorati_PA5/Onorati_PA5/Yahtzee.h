#ifndef YAHTZEE_H
#define YAHTZEE_H
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#define AVAILABLE 0
#define NOT_AVAILABLE 1
#define PLAYERS 2
#define NUM_COMBINATIONS 13
#define NUM_DICE 5
#define DIE_FACES 6
#define SMALL_STRAIGHT 4
#define LARGE_STRAIGHT 5

void displayGameMenu(void);
void displayRules(void);
int getMenuOption(void);
int rollDie(void);
void setDice(int *dice, int *keep);
void displayDice(int *dice, int roll);
void displayRoundMenu(char roundMenu[][20], int *combinationUsed);
char useRoll(void);
int getRoundSelection(int *combinationUsed);
void setRoundSelection(int selection, int *combinationUsed);
int calculatePoints(int roundSelection, int *dice);
int calculatePointsOfKind(int countNeeded, int *numFaces);
int calculatePointsFullHouse(int *numFaces);
int calculatePointsStraight(int staightLength, int *numFaces);
int calculatePointsYahtzee(int *numFaces);
void addPoints(int roundSelection, int currentPoints, int *points);
int totalDice(int *dice);
void setKeepDice(int *keep);
void resetKeepDice(int *keep);
void calculateTotalPoints(int points[][NUM_COMBINATIONS], int *totalPoints);
void displayWinner(int *totalPoints);





#endif