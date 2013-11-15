#include "Life.h"

Life::Life(double tSize, double tRate)
{
	size = tSize;
	rate = tRate;
}

Life::~Life()
{

}

double Life::getSize() const
{
	return size;
}

double Life::getRate() const
{
	return rate;
}

void Life::setSize(double newSize)
{
	size = newSize;
}

void Life::setRate(double newRate)
{
	rate = newRate;
}

void Life::simulateWeek()
{
	size += rate;
	if(!isAlive())
	{
		death();
	}
}

void Life::death()
{
	size = 0;
	rate = 0;
}

bool Life::isAlive() const
{
	bool alive = false;
	if(size > 0 )
	{
		alive = true;
	}
	return alive;
}

void Life::alterSize(double amount)
{
	size += amount;
	if(size <= 0)
	{
		death();
	}
}