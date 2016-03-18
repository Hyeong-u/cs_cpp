#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
//#include <stdio.h>

int main()
{
	//shortcircuit.c
	int a = 10, b = 20, c = 3;
	printf("a = %d, b = %d, c = %d\n", a, b, c);

	c = (a++ == 11) && (b++ == 20);
	printf("c = (a++ == 11) && (b++ == 20)의 연산 후 각각의 값 \n");
	printf("a = %d, b = %d, c = %d\n\n", a, b, c);
	printf("a = %d, b = %d, c = %d\n", a, b, c);

	c = (a++ == 11) && (b++ == 20);
	printf("c = (a++ == 11) && (b++ == 20)의 연산 후 각각의 값 \n");
	printf("a = %d, b = %d, c = %d\n\n", a, b, c);
	printf("a = %d, b = %d, c = %d\n", a, b, c);

	c = (a++ == 12) || (b++ == 20);
	printf("c = (a++ == 12) || (b++ == 20)의 연산 후 각각의 값 \n ");
	printf("a = %d, b = %d, c = %d\n\n", a, b, c);
	printf("a = %d, b = %d, c = %d\n", a, b, c);

	c = (a++ == 12) || (b++ == 20);
	printf("c = (a++ == 12) || (b++ == 20)의 연산 후 각각의 값 \n ");
	printf("a = %d, b = %d, c = %d\n\n", a, b, c);
	printf("a = %d, b = %d, c = %d\n", a, b, c);
	/*
	int m, n;
	char x, y;

	printf("두 문자 입력. ");
	scanf("%c%c", &x, &y);
	printf("두 정수 입력. ");
	scanf("%d%d", &m, &n);

	printf("\n 입력한 두 문자 %c(%d), %c(%d)를 비교하면 \n", x, x, y, y);
	printf("\n 입력한 두 문자 %c(%d), %c(%d)를 비교하면 \n", x, x, y, y);
	*/

	/*
	int x, y;
	int addition, substraction, multiplication, division, modulus;

	printf("정수1 입력 : ");
	//scanf("%d", &x);
	std::cin >> x;
	printf("정수2 입력 : ");
	//scanf("%d", &y);
	std::cin >> y;

	addition = x + y;
	substraction = x - y;
	multiplication = x * y;
	division = x / y;
	modulus = x % y;

	printf("%d + %d는 %d \n", x, y, addition);
	printf("%d - %d는 %d \n", x, y, substraction);
	printf("%d * %d는 %d \n", x, y, multiplication);
	printf("%d / %d는 %d \n", x, y, division);
	printf("%d %% %d는 %d \n", x, y, modulus);
	*/

	return  0;

}