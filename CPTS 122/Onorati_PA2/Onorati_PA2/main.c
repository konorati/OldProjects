#include "DMM.h"

/*************************************************************************************
* Programmer: Kristin Onorati
* Class: CPTS 122, Summer 2013
* Programming Assignment: 2
* Date: June 16th, 2013
* Description: Loads song info from file and allows user to manipulate list of song 
*    (change sorting, add song info, edit song info, save to file, delete song)
**************************************************************************************/
int main(void)
{
	FILE *infile = NULL, *outfile = NULL;
	Node* pItem = NULL;
	List* pList = NULL;
	char *str = NULL;
	int sortType = 0, menuChoice = 0, num = 0, searchOption = 0;

	while(menuChoice != 10){
		system("cls");
		displayMenu();
		menuChoice = getMenuChoice();
		switch(menuChoice)
		{
		case 1: pList = initList(); //Read items from file into a list
				infile = fopen("Music.txt", "r");
				while(!feof(infile))
				{
					pItem = readItem(infile);
					addItemToList(&pList, &pItem, sortType);
				}
				fclose(infile);
			break;
		case 2: outfile = fopen("Music.txt", "w"); //Save items in list to a file
			saveList(pList, outfile);
			fclose(outfile);
			break;
		case 3: printList(pList); //Print entire list
			break;
		case 4:  //Print individual record in list
				displaySearchOption();
				searchOption = (1 + getSortingOption());
				if(searchOption < 5)
				{
					str = getSearchString();
					pItem = searchListString(pList, searchOption, str);
				}
				else
				{
					num = getSearchInt();
					pItem = searchListInt(pList, searchOption, num);
				}
				if(pItem == NULL)
				{
					printf("\nItem not found\n");
				}
				else
				{
					printNode(pItem);
				}
			break;
		case 5: displaySortingOptions(); //Change sorting option of list
			sortType = getSortingOption();
			pList = resortList(pList, sortType);
			break;
		case 6:  pItem = createItem(); //Get new item & insert it into list
				addItemToList(&pList, &pItem, sortType);
			break;
		case 7:  displaySearchOption(); //Edit item
				searchOption = (1 + getSortingOption());
				if(searchOption < 5)
				{
					str = getSearchString();
					pItem = searchListString(pList, searchOption, str);
				}
				else
				{
					num = getSearchInt();
					pItem = searchListInt(pList, searchOption, num);
				}
				if(pItem == NULL)
				{
					printf("Item not found");
				} 
				else
				{
					editItem(&pItem);
				}
			break;
		case 8: deleteItem(&pList); //Delete record
			break;
		case 9: displaySearchOption(); //Rate item
				searchOption = (1 + getSortingOption());
				if(searchOption < 5)
				{
					str = getSearchString();
					pItem = searchListString(pList, searchOption, str);
				}
				else
				{
					num = getSearchInt();
					pItem = searchListInt(pList, searchOption, num);
				}
				if(pItem == NULL)
				{
					printf("Item not found");
				} 
				else
				{
					rateItem(&pItem);
				}
			break;
		case 10:
		default: printf("\nNow exiting music manager and saving your current list\n.");
			 outfile = fopen("Music.txt", "w"); //Save items in list to a file
			saveList(pList, outfile);
			fclose(outfile);
			break;
		}
		system("pause");
	}
	

	



	return 0;
}