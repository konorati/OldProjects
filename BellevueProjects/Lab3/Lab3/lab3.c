#include "lab3.h"

//Opens "input.dat" for reading
FILE *openInputFile(void){
	FILE *file = NULL;
	file = fopen("input.dat", "r");
	return file;
}

//Reads one character from the input file
char readCharacter(FILE *infile){
	char character = '\0';
	fscanf(infile, "%c", &character);
	return character;
}

//Returns the ASCII value of the character passed into the function
int determineAsciiValue(char character){
	int numChar = 0;
	numChar = (int)character;
	return numChar;
}

//Determines if the character is a newline. If the character is a newline a 1 is retured otherwise a 0 is returned.
int isLine(char character){
	if (character == '\n'){
		return NEWLINE;
	}
	else {
		return NOT_NEWLINE; 
	}
}

//Determines if the characer passed into the function indicates the end of a line
//if so function adds 1 to the current number of lines
int numberLines(char character, int currentNumberLines){
	if(isLine(character)){
		currentNumberLines++;
	}
	return currentNumberLines;
}

//Determines if the character is a vowel, if character is a vowel 2 is return if not a 0 is returned
int isVowel(char character){
	if((character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u' 
			|| character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U')){
		return ALPHA;
	}
	else{
		return NOT_ALPHA;
	}
}

//Determines if the character passed into the function is a vowel, if so adds 1 to current number of vowels
int numberVowels(char character, int currentNumberVowels){
	if(isVowel(character)){
		currentNumberVowels++;
	}
	return currentNumberVowels;
}

//Determines if character is a digit, if it is a digit 3 is returned, otherwise 0 is returned
int isDigit(char character){
	int numChar = 0;
	numChar = (int)character;
	if(numChar >= 48 && numChar <= 57){
		return DIGIT;
	}
	else{
		return NOT_DIGIT;
	}
}

//Determines if the character is a digit, if so adds 1 to current number of digits
int numberDigits(char character, int currentNumberDigits){
	if(isDigit(character)){
		currentNumberDigits++;
	}
	return currentNumberDigits;
}

//Determines if character is an alpha character, if so a 4 is returned otherwise a 0 is returned
int isAlpha(char character){
	int numChar = 0;
	numChar = (int)character;
	if((numChar >= 65 && numChar <=90) || (numChar >= 97 && numChar <= 122)){
		return ALPHA;
	}
	else{
		return NOT_ALPHA;
	}
}
//Determines if the character is an alpha character, if so adds 1 to current number of alpha characters
int numberAlphas(char character, int currentNumberAlphas){
	if(isAlpha(character)){
		currentNumberAlphas++;
	}
	return currentNumberAlphas;
}

//Determines if the character is an uppercase character, if so returns 6, otherwise returns 0
int isUpper(char character){
	int numChar = 0;
	numChar = (int)character;
	if(numChar >= 65 && numChar <= 90){
		return UPPER;
	}
	else{
		return NOT_UPPER;
	}
}

//Determines if the character is an uppercase character, if so adds 1 to current number of uppercase characters
int numberUppers(char character, int currentNumberUppers){
	if(isUpper(character)){
		currentNumberUppers++;
	}
	return currentNumberUppers;
}

//Determines if the character is a lowercase character, if so returns 5, otherwise returns 0
int isLower(char character){
	int numChar = 0;
	numChar = (int)character;
	if(numChar >= 97 && numChar <= 122){
		return LOWER;
	}
	else{
		return NOT_LOWER;
	}
}

//Determines if the character is an lowercase character, if so adds 1 to current number of lowercase characters
int numberLowers(char character, int currentNumberLowers){
	if(isLower(character)){
		currentNumberLowers++;
	}
	return currentNumberLowers;
}

//Determines if the character is whitespace, if so returns 7, otherwise returns 0
int isSpace(char character){
	int numChar = 0;
	numChar = (int)character;
	if(numChar == 32 || (numChar >= 9 && numChar <= 13) ){
		return WHITESPACE;
	}
	else{
		return NOT_WHITESPACE;
	}
}

//Determines if the character is a whitespace, if so adds 1 to current number of spaces
int numberSpaces(char character, int currentNumberSpaces){
	if(isSpace(character)){
		currentNumberSpaces++;
	}
	return currentNumberSpaces;
}

//Determines if the character is an alpha or digit character, if so returns 8, otherwise returns 0
int isAlnum(char character){
	int numChar = 0;
	numChar = (int)character;
	if(numChar >= 65 && numChar <= 90 || numChar >= 97 && numChar <= 122 || numChar >= 48 && numChar <= 57){
		return ALNUM;
	}
	else{
		return NOT_ALNUM;
	}
}

//Determines if the character is an alpha or digit character, if so adds 1 to current number of alnum characters
int numberAlnums(char character, int currentNumberAlnums){
	if(isAlnum(character)){
		currentNumberAlnums++;
	}
	return currentNumberAlnums;
}

//Determines if the character is an punctuation character, if so returns 9, otherwise returns 0
int isPunct(char character){
	int numChar = 0;
	numChar = (int)character;
	if(numChar == 33 || numChar == 44 || numChar == 46 || numChar == 58 || numChar == 59 || numChar == 63){
		return PUNCT;
	}
	else{
		return NOT_PUNCT;
	}
}

//Determines if the character is a punctuation character, if so adds 1 to current number of punct characters
int numberPuncts(char character, int currentNumberPuncts){
	if(isPunct(character)){
		currentNumberPuncts++;
	}
	return currentNumberPuncts;
}

//Prints an integer to an output file
//Precondition: File must already be open
void printInt(FILE *outfile, int number){

	fprintf(outfile, "%d\n", number);
}

//Prints a line to an output file
//Precondition: File must already be open
void printStats(FILE *outfile, char header[], int number){
	fprintf(outfile, "%s%d\n", header, number);
}
