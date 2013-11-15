#include "Dog.h"

Dog::Dog()
{
	cout << "Dog constructor" << endl;
}

Dog::~Dog()
{
	cout << "Dog destructor" << endl;
}

void Dog::Move() const
{
	 cout << "Dog moves a step!" << endl;
}
void Dog::Speak() const
{
	cout << "What does a dog speak? Woof!" << endl;
}