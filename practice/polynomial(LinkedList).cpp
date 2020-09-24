#include <stdio.h>
#include <stdlib.h>

//���׽� �׸��� �����Ǵ� ���
typedef struct ListNode {
	int coef; //���
	int expon; //����
	struct ListNode* link; //���(���� ���Ḯ��Ʈ �ּ�)
}ListNode;

// ���� ����Ʈ ���
typedef struct ListType { // ���׽��� ���� �����ϴ� ���
	int size; //���׽��� �� ����
	ListNode* head; //���׽� ó�� ��� �ּ�. ���(ListNode)�� ����� ����
	ListNode* tail; //���׽� ������ ��� �ּ�
}ListType;

void error(const char* message) { //���� �޽���
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListType* create(void) { // ListType ��� ���� (���׽� ���� ������ ���)
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->head = NULL;
	plist->tail = NULL;
	plist->size = 0;
	return plist; //�����ϰ� �ʱ�ȭ�ؼ� ��ȯ�ϴ� �Լ���
}
void insert_last(ListType* plist, int coef, int expon) { //����Ʈ �������� �� �߰�, head,tail Ȱ���ؼ�
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode)); //�߰��� ��� ����

	//�޸��Ҵ� ���� ��
	if (temp == NULL) { error("memory allocation error\n"); } 

	//����� ���, ���� ����
	temp->coef = coef; 
	temp->expon = expon;
	temp->link = NULL; //�������� �߰��ϹǷ� ��ũ�� NULL;
	
	if (plist->tail == NULL) //plist�� �� ����Ʈ�� ���
		plist->head = plist->tail = temp; //ó������ ���� ��� temp
	else { //������ ��� ������
		plist->tail->link = temp; //���� �������� temp �߰�
		plist->tail = temp; //������ ���� ������ �� ��� �ּ�(temp)�� ����
	}
	plist->size++; //�� ���� ���� �ϳ� �������ֱ�++
}

void poly_print(ListType* plist) {
	ListNode* node = plist->head; //���׽��� ó�� ����(�� �ּ�)
	
	for (int i = 0; i < plist->size - 1; i++) {
		printf("%dx^%d + ", node->coef, node->expon);
		node = node->link;
	}
	printf("%dx^%d \n", node->coef, node->expon); //������ �� ���

	/* ����. ��� �� �湮�� ��, for�� ��� while(node!=NULL){} �ᵵ �� */
}
void poly_add(ListType* list1, ListType* list2, ListType* result) { // (1)+(2) = (result)
	ListNode* p1, *p2;
	p1 = list1->head; //list1 ���� �ּ�
	p2 = list2->head;
	int sum;

	while (p1 && p2) { //�� ���׽� ��ο� "���� �����ִµ���" //�̷��� ǥ����!
		
		if (p1->expon > p2->expon) { //[list 1] ���� ������ �� ū ���
			insert_last(result, p1->coef, p1->expon); //result ����Ʈ�� �� �߰�(p1��.)
			p1 = p1->link;
			//p1�� �̵�(���� head�� �ƴ�, ���� �̵�)
			//p2�� ���ڸ�- ��� ���ؼ� ū �͸� �߰��ϴ� �����
		}
		else if (p1->expon == p2->expon) { //������ ������ ��� --> ���Ѵ�
			sum = p1->coef + p2->coef;
			if (sum != 0) { insert_last(result, sum, p1->expon); }
			p1 = p1->link;
			p2 = p2->link; //�Ѵ� �������� �̵�
		}
		else { //list1�� ���� < list2�� ����
			insert_last(result, p2->coef, p2->expon);
			p2 = p2->link;
		}
	}
	while (p1) { //���� while���� ������ ��, p1���� ���� ����������
		insert_last(result, p1->coef, p1->expon); //�����ִ� ��� �� �״�� result�� ����
		p1 = p1->link;
	}
	while (p2) { //p2���� ���� ����������
		insert_last(result, p2->coef, p2->expon); //�����ִ� ��� �� �״�� result�� ����
		p2 = p2->link;
	}
}

// ---------------- main --------------------
int main() {
	ListType* list1, * list2, * result;

	list1 = create(); //���׽� ���� �� �ʱ�ȭ
	list2 = create();
	result = create();

	// list1
	insert_last(list1, 3, 12);
	insert_last(list1, 2, 8);
	insert_last(list1, 13, 0); 

	// list2
	insert_last(list2, 5, 8);
	insert_last(list2, 1, 7);
	insert_last(list2, 5, 3);
	insert_last(list2, 13, 0);

	printf("< Poly 1 >\n");
	poly_print(list1);
	printf("< Poly 2 >\n");
	poly_print(list2);

	poly_add(list1, list2, result); //�����ֱ�
	printf("\n< Poly1 + Poly2 >\n");
	poly_print(result);

	free(list1); //�����޸� �Ҵ��� �� Ǯ���ֱ�
	free(list2);
	free(result);
	return 0;
}