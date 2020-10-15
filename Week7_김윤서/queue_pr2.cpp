/* 2-1. �迭 �̿��� ���� ť */
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int element;
typedef struct {
	int front; //����Ʈ �ε���
	int rear;
	element data[MAX];
}QueueType;

void error(const char* message);
void init(QueueType* q);
bool is_full(QueueType* q);
bool is_empty(QueueType* q);
void enqueue(QueueType* q, element item);
element dequeue(QueueType* q);
void print_queue(QueueType* q);

int main() {
	QueueType q;
	init(&q);
	int input;

	printf("<������ �߰�>\n");
	while (!is_full(&q)) {
		printf("���� �Է�: ");
		scanf_s("%d", &input);
		enqueue(&q, input);
		print_queue(&q);
	}
	printf("Queue is full\n");
	printf("\n<������ ��������>\n");
	while (!is_empty(&q)) {
		printf("%3d\n", dequeue(&q));
		print_queue(&q);
	}
	printf("Queue is empty");
	return 0;
}
void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init(QueueType* q) {
	q->front = q->rear = 0;
}
bool is_full(QueueType* q) {
	return ((q->rear + 1) % MAX == q->front); //rear�� ������Ų ���� front�� ������ full
}
bool is_empty(QueueType* q) {
	return (q->rear == q->front); //front�� rear�� ������ empty
}
void enqueue(QueueType* q, element item) {
	if (is_full(q)) { error("queue is full"); }
	else {
		q->rear = (q->rear + 1) % MAX; //rear�� ������Ŵ
		q->data[q->rear] = item;
	}
}
element dequeue(QueueType* q) {
	if (is_empty(q)) { error("queue is empty"); }
	else {
		q->front = (q->front + 1) % MAX; //front�� ������Ŵ (���� front�� �ƹ� �����͵� �Ȱ��� �����Ƿ� ���� ����)
		return q->data[q->front]; //��ȯ
	}
}
void print_queue(QueueType* q) {
	printf("Queue <front:%d, rear:%d> = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX; //front+1���� ���
			printf("%3d	:", q->data[i]);
			if (i == q->rear) { break; } //rear�� �ٴٸ��� �� ����� ���̹Ƿ� ����
		} while (i != q->front); //front�� �ƴ� �� ��� �ݺ�. ���ƿ��� ����
	}
	printf("\n");
}
