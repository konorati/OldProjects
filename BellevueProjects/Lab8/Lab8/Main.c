#include "Functions.h"


int main(){
	int num = 0, i = 0, j = 0, size = 20;
	int randomNums[20] = {0}, count[101] = {0};
	int nums[20] = {0};
	srand((unsigned int) time(NULL));

	// TASK 1
	//task1();


	//TASK 2
	//task2(randomNums, 20, count);
	



	//TASK 3
	populateArray(nums, size);
	printArray(nums, size);
	sortArray(nums, size, 1);
	printf("\n");
	printArray(nums, size);
	printf("\n");
	sortArray(nums, size, 0);
	printArray(nums, size);



	return 0;
}