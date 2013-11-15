#include "StringSort.h"

/*************************************************************************
* Date last modified: June 9th, 2013
* Description: Sorts a list of strings by sorting an array of pointers to said strings,
*   using bubble sort
* Input parameters: Pointer to an array of character pointers, size of array (integer),
*   direction to sort list (0 = descending, 1 = ascending);
* Returns: 
* Precondition: Array contains pointers which point to valid  strings, size
*   corresponds to actual size of array, direction is 0 or 1;
* Postcondition: Array of pointers is updated to be in specified order
*************************************************************************/
void stringSort(char** pList, int size, int direction)
{
	int start = 0, i = 0, j = 0, end = size-1, lowest = 0;
	char *pTemp = NULL;
	for(start = 0; start < size - 1; start++, end--)
	{
		lowest = 0;
		for(i = 1; i <= end; i++)
		{
			if(DESCENDING == direction) //If descending order
			{
				if(strcmp(*(pList+lowest), *(pList+i)) > 0){
				lowest = i;
				}
			}
			else //If ascending order
			{
				if(strcmp(*(pList+lowest), *(pList+i)) < 0){
				lowest = i;
				}
			}
		}
		pTemp = *(pList+lowest);
		*(pList+lowest) = *(pList+end);
		*(pList+end) = pTemp;
	}
}

/*************************************************************************
* Date last modified: June 9th, 2013
* Description: Prints list of strings
* Input parameters: Pointer to array of character pointers, integer size of array
* Returns: 
* Precondition: Size corresponds to actual size of array, pointers in array 
*   point to valid strings
* Postcondition: List of strings is printed
*************************************************************************/
void printList(char** pList, int size)
{
	int i = 0;
	for(i = 0; i < size; i++)
	{
		puts(*(pList+i));
	}
}

/*************************************************************************
* Date last modified: June 9th, 2013
* Description: Gets size of list from user
* Input parameters: 
* Returns: size of list (integer)
* Precondition:  
* Postcondition: Positive integer is returned
*************************************************************************/
int getSizeOfList(void)
{
	int size = 0;

	do
	{
		_flushall();
		printf("How many items are in your list? ");
		scanf("%d", &size);
		if(size <=0)
		{
			printf("Invalid size. Enter an integer greater than 0.\n");
		}
	}while(size <= 0);

	return size;
}

/*************************************************************************
* Date last modified: June 9th, 2013
* Description: Gets string from user
* Input parameters: 
* Returns: Character pointer to string (memory allocated dynamically)
* Precondition:  
* Postcondition: Pointer to valid string is returned
*************************************************************************/
char* getListItem(void)
{
	char* pItem = NULL;
	char item[100];

	_flushall();
	puts("Enter a word for the list: ");
	gets(item);

	pItem = (char*)malloc(sizeof(char)*(strlen(item)+1)); //Allocate dynamic memory for string
	strcpy(pItem, item);
	
	return pItem;
}