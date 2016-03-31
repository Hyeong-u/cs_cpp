#include <iostream>
#include <string>
using namespace std;
struct Student
{
	int studentID;
	string name;
};
void printArray(int &ref, const int size);
void printStudent(Student *ptr, const int size);
int main()
{
	/*
	int *arr = new int[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i * 10;
	}
	printArray(*arr, 10);
	printArray(arr[0], 10);
	delete arr;
	arr = NULL;
	*/

	Student students[5] = {
	{ 20150001, "Kim" },
	{ 20150002, "Lee" },
	{ 20150003, "Oh" },
	{ 20150004, "Park" },
	{ 20150005, "Gu" } };
	printStudent(students, 5);

}
void printStudent(Student *ptr, const int size)
{
	Student *begin = ptr;
	Student *end = ptr + size;
	for (; begin != end; begin++)
	{
		cout << "StudentID = " << begin->studentID << endl;
		cout << "Name = " << (*begin).name << endl;
	}
}
void printArray(int &ref, const int size)
{
	int *begin = &ref;
	int *end = &ref + size;
	for (int i = 0;begin != end; begin++, i++)
	{
		cout << "arr[" << i << "] = " << *begin << endl;
	}
	cout << endl;
}


