// File: Population.cpp
// This program calculates and displays expected population over a number of years
// Input: Current popoulation, birth rate, death rate, and number of years
// Output: Projected population
// -------------------------------------------------------------------------------
// Class: Prog 111 Online Instructor: Robert Main
// Project: 6B Date assigned: 10/22/12
// Programmer: Kristin Onorati Date submitted: 10/24/12

#include <iostream>

using namespace std;

//Prototypes for functions
int projectedPopulation(int, double, double);
int getPop();
int getYears();
double getBirth();
double getDeath();

//The main function gives an introduction then calls the necessary functions to get
//the user input for current population, birth rate, death rate, and number of years.
//Then calls a function to calculate the projected population over the years and 
//displays this to the user.
int main () {

	int currentPop, years, popProjected;
	double deathRate, birthRate;
	
	cout << "This program will display the projected population based on" << endl;
	cout << "the current population, the death rate, and the birthrate.\n" << endl;
	
	//Retrieves necessary information from user
	currentPop = getPop();
	birthRate = getBirth();
	deathRate = getDeath();
	years = getYears();


	cout << endl << endl << "With a starting population of " << currentPop << endl;

	for (int year = 1; year <= years; year++){ //Prints out projected population for each year
		popProjected = projectedPopulation(currentPop, deathRate, birthRate);
		cout << "The projected population for year "<< year << " is " << popProjected << endl;
		currentPop = popProjected;
	}
	system("pause");
	return 0;

}
//Retrieves and validates current population
int getPop(){
	int currentPop;
	cout << "Enter the current population: ";
	cin >> currentPop;
	while (currentPop < 2) { //Validates user input
		cout << "Population size is not valid\nEnter a population size greater than 1: ";
		cin >> currentPop;
	}
	return currentPop;
}
//Retrieves and validates number of years to project over
int getYears(){
	int years;
	cout << "Over how many years would you like to project the population? ";
	cin >> years;
	while (years < 1) { //Validates user input
		cout << "Number of years is not valid\nEnter a number of years greater than 0: ";
		cin >> years;
	}
	return years;
}
//Retrieves and validates birth rate
double getBirth(){
	double birthRate;
	cout << "Enter the birth rate: ";
	cin >> birthRate;
	while (birthRate < 0) { //Validates user input
		cout << "Birth rate must be positive\nEnter the birth rate: ";
		cin >> birthRate;
	}
	return birthRate;
}
//Retrieves and validates death rate
double getDeath(){
	double deathRate;
	cout << "Enter the death rate: ";
	cin >> deathRate;
	while (deathRate < 0) { //Validates user input
		cout << "Death rate must be positive\nEnter the death rate: ";
		cin >> deathRate;
	}
	return deathRate;
}
//Calculates the projected population after 1 year
int projectedPopulation (int popStart, double deathRate, double birthRate){
	
		int popProjected = popStart * (1 + birthRate) * (1 - deathRate);
		return popProjected;
}