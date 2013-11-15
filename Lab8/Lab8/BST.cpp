#include "BST.h"

BstNode::BstNode(string newData, BstNode *left, BstNode *right)
{
	mWord.assign(newData);
	mpLeft = left;
	mpRight = right;
}

BstNode::BstNode(BstNode &copy)
{
	mWord.assign(copy.mWord);
	mpLeft = copy.mpLeft;
	mpRight = copy.mpRight;
}

ostream & operator<<(ostream &lhs, BstNode &rhs)
{
	lhs << rhs.mWord << endl;
	return lhs;
}

BstNode & BstNode::operator=(BstNode &rhs)
{
	if(this != &rhs)
	{
		mWord.assign(rhs.mWord);
		mpRight = rhs.mpRight;
		mpLeft = rhs.mpLeft;
	}
	return *this;
}

void BstNode::setWord(string newWord)
{
	mWord.assign(newWord);
}

void BstNode::setLeft(BstNode *newLeft)
{
	mpLeft = newLeft;
}

void BstNode::setRight(BstNode *newRight)
{
	mpRight = newRight;
}

string BstNode::getWord()
{
	return mWord;
}

BstNode *BstNode::getLeft()
{
	return mpLeft;
}
		
BstNode *BstNode::getRight()
{
	return mpRight;
}

BST::BST(BstNode *newRoot)
{
	mpRoot = newRoot;
}

BST::~BST()
{

}
		
BST & BST::operator=(BST &rhs)
{
	if(this != &rhs)
	{
		mpRoot = rhs.mpRoot;
	}
	return *this;
}

void BST::setRoot(BstNode *newRoot)
{
	mpRoot = newRoot;
}

BstNode *BST::getRoot()
{
	return mpRoot;
}

void BST::insertNode(BstNode **pNode, string newData)
{
	BstNode *pMem = NULL;
	if(*pNode == NULL)
	{
		pMem = new BstNode(newData);
		if(pMem != NULL)
		{
			*pNode = pMem;
		}
	}
	else
	{
		if((*pNode)->mWord > newData)
		{
			insertNode(&((*pNode)->mpLeft), newData);
		}
		else if((*pNode)->mWord < newData)
		{
			insertNode(&((*pNode)->mpRight), newData);
		}
		else
		{
			cout << "Duplicate Item" << endl;
		}
	}
	
}

void BST::inOrderTraversal(BstNode *pNode)
{
	if(pNode != NULL)
	{
		inOrderTraversal(pNode->mpLeft);
		cout << (*pNode) << endl;
		inOrderTraversal(pNode->mpRight);
	}
}

void BST::preOrderTraversal(BstNode *pNode)
{
	if(pNode != NULL)
	{
		cout << (*pNode) << endl;
		preOrderTraversal(pNode->mpLeft);
		preOrderTraversal(pNode->mpRight);
	}
}

void BST::postOrderTraversal(BstNode *pNode)
{
	if(pNode != NULL)
	{
		postOrderTraversal(pNode->mpLeft);
		postOrderTraversal(pNode->mpRight);
		cout << (*pNode) << endl;
	}
}

bool BST::isEmpty()
{
	bool empty = false;
	if(mpRoot == NULL)
	{
		empty = true;
	}
	return empty;
}