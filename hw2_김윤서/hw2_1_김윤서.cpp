#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode { //��ũ�� ����Ʈ�� ����
	int key;
	TreeNode* left, * right;
}TreeNode;

int get_max_node(TreeNode* root) { /* �ִ� ���ϱ� */
	int root_key, left_max, right_max, max_node = 0; //���� ���� ������ �ʱ�ȭ
	if (root) {
		root_key = root->key; //��Ʈ�� key�� ����
		left_max = get_max_node(root->left); // left child���� ���� ū �� ã��
		right_max = get_max_node(root->right); // right child���� ���� ū �� ã��
		
		if (left_max > right_max) max_node = left_max;
		else max_node = right_max;
		if (root_key > max_node) max_node = root_key; //���� root�� ���� ���� Ŭ ���
	}
	return max_node; // �ִ� ����
}
int get_min_node(TreeNode* root) { /* �ּڰ� ���ϱ� */
	int root_key, left_min, right_min, min_node = INT_MAX; //���� ū ������ �ʱ�ȭ
	if (root) {
		root_key = root->key; //��Ʈ�� key�� ����
		left_min = get_min_node(root->left); // left child���� ���� ���� �� ã��
		right_min = get_min_node(root->right); // right child���� ���� ���� �� ã��

		if (left_min < right_min) min_node = left_min;
		else min_node = right_min;
		if (root_key < min_node) min_node = root_key; //���� root�� ���� ���� ���� ���
	}
	return min_node; // �ּڰ� ����
}

int get_sum(TreeNode* root) { /* key �հ� ���ϱ� */
	int sum = 0;
	if (root == NULL) return 0;
	else {
		sum += get_sum(root->left);
		sum += root->key;
		sum += get_sum(root->right); // LVR ������� ��ȸ�ϸ� �� ���ϱ�
		return sum;
	}
}
int get_only_child(TreeNode* root) { /* child�� �� ���� ����� �� ���ϱ� */
	int num = 0; //child�� �� ���� ����� ����
	if (root == NULL) return 0;
	else { //LVR ������ ��ȸ�ϸ� num++
		num += get_only_child(root->left);
		if (!(root->left == NULL && root->right == NULL) && ((root->left == NULL) || (root->right == NULL)))
			num++; // left,right�� �Ѵ� NULL(�ܸ����)�� �ƴ� && �� �� �ϳ��� NULL�� ����� ���
		num += get_only_child(root->right);
		return num; ///��� ����(num) ����
	}
}
void printInfo(void) {
	printf("====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971063\n");
	printf("����: ������\n");
	printf("====================\n");
}

int main() {
	printInfo(); //���� ���
	TreeNode n0 = { 11, NULL, NULL };
	TreeNode n1 = { 2, &n0, NULL };
	TreeNode n2 = { 5, &n1, NULL };
	TreeNode n3 = { 13, &n2, NULL };
	TreeNode n4 = { 25, &n3, NULL };
	TreeNode n5 = { 8, NULL, NULL };
	TreeNode n6 = { 3, NULL, &n5 };
	TreeNode n7 = { 21, &n4, &n6 };
	TreeNode* exp = &n7; // n7�� root�����

	printf("\nSum of keys in Binary tree: %d\n", get_sum(exp));
	printf("Num of one child nodes: %d\n", get_only_child(exp));
	printf("Max value: %d\n",get_max_node(exp));
	printf("Min value: %d\n", get_min_node(exp));

	return 0;
}