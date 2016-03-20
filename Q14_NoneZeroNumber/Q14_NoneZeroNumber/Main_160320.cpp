/*************************************************************************
*																		 *
* Problem:																 *
* 0이 아닌 마지막 자리수 구하기											 *
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
		long long int multiply = 1;
		long long int num;
		int numOfZero = 0;
		int countOfDivide2 = 0;
		int countOfDivide5 = 0;
		int roop;
		in >> roop;
		for (int j = 0; j < roop; j++)
		{
			in >> num;
			while (num % 2 == 0 || num % 5 == 0)
			{
				if (num % 2 == 0)
				{
					countOfDivide2++;
					num /= 2;
				}
				if (num % 5 == 0)
				{
					countOfDivide5++;
					num /= 5;
				}
			}
			num %= 10;
			multiply *= num;
			multiply %= 10;
			

		}
		while (countOfDivide2 > 0 && countOfDivide5 > 0)
		{
			numOfZero++;
			countOfDivide2--;
			countOfDivide5--;
		}
		for (int i = 0; i < countOfDivide2; i++)
		{
			multiply *= 2;
			multiply %= 10;
		}
		for (int i = 0; i < countOfDivide5; i++)
		{
			multiply *= 5;
			multiply %= 10;
		}
		cout << num << " " << numOfZero << endl; /* print out the sum of numbers */
	}
	in.close(); /* close input file */
	return 0;
}