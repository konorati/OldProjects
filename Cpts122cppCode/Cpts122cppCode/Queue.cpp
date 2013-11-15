#include "Queue.h"

Queue::Queue()
{
	mpHead = NULL;
	mpTail = NULL;
	mSize = 0;
}

Queue::Queue(Queue &rhs) //Deep copy
{
	QueueNode *conductor = NULL, *pTemp = NULL;
	conductor = rhs.mpHead;
	for(int i = 0; i < rhs.mSize; i++)
	{
		pTemp = new QueueNode(conductor->mData);
		conductor = conductor->mpNext;
		if(mSize == 0)
		{
			mpHead = mpTail = pTemp;
		}
		else
		{
			mpTail->mpNext = pTemp;
			mpTail = pTemp;
		}
		mSize++;
	}
}

Queue::~Queue()
{
}

Queue & Queue::operator=(Queue &rhs)
{
	if(this != &rhs)
	{
		mpHead = rhs.mpHead;
		mpTail = rhs.mpTail;
		mSize = rhs.mSize;
	}
	return *this;
}

bool Queue::enqueue(string newData)
{
	bool success = false;
	QueueNode *pMem = NULL;
	pMem = new QueueNode(newData);
	if(pMem != NULL)
	{
		success = true;
		if(mSize == 0) // Queue is empty
		{
			mpHead = mpTail = pMem;
		}	
		else
		{
			mpTail->mpNext = pMem;
			mpTail = pMem;
		}
		mSize++;
	}
	return success;
}

string Queue::dequeue()
{
	string tempData;
	QueueNode *pTemp = NULL;

	if(mSize == 0)
	{
		cout << "No data to dequeue" << endl;
	}
	else 
	{
		tempData = mpHead->mData;
		pTemp = mpHead;
		mpHead = mpHead->mpNext;
		if(mSize == 1)
		{
			mpTail = NULL;
		}
		delete(pTemp);
		mSize--;
	}
	return tempData;
}

void Queue::printQueue()
{
	QueueNode *conductor = mpHead;
	while(conductor != NULL)
	{
		cout << (conductor->mData) << " ";
		conductor = conductor->mpNext;
	}
	cout << endl;
}