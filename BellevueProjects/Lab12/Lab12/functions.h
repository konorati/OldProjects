#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
	char data[100];
	struct node *next;
}Node;

int recursiveDigitAdd(int num);
void recursiveStringReverse(char *word, int start, int end);
void towerOfHanoi(int num, char start, char mid, char end);
Node* makeNode(char *data);
void insertAtFront(Node **head, char *data);


#endif