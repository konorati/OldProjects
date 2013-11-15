#include "Stack.h"

Boolean isEmpty(StackNode *pTop)
{
	Boolean empty = FALSE;
	if(pTop == NULL)
	{
		empty = TRUE;
	}
	return empty;
}

void push(StackNode **pTop, double data)
{
	StackNode *pMem = (StackNode*)malloc(sizeof(StackNode));
	pMem->data = data;
	pMem->pNext = NULL;

	if(isEmpty(*pTop))
	{
		*pTop = pMem;
	}
	else
	{
		pMem->pNext = *pTop;
		*pTop = pMem;
	}
}

double pop(StackNode **pTop)
{
	double data = 0;
	StackNode *pTemp = *pTop;
	*pTop = pTemp->pNext;
	data = pTemp->data;
	free(pTemp);
	return data;
}
double peek(StackNode *pTop)
{
	double data = pTop->data;
	return data;
}

void recursivePrintStack(StackNode *pTop)
{
	if(pTop != NULL)
	{
		printf("%.2lf ", pTop->data);
		recursivePrintStack(pTop->pNext);
	}
}