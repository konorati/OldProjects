#include "LinkedList.h"

int main (void) 
{
	int choice = 0;
	Node *pList = NULL, *pNode = NULL;
	char name[100];
	Contact *pContact = NULL;
	while(choice != 7)
	{
		system("cls");
		displayMenu();
		choice = getMenuChoice();
		switch(choice)
		{
		case 1: //Load contacts
			break;
		case 2: //Save contacts
			break;
		case 3: pContact = createContact();  //Add new contact
				addNode(&pList, pContact);
			break;
		case 4: //Edit contact
			break;
		case 5: recursivePrintList(pList);  //Print contact list
			break;
		case 6: _flushall(); 
				printf("\nEnter name of contact to delete: "); //Delete contact
				gets(name);
				removeNode(&pList, name);
			break;
		default:
			break;
		}
		system("pause");
	}

	return 0;
}