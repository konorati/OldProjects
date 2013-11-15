
// File: MonthlyPayment.cpp
// This program calculates the monthly loan payment based on interest rate, number of payments, and loan amount
// Input: Interest rate, number of payments, loan amount
// Output: monthly interest rate, monthly payment, amount paid back, total interest paid, number of payments, loan amount
// -------------------------------------------------------------------------------
// Class: Prog 111 Online Instructor: Robert Main
// Project: 3 Date assigned: 9/26/12
// Programmer: Kristin Onorati Date submitted: 10/01/12

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//This program calculates the monthly loan payment based on interest rate, number of payments, and loan amount
int main()
{
	//Defines the variables
	double loanAmount, annualInterestRate, monthlyInterestRate, monthlyPayment, amountPaidBack, interestPaid;
	int numOfPayments;

	//Sends output describing what the program does to the console
	cout << "This program calculates the monthly loan payment based on interest rate, number of payments, and loan amount";
	cout << endl << endl;

	//Gets input from user to assign loan amount
	cout << "What is the total loan amount? ";
	cin >> loanAmount;

	//Gets input from user to assign annual interest rate
	cout << endl << "What is the annual interest rate? ";
	cin >> annualInterestRate;

	//Gets input from user to assign number of monthly payments
	cout << endl << "What are the total number of monthly payments? ";
	cin >> numOfPayments;
	cout << endl;

	//Calculates monthly interest rate
	monthlyInterestRate = (annualInterestRate / 12)/100;

	//Calculates monthly payment
	monthlyPayment = ((monthlyInterestRate * pow(1 + monthlyInterestRate, numOfPayments)) / (pow(1 + monthlyInterestRate, numOfPayments) - 1)) * loanAmount;

	//Calculates total amount paid back
	amountPaidBack = monthlyPayment * numOfPayments;

	//Calculates total interest paid
	interestPaid = amountPaidBack - loanAmount; 

	//Sends output to console
	cout << left << setw(25) << "Loan Amount:" << "$";
	cout << right << fixed << setprecision(2) << setw(10) << loanAmount << endl;
	cout << left << setw(25) << "Monthly Interest Rate:";
	cout << right << fixed << setprecision(2) << setw(10) << monthlyInterestRate * 100 << "%" << endl;
	cout << left << setw(25) << "Number of Payments:";
	cout << right << setw(11) << numOfPayments << endl;
	cout << left << setw(25) << "Monthly Payment:" << "$";
	cout << right << fixed << setprecision(2) << setw(10) << monthlyPayment << endl;
	cout << left << setw(25) << "Amount Paid Back:" << "$";
	cout << right << fixed << setprecision(2) << setw(10) << amountPaidBack << endl;
	cout << left << setw(25) << "Interest Paid:" << "$";
	cout << right << fixed << setprecision(2) << setw(10) << interestPaid << endl;
	return 0;
}
