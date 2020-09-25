#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101 //�迭 �ִ� ũ�⸦ 101��

struct { //����ü �̷��� ������ ���, ������ ���Ӱ� �������� ���� !
	float coef; //���
	int expon; //����
} terms[MAX_TERMS] = { {4,7},{8,6},{7,5} ,{1,1},{10,3},{-7,1},{1,0} }; //terms�� ��������. ���ڷ� ���� ���ص� ��𼭵� ��밡��
int avail = 7; //���� ����ִ� ��ġ�� index(���Ƿ� ����)

void add_one(float coef, int expon) { //����� ���� �Է��ϸ� ���ο� ������ terms�� �߰�
	if (avail > MAX_TERMS) { //�ִ�ũ�� �Ѿ ���
		printf("���� �Ұ�\n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail].expon = expon;
	avail++;
}
void print_poly(int s, int e) {
	for (int i = s; i < e; i++)
		printf("%.1fx^%d + ", terms[i].coef, terms[i].expon);
	printf("%.1fx^%d", terms[e].coef, terms[e].expon);
}
void poly_add(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) { // A+B = C
	// As(A start), Ae(A end)
	// Cs, Ce �ּҰ����� �޴� ����??? - ��ȯ���� �ΰ��� �� �����Ƿ� call by reference

	*Cs = avail; //��� ���׽��� ���� ��ġ
	while (As <= Ae && Bs <= Be) { //start-end ��Ű����
		if (terms[As].expon > terms[Bs].expon) { // A���׽��� ������ �� ū ���
			add_one(terms[As].coef, terms[As].expon);
			As++; //�ϳ� �� �̵�
		}
		else if (terms[As].expon == terms[Bs].expon) { //���� ��� --> ���Ѵ�
			if (terms[As].expon + terms[Bs].expon != 0) //���ļ� ����� 0�� ���- �� �߰� x
				add_one(terms[As].expon + terms[Bs].expon, terms[As].coef);
			As++; Bs++;
		}
		else { //B ������ �� Ŭ ���
			add_one(terms[Bs].expon, terms[Bs].coef);
			Bs++;
		}
	}
	for (; As <= Ae; As++) //B���׽��� �� ó���ǰ� A�� ���� ���(����: As<=Ae)--> ���� A ���׽� ����
		add_one(terms[As].coef, terms[As].expon);
	for (; Bs <= Be; Bs++)
		add_one(terms[Bs].coef, terms[Bs].expon);
	*Ce = avail - 1; //�� �߰� �� avail�� �ڵ����� �����Ǿ����Ƿ� ���� ��ġ�� avail-1
}

int main() {
	int As = 0, Ae = 3, Bs = 4, Be = 6; //���׽�A�� 0~3, B�� 4~6 (�ε��� ����)
	int Cs, Ce;
	poly_add(As, Ae, Bs, Be, &Cs, &Ce); //������� C�� �ּҷ� ������
	
	printf("\n< A >\n");
	print_poly(As, Ae);
	printf("\n< B >\n");
	print_poly(Bs, Be);

	printf("\n< C >\n");
	print_poly(Cs, Ce);

	return 0;
}