#include <iostream>

int *pi;
int *plk = NULL;
void foo() {
	pi = (int*)malloc(8 * sizeof(int));

	free(pi);
}

void genPLK() {
	int *ptr = plk; // �ڵ鸵 �� �� �ִ� �����͸� ����� ptr�� ������ ���.
	plk = (int *)malloc(2 * sizeof(int));
	/* Expect PLK as pointer variable is incremented
	   past beginning of block */
	plk++;
}

void main() {
	pi = (int*)malloc(4 * sizeof(int)); // �̰��� �ٽ� �� ���̶�� free�� �ϴ� ���� ����.
	//�������̸� ���� ����� �� �޸� ���� �ȿ��� free�� �Ѵ�.
	free(pi); //�̷�������
	/* Expect MLK : foo leaks it */
	foo();
}