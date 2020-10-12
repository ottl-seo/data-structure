#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int num;
	ListNode* link;
}ListNode;

void printInfo();
void error(const char* message);
ListNode* insert_first(ListNode* plist, int value); //�Ǿտ� ����
ListNode* insert(ListNode* head, ListNode* pre, int value); //Ư�� ��ġ ����
ListNode* insert_sort(ListNode* plist, int num); //������������ insert
void print_list(ListNode* plist); //����Ʈ ��� �Լ�

/* ------------------ main -----------------*/
int main() {
	printInfo(); //���� ���

	int input;
	ListNode* head = NULL; //���Ḯ��Ʈ ����

	printf("Input data to insert to linkedlist <0 to quit>\n");
	scanf_s("%d", &input);
	
	while (input != 0) { //������������ �ֱ�
		head = insert_sort(head, input);
		print_list(head);
		scanf_s("%d", &input);
	} // 0������ ����
	
	printf("Program finished.\n");
	return 0;
}
/* ---------------- func def ----------------- */
void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_first(ListNode* head, int value) { //�� �տ� �ֱ�
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //������ ��� ����
	if (p == NULL) { //�޸� �Ҵ� ���� ��
		error("���� �޸� �Ҵ� ����");
		exit(1);
	}
	p->num = value;
	p->link = head; // p->link�� ���� ��� ����Ű��
	head = p; //head�����Ͱ� ����Ű�� �� p�� ����
	return head;
}
ListNode* insert(ListNode* head, ListNode* pre, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //������ ��� ����
	if (p == NULL) { //�޸� �Ҵ� ���� ��
		error("���� �޸� �Ҵ� ����");
		exit(1);
	}
	p->num = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}
ListNode* insert_sort(ListNode* head, int value) {
	if (head == NULL) { return insert_first(head, value); }  //�� ����Ʈ�� ��.
	else if (head->link == NULL) { //��尡 1���� ��.
		ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //������ ��� ����
		if (value >= head->num) { //�� ū ���̸� ��� �ڿ� ����
			p->num = value; //�� ����
			head->link = p;
			return head;
		} else { return insert_first(head, value); } //�� ���� ���̸� �� �տ�.
	}
	ListNode* pre = head; // ��� ���� -�ݺ����� �̿�
	if (value <= (head->num)) { return insert_first(head, value); } //���� ���� ���.
	while (pre->link != NULL) { //pre�� head�������� ������
		
		if (value >= (pre->num) && value <= (pre->link->num)) { //�´� ��ġ ã����, �����ϰ� ��ȯ
			return insert(head, pre, value);
		}
		pre = pre->link; //�ݺ� ����
	} //end of while
	return insert(head, pre, value); // while�� �����µ� ���� �� �Ǹ� ������ ������ ����
}
void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%3d ->", p->num);
	printf("  NULL\n");
}
void printInfo(void) {
	printf("====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971063\n");
	printf("����: ������\n");
	printf("====================\n");
}