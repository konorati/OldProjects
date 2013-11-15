#include "Functions.h"

void setSentence(Sentence *sentence, char article[][20], char noun[][20], char verb[][20], char preposition[][20]){
	sentence->noun1 = noun[rand() % 5];
	sentence->noun2 = noun[rand() % 5];
	sentence->preposition = preposition[rand() % 5];
	sentence->article1 = article[rand() % 5];
	sentence->article2 = article[rand() % 5];
	sentence->verb = verb[rand() % 5];
}

void createSentence(Sentence build, char *sentence){
	strcpy(sentence, build.article1);
	strcat(sentence, " ");
	strcat(sentence, build.noun1);
	strcat(sentence, " ");
	strcat(sentence, build.verb);
	strcat(sentence, " ");
	strcat(sentence, build.preposition);
	strcat(sentence, " ");
	strcat(sentence, build.article2);
	strcat(sentence, " ");
	strcat(sentence, build.noun2);
}

int getNumCells(void){
	int num = 0;
	printf("\nHow many rows/columns would you like for the tic tac toe board (max 10)? ");
	scanf("%d", &num);
	return num;
}

void printBoard(Cell board[][10], int numCells){
	int i = 0, j = 0, k = 0;
	printf("   ");
	for(k = 1; k <= numCells; k++){
		printf("%d ", k);
	}
	putchar('\n');
	for(i = 0; i < numCells; i++){
		printf("%2d ", i + 1);
		for(j = 0; j < numCells; j++){
			putchar(board[i][j].symbol);
			putchar(' ');
		}
		putchar('\n');
	}
}

void getSpot(Cell board[][10], int numCells, int *spot){
	int valid = 0;
	while(!valid){
		printf("\nWhere would you like to play (row column)? ");
		scanf("%d %d", &spot[0], &spot[1]);
		spot[0]--;
		spot[1]--;
		if(spot[0] < 0 || spot[0] > (numCells-1) || spot[1] < 0 || spot[1] > (numCells-1)){
			printf("Invalid selection\n");
		}
		else{
			if(!isValidSpot(board, spot)){
				printf("Invalid selection\n");
			}
			else{
				valid = 1;
			}
		}
	}
}

int isValidSpot(Cell board[][10], int *spot){
	int valid = 1;
	if(board[spot[0]][spot[1]].occupied == TRUE){
		valid = 0;
	}
	return valid;
}

void setTile(Cell board[][10], int *spot, int player){
	if(player == 1){
		board[spot[0]][spot[1]].symbol = 'X';
	}
	else{
		board[spot[0]][spot[1]].symbol = 'O';
	}
	board[spot[0]][spot[1]].occupied = TRUE;
}

int isWin(Cell board[][10], int numCells){
	int rowCount = 0, columnCount = 0, diagCount = 0, i = 0, j = 0, win = 0;
	char firstCharacterRow = '\0', firstCharacterColumn = '\0', firstCharacterDiag = '\0';
	//Test row win
	for(i = 0; i < numCells; i++){
		firstCharacterRow = board[i][0].symbol;
		if(firstCharacterRow == 'E'){
			firstCharacterRow = 'N';
		}
		firstCharacterColumn = board[0][i].symbol;
		if(firstCharacterColumn == 'E'){
			firstCharacterColumn = 'N';
		}
		rowCount = 0;
		columnCount = 0;
		for(j = 0; j < numCells; j++){
			if(rowCount != numCells && columnCount != numCells){
				if(board[i][j].symbol == firstCharacterRow){
				rowCount++;
				}
				if(board[j][i].symbol == firstCharacterColumn){
				columnCount++;
				}
			}
		}
	}
	firstCharacterDiag = board[0][0].symbol;
	if(firstCharacterDiag != 'E'){
		for(i = 0, j = 0; i < numCells; i++, j++){
			if(board[i][j].symbol == firstCharacterDiag){
				diagCount++;
			}
		}
	}
	firstCharacterDiag = board[numCells-1][numCells-1].symbol;
	if(firstCharacterDiag != 'E'){
		for(i = numCells, j = numCells; i <= 0; i--, j--){
			if(board[i][j].symbol == firstCharacterDiag){
				diagCount++;
			}
		}
	}
	if(rowCount == numCells || columnCount == numCells || diagCount == numCells){
		win = 1;
	}
	return win;
}