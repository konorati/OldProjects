// File: DistancePerTank.cpp
// calculates the distance a car can get on one tank of gas when driving in town and on the highway
//
// Input: none
// Output: distance
// -------------------------------------------------------------------------------
// Class: Prog 111 Online Instructor: Robert Main
// Project: 2A Date assigned: 9/24/12
// Programmer: Kristin Onorati Date submitted: 10/01/12

#include <iostream>

using namespace std;

//Calculates distance per tank and sends output to console
int main()
{
	//Define each variable and assign number of gallons and miles travelled
    double gallons = 20;
	double mpgTown = 21.5;
	double mpgHighway = 26.8;
	double totalMilesTown;
	double totalMilesHighway;

	totalMilesTown = gallons * mpgTown; //Calculates miles per tank when driving in town

	totalMilesHighway = gallons * mpgHighway; //Calculates miles per tank when driving on the highway

	cout << "A car that holds " << gallons << " gallons of gas\n";
	cout << "and gets " << mpgTown << " miles per gallon while driving in town\n";
	cout << "can drive " << totalMilesTown << " miles on one tank of gas.\n";
	cout << endl;
	cout << "A car that holds " << gallons << " gallons of gas\n";
	cout << "and gets " << mpgHighway << " miles per gallon while driving on the highway\n";
	cout << "can drive " << totalMilesHighway << " miles on one tank of gas.\n";
	system("pause");

    return 0;
}