#include "Mammal.h"

#include <iostream>


class GuineaPig : public Mammal
{
	public:
            GuineaPig();
            ~GuineaPig(void);
			void Move() const;
			void Speak() const;
};