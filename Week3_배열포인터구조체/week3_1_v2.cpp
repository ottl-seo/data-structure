#include <stdio.h>
#include <string.h>

void printName();
void func_recursive(char * list, int size); //�Ųٷ� ����ϴ� ����Լ�

int main() {
	printName(); //���� ���

	char X[100]; //���� �迭 ����
	int size;
	printf("Input String\n");
	gets_s(X); //�Է¹��� ���ڿ��� ���ڷ� ���� �迭�� �־��ִ� �Լ� ����
	puts("���� ��: ");
	puts(X);
	puts("���� ��: ");
	size = strlen(X);
	func_recursive(X,size); //����Լ� ȣ��

	return 0;
}

void func_iterative(char* list) { //�ݺ��Լ�
	int size = strlen(list); //���ڿ��� ����
	for (int i = 0; i < size; i++)
		printf("%c", *(list + size-1 - i));
}

void func_recursive(char* list, int size) { // ����Լ�
	if (size== 0) { return; }
	else {
		printf("%c", *(list + size - 1)); //���� �������� �ִ� ����
		return func_recursive(list, size - 1);
	}
}
void printName(void) {
	printf("====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971063\n");
	printf("����: ������\n");
	printf("====================\n");
}