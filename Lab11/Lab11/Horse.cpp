#include "Horse.h"

Horse::Horse()
{
	cout << "Horse constructor" << endl;
}

Horse::~Horse()
{
	cout << "Horse destructor" << endl;
}

void Horse::Move() const
{
	 cout << "Horse moves a step!" << endl;
}
void Horse::Speak() const
{
	cout << "What does a horse speak? Neeeiigghh!" << endl;
}