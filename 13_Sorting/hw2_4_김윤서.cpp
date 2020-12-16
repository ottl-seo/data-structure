#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 50
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int partition1(int list[], int left, int right) {
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1; //�ε���
	pivot = list[left];
	printf("* pivot: %d\n", pivot); // pivot �� ���
	do {
		do { low++; } while (list[low] < pivot); // low�� �Ǻ����� �׻� �۾ƾ� �ϹǷ�. -> �� ū ���̸� ++�� �����
		do { high--; } while (list[high] > pivot);

		if (low < high) { SWAP(list[low], list[high], temp); }
	} while (low < high);

	//���� high > low�� �Ǹ�,
	SWAP(list[left], list[high], temp); //high�� �Ǻ��� ��ġ �ٲٱ�
	return high; //�Ǻ��� ��ġ ��ȯ
}
void quick_sort1(int list[], int left, int right) {
	if (left < right) {
		int p = partition1(list, left, right); //partition1 ȣ��
		quick_sort1(list, left, p - 1); // �Ǻ� ������ ���ȣ��
		quick_sort1(list, p + 1, right); //�Ǻ� �ں��� ������ ���ȣ��
	}
}
int median(int left, int right) { // left�� right ��ġ �޾Ƽ� ��� ��ġ��(median)�� ���ϴ� �Լ�
	return (left + (right - left) / 2);
}
int partition2(int list[], int left, int right) { // median of three�� ���� pivot�� �ǵ��� ����
	int mid = median(left, right); //�߰� �� ���ϱ�
	int pivot = list[mid]; // median�� ���� pivot����
	printf("* pivot: %d\n", pivot); // pivot �� ���
	left = mid; // left���� mid������ ����
	int temp, low, high;
	low = left;
	high = right + 1;
	do {
		do { low++; } while (list[low] < pivot); // low�� �Ǻ����� �׻� �۾ƾ� �ϹǷ�. -> �� ū ���̸� ++�� �����
		do { high--; } while (list[high] > pivot);

		if (low < high) { SWAP(list[low], list[high], temp); }
	} while (low < high);

	//���� high > low�� �Ǹ�,
	SWAP(list[left], list[high], temp); //high�� �Ǻ��� ��ġ �ٲٱ�
	return high; //�Ǻ��� ��ġ ��ȯ
}
void quick_sort2(int list[], int left, int right) {
	if (left < right) {
		int p = partition2(list, left, right); // partition2 ȣ���ؼ� pivot ã��
		quick_sort2(list, left, p - 1); // �Ǻ� ������ ���ȣ��
		quick_sort2(list, p + 1, right); //�Ǻ� �ں��� ������ ���ȣ��
	}
}
void printInfo(void) {
	printf("====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971063\n");
	printf("����: ������\n");
	printf("====================\n");
}
int main(void) {
	printInfo(); //���� ���

	int i, input;
	int list[MAX_SIZE];

	printf("Input size of list(1~50): ");
	scanf_s("%d", &input);
	printf("Input %d numbers in the list\n", input);

	for (i = 0; i < input; i++)
		scanf_s("%d", &list[i]); // ����Ʈ�� ���� �� �Է¹���
	printf("\n<< ���� ���� ���� >>\n");
	for (i = 0; i < input; i++)
		printf("%2d ", list[i]); // ���� �� ���
	printf("\n");

	printf("< Quick Sorting >\n");
	quick_sort1(list, 0, input - 1); // quick sort 1 ����
	printf("\n< Result >\n");
	for (i = 0; i < input; i++)
		printf("%2d ", list[i]); //���
	printf("\n");

	printf("\n< Quick Sorting <Median of three> >\n");
	quick_sort2(list, 0, input - 1); // quick sort 2 ����
	printf("\n< Result >\n");
	for (i = 0; i < input; i++)
		printf("%2d ", list[i]); // ���� �� ���
	printf("\n");

	return 0;
}