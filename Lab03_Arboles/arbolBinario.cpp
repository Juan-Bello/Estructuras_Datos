#include <stdlib.h>
#include <iostream>
using namespace std;

//estructura de nodo
struct node {
	int data;
	struct node *left; 
	struct node *right;
};

// creacion de nodo nuevo
struct node *newNode (int data){
	struct node *node = (struct node *)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
};


void traversePreOrder (struct node *temp);
void traverseInOrder(struct node *temp);
void traversePostOrder (struct node *temp);

int main(){
	struct node *root = newNode(7);
	root->left = newNode(3);
	root->right = newNode(20);
	root->left->left = newNode(0);
	root->left->left->left = newNode(-3);
	root->left->left->right = newNode(1);
	root->left->right = newNode(5);
	root->left->right->left = newNode(4);
	root->left->right->right = newNode(6);
	root->right->left = newNode(15);
	root->right->right = newNode(25);
	root->right->right->right = newNode(30);
	cout << "preorder traversal:";
	traversePreOrder(root);
	cout << "\nInorder traversal:";
	traverseInOrder(root);
	cout << "\nPostorder traversal:";
	traversePostOrder(root);
	cout << "\n";
}

//trasversar en PreOrder
void traversePreOrder (struct node *temp) {
	if (temp != NULL) {
		cout << " " << temp->data;
		traversePreOrder (temp->left);
		traversePreOrder(temp->right);
	}
}
//trasversar en Inorder
void traverseInOrder(struct node *temp) {
	if (temp != NULL) {
		traverseInOrder(temp->left);
		cout << " " << temp->data;
		traverseInOrder(temp->right);
	}
}
//Trasversar en Postorder
void traversePostOrder (struct node *temp){
	if (temp!= NULL){
		traversePostOrder(temp->left);
		traversePostOrder(temp->right);
		cout << " " << temp->data;
	}
}
