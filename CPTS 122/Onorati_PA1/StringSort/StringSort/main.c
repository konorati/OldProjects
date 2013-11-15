/*************************************************************************************
* Programmer: Kristin Onorati
* Class: CPTS 122, Summer 2013
* Programming Assignment: 1
* Date: June 9th, 2013
* Description: Gets a string from the user and applies a Caesar shift cipher based on a 
*		shift determined by the user.
**************************************************************************************/

#include "StringSort.h"

int main(void)
{
	char** list;
	int i = 0, direction = 0, size = 0;
	char tempStr[20];

	//Set list
	size = getSizeOfList();
	list = (char**)malloc(sizeof(char*)*size);
	for(i = 0; i < size; i++)
	{
		*(list+i) = getListItem();
	}

	printf("How would you like to sort the list?\n\t1. Descending\n\t2. Ascending\n");
	scanf("%d", &direction);
	printf("\nUNSORTED LIST\n");
	printList(list, size);
	stringSort(list, size, direction - 1);
	printf("\nSORTED LIST\n");
	printList(list, size);

	return 0;
}