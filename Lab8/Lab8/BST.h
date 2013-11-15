#ifndef BST_H
#define BST_H
#include <iostream>
#include <string>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
using std::string;

class BST;
class BstNode
{
	friend class BST;
	friend ostream & operator<<(ostream &lhs, BstNode &rhs);
	private:
		string mWord;
		BstNode *mpRight;
		BstNode *mpLeft;

	public:
		BstNode(string newData = "", BstNode *left = NULL, BstNode *right = NULL);
		BstNode(BstNode &copy);
		~BstNode();
		BstNode & operator=(BstNode &rhs);

		void setWord(string newWord);
		void setLeft(BstNode *newLeft);
		void setRight(BstNode *newRight);
		string getWord();
		BstNode *getLeft();
		BstNode *getRight();
		
};

class BST
{
	private:
		BstNode *mpRoot;
		void copy(BstNode **copyPtr);
		void destroy(BstNode **pCur);

	public:
		BST(BstNode *newRoot = NULL);
		~BST();
		BST & operator=(BST &rhs);
		void setRoot(BstNode *newRoot);
		BstNode *getRoot();
		void insertNode(BstNode **pNode, string newData);
		void inOrderTraversal(BstNode *pNode);
		void preOrderTraversal(BstNode *pNode);
		void postOrderTraversal(BstNode *pNode);
		bool isEmpty();
};




#endif
