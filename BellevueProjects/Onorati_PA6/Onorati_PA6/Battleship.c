#include "BattleShip.h"

/*************************************************************************
* Date last modified: March 24th, 2013
* Description: Displays the battleship game menu
* Input parameters: 
* Returns: 
* Precondition: 
* Postcondition: Game menu is displayed
*************************************************************************/
void welcomeScreen(void){
	printf("******** Battleship Game Menu ********\n");
	printf("--------------------------------------\n");
	printf("1. Display Game Rules\n");
	printf("2. Play Battleship\n");
	printf("3. Exit game\n");
}

/*************************************************************************
* Date last modified: March 24th, 2013
* Description: Gets and validates users menu selection
* Input parameters: 
* Returns: menu selection
* Precondition: 
* Postcondition: valid selection is returned
*************************************************************************/
int getMenuSelection(void){
	int selection = 0;
	printf("Please select menu option: ");
	scanf("%d", &selection);
	while(selection < 1 || selection > 3){
		printf("Invalid choice. Choose a selection 1-3: ");
		scanf("%d", &selection);
	}
	return selection;
}

/*************************************************************************
* Date last modified: March 24th, 2013
* Description: Displays the battleship game rules
* Input parameters: 
* Returns: 
* Precondition: 
* Postcondition: Game rules are displayed
*************************************************************************/
void displayRules(void){
	printf("******** Battleship Rules ********\n");
	printf("----------------------------------\n");
	printf("1. Player either randomly or manually place ships on game board\n");
	printf("2. Players alternate turns trying to hit the other players ships\n");
	printf("3. Players may only take one shot per turn\n");
	printf("4. Game ends when one players ships have all been sunk\n");
	system("pause");
}

/*************************************************************************
* Date last modified: March 24th, 2013
* Description: Initializes game board so every cell contains '~'
* Input parameters: game board, array[rows][columns]
* Returns: 
* Precondition: Board is an array of size [rows][columns]
* Postcondition: Game board has been set so every cell contains '~'
*************************************************************************/
void initializeBoard(char board[][COLUMNS]){
	int i = 0, j = 0;
	for(i = 0; i < ROWS; i++){
		for(j = 0; j < COLUMNS; j++){
			board[i][j] = '~';
		}
	}
}

/*************************************************************************
* Date last modified: March 24th, 2013
* Description: Prints game board of player or computer. If players board,
*   prints every cell as is in array. If computers board, prints only '~',
*   '*', or 'm' (does not print unhit ship locations).
* Input parameters: game board, array[rows][columns], who's board it is 
*   (player or computer).
* Returns: 
* Precondition: Board is an array of size [rows][columns]
* Postcondition: Game board is printed
*************************************************************************/
void printBoard(char board[][COLUMNS], int yourBoard){
	HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
	int i = 0, j = 0, k = 0;
	printf("   ");
	for(k = 1; k <= 10; k++){
		printf("%d ", k);
	}
	putchar('\n');
	for(i = 0; i < ROWS; i++){
		 //Reset Color
		SetConsoleTextAttribute(h, 07);
		printf("%2d ", i + 1);
		for(j = 0; j < COLUMNS; j++){
			if(yourBoard == 1){ // If displaying players own board
				if(board[i][j] == '~'){//Change color to blue
					SetConsoleTextAttribute(h, 03);
				}
				else if(board[i][j] == '*'){//Change color to red
					SetConsoleTextAttribute(h, 12);
				}
				else if(board[i][j] == 'm'){//Change color to green
					SetConsoleTextAttribute(h, 10);
				}
				else{
					SetConsoleTextAttribute(h, 14);
				}
				putchar(board[i][j]);
				putchar(' ');
			}
			if(yourBoard == 0){ // If displaying opponenets board
				if (board[i][j] == '~'){
					SetConsoleTextAttribute(h, 03);
					putchar(board[i][j]);
				}
				else if (board[i][j] == '*'){
					SetConsoleTextAttribute(h, 12);
					putchar(board[i][j]);
				}
				else if (board[i][j] == 'm'){
					SetConsoleTextAttribute(h, 10);
					putchar(board[i][j]);
				}
				else{
					SetConsoleTextAttribute(h, 03);
					putchar('~');
				}
				putchar(' ');
			}
		}
		putchar('\n');
	}
	SetConsoleTextAttribute(h, 07);
}

