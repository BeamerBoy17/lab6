#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <queue>
#include <iostream>
#include "Matrix_Graph.h"
#pragma warning (disable : 4996)

int* DIST;


void BFSD(Graph* graph,int v) {
	std::queue <int> qu;
	qu.push(v);
	DIST[v] = 0;
	while (!qu.empty()) {
		v = qu.front();
		printf(" %d  ", v + 1);
		qu.pop();
		for (int i = 0; i < graph->size; i++) {
			if ((graph->matrix[v][i] == 1) && (DIST[i] == -1)) {
				qu.push(i);	
				DIST[i] = DIST[v] + 1;
			}
		}
	}
}

void main()
{
	int ver;
	int size;
	int v;
	
	printf("\nEnter the probability from 0 to 100: ");
	scanf_s("%d", &ver);

	printf("Eneter size of graph:");
	scanf("%d", &size);
	Graph* g = init_graph(size);
	generate_matrix(g, ver);
	print_graph(g);
	DIST = (int*)malloc(g->size * sizeof(int));
	for (int i = 0; i < g->size; i++) {
		DIST[i] = -1;
	}
	srand(time(NULL));

	printf("Choose vertex:");
	scanf("%d", &v);
	v--;
	printf("\n");
	printf("Visited vertex:");
	printf("\n");
	BFSD(g,v);
	printf("\n");
	printf("Distance:");
	for (int i = 0; i < g->size; i++) {
	
		printf("%d,", DIST[i]);
	}
	



}









