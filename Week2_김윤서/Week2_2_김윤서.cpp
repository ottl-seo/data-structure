#include <stdio.h>

void func_self(int n);
void func_repeat(int n);
void printName();

int main() {
	
	printName();

	int n;
	printf("���� ���� �Է�: ");
	scanf_s("%d", &n);
	printf("\n�ݺ��Լ� ȣ��: ");
	func_repeat(n); // �ݺ��Լ�
	printf("\n����Լ� ȣ��: ");
	func_self(n); // ����Լ�

	return 0;
}

void func_self(int n) { //����Լ�, �������� ����ϴ� �����̹Ƿ� void
	if (n < 0) { return; } // 0 ����ϸ� ����
	else
	{
		printf("%d ", n);
		return func_self(n - 1); //����Լ�
	}
}
void func_repeat(int n) { //�ݺ��Լ�, �������� ����ϴ� �����̹Ƿ� void
	for (int i = n; i >= 0; i--) {
		printf("%d ", i);
	}
}
void printName(void) {
	printf("====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971063\n");
	printf("����: ������\n");
	printf("====================\n");
}
