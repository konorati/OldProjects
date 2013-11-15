#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct info
{
	char englishChar;
	char morseChar[10];
}Info;

typedef struct bstNode
{
	Info *pInfo;
	struct bstNode *pRight;
	struct bstNode *pLeft;
}BstNode;

void inOrderTraversal(BstNode *pRoot);
void initTree(BstNode **pRoot, FILE *infile);
void treeInsert(BstNode **pRoot, Info *pInfo);
BstNode *makeNode(Info *pInfo);
Info *makeInfoNode(char english, char morse[10]);
void removeNewLine (char buffer[10]);
void findMorse(BstNode *pRoot, char letter, char morseLetter[10]);


#endif