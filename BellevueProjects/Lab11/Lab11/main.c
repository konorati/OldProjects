#include "functions.h"


int main(void){
	char word1[100] = "racecar ten";
	char word2[100] = "Go hang a salami, I'm a lasagna hog";
	char word3[100] = "Banana tub";
	int j = 0, pal = -1;

	pal = isPalindrome(word1, 0, strlen(word1));

	//printf("Palindrome = %d\n", pal);

	//printBinaryNum("xxxxxxxx");

	j = gcd2(132, 20);
	printf("Greatest common denominator = %d\n", j);

}