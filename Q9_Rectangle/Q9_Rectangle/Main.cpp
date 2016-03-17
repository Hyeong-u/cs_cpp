/*************************************************************************
*																		 *
* Problem:																 *
* 사각형과 점과의거리													 *
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
		int x1, y1, x2, y2;
		int p, q;
		double d1, d2;
		inStream >> x1;
		inStream >> y1;
		inStream >> x2;
		inStream >> y2;
		inStream >> p;
		inStream >> q;
		
		if ((x1 <= p && p <= x2)&&(y1 <= q && q <= y2))
		{
			d1 = 0;
			d2 = 0;
		}
		else if ((x1 <= p && p <= x2) && !(y1 <= q && q <= y2))
		{
			if (q > y2)
			{
				d1 = (q - y2)*(q - y2);
				d2 = (q - y2);
			}
			else
			{
				d1 = (y1 - q)*(y1 - q);
				d2 = (y1 - q);
			}
		}
		else if (!(x1 <= p && p <= x2) && (y1 <= q && q <= y2))
		{
			if (p > x2)
			{
				d1 = (p - x2)*(p - x2);
				d2 = (p - x2);
			}
			else
			{
				d1 = (x1 - p)*(x1 - p);
				d2 = (x1 - p);
			}
		}
		else if (p > x2 && q > y2)
		{
			d1 = (p - x2)*(p - x2) + (q - y2)*(q - y2);
			d2 = (p - x2) + (q - y2);
		}
		else if (p > x2 && q < y1) 
		{
			d1 = (p - x2)*(p - x2) + (y1 - q)*(y1 - q);
			d2 = (p - x2) + (y1 - q);
		}
		else if (p < x1 && q < y1)
		{
			d1 = (x1 - p)*(x1 - p) + (y1 - q)*(y1 - q);
			d2 = (x1 - p) + (y1 - q);
		}
		else if (p < x1 && q > y2)
		{
			d1 = (x1 - p)*(x1 - p) + (y2 - q)*(y2 - q);
			d2 = (x1 - p) + (q - y2);
		}

		cout << d1 << " " << d2 << endl; /* print out */
	}
	inStream.close(); /* close input file */
	return 0;
}