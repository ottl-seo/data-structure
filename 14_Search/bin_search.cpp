/* 2. ����Ž��- ���/�ݺ� */
#include <stdio.h>
#include <stdlib.h>
// #include <time.h> 
//#include "quick_sort.h" //�� ���� �������
#define SWAP(x,y,t)((t)=(x), (x)=(y), (y)=(t))
#define SIZE 100

//int list[SIZE];

/* ��� */
int bin_search_recursive(int list[], int key, int low, int high) {
	int mid;
	if (low <= high) { //low, high�� ���ڷ� �ָ� �ݺ�
		mid = (low + high) / 2;
		if (key == list[mid]) return mid;
		else if(key < list[mid]) bin_search_recursive(list, key, low, mid - 1); //���� ���� �ٽ� Ž��
		else return bin_search_recursive(list, key, mid + 1, high); //������ ���� �ٽ� Ž��
	}
	else return -1; // when failed
}
/* �ݺ� */
int bin_search_iterative(int list[], int key, int low, int high) {
	int mid;
	while (low <= high) { //while�� �Ѵ�!!
		mid = (low + high) / 2;
		if (key == list[mid]) return mid;
		else if (key < list[mid]) high = mid - 1; //���� mid �Ʒ��ʿ� ������ mid ������ ����
		else low = mid + 1; //�Ʒ��� ����
	}
	return -1; // when failed
}

int main() {
	int key, res;
	int size = 10; // int list[size]={...}�� ���ǰ� �Ұ�...

	int list[10] = { 0,3,5,6,17,18,30,67,72, 89 };

	// rand, sort ���� ����
	for (int i = 0; i < size; i++) {
		printf("%3d", list[i]);
	}
	printf("\n\nInput key to search: ");
	scanf_s("%d", &key);

	printf("\n< ���ȣ�� ��� >\n");
	res = bin_search_recursive(list, key, 0, size);
	if (res != -1)
		printf("\n%d is found in position %d!\n", key, res);
	else printf("Search failed\n");

	printf("\n< �ݺ�ȣ�� ��� >\n");
	res = bin_search_iterative(list, key, 0, size);
	if (res != -1)
		printf("\n%d is found in position %d!\n", key, res);
	else printf("Search failed\n");

	return 0;
}
/* < �Լ��� ���ڰ� �迭�� ��� >
	* ���ǿ��� list[] �Ǵ� *list 
	* ���ο��� ������ ���� list

* �迭 ���� ��, list[����] = {1,2,3};�� �� �ȴ�. []�ȿ��� ������� ���� ��

*/