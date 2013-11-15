#include "Function.h"

Contact* createContact(void)
{
	char initFullName[100], initPhoneNumber[20], initEmail[100];
	Contact* pMem = NULL;
	char *pTempName = NULL, *pTempEmail = NULL;
	
	printf("Enter contact's name: ");
	gets(initFullName);

	puts("Enter contact's phone number: ");
	gets(initPhoneNumber);

	puts("Enter contact's email address: ");
	gets(initEmail);

	//pMem = (Contact*)malloc(sizeof(Contact)); Only creates 28 bytes
	//ptempName = initFullName; Can't do this because initFullName is temporary

	pTempName = (char*)malloc(sizeof(char)*(strlen(initFullName)+1));
	pTempEmail = (char*)malloc(sizeof(char)*(strlen(initEmail)+1));

	strcpy(pTempEmail, initFullName);
	strcpy(pTempEmail, initEmail);

	pMem = (Contact*)malloc(sizeof(Contact));
	//pMem -> pFullName = pTempName;
	strcpy(pMem->phoneNumber, initPhoneNumber);
	//pMem->pEmail = pTempEmail;

	return pMem;
}

Contact* makeNode(Contact newItem)
{
	Contact* pMem = NULL;
	pMem = (Contact*)malloc(sizeof(Contact));

	if(pMem != NULL) //If we haven't run out of memory
	{
		strcpy(pMem -> pEmail, newItem.pEmail);
		strcpy(pMem -> pFullName, newItem.pFullName);
		strcpy(pMem -> phoneNumber, newItem.phoneNumber);
		pMem -> next = NULL;
	}
	return pMem;
}

void insertAtFront(Contact **pList, Contact newItem)
{
	Contact* pMem = NULL, *pTemp = NULL;
	pMem = makeNode(newItem);
	if(NULL == *pList)
	{
		*pList = pMem; 
	}
	else
	{
		pMem -> next = *pList;
		*pList = pMem;
	}
}
