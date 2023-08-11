#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

struct node{
	char data[100];
	struct node *next;
}*hashTable[97], *curr;

// hashKey value will become the index in the hashTable
// data value will be stored in the hashTable
void pushBack(int hashKey, char data[]){
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	strcpy(newNode->data, data);
	newNode->next = NULL;
	
	// if the index is still empty
	if(hashTable[hashKey] == NULL){
		hashTable[hashKey] = newNode;
	}
	// if the index is not empty
	else{
		curr = hashTable[hashKey];
		while(curr->next != NULL) curr = curr->next;
		curr->next = newNode;
	}
}

void viewHashTable(){
	// ACCESS ALL INDEX 
	for(int i=0 ; i<97 ; i++){
		// CHECK WHETHER THE INDEX IS NULL OR NOT
		if(hashTable[i] != NULL){
			// PRINT ALL ELEMENTS / DATA IN THE INDEX
			printf("HASH TABLE INDEX [%d]:\n", i);
			curr = hashTable[i];
			while(curr != NULL){
				printf("%s ", curr->data);
				curr = curr->next;
			}
			printf("\n\n");
		}
	}
}

int countNum(int key){
	int count = 0;
	while (key != 0){
		key = key/10;
		count++;
	}
	return count;
}

int sumNum(int num){
	int sum = 0, m;
	while (num > 0){
		m = num % 10;
		sum = sum + m;
		num = num / 10;
	}
	return sum;
}

int hashFunction(int key){
	//int hashKey = -1;
	//char firstChar;
	// you can use method: division or mid-square or else
	// in this case, our rules is: a / A -> 0, b / B -> 1, c / C -> 2, and so on ...
	//firstChar = data[0];
	//hashKey = tolower(firstChar) - 97; // because ascii of a is 97	
	//return hashKey;
	int hashkey = -1, temp = 0;
	if (key < 10){
		hashkey = key;
	}
	else{
		temp = sumNum(key);
		if (temp > 97){
			temp = temp - 97;
		}
		hashkey = temp;
	}
	return hashkey;
}

int hashSearch(int key){
	//int hashKey = -1;
	//char firstChar;
	// you can use method: division or mid-square or else
	// in this case, our rules is: a / A -> 0, b / B -> 1, c / C -> 2, and so on ...
	//firstChar = data[0];
	//hashKey = tolower(firstChar) - 97; // because ascii of a is 97	
	//return hashKey;
	int index = 0, temp = 0;
	if (key < 10){
		index = key;
	}
	else{
		temp = sumNum(key);
		if (temp > 97){
			temp = temp - 97;
		}
		index = temp;
	}
	if (hashTable[index] != NULL){
		printf("HASH TABLE INDEX [%d]:\n", index);
		curr = hashTable[index];
		while(curr != NULL){
			printf("%s\n", curr->data);
			curr = curr->next;
		}
		printf("\n");
	}
	else{
		printf("Index empty!\n\n");
	}
}


void menu(){
	printf("1. Input data\n");
	printf("2. Search data\n");
	printf("3. Exit\n");
}

int main(){
	char data[100];
	int key;
	int input;
	/*
	do{
		printf("Input string data: ");
		scanf("%[^\n]", data); getchar();
		if(strcmpi(data, "exit") == 0) break;
		printf("Input Key data: ");
		scanf("%d", &key); getchar();
		
		pushBack(hashFunction(key), data);
	}while(true);
	//viewHashTable();
	//hashSearch(123);
	// pop all will be here
	*/
	do{
		printf("Menu\n");
		menu();
		printf("Input menu: ");
		scanf("%d", &input);
		switch(input){
			case 1:
				printf("Input string data: ");
				scanf("%s", &data); getchar();
				//getchar();
				//if(strcmpi(data, "exit") == 0) break;
				printf("Input Key data: ");
				scanf("%d", &key);
				pushBack(hashFunction(key), data);
				printf("Data added!\n\n");
				getchar();
				//system("cls");
				break;
			case 2:
				printf("Input key data: ");
				scanf("%d", &key);
				printf("==============================================\n");
				hashSearch(key);
				getchar();
				//system("cls");
				break;
			case 3:
				return 0;
			default:
				printf("Menu not available!\n");
				getchar();
				//system("cls");
				break;
		}
		//system("cls");
		
	}while (input != 3);
	//getchar();
	return 0;
}

