// Authors: Deitel & Deitel - C How to Program

#include "Poker.h"

/*************************************************************************************
* Programmer: Kristin Onorati
* Class: CPTS 121, Spring 2013, Lab Section 1
* Programming Assignment: 7
* Date: April 17th, 2013
* Description: This program runs a 5 card draw poker game for 1 player and a computer. 
**************************************************************************************/

int main (void)
{
	/* initialize suit array */
	const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

	/* initialize face array */
	const char *face[NUM_FACES] = {"Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King", "Ace"};

	/* initalize deck array */
	int deck[SUITS][NUM_FACES] = {0};

	/* initialize winning card arrays */
	int winningCards[13] = {0}, winningCardsComp[13] = {0};

	// Initialize suit and face arrays to store current hand info
	int numSuits[SUITS] = {0};
	int numFaces[NUM_FACES] = {0};
	int numSuitsComp[SUITS] = {0};
	int numFacesComp[NUM_FACES] = {0};
	int keepCards[HAND_SIZE] = {0};
	int winner = -1, wins = 0, losses = 0, choice = 0;

	// initialize 2 hands
	Card hand1[HAND_SIZE] = {{0, 0, 0}};
	Card hand2[HAND_SIZE] = {{0, 0, 0}};
	srand ((unsigned) time (NULL)); /* seed random-number generator */

	while(choice != 3){
		displayMenu();
		choice = getMenuChoice();
		if(choice == 1){
			system("cls");
			winner = -1;
			// Shuffle deck
			resetDeck(deck);
			shuffle (deck);
			resetKeepCards(keepCards);
	
			// Deal player hand
			deal (deck, hand1, 1, keepCards);

			// Deal computer hand
			deal(deck, hand2, 0, keepCards);
			resetCardArrays(numSuits, numFaces);
			resetCardArrays(numSuitsComp, numFacesComp);
			setCardArrays(numSuitsComp, numFacesComp, hand2);

			// Print player and computer hands
			printf("Your hand:\n");
			printf("-------------------------\n");
			printHand(hand1, face, suit);
				/* **For testing**
				printf("\nComputer's hand:\n");
				printf("-------------------------\n");
				printHand(hand2, face, suit);*/
			printSecretHand();

			// Get cards player would like to keep
			getKeepCards(keepCards);

			// Deal replacement cards to player
			deal(deck, hand1, 0, keepCards);

			// Determine which cards computer will keep
			resetKeepCards(keepCards);
			determineCompKeepCards(keepCards, numSuitsComp, numFacesComp, hand2);

			// Deal replacement cards to computer
			deal(deck, hand2, 0, keepCards);

			// Print new hands
			system("cls");
			printf("Your hand:\n");
			printf("-------------------------\n");
			printHand(hand1, face, suit);
			printf("\nComputer's hand:\n");
			printf("-------------------------\n");
			printHand(hand2, face, suit);

			// Determine winner
			resetCardArrays(numSuits, numFaces);
			resetCardArrays(numSuitsComp, numFacesComp);
			setCardArrays(numSuitsComp, numFacesComp, hand2);
			setCardArrays(numSuits, numFaces, hand1);
			setDetermineWinnerArray(numSuits, numFaces, winningCards);
			setDetermineWinnerArray(numSuitsComp, numFacesComp, winningCardsComp);
			winner = determineWinner(winningCards, winningCardsComp);

			// Display winner
			if(winner == 1){
				printf("\nYou win!\n");
				wins++;
			}
			else if(winner == 0){
				printf("\nComputer wins\n");
				losses++;
			}
			system("pause");
		}
		if(choice == 2){
			displayWinsLosses(wins, losses);
		}
	}
	return 0;
}



