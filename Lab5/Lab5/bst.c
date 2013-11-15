#include "BTS.h"

void inOrderTraversal(BstNode *pRoot)
{
	if(pRoot != NULL)
	{
		inOrderTraversal(pRoot->pLeft);
		printf("%c\n", pRoot->pInfo->englishChar);
		inOrderTraversal(pRoot->pRight);
	}
}

void initTree(BstNode **pRoot, FILE *infile)
{
	char letter = '\0';
	char buffer[10] = {'\0'};
	while(!feof(infile))
	{
		letter = fgetc(infile);
		fgetc(infile);
		fgets(buffer, 10, infile);
		removeNewLine(buffer);

		treeInsert(pRoot, makeInfoNode(letter, buffer));
	}
}

void treeInsert(BstNode **pRoot, Info *pInfo)
{
	BstNode *pMem = NULL;
	if(*pRoot == NULL)
	{
		pMem = makeNode(pInfo);
		(*pRoot) = pMem;
	}
	else
	{
		if(pInfo->englishChar < (*pRoot)->pInfo->englishChar)
		{
			treeInsert(&((*pRoot)->pLeft), pInfo);
		}
		else if (pInfo->englishChar > (*pRoot)->pInfo->englishChar)
		{
			treeInsert(&((*pRoot)->pRight), pInfo);
		}
	}

}
BstNode *makeNode(Info *pInfo)
{
	BstNode *pMem = (BstNode*)malloc(sizeof(BstNode));
	pMem->pInfo = pInfo;
	pMem->pLeft = NULL;
	pMem->pRight = NULL;
	return pMem;
}

Info *makeInfoNode(char english, char morse[10])
{
	Info *pMem = (Info*)malloc(sizeof(Info));
	pMem->englishChar = english;
	strcpy(pMem->morseChar, morse);
	return pMem;
}

void removeNewLine (char buffer[10])
{
	int i = 0;
	while(buffer[i] != '\n' && i < 9)
	{
		i++;
	}
	buffer[i] = '\0';
}

void findMorse(BstNode *pRoot, char letter, char morseLetter[10])
{
	if(pRoot->pInfo->englishChar == letter)
	{
		strcpy(morseLetter, pRoot->pInfo->morseChar);
	}
	else
	{
		if(letter < pRoot->pInfo->englishChar)
		{
			findMorse(pRoot->pLeft, letter, morseLetter);
		}
		else if(letter > pRoot->pInfo->englishChar)
		{
			findMorse(pRoot->pRight, letter, morseLetter);
		}
	}
}
