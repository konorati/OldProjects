#include "Poker.h"

/*************************************************************************
* Date last modified: April 17th, 2013
* Description: Shuffles a deck of 52 cards
* Input parameters: Deck (2d array with 4 rows & 13 columns)
* Returns: 
* Precondition: Random number has been seeded, array is of appropriate size
* Postcondition: Cards 1-52 are randomly placed within array
*************************************************************************/
void shuffle (int wDeck[][NUM_FACES])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand () % 4;
			column = rand () % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}
/*************************************************************************
* Date last modified: April 17th, 2013
* Description: Resets each spot in deck to 0 so deck can be reshuffled
* Input parameters: Deck (2d array with 4 rows & 13 columns)
* Returns: 
* Precondition: array is of appropriate size
* Postcondition: Each index of array is set to 0
*************************************************************************/
void resetDeck(int wDeck[][NUM_FACES]){
	int row = 0, column = 0;
	for(row = 0; row < SUITS; row++){
		for(column = 0; column < NUM_FACES; column++){
			wDeck[row][column] = 0;
		}
	}
}
/*************************************************************************
* Date last modified: April 17th, 2013
* Description: Deals 5 cards to players hand, starting at card just after last
*     card dealt. If new game starts back at first card
* Input parameters: Deck (2d array with 4 rows & 13 columns), players hand,
*     new game flag (1 if new game, 0 if not), array of card numbers player would
*     like to keep.
* Returns: 
* Precondition: Deck has already been shuffled
* Postcondition: New cards are dealt into slots the player did not want to keep
*************************************************************************/
void deal (int wDeck[][NUM_FACES], Card hand[HAND_SIZE], int newGame, int *keepCards)
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 1;   /* card counter */
	int handIndex = 0;
	static int start = 0;

	if(newGame){
		start = 1;
	}
 
	/* deal each of the next 5 of the 52 cards */
	for(card = start; card <= 52, handIndex < 5; card++, handIndex++, start++){
		if(!keepCards[handIndex]){
			/* loop through rows of wDeck */
			for (row = 0; row <= 3; row++)
			{
				/* loop through columns of wDeck for current row */
				for (column = 0; column <= 12; column++)
				{
					/* if slot contains current card, display card */
					if (wDeck[row][column] == card){
						hand[handIndex].cardNum = handIndex + 1;
						hand[handIndex].faceIndex = column;
						hand[handIndex].suitIndex = row;
					}
				}
			}
		}
	}
}
/*************************************************************************
* Date last modified: April 17th, 2013
* Description: Prints the players hand to the console
* Input parameters: Players hand, array of strings for card face values,
*    array of strings for card suits.
* Returns: 
* Precondition: Cards have been dealt to hand
* Postcondition: Current hand is displayed to console
*************************************************************************/
void printHand(Card hand[HAND_SIZE], const char *wFace[], const char *wSuit[]){
	int i = 0;
	for(i = 0; i < HAND_SIZE; i++){
		printf("Card %d: %s of %s\n", i+1, wFace[hand[i].faceIndex], wSuit[hand[i].suitIndex]);
	}

}
/*************************************************************************
* Date last modified: April 17th, 2013
* Description: Determines if hand contains a pair
* Input parameters: integer array of number of each face value in hand
* Returns: face value of pair (if pair exists), -1 if no pair 
*		**NOTE: Returns face value of lowest pair if 2 pairs exist
* Precondition: array of face values has been set
* Postcondition: -1 or 0-12 is returned
*************************************************************************/
int containsPair(int *faces){
	int pair = -1, i = 0;
	while(pair == -1 && i < 13){
		if(faces[i] == 2){
			pair = i;
		}
		i++;
	}
	return pair;
}
/*************************************************************************
* Date last modified: April 17th, 2013
* Description: Determines if hand contains two pairs
* Input parameters: integer array of number of each face value in hand
* Returns: face value of second pair (if second pair exists), -1 if not two pairs 
*		**NOTE: Returns face value of highest pair if 2 pairs exist
* Precondition: array of face values has been set
* Postcondition: -1 or 0-12 is returned
*************************************************************************/
int containsTwoPair(int *faces){
	int pair = -1, count = 0, i = 0;
	while(count != 2 && i < 13){
		if(faces[i] == 2){
			count++;
			if(count == 2){
				pair = i;
			}
		}
		i++;
	}
	return pair;
}
/*************************************************************************
* Date last modified: April 17th, 2013
* Description: Determines if hand contains three of a kind
* Input parameters: integer array of number of each face value in hand
* Returns: face value of three of a kind (if triple exists), -1 if no triple 
* Precondition: array of face values has been set
* Postcondition: -1 or 0-12 is returned
*************************************************************************/
int containsThreeOfAKind(int *faces){
	int three = -1, i = 0;
	while(three == -1 && i < 13){
		if(faces[i] == 3){
			three = i;
		}
		i++;
	}
	return three;
}
/*************************************************************************
* Date last modified: April 17th, 2013
* Description: Determines if hand contains four of a kind
* Input parameters: integer array of number of each face value in hand
* Returns: face value of four of a kind (if quadruple exists), -1 if no quadruple 
* Precondition: array of face values has been set
* Postcondition: -1 or 0-12 is returned
*************************************************************************/
int containsFourOfAKind(int *faces){
	int four = -1, i = 0;
	while(four == -1 && i < 13){
		if(faces[i] == 4){
			four = i;
		}
		i++;
	}
	return four;
}
/*************************************************************************
* Date last modified: April 17th, 2013
* Description: Determines if hand contains a flush
* Input parameters: integer array of number of each suit in hand
* Returns: suit index of flush (if pair exists), -1 if no flush
* Precondition: array of suit values has been set
* Postcondition: -1 or 0-3 is returned
*************************************************************************/
int containsFlush(int *suits){
	int flush = -1, i = 0;
	while(flush == -1 && i < 4){
		if(suits[i] == 5){
			flush = i;
		}
		i++;
	}
	return flush;
}
/*************************************************************************
* Date last modified: April 17th, 2013
* Description: Determines if hand contains a straight
* Input parameters: integer array of number of each face value in hand
* Returns: face value of highest card in straight (if straight exists), -1 if no straight 
* Precondition: array of face values has been set
* Postcondition: -1 or 4-12 is returned
*************************************************************************/
int containsStraight(int *faces){
	int i = 0, straight = 0, count = 0;
	for(i = 0; i < NUM_FACES; i++){
		if(faces[i] > 0){
			count++;
			if(count == 5){
				straight = i;
			}
		}
		else{
			count = 0;
		}
	}
	return straight;
}
/*************************************************************************
* Date last modified: April 17th, 2013
* Description: Determines if hand contains four cards of the same suit
* Input parameters: integer array of number of each suit in hand
* Returns: suit index of almost flush (if almost flush exists), -1 if no almost flush 
* Precondition: array of suit values has been set
* Postcondition: -1 or 0-3 is returned
*************************************************************************/
int hasFourToAFlush(int *suits){
	int flush = -1, i = 0;
	while(flush == -1 && i < 4){
		if(suits[i] == 4){
			flush = i;
		}
		i++;
	}
	return flush;
}
/*************************************************************************
* Date last modified: April 17th, 2013
* Description: Resets the arrays of number of each face value and number of each suit
* Input parameters: integer array of number of each face value in hand, and integer
*     array of number of each suit in hand
* Returns: 
* Precondition: 
* Postcondition: array of faces and suits have been set to 0
*************************************************************************/
void resetCardArrays(int *suits, int *faces){
	int i = 0;
	for(i = 0; i < 4; i++){
		suits[i] = 0;
	}
	for(i = 0; i < 13; i++){
		faces[i] = 0;
	}
}
/*************************************************************************
* Date last modified: April 17th, 2013
* Description: Sets arrays of number of each face value and number of each suit
* Input parameters: integer array of number of each face value in hand, array of
*     number of each suit in hand, current players hand
* Returns: 
* Precondition: suits and faces array are set to 0, current hand has been dealt
* Postcondition: suits and faces array have been updated to reflect cards in hand
*************************************************************************/
void setCardArrays(int *suits, int *faces, Card hand[HAND_SIZE]){
	int i = 0;
	for(i = 0; i < HAND_SIZE; i++){
		suits[hand[i].suitIndex]++;
		faces[hand[i].faceIndex]++;
	}
}
/*************************************************************************
* Date last modified: April 17th, 2013
* Description: Get user input as to which cards they want to keep (1 = keep, 0 = don't keep)
* Input parameters: int array, same size as hand, to store keep flags
* Precondition: array of keep cards was reset to 0
* Postcondition: array of keep cards is updated to reflect cards player wants to keep
*************************************************************************/
void getKeepCards(int *keepCards){
	int numCards = -1, card = -1, i = 0;
	char words[5][20] = {"first", "second", "third", "fourth", "fifth"};
	do{
		printf("How many cards would you like to keep? ");
		scanf("%d", &numCards);
		if(numCards < 0 || numCards > 5){
			printf("Invalid number of cards, enter a number between 0 and 5\n");
		}
	}while(numCards < 0 || numCards > 5);
	for(i = 0; i < numCards; i++){
		do{
			printf("What is the %s card you would like to keep <enter card number 1-5>: ", words[i]);
			scanf("%d", &card);
			if(card < 1 || card > 5){
				printf("Invalid card number, enter a number between 1 and 5\n");
			}
			else if(keepCards[card-1]){
				printf("You have already selected to keep this card, choose another card\n");
			}
		}while(card < 1 || card > 5 || keepCards[card-1]);
		keepCards[card-1] = 1;
	}
}
/*************************************************************************
* Date last modified: April 17th, 2013
* Description: Resets array of cards the player wants to keep to 0
* Input parameters: integer array of keep cards
* Returns: 
* Precondition: 
* Postcondition: array of keep cards is reset to 0
*************************************************************************/
void resetKeepCards(int *keepCards){
	int i = 0;
	for(i = 0; i < HAND_SIZE; i++){
		keepCards[i] = 0;
	}
}
/*************************************************************************
* Date last modified: April 17th, 2013
* Description: Sets all card in keep card array to keep (1)
* Input parameters: integer array of cards to keep
* Returns: 
* Precondition: 
* Postcondition: Entire keep card array is set to 1
*************************************************************************/
void keepAllCards(int *keepCards){
	int i =  0;
	for(i = 0; i < HAND_SIZE; i++){
		keepCards[i] = 1;
	}
}
/*************************************************************************
* Date last modified: April 17th, 2013
* Description: Prints computers hand so player can't see it (cards come up as a series of x's)
* Input parameters: 
* Precondition: 
* Postcondition: 5 x'd cards are displayed in console
*************************************************************************/
void printSecretHand(){
	int i = 0;
	printf("\nComputer's hand: \n");
	printf("-------------------------\n");
	for(i = 0; i < HAND_SIZE; i++){
		printf("Card %d: XXXXXXXXXXXXXXX\n", i+1);
	}
}
/*************************************************************************
* Date last modified: April 17th, 2013
* Description: Determines which of the computers cards to keep based on current hand,
*     set those cards to keep (1) in the keep card array
* Input parameters: array of keep cards, array of number of each suit in hand,
*     array of number of each face value in hand, players current hand
* Returns: 
* Precondition: array of face values and number of each suit has been set, array of 
*     keep cards has been reset to 0, hand has been dealt
* Postcondition: 0-5 cards are set to keep based on quality of hand
*************************************************************************/
void determineCompKeepCards(int *keepCards, int *suits, int *faces, Card hand[HAND_SIZE]){
	int i = 0, keep = 0, keep2 = 0, numKeep = 0, j = 0;
	//If straight keep all cards
	if(containsStraight(faces)){
		keepAllCards(keepCards);
	}
	//If flush keep all cards
	else if(containsFlush(suits) >= 0){
		keepAllCards(keepCards);
	}
	//If four of a kind keep all cards if extra card is a face card
	else if(containsFourOfAKind(faces) >= 0){
		keep = containsFourOfAKind(faces);
		for(i = 0; i < HAND_SIZE; i++){
			if(hand[i].faceIndex == keep){
				keepCards[i] = 1;
			}
			else if(hand[i].faceIndex > 8){
				keepCards[i] = 1;
			}
		}
	}
	//If full house keep all cards
	else if(containsThreeOfAKind(faces) >= 0 && containsPair(faces) >= 0){
		keepAllCards(keepCards);
	}
	//If three of a kind keep three
	else if(containsThreeOfAKind(faces) >= 0){
		keep = containsThreeOfAKind(faces);
		for(i = 0; i < HAND_SIZE; i++){
			if(hand[i].faceIndex == keep){
				keepCards[i] = 1;
			}
		}
	}
	//If 2 pair keep the 2 pair
	else if(containsTwoPair(faces) >= 0){
		keep = containsPair(faces);
		keep2 = containsTwoPair(faces);
		for(i = 0; i < HAND_SIZE; i++){
			if(hand[i].faceIndex == keep || hand[i].faceIndex == keep2){
				keepCards[i] = 1;
			}
		}
	}
	//If one pair keep the pair
	else if(containsPair(faces) >= 0){
		keep = containsPair(faces);
		for(i = 0; i < HAND_SIZE; i++){
			if(hand[i].faceIndex == keep){
				keepCards[i] = 1;
			}
		}
	}
	else if(hasFourToAFlush(suits) >= 0){ //If four to a flush keep those cards
		j = hasFourToAFlush(suits);
		for(i = 0; i < HAND_SIZE; i++){
			if(hand[i].suitIndex == j){
				keepCards[i] = 1;
			}
		}
	}
	else{ //If nothing then keep face cards
		for(i = NUM_FACES-1; i > 8; i--){
			if(faces[i] == 1){
				for(j = 0; j < HAND_SIZE; j++){
					if(hand[j].faceIndex == i){
						keepCards[j] = 1;
					}
				}
			}
		}
	}
}
/*************************************************************************
* Date last modified: April 17th, 2013
* Description: Determines winner of current hand
* Input parameters: array for player and computer indicating what they have in their hand
*     (0 - 12: Straight flush - low card)
* Returns: 1 if player is the winner, 0 if computer has won
* Precondition: array of winning hands has been set for both player and computer
* Postcondition: 0 or 1 is returned
*************************************************************************/
int determineWinner(int *playerCards, int *compCards){
	int i = 0, winner = -1;
	while(winner == -1 && i < 13){
		if(playerCards[i] > compCards[i]){
			winner = 1;
		}
		else if(playerCards[i] < compCards[i]){
			winner = 0;
		}
		i++;
	}
	if(winner == -1){ //Tie goes to the player
		winner = 1;
	}
	return winner;
}
/*************************************************************************
* Date last modified: April 17th, 2013
* Description: Sets the winning cards array for each the player.
*     ex: index 0 = 1 if straight flush exists...
* Input parameters: integer arrays of number of each face value and suit in hand,
*     array of winning card list
* Returns: 
* Precondition: array of face values and suits has been set
* Postcondition: winner list is set based on current cards
*************************************************************************/
void setDetermineWinnerArray(int *suits, int *faces, int *winnerList){
	int i = 0, j = 0;
	//Set all indexes to -1
	for(i = 0; i < 13; i++){
		winnerList[i] = -1;
	}
	if(containsFlush(suits) >= 0 && containsStraight(faces) > 0){ // If straight flush set array position 1 to 1
		winnerList[0] = 1;
	}
	else if(containsFourOfAKind(faces) >= 0){ // If four of a kind set array in position 2 to face index of four of a kind
		winnerList[1] = containsFourOfAKind(faces);
	}
	else if(containsThreeOfAKind(faces) >= 0 && containsPair(faces) >= 0){ // If full house set array in position 3 to face index of three of a kind
		winnerList[2] = containsThreeOfAKind(faces);
	}
	else if(containsFlush(suits) >= 0){ // If flush set array position 4 to 1
		winnerList[3] = 1;
	}
	else if(containsStraight(faces) > 0){ // If straight set array position 5 to 1
		winnerList[4] = 1;
	}
	else if(containsThreeOfAKind(faces) >= 0){ // If three of a kind set array in position 6 to face index of three of a kind
		winnerList[5] = containsThreeOfAKind(faces);
	}
	else if(containsTwoPair(faces) >= 0){ // If two pair set array position 7 to highest pair and array position 8 to second pair
		winnerList[6] = containsTwoPair(faces);
		winnerList[7] = containsPair(faces);
	}
	else if(containsPair(faces) >= 0){ // If pair set array position 8 to pair
		winnerList[7] = containsPair(faces);
	}
	//Set high cards (1-5)
	j = 8;
	for(i = NUM_FACES; i >= 0; i--){ 
		if(faces[i] > 0){
			winnerList[j] = i;
			j++;
		}
	}
}
/*************************************************************************
* Date last modified: April 17th, 2013
* Description: Displays game menu on console
* Input parameters: 
* Returns: 
* Precondition: 
* Postcondition: 
*************************************************************************/
void displayMenu(void){
	system("cls");
	printf("***** Five-Card Poker Menu *****\n");
	printf("1. Play game\n");
	printf("2. Display win/loss record\n");
	printf("3. Exit game\n");
}
/*************************************************************************
* Date last modified: April 17th, 2013
* Description: Gets menu choice from user and validates input
* Input parameters: 
* Returns: Menu choice (1-3)
* Precondition: 
* Postcondition: 1, 2, or 3 is returned
*************************************************************************/
int getMenuChoice(void){
	int choice = 0;
	while(choice < 1 || choice > 3){
		_flushall();
		printf("Enter menu choice: ");
		scanf("%d", &choice);
		if(choice < 1 || choice > 3){
			printf("Menu choice is invalid\n");
		}
	}
	return choice;
}
/*************************************************************************
* Date last modified: April 17th, 2013
* Description: Displays total games played, total wins, and total losses recorded
*     since the program was started
* Input parameters: total wins, total losses
* Returns: 
* Precondition: 
* Postcondition: 
*************************************************************************/
void displayWinsLosses(int wins, int losses){
	printf("\nTotal Games Played: %d\n", (wins + losses));
	printf("Wins: %d\n", wins);
	printf("Losses: %d\n", losses);
	system("pause");
}