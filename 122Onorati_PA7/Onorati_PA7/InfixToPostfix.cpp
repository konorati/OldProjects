#include "stdafx.h"
#include "InfixToPostfix.h"


//POSTFIX EVALUATOR FUNCTIONS
PostfixEvaluator::PostfixEvaluator()
{
	mExpression = "";
	op1 = 0;
	op2 = 0;
	mOperator = '\0';
	opLocation = 0;
}

PostfixEvaluator::~PostfixEvaluator()
{
}

PostfixEvaluator::PostfixEvaluator(PostfixEvaluator &rhs)
{
	mExpression = rhs.mExpression;
	op1 = rhs.op1;
	op2 = rhs.op2;
	mOperator = rhs.mOperator;
	opLocation = rhs.opLocation;
}

		//Getters & setters
string PostfixEvaluator::getExpression() const
{
	return mExpression;
}

int PostfixEvaluator::getOp1() const
{
	return op1;
}

int PostfixEvaluator::getOp2() const
{
	return op2;
}

int PostfixEvaluator::getOperator() const
{
	return mOperator;
}

int PostfixEvaluator::getOpLocation() const
{
	return opLocation;
}

void PostfixEvaluator::setExpression(string newExpression)
{
	mExpression = newExpression;
}

void PostfixEvaluator::setOp1(int newOp1)
{
	op1 = newOp1;
}

void PostfixEvaluator::setOp2(int newOp2)
{
	op2 = newOp2;
}

void PostfixEvaluator::setOperator(char newOperator)
{
	mOperator = newOperator;
}

void PostfixEvaluator::setOpLocation(int newOpLocation)
{
	opLocation = newOpLocation;
}

int PostfixEvaluator::evaluateExpression(Stack<int> & stack1, Compiler & compiler1, Simpletron & SML)
{
	int i = 0;
	int resultLocation = 0;
	char resultVar = 'A';
	int num;
	string strNum;
	
	for(i = 0; i != mExpression.length(); i++)
	{
		if(mExpression[i] == ' ');
	//1. If digit, push digits memory location to stack
		else if(isdigit(mExpression[i]))
		{
			while(isdigit(mExpression[i]))
			{
				strNum.push_back(mExpression[i]);
				i++;
			}
			i--;
			num = atoi(strNum.c_str());
			opLocation = compiler1.findVariable(num, 'C');
			if(opLocation == -1)
			{
				compiler1.linePiece = strNum;
				compiler1.createEntry('C');
				opLocation = compiler1.findVariable(num, 'C');
				SML.memory[opLocation] = num;
			}
			stack1.push(opLocation);
		}
		//If alpha, push variables memory location to stack
		else if(isalpha(mExpression[i]))
		{
			opLocation = compiler1.findVariable(mExpression[i], 'V');
			if(opLocation == -1)
			{
				compiler1.linePiece = to_string(mExpression[i]);
				compiler1.createEntry('V');
				opLocation = compiler1.findVariable(mExpression[i], 'V');
			}
			stack1.push(opLocation);
		}
	//2. if operator pop two elements from stack (op2 & op1), evaluate op1 operator op2, push result to stack
		else
		{
			op2 = stack1.pop();
			op1 = stack1.pop();
			SML.store(compiler1.memBegin, 20000 + op1);
			compiler1.memBegin++;
			switch(mExpression[i])
			{
			case '+': 
				SML.store(compiler1.memBegin, 30000 + op2);
				//TODO: temp store result
				break;
			case '-': 
				SML.store(compiler1.memBegin, 31000 + op2);
				//TODO: temp store result
				break;
			case '*': 
				SML.store(compiler1.memBegin, 33000 + op2);
				//TODO: temp store result
				break;
			case '/': 
				SML.store(compiler1.memBegin, 32000 + op2);
				//TODO: temp store result
				break;
			case '%': 
				SML.store(compiler1.memBegin, 34000 + op2);
				//TODO: temp store result
				break;
			case '^': 
				SML.store(compiler1.memBegin, 35000 + op2);
				//TODO: temp store result
				break;
			}
			compiler1.memBegin++;
			//Create table entry for temporary result
			compiler1.linePiece = to_string(resultVar);
			compiler1.createEntry('V');
			//Push location of result to stack
			opLocation = compiler1.findVariable(resultVar++, 'V');
			stack1.push(opLocation);
			//Store instruction for saving result in memory
			SML.store(compiler1.memBegin, 21000 + opLocation);
			compiler1.memBegin++;
		}
	}
	//Once expression has finished evaluating, pop result location from stack and return
	resultLocation = stack1.pop();
	return resultLocation;
}