/*************************************************************************
* Date last modified: March 24th, 2013
* Description: Selects who starts first via a "rock, paper, scissors" game
* Input parameters: 
* Returns: 1 if player goes first, 0 if computer goes first
* Precondition: 
* Postcondition: 1 or 0 is returned
*************************************************************************/
int selectWhoStartsFirst(void){
	int winner = 0, player = 0, computer = 0;
	char rps[3][10] = {{"Rock"}, {"Paper"}, {"Scissors"}};
	printf("*** Rock Paper Scissors ***\n");
	printf("1. Rock\n");
	printf("2. Paper\n");
	printf("3. Scissors\n");
	printf("Choose rock, paper, or scissors to determine who goes first\n");
	scanf("%d", &player);
	while (player < 1 || player > 3){
		printf("Invalid selection. Choose option 1-3: ");
		scanf("%d", &player);
	}
	do{
		computer = (rand() % 3 + 1);
	}while(computer == player);
	printf("Player Chose: %s\n", rps[player-1]);
	printf("Computer Chose: %s\n", rps[computer-1]);
	switch(player){
		case 1:
			if(computer == 2){
				printf("Paper covers rock\n");
				winner = 2;
			}
			else{
				printf("Rock smashes scissors\n");
				winner = 1;
			}
			break;
		case 2:
			if(computer == 1){
				printf("Paper covers rock\n");
				winner = 1;
			}
			else{
				printf("Scissors cut paper\n");
				winner = 2;
			}
			break;
		case 3:
			if(computer == 1){
				printf("Rock smashes scissors\n");
				winner = 2;
			}
			else{
				printf("Scissors cut paper\n");
				winner = 1;
			}
		default:
			break;
	}
	if(winner == 1){
		printf("You win! You will go first.\n");
	}
	else{
		printf("Computer wins. You will go second.\n");
	}
	system("pause");
	return winner;
}

/*************************************************************************
* Date last modified: March 24th, 2013
* Description: Gets users decision to randomly place or manually place ships
*   and validates selection
* Input parameters: 
* Returns: User selection (1 = randomly, 2 = manually);
* Precondition: 
* Postcondition: 1 or 2 is returned
*************************************************************************/
int getPlaceShipsDecision(void){
	int selection = 0;
	printf("Decide how you would like to place your ships:\n");
	printf("1. Randomly place ships for me\n");
	printf("2. Manually place my ships\n");
	_flushall();
	printf("Enter your selection: ");
	scanf("%d", &selection);
	while(selection < 1 || selection > 2){
		_flushall();
		printf("Invalid selection, choose option 1 or 2: ");
		scanf("%d", &selection);
	}
	return selection;
}

