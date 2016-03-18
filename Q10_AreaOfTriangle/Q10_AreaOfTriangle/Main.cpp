/*************************************************************************
*																		 *
* Problem:																 *
* �ﰢ���� ����															 *
*																		 *
*************************************************************************/
/*************************************************************************
*																		 *
* ���δ��б� ����������Ŵ��� ��ǻ�Ͱ��к� 2 �г�						 *
* 20153168 ������														 *
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
	int ax, ay, bx, by, cx, cy;
	int area, direction, Area;

	in >> numTestCases; /* read the number of test cases */
	for (int i = 0; i < numTestCases; i++)
	{
		in >> ax >> ay >> bx >> by >> cx >> cy;
		area = ((bx - ax)*(cy - ay) - (cx - ax)*(by - ay));
		if (area > 0)
		{
			Area = area;
			direction = 1;
		}
		else if (area <0)
		{
			Area = -1 * area;
			direction = -1;
		}
		else
		{
			Area = area;
			direction = 0;
		}

		cout << Area << " " << direction << endl; /* print out the sum of numbers */
	}
	in.close(); /* close input file */
	return 0;
}