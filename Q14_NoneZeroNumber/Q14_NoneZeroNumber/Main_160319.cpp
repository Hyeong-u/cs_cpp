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
	int roop, numOfZero, num, tmp, two, five;
	long long int multiply;
	in >> numTestCases; /* read the number of test cases */
	for (int i = 0; i < numTestCases; i++)
	{
		multiply = 1;
		numOfZero = 0;
		two = 0;
		five = 0;
		in >> roop;
		for (int j = 0; j < roop; j++)
		{
			in >> tmp;
			while (tmp % 2 == 0)
			{
				two++;
				tmp /= 2;
			}
			while (tmp % 5 == 0)
			{
				five++;
				tmp /= 5;
			}
			multiply *= tmp;
			

		}
		if (two <= five)
		{
			numOfZero += two;
		}
		else
		{
			numOfZero += five;
		}

		while (multiply % 10 == 0)
		{
			numOfZero++;
			multiply /= 10;
		}
		num = multiply % 10;
		cout << num << " " << numOfZero << endl; /* print out the sum of numbers */
	}
	in.close(); /* close input file */
	return 0;
}