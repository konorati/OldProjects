#ifndef GROCERY_STORE_H
#define GROCERY_STORE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct queueNode
{
	int customerNumber;
	int serviceTime;
	int totalTime;
	struct groceryNode *groceryList;
	struct queueNode *pNext;
}QueueNode;

typedef struct queue
{
	QueueNode *pHead;
	QueueNode *pTail;
}Queue;

typedef enum
{
	FALSE, TRUE
}Boolean;

typedef struct groceryNode
{
	char *item;
	struct groceryNode *pNext;
}GroceryNode;

int dequeue(Queue *pQ);
void enqueue(Queue *pQ, int custNum, Boolean isExpress, int serviceNext);
int getServiceTime(Boolean isExpress);
int getTotalTime(QueueNode *pHead, int serviceTime, int serviceNext);
Boolean isEmpty(Queue pQ);
void printQueue(QueueNode *pHead);
QueueNode *makeNode(QueueNode *pHead, int custNum, Boolean isExpress, int serviceNext);
Queue *initQueue(void);
int getSimulationTime(void);
GroceryNode *makeGroceryNode(void);
void addGroceryToList(GroceryNode **pList);
GroceryNode *makeGroceryList(int serviceTime);
void printGroceryList(GroceryNode *pList);


#endif