/**/
#include <stdio.h>
#define MAX_DEGREE 101 //���׽��� �ִ� ������ 100���� ����. �迭 ũ�� ���ϱ� ����

// �Լ� ���� area -------------------------------------------
typedef struct  {
	int degree; //���ǿ��� �ʱ�ȭ �Ұ���
	float coef[MAX_DEGREE];
}polynomial; //polynomial �̶�� �θ��ڴ�

void print_poly(polynomial s);
polynomial poly_add1(polynomial s1, polynomial s2); // �� ���׽� ����

// (����) �Լ� ȣ�� area ------------------------------------
int main(void) {
	polynomial b = { 6, {2,3,6,0,0,0,10} }; // ����ü ���� ����!!
	polynomial a = { 4, {7,0,5,0,1} };
	polynomial c;
	print_poly(a);
	print_poly(b);
	c = poly_add1(a, b); //a�� b ���ؼ� c�� ����
	printf("----------------------------------\n");
	print_poly(c);
	return 0;
}

// �Լ� ���� area --------------------------------------------
void print_poly(polynomial s) {
	int this_degree = s.degree; //�ְ� ���� ������
	for (int i = this_degree; i > 0 ; i--) {
		printf("%.1fx^%d +", s.coef[this_degree-i], i);
	} //���� ���� 0�� ��� �� ��!!
	printf("%.1f\n", s.coef[this_degree]); // ����� ���
}

polynomial poly_add1(polynomial s1, polynomial s2) {
	polynomial big, small; // �� ������ ū �� ���� //�������� ��ũ�η� �����Ͻ�
	if (s1.degree >= s2.degree) {
		big = s1;
		small = s2;
	}	else {
		big = s2;
		small = s1; //Ÿ���� �����Ƿ� ���� ok
	}
	//float this_coef[MAX_DEGREE] = {}; //�� �������� �ʾƵ� ���� �κ�
	polynomial result; // = { big.degree,this_coef[MAX_DEGREE - 1] }; //���� ���ڷ� ���� ���� �κ� ���� �����Ϸ� ����� �ʿ� X
	result.degree = big.degree;
	int i = 0;
	int bb = big.degree;
	while (1) { //�ݺ���. �� ���ѹݺ����� �ʿ� ��������...
		if (bb == small.degree)
			break;
		//���� �ʴٸ�,
		result.coef[i] = s1.coef[i]; //ū ������ ��� �״�� ó��
		i++;
		bb--; //small�� ������ ������
	}
	for (int d = i+1; d <= big.degree; d++) { //��ġ�� ��(i+1)���� ����. ����ױ���.
		result.coef[d] = big.coef[d] + small.coef[d]; //�����ֱ�
	}
	return result;
}

