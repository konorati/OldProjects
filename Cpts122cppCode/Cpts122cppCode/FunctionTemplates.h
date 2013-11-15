#ifndef FUNCTION_TEMPLATES_H
#define FUNCTION_TEMPLATES_H

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
using std::string;

template <class T>
T add (T operand1, T operand2)
{
	T result;
	result = operand1 + operand2;
	return result;
}

#endif