#include "Functions.h"

int main(void){
	char article[5][20] = {"the", "a", "one", "some", "any"}, noun[5][20] = {"boy", "girl", "dog", "town", "car"}, 
		verb[5][20] = {"drove", "jumped", "ran", "walked", "skipped"}, preposition[5][20] = {"to", "from", "over", "under", "on"}; 

	char totSentence[200] = {'\0'};
	int cells = 0, i = 0, j = 0, turn = 1, gameOver = 0, numPlays = 0, winner = 0;
	int spot[2] = {0};
	char playAgain = 'N';
	Cell cellArray[10][10];
	Sentence sent1;
	GameInfo info;
	srand((unsigned int) time(NULL));

	//TASK 1
	setSentence(&sent1, article, noun, verb, preposition);
	createSentence(sent1, totSentence);
	printf("%s", totSentence);
	printf("\n");

	//TASK 2
	info.wins = 0;
	info.losses = 0;
	info.gamesPlayed = 0;
	
	//initialize board

	do{
		cells = getNumCells();
		numPlays = 0;
		gameOver = 0;
		turn = 1;
		for(i = 0; i < cells; i++){
			for(j = 0; j < cells; j++){
				cellArray[i][j].occupied = FALSE;
				cellArray[i][j].symbol = 'E';
				cellArray[i][j].location.row = i;
				cellArray[i][j].location.column = j;
			}
		}
		while(!gameOver){
			numPlays++;
			system("cls");
			printf("\nPlayer #%d's turn:\n", turn);
			printBoard(cellArray, cells);
			getSpot(cellArray, cells, spot);
			setTile(cellArray, spot, turn);
			winner = isWin(cellArray, cells);
			if(winner || numPlays == (cells*cells)){
				gameOver = 1;
			}
			if(!gameOver){
				if(turn == 2){
					turn = 1;
				}
				else{
					turn++;
				}
			}
		}
		system("cls");
		printBoard(cellArray, cells);
		if(winner){
			printf("Player #%d is the winner!\n", turn);
			if(turn == 1){
				info.wins++;
			}
			else{
				info.losses++;
			}
		}
		else{
			printf("Cat's game, you tied.\n");
		}
		info.gamesPlayed++;
		_flushall();
		printf("\nWould you like to play again? (Y or N): ");
		playAgain = getchar();
		playAgain = toupper(playAgain);
	}while(playAgain == 'Y');
	return 0;
}