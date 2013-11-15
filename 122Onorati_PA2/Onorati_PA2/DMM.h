#ifndef DMM_H
#define DMM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
	FALSE, TRUE
}Boolean;

typedef struct node
{
	char* pArtist;
	char* pSongTitle;
	char* pAlbumTitle;
	char* pGenre;
	double songLength;
	int numTimesPlayed;
	int rating;
	struct node* pPrevious;
	struct node* pNext;
}Node;

typedef struct list
{
	Node* pStart;
	Node* pEnd;
}List;

char* readStr(FILE *infile);
Node* readItem(FILE *infile);
void printNode(Node *pItem);
List* initList(void);
Boolean isEmpty(List *pList);
void printList(List *pList);
void addItemToList(List **pList, Node **item, int sortType);
void saveList(List *pList, FILE *outfile);
List* resortList(List *pList, int sortType);
void displayMenu(void);
int getMenuChoice(void);
void displaySortingOptions(void);
int getSortingOption(void);
void displaySearchOption(void);
Node *searchListString(List *pList, int searchOption, char *str);
Node *searchListInt(List *pList, int searchOption, int num);
char *getSearchString(void);
int getSearchInt(void);
Node *createItem(void);
void deleteItem(List** pList);
void editItem(Node** pItem);
void rateItem(Node** pItem);
#endif