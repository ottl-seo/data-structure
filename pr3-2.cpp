/* week3 �迭�� ������ ���� 1 */

#include <stdio.h>
#define SIZE 6
void get_integers(int list[]) {
	printf("6���� ������ �Է��ϼ���: \n");
	for (int i = 0; i < SIZE; i++)
		scanf_s("%d", &list[i]);
}
int cal_sum(int * list) { // int cal_sum(int list[])�� ���� �ǹ�
	int sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum += *(list + i); //i��ŭ �� �̵��� ���� '��'�� ��� �����ֱ�
	}
	return sum;
}
int main(void) {
	int list[SIZE];
	get_integers(list); //�迭 �̸��� ��������
	printf("sum = %d\n",cal_sum(list));
	
	return 0;
}
