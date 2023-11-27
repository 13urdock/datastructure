#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>
using namespace std;
#define MAXV 50

typedef struct Mat{
	int edge[MAXV][MAXV];
	int weight[MAXV][MAXV];
}Mat;

typedef struct GraphType{
	int n;
	Mat* mat;
}GraphType;

void insert_vertex(GraphType* g){
	if(g->n >= MAXV) return;
	g->n = 5;
}

GraphType* create_graph(){
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));
	g->n = 0;
	g->mat = (Mat*)malloc(sizeof(Mat));
	for(int r = 0; r <  MAXV; r++){
		for(int c = 0; c < MAXV; c++){
			g->mat->edge[r][c] = 0;
		}
	}
	insert_vertex(g);
	return g;
}

void insert_edge(GraphType* g, int start, int end, int weight){
	if(start > g->n || end > g->n) return;
	g->mat->edge[start][end] = 1;
	g->mat->edge[end][start] = 1;
	g->mat->weight[start][end] = weight;
	g->mat->weight[end][start] = weight;
}

void default_graph(GraphType* g){
	insert_edge(g, 0, 1, 1);
	insert_edge(g, 0, 4, 5);
	insert_edge(g, 0, 5, 1);
	insert_edge(g, 1, 2, 5);
	insert_edge(g, 2, 3, 6);
	insert_edge(g, 2, 5, 4);
	insert_edge(g, 3, 4, 3);
}

void dfs(GraphType* g, int v){
	stack<int> s;
	int sum = 0; // sum of weight
	int visited[MAXV] = {0};
	printf("DFS :");
	s.push(v);// pushing starting point
	int top = s.top();
	while (!s.empty()){
		printf(" %d", top);
		s.pop();
		for (int i = g->n; i > 0; i--){
			if(g->mat->edge[top][i] && !visited[i]){
				s.push(i); // push all indexes that hasn't been visited from current vertex
			}
		}
		int prev = top;
		top = s.top(); // change vertex
		visited[top]++;
		sum += g->mat->weight[prev][top];
	}
	printf(" = %d", sum);
}

//menu 1
int add_edges(GraphType* g){
	int s, e, w;
	int count = 0;
	while (1){
		scanf("%d %d %d", &s, &e, &w);
		if(s == -1 &&  e ==  -1 && w == -1) return count;
		count++;
		insert_edge(g, s, e, w);
		printf("%d <-> %d weight: %d\n", s, e, g->mat->weight[s][e]);
	}
}

//menu 2
void change_weight(GraphType* g){
	int count = add_edges(g);
	printf("Weight %d개 변경 완료\n", count);
}

//menu 3
void compare_weight(GraphType* g){
	dfs(g, 0);
	//mst(g);
}

void menu(GraphType* g){
	printf("1. Edge 추가\n2. Weight 변경\n3. Weight 비교\n4. 종료\n");
	int menu;
	while (1){
		printf("입력: ");
		scanf("%d", &menu);
		switch(menu){
			case 1:
				add_edges(g);
				break;
			case 2:
				change_weight(g);
				break;
			case 3:
				compare_weight(g);
				break;
			case 4:
				return;
		}
	}
}

int main(){
	GraphType* g = create_graph();	
	default_graph(g);
	menu(g);
	return 0;
}
