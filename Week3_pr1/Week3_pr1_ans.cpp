/**/
#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b)) // �� ū �� ����ִ� macro
#define MAX_DEGREE 101

// �Լ� ���� area -------------------------------------------
typedef struct {
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
	for (int i = s.degree; i > 0; i--)
		printf("%3.1fx^%d +", s.coef[s.degree - i], i);
	printf("%3.1f\n", s.coef[s.degree]); // �����
}
polynomial poly_add1(polynomial A, polynomial B) {
	polynomial C; //��� ���׽�
	int Apos = 0, Bpos = 0, Cpos = 0; //�迭 �ε��� ����(���� ū ���� ����� �ε��� 0���� �����ϹǷ�...)
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree); //��� ���׽� ����(�� ū ������)

	while (Apos <= A.degree && Bpos <= B.degree) { //�迭ũ�Ⱑ �������� �ǵ���
		if (degree_a > degree_b) { // A�� > B��
			C.coef[Cpos++] = A.coef[Apos++]; //Ŭ ���� ��� �׳� ����
			degree_a--;
		}
		else if (degree_a == degree_b) { //A�� == B��
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--;
			degree_b--;
		}
		else
		{
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	} //end of While
	return C;

}
