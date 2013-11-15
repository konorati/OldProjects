// File: Project7B.cpp
// This program uses the car class to create a car object and
// access and use it's member functions
// Input: None
// Output: Car speed
// -------------------------------------------------------------------------------
// Class: Prog 111 Online Instructor: Robert Main
// Project: 7B Date assigned: 11/02/12
// Programmer: Kristin Onorati Date submitted: 11/08/12

#include <iostream>
#include <string>
#include "Car.h"

using namespace std;

//Creates a car object and uses the brake and accelerate member functions
//to increase and decrease car speed
int main(){
	
	Car car1(1998, "Honda");

	car1.accelerate();
	cout << "Speed: " << car1.getSpeed() << endl;
	car1.accelerate();
	cout << "Speed: " << car1.getSpeed() << endl;
	car1.accelerate();
	cout << "Speed: " << car1.getSpeed() << endl;
	car1.accelerate();
	cout << "Speed: " << car1.getSpeed() << endl;
	car1.accelerate();
	cout << "Speed: " << car1.getSpeed() << endl;
	car1.brake();
	cout << "Speed: " << car1.getSpeed() << endl;
	car1.brake();
	cout << "Speed: " << car1.getSpeed() << endl;
	car1.brake();
	cout << "Speed: " << car1.getSpeed() << endl;
	car1.brake();
	cout << "Speed: " << car1.getSpeed() << endl;
	car1.brake();
	cout << "Speed: " << car1.getSpeed() << endl;

	system("pause");

}