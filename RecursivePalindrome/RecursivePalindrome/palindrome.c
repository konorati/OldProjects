#include "palindrome.h"

/*************************************************************************
* Date last modified: June 9th, 2013
* Description: Determines if string provided by user is a palindrome,
*	ignoring non alphabetic characters
* Input parameters: String, placement of starting character (integer), 
*	placement of ending character (integer)
* Returns: Boolean True if string is a palindrome, False if not
* Precondition: Pointer points to valid string, start and end are within 
*	valid range for string
* Postcondition: True or False is returned
*************************************************************************/
Boolean recursivePalindrome(char* word, int start, int end)
{
	Boolean palindrome = TRUE;
	char cOne = '\0', cTwo = '\0';

	if(start < end) //If entire string has not been compared
	{
		cOne = word[start];
		cTwo = word[end];
		while(!isalpha(cOne)) //Find next alphabetic character from the beginning of the string
		{
			cOne = word[++start];
		}
		while(!isalpha(cTwo)) //Find next alphabetic character from the end of the string
		{
			cTwo = word[--end];
		}
		if(tolower(cOne) != tolower(cTwo))
		{
			palindrome =  FALSE;
		}
		else
		{
			palindrome = recursivePalindrome(word, start+1, end-1);
		}
	}
	else //If you reach this point, entire string has been compared and string must be a palindrome
	{
		palindrome = TRUE;
	}
	return palindrome;
}

/*************************************************************************
* Date last modified: June 9th, 2013
* Description: Gets string from user
* Input parameters: 
* Returns: Character pointer to string (memory allocated dynamically)
* Precondition:  
* Postcondition: Pointer to valid string is returned
*************************************************************************/
char* getWord(void)
{
	char* pWord = NULL;
	char word[200];

	puts("Enter a word/sentence to check if it is a palindrome: ");
	gets(word);
	pWord = (char*)malloc(sizeof(char)*(strlen(word)+1));
	strcpy(pWord, word);

	return pWord;
}