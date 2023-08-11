#include<stdio.h>
#include<stdlib.h>

struct node {
	int key;
	int height;
	struct node *left;
	struct node *right;
};

int max(int a, int b) {
	if (a < b) return b;
	else return a;
}

int getHeight(struct node *root) {
	if (root == NULL) return 0;
	return root->height;
}

int getBF(struct node *root) {
	if (root == NULL) return 0;
	return getHeight(root->left) - getHeight(root->right);
}

struct node *rightRotate(struct node *y) {
	struct node *x = y->left;
	struct node *B = x->right;
	
	x->right = y;
	y->left = B;
	
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	
	return x;
}

struct node *leftRotate(struct node *x) {
	struct node *y = x->right;
	struct node *B = y->left;
	
	y->left = x;
	x->right = B;
	
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	
	return y;
}


struct node *successor(struct node *root) {	
	struct node *cur = root->right;
	while(cur->left != NULL) {
		cur = cur->left;
	}
	return cur;
}

struct node *predecessor(struct node *root) {	
	struct node *cur = root->left;
	while(cur->right != NULL) {
		cur = cur->right;
	}
	return cur;
}

struct node *newNode(int x) {
	struct node *currNewNode =
			(struct node*)malloc(sizeof(struct node));
			
	currNewNode->key = x;
	currNewNode->height = 1;
	currNewNode->left = NULL;
	currNewNode->right = NULL;
	
	return currNewNode;
}

struct node *insert(struct node *root, int value) {
	if (root == NULL) return newNode(value);
	else if (value < root->key) {
		root->left = insert(root->left, value);
	} else {
		root->right = insert(root->right, value);
	}

	
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	int bfactor = getBF(root);
		
	if (bfactor > 1 && value < root->left->key) {
		return rightRotate(root);
	}
	if (bfactor < -1 && value > root->right->key) {
		return leftRotate(root);
	}
	if (bfactor > 1 && value > root->left->key) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	if (bfactor < -1 && value < root->right->key) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;	
}

struct node *deleteValue(struct node *root, int value) {
	if (root == NULL) return NULL; 
	if (value < root->key) {
		root->left = deleteValue(root->left, value);
	} else if (value > root->key) {
		root->right = deleteValue(root->right, value);
	} else {
		
		if ((root->left == NULL) || (root->right == NULL)) {
			
			struct node *temp = NULL;
			if (root->left != NULL) temp = root->left;
			else temp = root->right;
			
			if (temp == NULL) {
				temp = root;
				root = NULL;
			} else {
				*root = *temp;
			}
			free(temp);
			
		} else {
			
			struct node *temp = predecessor(root);
			root->key = temp->key;
			
			
			root->left = deleteValue(root->left, temp->key);
		}
	}

	if (root == NULL) return root;
	
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	int bfactor = getBF(root);
	
	if (bfactor > 1 && getBF(root->left) >= 0) {
		return rightRotate(root);
	}
	if (bfactor > 1 && getBF(root->left) < 0) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	if (bfactor < -1 && getBF(root->right) <= 0) {
		return leftRotate(root);
	}
	if (bfactor < -1 && getBF(root->right) > 0) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}


void preorder(struct node *root) {
	if (root == NULL) return;
	printf(" %d ", root->key);
	preorder(root->left);
	preorder(root->right);
}

void inorder(struct node *root) {
	if (root == NULL) return;
	inorder(root->left);
	printf(" %d ", root->key);
	inorder(root->right);
}

void postorder(struct node *root) {
	if (root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	printf(" %d ", root->key);
}

int search(struct node *root, int dat) {
	if (root == NULL) return 0;
	
	if (dat > root->key) {
		search(root->right, dat);
	} else if (dat < root->key) {
		search(root->left, dat);
	} else {
		return 1;
	}
	
}

struct node *freeAll(struct node *root) {
	if (root == NULL) return NULL;
	root->left = freeAll(root->left);
	root->right = freeAll(root->right);
	free(root);
	return NULL;
}

void menu() {
	puts("1. Insertion");
	puts("2. Deletion");
	puts("3. Transversal");
	puts("4. Exit");
}

int main() {
	struct node *root = NULL;
	
	int opt, ins, del, check;
		
	do {
		menu();
		printf("Choose: ");scanf("%d", &opt);
		switch(opt) {
			case 1:
				printf("Insert: ");scanf("%d", &ins);
				root = insert(root, ins);
				break;
			
			case 2:
				printf("Delete: ");scanf("%d", &del);
				check = search(root, del);
				
				if (check == 1) {
					puts("Data found.");
					root = deleteValue(root, del);
					printf("Value %d was deleted.", del);
				} else if(check == 2) {
					puts("No data available.");
				} else {
					
					puts("Data not found.");
				}
				
				
				getchar();
				break;
			
			case 3:
				printf("Pre Order: ");
				preorder(root);
				puts("");
				
				printf("In Order: ");
				inorder(root);
				puts("");
				
				printf("Post Order: ");
				postorder(root);
				getchar();
				break;
			
			case 4:
				puts("Thank you");
				getchar();
				return 0;
		}
		getchar();
		system("cls");
	} while(opt != 0);

	
	return 0;
}
