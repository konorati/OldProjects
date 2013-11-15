#include "Math_Education.h"
/*************************************************************************************
* Programmer: Kristin Onorati
* Class: CPTS 121, Spring 2013, Lab Section 1
* Programming Assignment: 8
* Date: April 26th, 2013
* Description: This program runs an educational math program for one player. 
**************************************************************************************/

int main(){
int result = 0, points = 0, rootMenu = 0, difficulty = 1;
char initials[8] = {"AAA"}, temp[50], loadGame = '/0';
FILE *gameFile = NULL;

srand(time(NULL));

// If player would like to load previous game data open game file for reading and read in initials and game info
printf("Would you like to load previous game data? <Y or N> ");
scanf("%c", &loadGame);
loadGame = toupper(loadGame);
if(loadGame == 'Y'){
	gameFile = fopen("game.txt", "r");
	if(gameFile != NULL && !(feof(gameFile))){
		fscanf(gameFile, "%s", temp);
		fscanf(gameFile, "%s", temp);
		fscanf(gameFile, "%s", initials);
		fscanf(gameFile, "%s", temp);
		fscanf(gameFile, "%d", &points);
		fclose(gameFile);
		printf("Player initials: %s\nTotal Points: %d\n", initials, points);
		system("pause");
	}
	else{
		printf("Error: Could not open saved game info\n");
	}
}
gameFile = fopen("game.txt", "w");

do{	
	displayMenu();
	rootMenu = getMenuChoice();
	switch(rootMenu){
		case 1: displayRules();
			break;
		case 2: getPlayerInitials(initials);
			break;
		case 3: displayDifficultyMenu();
				difficulty = getMenuChoice();
			break;
		case 4: points += runGameRound(difficulty);
			break;
	}

}while(rootMenu != 5);

if(gameFile != NULL){
	fprintf(gameFile, "Player Initials: %s\n", initials);
	fprintf(gameFile, "Points: %d", points);
}
else{
	printf("Error, cannot save game data, \"game.txt\" does not exist.\n");
}

printf("Thanks for playing!\n");
printf("Player initials: %s\n", initials);
printf("Total score: %d\n", points);



	return 0;
}