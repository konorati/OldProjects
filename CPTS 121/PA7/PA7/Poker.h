#ifndef POKER_H
#define POKER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define HAND_SIZE 5
#define SUITS 4
#define NUM_FACES 13

typedef struct card{
	int cardNum;
	int faceIndex;
	int suitIndex;
}Card;

void shuffle (int wDeck[][NUM_FACES]);
void resetDeck(int wDeck[][NUM_FACES]);
void deal (int wDeck[][NUM_FACES], Card hand[HAND_SIZE], int newGame, int *keepCards);
void printHand(Card hand[HAND_SIZE], const char *wFace[], const char *wSuit[]);
int containsPair(int *faces);
int containsTwoPair(int *faces);
int containsThreeOfAKind(int *faces);
int containsFourOfAKind(int *faces);
int containsFlush(int *suits);
int containsStraight(int *faces);
int hasFourToAFlush(int *suits);
void resetCardArrays(int *suits, int *faces);
void setCardArrays(int *suits, int *faces, Card hand[HAND_SIZE]);
void getKeepCards(int *keepCards);
void resetKeepCards(int *keepCards);
void keepAllCards(int *keepCards);
void printSecretHand(void);
void determineCompKeepCards(int *keepCards, int *suits, int *faces, Card hand[HAND_SIZE]);
int determineWinner(int *playerCards, int *compCards);
void setDetermineWinnerArray(int *suits, int *faces, int *winnerList);
void displayMenu(void);
int getMenuChoice(void);
void displayWinsLosses(int wins, int losses);



#endif