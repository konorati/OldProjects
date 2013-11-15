#ifndef MANAGER_H
#define MANAGER_H

#include "Store.h"
#include "Employee.h"
#include <list>

using std::list;


class Manager : public Employee
{
	public:
		Manager();
		~Manager();
		//Manager(Manager &copy);

		void addEmployee();
		void editEmployee();
		void changeDiscount(Store &store);
		double getPay();
		void terminateEmployee();
		list<Employee> employees;
};

#endif