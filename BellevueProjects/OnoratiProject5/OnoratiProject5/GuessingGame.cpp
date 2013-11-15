// File: GuessingGame.cpp
// This program provides a random addition problem then gives feedback to the user about their answer
// Input: guess
// Output: feedback to response
// -------------------------------------------------------------------------------
// Class: Prog 111 Online Instructor: Robert Main
// Project: 4A Date assigned: 10/10/12
// Programmer: Kristin Onorati Date submitted: 10/16/12

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//This program creates a random number and has the user guess the number. Program gives feedback to user until user gets the correct answer.
int main() {
	int seed = time(0);
	srand(seed);
	int number = 1 + rand() % 100; //Creates a random number between 1 and 100
	int guess;

	//Tells user about the program and asks them to guess what the random number is
	cout << "This program will generate a random whole number between 1 and 100" << endl;
	cout << "Guess what that number is (enter an integer between 1 and 100):  ";
	cin >> guess;

	//Gives feedback to the user until they correctly guess the random number
	while (guess != number) {
		if (guess > number) {
			cout << "Too high. Try again.  ";
		}
		else {
			cout << "Too low. Try again.  ";
		}
		cin >> guess;
	}

	//Congratulates the user on guessing the correct number
	cout << "Congratulations. You figured out my number!" << endl;
	system("pause");
}