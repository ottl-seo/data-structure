#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct GraphNode {
	int vertex;
	GraphNode* link;
}GraphNode;

typedef struct GraphType {
	int n; //vertex ����
	GraphNode* adj_list[MAX]; //vertex ���� ũ���� ������ �迭
}GraphType;

void init(GraphType* g) {
	g->n = 0; //��� �� 0���� �ʱ�ȭ
	for (int i = 0; i < MAX; i++) 
		g->adj_list[i] = NULL; //��� vertex NULL�� �ʱ�ȭ
}
void insert_vertex(GraphType* g, int value) {
	if (g->n + 1 > MAX) { //����ó��
		fprintf(stderr, "�׷���: ������ ���� �ʰ�");
		return;
	}
	else g->n++; //vertex���� ����
}
void insert_edge(GraphType* g, int u, int value) {
	if (u >= g->n || value >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return;
	}
	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = value; //�� �ְ�
	node->link = g->adj_list[u]; //u����Ʈ�� �� �տ� ����
	g->adj_list[u] = node; //insert�� ��尡 �Ǿ� vertex�� ��
}
void print_adj_list(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		GraphNode* temp = g->adj_list[i]; //�� vertex���� �ݺ��ؼ� ���
		printf("vertex %d�� adj list ", i);
		while (temp != NULL) {
			printf(" -> %d ", temp->vertex);
			temp = temp->link;
		}
		printf("\n");
	}
}
int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	for (int i = 0; i < 4; i++)
		insert_vertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 1, 0); //��Ī�ƴϾ, ���� ��������� �־�����Ѵ�
	insert_edge(g, 0, 2);
	insert_edge(g, 2, 0);
	insert_edge(g, 0, 3);
	insert_edge(g, 3, 0);
	insert_edge(g, 1,2);
	insert_edge(g, 2,1);
	insert_edge(g, 2,3);
	insert_edge(g, 3,2);

	print_adj_list(g);
	
	free(g);
	return 0;
}