#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	char eng[50];
	char kor[50];
	struct Node* left;
	struct Node* right;
}Node;

Node* alloc_new_node(char* eng, char* kor){
	Node* new_word = (Node*)malloc(sizeof(Node));
	new_word->left = NULL;
	new_word->right = NULL;
	strcpy(new_word->eng, eng);
	strcpy(new_word->kor, kor);
	return new_word;
}

Node* make_tree(FILE* fp, Node* root){
	fp = fopen("engkor.dat", "r");
	char eng[50];
	char kor[50];
	while (!EOF){
		fscanf(fp, "%s %s", eng, kor);
		Node* new_word = alloc_new_node(eng, kor);
		//if (root == NULL) root = new_word;
		//add_node(Node* root, new_word);
		printf("%s: %s\n", new_word->eng, new_word->kor);
	}
	fclose(fp);
	return root;
}

void add_words(FILE *fp){
	fp = fopen("engkor.dat", "w");
	for (int i = 0; i < 5; i++){
	char eng[30];
	char kor[30];
	scanf("%s %s", eng, kor);
	fprintf(fp, "%s %s\n", eng, kor);
	}
	fclose(fp);
}

void print_tree(Node* root){
	if (root == NULL) return;
	printf("%s: %s", root->eng, root->kor);
	print_tree(root->left);
	print_tree(root->right);
}

int main(){
	FILE *fp;
	add_words(fp);
	Node* root = make_tree(fp, root);

	//print_tree(root);
	return 0;
}
