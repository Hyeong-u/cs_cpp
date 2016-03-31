#include <iostream>
#define LIMIT 10

int main()
{
	int number, divisior, limit, count = 0;

	std::cout << "2부터 n(입력)까지의 소수를 구하자. " << std::endl;
	std::cout << "2보다 큰 상한값 정수 n을 입력>> " ;
	std::cin >> limit;
	std::cout << std::endl << "2부터 " << limit << "까지의 소수는 =======================" << std::endl;







	/*
	int i, j;
	for (i = 0; i < LIMIT; i++)
	{
		std::cout << i;
	}
	std::cout << std::endl << std::endl;

	//중첩된 for 문장
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