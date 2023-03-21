#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree{
	int price, level;
	char modelName[100];
	struct tree *left, *right;
};

struct tree *successor(struct tree *root) {
	// di subtree kanan, ambil nilai terkecil
	
	struct tree *cur = root->right;
	while(cur->left != NULL) {
		cur = cur->left;
	}
	return cur;
}

struct tree *predecessor(struct tree *root) {
	// di subtree kiri, ambil nilai terbesar
	
	struct tree *cur = root->left;
	while(cur->right != NULL) {
		cur = cur->right;
	}
	return cur;
}

struct tree *newNode(int price, char modelName[], int level) {
	struct tree *curNewNode =
			(struct tree*)malloc(sizeof(struct tree));
			
	curNewNode->price = price;
	strcpy(curNewNode->modelName, modelName);
	curNewNode->level = level;
	curNewNode->left = NULL;
	curNewNode->right = NULL;
	
	return curNewNode;
}

//insert function
struct tree *insert(struct tree *root, char modelName[], int price, int level) {
	if (root == NULL){
		puts("\n--- Add New Phone Success ---");
		return newNode(price, modelName, level);
	}
	else if (strcmp(root->modelName, modelName) < 0) {
		//assign levels on every node
		if (level < 4){
			root->left = insert(root->left, modelName, price, level + 1);	
		}
		else{
			puts("\n--- Maximum Tree Level is 4 ---");
		}
	}
	else if (strcmp(root->modelName, modelName) > 0) {
		if (level < 4){
			root->right = insert(root->right, modelName, price, level + 1);	
		}
		else{
			puts("\n--- Maximum Tree Level is 4 ---");
		}
	}
	else{
		puts("\n--- Add New Phone Failure ---");
		printf("Err: Phone Code Already Exists\n");
	}
	return root;
}

int search(struct tree *root, char modelName[]) {
	if (root == NULL) return 0;
	if (strcmp(root->modelName, modelName) < 0) {
		search(root->left, modelName);
	}
	else if (strcmp(root->modelName, modelName) > 0) {
		search(root->right, modelName);
	}
	else{
		return 1;
	}
	//return True;
}

struct tree *deleteValue(struct tree *root, char modelName[]) {
	if (root == NULL) return NULL; // tidak ketemu...
	if (strcmp(root->modelName, modelName) < 0) {
		root->left = deleteValue(root->left, modelName);
	} else if (strcmp(root->modelName, modelName) > 0) {
		root->right = deleteValue(root->right, modelName);
	} else {
		
		// ketemu. mari kita mulai delete...
		
		// case 1 : tidak punya anak
		// case 2 : hanya punya anak kiri
		// case 3 : hanya punya anak kanan
		if ((root->left == NULL) || (root->right == NULL)) {
			
			struct tree *temp = NULL;
			if (root->left != NULL) temp = root->left;
			else temp = root->right;
			
			if (temp == NULL) {
				// pasti tidak punya anak
				// ini adalah case 1
				temp = root;
				root = NULL;
			} else {
				// ini adalah case 2 dan case 3
				*root = *temp;
			}
			free(temp);
			
		} else {
			// ini case ke 4
			// ada 2 anak, maka kita ambil suksesor/predesesor
			// terserah
			
			struct tree *temp = predecessor(root);
			strcpy(root->modelName, temp->modelName);
			
			// delete
			root->left = deleteValue(root->left, temp->modelName);
		}
	}
	return root;
}

void printPre(struct tree *root) {
	if (root == NULL) return;
	printf(" - %s [$ %d]\n", root->modelName, root->price);
	printPre(root->left);
	printPre(root->right);
}

void printIn(struct tree *root) {
	if (root == NULL) return;
	printIn(root->left);
	printf(" - %s [$ %d]\n", root->modelName, root->price);
	printIn(root->right);
}

