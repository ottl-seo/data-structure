#include <stdio.h>
#include <string.h>

void printName();
void func_recursive(char* list); //�Ųٷ� ����ϴ� ����Լ�

int main() {
	printName(); //���� ���

	char X[100]; //���� �迭 ����
	printf("Input String\n");
	gets_s(X); //�Է¹��� ���ڿ��� ���ڷ� ���� �迭�� �־��ִ� �Լ� ����
	puts("���� ��: ");
	puts(X);
	puts("���� ��: ");
	func_recursive(X); //����Լ� ȣ��

	return 0;
}

void func_recursive(char* list) { // ����Լ�
	int size = strlen(list); //���ڿ��� ����

	if (*list == '\0') { return; } //���ڿ��� ���� �ι��ڸ� ������ ����
	else {
		func_recursive(list + 1); //���� ���ڸ� �θ��� �ڱ��ڽ� ȣ��
		printf("%c", *(list)); //�� ù ���� - ���� ��Ͱ� ��� ���ư� �� ���� �������� ��µ�
	}
}
void printName(void) {
	printf("====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971063\n");
	printf("����: ������\n");
	printf("====================\n");
}