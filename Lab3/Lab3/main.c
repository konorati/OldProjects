#include "Stack.h"

int main(void)
{
	StackNode *pStack = NULL;
	push(&pStack, 1.2);
	push(&pStack, 2.5);
	push(&pStack, 3.7);
	push(&pStack, 5.5);
	recursivePrintStack(pStack);
	system("pause");

	pop(&pStack);
	pop(&pStack);
	recursivePrintStack(pStack);
	return 0;
}