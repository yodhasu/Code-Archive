#include <stdio.h>
#include <stdlib.h>

struct tree{
	int data, height, bf;
	struct tree *left, *right;
};

int max(int a, int b){
	if(a < b) return b;
	else return a;
}

int getHeight(struct tree *root){
	if(root == NULL) return 0;
	return root->height;
}

int countBF(struct tree *root){
	if(root == NULL) return 0;
	return getHeight(root->left) - getHeight(root->right);
}

struct tree *rightRotate(struct tree *x){
	struct tree *y = x->left;
	struct tree *B = y->right;
	
	y->right = x;
	x->left = B;
	
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	
	return y;
}

struct tree *leftRotate(struct tree* x){
	struct tree *y = x->right;
	struct tree *B = y->left;
	
	y->left = x;
	x->right = B;
	
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	
	return y;
}

struct tree *predecessor(struct tree* root){
	struct tree *curr = root->left;
	while(curr->right != NULL){
		curr = curr->right;
	}
	return curr;
}


struct tree *successor(struct tree* root){
	struct tree *curr = root->right;
	while(curr->left != NULL){
		curr = curr->left;
	}
	return curr;
}

struct tree *newNode(int val){
	struct tree *currNewNode = (struct tree *)malloc(sizeof(struct tree));
	
	currNewNode->data = val;
	currNewNode->left = NULL;
	currNewNode->right = NULL;
	currNewNode->height = 1;
	currNewNode->bf = 0;
	
	return currNewNode;
}

struct tree *insert(struct tree *root, int val){
	if(root == NULL) return newNode(val);
	
	if(val < root->data){
		root->left = insert(root->left, val);
	}
	else{
		root->right = insert(root->right, val);
	}
	
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	int BF = countBF(root);
	
	//right once
	if(BF > 1 && val < root->left->data){
		return rightRotate(root);
	}
	//left once
	if(BF < -1 && val > root->right->data){
		return leftRotate(root);
	}
	//right left
	if(BF < -1 && val < root->right->data){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	//left right
	if(BF > 1 && val > root->left->data){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	root->bf = BF;
	return root;
}

void inOrder(struct tree* root){
	if(root == NULL) return;
	inOrder(root->left);
	printf(" val = %d height = %d BF = %d\n", root->data, root->height, root->bf);
	inOrder(root->right);
}

int main(){
	struct tree* root = NULL;
	
	root = insert(root, 1);
	root = insert(root, 2);
	root = insert(root, 5);
	root = insert(root, 3);
	root = insert(root, 4);
	inOrder(root);
	
	return 0;
}
