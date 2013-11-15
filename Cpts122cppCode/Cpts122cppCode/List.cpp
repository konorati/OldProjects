#include "List.h"

ListNode * List::makeNode(int data)
{
	ListNode *pMem = NULL;
	pMem = new ListNode(data);
	return pMem;
}

bool List::insertInOrder(int data)
{
	bool success = false;
	ListNode *pMem = NULL, *conductor = NULL, *pPrevious = NULL;
	pMem = makeNode(data);

	if(pMem != NULL)
	{
		success = true;
	}

	conductor = mpList;
	if(conductor == NULL)
	{
		mpList = pMem;
	}
	else
	{
		while((conductor != NULL) && (conductor->mData < data))
		{
			pPrevious = conductor;
			conductor = conductor->mpNext;
		}
		if(pPrevious == NULL) //If front of list
		{
			pMem->mpNext = conductor;
			mpList = pMem;
		}
		else
		{
			pMem->mpNext = conductor;
			pPrevious->mpNext = pMem;
		}
	}
	return success;
}

void List::printList(ListNode *next)
{
	if(next != NULL)
	{
		cout << next->mData << " ";
		printList(next->mpNext);
	}
}

List::List()
{
	mpList = NULL;
}

int List::deleteEndNode()
{
	int tempData;
	ListNode *conductor = NULL, *previous = NULL;
	
	
	conductor = mpList;
	while(conductor->mpNext != NULL)
	{
		previous = conductor;
		conductor = conductor->mpNext;
	}
	tempData = conductor->mData;
	delete conductor;
	if(previous == NULL)
	{
		mpList = NULL;
	}
	else
	{
		previous->mpNext = NULL;
	}
	
	return tempData;
}

List::~List()
{
	destroyList();
}

void List::destroyList()
{
	ListNode *pTemp = NULL;

	while(mpList != NULL)
	{
		pTemp = mpList;
		mpList = mpList->mpNext;
		delete(pTemp);
	}
}