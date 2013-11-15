#ifndef EVALUATE_POSTFIX_H
#define EVALUE_POSTFIX_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct stackNodeInt
{
	int data;
	struct stackNodeInt *pNext;
}StackNodeInt;


int evaluatePostfixExpression(char *postfix);
int calculate(int op1, int op2, char oper);
void pushInt(StackNodeInt **pTop, int data);
int popInt(StackNodeInt **pTop);
int isEmptyInt(StackNodeInt *pTop);
void recursivePrintInt(StackNodeInt *pTop);
int isOperInt(char c);



#endif