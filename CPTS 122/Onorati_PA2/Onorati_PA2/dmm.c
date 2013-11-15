#include "DMM.h"

/*************************************************************************
* Date last modified: June 16th, 2013
* Description: Reads strings from a file
* Input parameters: File pointer
* Returns: pointer to string (dynamically allocated memory)
* Precondition: File must already be open, string must be next
* Postcondition: String pointer is returned
*************************************************************************/
char* readStr(FILE *infile)
{
	char *pStr = NULL;
	char str[100];

	fgets(str, 100, infile);
	str[strlen(str)-1] = '\0';
	
	pStr = (char*)malloc(sizeof(char)*(strlen(str)+1));
	strcpy(pStr, str);
	
	return pStr;
}

/*************************************************************************
* Date last modified: June 16th, 2013
* Description: Inputs music node from file
* Input parameters: File pointer
* Returns: pointer to node (dynamically allocated memory)
* Precondition: File must already be open, memory must be available
* Postcondition: Node pointer is returned
*************************************************************************/
Node* readItem(FILE *infile)
{
	Node *pNewItem = NULL;
	char tempChar;
	
	pNewItem = (Node*)malloc(sizeof(Node));

	pNewItem->pArtist = readStr(infile);
	pNewItem->pSongTitle = readStr(infile);
	pNewItem->pAlbumTitle = readStr(infile);
	pNewItem->pGenre = readStr(infile);
	fscanf(infile, "%lf", &(pNewItem->songLength));
	fscanf(infile, "%d", &(pNewItem->numTimesPlayed));
	fscanf(infile, "%d", &(pNewItem->rating));
	fscanf(infile, "%c", &tempChar);
	pNewItem->pPrevious = NULL;
	pNewItem->pNext = NULL;

	return pNewItem;
	
}

/*************************************************************************
* Date last modified: June 16th, 2013
* Description: Prints individual node to console
* Input parameters: Node pointer
* Returns: 
* Precondition: Node must exist
* Postcondition: Node contents are printed to console
*************************************************************************/
void printNode(Node *pItem)
{
	printf("\nArtist: ");
	puts(pItem->pArtist);
	printf("Song Title: ");
	puts(pItem->pSongTitle);
	printf("Album Title: ");
	puts(pItem->pAlbumTitle);
	printf("Genre: ");
	puts(pItem->pGenre);
	printf("Song Length: %.2lf\n", pItem->songLength);
	printf("Number of Plays: %d\n", pItem->numTimesPlayed);
	printf("Rating: %d\n", pItem->rating);

}

/*************************************************************************
* Date last modified: June 16th, 2013
* Description: Initializes list, sets start and end to null;
* Input parameters: 
* Returns: pointer to list struct
* Precondition: Memory must be available
* Postcondition: Memory for list struct is allocated & pointer is returned
*************************************************************************/
List* initList(void)
{
	List *pList = (List*)malloc(sizeof(List));
	pList->pStart = NULL;
	pList->pEnd = NULL;
	return pList;
}

/*************************************************************************
* Date last modified: June 16th, 2013
* Description: Checks if list is empty
* Input parameters: List pointer
* Returns: True is list is empty, false if list is not empty
* Precondition: List pointer must exist
* Postcondition: True or False is returned
*************************************************************************/
Boolean isEmpty(List *pList)
{
	Boolean empty = FALSE;
	if(NULL == pList->pStart)
	{
		empty = TRUE;
	}
	return empty;
}

/*************************************************************************
* Date last modified: June 16th, 2013
* Description: Prints entire list to console
* Input parameters: List pointer
* Returns: 
* Precondition: List pointer must exist
* Postcondition: List is printed to console
*************************************************************************/
void printList(List *pList)
{
	Node* conductor = pList->pStart;
	while(NULL != conductor)
	{
		printNode(conductor);
		conductor = conductor->pNext;
	}

}

