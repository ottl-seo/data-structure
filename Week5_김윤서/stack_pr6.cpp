/* week5. ���� ǥ��� ��� �ڵ� */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef int element;
typedef struct StackType {
	element data[MAX]; //�ǿ�����(����): int �迭 --���ÿ� ������!
	int top; //�ְ������� index
}StackType;

/* ------------- stack General Function ------------- */
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
	} else {
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
int eval(char* input); //����ؼ� ����� ����ϴ� �Լ�

/* ---------------------- main ---------------------- */
int main() {
	char input[MAX]; //�Է� �ޱ� - �Է¹��� �� �迭��!

	printf("Input postfix\n");
	gets_s(input);
	printf("=================\n[postfix]\n");
	puts(input);
	printf("[Result]\n%d", eval(input));

	return 0;
}


int eval(char* input) { //����ؼ� ����� ����ϴ� �Լ�
	int first, second;
	char ch;
	StackType s;
	init(&s);
	
	/* for�� ��� */
	for (int i = 0; i < strlen(input); i++) {
		ch = input[i]; //���� �о����
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
			push(&s, ch - '0'); //���ڸ� ���ڷ� �ٲ� �� push
		else { //�������� ���
			second = pop(&s);
			first = pop(&s);

			switch (ch) {
			case '+':
				push(&s, first + second);
				break;
			case '-':
				push(&s, first - second);
				break;
			case '*':
				push(&s, first * second);
				break;
			case '/':
				push(&s, first / second);
				break;
			default:
				error("expression error\n");
			} // switch end
		} // else end
	} // for end
	return pop(&s); //���� �����
}
/* 
(*s) �� �����ϸ� ������ �����Ҵ� �������.
-- init �Լ��� �����Ҵ� �ڵ� ���� top�� �����ִ� �Ŷ�� �׳� s�� �����ϰ� &s ���簡,
	�ƴϸ� *s �ϰ� ���ο��� �Ҵ������ ��
*/

/* //while�� ver.
* 
while (*input) { //������� ������!
		ch = *input; //ù��° ����
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
			push(&s, ch-'0'); //���ڸ� ���ڷ� �ٲ� �� push
		else { //�������� ���
			second = pop(&s);
			first = pop(&s);

			switch (ch) {
			case '+':
				push(&s, first + second);
				break;
			case '-':
				push(&s, first - second);
				break;
			case '*':
				push(&s, first * second);
				break;
			case '/':
				push(&s, first / second);
				break;
			default:
				error("expression error\n");
			} // switch end
		} // else end

		input++; //��ĭ�� �ڷ� �̵�
	} //while end
*/