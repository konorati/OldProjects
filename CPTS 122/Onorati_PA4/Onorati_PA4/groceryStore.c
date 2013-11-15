#include "GroceryStore.h"

/*************************************************************************
* Date last modified: June 25th, 2013
* Description: Removes node from from of queue and frees dynamic memory
* Input parameters: pointer to Queue node (contains head and tail pointer)
* Returns: Customer number from node removed from queue (int)
* Precondition: Queue exists
* Postcondition: Node from front of queue is removed
*************************************************************************/
int dequeue(Queue *pQ)
{
	int custNum = 0;
	QueueNode *pTemp = NULL;
	GroceryNode *conductor = NULL, *pTempGroc = NULL;

	if(isEmpty(*pQ))
	{
		printf("Line is empty\n");
	}
	else
	{
		pTemp = pQ->pHead;
		custNum = pTemp->customerNumber;
		conductor = pTemp->groceryList;
		pQ->pHead = pTemp->pNext;
		if(pQ->pHead == NULL)
		{
			pQ->pTail = NULL;
		}
		while(conductor !=NULL)
		{
			pTempGroc = conductor;
			conductor = conductor->pNext;
			free(pTempGroc);
		}
		free(pTemp);
	}
	return custNum;
}

/*************************************************************************
* Date last modified: June 25th, 2013
* Description: Adds node to end of queue
* Input parameters: pointer to Queue node (contains head and tail pointer),
*		Customer number to add(int), Boolean value True if express lane, False if not,
*		Time til servicing next in line
* Returns: 
* Precondition: Queue exists
* Postcondition: Node is added to queue
*************************************************************************/
void enqueue(Queue *pQ, int custNum, Boolean isExpress, int serviceNext)
{
	QueueNode *pMem = NULL;
	pMem = makeNode(pQ->pHead, custNum, isExpress, serviceNext);
	if(pQ->pHead == NULL) // If queue is empty
	{
		pQ->pHead = pMem;
		pQ->pTail = pMem;
	}
	else
	{
		pQ->pTail->pNext = pMem;
		pQ->pTail = pMem;
	}
}

/*************************************************************************
* Date last modified: June 25th, 2013
* Description: Creates a random service time for customer based on which line they are in
* Input parameters: Boolean value True if express lane, False if not
* Returns: Customers individual service time
* Precondition: 
* Postcondition: Random value between 1 and 8 is returned
*************************************************************************/
int getServiceTime(Boolean isExpress)
{
	int time = 0;
	if(isExpress)
	{
		time = (rand() % 5) + 1;
	}
	else
	{
		time = (rand() % 6) + 3; 
	}
	return time;
}

/*************************************************************************
* Date last modified: June 25th, 2013
* Description: Determines customers total time in line (individual service time plus service time of those ahead of them)
* Input parameters: Pointer to head of queue, individual service time (int), time to service next in line
* Returns: Customers total service time
* Precondition: Queue exists
* Postcondition: Total customer service time is returned
*************************************************************************/
int getTotalTime(QueueNode *pHead, int serviceTime, int serviceNext)
{
	int totalTime = 0;
	QueueNode *conductor = pHead, *pPrevious = NULL;
	while(conductor != NULL)
	{
		totalTime += conductor->serviceTime;
		pPrevious = conductor;
		conductor = conductor->pNext;
	}
	if(serviceNext != -1)
	{
		totalTime -= (pPrevious->serviceTime - serviceNext);
	}
	totalTime += serviceTime;
}

/*************************************************************************
* Date last modified: June 25th, 2013
* Description: Determines if list is empty or not 
* Input parameters: pointer to Queue node (contains head and tail pointer)
* Returns: True if list is empty, false if not
* Precondition: Queue exists
* Postcondition: True or False is returned
*************************************************************************/
Boolean isEmpty(Queue pQ)
{
	Boolean empty = FALSE;
	if(NULL == pQ.pHead)
	{
		empty = TRUE;
	}
	return empty;
}

/*************************************************************************
* Date last modified: June 25th, 2013
* Description: Prints the entire queue including customer number, service time, and grocery list
* Input parameters: Pointer to the head of the queue
* Returns: 
* Precondition: Queue exists
* Postcondition: Entire queue is printed to console
*************************************************************************/
void printQueue(QueueNode *pHead)
{
	QueueNode *conductor = pHead;
	while(conductor != NULL)
	{
		printf("Customer Number: %d\n", conductor->customerNumber);
		printGroceryList(conductor->groceryList);
		printf("Service Time: %d\n", conductor->serviceTime);
		printf("Total Time: %d\n\n", conductor->totalTime);
		conductor = conductor->pNext;
	}
}

