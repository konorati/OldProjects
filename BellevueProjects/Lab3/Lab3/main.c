#include "lab3.h"

int main(void){

	FILE *inputFile = NULL, *outputFileStats = NULL, *outputFileAscii = NULL;
	char c1 = '\0', c2 = '\0', c3 = '\0', c4 = '\0', c5 = '\0', c6 = '\0', c7 = '\0', c8 = '\0', c9 = '\0', c10 = '\0';
	int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0, num7 = 0, num8 = 0, num9 = 0, num10 = 0, numLines = 0, 
		numVowels = 0, numDigits = 0, numAlpha = 0, numLower = 0, numUpper = 0, numSpace = 0, numAlnum = 0, numPunct = 0;

	inputFile = openInputFile();
	outputFileStats = fopen("output_stats.dat", "w");
	outputFileAscii = fopen("output_ascii.dat", "w");

	if (inputFile != NULL && outputFileStats != NULL && outputFileAscii != NULL){
		c1 = readCharacter(inputFile);
		c2 = readCharacter(inputFile);
		c3 = readCharacter(inputFile);
		c4 = readCharacter(inputFile);
		c5 = readCharacter(inputFile);
		c6 = readCharacter(inputFile);
		c7 = readCharacter(inputFile);
		c8 = readCharacter(inputFile);
		c9 = readCharacter(inputFile);
		c10 = readCharacter(inputFile);

		num1 = determineAsciiValue(c1);
		num2 = determineAsciiValue(c2);
		num3 = determineAsciiValue(c3);
		num4 = determineAsciiValue(c4);
		num5 = determineAsciiValue(c5);
		num6 = determineAsciiValue(c6);
		num7 = determineAsciiValue(c7);
		num8 = determineAsciiValue(c8);
		num9 = determineAsciiValue(c9);
		num10 = determineAsciiValue(c10);

		printInt(outputFileAscii, num1);
		printInt(outputFileAscii, num2);
		printInt(outputFileAscii, num3);
		printInt(outputFileAscii, num4);
		printInt(outputFileAscii, num5);
		printInt(outputFileAscii, num6);
		printInt(outputFileAscii, num7);
		printInt(outputFileAscii, num8);
		printInt(outputFileAscii, num9);
		printInt(outputFileAscii, num10);

		numLines = numberLines(c1, numLines);
		numLines = numberLines(c2, numLines);
		numLines = numberLines(c3, numLines);
		numLines = numberLines(c4, numLines);
		numLines = numberLines(c5, numLines);
		numLines = numberLines(c6, numLines);
		numLines = numberLines(c7, numLines);
		numLines = numberLines(c8, numLines);
		numLines = numberLines(c9, numLines);
		numLines = numberLines(c10, numLines);
		printStats(outputFileStats, "Number Lines: ", numLines);

		numVowels = numberVowels(c1, numVowels);
		numVowels = numberVowels(c2, numVowels);
		numVowels = numberVowels(c3, numVowels);
		numVowels = numberVowels(c4, numVowels);
		numVowels = numberVowels(c5, numVowels);
		numVowels = numberVowels(c6, numVowels);
		numVowels = numberVowels(c7, numVowels);
		numVowels = numberVowels(c8, numVowels);
		numVowels = numberVowels(c9, numVowels);
		numVowels = numberVowels(c10, numVowels);
		printStats(outputFileStats, "Number Vowels: ", numVowels);

		numDigits = numberDigits(c1, numDigits);
		numDigits = numberDigits(c2, numDigits);
		numDigits = numberDigits(c3, numDigits);
		numDigits = numberDigits(c4, numDigits);
		numDigits = numberDigits(c5, numDigits);
		numDigits = numberDigits(c6, numDigits);
		numDigits = numberDigits(c7, numDigits);
		numDigits = numberDigits(c8, numDigits);
		numDigits = numberDigits(c9, numDigits);
		numDigits = numberDigits(c10, numDigits);
		printStats(outputFileStats, "Number Digits: ", numDigits);
			
		numAlpha = numberAlphas(c1, numAlpha);
		numAlpha = numberAlphas(c2, numAlpha);
		numAlpha = numberAlphas(c3, numAlpha);
		numAlpha = numberAlphas(c4, numAlpha);
		numAlpha = numberAlphas(c5, numAlpha);
		numAlpha = numberAlphas(c6, numAlpha);
		numAlpha = numberAlphas(c7, numAlpha);
		numAlpha = numberAlphas(c8, numAlpha);
		numAlpha = numberAlphas(c9, numAlpha);
		numAlpha = numberAlphas(c10, numAlpha);
		printStats(outputFileStats, "Number Alpha Characters: ", numAlpha);

		numLower = numberLowers(c1, numLower);
		numLower = numberLowers(c2, numLower);
		numLower = numberLowers(c3, numLower);
		numLower = numberLowers(c4, numLower);
		numLower = numberLowers(c5, numLower);
		numLower = numberLowers(c6, numLower);
		numLower = numberLowers(c7, numLower);
		numLower = numberLowers(c8, numLower);
		numLower = numberLowers(c9, numLower);
		numLower = numberLowers(c10, numLower);
		printStats(outputFileStats, "Number Lowercase Characters: ", numLower);

		numUpper = numberUppers(c1, numUpper);
		numUpper = numberUppers(c2, numUpper);
		numUpper = numberUppers(c3, numUpper);
		numUpper = numberUppers(c4, numUpper);
		numUpper = numberUppers(c5, numUpper);
		numUpper = numberUppers(c6, numUpper);
		numUpper = numberUppers(c7, numUpper);
		numUpper = numberUppers(c8, numUpper);
		numUpper = numberUppers(c9, numUpper);
		numUpper = numberUppers(c10, numUpper);
		printStats(outputFileStats, "Number Uppercase Characters: ", numUpper);

		numSpace = numberSpaces(c1, numSpace);
		numSpace = numberSpaces(c2, numSpace);
		numSpace = numberSpaces(c3, numSpace);
		numSpace = numberSpaces(c4, numSpace);
		numSpace = numberSpaces(c5, numSpace);
		numSpace = numberSpaces(c6, numSpace);
		numSpace = numberSpaces(c7, numSpace);
		numSpace = numberSpaces(c8, numSpace);
		numSpace = numberSpaces(c9, numSpace);
		numSpace = numberSpaces(c10, numSpace);
		printStats(outputFileStats, "Number Whitespaces: ", numSpace);
			
		numAlnum = numberAlnums(c1, numAlnum);
		numAlnum = numberAlnums(c2, numAlnum);
		numAlnum = numberAlnums(c3, numAlnum);
		numAlnum = numberAlnums(c4, numAlnum);
		numAlnum = numberAlnums(c5, numAlnum);
		numAlnum = numberAlnums(c6, numAlnum);
		numAlnum = numberAlnums(c7, numAlnum);
		numAlnum = numberAlnums(c8, numAlnum);
		numAlnum = numberAlnums(c9, numAlnum);
		numAlnum = numberAlnums(c10, numAlnum);
		printStats(outputFileStats, "Number Alphanumeric Characters: ", numAlnum);

		numPunct = numberPuncts(c1, numPunct);
		numPunct = numberPuncts(c2, numPunct);
		numPunct = numberPuncts(c3, numPunct);
		numPunct = numberPuncts(c4, numPunct);
		numPunct = numberPuncts(c5, numPunct);
		numPunct = numberPuncts(c6, numPunct);
		numPunct = numberPuncts(c7, numPunct);
		numPunct = numberPuncts(c8, numPunct);
		numPunct = numberPuncts(c9, numPunct);
		numPunct = numberPuncts(c10, numPunct);
		printStats(outputFileStats, "Number Punctuation Characters: ", numPunct);

		fclose(inputFile);
		fclose(outputFileAscii);
		fclose(outputFileStats);
	}

	return 0;
}