#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include "Compiler.h"

using namespace std;
using std::ostream;

template <class T>
class Stack;

template <class T>
class StackNode
{
	template <class T>
	friend class Stack;
	

	private:
		T data;
		StackNode<T> *pNext;

	public:
		StackNode(T data = 0, StackNode *pNext = NULL);
		~StackNode();
		T getData();
		StackNode<T> *getNext();
		void setData(T newData);
		void setNext(StackNode<T> *next);

};

template <class T>
class Stack
{
	
	private:
		int size;
		StackNode<T> *pTop;

	public:
		Stack();
		Stack(Stack &rhs);
		~Stack();
		Stack<T> & operator=(Stack<T> &rhs);
		void push(T newData);
		T pop();
		T peek();
		StackNode<T> top(void);
		bool isEmpty(void);

		int getSize(void);
		StackNode<T> *getTop(void);
		void setSize(int newSize);
		void setTop(StackNode<T> *newTop);
};

template <class T>
StackNode<T>::StackNode(T data, StackNode *pNext)
{
	this->data = data;
	this->pNext = pNext;
}

template <class T>
StackNode<T>::~StackNode()
{
}

template <class T>
T StackNode<T>::getData()
{
	return data;
}

template <class T>
StackNode<T> * StackNode<T>::getNext()
{
	return pNext;
}

template <class T>
void StackNode<T>::setData(T newData)
{
	data = newData;
}

template <class T>
void StackNode<T>::setNext(StackNode<T> *next)
{
	pNext = next;
}


template <class T>
Stack<T>::Stack()
{
	size = 0;
	pTop = NULL;
}

template <class T>
Stack<T>::Stack(Stack<T> &rhs)
{
	this->size = rhs.size;
	this->pTop = rhs.pTop;
}

template <class T>
Stack<T>::~Stack()
{
	delete pTop;
}

template <class T>
Stack<T> & Stack<T>::operator=(Stack<T> &rhs)
{
	if(this != &rhs)
	{
		size = rhs.size;
		pTop = rhs.pTop;
	}
	return *this;
}

template <class T>
void Stack<T>::push(T newData)
{
	StackNode<T> *newNode = new StackNode<T>(newData);
	newNode->pNext = pTop;
	pTop = newNode;
	size++;
}

template <class T>
T Stack<T>::pop(void)
{
	T tempdata = 0;
	StackNode<T> pMem = *pTop;
	pTop = pMem.pNext;
	tempdata = pMem.data;
	size--;
	
	return tempdata;
}

template <class T>
StackNode<T> Stack<T>::top(void)
{
	return *pTop;
}

template <class T>
bool Stack<T>::isEmpty(void)
{
	bool empty = false;
	if(pTop == NULL)
	{
		empty = true;
	}
	return empty;
}



template <class T>
int Stack<T>::getSize(void)
{
	return size;
}

template <class T>
StackNode<T> * Stack<T>::getTop(void)
{
	return pTop;
}

template <class T>
void Stack<T>::setSize(int newSize)
{
	size = newSize;
}

template <class T>
void Stack<T>::setTop(StackNode<T> *newTop)
{
	pTop = newTop;
}
template <class T>
T Stack<T>::peek()
{
	return pTop->data;
}

#endif