/*************************************************************************
* Date last modified: June 25th, 2013
* Description: Creates a new queue node (Memory dynamically allocated)
* Input parameters: pointer to head of queue, customer number (int), and Boolean value
*		True if express lane, False if not, time to servicing next in line
* Returns: Pointer to new queueNode
* Precondition: Queue exists
* Postcondition: Pointer to valid node is returned
*************************************************************************/
QueueNode *makeNode(QueueNode *pHead, int custNum, Boolean isExpress, int serviceNext)
{
	QueueNode *pMem = NULL;
	pMem = (QueueNode*)malloc(sizeof(QueueNode));

	if(pMem != NULL)
	{
		pMem->customerNumber = custNum;
		pMem->serviceTime = getServiceTime(isExpress);
		pMem->totalTime = getTotalTime(pHead, pMem->serviceTime, serviceNext);
		pMem->groceryList = makeGroceryList(pMem->serviceTime);
		pMem->pNext = NULL;
	}
	return pMem;
}

/*************************************************************************
* Date last modified: June 25th, 2013
* Description: Initializes the queue (head and tail pointers)
* Input parameters: 
* Returns: Pointer to queue
* Precondition: 
* Postcondition: Valid pointer to queue is returned
*************************************************************************/
Queue *initQueue(void)
{
	Queue *pMem = NULL;
	pMem = (Queue*)malloc(sizeof(Queue*));
	if(pMem != NULL)
	{
		pMem->pHead = NULL;
		pMem->pTail = NULL;
	}
	return pMem;
}

/*************************************************************************
* Date last modified: June 25th, 2013
* Description: Gets simulation time from user and validates entry
* Input parameters: 
* Returns: Total user determined simulation time in minutes (int)
* Precondition: 
* Postcondition: Positive integer value is returned
*************************************************************************/
int getSimulationTime(void)
{
	int time = 0;
	while(time < 1)
	{
		printf("\nEnter total simulation time in whole minutes: ");
		scanf("%d", &time);
		if(time < 1)
		{
			printf("Invalid entry, time must be a positive number.\n");
		}
	}
	return time;
}

/*************************************************************************
* Date last modified: June 25th, 2013
* Description: Makes a new grocery node (memory dynamically allocated)
* Input parameters: 
* Returns: Pointer to grocery node
* Precondition: 
* Postcondition: Valid pointer to new grocery node is returned
*************************************************************************/
GroceryNode *makeGroceryNode(void)
{
	GroceryNode *pMem = NULL;
	int itemNum = 0;
	char *tempItem;
	char items[10][20] = {"Cereal", "Milk", "Carrots", "Bread", "Soda", "Steak", "Potatoes", "Jam", "Cookies", "Rice"};

	itemNum = rand()%10;
	pMem = (GroceryNode*)malloc(sizeof(GroceryNode));
	tempItem = (char*)malloc((sizeof(char)*strlen(items[itemNum])+1));
	strcpy(tempItem, items[itemNum]);
	pMem->item = tempItem;
	pMem->pNext = NULL;

	return pMem;
}

/*************************************************************************
* Date last modified: June 25th, 2013
* Description: Adds a grocery node to front of grocery list
* Input parameters: Pointer to front of grocery list
* Returns: 
* Precondition: GroceryList exists
* Postcondition: Grocery node is added to front of grocery list
*************************************************************************/
void addGroceryToList(GroceryNode **pList)
{
	GroceryNode *pMem = NULL;
	pMem = makeGroceryNode();

	if(*pList == NULL)
	{
		*pList = pMem;
	}
	else
	{
		pMem->pNext = *pList;
		*pList = pMem;
	}
}

/*************************************************************************
* Date last modified: June 25th, 2013
* Description: Makes entire grocery list for one customer with length based on service time
* Input parameters: Individual service time of customer
* Returns: Pointer to head of grocery list
* Precondition: Service time is valid
* Postcondition: Valid pointer to front of grocery list is returned
*************************************************************************/
GroceryNode *makeGroceryList(int serviceTime)
{
	GroceryNode *pList = NULL;
	int i = 0;
	for(i = 0; i < serviceTime; i++)
	{
		addGroceryToList(&pList);
	}
	return pList;
}

/*************************************************************************
* Date last modified: June 25th, 2013
* Description: Prints the entire grocery list for one customer
* Input parameters: Pointer to front of grocery list
* Returns: 
* Precondition: Grocery list exists
* Postcondition: Grocery list is printed to console
*************************************************************************/
void printGroceryList(GroceryNode *pList)
{
	GroceryNode *conductor = pList;
	printf("Grocery List: \n\t");
	while(conductor != NULL)
	{
		printf("%s ", conductor->item);
		conductor = conductor->pNext;
	}
	printf("\n");
}