/*************************************************************************
* Date last modified: March 24th, 2013
* Description: Places all ships on the game board, gets user input for where
*    to put each ship, validates placement, updates gameboard with ship placement
* Input parameters: game board, array[rows][columns]
* Returns: 
* Precondition: Board is an array of size [rows][columns]
* Postcondition: Game board has been set so every ship is placed in a valid
*   position and board is updated with char for each ship.
*************************************************************************/
void manuallyPlaceShips(char board[][COLUMNS], Ship *ships){
	int i = 0, j = 0, valid = 0, direction = -1;
	char strDirections[NUM_DIRECTIONS][10] = {"up", "down", "left", "right"};
	char selection[50];
	int validDirections[NUM_DIRECTIONS] = {1, 1, 1, 1};
	int shipPlacement[2] = {0};
	// Display board
	
	// Get user spot selection
	for(i = 0; i < NUM_SHIPS; i++){
		valid = 0;
		do{
			system("cls");
			printBoard(board, 1);
			printf("\nWhere would you like to place your %s (row column): ", ships[i].name);
			scanf("%d %d", &shipPlacement[0], &shipPlacement[1]);
			// Validate selection
			if(shipPlacement[0] < 1 || shipPlacement[0] > ROWS || shipPlacement[1] < 1 || shipPlacement[1] > COLUMNS){
				printf("Invalid selection, row and column must be between 1 & 10.\n");
				system("pause");
			}
			else if(isHit(board, shipPlacement)){
				printf("Invalid selection, this space is already taken.\n");
				system("pause");
			}
			else if(!(isValidShipSpot(board, shipPlacement, ships[i].size, validDirections))){ // Check if there is any direction the ship can go
				printf("Invalid selection, your %s cannot fit here.\n", ships[i].name);
				system("pause");
			}
			else{
				valid = 1;
			}
		}while(!valid);
		// Get ship direction
		do{
			printf("\nWhich direction would you like your ship to go? ");
			for(j = 0; j < NUM_DIRECTIONS; j++){
				if(validDirections[j]){ // If direction is valid
					printf(" %s", strDirections[j]);
				}
			}
			printf(": ");
			_flushall();
			scanf("%s", selection);
			for(j = 0; j < strlen(selection); j++){ // Convert string to lowercase
				tolower(selection[j]);
			}
				// Validate direction
			for(j = 0; j < NUM_DIRECTIONS; j++){
				if(!(strcmp(selection, strDirections[j]))){
					direction = j;
				}
			}
			if(direction == -1){
				printf("Direction entered is invalid.");
			}
		}while(direction == -1);
		// Set ship on board
		setShip(board, shipPlacement, ships[i].size, ships[i].token, direction);
	}
}

void resetValidDirection(int *direction){
	int i = 0;
	for(i = 0; i < NUM_DIRECTIONS; i++){
		direction[i] = 1;
	}
}

/*************************************************************************
* Date last modified: March 24th, 2013
* Description: Determines if specified ship can fit in the spot chosen. Updates 
*   array of possible ship directions to indicate if they are possible or not.
* Input parameters: game board, array[rows][columns], specified spot to place ship,
*   size of the ship, possible directions for ship to go (array[4])
* Returns: 1 if at atleast one direction ship can go, 0 if no directions are valid
* Precondition: Board is an array of size [rows][columns], ship placement is valid,
*   array of possible directions has all cells set to 0.
* Postcondition: Array of possible directions has been updated to reflect validity of
*   each ship direction, 1 or 0 is returned.
*************************************************************************/
int isValidShipSpot(char board[][COLUMNS], int *placement, int shipSize, int *direction){
	int i = 0, j = 0, outOfBounds = 0, valid = 0;
	int tempPlace[2] = {0};
	resetValidDirection(direction);
	for(i = 0; i < NUM_DIRECTIONS; i++){
		tempPlace[0] = placement[0];
		tempPlace[1] = placement[1];
		outOfBounds = 0;
		for(j = 1; j < shipSize; j++){
			switch(i){
			case UP: tempPlace[0]--;
					break;
			case DOWN: tempPlace[0]++;
					break;
			case LEFT: tempPlace[1]--;
					break;
			case RIGHT: tempPlace[1]++;
					break;
			}
			if(tempPlace[0]-1 < 0 || tempPlace[0]-1 > 9 || tempPlace[1]-1 < 0 || tempPlace[1]-1 > 9){
				outOfBounds = 1;
			}
			if(outOfBounds || isHit(board, tempPlace)){
				direction[i] = 0;
			}
		}
		if(direction[i]){
			valid = 1;
		}
	}
	return valid;
}

