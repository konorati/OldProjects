#include "Stack.h"

StackNode::StackNode(char data, StackNode *pNext)
{
	this->data = data;
	this->pNext = pNext;
}

StackNode::~StackNode()
{
}

char StackNode::getData()
{
	return data;
}

StackNode * StackNode::getNext()
{
	return pNext;
}

void StackNode::setData(char newData)
{
	data = newData;
}

void StackNode::setNext(StackNode *next)
{
	pNext = next;
}

ostream & operator<< (ostream &lhs, StackNode &rhs)
{
	lhs << rhs.data;

	return lhs;
}

Stack::Stack()
{
	size = 0;
	pTop = NULL;
}

Stack::Stack(Stack &rhs)
{
	this->size = rhs.size;
	this->pTop = rhs.pTop;
}

Stack::~Stack()
{

}

Stack & Stack::operator=(Stack &rhs)
{
	if(this != &rhs)
	{
		size = rhs.size;
		pTop = rhs.pTop;
	}
	return *this;
}

void Stack::push(char newData)
{
	StackNode *newNode = new StackNode(newData);
	newNode->pNext = pTop;
	pTop = newNode;
	size++;
}

char Stack::pop(void)
{
	char tempChar = '\0';
	StackNode pMem = *pTop;
	pTop = pMem.pNext;
	tempChar = pMem.data;
	size--;
	return tempChar;;
}

StackNode Stack::top(void)
{
	return *pTop;
}

bool Stack::isEmpty(void)
{
	bool empty = false;
	if(pTop == NULL)
	{
		empty = true;
	}
	return empty;
}

ostream & operator<< (ostream &lhs, Stack &rhs)
{
	StackNode *conductor = NULL;
	conductor = rhs.pTop;
	while(conductor != NULL)
	{
		lhs << conductor->getData() << " ";
		conductor = conductor->getNext();
	}
	return lhs;
}

int Stack::getSize(void)
{
	return size;
}

StackNode * Stack::getTop(void)
{
	return pTop;
}

void Stack::setSize(int newSize)
{
	size = newSize;
}

void Stack::setTop(StackNode *newTop)
{
	pTop = newTop;
}

int evaluatePostfixExpression(string ex, Stack & stack1)
{
	int i = 0, op1 = 0, op2 = 0, result = 0;
	char c = ex.at(i);
	while(i < ex.length())
	{
		c = ex.at(i);
	//1. If digit, push digit to stack
		if(isdigit(c))
		{
			stack1.push(c);
		}
	//2. if operator pop two elements from stack (op2 & op1), evaluate op1 operator op2, push result to stack
		else
		{
			op2 = (int)(stack1.pop() - 48);
			op1 = (int)(stack1.pop() - 48);
			switch(c)
			{
			case '+': result = op1 + op2;
				break;
			case '-': result = op1 - op2;
				break;
			case '*': result = op1 * op2;
				break;
			case '/': result = op1 / op2;
				break;
			}
			stack1.push(result+48);
		}
		i++;
		
	}
	result = (stack1.pop()-48);
	return result;
}