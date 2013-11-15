#include "Stack.h"

StackNode::StackNode(int data, StackNode *pNext)
{
	this->data = data;
	this->pNext = pNext;
}

StackNode::~StackNode()
{
}

int StackNode::getData()
{
	return data;
}

StackNode * StackNode::getNext()
{
	return pNext;
}

void StackNode::setData(int newData)
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
	int tempdata = 0;
	StackNode pMem = *pTop;
	pTop = pMem.pNext;
	tempdata = pMem.data;
	size--;
	return tempdata;
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

char Stack::peek()
{
	return pTop->data;
}