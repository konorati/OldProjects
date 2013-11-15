#ifndef ANIMAL_H
#define ANIMAL_H

#include "Life.h"

class Animal : public Life
{
	public:
		Animal(double initSize = 0, double initRate = 0, double initNeed = 0);

		void eat(double amount);
		void simulateWeek();

	protected:
		double totNeed;
		double stillNeed;
};



#endif