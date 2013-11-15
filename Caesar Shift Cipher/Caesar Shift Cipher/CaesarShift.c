#include "CaesarShift.h"

/*************************************************************************
* Date last modified: June 9th, 2013
* Description: Gets string from user
* Input parameters: 
* Returns: Character pointer to string (memory allocated dynamically)
* Precondition:  
* Postcondition: Pointer to valid string
*************************************************************************/
char* getSentence(void)
{
	char* pSentence = NULL;
	char sentence[500];

	puts("Enter a string for encryption: ");
	gets(sentence);

	pSentence = (char*)malloc(sizeof(char)*(strlen(sentence)+1));
	strcpy(pSentence, sentence);
	
	return pSentence;
}

/*************************************************************************
* Date last modified: June 9th, 2013
* Description: Gets integer shift value from user (can be positive or negative)
* Input parameters: 
* Returns: integer shift value
* Precondition:  
* Postcondition: Returns positive or negative integer
*************************************************************************/
int getShift(void)
{
	int shift = 0;

	puts("What shift value would you like to use for the cipher? ");
	scanf("%d", &shift);

	return shift;
}

/*************************************************************************
* Date last modified: June 9th, 2013
* Description: Creates new string containing encrypted version of string 
*	passed into the function
* Input parameters: String, integer shift value
* Returns: Encrypted string
* Precondition: Pointer passed in points to valid string 
* Postcondition: Returns pointer to valid string containing shifted values
*************************************************************************/
char* caesarShiftCipher(char* str, int shift)
{
	char *pShiftedStr = NULL;
	char shiftedStr[250];
	int i = 0;

	for(i = 0; i <= strlen(str); i++)
	{
		if(isalpha(str[i]))
		{
			shiftedStr[i] = applyShift(str[i], shift);
		}
		else
		{
			shiftedStr[i] = str[i];
		}
	}
	
	pShiftedStr = (char*)malloc(sizeof(char)*(strlen(shiftedStr)+1));
	strcpy(pShiftedStr, shiftedStr);

	return pShiftedStr;
}

/*************************************************************************
* Date last modified: June 9th, 2013
* Description: Applies shift to individual character
* Input parameters: Character, integer shift value
* Returns: Shifted character (uppercase)
* Precondition: Character passed in must be alphabetic character
* Postcondition: Shifted alphabetic character is returned
*************************************************************************/
char applyShift(char letter, int shift)
{
	char shiftedLetter = '\0';

	letter = toupper(letter);
	shiftedLetter = ((letter - 65 + shift) % 26);
	if(shiftedLetter < 0) //If negative wrap around to end of alphabet
	{
		shiftedLetter += 26;
	}
	shiftedLetter += 65;

	return shiftedLetter;
}