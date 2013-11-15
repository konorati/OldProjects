#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <class T>
class Stack
{
	public: 
		Stack (int newSize = 0);
		~Stack();

		bool push(T &newItem);
		bool pop(T &poppedItem);
		bool peek(T &item);

		bool isEmpty();

	private:
		int mSize;
		T *mTop; //This is a dynamically allocated array
};

template <class T>
Stack<T>::Stack (int newSize)
{
	mSize = newSize;
	mTop = new T[100];
}

template <class T>
Stack<T>::~Stack()
{
	delete [] mTop;
}

template <class T>
Stack<T>::push(T &newItem)
{
	bool status = false;

	mTop[mSize++] = newItem;
	status = true;

	return status;
}

template <class T>
Stack<T>::pop (T &poppedItem)
{
	bool status = false;

	poppedItem = mTop[mSize--];
	status = true;

	return status;
}

#endif