#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct GraphType {
	int n; //vertex�� ����
	int adj_matrix[MAX][MAX]; //vertex �迭
}GraphType;

int visited[MAX];

void init(GraphType* g) {
	/* init ����: (1) g->n=0; (2) ��� ���� �ʱ�ȭ */
	g->n = 0;
	for (int r = 0; r < MAX; r++) {
		for (int c = 0; c < MAX; c++)
			g->adj_matrix[r][c] = 0; //��� ���� 0���� �ʱ�ȭ
	}
}
void insert_vertex(GraphType* g, int value) {
	if (g->n + 1 > MAX) {
		fprintf(stderr,"�׷���: ������ ���� �ʰ�\n");
		return;
	}
	else g->n++; //vertex���� ����
}
void insert_edge(GraphType* g, int start, int end) {
	if (start >= g->n || end >= g->n) {
		fprintf(stderr,"�׷���: ���� ��ȣ ����\n");
		return;
	}
	g->adj_matrix[start][end] = 1;
	g->adj_matrix[end][start] = 1; //��Ī ��ġ�� ��� 1�� set
}
void dfs_matrix(GraphType* g, int value) {
	int w;
	visited[value] = true;
	printf("vertex%d ", value);
	for (w = 0; w < g->n; w++) {
		if (g->adj_matrix[value][w]==1 && !visited[w]) //���� �湮 ���߰� ���� ������ dfs �ٽ� 
			dfs_matrix(g, w);
	}
}
int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 4; i++)
		insert_vertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	dfs_matrix(g,0);

	free(g);
	return 0;
}