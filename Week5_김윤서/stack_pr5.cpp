/* ���Ḯ��Ʈ�� ������ ���� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct StackNode { //���� ��� ����ü
	element data; //���ϱ� ���� �ƴ� //�����ͺ�
	struct StackNode* link; //��ũ
}StackNode;

typedef struct {
	StackNode* top; //������ top ��� �ּ�. top�� �ε����� �ƴ϶�, head ����� �ּҰ� ��!!
}LinkedStackType;

void init(LinkedStackType* s) {
	s->top = NULL; //���Ḯ��Ʈ �ʱ�ȭ ���: head��带 NULL��
}
void error(const char* message) {
	fprintf(stderr, message);
}
bool is_full(LinkedStackType* s) {
	return 0; //full�� �� �� ����...
}
bool is_empty(LinkedStackType* s) {
	return (s->top == NULL); //top�� NULL�̸� ������
}
element pop(LinkedStackType* s) {
	if (is_empty(s)) {
		error("Stack empty");
		exit(1);
	}
	else {
		StackNode* temp = s->top; //���Ḹ Ǯ���ִ°� �ƴ϶�, free���� ���ֱ� ����!
		element data = temp->data; //��ȯ�� �����Ͱ�
		s->top = s->top->link; 
		free(temp); // !!!
		return data;
	}
}
void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item; //������ ����
	temp->link = s->top; //���� ������ ����� link�� ������ top�� ����Ŵ
	s->top = temp; //���� ������ ��尡 ���ο� top�� ��
}
void print_stack(LinkedStackType* s) {	
	for (StackNode* go = s->top; go!= NULL; go = go->link) {
		printf("%d -> ", go->data);
	}
	printf("NULL \n"); //������ ��ũ�� NULL
}
int main() {
	LinkedStackType s; //���� ���� ��������� ���� (??)
	init(&s);
	
	for (int i = 0; i < 10; i++) {
		push(&s, i);
	}
	printf("< Stack >\n");
	print_stack(&s); // ���

	for (int i = 0; i < 5; i++)
		pop(&s);
	printf("\n < Pop 1 >\n");
	print_stack(&s);
	for (int i = 0; i < 5; i++)
		pop(&s);
	printf("\n < Pop 2 >\n");
	print_stack(&s);

	return 0;
}