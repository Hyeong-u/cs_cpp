/*************************************************************************
*																		 *
* Problem:																 *
* 요일계산하기															 *
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
	int Year;
	int Month;
	int Day;
	int Sum;
	int normalYear []= { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int leapYear []= { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int dayOfTheWeek[]{ 4, 5, 6, 0, 1, 2, 3 };
	int idx;
	for (int i = 0; i < numTestCases; i++)
	{
		in >> Year;
		in >> Month;
		in >> Day;
		idx = 0;
		Sum = 0;
		for (int j = 1582; j < Year; j++)
		{
			if (j % 400 == 0 || (j % 100 != 0 && j % 4 == 0)) // 윤년
			{
				Sum += 366;
			}
			else // 평년
			{
				Sum += 365;
			}
		}
		
		if (Year % 400 == 0 || (Year % 100 != 0 && Year % 4 == 0))
		{
			for (int j = 0; j < Month - 1; j++)
			{
				Sum += leapYear[j];
			}
		}
		else
		{
			for (int j = 0; j < Month - 1; j++)
			{
				Sum += normalYear[j];
			}
		}
		
		Sum += Day;
		idx = Sum % 7;
		cout << dayOfTheWeek[idx] << endl;
	}
	in.close(); /* close input file */
	return 0;
}