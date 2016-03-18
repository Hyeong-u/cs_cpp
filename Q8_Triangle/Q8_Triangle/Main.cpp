/*************************************************************************
*																		 *
* Problem:																 *
* 삼각형의 종류(2)														 *
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
	ifstream inStream;
	int numTestCases;
	inStream.open("input.txt"); /* open input file */
	if (inStream.fail())
	{
		cerr << "Input file opening failed.\n";
		exit(1);
	}
	inStream >> numTestCases; /* read the number of test cases */
	for (int i = 0; i < numTestCases; i++)
	{
		int x1, y1, x2, y2, x3, y3;
		int L1, L2, L3;
		int min, mid, max;
		double l1, l2, l3;
		int result = 0;
		inStream >> x1;
		inStream >> y1;
		inStream >> x2;
		inStream >> y2;
		inStream >> x3;
		inStream >> y3;
		L1 = pow((x2 - x1), 2.0) + pow((y2 - y1), 2);
		L2 = pow((x3 - x2), 2.0) + pow((y3 - y2), 2);
		L3 = pow((x1 - x3), 2.0) + pow((y1 - y3), 2);
		l1 = sqrt(L1);
		l2 = sqrt(L2);
		l3 = sqrt(L3);
		if (l1 >= l2 && l1 >= l3)
		{
			max = L1;
			if (l2 >= l3)
			{
				mid = L2;
				min = L3;
			}
			else
			{
				mid = L3;
				min = L2;
			}
		}
		else if (l2 >= l1 && l2 >= l3)
		{
			max = L2;
			if (l1 >= l3)
			{
				mid = L1;
				min = L3;
			}
			else
			{
				mid = L3;
				min = L1;
			}
		}
		else
		{
			max = L3;
			if (l2 >= l1)
			{
				mid = L2;
				min = L1;
			}
			else
			{
				mid = L1;
				min = L2;
			}
		}

		if (max > mid + min)
		{
			result = 0;
		}
		else if (min + mid == max)
		{
			result = 1;
		}
		else if (min + mid > max)
		{
			result = 3;
		}
		else if (min + mid < max)
		{
			result = 2;
		}
		cout << result << endl; /* print out the sum of numbers */
	}
	inStream.close(); /* close input file */
	return 0;
}