#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10

#include <stdio.h>
#include <iostream>

int main()
{
	FILE *fp = NULL;
	const char *filename = "sample.bin";
	const int size = 10;
	int out[SIZE] = { 0x00, };
	int in[SIZE] = { 0x00, };
	
	if ((fp = fopen(filename, "wb")) == NULL)
	{
		printf("Can;t open file\n");
		exit(1);
	}

	for (int i = 0; i < size; i++)
	{
		out[i] = i * 10;
		
	}

	fwrite(out, sizeof(int)*SIZE, 1, fp);

	fclose(fp);

	if ((fp = fopen(filename, "rb")) == NULL)
	{
		printf("Can;t open file\n");
		exit(1);
	}

	fread(&in, sizeof(int)*SIZE, 1, fp);

	for (int i = 0; i < SIZE; i++)
	{
		printf("%d\n", in[i]);
	}
	fclose(fp);
	/*
	if ((fp = fopen(filename, "wb")) == NULL)
	{
		printf("Can;t open file\n");
		exit(1);
	}

	for (int i = 0; i < size; i++)
	{
		int val = i * 10;
		fwrite(&val, sizeof(int), 1, fp);
	}

	fclose(fp);
	*/
	/*
	if ((fp = fopen(filename, "rb")) == NULL)
	{
		printf("Can;t open file\n");
		exit(1);
	}

	for (int i = 0; i < size; i++)
	{
		int val = 0;
		fread(&val, sizeof(int), 1, fp);
		printf("%d\n", val);
	}

	fclose(fp);
	*/
	return 0;
}