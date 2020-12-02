/* 14���� �ǽ�1,2 : ����Ž�� (����/����) */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

int list[SIZE];

/* �Ϲ� ����Ž�� */
int seq_search(int key, int low, int high) { //low, high�� ���۰� �� �ε���
	for (int i = low; i <= high; i++)
		if (list[i] == key) return i;
	return -1;
}
int seq_search2(int key, int low, int high) {
	int i;
	list[high + 1] = key;
	for (i = low; list[i] != key; i++); // ����Ʈ�� ������ ���� �ʿ�x (key�� ������ �ٷ� for�� ����)
	
	if (i == high + 1) return -1; // ������ ��ġ���� üũ�ߴٸ� Ž�� ����
	else return i;
}
int main() {
	srand(time(NULL));
	int key, res1,res2;
	for (int i = 0; i < SIZE; i++)
		list[i] = rand() % 1000; //0~999
	for (int i = 0; i < SIZE; i++) {
		if (i % 10 == 0) putchar('\n'); //����
		printf("%4d", list[i]);
	}
	printf("\n\nInput key to search: ");
	scanf_s("%d", &key);
	res1 = seq_search(key, 0, SIZE - 1);
	res2 = seq_search2(key, 0, SIZE - 2); //Ű ������ ���� �迭�� ������ ���� ���ܵξ�� ��

	/* if (res1 != -1) printf("\n%d is found in position %d by sequential search 1\n", key, res1); */
	if (res2 != -1) printf("\n%d is found in position %d! (by sequential search 2)\n", key, res2);
	else printf("search failed\n");
}