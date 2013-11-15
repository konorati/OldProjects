#include "GuineaPig.h"

GuineaPig::GuineaPig()
{
	cout << "Guinea Pig constructor" << endl;
}

GuineaPig::~GuineaPig()
{
	cout << "Guinea Pig destructor" << endl;
}

void GuineaPig::Move() const
{
	 cout << "Guinea Pig moves a step!" << endl;
}
void GuineaPig::Speak() const
{
	cout << "What does a guinea pig speak? Weep weep!" << endl;
}