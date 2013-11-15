#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef enum
{
	FALSE, TRUE
} Boolean;
typedef struct contact
{
	char pFullName[50];
	char phoneNumber[20];
	char pEmail[50];
	struct contact* next;
} Contact;

typedef struct list
{
	Contact *pStart;
} List;

//Contact* createContact(void);
void insertFront(Contact **pList, Contact newItem);
Contact* makeNode(Contact newItem);

#endif