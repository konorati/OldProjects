// File: payrate.cpp
// calculates amount due, given pay rate and hrs worked
//
// Input: pay rate and # of hrs worked
// Output: pay
// -------------------------------------------------------------------------------
// Class: Prog 111				Online Instructor: Robert Main
// Project: 1					Date assigned: 9/21/09
// Programmer: Kristin Onorati  Date submitted: 9/19/12
#include <iostream>
using namespace std;
int main ()
{
float hrs, payrate;
float amount=0.0;
//get the hrs worked and pay rate
cout << "Enter the Number of Hours worked: ";
cin >> hrs;
cout << "Enter the Pay Rate: $ ";
cin >> payrate;
//compute the amount due
amount = hrs * payrate;
cout << "The Amount due is $ " << amount << endl;
system ("pause");
return 0;
}