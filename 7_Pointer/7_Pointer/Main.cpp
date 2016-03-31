#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

void test(int *ptr)
{
	*ptr = 50;
}

void test(int &ptr)
{
	ptr = 60;
}

int main()
{
	/*
	char *p;
	p = new char[20];
	
	char c[] = "Hello";
	const char* pc = c; // 값을 상수화, 포인터 assign 가능
	pc[2] = 'a';
	pc = p;

	char *const cp = c; // 포인터를 상수화, 값은 assign 가능
	cp[2] = 'a';
	cp = p;

	const char *const cpc = c; // 모두다 상수화 포인트와 값,
	cpc[2] = 'a';
	cpc = p;
	*/
	/*
	char *ptr;
	ptr = new char[5];

	strcpy(ptr, "Bye");
	ptr[0] = 'u';
	cout << "Value of ptr is " << *ptr << endl;
	delete[] ptr;
	ptr = NULL;
	*/
	
	
	/*
	int i = 10;
	int *ptr = &i;
	test(&i);

	cout << i << endl;

	test(i);

	cout << i << endl;
	*/


	/*
	int x = 5;
	int &z = x;

	//int &y;
	
	cout << "Address of x is " << &x << endl;
	cout << "Address of z is " << &z << endl;

	cout << "Value of x is " << x << endl;
	cout << "Value of z is " << z << endl;

	z = 9;

	cout << "Address of x is " << &x << endl;
	cout << "Address of z is " << &z << endl;

	cout << "Value of x is " << x << endl;
	cout << "Value of z is " << z << endl;
	*/
	/*
	char msg[] = "Hello";
	char* ptr = 0x00L;
	ptr = msg;

	cout << msg << endl;
	cout << ptr << endl;

	ptr++;
	*ptr = 'a';

	cout << msg << endl;
	cout << ptr << endl;

	ptr--;
	cout << ptr << endl;
	*/


	/*
	char ch = 'A';
	char* q = &ch;
	*q = 'Z';
	char* p = q;
	*/

	/*
	int x = 12;
	int* ptr = &x;
	cout << "Address of x is " << &x << endl;
	cout << "Address of ptr is " << &ptr << endl;
	cout << "Value of ptr is " << ptr << endl;
	cout << "Value of *ptr is " << *ptr << endl;

	*ptr = 5;
	cout << "Address of x is " << &x << endl;
	cout << "Address of ptr is " << &ptr << endl;
	cout << "Value of ptr is " << ptr << endl;
	cout << "Value of *ptr is " << *ptr << endl;
	*/
	/*
	char str[8] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	char *ptr;
	ptr = str;

	cout << "*(ptr + 0)" << *(ptr + 0) << endl;
	cout << "*(ptr)" << *(ptr) << endl;
	cout << "*(ptr + 1)" << *(ptr + 1) << endl;
	cout << "*ptr++" << *ptr++ << endl;
	cout << "*(ptr)" << *(ptr) << endl;

	

	cout << str << endl;

	cout << "*(str+0)" << *(str + 0) << endl;
	cout << "*(str+1)" << *(str + 1) << endl;
	cout << "*(str+2)" << *(str + 2) << endl;
	cout << "*(str+3)" << *(str + 3) << endl;
	cout << "*(str+10)" << *(str + 10) << endl;

	cout << endl;
	cout << "str[0]" << str[0] << endl;
	cout << "str[1]" << str[1] << endl;
	cout << "str[2]" << str[2] << endl;
	cout << "str[3]" << str[3] << endl;
	cout << "str[4]" << str[10] << endl;
	*/
	
	/*
	int i = 10;
	int* ptr;

	cout << "Address of ptr is " << &ptr << endl;
	cout << "Value of ptr is " << ptr << endl;
	ptr = &i;
	*ptr = 7000;
	i = 7000;
	cout << "Address of ptr is " << &ptr << endl;
	cout << "Value of ptr is " << ptr << endl;
	cout << "Value of *ptr is " << *ptr << endl;
	i = 20;
	//*ptr = 9000;
	cout << "Value of i is " << i << endl;
	

	int* ptr1 = 0x00L;
	cout << "Address of ptr1 is " << &ptr1 << endl;
	cout << "Value of ptr1 is " << ptr1 << endl;

	int* ptr2 = NULL;
	cout << "Address of ptr2 is " << &ptr2 << endl;
	cout << "Value of ptr2 is " << ptr2 << endl;
	
	int* ptr3 = new int;
	cout << "Address of ptr3 is " << &ptr3 << endl;
	cout << "Value of ptr3 is " << ptr3 << endl;

	//ptr3 = 100;
	*ptr3 = 9000;
	cout << "Value of ptr3 is " << ptr3 << endl;
	*/

	/*
	int x;
	float number;
	char ch;

	cout << "Address of x is " << &x << endl;
	cout << "Address of number is " << &number << endl;
	cout << "Address of ch is " << static_cast<void*> (&ch) << endl;
	*/


	/*
	char str[8] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	cout << str << endl;

	cout << "*(str+0)" << *(str + 0) << endl;
	cout << "*(str+1)" << *(str + 1) << endl;
	cout << "*(str+2)" << *(str + 2) << endl;
	cout << "*(str+3)" << *(str + 3) << endl;
	cout << "*(str+10)" << *(str + 10) << endl;

	cout << endl;
	cout << "str[0]" << str[0] << endl;
	cout << "str[1]" << str[1] << endl;
	cout << "str[2]" << str[2] << endl;
	cout << "str[3]" << str[3] << endl;
	cout << "str[4]" << str[10] << endl;
	*/

}