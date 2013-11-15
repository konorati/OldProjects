#include "LinkedList.h"

void addNode(Node** pList, Contact *pContact)
{
	Boolean found = FALSE;
	Node *conductor = *pList;
	Node *pPrevious = NULL;
	Node *pMem = NULL;
	pMem = createNode(pContact);
	if(*pList == NULL)
	{
		(*pList) = pMem;
	}
	else
	{
		while(conductor != NULL && !found)
		{
			if(strcmp(conductor->pContact->pName, pMem->pContact->pName) > 0)
			{
				found = TRUE;
			}
			else
			{
				pPrevious = conductor;
				conductor = conductor->pNext;
			}
		}
		if(conductor == NULL) //reached end of list
		{
			pPrevious->pNext = pMem;
		}
		else if (pPrevious == NULL) //Enter at front of list
		{
			pMem->pNext = (*pList);
			(*pList) = pMem;
		}
		else //Enter in middle of list
		{
			pPrevious->pNext = pMem;
			pMem -> pNext = conductor;
		}
	}
}

Contact *createContact(void)
{
	Contact *pMem = NULL;
	char str[100];
	char *pStr = NULL;

	pMem = (Contact*)malloc(sizeof(Contact));

	_flushall();
	//Get name
	printf("Enter contact name: ");
	gets(str);
	pStr = (char*)malloc(sizeof(char)*(strlen(str)+1));
	strcpy(pStr, str);
	pMem -> pName = pStr;

	//Get email
	printf("Enter contact email: ");
	gets(str);
	pStr = (char*)malloc(sizeof(char)*(strlen(str)+1));
	strcpy(pStr, str);
	pMem -> pEmail = pStr;

	//Get phone number
	printf("Enter contact phone number: ");
	gets(str);
	pStr = (char*)malloc(sizeof(char)*(strlen(str)+1));
	strcpy(pStr, str);
	pMem -> pPhone = pStr;

	//Get title
	printf("Enter contact professional title: ");
	gets(str);
	pStr = (char*)malloc(sizeof(char)*(strlen(str)+1));
	strcpy(pStr, str);
	pMem -> pTitle = pStr;

	return pMem;
}

Node *createNode(Contact *pContact)
{
	Node *pMem = (Node*)malloc(sizeof(Node));
	pMem -> pContact = pContact;
	pMem -> pNext = NULL;
	return pMem;
}

void removeNode(Node **pList, char *pName)
{
	Node *conductor = *pList;
	Node *pPrevious = NULL;
	Boolean found = FALSE;

	while(!found && conductor != NULL)
	{
		if(strcmp(pName, conductor->pContact->pName) == 0)
		{
			found = TRUE;
		}
		else
		{
			pPrevious = conductor;
			conductor = conductor->pNext;
		}
	}
	if(!found)
	{
		printf("\nEntry not found\n");
	}
	else if(pPrevious == NULL) //Delete from front of list
	{
		*pList = conductor->pNext;
	}
	else //Delete not from front
	{
		pPrevious->pNext = conductor->pNext;
	}
	free(conductor);
}

void recursivePrintList(Node *pList)
{
	if(pList != NULL)
	{
		puts(pList->pContact->pName);
		puts(pList->pContact->pEmail);
		puts(pList->pContact->pPhone);
		puts(pList->pContact->pTitle);
		recursivePrintList(pList->pNext);
	}
}

void displayMenu(void)
{
	printf("*** Main Menu ***\n");
	printf("1. Load contacts\n");
	printf("2. Save contacts to file\n");
	printf("3. Add new contact\n");
	printf("4. Edit contact\n");
	printf("5. Print contact list\n");
	printf("6. Delete contact\n");
	printf("7. Exit\n");
}

int getMenuChoice(void)
{
	int choice = 0;
	_flushall();
	printf("Enter your menu choice: ");
	scanf("%d", &choice);

	return choice;
}