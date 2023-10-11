#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

Node* create_node(int data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void add_nodes(Node* root){
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->left->right = create_node(5);
	root->right->left = create_node(6);
	root->right->right = create_node(7);
}

void inorder_iter(Node* root){
	stack<Node*> s;
	while (1){
		for(;root != NULL; root = root->left)
			s.push(root);
		root = s.top();
		s.pop();
		if (s.empty()) break; //when there's no data in stack
		printf("%d ", root->data);
		root = root->right;	
	}
}

int main(){
	Node* root = create_node(1);
	add_nodes(root);

	inorder_iter(root);
	
	return 0;
}
