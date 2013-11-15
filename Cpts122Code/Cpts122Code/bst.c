#include "BST.h"


TreeNode *makeNode(int data)
{
	TreeNode *pMem = (TreeNode*)malloc(sizeof(TreeNode));
	if(pMem != NULL)
	{
		pMem->data = data;
		pMem->pRight = NULL;
		pMem->pLeft = NULL;
	}
	return pMem;
}

void insertNode(TreeNode **pRoot, int data)
{
	TreeNode *pMem = NULL;

	if(NULL == *pRoot) //Tree is empty or we are at the end of a branch
	{
		pMem = makeNode(data);
		*pRoot = pMem;
	}
	else
	{
		if((*pRoot)->data < data)
		{
			insertNode(&((*pRoot)->pRight), data);
		}
		else if((*pRoot)->data > data)
		{
			insertNode(&((*pRoot)->pLeft), data);
		}
	}
}

void inOrderTraversal(TreeNode *pRoot) //Print smallest value first (left, process, right
{
	if(pRoot != NULL)
	{
		inOrderTraversal(pRoot->pLeft);
		printf("%d ", pRoot->data);
		inOrderTraversal(pRoot->pRight);
	}
}

void preOrderTraversal(TreeNode *pRoot) // Process, left , right
{
	if(pRoot != NULL)
	{
		printf("%d ", pRoot->data);
		preOrderTraversal(pRoot->pLeft);
		preOrderTraversal(pRoot->pRight);
	}
}

void postOrderTraversal(TreeNode *pRoot) // Left, right , process
{
	postOrderTraversal(pRoot->pLeft);
	postOrderTraversal(pRoot->pRight);
	printf("%d ", pRoot->data);
}

