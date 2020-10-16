/* 7-3. ���Ḯ��Ʈ�� ������ ť �ڵ� */
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int element;
typedef struct QueueNode {
	element data;
	QueueNode* link;
}QueueNode;
typedef struct QueueType {
	QueueNode* front;
	QueueNode* rear;
}QueueType;

void error(const char* message);
void init(QueueType* q);
bool is_full(QueueType* q); //full�� ���� ����
bool is_empty(QueueType* q);
void enqueue(QueueType* q, element item);
element dequeue(QueueType* q);
void print_queue(QueueType* q);

int main() {
	QueueType* q = (QueueType*)malloc(sizeof(QueueType));
	init(q);

	printf("<������ �߰�>\n");
	for (int i = 0; i < 5; i++) {
		enqueue(q, i+1);
		print_queue(q);
	}
	printf("\n<������ ��������>\n");
	for (int i = 0; i < 5; i++) {
		dequeue(q); print_queue(q);
	}
	free(q);
	return 0;
}
void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init(QueueType* q) {
	q->front = q->rear = NULL; //���Ḯ��Ʈ ť �ʱ�ȭ: front,rear ��� NULL�� ����
}
bool is_full(QueueType* q) { //full�� ���� ����
	return 0;
}
bool is_empty(QueueType* q) {
	return (q->front == NULL); //front�� NULL�̸� empty
}
void enqueue(QueueType* q, element item) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = item;
	temp->link = NULL;
	if (is_empty(q)) { //�ϳ��� ���� ���. (�� ť�� ���)
		q->front = temp;
		q->rear = temp;
	} else {
		q->rear->link = temp;
		q->rear = temp;
	}
}
element dequeue(QueueType* q) {
	if (is_empty(q)) { error("queue is empty"); }
	QueueNode* temp = q->front;
	element data = temp->data;
	if (q->front == q->rear) { //��尡 �� ���ִ� ���- �� ť�� �������
		q->front = q->rear = NULL; 
	} else { q->front = q->front->link; } //else- front��ġ�� �Ű��ش�
	
	free(temp); //dequeue�� ��� �����Ҵ��� Ǯ���ش�
	return data;
}
void print_queue(QueueType* q) {
	QueueNode* temp = q->front;
	while (temp != NULL) {
		printf("%3d  :", temp->data);
		temp = temp->link;
	}
	/* for(QueueNode* temp= q->front; temp!=NULL; temp=temp->link){} �� �ص� ok */
	printf("\n");
}