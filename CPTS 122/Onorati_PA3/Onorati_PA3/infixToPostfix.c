#include "InfixToPostfix.h"

/*************************************************************************
* Date last modified: June 18th, 2013
* Description: Adds a node (character) to the top of the stack
* Input parameters: Pointer to the top of the stack, math operator (char)
* Returns: 
* Precondition:
* Postcondition: New node with operator data is added to the top of the stack
*************************************************************************/
void push(StackNode **pTop, char oper)
{
	StackNode *pMem = (StackNode*)malloc(sizeof(StackNode));
	pMem->oper = oper;
	pMem->pNext = *pTop;
	*pTop = pMem;
}

/*************************************************************************
* Date last modified: June 18th, 2013
* Description: Removes top node from stack and returns node data
* Input parameters: Pointer to the top of the stack
* Returns: Operator (char) from top node of stack 
* Precondition: Stack is not empty
* Postcondition: Top node is removed from stack and char data is returned
*************************************************************************/
char pop(StackNode **pTop)
{
	char cTemp = '\0';
	StackNode *pTemp = *pTop;
	*pTop = (*pTop)->pNext;
	cTemp = pTemp->oper;
	free(pTemp);

	return cTemp;
}

/*************************************************************************
* Date last modified: June 18th, 2013
* Description: Converts infix expression to postfix expression
* Input parameters: infix expression (char array), postfix expression (char array)
* Returns:
* Precondition: postfix array is empty
* Postcondition: postfix array is updated to include postfix version of infix expression
*************************************************************************/
void convertToPostfix(char *infix, char *postfix)
{
	StackNode *pTop = NULL;
	int i = 0, j = 0;
	Boolean keepTrying = TRUE;
	//1. Push left parentheses onto stack
	push(&pTop, '(');
	//2. Append right parentheses to end of infix
	for(i = 0; infix[i] != '\0'; i++);
	infix[i] = ')';
	//3. While stack is not empty read infix from left to right
	i = 0;
	while (!isEmpty(pTop))
	{
		keepTrying = TRUE;
		//a. If current char in infix is a digit copy it to next element in postfix
		if(isdigit(infix[i]))
		{
			postfix[j] = (infix[i]);
			j++;
		}
		//b. If current char is left parenthesis, push to stack
		else if(infix[i] == '(')
		{
			push(&pTop, infix[i]);
		}
		//c. If current char is operator 
		else if(isOperator(infix[i]))
		{
			//pop operators from stack (if any with equal or higher precedence) and append to postfix
			while(keepTrying && isOperator(peek(pTop)))
			{
				if(precedence(peek(pTop), infix[i]) >= 0)
				{
					postfix[j] = pop(&pTop);
					j++;
				}
				else
				{
					keepTrying = FALSE;
				}
			}
			//Push current operator to stack
			push(&pTop, infix[i]);
		}
		//d. If current char is right parenthesis pop operators from stack and append to postfix until left parethensis (discard)
		else if(infix[i] == ')')
		{
			while(peek(pTop) != '(')
			{
				postfix[j] = pop(&pTop);
				j++;
			}
			pop(&pTop); //Discard parenthesis
		}
		i++;
	}
}

/*************************************************************************
* Date last modified: June 18th, 2013
* Description: Determines if character is an operator
* Input parameters: character
* Returns: True if char is an operator, false if not
* Precondition: 
* Postcondition: True or False is returned
*************************************************************************/
Boolean isOperator(char c)
{
	Boolean isOper = FALSE;
	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^')
	{
		isOper = TRUE;
	}
	return isOper;
}

/*************************************************************************
* Date last modified: June 18th, 2013
* Description: Determines if operator 1 has precedence over operator 2
* Input parameters: operator (char), operator (char)
* Returns: 1 if operator 1 has precedence, -1 if operator 2 has precedence, 
*			0 if equal precedence
* Precondition: Both operators are valid operators
* Postcondition: 1, 0, or -1 is returned
*************************************************************************/
int precedence(char operator1, char operator2)
{
	if(operator1 == '+' || operator1 == '-')
	{
		operator1 = 0;
	}
	else
	{
		operator1 = 1;
	}
	if(operator2 == '+' || operator1 == '-')
	{
		operator2 = 0;
	}
	else
	{
		operator2 = 1;
	}
	return (operator1 - operator2);
}

/*************************************************************************
* Date last modified: June 18th, 2013
* Description: Checks the value of the data in the top node of the stack
* Input parameters: Pointer to top of stack
* Returns: Char data from node at top of stack
* Precondition: Stack is not empty
* Postcondition: character is returned
*************************************************************************/
char peek(StackNode *pTop)
{
	char c = pTop->oper;
	return c;
}

/*************************************************************************
* Date last modified: June 18th, 2013
* Description: Determines if stack is empty
* Input parameters: Pointer to the top of the stack
* Returns: True if stack is empty, false if not
* Precondition: 
* Postcondition: True or False is returned
*************************************************************************/
Boolean isEmpty(StackNode *pTop)
{
	Boolean isEmpty = FALSE;
	if(NULL == pTop)
	{
		isEmpty = TRUE;
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
void recursivePrintStack(StackNode *pTop)
{
	if(NULL == pTop)
	{
		printf("%c ", pTop->oper);
		recursivePrintStack(pTop->pNext);
	}
}