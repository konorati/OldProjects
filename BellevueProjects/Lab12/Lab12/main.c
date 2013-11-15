#include "functions.h"

int main(void){
	int num = 0, digitAdd = 0;
	char *word = {"bananagram"};
	
	int *mem_ptr = NULL;
	Node *node_ptr = NULL;

	//malloc()
	mem_ptr = (int*)malloc(sizeof(int));
	*mem_ptr = 42;

	node_ptr = (Node*)malloc(sizeof(Node));
	strcpy(node_ptr->data, "tacos");
	node_ptr->next = (Node*)malloc(sizeof(Node));
	strcpy(node_ptr->next->data,  "Cheese");
	node_ptr->next->next = NULL;

	insertAtFront(&node_ptr, "eggs");

	
	
	/*printf("Enter an integer: ");
	scanf("%d", &num);
	digitAdd = recursiveDigitAdd(num);
	printf("Num is: %d, sum of digits is: %d\n", num, digitAdd);
	printf("Original word is: %s, ", word);
	recursiveStringReverse(word, 0, strlen(word)-1);
	printf("Reversed string is: %s\n", word);
	towerOfHanoi(3, 'a', 'b', 'c');*/

	return 0;
}