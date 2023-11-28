#include <stdio.h>
#include <stdlib.h>
#define MAXV 101

typedef struct GraphType{
	int size;
	int edge[MAXV][MAXV];
}GraphType;

GraphType* create_graph(int size){
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));
	g->size = size;
	return g;
}

void insert_edge(GraphType* g, int start, int end, int w){
	g->edge[start][end] = w;
}

void floyd(GraphType* g){
	for (int i = 0; i < g->size; i++){
		for(int j = 0; j < g->size; j++){
			for(int k = 0; k < g->size; k++){
				if (g->edge[j][i] && g->edge[i][k])
					g->edge[j][k] = 1;
			}
		}
	}
}

void print_floyd(GraphType* g){
	for (int i = 0; i < g->size; i++){
		for(int j = 0; j < g->size; j++){
			printf("%d ", g->edge[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int v;
	scanf("%d", &v);
	GraphType* g = create_graph(v);
	for (int i = 0; i < v; i++){
		for(int j = 0; j < v; j++){
			int w;
			scanf("%d", &w);
			insert_edge(g, i, j, w);
		}
	}
	floyd(g);
	print_floyd(g);

	return 0;
}
