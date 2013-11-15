#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queueNode
{
	char *strData;
	struct queueNode *pNext;
}QueueNode;

typedef struct queue
{
	struct queueNode *pHead;
	struct queueNode *pTail;
}Queue;

typedef enum 
{
	FALSE, TRUE
}Boolean;

Queue* initQueue(void);
Boolean isEmpty(Queue *pQ);
void enqueue(Queue **pQ, QueueNode *pItem);
QueueNode *makeNode(char *strData);
char *dequeue(Queue **pQ);
void printQueueRecursive(QueueNode *pHead);
char *getData(void);

#endif