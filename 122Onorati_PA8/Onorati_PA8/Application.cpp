#include "Application.h"

Application::Application()
{
}
Application::~Application()
{
}

void Application::runApplication()
{
	int choice = 0, empChoice = 0;

	//Load employees & managers
	loadManagers();
	loadEmployees();
	

	do
	{
		system("cls");
		_flushall();
		//Display main menu & get selection
		choice = mainMenu();
		//Login as either employee or manager
		login(choice);
		if(currentEmployee != NULL || currentManager != NULL)
		{
			switch(choice)
			{
			case 1: //Logged in as manager
				do
				{
					empChoice = ManagerMenu();
					runManager(empChoice);
				}while(empChoice != 11);
				break;
			case 2: //Logged in as employee
				do
				{
					empChoice = EmployeeMenu();
					runEmployee(empChoice);
				}while(empChoice != 7);
				break;
			default:
				break;
			}
			currentEmployee = NULL;
			currentManager = NULL;
		}
		else if(choice != 3)
		{
			cout << "Invalid Login" << endl;
		}
	}while(choice != 3);
	store.saveInventory();
	cout << "Now exiting program" << endl;
}

int Application::EmployeeMenu()
{
	int choice;
	do
	{
		system("cls");
		cout << "*** Employee Menu ***" << endl;
		cout << "1. Clock hours" << endl;
		cout << "2. Run transaction" << endl;
		cout << "3. Display all inventory" << endl;
		cout << "4. Display inventory category" << endl;
		cout << "5. Display inventory subcategory" << endl;
		cout << "6. Display inventory item" << endl;
		cout << "7. Logout" << endl;
		cout << "Enter menu choice: ";
		cin >> choice;
		if(choice < 1 || choice > 7)
		{
			cout << "Invalid selection" << endl;
			system("pause");
		}
	}while(choice < 1 || choice > 7);
	return choice;
}

int Application::mainMenu()
{
	int choice = 0;
	do
	{
		system("cls");
		cout << "*** Main Menu ***" << endl;
		cout << "1. Manager Login" << endl;
		cout << "2. Employee Login" << endl;
		cout << "3. Exit Program" << endl;
		cout << "Enter menu choice: ";
		cin >> choice;
		if(choice < 1 || choice > 3)
		{
			cout << "Invalid choice" << endl;
		}
	}while(choice < 1 || choice > 3);

	return choice;
}

int Application::ManagerMenu()
{
	int choice;
	do
	{
		system("cls");
		_flushall();
		cout << "*** Manager Menu ***" << endl;
		cout << "1. Run transaction" << endl;
		cout << "2. Update inventory item" << endl;
		cout << "3. Display all inventory" << endl;
		cout << "4. Display inventory category" << endl;
		cout << "5. Display inventory subcategory" << endl;
		cout << "6. Display inventory item" << endl;
		cout << "7. Update discounts" << endl;
		cout << "8. Add employee" << endl;
		cout << "9. Edit employee info" << endl;
		cout << "10. Terminate employee" << endl;
		cout << "11. Logout" << endl;
		cout << "Enter menu choice: ";
		cin >> choice;
		if(choice < 1 || choice > 11)
		{
			cout << "Invalid selection" << endl;
			system("pause");
		}
	}while(choice < 1 || choice > 11);
	return choice;
}

void Application::loadManagers()
{
	Manager *pTemp;
	string tmpString;
	managerList.open("Managerlist.txt", ios::in);
	while(managerList.good())
	{
		pTemp = new Manager();
		getline(managerList, tmpString);
		pTemp->setName(tmpString);
		getline(managerList, tmpString);
		pTemp->setSSNum(atoi(tmpString.c_str()));
		getline(managerList, tmpString);
		pTemp->setWage(atof(tmpString.c_str()));
		if(managerList.good())
		{
			getline(managerList, tmpString); //Get rid of blank line
		}
		managers.push_back(*pTemp);
	}
	managerList.close();
}

void Application::SaveManagers()
{
	managerList.open("ManagerList.txt", ios::out);
	list<Manager>::iterator iter = managers.begin();
	for(iter; iter != managers.end(); iter++)
	{
		managerList << iter->getName() << endl;
		managerList << iter->getSSNum() << endl;
		managerList << iter->getWage() << endl;
		managerList << endl;
	}
	managerList.close();
}

