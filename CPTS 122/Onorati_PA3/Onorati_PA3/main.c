/*************************************************************************************
* Programmer: Kristin Onorati
* Class: CPTS 122, Summer 2013
* Programming Assignment: 3
* Date: June 18th, 2013
* Description: Converts an infix expression to postfix then calculates the result of the
*	expression from the postfix
**************************************************************************************/

#include "EvaluatePostfix.h"
#include "InfixToPostfix.h"

int main(void)
{
	char infix[50] = {'(','3','-','1',')','*','8','+','2','\0'};
	char infix2[50];
	char postfix[50] = {'\0'};
	int i = 0, result = 0;
	char cont = 'y';

	while (toupper(cont) == 'Y')
	{
		//Clear infix2
		for(i = 0; i < 50; i++)
		{
			infix2[i] = '\0';
		}
		//Clear postfix
		for(i = 0; i < 50; i++)
		{
			postfix[i] = '\0';
		}

		//Get expression from user
		_flushall();
		printf("Enter an expression to convert to postfix (no spaces): ");
		gets(infix2);

		//Convert to postfix
		convertToPostfix(infix2, postfix);

		//Print postfix expression
		printf("\nPostfix: ");
		i = 0;
		while(postfix[i] != '\0')
		{
			printf("%c ", postfix[i]);
			i++;
		}

		//Calculate result using postfix expression
		result = evaluatePostfixExpression(postfix);

		//Print result
		printf("\nResult: %d\n", result);
		do{
			_flushall();
			printf("\nWould you like to continue? <Y or N>: ");
			scanf("%c", &cont);
			if(toupper(cont) != 'Y' && toupper(cont) != 'N')
			{
				printf("Invalid option, please choose Y or N\n");
			}
		}while(toupper(cont) != 'Y' && toupper(cont) != 'N');
	}
	return 0;
}