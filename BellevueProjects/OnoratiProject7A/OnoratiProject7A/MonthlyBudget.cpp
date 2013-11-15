// File: MonthlyBudget.cpp
// This program inputs, calculates, and displays user's monthly budget info
// Input: Monthly spending (housing, utilities, household, transportation,
//        food, medical, insurance, entertainment, clothing, miscellaneous.
// Output: Monthly budget differences (housing, utilities, household, transportation,
//        food, medical, insurance, entertainment, clothing, miscellaneous.
// -------------------------------------------------------------------------------
// Class: Prog 111 Online Instructor: Robert Main
// Project: 7A Date assigned: 11/02/12
// Programmer: Kristin Onorati Date submitted: 11/08/12

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Declare structure
struct MonthlyBudget {
	double housing, utilities, household, transportation, 
		food, medical, insurance, entertainment, clothing, misc;
};
//Function prototypes
void setSpending(MonthlyBudget&);
void reportBudget(MonthlyBudget, MonthlyBudget);
double validateSpending(string);

//Main calls functions to set and display budget report
int main() {
	MonthlyBudget budget = {500, 150, 65, 50, 250, 30, 100, 150, 75, 50};
	MonthlyBudget month1;

	setSpending(month1);
	system("cls");
	reportBudget(budget, month1);

	system("pause");
	return 0;
}

//Prompts user for monthly spending and sets data into structure
void setSpending(MonthlyBudget& thisMonth){
	thisMonth.housing = validateSpending("housing");
	thisMonth.utilities = validateSpending("utlities");
	thisMonth.household = validateSpending("household expenses");
	thisMonth.transportation = validateSpending("transportation");
	thisMonth.food = validateSpending("food");
	thisMonth.medical = validateSpending("medical");
	thisMonth.insurance = validateSpending("insurance");
	thisMonth.entertainment = validateSpending("entertainment");
	thisMonth.clothing = validateSpending("clothing");
	thisMonth.misc = validateSpending("miscellaneous expenses");

}
//Validates user input
double validateSpending(string budgetItem){
	double spending;
	cout << "Enter how much you spent this month on " << budgetItem << ": ";
	cin >> spending;
	while (spending < 0){
		cout <<"Amount entered is not valid. Enter a positive value: ";
		cin >> spending;
	}

	return spending;
}
//Computes budget differences and displays budget information in console
void reportBudget(MonthlyBudget budget, MonthlyBudget thisMonth){
	double difHousing, difUtil, difHHold, difTrans, 
		difFood, difMed, difInsure, difEnt, difCloth, difMisc,
		totBudget, totSpent, difTotal;

	difHousing = budget.housing - thisMonth.housing;
	difUtil = budget.utilities - thisMonth.utilities;
	difHHold = budget.household - thisMonth.household;
	difTrans = budget.transportation - thisMonth.transportation;
	difFood = budget.food - thisMonth.food;
	difMed = budget.medical - thisMonth.medical;
	difInsure = budget.insurance - thisMonth.insurance;
	difEnt = budget.entertainment - thisMonth.entertainment;
	difCloth = budget.clothing - thisMonth.clothing;
	difMisc = budget.misc - thisMonth.misc;

	totBudget = budget.housing + budget.utilities + budget.household +
		budget.transportation + budget.food + budget.medical +
		budget.insurance + budget.entertainment + budget.clothing +
		budget.misc;
	totSpent = thisMonth.housing + thisMonth.utilities + thisMonth.household +
		thisMonth.transportation + thisMonth.food + thisMonth.medical +
		thisMonth.insurance + thisMonth.entertainment +
		thisMonth.clothing + thisMonth.misc;
	difTotal = totBudget - totSpent;

	cout << setw(30) << "Budget" << setw(10) << "Spending" 
		 << setw(12) << "Difference" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << left << setw(22) << "Housing:"
		 << right << setw(8) << fixed << setprecision(2) << budget.housing
		 << setw(10) << thisMonth.housing << setw(12) << difHousing << endl;
	cout << left << setw(22) << "Utilities:"
		 << right << setw(8) << fixed << setprecision(2) << budget.utilities
		 << setw(10) << thisMonth.utilities << setw(12) << difUtil << endl;
	cout << left << setw(22) << "Household Expenses:"
		 << right << setw(8) << fixed << setprecision(2) << budget.household
		 << setw(10) << thisMonth.household << setw(12) << difHHold << endl;
	cout << left << setw(22) << "Transportation:"
		 << right << setw(8) << fixed << setprecision(2) << budget.transportation
		 << setw(10) << thisMonth.transportation << setw(12) << difTrans << endl;
	cout << left << setw(22) << "Food:"
		 << right << setw(8) << fixed << setprecision(2) << budget.food
		 << setw(10) << thisMonth.food << setw(12) << difFood << endl;
	cout << left << setw(22) << "Medical:"
		 << right << setw(8) << fixed << setprecision(2) << budget.medical
		 << setw(10) << thisMonth.medical << setw(12) << difMed << endl;
	cout << left << setw(22) << "Insurance:"
		 << right << setw(8) << fixed << setprecision(2) << budget.insurance
		 << setw(10) << thisMonth.insurance << setw(12) << difInsure << endl;
	cout << left << setw(22) << "Entertainment:"
		 << right << setw(8) << fixed << setprecision(2) << budget.entertainment
		 << setw(10) << thisMonth.entertainment << setw(12) << difEnt << endl;
	cout << left << setw(22) << "Clothing:"
		 << right << setw(8) << fixed << setprecision(2) << budget.clothing
		 << setw(10) << thisMonth.clothing << setw(12) << difCloth << endl;
	cout << left << setw(22) << "Miscellaneous:"
		 << right << setw(8) << fixed << setprecision(2) << budget.misc
		 << setw(10) << thisMonth.misc << setw(12) << difMisc << endl;
	cout << "----------------------------------------------------" << endl;
	cout << left << setw(22) << "Total:"
		 << right << setw(8) << fixed << setprecision(2) << totBudget
		 << setw(10) << totSpent << setw(12) << difTotal << endl << endl;



}