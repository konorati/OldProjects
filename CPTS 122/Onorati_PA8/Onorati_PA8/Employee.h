#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <iomanip>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::setprecision;
using std::fixed;

class Store;
class Employee
{
	public:
		Employee();
		~Employee();
		//Employee(Employee &rhs);

		//Getters & setters
		string getName() const;
		double getWage() const;
		int getSSNum() const;
		double getHoursWorked() const;

		void setName(string newName);
		void setWage(double newWage);
		void setSSNum(int newSSNum);
		void setHoursWorked(double newHours);

		//Member functions
		void transaction(Store &store);
		double applyDiscount(int type);
		virtual double getPay();
		void clockHours();

	protected:
		string mName;
		double mWage;
		int mSSNum;

	private:
		double hoursWorked;
		
};


#endif