#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>
using namespace std;

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

Node* alloc_new_node(){
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = NULL;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

void add_node(Node* root, int data){
	if(root->data == NULL) {
		root->data = data;
		return;
	}
	if (data > root->data)
		if (root->right == NULL){
			root->right = alloc_new_node();
			root->right->data = data;
		}
		else{
			add_node(root->right, data);
		}
	if (data < root->data){
		if (root->left == NULL){
			root->left = alloc_new_node();
			root->left->data = data;
		}
		else{
			add_node(root->left, data);
		}
	}
}

//should've tried iteration.. do it later and solve it with recursion
Node* search_node(Node* root, int data, int* count){
	stack<Node*> s;
	s.push(root);
	while(1){		
		if (s.top()->data == data){
			return s.top();
		}
		root = s.top();
		s.pop();
		if(root->right != NULL && root->data < data){
			s.push(root->right);
			++(*count);
		}
		if(root->left != NULL && root->data > data){
			s.push(root->left);
			++(*count);
		}
		if (root->right == NULL && root->left == NULL) {
			return NULL;
		}
	}
}

void level_order(Node* root){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		printf("%d ", q.front()->data);
		Node* tmp = q.front();
		q.pop();
		if(tmp->left != NULL)
			q.push(tmp->left);
		if(tmp->right != NULL)
			q.push(tmp->right);
	}
	printf("\n");
}

Node* min_data_node(Node* root){
	Node* tmp = root;

	while (tmp->left->left != NULL)
		tmp = tmp->left;

	return tmp;
}

//move the data of target to the node to be changed 
int delete_node(Node* root, int data){
	stack<Node*> s;
	s.push(root);
	while(1){
		if (s.empty()) //when the data is not found
			return 0;
		Node* node = s.top();
		if(node->data == data){//when data matches
			Node* tmp = node;
			if(node->left == NULL && node->right == NULL){//리프노드일 때
				free(node);
				tmp = NULL;
				return 1;
			}
			else if (node->left == NULL){//왼쪽 노드가 비었을 때
				node = node->right;
				
			}
			else if (node->right == NULL){//오른쪽 노드가 비었을 때
			
			}
			else { //두 쪽 모두 노드가 있을 때 오른쪽 트리에서 제일 작은 값으로 바꾸기
	
			}
		}
		s.pop();
		if(node->right != NULL)
			s.push(node->right);
		if(node->left != NULL)
			s.push(node->left);
	}
}

//nooo I wanted to use recursion.....
void free_node(Node* root){
	stack<Node*> s;
	int count = 0;
	s.push(root);
	while(1){
		if(s.empty()) break;
		if(root->right != NULL)
			s.push(root->right);
		if(root->left != NULL)
			s.push(root->left);	
		root = s.top();
		count++;
		printf("%d free ", root->data);
		s.pop();
	}
	printf("\n총 %d개의 노드가 free됨.\n", count);
}

void enter_data(Node* root){
	int data;
	while(1){	
		printf("입력 (종료는 -1) : ");
		scanf("%d", &data);
		if(data == -1){
			printf("\n");
			break;
		}
		add_node(root, data);
	}
}

void search_data(Node* root){
	printf("탐색할 노드: ");
	int count = 1;
	int data;
	scanf("%d", &data);
	Node* target = search_node(root, data, &count);
	if(target == NULL)
		printf("존재하지 않습니다.\n\n");
	else
		printf("%d은 %d회 탐색으로 발견\n\n", target->data, count);
}

void print_level_order(Node* root){
	printf("[Level]\n");
	level_order(root);
	printf("\n");
}

void end_program(Node* root){
	free_node(root);
	printf("[종료]\n");
}

int select_menu(){
	int menu;
	printf("1. 입력\n2. 탐색\n3. LevelOrder\n4. 삭제\n5. 종료\n");
	printf("번호를 넣으세요: ");
	scanf("%d", &menu);
	return menu;
}

Node* delete_data(Node* root){
	printf("삭제할 노드: ");
	int data;
	int count = 1;
	scanf("%d", &data);
	Node* target = search_node(root, data, &count);
	if (target == root){
		target = delete_node(root, target->data);
		return target;
	}
	if (target != NULL)
		target = delete_node(root, target->data);
	return root;
}

int main(){
	Node* root = alloc_new_node();
	while(1){
		int menu = select_menu();
		switch(menu){
		case 1:
			enter_data(root);
			break;
		case 2:
			search_data(root);
			break;
		case 3:
			print_level_order(root);
			break;
		case 4:
			root = delete_data(root);	
			break;
		case 5:
			end_program(root);
			return 0;
		}
	}	
	return 0;
}
