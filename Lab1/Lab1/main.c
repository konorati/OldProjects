#include "Functions.h"

int main(void)
{
	char str[100] = "";
	char listOne[][20] = {"banana", "apple", "coconut", "pineapple", "peach"};
	char listTwo[][20] = {"dog", "cat", "horse", "zebra", "giraffe", "pig"};
	char listThree[11][20] = {""};
	int i = 0;
	puts("Enter a string: ");
	gets(str);
	printf("Current string is: %s\n", str);
	reverseString(str, 0, strlen(str)-1);
	printf("Reversed string is: %s\n", str);

	mergeArrayFixedSize(listOne, 5, listTwo, 6, listThree);
	for(i = 0; i < 11; i++)
	{
		printf("%s\n", listThree[i]);
	}

	system("pause");

	return 0;
}