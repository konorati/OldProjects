#ifndef CAESAR_SHIFT_H
#define CAESAR_SHIFT_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* getSentence(void);
int getShift(void);
char* caesarShiftCipher(char* str, int shift);
char applyShift(char letter, int shift);

#endif