/*************************************************************************
* Date last modified: March 24th, 2013
* Description: Sets a ship onto the game board. Replaces '~' of each affected
*    cell with the first letter of the ship name (or second for the cruiser): 'c','b','r','s','d'.
* Input parameters: game board, array[rows][columns], specified spot to place ship,
*    size of the ship, direction of the ship.
* Returns: 
* Precondition: Board is an array of size [rows][columns], ship placement is valid,
*    direction is valid
* Postcondition: Game board has been updated to reflect ship placement
*************************************************************************/
void setShip(char board[][COLUMNS], int *placement, int shipSize, char shipName, int direction){
	int j = 0;
	int tempPlace[2] = {0};
	tempPlace[0] = placement[0];
	tempPlace[1] = placement[1];
	board[tempPlace[0]-1][tempPlace[1]-1] = shipName;
	for(j = 1; j < shipSize; j++){
		switch(direction){
		case UP: tempPlace[0]--;
				break;
		case DOWN: tempPlace[0]++;
				break;
		case LEFT: tempPlace[1]--;
				break;
		case RIGHT: tempPlace[1]++;
				break;
		}
		board[tempPlace[0]-1][tempPlace[1]-1] = shipName;
	}
}

/*************************************************************************
* Date last modified: March 29th, 2013
* Description: Randomly places all ships on game board
* Input parameters: game board, array[rows][columns], Array of ships
* Returns: 
* Precondition: Board is an array of size [rows][columns]
* Postcondition: Game board has been updated to reflect ship placement
*************************************************************************/
void randomlyPlaceShips(char board[][COLUMNS], Ship *ships){
	int i = 0, j = 0, valid = 0, direction = -1, hit = 0;
	int validDirections[NUM_DIRECTIONS] = {1, 1, 1, 1};
	int shipPlacement[2] = {0};
	
	for(i = 0; i < NUM_SHIPS; i++){
		valid = 0;
		direction = -1;
		while(valid == 0){
			getRandomShotEasy(board, shipPlacement);
			hit = isHit(board, shipPlacement);
			if(!hit){
				valid = isValidShipSpot(board, shipPlacement, ships[i].size, validDirections);
			}
			if(valid){
				while(direction == -1){
					direction = (rand() % NUM_DIRECTIONS);
					if(validDirections[direction] == 0){
						direction = -1;
						valid = 0;
					}
					else{
						valid = 1;
					}
				}
			}
		}
		// Set ship on board
		setShip(board, shipPlacement, ships[i].size, ships[i].token, direction);
	}
}


/*************************************************************************
* Date last modified: March 24th, 2013
* Description: Gets shot from user and validates it
* Input parameters: game board (array[rows][columns]), shot 
* Returns: 
* Precondition: 
* Postcondition: shot is updated to a valid shot
*************************************************************************/
void getShot(char board[][COLUMNS], int *shot){
	int valid = 0;
	do{
		printf("\nWhere would you like to shoot? (row column): ");
		_flushall();
		scanf("%d %d", &shot[0], &shot[1]);
		if(shot[0] < 1 || shot[0] > ROWS || shot[1] < 1 || shot[1] > COLUMNS){
			printf("Shot is invalid, rows and columns must be between 1 and 10.");
		}
		else if(!validateShot(board, shot)){
			printf("Shot is invalid, choose a cell you have not already shot at.");
		}
		else{
			valid = 1;
		}

	}while(!valid);
}

/*************************************************************************
* Date last modified: March 24th, 2013
* Description: Determines if given shot is a hit or miss
* Input parameters: game board (array[rows][columns]), shot 
* Returns: 1 if a hit, 0 if a miss
* Precondition: shot is a valid location that has not already been delcared a miss or hit
* Postcondition: 0 or 1 is returned
*************************************************************************/
int isHit(char board[][COLUMNS], int *shot){
	int hit = 0;
	if (board[shot[0]-1][shot[1]-1] != '~'){
		hit = 1;
	}
	return hit;
}

