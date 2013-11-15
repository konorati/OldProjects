#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct sentence{
	char *noun1;
	char *noun2;
	char *preposition;
	char *article1;
	char *article2;
	char *verb;
}Sentence;

typedef enum boolean{
	FALSE, TRUE
}Boolean;

typedef struct coordinate{
	int row;
	int column;
}Coordinate;

typedef struct cell{
	Boolean occupied;
	char symbol;
	Coordinate location;
}Cell;

typedef struct gameInfo{
	int wins;
	int losses;
	int gamesPlayed;
}GameInfo;



void setSentence(Sentence *sentence, char article[][20], char noun[][20], char verb[][20], char preposition[][20]);
void createSentence(Sentence build, char *sentence);
int getNumCells(void);
void printBoard(Cell board[][10], int numCells);
void getSpot(Cell board[][10], int numCells, int *spot);
int isValidSpot(Cell board[][10], int *spot);
void setTile(Cell board[][10], int *spot, int player);
int isWin(Cell board[][10], int numCells);


#endif