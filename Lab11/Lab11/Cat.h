#include "Mammal.h"

#include <iostream>


class Cat : public Mammal
{
	public:
            Cat();
            ~Cat(void);
			void Move() const;
			void Speak() const;
};