/*************************************************************************
* Date last modified: March 24th, 2013
* Description: Updates board after shot. Changes cell to '*' if a hit or 'm' if a miss
* Input parameters: game board (array[rows][columns]), shot location, whether a hit or not
* Returns: 
* Precondition: Board is an array of size [rows][columns], shot is valid
* Postcondition: Game board has been updated to cell denoted by shot is either '*' or 'm'
*************************************************************************/
void updateBoard(char board[][COLUMNS], int *shot, int hit){
	if (hit == 1){
		board[shot[0]-1][shot[1]-1] = '*';
	}
	else {
		board[shot[0]-1][shot[1]-1] = 'm';
	}
}

/*************************************************************************
* Date last modified: March 24th, 2013
* Description: Validates current shot, If shot has already been taken (cell contains
*    either '*' or 'm') then returns invalid
* Input parameters: game board (array[rows][columns]), shot
* Returns: 1 if shot is valid, 0 if invalid
* Precondition: Board is an array of size [rows][columns]
* Postcondition: 1 or 0 is returned
*************************************************************************/
int validateShot(char board[][COLUMNS], int *shot){
	int isValid = 0;
	if(board[shot[0]-1][shot[1]-1] != '*' && board[shot[0]-1][shot[1]-1] != 'm'){
		isValid = 1;
	}
	return isValid;
}

/*************************************************************************
* Date last modified: March 29th, 2013
* Description: Resets current shot to 0 0 
* Input parameters: shot
* Returns: 
* Precondition: 
* Postcondition: shot is reset to 0 0
*************************************************************************/
void resetShot(int *shot){
	shot[0] = 0;
	shot[1] = 0;
}

/*************************************************************************
* Date last modified: March 29th, 2013
* Description: Sets current shot to random  valid shot on the game board
* Input parameters: game board (array[rows][columns]), shot
* Returns: 
* Precondition: Board is an array of size [rows][columns]
* Postcondition: shot is set to a valid shot on the game board
*************************************************************************/
void getRandomShotEasy(char board[][COLUMNS], int *shot){
	do{
		shot[0] = (rand() % 10) + 1;
		shot[1] = (rand() % 10) + 1;
	}while(!validateShot(board, shot));

}

