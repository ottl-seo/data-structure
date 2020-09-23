/* ���Ḯ��Ʈ (�ܾ� �����ϱ�) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[10]; //member�� ���ڹ迭�� ����ü
}element; //element��� ���ο� �ڷ��� ����

typedef struct ListNode {
	element data; //���ڿ�
	struct ListNode* link; //���Ḯ��Ʈ�� link
}ListNode;

ListNode* insert_first(ListNode* head, element value); //�� �տ� ���� �Լ�
ListNode* insert(ListNode* head, element value, int location); //���ϴ� ��ġ�� ���� �Լ�
void print(ListNode* head); //head�κ��� link�� ����� ����� data�� ��� ���

int main() {
	ListNode* head = NULL;
	element data;
	
	strcpy_s(data.name, "Apple"); //data����Ʈ�� �� �տ� "Apple" insert
	head = insert_first(head, data); //head ����Ʈ�� data ����
	print(head);

	strcpy_s(data.name, "Banana");
	head = insert_first(head, data);
	print(head);

	strcpy_s(data.name, "Orange");
	head = insert_first(head, data);
	print(head);

	return 0;
}

//�Լ� ���� Area --------------------------------------
ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //���ο� ��� p ����
	p->data = value;

	p->link = head; 
	head = p; //head�� p�� �ٲ�����ٰ� �����ϱ�

	/* ���� �� �ڵ�
	p->link = head->link;
	head->link = p;
	// �̷��� �ϸ� �� �ǳ�??? ---�� ��. insert �ڵ��� */

	return head;
}
void print(ListNode* head) { //head�κ��� link�� ����� ����� data�� ��� ���
	ListNode* p = NULL;
	for (p = head; p != NULL; p = p->link) //�ݺ��� �ڵ�
		printf("%s ->", p->data.name);
	printf(" NULL\n");
}

// ���� �� insert �ڵ�------ ���߿� Review �ϱ�
// ppt���� location�� ���� �ʰ�, ���� ��ġ pre�� ���� �޾Ҵ�
ListNode* insert(ListNode* head, element value, int location) { //���ϴ� ��ġ�� ���� �Լ�
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //���ο� ��� p ����
	ListNode* pre = head; //
	for (int i = 0; i < location-1; i++) {
		pre = pre->link; //location ���� ��ġ�� pre �̵��ϱ�
	}
	p->data = value;
	p->link = pre->link;
	pre->link = p;

	return head;
}