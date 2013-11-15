// File: Car.cpp
// This program explains the car class and it's member functions
// Input: None
// Output: None
// -------------------------------------------------------------------------------
// Class: Prog 111 Online Instructor: Robert Main
// Project: 7B Date assigned: 11/02/12
// Programmer: Kristin Onorati Date submitted: 11/08/12
#include "Car.h"
#include <string>

using namespace std;

//Constructors
	Car::Car(int y, string m){
		year = y;
		make = m;
		speed = 0;
	}
	//Default constructor
	Car::Car(){
		year = 0;
		make = "Unknown";
		speed = 0;
	}
//Accessor functions
	int Car::getYear(){
		return year;
	}
	int Car::getSpeed(){
		return speed;
	}
	string Car::getMake(){
		return make;
	}

//Mutator functions
	void Car::accelerate(){
		speed +=5;
	}
	void Car::brake(){
		speed -=5;
	}

//Destructor function
	Car::~Car(){

	}