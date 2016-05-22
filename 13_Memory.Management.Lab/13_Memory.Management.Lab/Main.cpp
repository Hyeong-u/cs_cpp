#include <iostream>

using namespace std;

void CreateArray(int **arr, int size);
void FillArray(int *arr, int size);
void PrintArray(int *arr, int size);

int main(int argc, char* argv[])
{
	// 두가지 방법, 리턴, 선언하고 매개변수로 넣어주는 것
	// int *ptr = CreateArray(10);
	// free(ptr);  30%

	// int *ptr = NULL;
	// CreateArray(&ptr, 10);
	// free(ptr); 70% 리턴이 있으면 더 느리기 때문에.

	int *arr = NULL;
	CreateArray(&arr, 10);
	FillArray(arr, 10);
	PrintArray(arr, 10);

	printf("\n");
	free(arr);
	return 0;
}

void CreateArray(int **arr, int size) {
	*arr = (int *)malloc(size*sizeof(int));
	memset(*arr, 0x00, size*sizeof(int));
}

void FillArray(int *arr, int size) {
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = i;
	}
}

void PrintArray(int *arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << endl;
	}
}