/*************************************************************************
* Date last modified: June 16th, 2013
* Description: Adds node to list in user determined order
* Input parameters: List pointer, node pointer, user determined sorting type
* Returns: 
* Precondition: List must exist, node must exist
* Postcondition: Item is added to list in correct order
*************************************************************************/
void addItemToList(List **pList, Node **item, int sortType)
{
	Boolean found = FALSE;
	char pStr[100];
	double tempDouble = 0;
	int tempInt = 0;
	Node* conductor = (*pList)->pStart;
	if(TRUE == isEmpty(*pList))
	{
		(*pList)->pStart = *item;
		(*pList)->pEnd = *item;
	}
	else
	{
		//Find where to insert item
		switch(sortType)
		{
		case 1: strcpy(pStr, (*item)->pSongTitle);
			break;
		case 2: strcpy(pStr, (*item)->pAlbumTitle);
			break;
		case 3: strcpy(pStr, (*item)->pGenre);
			break;
		case 4: tempDouble = (*item)->songLength;
			break;
		case 5: tempInt = (*item)->numTimesPlayed;
			break;
		case 6: tempInt = (*item)->rating;
			break;
		case 0:  //Fall through
		default: strcpy(pStr, (*item)->pArtist);
			break;
		}
		while(NULL != conductor && !found) //While not at the end of the list && placement not found continue down the list
		{
			switch(sortType)
			{
			case 1: if(strcmp(pStr, conductor->pSongTitle) < 0)
						{
							found = TRUE;
						}
				break;
			case 2: if(strcmp(pStr, conductor->pAlbumTitle) < 0)
						{
							found = TRUE;
						}
				break;
			case 3: if(strcmp(pStr, conductor->pGenre) < 0)
						{
							found = TRUE;
						}
				break;
			case 4: if(tempDouble > conductor->songLength)
						{
							found = TRUE;
						}
				break;
			case 5: if(tempInt > conductor->numTimesPlayed)
						{
							found = TRUE;
						}
				break;
			case 6: if(tempInt > conductor->rating)
						{
						found = TRUE;
						}
				break;
			case 0:  //Fall through
			default: if(strcmp(pStr, conductor->pArtist) < 0)
						{
							found = TRUE;
						}
				break;
		}
			if(!found) //If placement not found continue down the list
			{
				conductor = conductor->pNext;
			}
		}
		if(NULL == conductor) //if item is to be inserted at end of list
		{
			(*item)->pPrevious = (*pList)->pEnd;
			(*pList)->pEnd->pNext = (*item);
			(*pList)->pEnd = (*item);
		}
		else if(NULL == conductor->pPrevious) //If item is to be inserted at front of list
		{
			(*item)->pNext = (*pList)->pStart;
			(*pList)->pStart->pPrevious = (*item);
			(*pList)->pStart = (*item);
		}
		else //If item to be inserted between two other nodes
		{
			conductor->pPrevious->pNext = (*item);
			(*item)->pNext = conductor;
			(*item)->pPrevious = conductor->pPrevious;
			conductor->pPrevious = (*item);
		}
	}

}

/*************************************************************************
* Date last modified: June 16th, 2013
* Description: Writes list to file
* Input parameters: List pointer, File pointer
* Returns: 
* Precondition: File must already be open, list must exist
* Postcondition: List is written to file
*************************************************************************/
void saveList(List *pList, FILE *outfile)
{
	Node *conductor = pList->pStart;
	while(NULL != conductor)
	{
		fputs(conductor->pArtist, outfile);
		fprintf(outfile, "\n");
		fputs(conductor->pAlbumTitle, outfile);
		fprintf(outfile, "\n");
		fputs(conductor->pSongTitle, outfile);
		fprintf(outfile, "\n");
		fputs(conductor->pGenre, outfile);
		fprintf(outfile, "\n");
		fprintf(outfile, "%.2f\n", conductor->songLength);
		fprintf(outfile, "%d\n", conductor->numTimesPlayed);
		fprintf(outfile, "%d\n", conductor->rating);
		conductor = conductor->pNext;
	}
}