/*************************************************************************
* Date last modified: March 24th, 2013
* Description: Gets a shot for medium difficulty setting. If previous shot was 
* not a hit or if ship has been sunk then a random easy shot is given. Else,
* shot is determined by choosing a board spot around last hit until another hit 
* occurs or until a ship is sunk.
* Input parameters: game board (array[rows][columns]), shot, whether ship was sunk
* Returns: 
* Precondition: Board is an array of size [rows][columns]
* Postcondition: valid shot is returned
*************************************************************************/
void getRandomShotMedium(char board[][COLUMNS], int *shot, int sunk){
	static int lastShotHit = 0, firstShot = 1;
	static int lastShot[2] = {0}, originalShotMed[2] = {0};
	static int directionMed = 0, directionSet = 0;
	static int validDirectionMed[4] = {0};

	int tempShotMed[2] = {0};
	int i = 0;

	if(sunk){
		lastShotHit = 0;
		resetValidDirection(validDirectionMed);
		firstShot = 1;
		directionSet = 0;
	}
	if(!lastShotHit){
		getRandomShotEasy(board, shot);
		if(isHit(board, shot)){
			lastShotHit = 1;
		}
		lastShot[0] = shot[0];
		lastShot[1] = shot[1];
	}
	else{
		//If first hit on ship set valid directions
		if(firstShot){
				originalShotMed[0] = lastShot[0];
				originalShotMed[1] = lastShot[1];
				tempShotMed[0] = lastShot[0]-1;
				tempShotMed[1] = lastShot[1];
				if(isOffBoard(tempShotMed)){
					validDirectionMed[UP] = 0;
				}
				else{
					validDirectionMed[UP] = validateShot(board, tempShotMed);
				}
				tempShotMed[0] = lastShot[0]+1;
				tempShotMed[1] = lastShot[1];
				if(isOffBoard(tempShotMed)){
					validDirectionMed[DOWN] = 0;
				}
				else{
					validDirectionMed[DOWN] = validateShot(board, tempShotMed);
				}
				tempShotMed[0] = lastShot[0];
				tempShotMed[1] = lastShot[1]-1;
				if(isOffBoard(tempShotMed)){
					validDirectionMed[LEFT] = 0;
				}
				else{
					validDirectionMed[LEFT] = validateShot(board, tempShotMed);
				}
				tempShotMed[0] = lastShot[0];
				tempShotMed[1] = lastShot[1]+1;
				if(isOffBoard(tempShotMed)){
					validDirectionMed[RIGHT] = 0;
				}
				else{
					validDirectionMed[RIGHT] = validateShot(board, tempShotMed);
				}
				firstShot = 0;
				if(validDirectionMed[UP] == 0 && validDirectionMed[DOWN] == 0 && validDirectionMed[LEFT] == 0 && validDirectionMed[RIGHT] == 0){
					firstShot = 1;
					directionSet = 0;
					lastShotHit = 0;
				}
			}
		if(lastShotHit == 0){
			getRandomShotEasy(board, shot);
			if(isHit(board, shot)){
				lastShotHit = 1;
			}
			resetValidDirection(validDirectionMed);
			lastShot[0] = shot[0];
			lastShot[1] = shot[1];
		}
		else{
		//Get random direction
		do{
		directionMed = rand() % 4;
		}while(!validDirectionMed[directionMed]);
		//Set new shot
		tempShotMed[0] = lastShot[0];
		tempShotMed[1] = lastShot[1];
		switch(directionMed){
			case UP: tempShotMed[0]--;
					break;
			case DOWN: tempShotMed[0]++;
					break;
			case LEFT: tempShotMed[1]--;
					break;
			case RIGHT: tempShotMed[1]++;
					break;
			}
		//If not the first shot & direction has been discovered, if next shot is off board switch to opposite direction
		if(!firstShot && directionSet && isOffBoard(tempShotMed)){
				if(validDirectionMed[0] == 1){
					validDirectionMed[0] = 0;
					validDirectionMed[1] = 1;
					directionMed = 1;
				}
				if(validDirectionMed[1] == 1){
					validDirectionMed[1] = 0;
					validDirectionMed[0] = 1;
					directionMed = 0;
				}
				if(validDirectionMed[2] == 1){
					validDirectionMed[2] = 0;
					validDirectionMed[3] = 1;
					directionMed = 3;
				}
				if(validDirectionMed[3] == 1){
					validDirectionMed[3] = 0;
					validDirectionMed[2] = 1;
					directionMed = 2;
				}
			tempShotMed[0] = originalShotMed[0];
			tempShotMed[1] = originalShotMed[1];
			switch(directionMed){
				case UP: tempShotMed[0]--;
					break;
				case DOWN: tempShotMed[0]++;
					break;
				case LEFT: tempShotMed[1]--;
					break;
				case RIGHT: tempShotMed[1]++;
					break;
			}
		}
		shot[0] = tempShotMed[0];
		shot[1] = tempShotMed[1];
		//If a hit continue shooting in that direction until sunk
		if(isHit(board, shot)){
			for(i = 0; i < NUM_DIRECTIONS; i++){
				if(i != directionMed){
					validDirectionMed[i] = 0;
				}
			}
			directionSet = 1;
			lastShot[0] = shot[0];
			lastShot[1] = shot[1];

		}
		else{
			validDirectionMed[directionMed] = 0;
		}
		if(validDirectionMed[UP] == 0 && validDirectionMed[DOWN] == 0 && validDirectionMed[LEFT] == 0 && validDirectionMed[RIGHT] == 0){
			lastShot[0] = originalShotMed[0];
			lastShot[1] = originalShotMed[1];
			firstShot = 1;
			directionSet = 0;
		}
	}
	}
}

