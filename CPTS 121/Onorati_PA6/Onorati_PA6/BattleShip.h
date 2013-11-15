#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#define ROWS 10
#define COLUMNS 10
#define NUM_SHIPS 5
#define NUM_DIRECTIONS 4
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define CARRIER 0
#define BATTLESHIP 1
#define CRUISER 2
#define SUBMARINE 3
#define DESTROYER 4
#define NUM_PLAYERS 2

typedef struct ship{
	int size;
	char *name;
	char token;
}Ship;

typedef struct stats{
	int hits;
	int misses;
	int totShots;
	double hitMissRatio;
	int wins;
	int losses;
}Stats;

	

void welcomeScreen(void);
int getMenuSelection(void);
void displayRules(void);
void initializeBoard(char board[][COLUMNS]);
void printBoard(char board[][COLUMNS], int yourBoard);
int selectWhoStartsFirst(void);
int getPlaceShipsDecision(void);
void manuallyPlaceShips(char board[][COLUMNS], Ship *ships);
void randomlyPlaceShips(char board[][COLUMNS], Ship *ships);
void getShot(char board[][COLUMNS], int *shot);
int isHit(char board[][COLUMNS], int *shot);
void updateBoard(char boar[][COLUMNS], int *shot, int hit);
int validateShot(char board[][COLUMNS], int *shot);
int isValidShipSpot(char board[][COLUMNS], int *placement, int shipSize, int *direction);
void setShip(char board[][COLUMNS], int *placement, int shipSize, char shipName, int direction);
void resetShot(int *shot);
void getRandomShotEasy(char board[][COLUMNS], int *shot);
int isShipSunk(char board[][COLUMNS], int *shot);
int isGameOver(char board[][COLUMNS]);
void resetValidDirection(int *direction);
void initializeShip(Ship *ship, int size, char *name, char token);
void getRandomShotMedium(char board[][COLUMNS], int *shot, int sunk);
void getRandomShotHard(char board[][COLUMNS], int *shot, int sunk);
int getDifficulty(void);
int isOffBoard(int *shot);
void writeToFile(FILE *outputFile, int player, int *shot, int hit, int sunk, Ship *ships);
void outputStats(FILE *outputFile, Stats user, Stats computer, int winner);


#endif