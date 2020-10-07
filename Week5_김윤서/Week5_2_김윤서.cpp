#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef char element;
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
void count_ch(char* string); //���ڿ��� ���ڷ� ���޹޾� ī��Ʈ�ϰ� ����ϴ� �Լ�

int main() {
	printInfo(); //���� ���
	char string[MAX];

	printf("�ݺ��Ǵ� ���ĺ����� ������ ���ڿ� �Է�(����� '0'�Է�)\n");
	gets_s(string);
	count_ch(string);

	return 0;
}

void init(StackType* s) { //���� �ʱ�ȭ �Լ�
	s->top = -1;
}
void error(const char* message) {
	fprintf(stderr, message); //���� �޽��� ��� �Լ�
}
bool is_full(StackType* s) { //�� á���� Ȯ��
	if (s->top == MAX) { return true; }
	else { return false; }
}
bool is_empty(StackType* s) { //����ֳ� Ȯ���ϴ� �Լ�
	if (s->top == -1) { return true; }
	else { return false; }
}
element pop(StackType* s) { // pop �Լ�
	if (is_empty(s)) {
		error("Stack Empty");
		exit(1);
	}
	else return (s->data[s->top--]); //top�� ���߿� --, data�� �迭�̹Ƿ� []
}
void push(StackType* s, element value) {
	if (is_full(s)) {
		error("Stack Overflow");
		return;
	}
	else 
		s->data[++(s->top)] = value; // ++����, s->data�� top ���� value ����.
}
element peek(StackType* s) {
	if (is_empty(s)) {
		error("Stack Empty");
		exit(1);
	}
	else return (s->data[s->top]); //top ���ҽ�Ű�� �ʰ� ���� ��ȯ
}
void count_ch(char* string) {
	int count = 0; //�� ���ڸ� ī��Ʈ�� ����
	StackType s; //���� ���� ����
	init(&s); // �ʱ�ȭ
	
	push(&s, *string); //ù��° ���ڸ� push
	string++; //�������ڷ� �̵�

	while (*string) { //string�� �������� ������ �ݺ�
		if (*string == peek(&s)) { //��� ���� ���ҿ� ������ ��� push
			push(&s, *string);
			count++; // ���� count ++
		}
		else { //�ٸ� ���� ������ ���, ���ڸ� count ���� �Բ� ���. ���� ���ð� ī��Ʈ���� �ʱ�ȭ
			printf("%d%c", count, peek(&s));
			init(&s);
			count = 0;

			push(&s, *string);
			count++; // ���� count ++
		}
		string++; // ���� ���ڷ� �̵�
	}
}

void printInfo(void) {
	printf("====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971063\n");
	printf("����: ������\n");
	printf("====================\n");
}