#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>


static int *ReadFile(const char *filename, int *rows, int *cols);
static void PrintArray(int *arr, const int rows, const int cols);

static int *ReadBinary(const char *filename, int *rows, int *cols);
static void WriteBinary(const char *filename, int *arr, const int rows, const int cols);
int main() 
{
	
	const char *filename = "sample.txt";
	int *arr = NULL;
	int *bin = NULL;
	int rows = 0, cols = 0;
	arr = ReadFile(filename, &rows, &cols);
	printf("Rows = %d, Cols = %d\n", rows, cols);
	PrintArray(arr, rows, cols);
	printf("\n");

	WriteBinary("sample.bin", arr, rows, cols);
	bin = ReadBinary("sample.bin", &rows, &cols);
	printf("Rows = %d, Cols = %d\n", rows, cols);
	PrintArray(bin, rows, cols);

	free(arr);
	free(bin);
	
}

int *ReadFile(const char *filename, int *rows, int *cols) {

	FILE *fp = NULL;
	int row = 0, col = 0;
	int *arr = NULL;
	if ((fp = fopen(filename, "r")) == NULL) {
		printf("Can't open file\n");
		exit(1);
	}
	fscanf(fp, "%d %d", rows, cols);
	arr = (int *)malloc(sizeof(int) * *rows* *cols);
	memset(arr, 0x00, (sizeof(int)* *rows* *cols));

	for (row = 0; row < *rows; row++){
		for (col = 0; col < *cols; col++){
			int val = 0;
			fscanf(fp, "%d", &val);
			*(arr + (row* *cols) + col) = val;
		}
	}

	fclose(fp);
	return arr;
}

void PrintArray(int *arr, const int rows, const int cols)
{
	int row = 0, col = 0;
	for (int row = 0; row < rows; row++) {
		for (col = 0; col < cols; col++) {
			
			printf("%d ", *(arr + (row* cols) + col));
		}
		printf("\n");
	}
}

static int *ReadBinary(const char *filename, int *rows, int *cols)
{
	FILE *fp = NULL;
	int row = 0, col = 0;
	int *bin = NULL;
	if ((fp = fopen(filename, "rb")) == NULL)
	{
		printf("Can't open file\n");
		exit(1);
	}
	bin = (int *)malloc(sizeof(int) * *rows* *cols);
	memset(bin, 0x00, (sizeof(int)* *rows* *cols));
	fread(&row, sizeof(int), 1, fp);
	fread(&col, sizeof(int), 1, fp);

	for (int row = 0; row < *rows; row++)
	{
		for (int col = 0; col < *cols; col++)
		{
			int val = 0;
			fread(&val, sizeof(int), 1, fp);
			*(bin + (row* *cols) + col) = val;
		}
	}


	fclose(fp);
	return bin;
}
static void WriteBinary(const char *filename, int *arr, const int rows, const int cols)
{
	FILE *fp = NULL;
	if ((fp = fopen(filename, "wb")) == NULL)
	{
		printf("Can't open file\n");
		exit(1);
	}
	fwrite(&rows, sizeof(int), 1, fp);
	fwrite(&cols, sizeof(int), 1, fp);
	fwrite(arr, sizeof(int) * rows * cols, 1, fp);
	
	fclose(fp);
}