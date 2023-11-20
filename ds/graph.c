#include <stdio.h>
#include <stdlib.h>

#define MAXV 50
typedef struct GraphType{
	int n;
	int mat[MAXV][MAXV];
}GraphType;

GraphType* createGraph(){
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));
	g->n = 0;
	for(int r = 0; MAXV; r++){
		for(int c = 0; c < MAXV; c++){
			g->mat[r][c] = 0;
		}
	}
	printf("finished creating\n");
	return g;
}

void insert_vertex(GraphType* g, int v){
	if (((g->n) + 1) > MAXV){
		printf("full of number of vertices\n");
		return;
	}
	g->n++;
	printf("finished inserting vertex\n");
}

void insert_edge(GraphType* g, int start, int end){
	if(start >= g->n || end >= g->n){
		printf("error with vertex nubmers\n");
		return;
	}
	g->mat[start][end] = 1;
	g->mat[end][start] = 1;
	printf("finished inserting edges\n");
}

int main(){
	GraphType* g = createGraph();
	for(int i = 0; i < 4; i++)
		insert_vertex(g, i);
	insert_edge(g, 1, 0);
	insert_edge(g, 2, 3);
	printf("1->0: %d\n", g->mat[1][0]);
	printf("3->2: %d\n", g->mat[3][2]);

	return 0;
}
