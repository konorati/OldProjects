#include "Manager.h"

Manager::Manager()
{
}

Manager::~Manager()
{
}

/*Manager::Manager(Manager &copy)
{
}*/

void Manager::addEmployee()
{
	Employee *tempEmployee = new Employee();
	string tempName;
	int tempNum;
	double tempWage;
	_flushall();
	cout << "Enter employee name: ";
	getline(cin, tempName);
	tempEmployee->setName(tempName);
	cout << "Enter employee social security number: ";
	cin >> tempNum;
	tempEmployee->setSSNum(tempNum);
	cout << "Enter employee wages: ";
	cin >> tempWage;
	tempEmployee->setWage(tempWage);

	employees.push_back(*tempEmployee);
}

void Manager::editEmployee()
{
	string tempName;
	int tempNum;
	double tempWage;
	_flushall();
	cout << "Enter name of employee to edit: ";
	getline(cin, tempName);
	bool found = false;
	//Find employee
	list<Employee>::iterator iter = employees.begin();
	for(iter; iter != employees.end() && !found; iter++)
	{
		if(iter->getName() == tempName)
		{
			found = true;
			break;
		}
	}
	if(!found)
	{
		cout << "Employee not found" << endl;
	}
	else
	{
		int choice = 0;
		do
		{
			_flushall();
			system("cls");
			cout << endl << "Employee Information" << endl;
			cout << "1. Name: " << iter->getName() << endl;
			cout << "2. Social Security Number: " << iter->getSSNum() << endl;
			cout << fixed << setprecision(2) << "3. Wage: $" << iter->getWage() << endl;
			cout << "4. Done editing" << endl;
			cout << "Which field would you like to edit? ";
			cin >> choice;

			_flushall();
			switch(choice)
			{
			case 1: cout << "Enter new employee name: ";
				getline(cin, tempName);
				iter->setName(tempName);
				break;
			case 2: cout << "Enter new employee social security number: ";
				cin >> tempNum;
				iter->setSSNum(tempNum);
				break;
			case 3: cout << "Enter new employee wages: ";
				cin >> tempWage;
				iter->setWage(tempWage);
				break;
			case 4: break;
			default: cout << "Invalid selection" << endl;
				break;
			}
		}while(choice != 4);
	}
	//employees.sort(mName);
}
		
void Manager::changeDiscount(Store &store)
{
	int choice = 0;
	double tempDisc = 0.0;
	do
	{
		system("cls");
		_flushall();
		cout << endl << "Discounts: " << endl;
		cout << "1. Bulk: " << fixed << setprecision(2) << store.getBulkDiscount() << "%" << endl;
		cout << "2. Faculty: " << store.getFacultyDiscount() << "%" << endl;
		cout << "3. Staff: " << store.getStaffDiscount() << "%" << endl;
		cout << "4. Student: " << store.getStudentDiscount() << "%" << endl;
		cout << "Which discount would you like to edit <press 0 to exit>? ";
		cin >> choice;

		if(choice > 0 && choice < 5)
		{
			cout << "Enter new discount: ";
			cin >> tempDisc;
		}

		switch(choice)
		{
		case 0: break;
		case 1: store.setBulkDiscount(tempDisc);
			break;
		case 2: store.setFacultyDiscount(tempDisc);
			break;
		case 3: store.setStaffDiscount(tempDisc);
			break;
		case 4: store.setStudentDiscount(tempDisc);
			break;
		default: cout << "Invalid Selection" << endl;
			break;
		}
	}while(choice != 0);
}

double Manager::getPay()
{
	return mWage;
}

void Manager::terminateEmployee()
{
	string tempName;
	_flushall();
	cout << endl << "Enter name of employee to terminate: ";
	getline(cin, tempName);
	bool found = false;
	//Find employee
	list<Employee>::iterator iter = employees.begin();
	for(iter; iter != employees.end() && !found; iter++)
	{
		if(iter->getName() == tempName)
		{
			found = true;
			break;
		}
	}
	if(!found)
	{
		cout << "Employee not found" << endl;
	}
	else
	{
		employees.erase(iter);
		cout << "Employee has been terminated" << endl;
	}
}