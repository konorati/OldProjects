#include "Functions.h"

int addition(int &num1, int &num2)
{
	int result = 0;
	cout << "Enter a number";
	cin >> num1;
	cout << "Enter another number";
	cin >> num2;
	result = num1 + num2;

	return result;
}



Rational::Rational(int num, int denom)
{
	mNumerator = num;
	if(denom == 0)
	{
		mDenominator = 1;
	}
	else
	{
		mDenominator = denom;
	}
}

Rational::Rational(Rational &rhs) //Overloaded function
{
	//Shallow copy
	mNumerator = rhs.mNumerator;
	mDenominator = rhs.mDenominator;
}

Rational::~Rational()
{
}

int Rational::getNumerator()
{
	return mNumerator;
}

int Rational::getDenominator()
{
	return mDenominator;
}

void Rational::setNumerator(int num)
{
	mNumerator = num;
}

void Rational::setDenominator(int num)
{
	mDenominator = num;
}

/*Rational Rational::add(Rational operand1, Rational operand2)
{
	Rational result;

	result.setDenominator ((operand1.getDenominator() * operand2.getDenominator()));
	result.setNumerator ((operand1.getNumerator() * operand2.getDenominator()) + 
		(operand2.getNumerator() * operand1.getDenominator()));

	return result;
}*/

/*Rational Rational::operator+(Rational &rhs)
{
	Rational result;

	result.setDenominator ((mDenominator * rhs.getDenominator()));
	result.setNumerator ((mNumerator * rhs.getDenominator()) + 
		(rhs.getNumerator() * mDenominator));

	return result;
}*/

Rational operator+(Rational &lhs, Rational &rhs)
{
	Rational result;

	result.setDenominator ((lhs.getDenominator() * rhs.getDenominator()));
	result.setNumerator ((lhs.getNumerator() * rhs.getDenominator()) + 
		(rhs.getNumerator() * lhs.getDenominator()));

	return result;
}

Rational & Rational::operator= (Rational &rhs)
{
	if(this != &rhs)
	{
		mNumerator = rhs.mNumerator;
		mDenominator = rhs.mDenominator;
	}
	return *this;
}

ostream  & operator<< (ostream &lhs, Rational &rhs)
{
	lhs << rhs.mNumerator << "/" << rhs.mDenominator;
	
	return lhs;
}

istream & operator>> (istream &lhs, Rational &rhs)
{
	char temp;
	lhs >> rhs.mNumerator >> temp >> rhs.mDenominator;

	return lhs;
}

Rational & Rational::operator-= (Rational &rhs)
{
	mNumerator = ((mNumerator * rhs.mDenominator) - (mDenominator *rhs.mNumerator));
	mDenominator = (mDenominator * rhs.mDenominator);
	return *this;
}

bool operator== (Rational &lhs, Rational &rhs)
{
	bool result = false;

	if((lhs.mNumerator * rhs.mDenominator) == (rhs.mNumerator * lhs.mDenominator))
	{
		result = true;
	}

	return result;

}