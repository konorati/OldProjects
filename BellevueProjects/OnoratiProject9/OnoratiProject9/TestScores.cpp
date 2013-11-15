//Kristin Onorati
//Programming 111
//Project 9
//File: TestScores.cpp
//Input: number of test scores, test scores
//Output: Test scores, score average
//Date: 11/4/2012

#include <iostream>
#include <iomanip>
using namespace std;

void sortArray(int *, int *);

double average(int *, int *);

int main() {

	int size;
	double testAverage;
	
	//Get number of test scores from user
	cout << "Enter the total number of test scores: ";
	cin >> size;
	
	//Allocate memory for array using pointer
	int *scorePtr;
	scorePtr = new int[size];

	//Get test scores from user and put into array
	for (int i = 0; i < size; i++) {
		do {
			cout << "Enter test score #" << i + 1 << ": ";
			cin >> *(scorePtr + i);
			if (*(scorePtr + i) < 0)
				cout << "Score must be a positive number" << endl;
		}while (*(scorePtr + i) < 0);
	}
	system("cls");

	//Calculate average
	testAverage = average(scorePtr, &size);
	//Sort array
	sortArray(scorePtr, &size);

	//Display sorted array and average
	cout << "  Test Scores" << endl;
	cout << "---------------" << endl;
	for (int i = 0; i < size; i++){
		cout << "#" << right << setw(2) << i + 1 << ":";
		cout << setw(9) << *(scorePtr + i) << endl;
	}
	cout << "---------------" << endl;
	cout << "Average:" << setw(7) << fixed << setprecision(2) << testAverage << endl;
	cout << endl;

	system("pause");
	return 0;
}
//Sort array in ascending order
void sortArray(int *scores, int *size){
	int start, minIndex, minValue;
	for (start = 0; start < (*size - 1); start++){
		minIndex = start;
		minValue = *(scores + start);
		for (int index = start + 1; index < *size; index++){
			if (*(scores + index) < minValue){
				minValue = *(scores + index);
				minIndex = index;
			}
		}
		*(scores + minIndex) = *(scores + start);
		*(scores + start) = minValue;
	}
}
//Finds the average of the scores in the array
double average(int *scores, int *size){
	int sum = 0;

	for (int i = 0; i < *size; i++){
		sum += *(scores + i);
	}
	return (double)sum / *size;
}