#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int* arr, int size){
	for (int i = 0; i < size; i++){
		int key = arr[i];
		for (int j = i - 1; j>= 0; j--){
			if (key < arr[j]){
				arr[j + 1] = arr[j];
				arr[j] = key;
			}
		}
	}
}

int sorted[1000000];
void merge(int* list, int left, int mid, int right){
  int i, j, k, l;
  i = left;
  j = mid+1;
  k = left;

  while(i<=mid && j<=right){
    if(list[i]<=list[j])
      sorted[k++] = list[i++];
    else
      sorted[k++] = list[j++];
  }

  if(i>mid){
    for(l=j; l<=right; l++)
      sorted[k++] = list[l];
  }
  else{
    for(l=i; l<=mid; l++)
      sorted[k++] = list[l];
  }

  for(l=left; l<=right; l++){
    list[l] = sorted[l];
  }
}

void merge_sort(int* arr, int left, int right){
  int mid;

  if(left<right){
    mid = (left+right)/2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right);
    merge(arr, left, mid, right);
  }
}

void print_array(int* arr, int size){
	for (int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void create_array(int* arr, int* arr2, int size){
	for (int i = 0; i < size; i++){
		arr[i] = rand() % size;
		arr2[i] = arr[i];
	}
	if (size <= 30){
		printf("생성배열: ");
		print_array(arr, size);	
	}
	printf("\n");
}

int main(){
	int size;
	printf("Input size: ");
	scanf("%d", &size);
	int* arr = (int*)malloc(size * sizeof(int));
	int* arr2 = (int*)malloc(size * sizeof(int));
	create_array(arr, arr2, size);
	
	clock_t start, end, start2, end2;
	//insertion sort
	start = clock();
	insertion_sort(arr, size);
	end = clock();

	//merge sort
	start2 = clock();
	merge_sort(arr2, 0, size-1);
	end2 = clock();

	//print time
	printf("Insertion Sort: %0.3lf초", (double)(end-start)/CLOCKS_PER_SEC);
	if(size <= 30) print_array(arr, size); else printf("\n");
	printf("Merge Sort: %0.3lf초", (double)(end2-start2)/CLOCKS_PER_SEC);
	if (size <= 30)	print_array(arr2, size); else printf("\n");

	return 0;
}
