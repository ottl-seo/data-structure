#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

void printInfo(void) {
	printf("====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971063\n");
	printf("����: ������\n");
	printf("====================\n");
}
int partition(int list[], int left, int right) {
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1; //�ε���
	pivot = list[left];
	do {
		do { low++; } while (list[low] < pivot); // low�� �Ǻ����� �׻� �۾ƾ� �ϹǷ�. -> �� ū ���̸� ++�� �����
		do { high--; } while (list[high] > pivot);
		if (low < high) { SWAP(list[low], list[high], temp); }
		
	} while (low < high);

	//���� high > low�� �Ǹ�,
	SWAP(list[left], list[high], temp); //high�� �Ǻ��� ��ġ �ٲٱ�
	return high; //�Ǻ��� ��ġ ��ȯ
}
void quick_sort(int list[], int n, int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);

		printf("\n* pivot: %d\n", list[q]); //�Ǻ��� �� ���
		for (int i = 0; i < n; i++)
			printf("%d ", list[i]);
		printf("\nleft size: %d	right size: %d\n", q - left, right - q); //left,right ������ ���

		quick_sort(list, n, left, q - 1); //��������� left side ����
		quick_sort(list, n, q + 1, right); // right side�� ����
	}
}

int main() {
	printInfo(); //���� ���

	int i, n;
	printf("Input size of list<1~10>: ");
	scanf_s("%d", &n); //����� �Է¹޾� n�� ����
	
	int* list = (int*)malloc(sizeof(int) * n); //ũ�Ⱑ �������� �ʾ����Ƿ�, ���� �Ҵ����� �迭 ����
	printf("Input %d numbers in the list\n", n);
	for (int i = 0; i < n; i++) { scanf_s("%d", &list[i]); } //n���� ���� �Է� �ޱ�

	printf("\n< Before Sorting >\n");
	for (int i = 0; i < n; i++) { printf("%d ", list[i]); } //before sorting ����Ʈ ���� ���
	printf("\n");

	quick_sort(list, n, 0, n - 1); //�� ���� ȣ�� --�ܰ躰 ��µ� ���⼭ �Ͼ

	printf("\n\n< After Quick Sorting >\n");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]); //����Ʈ

	printf("\n");

	free(list); //�����Ҵ��� ����Ʈ�� Ǯ���ش�
	return 0;
}