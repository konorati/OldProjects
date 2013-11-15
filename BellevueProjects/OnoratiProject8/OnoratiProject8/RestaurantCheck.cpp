// File: RestaurantCheck.cpp
// This program explains the restaurant check class and it's member functions
// Input: Item selections
// Output: Subtotal, total tax, total.
// -------------------------------------------------------------------------------
// Class: Prog 111 Online Instructor: Robert Main
// Project: 8 Date assigned: 11/17/12
// Programmer: Kristin Onorati Date submitted: 11/08/12
#include "RestaurantCheck.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

	//Initialize constants
	const double RestaurantCheck::DEFAULT_TAX = .065;
	const double RestaurantCheck::DEFAULT_TIP = .15;
	const double RestaurantCheck::LOW_TAX = 1;
	const double RestaurantCheck::HIGH_TAX = 12;
	const double RestaurantCheck::LOW_TIP = 5;
	const double RestaurantCheck::HIGH_TIP = 20;

	//Initialize arrays
	const string RestaurantCheck::itemDescription[NUM_ITEMS] = {"Cheese Pizza", "Pepperoni Pizza", "Hawaiian Pizza", 
		"Calzone", "Spaghetti", "Fettucini Alfredo", "Dinner Salad", "Side Salad", "Breadsticks", "Soda"};

	const double RestaurantCheck::itemCost[NUM_ITEMS] = {8.99, 9.99, 10.49, 11.49, 11.99, 12.49, 8.49, 4.99, 3.99, 1.49};
	
	//Constructors
	RestaurantCheck::RestaurantCheck(double taxPcnt, double tipPcnt){
		if (taxPcnt < LOW_TAX || taxPcnt > HIGH_TAX)
			taxRate = DEFAULT_TAX;
		else
			taxRate = taxPcnt/100;
		if (tipPcnt < LOW_TIP || tipPcnt > HIGH_TIP)
			tip = DEFAULT_TIP;
		else
			tip = tipPcnt/100;
	}
	//Default constructor
	RestaurantCheck::RestaurantCheck(){
		taxRate = DEFAULT_TAX;
		tip = DEFAULT_TIP;
	}
//Private functions
	//Displays the menu items and prices
	void RestaurantCheck::presentMenu(){
		cout << "\n*** Sella's Pizza, Pasta, & Calzones ***\n" << endl;
		for(int item = 0; item < NUM_ITEMS; item++){
			cout << right << setw(2) << item + 1 << ": " << left << setw(25) << itemDescription[item];
			cout << " $" << setw(6) << right << itemCost[item] << endl;
		}
	}
	//Calculates the total tax from the subtotal
	double RestaurantCheck::calculateTax(double subtotal){
		totalTax = taxRate * subtotal;
		return totalTax;
	}
	//Calculates the total tip from the subtotal
	double RestaurantCheck::calculateTip(double subtotal){
		totalTip = tip * subtotal;
		return totalTip;
	}
	

//Public functions
	//Retrieves user menu choices and sets them to an array
	void RestaurantCheck::placeOrder(RestaurantCheck& Check){
		cout << "Thank you for choosing Sella's!" << endl;
		cout << "Please choose from the following menu:" << endl;
		presentMenu();
		int item;
		int count = 0;
		cout << "\nEnter your item selection or enter -1 if you are finished ordering." << endl;
		do {
			cout << "Selection " << count + 1 << ": ";
			cin >> item;
			if (item != -1){
				selectedItems[count] = item - 1;
				count++;
			}
		} while (item != -1 && count != 5);
		
		numItemsOrdered = count;
		
	}
	//Calculates and displays the customers check
	void RestaurantCheck::issueCheck(RestaurantCheck Check){
		system("CLS"); //Clear screen
		if (numItemsOrdered == 0){
			cout << "\nYour order has been canceled." << endl;
		}
		else {
			cout << "\n    *** Order Summary ***\n" << endl;
		
			//Calculate subtotal & display items ordered
			subtotal = 0;
			for (int item = 0; item < numItemsOrdered; item++){
				for(int menuItem = 0; menuItem < NUM_ITEMS; menuItem++){
					if (selectedItems[item] == menuItem){
						subtotal += itemCost[menuItem];
						cout << left << setw(22) << itemDescription[menuItem];
						cout << "$" << right << setw(6) << itemCost[menuItem] << endl;
					}
				}
			}
		
			//Calculate total tip
			totalTip = calculateTip(subtotal);

			//Calculate total tax
			totalTax = calculateTax(subtotal);

			//Calculate bill total
			billTotal = subtotal + totalTip + totalTax;

			//Display tip, tax, and total
			cout << "-----------------------------" << endl;
			cout << left << setw(22) << "Subtotal: " << "$"; 
			cout << right << fixed << setprecision(2) << setw(6) << subtotal << endl;
			cout << left << setw(22) << "Tip: " << "$"; 
			cout << right << fixed << setprecision(2) << setw(6) << totalTip << endl;
			cout << left << setw(22) << "Tax: " << "$";
			cout << right << fixed << setprecision(2) << setw (6) << totalTax << endl;
			cout << left << setw(22) << "Total: " << "$";
			cout << right << fixed << setprecision(2) << setw(6) << billTotal << endl;
		}
	}

//Destructor function
	RestaurantCheck::~RestaurantCheck(){

	}