void Application::loadEmployees()
{
	string tmpString;
	Employee *pTemp;
	employeeList.open("EmployeeList.txt", ios::in);
	while(employeeList.good())
	{
		pTemp = new Employee();
		getline(employeeList, tmpString);
		pTemp->setName(tmpString);
		getline(employeeList, tmpString);
		pTemp->setSSNum(atoi(tmpString.c_str()));
		getline(employeeList, tmpString);
		pTemp->setWage(atof(tmpString.c_str()));
		getline(employeeList, tmpString);
		pTemp->setHoursWorked(atof(tmpString.c_str()));
		if(employeeList.good())
		{
			getline(employeeList, tmpString); //Get rid of blank line
		}
		employees.push_back(*pTemp);
		managers.begin()->employees.push_back(*pTemp);
	}

	employeeList.close();
}

void Application::SaveEmployees()
{
	employeeList.open("EmployeeList.txt", ios::out);
	list<Manager>:: iterator iterMan = managers.begin();
	list<Employee>::iterator iter;
	for(iterMan; iterMan != managers.end(); iterMan++)
	{
		for(iter = iterMan->employees.begin(); iter != iterMan->employees.end(); iter++)
		{
			employeeList << iter->getName() << endl;
			employeeList << iter->getSSNum() << endl;
			employeeList << iter->getWage() << endl;
			employeeList << iter->getHoursWorked() << endl;
			employeeList << endl;
		}
	}
	employeeList.close();
}

void Application::login(int choice)
{
	string name;
	_flushall();
	if(choice == 1 || choice == 2)
	{
		cout << "Enter login name: ";
		getline(cin, name);
	}

	
	switch(choice)
	{
		case 1:
			for(list<Manager>::iterator iter = managers.begin(); iter != managers.end(); iter++)
			{
				if(iter->getName() == name)
				{
					currentManager = &(*iter);
				}
			}
			break;
		case 2:
			for(list<Employee>::iterator iterEmp = employees.begin(); iterEmp != employees.end(); iterEmp++)
			{
				if(iterEmp->getName() == name)
				{
					currentEmployee = &(*iterEmp);
				}
			}
			break;
		default:
			break;
	}
	if(choice == 1 && currentManager == NULL)
	{
		cout << "Manager not found" << endl;
	}
	else if(choice == 2 && currentEmployee == NULL)
	{
		cout << "Employee not found" << endl;
	}
}

void Application::runManager(int choice)
{
	string tempStr;
	_flushall();
	switch(choice)
	{
		case 1: currentManager->transaction(store); //Run transaction
			break;
		case 2: store.updateInventory(); //Update inventory
			break;
		case 3: store.printInventory(); //Display all inventory
			system("pause");
			break;
		case 4: cout << "Enter category: ";
			getline(cin, tempStr);
			store.printInventory(tempStr, "category"); //Display category
			system("pause");
			break;
		case 5: cout << "Enter subcategory: ";
			getline(cin, tempStr);
			store.printInventory(tempStr, "subcategory"); //Display subcategory
			system("pause");
			break;
		case 6: cout << "Enter item name: ";
			getline(cin, tempStr);
			store.printInventory(tempStr, "name");//Display individual item
			system("pause");
			break;
		case 7: currentManager->changeDiscount(store);//Update discounts
			system("pause");
			break;
		case 8: currentManager->addEmployee();//Add employee
			system("pause");
			break;
		case 9: currentManager->editEmployee();//Edit employee
			system("pause");
			break;
		case 10: currentManager->terminateEmployee();//Terminate employee
			system("pause");
			break;
		default:
			break;
	}
}

void Application::runEmployee(int choice)
{
	string tempStr;
	_flushall();
	switch(choice)
	{
		case 1: currentEmployee->clockHours();//Clock hours
			system("pause");
			break;
		case 2: currentEmployee->transaction(store);//Transaction
			break;
		case 3: store.printInventory();//Display all inventory
			system("pause");
			break;
		case 4: cout << "Enter category: ";
			getline(cin, tempStr);
			store.printInventory(tempStr, "category");//Display category
			system("pause");
			break;
		case 5: cout << "Enter subcategory: ";
			getline(cin, tempStr);
			store.printInventory(tempStr, "subcategory");//Display subcategory
			system("pause");
			break;
		case 6: cout << "Enter item name: ";
			getline(cin, tempStr);
			store.printInventory(tempStr, "name");//Display item
			system("pause");
			break;
		default:
			break;
	}
}