#ifndef INFIX_TO_POSTFIX_H
#define INFIX_TO_POSTFIX_H

#include <iostream>
#include <string>
#include <cmath>
#include "Compiler.h"
#include <vector>



using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;
using std::vector;

template <class T>
class Stack;
class Compiler;

class PostfixEvaluator
{
	public:
		PostfixEvaluator();
		~PostfixEvaluator();
		PostfixEvaluator(PostfixEvaluator &rhs);

		//Getters & setters
		string getExpression() const;
		int getOp1() const;
		int getOp2() const;
		int getOperator() const;
		int getOpLocation() const;

		void setExpression(string newExpression);
		void setOp1(int newOp1);
		void setOp2(int newOp2);
		void setOperator(char newOperator);
		void setOpLocation(int newOpLocation);

		int evaluateExpression(Stack<int> & stack1, Compiler & compiler1, Simpletron &SML);

	private:
		string mExpression;
		int op1;
		int op2;
		char mOperator;
		int opLocation;

};

class InfixToPostfix
{
	friend class Compiler;
	public:
		InfixToPostfix();
		~InfixToPostfix();
		InfixToPostfix(InfixToPostfix & rhs);

		//Getters & setters
		string getInfix() const;
		string getPostfix() const;

		void setInfix(string newInfix);
		void setPostfix(string newPostfix);

		void convertToPostfix(Stack<char> & stack1);
		bool isOperator(char op1);
		int precedence(char op1, char op2);

	private:
		string infixExpression;
		string postfixExpression;
};







#endif