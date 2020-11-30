#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct GraphType {
	int n; // vertex�� ��
	int adj_mat[MAX][MAX]; //���
}GraphType;

void init(GraphType* g) {
	int row, col;
	g->n = 0;
	for (row = 0; row < MAX; row++)
		for (col = 0; col < MAX; col++)
			g->adj_mat[row][col] = 0; //��� ���� 0���� �ʱ�ȭ
}
void insert_vertex(GraphType* g, int value) {
	if (g->n + 1 > MAX) {
		fprintf(stderr, "�׷���: ������ ���� �ʰ�\n");
		return;
	}
	else g->n++; //vertex ���� ����
}
void insert_edge(GraphType* g, int start, int end) {
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����\n");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1; //��Ī ��ġ�� ��� 1�� set
}
void print_adj_mat(GraphType* g) {
	int row, col;
	for (row = 0; row < g->n; row++){
		for (col = 0; col < g->n; col++)
			printf("%2d", g->adj_mat[row][col]);
		printf("\n");
	}
}
int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	
	for (int i = 0; i < 4; i++) { insert_vertex(g, i); }
	insert_edge(g, 0, 1); // 0-1 ����
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	print_adj_mat(g);

	free(g);
	return 0;
}