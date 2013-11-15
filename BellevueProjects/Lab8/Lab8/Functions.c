#include "Functions.h"

int randomNumber(void){
	int num = 0;
	num = rand() % 100 + 1;
	return num;
}

void task1(void){
	FILE *infile = NULL;
	int num = 0, count = 0, list[100] = {0}, i = 0, temp = 0, j = 0;

	//Read ints from file and populate array
	infile = fopen("input.dat", "r");
	while (!feof(infile)){
		fscanf(infile, "%d", &num);
		list[count] = num;
		count++;
	}
	//Print array 
	printArray(list, count);
	printf("\n");

	//Reverse array
	for(i = 0, j = count-1; i < j; i++, j--){
		temp = list[i];
		list[i] = list[j];
		list[j] = temp;
	}
	//Print reversed array
	printArray(list, count);

}
void task2(int *list1, int size, int *list2){
	int i = 0;
	
	for(i = 0; i < size; i++){
		list1[i] = randomNumber();
		list2[list1[i]]++;
	}
	printArray(list1, size);
	printf("\n");

	for(i = 1; i < 101; i++){
		if (list2[i] != 0){
			printf("Number %d: Count %d\n", i, list2[i]);
		}

	}

}

void printArray(int *list, int size){
	int i = 0;
	for(i = 0; i < size; i++){
		printf("%d\n", list[i]);
	}

}

void sortArray(int *list, int size, int ascend){
	int i = 0, j = 0, temp = 0, numPasses = size-1; 
	if(ascend == 1){
		for(j = 0; j < size - 1; j++, numPasses--){
			for (i = 0; i < numPasses; i++){
				if(list[i] > list[i+1]){
					temp = list[i+1];
					list[i+1] = list[i];
					list[i] = temp;
				}
			}
		}
	}
	else{
		for(j = 0; j < size - 1; j++, numPasses--){
			for (i = 0; i < numPasses; i++){
				if(list[i] < list[i+1]){
					temp = list[i+1];
					list[i+1] = list[i];
					list[i] = temp;
				}
			}
		}
	}
}

void populateArray(int *list, int size){
	int i = 0;
	for(i = 0; i < size; i++){
		list[i] = randomNumber();
	}
}