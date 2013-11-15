#include "Functions.h"

int main(){
	char allStar = '\0', regularMVP = '\0', worldMVP = '\0', goldGlove = '\0', silverSlug = '\0',
		homeRun = '\0', battingAve = '\0', gender = '\0';
	int bonus = 0, num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, 
		 activityLevel = 0, menuChoice = 0, i = 0;
	double weight = 0, height = 0, age = 0, bmr = 0, calories = 0, result = 0;
	FILE *inputFile = NULL;

	
	//PROBLEM 1
	inputFile = openInputFile();
	/*
	gender = readCharacter(inputFile);
	age = readNumber(inputFile);
	weight = readNumber(inputFile);
	height = readNumber(inputFile);

	bmr = computeBMR(gender, weight, height, age);
	activityLevel = determineActivityLevel();
	calories = computeCalories(bmr, activityLevel);
	printf("Calories needed per day are: %.0lf\n", calories);

	//PROBLEM 2
	allStar = getBaseballAchievements("All-Star Game appearance");
	bonus += determineBonus(allStar, 25000);
	regularMVP = getBaseballAchievements("Regular Season MVP");
	bonus += determineBonus(regularMVP, 75000);
	worldMVP = getBaseballAchievements("World Series MVP");
	bonus += determineBonus(worldMVP, 100000);
	goldGlove = getBaseballAchievements("Gold Glove award");
	bonus += determineBonus(goldGlove, 50000);
	silverSlug = getBaseballAchievements("Silver Slugger award");
	bonus += determineBonus(silverSlug, 35000);
	homeRun = getBaseballAchievements("Home run champ");
	bonus += determineBonus(homeRun, 25000);
	battingAve = getBaseballAchievements("Batting average champ");
	bonus += determineBonus(battingAve, 25000);

	printf("Total player bonus is %d\n", bonus);
		int i = 0;*/
	//PROBLEM 3
	num1 = readInteger(inputFile);
	num2 = readInteger(inputFile);
	num3 = readInteger(inputFile);
	num4 = readInteger(inputFile);
	num5 = readInteger(inputFile);

	
	while (i < 3){
		menuChoice = displayMenu();
		result = calculateResult(menuChoice, num1, num2, num3, num4, num5);
		displayResult(menuChoice, result);
		i++;
	}
	
	return 0;
}