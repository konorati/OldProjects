#include "Plant.h"

Plant::Plant(double initsize, double initrate)
{
	size = initsize;
	rate = initrate;
}

Plant::~Plant()
{
}

void Plant::nibbledOn(double amount)
{
	size -= amount;
	if(!isAlive())
	{
		death();
	}
}