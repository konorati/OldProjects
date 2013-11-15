#include "Animal.h"

Animal::Animal(double initSize = 0, double initRate = 0, double initNeed = 0)
{
	size = initSize;
	rate = initRate;
	totNeed = stillNeed = initNeed;
}

void Animal::eat(double amount)
{
	stillNeed -= amount;
}

void Animal::simulateWeek()
{
	if(stillNeed > 0)
	{
		death();
	}
	else
	{
		stillNeed = totNeed;
		size += rate;
		if(size <= 0)
		{
			death();
		}
	}
}