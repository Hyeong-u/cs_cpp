#include <iostream>

void genFNH() {
	int fnh = 0;
	free(&fnh);
}

void genFUM() {
	int *fum = (int *)malloc(4 * sizeof(int));
	free(fum + 1);
	free(fum);
	free(fum);  // �޸𸮿� �������� �ؾ� ������ �� �� �ִ�.
}