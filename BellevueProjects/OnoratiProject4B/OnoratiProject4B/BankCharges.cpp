// File: BankCharges.cpp
// This program calculates the total bank charges based on number of checks written during the month
// Input: Number of checks written
// Output: Total bank fees
// -------------------------------------------------------------------------------
// Class: Prog 111 Online Instructor: Robert Main
// Project: 4B Date assigned: 10/01/12
// Programmer: Kristin Onorati Date submitted: 10/02/12

#include <iostream>
#include <iomanip>

using namespace std;

//This program calculates total bank fees using a standard fee and then fees based on increasing number of checks
int main() {

	const double FEE = 10.0; //Standard monthly fee
	int checks; //number of checks written during past month
	double bankFees; //Total bank fees
	double fee1 = .10; //fee for 1-19 checks
	double fee2 = .08; //fee for 20-39 checks
	double fee3 = .06; //fee for 40-59 checks
	double fee4 = .04; //fee for 60+ checks

	cout << "This program calculates total monthly bank charges\n";
	cout << endl;
	cout << "How many checks were written during the last month?\n";
	cin >> checks;
	cout << endl;

	if (checks >= 0){
		if (checks < 20){
			bankFees = FEE + (checks * fee1); //calculated total fee for less than 20 checks
		}
		else if (checks < 40){
			bankFees = FEE + (19.0 * fee1) + (checks - 19) * fee2; //calculates total fee for 20-39 checks
		}
		else if (checks < 60){
			bankFees = FEE + (19.0 * fee1) + (20.0 * fee2) + (checks - 39) * fee3; //calculates total fee for 40-59 checks
		}
		else {
			bankFees = FEE + (19.0 * fee1) + (20.0 * fee2) + (20.0 * fee3) + (checks - 59) * fee4; //calculates total fee for 60+ checks
		}
		cout << fixed << setprecision(2);
		cout << "The total bank fees for this month are $" << bankFees << endl; //outputs total bankfees to console
	}
	else { //Outputs error message to console if an invalid number of checks is given
		cout << "Please run the program again and enter a number \nof checks that is greater than or equal to 0\n";
	}
	system("pause");
	return 0;

}