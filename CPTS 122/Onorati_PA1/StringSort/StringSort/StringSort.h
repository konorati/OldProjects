#ifndef STRING_SORT_H
#define STRING_SORT_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define DESCENDING 0
#define ASCENDING 1

void stringSort(char** pList, int size, int direction);
int getSizeOfList(void);
char* getListItem(void);
void printList(char** pList, int size);
#endif