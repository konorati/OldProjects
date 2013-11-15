#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;

int addition(int &num1, int &num2);

class Rational
{
	friend ostream  & operator<< (ostream &lhs, Rational &rhs);
	friend istream & operator>> (istream &lhs, Rational &rhs);
	friend bool operator== (Rational &lhs, Rational &rhs);
		
	private: 
		int mNumerator;
		int mDenominator;

	public:
		Rational(int num = 0, int denom = 1); //Default constructor
		~Rational(); //Destructor (frees dynamic memory)
		Rational(Rational &rhs); //Copy constructor (creates a copy)
		Rational & operator= (Rational &rhs);
		Rational & operator-= (Rational &rhs);

		int getNumerator();
		int getDenominator();
		void setNumerator(int num);
		void setDenominator(int num);

		//Rational add(Rational operand1, Rational operand2);
		//Rational operator+(Rational &rhs);
		
};

//Non members
Rational operator+(Rational &lhs, Rational &rhs);

#endif