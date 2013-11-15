#include "BTS.h"

int main (void)
{
	char word[50] = {'\0'};
	char morseLetter[10] = {'\0'};
	BstNode *pRoot = NULL;
	FILE *infile = NULL;
	int i = 0;

	infile = fopen("Morse.txt", "r");
	initTree(&pRoot, infile);
	//inOrderTraversal(pRoot);


	printf("Enter a word: ");
	gets(word);

	while (word[i] != '\0')
	{
		findMorse(pRoot, toupper(word[i]), morseLetter);
		printf("%s ", morseLetter);
		i++;
	}
	findMorse(pRoot, '.', morseLetter);
	printf("%s\n", morseLetter);

	fclose(infile);


	return 0;
}