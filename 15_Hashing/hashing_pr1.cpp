/* 1. ��������� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KEY_SIZE 10 //Ž��Ű�� �ִ� ����
#define TABLE_SIZE 13 //ht�� ũ��(prime number)
#define empty(item) (strlen(item.key)==0)
#define equal(item1, item2) (!strcmp(item1.key, item2.key))

typedef struct element {
	char key[KEY_SIZE];
}element;

element hash_table[TABLE_SIZE]; //2���� �迭ó��

void init_table(element ht[]) {
	for (int i = 0; i < TABLE_SIZE; i++)
		ht[i].key[0] = NULL; //��� ���̺��� 0�� Ű�� �η� �ʱ�ȭ
}
int transform(char* key) { //�� ������ �ƽ�Ű�ڵ带 ���ؼ� ���ڷ� ��ȯ
	int num = 0;
	while (*key)
		num += *key++; //���� ���ڷ� �Ѿ++
	return num;
}
int hash_function(char* key) { //modulo ���� ����� hash function
	return transform(key) % TABLE_SIZE; // k mod M
}
void hash_lp_add(element item, element ht[]) { //key�� hash table�� insert
	int i, hash_value;
	hash_value = i = hash_function(item.key); //hash �� ���
	while (!empty(ht[i])) { //������ Ű���� �̹� ���������
		if (equal(ht[i], item)) {
			fprintf(stderr, "search key duplicated\n");
			exit(1);
		}
		i = (i + 1) % TABLE_SIZE; //���� ��ġ ã��
		if (i == hash_value) { //������ �� �ڸ��� ���ƿ���
			fprintf(stderr, "table is full\n"); //���̺��� �� �� ��
			exit(1);
		}
	}
	ht[i] = item; //�ش� ��ġ�� ��������� insert
}
void hash_lp_search(element item, element ht[]) { //item�� �ִ��� ã�� �Լ�
	int i, hash_value;
	hash_value = i = hash_function(item.key);
	while (!empty(ht[i])) { //���� ������

		if (equal(item, ht[i])) { //������ ã�Ҵٰ� ǥ��, ����
			fprintf(stderr, "%s: location = %d\n", item.key, i);
			return;
		}
		i = (i + 1) % TABLE_SIZE; // i++
		if (i == hash_value) { //�� ���� �� ����
			fprintf(stderr, "not in the table\n");
			return;
		}
	} // end of while
	fprintf(stderr, "not in the table\n");
}
void hash_lp_print(element ht[]) {
	int i;
	printf("\n==============================\n");
	for (i = 0; i < TABLE_SIZE; i++)
		printf("[%d]	%s\n", i, ht[i].key);
	printf("==============================\n\n");
}
int main() {
	const char* s[7] = { "do","for","if","case","else","return","function" };
	element e;

	for (int i = 0; i < 7; i++) {
		strcpy(e.key, s[i]); // e.key�� ���� �ܾ���� ����
		puts(s[i]);
		hash_lp_add(e, hash_table); //�ؽ����̺� e�� �ִ´�
		hash_lp_print(hash_table); //�ؽ����̺� ����Ʈ
	}
	return 0;
}