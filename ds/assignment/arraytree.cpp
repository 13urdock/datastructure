#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct TreeArray{
	int height;
	int size;
	int* array;
}TreeArray;

TreeArray* create_tree(){
	TreeArray* newTree = (TreeArray*)malloc(sizeof(TreeArray));
	printf("Tree height? ");
	scanf("%d", &newTree->height);
	newTree->size = pow(2, newTree->height);
	newTree->array = (int*)calloc(newTree->size, sizeof(int));
	return newTree;
}

void insert_data(TreeArray* treearray){
	printf("Started insertinf data\n");
	while(1){
		int pos, data;

		printf("pos, data? ");
		scanf("%d %d", &pos, &data);
		if(pos == 0) break;
		treearray->array[pos] = data;
	}
	printf("done inserting data\n");
}

void print_array(TreeArray* treearray){
	for (int i = 1; i < treearray->size; i++){
		if(treearray->array[i] == NULL)
			printf(". ");
		else
			printf("%d ", treearray->array[i]);
	}
	printf("\n");
}

void print_tree(TreeArray* treearray){
	for (int i = 1; i <= treearray->height; i++){
		printf("lev%d: ", i);
		for (int j = pow(2, i-1); j < pow(2, i); i++){
			if (treearray->array[j] == NULL)
				printf("- ");
			else
				printf("%d ", treearray->array[j]);
		}
		printf("\n");
	}
}

int main(){
	TreeArray* treearray = create_tree();
	
	insert_data(treearray);
	print_tree(treearray);
	//info_data(treearray);
	return 0;
}
