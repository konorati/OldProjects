#include "BST.h"

int main(void)
{
	BST root;
	BstNode *Root = root.getRoot();
	root.insertNode(&Root, "Cat");
	root.insertNode(&Root, "Dog");
	root.insertNode(&Root, "Zebra");
	root.insertNode(&Root, "Apple");
	root.insertNode(&Root, "Banana");
	root.inOrderTraversal(Root);
	return 0;
}