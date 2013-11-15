#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <string>
#include "Employee.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Manager : public Employee
{
	public:
		Manager();
		Manager(Manager &rhs);
		~Manager();

		void terminate(Employee &firedEmployee);
		Employee hire();
		void promote(Employee &newEmployee);

	protected:
		bool mIsSalaried;
		int mNumEmployees;
};



#endif