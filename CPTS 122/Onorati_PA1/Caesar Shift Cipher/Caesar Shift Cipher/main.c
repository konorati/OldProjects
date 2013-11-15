/*************************************************************************************
* Programmer: Kristin Onorati
* Class: CPTS 122, Summer 2013
* Programming Assignment: 1
* Date: June 9th, 2013
* Description: Gets a string from the user and applies a Caesar shift cipher based on a 
*		shift determined by the user.
**************************************************************************************/

#include "CaesarShift.h"

int main(void)
{
	int shift = 0;
	char* pSentence = NULL;
	char* pEncrypted = NULL;

	pSentence = getSentence();
	shift = getShift();
	pEncrypted = caesarShiftCipher(pSentence, shift);

	puts("\nOriginal Sentence: ");
	puts(pSentence);
	puts("\nEncrypted Sentence: ");
	puts(pEncrypted);

	return 0;
}