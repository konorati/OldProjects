#ifndef APPLICATION_H
#define APPLICATION_H

#include "Store.h"
#include <list>
#include <fstream>

using std::list;
using std::fstream;



class Manager;
class Employee;
class Application
{
	public:
		Application();
		~Application();

		void runApplication();
		int mainMenu();
		int EmployeeMenu();
		int ManagerMenu();
		void loadManagers();
		void SaveManagers();
		void loadEmployees();
		void SaveEmployees();
		void login(int choice);
		void runManager(int choice);
		void runEmployee(int choice);

		fstream managerList;
		fstream employeeList;

	private:
		Store store;
		list<Manager> managers;
		list<Employee> employees;
		Employee *currentEmployee;
		Manager *currentManager;
};

#endif