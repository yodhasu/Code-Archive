#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct items{
	char name[100];
	int val;
	struct items *next, *prev;
}*head, *tail, *curr;

void createTail(int value, char id[]){
	struct items *newItems = (items*)malloc(sizeof(items));
	
	newItems->val = value;
	strcpy(newItems->name, id);
	
	if (head == NULL){
		head = tail = newItems;
		head->prev = NULL;
		tail->next = NULL;
	}
	else{
		tail->next = newItems;
		newItems->prev = tail;
		tail = newItems;
		tail->next = NULL;
	}
	return;
}

void printAll(){
	curr = head;
	if (head == NULL){
		puts("No data.");
		return;
	}
	else{	
		while(curr != NULL){
			printf("%s - %d", curr->name, curr->val);
			curr = curr->next;
		}
	}
	return;
}

int main(){
	char name[100];
	int ammount;
	createTail(1, "Nasi");
	
	createTail(1, "Ayam");
	
	createTail(1, "Sambal");
	
	createTail(1, "Air");
	
	printAll();
	
	
	return 0;
}
