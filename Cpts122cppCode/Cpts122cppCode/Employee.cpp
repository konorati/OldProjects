#include "Employee.h"

Employee::Employee()
{

}
Employee::Employee(Employee &rhs);
Employee::~Employee();
Employee & Employee::operator=(Employee &rhs);

		//Getters & Setters
string Employee::getName();
string Employee::getTitle();
double Employee::getWage();
int Employee::getSSNum();
double Employee::getYearsWorked();
bool Employee::getIsActive();

void Employee::setName(string newName);
void Employee::setTitle(string newTitle);
void Employee::setWage(double newWage);
void Employee::setSSNum (int newSSNum);
void Employee::setYearsWorked(double newYearsWorked);
void Employee::setIsActive(bool newIsActive);

		//Member functions
void Employee::printEmployee();
double Employee::computePay(double hours)
{
	return (mWage * hours);
}