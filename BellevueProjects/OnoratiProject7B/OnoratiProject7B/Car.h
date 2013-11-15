// File: Car.h
// This file holds function prototypes for the car class
// Input: None
// Output: None
// -------------------------------------------------------------------------------
// Class: Prog 111 Online Instructor: Robert Main
// Project: 7B Date assigned: 11/02/12
// Programmer: Kristin Onorati Date submitted: 11/08/12

#ifndef CAR_H
#define CAR_H
#include <string>

using namespace std;

//Function prototypes for car class
class Car
{
private:
	int year, speed;
	string make;
public:
	Car(int, string);
	Car();
	int getYear();
	int getSpeed();
	string getMake();
	void accelerate();
	void brake();
	~Car();
};
#endif