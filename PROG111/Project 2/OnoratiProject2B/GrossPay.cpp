// File: MilesPerGallon.cpp
// calculates gross pay per pay period if paid bi-monthly and if paid every two weeks based on gross annual salary
//
// Input: none
// Output: twoWeekPay, biWeekPay
// -------------------------------------------------------------------------------
// Class: Prog 111 Online Instructor: Robert Main
// Project: 2B Date assigned: 9/24/12
// Programmer: Kristin Onorati Date submitted: 09/26/12

#include <iostream>

using namespace std;

//Calculates gross pay per paycheck for bi-monthly and every two week pay cycles and sends output to console
int main()
{
	//Define each variable and assign number of bi-monthly paychecks and number of paycheck per year if paid every two weeks
    int biMonthly = 24;
	int everyTwoWeeks = 26;
	double annualSalary = 35000;
	double paycheck; 

	paycheck = annualSalary / biMonthly; //Calculates gross pay per paycheck for a bi-monthly pay schedule

	cout << "A person who makes $" << annualSalary << " per year and is paid twice per month\n"; //Sends output for bi-monthly gross pay to console
	cout << "will make $" << paycheck << " in gross pay per paycheck\n";
	cout << endl;
	
	paycheck = annualSalary / everyTwoWeeks; //Calculates gross pay per paycheck for a every two weeks pay schedule
	
	cout << "A person who makes $" << annualSalary << " per year and is paid every two weeks\n"; //Sends output for gross pay on an every two weeks cycle to console
	cout << "will make $" << paycheck << " in gross pay per paycheck\n";

    return 0;
}