/* ���߿��Ḯ��Ʈ - insertion/deletion */

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct dListNode {
	element data;
	struct dListNode* llink;
	struct dListNode* rlink;
}dListNode;

void init(dListNode* phead) { //���߿��Ḯ��Ʈ �ʱ�ȭ
	phead->llink = phead; //�ڱ� �ڽ��� ����Ű����
	phead->rlink = phead;
}
void dinsert(dListNode* pnode, element value) { //���ο� �����͸� ���� ��� pnode�� �����ʿ� insert
	dListNode* newnode = (dListNode*)malloc(sizeof(dListNode)); //���ο� ��� ����
	newnode->data = value;
	newnode->llink = pnode;
	newnode->rlink = pnode->rlink;
	pnode->rlink->llink = newnode;
	pnode->rlink = newnode;
}
void ddelete(dListNode* head, dListNode* removed) { //�� �տ� �ִ� ������� removed�� delete
	if (removed == head) { return; } //���� ������ ����Ʈ
	removed->rlink->llink = head; //delete�� ����� ������ ����� llink�� head�� ����Ŵ
	head->rlink = removed->rlink;
	free(removed);
}
void print_dlist(dListNode* phead) { //���߿��Ḯ��Ʈ ���
	dListNode* p = NULL;
	for (p = phead->rlink; p != phead; p = p->rlink) //head�� ������ ������ �ϳ��� ���
		printf("%3d", p->data);
	printf("\n");
}

int main() {
	dListNode* head = (dListNode*)malloc(sizeof(dListNode)); //head ���
	init(head); //head ��� �ʱ�ȭ

	printf("ù ��ġ�� ��� 5�� ������ �߰�\n");
	for (int i = 1; i < 6; i++) {
		dinsert(head, i); //0~4 head��� �����ʿ� insert
		print_dlist(head);
	}
	printf("\nù��° ��� 5�� ������ ����\n");
	print_dlist(head);
	for (int i = 1; i < 6; i++) {
		ddelete(head, head->rlink); //head����� ������ ��带 �ϳ��� ����
		print_dlist(head);
	}
	free(head);
	return 0;
}