void printPost(struct tree *root) {
	if (root == NULL) return;
	printPost(root->left);
	printPost(root->right);
	printf(" - %s [$ %d]\n", root->modelName, root->price);
}

struct tree *freeAll(struct tree *root) {
	if (root == NULL) return NULL;
	root->left = freeAll(root->left);
	root->right = freeAll(root->right);
	free(root);
	return NULL;
}

void menu(){
	int i = 0;
	char title[] = "NOKIYEM CELLULAR PHONE";
	int percent = strlen(title);
	
	puts(title);
	for (i = 0; i < percent; i++){
		printf("%%");
	}
	puts("\n");
	puts("1. Add new phone");
	puts("2. Update phone price");
	puts("3. InOrder, PreOrder, PostOrder");
	puts("4. Exit");
	puts("");
}

int main(){
	struct tree *root = NULL;
	/*
	//insert
	puts("Normal insert");
	root = insert(root, "N12345", 69);
	root = insert(root, "N23456", 70);
	root = insert(root, "N45678", 80);
	
	printAll(root);
	puts("");
	//insert duplicate
	puts("Duplicate insert");
	root = insert(root, "N12345", 71);
	
	printAll(root);
	puts("");
	//delete
	puts("Delete Model Name N45678");
	root = deleteValue(root, "N45678");
	printAll(root);
	puts("");
	//update info
	puts("Update info");
	root = deleteValue(root, "N12345");
	root = insert(root, "N12345", 96);
	printAll(root);
	puts("");
	*/
	
	char name[5];
	int price = 0;
	int input = 0;
	bool check;
	int level = 1;
	int flag = 0;
	
	do{
		//system("cls");
		menu();
		printf(">> Input choice: ");scanf("%d", &input);
		switch(input){
			case 1:
				do{
					
					printf("Input phone code N[1-9][0-9][0-9][0-9]: ");
					scanf("%s", name); getchar();
					/*
					if (temp1 == comp1){
						if (temp2 > comp2){
							flag = 1;
						}
					}*/
				}while((name[0] != 'N') || (name[1] == '0') || (strlen(name) != 5));
				puts("");
				do{
					printf("Input phone price [$50...$999]: $");
					scanf("%d", &price);
				}while((price < 50) || (price > 999));
				/*
				check = search(root, name);
				puts("");
				if ((check == 1) && (insert(root, name, price, level) == 2)){
					puts("--- Add New Phone Failure ---");
				}
				else{
					puts("--- Add New Phone Success ---");
				}*/
				root = insert(root, name, price, level);
				getchar();
				break;
			
			case 2:
				do{
					
					printf("Input phone code N[1-9][0-9][0-9][0-9]: ");
					scanf("%s", name); getchar();
					/*
					if (temp1 == comp1){
						if (temp2 > comp2){
							flag = 1;
						}
					}*/
				}while((name[0] != 'N') || (name[1] == '0') || (strlen(name) != 5));
				check = search(root, name);
				if (check == 1){
					printf("Phone Code\t: %s\n", root->modelName);
					printf("Phone Price\t: $ %d\n", root->price);
					puts("");
					do{
						printf("Input phone price [$50...$999]: $");
						scanf("%d", &price);
					}while((price < 50) || (price > 999));
					root = deleteValue(root, name);
					root = insert(root, name, price, level);
					puts("\n");
					puts("--- Update Phone Price Success ---");
					getchar();
					break;
				}
				else{
					puts("\n");
					puts("--- Phone Code is Not Found ---");
					break;
				}
			
			case 3:
				system("cls");
				puts("Inrder\t\t:");
				//getchar();
				printIn(root);
				puts("");
				puts("PreOrder\t:");
				//getchar();
				printPre(root);
				puts("");
				puts("PostOrder\t:");
				getchar();
				printPost(root);
				puts("");
				break;
			default:
				break;
			
		}
		getchar();
		system("cls");	
	}while (input != 4);
	return 0;
}
