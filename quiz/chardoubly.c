#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	char data;
	struct Node* prev;
	struct Node* next;
}Node;

Node* alloc_new_node(){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = NULL;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void add_new_node(Node* head, char data){
	if (head->data == NULL){
		head->data = data;
	}
	else{
		Node* newNode = alloc_new_node();
		newNode->data = data;
		Node* tmp = head;
		for(; tmp->next != NULL; tmp = tmp->next);
		tmp->next = newNode;
		newNode->prev = tmp;
	}
}

void print_list(Node* head){
	if(head->data == NULL){
		printf("NULL");
	}
	else{
		for(Node* tmp = head; tmp != NULL; tmp = tmp->next){
			printf("%c", tmp->data);
		}
	}
	printf("\n");
}

Node* delete_all(Node* head, char data){
	Node* deleted = NULL;
	Node* tmp = head;
	while (tmp != NULL){
		if(tmp->data == data){
			if(tmp->prev == NULL){//when first node
				deleted = tmp;
				tmp = tmp->next;
				head = head->next;
				free(deleted);
				head->prev = NULL;
				continue;
			}
			else{
				if(tmp->next == NULL){
					deleted = tmp;
					tmp->prev->next = NULL;
					free(deleted);
					continue;
				}
				else{
					deleted = tmp;
					tmp->prev->next = tmp->next;
					tmp->next->prev = tmp->prev;
					free(deleted);
					continue;
				}
			}
		}
		else{
			tmp = tmp->next;
		}
	}
	return head;
}

Node* add(Node* head, char data, int pos){
	Node* newNode = alloc_new_node();
	newNode->data = data;

	Node* tmp = head;
	for(int i = 0; i < pos; i++)
		tmp = tmp->next;

	if(tmp == head){
		head->prev = newNode;
		newNode->next = head;
		return newNode;
	}
	else{
		tmp->prev->next = newNode;
		newNode->prev = tmp->prev;
		tmp->prev = newNode;
		newNode->next = tmp;
		return head;
	}
}

//find out how to compare strings.,,,no idea
int find(Node* head, const char* data){

}

void add_nodes(Node* head){
	add_new_node(head, 'a');
	add_new_node(head, 'p');
	add_new_node(head, 'p');
	add_new_node(head, 'l');
	add_new_node(head, 'e');
	add_new_node(head, 'c');
	add_new_node(head, 'a');
	add_new_node(head, 'r');
	add_new_node(head, 'r');
	add_new_node(head, 'o');
	add_new_node(head, 't');
	add_new_node(head, 'b');
	add_new_node(head, 'a');
	add_new_node(head, 'n');
	add_new_node(head, 'a');
	add_new_node(head, 'n');
	add_new_node(head, 'a');
}

int main(){
	Node* head = alloc_new_node();

	add_nodes(head);
	print_list(head);

	head = delete_all(head, 'p');
	print_list(head);

	head = delete_all(head, 'a');
	print_list(head);

	head = delete_all(head, 'n');
	print_list(head);

	printf("add characters\n");
	head = add(head, 'a', 0);
	print_list(head);

	head = add(head, 'p', 1);
	head = add(head, 'p', 1);
	print_list(head);

	head = add(head, 'a', 6);
	print_list(head);

	return 0;
}
