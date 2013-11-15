#include "Functions.h"


void reverseString(char* str, int start, int end)
{
	char tempLetter = '\0';
	if(start == end || start > end)
	{

	}
	else
	{
		tempLetter = *(str + start);
		*(str + start) = *(str + end);
		*(str + end) = tempLetter;
		reverseString(str, start+1, end-1);
	}
}

void mergeArrayFixedSize(char listOne[][20], int sizeListOne, char listTwo[][20], int sizeListTwo, char sortedList[][20])
{
	
	int i = 0, j = 0, lowestOne = 0, lowestTwo = 0, startOne = 0, startTwo = 0, found = 0, newListStart = 0;
	//Start at the beginning of new sorted array and place lowest string in starting position
	//increment starting position after every placement
	for(newListStart = 0; newListStart < (sizeListOne + sizeListTwo); newListStart++)
	{
		startOne = 0;
		startTwo = 0;
		found = 0;
		lowestOne = -1;
		lowestTwo = -1;
		do{
			if(listOne[startOne][0] == '~')
			{
				startOne++;
			}
			else
			{
				lowestOne = startOne;
				found = 1;
			}
			
		}while(!found && startOne < sizeListOne);
		found = 0;
		do{
			if(listTwo[startTwo][0] == '~')
			{
				startTwo++;
			}
			else
			{
				lowestTwo = startTwo;
				found = 1;
			}
		}while(!found && startTwo < sizeListTwo);
		if(lowestOne >= 0)
		{
			for(i = startOne+1; i < sizeListOne; i++)
			{
				if(strcmp(listOne[lowestOne], listOne[i]) > 0)
				{
				lowestOne = i;
				}
			}
		}
		if(lowestTwo >= 0)
		{
			for(j = startTwo+1; j < sizeListTwo; j++)
			{
				if(strcmp(listTwo[lowestTwo], listTwo[j]) > 0)
				{
					lowestTwo = j;
				}
			}
		}
		if(lowestOne >= 0 && lowestTwo >= 0)  
		{
			if(strcmp(listOne[lowestOne], listTwo[lowestTwo]) > 0)
			{
				strcpy(sortedList[newListStart], listTwo[lowestTwo]);
				strcpy(listTwo[lowestTwo], "~");
			}
			else
			{
				strcpy(sortedList[newListStart], listOne[lowestOne]);
				strcpy(listOne[lowestOne], "~");
			}
		}
		else if (lowestTwo < 0)
		{
			strcpy(sortedList[newListStart], listOne[lowestOne]);
			strcpy(listOne[lowestOne], "~");
		}
		else
		{
			strcpy(sortedList[newListStart], listTwo[lowestTwo]);
			strcpy(listTwo[lowestTwo], "~");
		}
	}
}
void mergeArrayDynamicSize(char listOne[][20], int sizeListOne, char listTwo[][20], int sizeListTwo, char sortedList[][20])
{
	
	int i = 0, j = 0, lowestOne = 0, lowestTwo = 0, startOne = 0, startTwo = 0, found = 0, newListStart = 0;
	//Start at the beginning of new sorted array and place lowest string in starting position
	//increment starting position after every placement
	for(newListStart = 0; newListStart < (sizeListOne + sizeListTwo); newListStart++)
	{
		startOne = 0;
		startTwo = 0;
		found = 0;
		lowestOne = -1;
		lowestTwo = -1;
		do{
			if(listOne[startOne][0] == '~')
			{
				startOne++;
			}
			else
			{
				lowestOne = startOne;
				found = 1;
			}
			
		}while(!found && startOne < sizeListOne);
		found = 0;
		do{
			if(listTwo[startTwo][0] == '~')
			{
				startTwo++;
			}
			else
			{
				lowestTwo = startTwo;
				found = 1;
			}
		}while(!found && startTwo < sizeListTwo);
		if(lowestOne >= 0)
		{
			for(i = startOne+1; i < sizeListOne; i++)
			{
				if(strcmp(listOne[lowestOne], listOne[i]) > 0)
				{
				lowestOne = i;
				}
			}
		}
		if(lowestTwo >= 0)
		{
			for(j = startTwo+1; j < sizeListTwo; j++)
			{
				if(strcmp(listTwo[lowestTwo], listTwo[j]) > 0)
				{
					lowestTwo = j;
				}
			}
		}
		if(lowestOne >= 0 && lowestTwo >= 0)  
		{
			if(strcmp(listOne[lowestOne], listTwo[lowestTwo]) > 0)
			{
				strcpy(sortedList[newListStart], listTwo[lowestTwo]);
				strcpy(listTwo[lowestTwo], "~");
			}
			else
			{
				strcpy(sortedList[newListStart], listOne[lowestOne]);
				strcpy(listOne[lowestOne], "~");
			}
		}
		else if (lowestTwo < 0)
		{
			strcpy(sortedList[newListStart], listOne[lowestOne]);
			strcpy(listOne[lowestOne], "~");
		}
		else
		{
			strcpy(sortedList[newListStart], listTwo[lowestTwo]);
			strcpy(listTwo[lowestTwo], "~");
		}
	}
}