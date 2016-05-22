/*************************************************************************
*																		 *
* Problem:																 *
* 숫자 읽기																 *
*																		 *
*************************************************************************/
/*************************************************************************
*																		 *
* 국민대학교 전자정보통신대학 컴퓨터공학부 2 학년						 *
* 20153168 김형우														 *
*																		 *
*************************************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

char* numArr[101] = { "Zero","One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty",
"Twenty_One", "Twenty_Two", "Twenty_Three", "Twenty_Four", "Twenty_Five", "Twenty_Six", "Twenty_Seven", "Twenty_Eight", "Twenty_Nine", "Thirty",
"Thirty_One", "Thirty_Two", "Thirty_Three", "Thirty_Four", "Thirty_Five", "Thirty_Six", "Thirty_Seven", "Thirty_Eight", "Thirty_Nine", "Forty",
"Forty_One", "Forty_Two", "Forty_Three", "Forty_Four", "Forty_Five", "Forty_Six", "Forty_Seven", "Forty_Eight", "Forty_Nine", "Fifty",
"Fifty_One", "Fifty_Two", "Fifty_Three", "Fifty_Four", "Fifty_Five", "Fifty_Six", "Fifty_Seven", "Fifty_Eight", "Fifty_Nine", "Sixty",
"Sixty_One", "Sixty_Two", "Sixty_Three", "Sixty_Four", "Sixty_Five", "Sixty_Six", "Sixty_Seven", "Sixty_Eight", "Sixty_Nine", "Seventy",
"Seventy_One", "Seventy_Two", "Seventy_Three", "Seventy_Four", "Seventy_Five", "Seventy_Six", "Seventy_Seven", "Seventy_Eight", "Seventy_Nine", "Eighty",
"Eighty_One", "Eighty_Two", "Eighty_Three", "Eighty_Four", "Eighty_Five", "Eighty_Six", "Eighty_Seven", "Eighty_Eight", "Eighty_Nine", "Ninety",
"Ninety_One", "Ninety_Two", "Ninety_Three", "Ninety_Four", "Ninety_Five", "Ninety_Six", "Ninety_Seven", "Ninety_Eight", "Ninety_Nine", "Hundred" };
void Calc(int num);
int main()
{
	ifstream in;
	int numTestCases;
	in.open("input.txt"); /* open input file */
	if (in.fail())
	{
		cerr << "Input file opening failed.\n";
		exit(1);
	}

	in >> numTestCases; /* read the number of test cases */
	
	
	for (int i = 0; i < numTestCases; i++)
	{
		unsigned int num;
		unsigned int temp;
		int Count = 0;
		in >> num;
		temp = num;
		while (temp != 0)
		{
			temp /= 10;
			Count++;
		}
		/*
		if (Count < 3)
		{
			cout << numArr[num] << endl;
			continue;
		}
		if (Count == 3)
		{
			if (num % 100 == 0)
			{
				cout << numArr[num / 100] << "_Hundred"<< endl;
				continue;
			}
			cout << numArr[num/100] << "_Hundred_" << numArr[num%100] << endl;
			continue;
		}
		*/
		if (Count < 4)
		{
			Calc(num);
			cout << endl;
			continue;
		}
		if (Count < 7)
		{
			Calc(num / 1000);
			if (num % 1000 == 0)
			{
				cout << "_Thousand" << endl;
				continue;
			}
			cout << "_Thousand_";
			Calc(num % 1000);
			cout << endl;
			continue;
		}
		if (Count < 10)
		{
			Calc(num / 1000000);
			if (num % 1000000 == 0)
			{
				cout << "_Million" << endl;
				continue;
			}
			cout << "_Million_";
			if ((num % 1000000) / 1000 != 0)
			{
				Calc((num % 1000000) / 1000);
				if (num % 1000 == 0)
				{
					cout << "_Thousand" << endl;
					continue;
				}
				cout << "_Thousand_";
			}
			Calc(num % 1000);
			cout << endl;
			continue;
		}


		Calc(num / 1000000000);
		if (num % 1000000000 == 0)
		{
			cout << "_Billion" << endl;
			continue;
		}
		cout << "_Billion_";
		if ((num % 1000000000) / 1000000 != 0)
		{
			if (num % 1000000 == 0)
			{
				Calc((num % 1000000000) / 1000000);
				cout << "_Million" << endl;
				continue;
			}
			Calc((num % 1000000000) / 1000000);
			cout << "_Million_";
		}
		
		if ((num % 1000000) / 1000 != 0)
		{
			if (num % 1000 == 0)
			{
				Calc((num % 1000000) / 1000);
				cout << "_Thousand" << endl;
				continue;
			}
			Calc((num % 1000000) / 1000);
			cout << "_Thousand_";
		}

		Calc(num % 1000);
		cout << endl;
		continue;

		
	}
	in.close(); /* close input file */
	return 0;
}

void Calc(int num)
{
	if (num < 100)
	{
		cout << numArr[num];
		return;
	}
	if (num % 100 == 0)
	{
		cout << numArr[num / 100] << "_Hundred";
		return;
	}
	cout << numArr[num / 100] << "_Hundred_" << numArr[num % 100];
}