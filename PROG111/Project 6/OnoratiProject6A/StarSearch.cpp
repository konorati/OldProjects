// File: StarSearch.cpp
// This program displays a menu and calculates total price based on user selection
// Input: Judge's scores
// Output: Contestants score
// -------------------------------------------------------------------------------
// Class: Prog 111 Online Instructor: Robert Main
// Project: 6A Date assigned: 10/22/12
// Programmer: Kristin Onorati Date submitted: 10/24/12

#include <iostream>
#include <iomanip>

using namespace std;

//Prototypes for functions
void getJudgeData(double&);
double calcScore(double, double, double, double, double);
int findLowest(double);
int findHighest(double);

//The main function receives judges scores, calculates the contestant score, and reports it to the user
int main () {

	double score1 = 0, score2 = 0, score3 = 0, score4 = 0, score5 = 0, contestScore = 0;
	

	cout << "This program will calculate the contestants score\nfrom 5 judges individual scores\n" << endl;

	getJudgeData(score1);
	getJudgeData(score2);
	getJudgeData(score3);
	getJudgeData(score4);
	getJudgeData(score5);

	contestScore = calcScore(score1, score2, score3, score4, score5);

	cout << "The contestants score is " << setprecision(2) << contestScore << endl;
	system("pause");
}

//Gets judges scores from user and validates the score
void getJudgeData(double& score) {
	
	static int judgeNum = 1;
	cout << "Enter a score between 0 and 10 for judge " << judgeNum << ":  ";
	cin >> score;
		while (score < 0 || score > 10) {
			cout << "Entered score is not valid. Please enter\na score between 0 and 10:  ";
			cin >> score;
		}
	judgeNum++;
}
//Calculates the total score
double calcScore (double score1, double score2, double score3, double score4, double score5) {

	int lowJudge = 0;
	int highJudge = 0;

	findLowest(score1);
	findLowest(score2);
	findLowest(score3);
	findLowest(score4);
	lowJudge = findLowest(score5);

	findHighest(score1);
	findHighest(score2);
	findHighest(score3);
	findHighest(score4);
	highJudge = findHighest(score5);
	
	if (lowJudge == 1 || highJudge == 1){
		score1 = 0;
	}
	if (lowJudge == 2 || highJudge == 2){
		score2 = 0;
	}
	if (lowJudge == 3 || highJudge == 3){
		score3 = 0;
	}
	if (lowJudge == 4 || highJudge == 4){
		score4 = 0;
	}
	if (lowJudge == 5 || highJudge == 5){
		score5 = 0;
	}

	double contestScore = (score1 + score2 + score3 + score4 + score5) / 3;

	return contestScore;

}
//Finds the lowest score
int findLowest (double score) {
	static double lowest = 11;
	static int count = 1;
	static int lowJudge = 0;

	if (score < lowest) {
		lowest = score;
		lowJudge = count;
	}
	count++;
	return lowJudge;
}
//Finds the highest score
int findHighest (double score) {
	static double highest = -1;
	static int count = 1;
	static int highJudge = 0;
	
	if (score > highest) {
		highest = score;
		highJudge = count;
	}
	count++;
	return highJudge;
}

		


