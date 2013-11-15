#include "Queue.h"

void initQueue (Queue *pQ)
{
	pQ -> pHead = NULL;
	pQ -> pTail = NULL;
}


QueueNode* makeQueueNode(int newItem)
{
	QueueNode* pMem = NULL;

	pMem = (QueueNode*) malloc(sizeof(QueueNode));

	pMem->data = newItem;
	pMem->pNext = NULL;

	return pMem;
};


void enqueue(Queue *pQ, int newItem)
{
	QueueNode *pMem = NULL;

	pMem = makeQueueNode(newItem);

	if(NULL == pQ->pHead) //Could check tail but if head is null tail must also be NULL
	{
		pQ -> pTail = pQ -> pHead = pMem; //If only item in queue it is both the head and the tail
	}
	else //Non-empty queue
	{
		pQ->pTail->pNext = pMem;
		pQ->pTail = pMem;
	}
}


void recursivePrint(Queue q)
{
	if(NULL == q.pHead)
	{
	}
	else
	{
		printf("%d ", q.pHead->data);
		q.pHead = q.pHead->pNext;
		recursivePrint(q);
	}
}

//Precondition: queue is not empty
int dequeue(Queue *pQ)
{
	int data = 0;
	QueueNode *pMem = NULL;

	pMem = pQ->pHead;

	if(pQ->pHead == pQ->pTail) //Only one node in queue
	{
		pQ -> pTail = NULL;
	}
	pQ -> pHead = pQ -> pHead -> pNext;

	data = pMem->data;
	free(pMem);

	return data;
}

void display(QueueNode *pHead)
{
	if(pHead != NULL)
	{
		printf("%d ", pHead->data);
		display(pHead->pNext);
	}
}