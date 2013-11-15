#ifndef CO_H
#define CO_H

#include <iostream>
#include <string>

#include "Manager.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class CO : public Manager
{
	public:
		void spent(double amountSpent);
		void earned(double amountEarned);

	private:
		double mExpenseAccount;
};
#endif