#include "Manager.h"

void Manager::terminate (Employee &firedEmployee)
{
	string tempReason;
	firedEmployee.setIsActive(false);
	cout << "Enter reason for termination: ";
	getline(tempReason);
	setReasonForTermination(tempReason);
}

void Manager::promote (Employee &newEmployee);