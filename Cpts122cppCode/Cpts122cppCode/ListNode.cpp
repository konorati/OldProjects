#include "ListNode.h"

ListNode::ListNode(int data)
{
	mData = data;
	mpNext = NULL;
}

ListNode::ListNode(ListNode &obj)
{
	mData = obj.mData;
	mpNext = obj.mpNext;
}

ListNode::~ListNode()
{
}

ListNode & ListNode::operator=(ListNode &rhs)
{
	if(this != &rhs)
	{
		mData = rhs.mData;
		mpNext = rhs.mpNext;
	}
	return *this;
}

int ListNode::getData() const
{
	return mData;
}

ListNode * ListNode::getNext() const
{
	return mpNext;
}

void ListNode::setData(int data)
{
	mData = data;
}

void ListNode::setNext(ListNode *next)
{
	mpNext = next;
}