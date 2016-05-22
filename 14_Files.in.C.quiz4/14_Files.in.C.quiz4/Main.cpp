#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>

typedef struct person PERSON;
struct person {
	int year;
	int month;
	int day;
	char name[128];
};

//static PERSON *ReadFile(const char *filename, int *rows);
static void PrintArray(PERSON *arr, const int rows);

static void WriteBinary(const char *filename, PERSON *persons, int size);
static PERSON *ReadBinary(const char *filename, int *size);
int main()
{
	PERSON persons[] = {
		1998, 5, 15, "Hong,Gil-Dong",
		1998, 7, 25, "Lee,Gil-Dong",
		1998, 3, 11, "Kang,Gil-Dong",
		1998, 4, 13, "Parck,Gil-Dong",
		1998, 2, 14, "Kim,Gil-Dong",
		1998, 11, 10, "Nam,Gil-Dong"
	};

	PERSON *in = NULL;
	int size = 6;

	WriteBinary("persons.bin", persons, size);
	in = ReadBinary("persons.bin", &size);
	
	PrintArray(in, size);
	free(in);

}
/*
PERSON *ReadFile(const char *filename, int *rows) {

	
}
*/

void PrintArray(PERSON *arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		printf("%d, %d, %d, %s\n", arr[i].year, arr[i].month, arr[i].day, arr[i].name);
	}
}

PERSON *ReadBinary(const char *filename, int *size)
{
	FILE *fp = NULL;
	PERSON *bin = NULL;
	if ((fp = fopen(filename, "rb")) == NULL)
	{
		printf("Can't open file\n");
		exit(1);
	}
	bin = (PERSON *)malloc(sizeof(PERSON) * *size);
	memset(bin, 0x00, (sizeof(PERSON) * *size));

	for (int i = 0; i < *size; i++)
	{
		person per;
		fread(&per, sizeof(PERSON), 1, fp);
		*(bin + i) = per;
	}

	fclose(fp);
	return bin;
}
void WriteBinary(const char *filename, PERSON *persons, int size)
{
	FILE *fp = NULL;
	if ((fp = fopen(filename, "wb")) == NULL)
	{
		printf("Can't open file\n");
		exit(1);
	}
	
	fwrite(persons, sizeof(PERSON) * size, 1, fp);

	fclose(fp);
}