#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX];
}QueueType;

void printInfo();
void init(QueueType* q); //ť �ʱ�ȭ �Լ�
bool is_full(QueueType* q);
bool is_empty(QueueType* q);
void enqueue(QueueType* q, element item); //���� �ֱ�. full���� üũ�ϱ� ���� int�� ��ȯ
element dequeue(QueueType* q); //���� ��ȯ
void print_queue(QueueType* q);  //ť ���
int print_num(QueueType* q); //���� ���� ��ȯ

int main() {
	printInfo(); //���� ���

	char input; //�Է� ���� ���ڰ� (e, d, p, 0)
	element en, de; //enqueue,dequeue �� ��
	QueueType q;
	init(&q); //ť �ʱ�ȭ

	printf("���ϴ� �۾� <E/e:enqueue, D/d:dequeue, P/p:output, 0:quit>: ");
	scanf_s("%c", &input);

	while (input != '0') { //�Է��� 0�̸� break
		switch (input) {
		case 'E': case 'e':
			printf("���� �Է�: ");
			scanf_s("\n%d", &en); //���͸� �Է°����� ���� �ʵ��� \n%d
			if (is_full(&q)) { printf("queue is full"); }
			else { enqueue(&q, en); }//�Է¹��� en���� enqueue
			break;
		case 'D': case 'd':
			if (is_empty(&q)) { printf("queue empty"); } //empty�� ��� ���
			else { printf("%3d\n", dequeue(&q)); } //dequeue�� �� ��ȯ, print
			break;
		case 'P': case 'p':
			print_queue(&q);
			break;
		default: //�̿��� �� ������
			printf("Wrong Input\n");
			break;
		}
		printf("\n���ϴ� �۾� <E/e:enqueue, D/d:dequeue, P/p:output, 0:quit>: ");
		scanf_s("\n%c", &input);
	} //end of while

	printf("\n���� ���� ������: %d\n", print_num(&q)); //���� ������ ���
	print_queue(&q); // ť ����ϰ� ����
	printf("Program Finished.");

	return 0;
}

void init(QueueType* q) {
	q->front = q->rear = 0;
}
bool is_full(QueueType* q) {
	return ((q->front) % MAX == (q->rear + 1) % MAX); //��ȭ ����
}
bool is_empty(QueueType* q) {
	return (q->front == q->rear);
}
void enqueue(QueueType* q, element item) {
	q->rear = (q->rear + 1) % MAX; //rear ����
	q->data[q->rear] = item;
}
element dequeue(QueueType* q) {
	q->front = (q->front + 1) % MAX; //front ����
	return q->data[q->front];
}
void print_queue(QueueType* q) {
	printf("Queue (front: %d, rear: %d) = ", q->front, q->rear); //front�� rear ��ġ ���
	if (!is_empty(q)) {
		int i = q->front; //front���� ����.
		do {
			i = (i + 1) % MAX; // i ���������ش�
			printf("%3d	|", q->data[i]); // ���
			if (i == q->rear) break; // i�� rear�� �������� break
		} while (i != q->front);
	}
	printf("\n");
}
int print_num(QueueType* q) {
	return (q->rear - q->front + MAX) % MAX;
}

void printInfo(void) {
	printf("====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971063\n");
	printf("����: ������\n");
	printf("====================\n");
}