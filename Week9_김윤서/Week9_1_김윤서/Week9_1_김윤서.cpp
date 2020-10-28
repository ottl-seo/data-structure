#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	TreeNode* left, * right;
}TreeNode;

void printInfo();
void inorder(TreeNode* exp);
int node_count(TreeNode* exp);
int leaf_count(TreeNode* exp);
int get_height(TreeNode* exp);
void balanced(TreeNode* exp);
void greater_num(TreeNode* exp, int num);

int main() {
	printInfo(); //���� ���

	int check; //number to check
	TreeNode n1 = { 1,NULL,NULL };
	TreeNode n2 = { 2,NULL,NULL };
	TreeNode n3 = { 3,&n1,&n2 };
	TreeNode n4 = { 4,NULL,NULL };
	TreeNode n5 = { 5,NULL,NULL };
	TreeNode n6 = { 6,&n4,&n5 };
	TreeNode n7 = { 7,&n3,&n6 };
	TreeNode* exp = &n7;

	inorder(exp);
	printf("\n\nNumber of nodes in Tree: %d", node_count(exp));
	printf("\nHeight of the Tree: %d", get_height(exp));
	printf("\nNumber of leafs in Tree: %d", leaf_count(exp));
	printf("\nBalanced Tree? ");
	balanced(exp);
	printf("\nInput a number to check: ");
	scanf_s("%d", &check);
	printf("\nnumbers greater than %d: ", check);
	greater_num(exp,check);

	return 0;
}
void inorder(TreeNode* exp) { /* ���� ��ȸ (LVR) */
	if (exp) {
		inorder(exp->left);
		printf("[%d]", exp->data);
		inorder(exp->right);
	}
}
int node_count(TreeNode* exp) {
	if (exp == NULL)return 0;
	else { return node_count(exp->left) + node_count(exp->right) + 1; }
}
int leaf_count(TreeNode* exp) {
	if (exp == NULL) { return 0; }
	else {
		if (exp->left == NULL && exp->right == NULL) { return 1; } //�ܸ������ ���
		else { return leaf_count(exp->left) + leaf_count(exp->right); } //child�� �ִ� ���- ������
	}
}
int get_height(TreeNode* exp) {
	if (exp == NULL) { return 0; }
	else {
		int l_height = get_height(exp->left); //���� ����
		int r_height = get_height(exp->right); //������ ����
		if (l_height >= r_height)return l_height + 1;
		else return r_height + 1;
	}
}
void balanced(TreeNode* exp) {
	if (exp == NULL) { return; }
	else {
		int l_height = get_height(exp->left);
		int r_height = get_height(exp->right);
		if (abs(l_height - r_height) > 1) { printf("No"); } //�� subtree�� ���̰� 1 �̻� ���̳��� no ���
		else { printf("Yes"); } //���̰� 1 �����̸� Yes ���
	}
}
void greater_num(TreeNode* exp, int num) {
	TreeNode* root = exp;
	if(root){
		greater_num(exp->left, num); //LVR ������� ��ȸ�ϸ� num���� �� ū ���� ã�´�
		if (root->data > num) { printf("%d ",root->data); } //num���� ���� �� ū ��带 ã����, ���
		greater_num(exp->right, num);
	}
}
void printInfo(void) {
	printf("====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971063\n");
	printf("����: ������\n");
	printf("====================\n");
}