/*************************************************************************
* Date last modified: June 16th, 2013
* Description: Resorts list in user determined way
* Input parameters: List pointer, user determined sorting type
* Returns: new pointer to list
* Precondition: List must exist
* Postcondition: Valid list pointer is returned to newly sorted list
*************************************************************************/
List* resortList(List *pList, int sortType)
{
	List *pNewList = NULL;
	Node* conductor = pList->pStart;
	Node* tempNode = NULL;
	pNewList = initList();

	while(NULL != conductor)
	{
		pList->pStart = pList->pStart->pNext;
		conductor->pNext = NULL;
		conductor->pPrevious = NULL;
		addItemToList(&pNewList, &conductor, sortType);
		conductor = pList->pStart;
	}
	free(pList);
	return pNewList;
}

/*************************************************************************
* Date last modified: June 16th, 2013
* Description: Displays main menu
* Input parameters:
* Returns: 
* Precondition: 
* Postcondition: Menu is displayed
*************************************************************************/
void displayMenu(void)
{
	printf("***** Digital Music Manager menu *****\n");
	printf("1. Load music from file\n");
	printf("2. Save music list to file\n");
	printf("3. Print music list to screen\n");
	printf("4. Print individual record to screen\n");
	printf("5. Change list sorting option\n");
	printf("6. Insert new record\n");
	printf("7. Edit record\n");
	printf("8. Delete record\n");
	printf("9. Rate song\n");
	printf("10. Exit Music Manager\n\n");
}

/*************************************************************************
* Date last modified: June 16th, 2013
* Description: Gets and validates users main menu choice
* Input parameters: 
* Returns: menu choice
* Precondition:
* Postcondition: Valid menu choice is returned
*************************************************************************/
int getMenuChoice(void)
{
	int choice = 0;
	do
	{
		_flushall;
		printf("Enter your menu choice: ");
		scanf("%d", &choice);
		if(choice < 1 || choice > 10)
		{
			printf("Invalid choice, choose an option between 1 and 6\n");
		}
	}while(choice < 1 || choice > 10);
	return choice;
}

/*************************************************************************
* Date last modified: June 16th, 2013
* Description: Displays sorting options
* Input parameters: 
* Returns: 
* Precondition: 
* Postcondition: Sort options are displayed
*************************************************************************/
void displaySortingOptions(void)
{
	printf("\n*** Sorting Options ***\n");
	printf("1. Artist\n");
	printf("2. Song Title\n");
	printf("3. Album Title\n");
	printf("4. Genre\n");
	printf("5. Song Length\n");
	printf("6. Number of Plays\n");
	printf("7. Rating\n");
}

/*************************************************************************
* Date last modified: June 16th, 2013
* Description: Gets and validates users sort menu option
* Input parameters:
* Returns: Menu choice
* Precondition: 
* Postcondition: Returns valid menu choice
*************************************************************************/
int getSortingOption(void)
{
	int choice = 0;
	do
	{
		printf("\nEnter your choice: ");
		scanf("%d", & choice);
		if(choice < 1 || choice > 7)
		{
			printf("Invalid choice, enter a number between 1 and 7\n");
		}
	}while(choice < 1 || choice > 7);
	return (choice - 1);
}

/*************************************************************************
* Date last modified: June 16th, 2013
* Description: displays search options to console
* Input parameters: 
* Returns: 
* Precondition:
* Postcondition: Search options are displayed
*************************************************************************/
void displaySearchOption(void)
{
	printf("\n*** Searching Option ***\n");
	printf("1. Artist\n");
	printf("2. Song Title\n");
	printf("3. Album Title\n");
	printf("4. Genre\n");
	printf("5. Number of Plays\n");
	printf("6. Rating\n");
}

