#include <iostream>
#define LIMIT 10

int main()
{
	int number, divisior, limit, count = 0;

	std::cout << "2���� n(�Է�)������ �Ҽ��� ������. " << std::endl;
	std::cout << "2���� ū ���Ѱ� ���� n�� �Է�>> " ;
	std::cin >> limit;
	std::cout << std::endl << "2���� " << limit << "������ �Ҽ��� =======================" << std::endl;







	/*
	int i, j;
	for (i = 0; i < LIMIT; i++)
	{
		std::cout << i;
	}
	std::cout << std::endl << std::endl;

	//��ø�� for ����
	for (i = 1; i <= LIMIT; i++)
	{
		for (j = 0; j < i; j++)
		{
			std::cout << j;
		}
		std::cout << std::endl;
	}
	char c = 'a';
	for (; c <= 'z'; c++) 
	{
		std::cout << c;
	}
	std::cout << std::endl;
	*/
	



	/*
	int i;
	for (i = 0; i < 5; i = i + 1)
	{
		std::cout << "*****" << std::endl;
	}
	
	std::cout << i << std::endl;
	

	int sum = 0;
	for (i = 0; i <= 10; i++)
	{
		sum += i;
	}
	std::cout << "sum = " << sum << std::endl;
	

	for (sum = 0, i = 0; i <= 10; sum += i, i++);
	std::cout << "sum = " << sum << std::endl;
	*/
	/*
	int mult = 1;
	i = 1;
	while (i <= 10)
	{
		mult *= i;
		i++;
	}
	std::cout << "mult = " << mult << std::endl;

	mult = 1;
	i = 0;
	while (i < 10)
	{
		mult *= ++i;
		
	}
	std::cout << "mult = " << mult << std::endl;

	int r_digit = 0;
	int value = 125;
	do
	{
		r_digit = value % 10;
		std::cout << r_digit << std::endl;
		//value = value / 10;
		value /= 10;
	} while ( value != 0 );
	*/
}