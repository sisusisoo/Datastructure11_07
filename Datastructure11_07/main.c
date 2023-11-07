#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

typedef struct GraphType {
	int n;//정점갯수 
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];
//최소 dist[v]값을 갖는 정점을 반환 
int get_min_vertex(int n) {
	int v, i;
	for (i = 0; i < n; i++) {
		if (!selected[i]) {
			v = i;
			break;
		}
	}
	for (i = 0; i < n; i++) {
		if (!selected[i] && (distance[i] < distance[v])) v = i;
	
	}
	return (v);
}
void prim(GraphType* g, int s) {
	int i, u, v;

	for (u = 0; u < g->n; u++) {
		distance[u] = INF;

	}
	distance[s] = 0;
	for (i = 0; i < g->n; i++) {
		u = get_min_vertex(g->n);
		selected[u] = TRUE;
		if (distance[u] == INF) {
			return;
		}
		printf("정점%d추가\n", u);
		for (v = 0; v < g->n; v++) {
			if (g->weight[u][v] != INF) {
				if (!selected[v] && g->weight[u][v] < distance[v])
					distance[v] = g->weight[u][v];
			}
		}
	}
}

int main(void) {//1에서부터
	GraphType g = { 10,
		//0 1 2 3 4 5 6 7 8 9 10
		 {
			 
		 {  0,  3,INF,INF,INF, 11, 12,INF,INF,INF},//1
		 {  3,  0,  5,  4,  1,  7,  8,INF,INF,INF},//2
		 {INF,  5,  0,  2,INF,INF,  6,  5,INF,INF},//3
		 {INF,  4,  2,  0, 13,INF,INF, 14,INF, 16},//4
		 {INF,  1,INF, 13,  0,  9,INF,INF, 18,INF},//5
		 { 11,  7,INF,INF,  9,  0,INF,INF,INF,INF},//6
	   // 0   1   2   3   4   5   6   7   8   9 10
		 { 12,  8,  6,INF,INF,INF,  0, 13,INF,INF},//7
	   // 0   1   2   3   4   5   6   7   8   9 10
		 {INF,INF,  5, 14,INF,INF, 13,  0,INF, 15},//8
       // 0   1   2   3   4   5   6   7   8   9 10
	     {INF,INF,INF,INF, 18,INF,INF,INF,  0, 10},//9
	   // 0   1   2   3   4   5   6   7   8   9 10
		 {INF,INF,INF, 16,INF,INF,INF, 15, 10,  0},//10
		}

	};

	GraphType h = {7,
		{
		{0,29,INF,INF,INF,10,INF},
		{29,0,16,INF,INF,INF,15},
		{INF,16,0,12,INF,INF,INF},
		{INF,INF,12,0,22,INF,18},
		{INF,INF,INF,22,0,27,25},
		{10,INF,INF,INF,27,0,INF},
		{INF,15,INF,18,25,INF,0},
		}
	};
	prim(&g, 0);
	//prim(&h, 0);
	return 0;
}