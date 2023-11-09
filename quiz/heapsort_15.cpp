#include <stdio.h>
#include <stdlib.h>

// 알파벳과 빈도를 담은 구조체
typedef struct Element {
	char letter;
	int count;
}Element;

typedef struct HeapType {
	Element* data;
	int size;
}HeapType;

// 측정한 빈도수를 Element 배열에 저장
Element* create_element(int* count) {
	Element* data = (Element*)malloc(28 * sizeof(Element));
	for (int i = 0; i < 28; i++) {
		if (i == 26)
			data[i].letter = 'P';
		else if (i == 27)
			data[i].letter = 'S';
		else
			data[i].letter = (char)(i + 97);
		data[i].count = count[i];
	}
	return data;
}

HeapType* create_heap() {
	HeapType* heap = (HeapType*)malloc(sizeof(HeapType));
	heap->size = 0;
	return heap;
}

Element remove(HeapType* heap){
	int parent = 1;
	int child = 2;
	Element removed = heap->data[1];
	heap->data[1] = heap->data[heap->size];//마지막노드를 첫번째 노드로 이동
	--(heap->size);
	while (child <= heap->size){
		//자식 노드 중 작은 곳으로 이동
		if (heap->data[child].count > heap->data[child + 1].count)
			child++;
		//자식 노드가 적으면 바꾸기
		if (heap->data[parent].count > heap->data[child].count){
			Element tmp = heap->data[parent];
			heap->data[parent] = heap->data[child];
			heap->data[child] = tmp;
		}
		else break;
		parent = child;
		child *= 2;
	}
	return removed;
}

// 10점 문제 출력
void print_q1(Element* data) {
	printf("Q1) - 10pt\n");
	printf("%c(%d)", data[0].letter, data[0].count);
	for (int i = 1; i < 28; i++) {
		if (data[i].count == 0) continue;
		printf(" / %c(%d)", data[i].letter, data[i].count);
	}
	printf("\n");
}

// 추가 점수
void print_q2(HeapType* heap) {
	int size = heap->size;
	printf("Q2) - 5pt\n");
	Element element = remove(heap);
	printf("%c(%d)", element.letter, element.count);
	for (int i = 2; i <= size; i++) {
		element = remove(heap);
		printf(", %c(%d)", element.letter, element.count);
	}
	printf("\n");
}


void print_queue(HeapType* heap, Element* data) {
	print_q1(data);
	print_q2(heap);
}

void insert(HeapType* heap, Element* data) {
	Element* new_data = (Element*)malloc(28 * sizeof(new_data));
	for (int j = 0; j < 28; j++) {
		if (data[j].count == 0) continue;
		int i = ++(heap->size);
		new_data[i] = data[j];
		while (i != 1 && (new_data[i].count < new_data[i / 2].count)) {
			new_data[i] = new_data[i / 2];
			i /= 2;
		}
		new_data[i] = data[j];		
	}
	heap->data = new_data;
}

char* get_str() {
	char* str = (char*)malloc(100 * sizeof(char));
	printf("Input String: ");
	scanf("%[^\n]s", str);
	return str;
}

int* count_char(char* str) {
	int* count = (int*)calloc(28, sizeof(int));

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ')
			count[27]++;
		else if (str[i] == '.')
			count[26]++;
		else
			count[(int)str[i] - 97]++;
	}
	return count;
}

int main() {
	char* str = get_str();
	int* count = count_char(str);
	Element* data = create_element(count);
	HeapType* heap = create_heap();
	insert(heap, data);
	print_queue(heap, data);
	return 0;
}
