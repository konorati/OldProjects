#include "EvaluatePostfix.h"

/*************************************************************************
* Date last modified: June 18th, 2013
* Description: Evaluates a postfix expression and returns the result
* Input parameters: postfix expression (character array)
* Returns: Result of expression (int)
* Precondition: Postfix expression is valid
* Postcondition: Valid result is returned
*************************************************************************/
int evaluatePostfixExpression(char *postfix)
{
	int i = 0, tempNum1 = 0, tempNum2 = 0, tempResult = 0;
	StackNodeInt *pTop = NULL;

	//1. Append null character to the end of postfix expression
	while(isOperInt(postfix[i]) || isdigit(postfix[i]))
	{
		i++;
	}
	postfix[i] = '\0';
	i = 0;
	//2. While not null read postfix from left to right
	while(postfix[i] != '\0')
	{
		//a. If digit, push to stack
		if(isdigit(postfix[i]))
		{
			pushInt(&pTop, (postfix[i]-48));
		}
		//b. If operator, pop top two digits from stack, compute y operator x, push result to stack
		else if(isOperInt(postfix[i]))
		{
			tempNum2 = popInt(&pTop);
			tempNum1 = popInt(&pTop);
			tempResult = calculate(tempNum1, tempNum2, postfix[i]);
			pushInt(&pTop, tempResult);
		}
		i++;
	}
	//c. When null character is encountered pop from stack which is the result
	tempResult = popInt(&pTop);
	
	return tempResult;
}

/*************************************************************************
* Date last modified: June 18th, 2013
* Description: Calculates result of simply expression op1 oper op2
* Input parameters: first operand(int), second operand(int), operator(char)
* Returns: result of expression (int)
* Precondition: operator is valid
* Postcondition: Result is returned
*************************************************************************/
int calculate(int op1, int op2, char oper)
{
	int num = 0;
	switch(oper)
	{
	case '+': num = op1 + op2;
		break;
	case '-': num = op1 - op2;
		break;
	case '*': num = op1 * op2;
		break;
	case '/': num = op1 / op2;
		break;
	case '%': num = op1 % op2;
		break;
	case '^': num = (int)pow((double)op1, op2);
		break;
	}
	return num;
}

/*************************************************************************
* Date last modified: June 18th, 2013
* Description: Adds a node (int) to the top of the stack
* Input parameters: Pointer to the top of the stack, math operand (int)
* Returns: 
* Precondition:
* Postcondition: New node with operand data is added to the top of the stack
*************************************************************************/
void pushInt(StackNodeInt **pTop, int data)
{
	StackNodeInt *pMem = (StackNodeInt*)malloc(sizeof(StackNodeInt));
	pMem->data = data;
	pMem->pNext = *pTop;
	*pTop = pMem;
}

/*************************************************************************
* Date last modified: June 18th, 2013
* Description: Removes top node from stack and returns node data
* Input parameters: Pointer to the top of the stack
* Returns: Operand (int) from top node of stack 
* Precondition: Stack is not empty
* Postcondition: Top node is removed from stack and int data is returned
*************************************************************************/
int popInt(StackNodeInt **pTop)
{
	int data = 0;
	StackNodeInt *pTemp = *pTop;
	*pTop = (*pTop)->pNext;
	data = pTemp->data;
	free(pTemp);
	return data;
}

/*************************************************************************
* Date last modified: June 18th, 2013
* Description: Determines if stack is empty
* Input parameters: Pointer to the top of the stack
* Returns: 1 if stack is empty, 0 if not
* Precondition: 
* Postcondition: 1 or 0 is returned
*************************************************************************/
int isEmptyInt(StackNodeInt *pTop)
{
	int isEmpty = 0;
	if(NULL == pTop)
	{
		isEmpty = 1;
	}
	return isEmpty;
}

/*************************************************************************
* Date last modified: June 18th, 2013
* Description: Recursively prints the character data from the entire stack, prints top down
* Input parameters: Pointer to the top of the stack
* Returns: 
* Precondition: 
* Postcondition: Contents of stack are printed to console
*************************************************************************/
void recursivePrintInt(StackNodeInt *pTop)
{
	if(pTop != NULL)
	{
		printf("%d ", pTop->data);
		recursivePrintInt(pTop->pNext);
	}
}

/*************************************************************************
* Date last modified: June 18th, 2013
* Description: Determines if character is an operator
* Input parameters: character
* Returns: 1 if char is an operator, 0 if not
* Precondition: 
* Postcondition: 1 or 0 is returned
*************************************************************************/
int isOperInt(char c)
{
	int isOper = 0;
	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^')
	{
		isOper = 1;
	}
	return isOper;
}