/*************************************************************************
* Date last modified: March 29th, 2013
* Description: Gets a shot at the hard difficulty level. If previous shot was a hit
* and the current ship hasn't been sunk then function will keep hitting the current ship
* until it is sunk at which point random shots will be given until another ship is hit.
* Input parameters: game board (array[rows][columns]), shot, sunk
* Returns:
* Precondition: Board is an array of size [rows][columns]
* Postcondition: Valid shot is returned
*************************************************************************/
void getRandomShotHard(char board[][COLUMNS], int *shot, int sunk){
	static int lastShotHitHard = 0;
	static char ship = '\0';
	int i = 0, j = 0, found = 0;

	if(sunk){
		lastShotHitHard = 0;
	}
	if(!lastShotHitHard){
		getRandomShotEasy(board, shot);
		if(isHit(board, shot)){
			lastShotHitHard = 1;
			ship = board[shot[0]-1][shot[1]-1];
		}
	}
	else{
		for(i = 0; i < ROWS; i++){
			for(j = 0; j < COLUMNS; j++){
				if(!found && board[i][j] == ship){
					shot[0] = i+1;
					shot[1] = j+1;
					found = 1;
				}
			}
		}
	}
}

/*************************************************************************
* Date last modified: March 29th, 2013
* Description: Determines whether current shot sunk a ship
* Input parameters: game board (array[rows][columns]), shot
* Returns: 0 if ship has not been sunk, returns 1 - 5 if ship has been sunk.
* 1-5 correspond to each ship in the array order (carrier = 1)
* Precondition: Board is an array of size [rows][columns]
* Postcondition:  0  or 1-5 is returned
*************************************************************************/
int isShipSunk(char board[][COLUMNS], int *shot){
	char ship = '\0';
	int i = 0, j = 0, sunk = 0;
	ship = board[(shot[0])-1][(shot[1])-1];
	for (i = 0; i < ROWS; i++){
		for(j = 0; j < COLUMNS; j++){
			if(board[i][j] == ship){
				sunk++;
			}
		}
	}
	if(sunk == 1){
		switch(ship){
			case 'c': sunk = 1;
				break;
			case 'b': sunk = 2;
				break;
			case 'r': sunk = 3;
				break;
			case 's': sunk = 4;
				break;
			case 'd': sunk = 5;
				break;
		}
	}
	else{
		sunk = 0;
	}
	return sunk;
}

/*************************************************************************
* Date last modified: March 24th, 2013
* Description: Determines if all ships on the current game board have been sunk
* Input parameters: game board (array[rows][columns])
* Returns: 1 if gameover, 0 if not
* Precondition: Board is an array of size [rows][columns]
* Postcondition: 1 or 0 is returned
*************************************************************************/
int isGameOver(char board[][COLUMNS]){
	int gameOver = 1, i = 0, j = 0;
	for (i = 0; i < ROWS; i++){
		for(j = 0; j < COLUMNS; j++){
			if(!(board[i][j] == '~') && !(board[i][j] == '*') && !(board[i][j] == 'm')){
				gameOver = 0;
			}
		}
	}
	return gameOver;
}

/*************************************************************************
* Date last modified: March 29th, 2013
* Description: Initializes a ship(struct) with size, token, and name
* Input parameters: ship, size of ship, name of ship, and gameboard token for ship
* Returns: 
* Precondition: 
* Postcondition: ships correct values are stored
*************************************************************************/
void initializeShip(Ship *ship, int size, char *name, char token){
	ship->size = size;
	ship->token = token;
	ship->name = name;
}

