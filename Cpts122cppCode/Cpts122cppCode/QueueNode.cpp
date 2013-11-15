#include "QueueNode.h"

QueueNode::QueueNode(string newData)
{
	mData = newData;
	mpNext = NULL;
}

QueueNode::QueueNode(QueueNode &rhs)
{
	mData = rhs.mData;
	mpNext = rhs.mpNext;
}

QueueNode::~QueueNode()
{
}

QueueNode & QueueNode::operator=(QueueNode &rhs)
{
	if(this != &rhs)
	{
		mData = rhs.mData;
		mpNext = rhs.mpNext;
	}
	return *this;
}

void QueueNode::setData(string newData)
{
	mData = newData;
}

void QueueNode::setNext(QueueNode *newNext)
{
	mpNext = newNext;
}

string QueueNode::getData()
{
	return mData;
}

QueueNode * QueueNode::getNext()
{
	return mpNext;
}