/*************************************************************************
*																		 *
* Problem:																 *
* 수직/수평 성분의 교차													 *
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
		int x1, y1, x2, y2, x3, y3, x4, y4;
		int result = 0;
		inStream >> x1;
		inStream >> y1;
		inStream >> x2;
		inStream >> y2;
		inStream >> x3;
		inStream >> y3;
		inStream >> x4;
		inStream >> y4;
		if (x1 == x2)
		{
			if (y1 > y2)
			{
				if ( y3 > y1 || y3 < y2 || (x3 < x1 && x4 < x1) || (x1 < x4 && x1 < x3))
				{
					result = 0;
				}
				else if (((y1 < y3 && y3 < y2) || (y2 < y3 && y3 < y1)) && ((x3 < x1 && x1 < x4) || (x4<x1 && x1 < x3)))
				{
					result = 1;
				}
				else
				{
					result = 2;
				}
			}
			else
			{
				if (y3 > y2 || y3 < y1 || (x3 < x1 && x4 < x1) || (x1 < x4 && x1 < x3))
				{
					result = 0;
				}
				else if (((y1 < y3 && y3 < y2) || (y2 < y3 && y3 < y1)) && ((x3 < x1 && x1 < x4) || (x4 < x1 && x1 < x3)))
				{
					result = 1;
				}
				else
				{
					result = 2;
				}
			}
			
		}
		else
		{
			if (x1 > x2)
			{
				if (x3 > x1 || x3 < x2 || (y3 < y1 && y4 < y1) || (y1 < y4 && y1 < y3))
				{
					result = 0;
				}
				else if (((x1 < x3 && x3 < x2) || (x2 < x3 && x3 < x1)) && ((y3 < y1 && y1 < y4) || (y4 < y1 && y1 < y3)))
				{
					result = 1;
				}
				else
				{
					result = 2;
				}
			}
			else
			{
				if (x3 > x2 || x3 < x1 || (y3 < y1 && y4 < y1) || (y1 < y4 && y1 < y3))
				{
					result = 0;
				}
				else if (((x1 < x3 && x3 < x2) || (x2 < x3 && x3 < x1)) && ((y3 < y1 && y1 < y4) || (y4 < y1 && y1 < y3)))
				{
					result = 1;
				}
				else
				{
					result = 2;
				}
			}
		}
		cout << result << endl; /* print out the sum of numbers */
	}
	inStream.close(); /* close input file */
	return 0;
}