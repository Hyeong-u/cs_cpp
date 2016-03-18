/*************************************************************************
*																		 *
* Problem:																 *
* 다각형의 면적															 *
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
	int point = 0;
	int sum = 0;
	int direction = 0;
	in >> numTestCases; /* read the number of test cases */
	for (int i = 0; i < numTestCases; i++)
	{
		in >> point;
		int * x = new int[point];
		int * y = new int[point];
		for (int j = 0; j < point; j++)
		{
			in >> x[j] >> y[j];
		}
		for (int j = 0; j < point ; j++)
		{
			if (j == point - 1)
			{
				sum += (x[j] + x[0]) * (y[0] - y[j]);
			}
			else
			{
				sum += (x[j] + x[j + 1]) * (y[j + 1] - y[j]);
			}
		}
		if (sum > 0)
		{
			direction = 1;
		}
		else
		{
			direction = -1;
			sum *= -1;
		}
		
		cout << sum << " " << direction << endl; /* print out the sum of numbers */
		delete []x;
		delete []y;
		sum = 0;
	}
	in.close(); /* close input file */
	return 0;
}