#include "functions.h"

int main (){
	double x1 = 0, x2 = 0, y1 = 0, y2 = 0, slope = 0, xMid = 0, yMid = 0, perpSlope = 0, 
		yIntercept = 0, heightFeet = 0, heightInches = 0, weight = 0, BMI = 0, rawHarrisPoll = 0,
		rawCoachesPoll = 0, computerRank = 0, bcsScore = 0, harrisWeight = 2850, coachesWeight = 1475,
		harrisPoll = 0, coachesPoll = 0, gp1 = 0, gp2 = 0, gp3 = 0;
	int credits1 = 0, credits2 = 0, credits3 = 0;

	FILE *inputHandle = NULL, *output_handle = NULL;


	inputHandle = openFile();

	output_handle = fopen("gpa.txt", "w");
	

	credits1 = readCredits(inputHandle);
	gp1 = readGradePoint(inputHandle);
	credits2 = readCredits(inputHandle);
	gp2 = readGradePoint(inputHandle);
	credits3 = readCredits(inputHandle);
	gp3 = readGradePoint(inputHandle);
	fprintf(output_handle, "%d", credits1);
	printf("credits1: %d, gp1: %f\n", credits1, gp1);
	printf("credits2: %d, gp2: %f\n", credits2, gp2);
	printf("credits3: %d, gp3: %f\n", credits3, gp3);
	//fprintf(output_handle, "%d", &credits1);
	/*//Line Problem
	x1 = getDataPoint('x', 1);
	y1 = getDataPoint('y', 1);
	x2 = getDataPoint('x', 2);
	y2 = getDataPoint('y', 2);

	slope = computeSlope(x1, x2, y1, y2);

	xMid = computeMidpoint(x1, x2);
	yMid = computeMidpoint(y1, y2);

	perpSlope = computeSlopeOfBisector(slope);

	yIntercept = computeYInterceptOfBisector(perpSlope, yMid, xMid);

	outputResults(x1, x2, y1, y2, perpSlope, yIntercept);

	//BMI problem
	heightFeet = getHeight();
	heightInches = convertFeetToInches(heightFeet);
	weight = getWeight();
	BMI = computeBodyMassIndex(heightInches, weight);
	displayBMI(BMI);

	//BCS Score problem
	rawHarrisPoll = getHarrisPoll();
	harrisPoll = computePoll(rawHarrisPoll, harrisWeight);
	rawCoachesPoll = getCoachesPoll();
	coachesPoll = computePoll(rawCoachesPoll, coachesWeight);
	computerRank = getComputerRanking();
	bcsScore = computeBcsScore(harrisPoll, coachesPoll, computerRank);
	displayIntermediateResult(harrisPoll, coachesPoll, computerRank);
	displayBcsScore(bcsScore);*/
	

	return 0;
}