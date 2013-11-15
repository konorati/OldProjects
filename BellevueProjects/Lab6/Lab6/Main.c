#include "Functions.h"



int main(){
	FILE *infile = NULL;
	int num = 0, numWin = 0, sum = 0, correct = 0, divisor = 10, prime = 0, factorialNum = 0, num2 = 0;
	/*
	//TASK 1
	infile = fopen("data.txt", "r");

	while (!(feof(infile))){
		num = readInt(infile);
		sum += num;
	}
	printf("Sum = %d", sum);

	if (isPrime(sum)){
		printf("Sum is not prime\n");
	}
	else {
		printf("Sum is prime\n");
	}
	while (sum != 0){
		num = sum % divisor;
		prime = isPrime(num);
		divisor *= 10;
		sum -= num;
	}
	if(prime = 0){
		printf("All digits are prime\n");
	}
	else{
		printf("One or more digits are not prime\n");
	}
	*/

	
	//TASK 2
	/*printf("Enter a number to find it's factorial value: ");
	scanf("%d", &num);
	factorialNum = factorial(num);
	printf("The factorial of %d is %d\n", num, factorialNum);
	*/

	//TASK 3
	printf("Enter a number to find the fibonacci number for the nth term: ");
	scanf("%d", &num);
	num2 = fib(num);
	printf("Fibonacci number for term number %d is %d\n", num, num2);

	//TASK 4
	/*srand((unsigned int) time(NULL));
	numWin = (rand() % 201) - 100;
	do {
		printf("Guess a number between -100 and 100: ");
		scanf("%d", &num);
		
		correct = numGuess(num, numWin);
		
	}while(correct != 0);
	printf("Winning number is %d", numWin);*/

	




	return 0;
}