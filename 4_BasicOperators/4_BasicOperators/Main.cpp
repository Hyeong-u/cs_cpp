#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
//#include <stdio.h>

int main()
{
	//shortcircuit.c
	int a = 10, b = 20, c = 3;
	printf("a = %d, b = %d, c = %d\n", a, b, c);

	c = (a++ == 11) && (b++ == 20);
	printf("c = (a++ == 11) && (b++ == 20)�� ���� �� ������ �� \n");
	printf("a = %d, b = %d, c = %d\n\n", a, b, c);
	printf("a = %d, b = %d, c = %d\n", a, b, c);

	c = (a++ == 11) && (b++ == 20);
	printf("c = (a++ == 11) && (b++ == 20)�� ���� �� ������ �� \n");
	printf("a = %d, b = %d, c = %d\n\n", a, b, c);
	printf("a = %d, b = %d, c = %d\n", a, b, c);

	c = (a++ == 12) || (b++ == 20);
	printf("c = (a++ == 12) || (b++ == 20)�� ���� �� ������ �� \n ");
	printf("a = %d, b = %d, c = %d\n\n", a, b, c);
	printf("a = %d, b = %d, c = %d\n", a, b, c);

	c = (a++ == 12) || (b++ == 20);
	printf("c = (a++ == 12) || (b++ == 20)�� ���� �� ������ �� \n ");
	printf("a = %d, b = %d, c = %d\n\n", a, b, c);
	printf("a = %d, b = %d, c = %d\n", a, b, c);
	/*
	int m, n;
	char x, y;

	printf("�� ���� �Է�. ");
	scanf("%c%c", &x, &y);
	printf("�� ���� �Է�. ");
	scanf("%d%d", &m, &n);

	printf("\n �Է��� �� ���� %c(%d), %c(%d)�� ���ϸ� \n", x, x, y, y);
	printf("\n �Է��� �� ���� %c(%d), %c(%d)�� ���ϸ� \n", x, x, y, y);
	*/

	/*
	int x, y;
	int addition, substraction, multiplication, division, modulus;

	printf("����1 �Է� : ");
	//scanf("%d", &x);
	std::cin >> x;
	printf("����2 �Է� : ");
	//scanf("%d", &y);
	std::cin >> y;

	addition = x + y;
	substraction = x - y;
	multiplication = x * y;
	division = x / y;
	modulus = x % y;

	printf("%d + %d�� %d \n", x, y, addition);
	printf("%d - %d�� %d \n", x, y, substraction);
	printf("%d * %d�� %d \n", x, y, multiplication);
	printf("%d / %d�� %d \n", x, y, division);
	printf("%d %% %d�� %d \n", x, y, modulus);
	*/

	return  0;

}