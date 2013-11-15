#include "Stack.h"

int main(void)
{
	string postfix("62+5*84/-");
	string postfix2("562*+9/");
	int result = 0;
	Stack stack1;

	result = evaluatePostfixExpression(postfix2, stack1);
	cout << result << endl;

	
	
	return 0;
}