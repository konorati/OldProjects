#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <iostream>

using std::string;

class Calculator
{
	public:
		Calculator ();
		Calculator (Calculator &copy);
		~Calculator();

		int getAccumulator();
		void setAccumulator(int num);

		int addition(int operand1, int operand2);
		int subtraction(int operand1, int operand2);
		int multiplication(int operand1, int operand2);
		int division(int operand1, int operand2);

		void displayResult();

	private:
		int mAccumulator;
};

#endif