#include "Functions.h"
#include "FunctionTemplates.h"
#include "DivideByZero.h"


int main (void)
{
	int num = 10, den = 0, answer = 0;

	try
	{
		answer = divide(num, den);
		cout << "answer: " << answer << endl;
	}
	catch(DivideByZeroException &divideByZero)
	{
		cout << divideByZero.what () << endl;
	}
	//int num1 = 0, num2 = 0, result = 0;

	//result = addition(num1, num2);

	//cout << "Result = " << result << endl;

	//Rational number1(2, 7), number2(3, 8), result; //Constructor is implicitly called
	//result = number1 + number2;
	
	//cout << "Number: " << result.getNumerator() << "/" << result.getDenominator() << endl;
	//cout << result << endl;

	//cout << "result: " << add(number1, number2) << endl;
	return 0;
}

int divide(int num, int den)
{
	int answer = 0;

	if(den != 0)
	{
		answer = num / den;
	}
	else
	{
		throw DivideByZeroException();
	}

	return answer;
}
