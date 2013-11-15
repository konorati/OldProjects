#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>

using namespace std;

class Stack;

class StackNode
{
	friend class Stack;
	friend ostream & operator<< (ostream &lhs, StackNode &rhs);

	private:
		char data;
		StackNode *pNext;

	public:
		StackNode(char data = '\0', StackNode *pNext = NULL);
		~StackNode();
		char getData();
		StackNode *getNext();
		void setData(char newData);
		void setNext(StackNode *next);

};

class Stack
{
	friend ostream & operator<< (ostream &lhs, Stack &rhs);
	private:
		int size;
		StackNode *pTop;

	public:
		Stack();
		Stack(Stack &rhs);
		~Stack();
		Stack & operator=(Stack &rhs);
		void push(char newData);
		char pop(void);
		StackNode top(void);
		bool isEmpty(void);

		int getSize(void);
		StackNode *getTop(void);
		void setSize(int newSize);
		void setTop(StackNode *newTop);
};

string getPostfixExpression(void);
int evaluatePostfixExpression(string ex, Stack & stack1);

#endif