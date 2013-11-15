// File: MilesPerGallon.cpp
// calculates gross pay per pay period if paid bi-monthly and if paid every two weeks based on gross annual salary
//
// Input: none
// Output: twoWeekPay, biWeekPay
// -------------------------------------------------------------------------------
// Class: Prog 111 Online Instructor: Robert Main
// Project: 2B Date assigned: 9/24/12
// Programmer: Kristin Onorati Date submitted: 09/26/12

#include <iostream>

using namespace std;

//Calculates gross pay per paycheck for bi-monthly and every two week pay cycles and sends output to console
int main()
{
	int number = 1;

int odd = 1;

while (number <= 10) {

      cout << odd << " ";

      odd += 2;

      number++;

}
system("pause");

    return 0;
}