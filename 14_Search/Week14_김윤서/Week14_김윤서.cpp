/* �ǽ�4. ���μ���Ž�� */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#define SIZE 100
//#define INDEX_SIZE 256

typedef struct itable {
	int key;
	int index;
}itable;

itable index_list[SIZE]; //index table
int list[SIZE];
int itable_size; //INDEX_SIZE ��� �������� ���

/* ����Ž�� �Լ� */
int seq_search(int key, int low, int high) {
	int i;
	for (int i = low; i <= high; i++)
		if (list[i] == key) return i;
	return -1;
}
/* index_list ���� �� ��� */
void create_itable(int interval) {
	itable_size = (int)((SIZE - 1) / interval); //interval���� ���� ���������� itable_size�� ����
	for (int i = 0; i <= itable_size; i++) {
		index_list[i] = { list[i * interval], i * interval }; //index_list�� i��° ���ҷ� key�� �ε����� insert
		printf("%2d: %4d\n", i, list[i * interval]);
	}
	printf("\n");
}
/* ���μ���Ž�� �Լ� */
int indexed_search(int key, int n) { //ã�� Ű, ����Ʈ ����� ���ڷ� ����
	int i, low, high;
	if (key<list[0] || key>list[n - 1]) return -1; //���� ���� ��� ����
	for (i = 0; i < itable_size; i++)
		if (index_list[i].key <= key && index_list[i + 1].key > key) break; //���� �´� �ε��� ã���� break
	if (i == itable_size) { //�ε������� �� ū ���� ���
		low = index_list[i - 1].index;
		high = n;
	}
	else {
		low = index_list[i].index;
		high = index_list[i + 1].index;
	}
	printf("\n< Indexed Search ��� >\n");
	printf("Index location: %d\n", i);
	return seq_search(key, low, high); //�� �ٺ��� ����Ž��
}
void printInfo(void) {
	printf("====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971063\n");
	printf("����: ������\n");
	printf("====================\n");
}
/* ============== main ============== */
int main() {
	printInfo();
	srand(time(NULL));
	int interval, key, res;
	for (int i = 0; i < SIZE; i++)
		list[i] = rand() % 1000;
	for (int i = 0; i < SIZE; i++) {
		if (i % 10 == 0) putchar('\n'); // 10������ ����
		printf("%4d", list[i]);
	}
	printf("\n\n< Sorting Result >\n");
	quick_sort(list, 0, SIZE); // quick sort ȣ��
	for (int i = 0; i < SIZE; i++) { // �������� �Ȱ��� ���
		if (i % 10 == 0) putchar('\n');
		printf("%4d", list[i]);
	}

	printf("\n\nInput index interval(1~100): "); // interval �Է¹ޱ�
	scanf_s("%d", &interval);
	printf("\n< Index table >\n");
	create_itable(interval); // itable ���� �� ���-

	printf("Input key to search: ");
	scanf_s("%d", &key);

	res = indexed_search(key, SIZE);
	if (res != -1)
		printf("%d is found in position %d\n", key, res);
	else printf("search failed\n");
}