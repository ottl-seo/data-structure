#include <stdio.h>

void bin(int n);
void printName();

int main() {
	printName();

	int n;
	printf("���� ���� �Է�: ");
	scanf_s("%d", &n);
	printf("\n������ %d�� ����ǥ��: ",n);
	bin(n); //����Լ� ȣ��
	putchar('\n');

	return 0;
}
void bin(int n) { //�ݺ��Լ� ����
	int rest; //������
	int array[100]; //�迭
	int count = 0; // �迭 ũ�� count

	while (true)
	{
		if (n == 0) { break; }
		array[count] = n % 2; // �迭�� 2�� ���� ������ �߰�
		n /= 2; // ��. �̰� ��� �ݺ��ϸ鼭 n�� 0�� ������ �ݺ�

		count++; //�迭 ũ�� ++
	}
	for (int i = count-1; i >= 0; i--) {
		printf("%d", array[i]); //�ڿ������� ���
	}
}

void printName(void) {
	printf("====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971063\n");
	printf("����: ������\n");
	printf("====================\n");
}