/*************************************************************************
* Date last modified: June 16th, 2013
* Description: Searches through list for user determined node
* Input parameters: List pointer, type of search field, search string
* Returns: pointer to user selected node (Null node if not found)
* Precondition: List must exist
* Postcondition: If node exists a pointer to it is returned
*************************************************************************/
Node *searchListString(List *pList, int searchOption, char *str)
{
	Boolean found = FALSE;
	Node *conductor = pList->pStart;
	Node *pMem = NULL;
	while(found == FALSE && conductor != NULL)
	{
		switch(searchOption)
		{
		case 1: if(strcmp(str, conductor->pArtist) == 0)
				{
					pMem = conductor;
				}
				break;
		case 2: if(strcmp(str, conductor->pSongTitle) == 0)
				{
					pMem = conductor;
				}
				break;
		case 3: if(strcmp(str, conductor->pAlbumTitle) == 0)
				{
					pMem = conductor;
				}
				break;
		case 4: if(strcmp(str, conductor->pGenre) == 0)
				{
					pMem = conductor;
				}
				break;
		}
		if(!found)
		{
			conductor = conductor->pNext;
		}
	}
	return pMem;
}

/*************************************************************************
* Date last modified: June 16th, 2013
* Description: Searches through list for user determined integer
* Input parameters: List pointer, type of search field, search integer
* Returns: pointer to user selected node (null node if not found)
* Precondition: List must exist
* Postcondition: If node exists a pointer to it is returned
*************************************************************************/
Node *searchListInt(List *pList, int searchOption, int num){
	Boolean found = FALSE;
	Node *conductor = pList->pStart;
	Node *pMem = NULL;
	while(found == FALSE && conductor != NULL)
	{
		switch(searchOption)
		{
		case 5: if(num == conductor->numTimesPlayed)
				{
					pMem = conductor;
				}
				break;
		case 2: if(num == conductor->rating)
				{
					pMem = conductor;
				}
				break;
		}
		if(!found)
		{
			conductor = conductor->pNext;
		}
	}
	return pMem;
}

/*************************************************************************
* Date last modified: June 16th, 2013
* Description: Gets string from user to search for
* Input parameters: 
* Returns: pointer to string (dynamically allocated)
* Precondition: 
* Postcondition: String pointer is returned
*************************************************************************/
char *getSearchString(void)
{
	char str[100];
	char *pStr = NULL;

	_flushall();
	printf("\nEnter your search term: ");
	gets(str);
	pStr = (char*)malloc(sizeof(char)*(strlen(str)+1));
	strcpy(pStr, str);
	return pStr;
}

/*************************************************************************
* Date last modified: June 16th, 2013
* Description: Get integer from user to search for
* Input parameters: 
* Returns: integer
* Precondition: 
* Postcondition: Integer is returned
*************************************************************************/
int getSearchInt(void)
{
	int num = 0;
	printf("\nEnter your search term: ");
	scanf("%d", &num);
	return num;
}

/*************************************************************************
* Date last modified: June 16th, 2013
* Description: Asks user for input to create new node
* Input parameters: 
* Returns: pointer to new user defined node (dynamically allocated)
* Precondition: Memory must be available
* Postcondition: Pointer to valid node is returned
*************************************************************************/
Node *createItem(void)
{
	char *pStr;
	char str[100];
	Node *pMem = NULL;

	_flushall();
	pMem = (Node*)malloc(sizeof(Node));
	printf("\nEnter artist: ");
	gets(str);
	pStr = (char*)malloc(sizeof(char)*(strlen(str)+1));
	strcpy(pStr, str);
	pMem->pArtist = pStr;
	printf("Enter song title: ");
	gets(str);
	pStr = (char*)malloc(sizeof(char)*(strlen(str)+1));
	strcpy(pStr, str);
	pMem->pSongTitle = pStr;
	printf("Enter album title: ");
	gets(str);
	pStr = (char*)malloc(sizeof(char)*(strlen(str)+1));
	strcpy(pStr, str);
	pMem->pAlbumTitle = pStr;
	printf("Enter Genre: ");
	gets(str);
	pStr = (char*)malloc(sizeof(char)*(strlen(str)+1));
	strcpy(pStr, str);
	pMem->pGenre = pStr;
	printf("Enter song length: ");
	scanf("%lf", &(pMem->songLength));
	printf("Enter number of plays: ");
	scanf("%d", &(pMem->numTimesPlayed));
	printf("Enter rating: ");
	scanf("%d", &(pMem->rating));
	
	return pMem;
}

