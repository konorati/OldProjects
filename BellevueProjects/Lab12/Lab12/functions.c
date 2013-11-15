#include "functions.h"

int recursiveDigitAdd(int num){
	if(num < 10){
		return num;
	}
	else{
		return (num%10 + recursiveDigitAdd(num/10)); 
	}
}

void recursiveStringReverse(char *word, int start, int end){
	char temp = '\0';
	if(start <= end){
		temp = word[start];
		word[start] = word[end];
		word[end] = temp;
		recursiveStringReverse(word, start+1, end-1);
	}
}

void towerOfHanoi(int num, char start, char mid, char end){
	if(num == 0){

	}
	else{
		towerOfHanoi(num-1, start, end, mid);
		printf("Move disk %d to peg %c\n", num, end);
		towerOfHanoi(num-1, mid, start, end);
	}
}

Node* makeNode(char *data){
	Node *mem_ptr = (Node*)malloc(sizeof(Node));
	strcpy(mem_ptr->data, data);
	mem_ptr->next = NULL;
	return mem_ptr;
}

void insertAtFront(Node **head, char *data){
	Node *memPtr = NULL;
	memPtr = makeNode(data); //Make a new node and return pointer to that node
	if(*head == NULL){
		*head = memPtr;
	}
	else{
		memPtr->next = *head;
		*head = memPtr;
	}
}