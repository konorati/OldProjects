#ifndef LAB3_H_INCLUDE
#define LAB3_H_INCLUDE

#include <stdio.h>

#define ALPHA 4
#define NOT_ALPHA 0
#define VOWEL 2
#define NOT_VOWEL 0
#define DIGIT 3
#define NOT_DIGIT 0
#define NEWLINE  1
#define NOT_NEWLINE 0
#define LOWER 5
#define NOT_LOWER 0
#define UPPER 6
#define NOT_UPPER 0
#define WHITESPACE 7
#define NOT_WHITESPACE 0
#define ALNUM 8
#define NOT_ALNUM 0
#define PUNCT 9
#define NOT_PUNCT 0

FILE *openInputFile(void);
char readCharacter(FILE *);
int determineAsciiValue(char);
int isLine(char);
int numberLines(char, int);
int isVowel(char);
int numberVowels(char, int);
int isDigit(char);
int numberDigits(char, int);
int isAlpha(char);
int numberAlphas(char, int);
int isLower(char);
int numberLowers(char, int);
int isUpper(char);
int numberUppers(char, int);
int isSpace(char);
int numberSpaces(char, int);
int isAlnum(char);
int numberAlnums(char, int);
int isPunct(char);
int numberPuncts(char, int);
void printInt(FILE *, int);
void printStats(FILE *, char [], int);

#endif