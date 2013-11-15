#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact
{
	char *pName;
	char *pEmail;
	char *pPhone;
	char *pTitle;
}Contact;

typedef struct node
{
	Contact *pContact;
	struct node *pNext;
}Node;

typedef enum
{
	FALSE, TRUE
}Boolean;

void addNode(Node** pList, Contact *pContact);
Contact *createContact(void);
Node *createNode(Contact *pContact);
void removeNode(Node **pList, char *pName);
void recursivePrintList(Node *pList);
void displayMenu(void);
int getMenuChoice(void);



#endif