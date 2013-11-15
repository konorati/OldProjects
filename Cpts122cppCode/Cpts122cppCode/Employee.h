#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Employee
{
	protected:
		string mName;
		string mTitle;
		double mWage;
		int mSSNum;
		double mYearsWorked;
		bool mIsActive;
		string mReasonForTermination;

	public:
		Employee();
		Employee(Employee &rhs);
		~Employee();
		Employee & operator=(Employee &rhs);

		//Getters & Setters
		string getName();
		string getTitle();
		double getWage();
		int getSSNum();
		double getYearsWorked();
		bool getIsActive();

		void setName(string newName);
		void setTitle(string newTitle);
		void setWage(double newWage);
		void setSSNum (int newSSNum);
		void setYearsWorked(double newYearsWorked);
		void setIsActive(bool newIsActive);

		//Member functions
		void printEmployee();
		double computePay(double hours);
		
};



#endif