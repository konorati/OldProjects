#include "stdafx.h"
#include "Calculator.h"

Calculator::Calculator ()
{
	mAccumulator = 0;
}

Calculator::Calculator (Calculator &copy)
{
	mAccumulator = copy.mAccumulator;
}

Calculator::~Calculator()
{
}

int Calculator::getAccumulator()
{
	return mAccumulator;
}

void Calculator::setAccumulator(int num)
{
	mAccumulator = num;
}

int Calculator::addition(int operand1, int operand2)
{
	mAccumulator = operand1 + operand2;
	return mAccumulator;
}

int Calculator::subtraction(int operand1, int operand2)
{
	mAccumulator = operand1 - operand2;
	return mAccumulator;
}

int Calculator::multiplication(int operand1, int operand2)
{
	mAccumulator = operand1 * operand2;
	return mAccumulator;
}

int Calculator::division(int operand1, int operand2)
{
	mAccumulator = operand1 / operand2;
	return mAccumulator;
}

void Calculator::displayResult()
{

}