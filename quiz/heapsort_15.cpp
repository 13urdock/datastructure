#include <stdio.h>
#include <stdlib.h>

typedef struct Element{
	char letter;
	int count;
}Element;

typedef struct HeapType{
	Element* data;
	int size;
}HeapType;

Element* create_element(int* count){
	Element* data = (Element*)malloc(28 * sizeof(Element));
	for (int i = 0; i < 28; i++){
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

HeapType* create_heap(){
	HeapType* heap = (HeapType*)malloc(sizeof(HeapType));
	heap->size = 0;
	return heap;
}

void print_data(Element* data){
	printf("%c(%d)", data[1].letter, data[1].count);
	for (int i = 2; i <= 28; i++){
		Element a = data[i];
		printf(", %c(%d)", data[i].letter, data[i].count);
	}
	printf("\n");
}

void insert(HeapType* heap, Element* data){
	Element* new_data = (Element*)malloc(28 * sizeof(new_data));
	for (int j = 0; j < 28; j++){
		if (data[j].count == 0) continue;
		int i = ++(heap->size);
		new_data[i] = data[j];
		while(i != 1 && (new_data[i].count < new_data[i / 2].count)){
			new_data[i] = new_data[i / 2];
			i /= 2;
		}
		new_data[i] = data[j];
		printf("after insertting data %d: ", data[i].count);
		print_data(new_data);
	}
	heap->data = new_data;
}

void print_sorted(HeapType* heap){
	printf("%c(%d)", heap->data[0].letter, heap->data[0].count);
	for (int i = 1; i < 28; i ++){
		if(heap->data[i].count == 0) continue;
		printf(" / %c(%d)", heap->data[i].letter, heap->data[i].count);
	}
	printf("\n");
}

char* get_str(){
	char* str = (char*)malloc(100 * sizeof(char));
	printf("Input String: ");
	scanf("%[^\n]s", str);
	return str;
}

int* count_char(char* str){
	int* count = (int*)calloc(28,  sizeof(int));

	for (int i = 0; str[i] != '\0'; i++){
		if(str[i] == ' ')
			count[27]++;
		else if(str[i] == '.')
			count[26]++;
		else
			count[(int)str[i]-97]++;
	}
	return count;
}

int main(){
	char* str = get_str();
	int* count = count_char(str);
	Element* data = create_element(count);
	HeapType* heap = create_heap();

	print_data(heap->data);
	return 0;
}
