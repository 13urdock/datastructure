#include <stdio.h>
#include <stdlib.h>

typedef struct HeapType{
	int data[100];
	int size;
}HeapType;

void print(HeapType* heap);

HeapType* create(){
	HeapType* heap = (HeapType*)malloc(sizeof(HeapType));
	heap->size = 0;
	return heap;
}

void swp(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void insert(HeapType* heap, int data){
	int i = ++(heap->size);
	heap->data[i] = data;
	while(i != 1 && (heap->data[i] < heap->data[i / 2]) ){
		heap->data[i] = heap->data[i / 2];
		i /= 2;
	}
	heap->data[i] = data;
	printf("after inserting data %d: ", data);
	print(heap);
}

void sort(HeapType* heap, int idx){
	if (heap->size <  idx) return;
	if (heap->data[idx * 2 + 1] > heap->data[idx * 2]){
		if(heap->data[idx] > heap->data[idx * 2 + 1])
				swp(&heap->data[idx], &heap->data[idx * 2 + 1]);
	}
	else{
		if(heap->data[idx] > heap->data[idx * 2])
			swp(&heap->data[idx], &heap->data[idx * 2]);
	}
	sort(heap, idx * 2);
	sort(heap, idx * 2 + 1);
}

int remove(HeapType* heap){
	int parent = 1;
	int child = 2;
	int removed = heap->data[1];
	heap->data[1] = heap->data[heap->size];//마지막노드를 첫번째 노드로 이동
	--(heap->size);
	while (child <= heap->size){
		if (heap->data[child] > heap->data[child + 1])
			child++;
		if (heap->data[parent] > heap->data[child]){
			swp(&heap->data[parent], &heap->data[child]);
		}
		else break;
		parent = child;
		child *= 2;
	}
	return removed;
}

void print(HeapType* heap){
	for (int i = 1; i <= heap->size; i++)
		printf("%d ", heap->data[i]);
	printf("\n");
}

int main(){
	HeapType *heap = create();
	for (int i = 5; i > 0; i--){
		insert(heap, i);
	}
	print(heap);
	int a =	remove(heap);
	printf("removed data: %d\n", a);
	print(heap);
}
