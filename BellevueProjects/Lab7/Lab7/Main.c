#include "Functions.h"

int main (void){
	
	
	double totCharges = 0, averageCharge = 0, hours = 0, rev = 0;
	FILE *inputFile = NULL, *outputFile = NULL;
	int i = 0, year = 0;

	student_t kristin;
	kristin.age = 27;
	strcpy(kristin.firstName, "Kristin");
	strcpy(kristin.lastName, "Onorati");
	kristin.idNum = 10874126;

	//inputFile = fopen("input.dat", "r");
	outputFile = fopen("output.dat", "w");
	predict(1000, &year);
	for(i = 0; i <= (year - 1984); i++){
		revenue(&rev, i);
		fprintf(outputFile, "%d  %.2lf\n", i + 1984, rev);
	};

	/*predict(200, &year);
	printf("Years for $200 revenue = %d\n", year);
	predict(1000000000, &year);
	printf("Years for 1 trillion dollars in revenue = %d\n", year);
	*/

	/*for(i = 0; i <= 3; i++){
		fscanf(inputFile, "%lf", &hours);
	}

	charges(hours, &totCharges, &averageCharge);
	printf("Hours are %.2f, charges are: %.2f, average charges are: %.2f\n", hours, totCharges, roundMoney(totCharges), averageCharge);

	fprintf(outputFile, "%s%.2f\n", "Hours Used: ", hours);
	fprintf(outputFile, "%s%.2f\n", "Total Charges: ", totCharges);
	fprintf(outputFile, "%s%.2f\n", "Average Charges: ", averageCharge);
	*/
	return 0;
	
}
