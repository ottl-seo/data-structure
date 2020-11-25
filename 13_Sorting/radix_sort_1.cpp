/* radix sort */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 100
#define BUCKETS 10 //������
#define DIGITS 4 //�ִ� 4�ڸ������� ����
#define SIZE 10

void printInfo(void);

/*------------------ Queue func ------------------*/
typedef int element;
typedef struct QueueType {
	int front, rear;
	element data[MAX_QUEUE_SIZE]; //ť
}QueueType;

void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init_queue(QueueType* q) { //ť �ʱ�ȭ �Լ�
	q->front = q->rear = 0; 
}
int is_empty(QueueType* q) {
	return (q->front == q->rear); //front�� rear�� ������ empty
}
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front); //���� ť�� ����, rear+1�� front�� ������ ��ȭ
}
void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("Queue is full");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("Queue is empty");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE; //front�� �ϳ� ����ְ� 
	return q->data[q->front]; //front�� �ִ� ���� �����Ѵ�
}

/*------------------ radix_sort func ------------------*/
void radix_sort(int list[], int n) {
	int i, buc, dig, factor = 1;
	QueueType queue[BUCKETS];

	for (buc = 0; buc < BUCKETS; buc++) init_queue(&queue[buc]); //ť �ʱ�ȭ
	
	for (dig = 0; dig < DIGITS; dig++) { // �ڸ����� ���� �ݺ��� ����
		for (i = 0; i < n; i++)
			enqueue(&queue[(list[i] / factor) % 10], list[i]); //�����͵��� �ڸ����� ���� ť�� ����

		for (buc = i = 0; buc < BUCKETS; buc++) { //��Ŷ���� ������ list�� ��ġ�� ����
			while (!is_empty(&queue[buc])) //������� ������
				list[i++] = dequeue(&queue[buc]);
		}
		factor *= 10; //�ڸ����� �����ϴ� factor *10
	}
}

/*------------------ main ------------------*/
int main() {
	printInfo(); //���� ���
	
	int list[SIZE];
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
		list[i] = rand() % 100;

	radix_sort(list, SIZE);
	for (int i = 0; i < SIZE; i++)
		printf("%d ", list[i]);
	printf("\n");

	return 0;
}

void printInfo(void) {
	printf("====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971063\n");
	printf("����: ������\n");
	printf("====================\n");
}