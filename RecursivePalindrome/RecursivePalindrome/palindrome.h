#ifndef PALINDROME_H
#define PALINDROME_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef enum 
{
	FALSE, TRUE
} Boolean;

Boolean recursivePalindrome(char* word, int start, int end);
char* getWord(void);

#endif