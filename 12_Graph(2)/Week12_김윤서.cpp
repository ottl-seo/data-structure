/* 12���� ����: ���ͽ�Ʈ�� �˰����� ��������Ʈ�� ǥ���ϱ� */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L //���Ѵ�(������ ���� ���)

typedef struct GraphNode {
	int vertex; //���� ��ȣ
	int weight; //�ش� ����Ʈ �������� �Ÿ��� ����
	GraphNode* link; // ��ũ
}GraphNode;
typedef struct GraphType {
	int n; //���� ����
	GraphNode* adj_list[MAX_VERTICES]; //������ �迭
}GraphType;

void printInfo(void) {
	printf("====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971063\n");
	printf("����: ������\n");
	printf("====================\n");
}
/* ----------------- adj_list Func ---------------- */
void init(GraphType* g) {
	g->n = 0;
	for (int v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL; //������ �迭 �ʱ�ȭ
}
void insert_vertex(GraphType* g, int v) {
	if ((g->n) + 1 > MAX_VERTICES) { // vertex ���� MAX�� �Ѿ ���
		fprintf(stderr, "%s\n", "�׷���: ������ ���� �ʰ�");
		return;
	}
	g->n++;
}
void insert_edge(GraphType* g, int u, int ver, int wei) {  //u�� ��������Ʈ�� v�� �����Ѵ�
	GraphNode* node;
	if (u >= g->n || ver >= g->n) {
		fprintf(stderr, "%s\n", "�׷���: ���� ��ȣ ����");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode)); // ������ �� ��� ����
	node->vertex = ver; //
	node->weight = wei; //
	node->link = g->adj_list[u]; //��ũ ����
	g->adj_list[u] = node; //node�� ���Ḯ��Ʈ u�� �� ó���� ����
}

/* ------------------ Graph Func ------------------ */
int distance[MAX_VERTICES]; // start vertex�κ��� �� ���������� �ִ� �Ÿ�
int found[MAX_VERTICES]; //�湮�� ���� ǥ��

int choose(int distance[], int n, int found[]) { /* distance �߿��� ���� ª�� vertex��ȣ�� ���� */
	int i, min, min_vertex;
	min = INT_MAX;
	min_vertex = -1; // �ּҰŸ� ���� vertex: ���� vertex�� �ϴ� �ʱ�ȭ
	for (i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i]; // min�� ����
			min_vertex = i; //�ּҰŸ� ���� vertex
		}
	}
	return min_vertex; //vertex ��ȣ ��ȯ
}
void print_status(GraphType* g) {
	static int step = 1;
	printf("STEP %d:\n", step++); //step 1, 2, ...
	printf(" distance: ");
	for (int i = 0; i < g->n; i++)
		if (distance[i] == INF) { printf(" * "); }
		else { printf("%2d ", distance[i]); }
	printf("\n found: ");
	for (int i = 0; i < g->n; i++)
		printf("%2d ", found[i]);
	printf("\n\n");
}
int find_weight(GraphType* g, int u, int v) { /* vertex u���� v������ �Ÿ� ã�� �Լ� */
	GraphNode* p = g->adj_list[u];
	int utov_weight = 0; 
	while (p != NULL) {

		if (p->vertex == v) { // u�� ��������Ʈ���� v�� ������
			utov_weight = p->weight; //u���� v������ �Ÿ�
			break;
		}
		else p = p->link; 
	}
	return utov_weight;
}
void shortest_path(GraphType* g, int start) { // start_vertex ��ȣ �ޱ�
	int i, u, w;
	GraphNode* p = g->adj_list[start];

	/* 1.�ʱ�ȭ */
	for (int i = 0; i < g->n; i++) {
		found[i] = FALSE;
		distance[i] = INF; //distance�� ��� INF�� �ʱ�ȭ�ϰ�, ���߿� ���� �ִ� �͸� �����Ѵ�
	}
	for (p; p!=NULL; p=p->link)	
		distance[p->vertex] = p->weight; //start vertex�κ����� ���������� �Ÿ� (1,INF,3 ���...)
	
	/* 2.start vertex ���� */
	found[start] = TRUE;
	distance[start] = 0;
	/////////////////������� ok

	/* 3.�ִ� vertex�� ã�Ƽ� found�� �߰� */
	for (int i = 0; i < g->n - 1; i++) {
		print_status(g); //step ���
		u = choose(distance, g->n, found); // ���� ���� distance ���� vertex ��ȯ == u
		found[u] = TRUE;

		/* 4.u�� ���İ��� �� �� ª�� ���, ���� */
		for (w = 0; w < g->n; w++) {
			if (!found[w]) { // !found ����...
				if (distance[u] + find_weight(g,w,u) < distance[w]) //�� ª�� ���
					distance[w] = distance[u] + find_weight(g, w, u); // distance[w]�� ����
			}
		}
	}
}
int main() {
	printInfo(); //���� ���
	/*
	GraphType g = {
		7,
		{
		0 {0,7,INF,INF,3,10,INF},
		1 {7,0,4,10,2,6,INF},
		2 {INF,4,0,2,INF,INF,INF},
		3 {INF,10,2,0,11,9,4},
		4 {3,2,INF,11,0,INF,5},
		5 {10,6,INF,9,INF,0,INF},
		6 {INF,INF,INF,4,5,INF,0}
		}
	}; */
	GraphType* g = (GraphType*)malloc(sizeof(GraphType)); //�׷��� ����
	init(g);
	for (int i = 0; i < 7; i++)
		insert_vertex(g, i); // n=7 :���� 7�� ���� (0~6)

	insert_edge(g, 0, 1, 7); insert_edge(g, 1, 0, 7); //��Ī���� ����Ǵ� ���� �ƴϹǷ�, (1,0) �� (0,1) �ι� �����������
	insert_edge(g, 0, 4, 3); insert_edge(g, 4, 0, 3);
	insert_edge(g, 0, 5, 10); insert_edge(g, 5, 0, 10);

	insert_edge(g, 1, 2, 4); insert_edge(g, 2, 1, 4);
	insert_edge(g, 1, 3, 10); insert_edge(g, 3, 1, 10);
	insert_edge(g, 1, 4, 2); insert_edge(g, 4, 1, 2);
	insert_edge(g, 1, 5, 6); insert_edge(g, 5, 1, 6);

	insert_edge(g, 2, 3, 2); insert_edge(g, 3, 2, 2);

	insert_edge(g, 3,4, 11); insert_edge(g, 4, 3, 11);
	insert_edge(g, 3, 5, 9); insert_edge(g, 5, 3, 9);
	insert_edge(g, 3, 6, 4); insert_edge(g, 6, 3, 4);

	insert_edge(g, 4, 6, 5); insert_edge(g, 6, 4, 5);

	shortest_path(g, 0); //0�� vertex���� ��� vertex������ shortest path

	free(g);
	return 0;
}