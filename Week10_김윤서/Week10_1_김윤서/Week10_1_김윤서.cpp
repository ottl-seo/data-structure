#include <stdio.h>
#include <stdlib.h>
#define MAX 200

typedef int element;
typedef struct HeapType {
	element heap[MAX];
	int heap_size;
}HeapType;

void printInfo();
void insert_max_heap(HeapType* h, element item);
element delete_max_heap(HeapType* h);
void insert_min_heap(HeapType* h, element item);
element delete_min_heap(HeapType* h);
void print_heap(HeapType* h);

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}
void init(HeapType* h) { //heap �ʱ�ȭ
	h->heap_size = 0;
}

int main() {
	printInfo(); //���� ���
	char input; // I/D/X �߿� ����� ����
	int value; //insert/delete �ÿ� �Է¹��� ��
	HeapType* max_heap = create();
	HeapType* min_heap = create();
	init(max_heap);
	init(min_heap);
	do {
		printf("* operation ����: Insert(I) / Delete(D) / Exit(X): ");
		scanf_s("\n%c", &input);

		switch (input) {
		case'I': case'i':
			printf("Input value to Insert: ");
			scanf_s("%d", &value);
			insert_max_heap(max_heap, value); //value�� max_heap�� insert
			insert_min_heap(min_heap, value); //value�� min_heap�� insert
			printf("<Max Heap>\n");
			print_heap(max_heap);
			printf("<Min Heap>\n");
			print_heap(min_heap);
			printf("\n\n");
			break;
		case'D':case'd':
			delete_max_heap(max_heap); //max_heap���� delete
			delete_min_heap(min_heap); //min_heap���� delete
			printf("<Max Heap>\n");
			print_heap(max_heap);
			printf("<Min Heap>\n");
			print_heap(min_heap);
			printf("\n\n");
			break;
		case 'X':
			break;
		default:
			printf("Wrong Input\n");
			break;
		}
	} while (input != 'X'); //�Է��� X�̸� �ݺ��� ����

	free(max_heap); free(min_heap);
	return 0;
}
void printInfo(void) {
	printf("====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971063\n");
	printf("����: ������\n");
	printf("====================\n");
}
void insert_max_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size); // ��� �߰�
	while ((i != 1) && (item > h->heap[i / 2])) { // Ʈ���� �Ž��� �ö󰡸鼭 �θ� ����� key ���� ��
		h->heap[i] = h->heap[i / 2]; // �߰� �� ��� key������ ���� ��� �θ��带 downheap
		i /= 2; // �ε����� �θ� �ڸ��� �̵�
	}
	h->heap[i] = item; // ������ġ�� ���ο� ��� insert

}
element delete_max_heap(HeapType* h) {
	int parent = 1, child = 2; // �� ��° ������ root ���� �� ����
	element item = h->heap[1]; // �����Ǵ� ���(���� �� ��ȯ)
	element temp = h->heap[h->heap_size--]; // ���� ��带 temp�� ����(��� ���� �� heap_size�� ����)
	while (child <= h->heap_size) { // �ִ� ���ܱ��� Ʈ���� �������鼭 �ڽĳ�� key���� temp key ��
		if ((child < h->heap_size) && (h->heap[child] < h->heap[child + 1])) // sibling�� ���� �� �� �� ū �� ã��
			child++; // sibling�� �񱳴�� ��尡 ��(subtree ����)
		if (temp >= h->heap[child])
			break; // �ڽ� ��庸�� �ű� ��� key�� ũ�� ��ġ Ȯ���Ǿ� �ݺ� ����
		h->heap[parent] = h->heap[child]; // �ڽ� ��� key�� �� ũ�� parent ��忡 child ��� ����
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp; // Ȯ����ġ(parent)�� �űԳ�� insert
	return item;

}
void insert_min_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);
	while ((i != 1) && (item) < h->heap[i / 2]) {
		h->heap[i] = h->heap[i / 2];
		i /= 2; //�ε��� ���ο� ��ġ(�θ�)�� �̵�
	}
	h->heap[i] = item; //���� ��ġ�� insert
}
element delete_min_heap(HeapType* h) {
	int parent = 1, child = 2;
	element item = h->heap[1];
	element temp = h->heap[(h->heap_size)--]; //���ܳ�带 temp�� ����
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child] > h->heap[child + 1]))
			child++;
		if (temp < h->heap[child])break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp; //Ȯ�� ��ġ(parent)�� �ű� ��� insert
	return item;
}
void print_heap(HeapType* h) {
	for (int i = 1; i < h->heap_size+1; i++)
		printf("%d ", h->heap[i]);
	printf("\n");
}