/*************************************************************************
* Date last modified: March 29th, 2013
* Description: Gets wanted difficulty level from user, validates input, and returns input
* Input parameters: 
* Returns: 1 if easy, 2 if medium, 3 if hard
* Precondition: 
* Postcondition: 1-3 returned
*************************************************************************/
int getDifficulty(void){
	int difficulty = 0;
	do{
		system("cls");
		printf("\nChoose a difficulty level:\n");
		printf("\t1. Easy\n");
		printf("\t2. Medium\n");
		printf("\t3. Hard\n");
		scanf("%d", &difficulty);
		if(difficulty < 1 || difficulty > 3){
			printf("Invalid Selection\n");
			difficulty = 0;
		}
	}while(difficulty == 0);
	return difficulty;
}

/*************************************************************************
* Date last modified: March 24th, 2013
* Description: Determines if current shot is off the gameboard
* Input parameters: game board (array[rows][columns]), shot
* Returns: 1 if shot is not valid, 0 if valid
* Precondition: Board is an array of size [rows][columns]
* Postcondition: 1 or 0 is returned
*************************************************************************/
int isOffBoard(int *shot){
	int offBoard = 0;
	if(shot[0] < 1 || shot[0] > ROWS || shot[1] < 1 || shot[1] > COLUMNS){
		offBoard = 1;
	}
	return offBoard;
}

/*************************************************************************
* Date last modified: March 29th, 2013
* Description: Writes current turn info to file
* Input parameters: output file, player, current shot, whether a hit occured,
* whether a ship was sunk, array of ship info
* Returns: 
* Precondition:
* Postcondition: Info is wrtten to file
*************************************************************************/
void writeToFile(FILE *outputFile, int player, int *shot, int hit, int sunk, Ship *ships){

		if(hit && (sunk > 0)){
			fprintf(outputFile, "%-10d%-10d%-10d%-10c%-10s\n", player, shot[0], shot[1], 'Y', ships[sunk-1].name);
		}
		else if(hit){
			fprintf(outputFile, "%-10d%-10d%-10d%-10c\n", player, shot[0], shot[1], 'Y');
		}
		else{
			fprintf(outputFile, "%-10d%-10d%-10d%-10c\n", player, shot[0], shot[1], 'N');
		}
}

/*************************************************************************
* Date last modified: March 29th, 2013
* Description: Writes game stats to output file at the end of the game
* Input parameters: output file, user stats(struct), computer stats(struct), winner
* Returns: 
* Precondition: 
* Postcondition: stats are written to file
*************************************************************************/
void outputStats(FILE *outputFile, Stats user, Stats computer, int winner){
	user.hitMissRatio = (((double)user.hits)/user.totShots)*100;
	computer.hitMissRatio = (((double)computer.hits)/computer.totShots)*100;
	fprintf(outputFile, "\n%s\n", "Player 1 Stats");
	fprintf(outputFile, "%s%d\n", "Total Hits: ", user.hits);
	fprintf(outputFile, "%s%d\n", "Total Misses: ", user.misses);
	fprintf(outputFile, "%s%d\n", "Total Shots: ", user.totShots);
	fprintf(outputFile, "%s%%%.2f\n", "Percent hits: ", user.hitMissRatio);
	fprintf(outputFile, "%s%%%.2f\n", "Percent misses: ", (100 - user.hitMissRatio));
	fprintf(outputFile, "%s&d\n", "Wins: ", user.wins);
	fprintf(outputFile, "%s&d\n", "Losses: ", user.losses);
	fprintf(outputFile, "\n%s\n", "Computer Stats");
	fprintf(outputFile, "%s%d\n", "Total Hits: ", computer.hits);
	fprintf(outputFile, "%s%d\n", "Total Misses: ", computer.misses);
	fprintf(outputFile, "%s%d\n", "Total Shots: ", computer.totShots);
	fprintf(outputFile, "%s%%%.2f\n", "Percent hits: ", computer.hitMissRatio);
	fprintf(outputFile, "%s%%%.2f\n", "Percent misses: ", (100 - computer.hitMissRatio));
	fprintf(outputFile, "%s%d\n", "Wins: ", computer.wins);
	fprintf(outputFile, "%s%d\n", "Losses: ", computer.losses);

}

