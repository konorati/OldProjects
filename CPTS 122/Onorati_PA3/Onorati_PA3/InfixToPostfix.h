#ifndef INFIX_TO_POSTFIX_C
#define INFIX_TO_POSTFIX_C

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct stackNode
{
	char oper;
	struct stackNode *pNext;
}StackNode;

typedef enum
{
	FALSE, TRUE
}Boolean;

void push(StackNode **pTop, char oper);
char pop(StackNode **pTop);
void convertToPostfix(char *infix, char *postfix);
Boolean isOperator(char c);
int precedence(char operator1, char operator2);
char peek(StackNode *pTop);
Boolean isEmpty(StackNode *pTop);
void recursivePrintStack(StackNode *pTop);


#endif