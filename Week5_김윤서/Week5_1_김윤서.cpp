#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef int element;
typedef struct stack {
	element data[MAX];
	int top; //�ְ��� ������ �ε���
}StackType;

void printInfo();
void init(StackType* s); //���� �ʱ�ȭ �Լ�
void error(const char* message); //���� ��� �Լ�
bool is_full(StackType* s); 
bool is_empty(StackType* s);
element pop(StackType* s); //pop �Լ�
void push(StackType* s, element value); //push �Լ�
void dec_to_bin(int decimal); //�������� �������� ��ȯ�� ����ϴ� �Լ�

int main() {
	int input; //�Է¹��� ����. �ʱⰪ �ƹ��ų� ����
	
	printInfo(); //���� ���
	printf("������ �Է� <����: 0 ���� �Է�>\n");
	scanf_s("%d", &input);
	
	while (input > 0) {
		dec_to_bin(input);
		printf("\n\n");

		printf("������ �Է� <����: 0 ���� �Է�>\n");
		scanf_s("%d", &input);
	}
	return 0;
}
void init(StackType* s) { //���� �ʱ�ȭ �Լ�
	s->top = -1;
}
void error(const char* message) {
	fprintf(stderr, message); //���� �޽��� ��� �Լ�
}
bool is_full(StackType* s) {
	if (s->top == MAX) { return true; }
	else { return false; }
}
bool is_empty(StackType* s) {
	if (s->top == -1) { return true; }
	else { return false; }
}
element pop(StackType* s) {
	if (is_empty(s)) {
		error("Stack Empty");
		exit(1);
	}
	else {
		return (s->data[s->top--]); //top�� ���߿� --, data�� �迭�̹Ƿ� []
	}
}
void push(StackType* s, element value) {
	if (is_full(s)) {
		error("Stack Overflow");
		return;
	}
	else {
		s->data[++(s->top)] = value; // ++����, s->data�� top ���� value ����.
	}
}
void dec_to_bin(int decimal) {
	int r; //������
	StackType s;
	init(&s); //���� �����ϰ� �ʱ�ȭ
	while (decimal != 0) {
		r = decimal % 2;
		push(&s, r); //���ÿ� �������� �־��ش�
		decimal /= 2; //2�� ���� ������ ��� �ݺ�. ���� 0�� �ɶ�����.
	}
	printf("������ ǥ��: ");
	while (!is_empty(&s)) { printf("%d", pop(&s)); }
}
void printInfo(void) {
	printf("====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971063\n");
	printf("����: ������\n");
	printf("====================\n");
}