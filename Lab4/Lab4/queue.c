#include "Queue.h"

Queue *initQueue(void)
{
	Queue *pQ = (Queue*)malloc(sizeof(Queue));
	pQ -> pHead = NULL;
	pQ -> pTail = NULL;
	return pQ;
}

Boolean isEmpty(Queue *pQ)
{
	Boolean empty = FALSE;
	if(pQ->pHead == NULL)
	{
		empty = TRUE;
	}
	return empty;
}

void enqueue(Queue **pQ, QueueNode *pItem)
{
	if(isEmpty(*pQ))
	{
		(*pQ) -> pHead = pItem;
		(*pQ) -> pTail = pItem;
	}
	else
	{
		(*pQ)-> pTail -> pNext = pItem;
		(*pQ) -> pTail = pItem;
	}
}

QueueNode *makeNode(char *strData)
{
	QueueNode *pMem = (QueueNode*)malloc(sizeof(QueueNode));
	pMem->strData = strData;
	pMem->pNext = NULL;
	
	return pMem;
}

char *dequeue(Queue **pQ)
{
	QueueNode *pTemp = NULL;
	char *pStrTemp = NULL;

	if(isEmpty(*pQ))
	{
		(*pQ) -> pTail = NULL;
	}

	pTemp = (*pQ) -> pHead;
	(*pQ) -> pHead = (*pQ) -> pHead -> pNext;

	pStrTemp = pTemp->strData;
	free(pTemp);

	return pStrTemp;
}

void printQueueRecursive(QueueNode *pHead)
{
	if(pHead != NULL)
	{
		puts(pHead->strData);
		printQueueRecursive(pHead->pNext);
	}
}

char *getData(void)
{
	char str[100];
	char *pStr = NULL;

	printf("Enter string: ");
	gets(str);

	pStr = (char*)malloc(sizeof(char)*(strlen(str)+1));
	strcpy(pStr, str);

	return pStr;
}