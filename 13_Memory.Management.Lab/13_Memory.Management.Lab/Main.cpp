#include <iostream>

using namespace std;

void CreateArray(int **arr, int size);
void FillArray(int *arr, int size);
void PrintArray(int *arr, int size);

int main(int argc, char* argv[])
{
	// �ΰ��� ���, ����, �����ϰ� �Ű������� �־��ִ� ��
	// int *ptr = CreateArray(10);
	// free(ptr);  30%

	// int *ptr = NULL;
	// CreateArray(&ptr, 10);
	// free(ptr); 70% ������ ������ �� ������ ������.

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