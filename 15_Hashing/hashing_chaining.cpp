#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 
#define TABLE_SIZE 7 // M

typedef struct element {
	int key;
}element;

struct list {
	element item;
	struct list* link;
};

struct list* hash_table[TABLE_SIZE]; // item�� link�� ������ �������� �迭

int hash_function(int key) {
	return key % TABLE_SIZE; //modulo ���� ����� �ؽ��Լ�
}
void hash_chain_add(element item, struct list* ht[]) {
	int hash_value = hash_function(item.key); //�ؽù���� �ؽ��Լ���

	struct list* ptr; //���ο� ���
	struct list * node = ht[hash_value], * node_before = NULL; // ��Ʈ ���node�� �� �ڿ� ��ġ�ϴ� before���
	
	for (; node; node_before = node, node = node->link) { //�ش� ��ġ�� ��� �˻�
		if (node->item.key == item.key) { //���� ���� ��������� �ߺ�-
			fprintf(stderr, "%d is already stored\n", item.key);
			return;
		}
	}
	ptr = (struct list*)malloc(sizeof(struct list));
	ptr->item = item;
	ptr->link = NULL;
	if (node_before)
		node_before->link = ptr; //������ ��ġ�� �߰�
	else //�ش� ��ġ�� ��尡 �����Ƿ�
		ht[hash_value] = ptr; // ù ���� ����	
}
void hash_chain_search(element item, struct list* ht[]) {
	struct list* node;
	int hash_value = hash_function(item.key); //ã������ value ���ϱ�
	for (node = ht[hash_value]; node; node = node->link) //�ش� �ؽ����̺�� ���� item�� �ִ��� ����
		if (node->item.key == hash_value) {
			fprintf(stderr, "%d is found\n", item.key);
			return;
		}
	fprintf(stderr, "%d is found\n", item.key);
}
void hash_chain_print(struct list* ht[]) {
	struct list* node;
	int i;
	printf("\n============================\n");
	for (i = 0; i < TABLE_SIZE; i++) {
		printf("[%d]", i);
		for (node = ht[i]; node; node = node->link)
			printf("-%3d", node->item.key);
		printf("\n");
	}
	printf("\n============================\n");
}

int main() {
	int data[SIZE] = { 8,1,9,6,13 };
	element e;
	for (int i = 0; i < SIZE; i++) {
		e.key = data[i];
		hash_chain_add(e, hash_table);
		hash_chain_print(hash_table);
	}
	for (int i = 0; i < SIZE; i++) {
		e.key = data[i];
		hash_chain_search(e, hash_table);
	}
	return 0;
}