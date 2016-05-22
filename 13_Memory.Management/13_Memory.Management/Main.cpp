#include <iostream>

using namespace std;

#define SIZE 10

int main()
{
	int i = 0;
	int *buffer = NULL;
	int *ptr = NULL;

	buffer = (int *)malloc(sizeof(int) * SIZE);
	memset(buffer, 0x00, (sizeof(int)* SIZE)); // 메모리 초기화 메소드
	printf("Address = %p\n", &buffer);
	for (i = 0; i < SIZE; i++)
	{
		*(buffer + i) = i * 10;
	}

	for  (i = 0; i < SIZE; i++)
	{
		printf("%d\n", *(buffer + i));
	}

	buffer = (int *)realloc(buffer, (SIZE * 2)*sizeof(int));
	printf("Address = %p\n", &buffer);

	ptr = buffer + SIZE;
	for (i = SIZE; i < 2*SIZE; i++)
	{
		*(buffer + i) = i * 10;
	}

	for (i = 0; i < 2 * SIZE; i++)
	{
		printf("%d\n", *(buffer + i));
	}

	free(buffer);
	return 0;
}