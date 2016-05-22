#include <iostream>

int *pi;
int *plk = NULL;
void foo() {
	pi = (int*)malloc(8 * sizeof(int));

	free(pi);
}

void genPLK() {
	int *ptr = plk; // 핸들링 할 수 있는 포인터를 만들고 ptr을 가지고 논다.
	plk = (int *)malloc(2 * sizeof(int));
	/* Expect PLK as pointer variable is incremented
	   past beginning of block */
	plk++;
}

void main() {
	pi = (int*)malloc(4 * sizeof(int)); // 이것을 다시 쓸 것이라면 free를 하는 것이 좋다.
	//가급적이면 내가 만들어 낸 메모리 범주 안에서 free를 한다.
	free(pi); //이런식으로
	/* Expect MLK : foo leaks it */
	foo();
}