/*************************************************************************
* Date last modified: June 16th, 2013
* Description: Deletes user determined item from list
* Input parameters: List pointer
* Returns: 
* Precondition:List must exist
* Postcondition: List is updated to reflect deleted node
*************************************************************************/
void deleteItem(List **pList)
{
	char str[100];
	Node *conductor = (*pList)->pStart;
	Boolean found = FALSE;

	_flushall();
	printf("Enter the song title you would like to delete: ");
	gets(str);

	while(conductor != NULL && !found)
	{
		if(strcmp(conductor->pSongTitle, str) == 0)
		{
			found = TRUE;
		}
		else
		{
			conductor = conductor->pNext;
		}
	}
	if(!found)
	{
		printf("\nRecord not found");
	}
	else
	{
		if(conductor->pPrevious == NULL) //If deleting front node
		{
			(*pList)->pStart = conductor->pNext;
			conductor->pNext->pPrevious = NULL;
		}
		else if(conductor->pNext == NULL) //If deleting last node
		{
			(*pList)->pEnd = conductor->pPrevious;
			conductor->pPrevious->pNext = NULL;
		}
		else
		{
			conductor->pPrevious->pNext = conductor->pNext;
			conductor->pNext->pPrevious = conductor->pPrevious;
		}
		free(conductor);
	}
}

/*************************************************************************
* Date last modified: June 16th, 2013
* Description: Edits any part of node (designated by user)
* Input parameters: Node pointer
* Returns: 
* Precondition: Node must exist
* Postcondition: Node is updated
*************************************************************************/
void editItem(Node **pItem)
{
	int num = 0;
	char str[100];
	char *pStr = NULL;

	printf("\nItem to edit: ");
	printNode(*pItem);
	printf("\nWhich attribute would you like to edit?\n");
	printf("1. Artist\n");
	printf("2. Song Title\n");
	printf("3. Album Title\n");
	printf("4. Genre\n");
	printf("5. Song Length\n");
	printf("6. Number of Plays\n");
	printf("7. Rating\n");

	num = (1 + getSortingOption());

	_flushall();
	printf("Enter new field: ");
	if(num < 5)
	{
		gets(str);
		pStr = (char*)malloc(sizeof(char)*(strlen(str)+1));
		strcpy(pStr, str);
	}
	switch(num)
	{
	case 1: (*pItem)->pArtist = pStr;
		break;
	case 2: (*pItem)->pSongTitle = pStr;
		break;
	case 3: (*pItem)->pAlbumTitle = pStr;
		break;
	case 4: (*pItem)->pGenre = pStr;
		break;
	case 5: scanf("%lf", &((*pItem)->songLength));
		break;
	case 6: scanf("%d", &((*pItem)->numTimesPlayed));
		break;
	case 7: scanf("%d", &((*pItem)->rating));
		break;
	}
}

/*************************************************************************
* Date last modified: June 16th, 2013
* Description: Changes rating of item
* Input parameters: Node pointer
* Returns: 
* Precondition: Node must exist
* Postcondition: Node rating is updated
*************************************************************************/
void rateItem(Node **pItem)
{
	int num = 0;
	do
	{
		printf("\nEnter new rating for song (1 to 5): ");
		scanf("%d", &num);
		if(num < 1 || num > 5)
		{
			printf("Invalid rating.\n");
		}
	}while(num < 1 || num > 5);
	(*pItem)->rating = num;
}