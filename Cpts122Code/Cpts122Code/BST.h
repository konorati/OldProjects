#ifndef BST_H
#define BST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct treeNode
{
	int data;
	struct treeNode *pRight;
	struct treeNode *pLeft;
}TreeNode;


TreeNode *makeNode(int newData);
void insertNode(TreeNode **pRoot, int data);
void inOrderTraversal(TreeNode *pRoot);
void preOrderTraversal(TreeNode *pRoot);
void postOrderTraversal(TreeNode *pRoot);

#endif