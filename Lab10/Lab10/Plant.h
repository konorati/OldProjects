#ifndef PLANT_H
#define PLANT_H

#include "Life.h"

class Plant : public Life
{
	public:
		Plant(double initsize = 0, double initrate = 0);
		~Plant();
		void nibbledOn(double amount);
};


#endif