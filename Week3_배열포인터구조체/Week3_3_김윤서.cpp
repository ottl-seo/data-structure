#include <stdio.h>
#define MAX_SIZE 100

void printName();
void elementGeneration(int* arr, int num); //arr ���� �Է�
void elementInsertion(int* arr, int num); // ���ο� element ���� �Է�
void elementDeletion(int* arr, int num); //element ����
void elementPrint(int* arr, int num); //arr ���

int main() {
	printName(); //Print information

	int arr[MAX_SIZE]; //�迭 ����
	int choose = 1; //�ʱⰪ 1�� ����
	int num; // "How many numbers?"

	printf("How many numbers? ");
	scanf_s("%d", &(num)); //ó�� �迭 ���� ���� �Է¹���

	elementGeneration(arr, num); //�迭�� ���� �Է¹ް� ����
	elementPrint(arr, num); //���
	while (1) //���ѹݺ�, 0 �Է� �� ����(if�� �̿�)
	{
		printf("\nChoose operation:\n");
		printf("1.Insertion	2.deletion	3.output	0.program end\n");
		scanf_s("%d", &choose); //������� ���� �Է¹޾� choose�� ����

		if (choose == 0) //0 �Է��� ���
			break; //�ݺ��� ����������

		else if (choose == 1) { // �Է� 1�� ��� elementInsertion �Լ� ȣ��
			elementInsertion(arr, num);
			num++; //�迭 ũ�� ++
		}
		else if (choose == 2) { //�Է� 2�� ��� elementDeletion �Լ� ȣ��
			elementDeletion(arr, num);
			num--; //�迭 ũ�� --
		}
		else if (choose == 3) { elementPrint(arr, num); } //�Է� 3�� ��� elementPrint �Լ� ȣ��
		else {
			printf("Wrong Input"); //0~3 �ܿ� �ٸ� �� �Է��� ���
			continue; //�ݺ��� ���
		}
	}
	return 0;
}
void elementGeneration(int* arr, int num) { //arr ���� �Է��ϴ� �Լ�

	printf("\nInput %d numbers ", num);
	for (int i = 0; i < num; i++)
		scanf_s("%d", &arr[i]); //arr�迭�� �� ���ҷ� ����
}
void elementInsertion(int* arr, int num) {
	int location, value; //������ ��ġ�� ��
	printf("\nInput location and value to insert: ");
	scanf_s("%d %d", &location, &value); //�Է¹޾� ����
	for (int i = 0; i < location + 2; i++) {
		arr[num - i] = arr[num - i-1]; //�ڷ� ��ĭ�� �б�
	}
	arr[location-1] = value; //���ϴ� �ڸ��� ����.
}
void elementDeletion(int* arr, int num) {
	int location; //������ ��ġ
	printf("\nInput location to delete: ");
	scanf_s("%d", &location);
	for (int i = 0; i < location + 2; i++) {
		arr[location - 1 + i] = arr[location + i];
	}
}
void elementPrint(int* arr, int num) {
	printf("\nArray:	");
	for (int i = 0; i < num; i++)
		printf("%3d", arr[i]);
}

void printName(void) {
	printf("====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971063\n");
	printf("����: ������\n");
	printf("====================\n");
}