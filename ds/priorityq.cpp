#include <stdio.h>
#include <stdlib.h>

typedef struct HeapType{
	int data[100];
	int size;
}HeapType;

HeapType* create(){
	HeapType* heap = (HeapType*)malloc(sizeof(HeapType));
	heap->size = 0;
	return heap;
}

//parent = child / 2

void insert(HeapType* heap, int data){
	++(heap->size);
	int i = heap->size;
	heap->data[i] = data;
	while(i != 1 && (heap->data[i] > heap->data[i / 2]) ){
		int tmp;
		tmp =	heap->data[i / 2];
		heap->data[i] = heap->data[i / 2];
		heap->data[i] = tmp;
		i /= 2;
	}
}

void print(HeapType* heap){
	for (int i = 0; i < heap->size; i++)
		printf("%d ", heap->data[i]);
	printf("\n");
}

int main(){
	HeapType *heap = create();
	for (int i = 5; i > 0; i--){
		insert(heap, i);
	}
	print(heap);
}
