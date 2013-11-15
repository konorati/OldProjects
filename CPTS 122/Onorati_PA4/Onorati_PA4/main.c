/*************************************************************************************
* Programmer: Kristin Onorati
* Class: CPTS 122, Summer 2013
* Programming Assignment: 4
* Date: June 25th, 2013
* Description: Simulates 2 grocery store lines (express and normal) over user determined
*	period of time.
**************************************************************************************/

#include "GroceryStore.h"

int main (void)
{
	int timeElapsed = 0, nextCustNum = 1, nextCustExpress = 0, nextCustNormal = 0, 
		simulationTime = 0, serviceNextExpress = -1, serviceNextNormal = -1;
	
	Queue *pQExpress = NULL, *pQNormal = NULL;

	srand(time(NULL));
	nextCustExpress = getServiceTime(TRUE);
	nextCustNormal = getServiceTime(FALSE);

	pQExpress = initQueue();
	pQNormal = initQueue();

	simulationTime = getSimulationTime();
	while (timeElapsed <= simulationTime)
	{
		//If 24 hours has gone by reset customer number to 1
		if(timeElapsed % 1440 == 0)
		{
			nextCustNum = 1;
		}
		//Add customer to express line 
		if(nextCustExpress == timeElapsed)
		{
			//Add customer to queue
			enqueue(pQExpress, nextCustNum, TRUE, serviceNextExpress);
			
			//Print customer info
			printf("Customer %d has entered express lane.\n Total Time elapsed: %d minutes\n", nextCustNum, timeElapsed);
			
			//Increase customer number
			nextCustNum++;

			//Get time next customer will enter line
			nextCustExpress = getServiceTime(TRUE) + timeElapsed;

			//If line was empty get new time til next service
			if(serviceNextExpress == -1)
			{
				serviceNextExpress = pQExpress->pHead->serviceTime;
			}
		}

		//Add customer to normal line
		if(nextCustNormal == timeElapsed)
		{
			//Add customer to queue
			enqueue(pQNormal, nextCustNum, FALSE, serviceNextNormal);

			//Print customer info
			printf("Customer %d has entered normal lane.\n Total Time elapsed: %d minutes\n", nextCustNum, timeElapsed);
			
			//Increase customer number
			nextCustNum++;

			//Get time next customer will enter line
			nextCustNormal = getServiceTime(FALSE) + timeElapsed;

			//If line was empty get new time til next service
			if(serviceNextNormal == -1)
			{
				serviceNextNormal = pQNormal->pHead->serviceTime;
			}
		}
		//Remove customer from express line
		if(serviceNextExpress == 0)
		{
			//Print customer info
			printf("Customer %d serviced from express lane.\n Total service time: %d minutes\n", pQExpress->pHead->customerNumber, pQExpress->pHead->totalTime);
			
			//Remove customer
			dequeue(pQExpress);

			//Reset next service 
			if(isEmpty(*pQExpress))
			{
				serviceNextExpress = -1;
			}
			else
			{
				serviceNextExpress = pQExpress->pHead->serviceTime;
			}
		}

		//Remove customer from normal line
		if(serviceNextNormal == 0)
		{
			//Print customer info
			printf("Customer %d serviced from normal lane.\n Total service time: %d minutes\n", pQNormal->pHead->customerNumber, pQNormal->pHead->totalTime);

			//Remove customer
			dequeue(pQNormal);

			//Reset next service
			if(isEmpty(*pQNormal))
			{
				serviceNextNormal = -1;
			}
			else
			{
				serviceNextNormal = pQNormal->pHead->serviceTime;
			}
		}

		//If elapsed time is divisible by 10 print both queues
		if(timeElapsed != 0 && (timeElapsed % 10) == 0)
		{
			printf("\nExpress Lane: \n");
			printQueue(pQExpress->pHead);
			printf("\nNormal Lane: \n");
			printQueue(pQNormal->pHead);
		}

		//Increment time & decrement next service time
		timeElapsed++;
		if(serviceNextExpress != -1)
		{
			serviceNextExpress--;
		}
		if(serviceNextNormal != -1)
		{
			serviceNextNormal--;
		}

		
	}

	return 0;
}