#include "Mammal.h"

#include <iostream>


class Horse : public Mammal
{
	public:
            Horse();
            ~Horse(void);
			void Move(void) const;
			void Speak(void) const;
};