//INFIX TO POSTFIX FUNCTIONS
InfixToPostfix::InfixToPostfix()
{
	infixExpression = "";
	postfixExpression = "";
}

InfixToPostfix::~InfixToPostfix()
{
}

InfixToPostfix::InfixToPostfix(InfixToPostfix & rhs)
{
	infixExpression = rhs.infixExpression;
	postfixExpression = rhs.postfixExpression;
}

		//Getters & setters
string InfixToPostfix::getInfix() const
{
	return infixExpression;
}
string InfixToPostfix::getPostfix() const
{
	return postfixExpression;
}

void InfixToPostfix::setInfix(string newInfix)
{
	infixExpression = newInfix;
}
void InfixToPostfix::setPostfix(string newPostfix)
{
	postfixExpression = newPostfix;
}

void InfixToPostfix::convertToPostfix(Stack<char> & stack1)
{
	
	int i = 0;
	
	bool keepTrying = true;
	//1. Push left parentheses onto stack
	stack1.push('(');
	//2. Append right parentheses to end of infix
	infixExpression.push_back(' ');
	infixExpression.push_back(')');
	//3. While stack is not empty read infix from left to right
	for(i = 0; i != infixExpression.length(); i++)
	{
		keepTrying = true;
		if(infixExpression[i] == ' ')
		{
			i++;
		}
		//a. If current char in infix is a digit copy it to next element in postfix
		if(isalnum(infixExpression[i]))
		{
			while(isalnum(infixExpression[i]))
			{
				postfixExpression.push_back(infixExpression[i]);
				i++;
			}
			i--;
			postfixExpression.push_back(' ');
		}
		//b. If current char is left parenthesis, push to stack
		else if(infixExpression[i] == '(')
		{
			stack1.push(infixExpression[i]);
		}
		//d. If current char is right parenthesis pop operators from stack and append to postfix until left parethensis (discard)
		else if(infixExpression[i] == ')')
		{
			while(stack1.peek() != '(')
			{
				postfixExpression.push_back(stack1.pop());
				postfixExpression.push_back(' ');
			}
			stack1.pop(); //Discard parenthesis
		}
		//c. If current char is operator 
		else
		{
			//pop operators from stack (if any with equal or higher precedence) and append to postfix
			while(keepTrying && isOperator(stack1.peek()))
			{
				if(precedence(stack1.peek(), infixExpression[i]) >= 0)
				{
					postfixExpression.push_back(stack1.pop());
					postfixExpression.push_back(' ');
				}
				else
				{
					keepTrying = false;
				}
			}
			//Push current operator to stack
		stack1.push(infixExpression[i]);
		}
	}
}

bool InfixToPostfix::isOperator(char op1)
{
	bool isOp = false;
	if(op1 == '+' || op1 == '-' || op1 == '*' || op1 == '/' || op1 == '%' || op1 == '^')
	{
		isOp = true;
	}
	return isOp;
}

int InfixToPostfix::precedence(char op1, char op2)
{
	if(op1 == '+' || op1 == '-')
	{
		op1 = 0;
	}
	else
	{
		op1 = 1;
	}
	if(op2 == '+' || op1 == '-')
	{
		op2 = 0;
	}
	else
	{
		op2 = 1;
	}
	return (op1 - op2);
}