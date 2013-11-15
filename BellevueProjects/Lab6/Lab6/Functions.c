#include "Functions.h"

int readInt(FILE *infile){
	int num = 0;
	fscanf(infile, "%d", &num);
	return num;
}

int isPrime(int num){
	int prime = 0, multiple = 0, divisor = num-1;
	if(num < 0){
		num = -num;
	}
	while(divisor > 1 && prime == 0){
		if(num % divisor == 0){
			prime = 1;
		}
		divisor--;
	}
	return prime;
}

int numGuess(int num, int winner){
	int isWin = 0;
	if((num - winner) > 0){
		isWin = 1;
		printf("Your guess is too high\n");
	}
	else if((num - winner) < 0){
		isWin = -1;
		printf("Your guess is too low\n");
	}
	else if ((num - winner) == 0){
		isWin = 0;
		printf("You guessed the correct number!\n");
	}
	return isWin;
}

int factorial(int num){
	int sum = 1, i;
	for(i = 2; i <= num; i++){
		sum = sum*i;
	}
	return sum;
}

int fib(int num){
	if (num == 1)
	{
		return 1;
	}
	if (num == 0)
	{
		return 0;
	}
	return fib(num-2) + fib(num-1);
}