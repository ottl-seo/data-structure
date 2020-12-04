/* 4. ����Ž�� */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quick_sort.h"
#define SIZE 100
#define INDEX_SIZE 256

typedef struct itable {
	int key;
	int index;
}itable;
itable index_list[INDEX_SIZE]; //index table

int list[SIZE];
int interpol_search(int key, int n) {
	int i, low, high;
	low = 0;
	high = n - 1;
	while ((key <= list[high]) && (key > list[low])) { //key���� low�� high ���̿� ���� ��
		i = ((float)(key - list[low]) / (list[high] - list[low]) * (high - low)) + low; //��ʽ� �̿��Ͽ� �ε��� ����
		if (key > list[i]) low = i + 1; //���� ������ �ͺ��� Ŭ ���, ���� ����
		else if (key < list[i]) high = i - 1; //���� ���, ������ ����
		else low = i; // �ٷ� ���� ��� low=i �ϰ� �Ʒ����� low�� ������
	}
	if (list[low] == key) return low; // Ž�� ����
	else return -1; // Ž�� ����
}
int main() {

	int key, res;
	srand(time(NULL));
	
	for (int i = 0; i < SIZE; i++)
		list[i] = rand() % 1000; //0~999
	/* ���� �� */
	for (int i = 0; i < SIZE; i++) {
		if (i % 10 == 0) putchar('\n'); //����
		printf("%4d", list[i]);
	}
	quick_sort(list, 0, SIZE);
	printf("\n\n< Sorting Result >\n"); /* ���� �� */
	for (int i = 0; i < SIZE; i++) {
		if (i % 10 == 0) putchar('\n');
		printf("%4d", list[i]);
	}
	printf("\n\nInput key to search: ");
	scanf_s("%d", &key);

	printf("\n< Interpolation Search Result >\n");
	res = interpol_search(key, SIZE);
	if (res != -1)
		printf("\n%d is found in position %d!\n", key, res);
	else printf("Search failed\n");

}

/*
int size = 10; // int list[size]={...}�� ���ǰ� �Ұ�...
int list[10] = { 0,3,5,6,17,18,30,67,72, 89 };
// rand, sort ���� ���� */