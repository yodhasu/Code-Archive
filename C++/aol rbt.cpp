#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	int color; //1 red, 0 black
	struct node *left, *right, *parent;
};

struct node *newNode(int x) {
	struct node *currNewNode =
			(struct node*)malloc(sizeof(struct node));
			
	currNewNode->data = x;
	currNewNode->left = NULL;
	currNewNode->right = NULL;
	
	return currNewNode;
}

struct node *insert(struct node *root, int value) {
	if (root == NULL) return newNode(value);
	else if (value < root->data) {
		root->left = insert(root->left, value);
	} else {
		root->right = insert(root->right, value);
	}

	return root;	
}

void leftRotate(struct node *root,struct node *x)
{
    //y stored pointer of right child of x
    struct node *y = x->right;
 
    //store y's left subtree's pointer as x's right child
    x->right = y->left;
 
    //update parent pointer of x's right
    if (x->right != NULL) x->right->parent = x;
 
    //update y's parent pointer
    y->parent = x->parent;
 
    // if x's parent is null make y as root of tree
    if (x->parent == NULL) root = y;
 
    // store y at the place of x
    else if (x == x->parent->left) {
        x->parent->left = y;
	}
    else    x->parent->right = y;
 
    // make x as left child of y
    y->left = x;
 
    //update parent pointer of x
    x->parent = y;
}
 
 
// Right Rotation (Similar to LeftRotate)
void rightRotate(struct node *root,struct node *y)
{
    struct node *x = y->left;
    y->left = x->right;
    if (x->right != NULL) {
        x->right->parent = y;
	}
    x->parent =y->parent;
    if (x->parent == NULL) root = x;
    else if (y == y->parent->left) {
        y->parent->left = x;
	} else y->parent->right = x;
    
    x->right = y;
    y->parent = x;
}

void fix(struct node *root, struct node *curr) {
	//iterate until temp != root & temp->parent != red
	
	while (curr != root && curr->parent->color != 1) {
		struct node *y;

		//find and store uncle in y
		if (curr->parent == curr->parent->parent->left) {
			y = curr->parent->parent->right;
		} else {
			y = curr->parent->parent->left;
		}
		
		//If uncle red
		if (y->color == 1) {
			y->color = 0;
			curr->parent->color = 0;
			curr->parent->parent->color = 1;
			curr = curr->parent->parent;
		}
		//else uncle is black, rotate
		else {
			/*
				LR Rotate
				
							curr grand
							/
					curr parent
							\
							 curr
			*/
			if (curr->parent == curr->parent->parent->left && curr == curr->parent->right) {
				int clr = curr->color;
				curr->color = curr->parent->parent->color;
				curr->parent->parent->color = clr;
				leftRotate(root, curr->parent);
				rightRotate(root, curr->parent->parent);
			}
			//LL Rotate
			if (curr->parent == curr->parent->parent->left && curr == curr->parent->left) {
				int clr = curr->parent->color;
				curr->parent->color = curr->parent->parent->color;
				curr->parent->parent->color = clr;
				rightRotate(root, curr->parent->parent);
			}
			//RR Rotate
			if (curr->parent == curr->parent->parent->right && curr == curr->parent->right) {
				int clr = curr->parent->color;
				curr->parent->color = curr->parent->parent->color;
				curr->parent->parent->color = clr;
				leftRotate(root, curr->parent->parent);
			}
			//RL Rotate
			if (curr->parent == curr->parent->parent->right && curr == curr->parent->left) {
				int clr = curr->color;
				curr->color = curr->parent->parent->color;
				curr->parent->parent->color = clr;
				rightRotate(root, curr->parent);
				leftRotate(root, curr->parent->parent);
			}
		}
	}
	//root always black
	root->color = 0;
}



void inorder(struct node *root) {
	if (root == NULL) return;
	inorder(root->left);
	printf(" %d ", root->data);
	inorder(root->right);
}

int main() {
	struct node *root = NULL;
	
	int leng = 10;
	int dat[10] = {41, 22, 5, 51, 48, 29, 18, 21, 45, 3};
	
	for (int i = 0; i < leng; i++) {
		root = insert(root, dat[i]);
	}
	
	inorder(root);
	
}
