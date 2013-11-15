#include "Queue.h"

int main(void)
{
	Queue *pQ = NULL;
	QueueNode *pNode = NULL;
	char *pStr = NULL;
	
	pQ = initQueue();

	pStr = getData();
	pNode = makeNode(pStr);
	enqueue(&pQ, pNode);

	pStr = getData();
	pNode = makeNode(pStr);
	enqueue(&pQ, pNode);

	pStr = getData();
	pNode = makeNode(pStr);
	enqueue(&pQ, pNode);
	//Print current queue
	printQueueRecursive(pQ->pHead);
	printf("\n");
	system("pause");

	//dequeue
	pStr = dequeue(&pQ);
	pStr = dequeue(&pQ);
	pStr = dequeue(&pQ);
	printQueueRecursive(pQ->pHead);
	printf("\n");
	system("pause");

	//add to queue
	pStr = getData();
	pNode = makeNode(pStr);
	enqueue(&pQ, pNode);

	pStr = getData();
	pNode = makeNode(pStr);
	enqueue(&pQ, pNode);

	printQueueRecursive(pQ->pHead);

	return 0;
}