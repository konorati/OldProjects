#include "Lab7.h"

StackNode::StackNode(char data, StackNode *pNext)
{
	this->data = data;
	this->pNext = pNext;
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

void Stack::push(StackNode &newNode)
{
	newNode.pNext = pTop;
	pTop = &newNode;
}

StackNode & Stack::pop(void)
{
	StackNode pMem = *pTop;
	pTop = pMem.pNext;
	return pMem;
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
		cout << conductor->getData() << " ";
		conductor = conductor->getNext();
	}
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

