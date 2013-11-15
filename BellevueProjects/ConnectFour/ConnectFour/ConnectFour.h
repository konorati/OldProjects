#ifndef CONNECT_FOUR
#define CONNECT_FOUR

#include <stdio.h>
#define ROWS 6
#define COLUMNS

typedef enum boolean{
	FALSE, TRUE
}Boolean;

typedef enum token{
	EMPTY, RED, BLACK
}Token;

typedef struct location{
	int row;
	int column;
}Location;

typedef struct cell{
	Location coordinates;
	Boolean occupied;
	Token token;
}Cell;

#endif