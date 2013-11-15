#include "functions.h"


int isPalindrome (char *str, int i, int j){
	for(;!isalnum(str[i]); i++);
	for(;!isalnum(str[j]); j--);
	if(i>j){
		return 1;
	}
	else if(tolower(str[i]) != tolower(str[j])){
		return 0;
	}
	else{
		isPalindrome(str, i+1, j-1);
	}
}

void printBinaryNum(char *str){
	char str1[100], str2[100];
	int index = -1;
	if(!(is_element(str, 'x'))){
		printf("%s\n", str);
	}
	else{
		strcpy(str1, str);
		strcpy(str2, str);
		index = locationOfElement(str, 'x');
		str1[index] = '1';
		str2[index] = '0';
		printBinaryNum(str1);
		printBinaryNum(str2);
	}
}

int is_element(char *str, char letter){
	int element = 0, i = 0;
	for(i = 0; i < strlen(str); i++){
		if(str[i] == letter){
			element = 1;
		}
	}
	return element;
}

int locationOfElement(char *str, char letter){
	int location = -1, i = 0;
	while(location == -1){
		if(str[i] == letter){
			location = i;
		}
		else{
			i++;
		}
	}
	return location;
}

int gcd(int num1, int num2, int numd){
	if((num1%numd + num2%numd) == 0){
		return numd;
	}
	else{
		gcd(num1, num2, numd-1);
	}

}

int gcd2(int num1, int num2){
	
	
	if(num2 == 0){
		return num1;
	}
	else{
		return gcd2(num2, num1%num2);
	}
}

int swapNum(int x, int y){
	x = x+y;
	y = x-y;
	x = x-y;
	
}