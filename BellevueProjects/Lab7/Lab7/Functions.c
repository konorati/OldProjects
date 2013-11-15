#include "Functions.h"

void test(int *x){
	*x = 6;
}



void revenue(double *rev, int years){
	*rev = 203.265 * pow(1.071, years);
}
void predict(double rev, int *years){
	int tempYears = -1;
	double tempRev = 0;
	while (rev > tempRev){
		tempYears++;
		revenue(&tempRev, tempYears);
	}
	
	*years =  tempYears + 1984;
}

void charges(double hours, double *totCharges, double *aveCharges){
	*totCharges = 7.99;
	if(hours > 10){
		if((int)(hours*10)%10 != 0){
			*totCharges += ((int)(hours-10) + 1)*1.99;
		}
		else{
			*totCharges += ((int)(hours-10))*1.99;
		}
	}
	*aveCharges = (*totCharges/hours);
}

double roundMoney(double number){
	double roundedNum = ((int)(number * 1000));
	if((int)roundedNum%10 >= 5){
		roundedNum += ((int)roundedNum%10 + 10)/1000.0;
	}
	else{
		roundedNum = roundedNum/1000.0;
	}
	return roundedNum;
}

int binarySearch(int *arr, int size, int value){
	int i = 0, low = 0, high = size - 1, found = -1, index = -1, mid = 0;
	while (found != 1 && low <= high){
		mid = (low + high)/2;
		if(value < arr[mid]){
			high = mid - 1;
		}
		else if(value > arr[mid]){
			low = mid + 1;
		}
		else if (value == arr[mid]){
			found == 1;
			index = arr[mid];
		}

	}

void bubbleSort(int *list, int size){
	int index = 0, temp = 0, i = 0, numPasses = (size - 1);
	for(i = 0; i < size - 1; i++){
		for (index = 0; index < numPasses; index++){
			if(list[index] > list[index+1]){
				temp = list[index];
				list[index] = list[index+1];
				list[index+1] = temp;
			}
			numPasses--;
		}
	}
}

void selectionSortStrings(char[][100] list, int length){
	char[100] temp;
	int i = 0, smallest = 0;
	for(i = 0; i < length-1; i++){
		smallest = findSmallest(list, i, length);
		strcpy(temp, list[i]);
		strcpy(list[i], list[smallestIndex]);
		strcpy(list[smallestIndex], temp);
	}


}

int findSmallest(char[][100] values, int low, int length){
	int smallestIndex = low, i = 0;
	for(i = low + 1; i < length; i++){
		if(strcmp(values[i], values[smallestIndex]) < 0){
			smallestIndex = i;
		}
	}
	return smallestIndex;
}
	

