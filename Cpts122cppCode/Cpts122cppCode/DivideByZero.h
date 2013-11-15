#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

class DivideByZeroException : public runtime_error
{
	public:
		DivideByZeroException () : runtime_error ("ERROR: Dividing by zero!") {};
};