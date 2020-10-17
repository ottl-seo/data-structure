#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef char element;
typedef struct stack {
	element data[MAX]; //���ڿ�
	int top; //�ְ��� ������ �ε���
}StackType; //stack ����ü ����

void printInfo();
void init_stack(StackType* s);
void error(const char* message);
bool is_full(StackType* s);
bool is_empty(StackType* s);
element pop(StackType* s);
void push(StackType* s, element item);
bool symmetric_arr(char* string); // �迭 �̿�
bool symmetric_stack(char* string); // ���� �̿�

/* ------------------ main ------------------- */
int main() {
	printInfo(); //���� ���
	char string[MAX]; //�Է¹��� ���ڿ�

	printf("���ĺ����� ������ ���ڿ� �Է�\n");
	gets_s(string);
	
	while (strcmp(string, "0") != 0) { //�Է¹��� ���ڿ��� 0�� �ƴ� ��쿡 ��� �ݺ�
		
		if (symmetric_arr(string)) { printf("��Ī <�迭>\n"); }
		else { printf("���Ī <�迭>\n"); }
		if (symmetric_stack(string)) { printf("��Ī <����>\n"); }
		else { printf("���Ī <����>\n"); }

		printf("\n���ĺ����� ������ ���ڿ� �Է�\n");
		gets_s(string);
	}
	return 0;
}
/* ------------------ func def ------------------- */
void init_stack(StackType* s) {
	s->top = -1; //���� �ʱ�ȭ. top �ʱ���´� -1
}
void error(const char* message) { //���� ��� �Լ�
	fprintf(stderr, "%s\n", message);
	exit(1);
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
	if (is_empty(s)) { //������ ����ִٸ� ���� ����ϰ� ����
		error("stack empty");
		exit(1);
	} else { return s->data[s->top--]; }
}
void push(StackType* s, element item) {
	if (is_full(s)) { //���� ������ �ִ� ���
		error("stack Overflow");
		return;
	} else { s->data[++s->top] = item; }
}
/**/
bool symmetric_arr(char* string) { // �迭 �̿�
	int length = strlen(string);
	int end = (length + 1) / 2; //length�� ¦������ 7/2==3���� 
	for (int i = 0; i < end; i++) {
		if (string[i] != string[length - i-1]) { return false; } //�ε��� �̿�- �տ��� i��°, �ڿ��� i��° ���ڰ� �ٸ���false
	}
	return true;
}
bool symmetric_stack(char* string) { // ���� �̿�
	StackType* s = (StackType*)malloc(sizeof(StackType));
	init_stack(s); //���� �ʱ�ȭ
	int length = strlen(string);
	int end = (length + 1) / 2; //���ÿ� push�� ��ŭ�� �ε���
	int temp; //Ȧ���� ���ڿ� �Է� ��, �߰� ���ڸ� ���� ����

	for (int i = 0; i < end; i++) { push(s, string[i]); }
	if (s->top != length - end-1) { temp= pop(s); } //������ ���� ���� ���� ���� ���� �ٸ��� �ϳ��� ����
	for (int i = end; i < length; i++) {
		if (pop(s) != string[i]) { return false; }
	} //���ÿ��� pop�� �Ͱ� ���� ���ڰ� �ٸ��� false 
	if (!is_empty(s)) { return false; } //�����µ� ���ÿ� ���������� false
	return true; //�� ����ϸ� true
}

void printInfo(void) {
	printf("====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971063\n");
	printf("����: ������\n");
	printf("====================\n");
}