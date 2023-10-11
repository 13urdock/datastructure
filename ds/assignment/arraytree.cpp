#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//배열, 트리의 높이, 노드의 개수를 담는 구조체
typedef struct TreeArray{
	int height;
	int size;
	int* array;
}TreeArray;

//트리 생성
TreeArray* create_tree(){
	TreeArray* newTree = (TreeArray*)malloc(sizeof(TreeArray));
	printf("Tree height? ");
	scanf("%d", &newTree->height);
	newTree->size = pow(2, newTree->height);
	newTree->array = (int*)calloc(newTree->size, sizeof(int));
	return newTree;
}

//데이터 입력
void insert_data(TreeArray* treearray){
	printf("트리 데이터 입력을 시작합니다.\n");
	while(1){
		int pos, data;

		printf("pos, data? ");
		scanf("%d %d", &pos, &data);
		if(pos == 0) break;
		treearray->array[pos] = data;
	}
	printf("트리 데이터 입력이 완료되었습니다.\n");
}

//트리 출력
void print_tree(TreeArray* treearray){
	for (int i = 1; i <= treearray->height; i++){
		printf("Lev%d: ", i);
		for (int j = pow(2, i-1); j < pow(2, i); j++){
			if (treearray->array[j] == NULL)
				printf("- ");
			else
				printf("%d ", treearray->array[j]);
		}
		printf("\n");
	}
}

//데이터가 있는 배열의 인덱스 검색, 반환
int search_data(TreeArray* treearray, int data){
	for (int i = 1; i < treearray->size; i++){
		if(treearray->array[i] == data)
			return i; 
	}
	return 0; //찾지 못하면 0 반환
}

//데이터 정보
void info_data(TreeArray* treearray){
	while(1){
		int data;
		printf("정보를 알고 싶은 데이터를 입력하세요. (종료 = 999) : ");
		scanf("%d", &data);
		if (data == 999) {
			printf("종료합니다.\n");
			return;
		}
		
		// 입력한 데이터와 일치하는 요소의 인덱스
		int index = search_data(treearray, data);
		printf("%d: ", data);

		//일치하는 데이터가 없을 경우
		if (index == 0) { 
			printf("노드가 존재하지 않습니다.\n");
			continue;
		}
		else{
			int parent = index / 2;
			printf("부모 = ");
			if(parent == 0) // 부모 노드가 없을 경우
				printf("없음, ");
			else
				printf("%d, ", treearray->array[parent]);
			
			int left = index * 2;
			printf("왼쪽 자식 = ");
			//배열의 사이즈보다 큰 경우, 자식 노드가 없는 경우
			if(left >= treearray->size || treearray->array[left] == NULL)
				printf("없음, ");
			else
				printf("%d, ", treearray->array[left]);

			int right = index * 2 + 1;
			printf("오른쪽 자식 = ");
			if(right >= treearray->size || treearray->array[right] == NULL)
				printf("없음\n");
			else
				printf("%d\n", treearray->array[right]);
		}
	}
}

int main(){
	TreeArray* treearray = create_tree();
	
	insert_data(treearray);
	print_tree(treearray);
	info_data(treearray);

	return 0;
}
