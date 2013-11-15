/*************************************************************************************
* Programmer: Kristin Onorati
* Class: CPTS 122, Summer 2013
* Programming Assignment: 1
* Date: June 9th, 2013
* Description: Gets a string from the user and determines if string is a palindrome
**************************************************************************************/

#include "palindrome.h"

int main(void)
{
	char* word = NULL;
	Boolean isPalindrome = FALSE;
	
	word = getWord();
	isPalindrome = recursivePalindrome(word, 0, strlen(word));
	if(isPalindrome)
	{
		printf("%s\nis a palindrome\n", word);
	}
	else
	{
		printf("%s\nis not a palindrome\n", word);
	}


	return 0;
}