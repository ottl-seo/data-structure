/* Week4_2_������ */
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct dListNode {
	element data; // ���� �Է� �޾� ����
	dListNode* llink; // left
	dListNode* rlink; // right
}dListNode;

void printName();
void init(dListNode* phead);
void dinsert(dListNode* head, element value); //head ���� ���� �����ϸ�, ��� �ڿ� ��� ����
void ddelete(dListNode* head, dListNode* removed);
void print_dlist(dListNode* phead);
dListNode* search_dlist(dListNode* head, element value); //�� ã�Ƽ� �ּҰ� ��ȯ

int main() {
	printName(); //���� ���
	int input;
	int choose; //number to SEARCH and DELETE
	dListNode* head = (dListNode*)malloc(sizeof(dListNode)); //intLIst ����
	dListNode* search; //�˻������ ��� delete�� ���ڷ� ������ ���

	init(head); //head ��� �ʱ�ȭ!!!!!!!
	while (true) //insert
	{
		printf("Input an Integer to add <0 to quit>: ");
		scanf_s("%d", &input);
		if (input == 0) { break; } //�Է°� 0�� ��� break
		else {
			dinsert(head, input); //insert
			continue;
		}
	}
	printf("\n<LIST>\n");
	print_dlist(head); //intList ���
	printf("\nInput a number to SEARCH and DELETE: ");
	scanf_s("%d", &choose); // �˻��ؼ� ���� ���� �Է¹���

	search = search_dlist(head, choose); //���� �ִ��� ������, ������ �� �ּҸ� ������ ����
	if (search == NULL) { printf("%d is not in the LIST\n",choose); } //search�� ���� ���
	else {
		ddelete(head, search); //search�� ������ ��带 �����Ѵ�
		printf("%d is found and deleted\n", choose);
	}
	printf("<LIST>\n");
	print_dlist(head); //intList ���

	return 0;
}
void init(dListNode* phead) { //���߿��Ḯ��Ʈ �ʱ�ȭ
	phead->rlink = phead;
	phead->llink = phead; //��-�� ��ũ�� �ڱ� �ڽ� ����Ű��...
}
void dinsert(dListNode* head, element value) { //���ο� �����͸� head�� �����ʿ� insert
	dListNode* newnode = (dListNode*)malloc(sizeof(dListNode)); //���ο� ��� ����
	newnode->data = value; //newnode�� ������ �ֱ�

	newnode->llink = head;
	newnode->rlink = head->rlink;
	head->rlink->llink = newnode;
	head->rlink = newnode;
}
void ddelete(dListNode* head, dListNode* removed) { //�� �տ� �ִ� ������� removed�� delete
	if (removed == head) { return; } //���� ������ ����Ʈ: ���� �� �����Ƿ� �׳� ����
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}
void print_dlist(dListNode* phead) { //���߿��Ḯ��Ʈ ���
	dListNode* p = phead->rlink;
	while (p != phead) {
		printf("%3d", p->data);
		p = p->rlink;
	}
	/*
	dListNode* p = NULL;
	for (p = phead->rlink; p != phead; p = p->rlink) //head�� ������ ������ �ϳ��� ���
		printf("%3d", p->data);
	*/
	printf("\n");
}
dListNode* search_dlist(dListNode* head, element value) {
	// ã���� �ش� ��带, ������ NULL ��ȯ
	dListNode* p = head->rlink; // p ����- head�� ���� ������.
	while (p!=head) //p�� head�� ���ƿ��� �ݺ��� ����
	{
		if ((p->data) == value) { return p; }
		p = p->rlink; // ���� ���� �̵�
	}
	return NULL; //���� ��� NULL ��ȯ
}
void printName(void) {
	printf("====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971063\n");
	printf("����: ������\n");
	printf("====================\n");
}

/* < ���߿��Ḯ��Ʈ ������ �� >
* void init() �Լ��� ������ �ʱ�ȭ ���� ��
* insert �Լ����� ������� ��츦 ó������ �ʿ� ���� (if(head==NULL){} �� �ʿ� XX)
* insert �Լ������� �׳� 4���� �����ڵ常 �ۼ����ָ� ��!
* for��/while���� ���� ������ p!=head; //head�� �ٽ� ���ƿ��� ����
*/