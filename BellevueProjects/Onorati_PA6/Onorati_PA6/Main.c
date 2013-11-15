#include "BattleShip.h"

/*************************************************************************************
* Programmer: Kristin Onorati
* Class: CPTS 121, Spring 2013, Lab Section 1
* Programming Assignment: 6
* Date: March 30th, 2013
* Description: This program runs a battleship game for 2 players. Moves by each player 
* are recorded in an output file.
**************************************************************************************/

int main(void){
	char board1[ROWS][COLUMNS] = {0}, boardComp[ROWS][COLUMNS];
	int shot[2] = {0};
	int menuSelection = 0, shipSetSelection = 0, turn = 0, gameOver = 0, hit = 0, sunk = 0, sunkComp = 0, difficulty = 0;
	Ship ships[NUM_SHIPS] = {0};
	Stats user = {0, 0, 0, 0.0, 0, 0}, computer = {0, 0, 0, 0.0, 0, 0};
	FILE *outputFile = NULL;
	

	srand((unsigned int) time(NULL));
	initializeShip(&ships[CARRIER], 5, "carrier", 'c');
	initializeShip(&ships[BATTLESHIP], 4, "battleship", 'b');
	initializeShip(&ships[CRUISER], 3, "cruiser", 'r');
	initializeShip(&ships[SUBMARINE], 3, "submarine", 's');
	initializeShip(&ships[DESTROYER], 2, "destroyer", 'd');

	// Open output file
	outputFile = fopen("output.dat", "w");
	fprintf(outputFile, "%-10s%-10s%-10s%-10s%-10s\n", "Player", "Row", "Column", "Hit", "Ship Sunk");
 
	//Display game menu
	do{
		welcomeScreen();
		menuSelection = getMenuSelection();
		switch(menuSelection){
			case 1:			// Display rules
				system("cls");
				displayRules();
				break;
			case 2:			//Play game
				system("cls");
				//Initialize game boards
				initializeBoard(board1);
				initializeBoard(boardComp);
				//Set computer ships
				randomlyPlaceShips(boardComp, ships);
				//User decides to set ships manually or automatically
				shipSetSelection = getPlaceShipsDecision();
				if(shipSetSelection == 2){ // Manually set ships
					manuallyPlaceShips(board1, ships);
					//Display board
					system("cls");
					printf("Player 1: Your Board\n");
					printBoard(board1, 1);
				}
				else{ // Randomly set ships
					randomlyPlaceShips(board1, ships);
					printBoard(board1, 1);
				}
				system("pause");
			//Determine who will go first
				system("cls");
				turn = selectWhoStartsFirst();
				difficulty = getDifficulty();
				while (!gameOver){ //Player takes turns until game is over
					//Reset shot
					resetShot(shot);
					hit = 0;
					if (turn == 1){ //If players turn
						system("cls");
						printf("Player 1: Your turn\n");
						printBoard(boardComp, 0); // Display other players board
						getShot(boardComp, shot);
						hit = isHit(boardComp, shot);
						if(hit){
							sunk = isShipSunk(boardComp, shot);
						}
						updateBoard(boardComp, shot, hit);
						system("cls");
						//Display updated board & shot
						printf("Player %d: Your turn\n", turn);
						printBoard(boardComp, 0);
						printf("\nYour shot = Row: %d Column: %d", shot[0], shot[1]);
						//Display appropriate message for hit/miss
						if(hit){
							user.hits++;
							printf("\nResult: Hit!\n");
							//If ship is sunk display message
							if(sunk > 0){
								printf("You sank the computers %s!\n", ships[sunk-1].name);
							}
						}
						else{ // If a miss
							user.misses++;
							printf("\nResult: Miss\n");
						}
						
						gameOver = isGameOver(boardComp);
					}	
					else { // If computers turn
						system("cls");
						printf("Player %d: Computer's Turn\n", turn);
						if(difficulty == 1){
							getRandomShotEasy(board1, shot);
						}
						else if(difficulty == 2){
							getRandomShotMedium(board1, shot, sunkComp);
						}
						else if(difficulty == 3){
							getRandomShotHard(board1, shot, sunkComp);
						}
						hit = isHit(board1, shot);
						if(hit){
							sunkComp = isShipSunk(board1, shot);
						}
						updateBoard(board1, shot, hit);
						printBoard(board1, 1);
						printf("\nComputer's shot = Row: %d Column: %d", shot[0], shot[1]);
						if(hit){
							computer.hits++;
							printf("\nResult: Hit!\n");
							//If ship is sunk display message
							if(sunkComp > 0){
								printf("Computer sank your %s!\n", ships[sunkComp-1].name);
							}
						}
						else{ // If a miss
							computer.misses++;
							printf("\nResult: Miss\n");
						}
						gameOver = isGameOver(board1);
					}
					if(!gameOver){ // If not gameover write stats to file & switch player turns
						if(turn == NUM_PLAYERS){
							computer.totShots += 1;
							writeToFile(outputFile, turn, shot, hit, sunkComp, ships);
							turn = 1;
						}
						else{
							user.totShots += 1;
							writeToFile(outputFile, turn, shot, hit, sunk, ships);
							turn++;
						}
					}
					else{
						if(turn == 1){
							user.totShots += 1;
							user.wins += 1;
							computer.losses += 1;
						}
						else{
							computer.totShots += 1;
							user.losses += 1;
							computer.wins += 1;
						}
					}
					system("pause");
				}
			//Congratulate winner
			system("cls");
			if(turn == 1){
				printf("Congratulations! You are the winner!\n\n");
			}
			else{
				printf("Too bad. Computer wins.\n\n");
			}
			//Print stats to file
			outputStats(outputFile, user, computer, turn);
			//Return to game menu
			break;
		}
	}while(menuSelection != 3);

	return 0;
}