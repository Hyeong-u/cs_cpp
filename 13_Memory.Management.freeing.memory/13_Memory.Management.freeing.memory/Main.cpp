#include <iostream>

void genFNH() {
	int fnh = 0;
	free(&fnh);
}

void genFUM() {
	int *fum = (int *)malloc(4 * sizeof(int));
	free(fum + 1);
	free(fum);
	free(fum);  // 메모리에 엑세스를 해야 프리를 할 수 있다.
}