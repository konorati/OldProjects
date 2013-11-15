#include "Mammal.h"

#include <iostream>


class Dog : public Mammal
{
	public:
            Dog();
            ~Dog(void);
			void Move() const;
			void Speak() const;
};