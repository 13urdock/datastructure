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
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

Node* make_tree(){
	Node* root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->right->left = create_node(5);
	root->right->right = create_node(6);
	root->right->left->right = create_node(7);
	return root;
}

void recursion(Node* node){
	if (node == NULL) return;
	printf("%d ", node->data);
	recursion(node->left);
	recursion(node->right);
}

void pre_order_recursive(Node* root){
	printf("[Pre order_recursive] ");
	recursion(root);
	printf("\n");
}
	
void pre_order_iter(Node* root){
	printf("[Pre order_iter] ");
	stack<Node*> s;
	s.push(root);
	while(1){
		if (s.empty()) break;
		root = s.top();
		printf("%d ", root->data);
		s.pop();
		if(root->right != NULL)
			s.push(root->right);
		if(root->left != NULL)
			s.push(root->left);
	}
	printf("\n");
}

void get_node_sum(Node* root){
	int sum = 0;
	stack<Node*> s;
	while (1){
		for(;root != NULL; root = root->left){
			s.push(root);
		}
		if (s.empty()) break;
		root = s.top();
		s.pop();
		sum += root->data;
		root = root->right;
	}
	printf("[Sum] %d\n", sum);
}

void leafnodes(Node* node){
	if (node == NULL) return;
		if (node->left == NULL && node->right == NULL) {
			printf("%d ", node->data);
			return;
		}
	leafnodes(node->left);
	leafnodes(node->right);
}

void find_leafnodes(Node* node){
	printf("[Leaf nodes] ");
	leafnodes(node);
	printf("\n");
}
	
int main(){
	Node* root = make_tree();
	pre_order_recursive(root);
	pre_order_iter(root);
	get_node_sum(root);
	find_leafnodes(root);
	return 0;
}
