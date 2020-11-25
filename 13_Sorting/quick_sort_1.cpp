/* quick sort */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))

int list[MAX_SIZE];
int n;

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
void quick_sort(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}
int main() {
	int i;
	n = MAX_SIZE;
	
	srand(time(NULL));
	printf("< Before Sorting >\n");
	for (i = 0; i < n; i++){
		list[i] = rand() % 100; //���� ���� �� ���
		printf("%d ", list[i]);
	}

	quick_sort(list, 0, n - 1); //�� ���� ȣ��
	printf("\n\n< After Sorting >\n");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]); //����Ʈ

	printf("\n");
	return 0;
}