/*************************************************************************
*																		 *
* Problem:																 *
* 삼각형의 면적															 *
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