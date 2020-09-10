#include <stdio.h>

void printName(void) {
	printf("====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971063\n");
	printf("����: ������\n");
	printf("====================\n");
}

double iterative(int n); //�ݺ��Լ�
double recursive(int n); //����Լ�

int main() {
	printName(); //���� ���

	int n; //�Է¹��� ���� ����
	while (true) {
		printf("���� ���� �Է�: ");
		scanf_s("%d", &n); //n�� ����

		if (n <= 0) { //�Է°��� 0�����̸� ����
			break;
		}

		printf("Result from iterative: %.2f", (double)(iterative(n))); // �Ҽ��� ��°�ڸ����� ���
		printf("\nResult from recursive: %.2f", (double)(recursive(n))); // �Ҽ��� ��°�ڸ����� ���
		printf("\n\n");
	}
}

double iterative(int n) { //�ݺ��Լ�
	double result = 0;
	for (int i = 1; i <= n; i++) {
		result += (double)1 / i;
	}
	return result;
}
double recursive(int n) { //����Լ�
	if (n == 1) { return 1; } //n==1�̸� recursive(0)-> ����
	else {
		return (double)1 / n + recursive(n - 1); //���ڸ� �ٲ㼭 �ڱ� �ڽ� ȣ��
	}
}
