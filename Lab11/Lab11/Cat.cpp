#include "Cat.h"

Cat::Cat()
{
	cout << "Cat constructor" << endl;
}

Cat::~Cat()
{
	cout << "Cat destructor" << endl;
}

void Cat::Move() const
{
	 cout << "Cat moves a step!" << endl;
}
void Cat::Speak() const
{
	cout << "What does a cat speak? Meow!" << endl;
}