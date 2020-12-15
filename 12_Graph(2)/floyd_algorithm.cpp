#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX 100
#define INF 1000L

typedef struct GraphType {
	int n;
	int weight[MAX][MAX];
}GraphType;

int A[MAX][MAX]; //weight 2���� �迭 ǥ��

void printA(GraphType* g) {
	int i, j;
	printf("=======================\n");
	for (i = 0; i < g->n; i++) {
		for (j = 0; j < g->n; j++) {
			if (A[i][j] == INF)	printf("%3c", '*'); //���Ѵ�� * ���
			else printf("%3d", A[i][j]); //���Ѵ� �ƴϸ� ����ġ �״�� ���
		}
		printf("\n");
	}
}
void floyd(GraphType* g) {
	int i, j, k;
	for (i = 0; i < g->n; i++) {
		for (j = 0; j < g->n; j++)
			A[i][j] = g->weight[i][j]; //weight�� �ʱ�ȭ
	}
	printA(g); //���
	for (k = 0; k < g->n; k++) {
		for (i = 0; i < g->n; i++) {
			for (j = 0; j < g->n; j++) {
				if (A[i][j] > A[i][k] + A[k][j]) A[i][j] = A[i][k] + A[k][j]; // i->k->j�� �� ������ �ٲ�
			}
		}
		printA(g);
	}
}
int main() {
	GraphType g = { 7,
		{
		{0,7,INF,INF,3,10,INF},
		{7,0,4,10,2,6,INF},
		{INF,4,0,2,INF,INF,INF},
		{INF,10,2,0,11,9,4},
		{3,2,INF,11,0,INF,5},
		{10,6,INF,9,INF,0,INF},
		{INF,INF,INF,4,5,INF,0}
		}
	};
	floyd(&g);
	return 0;
}