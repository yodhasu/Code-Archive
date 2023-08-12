#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct backpack{
	char itemID[100];
	int val;
	struct backpack *next;
	struct backpack *prev;
} *head, *tail, *curr;

void inputItem(char item[], int amm){
	struct backpack *newItem = (struct backpack*) malloc(sizeof(struct backpack));
	newItem->val = amm;
	strcpy(newItem->itemID, item);
	
	if(head == NULL){
		head = tail = newItem;
		head->prev = NULL;
		tail->next = NULL;
	}
	else{
		//int flag = 0;
		curr = head;
		while(strcmp(curr->itemID, item) != 0){
			curr = curr->next;
			if(curr == NULL){
				curr = tail;
				//printf("Item not found!/n");
				break;
			}
		}
		if(strcmp(curr->itemID, item) == 0){
			curr->val += amm;
		}
		else{
			tail->next = newItem;
			newItem->prev = tail;
			tail = newItem;
			tail->next = NULL;
		}
	}
}
/*
void addAmmount(char item[]){
	curr = head;
	while(strcmp(curr->itemID, item) != 0){
		curr = curr->next;
		if(curr == NULL){
			printf("Item not found!/n");
			return;
		}
	}
	if(strcmp(curr->itemID, item) == 0){
		curr->val++;
	}
}*/

void delAll(){
	while(head != NULL){
		curr = head;
		head = head->next;
		free(curr);
	}
}

void delHead(){
	if(head == NULL){
		printf("Backpack empty!\n");
		//return;
	}
	else{
		if(head == tail){
			free(head);
			free(tail);
		}
		else{
			curr = head;
			head = head->next;
			free(curr);
			head->prev = NULL;
		}
	}
}

void delTail(){
	if(head == NULL){
		printf("Backpack empty!\n");
		//return;
	}
	else{
		if(head == tail){
			free(head);
			free(tail);
		}
		else{
			curr = tail;
			tail = tail->prev;
			free(curr);
			tail->next = NULL;
		}
	}
}

int delSelect(char item[]){
	int deleted = 0;
	curr = head;
	while(strcmp(curr->itemID, item) != 0){
		curr = curr->next;
		if(curr == NULL){
			return deleted;
		}
	}
	if (curr->val > 1){
		curr->val -= 1;
	} else{
		if(head == tail){
			free(head);
			free(tail);
			head = NULL;
			tail = NULL;
			
		}
		else if(curr == head){
			delHead();
		}
		else if(curr == tail){
			delTail();
		}
		else{
			//struct backpack *del = curr;
			curr->prev->next = curr->next;
			free(curr);
		}
	}
	return deleted = 1;
}


void openBackpack(int open){
	if(open != 0){
		int count = 1;
		curr = head;
		if(head == NULL){
			printf("Backpack is empty!\n");
			return;
		}
		printf("No. \tItem Ammount\t\tItem ID\n\n");
		while(curr != NULL){
			printf("%d.\t%d\t\t\t%s\n\n", count, curr->val, curr->itemID);
			curr = curr->next;
			count++;
		}
	}
}

void openBackpackReverse(int open){
	if(open != 0){
		int count = 1;
		curr = tail;
		if(tail == NULL or head == NULL){
			printf("Backpack is empty!\n");
			return;
		}
		printf("No. \tItem Ammount\t\tItem ID\n\n");
		while(curr != NULL){
			printf("%d.\t%d\t\t\t%s\n\n", count, curr->val, curr->itemID);
			curr = curr->prev;
			count++;
		}
	}
}

void menu(){
	printf("1. Add Items\n");
	printf("2. Open/CloseBackpack\n");
	printf("3. Del select\n");
	printf("4. Reverse Backpack List\n");
	printf("5. Exit\n");
}

int main(){
	/*
	inputItem("dirt");
	inputItem("swordWooden");
	inputItem("dirt");
	inputItem("dirt");
	inputItem("iron");
	//itemSearch("dirt");
	//inputItem("dirt");
	openBackpack();
	*/
	
	int delstatus;
	int input;
	int count = 0;
	int open = 0;
	int flag = 0;
	char itemID[100];
	int itemAmmount;
	
	do{
		if(count == 20){
			puts("Backpack is full!");
		}
		printf("Backpack menu:\n");
		if(flag == 0){
			openBackpack(open);
		}
		else{
			openBackpackReverse(open);
		}
		printf("Item in backpack: %d\n\n", count);
		menu();
		printf("Input menu: ");
		scanf("%d", &input);
		switch(input){
			case 1:
				if (count == 20){
					puts("Backpack is full!"); getchar();
					break;
				}
				printf("Input item ID: ");
				scanf("%s", &itemID);getchar();
				for (int i = 0; i < strlen(itemID); i++){
					itemID[i] = tolower(itemID[i]);
				}
				printf("Input ammount: ");
				scanf("%d", &itemAmmount);
				count = count + itemAmmount;
				if (count > 20){
					printf("Input failed! Backpack is full!");
					count -= itemAmmount;
					getchar();
					break;
				}
				inputItem(itemID, itemAmmount);
				printf("Item added!\n");
				
				getchar();
				break;
			case 2:
				if(open == 0){
					open = 1;
					break;
				}
				else{
					open = 0;
					break;
				}
				break;
			case 3:
				if (count == 0){
					puts("Backpack is empty!"); getchar();
					
					break;
				}
				printf("Input item ID: ");
				scanf("%s", &itemID);getchar();
				delstatus = delSelect(itemID);
				if (delstatus != 0){
					puts("Item deleted!");
					count--;
					getchar();
					break;
				} else{
					puts("Item not exist!");
					getchar();
					break;
				}
			case 4:
				if(flag == 0){
					flag = 1;
					break;
				}
				else{
					flag = 0;
					break;
				}
			case 5:
				return 0;
			default:
				break;
		}
		system("cls");
		
	}while(input != 5);
	
	
	return 0;
}
