#include <iostream>

using namespace std;

void foo(int *pi) {
	int j;
	*pi = j;
}

void bar() {
	int i = 10;
	foo(&i);
	printf("i = %d\n", i);
}

int main()
{
	bar();
	return 0;
}