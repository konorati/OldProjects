// File: OnoratiProject8.cpp
// This program uses the RestaurantCheck class to create a restaurantCheck object and
// access and use it's member functions
// Input: None
// Output: 
// -------------------------------------------------------------------------------
// Class: Prog 111 Online Instructor: Robert Main
// Project: 8 Date assigned: 11/12/12
// Programmer: Kristin Onorati Date submitted: 11/08/12

#include <iostream>
#include <string>
#include "RestaurantCheck.h"

using namespace std;

//Creates a restaurantCheck object and uses its member functions
//to create and display a bill
int main(){
	
	RestaurantCheck check1;
	check1.placeOrder(check1);
	check1.issueCheck(check1);


	system("pause");
	return 0;

}