// File: MathTutor.cpp
// This program provides a random addition problem then gives feedback to the user about their answer
// Input: answer
// Output: math problem, feedback to response
// -------------------------------------------------------------------------------
// Class: Prog 111 Online Instructor: Robert Main
// Project: 4A Date assigned: 10/01/12
// Programmer: Kristin Onorati Date submitted: 10/02/12

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//This program creates a random addition problem then gets input from user for the answer. Then provides feedback about users answer.
int main() {
	int seed = time(0);
	srand(seed);
	int num1 = 10 + rand() % 41; //Creates first random number between 10 and 50
	int num2 = 10 + rand() % 41; //Creates second random number between 10 and 50
	int answer; //The users response
	int correctAnswer; //The correct answer

	cout << setw(4) << num1 << endl; //Creates the addition equation
	cout << "+" << setw(3) << num2 << endl;
	cout << "____" << endl;
	cout << "  ";
	cin >> answer; //User inputs answer
	cout << endl;

	correctAnswer = num1 + num2; //Calculates the correct answer

	if (answer == correctAnswer) { //Determines if user gave correct answer
		cout << "Congratulations! " << answer << " is correct!" << endl;
		cout << endl;
	}
	else {
		cout << answer << " is incorrect" << endl; //Used if answer given is incorrect
		cout << "The correct answer is " << correctAnswer << endl;
		cout << endl;
	}
	system("pause");
	return 0;
}