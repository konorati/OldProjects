#include "Employee.h"
#include "Transaction.h"
#include "Store.h"

Employee::Employee()
{
	mName = "";
	mWage = 9.05;
	mSSNum = 000;
	hoursWorked = 0;
}

Employee::~Employee()
{
}

/*Employee::Employee(Employee &rhs)
{
	mName = rhs.mName;
	mWage = rhs.mWage;
	mSSNum = rhs.mSSNum;
	hoursWorked = rhs.hoursWorked;
}*/

//Getters & setters
string Employee::getName() const
{
	return mName;
}

double Employee::getWage() const
{
	return mWage;
}

int Employee::getSSNum() const
{
	return mSSNum;
}

double Employee::getHoursWorked() const
{
	return hoursWorked;
}

void Employee::setName(string newName)
{
	mName = newName;
}

void Employee::setWage(double newWage)
{
	mWage = newWage;
}

void Employee::setSSNum(int newSSNum)
{
	mSSNum = newSSNum;
}

void Employee::setHoursWorked(double newHours)
{
	hoursWorked = newHours;
}

//Member functions
void Employee::transaction(Store &store)
{
	Transaction *pTransaction = new Transaction();
	pTransaction->mID = store.getTransactionID();
	pTransaction->setType();
	if(pTransaction->mType == 1)
	{
		pTransaction->sale(store);
		//Get & apply discount
	}
	else
	{
		pTransaction->retrn(store);
	}
	store.increaseTransactionID();
}

double Employee::getPay()
{
	return (hoursWorked * mWage);
}

void Employee::clockHours()
{
	double tempHours = 0;
	do{
		cout << "Enter number of hours worked for this shift: ";
		cin >> tempHours;
		if(tempHours <= 0)
		{
			cout << "Invalid entry, number of hours must be greater than 0" << endl;
		}
	}while(tempHours <= 0);

	hoursWorked += tempHours;
}