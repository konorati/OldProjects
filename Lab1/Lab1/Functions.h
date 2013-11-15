#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void reverseString(char* str, int start, int end);
void mergeArrayFixedSize(char listOne[][20], int sizeListOne, char listTwo[][20], int sizeListTwo, char sortedList[][20]);
void mergeArrayDynamicSize(char listOne[][20], int sizeListOne, char listTwo[][20], int sizeListTwo, char *sortedList);


#endif