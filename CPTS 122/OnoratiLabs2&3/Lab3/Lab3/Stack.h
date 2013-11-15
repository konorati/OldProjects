#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode
{
	double data;
	struct stackNode *pNext;
}StackNode;

typedef enum
{
	FALSE, TRUE
}Boolean;

Boolean isEmpty(StackNode *pTop);
void push(StackNode **pTop, double data);
double pop(StackNode **pTop);
double peek(StackNode *pTop);
void recursivePrintStack(StackNode *pTop);

#endif