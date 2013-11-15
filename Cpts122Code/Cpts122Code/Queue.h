#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct queueNode
{
	int data;
	struct queueNode *pNext;
}QueueNode;

typedef struct queue
{
	QueueNode *pHead;
	QueueNode *pTail;
}Queue;

void initQueue (Queue *pQ);
QueueNode* makeQueueNode(int newItem);
void enqueue(Queue *pQ, int newItem);
void recursivePrint(Queue q);
int dequeue(Queue *pQ);
void display(QueueNode *pHead);

#endif